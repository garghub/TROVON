static bool nft_rbtree_interval_end(const struct nft_rbtree_elem *rbe)
{
return nft_set_ext_exists(&rbe->ext, NFT_SET_EXT_FLAGS) &&
(*nft_set_ext_flags(&rbe->ext) & NFT_SET_ELEM_INTERVAL_END);
}
static bool nft_rbtree_equal(const struct nft_set *set, const void *this,
const struct nft_rbtree_elem *interval)
{
return memcmp(this, nft_set_ext_key(&interval->ext), set->klen) == 0;
}
static bool __nft_rbtree_lookup(const struct net *net, const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext,
unsigned int seq)
{
struct nft_rbtree *priv = nft_set_priv(set);
const struct nft_rbtree_elem *rbe, *interval = NULL;
u8 genmask = nft_genmask_cur(net);
const struct rb_node *parent;
const void *this;
int d;
parent = rcu_dereference_raw(priv->root.rb_node);
while (parent != NULL) {
if (read_seqcount_retry(&priv->count, seq))
return false;
rbe = rb_entry(parent, struct nft_rbtree_elem, node);
this = nft_set_ext_key(&rbe->ext);
d = memcmp(this, key, set->klen);
if (d < 0) {
parent = rcu_dereference_raw(parent->rb_left);
if (interval &&
nft_rbtree_equal(set, this, interval) &&
nft_rbtree_interval_end(this) &&
!nft_rbtree_interval_end(interval))
continue;
interval = rbe;
} else if (d > 0)
parent = rcu_dereference_raw(parent->rb_right);
else {
if (!nft_set_elem_active(&rbe->ext, genmask)) {
parent = rcu_dereference_raw(parent->rb_left);
continue;
}
if (nft_rbtree_interval_end(rbe))
goto out;
*ext = &rbe->ext;
return true;
}
}
if (set->flags & NFT_SET_INTERVAL && interval != NULL &&
nft_set_elem_active(&interval->ext, genmask) &&
!nft_rbtree_interval_end(interval)) {
*ext = &interval->ext;
return true;
}
out:
return false;
}
static bool nft_rbtree_lookup(const struct net *net, const struct nft_set *set,
const u32 *key, const struct nft_set_ext **ext)
{
struct nft_rbtree *priv = nft_set_priv(set);
unsigned int seq = read_seqcount_begin(&priv->count);
bool ret;
ret = __nft_rbtree_lookup(net, set, key, ext, seq);
if (ret || !read_seqcount_retry(&priv->count, seq))
return ret;
read_lock_bh(&priv->lock);
seq = read_seqcount_begin(&priv->count);
ret = __nft_rbtree_lookup(net, set, key, ext, seq);
read_unlock_bh(&priv->lock);
return ret;
}
static int __nft_rbtree_insert(const struct net *net, const struct nft_set *set,
struct nft_rbtree_elem *new,
struct nft_set_ext **ext)
{
struct nft_rbtree *priv = nft_set_priv(set);
u8 genmask = nft_genmask_next(net);
struct nft_rbtree_elem *rbe;
struct rb_node *parent, **p;
int d;
parent = NULL;
p = &priv->root.rb_node;
while (*p != NULL) {
parent = *p;
rbe = rb_entry(parent, struct nft_rbtree_elem, node);
d = memcmp(nft_set_ext_key(&rbe->ext),
nft_set_ext_key(&new->ext),
set->klen);
if (d < 0)
p = &parent->rb_left;
else if (d > 0)
p = &parent->rb_right;
else {
if (nft_rbtree_interval_end(rbe) &&
!nft_rbtree_interval_end(new)) {
p = &parent->rb_left;
} else if (!nft_rbtree_interval_end(rbe) &&
nft_rbtree_interval_end(new)) {
p = &parent->rb_right;
} else if (nft_set_elem_active(&rbe->ext, genmask)) {
*ext = &rbe->ext;
return -EEXIST;
} else {
p = &parent->rb_left;
}
}
}
rb_link_node_rcu(&new->node, parent, p);
rb_insert_color(&new->node, &priv->root);
return 0;
}
static int nft_rbtree_insert(const struct net *net, const struct nft_set *set,
const struct nft_set_elem *elem,
struct nft_set_ext **ext)
{
struct nft_rbtree *priv = nft_set_priv(set);
struct nft_rbtree_elem *rbe = elem->priv;
int err;
write_lock_bh(&priv->lock);
write_seqcount_begin(&priv->count);
err = __nft_rbtree_insert(net, set, rbe, ext);
write_seqcount_end(&priv->count);
write_unlock_bh(&priv->lock);
return err;
}
static void nft_rbtree_remove(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_rbtree *priv = nft_set_priv(set);
struct nft_rbtree_elem *rbe = elem->priv;
write_lock_bh(&priv->lock);
write_seqcount_begin(&priv->count);
rb_erase(&rbe->node, &priv->root);
write_seqcount_end(&priv->count);
write_unlock_bh(&priv->lock);
}
static void nft_rbtree_activate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
struct nft_rbtree_elem *rbe = elem->priv;
nft_set_elem_change_active(net, set, &rbe->ext);
}
static bool nft_rbtree_flush(const struct net *net,
const struct nft_set *set, void *priv)
{
struct nft_rbtree_elem *rbe = priv;
nft_set_elem_change_active(net, set, &rbe->ext);
return true;
}
static void *nft_rbtree_deactivate(const struct net *net,
const struct nft_set *set,
const struct nft_set_elem *elem)
{
const struct nft_rbtree *priv = nft_set_priv(set);
const struct rb_node *parent = priv->root.rb_node;
struct nft_rbtree_elem *rbe, *this = elem->priv;
u8 genmask = nft_genmask_next(net);
int d;
while (parent != NULL) {
rbe = rb_entry(parent, struct nft_rbtree_elem, node);
d = memcmp(nft_set_ext_key(&rbe->ext), &elem->key.val,
set->klen);
if (d < 0)
parent = parent->rb_left;
else if (d > 0)
parent = parent->rb_right;
else {
if (!nft_set_elem_active(&rbe->ext, genmask)) {
parent = parent->rb_left;
continue;
}
if (nft_rbtree_interval_end(rbe) &&
!nft_rbtree_interval_end(this)) {
parent = parent->rb_left;
continue;
} else if (!nft_rbtree_interval_end(rbe) &&
nft_rbtree_interval_end(this)) {
parent = parent->rb_right;
continue;
}
nft_rbtree_flush(net, set, rbe);
return rbe;
}
}
return NULL;
}
static void nft_rbtree_walk(const struct nft_ctx *ctx,
struct nft_set *set,
struct nft_set_iter *iter)
{
struct nft_rbtree *priv = nft_set_priv(set);
struct nft_rbtree_elem *rbe;
struct nft_set_elem elem;
struct rb_node *node;
read_lock_bh(&priv->lock);
for (node = rb_first(&priv->root); node != NULL; node = rb_next(node)) {
rbe = rb_entry(node, struct nft_rbtree_elem, node);
if (iter->count < iter->skip)
goto cont;
if (!nft_set_elem_active(&rbe->ext, iter->genmask))
goto cont;
elem.priv = rbe;
iter->err = iter->fn(ctx, set, iter, &elem);
if (iter->err < 0) {
read_unlock_bh(&priv->lock);
return;
}
cont:
iter->count++;
}
read_unlock_bh(&priv->lock);
}
static unsigned int nft_rbtree_privsize(const struct nlattr * const nla[],
const struct nft_set_desc *desc)
{
return sizeof(struct nft_rbtree);
}
static int nft_rbtree_init(const struct nft_set *set,
const struct nft_set_desc *desc,
const struct nlattr * const nla[])
{
struct nft_rbtree *priv = nft_set_priv(set);
rwlock_init(&priv->lock);
seqcount_init(&priv->count);
priv->root = RB_ROOT;
return 0;
}
static void nft_rbtree_destroy(const struct nft_set *set)
{
struct nft_rbtree *priv = nft_set_priv(set);
struct nft_rbtree_elem *rbe;
struct rb_node *node;
while ((node = priv->root.rb_node) != NULL) {
rb_erase(node, &priv->root);
rbe = rb_entry(node, struct nft_rbtree_elem, node);
nft_set_elem_destroy(set, rbe, true);
}
}
static bool nft_rbtree_estimate(const struct nft_set_desc *desc, u32 features,
struct nft_set_estimate *est)
{
if (desc->size)
est->size = sizeof(struct nft_rbtree) +
desc->size * sizeof(struct nft_rbtree_elem);
else
est->size = ~0;
est->lookup = NFT_SET_CLASS_O_LOG_N;
est->space = NFT_SET_CLASS_O_N;
return true;
}
static int __init nft_rbtree_module_init(void)
{
return nft_register_set(&nft_rbtree_type);
}
static void __exit nft_rbtree_module_exit(void)
{
nft_unregister_set(&nft_rbtree_type);
}
