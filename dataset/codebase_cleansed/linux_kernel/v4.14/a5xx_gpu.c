static int zap_shader_load_mdt(struct device *dev, const char *fwname)
{
const struct firmware *fw;
struct device_node *np;
struct resource r;
phys_addr_t mem_phys;
ssize_t mem_size;
void *mem_region = NULL;
int ret;
if (!IS_ENABLED(CONFIG_ARCH_QCOM))
return -EINVAL;
np = of_get_child_by_name(dev->of_node, "zap-shader");
if (!np)
return -ENODEV;
np = of_parse_phandle(np, "memory-region", 0);
if (!np)
return -EINVAL;
ret = of_address_to_resource(np, 0, &r);
if (ret)
return ret;
mem_phys = r.start;
mem_size = resource_size(&r);
ret = request_firmware(&fw, fwname, dev);
if (ret) {
DRM_DEV_ERROR(dev, "Unable to load %s\n", fwname);
return ret;
}
mem_size = qcom_mdt_get_size(fw);
if (mem_size < 0) {
ret = mem_size;
goto out;
}
mem_region = memremap(mem_phys, mem_size, MEMREMAP_WC);
if (!mem_region) {
ret = -ENOMEM;
goto out;
}
ret = qcom_mdt_load(dev, fw, fwname, GPU_PAS_ID, mem_region, mem_phys,
mem_size);
if (ret)
goto out;
ret = qcom_scm_pas_auth_and_reset(GPU_PAS_ID);
if (ret)
DRM_DEV_ERROR(dev, "Unable to authorize the image\n");
out:
if (mem_region)
memunmap(mem_region);
release_firmware(fw);
return ret;
}
static void a5xx_submit(struct msm_gpu *gpu, struct msm_gem_submit *submit,
struct msm_file_private *ctx)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct msm_drm_private *priv = gpu->dev->dev_private;
struct msm_ringbuffer *ring = gpu->rb;
unsigned int i, ibs = 0;
for (i = 0; i < submit->nr_cmds; i++) {
switch (submit->cmd[i].type) {
case MSM_SUBMIT_CMD_IB_TARGET_BUF:
break;
case MSM_SUBMIT_CMD_CTX_RESTORE_BUF:
if (priv->lastctx == ctx)
break;
case MSM_SUBMIT_CMD_BUF:
OUT_PKT7(ring, CP_INDIRECT_BUFFER_PFE, 3);
OUT_RING(ring, lower_32_bits(submit->cmd[i].iova));
OUT_RING(ring, upper_32_bits(submit->cmd[i].iova));
OUT_RING(ring, submit->cmd[i].size);
ibs++;
break;
}
}
OUT_PKT4(ring, REG_A5XX_CP_SCRATCH_REG(2), 1);
OUT_RING(ring, submit->fence->seqno);
OUT_PKT7(ring, CP_EVENT_WRITE, 4);
OUT_RING(ring, CACHE_FLUSH_TS | (1 << 31));
OUT_RING(ring, lower_32_bits(rbmemptr(adreno_gpu, fence)));
OUT_RING(ring, upper_32_bits(rbmemptr(adreno_gpu, fence)));
OUT_RING(ring, submit->fence->seqno);
gpu->funcs->flush(gpu);
}
void a5xx_set_hwcg(struct msm_gpu *gpu, bool state)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(a5xx_hwcg); i++)
gpu_write(gpu, a5xx_hwcg[i].offset,
state ? a5xx_hwcg[i].value : 0);
gpu_write(gpu, REG_A5XX_RBBM_CLOCK_CNTL, state ? 0xAAA8AA00 : 0);
gpu_write(gpu, REG_A5XX_RBBM_ISDB_CNT, state ? 0x182 : 0x180);
}
static int a5xx_me_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct msm_ringbuffer *ring = gpu->rb;
OUT_PKT7(ring, CP_ME_INIT, 8);
OUT_RING(ring, 0x0000002F);
OUT_RING(ring, 0x00000003);
OUT_RING(ring, 0x20000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
if (adreno_is_a530(adreno_gpu)) {
OUT_RING(ring, 0x0000000B);
} else {
OUT_RING(ring, 0x00000000);
}
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
gpu->funcs->flush(gpu);
return a5xx_idle(gpu) ? 0 : -EINVAL;
}
static struct drm_gem_object *a5xx_ucode_load_bo(struct msm_gpu *gpu,
const struct firmware *fw, u64 *iova)
{
struct drm_gem_object *bo;
void *ptr;
ptr = msm_gem_kernel_new_locked(gpu->dev, fw->size - 4,
MSM_BO_UNCACHED | MSM_BO_GPU_READONLY, gpu->aspace, &bo, iova);
if (IS_ERR(ptr))
return ERR_CAST(ptr);
memcpy(ptr, &fw->data[4], fw->size - 4);
msm_gem_put_vaddr(bo);
return bo;
}
static int a5xx_ucode_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a5xx_gpu *a5xx_gpu = to_a5xx_gpu(adreno_gpu);
int ret;
if (!a5xx_gpu->pm4_bo) {
a5xx_gpu->pm4_bo = a5xx_ucode_load_bo(gpu, adreno_gpu->pm4,
&a5xx_gpu->pm4_iova);
if (IS_ERR(a5xx_gpu->pm4_bo)) {
ret = PTR_ERR(a5xx_gpu->pm4_bo);
a5xx_gpu->pm4_bo = NULL;
dev_err(gpu->dev->dev, "could not allocate PM4: %d\n",
ret);
return ret;
}
}
if (!a5xx_gpu->pfp_bo) {
a5xx_gpu->pfp_bo = a5xx_ucode_load_bo(gpu, adreno_gpu->pfp,
&a5xx_gpu->pfp_iova);
if (IS_ERR(a5xx_gpu->pfp_bo)) {
ret = PTR_ERR(a5xx_gpu->pfp_bo);
a5xx_gpu->pfp_bo = NULL;
dev_err(gpu->dev->dev, "could not allocate PFP: %d\n",
ret);
return ret;
}
}
gpu_write64(gpu, REG_A5XX_CP_ME_INSTR_BASE_LO,
REG_A5XX_CP_ME_INSTR_BASE_HI, a5xx_gpu->pm4_iova);
gpu_write64(gpu, REG_A5XX_CP_PFP_INSTR_BASE_LO,
REG_A5XX_CP_PFP_INSTR_BASE_HI, a5xx_gpu->pfp_iova);
return 0;
}
static int a5xx_zap_shader_resume(struct msm_gpu *gpu)
{
int ret;
ret = qcom_scm_set_remote_state(SCM_GPU_ZAP_SHADER_RESUME, GPU_PAS_ID);
if (ret)
DRM_ERROR("%s: zap-shader resume failed: %d\n",
gpu->name, ret);
return ret;
}
static int a5xx_zap_shader_init(struct msm_gpu *gpu)
{
static bool loaded;
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct platform_device *pdev = gpu->pdev;
int ret;
if (loaded)
return a5xx_zap_shader_resume(gpu);
if (!qcom_scm_is_available()) {
DRM_DEV_ERROR(&pdev->dev, "SCM is not available\n");
return -EPROBE_DEFER;
}
if (!adreno_gpu->info->zapfw) {
DRM_DEV_ERROR(&pdev->dev,
"Zap shader firmware file not specified for this target\n");
return -ENODEV;
}
ret = zap_shader_load_mdt(&pdev->dev, adreno_gpu->info->zapfw);
loaded = !ret;
return ret;
}
static int a5xx_hw_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
int ret;
gpu_write(gpu, REG_A5XX_VBIF_ROUND_ROBIN_QOS_ARB, 0x00000003);
gpu_write(gpu, REG_A5XX_RBBM_PERFCTR_GPU_BUSY_MASKED, 0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_AHB_CNTL0, 0x00000001);
if (adreno_gpu->info->quirks & ADRENO_QUIRK_FAULT_DETECT_MASK) {
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL11,
0xF0000000);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL12,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL13,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL14,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL15,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL16,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL17,
0xFFFFFFFF);
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_MASK_CNTL18,
0xFFFFFFFF);
}
gpu_write(gpu, REG_A5XX_RBBM_INTERFACE_HANG_INT_CNTL,
(1 << 30) | 0xFFFF);
gpu_write(gpu, REG_A5XX_RBBM_PERFCTR_CNTL, 0x01);
gpu_write(gpu, REG_A5XX_UCHE_CACHE_WAYS, 0x02);
gpu_write(gpu, REG_A5XX_UCHE_TRAP_BASE_LO, 0xFFFF0000);
gpu_write(gpu, REG_A5XX_UCHE_TRAP_BASE_HI, 0x0001FFFF);
gpu_write(gpu, REG_A5XX_UCHE_WRITE_THRU_BASE_LO, 0xFFFF0000);
gpu_write(gpu, REG_A5XX_UCHE_WRITE_THRU_BASE_HI, 0x0001FFFF);
gpu_write(gpu, REG_A5XX_UCHE_GMEM_RANGE_MIN_LO, 0x00100000);
gpu_write(gpu, REG_A5XX_UCHE_GMEM_RANGE_MIN_HI, 0x00000000);
gpu_write(gpu, REG_A5XX_UCHE_GMEM_RANGE_MAX_LO,
0x00100000 + adreno_gpu->gmem - 1);
gpu_write(gpu, REG_A5XX_UCHE_GMEM_RANGE_MAX_HI, 0x00000000);
gpu_write(gpu, REG_A5XX_CP_MEQ_THRESHOLDS, 0x40);
gpu_write(gpu, REG_A5XX_CP_MERCIU_SIZE, 0x40);
gpu_write(gpu, REG_A5XX_CP_ROQ_THRESHOLDS_2, 0x80000060);
gpu_write(gpu, REG_A5XX_CP_ROQ_THRESHOLDS_1, 0x40201B16);
gpu_write(gpu, REG_A5XX_PC_DBG_ECO_CNTL, (0x400 << 11 | 0x300 << 22));
if (adreno_gpu->info->quirks & ADRENO_QUIRK_TWO_PASS_USE_WFI)
gpu_rmw(gpu, REG_A5XX_PC_DBG_ECO_CNTL, 0, (1 << 8));
gpu_write(gpu, REG_A5XX_PC_DBG_ECO_CNTL, 0xc0200100);
gpu_write(gpu, REG_A5XX_CP_CHICKEN_DBG, 0x02000000);
gpu_write(gpu, REG_A5XX_RBBM_AHB_CNTL1, 0xA6FFFFFF);
a5xx_set_hwcg(gpu, true);
gpu_write(gpu, REG_A5XX_RBBM_AHB_CNTL2, 0x0000003F);
gpu_write(gpu, REG_A5XX_TPL1_MODE_CNTL, 2 << 7);
gpu_write(gpu, REG_A5XX_RB_MODE_CNTL, 2 << 1);
gpu_write(gpu, REG_A5XX_CP_PROTECT_CNTL, 0x00000007);
gpu_write(gpu, REG_A5XX_CP_PROTECT(0), ADRENO_PROTECT_RW(0x04, 4));
gpu_write(gpu, REG_A5XX_CP_PROTECT(1), ADRENO_PROTECT_RW(0x08, 8));
gpu_write(gpu, REG_A5XX_CP_PROTECT(2), ADRENO_PROTECT_RW(0x10, 16));
gpu_write(gpu, REG_A5XX_CP_PROTECT(3), ADRENO_PROTECT_RW(0x20, 32));
gpu_write(gpu, REG_A5XX_CP_PROTECT(4), ADRENO_PROTECT_RW(0x40, 64));
gpu_write(gpu, REG_A5XX_CP_PROTECT(5), ADRENO_PROTECT_RW(0x80, 64));
gpu_write(gpu, REG_A5XX_CP_PROTECT(6),
ADRENO_PROTECT_RW(REG_A5XX_RBBM_SECVID_TSB_TRUSTED_BASE_LO,
16));
gpu_write(gpu, REG_A5XX_CP_PROTECT(7),
ADRENO_PROTECT_RW(REG_A5XX_RBBM_SECVID_TRUST_CNTL, 2));
gpu_write(gpu, REG_A5XX_CP_PROTECT(8), ADRENO_PROTECT_RW(0x800, 64));
gpu_write(gpu, REG_A5XX_CP_PROTECT(9), ADRENO_PROTECT_RW(0x840, 8));
gpu_write(gpu, REG_A5XX_CP_PROTECT(10), ADRENO_PROTECT_RW(0x880, 32));
gpu_write(gpu, REG_A5XX_CP_PROTECT(11), ADRENO_PROTECT_RW(0xAA0, 1));
gpu_write(gpu, REG_A5XX_CP_PROTECT(12), ADRENO_PROTECT_RW(0xCC0, 1));
gpu_write(gpu, REG_A5XX_CP_PROTECT(13), ADRENO_PROTECT_RW(0xCF0, 2));
gpu_write(gpu, REG_A5XX_CP_PROTECT(14), ADRENO_PROTECT_RW(0xE68, 8));
gpu_write(gpu, REG_A5XX_CP_PROTECT(15), ADRENO_PROTECT_RW(0xE70, 4));
gpu_write(gpu, REG_A5XX_CP_PROTECT(16), ADRENO_PROTECT_RW(0xE80, 16));
if (adreno_is_a530(adreno_gpu))
gpu_write(gpu, REG_A5XX_CP_PROTECT(17),
ADRENO_PROTECT_RW(0x10000, 0x8000));
gpu_write(gpu, REG_A5XX_RBBM_SECVID_TSB_CNTL, 0);
gpu_write64(gpu, REG_A5XX_RBBM_SECVID_TSB_TRUSTED_BASE_LO,
REG_A5XX_RBBM_SECVID_TSB_TRUSTED_BASE_HI, 0x00000000);
gpu_write(gpu, REG_A5XX_RBBM_SECVID_TSB_TRUSTED_SIZE, 0x00000000);
a5xx_gpmu_ucode_init(gpu);
ret = adreno_hw_init(gpu);
if (ret)
return ret;
ret = a5xx_ucode_init(gpu);
if (ret)
return ret;
gpu_write(gpu, REG_A5XX_RBBM_INT_0_MASK, A5XX_INT_MASK);
gpu_write(gpu, REG_A5XX_CP_PFP_ME_CNTL, 0);
ret = a5xx_me_init(gpu);
if (ret)
return ret;
ret = a5xx_power_init(gpu);
if (ret)
return ret;
if (adreno_is_a530(adreno_gpu)) {
OUT_PKT7(gpu->rb, CP_EVENT_WRITE, 1);
OUT_RING(gpu->rb, 0x0F);
gpu->funcs->flush(gpu);
if (!a5xx_idle(gpu))
return -EINVAL;
}
ret = a5xx_zap_shader_init(gpu);
if (!ret) {
OUT_PKT7(gpu->rb, CP_SET_SECURE_MODE, 1);
OUT_RING(gpu->rb, 0x00000000);
gpu->funcs->flush(gpu);
if (!a5xx_idle(gpu))
return -EINVAL;
} else {
dev_warn_once(gpu->dev->dev,
"Zap shader not enabled - using SECVID_TRUST_CNTL instead\n");
gpu_write(gpu, REG_A5XX_RBBM_SECVID_TRUST_CNTL, 0x0);
}
return 0;
}
static void a5xx_recover(struct msm_gpu *gpu)
{
int i;
adreno_dump_info(gpu);
for (i = 0; i < 8; i++) {
printk("CP_SCRATCH_REG%d: %u\n", i,
gpu_read(gpu, REG_A5XX_CP_SCRATCH_REG(i)));
}
if (hang_debug)
a5xx_dump(gpu);
gpu_write(gpu, REG_A5XX_RBBM_SW_RESET_CMD, 1);
gpu_read(gpu, REG_A5XX_RBBM_SW_RESET_CMD);
gpu_write(gpu, REG_A5XX_RBBM_SW_RESET_CMD, 0);
adreno_recover(gpu);
}
static void a5xx_destroy(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a5xx_gpu *a5xx_gpu = to_a5xx_gpu(adreno_gpu);
DBG("%s", gpu->name);
if (a5xx_gpu->pm4_bo) {
if (a5xx_gpu->pm4_iova)
msm_gem_put_iova(a5xx_gpu->pm4_bo, gpu->aspace);
drm_gem_object_unreference_unlocked(a5xx_gpu->pm4_bo);
}
if (a5xx_gpu->pfp_bo) {
if (a5xx_gpu->pfp_iova)
msm_gem_put_iova(a5xx_gpu->pfp_bo, gpu->aspace);
drm_gem_object_unreference_unlocked(a5xx_gpu->pfp_bo);
}
if (a5xx_gpu->gpmu_bo) {
if (a5xx_gpu->gpmu_iova)
msm_gem_put_iova(a5xx_gpu->gpmu_bo, gpu->aspace);
drm_gem_object_unreference_unlocked(a5xx_gpu->gpmu_bo);
}
adreno_gpu_cleanup(adreno_gpu);
kfree(a5xx_gpu);
}
static inline bool _a5xx_check_idle(struct msm_gpu *gpu)
{
if (gpu_read(gpu, REG_A5XX_RBBM_STATUS) & ~A5XX_RBBM_STATUS_HI_BUSY)
return false;
return !(gpu_read(gpu, REG_A5XX_RBBM_INT_0_STATUS) &
A5XX_RBBM_INT_0_MASK_MISC_HANG_DETECT);
}
bool a5xx_idle(struct msm_gpu *gpu)
{
if (!adreno_idle(gpu))
return false;
if (spin_until(_a5xx_check_idle(gpu))) {
DRM_ERROR("%s: %ps: timeout waiting for GPU to idle: status %8.8X irq %8.8X\n",
gpu->name, __builtin_return_address(0),
gpu_read(gpu, REG_A5XX_RBBM_STATUS),
gpu_read(gpu, REG_A5XX_RBBM_INT_0_STATUS));
return false;
}
return true;
}
static int a5xx_fault_handler(void *arg, unsigned long iova, int flags)
{
struct msm_gpu *gpu = arg;
pr_warn_ratelimited("*** gpu fault: iova=%08lx, flags=%d (%u,%u,%u,%u)\n",
iova, flags,
gpu_read(gpu, REG_A5XX_CP_SCRATCH_REG(4)),
gpu_read(gpu, REG_A5XX_CP_SCRATCH_REG(5)),
gpu_read(gpu, REG_A5XX_CP_SCRATCH_REG(6)),
gpu_read(gpu, REG_A5XX_CP_SCRATCH_REG(7)));
return -EFAULT;
}
static void a5xx_cp_err_irq(struct msm_gpu *gpu)
{
u32 status = gpu_read(gpu, REG_A5XX_CP_INTERRUPT_STATUS);
if (status & A5XX_CP_INT_CP_OPCODE_ERROR) {
u32 val;
gpu_write(gpu, REG_A5XX_CP_PFP_STAT_ADDR, 0);
gpu_read(gpu, REG_A5XX_CP_PFP_STAT_DATA);
val = gpu_read(gpu, REG_A5XX_CP_PFP_STAT_DATA);
dev_err_ratelimited(gpu->dev->dev, "CP | opcode error | possible opcode=0x%8.8X\n",
val);
}
if (status & A5XX_CP_INT_CP_HW_FAULT_ERROR)
dev_err_ratelimited(gpu->dev->dev, "CP | HW fault | status=0x%8.8X\n",
gpu_read(gpu, REG_A5XX_CP_HW_FAULT));
if (status & A5XX_CP_INT_CP_DMA_ERROR)
dev_err_ratelimited(gpu->dev->dev, "CP | DMA error\n");
if (status & A5XX_CP_INT_CP_REGISTER_PROTECTION_ERROR) {
u32 val = gpu_read(gpu, REG_A5XX_CP_PROTECT_STATUS);
dev_err_ratelimited(gpu->dev->dev,
"CP | protected mode error | %s | addr=0x%8.8X | status=0x%8.8X\n",
val & (1 << 24) ? "WRITE" : "READ",
(val & 0xFFFFF) >> 2, val);
}
if (status & A5XX_CP_INT_CP_AHB_ERROR) {
u32 status = gpu_read(gpu, REG_A5XX_CP_AHB_FAULT);
const char *access[16] = { "reserved", "reserved",
"timestamp lo", "timestamp hi", "pfp read", "pfp write",
"", "", "me read", "me write", "", "", "crashdump read",
"crashdump write" };
dev_err_ratelimited(gpu->dev->dev,
"CP | AHB error | addr=%X access=%s error=%d | status=0x%8.8X\n",
status & 0xFFFFF, access[(status >> 24) & 0xF],
(status & (1 << 31)), status);
}
}
static void a5xx_rbbm_err_irq(struct msm_gpu *gpu, u32 status)
{
if (status & A5XX_RBBM_INT_0_MASK_RBBM_AHB_ERROR) {
u32 val = gpu_read(gpu, REG_A5XX_RBBM_AHB_ERROR_STATUS);
dev_err_ratelimited(gpu->dev->dev,
"RBBM | AHB bus error | %s | addr=0x%X | ports=0x%X:0x%X\n",
val & (1 << 28) ? "WRITE" : "READ",
(val & 0xFFFFF) >> 2, (val >> 20) & 0x3,
(val >> 24) & 0xF);
gpu_write(gpu, REG_A5XX_RBBM_AHB_CMD, (1 << 4));
gpu_write(gpu, REG_A5XX_RBBM_INT_CLEAR_CMD,
A5XX_RBBM_INT_0_MASK_RBBM_AHB_ERROR);
}
if (status & A5XX_RBBM_INT_0_MASK_RBBM_TRANSFER_TIMEOUT)
dev_err_ratelimited(gpu->dev->dev, "RBBM | AHB transfer timeout\n");
if (status & A5XX_RBBM_INT_0_MASK_RBBM_ME_MS_TIMEOUT)
dev_err_ratelimited(gpu->dev->dev, "RBBM | ME master split | status=0x%X\n",
gpu_read(gpu, REG_A5XX_RBBM_AHB_ME_SPLIT_STATUS));
if (status & A5XX_RBBM_INT_0_MASK_RBBM_PFP_MS_TIMEOUT)
dev_err_ratelimited(gpu->dev->dev, "RBBM | PFP master split | status=0x%X\n",
gpu_read(gpu, REG_A5XX_RBBM_AHB_PFP_SPLIT_STATUS));
if (status & A5XX_RBBM_INT_0_MASK_RBBM_ETS_MS_TIMEOUT)
dev_err_ratelimited(gpu->dev->dev, "RBBM | ETS master split | status=0x%X\n",
gpu_read(gpu, REG_A5XX_RBBM_AHB_ETS_SPLIT_STATUS));
if (status & A5XX_RBBM_INT_0_MASK_RBBM_ATB_ASYNC_OVERFLOW)
dev_err_ratelimited(gpu->dev->dev, "RBBM | ATB ASYNC overflow\n");
if (status & A5XX_RBBM_INT_0_MASK_RBBM_ATB_BUS_OVERFLOW)
dev_err_ratelimited(gpu->dev->dev, "RBBM | ATB bus overflow\n");
}
static void a5xx_uche_err_irq(struct msm_gpu *gpu)
{
uint64_t addr = (uint64_t) gpu_read(gpu, REG_A5XX_UCHE_TRAP_LOG_HI);
addr |= gpu_read(gpu, REG_A5XX_UCHE_TRAP_LOG_LO);
dev_err_ratelimited(gpu->dev->dev, "UCHE | Out of bounds access | addr=0x%llX\n",
addr);
}
static void a5xx_gpmu_err_irq(struct msm_gpu *gpu)
{
dev_err_ratelimited(gpu->dev->dev, "GPMU | voltage droop\n");
}
static void a5xx_fault_detect_irq(struct msm_gpu *gpu)
{
struct drm_device *dev = gpu->dev;
struct msm_drm_private *priv = dev->dev_private;
dev_err(dev->dev, "gpu fault fence %x status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
gpu->funcs->last_fence(gpu),
gpu_read(gpu, REG_A5XX_RBBM_STATUS),
gpu_read(gpu, REG_A5XX_CP_RB_RPTR),
gpu_read(gpu, REG_A5XX_CP_RB_WPTR),
gpu_read64(gpu, REG_A5XX_CP_IB1_BASE, REG_A5XX_CP_IB1_BASE_HI),
gpu_read(gpu, REG_A5XX_CP_IB1_BUFSZ),
gpu_read64(gpu, REG_A5XX_CP_IB2_BASE, REG_A5XX_CP_IB2_BASE_HI),
gpu_read(gpu, REG_A5XX_CP_IB2_BUFSZ));
del_timer(&gpu->hangcheck_timer);
queue_work(priv->wq, &gpu->recover_work);
}
static irqreturn_t a5xx_irq(struct msm_gpu *gpu)
{
u32 status = gpu_read(gpu, REG_A5XX_RBBM_INT_0_STATUS);
gpu_write(gpu, REG_A5XX_RBBM_INT_CLEAR_CMD,
status & ~A5XX_RBBM_INT_0_MASK_RBBM_AHB_ERROR);
if (status & RBBM_ERROR_MASK)
a5xx_rbbm_err_irq(gpu, status);
if (status & A5XX_RBBM_INT_0_MASK_CP_HW_ERROR)
a5xx_cp_err_irq(gpu);
if (status & A5XX_RBBM_INT_0_MASK_MISC_HANG_DETECT)
a5xx_fault_detect_irq(gpu);
if (status & A5XX_RBBM_INT_0_MASK_UCHE_OOB_ACCESS)
a5xx_uche_err_irq(gpu);
if (status & A5XX_RBBM_INT_0_MASK_GPMU_VOLTAGE_DROOP)
a5xx_gpmu_err_irq(gpu);
if (status & A5XX_RBBM_INT_0_MASK_CP_CACHE_FLUSH_TS)
msm_gpu_retire(gpu);
return IRQ_HANDLED;
}
static void a5xx_dump(struct msm_gpu *gpu)
{
dev_info(gpu->dev->dev, "status: %08x\n",
gpu_read(gpu, REG_A5XX_RBBM_STATUS));
adreno_dump(gpu);
}
static int a5xx_pm_resume(struct msm_gpu *gpu)
{
int ret;
ret = msm_gpu_pm_resume(gpu);
if (ret)
return ret;
gpu_write(gpu, REG_A5XX_GPMU_RBCCU_POWER_CNTL, 0x778000);
udelay(3);
ret = spin_usecs(gpu, 20, REG_A5XX_GPMU_RBCCU_PWR_CLK_STATUS,
(1 << 20), (1 << 20));
if (ret) {
DRM_ERROR("%s: timeout waiting for RBCCU GDSC enable: %X\n",
gpu->name,
gpu_read(gpu, REG_A5XX_GPMU_RBCCU_PWR_CLK_STATUS));
return ret;
}
gpu_write(gpu, REG_A5XX_GPMU_SP_POWER_CNTL, 0x778000);
ret = spin_usecs(gpu, 20, REG_A5XX_GPMU_SP_PWR_CLK_STATUS,
(1 << 20), (1 << 20));
if (ret)
DRM_ERROR("%s: timeout waiting for SP GDSC enable\n",
gpu->name);
return ret;
}
static int a5xx_pm_suspend(struct msm_gpu *gpu)
{
gpu_write(gpu, REG_A5XX_VBIF_XIN_HALT_CTRL0, 0xF);
spin_until((gpu_read(gpu, REG_A5XX_VBIF_XIN_HALT_CTRL1) & 0xF) == 0xF);
gpu_write(gpu, REG_A5XX_VBIF_XIN_HALT_CTRL0, 0);
gpu_write(gpu, REG_A5XX_RBBM_BLOCK_SW_RESET_CMD, 0x003C0000);
gpu_write(gpu, REG_A5XX_RBBM_BLOCK_SW_RESET_CMD, 0x00000000);
return msm_gpu_pm_suspend(gpu);
}
static int a5xx_get_timestamp(struct msm_gpu *gpu, uint64_t *value)
{
*value = gpu_read64(gpu, REG_A5XX_RBBM_PERFCTR_CP_0_LO,
REG_A5XX_RBBM_PERFCTR_CP_0_HI);
return 0;
}
static void a5xx_show(struct msm_gpu *gpu, struct seq_file *m)
{
seq_printf(m, "status: %08x\n",
gpu_read(gpu, REG_A5XX_RBBM_STATUS));
a5xx_set_hwcg(gpu, false);
adreno_show(gpu, m);
a5xx_set_hwcg(gpu, true);
}
struct msm_gpu *a5xx_gpu_init(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
struct a5xx_gpu *a5xx_gpu = NULL;
struct adreno_gpu *adreno_gpu;
struct msm_gpu *gpu;
int ret;
if (!pdev) {
dev_err(dev->dev, "No A5XX device is defined\n");
return ERR_PTR(-ENXIO);
}
a5xx_gpu = kzalloc(sizeof(*a5xx_gpu), GFP_KERNEL);
if (!a5xx_gpu)
return ERR_PTR(-ENOMEM);
adreno_gpu = &a5xx_gpu->base;
gpu = &adreno_gpu->base;
adreno_gpu->registers = a5xx_registers;
adreno_gpu->reg_offsets = a5xx_register_offsets;
a5xx_gpu->lm_leakage = 0x4E001A;
ret = adreno_gpu_init(dev, pdev, adreno_gpu, &funcs);
if (ret) {
a5xx_destroy(&(a5xx_gpu->base.base));
return ERR_PTR(ret);
}
if (gpu->aspace)
msm_mmu_set_fault_handler(gpu->aspace->mmu, gpu, a5xx_fault_handler);
return gpu;
}
