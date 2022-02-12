int amdgpu_ring_alloc(struct amdgpu_ring *ring, unsigned ndw)
{
ndw = (ndw + ring->align_mask) & ~ring->align_mask;
if (WARN_ON_ONCE(ndw > ring->max_dw))
return -ENOMEM;
ring->count_dw = ndw;
ring->wptr_old = ring->wptr;
return 0;
}
void amdgpu_ring_insert_nop(struct amdgpu_ring *ring, uint32_t count)
{
int i;
for (i = 0; i < count; i++)
amdgpu_ring_write(ring, ring->nop);
}
void amdgpu_ring_generic_pad_ib(struct amdgpu_ring *ring, struct amdgpu_ib *ib)
{
while (ib->length_dw & ring->align_mask)
ib->ptr[ib->length_dw++] = ring->nop;
}
void amdgpu_ring_commit(struct amdgpu_ring *ring)
{
uint32_t count;
count = ring->align_mask + 1 - (ring->wptr & ring->align_mask);
count %= ring->align_mask + 1;
ring->funcs->insert_nop(ring, count);
mb();
amdgpu_ring_set_wptr(ring);
}
void amdgpu_ring_undo(struct amdgpu_ring *ring)
{
ring->wptr = ring->wptr_old;
}
unsigned amdgpu_ring_backup(struct amdgpu_ring *ring,
uint32_t **data)
{
unsigned size, ptr, i;
*data = NULL;
if (ring->ring_obj == NULL)
return 0;
if (!amdgpu_fence_count_emitted(ring))
return 0;
ptr = le32_to_cpu(*ring->next_rptr_cpu_addr);
size = ring->wptr + (ring->ring_size / 4);
size -= ptr;
size &= ring->ptr_mask;
if (size == 0)
return 0;
*data = kmalloc_array(size, sizeof(uint32_t), GFP_KERNEL);
if (!*data)
return 0;
for (i = 0; i < size; ++i) {
(*data)[i] = ring->ring[ptr++];
ptr &= ring->ptr_mask;
}
return size;
}
int amdgpu_ring_restore(struct amdgpu_ring *ring,
unsigned size, uint32_t *data)
{
int i, r;
if (!size || !data)
return 0;
r = amdgpu_ring_alloc(ring, size);
if (r)
return r;
for (i = 0; i < size; ++i) {
amdgpu_ring_write(ring, data[i]);
}
amdgpu_ring_commit(ring);
kfree(data);
return 0;
}
int amdgpu_ring_init(struct amdgpu_device *adev, struct amdgpu_ring *ring,
unsigned max_dw, u32 nop, u32 align_mask,
struct amdgpu_irq_src *irq_src, unsigned irq_type,
enum amdgpu_ring_type ring_type)
{
int r;
if (ring->adev == NULL) {
if (adev->num_rings >= AMDGPU_MAX_RINGS)
return -EINVAL;
ring->adev = adev;
ring->idx = adev->num_rings++;
adev->rings[ring->idx] = ring;
r = amdgpu_fence_driver_init_ring(ring,
amdgpu_sched_hw_submission);
if (r)
return r;
}
r = amdgpu_wb_get(adev, &ring->rptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring rptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->wptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring wptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->fence_offs);
if (r) {
dev_err(adev->dev, "(%d) ring fence_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->next_rptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring next_rptr wb alloc failed\n", r);
return r;
}
ring->next_rptr_gpu_addr = adev->wb.gpu_addr + ring->next_rptr_offs * 4;
ring->next_rptr_cpu_addr = &adev->wb.wb[ring->next_rptr_offs];
r = amdgpu_wb_get(adev, &ring->cond_exe_offs);
if (r) {
dev_err(adev->dev, "(%d) ring cond_exec_polling wb alloc failed\n", r);
return r;
}
ring->cond_exe_gpu_addr = adev->wb.gpu_addr + (ring->cond_exe_offs * 4);
ring->cond_exe_cpu_addr = &adev->wb.wb[ring->cond_exe_offs];
spin_lock_init(&ring->fence_lock);
r = amdgpu_fence_driver_start_ring(ring, irq_src, irq_type);
if (r) {
dev_err(adev->dev, "failed initializing fences (%d).\n", r);
return r;
}
ring->ring_size = roundup_pow_of_two(max_dw * 4 *
amdgpu_sched_hw_submission);
ring->align_mask = align_mask;
ring->nop = nop;
ring->type = ring_type;
if (ring->ring_obj == NULL) {
r = amdgpu_bo_create(adev, ring->ring_size, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0,
NULL, NULL, &ring->ring_obj);
if (r) {
dev_err(adev->dev, "(%d) ring create failed\n", r);
return r;
}
r = amdgpu_bo_reserve(ring->ring_obj, false);
if (unlikely(r != 0))
return r;
r = amdgpu_bo_pin(ring->ring_obj, AMDGPU_GEM_DOMAIN_GTT,
&ring->gpu_addr);
if (r) {
amdgpu_bo_unreserve(ring->ring_obj);
dev_err(adev->dev, "(%d) ring pin failed\n", r);
return r;
}
r = amdgpu_bo_kmap(ring->ring_obj,
(void **)&ring->ring);
amdgpu_bo_unreserve(ring->ring_obj);
if (r) {
dev_err(adev->dev, "(%d) ring map failed\n", r);
return r;
}
}
ring->ptr_mask = (ring->ring_size / 4) - 1;
ring->max_dw = max_dw;
if (amdgpu_debugfs_ring_init(adev, ring)) {
DRM_ERROR("Failed to register debugfs file for rings !\n");
}
return 0;
}
void amdgpu_ring_fini(struct amdgpu_ring *ring)
{
int r;
struct amdgpu_bo *ring_obj;
ring_obj = ring->ring_obj;
ring->ready = false;
ring->ring = NULL;
ring->ring_obj = NULL;
amdgpu_wb_free(ring->adev, ring->cond_exe_offs);
amdgpu_wb_free(ring->adev, ring->fence_offs);
amdgpu_wb_free(ring->adev, ring->rptr_offs);
amdgpu_wb_free(ring->adev, ring->wptr_offs);
amdgpu_wb_free(ring->adev, ring->next_rptr_offs);
if (ring_obj) {
r = amdgpu_bo_reserve(ring_obj, false);
if (likely(r == 0)) {
amdgpu_bo_kunmap(ring_obj);
amdgpu_bo_unpin(ring_obj);
amdgpu_bo_unreserve(ring_obj);
}
amdgpu_bo_unref(&ring_obj);
}
}
static int amdgpu_debugfs_ring_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
int roffset = (unsigned long)node->info_ent->data;
struct amdgpu_ring *ring = (void *)(((uint8_t*)adev) + roffset);
uint32_t rptr, wptr, rptr_next;
unsigned i;
wptr = amdgpu_ring_get_wptr(ring);
seq_printf(m, "wptr: 0x%08x [%5d]\n", wptr, wptr);
rptr = amdgpu_ring_get_rptr(ring);
rptr_next = le32_to_cpu(*ring->next_rptr_cpu_addr);
seq_printf(m, "rptr: 0x%08x [%5d]\n", rptr, rptr);
seq_printf(m, "driver's copy of the wptr: 0x%08x [%5d]\n",
ring->wptr, ring->wptr);
if (!ring->ready)
return 0;
i = (rptr + ring->ptr_mask + 1 - 32) & ring->ptr_mask;
while (i != rptr) {
seq_printf(m, "r[%5d]=0x%08x", i, ring->ring[i]);
if (i == rptr)
seq_puts(m, " *");
if (i == rptr_next)
seq_puts(m, " #");
seq_puts(m, "\n");
i = (i + 1) & ring->ptr_mask;
}
while (i != wptr) {
seq_printf(m, "r[%5d]=0x%08x", i, ring->ring[i]);
if (i == rptr)
seq_puts(m, " *");
if (i == rptr_next)
seq_puts(m, " #");
seq_puts(m, "\n");
i = (i + 1) & ring->ptr_mask;
}
return 0;
}
static int amdgpu_debugfs_ring_init(struct amdgpu_device *adev,
struct amdgpu_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
unsigned offset = (uint8_t*)ring - (uint8_t*)adev;
unsigned i;
struct drm_info_list *info;
char *name;
for (i = 0; i < ARRAY_SIZE(amdgpu_debugfs_ring_info_list); ++i) {
info = &amdgpu_debugfs_ring_info_list[i];
if (!info->data)
break;
}
if (i == ARRAY_SIZE(amdgpu_debugfs_ring_info_list))
return -ENOSPC;
name = &amdgpu_debugfs_ring_names[i][0];
sprintf(name, "amdgpu_ring_%s", ring->name);
info->name = name;
info->show = amdgpu_debugfs_ring_info;
info->driver_features = 0;
info->data = (void*)(uintptr_t)offset;
return amdgpu_debugfs_add_files(adev, info, 1);
#endif
return 0;
}
