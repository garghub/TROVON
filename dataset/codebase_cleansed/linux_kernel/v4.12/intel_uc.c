static void __intel_uc_fw_fini(struct intel_uc_fw *uc_fw)
{
struct drm_i915_gem_object *obj;
obj = fetch_and_zero(&uc_fw->obj);
if (obj)
i915_gem_object_put(obj);
uc_fw->fetch_status = INTEL_UC_FIRMWARE_NONE;
}
static int __intel_uc_reset_hw(struct drm_i915_private *dev_priv)
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
"GuC status: 0x%x, MIA core expected to be in reset\n",
guc_status);
return ret;
}
void intel_uc_sanitize_options(struct drm_i915_private *dev_priv)
{
if (!HAS_GUC(dev_priv)) {
if (i915.enable_guc_loading > 0 ||
i915.enable_guc_submission > 0)
DRM_INFO("Ignoring GuC options, no hardware\n");
i915.enable_guc_loading = 0;
i915.enable_guc_submission = 0;
return;
}
if (i915.enable_guc_loading < 0)
i915.enable_guc_loading = HAS_GUC_UCODE(dev_priv);
if (i915.enable_guc_loading) {
if (HAS_HUC_UCODE(dev_priv))
intel_huc_select_fw(&dev_priv->huc);
if (intel_guc_select_fw(&dev_priv->guc))
i915.enable_guc_loading = 0;
}
if (!i915.enable_guc_loading)
i915.enable_guc_submission = 0;
if (i915.enable_guc_submission < 0)
i915.enable_guc_submission = HAS_GUC_SCHED(dev_priv);
}
void intel_uc_init_early(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
mutex_init(&guc->send_mutex);
guc->send = intel_guc_send_mmio;
}
static void fetch_uc_fw(struct drm_i915_private *dev_priv,
struct intel_uc_fw *uc_fw)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
struct drm_i915_gem_object *obj;
const struct firmware *fw = NULL;
struct uc_css_header *css;
size_t size;
int err;
if (!uc_fw->path)
return;
uc_fw->fetch_status = INTEL_UC_FIRMWARE_PENDING;
DRM_DEBUG_DRIVER("before requesting firmware: uC fw fetch status %s\n",
intel_uc_fw_status_repr(uc_fw->fetch_status));
err = request_firmware(&fw, uc_fw->path, &pdev->dev);
if (err)
goto fail;
if (!fw)
goto fail;
DRM_DEBUG_DRIVER("fetch uC fw from %s succeeded, fw %p\n",
uc_fw->path, fw);
if (fw->size < sizeof(struct uc_css_header)) {
DRM_NOTE("Firmware header is missing\n");
goto fail;
}
css = (struct uc_css_header *)fw->data;
uc_fw->header_offset = 0;
uc_fw->header_size = (css->header_size_dw - css->modulus_size_dw -
css->key_size_dw - css->exponent_size_dw) * sizeof(u32);
if (uc_fw->header_size != sizeof(struct uc_css_header)) {
DRM_NOTE("CSS header definition mismatch\n");
goto fail;
}
uc_fw->ucode_offset = uc_fw->header_offset + uc_fw->header_size;
uc_fw->ucode_size = (css->size_dw - css->header_size_dw) * sizeof(u32);
if (css->key_size_dw != UOS_RSA_SCRATCH_MAX_COUNT) {
DRM_NOTE("RSA key size is bad\n");
goto fail;
}
uc_fw->rsa_offset = uc_fw->ucode_offset + uc_fw->ucode_size;
uc_fw->rsa_size = css->key_size_dw * sizeof(u32);
size = uc_fw->header_size + uc_fw->ucode_size + uc_fw->rsa_size;
if (fw->size < size) {
DRM_NOTE("Missing firmware components\n");
goto fail;
}
switch (uc_fw->type) {
case INTEL_UC_FW_TYPE_GUC:
size = uc_fw->header_size + uc_fw->ucode_size;
if (size > intel_guc_wopcm_size(dev_priv)) {
DRM_ERROR("Firmware is too large to fit in WOPCM\n");
goto fail;
}
uc_fw->major_ver_found = css->guc.sw_version >> 16;
uc_fw->minor_ver_found = css->guc.sw_version & 0xFFFF;
break;
case INTEL_UC_FW_TYPE_HUC:
uc_fw->major_ver_found = css->huc.sw_version >> 16;
uc_fw->minor_ver_found = css->huc.sw_version & 0xFFFF;
break;
default:
DRM_ERROR("Unknown firmware type %d\n", uc_fw->type);
err = -ENOEXEC;
goto fail;
}
if (uc_fw->major_ver_wanted == 0 && uc_fw->minor_ver_wanted == 0) {
DRM_NOTE("Skipping %s firmware version check\n",
intel_uc_fw_type_repr(uc_fw->type));
} else if (uc_fw->major_ver_found != uc_fw->major_ver_wanted ||
uc_fw->minor_ver_found < uc_fw->minor_ver_wanted) {
DRM_NOTE("%s firmware version %d.%d, required %d.%d\n",
intel_uc_fw_type_repr(uc_fw->type),
uc_fw->major_ver_found, uc_fw->minor_ver_found,
uc_fw->major_ver_wanted, uc_fw->minor_ver_wanted);
err = -ENOEXEC;
goto fail;
}
DRM_DEBUG_DRIVER("firmware version %d.%d OK (minimum %d.%d)\n",
uc_fw->major_ver_found, uc_fw->minor_ver_found,
uc_fw->major_ver_wanted, uc_fw->minor_ver_wanted);
obj = i915_gem_object_create_from_data(dev_priv, fw->data, fw->size);
if (IS_ERR(obj)) {
err = PTR_ERR(obj);
goto fail;
}
uc_fw->obj = obj;
uc_fw->size = fw->size;
DRM_DEBUG_DRIVER("uC fw fetch status SUCCESS, obj %p\n",
uc_fw->obj);
release_firmware(fw);
uc_fw->fetch_status = INTEL_UC_FIRMWARE_SUCCESS;
return;
fail:
DRM_WARN("Failed to fetch valid uC firmware from %s (error %d)\n",
uc_fw->path, err);
DRM_DEBUG_DRIVER("uC fw fetch status FAIL; err %d, fw %p, obj %p\n",
err, fw, uc_fw->obj);
release_firmware(fw);
uc_fw->fetch_status = INTEL_UC_FIRMWARE_FAIL;
}
void intel_uc_init_fw(struct drm_i915_private *dev_priv)
{
fetch_uc_fw(dev_priv, &dev_priv->huc.fw);
fetch_uc_fw(dev_priv, &dev_priv->guc.fw);
}
void intel_uc_fini_fw(struct drm_i915_private *dev_priv)
{
__intel_uc_fw_fini(&dev_priv->guc.fw);
__intel_uc_fw_fini(&dev_priv->huc.fw);
}
int intel_uc_init_hw(struct drm_i915_private *dev_priv)
{
int ret, attempts;
if (!i915.enable_guc_loading)
return 0;
gen9_reset_guc_interrupts(dev_priv);
i915_ggtt_enable_guc(dev_priv);
if (i915.enable_guc_submission) {
ret = i915_guc_submission_init(dev_priv);
if (ret)
goto err_guc;
}
if (IS_GEN9(dev_priv))
attempts = 3;
else
attempts = 1;
while (attempts--) {
ret = __intel_uc_reset_hw(dev_priv);
if (ret)
goto err_submission;
intel_huc_init_hw(&dev_priv->huc);
ret = intel_guc_init_hw(&dev_priv->guc);
if (ret == 0 || ret != -EAGAIN)
break;
DRM_DEBUG_DRIVER("GuC fw load failed: %d; will reset and "
"retry %d more time(s)\n", ret, attempts);
}
if (ret)
goto err_submission;
intel_guc_auth_huc(dev_priv);
if (i915.enable_guc_submission) {
if (i915.guc_log_level >= 0)
gen9_enable_guc_interrupts(dev_priv);
ret = i915_guc_submission_enable(dev_priv);
if (ret)
goto err_interrupts;
}
return 0;
err_interrupts:
gen9_disable_guc_interrupts(dev_priv);
err_submission:
if (i915.enable_guc_submission)
i915_guc_submission_fini(dev_priv);
err_guc:
i915_ggtt_disable_guc(dev_priv);
DRM_ERROR("GuC init failed\n");
if (i915.enable_guc_loading > 1 || i915.enable_guc_submission > 1)
ret = -EIO;
else
ret = 0;
if (i915.enable_guc_submission) {
i915.enable_guc_submission = 0;
DRM_NOTE("Falling back from GuC submission to execlist mode\n");
}
return ret;
}
void intel_uc_fini_hw(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_loading)
return;
if (i915.enable_guc_submission) {
i915_guc_submission_disable(dev_priv);
gen9_disable_guc_interrupts(dev_priv);
i915_guc_submission_fini(dev_priv);
}
i915_ggtt_disable_guc(dev_priv);
}
static bool guc_recv(struct intel_guc *guc, u32 *status)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 val = I915_READ(SOFT_SCRATCH(0));
*status = val;
return INTEL_GUC_RECV_IS_RESPONSE(val);
}
int intel_guc_send_mmio(struct intel_guc *guc, const u32 *action, u32 len)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 status;
int i;
int ret;
if (WARN_ON(len < 1 || len > 15))
return -EINVAL;
mutex_lock(&guc->send_mutex);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_BLITTER);
dev_priv->guc.action_count += 1;
dev_priv->guc.action_cmd = action[0];
for (i = 0; i < len; i++)
I915_WRITE(SOFT_SCRATCH(i), action[i]);
POSTING_READ(SOFT_SCRATCH(i - 1));
I915_WRITE(GUC_SEND_INTERRUPT, GUC_SEND_TRIGGER);
ret = wait_for_us(guc_recv(guc, &status), 10);
if (ret)
ret = wait_for(guc_recv(guc, &status), 10);
if (status != INTEL_GUC_STATUS_SUCCESS) {
if (ret != -ETIMEDOUT)
ret = -EIO;
DRM_WARN("INTEL_GUC_SEND: Action 0x%X failed;"
" ret=%d status=0x%08X response=0x%08X\n",
action[0], ret, status, I915_READ(SOFT_SCRATCH(15)));
dev_priv->guc.action_fail += 1;
dev_priv->guc.action_err = ret;
}
dev_priv->guc.action_status = status;
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_BLITTER);
mutex_unlock(&guc->send_mutex);
return ret;
}
int intel_guc_sample_forcewake(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 action[2];
action[0] = INTEL_GUC_ACTION_SAMPLE_FORCEWAKE;
if (!intel_enable_rc6() || NEEDS_WaRsDisableCoarsePowerGating(dev_priv))
action[1] = 0;
else
action[1] = GUC_FORCEWAKE_RENDER | GUC_FORCEWAKE_MEDIA;
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
