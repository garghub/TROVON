int __init extent_io_init(void)
{
extent_state_cache = kmem_cache_create("extent_state",
sizeof(struct extent_state), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!extent_state_cache)
return -ENOMEM;
extent_buffer_cache = kmem_cache_create("extent_buffers",
sizeof(struct extent_buffer), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!extent_buffer_cache)
goto free_state_cache;
return 0;
free_state_cache:
kmem_cache_destroy(extent_state_cache);
return -ENOMEM;
}
void extent_io_exit(void)
{
struct extent_state *state;
struct extent_buffer *eb;
while (!list_empty(&states)) {
state = list_entry(states.next, struct extent_state, leak_list);
printk(KERN_ERR "btrfs state leak: start %llu end %llu "
"state %lu in tree %p refs %d\n",
(unsigned long long)state->start,
(unsigned long long)state->end,
state->state, state->tree, atomic_read(&state->refs));
list_del(&state->leak_list);
kmem_cache_free(extent_state_cache, state);
}
while (!list_empty(&buffers)) {
eb = list_entry(buffers.next, struct extent_buffer, leak_list);
printk(KERN_ERR "btrfs buffer leak start %llu len %lu "
"refs %d\n", (unsigned long long)eb->start,
eb->len, atomic_read(&eb->refs));
list_del(&eb->leak_list);
kmem_cache_free(extent_buffer_cache, eb);
}
if (extent_state_cache)
kmem_cache_destroy(extent_state_cache);
if (extent_buffer_cache)
kmem_cache_destroy(extent_buffer_cache);
}
void extent_io_tree_init(struct extent_io_tree *tree,
struct address_space *mapping)
{
tree->state = RB_ROOT;
INIT_RADIX_TREE(&tree->buffer, GFP_ATOMIC);
tree->ops = NULL;
tree->dirty_bytes = 0;
spin_lock_init(&tree->lock);
spin_lock_init(&tree->buffer_lock);
tree->mapping = mapping;
}
static struct extent_state *alloc_extent_state(gfp_t mask)
{
struct extent_state *state;
#if LEAK_DEBUG
unsigned long flags;
#endif
state = kmem_cache_alloc(extent_state_cache, mask);
if (!state)
return state;
state->state = 0;
state->private = 0;
state->tree = NULL;
#if LEAK_DEBUG
spin_lock_irqsave(&leak_lock, flags);
list_add(&state->leak_list, &states);
spin_unlock_irqrestore(&leak_lock, flags);
#endif
atomic_set(&state->refs, 1);
init_waitqueue_head(&state->wq);
return state;
}
void free_extent_state(struct extent_state *state)
{
if (!state)
return;
if (atomic_dec_and_test(&state->refs)) {
#if LEAK_DEBUG
unsigned long flags;
#endif
WARN_ON(state->tree);
#if LEAK_DEBUG
spin_lock_irqsave(&leak_lock, flags);
list_del(&state->leak_list);
spin_unlock_irqrestore(&leak_lock, flags);
#endif
kmem_cache_free(extent_state_cache, state);
}
}
static struct rb_node *tree_insert(struct rb_root *root, u64 offset,
struct rb_node *node)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct tree_entry *entry;
while (*p) {
parent = *p;
entry = rb_entry(parent, struct tree_entry, rb_node);
if (offset < entry->start)
p = &(*p)->rb_left;
else if (offset > entry->end)
p = &(*p)->rb_right;
else
return parent;
}
entry = rb_entry(node, struct tree_entry, rb_node);
rb_link_node(node, parent, p);
rb_insert_color(node, root);
return NULL;
}
static struct rb_node *__etree_search(struct extent_io_tree *tree, u64 offset,
struct rb_node **prev_ret,
struct rb_node **next_ret)
{
struct rb_root *root = &tree->state;
struct rb_node *n = root->rb_node;
struct rb_node *prev = NULL;
struct rb_node *orig_prev = NULL;
struct tree_entry *entry;
struct tree_entry *prev_entry = NULL;
while (n) {
entry = rb_entry(n, struct tree_entry, rb_node);
prev = n;
prev_entry = entry;
if (offset < entry->start)
n = n->rb_left;
else if (offset > entry->end)
n = n->rb_right;
else
return n;
}
if (prev_ret) {
orig_prev = prev;
while (prev && offset > prev_entry->end) {
prev = rb_next(prev);
prev_entry = rb_entry(prev, struct tree_entry, rb_node);
}
*prev_ret = prev;
prev = orig_prev;
}
if (next_ret) {
prev_entry = rb_entry(prev, struct tree_entry, rb_node);
while (prev && offset < prev_entry->start) {
prev = rb_prev(prev);
prev_entry = rb_entry(prev, struct tree_entry, rb_node);
}
*next_ret = prev;
}
return NULL;
}
static inline struct rb_node *tree_search(struct extent_io_tree *tree,
u64 offset)
{
struct rb_node *prev = NULL;
struct rb_node *ret;
ret = __etree_search(tree, offset, &prev, NULL);
if (!ret)
return prev;
return ret;
}
static void merge_cb(struct extent_io_tree *tree, struct extent_state *new,
struct extent_state *other)
{
if (tree->ops && tree->ops->merge_extent_hook)
tree->ops->merge_extent_hook(tree->mapping->host, new,
other);
}
static int merge_state(struct extent_io_tree *tree,
struct extent_state *state)
{
struct extent_state *other;
struct rb_node *other_node;
if (state->state & (EXTENT_IOBITS | EXTENT_BOUNDARY))
return 0;
other_node = rb_prev(&state->rb_node);
if (other_node) {
other = rb_entry(other_node, struct extent_state, rb_node);
if (other->end == state->start - 1 &&
other->state == state->state) {
merge_cb(tree, state, other);
state->start = other->start;
other->tree = NULL;
rb_erase(&other->rb_node, &tree->state);
free_extent_state(other);
}
}
other_node = rb_next(&state->rb_node);
if (other_node) {
other = rb_entry(other_node, struct extent_state, rb_node);
if (other->start == state->end + 1 &&
other->state == state->state) {
merge_cb(tree, state, other);
other->start = state->start;
state->tree = NULL;
rb_erase(&state->rb_node, &tree->state);
free_extent_state(state);
state = NULL;
}
}
return 0;
}
static int set_state_cb(struct extent_io_tree *tree,
struct extent_state *state, int *bits)
{
if (tree->ops && tree->ops->set_bit_hook) {
return tree->ops->set_bit_hook(tree->mapping->host,
state, bits);
}
return 0;
}
static void clear_state_cb(struct extent_io_tree *tree,
struct extent_state *state, int *bits)
{
if (tree->ops && tree->ops->clear_bit_hook)
tree->ops->clear_bit_hook(tree->mapping->host, state, bits);
}
static int insert_state(struct extent_io_tree *tree,
struct extent_state *state, u64 start, u64 end,
int *bits)
{
struct rb_node *node;
int bits_to_set = *bits & ~EXTENT_CTLBITS;
int ret;
if (end < start) {
printk(KERN_ERR "btrfs end < start %llu %llu\n",
(unsigned long long)end,
(unsigned long long)start);
WARN_ON(1);
}
state->start = start;
state->end = end;
ret = set_state_cb(tree, state, bits);
if (ret)
return ret;
if (bits_to_set & EXTENT_DIRTY)
tree->dirty_bytes += end - start + 1;
state->state |= bits_to_set;
node = tree_insert(&tree->state, end, &state->rb_node);
if (node) {
struct extent_state *found;
found = rb_entry(node, struct extent_state, rb_node);
printk(KERN_ERR "btrfs found node %llu %llu on insert of "
"%llu %llu\n", (unsigned long long)found->start,
(unsigned long long)found->end,
(unsigned long long)start, (unsigned long long)end);
free_extent_state(state);
return -EEXIST;
}
state->tree = tree;
merge_state(tree, state);
return 0;
}
static int split_cb(struct extent_io_tree *tree, struct extent_state *orig,
u64 split)
{
if (tree->ops && tree->ops->split_extent_hook)
return tree->ops->split_extent_hook(tree->mapping->host,
orig, split);
return 0;
}
static int split_state(struct extent_io_tree *tree, struct extent_state *orig,
struct extent_state *prealloc, u64 split)
{
struct rb_node *node;
split_cb(tree, orig, split);
prealloc->start = orig->start;
prealloc->end = split - 1;
prealloc->state = orig->state;
orig->start = split;
node = tree_insert(&tree->state, prealloc->end, &prealloc->rb_node);
if (node) {
free_extent_state(prealloc);
return -EEXIST;
}
prealloc->tree = tree;
return 0;
}
static int clear_state_bit(struct extent_io_tree *tree,
struct extent_state *state,
int *bits, int wake)
{
int bits_to_clear = *bits & ~EXTENT_CTLBITS;
int ret = state->state & bits_to_clear;
if ((bits_to_clear & EXTENT_DIRTY) && (state->state & EXTENT_DIRTY)) {
u64 range = state->end - state->start + 1;
WARN_ON(range > tree->dirty_bytes);
tree->dirty_bytes -= range;
}
clear_state_cb(tree, state, bits);
state->state &= ~bits_to_clear;
if (wake)
wake_up(&state->wq);
if (state->state == 0) {
if (state->tree) {
rb_erase(&state->rb_node, &tree->state);
state->tree = NULL;
free_extent_state(state);
} else {
WARN_ON(1);
}
} else {
merge_state(tree, state);
}
return ret;
}
static struct extent_state *
alloc_extent_state_atomic(struct extent_state *prealloc)
{
if (!prealloc)
prealloc = alloc_extent_state(GFP_ATOMIC);
return prealloc;
}
int clear_extent_bit(struct extent_io_tree *tree, u64 start, u64 end,
int bits, int wake, int delete,
struct extent_state **cached_state,
gfp_t mask)
{
struct extent_state *state;
struct extent_state *cached;
struct extent_state *prealloc = NULL;
struct rb_node *next_node;
struct rb_node *node;
u64 last_end;
int err;
int set = 0;
int clear = 0;
if (delete)
bits |= ~EXTENT_CTLBITS;
bits |= EXTENT_FIRST_DELALLOC;
if (bits & (EXTENT_IOBITS | EXTENT_BOUNDARY))
clear = 1;
again:
if (!prealloc && (mask & __GFP_WAIT)) {
prealloc = alloc_extent_state(mask);
if (!prealloc)
return -ENOMEM;
}
spin_lock(&tree->lock);
if (cached_state) {
cached = *cached_state;
if (clear) {
*cached_state = NULL;
cached_state = NULL;
}
if (cached && cached->tree && cached->start == start) {
if (clear)
atomic_dec(&cached->refs);
state = cached;
goto hit_next;
}
if (clear)
free_extent_state(cached);
}
node = tree_search(tree, start);
if (!node)
goto out;
state = rb_entry(node, struct extent_state, rb_node);
hit_next:
if (state->start > end)
goto out;
WARN_ON(state->end < start);
last_end = state->end;
if (state->start < start) {
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
err = split_state(tree, state, prealloc, start);
BUG_ON(err == -EEXIST);
prealloc = NULL;
if (err)
goto out;
if (state->end <= end) {
set |= clear_state_bit(tree, state, &bits, wake);
if (last_end == (u64)-1)
goto out;
start = last_end + 1;
}
goto search_again;
}
if (state->start <= end && state->end > end) {
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
err = split_state(tree, state, prealloc, end + 1);
BUG_ON(err == -EEXIST);
if (wake)
wake_up(&state->wq);
set |= clear_state_bit(tree, prealloc, &bits, wake);
prealloc = NULL;
goto out;
}
if (state->end < end && prealloc && !need_resched())
next_node = rb_next(&state->rb_node);
else
next_node = NULL;
set |= clear_state_bit(tree, state, &bits, wake);
if (last_end == (u64)-1)
goto out;
start = last_end + 1;
if (start <= end && next_node) {
state = rb_entry(next_node, struct extent_state,
rb_node);
if (state->start == start)
goto hit_next;
}
goto search_again;
out:
spin_unlock(&tree->lock);
if (prealloc)
free_extent_state(prealloc);
return set;
search_again:
if (start > end)
goto out;
spin_unlock(&tree->lock);
if (mask & __GFP_WAIT)
cond_resched();
goto again;
}
static int wait_on_state(struct extent_io_tree *tree,
struct extent_state *state)
__releases(tree->lock)
__acquires(tree->lock)
{
DEFINE_WAIT(wait);
prepare_to_wait(&state->wq, &wait, TASK_UNINTERRUPTIBLE);
spin_unlock(&tree->lock);
schedule();
spin_lock(&tree->lock);
finish_wait(&state->wq, &wait);
return 0;
}
int wait_extent_bit(struct extent_io_tree *tree, u64 start, u64 end, int bits)
{
struct extent_state *state;
struct rb_node *node;
spin_lock(&tree->lock);
again:
while (1) {
node = tree_search(tree, start);
if (!node)
break;
state = rb_entry(node, struct extent_state, rb_node);
if (state->start > end)
goto out;
if (state->state & bits) {
start = state->start;
atomic_inc(&state->refs);
wait_on_state(tree, state);
free_extent_state(state);
goto again;
}
start = state->end + 1;
if (start > end)
break;
if (need_resched()) {
spin_unlock(&tree->lock);
cond_resched();
spin_lock(&tree->lock);
}
}
out:
spin_unlock(&tree->lock);
return 0;
}
static int set_state_bits(struct extent_io_tree *tree,
struct extent_state *state,
int *bits)
{
int ret;
int bits_to_set = *bits & ~EXTENT_CTLBITS;
ret = set_state_cb(tree, state, bits);
if (ret)
return ret;
if ((bits_to_set & EXTENT_DIRTY) && !(state->state & EXTENT_DIRTY)) {
u64 range = state->end - state->start + 1;
tree->dirty_bytes += range;
}
state->state |= bits_to_set;
return 0;
}
static void cache_state(struct extent_state *state,
struct extent_state **cached_ptr)
{
if (cached_ptr && !(*cached_ptr)) {
if (state->state & (EXTENT_IOBITS | EXTENT_BOUNDARY)) {
*cached_ptr = state;
atomic_inc(&state->refs);
}
}
}
static void uncache_state(struct extent_state **cached_ptr)
{
if (cached_ptr && (*cached_ptr)) {
struct extent_state *state = *cached_ptr;
*cached_ptr = NULL;
free_extent_state(state);
}
}
int set_extent_bit(struct extent_io_tree *tree, u64 start, u64 end,
int bits, int exclusive_bits, u64 *failed_start,
struct extent_state **cached_state, gfp_t mask)
{
struct extent_state *state;
struct extent_state *prealloc = NULL;
struct rb_node *node;
int err = 0;
u64 last_start;
u64 last_end;
bits |= EXTENT_FIRST_DELALLOC;
again:
if (!prealloc && (mask & __GFP_WAIT)) {
prealloc = alloc_extent_state(mask);
BUG_ON(!prealloc);
}
spin_lock(&tree->lock);
if (cached_state && *cached_state) {
state = *cached_state;
if (state->start == start && state->tree) {
node = &state->rb_node;
goto hit_next;
}
}
node = tree_search(tree, start);
if (!node) {
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
err = insert_state(tree, prealloc, start, end, &bits);
prealloc = NULL;
BUG_ON(err == -EEXIST);
goto out;
}
state = rb_entry(node, struct extent_state, rb_node);
hit_next:
last_start = state->start;
last_end = state->end;
if (state->start == start && state->end <= end) {
struct rb_node *next_node;
if (state->state & exclusive_bits) {
*failed_start = state->start;
err = -EEXIST;
goto out;
}
err = set_state_bits(tree, state, &bits);
if (err)
goto out;
next_node = rb_next(node);
cache_state(state, cached_state);
merge_state(tree, state);
if (last_end == (u64)-1)
goto out;
start = last_end + 1;
if (next_node && start < end && prealloc && !need_resched()) {
state = rb_entry(next_node, struct extent_state,
rb_node);
if (state->start == start)
goto hit_next;
}
goto search_again;
}
if (state->start < start) {
if (state->state & exclusive_bits) {
*failed_start = start;
err = -EEXIST;
goto out;
}
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
err = split_state(tree, state, prealloc, start);
BUG_ON(err == -EEXIST);
prealloc = NULL;
if (err)
goto out;
if (state->end <= end) {
err = set_state_bits(tree, state, &bits);
if (err)
goto out;
cache_state(state, cached_state);
merge_state(tree, state);
if (last_end == (u64)-1)
goto out;
start = last_end + 1;
}
goto search_again;
}
if (state->start > start) {
u64 this_end;
if (end < last_start)
this_end = end;
else
this_end = last_start - 1;
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
atomic_inc(&prealloc->refs);
err = insert_state(tree, prealloc, start, this_end,
&bits);
BUG_ON(err == -EEXIST);
if (err) {
free_extent_state(prealloc);
prealloc = NULL;
goto out;
}
cache_state(prealloc, cached_state);
free_extent_state(prealloc);
prealloc = NULL;
start = this_end + 1;
goto search_again;
}
if (state->start <= end && state->end > end) {
if (state->state & exclusive_bits) {
*failed_start = start;
err = -EEXIST;
goto out;
}
prealloc = alloc_extent_state_atomic(prealloc);
BUG_ON(!prealloc);
err = split_state(tree, state, prealloc, end + 1);
BUG_ON(err == -EEXIST);
err = set_state_bits(tree, prealloc, &bits);
if (err) {
prealloc = NULL;
goto out;
}
cache_state(prealloc, cached_state);
merge_state(tree, prealloc);
prealloc = NULL;
goto out;
}
goto search_again;
out:
spin_unlock(&tree->lock);
if (prealloc)
free_extent_state(prealloc);
return err;
search_again:
if (start > end)
goto out;
spin_unlock(&tree->lock);
if (mask & __GFP_WAIT)
cond_resched();
goto again;
}
int set_extent_dirty(struct extent_io_tree *tree, u64 start, u64 end,
gfp_t mask)
{
return set_extent_bit(tree, start, end, EXTENT_DIRTY, 0, NULL,
NULL, mask);
}
int set_extent_bits(struct extent_io_tree *tree, u64 start, u64 end,
int bits, gfp_t mask)
{
return set_extent_bit(tree, start, end, bits, 0, NULL,
NULL, mask);
}
int clear_extent_bits(struct extent_io_tree *tree, u64 start, u64 end,
int bits, gfp_t mask)
{
return clear_extent_bit(tree, start, end, bits, 0, 0, NULL, mask);
}
int set_extent_delalloc(struct extent_io_tree *tree, u64 start, u64 end,
struct extent_state **cached_state, gfp_t mask)
{
return set_extent_bit(tree, start, end,
EXTENT_DELALLOC | EXTENT_DIRTY | EXTENT_UPTODATE,
0, NULL, cached_state, mask);
}
int clear_extent_dirty(struct extent_io_tree *tree, u64 start, u64 end,
gfp_t mask)
{
return clear_extent_bit(tree, start, end,
EXTENT_DIRTY | EXTENT_DELALLOC |
EXTENT_DO_ACCOUNTING, 0, 0, NULL, mask);
}
int set_extent_new(struct extent_io_tree *tree, u64 start, u64 end,
gfp_t mask)
{
return set_extent_bit(tree, start, end, EXTENT_NEW, 0, NULL,
NULL, mask);
}
int set_extent_uptodate(struct extent_io_tree *tree, u64 start, u64 end,
struct extent_state **cached_state, gfp_t mask)
{
return set_extent_bit(tree, start, end, EXTENT_UPTODATE, 0,
NULL, cached_state, mask);
}
static int clear_extent_uptodate(struct extent_io_tree *tree, u64 start,
u64 end, struct extent_state **cached_state,
gfp_t mask)
{
return clear_extent_bit(tree, start, end, EXTENT_UPTODATE, 0, 0,
cached_state, mask);
}
int lock_extent_bits(struct extent_io_tree *tree, u64 start, u64 end,
int bits, struct extent_state **cached_state, gfp_t mask)
{
int err;
u64 failed_start;
while (1) {
err = set_extent_bit(tree, start, end, EXTENT_LOCKED | bits,
EXTENT_LOCKED, &failed_start,
cached_state, mask);
if (err == -EEXIST && (mask & __GFP_WAIT)) {
wait_extent_bit(tree, failed_start, end, EXTENT_LOCKED);
start = failed_start;
} else {
break;
}
WARN_ON(start > end);
}
return err;
}
int lock_extent(struct extent_io_tree *tree, u64 start, u64 end, gfp_t mask)
{
return lock_extent_bits(tree, start, end, 0, NULL, mask);
}
int try_lock_extent(struct extent_io_tree *tree, u64 start, u64 end,
gfp_t mask)
{
int err;
u64 failed_start;
err = set_extent_bit(tree, start, end, EXTENT_LOCKED, EXTENT_LOCKED,
&failed_start, NULL, mask);
if (err == -EEXIST) {
if (failed_start > start)
clear_extent_bit(tree, start, failed_start - 1,
EXTENT_LOCKED, 1, 0, NULL, mask);
return 0;
}
return 1;
}
int unlock_extent_cached(struct extent_io_tree *tree, u64 start, u64 end,
struct extent_state **cached, gfp_t mask)
{
return clear_extent_bit(tree, start, end, EXTENT_LOCKED, 1, 0, cached,
mask);
}
int unlock_extent(struct extent_io_tree *tree, u64 start, u64 end, gfp_t mask)
{
return clear_extent_bit(tree, start, end, EXTENT_LOCKED, 1, 0, NULL,
mask);
}
static int set_range_writeback(struct extent_io_tree *tree, u64 start, u64 end)
{
unsigned long index = start >> PAGE_CACHE_SHIFT;
unsigned long end_index = end >> PAGE_CACHE_SHIFT;
struct page *page;
while (index <= end_index) {
page = find_get_page(tree->mapping, index);
BUG_ON(!page);
set_page_writeback(page);
page_cache_release(page);
index++;
}
return 0;
}
int find_first_extent_bit(struct extent_io_tree *tree, u64 start,
u64 *start_ret, u64 *end_ret, int bits)
{
struct rb_node *node;
struct extent_state *state;
int ret = 1;
spin_lock(&tree->lock);
node = tree_search(tree, start);
if (!node)
goto out;
while (1) {
state = rb_entry(node, struct extent_state, rb_node);
if (state->end >= start && (state->state & bits)) {
*start_ret = state->start;
*end_ret = state->end;
ret = 0;
break;
}
node = rb_next(node);
if (!node)
break;
}
out:
spin_unlock(&tree->lock);
return ret;
}
struct extent_state *find_first_extent_bit_state(struct extent_io_tree *tree,
u64 start, int bits)
{
struct rb_node *node;
struct extent_state *state;
node = tree_search(tree, start);
if (!node)
goto out;
while (1) {
state = rb_entry(node, struct extent_state, rb_node);
if (state->end >= start && (state->state & bits))
return state;
node = rb_next(node);
if (!node)
break;
}
out:
return NULL;
}
static noinline u64 find_delalloc_range(struct extent_io_tree *tree,
u64 *start, u64 *end, u64 max_bytes,
struct extent_state **cached_state)
{
struct rb_node *node;
struct extent_state *state;
u64 cur_start = *start;
u64 found = 0;
u64 total_bytes = 0;
spin_lock(&tree->lock);
node = tree_search(tree, cur_start);
if (!node) {
if (!found)
*end = (u64)-1;
goto out;
}
while (1) {
state = rb_entry(node, struct extent_state, rb_node);
if (found && (state->start != cur_start ||
(state->state & EXTENT_BOUNDARY))) {
goto out;
}
if (!(state->state & EXTENT_DELALLOC)) {
if (!found)
*end = state->end;
goto out;
}
if (!found) {
*start = state->start;
*cached_state = state;
atomic_inc(&state->refs);
}
found++;
*end = state->end;
cur_start = state->end + 1;
node = rb_next(node);
if (!node)
break;
total_bytes += state->end - state->start + 1;
if (total_bytes >= max_bytes)
break;
}
out:
spin_unlock(&tree->lock);
return found;
}
static noinline int __unlock_for_delalloc(struct inode *inode,
struct page *locked_page,
u64 start, u64 end)
{
int ret;
struct page *pages[16];
unsigned long index = start >> PAGE_CACHE_SHIFT;
unsigned long end_index = end >> PAGE_CACHE_SHIFT;
unsigned long nr_pages = end_index - index + 1;
int i;
if (index == locked_page->index && end_index == index)
return 0;
while (nr_pages > 0) {
ret = find_get_pages_contig(inode->i_mapping, index,
min_t(unsigned long, nr_pages,
ARRAY_SIZE(pages)), pages);
for (i = 0; i < ret; i++) {
if (pages[i] != locked_page)
unlock_page(pages[i]);
page_cache_release(pages[i]);
}
nr_pages -= ret;
index += ret;
cond_resched();
}
return 0;
}
static noinline int lock_delalloc_pages(struct inode *inode,
struct page *locked_page,
u64 delalloc_start,
u64 delalloc_end)
{
unsigned long index = delalloc_start >> PAGE_CACHE_SHIFT;
unsigned long start_index = index;
unsigned long end_index = delalloc_end >> PAGE_CACHE_SHIFT;
unsigned long pages_locked = 0;
struct page *pages[16];
unsigned long nrpages;
int ret;
int i;
if (index == locked_page->index && index == end_index)
return 0;
nrpages = end_index - index + 1;
while (nrpages > 0) {
ret = find_get_pages_contig(inode->i_mapping, index,
min_t(unsigned long,
nrpages, ARRAY_SIZE(pages)), pages);
if (ret == 0) {
ret = -EAGAIN;
goto done;
}
for (i = 0; i < ret; i++) {
if (pages[i] != locked_page) {
lock_page(pages[i]);
if (!PageDirty(pages[i]) ||
pages[i]->mapping != inode->i_mapping) {
ret = -EAGAIN;
unlock_page(pages[i]);
page_cache_release(pages[i]);
goto done;
}
}
page_cache_release(pages[i]);
pages_locked++;
}
nrpages -= ret;
index += ret;
cond_resched();
}
ret = 0;
done:
if (ret && pages_locked) {
__unlock_for_delalloc(inode, locked_page,
delalloc_start,
((u64)(start_index + pages_locked - 1)) <<
PAGE_CACHE_SHIFT);
}
return ret;
}
static noinline u64 find_lock_delalloc_range(struct inode *inode,
struct extent_io_tree *tree,
struct page *locked_page,
u64 *start, u64 *end,
u64 max_bytes)
{
u64 delalloc_start;
u64 delalloc_end;
u64 found;
struct extent_state *cached_state = NULL;
int ret;
int loops = 0;
again:
delalloc_start = *start;
delalloc_end = 0;
found = find_delalloc_range(tree, &delalloc_start, &delalloc_end,
max_bytes, &cached_state);
if (!found || delalloc_end <= *start) {
*start = delalloc_start;
*end = delalloc_end;
free_extent_state(cached_state);
return found;
}
if (delalloc_start < *start)
delalloc_start = *start;
if (delalloc_end + 1 - delalloc_start > max_bytes && loops)
delalloc_end = delalloc_start + PAGE_CACHE_SIZE - 1;
ret = lock_delalloc_pages(inode, locked_page,
delalloc_start, delalloc_end);
if (ret == -EAGAIN) {
free_extent_state(cached_state);
if (!loops) {
unsigned long offset = (*start) & (PAGE_CACHE_SIZE - 1);
max_bytes = PAGE_CACHE_SIZE - offset;
loops = 1;
goto again;
} else {
found = 0;
goto out_failed;
}
}
BUG_ON(ret);
lock_extent_bits(tree, delalloc_start, delalloc_end,
0, &cached_state, GFP_NOFS);
ret = test_range_bit(tree, delalloc_start, delalloc_end,
EXTENT_DELALLOC, 1, cached_state);
if (!ret) {
unlock_extent_cached(tree, delalloc_start, delalloc_end,
&cached_state, GFP_NOFS);
__unlock_for_delalloc(inode, locked_page,
delalloc_start, delalloc_end);
cond_resched();
goto again;
}
free_extent_state(cached_state);
*start = delalloc_start;
*end = delalloc_end;
out_failed:
return found;
}
int extent_clear_unlock_delalloc(struct inode *inode,
struct extent_io_tree *tree,
u64 start, u64 end, struct page *locked_page,
unsigned long op)
{
int ret;
struct page *pages[16];
unsigned long index = start >> PAGE_CACHE_SHIFT;
unsigned long end_index = end >> PAGE_CACHE_SHIFT;
unsigned long nr_pages = end_index - index + 1;
int i;
int clear_bits = 0;
if (op & EXTENT_CLEAR_UNLOCK)
clear_bits |= EXTENT_LOCKED;
if (op & EXTENT_CLEAR_DIRTY)
clear_bits |= EXTENT_DIRTY;
if (op & EXTENT_CLEAR_DELALLOC)
clear_bits |= EXTENT_DELALLOC;
clear_extent_bit(tree, start, end, clear_bits, 1, 0, NULL, GFP_NOFS);
if (!(op & (EXTENT_CLEAR_UNLOCK_PAGE | EXTENT_CLEAR_DIRTY |
EXTENT_SET_WRITEBACK | EXTENT_END_WRITEBACK |
EXTENT_SET_PRIVATE2)))
return 0;
while (nr_pages > 0) {
ret = find_get_pages_contig(inode->i_mapping, index,
min_t(unsigned long,
nr_pages, ARRAY_SIZE(pages)), pages);
for (i = 0; i < ret; i++) {
if (op & EXTENT_SET_PRIVATE2)
SetPagePrivate2(pages[i]);
if (pages[i] == locked_page) {
page_cache_release(pages[i]);
continue;
}
if (op & EXTENT_CLEAR_DIRTY)
clear_page_dirty_for_io(pages[i]);
if (op & EXTENT_SET_WRITEBACK)
set_page_writeback(pages[i]);
if (op & EXTENT_END_WRITEBACK)
end_page_writeback(pages[i]);
if (op & EXTENT_CLEAR_UNLOCK_PAGE)
unlock_page(pages[i]);
page_cache_release(pages[i]);
}
nr_pages -= ret;
index += ret;
cond_resched();
}
return 0;
}
u64 count_range_bits(struct extent_io_tree *tree,
u64 *start, u64 search_end, u64 max_bytes,
unsigned long bits, int contig)
{
struct rb_node *node;
struct extent_state *state;
u64 cur_start = *start;
u64 total_bytes = 0;
u64 last = 0;
int found = 0;
if (search_end <= cur_start) {
WARN_ON(1);
return 0;
}
spin_lock(&tree->lock);
if (cur_start == 0 && bits == EXTENT_DIRTY) {
total_bytes = tree->dirty_bytes;
goto out;
}
node = tree_search(tree, cur_start);
if (!node)
goto out;
while (1) {
state = rb_entry(node, struct extent_state, rb_node);
if (state->start > search_end)
break;
if (contig && found && state->start > last + 1)
break;
if (state->end >= cur_start && (state->state & bits) == bits) {
total_bytes += min(search_end, state->end) + 1 -
max(cur_start, state->start);
if (total_bytes >= max_bytes)
break;
if (!found) {
*start = max(cur_start, state->start);
found = 1;
}
last = state->end;
} else if (contig && found) {
break;
}
node = rb_next(node);
if (!node)
break;
}
out:
spin_unlock(&tree->lock);
return total_bytes;
}
int set_state_private(struct extent_io_tree *tree, u64 start, u64 private)
{
struct rb_node *node;
struct extent_state *state;
int ret = 0;
spin_lock(&tree->lock);
node = tree_search(tree, start);
if (!node) {
ret = -ENOENT;
goto out;
}
state = rb_entry(node, struct extent_state, rb_node);
if (state->start != start) {
ret = -ENOENT;
goto out;
}
state->private = private;
out:
spin_unlock(&tree->lock);
return ret;
}
int get_state_private(struct extent_io_tree *tree, u64 start, u64 *private)
{
struct rb_node *node;
struct extent_state *state;
int ret = 0;
spin_lock(&tree->lock);
node = tree_search(tree, start);
if (!node) {
ret = -ENOENT;
goto out;
}
state = rb_entry(node, struct extent_state, rb_node);
if (state->start != start) {
ret = -ENOENT;
goto out;
}
*private = state->private;
out:
spin_unlock(&tree->lock);
return ret;
}
int test_range_bit(struct extent_io_tree *tree, u64 start, u64 end,
int bits, int filled, struct extent_state *cached)
{
struct extent_state *state = NULL;
struct rb_node *node;
int bitset = 0;
spin_lock(&tree->lock);
if (cached && cached->tree && cached->start == start)
node = &cached->rb_node;
else
node = tree_search(tree, start);
while (node && start <= end) {
state = rb_entry(node, struct extent_state, rb_node);
if (filled && state->start > start) {
bitset = 0;
break;
}
if (state->start > end)
break;
if (state->state & bits) {
bitset = 1;
if (!filled)
break;
} else if (filled) {
bitset = 0;
break;
}
if (state->end == (u64)-1)
break;
start = state->end + 1;
if (start > end)
break;
node = rb_next(node);
if (!node) {
if (filled)
bitset = 0;
break;
}
}
spin_unlock(&tree->lock);
return bitset;
}
static int check_page_uptodate(struct extent_io_tree *tree,
struct page *page)
{
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 end = start + PAGE_CACHE_SIZE - 1;
if (test_range_bit(tree, start, end, EXTENT_UPTODATE, 1, NULL))
SetPageUptodate(page);
return 0;
}
static int check_page_locked(struct extent_io_tree *tree,
struct page *page)
{
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 end = start + PAGE_CACHE_SIZE - 1;
if (!test_range_bit(tree, start, end, EXTENT_LOCKED, 0, NULL))
unlock_page(page);
return 0;
}
static int check_page_writeback(struct extent_io_tree *tree,
struct page *page)
{
end_page_writeback(page);
return 0;
}
static void end_bio_extent_writepage(struct bio *bio, int err)
{
int uptodate = err == 0;
struct bio_vec *bvec = bio->bi_io_vec + bio->bi_vcnt - 1;
struct extent_io_tree *tree;
u64 start;
u64 end;
int whole_page;
int ret;
do {
struct page *page = bvec->bv_page;
tree = &BTRFS_I(page->mapping->host)->io_tree;
start = ((u64)page->index << PAGE_CACHE_SHIFT) +
bvec->bv_offset;
end = start + bvec->bv_len - 1;
if (bvec->bv_offset == 0 && bvec->bv_len == PAGE_CACHE_SIZE)
whole_page = 1;
else
whole_page = 0;
if (--bvec >= bio->bi_io_vec)
prefetchw(&bvec->bv_page->flags);
if (tree->ops && tree->ops->writepage_end_io_hook) {
ret = tree->ops->writepage_end_io_hook(page, start,
end, NULL, uptodate);
if (ret)
uptodate = 0;
}
if (!uptodate && tree->ops &&
tree->ops->writepage_io_failed_hook) {
ret = tree->ops->writepage_io_failed_hook(bio, page,
start, end, NULL);
if (ret == 0) {
uptodate = (err == 0);
continue;
}
}
if (!uptodate) {
clear_extent_uptodate(tree, start, end, NULL, GFP_NOFS);
ClearPageUptodate(page);
SetPageError(page);
}
if (whole_page)
end_page_writeback(page);
else
check_page_writeback(tree, page);
} while (bvec >= bio->bi_io_vec);
bio_put(bio);
}
static void end_bio_extent_readpage(struct bio *bio, int err)
{
int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct bio_vec *bvec_end = bio->bi_io_vec + bio->bi_vcnt - 1;
struct bio_vec *bvec = bio->bi_io_vec;
struct extent_io_tree *tree;
u64 start;
u64 end;
int whole_page;
int ret;
if (err)
uptodate = 0;
do {
struct page *page = bvec->bv_page;
struct extent_state *cached = NULL;
struct extent_state *state;
tree = &BTRFS_I(page->mapping->host)->io_tree;
start = ((u64)page->index << PAGE_CACHE_SHIFT) +
bvec->bv_offset;
end = start + bvec->bv_len - 1;
if (bvec->bv_offset == 0 && bvec->bv_len == PAGE_CACHE_SIZE)
whole_page = 1;
else
whole_page = 0;
if (++bvec <= bvec_end)
prefetchw(&bvec->bv_page->flags);
spin_lock(&tree->lock);
state = find_first_extent_bit_state(tree, start, EXTENT_LOCKED);
if (state && state->start == start) {
cache_state(state, &cached);
}
spin_unlock(&tree->lock);
if (uptodate && tree->ops && tree->ops->readpage_end_io_hook) {
ret = tree->ops->readpage_end_io_hook(page, start, end,
state);
if (ret)
uptodate = 0;
}
if (!uptodate && tree->ops &&
tree->ops->readpage_io_failed_hook) {
ret = tree->ops->readpage_io_failed_hook(bio, page,
start, end, NULL);
if (ret == 0) {
uptodate =
test_bit(BIO_UPTODATE, &bio->bi_flags);
if (err)
uptodate = 0;
uncache_state(&cached);
continue;
}
}
if (uptodate) {
set_extent_uptodate(tree, start, end, &cached,
GFP_ATOMIC);
}
unlock_extent_cached(tree, start, end, &cached, GFP_ATOMIC);
if (whole_page) {
if (uptodate) {
SetPageUptodate(page);
} else {
ClearPageUptodate(page);
SetPageError(page);
}
unlock_page(page);
} else {
if (uptodate) {
check_page_uptodate(tree, page);
} else {
ClearPageUptodate(page);
SetPageError(page);
}
check_page_locked(tree, page);
}
} while (bvec <= bvec_end);
bio_put(bio);
}
struct bio *
btrfs_bio_alloc(struct block_device *bdev, u64 first_sector, int nr_vecs,
gfp_t gfp_flags)
{
struct bio *bio;
bio = bio_alloc(gfp_flags, nr_vecs);
if (bio == NULL && (current->flags & PF_MEMALLOC)) {
while (!bio && (nr_vecs /= 2))
bio = bio_alloc(gfp_flags, nr_vecs);
}
if (bio) {
bio->bi_size = 0;
bio->bi_bdev = bdev;
bio->bi_sector = first_sector;
}
return bio;
}
static int submit_one_bio(int rw, struct bio *bio, int mirror_num,
unsigned long bio_flags)
{
int ret = 0;
struct bio_vec *bvec = bio->bi_io_vec + bio->bi_vcnt - 1;
struct page *page = bvec->bv_page;
struct extent_io_tree *tree = bio->bi_private;
u64 start;
start = ((u64)page->index << PAGE_CACHE_SHIFT) + bvec->bv_offset;
bio->bi_private = NULL;
bio_get(bio);
if (tree->ops && tree->ops->submit_bio_hook)
ret = tree->ops->submit_bio_hook(page->mapping->host, rw, bio,
mirror_num, bio_flags, start);
else
submit_bio(rw, bio);
if (bio_flagged(bio, BIO_EOPNOTSUPP))
ret = -EOPNOTSUPP;
bio_put(bio);
return ret;
}
static int submit_extent_page(int rw, struct extent_io_tree *tree,
struct page *page, sector_t sector,
size_t size, unsigned long offset,
struct block_device *bdev,
struct bio **bio_ret,
unsigned long max_pages,
bio_end_io_t end_io_func,
int mirror_num,
unsigned long prev_bio_flags,
unsigned long bio_flags)
{
int ret = 0;
struct bio *bio;
int nr;
int contig = 0;
int this_compressed = bio_flags & EXTENT_BIO_COMPRESSED;
int old_compressed = prev_bio_flags & EXTENT_BIO_COMPRESSED;
size_t page_size = min_t(size_t, size, PAGE_CACHE_SIZE);
if (bio_ret && *bio_ret) {
bio = *bio_ret;
if (old_compressed)
contig = bio->bi_sector == sector;
else
contig = bio->bi_sector + (bio->bi_size >> 9) ==
sector;
if (prev_bio_flags != bio_flags || !contig ||
(tree->ops && tree->ops->merge_bio_hook &&
tree->ops->merge_bio_hook(page, offset, page_size, bio,
bio_flags)) ||
bio_add_page(bio, page, page_size, offset) < page_size) {
ret = submit_one_bio(rw, bio, mirror_num,
prev_bio_flags);
bio = NULL;
} else {
return 0;
}
}
if (this_compressed)
nr = BIO_MAX_PAGES;
else
nr = bio_get_nr_vecs(bdev);
bio = btrfs_bio_alloc(bdev, sector, nr, GFP_NOFS | __GFP_HIGH);
if (!bio)
return -ENOMEM;
bio_add_page(bio, page, page_size, offset);
bio->bi_end_io = end_io_func;
bio->bi_private = tree;
if (bio_ret)
*bio_ret = bio;
else
ret = submit_one_bio(rw, bio, mirror_num, bio_flags);
return ret;
}
void set_page_extent_mapped(struct page *page)
{
if (!PagePrivate(page)) {
SetPagePrivate(page);
page_cache_get(page);
set_page_private(page, EXTENT_PAGE_PRIVATE);
}
}
static void set_page_extent_head(struct page *page, unsigned long len)
{
WARN_ON(!PagePrivate(page));
set_page_private(page, EXTENT_PAGE_PRIVATE_FIRST_PAGE | len << 2);
}
static int __extent_read_full_page(struct extent_io_tree *tree,
struct page *page,
get_extent_t *get_extent,
struct bio **bio, int mirror_num,
unsigned long *bio_flags)
{
struct inode *inode = page->mapping->host;
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 page_end = start + PAGE_CACHE_SIZE - 1;
u64 end;
u64 cur = start;
u64 extent_offset;
u64 last_byte = i_size_read(inode);
u64 block_start;
u64 cur_end;
sector_t sector;
struct extent_map *em;
struct block_device *bdev;
struct btrfs_ordered_extent *ordered;
int ret;
int nr = 0;
size_t pg_offset = 0;
size_t iosize;
size_t disk_io_size;
size_t blocksize = inode->i_sb->s_blocksize;
unsigned long this_bio_flag = 0;
set_page_extent_mapped(page);
if (!PageUptodate(page)) {
if (cleancache_get_page(page) == 0) {
BUG_ON(blocksize != PAGE_SIZE);
goto out;
}
}
end = page_end;
while (1) {
lock_extent(tree, start, end, GFP_NOFS);
ordered = btrfs_lookup_ordered_extent(inode, start);
if (!ordered)
break;
unlock_extent(tree, start, end, GFP_NOFS);
btrfs_start_ordered_extent(inode, ordered, 1);
btrfs_put_ordered_extent(ordered);
}
if (page->index == last_byte >> PAGE_CACHE_SHIFT) {
char *userpage;
size_t zero_offset = last_byte & (PAGE_CACHE_SIZE - 1);
if (zero_offset) {
iosize = PAGE_CACHE_SIZE - zero_offset;
userpage = kmap_atomic(page, KM_USER0);
memset(userpage + zero_offset, 0, iosize);
flush_dcache_page(page);
kunmap_atomic(userpage, KM_USER0);
}
}
while (cur <= end) {
if (cur >= last_byte) {
char *userpage;
struct extent_state *cached = NULL;
iosize = PAGE_CACHE_SIZE - pg_offset;
userpage = kmap_atomic(page, KM_USER0);
memset(userpage + pg_offset, 0, iosize);
flush_dcache_page(page);
kunmap_atomic(userpage, KM_USER0);
set_extent_uptodate(tree, cur, cur + iosize - 1,
&cached, GFP_NOFS);
unlock_extent_cached(tree, cur, cur + iosize - 1,
&cached, GFP_NOFS);
break;
}
em = get_extent(inode, page, pg_offset, cur,
end - cur + 1, 0);
if (IS_ERR_OR_NULL(em)) {
SetPageError(page);
unlock_extent(tree, cur, end, GFP_NOFS);
break;
}
extent_offset = cur - em->start;
BUG_ON(extent_map_end(em) <= cur);
BUG_ON(end < cur);
if (test_bit(EXTENT_FLAG_COMPRESSED, &em->flags)) {
this_bio_flag = EXTENT_BIO_COMPRESSED;
extent_set_compress_type(&this_bio_flag,
em->compress_type);
}
iosize = min(extent_map_end(em) - cur, end - cur + 1);
cur_end = min(extent_map_end(em) - 1, end);
iosize = (iosize + blocksize - 1) & ~((u64)blocksize - 1);
if (this_bio_flag & EXTENT_BIO_COMPRESSED) {
disk_io_size = em->block_len;
sector = em->block_start >> 9;
} else {
sector = (em->block_start + extent_offset) >> 9;
disk_io_size = iosize;
}
bdev = em->bdev;
block_start = em->block_start;
if (test_bit(EXTENT_FLAG_PREALLOC, &em->flags))
block_start = EXTENT_MAP_HOLE;
free_extent_map(em);
em = NULL;
if (block_start == EXTENT_MAP_HOLE) {
char *userpage;
struct extent_state *cached = NULL;
userpage = kmap_atomic(page, KM_USER0);
memset(userpage + pg_offset, 0, iosize);
flush_dcache_page(page);
kunmap_atomic(userpage, KM_USER0);
set_extent_uptodate(tree, cur, cur + iosize - 1,
&cached, GFP_NOFS);
unlock_extent_cached(tree, cur, cur + iosize - 1,
&cached, GFP_NOFS);
cur = cur + iosize;
pg_offset += iosize;
continue;
}
if (test_range_bit(tree, cur, cur_end,
EXTENT_UPTODATE, 1, NULL)) {
check_page_uptodate(tree, page);
unlock_extent(tree, cur, cur + iosize - 1, GFP_NOFS);
cur = cur + iosize;
pg_offset += iosize;
continue;
}
if (block_start == EXTENT_MAP_INLINE) {
SetPageError(page);
unlock_extent(tree, cur, cur + iosize - 1, GFP_NOFS);
cur = cur + iosize;
pg_offset += iosize;
continue;
}
ret = 0;
if (tree->ops && tree->ops->readpage_io_hook) {
ret = tree->ops->readpage_io_hook(page, cur,
cur + iosize - 1);
}
if (!ret) {
unsigned long pnr = (last_byte >> PAGE_CACHE_SHIFT) + 1;
pnr -= page->index;
ret = submit_extent_page(READ, tree, page,
sector, disk_io_size, pg_offset,
bdev, bio, pnr,
end_bio_extent_readpage, mirror_num,
*bio_flags,
this_bio_flag);
nr++;
*bio_flags = this_bio_flag;
}
if (ret)
SetPageError(page);
cur = cur + iosize;
pg_offset += iosize;
}
out:
if (!nr) {
if (!PageError(page))
SetPageUptodate(page);
unlock_page(page);
}
return 0;
}
int extent_read_full_page(struct extent_io_tree *tree, struct page *page,
get_extent_t *get_extent)
{
struct bio *bio = NULL;
unsigned long bio_flags = 0;
int ret;
ret = __extent_read_full_page(tree, page, get_extent, &bio, 0,
&bio_flags);
if (bio)
ret = submit_one_bio(READ, bio, 0, bio_flags);
return ret;
}
static noinline void update_nr_written(struct page *page,
struct writeback_control *wbc,
unsigned long nr_written)
{
wbc->nr_to_write -= nr_written;
if (wbc->range_cyclic || (wbc->nr_to_write > 0 &&
wbc->range_start == 0 && wbc->range_end == LLONG_MAX))
page->mapping->writeback_index = page->index + nr_written;
}
static int __extent_writepage(struct page *page, struct writeback_control *wbc,
void *data)
{
struct inode *inode = page->mapping->host;
struct extent_page_data *epd = data;
struct extent_io_tree *tree = epd->tree;
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 delalloc_start;
u64 page_end = start + PAGE_CACHE_SIZE - 1;
u64 end;
u64 cur = start;
u64 extent_offset;
u64 last_byte = i_size_read(inode);
u64 block_start;
u64 iosize;
sector_t sector;
struct extent_state *cached_state = NULL;
struct extent_map *em;
struct block_device *bdev;
int ret;
int nr = 0;
size_t pg_offset = 0;
size_t blocksize;
loff_t i_size = i_size_read(inode);
unsigned long end_index = i_size >> PAGE_CACHE_SHIFT;
u64 nr_delalloc;
u64 delalloc_end;
int page_started;
int compressed;
int write_flags;
unsigned long nr_written = 0;
if (wbc->sync_mode == WB_SYNC_ALL)
write_flags = WRITE_SYNC;
else
write_flags = WRITE;
trace___extent_writepage(page, inode, wbc);
WARN_ON(!PageLocked(page));
pg_offset = i_size & (PAGE_CACHE_SIZE - 1);
if (page->index > end_index ||
(page->index == end_index && !pg_offset)) {
page->mapping->a_ops->invalidatepage(page, 0);
unlock_page(page);
return 0;
}
if (page->index == end_index) {
char *userpage;
userpage = kmap_atomic(page, KM_USER0);
memset(userpage + pg_offset, 0,
PAGE_CACHE_SIZE - pg_offset);
kunmap_atomic(userpage, KM_USER0);
flush_dcache_page(page);
}
pg_offset = 0;
set_page_extent_mapped(page);
delalloc_start = start;
delalloc_end = 0;
page_started = 0;
if (!epd->extent_locked) {
u64 delalloc_to_write = 0;
update_nr_written(page, wbc, 0);
while (delalloc_end < page_end) {
nr_delalloc = find_lock_delalloc_range(inode, tree,
page,
&delalloc_start,
&delalloc_end,
128 * 1024 * 1024);
if (nr_delalloc == 0) {
delalloc_start = delalloc_end + 1;
continue;
}
tree->ops->fill_delalloc(inode, page, delalloc_start,
delalloc_end, &page_started,
&nr_written);
delalloc_to_write += (delalloc_end - delalloc_start +
PAGE_CACHE_SIZE) >>
PAGE_CACHE_SHIFT;
delalloc_start = delalloc_end + 1;
}
if (wbc->nr_to_write < delalloc_to_write) {
int thresh = 8192;
if (delalloc_to_write < thresh * 2)
thresh = delalloc_to_write;
wbc->nr_to_write = min_t(u64, delalloc_to_write,
thresh);
}
if (page_started) {
ret = 0;
wbc->nr_to_write -= nr_written;
goto done_unlocked;
}
}
if (tree->ops && tree->ops->writepage_start_hook) {
ret = tree->ops->writepage_start_hook(page, start,
page_end);
if (ret == -EAGAIN) {
redirty_page_for_writepage(wbc, page);
update_nr_written(page, wbc, nr_written);
unlock_page(page);
ret = 0;
goto done_unlocked;
}
}
update_nr_written(page, wbc, nr_written + 1);
end = page_end;
if (last_byte <= start) {
if (tree->ops && tree->ops->writepage_end_io_hook)
tree->ops->writepage_end_io_hook(page, start,
page_end, NULL, 1);
goto done;
}
blocksize = inode->i_sb->s_blocksize;
while (cur <= end) {
if (cur >= last_byte) {
if (tree->ops && tree->ops->writepage_end_io_hook)
tree->ops->writepage_end_io_hook(page, cur,
page_end, NULL, 1);
break;
}
em = epd->get_extent(inode, page, pg_offset, cur,
end - cur + 1, 1);
if (IS_ERR_OR_NULL(em)) {
SetPageError(page);
break;
}
extent_offset = cur - em->start;
BUG_ON(extent_map_end(em) <= cur);
BUG_ON(end < cur);
iosize = min(extent_map_end(em) - cur, end - cur + 1);
iosize = (iosize + blocksize - 1) & ~((u64)blocksize - 1);
sector = (em->block_start + extent_offset) >> 9;
bdev = em->bdev;
block_start = em->block_start;
compressed = test_bit(EXTENT_FLAG_COMPRESSED, &em->flags);
free_extent_map(em);
em = NULL;
if (compressed || block_start == EXTENT_MAP_HOLE ||
block_start == EXTENT_MAP_INLINE) {
if (!compressed && tree->ops &&
tree->ops->writepage_end_io_hook)
tree->ops->writepage_end_io_hook(page, cur,
cur + iosize - 1,
NULL, 1);
else if (compressed) {
nr++;
}
cur += iosize;
pg_offset += iosize;
continue;
}
if (0 && !test_range_bit(tree, cur, cur + iosize - 1,
EXTENT_DIRTY, 0, NULL)) {
cur = cur + iosize;
pg_offset += iosize;
continue;
}
if (tree->ops && tree->ops->writepage_io_hook) {
ret = tree->ops->writepage_io_hook(page, cur,
cur + iosize - 1);
} else {
ret = 0;
}
if (ret) {
SetPageError(page);
} else {
unsigned long max_nr = end_index + 1;
set_range_writeback(tree, cur, cur + iosize - 1);
if (!PageWriteback(page)) {
printk(KERN_ERR "btrfs warning page %lu not "
"writeback, cur %llu end %llu\n",
page->index, (unsigned long long)cur,
(unsigned long long)end);
}
ret = submit_extent_page(write_flags, tree, page,
sector, iosize, pg_offset,
bdev, &epd->bio, max_nr,
end_bio_extent_writepage,
0, 0, 0);
if (ret)
SetPageError(page);
}
cur = cur + iosize;
pg_offset += iosize;
nr++;
}
done:
if (nr == 0) {
set_page_writeback(page);
end_page_writeback(page);
}
unlock_page(page);
done_unlocked:
free_extent_state(cached_state);
return 0;
}
static int extent_write_cache_pages(struct extent_io_tree *tree,
struct address_space *mapping,
struct writeback_control *wbc,
writepage_t writepage, void *data,
void (*flush_fn)(void *))
{
int ret = 0;
int done = 0;
int nr_to_write_done = 0;
struct pagevec pvec;
int nr_pages;
pgoff_t index;
pgoff_t end;
int scanned = 0;
pagevec_init(&pvec, 0);
if (wbc->range_cyclic) {
index = mapping->writeback_index;
end = -1;
} else {
index = wbc->range_start >> PAGE_CACHE_SHIFT;
end = wbc->range_end >> PAGE_CACHE_SHIFT;
scanned = 1;
}
retry:
while (!done && !nr_to_write_done && (index <= end) &&
(nr_pages = pagevec_lookup_tag(&pvec, mapping, &index,
PAGECACHE_TAG_DIRTY, min(end - index,
(pgoff_t)PAGEVEC_SIZE-1) + 1))) {
unsigned i;
scanned = 1;
for (i = 0; i < nr_pages; i++) {
struct page *page = pvec.pages[i];
if (tree->ops && tree->ops->write_cache_pages_lock_hook)
tree->ops->write_cache_pages_lock_hook(page);
else
lock_page(page);
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
continue;
}
if (!wbc->range_cyclic && page->index > end) {
done = 1;
unlock_page(page);
continue;
}
if (wbc->sync_mode != WB_SYNC_NONE) {
if (PageWriteback(page))
flush_fn(data);
wait_on_page_writeback(page);
}
if (PageWriteback(page) ||
!clear_page_dirty_for_io(page)) {
unlock_page(page);
continue;
}
ret = (*writepage)(page, wbc, data);
if (unlikely(ret == AOP_WRITEPAGE_ACTIVATE)) {
unlock_page(page);
ret = 0;
}
if (ret)
done = 1;
nr_to_write_done = wbc->nr_to_write <= 0;
}
pagevec_release(&pvec);
cond_resched();
}
if (!scanned && !done) {
scanned = 1;
index = 0;
goto retry;
}
return ret;
}
static void flush_epd_write_bio(struct extent_page_data *epd)
{
if (epd->bio) {
if (epd->sync_io)
submit_one_bio(WRITE_SYNC, epd->bio, 0, 0);
else
submit_one_bio(WRITE, epd->bio, 0, 0);
epd->bio = NULL;
}
}
static noinline void flush_write_bio(void *data)
{
struct extent_page_data *epd = data;
flush_epd_write_bio(epd);
}
int extent_write_full_page(struct extent_io_tree *tree, struct page *page,
get_extent_t *get_extent,
struct writeback_control *wbc)
{
int ret;
struct address_space *mapping = page->mapping;
struct extent_page_data epd = {
.bio = NULL,
.tree = tree,
.get_extent = get_extent,
.extent_locked = 0,
.sync_io = wbc->sync_mode == WB_SYNC_ALL,
};
struct writeback_control wbc_writepages = {
.sync_mode = wbc->sync_mode,
.older_than_this = NULL,
.nr_to_write = 64,
.range_start = page_offset(page) + PAGE_CACHE_SIZE,
.range_end = (loff_t)-1,
};
ret = __extent_writepage(page, wbc, &epd);
extent_write_cache_pages(tree, mapping, &wbc_writepages,
__extent_writepage, &epd, flush_write_bio);
flush_epd_write_bio(&epd);
return ret;
}
int extent_write_locked_range(struct extent_io_tree *tree, struct inode *inode,
u64 start, u64 end, get_extent_t *get_extent,
int mode)
{
int ret = 0;
struct address_space *mapping = inode->i_mapping;
struct page *page;
unsigned long nr_pages = (end - start + PAGE_CACHE_SIZE) >>
PAGE_CACHE_SHIFT;
struct extent_page_data epd = {
.bio = NULL,
.tree = tree,
.get_extent = get_extent,
.extent_locked = 1,
.sync_io = mode == WB_SYNC_ALL,
};
struct writeback_control wbc_writepages = {
.sync_mode = mode,
.older_than_this = NULL,
.nr_to_write = nr_pages * 2,
.range_start = start,
.range_end = end + 1,
};
while (start <= end) {
page = find_get_page(mapping, start >> PAGE_CACHE_SHIFT);
if (clear_page_dirty_for_io(page))
ret = __extent_writepage(page, &wbc_writepages, &epd);
else {
if (tree->ops && tree->ops->writepage_end_io_hook)
tree->ops->writepage_end_io_hook(page, start,
start + PAGE_CACHE_SIZE - 1,
NULL, 1);
unlock_page(page);
}
page_cache_release(page);
start += PAGE_CACHE_SIZE;
}
flush_epd_write_bio(&epd);
return ret;
}
int extent_writepages(struct extent_io_tree *tree,
struct address_space *mapping,
get_extent_t *get_extent,
struct writeback_control *wbc)
{
int ret = 0;
struct extent_page_data epd = {
.bio = NULL,
.tree = tree,
.get_extent = get_extent,
.extent_locked = 0,
.sync_io = wbc->sync_mode == WB_SYNC_ALL,
};
ret = extent_write_cache_pages(tree, mapping, wbc,
__extent_writepage, &epd,
flush_write_bio);
flush_epd_write_bio(&epd);
return ret;
}
int extent_readpages(struct extent_io_tree *tree,
struct address_space *mapping,
struct list_head *pages, unsigned nr_pages,
get_extent_t get_extent)
{
struct bio *bio = NULL;
unsigned page_idx;
unsigned long bio_flags = 0;
for (page_idx = 0; page_idx < nr_pages; page_idx++) {
struct page *page = list_entry(pages->prev, struct page, lru);
prefetchw(&page->flags);
list_del(&page->lru);
if (!add_to_page_cache_lru(page, mapping,
page->index, GFP_NOFS)) {
__extent_read_full_page(tree, page, get_extent,
&bio, 0, &bio_flags);
}
page_cache_release(page);
}
BUG_ON(!list_empty(pages));
if (bio)
submit_one_bio(READ, bio, 0, bio_flags);
return 0;
}
int extent_invalidatepage(struct extent_io_tree *tree,
struct page *page, unsigned long offset)
{
struct extent_state *cached_state = NULL;
u64 start = ((u64)page->index << PAGE_CACHE_SHIFT);
u64 end = start + PAGE_CACHE_SIZE - 1;
size_t blocksize = page->mapping->host->i_sb->s_blocksize;
start += (offset + blocksize - 1) & ~(blocksize - 1);
if (start > end)
return 0;
lock_extent_bits(tree, start, end, 0, &cached_state, GFP_NOFS);
wait_on_page_writeback(page);
clear_extent_bit(tree, start, end,
EXTENT_LOCKED | EXTENT_DIRTY | EXTENT_DELALLOC |
EXTENT_DO_ACCOUNTING,
1, 1, &cached_state, GFP_NOFS);
return 0;
}
int try_release_extent_state(struct extent_map_tree *map,
struct extent_io_tree *tree, struct page *page,
gfp_t mask)
{
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 end = start + PAGE_CACHE_SIZE - 1;
int ret = 1;
if (test_range_bit(tree, start, end,
EXTENT_IOBITS, 0, NULL))
ret = 0;
else {
if ((mask & GFP_NOFS) == GFP_NOFS)
mask = GFP_NOFS;
ret = clear_extent_bit(tree, start, end,
~(EXTENT_LOCKED | EXTENT_NODATASUM),
0, 0, NULL, mask);
if (ret < 0)
ret = 0;
else
ret = 1;
}
return ret;
}
int try_release_extent_mapping(struct extent_map_tree *map,
struct extent_io_tree *tree, struct page *page,
gfp_t mask)
{
struct extent_map *em;
u64 start = (u64)page->index << PAGE_CACHE_SHIFT;
u64 end = start + PAGE_CACHE_SIZE - 1;
if ((mask & __GFP_WAIT) &&
page->mapping->host->i_size > 16 * 1024 * 1024) {
u64 len;
while (start <= end) {
len = end - start + 1;
write_lock(&map->lock);
em = lookup_extent_mapping(map, start, len);
if (IS_ERR_OR_NULL(em)) {
write_unlock(&map->lock);
break;
}
if (test_bit(EXTENT_FLAG_PINNED, &em->flags) ||
em->start != start) {
write_unlock(&map->lock);
free_extent_map(em);
break;
}
if (!test_range_bit(tree, em->start,
extent_map_end(em) - 1,
EXTENT_LOCKED | EXTENT_WRITEBACK,
0, NULL)) {
remove_extent_mapping(map, em);
free_extent_map(em);
}
start = extent_map_end(em);
write_unlock(&map->lock);
free_extent_map(em);
}
}
return try_release_extent_state(map, tree, page, mask);
}
static struct extent_map *get_extent_skip_holes(struct inode *inode,
u64 offset,
u64 last,
get_extent_t *get_extent)
{
u64 sectorsize = BTRFS_I(inode)->root->sectorsize;
struct extent_map *em;
u64 len;
if (offset >= last)
return NULL;
while(1) {
len = last - offset;
if (len == 0)
break;
len = (len + sectorsize - 1) & ~(sectorsize - 1);
em = get_extent(inode, NULL, 0, offset, len, 0);
if (IS_ERR_OR_NULL(em))
return em;
if (!test_bit(EXTENT_FLAG_VACANCY, &em->flags) &&
em->block_start != EXTENT_MAP_HOLE) {
return em;
}
offset = extent_map_end(em);
free_extent_map(em);
if (offset >= last)
break;
}
return NULL;
}
int extent_fiemap(struct inode *inode, struct fiemap_extent_info *fieinfo,
__u64 start, __u64 len, get_extent_t *get_extent)
{
int ret = 0;
u64 off = start;
u64 max = start + len;
u32 flags = 0;
u32 found_type;
u64 last;
u64 last_for_get_extent = 0;
u64 disko = 0;
u64 isize = i_size_read(inode);
struct btrfs_key found_key;
struct extent_map *em = NULL;
struct extent_state *cached_state = NULL;
struct btrfs_path *path;
struct btrfs_file_extent_item *item;
int end = 0;
u64 em_start = 0;
u64 em_len = 0;
u64 em_end = 0;
unsigned long emflags;
if (len == 0)
return -EINVAL;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
path->leave_spinning = 1;
ret = btrfs_lookup_file_extent(NULL, BTRFS_I(inode)->root,
path, btrfs_ino(inode), -1, 0);
if (ret < 0) {
btrfs_free_path(path);
return ret;
}
WARN_ON(!ret);
path->slots[0]--;
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_file_extent_item);
btrfs_item_key_to_cpu(path->nodes[0], &found_key, path->slots[0]);
found_type = btrfs_key_type(&found_key);
if (found_key.objectid != btrfs_ino(inode) ||
found_type != BTRFS_EXTENT_DATA_KEY) {
last = (u64)-1;
last_for_get_extent = isize;
} else {
last = found_key.offset;
last_for_get_extent = last + 1;
}
btrfs_free_path(path);
if (last < isize) {
last = (u64)-1;
last_for_get_extent = isize;
}
lock_extent_bits(&BTRFS_I(inode)->io_tree, start, start + len, 0,
&cached_state, GFP_NOFS);
em = get_extent_skip_holes(inode, off, last_for_get_extent,
get_extent);
if (!em)
goto out;
if (IS_ERR(em)) {
ret = PTR_ERR(em);
goto out;
}
while (!end) {
u64 offset_in_extent;
if (em->start >= max || extent_map_end(em) < off)
break;
em_start = max(em->start, off);
offset_in_extent = em_start - em->start;
em_end = extent_map_end(em);
em_len = em_end - em_start;
emflags = em->flags;
disko = 0;
flags = 0;
off = extent_map_end(em);
if (off >= max)
end = 1;
if (em->block_start == EXTENT_MAP_LAST_BYTE) {
end = 1;
flags |= FIEMAP_EXTENT_LAST;
} else if (em->block_start == EXTENT_MAP_INLINE) {
flags |= (FIEMAP_EXTENT_DATA_INLINE |
FIEMAP_EXTENT_NOT_ALIGNED);
} else if (em->block_start == EXTENT_MAP_DELALLOC) {
flags |= (FIEMAP_EXTENT_DELALLOC |
FIEMAP_EXTENT_UNKNOWN);
} else {
disko = em->block_start + offset_in_extent;
}
if (test_bit(EXTENT_FLAG_COMPRESSED, &em->flags))
flags |= FIEMAP_EXTENT_ENCODED;
free_extent_map(em);
em = NULL;
if ((em_start >= last) || em_len == (u64)-1 ||
(last == (u64)-1 && isize <= em_end)) {
flags |= FIEMAP_EXTENT_LAST;
end = 1;
}
em = get_extent_skip_holes(inode, off, last_for_get_extent,
get_extent);
if (IS_ERR(em)) {
ret = PTR_ERR(em);
goto out;
}
if (!em) {
flags |= FIEMAP_EXTENT_LAST;
end = 1;
}
ret = fiemap_fill_next_extent(fieinfo, em_start, disko,
em_len, flags);
if (ret)
goto out_free;
}
out_free:
free_extent_map(em);
out:
unlock_extent_cached(&BTRFS_I(inode)->io_tree, start, start + len,
&cached_state, GFP_NOFS);
return ret;
}
static inline struct page *extent_buffer_page(struct extent_buffer *eb,
unsigned long i)
{
struct page *p;
struct address_space *mapping;
if (i == 0)
return eb->first_page;
i += eb->start >> PAGE_CACHE_SHIFT;
mapping = eb->first_page->mapping;
if (!mapping)
return NULL;
rcu_read_lock();
p = radix_tree_lookup(&mapping->page_tree, i);
rcu_read_unlock();
return p;
}
static inline unsigned long num_extent_pages(u64 start, u64 len)
{
return ((start + len + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT) -
(start >> PAGE_CACHE_SHIFT);
}
static struct extent_buffer *__alloc_extent_buffer(struct extent_io_tree *tree,
u64 start,
unsigned long len,
gfp_t mask)
{
struct extent_buffer *eb = NULL;
#if LEAK_DEBUG
unsigned long flags;
#endif
eb = kmem_cache_zalloc(extent_buffer_cache, mask);
if (eb == NULL)
return NULL;
eb->start = start;
eb->len = len;
spin_lock_init(&eb->lock);
init_waitqueue_head(&eb->lock_wq);
#if LEAK_DEBUG
spin_lock_irqsave(&leak_lock, flags);
list_add(&eb->leak_list, &buffers);
spin_unlock_irqrestore(&leak_lock, flags);
#endif
atomic_set(&eb->refs, 1);
return eb;
}
static void __free_extent_buffer(struct extent_buffer *eb)
{
#if LEAK_DEBUG
unsigned long flags;
spin_lock_irqsave(&leak_lock, flags);
list_del(&eb->leak_list);
spin_unlock_irqrestore(&leak_lock, flags);
#endif
kmem_cache_free(extent_buffer_cache, eb);
}
static void btrfs_release_extent_buffer_page(struct extent_buffer *eb,
unsigned long start_idx)
{
unsigned long index;
struct page *page;
if (!eb->first_page)
return;
index = num_extent_pages(eb->start, eb->len);
if (start_idx >= index)
return;
do {
index--;
page = extent_buffer_page(eb, index);
if (page)
page_cache_release(page);
} while (index != start_idx);
}
static inline void btrfs_release_extent_buffer(struct extent_buffer *eb)
{
btrfs_release_extent_buffer_page(eb, 0);
__free_extent_buffer(eb);
}
struct extent_buffer *alloc_extent_buffer(struct extent_io_tree *tree,
u64 start, unsigned long len,
struct page *page0)
{
unsigned long num_pages = num_extent_pages(start, len);
unsigned long i;
unsigned long index = start >> PAGE_CACHE_SHIFT;
struct extent_buffer *eb;
struct extent_buffer *exists = NULL;
struct page *p;
struct address_space *mapping = tree->mapping;
int uptodate = 1;
int ret;
rcu_read_lock();
eb = radix_tree_lookup(&tree->buffer, start >> PAGE_CACHE_SHIFT);
if (eb && atomic_inc_not_zero(&eb->refs)) {
rcu_read_unlock();
mark_page_accessed(eb->first_page);
return eb;
}
rcu_read_unlock();
eb = __alloc_extent_buffer(tree, start, len, GFP_NOFS);
if (!eb)
return NULL;
if (page0) {
eb->first_page = page0;
i = 1;
index++;
page_cache_get(page0);
mark_page_accessed(page0);
set_page_extent_mapped(page0);
set_page_extent_head(page0, len);
uptodate = PageUptodate(page0);
} else {
i = 0;
}
for (; i < num_pages; i++, index++) {
p = find_or_create_page(mapping, index, GFP_NOFS | __GFP_HIGHMEM);
if (!p) {
WARN_ON(1);
goto free_eb;
}
set_page_extent_mapped(p);
mark_page_accessed(p);
if (i == 0) {
eb->first_page = p;
set_page_extent_head(p, len);
} else {
set_page_private(p, EXTENT_PAGE_PRIVATE);
}
if (!PageUptodate(p))
uptodate = 0;
if (i != 0)
unlock_page(p);
}
if (uptodate)
set_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags);
ret = radix_tree_preload(GFP_NOFS & ~__GFP_HIGHMEM);
if (ret)
goto free_eb;
spin_lock(&tree->buffer_lock);
ret = radix_tree_insert(&tree->buffer, start >> PAGE_CACHE_SHIFT, eb);
if (ret == -EEXIST) {
exists = radix_tree_lookup(&tree->buffer,
start >> PAGE_CACHE_SHIFT);
atomic_inc(&exists->refs);
spin_unlock(&tree->buffer_lock);
radix_tree_preload_end();
goto free_eb;
}
atomic_inc(&eb->refs);
spin_unlock(&tree->buffer_lock);
radix_tree_preload_end();
set_page_extent_mapped(eb->first_page);
set_page_extent_head(eb->first_page, eb->len);
if (!page0)
unlock_page(eb->first_page);
return eb;
free_eb:
if (eb->first_page && !page0)
unlock_page(eb->first_page);
if (!atomic_dec_and_test(&eb->refs))
return exists;
btrfs_release_extent_buffer(eb);
return exists;
}
struct extent_buffer *find_extent_buffer(struct extent_io_tree *tree,
u64 start, unsigned long len)
{
struct extent_buffer *eb;
rcu_read_lock();
eb = radix_tree_lookup(&tree->buffer, start >> PAGE_CACHE_SHIFT);
if (eb && atomic_inc_not_zero(&eb->refs)) {
rcu_read_unlock();
mark_page_accessed(eb->first_page);
return eb;
}
rcu_read_unlock();
return NULL;
}
void free_extent_buffer(struct extent_buffer *eb)
{
if (!eb)
return;
if (!atomic_dec_and_test(&eb->refs))
return;
WARN_ON(1);
}
int clear_extent_buffer_dirty(struct extent_io_tree *tree,
struct extent_buffer *eb)
{
unsigned long i;
unsigned long num_pages;
struct page *page;
num_pages = num_extent_pages(eb->start, eb->len);
for (i = 0; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
if (!PageDirty(page))
continue;
lock_page(page);
WARN_ON(!PagePrivate(page));
set_page_extent_mapped(page);
if (i == 0)
set_page_extent_head(page, eb->len);
clear_page_dirty_for_io(page);
spin_lock_irq(&page->mapping->tree_lock);
if (!PageDirty(page)) {
radix_tree_tag_clear(&page->mapping->page_tree,
page_index(page),
PAGECACHE_TAG_DIRTY);
}
spin_unlock_irq(&page->mapping->tree_lock);
unlock_page(page);
}
return 0;
}
int set_extent_buffer_dirty(struct extent_io_tree *tree,
struct extent_buffer *eb)
{
unsigned long i;
unsigned long num_pages;
int was_dirty = 0;
was_dirty = test_and_set_bit(EXTENT_BUFFER_DIRTY, &eb->bflags);
num_pages = num_extent_pages(eb->start, eb->len);
for (i = 0; i < num_pages; i++)
__set_page_dirty_nobuffers(extent_buffer_page(eb, i));
return was_dirty;
}
int clear_extent_buffer_uptodate(struct extent_io_tree *tree,
struct extent_buffer *eb,
struct extent_state **cached_state)
{
unsigned long i;
struct page *page;
unsigned long num_pages;
num_pages = num_extent_pages(eb->start, eb->len);
clear_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags);
clear_extent_uptodate(tree, eb->start, eb->start + eb->len - 1,
cached_state, GFP_NOFS);
for (i = 0; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
if (page)
ClearPageUptodate(page);
}
return 0;
}
int set_extent_buffer_uptodate(struct extent_io_tree *tree,
struct extent_buffer *eb)
{
unsigned long i;
struct page *page;
unsigned long num_pages;
num_pages = num_extent_pages(eb->start, eb->len);
set_extent_uptodate(tree, eb->start, eb->start + eb->len - 1,
NULL, GFP_NOFS);
for (i = 0; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
if ((i == 0 && (eb->start & (PAGE_CACHE_SIZE - 1))) ||
((i == num_pages - 1) &&
((eb->start + eb->len) & (PAGE_CACHE_SIZE - 1)))) {
check_page_uptodate(tree, page);
continue;
}
SetPageUptodate(page);
}
return 0;
}
int extent_range_uptodate(struct extent_io_tree *tree,
u64 start, u64 end)
{
struct page *page;
int ret;
int pg_uptodate = 1;
int uptodate;
unsigned long index;
ret = test_range_bit(tree, start, end, EXTENT_UPTODATE, 1, NULL);
if (ret)
return 1;
while (start <= end) {
index = start >> PAGE_CACHE_SHIFT;
page = find_get_page(tree->mapping, index);
uptodate = PageUptodate(page);
page_cache_release(page);
if (!uptodate) {
pg_uptodate = 0;
break;
}
start += PAGE_CACHE_SIZE;
}
return pg_uptodate;
}
int extent_buffer_uptodate(struct extent_io_tree *tree,
struct extent_buffer *eb,
struct extent_state *cached_state)
{
int ret = 0;
unsigned long num_pages;
unsigned long i;
struct page *page;
int pg_uptodate = 1;
if (test_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags))
return 1;
ret = test_range_bit(tree, eb->start, eb->start + eb->len - 1,
EXTENT_UPTODATE, 1, cached_state);
if (ret)
return ret;
num_pages = num_extent_pages(eb->start, eb->len);
for (i = 0; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
if (!PageUptodate(page)) {
pg_uptodate = 0;
break;
}
}
return pg_uptodate;
}
int read_extent_buffer_pages(struct extent_io_tree *tree,
struct extent_buffer *eb,
u64 start, int wait,
get_extent_t *get_extent, int mirror_num)
{
unsigned long i;
unsigned long start_i;
struct page *page;
int err;
int ret = 0;
int locked_pages = 0;
int all_uptodate = 1;
int inc_all_pages = 0;
unsigned long num_pages;
struct bio *bio = NULL;
unsigned long bio_flags = 0;
if (test_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags))
return 0;
if (test_range_bit(tree, eb->start, eb->start + eb->len - 1,
EXTENT_UPTODATE, 1, NULL)) {
return 0;
}
if (start) {
WARN_ON(start < eb->start);
start_i = (start >> PAGE_CACHE_SHIFT) -
(eb->start >> PAGE_CACHE_SHIFT);
} else {
start_i = 0;
}
num_pages = num_extent_pages(eb->start, eb->len);
for (i = start_i; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
if (!wait) {
if (!trylock_page(page))
goto unlock_exit;
} else {
lock_page(page);
}
locked_pages++;
if (!PageUptodate(page))
all_uptodate = 0;
}
if (all_uptodate) {
if (start_i == 0)
set_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags);
goto unlock_exit;
}
for (i = start_i; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
WARN_ON(!PagePrivate(page));
set_page_extent_mapped(page);
if (i == 0)
set_page_extent_head(page, eb->len);
if (inc_all_pages)
page_cache_get(page);
if (!PageUptodate(page)) {
if (start_i == 0)
inc_all_pages = 1;
ClearPageError(page);
err = __extent_read_full_page(tree, page,
get_extent, &bio,
mirror_num, &bio_flags);
if (err)
ret = err;
} else {
unlock_page(page);
}
}
if (bio)
submit_one_bio(READ, bio, mirror_num, bio_flags);
if (ret || !wait)
return ret;
for (i = start_i; i < num_pages; i++) {
page = extent_buffer_page(eb, i);
wait_on_page_locked(page);
if (!PageUptodate(page))
ret = -EIO;
}
if (!ret)
set_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags);
return ret;
unlock_exit:
i = start_i;
while (locked_pages > 0) {
page = extent_buffer_page(eb, i);
i++;
unlock_page(page);
locked_pages--;
}
return ret;
}
void read_extent_buffer(struct extent_buffer *eb, void *dstv,
unsigned long start,
unsigned long len)
{
size_t cur;
size_t offset;
struct page *page;
char *kaddr;
char *dst = (char *)dstv;
size_t start_offset = eb->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + start) >> PAGE_CACHE_SHIFT;
WARN_ON(start > eb->len);
WARN_ON(start + len > eb->start + eb->len);
offset = (start_offset + start) & ((unsigned long)PAGE_CACHE_SIZE - 1);
while (len > 0) {
page = extent_buffer_page(eb, i);
cur = min(len, (PAGE_CACHE_SIZE - offset));
kaddr = kmap_atomic(page, KM_USER1);
memcpy(dst, kaddr + offset, cur);
kunmap_atomic(kaddr, KM_USER1);
dst += cur;
len -= cur;
offset = 0;
i++;
}
}
int map_private_extent_buffer(struct extent_buffer *eb, unsigned long start,
unsigned long min_len, char **token, char **map,
unsigned long *map_start,
unsigned long *map_len, int km)
{
size_t offset = start & (PAGE_CACHE_SIZE - 1);
char *kaddr;
struct page *p;
size_t start_offset = eb->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + start) >> PAGE_CACHE_SHIFT;
unsigned long end_i = (start_offset + start + min_len - 1) >>
PAGE_CACHE_SHIFT;
if (i != end_i)
return -EINVAL;
if (i == 0) {
offset = start_offset;
*map_start = 0;
} else {
offset = 0;
*map_start = ((u64)i << PAGE_CACHE_SHIFT) - start_offset;
}
if (start + min_len > eb->len) {
printk(KERN_ERR "btrfs bad mapping eb start %llu len %lu, "
"wanted %lu %lu\n", (unsigned long long)eb->start,
eb->len, start, min_len);
WARN_ON(1);
return -EINVAL;
}
p = extent_buffer_page(eb, i);
kaddr = kmap_atomic(p, km);
*token = kaddr;
*map = kaddr + offset;
*map_len = PAGE_CACHE_SIZE - offset;
return 0;
}
int map_extent_buffer(struct extent_buffer *eb, unsigned long start,
unsigned long min_len,
char **token, char **map,
unsigned long *map_start,
unsigned long *map_len, int km)
{
int err;
int save = 0;
if (eb->map_token) {
unmap_extent_buffer(eb, eb->map_token, km);
eb->map_token = NULL;
save = 1;
}
err = map_private_extent_buffer(eb, start, min_len, token, map,
map_start, map_len, km);
if (!err && save) {
eb->map_token = *token;
eb->kaddr = *map;
eb->map_start = *map_start;
eb->map_len = *map_len;
}
return err;
}
void unmap_extent_buffer(struct extent_buffer *eb, char *token, int km)
{
kunmap_atomic(token, km);
}
int memcmp_extent_buffer(struct extent_buffer *eb, const void *ptrv,
unsigned long start,
unsigned long len)
{
size_t cur;
size_t offset;
struct page *page;
char *kaddr;
char *ptr = (char *)ptrv;
size_t start_offset = eb->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + start) >> PAGE_CACHE_SHIFT;
int ret = 0;
WARN_ON(start > eb->len);
WARN_ON(start + len > eb->start + eb->len);
offset = (start_offset + start) & ((unsigned long)PAGE_CACHE_SIZE - 1);
while (len > 0) {
page = extent_buffer_page(eb, i);
cur = min(len, (PAGE_CACHE_SIZE - offset));
kaddr = kmap_atomic(page, KM_USER0);
ret = memcmp(ptr, kaddr + offset, cur);
kunmap_atomic(kaddr, KM_USER0);
if (ret)
break;
ptr += cur;
len -= cur;
offset = 0;
i++;
}
return ret;
}
void write_extent_buffer(struct extent_buffer *eb, const void *srcv,
unsigned long start, unsigned long len)
{
size_t cur;
size_t offset;
struct page *page;
char *kaddr;
char *src = (char *)srcv;
size_t start_offset = eb->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + start) >> PAGE_CACHE_SHIFT;
WARN_ON(start > eb->len);
WARN_ON(start + len > eb->start + eb->len);
offset = (start_offset + start) & ((unsigned long)PAGE_CACHE_SIZE - 1);
while (len > 0) {
page = extent_buffer_page(eb, i);
WARN_ON(!PageUptodate(page));
cur = min(len, PAGE_CACHE_SIZE - offset);
kaddr = kmap_atomic(page, KM_USER1);
memcpy(kaddr + offset, src, cur);
kunmap_atomic(kaddr, KM_USER1);
src += cur;
len -= cur;
offset = 0;
i++;
}
}
void memset_extent_buffer(struct extent_buffer *eb, char c,
unsigned long start, unsigned long len)
{
size_t cur;
size_t offset;
struct page *page;
char *kaddr;
size_t start_offset = eb->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + start) >> PAGE_CACHE_SHIFT;
WARN_ON(start > eb->len);
WARN_ON(start + len > eb->start + eb->len);
offset = (start_offset + start) & ((unsigned long)PAGE_CACHE_SIZE - 1);
while (len > 0) {
page = extent_buffer_page(eb, i);
WARN_ON(!PageUptodate(page));
cur = min(len, PAGE_CACHE_SIZE - offset);
kaddr = kmap_atomic(page, KM_USER0);
memset(kaddr + offset, c, cur);
kunmap_atomic(kaddr, KM_USER0);
len -= cur;
offset = 0;
i++;
}
}
void copy_extent_buffer(struct extent_buffer *dst, struct extent_buffer *src,
unsigned long dst_offset, unsigned long src_offset,
unsigned long len)
{
u64 dst_len = dst->len;
size_t cur;
size_t offset;
struct page *page;
char *kaddr;
size_t start_offset = dst->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long i = (start_offset + dst_offset) >> PAGE_CACHE_SHIFT;
WARN_ON(src->len != dst_len);
offset = (start_offset + dst_offset) &
((unsigned long)PAGE_CACHE_SIZE - 1);
while (len > 0) {
page = extent_buffer_page(dst, i);
WARN_ON(!PageUptodate(page));
cur = min(len, (unsigned long)(PAGE_CACHE_SIZE - offset));
kaddr = kmap_atomic(page, KM_USER0);
read_extent_buffer(src, kaddr + offset, src_offset, cur);
kunmap_atomic(kaddr, KM_USER0);
src_offset += cur;
len -= cur;
offset = 0;
i++;
}
}
static void move_pages(struct page *dst_page, struct page *src_page,
unsigned long dst_off, unsigned long src_off,
unsigned long len)
{
char *dst_kaddr = kmap_atomic(dst_page, KM_USER0);
if (dst_page == src_page) {
memmove(dst_kaddr + dst_off, dst_kaddr + src_off, len);
} else {
char *src_kaddr = kmap_atomic(src_page, KM_USER1);
char *p = dst_kaddr + dst_off + len;
char *s = src_kaddr + src_off + len;
while (len--)
*--p = *--s;
kunmap_atomic(src_kaddr, KM_USER1);
}
kunmap_atomic(dst_kaddr, KM_USER0);
}
static inline bool areas_overlap(unsigned long src, unsigned long dst, unsigned long len)
{
unsigned long distance = (src > dst) ? src - dst : dst - src;
return distance < len;
}
static void copy_pages(struct page *dst_page, struct page *src_page,
unsigned long dst_off, unsigned long src_off,
unsigned long len)
{
char *dst_kaddr = kmap_atomic(dst_page, KM_USER0);
char *src_kaddr;
if (dst_page != src_page) {
src_kaddr = kmap_atomic(src_page, KM_USER1);
} else {
src_kaddr = dst_kaddr;
BUG_ON(areas_overlap(src_off, dst_off, len));
}
memcpy(dst_kaddr + dst_off, src_kaddr + src_off, len);
kunmap_atomic(dst_kaddr, KM_USER0);
if (dst_page != src_page)
kunmap_atomic(src_kaddr, KM_USER1);
}
void memcpy_extent_buffer(struct extent_buffer *dst, unsigned long dst_offset,
unsigned long src_offset, unsigned long len)
{
size_t cur;
size_t dst_off_in_page;
size_t src_off_in_page;
size_t start_offset = dst->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long dst_i;
unsigned long src_i;
if (src_offset + len > dst->len) {
printk(KERN_ERR "btrfs memmove bogus src_offset %lu move "
"len %lu dst len %lu\n", src_offset, len, dst->len);
BUG_ON(1);
}
if (dst_offset + len > dst->len) {
printk(KERN_ERR "btrfs memmove bogus dst_offset %lu move "
"len %lu dst len %lu\n", dst_offset, len, dst->len);
BUG_ON(1);
}
while (len > 0) {
dst_off_in_page = (start_offset + dst_offset) &
((unsigned long)PAGE_CACHE_SIZE - 1);
src_off_in_page = (start_offset + src_offset) &
((unsigned long)PAGE_CACHE_SIZE - 1);
dst_i = (start_offset + dst_offset) >> PAGE_CACHE_SHIFT;
src_i = (start_offset + src_offset) >> PAGE_CACHE_SHIFT;
cur = min(len, (unsigned long)(PAGE_CACHE_SIZE -
src_off_in_page));
cur = min_t(unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page));
copy_pages(extent_buffer_page(dst, dst_i),
extent_buffer_page(dst, src_i),
dst_off_in_page, src_off_in_page, cur);
src_offset += cur;
dst_offset += cur;
len -= cur;
}
}
void memmove_extent_buffer(struct extent_buffer *dst, unsigned long dst_offset,
unsigned long src_offset, unsigned long len)
{
size_t cur;
size_t dst_off_in_page;
size_t src_off_in_page;
unsigned long dst_end = dst_offset + len - 1;
unsigned long src_end = src_offset + len - 1;
size_t start_offset = dst->start & ((u64)PAGE_CACHE_SIZE - 1);
unsigned long dst_i;
unsigned long src_i;
if (src_offset + len > dst->len) {
printk(KERN_ERR "btrfs memmove bogus src_offset %lu move "
"len %lu len %lu\n", src_offset, len, dst->len);
BUG_ON(1);
}
if (dst_offset + len > dst->len) {
printk(KERN_ERR "btrfs memmove bogus dst_offset %lu move "
"len %lu len %lu\n", dst_offset, len, dst->len);
BUG_ON(1);
}
if (!areas_overlap(src_offset, dst_offset, len)) {
memcpy_extent_buffer(dst, dst_offset, src_offset, len);
return;
}
while (len > 0) {
dst_i = (start_offset + dst_end) >> PAGE_CACHE_SHIFT;
src_i = (start_offset + src_end) >> PAGE_CACHE_SHIFT;
dst_off_in_page = (start_offset + dst_end) &
((unsigned long)PAGE_CACHE_SIZE - 1);
src_off_in_page = (start_offset + src_end) &
((unsigned long)PAGE_CACHE_SIZE - 1);
cur = min_t(unsigned long, len, src_off_in_page + 1);
cur = min(cur, dst_off_in_page + 1);
move_pages(extent_buffer_page(dst, dst_i),
extent_buffer_page(dst, src_i),
dst_off_in_page - cur + 1,
src_off_in_page - cur + 1, cur);
dst_end -= cur;
src_end -= cur;
len -= cur;
}
}
static inline void btrfs_release_extent_buffer_rcu(struct rcu_head *head)
{
struct extent_buffer *eb =
container_of(head, struct extent_buffer, rcu_head);
btrfs_release_extent_buffer(eb);
}
int try_release_extent_buffer(struct extent_io_tree *tree, struct page *page)
{
u64 start = page_offset(page);
struct extent_buffer *eb;
int ret = 1;
spin_lock(&tree->buffer_lock);
eb = radix_tree_lookup(&tree->buffer, start >> PAGE_CACHE_SHIFT);
if (!eb) {
spin_unlock(&tree->buffer_lock);
return ret;
}
if (test_bit(EXTENT_BUFFER_DIRTY, &eb->bflags)) {
ret = 0;
goto out;
}
if (atomic_cmpxchg(&eb->refs, 1, 0) != 1) {
ret = 0;
goto out;
}
radix_tree_delete(&tree->buffer, start >> PAGE_CACHE_SHIFT);
out:
spin_unlock(&tree->buffer_lock);
if (atomic_read(&eb->refs) == 0)
call_rcu(&eb->rcu_head, btrfs_release_extent_buffer_rcu);
return ret;
}
