void intel_detect_pch(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pch;
if (INTEL_INFO(dev)->num_pipes == 0) {
dev_priv->pch_type = PCH_NOP;
return;
}
pch = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, NULL);
while (pch) {
struct pci_dev *curr = pch;
if (pch->vendor == PCI_VENDOR_ID_INTEL) {
unsigned short id;
id = pch->device & INTEL_PCH_DEVICE_ID_MASK;
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
DRM_DEBUG_KMS("Found PatherPoint PCH\n");
WARN_ON(!(IS_GEN6(dev) || IS_IVYBRIDGE(dev)));
} else if (id == INTEL_PCH_LPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(IS_ULT(dev));
} else if (id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint LP PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(!IS_ULT(dev));
} else {
goto check_next;
}
pci_dev_put(pch);
break;
}
check_next:
pch = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, curr);
pci_dev_put(curr);
}
if (!pch)
DRM_DEBUG_KMS("No PCH found?\n");
}
bool i915_semaphore_is_enabled(struct drm_device *dev)
{
if (INTEL_INFO(dev)->gen < 6)
return 0;
if (i915_semaphores >= 0)
return i915_semaphores;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return 1;
}
static int i915_drm_freeze(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_SUSPENDED;
mutex_unlock(&dev_priv->modeset_restore_lock);
hsw_disable_package_c8(dev_priv);
intel_set_power_well(dev, true);
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
int error;
mutex_lock(&dev->struct_mutex);
error = i915_gem_idle(dev);
mutex_unlock(&dev->struct_mutex);
if (error) {
dev_err(&dev->pdev->dev,
"GEM idle failed, resume might fail\n");
return error;
}
cancel_delayed_work_sync(&dev_priv->rps.delayed_resume_work);
drm_irq_uninstall(dev);
dev_priv->enable_hotplug_processing = false;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
dev_priv->display.crtc_disable(crtc);
intel_modeset_suspend_hw(dev);
}
i915_gem_suspend_gtt_mappings(dev);
i915_save_state(dev);
intel_opregion_fini(dev);
console_lock();
intel_fbdev_set_suspend(dev, FBINFO_STATE_SUSPENDED);
console_unlock();
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
static int __i915_drm_thaw(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int error = 0;
i915_restore_state(dev);
intel_opregion_setup(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_init_pch_refclk(dev);
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
hsw_enable_package_c8(dev_priv);
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_DONE;
mutex_unlock(&dev_priv->modeset_restore_lock);
return error;
}
static int i915_drm_thaw(struct drm_device *dev)
{
int error = 0;
intel_uncore_sanitize(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
} else if (drm_core_check_feature(dev, DRIVER_MODESET))
i915_check_and_clear_faults(dev);
__i915_drm_thaw(dev);
return error;
}
int i915_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
if (pci_enable_device(dev->pdev))
return -EIO;
pci_set_master(dev->pdev);
intel_uncore_sanitize(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET) &&
!dev_priv->opregion.header) {
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
}
ret = __i915_drm_thaw(dev);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
int i915_reset(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
bool simulated;
int ret;
if (!i915_try_reset)
return 0;
mutex_lock(&dev->struct_mutex);
i915_gem_reset(dev);
simulated = dev_priv->gpu_error.stop_rings != 0;
if (!simulated && get_seconds() - dev_priv->gpu_error.last_reset < 5) {
DRM_ERROR("GPU hanging too fast, declaring wedged!\n");
ret = -ENODEV;
} else {
ret = intel_gpu_reset(dev);
if (simulated) {
DRM_INFO("Simulated gpu hang, resetting stop_rings\n");
dev_priv->gpu_error.stop_rings = 0;
if (ret == -ENODEV) {
DRM_ERROR("Reset not implemented, but ignoring "
"error for simulated gpu hangs\n");
ret = 0;
}
} else
dev_priv->gpu_error.last_reset = get_seconds();
}
if (ret) {
DRM_ERROR("Failed to reset chip.\n");
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_MODESET) ||
!dev_priv->ums.mm_suspended) {
struct intel_ring_buffer *ring;
int i;
dev_priv->ums.mm_suspended = 0;
i915_gem_init_swizzling(dev);
for_each_ring(ring, dev_priv, i)
ring->init(ring);
i915_gem_context_init(dev);
if (dev_priv->mm.aliasing_ppgtt) {
ret = dev_priv->mm.aliasing_ppgtt->enable(dev);
if (ret)
i915_gem_cleanup_aliasing_ppgtt(dev);
}
mutex_unlock(&dev->struct_mutex);
drm_irq_uninstall(dev);
drm_irq_install(dev);
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
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
if (intel_info->gen != 3) {
driver.driver_features &=
~(DRIVER_USE_AGP | DRIVER_REQUIRE_AGP);
} else if (!intel_agp_enabled) {
DRM_ERROR("drm/i915 can't work without intel_agp module!\n");
return -ENODEV;
}
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
int error;
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
error = i915_drm_freeze(drm_dev);
if (error)
return error;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
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
static int __init i915_init(void)
{
driver.num_ioctls = i915_max_ioctl;
#if defined(CONFIG_DRM_I915_KMS)
if (i915_modeset != 0)
driver.driver_features |= DRIVER_MODESET;
#endif
if (i915_modeset == 1)
driver.driver_features |= DRIVER_MODESET;
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && i915_modeset == -1)
driver.driver_features &= ~DRIVER_MODESET;
#endif
if (!(driver.driver_features & DRIVER_MODESET))
driver.get_vblank_timestamp = NULL;
return drm_pci_init(&driver, &i915_pci_driver);
}
static void __exit i915_exit(void)
{
drm_pci_exit(&driver, &i915_pci_driver);
}
