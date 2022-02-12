static void drm_mm_insert_helper(struct drm_mm_node *hole_node,
struct drm_mm_node *node,
u64 size, unsigned alignment,
unsigned long color,
enum drm_mm_allocator_flags flags)
{
struct drm_mm *mm = hole_node->mm;
u64 hole_start = drm_mm_hole_node_start(hole_node);
u64 hole_end = drm_mm_hole_node_end(hole_node);
u64 adj_start = hole_start;
u64 adj_end = hole_end;
BUG_ON(node->allocated);
if (mm->color_adjust)
mm->color_adjust(hole_node, color, &adj_start, &adj_end);
if (flags & DRM_MM_CREATE_TOP)
adj_start = adj_end - size;
if (alignment) {
u64 tmp = adj_start;
unsigned rem;
rem = do_div(tmp, alignment);
if (rem) {
if (flags & DRM_MM_CREATE_TOP)
adj_start -= rem;
else
adj_start += alignment - rem;
}
}
BUG_ON(adj_start < hole_start);
BUG_ON(adj_end > hole_end);
if (adj_start == hole_start) {
hole_node->hole_follows = 0;
list_del(&hole_node->hole_stack);
}
node->start = adj_start;
node->size = size;
node->mm = mm;
node->color = color;
node->allocated = 1;
INIT_LIST_HEAD(&node->hole_stack);
list_add(&node->node_list, &hole_node->node_list);
BUG_ON(node->start + node->size > adj_end);
node->hole_follows = 0;
if (__drm_mm_hole_node_start(node) < hole_end) {
list_add(&node->hole_stack, &mm->hole_stack);
node->hole_follows = 1;
}
}
int drm_mm_reserve_node(struct drm_mm *mm, struct drm_mm_node *node)
{
struct drm_mm_node *hole;
u64 end = node->start + node->size;
u64 hole_start;
u64 hole_end;
BUG_ON(node == NULL);
drm_mm_for_each_hole(hole, mm, hole_start, hole_end) {
if (hole_start > node->start || hole_end < end)
continue;
node->mm = mm;
node->allocated = 1;
INIT_LIST_HEAD(&node->hole_stack);
list_add(&node->node_list, &hole->node_list);
if (node->start == hole_start) {
hole->hole_follows = 0;
list_del_init(&hole->hole_stack);
}
node->hole_follows = 0;
if (end != hole_end) {
list_add(&node->hole_stack, &mm->hole_stack);
node->hole_follows = 1;
}
return 0;
}
return -ENOSPC;
}
int drm_mm_insert_node_generic(struct drm_mm *mm, struct drm_mm_node *node,
u64 size, unsigned alignment,
unsigned long color,
enum drm_mm_search_flags sflags,
enum drm_mm_allocator_flags aflags)
{
struct drm_mm_node *hole_node;
hole_node = drm_mm_search_free_generic(mm, size, alignment,
color, sflags);
if (!hole_node)
return -ENOSPC;
drm_mm_insert_helper(hole_node, node, size, alignment, color, aflags);
return 0;
}
static void drm_mm_insert_helper_range(struct drm_mm_node *hole_node,
struct drm_mm_node *node,
u64 size, unsigned alignment,
unsigned long color,
u64 start, u64 end,
enum drm_mm_allocator_flags flags)
{
struct drm_mm *mm = hole_node->mm;
u64 hole_start = drm_mm_hole_node_start(hole_node);
u64 hole_end = drm_mm_hole_node_end(hole_node);
u64 adj_start = hole_start;
u64 adj_end = hole_end;
BUG_ON(!hole_node->hole_follows || node->allocated);
if (adj_start < start)
adj_start = start;
if (adj_end > end)
adj_end = end;
if (flags & DRM_MM_CREATE_TOP)
adj_start = adj_end - size;
if (mm->color_adjust)
mm->color_adjust(hole_node, color, &adj_start, &adj_end);
if (alignment) {
u64 tmp = adj_start;
unsigned rem;
rem = do_div(tmp, alignment);
if (rem) {
if (flags & DRM_MM_CREATE_TOP)
adj_start -= rem;
else
adj_start += alignment - rem;
}
}
if (adj_start == hole_start) {
hole_node->hole_follows = 0;
list_del(&hole_node->hole_stack);
}
node->start = adj_start;
node->size = size;
node->mm = mm;
node->color = color;
node->allocated = 1;
INIT_LIST_HEAD(&node->hole_stack);
list_add(&node->node_list, &hole_node->node_list);
BUG_ON(node->start < start);
BUG_ON(node->start < adj_start);
BUG_ON(node->start + node->size > adj_end);
BUG_ON(node->start + node->size > end);
node->hole_follows = 0;
if (__drm_mm_hole_node_start(node) < hole_end) {
list_add(&node->hole_stack, &mm->hole_stack);
node->hole_follows = 1;
}
}
int drm_mm_insert_node_in_range_generic(struct drm_mm *mm, struct drm_mm_node *node,
u64 size, unsigned alignment,
unsigned long color,
u64 start, u64 end,
enum drm_mm_search_flags sflags,
enum drm_mm_allocator_flags aflags)
{
struct drm_mm_node *hole_node;
hole_node = drm_mm_search_free_in_range_generic(mm,
size, alignment, color,
start, end, sflags);
if (!hole_node)
return -ENOSPC;
drm_mm_insert_helper_range(hole_node, node,
size, alignment, color,
start, end, aflags);
return 0;
}
void drm_mm_remove_node(struct drm_mm_node *node)
{
struct drm_mm *mm = node->mm;
struct drm_mm_node *prev_node;
if (WARN_ON(!node->allocated))
return;
BUG_ON(node->scanned_block || node->scanned_prev_free
|| node->scanned_next_free);
prev_node =
list_entry(node->node_list.prev, struct drm_mm_node, node_list);
if (node->hole_follows) {
BUG_ON(__drm_mm_hole_node_start(node) ==
__drm_mm_hole_node_end(node));
list_del(&node->hole_stack);
} else
BUG_ON(__drm_mm_hole_node_start(node) !=
__drm_mm_hole_node_end(node));
if (!prev_node->hole_follows) {
prev_node->hole_follows = 1;
list_add(&prev_node->hole_stack, &mm->hole_stack);
} else
list_move(&prev_node->hole_stack, &mm->hole_stack);
list_del(&node->node_list);
node->allocated = 0;
}
static int check_free_hole(u64 start, u64 end, u64 size, unsigned alignment)
{
if (end - start < size)
return 0;
if (alignment) {
u64 tmp = start;
unsigned rem;
rem = do_div(tmp, alignment);
if (rem)
start += alignment - rem;
}
return end >= start + size;
}
static struct drm_mm_node *drm_mm_search_free_generic(const struct drm_mm *mm,
u64 size,
unsigned alignment,
unsigned long color,
enum drm_mm_search_flags flags)
{
struct drm_mm_node *entry;
struct drm_mm_node *best;
u64 adj_start;
u64 adj_end;
u64 best_size;
BUG_ON(mm->scanned_blocks);
best = NULL;
best_size = ~0UL;
__drm_mm_for_each_hole(entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
u64 hole_size = adj_end - adj_start;
if (mm->color_adjust) {
mm->color_adjust(entry, color, &adj_start, &adj_end);
if (adj_end <= adj_start)
continue;
}
if (!check_free_hole(adj_start, adj_end, size, alignment))
continue;
if (!(flags & DRM_MM_SEARCH_BEST))
return entry;
if (hole_size < best_size) {
best = entry;
best_size = hole_size;
}
}
return best;
}
static struct drm_mm_node *drm_mm_search_free_in_range_generic(const struct drm_mm *mm,
u64 size,
unsigned alignment,
unsigned long color,
u64 start,
u64 end,
enum drm_mm_search_flags flags)
{
struct drm_mm_node *entry;
struct drm_mm_node *best;
u64 adj_start;
u64 adj_end;
u64 best_size;
BUG_ON(mm->scanned_blocks);
best = NULL;
best_size = ~0UL;
__drm_mm_for_each_hole(entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
u64 hole_size = adj_end - adj_start;
if (adj_start < start)
adj_start = start;
if (adj_end > end)
adj_end = end;
if (mm->color_adjust) {
mm->color_adjust(entry, color, &adj_start, &adj_end);
if (adj_end <= adj_start)
continue;
}
if (!check_free_hole(adj_start, adj_end, size, alignment))
continue;
if (!(flags & DRM_MM_SEARCH_BEST))
return entry;
if (hole_size < best_size) {
best = entry;
best_size = hole_size;
}
}
return best;
}
void drm_mm_replace_node(struct drm_mm_node *old, struct drm_mm_node *new)
{
list_replace(&old->node_list, &new->node_list);
list_replace(&old->hole_stack, &new->hole_stack);
new->hole_follows = old->hole_follows;
new->mm = old->mm;
new->start = old->start;
new->size = old->size;
new->color = old->color;
old->allocated = 0;
new->allocated = 1;
}
void drm_mm_init_scan(struct drm_mm *mm,
u64 size,
unsigned alignment,
unsigned long color)
{
mm->scan_color = color;
mm->scan_alignment = alignment;
mm->scan_size = size;
mm->scanned_blocks = 0;
mm->scan_hit_start = 0;
mm->scan_hit_end = 0;
mm->scan_check_range = 0;
mm->prev_scanned_node = NULL;
}
void drm_mm_init_scan_with_range(struct drm_mm *mm,
u64 size,
unsigned alignment,
unsigned long color,
u64 start,
u64 end)
{
mm->scan_color = color;
mm->scan_alignment = alignment;
mm->scan_size = size;
mm->scanned_blocks = 0;
mm->scan_hit_start = 0;
mm->scan_hit_end = 0;
mm->scan_start = start;
mm->scan_end = end;
mm->scan_check_range = 1;
mm->prev_scanned_node = NULL;
}
bool drm_mm_scan_add_block(struct drm_mm_node *node)
{
struct drm_mm *mm = node->mm;
struct drm_mm_node *prev_node;
u64 hole_start, hole_end;
u64 adj_start, adj_end;
mm->scanned_blocks++;
BUG_ON(node->scanned_block);
node->scanned_block = 1;
prev_node = list_entry(node->node_list.prev, struct drm_mm_node,
node_list);
node->scanned_preceeds_hole = prev_node->hole_follows;
prev_node->hole_follows = 1;
list_del(&node->node_list);
node->node_list.prev = &prev_node->node_list;
node->node_list.next = &mm->prev_scanned_node->node_list;
mm->prev_scanned_node = node;
adj_start = hole_start = drm_mm_hole_node_start(prev_node);
adj_end = hole_end = drm_mm_hole_node_end(prev_node);
if (mm->scan_check_range) {
if (adj_start < mm->scan_start)
adj_start = mm->scan_start;
if (adj_end > mm->scan_end)
adj_end = mm->scan_end;
}
if (mm->color_adjust)
mm->color_adjust(prev_node, mm->scan_color,
&adj_start, &adj_end);
if (check_free_hole(adj_start, adj_end,
mm->scan_size, mm->scan_alignment)) {
mm->scan_hit_start = hole_start;
mm->scan_hit_end = hole_end;
return true;
}
return false;
}
bool drm_mm_scan_remove_block(struct drm_mm_node *node)
{
struct drm_mm *mm = node->mm;
struct drm_mm_node *prev_node;
mm->scanned_blocks--;
BUG_ON(!node->scanned_block);
node->scanned_block = 0;
prev_node = list_entry(node->node_list.prev, struct drm_mm_node,
node_list);
prev_node->hole_follows = node->scanned_preceeds_hole;
list_add(&node->node_list, &prev_node->node_list);
return (drm_mm_hole_node_end(node) > mm->scan_hit_start &&
node->start < mm->scan_hit_end);
}
bool drm_mm_clean(struct drm_mm * mm)
{
struct list_head *head = &mm->head_node.node_list;
return (head->next->next == head);
}
void drm_mm_init(struct drm_mm * mm, u64 start, u64 size)
{
INIT_LIST_HEAD(&mm->hole_stack);
mm->scanned_blocks = 0;
INIT_LIST_HEAD(&mm->head_node.node_list);
INIT_LIST_HEAD(&mm->head_node.hole_stack);
mm->head_node.hole_follows = 1;
mm->head_node.scanned_block = 0;
mm->head_node.scanned_prev_free = 0;
mm->head_node.scanned_next_free = 0;
mm->head_node.mm = mm;
mm->head_node.start = start + size;
mm->head_node.size = start - mm->head_node.start;
list_add_tail(&mm->head_node.hole_stack, &mm->hole_stack);
mm->color_adjust = NULL;
}
void drm_mm_takedown(struct drm_mm * mm)
{
WARN(!list_empty(&mm->head_node.node_list),
"Memory manager not clean during takedown.\n");
}
static u64 drm_mm_debug_hole(struct drm_mm_node *entry,
const char *prefix)
{
u64 hole_start, hole_end, hole_size;
if (entry->hole_follows) {
hole_start = drm_mm_hole_node_start(entry);
hole_end = drm_mm_hole_node_end(entry);
hole_size = hole_end - hole_start;
pr_debug("%s %#llx-%#llx: %llu: free\n", prefix, hole_start,
hole_end, hole_size);
return hole_size;
}
return 0;
}
void drm_mm_debug_table(struct drm_mm *mm, const char *prefix)
{
struct drm_mm_node *entry;
u64 total_used = 0, total_free = 0, total = 0;
total_free += drm_mm_debug_hole(&mm->head_node, prefix);
drm_mm_for_each_node(entry, mm) {
pr_debug("%s %#llx-%#llx: %llu: used\n", prefix, entry->start,
entry->start + entry->size, entry->size);
total_used += entry->size;
total_free += drm_mm_debug_hole(entry, prefix);
}
total = total_free + total_used;
pr_debug("%s total: %llu, used %llu free %llu\n", prefix, total,
total_used, total_free);
}
static u64 drm_mm_dump_hole(struct seq_file *m, struct drm_mm_node *entry)
{
u64 hole_start, hole_end, hole_size;
if (entry->hole_follows) {
hole_start = drm_mm_hole_node_start(entry);
hole_end = drm_mm_hole_node_end(entry);
hole_size = hole_end - hole_start;
seq_printf(m, "%#llx-%#llx: %llu: free\n", hole_start,
hole_end, hole_size);
return hole_size;
}
return 0;
}
int drm_mm_dump_table(struct seq_file *m, struct drm_mm *mm)
{
struct drm_mm_node *entry;
u64 total_used = 0, total_free = 0, total = 0;
total_free += drm_mm_dump_hole(m, &mm->head_node);
drm_mm_for_each_node(entry, mm) {
seq_printf(m, "%#016llx-%#016llx: %llu: used\n", entry->start,
entry->start + entry->size, entry->size);
total_used += entry->size;
total_free += drm_mm_dump_hole(m, entry);
}
total = total_free + total_used;
seq_printf(m, "total: %llu, used %llu free %llu\n", total,
total_used, total_free);
return 0;
}
