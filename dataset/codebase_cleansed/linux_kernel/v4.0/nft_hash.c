static bool nft_hash_lookup(const struct nft_set *set,
const struct nft_data *key,
struct nft_data *data)
{
struct rhashtable *priv = nft_set_priv(set);
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
rhashtable_insert(priv, &he->node);
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
rhashtable_remove(priv, elem->cookie);
synchronize_rcu();
kfree(elem->cookie);
}
static bool nft_hash_compare(void *ptr, void *arg)
{
struct nft_hash_elem *he = ptr;
struct nft_compare_arg *x = arg;
if (!nft_data_cmp(&he->key, &x->elem->key, x->set->klen)) {
x->elem->cookie = he;
x->elem->flags = 0;
if (x->set->flags & NFT_SET_MAP)
nft_data_copy(&x->elem->data, he->data);
return true;
}
return false;
}
static int nft_hash_get(const struct nft_set *set, struct nft_set_elem *elem)
{
struct rhashtable *priv = nft_set_priv(set);
struct nft_compare_arg arg = {
.set = set,
.elem = elem,
};
if (rhashtable_lookup_compare(priv, &elem->key,
&nft_hash_compare, &arg))
return 0;
return -ENOENT;
}
static void nft_hash_walk(const struct nft_ctx *ctx, const struct nft_set *set,
struct nft_set_iter *iter)
{
struct rhashtable *priv = nft_set_priv(set);
const struct nft_hash_elem *he;
struct rhashtable_iter hti;
struct nft_set_elem elem;
int err;
err = rhashtable_walk_init(priv, &hti);
iter->err = err;
if (err)
return;
err = rhashtable_walk_start(&hti);
if (err && err != -EAGAIN) {
iter->err = err;
goto out;
}
while ((he = rhashtable_walk_next(&hti))) {
if (IS_ERR(he)) {
err = PTR_ERR(he);
if (err != -EAGAIN) {
iter->err = err;
goto out;
}
continue;
}
if (iter->count < iter->skip)
goto cont;
memcpy(&elem.key, &he->key, sizeof(elem.key));
if (set->flags & NFT_SET_MAP)
memcpy(&elem.data, he->data, sizeof(elem.data));
elem.flags = 0;
iter->err = iter->fn(ctx, set, iter, &elem);
if (iter->err < 0)
goto out;
cont:
iter->count++;
}
out:
rhashtable_walk_stop(&hti);
rhashtable_walk_exit(&hti);
}
static unsigned int nft_hash_privsize(const struct nlattr * const nla[])
{
return sizeof(struct rhashtable);
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
};
return rhashtable_init(priv, &params);
}
static void nft_hash_destroy(const struct nft_set *set)
{
struct rhashtable *priv = nft_set_priv(set);
const struct bucket_table *tbl;
struct nft_hash_elem *he;
struct rhash_head *pos, *next;
unsigned int i;
priv->being_destroyed = true;
mutex_lock(&priv->mutex);
tbl = rht_dereference(priv->tbl, priv);
for (i = 0; i < tbl->size; i++) {
rht_for_each_entry_safe(he, pos, next, tbl, i, node)
nft_hash_elem_destroy(set, he);
}
mutex_unlock(&priv->mutex);
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
