int amdgpu_ring_alloc(struct amdgpu_ring *ring, unsigned ndw)
{
ndw = (ndw + ring->funcs->align_mask) & ~ring->funcs->align_mask;
if (WARN_ON_ONCE(ndw > ring->max_dw))
return -ENOMEM;
ring->count_dw = ndw;
ring->wptr_old = ring->wptr;
if (ring->funcs->begin_use)
ring->funcs->begin_use(ring);
return 0;
}
void amdgpu_ring_insert_nop(struct amdgpu_ring *ring, uint32_t count)
{
int i;
for (i = 0; i < count; i++)
amdgpu_ring_write(ring, ring->funcs->nop);
}
void amdgpu_ring_generic_pad_ib(struct amdgpu_ring *ring, struct amdgpu_ib *ib)
{
while (ib->length_dw & ring->funcs->align_mask)
ib->ptr[ib->length_dw++] = ring->funcs->nop;
}
void amdgpu_ring_commit(struct amdgpu_ring *ring)
{
uint32_t count;
count = ring->funcs->align_mask + 1 -
(ring->wptr & ring->funcs->align_mask);
count %= ring->funcs->align_mask + 1;
ring->funcs->insert_nop(ring, count);
mb();
amdgpu_ring_set_wptr(ring);
if (ring->funcs->end_use)
ring->funcs->end_use(ring);
amdgpu_ring_lru_touch(ring->adev, ring);
}
void amdgpu_ring_undo(struct amdgpu_ring *ring)
{
ring->wptr = ring->wptr_old;
if (ring->funcs->end_use)
ring->funcs->end_use(ring);
}
int amdgpu_ring_init(struct amdgpu_device *adev, struct amdgpu_ring *ring,
unsigned max_dw, struct amdgpu_irq_src *irq_src,
unsigned irq_type)
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
if (ring->funcs->support_64bit_ptrs) {
r = amdgpu_wb_get_64bit(adev, &ring->rptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring rptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get_64bit(adev, &ring->wptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring wptr_offs wb alloc failed\n", r);
return r;
}
} else {
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
}
r = amdgpu_wb_get(adev, &ring->fence_offs);
if (r) {
dev_err(adev->dev, "(%d) ring fence_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->cond_exe_offs);
if (r) {
dev_err(adev->dev, "(%d) ring cond_exec_polling wb alloc failed\n", r);
return r;
}
ring->cond_exe_gpu_addr = adev->wb.gpu_addr + (ring->cond_exe_offs * 4);
ring->cond_exe_cpu_addr = &adev->wb.wb[ring->cond_exe_offs];
*ring->cond_exe_cpu_addr = 1;
r = amdgpu_fence_driver_start_ring(ring, irq_src, irq_type);
if (r) {
dev_err(adev->dev, "failed initializing fences (%d).\n", r);
return r;
}
ring->ring_size = roundup_pow_of_two(max_dw * 4 *
amdgpu_sched_hw_submission);
ring->buf_mask = (ring->ring_size / 4) - 1;
ring->ptr_mask = ring->funcs->support_64bit_ptrs ?
0xffffffffffffffff : ring->buf_mask;
if (ring->ring_obj == NULL) {
r = amdgpu_bo_create_kernel(adev, ring->ring_size, PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT,
&ring->ring_obj,
&ring->gpu_addr,
(void **)&ring->ring);
if (r) {
dev_err(adev->dev, "(%d) ring create failed\n", r);
return r;
}
amdgpu_ring_clear_ring(ring);
}
ring->max_dw = max_dw;
INIT_LIST_HEAD(&ring->lru_list);
amdgpu_ring_lru_touch(adev, ring);
if (amdgpu_debugfs_ring_init(adev, ring)) {
DRM_ERROR("Failed to register debugfs file for rings !\n");
}
return 0;
}
void amdgpu_ring_fini(struct amdgpu_ring *ring)
{
ring->ready = false;
if (ring->funcs->support_64bit_ptrs) {
amdgpu_wb_free_64bit(ring->adev, ring->cond_exe_offs);
amdgpu_wb_free_64bit(ring->adev, ring->fence_offs);
amdgpu_wb_free_64bit(ring->adev, ring->rptr_offs);
amdgpu_wb_free_64bit(ring->adev, ring->wptr_offs);
} else {
amdgpu_wb_free(ring->adev, ring->cond_exe_offs);
amdgpu_wb_free(ring->adev, ring->fence_offs);
amdgpu_wb_free(ring->adev, ring->rptr_offs);
amdgpu_wb_free(ring->adev, ring->wptr_offs);
}
amdgpu_bo_free_kernel(&ring->ring_obj,
&ring->gpu_addr,
(void **)&ring->ring);
amdgpu_debugfs_ring_fini(ring);
ring->adev->rings[ring->idx] = NULL;
}
static void amdgpu_ring_lru_touch_locked(struct amdgpu_device *adev,
struct amdgpu_ring *ring)
{
list_move_tail(&ring->lru_list, &adev->ring_lru_list);
}
static bool amdgpu_ring_is_blacklisted(struct amdgpu_ring *ring,
int *blacklist, int num_blacklist)
{
int i;
for (i = 0; i < num_blacklist; i++) {
if (ring->idx == blacklist[i])
return true;
}
return false;
}
int amdgpu_ring_lru_get(struct amdgpu_device *adev, int type, int *blacklist,
int num_blacklist, struct amdgpu_ring **ring)
{
struct amdgpu_ring *entry;
*ring = NULL;
spin_lock(&adev->ring_lru_list_lock);
list_for_each_entry(entry, &adev->ring_lru_list, lru_list) {
if (entry->funcs->type != type)
continue;
if (amdgpu_ring_is_blacklisted(entry, blacklist, num_blacklist))
continue;
*ring = entry;
amdgpu_ring_lru_touch_locked(adev, *ring);
break;
}
spin_unlock(&adev->ring_lru_list_lock);
if (!*ring) {
DRM_ERROR("Ring LRU contains no entries for ring type:%d\n", type);
return -EINVAL;
}
return 0;
}
void amdgpu_ring_lru_touch(struct amdgpu_device *adev, struct amdgpu_ring *ring)
{
spin_lock(&adev->ring_lru_list_lock);
amdgpu_ring_lru_touch_locked(adev, ring);
spin_unlock(&adev->ring_lru_list_lock);
}
static ssize_t amdgpu_debugfs_ring_read(struct file *f, char __user *buf,
size_t size, loff_t *pos)
{
struct amdgpu_ring *ring = file_inode(f)->i_private;
int r, i;
uint32_t value, result, early[3];
if (*pos & 3 || size & 3)
return -EINVAL;
result = 0;
if (*pos < 12) {
early[0] = amdgpu_ring_get_rptr(ring);
early[1] = amdgpu_ring_get_wptr(ring) & ring->buf_mask;
early[2] = ring->wptr & ring->buf_mask;
for (i = *pos / 4; i < 3 && size; i++) {
r = put_user(early[i], (uint32_t *)buf);
if (r)
return r;
buf += 4;
result += 4;
size -= 4;
*pos += 4;
}
}
while (size) {
if (*pos >= (ring->ring_size + 12))
return result;
value = ring->ring[(*pos - 12)/4];
r = put_user(value, (uint32_t*)buf);
if (r)
return r;
buf += 4;
result += 4;
size -= 4;
*pos += 4;
}
return result;
}
static int amdgpu_debugfs_ring_init(struct amdgpu_device *adev,
struct amdgpu_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
struct drm_minor *minor = adev->ddev->primary;
struct dentry *ent, *root = minor->debugfs_root;
char name[32];
sprintf(name, "amdgpu_ring_%s", ring->name);
ent = debugfs_create_file(name,
S_IFREG | S_IRUGO, root,
ring, &amdgpu_debugfs_ring_fops);
if (!ent)
return -ENOMEM;
i_size_write(ent->d_inode, ring->ring_size + 12);
ring->ent = ent;
#endif
return 0;
}
static void amdgpu_debugfs_ring_fini(struct amdgpu_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
debugfs_remove(ring->ent);
#endif
}
