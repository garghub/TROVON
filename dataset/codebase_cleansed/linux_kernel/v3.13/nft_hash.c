static unsigned int nft_hash_data(const struct nft_data *data,
unsigned int hsize, unsigned int len)
{
unsigned int h;
h = jhash(data->data, len, nft_hash_rnd);
return ((u64)h * hsize) >> 32;
}
static bool nft_hash_lookup(const struct nft_set *set,
const struct nft_data *key,
struct nft_data *data)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct nft_hash_elem *he;
unsigned int h;
h = nft_hash_data(key, priv->hsize, set->klen);
hlist_for_each_entry(he, &priv->hash[h], hnode) {
if (nft_data_cmp(&he->key, key, set->klen))
continue;
if (set->flags & NFT_SET_MAP)
nft_data_copy(data, he->data);
return true;
}
return false;
}
static void nft_hash_elem_destroy(const struct nft_set *set,
struct nft_hash_elem *he)
{
nft_data_uninit(&he->key, NFT_DATA_VALUE);
if (set->flags & NFT_SET_MAP)
nft_data_uninit(he->data, set->dtype);
kfree(he);
}
static int nft_hash_insert(const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash *priv = nft_set_priv(set);
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
h = nft_hash_data(&he->key, priv->hsize, set->klen);
hlist_add_head_rcu(&he->hnode, &priv->hash[h]);
return 0;
}
static void nft_hash_remove(const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash_elem *he = elem->cookie;
hlist_del_rcu(&he->hnode);
kfree(he);
}
static int nft_hash_get(const struct nft_set *set, struct nft_set_elem *elem)
{
const struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_elem *he;
unsigned int h;
h = nft_hash_data(&elem->key, priv->hsize, set->klen);
hlist_for_each_entry(he, &priv->hash[h], hnode) {
if (nft_data_cmp(&he->key, &elem->key, set->klen))
continue;
elem->cookie = he;
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
const struct nft_hash_elem *he;
struct nft_set_elem elem;
unsigned int i;
for (i = 0; i < priv->hsize; i++) {
hlist_for_each_entry(he, &priv->hash[i], hnode) {
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
unsigned int cnt, i;
if (unlikely(!nft_hash_rnd_initted)) {
get_random_bytes(&nft_hash_rnd, 4);
nft_hash_rnd_initted = true;
}
cnt = 100;
cnt = cnt * 4 / 3;
priv->hash = kcalloc(cnt, sizeof(struct hlist_head), GFP_KERNEL);
if (priv->hash == NULL)
return -ENOMEM;
priv->hsize = cnt;
for (i = 0; i < cnt; i++)
INIT_HLIST_HEAD(&priv->hash[i]);
return 0;
}
static void nft_hash_destroy(const struct nft_set *set)
{
const struct nft_hash *priv = nft_set_priv(set);
const struct hlist_node *next;
struct nft_hash_elem *elem;
unsigned int i;
for (i = 0; i < priv->hsize; i++) {
hlist_for_each_entry_safe(elem, next, &priv->hash[i], hnode) {
hlist_del(&elem->hnode);
nft_hash_elem_destroy(set, elem);
}
}
kfree(priv->hash);
}
static int __init nft_hash_module_init(void)
{
return nft_register_set(&nft_hash_ops);
}
static void __exit nft_hash_module_exit(void)
{
nft_unregister_set(&nft_hash_ops);
}
