static bool nft_hash_lookup(const struct nft_set *set,
const struct nft_data *key,
struct nft_data *data)
{
const struct rhashtable *priv = nft_set_priv(set);
const struct nft_hash_elem *he;
he = rhashtable_lookup(priv, key);
if (he && set->flags & NFT_SET_MAP)
nft_data_copy(data, he->data);
return !!he;
}
static int nft_hash_insert(const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct rhashtable *priv = nft_set_priv(set);
struct nft_hash_elem *he;
unsigned int size;
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
rhashtable_insert(priv, &he->node, GFP_KERNEL);
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
struct rhashtable *priv = nft_set_priv(set);
struct rhash_head *he, __rcu **pprev;
pprev = elem->cookie;
he = rht_dereference((*pprev), priv);
rhashtable_remove_pprev(priv, he, pprev, GFP_KERNEL);
synchronize_rcu();
kfree(he);
}
static int nft_hash_get(const struct nft_set *set, struct nft_set_elem *elem)
{
const struct rhashtable *priv = nft_set_priv(set);
const struct bucket_table *tbl = rht_dereference_rcu(priv->tbl, priv);
struct rhash_head __rcu * const *pprev;
struct nft_hash_elem *he;
u32 h;
h = rhashtable_hashfn(priv, &elem->key, set->klen);
pprev = &tbl->buckets[h];
rht_for_each_entry_rcu(he, tbl->buckets[h], node) {
if (nft_data_cmp(&he->key, &elem->key, set->klen)) {
pprev = &he->node.next;
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
const struct rhashtable *priv = nft_set_priv(set);
const struct bucket_table *tbl;
const struct nft_hash_elem *he;
struct nft_set_elem elem;
unsigned int i;
tbl = rht_dereference_rcu(priv->tbl, priv);
for (i = 0; i < tbl->size; i++) {
rht_for_each_entry_rcu(he, tbl->buckets[i], node) {
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
return sizeof(struct rhashtable);
}
static int lockdep_nfnl_lock_is_held(void)
{
return lockdep_nfnl_is_held(NFNL_SUBSYS_NFTABLES);
}
static int nft_hash_init(const struct nft_set *set,
const struct nft_set_desc *desc,
const struct nlattr * const tb[])
{
struct rhashtable *priv = nft_set_priv(set);
struct rhashtable_params params = {
.nelem_hint = desc->size ? : NFT_HASH_ELEMENT_HINT,
.head_offset = offsetof(struct nft_hash_elem, node),
.key_offset = offsetof(struct nft_hash_elem, key),
.key_len = set->klen,
.hashfn = jhash,
.grow_decision = rht_grow_above_75,
.shrink_decision = rht_shrink_below_30,
.mutex_is_held = lockdep_nfnl_lock_is_held,
};
return rhashtable_init(priv, &params);
}
static void nft_hash_destroy(const struct nft_set *set)
{
const struct rhashtable *priv = nft_set_priv(set);
const struct bucket_table *tbl = priv->tbl;
struct nft_hash_elem *he, *next;
unsigned int i;
for (i = 0; i < tbl->size; i++) {
for (he = rht_entry(tbl->buckets[i], struct nft_hash_elem, node);
he != NULL; he = next) {
next = rht_entry(he->node.next, struct nft_hash_elem, node);
nft_hash_elem_destroy(set, he);
}
}
rhashtable_destroy(priv);
}
static bool nft_hash_estimate(const struct nft_set_desc *desc, u32 features,
struct nft_set_estimate *est)
{
unsigned int esize;
esize = sizeof(struct nft_hash_elem);
if (features & NFT_SET_MAP)
esize += FIELD_SIZEOF(struct nft_hash_elem, data[0]);
if (desc->size) {
est->size = sizeof(struct rhashtable) +
roundup_pow_of_two(desc->size * 4 / 3) *
sizeof(struct nft_hash_elem *) +
desc->size * esize;
} else {
est->size = esize + 2 * sizeof(struct nft_hash_elem *);
}
est->class = NFT_SET_CLASS_O_1;
return true;
}
static int __init nft_hash_module_init(void)
{
return nft_register_set(&nft_hash_ops);
}
static void __exit nft_hash_module_exit(void)
{
nft_unregister_set(&nft_hash_ops);
}
