int amdgpu_ib_get(struct amdgpu_device *adev, struct amdgpu_vm *vm,
unsigned size, struct amdgpu_ib *ib)
{
int r;
if (size) {
r = amdgpu_sa_bo_new(&adev->ring_tmp_bo,
&ib->sa_bo, size, 256);
if (r) {
dev_err(adev->dev, "failed to get a new IB (%d)\n", r);
return r;
}
ib->ptr = amdgpu_sa_bo_cpu_addr(ib->sa_bo);
if (!vm)
ib->gpu_addr = amdgpu_sa_bo_gpu_addr(ib->sa_bo);
}
return 0;
}
void amdgpu_ib_free(struct amdgpu_device *adev, struct amdgpu_ib *ib,
struct dma_fence *f)
{
amdgpu_sa_bo_free(adev, &ib->sa_bo, f);
}
int amdgpu_ib_schedule(struct amdgpu_ring *ring, unsigned num_ibs,
struct amdgpu_ib *ibs, struct amdgpu_job *job,
struct dma_fence **f)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib *ib = &ibs[0];
struct dma_fence *tmp = NULL;
bool skip_preamble, need_ctx_switch;
unsigned patch_offset = ~0;
struct amdgpu_vm *vm;
uint64_t fence_ctx;
uint32_t status = 0, alloc_size;
unsigned i;
int r = 0;
if (num_ibs == 0)
return -EINVAL;
if (job) {
vm = job->vm;
fence_ctx = job->fence_ctx;
} else {
vm = NULL;
fence_ctx = 0;
}
if (!ring->ready) {
dev_err(adev->dev, "couldn't schedule ib on ring <%s>\n", ring->name);
return -EINVAL;
}
if (vm && !job->vm_id) {
dev_err(adev->dev, "VM IB without ID\n");
return -EINVAL;
}
alloc_size = ring->funcs->emit_frame_size + num_ibs *
ring->funcs->emit_ib_size;
r = amdgpu_ring_alloc(ring, alloc_size);
if (r) {
dev_err(adev->dev, "scheduling IB failed (%d).\n", r);
return r;
}
if (ring->funcs->emit_pipeline_sync && job &&
((tmp = amdgpu_sync_get_fence(&job->sched_sync)) ||
amdgpu_vm_need_pipeline_sync(ring, job))) {
amdgpu_ring_emit_pipeline_sync(ring);
dma_fence_put(tmp);
}
if (ring->funcs->insert_start)
ring->funcs->insert_start(ring);
if (vm) {
r = amdgpu_vm_flush(ring, job);
if (r) {
amdgpu_ring_undo(ring);
return r;
}
}
if (ring->funcs->init_cond_exec)
patch_offset = amdgpu_ring_init_cond_exec(ring);
if (ring->funcs->emit_hdp_flush
#ifdef CONFIG_X86_64
&& !(adev->flags & AMD_IS_APU)
#endif
)
amdgpu_ring_emit_hdp_flush(ring);
skip_preamble = ring->current_ctx == fence_ctx;
need_ctx_switch = ring->current_ctx != fence_ctx;
if (job && ring->funcs->emit_cntxcntl) {
if (need_ctx_switch)
status |= AMDGPU_HAVE_CTX_SWITCH;
status |= job->preamble_status;
amdgpu_ring_emit_cntxcntl(ring, status);
}
for (i = 0; i < num_ibs; ++i) {
ib = &ibs[i];
if ((ib->flags & AMDGPU_IB_FLAG_PREAMBLE) &&
skip_preamble &&
!(status & AMDGPU_PREAMBLE_IB_PRESENT_FIRST) &&
!amdgpu_sriov_vf(adev))
continue;
amdgpu_ring_emit_ib(ring, ib, job ? job->vm_id : 0,
need_ctx_switch);
need_ctx_switch = false;
}
if (ring->funcs->emit_tmz)
amdgpu_ring_emit_tmz(ring, false);
if (ring->funcs->emit_hdp_invalidate
#ifdef CONFIG_X86_64
&& !(adev->flags & AMD_IS_APU)
#endif
)
amdgpu_ring_emit_hdp_invalidate(ring);
r = amdgpu_fence_emit(ring, f);
if (r) {
dev_err(adev->dev, "failed to emit fence (%d)\n", r);
if (job && job->vm_id)
amdgpu_vm_reset_id(adev, ring->funcs->vmhub,
job->vm_id);
amdgpu_ring_undo(ring);
return r;
}
if (ring->funcs->insert_end)
ring->funcs->insert_end(ring);
if (job && job->uf_addr) {
amdgpu_ring_emit_fence(ring, job->uf_addr, job->uf_sequence,
AMDGPU_FENCE_FLAG_64BIT);
}
if (patch_offset != ~0 && ring->funcs->patch_cond_exec)
amdgpu_ring_patch_cond_exec(ring, patch_offset);
ring->current_ctx = fence_ctx;
if (vm && ring->funcs->emit_switch_buffer)
amdgpu_ring_emit_switch_buffer(ring);
amdgpu_ring_commit(ring);
return 0;
}
int amdgpu_ib_pool_init(struct amdgpu_device *adev)
{
int r;
if (adev->ib_pool_ready) {
return 0;
}
r = amdgpu_sa_bo_manager_init(adev, &adev->ring_tmp_bo,
AMDGPU_IB_POOL_SIZE*64*1024,
AMDGPU_GPU_PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT);
if (r) {
return r;
}
r = amdgpu_sa_bo_manager_start(adev, &adev->ring_tmp_bo);
if (r) {
return r;
}
adev->ib_pool_ready = true;
if (amdgpu_debugfs_sa_init(adev)) {
dev_err(adev->dev, "failed to register debugfs file for SA\n");
}
return 0;
}
void amdgpu_ib_pool_fini(struct amdgpu_device *adev)
{
if (adev->ib_pool_ready) {
amdgpu_sa_bo_manager_suspend(adev, &adev->ring_tmp_bo);
amdgpu_sa_bo_manager_fini(adev, &adev->ring_tmp_bo);
adev->ib_pool_ready = false;
}
}
int amdgpu_ib_ring_tests(struct amdgpu_device *adev)
{
unsigned i;
int r, ret = 0;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->ready)
continue;
r = amdgpu_ring_test_ib(ring, AMDGPU_IB_TEST_TIMEOUT);
if (r) {
ring->ready = false;
if (ring == &adev->gfx.gfx_ring[0]) {
DRM_ERROR("amdgpu: failed testing IB on GFX ring (%d).\n", r);
adev->accel_working = false;
return r;
} else {
DRM_ERROR("amdgpu: failed testing IB on ring %d (%d).\n", i, r);
ret = r;
}
}
}
return ret;
}
static int amdgpu_debugfs_sa_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
amdgpu_sa_bo_dump_debug_info(&adev->ring_tmp_bo, m);
return 0;
}
static int amdgpu_debugfs_sa_init(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
return amdgpu_debugfs_add_files(adev, amdgpu_debugfs_sa_list, 1);
#else
return 0;
#endif
}
