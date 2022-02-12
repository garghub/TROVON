static inline void nft_bitmap_location(const struct nft_set *set,
const void *key,
u32 *idx, u32 *off)
{
u32 k;
if (set->klen == 2)
k = *(u16 *)key;
else
k = *(u8 *)key;
k <<= 1;
*idx = k / BITS_PER_BYTE;
*off = k % BITS_PER_BYTE;
}
static inline bool
nft_bitmap_active(const u8 *bitmap, u32 idx, u32 off, u8 genmask)
{
return (bitmap[idx] & (0x3 << off)) & (genmask << off);
}
static bool nft_bitmap_lookup(const struct net *net, const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext)
{
const struct nft_bitmap *priv = nft_set_priv(set);
u8 genmask = nft_genmask_cur(net);
u32 idx, off;
nft_bitmap_location(set, key, &idx, &off);
return nft_bitmap_active(priv->bitmap, idx, off, genmask);
}
static struct nft_bitmap_elem *
nft_bitmap_elem_find(const struct nft_set *set, struct nft_bitmap_elem *this,
u8 genmask)
{
const struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *be;
list_for_each_entry_rcu(be, &priv->list, head) {
if (memcmp(nft_set_ext_key(&be->ext),
nft_set_ext_key(&this->ext), set->klen) ||
!nft_set_elem_active(&be->ext, genmask))
continue;
return be;
}
return NULL;
}
static int nft_bitmap_insert(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem,
struct nft_set_ext **ext)
{
struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *new = elem->priv, *be;
u8 genmask = nft_genmask_next(net);
u32 idx, off;
be = nft_bitmap_elem_find(set, new, genmask);
if (be) {
*ext = &be->ext;
return -EEXIST;
}
nft_bitmap_location(set, nft_set_ext_key(&new->ext), &idx, &off);
priv->bitmap[idx] |= (genmask << off);
list_add_tail_rcu(&new->head, &priv->list);
return 0;
}
static void nft_bitmap_remove(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *be = elem->priv;
u8 genmask = nft_genmask_next(net);
u32 idx, off;
nft_bitmap_location(set, nft_set_ext_key(&be->ext), &idx, &off);
priv->bitmap[idx] &= ~(genmask << off);
list_del_rcu(&be->head);
}
static void nft_bitmap_activate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *be = elem->priv;
u8 genmask = nft_genmask_next(net);
u32 idx, off;
nft_bitmap_location(set, nft_set_ext_key(&be->ext), &idx, &off);
priv->bitmap[idx] |= (genmask << off);
nft_set_elem_change_active(net, set, &be->ext);
}
static bool nft_bitmap_flush(const struct net *net,
const struct nft_set *set, void *_be)
{
struct nft_bitmap *priv = nft_set_priv(set);
u8 genmask = nft_genmask_next(net);
struct nft_bitmap_elem *be = _be;
u32 idx, off;
nft_bitmap_location(set, nft_set_ext_key(&be->ext), &idx, &off);
priv->bitmap[idx] &= ~(genmask << off);
nft_set_elem_change_active(net, set, &be->ext);
return true;
}
static void *nft_bitmap_deactivate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *this = elem->priv, *be;
u8 genmask = nft_genmask_next(net);
u32 idx, off;
nft_bitmap_location(set, elem->key.val.data, &idx, &off);
be = nft_bitmap_elem_find(set, this, genmask);
if (!be)
return NULL;
priv->bitmap[idx] &= ~(genmask << off);
nft_set_elem_change_active(net, set, &be->ext);
return be;
}
static void nft_bitmap_walk(const struct nft_ctx *ctx,
struct nft_set *set,
struct nft_set_iter *iter)
{
const struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *be;
struct nft_set_elem elem;
list_for_each_entry_rcu(be, &priv->list, head) {
if (iter->count < iter->skip)
goto cont;
if (!nft_set_elem_active(&be->ext, iter->genmask))
goto cont;
elem.priv = be;
iter->err = iter->fn(ctx, set, iter, &elem);
if (iter->err < 0)
return;
cont:
iter->count++;
}
}
static inline u32 nft_bitmap_size(u32 klen)
{
return ((2 << ((klen * BITS_PER_BYTE) - 1)) / BITS_PER_BYTE) << 1;
}
static inline u32 nft_bitmap_total_size(u32 klen)
{
return sizeof(struct nft_bitmap) + nft_bitmap_size(klen);
}
static unsigned int nft_bitmap_privsize(const struct nlattr * const nla[])
{
u32 klen = ntohl(nla_get_be32(nla[NFTA_SET_KEY_LEN]));
return nft_bitmap_total_size(klen);
}
static int nft_bitmap_init(const struct nft_set *set,
const struct nft_set_desc *desc,
const struct nlattr * const nla[])
{
struct nft_bitmap *priv = nft_set_priv(set);
INIT_LIST_HEAD(&priv->list);
priv->bitmap_size = nft_bitmap_size(set->klen);
return 0;
}
static void nft_bitmap_destroy(const struct nft_set *set)
{
struct nft_bitmap *priv = nft_set_priv(set);
struct nft_bitmap_elem *be, *n;
list_for_each_entry_safe(be, n, &priv->list, head)
nft_set_elem_destroy(set, be, true);
}
static bool nft_bitmap_estimate(const struct nft_set_desc *desc, u32 features,
struct nft_set_estimate *est)
{
if (desc->klen > 2)
return false;
est->size = nft_bitmap_total_size(desc->klen);
est->lookup = NFT_SET_CLASS_O_1;
est->space = NFT_SET_CLASS_O_1;
return true;
}
static int __init nft_bitmap_module_init(void)
{
return nft_register_set(&nft_bitmap_ops);
}
static void __exit nft_bitmap_module_exit(void)
{
nft_unregister_set(&nft_bitmap_ops);
}
