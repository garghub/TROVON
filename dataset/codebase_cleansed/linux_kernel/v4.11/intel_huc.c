static int huc_ucode_xfer(struct drm_i915_private *dev_priv)
{
struct intel_uc_fw *huc_fw = &dev_priv->huc.fw;
struct i915_vma *vma;
unsigned long offset = 0;
u32 size;
int ret;
ret = i915_gem_object_set_to_gtt_domain(huc_fw->obj, false);
if (ret) {
DRM_DEBUG_DRIVER("set-domain failed %d\n", ret);
return ret;
}
vma = i915_gem_object_ggtt_pin(huc_fw->obj, NULL, 0, 0,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (IS_ERR(vma)) {
DRM_DEBUG_DRIVER("pin failed %d\n", (int)PTR_ERR(vma));
return PTR_ERR(vma);
}
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
I915_WRITE(GUC_WOPCM_SIZE, intel_guc_wopcm_size(dev_priv));
I915_WRITE(DMA_GUC_WOPCM_OFFSET, GUC_WOPCM_OFFSET_VALUE |
HUC_LOADING_AGENT_GUC);
offset = guc_ggtt_offset(vma) + huc_fw->header_offset;
I915_WRITE(DMA_ADDR_0_LOW, lower_32_bits(offset));
I915_WRITE(DMA_ADDR_0_HIGH, upper_32_bits(offset) & 0xFFFF);
I915_WRITE(DMA_ADDR_1_LOW, 0);
I915_WRITE(DMA_ADDR_1_HIGH, DMA_ADDRESS_SPACE_WOPCM);
size = huc_fw->header_size + huc_fw->ucode_size;
I915_WRITE(DMA_COPY_SIZE, size);
I915_WRITE(DMA_CTRL, _MASKED_BIT_ENABLE(HUC_UKERNEL | START_DMA));
ret = wait_for((I915_READ(DMA_CTRL) & START_DMA) == 0, 100);
DRM_DEBUG_DRIVER("HuC DMA transfer wait over with ret %d\n", ret);
I915_WRITE(DMA_CTRL, _MASKED_BIT_DISABLE(HUC_UKERNEL));
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
i915_vma_unpin(vma);
return ret;
}
void intel_huc_init(struct drm_i915_private *dev_priv)
{
struct intel_huc *huc = &dev_priv->huc;
struct intel_uc_fw *huc_fw = &huc->fw;
const char *fw_path = NULL;
huc_fw->path = NULL;
huc_fw->fetch_status = INTEL_UC_FIRMWARE_NONE;
huc_fw->load_status = INTEL_UC_FIRMWARE_NONE;
huc_fw->fw = INTEL_UC_FW_TYPE_HUC;
if (!HAS_HUC_UCODE(dev_priv))
return;
if (IS_SKYLAKE(dev_priv)) {
fw_path = I915_SKL_HUC_UCODE;
huc_fw->major_ver_wanted = SKL_HUC_FW_MAJOR;
huc_fw->minor_ver_wanted = SKL_HUC_FW_MINOR;
} else if (IS_BROXTON(dev_priv)) {
fw_path = I915_BXT_HUC_UCODE;
huc_fw->major_ver_wanted = BXT_HUC_FW_MAJOR;
huc_fw->minor_ver_wanted = BXT_HUC_FW_MINOR;
} else if (IS_KABYLAKE(dev_priv)) {
fw_path = I915_KBL_HUC_UCODE;
huc_fw->major_ver_wanted = KBL_HUC_FW_MAJOR;
huc_fw->minor_ver_wanted = KBL_HUC_FW_MINOR;
}
huc_fw->path = fw_path;
huc_fw->fetch_status = INTEL_UC_FIRMWARE_PENDING;
DRM_DEBUG_DRIVER("HuC firmware pending, path %s\n", fw_path);
WARN(huc_fw->path == NULL, "HuC present but no fw path\n");
intel_uc_fw_fetch(dev_priv, huc_fw);
}
int intel_huc_load(struct drm_i915_private *dev_priv)
{
struct intel_uc_fw *huc_fw = &dev_priv->huc.fw;
int err;
if (huc_fw->fetch_status == INTEL_UC_FIRMWARE_NONE)
return 0;
DRM_DEBUG_DRIVER("%s fw status: fetch %s, load %s\n",
huc_fw->path,
intel_uc_fw_status_repr(huc_fw->fetch_status),
intel_uc_fw_status_repr(huc_fw->load_status));
if (huc_fw->fetch_status == INTEL_UC_FIRMWARE_SUCCESS &&
huc_fw->load_status == INTEL_UC_FIRMWARE_FAIL)
return -ENOEXEC;
huc_fw->load_status = INTEL_UC_FIRMWARE_PENDING;
switch (huc_fw->fetch_status) {
case INTEL_UC_FIRMWARE_FAIL:
err = -EIO;
goto fail;
case INTEL_UC_FIRMWARE_NONE:
case INTEL_UC_FIRMWARE_PENDING:
default:
WARN_ONCE(1, "HuC fw %s invalid fetch_status %s [%d]\n",
huc_fw->path,
intel_uc_fw_status_repr(huc_fw->fetch_status),
huc_fw->fetch_status);
err = -ENXIO;
goto fail;
case INTEL_UC_FIRMWARE_SUCCESS:
break;
}
err = huc_ucode_xfer(dev_priv);
if (err)
goto fail;
huc_fw->load_status = INTEL_UC_FIRMWARE_SUCCESS;
DRM_DEBUG_DRIVER("%s fw status: fetch %s, load %s\n",
huc_fw->path,
intel_uc_fw_status_repr(huc_fw->fetch_status),
intel_uc_fw_status_repr(huc_fw->load_status));
return 0;
fail:
if (huc_fw->load_status == INTEL_UC_FIRMWARE_PENDING)
huc_fw->load_status = INTEL_UC_FIRMWARE_FAIL;
DRM_ERROR("Failed to complete HuC uCode load with ret %d\n", err);
return err;
}
void intel_huc_fini(struct drm_i915_private *dev_priv)
{
struct intel_uc_fw *huc_fw = &dev_priv->huc.fw;
mutex_lock(&dev_priv->drm.struct_mutex);
if (huc_fw->obj)
i915_gem_object_put(huc_fw->obj);
huc_fw->obj = NULL;
mutex_unlock(&dev_priv->drm.struct_mutex);
huc_fw->fetch_status = INTEL_UC_FIRMWARE_NONE;
}
void intel_guc_auth_huc(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct intel_huc *huc = &dev_priv->huc;
struct i915_vma *vma;
int ret;
u32 data[2];
if (huc->fw.load_status != INTEL_UC_FIRMWARE_SUCCESS)
return;
vma = i915_gem_object_ggtt_pin(huc->fw.obj, NULL, 0, 0,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (IS_ERR(vma)) {
DRM_ERROR("failed to pin huc fw object %d\n",
(int)PTR_ERR(vma));
return;
}
data[0] = INTEL_GUC_ACTION_AUTHENTICATE_HUC;
data[1] = guc_ggtt_offset(vma) + huc->fw.rsa_offset;
ret = intel_guc_send(guc, data, ARRAY_SIZE(data));
if (ret) {
DRM_ERROR("HuC: GuC did not ack Auth request %d\n", ret);
goto out;
}
ret = intel_wait_for_register(dev_priv,
HUC_STATUS2,
HUC_FW_VERIFIED,
HUC_FW_VERIFIED,
50);
if (ret) {
DRM_ERROR("HuC: Authentication failed %d\n", ret);
goto out;
}
out:
i915_vma_unpin(vma);
}
