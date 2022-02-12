int __init ext4_init_es(void)
{
ext4_es_cachep = KMEM_CACHE(extent_status, SLAB_RECLAIM_ACCOUNT);
if (ext4_es_cachep == NULL)
return -ENOMEM;
return 0;
}
void ext4_exit_es(void)
{
if (ext4_es_cachep)
kmem_cache_destroy(ext4_es_cachep);
}
void ext4_es_init_tree(struct ext4_es_tree *tree)
{
tree->root = RB_ROOT;
tree->cache_es = NULL;
}
static void ext4_es_print_tree(struct inode *inode)
{
struct ext4_es_tree *tree;
struct rb_node *node;
printk(KERN_DEBUG "status extents for inode %lu:", inode->i_ino);
tree = &EXT4_I(inode)->i_es_tree;
node = rb_first(&tree->root);
while (node) {
struct extent_status *es;
es = rb_entry(node, struct extent_status, rb_node);
printk(KERN_DEBUG " [%u/%u)", es->start, es->len);
node = rb_next(node);
}
printk(KERN_DEBUG "\n");
}
static inline ext4_lblk_t extent_status_end(struct extent_status *es)
{
BUG_ON(es->start + es->len < es->start);
return es->start + es->len - 1;
}
static struct extent_status *__es_tree_search(struct rb_root *root,
ext4_lblk_t offset)
{
struct rb_node *node = root->rb_node;
struct extent_status *es = NULL;
while (node) {
es = rb_entry(node, struct extent_status, rb_node);
if (offset < es->start)
node = node->rb_left;
else if (offset > extent_status_end(es))
node = node->rb_right;
else
return es;
}
if (es && offset < es->start)
return es;
if (es && offset > extent_status_end(es)) {
node = rb_next(&es->rb_node);
return node ? rb_entry(node, struct extent_status, rb_node) :
NULL;
}
return NULL;
}
ext4_lblk_t ext4_es_find_extent(struct inode *inode, struct extent_status *es)
{
struct ext4_es_tree *tree = NULL;
struct extent_status *es1 = NULL;
struct rb_node *node;
ext4_lblk_t ret = EXT_MAX_BLOCKS;
trace_ext4_es_find_extent_enter(inode, es->start);
read_lock(&EXT4_I(inode)->i_es_lock);
tree = &EXT4_I(inode)->i_es_tree;
if (tree->cache_es) {
es1 = tree->cache_es;
if (in_range(es->start, es1->start, es1->len)) {
es_debug("%u cached by [%u/%u)\n",
es->start, es1->start, es1->len);
goto out;
}
}
es->len = 0;
es1 = __es_tree_search(&tree->root, es->start);
out:
if (es1) {
tree->cache_es = es1;
es->start = es1->start;
es->len = es1->len;
node = rb_next(&es1->rb_node);
if (node) {
es1 = rb_entry(node, struct extent_status, rb_node);
ret = es1->start;
}
}
read_unlock(&EXT4_I(inode)->i_es_lock);
trace_ext4_es_find_extent_exit(inode, es, ret);
return ret;
}
static struct extent_status *
ext4_es_alloc_extent(ext4_lblk_t start, ext4_lblk_t len)
{
struct extent_status *es;
es = kmem_cache_alloc(ext4_es_cachep, GFP_ATOMIC);
if (es == NULL)
return NULL;
es->start = start;
es->len = len;
return es;
}
static void ext4_es_free_extent(struct extent_status *es)
{
kmem_cache_free(ext4_es_cachep, es);
}
static struct extent_status *
ext4_es_try_to_merge_left(struct ext4_es_tree *tree, struct extent_status *es)
{
struct extent_status *es1;
struct rb_node *node;
node = rb_prev(&es->rb_node);
if (!node)
return es;
es1 = rb_entry(node, struct extent_status, rb_node);
if (es->start == extent_status_end(es1) + 1) {
es1->len += es->len;
rb_erase(&es->rb_node, &tree->root);
ext4_es_free_extent(es);
es = es1;
}
return es;
}
static struct extent_status *
ext4_es_try_to_merge_right(struct ext4_es_tree *tree, struct extent_status *es)
{
struct extent_status *es1;
struct rb_node *node;
node = rb_next(&es->rb_node);
if (!node)
return es;
es1 = rb_entry(node, struct extent_status, rb_node);
if (es1->start == extent_status_end(es) + 1) {
es->len += es1->len;
rb_erase(node, &tree->root);
ext4_es_free_extent(es1);
}
return es;
}
static int __es_insert_extent(struct ext4_es_tree *tree, ext4_lblk_t offset,
ext4_lblk_t len)
{
struct rb_node **p = &tree->root.rb_node;
struct rb_node *parent = NULL;
struct extent_status *es;
ext4_lblk_t end = offset + len - 1;
BUG_ON(end < offset);
es = tree->cache_es;
if (es && offset == (extent_status_end(es) + 1)) {
es_debug("cached by [%u/%u)\n", es->start, es->len);
es->len += len;
es = ext4_es_try_to_merge_right(tree, es);
goto out;
} else if (es && es->start == end + 1) {
es_debug("cached by [%u/%u)\n", es->start, es->len);
es->start = offset;
es->len += len;
es = ext4_es_try_to_merge_left(tree, es);
goto out;
} else if (es && es->start <= offset &&
end <= extent_status_end(es)) {
es_debug("cached by [%u/%u)\n", es->start, es->len);
goto out;
}
while (*p) {
parent = *p;
es = rb_entry(parent, struct extent_status, rb_node);
if (offset < es->start) {
if (es->start == end + 1) {
es->start = offset;
es->len += len;
es = ext4_es_try_to_merge_left(tree, es);
goto out;
}
p = &(*p)->rb_left;
} else if (offset > extent_status_end(es)) {
if (offset == extent_status_end(es) + 1) {
es->len += len;
es = ext4_es_try_to_merge_right(tree, es);
goto out;
}
p = &(*p)->rb_right;
} else {
if (extent_status_end(es) <= end)
es->len = offset - es->start + len;
goto out;
}
}
es = ext4_es_alloc_extent(offset, len);
if (!es)
return -ENOMEM;
rb_link_node(&es->rb_node, parent, p);
rb_insert_color(&es->rb_node, &tree->root);
out:
tree->cache_es = es;
return 0;
}
int ext4_es_insert_extent(struct inode *inode, ext4_lblk_t offset,
ext4_lblk_t len)
{
struct ext4_es_tree *tree;
int err = 0;
trace_ext4_es_insert_extent(inode, offset, len);
es_debug("add [%u/%u) to extent status tree of inode %lu\n",
offset, len, inode->i_ino);
write_lock(&EXT4_I(inode)->i_es_lock);
tree = &EXT4_I(inode)->i_es_tree;
err = __es_insert_extent(tree, offset, len);
write_unlock(&EXT4_I(inode)->i_es_lock);
ext4_es_print_tree(inode);
return err;
}
int ext4_es_remove_extent(struct inode *inode, ext4_lblk_t offset,
ext4_lblk_t len)
{
struct rb_node *node;
struct ext4_es_tree *tree;
struct extent_status *es;
struct extent_status orig_es;
ext4_lblk_t len1, len2, end;
int err = 0;
trace_ext4_es_remove_extent(inode, offset, len);
es_debug("remove [%u/%u) from extent status tree of inode %lu\n",
offset, len, inode->i_ino);
end = offset + len - 1;
BUG_ON(end < offset);
write_lock(&EXT4_I(inode)->i_es_lock);
tree = &EXT4_I(inode)->i_es_tree;
es = __es_tree_search(&tree->root, offset);
if (!es)
goto out;
if (es->start > end)
goto out;
tree->cache_es = NULL;
orig_es.start = es->start;
orig_es.len = es->len;
len1 = offset > es->start ? offset - es->start : 0;
len2 = extent_status_end(es) > end ?
extent_status_end(es) - end : 0;
if (len1 > 0)
es->len = len1;
if (len2 > 0) {
if (len1 > 0) {
err = __es_insert_extent(tree, end + 1, len2);
if (err) {
es->start = orig_es.start;
es->len = orig_es.len;
goto out;
}
} else {
es->start = end + 1;
es->len = len2;
}
goto out;
}
if (len1 > 0) {
node = rb_next(&es->rb_node);
if (node)
es = rb_entry(node, struct extent_status, rb_node);
else
es = NULL;
}
while (es && extent_status_end(es) <= end) {
node = rb_next(&es->rb_node);
rb_erase(&es->rb_node, &tree->root);
ext4_es_free_extent(es);
if (!node) {
es = NULL;
break;
}
es = rb_entry(node, struct extent_status, rb_node);
}
if (es && es->start < end + 1) {
len1 = extent_status_end(es) - end;
es->start = end + 1;
es->len = len1;
}
out:
write_unlock(&EXT4_I(inode)->i_es_lock);
ext4_es_print_tree(inode);
return err;
}
