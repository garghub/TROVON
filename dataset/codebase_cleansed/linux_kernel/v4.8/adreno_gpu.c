int adreno_get_param(struct msm_gpu *gpu, uint32_t param, uint64_t *value)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
switch (param) {
case MSM_PARAM_GPU_ID:
*value = adreno_gpu->info->revn;
return 0;
case MSM_PARAM_GMEM_SIZE:
*value = adreno_gpu->gmem;
return 0;
case MSM_PARAM_CHIP_ID:
*value = adreno_gpu->rev.patchid |
(adreno_gpu->rev.minor << 8) |
(adreno_gpu->rev.major << 16) |
(adreno_gpu->rev.core << 24);
return 0;
case MSM_PARAM_MAX_FREQ:
*value = adreno_gpu->base.fast_rate;
return 0;
case MSM_PARAM_TIMESTAMP:
if (adreno_gpu->funcs->get_timestamp)
return adreno_gpu->funcs->get_timestamp(gpu, value);
return -EINVAL;
default:
DBG("%s: invalid param: %u", gpu->name, param);
return -EINVAL;
}
}
int adreno_hw_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
int ret;
DBG("%s", gpu->name);
ret = msm_gem_get_iova(gpu->rb->bo, gpu->id, &gpu->rb_iova);
if (ret) {
gpu->rb_iova = 0;
dev_err(gpu->dev->dev, "could not map ringbuffer: %d\n", ret);
return ret;
}
adreno_gpu_write(adreno_gpu, REG_ADRENO_CP_RB_CNTL,
AXXX_CP_RB_CNTL_BUFSZ(ilog2(gpu->rb->size / 8)) |
AXXX_CP_RB_CNTL_BLKSZ(ilog2(RB_BLKSIZE / 8)) |
(adreno_is_a430(adreno_gpu) ? AXXX_CP_RB_CNTL_NO_UPDATE : 0));
adreno_gpu_write(adreno_gpu, REG_ADRENO_CP_RB_BASE, gpu->rb_iova);
if (!adreno_is_a430(adreno_gpu))
adreno_gpu_write(adreno_gpu, REG_ADRENO_CP_RB_RPTR_ADDR,
rbmemptr(adreno_gpu, rptr));
return 0;
}
static uint32_t get_wptr(struct msm_ringbuffer *ring)
{
return ring->cur - ring->start;
}
static uint32_t get_rptr(struct adreno_gpu *adreno_gpu)
{
if (adreno_is_a430(adreno_gpu))
return adreno_gpu->memptrs->rptr = adreno_gpu_read(
adreno_gpu, REG_ADRENO_CP_RB_RPTR);
else
return adreno_gpu->memptrs->rptr;
}
uint32_t adreno_last_fence(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
return adreno_gpu->memptrs->fence;
}
void adreno_recover(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct drm_device *dev = gpu->dev;
int ret;
gpu->funcs->pm_suspend(gpu);
gpu->rb->cur = gpu->rb->start;
adreno_gpu->memptrs->fence = gpu->fctx->completed_fence;
adreno_gpu->memptrs->rptr = 0;
adreno_gpu->memptrs->wptr = 0;
gpu->funcs->pm_resume(gpu);
ret = gpu->funcs->hw_init(gpu);
if (ret) {
dev_err(dev->dev, "gpu hw init failed: %d\n", ret);
}
}
void adreno_submit(struct msm_gpu *gpu, struct msm_gem_submit *submit,
struct msm_file_private *ctx)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct msm_drm_private *priv = gpu->dev->dev_private;
struct msm_ringbuffer *ring = gpu->rb;
unsigned i;
for (i = 0; i < submit->nr_cmds; i++) {
switch (submit->cmd[i].type) {
case MSM_SUBMIT_CMD_IB_TARGET_BUF:
break;
case MSM_SUBMIT_CMD_CTX_RESTORE_BUF:
if (priv->lastctx == ctx)
break;
case MSM_SUBMIT_CMD_BUF:
OUT_PKT3(ring, adreno_is_a430(adreno_gpu) ?
CP_INDIRECT_BUFFER_PFE : CP_INDIRECT_BUFFER_PFD, 2);
OUT_RING(ring, submit->cmd[i].iova);
OUT_RING(ring, submit->cmd[i].size);
OUT_PKT2(ring);
break;
}
}
OUT_PKT0(ring, REG_AXXX_CP_SCRATCH_REG2, 1);
OUT_RING(ring, submit->fence->seqno);
if (adreno_is_a3xx(adreno_gpu) || adreno_is_a4xx(adreno_gpu)) {
OUT_PKT3(ring, CP_EVENT_WRITE, 1);
OUT_RING(ring, HLSQ_FLUSH);
OUT_PKT3(ring, CP_WAIT_FOR_IDLE, 1);
OUT_RING(ring, 0x00000000);
}
OUT_PKT3(ring, CP_EVENT_WRITE, 3);
OUT_RING(ring, CACHE_FLUSH_TS);
OUT_RING(ring, rbmemptr(adreno_gpu, fence));
OUT_RING(ring, submit->fence->seqno);
OUT_PKT3(ring, CP_INTERRUPT, 1);
OUT_RING(ring, 0x80000000);
if (adreno_is_a306(adreno_gpu)) {
OUT_PKT3(ring, CP_WAIT_FOR_IDLE, 1);
OUT_RING(ring, 0x00000000);
OUT_PKT3(ring, CP_INTERRUPT, 1);
OUT_RING(ring, 0x80000000);
}
#if 0
if (adreno_is_a3xx(adreno_gpu)) {
OUT_PKT3(ring, CP_SET_CONSTANT, 2);
OUT_RING(ring, CP_REG(REG_A3XX_HLSQ_CL_KERNEL_GROUP_X_REG));
OUT_RING(ring, 0x00000000);
}
#endif
gpu->funcs->flush(gpu);
}
void adreno_flush(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
uint32_t wptr = get_wptr(gpu->rb);
mb();
adreno_gpu_write(adreno_gpu, REG_ADRENO_CP_RB_WPTR, wptr);
}
void adreno_idle(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
uint32_t wptr = get_wptr(gpu->rb);
int ret;
ret = spin_until(get_rptr(adreno_gpu) == wptr);
if (ret)
DRM_ERROR("%s: timeout waiting to drain ringbuffer!\n", gpu->name);
}
void adreno_show(struct msm_gpu *gpu, struct seq_file *m)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
int i;
seq_printf(m, "revision: %d (%d.%d.%d.%d)\n",
adreno_gpu->info->revn, adreno_gpu->rev.core,
adreno_gpu->rev.major, adreno_gpu->rev.minor,
adreno_gpu->rev.patchid);
seq_printf(m, "fence: %d/%d\n", adreno_gpu->memptrs->fence,
gpu->fctx->last_fence);
seq_printf(m, "rptr: %d\n", get_rptr(adreno_gpu));
seq_printf(m, "wptr: %d\n", adreno_gpu->memptrs->wptr);
seq_printf(m, "rb wptr: %d\n", get_wptr(gpu->rb));
gpu->funcs->pm_resume(gpu);
seq_printf(m, "IO:region %s 00000000 00020000\n", gpu->name);
for (i = 0; adreno_gpu->registers[i] != ~0; i += 2) {
uint32_t start = adreno_gpu->registers[i];
uint32_t end = adreno_gpu->registers[i+1];
uint32_t addr;
for (addr = start; addr <= end; addr++) {
uint32_t val = gpu_read(gpu, addr);
seq_printf(m, "IO:R %08x %08x\n", addr<<2, val);
}
}
gpu->funcs->pm_suspend(gpu);
}
void adreno_dump_info(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
int i;
printk("revision: %d (%d.%d.%d.%d)\n",
adreno_gpu->info->revn, adreno_gpu->rev.core,
adreno_gpu->rev.major, adreno_gpu->rev.minor,
adreno_gpu->rev.patchid);
printk("fence: %d/%d\n", adreno_gpu->memptrs->fence,
gpu->fctx->last_fence);
printk("rptr: %d\n", get_rptr(adreno_gpu));
printk("wptr: %d\n", adreno_gpu->memptrs->wptr);
printk("rb wptr: %d\n", get_wptr(gpu->rb));
for (i = 0; i < 8; i++) {
printk("CP_SCRATCH_REG%d: %u\n", i,
gpu_read(gpu, REG_AXXX_CP_SCRATCH_REG0 + i));
}
}
void adreno_dump(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
int i;
printk("IO:region %s 00000000 00020000\n", gpu->name);
for (i = 0; adreno_gpu->registers[i] != ~0; i += 2) {
uint32_t start = adreno_gpu->registers[i];
uint32_t end = adreno_gpu->registers[i+1];
uint32_t addr;
for (addr = start; addr <= end; addr++) {
uint32_t val = gpu_read(gpu, addr);
printk("IO:R %08x %08x\n", addr<<2, val);
}
}
}
static uint32_t ring_freewords(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
uint32_t size = gpu->rb->size / 4;
uint32_t wptr = get_wptr(gpu->rb);
uint32_t rptr = get_rptr(adreno_gpu);
return (rptr + (size - 1) - wptr) % size;
}
void adreno_wait_ring(struct msm_gpu *gpu, uint32_t ndwords)
{
if (spin_until(ring_freewords(gpu) >= ndwords))
DRM_ERROR("%s: timeout waiting for ringbuffer space\n", gpu->name);
}
int adreno_gpu_init(struct drm_device *drm, struct platform_device *pdev,
struct adreno_gpu *adreno_gpu, const struct adreno_gpu_funcs *funcs)
{
struct adreno_platform_config *config = pdev->dev.platform_data;
struct msm_gpu *gpu = &adreno_gpu->base;
struct msm_mmu *mmu;
int ret;
adreno_gpu->funcs = funcs;
adreno_gpu->info = adreno_info(config->rev);
adreno_gpu->gmem = adreno_gpu->info->gmem;
adreno_gpu->revn = adreno_gpu->info->revn;
adreno_gpu->rev = config->rev;
gpu->fast_rate = config->fast_rate;
gpu->slow_rate = config->slow_rate;
gpu->bus_freq = config->bus_freq;
#ifdef DOWNSTREAM_CONFIG_MSM_BUS_SCALING
gpu->bus_scale_table = config->bus_scale_table;
#endif
DBG("fast_rate=%u, slow_rate=%u, bus_freq=%u",
gpu->fast_rate, gpu->slow_rate, gpu->bus_freq);
ret = msm_gpu_init(drm, pdev, &adreno_gpu->base, &funcs->base,
adreno_gpu->info->name, "kgsl_3d0_reg_memory", "kgsl_3d0_irq",
RB_SIZE);
if (ret)
return ret;
ret = request_firmware(&adreno_gpu->pm4, adreno_gpu->info->pm4fw, drm->dev);
if (ret) {
dev_err(drm->dev, "failed to load %s PM4 firmware: %d\n",
adreno_gpu->info->pm4fw, ret);
return ret;
}
ret = request_firmware(&adreno_gpu->pfp, adreno_gpu->info->pfpfw, drm->dev);
if (ret) {
dev_err(drm->dev, "failed to load %s PFP firmware: %d\n",
adreno_gpu->info->pfpfw, ret);
return ret;
}
mmu = gpu->mmu;
if (mmu) {
ret = mmu->funcs->attach(mmu, iommu_ports,
ARRAY_SIZE(iommu_ports));
if (ret)
return ret;
}
mutex_lock(&drm->struct_mutex);
adreno_gpu->memptrs_bo = msm_gem_new(drm, sizeof(*adreno_gpu->memptrs),
MSM_BO_UNCACHED);
mutex_unlock(&drm->struct_mutex);
if (IS_ERR(adreno_gpu->memptrs_bo)) {
ret = PTR_ERR(adreno_gpu->memptrs_bo);
adreno_gpu->memptrs_bo = NULL;
dev_err(drm->dev, "could not allocate memptrs: %d\n", ret);
return ret;
}
adreno_gpu->memptrs = msm_gem_get_vaddr(adreno_gpu->memptrs_bo);
if (IS_ERR(adreno_gpu->memptrs)) {
dev_err(drm->dev, "could not vmap memptrs\n");
return -ENOMEM;
}
ret = msm_gem_get_iova(adreno_gpu->memptrs_bo, gpu->id,
&adreno_gpu->memptrs_iova);
if (ret) {
dev_err(drm->dev, "could not map memptrs: %d\n", ret);
return ret;
}
return 0;
}
void adreno_gpu_cleanup(struct adreno_gpu *gpu)
{
if (gpu->memptrs_bo) {
if (gpu->memptrs)
msm_gem_put_vaddr(gpu->memptrs_bo);
if (gpu->memptrs_iova)
msm_gem_put_iova(gpu->memptrs_bo, gpu->base.id);
drm_gem_object_unreference_unlocked(gpu->memptrs_bo);
}
release_firmware(gpu->pm4);
release_firmware(gpu->pfp);
msm_gpu_cleanup(&gpu->base);
}
