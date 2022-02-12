static noinline void save_stack(struct drm_mm_node *node)
{
unsigned long entries[STACKDEPTH];
struct stack_trace trace = {
.entries = entries,
.max_entries = STACKDEPTH,
.skip = 1
};
save_stack_trace(&trace);
if (trace.nr_entries != 0 &&
trace.entries[trace.nr_entries-1] == ULONG_MAX)
trace.nr_entries--;
node->stack = depot_save_stack(&trace, GFP_NOWAIT);
}
static void show_leaks(struct drm_mm *mm)
{
struct drm_mm_node *node;
unsigned long entries[STACKDEPTH];
char *buf;
buf = kmalloc(BUFSZ, GFP_KERNEL);
if (!buf)
return;
list_for_each_entry(node, drm_mm_nodes(mm), node_list) {
struct stack_trace trace = {
.entries = entries,
.max_entries = STACKDEPTH
};
if (!node->stack) {
DRM_ERROR("node [%08llx + %08llx]: unknown owner\n",
node->start, node->size);
continue;
}
depot_fetch_stack(node->stack, &trace);
snprint_stack_trace(buf, BUFSZ, &trace, 0);
DRM_ERROR("node [%08llx + %08llx]: inserted at\n%s",
node->start, node->size, buf);
}
kfree(buf);
}
static void save_stack(struct drm_mm_node *node) { }
static void show_leaks(struct drm_mm *mm) { }
struct drm_mm_node *
__drm_mm_interval_first(const struct drm_mm *mm, u64 start, u64 last)
{
return drm_mm_interval_tree_iter_first((struct rb_root *)&mm->interval_tree,
start, last);
}
static void drm_mm_interval_tree_add_node(struct drm_mm_node *hole_node,
struct drm_mm_node *node)
{
struct drm_mm *mm = hole_node->mm;
struct rb_node **link, *rb;
struct drm_mm_node *parent;
node->__subtree_last = LAST(node);
if (hole_node->allocated) {
rb = &hole_node->rb;
while (rb) {
parent = rb_entry(rb, struct drm_mm_node, rb);
if (parent->__subtree_last >= node->__subtree_last)
break;
parent->__subtree_last = node->__subtree_last;
rb = rb_parent(rb);
}
rb = &hole_node->rb;
link = &hole_node->rb.rb_right;
} else {
rb = NULL;
link = &mm->interval_tree.rb_node;
}
while (*link) {
rb = *link;
parent = rb_entry(rb, struct drm_mm_node, rb);
if (parent->__subtree_last < node->__subtree_last)
parent->__subtree_last = node->__subtree_last;
if (node->start < parent->start)
link = &parent->rb.rb_left;
else
link = &parent->rb.rb_right;
}
rb_link_node(&node->rb, rb, link);
rb_insert_augmented(&node->rb,
&mm->interval_tree,
&drm_mm_interval_tree_augment);
}
static void add_hole(struct drm_mm_node *node)
{
struct drm_mm *mm = node->mm;
node->hole_size =
__drm_mm_hole_node_end(node) - __drm_mm_hole_node_start(node);
DRM_MM_BUG_ON(!drm_mm_hole_follows(node));
RB_INSERT(mm->holes_size, rb_hole_size, HOLE_SIZE);
RB_INSERT(mm->holes_addr, rb_hole_addr, HOLE_ADDR);
list_add(&node->hole_stack, &mm->hole_stack);
}
static void rm_hole(struct drm_mm_node *node)
{
DRM_MM_BUG_ON(!drm_mm_hole_follows(node));
list_del(&node->hole_stack);
rb_erase(&node->rb_hole_size, &node->mm->holes_size);
rb_erase(&node->rb_hole_addr, &node->mm->holes_addr);
node->hole_size = 0;
DRM_MM_BUG_ON(drm_mm_hole_follows(node));
}
static inline struct drm_mm_node *rb_hole_size_to_node(struct rb_node *rb)
{
return rb_entry_safe(rb, struct drm_mm_node, rb_hole_size);
}
static inline struct drm_mm_node *rb_hole_addr_to_node(struct rb_node *rb)
{
return rb_entry_safe(rb, struct drm_mm_node, rb_hole_addr);
}
static inline u64 rb_hole_size(struct rb_node *rb)
{
return rb_entry(rb, struct drm_mm_node, rb_hole_size)->hole_size;
}
static struct drm_mm_node *best_hole(struct drm_mm *mm, u64 size)
{
struct rb_node *best = NULL;
struct rb_node **link = &mm->holes_size.rb_node;
while (*link) {
struct rb_node *rb = *link;
if (size <= rb_hole_size(rb)) {
link = &rb->rb_left;
best = rb;
} else {
link = &rb->rb_right;
}
}
return rb_hole_size_to_node(best);
}
static struct drm_mm_node *find_hole(struct drm_mm *mm, u64 addr)
{
struct drm_mm_node *node = NULL;
struct rb_node **link = &mm->holes_addr.rb_node;
while (*link) {
u64 hole_start;
node = rb_hole_addr_to_node(*link);
hole_start = __drm_mm_hole_node_start(node);
if (addr < hole_start)
link = &node->rb_hole_addr.rb_left;
else if (addr > hole_start + node->hole_size)
link = &node->rb_hole_addr.rb_right;
else
break;
}
return node;
}
static struct drm_mm_node *
first_hole(struct drm_mm *mm,
u64 start, u64 end, u64 size,
enum drm_mm_insert_mode mode)
{
if (RB_EMPTY_ROOT(&mm->holes_size))
return NULL;
switch (mode) {
default:
case DRM_MM_INSERT_BEST:
return best_hole(mm, size);
case DRM_MM_INSERT_LOW:
return find_hole(mm, start);
case DRM_MM_INSERT_HIGH:
return find_hole(mm, end);
case DRM_MM_INSERT_EVICT:
return list_first_entry_or_null(&mm->hole_stack,
struct drm_mm_node,
hole_stack);
}
}
static struct drm_mm_node *
next_hole(struct drm_mm *mm,
struct drm_mm_node *node,
enum drm_mm_insert_mode mode)
{
switch (mode) {
default:
case DRM_MM_INSERT_BEST:
return rb_hole_size_to_node(rb_next(&node->rb_hole_size));
case DRM_MM_INSERT_LOW:
return rb_hole_addr_to_node(rb_next(&node->rb_hole_addr));
case DRM_MM_INSERT_HIGH:
return rb_hole_addr_to_node(rb_prev(&node->rb_hole_addr));
case DRM_MM_INSERT_EVICT:
node = list_next_entry(node, hole_stack);
return &node->hole_stack == &mm->hole_stack ? NULL : node;
}
}
int drm_mm_reserve_node(struct drm_mm *mm, struct drm_mm_node *node)
{
u64 end = node->start + node->size;
struct drm_mm_node *hole;
u64 hole_start, hole_end;
u64 adj_start, adj_end;
end = node->start + node->size;
if (unlikely(end <= node->start))
return -ENOSPC;
hole = find_hole(mm, node->start);
if (!hole)
return -ENOSPC;
adj_start = hole_start = __drm_mm_hole_node_start(hole);
adj_end = hole_end = hole_start + hole->hole_size;
if (mm->color_adjust)
mm->color_adjust(hole, node->color, &adj_start, &adj_end);
if (adj_start > node->start || adj_end < end)
return -ENOSPC;
node->mm = mm;
list_add(&node->node_list, &hole->node_list);
drm_mm_interval_tree_add_node(hole, node);
node->allocated = true;
node->hole_size = 0;
rm_hole(hole);
if (node->start > hole_start)
add_hole(hole);
if (end < hole_end)
add_hole(node);
save_stack(node);
return 0;
}
int drm_mm_insert_node_in_range(struct drm_mm * const mm,
struct drm_mm_node * const node,
u64 size, u64 alignment,
unsigned long color,
u64 range_start, u64 range_end,
enum drm_mm_insert_mode mode)
{
struct drm_mm_node *hole;
u64 remainder_mask;
DRM_MM_BUG_ON(range_start >= range_end);
if (unlikely(size == 0 || range_end - range_start < size))
return -ENOSPC;
if (alignment <= 1)
alignment = 0;
remainder_mask = is_power_of_2(alignment) ? alignment - 1 : 0;
for (hole = first_hole(mm, range_start, range_end, size, mode); hole;
hole = next_hole(mm, hole, mode)) {
u64 hole_start = __drm_mm_hole_node_start(hole);
u64 hole_end = hole_start + hole->hole_size;
u64 adj_start, adj_end;
u64 col_start, col_end;
if (mode == DRM_MM_INSERT_LOW && hole_start >= range_end)
break;
if (mode == DRM_MM_INSERT_HIGH && hole_end <= range_start)
break;
col_start = hole_start;
col_end = hole_end;
if (mm->color_adjust)
mm->color_adjust(hole, color, &col_start, &col_end);
adj_start = max(col_start, range_start);
adj_end = min(col_end, range_end);
if (adj_end <= adj_start || adj_end - adj_start < size)
continue;
if (mode == DRM_MM_INSERT_HIGH)
adj_start = adj_end - size;
if (alignment) {
u64 rem;
if (likely(remainder_mask))
rem = adj_start & remainder_mask;
else
div64_u64_rem(adj_start, alignment, &rem);
if (rem) {
adj_start -= rem;
if (mode != DRM_MM_INSERT_HIGH)
adj_start += alignment;
if (adj_start < max(col_start, range_start) ||
min(col_end, range_end) - adj_start < size)
continue;
if (adj_end <= adj_start ||
adj_end - adj_start < size)
continue;
}
}
node->mm = mm;
node->size = size;
node->start = adj_start;
node->color = color;
node->hole_size = 0;
list_add(&node->node_list, &hole->node_list);
drm_mm_interval_tree_add_node(hole, node);
node->allocated = true;
rm_hole(hole);
if (adj_start > hole_start)
add_hole(hole);
if (adj_start + size < hole_end)
add_hole(node);
save_stack(node);
return 0;
}
return -ENOSPC;
}
void drm_mm_remove_node(struct drm_mm_node *node)
{
struct drm_mm *mm = node->mm;
struct drm_mm_node *prev_node;
DRM_MM_BUG_ON(!node->allocated);
DRM_MM_BUG_ON(node->scanned_block);
prev_node = list_prev_entry(node, node_list);
if (drm_mm_hole_follows(node))
rm_hole(node);
drm_mm_interval_tree_remove(node, &mm->interval_tree);
list_del(&node->node_list);
node->allocated = false;
if (drm_mm_hole_follows(prev_node))
rm_hole(prev_node);
add_hole(prev_node);
}
void drm_mm_replace_node(struct drm_mm_node *old, struct drm_mm_node *new)
{
DRM_MM_BUG_ON(!old->allocated);
*new = *old;
list_replace(&old->node_list, &new->node_list);
rb_replace_node(&old->rb, &new->rb, &old->mm->interval_tree);
if (drm_mm_hole_follows(old)) {
list_replace(&old->hole_stack, &new->hole_stack);
rb_replace_node(&old->rb_hole_size,
&new->rb_hole_size,
&old->mm->holes_size);
rb_replace_node(&old->rb_hole_addr,
&new->rb_hole_addr,
&old->mm->holes_addr);
}
old->allocated = false;
new->allocated = true;
}
void drm_mm_scan_init_with_range(struct drm_mm_scan *scan,
struct drm_mm *mm,
u64 size,
u64 alignment,
unsigned long color,
u64 start,
u64 end,
enum drm_mm_insert_mode mode)
{
DRM_MM_BUG_ON(start >= end);
DRM_MM_BUG_ON(!size || size > end - start);
DRM_MM_BUG_ON(mm->scan_active);
scan->mm = mm;
if (alignment <= 1)
alignment = 0;
scan->color = color;
scan->alignment = alignment;
scan->remainder_mask = is_power_of_2(alignment) ? alignment - 1 : 0;
scan->size = size;
scan->mode = mode;
DRM_MM_BUG_ON(end <= start);
scan->range_start = start;
scan->range_end = end;
scan->hit_start = U64_MAX;
scan->hit_end = 0;
}
bool drm_mm_scan_add_block(struct drm_mm_scan *scan,
struct drm_mm_node *node)
{
struct drm_mm *mm = scan->mm;
struct drm_mm_node *hole;
u64 hole_start, hole_end;
u64 col_start, col_end;
u64 adj_start, adj_end;
DRM_MM_BUG_ON(node->mm != mm);
DRM_MM_BUG_ON(!node->allocated);
DRM_MM_BUG_ON(node->scanned_block);
node->scanned_block = true;
mm->scan_active++;
hole = list_prev_entry(node, node_list);
DRM_MM_BUG_ON(list_next_entry(hole, node_list) != node);
__list_del_entry(&node->node_list);
hole_start = __drm_mm_hole_node_start(hole);
hole_end = __drm_mm_hole_node_end(hole);
col_start = hole_start;
col_end = hole_end;
if (mm->color_adjust)
mm->color_adjust(hole, scan->color, &col_start, &col_end);
adj_start = max(col_start, scan->range_start);
adj_end = min(col_end, scan->range_end);
if (adj_end <= adj_start || adj_end - adj_start < scan->size)
return false;
if (scan->mode == DRM_MM_INSERT_HIGH)
adj_start = adj_end - scan->size;
if (scan->alignment) {
u64 rem;
if (likely(scan->remainder_mask))
rem = adj_start & scan->remainder_mask;
else
div64_u64_rem(adj_start, scan->alignment, &rem);
if (rem) {
adj_start -= rem;
if (scan->mode != DRM_MM_INSERT_HIGH)
adj_start += scan->alignment;
if (adj_start < max(col_start, scan->range_start) ||
min(col_end, scan->range_end) - adj_start < scan->size)
return false;
if (adj_end <= adj_start ||
adj_end - adj_start < scan->size)
return false;
}
}
scan->hit_start = adj_start;
scan->hit_end = adj_start + scan->size;
DRM_MM_BUG_ON(scan->hit_start >= scan->hit_end);
DRM_MM_BUG_ON(scan->hit_start < hole_start);
DRM_MM_BUG_ON(scan->hit_end > hole_end);
return true;
}
bool drm_mm_scan_remove_block(struct drm_mm_scan *scan,
struct drm_mm_node *node)
{
struct drm_mm_node *prev_node;
DRM_MM_BUG_ON(node->mm != scan->mm);
DRM_MM_BUG_ON(!node->scanned_block);
node->scanned_block = false;
DRM_MM_BUG_ON(!node->mm->scan_active);
node->mm->scan_active--;
prev_node = list_prev_entry(node, node_list);
DRM_MM_BUG_ON(list_next_entry(prev_node, node_list) !=
list_next_entry(node, node_list));
list_add(&node->node_list, &prev_node->node_list);
return (node->start + node->size > scan->hit_start &&
node->start < scan->hit_end);
}
struct drm_mm_node *drm_mm_scan_color_evict(struct drm_mm_scan *scan)
{
struct drm_mm *mm = scan->mm;
struct drm_mm_node *hole;
u64 hole_start, hole_end;
DRM_MM_BUG_ON(list_empty(&mm->hole_stack));
if (!mm->color_adjust)
return NULL;
hole = list_first_entry(&mm->hole_stack, typeof(*hole), hole_stack);
hole_start = __drm_mm_hole_node_start(hole);
hole_end = hole_start + hole->hole_size;
DRM_MM_BUG_ON(hole_start > scan->hit_start);
DRM_MM_BUG_ON(hole_end < scan->hit_end);
mm->color_adjust(hole, scan->color, &hole_start, &hole_end);
if (hole_start > scan->hit_start)
return hole;
if (hole_end < scan->hit_end)
return list_next_entry(hole, node_list);
return NULL;
}
void drm_mm_init(struct drm_mm *mm, u64 start, u64 size)
{
DRM_MM_BUG_ON(start + size <= start);
mm->color_adjust = NULL;
INIT_LIST_HEAD(&mm->hole_stack);
mm->interval_tree = RB_ROOT;
mm->holes_size = RB_ROOT;
mm->holes_addr = RB_ROOT;
INIT_LIST_HEAD(&mm->head_node.node_list);
mm->head_node.allocated = false;
mm->head_node.mm = mm;
mm->head_node.start = start + size;
mm->head_node.size = -size;
add_hole(&mm->head_node);
mm->scan_active = 0;
}
void drm_mm_takedown(struct drm_mm *mm)
{
if (WARN(!drm_mm_clean(mm),
"Memory manager not clean during takedown.\n"))
show_leaks(mm);
}
static u64 drm_mm_dump_hole(struct drm_printer *p, const struct drm_mm_node *entry)
{
u64 start, size;
size = entry->hole_size;
if (size) {
start = drm_mm_hole_node_start(entry);
drm_printf(p, "%#018llx-%#018llx: %llu: free\n",
start, start + size, size);
}
return size;
}
void drm_mm_print(const struct drm_mm *mm, struct drm_printer *p)
{
const struct drm_mm_node *entry;
u64 total_used = 0, total_free = 0, total = 0;
total_free += drm_mm_dump_hole(p, &mm->head_node);
drm_mm_for_each_node(entry, mm) {
drm_printf(p, "%#018llx-%#018llx: %llu: used\n", entry->start,
entry->start + entry->size, entry->size);
total_used += entry->size;
total_free += drm_mm_dump_hole(p, entry);
}
total = total_free + total_used;
drm_printf(p, "total: %llu, used %llu free %llu\n", total,
total_used, total_free);
}
