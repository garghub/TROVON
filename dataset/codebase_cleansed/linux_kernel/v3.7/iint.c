static struct integrity_iint_cache *__integrity_iint_find(struct inode *inode)
{
struct integrity_iint_cache *iint;
struct rb_node *n = integrity_iint_tree.rb_node;
while (n) {
iint = rb_entry(n, struct integrity_iint_cache, rb_node);
if (inode < iint->inode)
n = n->rb_left;
else if (inode > iint->inode)
n = n->rb_right;
else
break;
}
if (!n)
return NULL;
return iint;
}
struct integrity_iint_cache *integrity_iint_find(struct inode *inode)
{
struct integrity_iint_cache *iint;
if (!IS_IMA(inode))
return NULL;
read_lock(&integrity_iint_lock);
iint = __integrity_iint_find(inode);
read_unlock(&integrity_iint_lock);
return iint;
}
static void iint_free(struct integrity_iint_cache *iint)
{
iint->version = 0;
iint->flags = 0UL;
iint->ima_status = INTEGRITY_UNKNOWN;
iint->evm_status = INTEGRITY_UNKNOWN;
kmem_cache_free(iint_cache, iint);
}
struct integrity_iint_cache *integrity_inode_get(struct inode *inode)
{
struct rb_node **p;
struct rb_node *node, *parent = NULL;
struct integrity_iint_cache *iint, *test_iint;
iint = integrity_iint_find(inode);
if (iint)
return iint;
iint = kmem_cache_alloc(iint_cache, GFP_NOFS);
if (!iint)
return NULL;
write_lock(&integrity_iint_lock);
p = &integrity_iint_tree.rb_node;
while (*p) {
parent = *p;
test_iint = rb_entry(parent, struct integrity_iint_cache,
rb_node);
if (inode < test_iint->inode)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
iint->inode = inode;
node = &iint->rb_node;
inode->i_flags |= S_IMA;
rb_link_node(node, parent, p);
rb_insert_color(node, &integrity_iint_tree);
write_unlock(&integrity_iint_lock);
return iint;
}
void integrity_inode_free(struct inode *inode)
{
struct integrity_iint_cache *iint;
if (!IS_IMA(inode))
return;
write_lock(&integrity_iint_lock);
iint = __integrity_iint_find(inode);
rb_erase(&iint->rb_node, &integrity_iint_tree);
write_unlock(&integrity_iint_lock);
iint_free(iint);
}
static void init_once(void *foo)
{
struct integrity_iint_cache *iint = foo;
memset(iint, 0, sizeof *iint);
iint->version = 0;
iint->flags = 0UL;
iint->ima_status = INTEGRITY_UNKNOWN;
iint->evm_status = INTEGRITY_UNKNOWN;
}
static int __init integrity_iintcache_init(void)
{
iint_cache =
kmem_cache_create("iint_cache", sizeof(struct integrity_iint_cache),
0, SLAB_PANIC, init_once);
iint_initialized = 1;
return 0;
}
