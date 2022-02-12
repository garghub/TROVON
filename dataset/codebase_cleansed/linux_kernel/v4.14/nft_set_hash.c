static inline u32 nft_rhash_key(const void *data, u32 len, u32 seed)
{
const struct nft_rhash_cmp_arg *arg = data;
return jhash(arg->key, len, seed);
}
static inline u32 nft_rhash_obj(const void *data, u32 len, u32 seed)
{
const struct nft_rhash_elem *he = data;
return jhash(nft_set_ext_key(&he->ext), len, seed);
}
static inline int nft_rhash_cmp(struct rhashtable_compare_arg *arg,
const void *ptr)
{
const struct nft_rhash_cmp_arg *x = arg->key;
const struct nft_rhash_elem *he = ptr;
if (memcmp(nft_set_ext_key(&he->ext), x->key, x->set->klen))
return 1;
if (nft_set_elem_expired(&he->ext))
return 1;
if (!nft_set_elem_active(&he->ext, x->genmask))
return 1;
return 0;
}
static bool nft_rhash_lookup(const struct net *net, const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext)
{
struct nft_rhash *priv = nft_set_priv(set);
const struct nft_rhash_elem *he;
struct nft_rhash_cmp_arg arg = {
.genmask = nft_genmask_cur(net),
.set = set,
.key = key,
};
he = rhashtable_lookup_fast(&priv->ht, &arg, nft_rhash_params);
if (he != NULL)
*ext = &he->ext;
return !!he;
}
static bool nft_rhash_update(struct nft_set *set, const u32 *key,
void *(*new)(struct nft_set *,
const struct nft_expr *,
struct nft_regs *regs),
const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_set_ext **ext)
{
struct nft_rhash *priv = nft_set_priv(set);
struct nft_rhash_elem *he, *prev;
struct nft_rhash_cmp_arg arg = {
.genmask = NFT_GENMASK_ANY,
.set = set,
.key = key,
};
he = rhashtable_lookup_fast(&priv->ht, &arg, nft_rhash_params);
if (he != NULL)
goto out;
he = new(set, expr, regs);
if (he == NULL)
goto err1;
prev = rhashtable_lookup_get_insert_key(&priv->ht, &arg, &he->node,
nft_rhash_params);
if (IS_ERR(prev))
goto err2;
if (prev) {
nft_set_elem_destroy(set, he, true);
he = prev;
}
out:
*ext = &he->ext;
return true;
err2:
nft_set_elem_destroy(set, he, true);
err1:
return false;
}
static int nft_rhash_insert(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem,
struct nft_set_ext **ext)
{
struct nft_rhash *priv = nft_set_priv(set);
struct nft_rhash_elem *he = elem->priv;
struct nft_rhash_cmp_arg arg = {
.genmask = nft_genmask_next(net),
.set = set,
.key = elem->key.val.data,
};
struct nft_rhash_elem *prev;
prev = rhashtable_lookup_get_insert_key(&priv->ht, &arg, &he->node,
nft_rhash_params);
if (IS_ERR(prev))
return PTR_ERR(prev);
if (prev) {
*ext = &prev->ext;
return -EEXIST;
}
return 0;
}
static void nft_rhash_activate(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_rhash_elem *he = elem->priv;
nft_set_elem_change_active(net, set, &he->ext);
nft_set_elem_clear_busy(&he->ext);
}
static bool nft_rhash_flush(const struct net *net,
const struct nft_set *set, void *priv)
{
struct nft_rhash_elem *he = priv;
if (!nft_set_elem_mark_busy(&he->ext) ||
!nft_is_active(net, &he->ext)) {
nft_set_elem_change_active(net, set, &he->ext);
return true;
}
return false;
}
static void *nft_rhash_deactivate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_rhash *priv = nft_set_priv(set);
struct nft_rhash_elem *he;
struct nft_rhash_cmp_arg arg = {
.genmask = nft_genmask_next(net),
.set = set,
.key = elem->key.val.data,
};
rcu_read_lock();
he = rhashtable_lookup_fast(&priv->ht, &arg, nft_rhash_params);
if (he != NULL &&
!nft_rhash_flush(net, set, he))
he = NULL;
rcu_read_unlock();
return he;
}
static void nft_rhash_remove(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_rhash *priv = nft_set_priv(set);
struct nft_rhash_elem *he = elem->priv;
rhashtable_remove_fast(&priv->ht, &he->node, nft_rhash_params);
}
static void nft_rhash_walk(const struct nft_ctx *ctx, struct nft_set *set,
struct nft_set_iter *iter)
{
struct nft_rhash *priv = nft_set_priv(set);
struct nft_rhash_elem *he;
struct rhashtable_iter hti;
struct nft_set_elem elem;
int err;
err = rhashtable_walk_init(&priv->ht, &hti, GFP_ATOMIC);
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
if (nft_set_elem_expired(&he->ext))
goto cont;
if (!nft_set_elem_active(&he->ext, iter->genmask))
goto cont;
elem.priv = he;
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
static void nft_rhash_gc(struct work_struct *work)
{
struct nft_set *set;
struct nft_rhash_elem *he;
struct nft_rhash *priv;
struct nft_set_gc_batch *gcb = NULL;
struct rhashtable_iter hti;
int err;
priv = container_of(work, struct nft_rhash, gc_work.work);
set = nft_set_container_of(priv);
err = rhashtable_walk_init(&priv->ht, &hti, GFP_KERNEL);
if (err)
goto schedule;
err = rhashtable_walk_start(&hti);
if (err && err != -EAGAIN)
goto out;
while ((he = rhashtable_walk_next(&hti))) {
if (IS_ERR(he)) {
if (PTR_ERR(he) != -EAGAIN)
goto out;
continue;
}
if (!nft_set_elem_expired(&he->ext))
continue;
if (nft_set_elem_mark_busy(&he->ext))
continue;
gcb = nft_set_gc_batch_check(set, gcb, GFP_ATOMIC);
if (gcb == NULL)
goto out;
rhashtable_remove_fast(&priv->ht, &he->node, nft_rhash_params);
atomic_dec(&set->nelems);
nft_set_gc_batch_add(gcb, he);
}
out:
rhashtable_walk_stop(&hti);
rhashtable_walk_exit(&hti);
nft_set_gc_batch_complete(gcb);
schedule:
queue_delayed_work(system_power_efficient_wq, &priv->gc_work,
nft_set_gc_interval(set));
}
static unsigned int nft_rhash_privsize(const struct nlattr * const nla[],
const struct nft_set_desc *desc)
{
return sizeof(struct nft_rhash);
}
static int nft_rhash_init(const struct nft_set *set,
const struct nft_set_desc *desc,
const struct nlattr * const tb[])
{
struct nft_rhash *priv = nft_set_priv(set);
struct rhashtable_params params = nft_rhash_params;
int err;
params.nelem_hint = desc->size ?: NFT_RHASH_ELEMENT_HINT;
params.key_len = set->klen;
err = rhashtable_init(&priv->ht, &params);
if (err < 0)
return err;
INIT_DEFERRABLE_WORK(&priv->gc_work, nft_rhash_gc);
if (set->flags & NFT_SET_TIMEOUT)
queue_delayed_work(system_power_efficient_wq, &priv->gc_work,
nft_set_gc_interval(set));
return 0;
}
static void nft_rhash_elem_destroy(void *ptr, void *arg)
{
nft_set_elem_destroy(arg, ptr, true);
}
static void nft_rhash_destroy(const struct nft_set *set)
{
struct nft_rhash *priv = nft_set_priv(set);
cancel_delayed_work_sync(&priv->gc_work);
rhashtable_free_and_destroy(&priv->ht, nft_rhash_elem_destroy,
(void *)set);
}
static u32 nft_hash_buckets(u32 size)
{
return roundup_pow_of_two(size * 4 / 3);
}
static bool nft_rhash_estimate(const struct nft_set_desc *desc, u32 features,
struct nft_set_estimate *est)
{
est->size = ~0;
est->lookup = NFT_SET_CLASS_O_1;
est->space = NFT_SET_CLASS_O_N;
return true;
}
static bool nft_hash_lookup(const struct net *net, const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext)
{
struct nft_hash *priv = nft_set_priv(set);
u8 genmask = nft_genmask_cur(net);
const struct nft_hash_elem *he;
u32 hash;
hash = jhash(key, set->klen, priv->seed);
hash = reciprocal_scale(hash, priv->buckets);
hlist_for_each_entry_rcu(he, &priv->table[hash], node) {
if (!memcmp(nft_set_ext_key(&he->ext), key, set->klen) &&
nft_set_elem_active(&he->ext, genmask)) {
*ext = &he->ext;
return true;
}
}
return false;
}
static inline u32 nft_hash_key(const u32 *key, u32 klen)
{
if (klen == 4)
return *key;
return *(u16 *)key;
}
static bool nft_hash_lookup_fast(const struct net *net,
const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext)
{
struct nft_hash *priv = nft_set_priv(set);
u8 genmask = nft_genmask_cur(net);
const struct nft_hash_elem *he;
u32 hash, k1, k2;
k1 = nft_hash_key(key, set->klen);
hash = jhash_1word(k1, priv->seed);
hash = reciprocal_scale(hash, priv->buckets);
hlist_for_each_entry_rcu(he, &priv->table[hash], node) {
k2 = nft_hash_key(nft_set_ext_key(&he->ext)->data, set->klen);
if (k1 == k2 &&
nft_set_elem_active(&he->ext, genmask)) {
*ext = &he->ext;
return true;
}
}
return false;
}
static int nft_hash_insert(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem,
struct nft_set_ext **ext)
{
struct nft_hash_elem *this = elem->priv, *he;
struct nft_hash *priv = nft_set_priv(set);
u8 genmask = nft_genmask_next(net);
u32 hash;
hash = jhash(nft_set_ext_key(&this->ext), set->klen, priv->seed);
hash = reciprocal_scale(hash, priv->buckets);
hlist_for_each_entry(he, &priv->table[hash], node) {
if (!memcmp(nft_set_ext_key(&this->ext),
nft_set_ext_key(&he->ext), set->klen) &&
nft_set_elem_active(&he->ext, genmask)) {
*ext = &he->ext;
return -EEXIST;
}
}
hlist_add_head_rcu(&this->node, &priv->table[hash]);
return 0;
}
static void nft_hash_activate(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash_elem *he = elem->priv;
nft_set_elem_change_active(net, set, &he->ext);
}
static bool nft_hash_flush(const struct net *net,
const struct nft_set *set, void *priv)
{
struct nft_hash_elem *he = priv;
nft_set_elem_change_active(net, set, &he->ext);
return true;
}
static void *nft_hash_deactivate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_elem *this = elem->priv, *he;
u8 genmask = nft_genmask_next(net);
u32 hash;
hash = jhash(nft_set_ext_key(&this->ext), set->klen, priv->seed);
hash = reciprocal_scale(hash, priv->buckets);
hlist_for_each_entry(he, &priv->table[hash], node) {
if (!memcmp(nft_set_ext_key(&this->ext), &elem->key.val,
set->klen) ||
nft_set_elem_active(&he->ext, genmask)) {
nft_set_elem_change_active(net, set, &he->ext);
return he;
}
}
return NULL;
}
static void nft_hash_remove(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_hash_elem *he = elem->priv;
hlist_del_rcu(&he->node);
}
static void nft_hash_walk(const struct nft_ctx *ctx, struct nft_set *set,
struct nft_set_iter *iter)
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_elem *he;
struct nft_set_elem elem;
int i;
for (i = 0; i < priv->buckets; i++) {
hlist_for_each_entry_rcu(he, &priv->table[i], node) {
if (iter->count < iter->skip)
goto cont;
if (!nft_set_elem_active(&he->ext, iter->genmask))
goto cont;
elem.priv = he;
iter->err = iter->fn(ctx, set, iter, &elem);
if (iter->err < 0)
return;
cont:
iter->count++;
}
}
}
static unsigned int nft_hash_privsize(const struct nlattr * const nla[],
const struct nft_set_desc *desc)
{
return sizeof(struct nft_hash) +
nft_hash_buckets(desc->size) * sizeof(struct hlist_head);
}
static int nft_hash_init(const struct nft_set *set,
const struct nft_set_desc *desc,
const struct nlattr * const tb[])
{
struct nft_hash *priv = nft_set_priv(set);
priv->buckets = nft_hash_buckets(desc->size);
get_random_bytes(&priv->seed, sizeof(priv->seed));
return 0;
}
static void nft_hash_destroy(const struct nft_set *set)
{
struct nft_hash *priv = nft_set_priv(set);
struct nft_hash_elem *he;
struct hlist_node *next;
int i;
for (i = 0; i < priv->buckets; i++) {
hlist_for_each_entry_safe(he, next, &priv->table[i], node) {
hlist_del_rcu(&he->node);
nft_set_elem_destroy(set, he, true);
}
}
}
static bool nft_hash_estimate(const struct nft_set_desc *desc, u32 features,
struct nft_set_estimate *est)
{
est->size = sizeof(struct nft_hash) +
nft_hash_buckets(desc->size) * sizeof(struct hlist_head) +
desc->size * sizeof(struct nft_hash_elem);
est->lookup = NFT_SET_CLASS_O_1;
est->space = NFT_SET_CLASS_O_N;
return true;
}
static const struct nft_set_ops *
nft_hash_select_ops(const struct nft_ctx *ctx, const struct nft_set_desc *desc,
u32 flags)
{
if (desc->size) {
switch (desc->klen) {
case 4:
return &nft_hash_fast_ops;
default:
return &nft_hash_ops;
}
}
return &nft_rhash_ops;
}
static int __init nft_hash_module_init(void)
{
return nft_register_set(&nft_hash_type);
}
static void __exit nft_hash_module_exit(void)
{
nft_unregister_set(&nft_hash_type);
}
