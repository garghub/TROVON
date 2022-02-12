static inline uint32_t _get_mvolts(struct msm_gpu *gpu, uint32_t freq)
{
struct drm_device *dev = gpu->dev;
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
struct dev_pm_opp *opp;
opp = dev_pm_opp_find_freq_exact(&pdev->dev, freq, true);
return (!IS_ERR(opp)) ? dev_pm_opp_get_voltage(opp) / 1000 : 0;
}
static void a5xx_lm_setup(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a5xx_gpu *a5xx_gpu = to_a5xx_gpu(adreno_gpu);
unsigned int i;
for (i = 0; i < ARRAY_SIZE(a5xx_sequence_regs); i++)
gpu_write(gpu, a5xx_sequence_regs[i].reg,
a5xx_sequence_regs[i].value);
gpu_write(gpu, REG_A5XX_GPMU_TEMP_SENSOR_ID, 0x60007);
gpu_write(gpu, REG_A5XX_GPMU_DELTA_TEMP_THRESHOLD, 0x01);
gpu_write(gpu, REG_A5XX_GPMU_TEMP_SENSOR_CONFIG, 0x01);
gpu_write(gpu, REG_A5XX_GPMU_GPMU_VOLTAGE, 0x80000000 | 0);
gpu_write(gpu, REG_A5XX_GPMU_BASE_LEAKAGE, a5xx_gpu->lm_leakage);
gpu_write(gpu, REG_A5XX_GPMU_GPMU_PWR_THRESHOLD, 0x80000000 | 6000);
gpu_write(gpu, REG_A5XX_GPMU_BEC_ENABLE, 0x10001FFF);
gpu_write(gpu, REG_A5XX_GDPM_CONFIG1, 0x00201FF1);
gpu_write(gpu, REG_A5XX_GPMU_BEC_ENABLE, 0x10001FFF);
gpu_write(gpu, REG_A5XX_GDPM_CONFIG1, 0x201FF1);
gpu_write(gpu, AGC_MSG_STATE, 1);
gpu_write(gpu, AGC_MSG_COMMAND, AGC_POWER_CONFIG_PRODUCTION_ID);
gpu_write(gpu, AGC_MSG_PAYLOAD(0), 5448);
gpu_write(gpu, AGC_MSG_PAYLOAD(1), 1);
gpu_write(gpu, AGC_MSG_PAYLOAD(2), _get_mvolts(gpu, gpu->fast_rate));
gpu_write(gpu, AGC_MSG_PAYLOAD(3), gpu->fast_rate / 1000000);
gpu_write(gpu, AGC_MSG_PAYLOAD_SIZE, 4 * sizeof(uint32_t));
gpu_write(gpu, AGC_INIT_MSG_MAGIC, AGC_INIT_MSG_VALUE);
}
static void a5xx_pc_init(struct msm_gpu *gpu)
{
gpu_write(gpu, REG_A5XX_GPMU_PWR_COL_INTER_FRAME_CTRL, 0x7F);
gpu_write(gpu, REG_A5XX_GPMU_PWR_COL_BINNING_CTRL, 0);
gpu_write(gpu, REG_A5XX_GPMU_PWR_COL_INTER_FRAME_HYST, 0xA0080);
gpu_write(gpu, REG_A5XX_GPMU_PWR_COL_STAGGER_DELAY, 0x600040);
}
static int a5xx_gpmu_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a5xx_gpu *a5xx_gpu = to_a5xx_gpu(adreno_gpu);
struct msm_ringbuffer *ring = gpu->rb;
if (!a5xx_gpu->gpmu_dwords)
return 0;
OUT_PKT7(ring, CP_SET_PROTECTED_MODE, 1);
OUT_RING(ring, 0);
OUT_PKT7(ring, CP_INDIRECT_BUFFER_PFE, 3);
OUT_RING(ring, lower_32_bits(a5xx_gpu->gpmu_iova));
OUT_RING(ring, upper_32_bits(a5xx_gpu->gpmu_iova));
OUT_RING(ring, a5xx_gpu->gpmu_dwords);
OUT_PKT7(ring, CP_SET_PROTECTED_MODE, 1);
OUT_RING(ring, 1);
gpu->funcs->flush(gpu);
if (!a5xx_idle(gpu)) {
DRM_ERROR("%s: Unable to load GPMU firmware. GPMU will not be active\n",
gpu->name);
return -EINVAL;
}
gpu_write(gpu, REG_A5XX_GPMU_WFI_CONFIG, 0x4014);
gpu_write(gpu, REG_A5XX_GPMU_CM3_SYSRESET, 0x0);
if (spin_usecs(gpu, 25, REG_A5XX_GPMU_GENERAL_0, 0xFFFFFFFF,
0xBABEFACE))
DRM_ERROR("%s: GPMU firmware initialization timed out\n",
gpu->name);
return 0;
}
static void a5xx_lm_enable(struct msm_gpu *gpu)
{
gpu_write(gpu, REG_A5XX_GDPM_INT_MASK, 0x0);
gpu_write(gpu, REG_A5XX_GDPM_INT_EN, 0x0A);
gpu_write(gpu, REG_A5XX_GPMU_GPMU_VOLTAGE_INTR_EN_MASK, 0x01);
gpu_write(gpu, REG_A5XX_GPMU_TEMP_THRESHOLD_INTR_EN_MASK, 0x50000);
gpu_write(gpu, REG_A5XX_GPMU_THROTTLE_UNMASK_FORCE_CTRL, 0x30000);
gpu_write(gpu, REG_A5XX_GPMU_CLOCK_THROTTLE_CTRL, 0x011);
}
int a5xx_power_init(struct msm_gpu *gpu)
{
int ret;
a5xx_lm_setup(gpu);
a5xx_pc_init(gpu);
ret = a5xx_gpmu_init(gpu);
if (ret)
return ret;
a5xx_lm_enable(gpu);
return 0;
}
void a5xx_gpmu_ucode_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a5xx_gpu *a5xx_gpu = to_a5xx_gpu(adreno_gpu);
struct drm_device *drm = gpu->dev;
const struct firmware *fw;
uint32_t dwords = 0, offset = 0, bosize;
unsigned int *data, *ptr, *cmds;
unsigned int cmds_size;
if (a5xx_gpu->gpmu_bo)
return;
if (request_firmware(&fw, adreno_gpu->info->gpmufw, drm->dev)) {
DRM_ERROR("%s: Could not get GPMU firmware. GPMU will not be active\n",
gpu->name);
return;
}
data = (unsigned int *) fw->data;
if (fw->size < 8 || (data[0] < 2) || (data[0] >= (fw->size >> 2)))
goto out;
if (data[1] != 2)
goto out;
cmds = data + data[2] + 3;
cmds_size = data[0] - data[2] - 2;
bosize = (cmds_size + (cmds_size / TYPE4_MAX_PAYLOAD) + 1) << 2;
ptr = msm_gem_kernel_new_locked(drm, bosize,
MSM_BO_UNCACHED | MSM_BO_GPU_READONLY, gpu->aspace,
&a5xx_gpu->gpmu_bo, &a5xx_gpu->gpmu_iova);
if (IS_ERR(ptr))
goto err;
while (cmds_size > 0) {
int i;
uint32_t _size = cmds_size > TYPE4_MAX_PAYLOAD ?
TYPE4_MAX_PAYLOAD : cmds_size;
ptr[dwords++] = PKT4(REG_A5XX_GPMU_INST_RAM_BASE + offset,
_size);
for (i = 0; i < _size; i++)
ptr[dwords++] = *cmds++;
offset += _size;
cmds_size -= _size;
}
msm_gem_put_vaddr(a5xx_gpu->gpmu_bo);
a5xx_gpu->gpmu_dwords = dwords;
goto out;
err:
if (a5xx_gpu->gpmu_iova)
msm_gem_put_iova(a5xx_gpu->gpmu_bo, gpu->aspace);
if (a5xx_gpu->gpmu_bo)
drm_gem_object_unreference(a5xx_gpu->gpmu_bo);
a5xx_gpu->gpmu_bo = NULL;
a5xx_gpu->gpmu_iova = 0;
a5xx_gpu->gpmu_dwords = 0;
out:
release_firmware(fw);
}
