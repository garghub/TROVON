static int amdgpu_kick_out_firmware_fb(struct pci_dev *pdev)
{
struct apertures_struct *ap;
bool primary = false;
ap = alloc_apertures(1);
if (!ap)
return -ENOMEM;
ap->ranges[0].base = pci_resource_start(pdev, 0);
ap->ranges[0].size = pci_resource_len(pdev, 0);
#ifdef CONFIG_X86
primary = pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
#endif
drm_fb_helper_remove_conflicting_framebuffers(ap, "amdgpudrmfb", primary);
kfree(ap);
return 0;
}
static int amdgpu_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned long flags = ent->driver_data;
int ret;
if ((flags & AMD_EXP_HW_SUPPORT) && !amdgpu_exp_hw_support) {
DRM_INFO("This hardware requires experimental hardware support.\n"
"See modparam exp_hw_support\n");
return -ENODEV;
}
ret = amdgpu_amdkfd_init();
if (ret == -EPROBE_DEFER)
return ret;
ret = amdgpu_kick_out_firmware_fb(pdev);
if (ret)
return ret;
return drm_get_pci_dev(pdev, ent, &kms_driver);
}
static void
amdgpu_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static void
amdgpu_pci_shutdown(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct amdgpu_device *adev = dev->dev_private;
amdgpu_suspend(adev);
}
static int amdgpu_pmops_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return amdgpu_device_suspend(drm_dev, true, true);
}
static int amdgpu_pmops_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (amdgpu_device_is_px(drm_dev)) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
return amdgpu_device_resume(drm_dev, true, true);
}
static int amdgpu_pmops_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return amdgpu_device_suspend(drm_dev, false, true);
}
static int amdgpu_pmops_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return amdgpu_device_resume(drm_dev, false, true);
}
static int amdgpu_pmops_poweroff(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return amdgpu_device_suspend(drm_dev, true, true);
}
static int amdgpu_pmops_restore(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return amdgpu_device_resume(drm_dev, false, true);
}
static int amdgpu_pmops_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int ret;
if (!amdgpu_device_is_px(drm_dev)) {
pm_runtime_forbid(dev);
return -EBUSY;
}
drm_dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
drm_kms_helper_poll_disable(drm_dev);
vga_switcheroo_set_dynamic_switch(pdev, VGA_SWITCHEROO_OFF);
ret = amdgpu_device_suspend(drm_dev, false, false);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_ignore_hotplug(pdev);
if (amdgpu_is_atpx_hybrid())
pci_set_power_state(pdev, PCI_D3cold);
else if (!amdgpu_has_atpx_dgpu_power_cntl())
pci_set_power_state(pdev, PCI_D3hot);
drm_dev->switch_power_state = DRM_SWITCH_POWER_DYNAMIC_OFF;
return 0;
}
static int amdgpu_pmops_runtime_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int ret;
if (!amdgpu_device_is_px(drm_dev))
return -EINVAL;
drm_dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
if (amdgpu_is_atpx_hybrid() ||
!amdgpu_has_atpx_dgpu_power_cntl())
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret)
return ret;
pci_set_master(pdev);
ret = amdgpu_device_resume(drm_dev, false, false);
drm_kms_helper_poll_enable(drm_dev);
vga_switcheroo_set_dynamic_switch(pdev, VGA_SWITCHEROO_ON);
drm_dev->switch_power_state = DRM_SWITCH_POWER_ON;
return 0;
}
static int amdgpu_pmops_runtime_idle(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct drm_crtc *crtc;
if (!amdgpu_device_is_px(drm_dev)) {
pm_runtime_forbid(dev);
return -EBUSY;
}
list_for_each_entry(crtc, &drm_dev->mode_config.crtc_list, head) {
if (crtc->enabled) {
DRM_DEBUG_DRIVER("failing to power off - crtc active\n");
return -EBUSY;
}
}
pm_runtime_mark_last_busy(dev);
pm_runtime_autosuspend(dev);
return 1;
}
long amdgpu_drm_ioctl(struct file *filp,
unsigned int cmd, unsigned long arg)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev;
long ret;
dev = file_priv->minor->dev;
ret = pm_runtime_get_sync(dev->dev);
if (ret < 0)
return ret;
ret = drm_ioctl(filp, cmd, arg);
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
return ret;
}
static int __init amdgpu_init(void)
{
int r;
r = amdgpu_sync_init();
if (r)
goto error_sync;
r = amdgpu_fence_slab_init();
if (r)
goto error_fence;
r = amd_sched_fence_slab_init();
if (r)
goto error_sched;
if (vgacon_text_force()) {
DRM_ERROR("VGACON disables amdgpu kernel modesetting.\n");
return -EINVAL;
}
DRM_INFO("amdgpu kernel modesetting enabled.\n");
driver = &kms_driver;
pdriver = &amdgpu_kms_pci_driver;
driver->num_ioctls = amdgpu_max_kms_ioctl;
amdgpu_register_atpx_handler();
return drm_pci_init(driver, pdriver);
error_sched:
amdgpu_fence_slab_fini();
error_fence:
amdgpu_sync_fini();
error_sync:
return r;
}
static void __exit amdgpu_exit(void)
{
amdgpu_amdkfd_fini();
drm_pci_exit(driver, pdriver);
amdgpu_unregister_atpx_handler();
amdgpu_sync_fini();
amd_sched_fence_slab_fini();
amdgpu_fence_slab_fini();
}
