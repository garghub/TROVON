u32 radeon_get_ib_value(struct radeon_cs_parser *p, int idx)
{
struct radeon_cs_chunk *ibc = &p->chunks[p->chunk_ib_idx];
u32 pg_idx, pg_offset;
u32 idx_value = 0;
int new_page;
pg_idx = (idx * 4) / PAGE_SIZE;
pg_offset = (idx * 4) % PAGE_SIZE;
if (ibc->kpage_idx[0] == pg_idx)
return ibc->kpage[0][pg_offset/4];
if (ibc->kpage_idx[1] == pg_idx)
return ibc->kpage[1][pg_offset/4];
new_page = radeon_cs_update_pages(p, pg_idx);
if (new_page < 0) {
p->parser_error = new_page;
return 0;
}
idx_value = ibc->kpage[new_page][pg_offset/4];
return idx_value;
}
void radeon_ring_write(struct radeon_device *rdev, uint32_t v)
{
#if DRM_DEBUG_CODE
if (rdev->cp.count_dw <= 0) {
DRM_ERROR("radeon: writting more dword to ring than expected !\n");
}
#endif
rdev->cp.ring[rdev->cp.wptr++] = v;
rdev->cp.wptr &= rdev->cp.ptr_mask;
rdev->cp.count_dw--;
rdev->cp.ring_free_dw--;
}
void radeon_ib_bogus_cleanup(struct radeon_device *rdev)
{
struct radeon_ib *ib, *n;
list_for_each_entry_safe(ib, n, &rdev->ib_pool.bogus_ib, list) {
list_del(&ib->list);
vfree(ib->ptr);
kfree(ib);
}
}
void radeon_ib_bogus_add(struct radeon_device *rdev, struct radeon_ib *ib)
{
struct radeon_ib *bib;
bib = kmalloc(sizeof(*bib), GFP_KERNEL);
if (bib == NULL)
return;
bib->ptr = vmalloc(ib->length_dw * 4);
if (bib->ptr == NULL) {
kfree(bib);
return;
}
memcpy(bib->ptr, ib->ptr, ib->length_dw * 4);
bib->length_dw = ib->length_dw;
mutex_lock(&rdev->ib_pool.mutex);
list_add_tail(&bib->list, &rdev->ib_pool.bogus_ib);
mutex_unlock(&rdev->ib_pool.mutex);
}
int radeon_ib_get(struct radeon_device *rdev, struct radeon_ib **ib)
{
struct radeon_fence *fence;
struct radeon_ib *nib;
int r = 0, i, c;
*ib = NULL;
r = radeon_fence_create(rdev, &fence);
if (r) {
dev_err(rdev->dev, "failed to create fence for new IB\n");
return r;
}
mutex_lock(&rdev->ib_pool.mutex);
for (i = rdev->ib_pool.head_id, c = 0, nib = NULL; c < RADEON_IB_POOL_SIZE; c++, i++) {
i &= (RADEON_IB_POOL_SIZE - 1);
if (rdev->ib_pool.ibs[i].free) {
nib = &rdev->ib_pool.ibs[i];
break;
}
}
if (nib == NULL) {
dev_err(rdev->dev, "no free indirect buffer !\n");
mutex_unlock(&rdev->ib_pool.mutex);
radeon_fence_unref(&fence);
return -EBUSY;
}
rdev->ib_pool.head_id = (nib->idx + 1) & (RADEON_IB_POOL_SIZE - 1);
nib->free = false;
if (nib->fence) {
mutex_unlock(&rdev->ib_pool.mutex);
r = radeon_fence_wait(nib->fence, false);
if (r) {
dev_err(rdev->dev, "error waiting fence of IB(%u:0x%016lX:%u)\n",
nib->idx, (unsigned long)nib->gpu_addr, nib->length_dw);
mutex_lock(&rdev->ib_pool.mutex);
nib->free = true;
mutex_unlock(&rdev->ib_pool.mutex);
radeon_fence_unref(&fence);
return r;
}
mutex_lock(&rdev->ib_pool.mutex);
}
radeon_fence_unref(&nib->fence);
nib->fence = fence;
nib->length_dw = 0;
mutex_unlock(&rdev->ib_pool.mutex);
*ib = nib;
return 0;
}
void radeon_ib_free(struct radeon_device *rdev, struct radeon_ib **ib)
{
struct radeon_ib *tmp = *ib;
*ib = NULL;
if (tmp == NULL) {
return;
}
if (!tmp->fence->emited)
radeon_fence_unref(&tmp->fence);
mutex_lock(&rdev->ib_pool.mutex);
tmp->free = true;
mutex_unlock(&rdev->ib_pool.mutex);
}
int radeon_ib_schedule(struct radeon_device *rdev, struct radeon_ib *ib)
{
int r = 0;
if (!ib->length_dw || !rdev->cp.ready) {
DRM_ERROR("radeon: couldn't schedule IB(%u).\n", ib->idx);
return -EINVAL;
}
r = radeon_ring_lock(rdev, 64);
if (r) {
DRM_ERROR("radeon: scheduling IB failed (%d).\n", r);
return r;
}
radeon_ring_ib_execute(rdev, ib);
radeon_fence_emit(rdev, ib->fence);
mutex_lock(&rdev->ib_pool.mutex);
ib->free = true;
mutex_unlock(&rdev->ib_pool.mutex);
radeon_ring_unlock_commit(rdev);
return 0;
}
int radeon_ib_pool_init(struct radeon_device *rdev)
{
void *ptr;
uint64_t gpu_addr;
int i;
int r = 0;
if (rdev->ib_pool.robj)
return 0;
INIT_LIST_HEAD(&rdev->ib_pool.bogus_ib);
r = radeon_bo_create(rdev, RADEON_IB_POOL_SIZE*64*1024,
PAGE_SIZE, true, RADEON_GEM_DOMAIN_GTT,
&rdev->ib_pool.robj);
if (r) {
DRM_ERROR("radeon: failed to ib pool (%d).\n", r);
return r;
}
r = radeon_bo_reserve(rdev->ib_pool.robj, false);
if (unlikely(r != 0))
return r;
r = radeon_bo_pin(rdev->ib_pool.robj, RADEON_GEM_DOMAIN_GTT, &gpu_addr);
if (r) {
radeon_bo_unreserve(rdev->ib_pool.robj);
DRM_ERROR("radeon: failed to pin ib pool (%d).\n", r);
return r;
}
r = radeon_bo_kmap(rdev->ib_pool.robj, &ptr);
radeon_bo_unreserve(rdev->ib_pool.robj);
if (r) {
DRM_ERROR("radeon: failed to map ib pool (%d).\n", r);
return r;
}
for (i = 0; i < RADEON_IB_POOL_SIZE; i++) {
unsigned offset;
offset = i * 64 * 1024;
rdev->ib_pool.ibs[i].gpu_addr = gpu_addr + offset;
rdev->ib_pool.ibs[i].ptr = ptr + offset;
rdev->ib_pool.ibs[i].idx = i;
rdev->ib_pool.ibs[i].length_dw = 0;
rdev->ib_pool.ibs[i].free = true;
}
rdev->ib_pool.head_id = 0;
rdev->ib_pool.ready = true;
DRM_INFO("radeon: ib pool ready.\n");
if (radeon_debugfs_ib_init(rdev)) {
DRM_ERROR("Failed to register debugfs file for IB !\n");
}
return r;
}
void radeon_ib_pool_fini(struct radeon_device *rdev)
{
int r;
struct radeon_bo *robj;
if (!rdev->ib_pool.ready) {
return;
}
mutex_lock(&rdev->ib_pool.mutex);
radeon_ib_bogus_cleanup(rdev);
robj = rdev->ib_pool.robj;
rdev->ib_pool.robj = NULL;
mutex_unlock(&rdev->ib_pool.mutex);
if (robj) {
r = radeon_bo_reserve(robj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(robj);
radeon_bo_unpin(robj);
radeon_bo_unreserve(robj);
}
radeon_bo_unref(&robj);
}
}
void radeon_ring_free_size(struct radeon_device *rdev)
{
if (rdev->wb.enabled)
rdev->cp.rptr = le32_to_cpu(rdev->wb.wb[RADEON_WB_CP_RPTR_OFFSET/4]);
else {
if (rdev->family >= CHIP_R600)
rdev->cp.rptr = RREG32(R600_CP_RB_RPTR);
else
rdev->cp.rptr = RREG32(RADEON_CP_RB_RPTR);
}
rdev->cp.ring_free_dw = (rdev->cp.rptr + (rdev->cp.ring_size / 4));
rdev->cp.ring_free_dw -= rdev->cp.wptr;
rdev->cp.ring_free_dw &= rdev->cp.ptr_mask;
if (!rdev->cp.ring_free_dw) {
rdev->cp.ring_free_dw = rdev->cp.ring_size / 4;
}
}
int radeon_ring_alloc(struct radeon_device *rdev, unsigned ndw)
{
int r;
ndw = (ndw + rdev->cp.align_mask) & ~rdev->cp.align_mask;
while (ndw > (rdev->cp.ring_free_dw - 1)) {
radeon_ring_free_size(rdev);
if (ndw < rdev->cp.ring_free_dw) {
break;
}
r = radeon_fence_wait_next(rdev);
if (r)
return r;
}
rdev->cp.count_dw = ndw;
rdev->cp.wptr_old = rdev->cp.wptr;
return 0;
}
int radeon_ring_lock(struct radeon_device *rdev, unsigned ndw)
{
int r;
mutex_lock(&rdev->cp.mutex);
r = radeon_ring_alloc(rdev, ndw);
if (r) {
mutex_unlock(&rdev->cp.mutex);
return r;
}
return 0;
}
void radeon_ring_commit(struct radeon_device *rdev)
{
unsigned count_dw_pad;
unsigned i;
count_dw_pad = (rdev->cp.align_mask + 1) -
(rdev->cp.wptr & rdev->cp.align_mask);
for (i = 0; i < count_dw_pad; i++) {
radeon_ring_write(rdev, 2 << 30);
}
DRM_MEMORYBARRIER();
radeon_cp_commit(rdev);
}
void radeon_ring_unlock_commit(struct radeon_device *rdev)
{
radeon_ring_commit(rdev);
mutex_unlock(&rdev->cp.mutex);
}
void radeon_ring_unlock_undo(struct radeon_device *rdev)
{
rdev->cp.wptr = rdev->cp.wptr_old;
mutex_unlock(&rdev->cp.mutex);
}
int radeon_ring_init(struct radeon_device *rdev, unsigned ring_size)
{
int r;
rdev->cp.ring_size = ring_size;
if (rdev->cp.ring_obj == NULL) {
r = radeon_bo_create(rdev, rdev->cp.ring_size, PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT,
&rdev->cp.ring_obj);
if (r) {
dev_err(rdev->dev, "(%d) ring create failed\n", r);
return r;
}
r = radeon_bo_reserve(rdev->cp.ring_obj, false);
if (unlikely(r != 0))
return r;
r = radeon_bo_pin(rdev->cp.ring_obj, RADEON_GEM_DOMAIN_GTT,
&rdev->cp.gpu_addr);
if (r) {
radeon_bo_unreserve(rdev->cp.ring_obj);
dev_err(rdev->dev, "(%d) ring pin failed\n", r);
return r;
}
r = radeon_bo_kmap(rdev->cp.ring_obj,
(void **)&rdev->cp.ring);
radeon_bo_unreserve(rdev->cp.ring_obj);
if (r) {
dev_err(rdev->dev, "(%d) ring map failed\n", r);
return r;
}
}
rdev->cp.ptr_mask = (rdev->cp.ring_size / 4) - 1;
rdev->cp.ring_free_dw = rdev->cp.ring_size / 4;
return 0;
}
void radeon_ring_fini(struct radeon_device *rdev)
{
int r;
struct radeon_bo *ring_obj;
mutex_lock(&rdev->cp.mutex);
ring_obj = rdev->cp.ring_obj;
rdev->cp.ring = NULL;
rdev->cp.ring_obj = NULL;
mutex_unlock(&rdev->cp.mutex);
if (ring_obj) {
r = radeon_bo_reserve(ring_obj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(ring_obj);
radeon_bo_unpin(ring_obj);
radeon_bo_unreserve(ring_obj);
}
radeon_bo_unref(&ring_obj);
}
}
static int radeon_debugfs_ib_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct radeon_ib *ib = node->info_ent->data;
unsigned i;
if (ib == NULL) {
return 0;
}
seq_printf(m, "IB %04u\n", ib->idx);
seq_printf(m, "IB fence %p\n", ib->fence);
seq_printf(m, "IB size %05u dwords\n", ib->length_dw);
for (i = 0; i < ib->length_dw; i++) {
seq_printf(m, "[%05u]=0x%08X\n", i, ib->ptr[i]);
}
return 0;
}
static int radeon_debugfs_ib_bogus_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct radeon_device *rdev = node->info_ent->data;
struct radeon_ib *ib;
unsigned i;
mutex_lock(&rdev->ib_pool.mutex);
if (list_empty(&rdev->ib_pool.bogus_ib)) {
mutex_unlock(&rdev->ib_pool.mutex);
seq_printf(m, "no bogus IB recorded\n");
return 0;
}
ib = list_first_entry(&rdev->ib_pool.bogus_ib, struct radeon_ib, list);
list_del_init(&ib->list);
mutex_unlock(&rdev->ib_pool.mutex);
seq_printf(m, "IB size %05u dwords\n", ib->length_dw);
for (i = 0; i < ib->length_dw; i++) {
seq_printf(m, "[%05u]=0x%08X\n", i, ib->ptr[i]);
}
vfree(ib->ptr);
kfree(ib);
return 0;
}
int radeon_debugfs_ib_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
unsigned i;
int r;
radeon_debugfs_ib_bogus_info_list[0].data = rdev;
r = radeon_debugfs_add_files(rdev, radeon_debugfs_ib_bogus_info_list, 1);
if (r)
return r;
for (i = 0; i < RADEON_IB_POOL_SIZE; i++) {
sprintf(radeon_debugfs_ib_names[i], "radeon_ib_%04u", i);
radeon_debugfs_ib_list[i].name = radeon_debugfs_ib_names[i];
radeon_debugfs_ib_list[i].show = &radeon_debugfs_ib_info;
radeon_debugfs_ib_list[i].driver_features = 0;
radeon_debugfs_ib_list[i].data = &rdev->ib_pool.ibs[i];
}
return radeon_debugfs_add_files(rdev, radeon_debugfs_ib_list,
RADEON_IB_POOL_SIZE);
#else
return 0;
#endif
}
