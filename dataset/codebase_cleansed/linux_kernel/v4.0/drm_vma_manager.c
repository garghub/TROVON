void drm_vma_offset_manager_init(struct drm_vma_offset_manager *mgr,
unsigned long page_offset, unsigned long size)
{
rwlock_init(&mgr->vm_lock);
mgr->vm_addr_space_rb = RB_ROOT;
drm_mm_init(&mgr->vm_addr_space_mm, page_offset, size);
}
void drm_vma_offset_manager_destroy(struct drm_vma_offset_manager *mgr)
{
write_lock(&mgr->vm_lock);
drm_mm_takedown(&mgr->vm_addr_space_mm);
write_unlock(&mgr->vm_lock);
}
struct drm_vma_offset_node *drm_vma_offset_lookup(struct drm_vma_offset_manager *mgr,
unsigned long start,
unsigned long pages)
{
struct drm_vma_offset_node *node;
read_lock(&mgr->vm_lock);
node = drm_vma_offset_lookup_locked(mgr, start, pages);
read_unlock(&mgr->vm_lock);
return node;
}
struct drm_vma_offset_node *drm_vma_offset_lookup_locked(struct drm_vma_offset_manager *mgr,
unsigned long start,
unsigned long pages)
{
struct drm_vma_offset_node *node, *best;
struct rb_node *iter;
unsigned long offset;
iter = mgr->vm_addr_space_rb.rb_node;
best = NULL;
while (likely(iter)) {
node = rb_entry(iter, struct drm_vma_offset_node, vm_rb);
offset = node->vm_node.start;
if (start >= offset) {
iter = iter->rb_right;
best = node;
if (start == offset)
break;
} else {
iter = iter->rb_left;
}
}
if (best) {
offset = best->vm_node.start + best->vm_node.size;
if (offset < start + pages)
best = NULL;
}
return best;
}
static void _drm_vma_offset_add_rb(struct drm_vma_offset_manager *mgr,
struct drm_vma_offset_node *node)
{
struct rb_node **iter = &mgr->vm_addr_space_rb.rb_node;
struct rb_node *parent = NULL;
struct drm_vma_offset_node *iter_node;
while (likely(*iter)) {
parent = *iter;
iter_node = rb_entry(*iter, struct drm_vma_offset_node, vm_rb);
if (node->vm_node.start < iter_node->vm_node.start)
iter = &(*iter)->rb_left;
else if (node->vm_node.start > iter_node->vm_node.start)
iter = &(*iter)->rb_right;
else
BUG();
}
rb_link_node(&node->vm_rb, parent, iter);
rb_insert_color(&node->vm_rb, &mgr->vm_addr_space_rb);
}
int drm_vma_offset_add(struct drm_vma_offset_manager *mgr,
struct drm_vma_offset_node *node, unsigned long pages)
{
int ret;
write_lock(&mgr->vm_lock);
if (drm_mm_node_allocated(&node->vm_node)) {
ret = 0;
goto out_unlock;
}
ret = drm_mm_insert_node(&mgr->vm_addr_space_mm, &node->vm_node,
pages, 0, DRM_MM_SEARCH_DEFAULT);
if (ret)
goto out_unlock;
_drm_vma_offset_add_rb(mgr, node);
out_unlock:
write_unlock(&mgr->vm_lock);
return ret;
}
void drm_vma_offset_remove(struct drm_vma_offset_manager *mgr,
struct drm_vma_offset_node *node)
{
write_lock(&mgr->vm_lock);
if (drm_mm_node_allocated(&node->vm_node)) {
rb_erase(&node->vm_rb, &mgr->vm_addr_space_rb);
drm_mm_remove_node(&node->vm_node);
memset(&node->vm_node, 0, sizeof(node->vm_node));
}
write_unlock(&mgr->vm_lock);
}
int drm_vma_node_allow(struct drm_vma_offset_node *node, struct file *filp)
{
struct rb_node **iter;
struct rb_node *parent = NULL;
struct drm_vma_offset_file *new, *entry;
int ret = 0;
new = kmalloc(sizeof(*entry), GFP_KERNEL);
write_lock(&node->vm_lock);
iter = &node->vm_files.rb_node;
while (likely(*iter)) {
parent = *iter;
entry = rb_entry(*iter, struct drm_vma_offset_file, vm_rb);
if (filp == entry->vm_filp) {
entry->vm_count++;
goto unlock;
} else if (filp > entry->vm_filp) {
iter = &(*iter)->rb_right;
} else {
iter = &(*iter)->rb_left;
}
}
if (!new) {
ret = -ENOMEM;
goto unlock;
}
new->vm_filp = filp;
new->vm_count = 1;
rb_link_node(&new->vm_rb, parent, iter);
rb_insert_color(&new->vm_rb, &node->vm_files);
new = NULL;
unlock:
write_unlock(&node->vm_lock);
kfree(new);
return ret;
}
void drm_vma_node_revoke(struct drm_vma_offset_node *node, struct file *filp)
{
struct drm_vma_offset_file *entry;
struct rb_node *iter;
write_lock(&node->vm_lock);
iter = node->vm_files.rb_node;
while (likely(iter)) {
entry = rb_entry(iter, struct drm_vma_offset_file, vm_rb);
if (filp == entry->vm_filp) {
if (!--entry->vm_count) {
rb_erase(&entry->vm_rb, &node->vm_files);
kfree(entry);
}
break;
} else if (filp > entry->vm_filp) {
iter = iter->rb_right;
} else {
iter = iter->rb_left;
}
}
write_unlock(&node->vm_lock);
}
bool drm_vma_node_is_allowed(struct drm_vma_offset_node *node,
struct file *filp)
{
struct drm_vma_offset_file *entry;
struct rb_node *iter;
read_lock(&node->vm_lock);
iter = node->vm_files.rb_node;
while (likely(iter)) {
entry = rb_entry(iter, struct drm_vma_offset_file, vm_rb);
if (filp == entry->vm_filp)
break;
else if (filp > entry->vm_filp)
iter = iter->rb_right;
else
iter = iter->rb_left;
}
read_unlock(&node->vm_lock);
return iter;
}
