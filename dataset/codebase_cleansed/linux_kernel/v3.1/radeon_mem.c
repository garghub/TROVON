static struct mem_block *split_block(struct mem_block *p, int start, int size,
struct drm_file *file_priv)
{
if (start > p->start) {
struct mem_block *newblock = kmalloc(sizeof(*newblock),
GFP_KERNEL);
if (!newblock)
goto out;
newblock->start = start;
newblock->size = p->size - (start - p->start);
newblock->file_priv = NULL;
newblock->next = p->next;
newblock->prev = p;
p->next->prev = newblock;
p->next = newblock;
p->size -= newblock->size;
p = newblock;
}
if (size < p->size) {
struct mem_block *newblock = kmalloc(sizeof(*newblock),
GFP_KERNEL);
if (!newblock)
goto out;
newblock->start = start + size;
newblock->size = p->size - size;
newblock->file_priv = NULL;
newblock->next = p->next;
newblock->prev = p;
p->next->prev = newblock;
p->next = newblock;
p->size = size;
}
out:
p->file_priv = file_priv;
return p;
}
static struct mem_block *alloc_block(struct mem_block *heap, int size,
int align2, struct drm_file *file_priv)
{
struct mem_block *p;
int mask = (1 << align2) - 1;
list_for_each(p, heap) {
int start = (p->start + mask) & ~mask;
if (p->file_priv == NULL && start + size <= p->start + p->size)
return split_block(p, start, size, file_priv);
}
return NULL;
}
static struct mem_block *find_block(struct mem_block *heap, int start)
{
struct mem_block *p;
list_for_each(p, heap)
if (p->start == start)
return p;
return NULL;
}
static void free_block(struct mem_block *p)
{
p->file_priv = NULL;
if (p->next->file_priv == NULL) {
struct mem_block *q = p->next;
p->size += q->size;
p->next = q->next;
p->next->prev = p;
kfree(q);
}
if (p->prev->file_priv == NULL) {
struct mem_block *q = p->prev;
q->size += p->size;
q->next = p->next;
q->next->prev = q;
kfree(p);
}
}
static int init_heap(struct mem_block **heap, int start, int size)
{
struct mem_block *blocks = kmalloc(sizeof(*blocks), GFP_KERNEL);
if (!blocks)
return -ENOMEM;
*heap = kzalloc(sizeof(**heap), GFP_KERNEL);
if (!*heap) {
kfree(blocks);
return -ENOMEM;
}
blocks->start = start;
blocks->size = size;
blocks->file_priv = NULL;
blocks->next = blocks->prev = *heap;
(*heap)->file_priv = (struct drm_file *) - 1;
(*heap)->next = (*heap)->prev = blocks;
return 0;
}
void radeon_mem_release(struct drm_file *file_priv, struct mem_block *heap)
{
struct mem_block *p;
if (!heap || !heap->next)
return;
list_for_each(p, heap) {
if (p->file_priv == file_priv)
p->file_priv = NULL;
}
list_for_each(p, heap) {
while (p->file_priv == NULL && p->next->file_priv == NULL) {
struct mem_block *q = p->next;
p->size += q->size;
p->next = q->next;
p->next->prev = p;
kfree(q);
}
}
}
void radeon_mem_takedown(struct mem_block **heap)
{
struct mem_block *p;
if (!*heap)
return;
for (p = (*heap)->next; p != *heap;) {
struct mem_block *q = p;
p = p->next;
kfree(q);
}
kfree(*heap);
*heap = NULL;
}
static struct mem_block **get_heap(drm_radeon_private_t * dev_priv, int region)
{
switch (region) {
case RADEON_MEM_REGION_GART:
return &dev_priv->gart_heap;
case RADEON_MEM_REGION_FB:
return &dev_priv->fb_heap;
default:
return NULL;
}
}
int radeon_mem_alloc(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_mem_alloc_t *alloc = data;
struct mem_block *block, **heap;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
heap = get_heap(dev_priv, alloc->region);
if (!heap || !*heap)
return -EFAULT;
if (alloc->alignment < 12)
alloc->alignment = 12;
block = alloc_block(*heap, alloc->size, alloc->alignment, file_priv);
if (!block)
return -ENOMEM;
if (DRM_COPY_TO_USER(alloc->region_offset, &block->start,
sizeof(int))) {
DRM_ERROR("copy_to_user\n");
return -EFAULT;
}
return 0;
}
int radeon_mem_free(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_mem_free_t *memfree = data;
struct mem_block *block, **heap;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
heap = get_heap(dev_priv, memfree->region);
if (!heap || !*heap)
return -EFAULT;
block = find_block(*heap, memfree->region_offset);
if (!block)
return -EFAULT;
if (block->file_priv != file_priv)
return -EPERM;
free_block(block);
return 0;
}
int radeon_mem_init_heap(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
drm_radeon_mem_init_heap_t *initheap = data;
struct mem_block **heap;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
heap = get_heap(dev_priv, initheap->region);
if (!heap)
return -EFAULT;
if (*heap) {
DRM_ERROR("heap already initialized?");
return -EFAULT;
}
return init_heap(heap, initheap->start, initheap->size);
}
