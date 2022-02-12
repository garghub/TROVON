void drm_vma_offset_manager_init(struct drm_vma_offset_manager *mgr,
unsigned long page_offset, unsigned long size)
{
rwlock_init(&mgr->vm_lock);
drm_mm_init(&mgr->vm_addr_space_mm, page_offset, size);
}
void drm_vma_offset_manager_destroy(struct drm_vma_offset_manager *mgr)
{
write_lock(&mgr->vm_lock);
drm_mm_takedown(&mgr->vm_addr_space_mm);
write_unlock(&mgr->vm_lock);
}
struct drm_vma_offset_node *drm_vma_offset_lookup_locked(struct drm_vma_offset_manager *mgr,
unsigned long start,
unsigned long pages)
{
struct drm_mm_node *node, *best;
struct rb_node *iter;
unsigned long offset;
iter = mgr->vm_addr_space_mm.interval_tree.rb_node;
best = NULL;
while (likely(iter)) {
node = rb_entry(iter, struct drm_mm_node, rb);
offset = node->start;
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
offset = best->start + best->size;
if (offset < start + pages)
best = NULL;
}
if (!best)
return NULL;
return container_of(best, struct drm_vma_offset_node, vm_node);
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
ret = drm_mm_insert_node(&mgr->vm_addr_space_mm, &node->vm_node, pages);
if (ret)
goto out_unlock;
out_unlock:
write_unlock(&mgr->vm_lock);
return ret;
}
void drm_vma_offset_remove(struct drm_vma_offset_manager *mgr,
struct drm_vma_offset_node *node)
{
write_lock(&mgr->vm_lock);
if (drm_mm_node_allocated(&node->vm_node)) {
drm_mm_remove_node(&node->vm_node);
memset(&node->vm_node, 0, sizeof(node->vm_node));
}
write_unlock(&mgr->vm_lock);
}
int drm_vma_node_allow(struct drm_vma_offset_node *node, struct drm_file *tag)
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
if (tag == entry->vm_tag) {
entry->vm_count++;
goto unlock;
} else if (tag > entry->vm_tag) {
iter = &(*iter)->rb_right;
} else {
iter = &(*iter)->rb_left;
}
}
if (!new) {
ret = -ENOMEM;
goto unlock;
}
new->vm_tag = tag;
new->vm_count = 1;
rb_link_node(&new->vm_rb, parent, iter);
rb_insert_color(&new->vm_rb, &node->vm_files);
new = NULL;
unlock:
write_unlock(&node->vm_lock);
kfree(new);
return ret;
}
void drm_vma_node_revoke(struct drm_vma_offset_node *node,
struct drm_file *tag)
{
struct drm_vma_offset_file *entry;
struct rb_node *iter;
write_lock(&node->vm_lock);
iter = node->vm_files.rb_node;
while (likely(iter)) {
entry = rb_entry(iter, struct drm_vma_offset_file, vm_rb);
if (tag == entry->vm_tag) {
if (!--entry->vm_count) {
rb_erase(&entry->vm_rb, &node->vm_files);
kfree(entry);
}
break;
} else if (tag > entry->vm_tag) {
iter = iter->rb_right;
} else {
iter = iter->rb_left;
}
}
write_unlock(&node->vm_lock);
}
bool drm_vma_node_is_allowed(struct drm_vma_offset_node *node,
struct drm_file *tag)
{
struct drm_vma_offset_file *entry;
struct rb_node *iter;
read_lock(&node->vm_lock);
iter = node->vm_files.rb_node;
while (likely(iter)) {
entry = rb_entry(iter, struct drm_vma_offset_file, vm_rb);
if (tag == entry->vm_tag)
break;
else if (tag > entry->vm_tag)
iter = iter->rb_right;
else
iter = iter->rb_left;
}
read_unlock(&node->vm_lock);
return iter;
}
