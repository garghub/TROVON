static bool is_supported_device(struct drm_i915_private *dev_priv)
{
if (IS_BROADWELL(dev_priv))
return true;
if (IS_SKYLAKE(dev_priv))
return true;
if (IS_KABYLAKE(dev_priv))
return true;
return false;
}
void intel_gvt_sanitize_options(struct drm_i915_private *dev_priv)
{
if (!i915.enable_gvt)
return;
if (intel_vgpu_active(dev_priv)) {
DRM_INFO("GVT-g is disabled for guest\n");
goto bail;
}
if (!is_supported_device(dev_priv)) {
DRM_INFO("Unsupported device. GVT-g is disabled\n");
goto bail;
}
return;
bail:
i915.enable_gvt = 0;
}
int intel_gvt_init(struct drm_i915_private *dev_priv)
{
int ret;
if (!i915.enable_gvt) {
DRM_DEBUG_DRIVER("GVT-g is disabled by kernel params\n");
return 0;
}
if (!i915.enable_execlists) {
DRM_ERROR("i915 GVT-g loading failed due to disabled execlists mode\n");
return -EIO;
}
if (i915.enable_guc_submission) {
DRM_ERROR("i915 GVT-g loading failed due to Graphics virtualization is not yet supported with GuC submission\n");
return -EIO;
}
ret = intel_gvt_init_host();
if (ret) {
DRM_DEBUG_DRIVER("Not in host or MPT modules not found\n");
goto bail;
}
ret = intel_gvt_init_device(dev_priv);
if (ret) {
DRM_DEBUG_DRIVER("Fail to init GVT device\n");
goto bail;
}
return 0;
bail:
i915.enable_gvt = 0;
return 0;
}
void intel_gvt_cleanup(struct drm_i915_private *dev_priv)
{
if (!intel_gvt_active(dev_priv))
return;
intel_gvt_clean_device(dev_priv);
}
