int __init extent_map_init(void)
{
extent_map_cache = kmem_cache_create("extent_map",
sizeof(struct extent_map), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!extent_map_cache)
return -ENOMEM;
return 0;
}
void extent_map_exit(void)
{
if (extent_map_cache)
kmem_cache_destroy(extent_map_cache);
}
void extent_map_tree_init(struct extent_map_tree *tree)
{
tree->map = RB_ROOT;
rwlock_init(&tree->lock);
}
struct extent_map *alloc_extent_map(void)
{
struct extent_map *em;
em = kmem_cache_alloc(extent_map_cache, GFP_NOFS);
if (!em)
return NULL;
em->in_tree = 0;
em->flags = 0;
em->compress_type = BTRFS_COMPRESS_NONE;
atomic_set(&em->refs, 1);
return em;
}
void free_extent_map(struct extent_map *em)
{
if (!em)
return;
WARN_ON(atomic_read(&em->refs) == 0);
if (atomic_dec_and_test(&em->refs)) {
WARN_ON(em->in_tree);
kmem_cache_free(extent_map_cache, em);
}
}
static struct rb_node *tree_insert(struct rb_root *root, u64 offset,
struct rb_node *node)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct extent_map *entry;
while (*p) {
parent = *p;
entry = rb_entry(parent, struct extent_map, rb_node);
WARN_ON(!entry->in_tree);
if (offset < entry->start)
p = &(*p)->rb_left;
else if (offset >= extent_map_end(entry))
p = &(*p)->rb_right;
else
return parent;
}
entry = rb_entry(node, struct extent_map, rb_node);
entry->in_tree = 1;
rb_link_node(node, parent, p);
rb_insert_color(node, root);
return NULL;
}
static struct rb_node *__tree_search(struct rb_root *root, u64 offset,
struct rb_node **prev_ret,
struct rb_node **next_ret)
{
struct rb_node *n = root->rb_node;
struct rb_node *prev = NULL;
struct rb_node *orig_prev = NULL;
struct extent_map *entry;
struct extent_map *prev_entry = NULL;
while (n) {
entry = rb_entry(n, struct extent_map, rb_node);
prev = n;
prev_entry = entry;
WARN_ON(!entry->in_tree);
if (offset < entry->start)
n = n->rb_left;
else if (offset >= extent_map_end(entry))
n = n->rb_right;
else
return n;
}
if (prev_ret) {
orig_prev = prev;
while (prev && offset >= extent_map_end(prev_entry)) {
prev = rb_next(prev);
prev_entry = rb_entry(prev, struct extent_map, rb_node);
}
*prev_ret = prev;
prev = orig_prev;
}
if (next_ret) {
prev_entry = rb_entry(prev, struct extent_map, rb_node);
while (prev && offset < prev_entry->start) {
prev = rb_prev(prev);
prev_entry = rb_entry(prev, struct extent_map, rb_node);
}
*next_ret = prev;
}
return NULL;
}
static int mergable_maps(struct extent_map *prev, struct extent_map *next)
{
if (test_bit(EXTENT_FLAG_PINNED, &prev->flags))
return 0;
if (test_bit(EXTENT_FLAG_COMPRESSED, &prev->flags))
return 0;
if (extent_map_end(prev) == next->start &&
prev->flags == next->flags &&
prev->bdev == next->bdev &&
((next->block_start == EXTENT_MAP_HOLE &&
prev->block_start == EXTENT_MAP_HOLE) ||
(next->block_start == EXTENT_MAP_INLINE &&
prev->block_start == EXTENT_MAP_INLINE) ||
(next->block_start == EXTENT_MAP_DELALLOC &&
prev->block_start == EXTENT_MAP_DELALLOC) ||
(next->block_start < EXTENT_MAP_LAST_BYTE - 1 &&
next->block_start == extent_map_block_end(prev)))) {
return 1;
}
return 0;
}
int unpin_extent_cache(struct extent_map_tree *tree, u64 start, u64 len)
{
int ret = 0;
struct extent_map *merge = NULL;
struct rb_node *rb;
struct extent_map *em;
write_lock(&tree->lock);
em = lookup_extent_mapping(tree, start, len);
WARN_ON(!em || em->start != start);
if (!em)
goto out;
clear_bit(EXTENT_FLAG_PINNED, &em->flags);
if (em->start != 0) {
rb = rb_prev(&em->rb_node);
if (rb)
merge = rb_entry(rb, struct extent_map, rb_node);
if (rb && mergable_maps(merge, em)) {
em->start = merge->start;
em->len += merge->len;
em->block_len += merge->block_len;
em->block_start = merge->block_start;
merge->in_tree = 0;
rb_erase(&merge->rb_node, &tree->map);
free_extent_map(merge);
}
}
rb = rb_next(&em->rb_node);
if (rb)
merge = rb_entry(rb, struct extent_map, rb_node);
if (rb && mergable_maps(em, merge)) {
em->len += merge->len;
em->block_len += merge->len;
rb_erase(&merge->rb_node, &tree->map);
merge->in_tree = 0;
free_extent_map(merge);
}
free_extent_map(em);
out:
write_unlock(&tree->lock);
return ret;
}
int add_extent_mapping(struct extent_map_tree *tree,
struct extent_map *em)
{
int ret = 0;
struct extent_map *merge = NULL;
struct rb_node *rb;
struct extent_map *exist;
exist = lookup_extent_mapping(tree, em->start, em->len);
if (exist) {
free_extent_map(exist);
ret = -EEXIST;
goto out;
}
rb = tree_insert(&tree->map, em->start, &em->rb_node);
if (rb) {
ret = -EEXIST;
goto out;
}
atomic_inc(&em->refs);
if (em->start != 0) {
rb = rb_prev(&em->rb_node);
if (rb)
merge = rb_entry(rb, struct extent_map, rb_node);
if (rb && mergable_maps(merge, em)) {
em->start = merge->start;
em->len += merge->len;
em->block_len += merge->block_len;
em->block_start = merge->block_start;
merge->in_tree = 0;
rb_erase(&merge->rb_node, &tree->map);
free_extent_map(merge);
}
}
rb = rb_next(&em->rb_node);
if (rb)
merge = rb_entry(rb, struct extent_map, rb_node);
if (rb && mergable_maps(em, merge)) {
em->len += merge->len;
em->block_len += merge->len;
rb_erase(&merge->rb_node, &tree->map);
merge->in_tree = 0;
free_extent_map(merge);
}
out:
return ret;
}
static u64 range_end(u64 start, u64 len)
{
if (start + len < start)
return (u64)-1;
return start + len;
}
struct extent_map *lookup_extent_mapping(struct extent_map_tree *tree,
u64 start, u64 len)
{
struct extent_map *em;
struct rb_node *rb_node;
struct rb_node *prev = NULL;
struct rb_node *next = NULL;
u64 end = range_end(start, len);
rb_node = __tree_search(&tree->map, start, &prev, &next);
if (!rb_node && prev) {
em = rb_entry(prev, struct extent_map, rb_node);
if (end > em->start && start < extent_map_end(em))
goto found;
}
if (!rb_node && next) {
em = rb_entry(next, struct extent_map, rb_node);
if (end > em->start && start < extent_map_end(em))
goto found;
}
if (!rb_node) {
em = NULL;
goto out;
}
if (IS_ERR(rb_node)) {
em = ERR_CAST(rb_node);
goto out;
}
em = rb_entry(rb_node, struct extent_map, rb_node);
if (end > em->start && start < extent_map_end(em))
goto found;
em = NULL;
goto out;
found:
atomic_inc(&em->refs);
out:
return em;
}
struct extent_map *search_extent_mapping(struct extent_map_tree *tree,
u64 start, u64 len)
{
struct extent_map *em;
struct rb_node *rb_node;
struct rb_node *prev = NULL;
struct rb_node *next = NULL;
rb_node = __tree_search(&tree->map, start, &prev, &next);
if (!rb_node && prev) {
em = rb_entry(prev, struct extent_map, rb_node);
goto found;
}
if (!rb_node && next) {
em = rb_entry(next, struct extent_map, rb_node);
goto found;
}
if (!rb_node) {
em = NULL;
goto out;
}
if (IS_ERR(rb_node)) {
em = ERR_CAST(rb_node);
goto out;
}
em = rb_entry(rb_node, struct extent_map, rb_node);
goto found;
em = NULL;
goto out;
found:
atomic_inc(&em->refs);
out:
return em;
}
int remove_extent_mapping(struct extent_map_tree *tree, struct extent_map *em)
{
int ret = 0;
WARN_ON(test_bit(EXTENT_FLAG_PINNED, &em->flags));
rb_erase(&em->rb_node, &tree->map);
em->in_tree = 0;
return ret;
}
