static u32 get_gttype(struct drm_i915_private *dev_priv)
{
return 0;
}
static u32 get_core_family(struct drm_i915_private *dev_priv)
{
u32 gen = INTEL_GEN(dev_priv);
switch (gen) {
case 9:
return GFXCORE_FAMILY_GEN9;
default:
WARN(1, "GEN%d does not support GuC operation!\n", gen);
return GFXCORE_FAMILY_UNKNOWN;
}
}
static void guc_params_init(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
u32 params[GUC_CTL_MAX_DWORDS];
int i;
memset(&params, 0, sizeof(params));
params[GUC_CTL_DEVICE_INFO] |=
(get_gttype(dev_priv) << GUC_CTL_GTTYPE_SHIFT) |
(get_core_family(dev_priv) << GUC_CTL_COREFAMILY_SHIFT);
params[GUC_CTL_ARAT_HIGH] = 0;
params[GUC_CTL_ARAT_LOW] = 100000000;
params[GUC_CTL_WA] |= GUC_CTL_WA_UK_BY_DRIVER;
params[GUC_CTL_FEATURE] |= GUC_CTL_DISABLE_SCHEDULER |
GUC_CTL_VCS2_ENABLED;
params[GUC_CTL_LOG_PARAMS] = guc->log.flags;
if (i915.guc_log_level >= 0) {
params[GUC_CTL_DEBUG] =
i915.guc_log_level << GUC_LOG_VERBOSITY_SHIFT;
} else
params[GUC_CTL_DEBUG] = GUC_LOG_DISABLED;
if (i915.enable_guc_submission) {
u32 ads = guc_ggtt_offset(guc->ads_vma) >> PAGE_SHIFT;
u32 pgs = guc_ggtt_offset(dev_priv->guc.stage_desc_pool);
u32 ctx_in_16 = GUC_MAX_STAGE_DESCRIPTORS / 16;
params[GUC_CTL_DEBUG] |= ads << GUC_ADS_ADDR_SHIFT;
params[GUC_CTL_DEBUG] |= GUC_ADS_ENABLED;
pgs >>= PAGE_SHIFT;
params[GUC_CTL_CTXINFO] = (pgs << GUC_CTL_BASE_ADDR_SHIFT) |
(ctx_in_16 << GUC_CTL_CTXNUM_IN16_SHIFT);
params[GUC_CTL_FEATURE] |= GUC_CTL_KERNEL_SUBMISSIONS;
params[GUC_CTL_FEATURE] &= ~GUC_CTL_DISABLE_SCHEDULER;
}
I915_WRITE(SOFT_SCRATCH(0), 0);
for (i = 0; i < GUC_CTL_MAX_DWORDS; i++)
I915_WRITE(SOFT_SCRATCH(1 + i), params[i]);
}
static inline bool guc_ucode_response(struct drm_i915_private *dev_priv,
u32 *status)
{
u32 val = I915_READ(GUC_STATUS);
u32 uk_val = val & GS_UKERNEL_MASK;
*status = val;
return (uk_val == GS_UKERNEL_READY ||
((val & GS_MIA_CORE_STATE) && uk_val == GS_UKERNEL_LAPIC_DONE));
}
static int guc_ucode_xfer_dma(struct drm_i915_private *dev_priv,
struct i915_vma *vma)
{
struct intel_uc_fw *guc_fw = &dev_priv->guc.fw;
unsigned long offset;
struct sg_table *sg = vma->pages;
u32 status, rsa[UOS_RSA_SCRATCH_MAX_COUNT];
int i, ret = 0;
offset = guc_fw->rsa_offset;
sg_pcopy_to_buffer(sg->sgl, sg->nents, rsa, sizeof(rsa), offset);
for (i = 0; i < UOS_RSA_SCRATCH_MAX_COUNT; i++)
I915_WRITE(UOS_RSA_SCRATCH(i), rsa[i]);
I915_WRITE(DMA_COPY_SIZE, guc_fw->header_size + guc_fw->ucode_size);
offset = guc_ggtt_offset(vma) + guc_fw->header_offset;
I915_WRITE(DMA_ADDR_0_LOW, lower_32_bits(offset));
I915_WRITE(DMA_ADDR_0_HIGH, upper_32_bits(offset) & 0xFFFF);
I915_WRITE(DMA_ADDR_1_LOW, 0x2000);
I915_WRITE(DMA_ADDR_1_HIGH, DMA_ADDRESS_SPACE_WOPCM);
I915_WRITE(DMA_CTRL, _MASKED_BIT_ENABLE(UOS_MOVE | START_DMA));
ret = wait_for(guc_ucode_response(dev_priv, &status), 100);
DRM_DEBUG_DRIVER("DMA status 0x%x, GuC status 0x%x\n",
I915_READ(DMA_CTRL), status);
if ((status & GS_BOOTROM_MASK) == GS_BOOTROM_RSA_FAILED) {
DRM_ERROR("GuC firmware signature verification failed\n");
ret = -ENOEXEC;
}
DRM_DEBUG_DRIVER("returning %d\n", ret);
return ret;
}
u32 intel_guc_wopcm_size(struct drm_i915_private *dev_priv)
{
u32 wopcm_size = GUC_WOPCM_TOP;
if (IS_GEN9_LP(dev_priv))
wopcm_size -= BXT_GUC_WOPCM_RC6_RESERVED;
return wopcm_size;
}
static int guc_ucode_xfer(struct drm_i915_private *dev_priv)
{
struct intel_uc_fw *guc_fw = &dev_priv->guc.fw;
struct i915_vma *vma;
int ret;
ret = i915_gem_object_set_to_gtt_domain(guc_fw->obj, false);
if (ret) {
DRM_DEBUG_DRIVER("set-domain failed %d\n", ret);
return ret;
}
vma = i915_gem_object_ggtt_pin(guc_fw->obj, NULL, 0, 0,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (IS_ERR(vma)) {
DRM_DEBUG_DRIVER("pin failed %d\n", (int)PTR_ERR(vma));
return PTR_ERR(vma);
}
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
I915_WRITE(GUC_WOPCM_SIZE, intel_guc_wopcm_size(dev_priv));
I915_WRITE(DMA_GUC_WOPCM_OFFSET, GUC_WOPCM_OFFSET_VALUE);
I915_WRITE(GUC_SHIM_CONTROL, GUC_SHIM_CONTROL_VALUE);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
I915_WRITE(GUC_SHIM_CONTROL, (I915_READ(GUC_SHIM_CONTROL) &
~GUC_ENABLE_MIA_CLOCK_GATING));
}
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_B0))
I915_WRITE(GEN6_GFXPAUSE, 0x30FFF);
if (IS_GEN9_LP(dev_priv))
I915_WRITE(GEN9LP_GT_PM_CONFIG, GT_DOORBELL_ENABLE);
else
I915_WRITE(GEN9_GT_PM_CONFIG, GT_DOORBELL_ENABLE);
if (IS_GEN9(dev_priv)) {
I915_WRITE(GEN7_MISCCPCTL, (GEN8_DOP_CLOCK_GATE_GUC_ENABLE |
I915_READ(GEN7_MISCCPCTL)));
I915_WRITE(GUC_ARAT_C6DIS, 0x1FF);
}
guc_params_init(dev_priv);
ret = guc_ucode_xfer_dma(dev_priv, vma);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
i915_vma_unpin(vma);
return ret;
}
int intel_guc_init_hw(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
const char *fw_path = guc->fw.path;
int ret;
DRM_DEBUG_DRIVER("GuC fw status: path %s, fetch %s, load %s\n",
fw_path,
intel_uc_fw_status_repr(guc->fw.fetch_status),
intel_uc_fw_status_repr(guc->fw.load_status));
if (guc->fw.fetch_status != INTEL_UC_FIRMWARE_SUCCESS)
return -EIO;
guc->fw.load_status = INTEL_UC_FIRMWARE_PENDING;
DRM_DEBUG_DRIVER("GuC fw status: fetch %s, load %s\n",
intel_uc_fw_status_repr(guc->fw.fetch_status),
intel_uc_fw_status_repr(guc->fw.load_status));
ret = guc_ucode_xfer(dev_priv);
if (ret)
return -EAGAIN;
guc->fw.load_status = INTEL_UC_FIRMWARE_SUCCESS;
DRM_INFO("GuC %s (firmware %s [version %u.%u])\n",
i915.enable_guc_submission ? "submission enabled" : "loaded",
guc->fw.path,
guc->fw.major_ver_found, guc->fw.minor_ver_found);
return 0;
}
int intel_guc_select_fw(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
guc->fw.path = NULL;
guc->fw.fetch_status = INTEL_UC_FIRMWARE_NONE;
guc->fw.load_status = INTEL_UC_FIRMWARE_NONE;
guc->fw.type = INTEL_UC_FW_TYPE_GUC;
if (i915.guc_firmware_path) {
guc->fw.path = i915.guc_firmware_path;
guc->fw.major_ver_wanted = 0;
guc->fw.minor_ver_wanted = 0;
} else if (IS_SKYLAKE(dev_priv)) {
guc->fw.path = I915_SKL_GUC_UCODE;
guc->fw.major_ver_wanted = SKL_FW_MAJOR;
guc->fw.minor_ver_wanted = SKL_FW_MINOR;
} else if (IS_BROXTON(dev_priv)) {
guc->fw.path = I915_BXT_GUC_UCODE;
guc->fw.major_ver_wanted = BXT_FW_MAJOR;
guc->fw.minor_ver_wanted = BXT_FW_MINOR;
} else if (IS_KABYLAKE(dev_priv)) {
guc->fw.path = I915_KBL_GUC_UCODE;
guc->fw.major_ver_wanted = KBL_FW_MAJOR;
guc->fw.minor_ver_wanted = KBL_FW_MINOR;
} else {
DRM_ERROR("No GuC firmware known for platform with GuC!\n");
return -ENOENT;
}
return 0;
}
