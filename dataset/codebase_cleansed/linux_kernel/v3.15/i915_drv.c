void intel_detect_pch(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pch = NULL;
if (INTEL_INFO(dev)->num_pipes == 0) {
dev_priv->pch_type = PCH_NOP;
return;
}
while ((pch = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, pch))) {
if (pch->vendor == PCI_VENDOR_ID_INTEL) {
unsigned short id = pch->device & INTEL_PCH_DEVICE_ID_MASK;
dev_priv->pch_id = id;
if (id == INTEL_PCH_IBX_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_IBX;
DRM_DEBUG_KMS("Found Ibex Peak PCH\n");
WARN_ON(!IS_GEN5(dev));
} else if (id == INTEL_PCH_CPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found CougarPoint PCH\n");
WARN_ON(!(IS_GEN6(dev) || IS_IVYBRIDGE(dev)));
} else if (id == INTEL_PCH_PPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found PantherPoint PCH\n");
WARN_ON(!(IS_GEN6(dev) || IS_IVYBRIDGE(dev)));
} else if (id == INTEL_PCH_LPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(IS_ULT(dev));
} else if (IS_BROADWELL(dev)) {
dev_priv->pch_type = PCH_LPT;
dev_priv->pch_id =
INTEL_PCH_LPT_LP_DEVICE_ID_TYPE;
DRM_DEBUG_KMS("This is Broadwell, assuming "
"LynxPoint LP PCH\n");
} else if (id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint LP PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(!IS_ULT(dev));
} else
continue;
break;
}
}
if (!pch)
DRM_DEBUG_KMS("No PCH found.\n");
pci_dev_put(pch);
}
bool i915_semaphore_is_enabled(struct drm_device *dev)
{
if (INTEL_INFO(dev)->gen < 6)
return false;
if (i915.semaphores >= 0)
return i915.semaphores;
if (IS_GEN8(dev))
return false;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return true;
}
static int i915_drm_freeze(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_SUSPENDED;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_display_set_init_power(dev_priv, true);
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
int error;
error = i915_gem_suspend(dev);
if (error) {
dev_err(&dev->pdev->dev,
"GEM idle failed, resume might fail\n");
return error;
}
cancel_delayed_work_sync(&dev_priv->rps.delayed_resume_work);
drm_irq_uninstall(dev);
dev_priv->enable_hotplug_processing = false;
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
dev_priv->display.crtc_disable(crtc);
mutex_unlock(&dev->mode_config.mutex);
intel_modeset_suspend_hw(dev);
}
i915_gem_suspend_gtt_mappings(dev);
i915_save_state(dev);
intel_opregion_fini(dev);
intel_uncore_fini(dev);
console_lock();
intel_fbdev_set_suspend(dev, FBINFO_STATE_SUSPENDED);
console_unlock();
dev_priv->suspend_count++;
return 0;
}
int i915_suspend(struct drm_device *dev, pm_message_t state)
{
int error;
if (!dev || !dev->dev_private) {
DRM_ERROR("dev: %p\n", dev);
DRM_ERROR("DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (state.event == PM_EVENT_PRETHAW)
return 0;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
error = i915_drm_freeze(dev);
if (error)
return error;
if (state.event == PM_EVENT_SUSPEND) {
pci_disable_device(dev->pdev);
pci_set_power_state(dev->pdev, PCI_D3hot);
}
return 0;
}
void intel_console_resume(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private,
console_resume_work);
struct drm_device *dev = dev_priv->dev;
console_lock();
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING);
console_unlock();
}
static void intel_resume_hotplug(struct drm_device *dev)
{
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
mutex_lock(&mode_config->mutex);
DRM_DEBUG_KMS("running encoder hotplug functions\n");
list_for_each_entry(encoder, &mode_config->encoder_list, base.head)
if (encoder->hot_plug)
encoder->hot_plug(encoder);
mutex_unlock(&mode_config->mutex);
drm_helper_hpd_irq_event(dev);
}
static int i915_drm_thaw_early(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
intel_uncore_early_sanitize(dev);
intel_uncore_sanitize(dev);
intel_power_domains_init_hw(dev_priv);
return 0;
}
static int __i915_drm_thaw(struct drm_device *dev, bool restore_gtt_mappings)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int error = 0;
if (drm_core_check_feature(dev, DRIVER_MODESET) &&
restore_gtt_mappings) {
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
}
i915_restore_state(dev);
intel_opregion_setup(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_init_pch_refclk(dev);
drm_mode_config_reset(dev);
mutex_lock(&dev->struct_mutex);
error = i915_gem_init_hw(dev);
mutex_unlock(&dev->struct_mutex);
drm_irq_install(dev);
intel_modeset_init_hw(dev);
drm_modeset_lock_all(dev);
intel_modeset_setup_hw_state(dev, true);
drm_modeset_unlock_all(dev);
intel_hpd_init(dev);
dev_priv->enable_hotplug_processing = true;
intel_resume_hotplug(dev);
}
intel_opregion_init(dev);
if (console_trylock()) {
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING);
console_unlock();
} else {
schedule_work(&dev_priv->console_resume_work);
}
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_DONE;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_runtime_pm_put(dev_priv);
return error;
}
static int i915_drm_thaw(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_MODESET))
i915_check_and_clear_faults(dev);
return __i915_drm_thaw(dev, true);
}
static int i915_resume_early(struct drm_device *dev)
{
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
if (pci_enable_device(dev->pdev))
return -EIO;
pci_set_master(dev->pdev);
return i915_drm_thaw_early(dev);
}
int i915_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = __i915_drm_thaw(dev, !dev_priv->opregion.header);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
static int i915_resume_legacy(struct drm_device *dev)
{
i915_resume_early(dev);
i915_resume(dev);
return 0;
}
int i915_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
bool simulated;
int ret;
if (!i915.reset)
return 0;
mutex_lock(&dev->struct_mutex);
i915_gem_reset(dev);
simulated = dev_priv->gpu_error.stop_rings != 0;
ret = intel_gpu_reset(dev);
if (simulated) {
DRM_INFO("Simulated gpu hang, resetting stop_rings\n");
dev_priv->gpu_error.stop_rings = 0;
if (ret == -ENODEV) {
DRM_INFO("Reset not implemented, but ignoring "
"error for simulated gpu hangs\n");
ret = 0;
}
}
if (ret) {
DRM_ERROR("Failed to reset chip: %i\n", ret);
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_MODESET) ||
!dev_priv->ums.mm_suspended) {
dev_priv->ums.mm_suspended = 0;
ret = i915_gem_init_hw(dev);
mutex_unlock(&dev->struct_mutex);
if (ret) {
DRM_ERROR("Failed hw init on reset %d\n", ret);
return ret;
}
drm_irq_uninstall(dev);
drm_irq_install(dev);
if (INTEL_INFO(dev)->gen > 5) {
mutex_lock(&dev->struct_mutex);
intel_enable_gt_powersave(dev);
mutex_unlock(&dev->struct_mutex);
}
intel_hpd_init(dev);
} else {
mutex_unlock(&dev->struct_mutex);
}
return 0;
}
static int i915_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct intel_device_info *intel_info =
(struct intel_device_info *) ent->driver_data;
if (IS_PRELIMINARY_HW(intel_info) && !i915.preliminary_hw_support) {
DRM_INFO("This hardware requires preliminary hardware support.\n"
"See CONFIG_DRM_I915_PRELIMINARY_HW_SUPPORT, and/or modparam preliminary_hw_support\n");
return -ENODEV;
}
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
driver.driver_features &= ~(DRIVER_USE_AGP);
return drm_get_pci_dev(pdev, ent, &driver);
}
static void
i915_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int i915_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_freeze(drm_dev);
}
static int i915_pm_suspend_late(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int i915_pm_resume_early(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_resume_early(drm_dev);
}
static int i915_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_resume(drm_dev);
}
static int i915_pm_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
return i915_drm_freeze(drm_dev);
}
static int i915_pm_thaw_early(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_thaw_early(drm_dev);
}
static int i915_pm_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_thaw(drm_dev);
}
static int i915_pm_poweroff(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_freeze(drm_dev);
}
static int i915_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(!HAS_RUNTIME_PM(dev));
assert_force_wake_inactive(dev_priv);
DRM_DEBUG_KMS("Suspending device\n");
if (HAS_PC8(dev))
hsw_enable_pc8(dev_priv);
i915_gem_release_all_mmaps(dev_priv);
del_timer_sync(&dev_priv->gpu_error.hangcheck_timer);
dev_priv->pm.suspended = true;
intel_opregion_notify_adapter(dev, PCI_D1);
DRM_DEBUG_KMS("Device suspended\n");
return 0;
}
static int i915_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(!HAS_RUNTIME_PM(dev));
DRM_DEBUG_KMS("Resuming device\n");
intel_opregion_notify_adapter(dev, PCI_D0);
dev_priv->pm.suspended = false;
if (HAS_PC8(dev))
hsw_disable_pc8(dev_priv);
DRM_DEBUG_KMS("Device resumed\n");
return 0;
}
static int __init i915_init(void)
{
driver.num_ioctls = i915_max_ioctl;
#if defined(CONFIG_DRM_I915_KMS)
if (i915.modeset != 0)
driver.driver_features |= DRIVER_MODESET;
#endif
if (i915.modeset == 1)
driver.driver_features |= DRIVER_MODESET;
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && i915.modeset == -1)
driver.driver_features &= ~DRIVER_MODESET;
#endif
if (!(driver.driver_features & DRIVER_MODESET)) {
driver.get_vblank_timestamp = NULL;
#ifndef CONFIG_DRM_I915_UMS
return 0;
#endif
}
return drm_pci_init(&driver, &i915_pci_driver);
}
static void __exit i915_exit(void)
{
#ifndef CONFIG_DRM_I915_UMS
if (!(driver.driver_features & DRIVER_MODESET))
return;
#endif
drm_pci_exit(&driver, &i915_pci_driver);
}
