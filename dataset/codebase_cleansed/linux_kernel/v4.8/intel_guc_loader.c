const char *intel_guc_fw_status_repr(enum intel_guc_fw_status status)
{
switch (status) {
case GUC_FIRMWARE_FAIL:
return "FAIL";
case GUC_FIRMWARE_NONE:
return "NONE";
case GUC_FIRMWARE_PENDING:
return "PENDING";
case GUC_FIRMWARE_SUCCESS:
return "SUCCESS";
default:
return "UNKNOWN!";
}
}
static void direct_interrupts_to_host(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
int irqs;
irqs = _MASKED_FIELD(GFX_FORWARD_VBLANK_MASK, GFX_FORWARD_VBLANK_NEVER);
irqs |= _MASKED_BIT_DISABLE(GFX_INTERRUPT_STEERING);
for_each_engine(engine, dev_priv)
I915_WRITE(RING_MODE_GEN7(engine), irqs);
I915_WRITE(GUC_BCS_RCS_IER, 0);
I915_WRITE(GUC_VCS2_VCS1_IER, 0);
I915_WRITE(GUC_WD_VECS_IER, 0);
}
static void direct_interrupts_to_guc(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
int irqs;
u32 tmp;
irqs = _MASKED_BIT_ENABLE(GFX_INTERRUPT_STEERING);
for_each_engine(engine, dev_priv)
I915_WRITE(RING_MODE_GEN7(engine), irqs);
irqs = GT_RENDER_USER_INTERRUPT << GEN8_RCS_IRQ_SHIFT |
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
I915_WRITE(GUC_BCS_RCS_IER, ~irqs);
I915_WRITE(GUC_VCS2_VCS1_IER, ~irqs);
I915_WRITE(GUC_WD_VECS_IER, ~irqs);
tmp = I915_READ(GEN6_PMINTRMSK);
if (tmp & GEN8_PMINTR_REDIRECT_TO_NON_DISP) {
dev_priv->rps.pm_intr_keep |= ~(tmp & ~GEN8_PMINTR_REDIRECT_TO_NON_DISP);
dev_priv->rps.pm_intr_keep &= ~GEN8_PMINTR_REDIRECT_TO_NON_DISP;
}
}
static u32 get_gttype(struct drm_i915_private *dev_priv)
{
return 0;
}
static u32 get_core_family(struct drm_i915_private *dev_priv)
{
switch (INTEL_INFO(dev_priv)->gen) {
case 9:
return GFXCORE_FAMILY_GEN9;
default:
DRM_ERROR("GUC: unsupported core family\n");
return GFXCORE_FAMILY_UNKNOWN;
}
}
static void set_guc_init_params(struct drm_i915_private *dev_priv)
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
if (i915.guc_log_level >= 0) {
params[GUC_CTL_LOG_PARAMS] = guc->log_flags;
params[GUC_CTL_DEBUG] =
i915.guc_log_level << GUC_LOG_VERBOSITY_SHIFT;
}
if (guc->ads_obj) {
u32 ads = (u32)i915_gem_obj_ggtt_offset(guc->ads_obj)
>> PAGE_SHIFT;
params[GUC_CTL_DEBUG] |= ads << GUC_ADS_ADDR_SHIFT;
params[GUC_CTL_DEBUG] |= GUC_ADS_ENABLED;
}
if (i915.enable_guc_submission) {
u32 pgs = i915_gem_obj_ggtt_offset(dev_priv->guc.ctx_pool_obj);
u32 ctx_in_16 = GUC_MAX_GPU_CONTEXTS / 16;
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
static int guc_ucode_xfer_dma(struct drm_i915_private *dev_priv)
{
struct intel_guc_fw *guc_fw = &dev_priv->guc.guc_fw;
struct drm_i915_gem_object *fw_obj = guc_fw->guc_fw_obj;
unsigned long offset;
struct sg_table *sg = fw_obj->pages;
u32 status, rsa[UOS_RSA_SCRATCH_MAX_COUNT];
int i, ret = 0;
offset = guc_fw->rsa_offset;
sg_pcopy_to_buffer(sg->sgl, sg->nents, rsa, sizeof(rsa), offset);
for (i = 0; i < UOS_RSA_SCRATCH_MAX_COUNT; i++)
I915_WRITE(UOS_RSA_SCRATCH(i), rsa[i]);
I915_WRITE(DMA_COPY_SIZE, guc_fw->header_size + guc_fw->ucode_size);
offset = i915_gem_obj_ggtt_offset(fw_obj) + guc_fw->header_offset;
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
static u32 guc_wopcm_size(struct drm_i915_private *dev_priv)
{
u32 wopcm_size = GUC_WOPCM_TOP;
if (IS_BROXTON(dev_priv))
wopcm_size -= BXT_GUC_WOPCM_RC6_RESERVED;
return wopcm_size;
}
static int guc_ucode_xfer(struct drm_i915_private *dev_priv)
{
struct intel_guc_fw *guc_fw = &dev_priv->guc.guc_fw;
struct drm_device *dev = &dev_priv->drm;
int ret;
ret = i915_gem_object_set_to_gtt_domain(guc_fw->guc_fw_obj, false);
if (ret) {
DRM_DEBUG_DRIVER("set-domain failed %d\n", ret);
return ret;
}
ret = i915_gem_obj_ggtt_pin(guc_fw->guc_fw_obj, 0, 0);
if (ret) {
DRM_DEBUG_DRIVER("pin failed %d\n", ret);
return ret;
}
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
I915_WRITE(GUC_WOPCM_SIZE, guc_wopcm_size(dev_priv));
I915_WRITE(DMA_GUC_WOPCM_OFFSET, GUC_WOPCM_OFFSET_VALUE);
I915_WRITE(GUC_SHIM_CONTROL, GUC_SHIM_CONTROL_VALUE);
if (IS_SKL_REVID(dev, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1)) {
I915_WRITE(GUC_SHIM_CONTROL, (I915_READ(GUC_SHIM_CONTROL) &
~GUC_ENABLE_MIA_CLOCK_GATING));
}
I915_WRITE(GEN6_GFXPAUSE, 0x30FFF);
if (IS_BROXTON(dev))
I915_WRITE(GEN9LP_GT_PM_CONFIG, GT_DOORBELL_ENABLE);
else
I915_WRITE(GEN9_GT_PM_CONFIG, GT_DOORBELL_ENABLE);
if (IS_GEN9(dev)) {
I915_WRITE(GEN7_MISCCPCTL, (GEN8_DOP_CLOCK_GATE_GUC_ENABLE |
I915_READ(GEN7_MISCCPCTL)));
I915_WRITE(GUC_ARAT_C6DIS, 0x1FF);
}
set_guc_init_params(dev_priv);
ret = guc_ucode_xfer_dma(dev_priv);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
i915_gem_object_ggtt_unpin(guc_fw->guc_fw_obj);
return ret;
}
static int i915_reset_guc(struct drm_i915_private *dev_priv)
{
int ret;
u32 guc_status;
ret = intel_guc_reset(dev_priv);
if (ret) {
DRM_ERROR("GuC reset failed, ret = %d\n", ret);
return ret;
}
guc_status = I915_READ(GUC_STATUS);
WARN(!(guc_status & GS_MIA_IN_RESET),
"GuC status: 0x%x, MIA core expected to be in reset\n", guc_status);
return ret;
}
int intel_guc_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_guc_fw *guc_fw = &dev_priv->guc.guc_fw;
const char *fw_path = guc_fw->guc_fw_path;
int retries, ret, err;
DRM_DEBUG_DRIVER("GuC fw status: path %s, fetch %s, load %s\n",
fw_path,
intel_guc_fw_status_repr(guc_fw->guc_fw_fetch_status),
intel_guc_fw_status_repr(guc_fw->guc_fw_load_status));
if (!i915.enable_guc_loading) {
err = 0;
goto fail;
} else if (fw_path == NULL) {
err = -ENXIO;
goto fail;
} else if (*fw_path == '\0') {
DRM_INFO("No GuC firmware known for this platform\n");
err = -ENODEV;
goto fail;
}
if (guc_fw->guc_fw_fetch_status != GUC_FIRMWARE_SUCCESS) {
err = -EIO;
goto fail;
} else if (guc_fw->guc_fw_load_status == GUC_FIRMWARE_FAIL) {
err = -ENOEXEC;
goto fail;
}
direct_interrupts_to_host(dev_priv);
guc_fw->guc_fw_load_status = GUC_FIRMWARE_PENDING;
DRM_DEBUG_DRIVER("GuC fw status: fetch %s, load %s\n",
intel_guc_fw_status_repr(guc_fw->guc_fw_fetch_status),
intel_guc_fw_status_repr(guc_fw->guc_fw_load_status));
err = i915_guc_submission_init(dev_priv);
if (err)
goto fail;
for (retries = 3; ; ) {
err = i915_reset_guc(dev_priv);
if (err) {
DRM_ERROR("GuC reset failed: %d\n", err);
goto fail;
}
err = guc_ucode_xfer(dev_priv);
if (!err)
break;
if (--retries == 0)
goto fail;
DRM_INFO("GuC fw load failed: %d; will reset and "
"retry %d more time(s)\n", err, retries);
}
guc_fw->guc_fw_load_status = GUC_FIRMWARE_SUCCESS;
DRM_DEBUG_DRIVER("GuC fw status: fetch %s, load %s\n",
intel_guc_fw_status_repr(guc_fw->guc_fw_fetch_status),
intel_guc_fw_status_repr(guc_fw->guc_fw_load_status));
if (i915.enable_guc_submission) {
err = i915_guc_submission_enable(dev_priv);
if (err)
goto fail;
direct_interrupts_to_guc(dev_priv);
}
return 0;
fail:
if (guc_fw->guc_fw_load_status == GUC_FIRMWARE_PENDING)
guc_fw->guc_fw_load_status = GUC_FIRMWARE_FAIL;
direct_interrupts_to_host(dev_priv);
i915_guc_submission_disable(dev_priv);
i915_guc_submission_fini(dev_priv);
if (i915.enable_guc_loading > 1) {
ret = -EIO;
} else if (i915.enable_guc_submission > 1) {
ret = -EIO;
} else {
ret = 0;
}
if (err == 0 && !HAS_GUC_UCODE(dev))
;
else if (err == 0)
DRM_INFO("GuC firmware load skipped\n");
else if (ret != -EIO)
DRM_INFO("GuC firmware load failed: %d\n", err);
else
DRM_ERROR("GuC firmware load failed: %d\n", err);
if (i915.enable_guc_submission) {
if (fw_path == NULL)
DRM_INFO("GuC submission without firmware not supported\n");
if (ret == 0)
DRM_INFO("Falling back from GuC submission to execlist mode\n");
else
DRM_ERROR("GuC init failed: %d\n", ret);
}
i915.enable_guc_submission = 0;
return ret;
}
static void guc_fw_fetch(struct drm_device *dev, struct intel_guc_fw *guc_fw)
{
struct drm_i915_gem_object *obj;
const struct firmware *fw;
struct guc_css_header *css;
size_t size;
int err;
DRM_DEBUG_DRIVER("before requesting firmware: GuC fw fetch status %s\n",
intel_guc_fw_status_repr(guc_fw->guc_fw_fetch_status));
err = request_firmware(&fw, guc_fw->guc_fw_path, &dev->pdev->dev);
if (err)
goto fail;
if (!fw)
goto fail;
DRM_DEBUG_DRIVER("fetch GuC fw from %s succeeded, fw %p\n",
guc_fw->guc_fw_path, fw);
if (fw->size < sizeof(struct guc_css_header)) {
DRM_ERROR("Firmware header is missing\n");
goto fail;
}
css = (struct guc_css_header *)fw->data;
guc_fw->header_offset = 0;
guc_fw->header_size = (css->header_size_dw - css->modulus_size_dw -
css->key_size_dw - css->exponent_size_dw) * sizeof(u32);
if (guc_fw->header_size != sizeof(struct guc_css_header)) {
DRM_ERROR("CSS header definition mismatch\n");
goto fail;
}
guc_fw->ucode_offset = guc_fw->header_offset + guc_fw->header_size;
guc_fw->ucode_size = (css->size_dw - css->header_size_dw) * sizeof(u32);
if (css->key_size_dw != UOS_RSA_SCRATCH_MAX_COUNT) {
DRM_ERROR("RSA key size is bad\n");
goto fail;
}
guc_fw->rsa_offset = guc_fw->ucode_offset + guc_fw->ucode_size;
guc_fw->rsa_size = css->key_size_dw * sizeof(u32);
size = guc_fw->header_size + guc_fw->ucode_size + guc_fw->rsa_size;
if (fw->size < size) {
DRM_ERROR("Missing firmware components\n");
goto fail;
}
size = guc_fw->header_size + guc_fw->ucode_size;
if (size > guc_wopcm_size(to_i915(dev))) {
DRM_ERROR("Firmware is too large to fit in WOPCM\n");
goto fail;
}
guc_fw->guc_fw_major_found = css->guc_sw_version >> 16;
guc_fw->guc_fw_minor_found = css->guc_sw_version & 0xFFFF;
if (guc_fw->guc_fw_major_found != guc_fw->guc_fw_major_wanted ||
guc_fw->guc_fw_minor_found < guc_fw->guc_fw_minor_wanted) {
DRM_ERROR("GuC firmware version %d.%d, required %d.%d\n",
guc_fw->guc_fw_major_found, guc_fw->guc_fw_minor_found,
guc_fw->guc_fw_major_wanted, guc_fw->guc_fw_minor_wanted);
err = -ENOEXEC;
goto fail;
}
DRM_DEBUG_DRIVER("firmware version %d.%d OK (minimum %d.%d)\n",
guc_fw->guc_fw_major_found, guc_fw->guc_fw_minor_found,
guc_fw->guc_fw_major_wanted, guc_fw->guc_fw_minor_wanted);
mutex_lock(&dev->struct_mutex);
obj = i915_gem_object_create_from_data(dev, fw->data, fw->size);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR_OR_NULL(obj)) {
err = obj ? PTR_ERR(obj) : -ENOMEM;
goto fail;
}
guc_fw->guc_fw_obj = obj;
guc_fw->guc_fw_size = fw->size;
DRM_DEBUG_DRIVER("GuC fw fetch status SUCCESS, obj %p\n",
guc_fw->guc_fw_obj);
release_firmware(fw);
guc_fw->guc_fw_fetch_status = GUC_FIRMWARE_SUCCESS;
return;
fail:
DRM_DEBUG_DRIVER("GuC fw fetch status FAIL; err %d, fw %p, obj %p\n",
err, fw, guc_fw->guc_fw_obj);
DRM_ERROR("Failed to fetch GuC firmware from %s (error %d)\n",
guc_fw->guc_fw_path, err);
mutex_lock(&dev->struct_mutex);
obj = guc_fw->guc_fw_obj;
if (obj)
drm_gem_object_unreference(&obj->base);
guc_fw->guc_fw_obj = NULL;
mutex_unlock(&dev->struct_mutex);
release_firmware(fw);
guc_fw->guc_fw_fetch_status = GUC_FIRMWARE_FAIL;
}
void intel_guc_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_guc_fw *guc_fw = &dev_priv->guc.guc_fw;
const char *fw_path;
if (i915.enable_guc_loading < 0)
i915.enable_guc_loading = HAS_GUC_UCODE(dev);
if (i915.enable_guc_submission < 0)
i915.enable_guc_submission = HAS_GUC_SCHED(dev);
if (!HAS_GUC_UCODE(dev)) {
fw_path = NULL;
} else if (IS_SKYLAKE(dev)) {
fw_path = I915_SKL_GUC_UCODE;
guc_fw->guc_fw_major_wanted = 6;
guc_fw->guc_fw_minor_wanted = 1;
} else if (IS_BROXTON(dev)) {
fw_path = I915_BXT_GUC_UCODE;
guc_fw->guc_fw_major_wanted = 8;
guc_fw->guc_fw_minor_wanted = 7;
} else if (IS_KABYLAKE(dev)) {
fw_path = I915_KBL_GUC_UCODE;
guc_fw->guc_fw_major_wanted = 9;
guc_fw->guc_fw_minor_wanted = 14;
} else {
fw_path = "";
}
guc_fw->guc_dev = dev;
guc_fw->guc_fw_path = fw_path;
guc_fw->guc_fw_fetch_status = GUC_FIRMWARE_NONE;
guc_fw->guc_fw_load_status = GUC_FIRMWARE_NONE;
if (!i915.enable_guc_loading)
return;
if (fw_path == NULL)
return;
if (*fw_path == '\0')
return;
guc_fw->guc_fw_fetch_status = GUC_FIRMWARE_PENDING;
DRM_DEBUG_DRIVER("GuC firmware pending, path %s\n", fw_path);
guc_fw_fetch(dev, guc_fw);
}
void intel_guc_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_guc_fw *guc_fw = &dev_priv->guc.guc_fw;
mutex_lock(&dev->struct_mutex);
direct_interrupts_to_host(dev_priv);
i915_guc_submission_disable(dev_priv);
i915_guc_submission_fini(dev_priv);
if (guc_fw->guc_fw_obj)
drm_gem_object_unreference(&guc_fw->guc_fw_obj->base);
guc_fw->guc_fw_obj = NULL;
mutex_unlock(&dev->struct_mutex);
guc_fw->guc_fw_fetch_status = GUC_FIRMWARE_NONE;
}
