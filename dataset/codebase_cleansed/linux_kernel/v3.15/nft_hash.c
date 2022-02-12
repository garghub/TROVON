static unsigned int nft_hash_data(const struct nft_data *data,
unsigned int hsize, unsigned int len)
{
unsigned int h;
h = jhash(data->data, len, nft_hash_rnd);
return h & (hsize - 1);
}
static bool nft_hash_lookup(const struct nft_set *set,
const struct nft_data *key,
struct nft_data *data)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct nft_hash_table *tbl = rcu_dereference(priv->tbl);
const struct nft_hash_elem *he;
unsigned int h;
h = nft_hash_data(key, tbl->size, set->klen);
nft_hash_for_each_entry_rcu(he, tbl->buckets[h]) {
if (nft_data_cmp(&he->key, key, set->klen))
continue;
if (set->flags & NFT_SET_MAP)
nft_data_copy(data, he->data);
return true;
}
return false;
}
static void nft_hash_tbl_free(const struct nft_hash_table *tbl)
{
if (is_vmalloc_addr(tbl))
vfree(tbl);
else
kfree(tbl);
}
static struct nft_hash_table *nft_hash_tbl_alloc(unsigned int nbuckets)
{
struct nft_hash_table *tbl;
size_t size;
size = sizeof(*tbl) + nbuckets * sizeof(tbl->buckets[0]);
tbl = kzalloc(size, GFP_KERNEL | __GFP_REPEAT | __GFP_NOWARN);
if (tbl == NULL)
tbl = vzalloc(size);
if (tbl == NULL)
return NULL;
tbl->size = nbuckets;
return tbl;
}
static void nft_hash_chain_unzip(const struct nft_set *set,
const struct nft_hash_table *ntbl,
struct nft_hash_table *tbl, unsigned int n)
{
struct nft_hash_elem *he, *last, *next;
unsigned int h;
he = nft_dereference(tbl->buckets[n]);
if (he == NULL)
return;
h = nft_hash_data(&he->key, ntbl->size, set->klen);
last = he;
nft_hash_for_each_entry(he, he->next) {
if (nft_hash_data(&he->key, ntbl->size, set->klen) != h)
break;
last = he;
}
RCU_INIT_POINTER(tbl->buckets[n], last->next);
if (he == NULL)
return;
next = NULL;
nft_hash_for_each_entry(he, he->next) {
if (nft_hash_data(&he->key, ntbl->size, set->klen) != h)
continue;
next = he;
break;
}
RCU_INIT_POINTER(last->next, next);
}
static int nft_hash_tbl_expand(const struct nft_set *set, struct nft_hash *priv)
{
struct nft_hash_table *tbl = nft_dereference(priv->tbl), *ntbl;
struct nft_hash_elem *he;
unsigned int i, h;
bool complete;
ntbl = nft_hash_tbl_alloc(tbl->size * 2);
if (ntbl == NULL)
return -ENOMEM;
for (i = 0; i < ntbl->size; i++) {
h = i < tbl->size ? i : i - tbl->size;
nft_hash_for_each_entry(he, tbl->buckets[h]) {
if (nft_hash_data(&he->key, ntbl->size, set->klen) != i)
continue;
RCU_INIT_POINTER(ntbl->buckets[i], he);
break;
}
}
ntbl->elements = tbl->elements;
rcu_assign_pointer(priv->tbl, ntbl);
do {
synchronize_rcu();
complete = true;
for (i = 0; i < tbl->size; i++) {
nft_hash_chain_unzip(set, ntbl, tbl, i);
if (tbl->buckets[i] != NULL)
complete = false;
}
} while (!complete);
nft_hash_tbl_free(tbl);
return 0;
}
static int nft_hash_tbl_shrink(const struct nft_set *set, struct nft_hash *priv)
{
struct nft_hash_table *tbl = nft_dereference(priv->tbl), *ntbl;
struct nft_hash_elem __rcu **pprev;
unsigned int i;
ntbl = nft_hash_tbl_alloc(tbl->size / 2);
if (ntbl == NULL)
return -ENOMEM;
for (i = 0; i < ntbl->size; i++) {
ntbl->buckets[i] = tbl->buckets[i];
for (pprev = &ntbl->buckets[i]; *pprev != NULL;
pprev = &nft_dereference(*pprev)->next)
;
RCU_INIT_POINTER(*pprev, tbl->buckets[i + ntbl->size]);
}
ntbl->elements = tbl->elements;
rcu_assign_pointer(priv->tbl, ntbl);
synchronize_rcu();
nft_hash_tbl_free(tbl);
return 0;
}
static int nft_hash_insert(const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_table *tbl = nft_dereference(priv->tbl);
struct nft_hash_elem *he;
unsigned int size, h;
if (elem->flags != 0)
return -EINVAL;
size = sizeof(*he);
if (set->flags & NFT_SET_MAP)
size += sizeof(he->data[0]);
he = kzalloc(size, GFP_KERNEL);
if (he == NULL)
return -ENOMEM;
nft_data_copy(&he->key, &elem->key);
if (set->flags & NFT_SET_MAP)
nft_data_copy(he->data, &elem->data);
h = nft_hash_data(&he->key, tbl->size, set->klen);
RCU_INIT_POINTER(he->next, tbl->buckets[h]);
rcu_assign_pointer(tbl->buckets[h], he);
tbl->elements++;
if (tbl->elements > tbl->size / 4 * 3)
nft_hash_tbl_expand(set, priv);
return 0;
}
static void nft_hash_elem_destroy(const struct nft_set *set,
struct nft_hash_elem *he)
{
nft_data_uninit(&he->key, NFT_DATA_VALUE);
if (set->flags & NFT_SET_MAP)
nft_data_uninit(he->data, set->dtype);
kfree(he);
}
static void nft_hash_remove(const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_table *tbl = nft_dereference(priv->tbl);
struct nft_hash_elem *he, __rcu **pprev;
pprev = elem->cookie;
he = nft_dereference((*pprev));
RCU_INIT_POINTER(*pprev, he->next);
synchronize_rcu();
kfree(he);
tbl->elements--;
if (tbl->elements < tbl->size * 3 / 10 &&
tbl->size > NFT_HASH_MIN_SIZE)
nft_hash_tbl_shrink(set, priv);
}
static int nft_hash_get(const struct nft_set *set, struct nft_set_elem *elem)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct nft_hash_table *tbl = nft_dereference(priv->tbl);
struct nft_hash_elem __rcu * const *pprev;
struct nft_hash_elem *he;
unsigned int h;
h = nft_hash_data(&elem->key, tbl->size, set->klen);
pprev = &tbl->buckets[h];
nft_hash_for_each_entry(he, tbl->buckets[h]) {
if (nft_data_cmp(&he->key, &elem->key, set->klen)) {
pprev = &he->next;
continue;
}
elem->cookie = (void *)pprev;
elem->flags = 0;
if (set->flags & NFT_SET_MAP)
nft_data_copy(&elem->data, he->data);
return 0;
}
return -ENOENT;
}
static void nft_hash_walk(const struct nft_ctx *ctx, const struct nft_set *set,
struct nft_set_iter *iter)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct nft_hash_table *tbl = nft_dereference(priv->tbl);
const struct nft_hash_elem *he;
struct nft_set_elem elem;
unsigned int i;
for (i = 0; i < tbl->size; i++) {
nft_hash_for_each_entry(he, tbl->buckets[i]) {
if (iter->count < iter->skip)
goto cont;
memcpy(&elem.key, &he->key, sizeof(elem.key));
if (set->flags & NFT_SET_MAP)
memcpy(&elem.data, he->data, sizeof(elem.data));
elem.flags = 0;
iter->err = iter->fn(ctx, set, iter, &elem);
if (iter->err < 0)
return;
cont:
iter->count++;
}
}
}
static unsigned int nft_hash_privsize(const struct nlattr * const nla[])
{
return sizeof(struct nft_hash);
}
static int nft_hash_init(const struct nft_set *set,
const struct nlattr * const tb[])
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_table *tbl;
if (unlikely(!nft_hash_rnd_initted)) {
get_random_bytes(&nft_hash_rnd, 4);
nft_hash_rnd_initted = true;
}
tbl = nft_hash_tbl_alloc(NFT_HASH_MIN_SIZE);
if (tbl == NULL)
return -ENOMEM;
RCU_INIT_POINTER(priv->tbl, tbl);
return 0;
}
static void nft_hash_destroy(const struct nft_set *set)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct nft_hash_table *tbl = nft_dereference(priv->tbl);
struct nft_hash_elem *he, *next;
unsigned int i;
for (i = 0; i < tbl->size; i++) {
for (he = nft_dereference(tbl->buckets[i]); he != NULL;
he = next) {
next = nft_dereference(he->next);
nft_hash_elem_destroy(set, he);
}
}
kfree(tbl);
}
static int __init nft_hash_module_init(void)
{
return nft_register_set(&nft_hash_ops);
}
static void __exit nft_hash_module_exit(void)
{
nft_unregister_set(&nft_hash_ops);
}
