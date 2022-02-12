static inline void radeon_register_atpx_handler(void) {}
static inline void radeon_unregister_atpx_handler(void) {}
static int radeon_suspend(struct drm_device *dev, pm_message_t state)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
return 0;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_RS600)
RADEON_WRITE(R500_DxMODE_INT_MASK, 0);
RADEON_WRITE(RADEON_GEN_INT_CNTL, 0);
return 0;
}
static int radeon_resume(struct drm_device *dev)
{
drm_radeon_private_t *dev_priv = dev->dev_private;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_R600)
return 0;
if ((dev_priv->flags & RADEON_FAMILY_MASK) >= CHIP_RS600)
RADEON_WRITE(R500_DxMODE_INT_MASK, dev_priv->r500_disp_irq_reg);
RADEON_WRITE(RADEON_GEN_INT_CNTL, dev_priv->irq_enable_reg);
return 0;
}
static int radeon_kick_out_firmware_fb(struct pci_dev *pdev)
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
remove_conflicting_framebuffers(ap, "radeondrmfb", primary);
kfree(ap);
return 0;
}
static int radeon_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret;
ret = radeon_kick_out_firmware_fb(pdev);
if (ret)
return ret;
return drm_get_pci_dev(pdev, ent, &kms_driver);
}
static void
radeon_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int radeon_pmops_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return radeon_suspend_kms(drm_dev, true, true);
}
static int radeon_pmops_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return radeon_resume_kms(drm_dev, true, true);
}
static int radeon_pmops_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return radeon_suspend_kms(drm_dev, false, true);
}
static int radeon_pmops_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return radeon_resume_kms(drm_dev, false, true);
}
static int radeon_pmops_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int ret;
if (!radeon_is_px(drm_dev)) {
pm_runtime_forbid(dev);
return -EBUSY;
}
drm_dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
drm_kms_helper_poll_disable(drm_dev);
vga_switcheroo_set_dynamic_switch(pdev, VGA_SWITCHEROO_OFF);
ret = radeon_suspend_kms(drm_dev, false, false);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3cold);
drm_dev->switch_power_state = DRM_SWITCH_POWER_DYNAMIC_OFF;
return 0;
}
static int radeon_pmops_runtime_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int ret;
if (!radeon_is_px(drm_dev))
return -EINVAL;
drm_dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret)
return ret;
pci_set_master(pdev);
ret = radeon_resume_kms(drm_dev, false, false);
drm_kms_helper_poll_enable(drm_dev);
vga_switcheroo_set_dynamic_switch(pdev, VGA_SWITCHEROO_ON);
drm_dev->switch_power_state = DRM_SWITCH_POWER_ON;
return 0;
}
static int radeon_pmops_runtime_idle(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct drm_crtc *crtc;
if (!radeon_is_px(drm_dev)) {
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
long radeon_drm_ioctl(struct file *filp,
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
static int __init radeon_init(void)
{
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && radeon_modeset == -1) {
DRM_INFO("VGACON disable radeon kernel modesetting.\n");
radeon_modeset = 0;
}
#endif
if (radeon_modeset == -1)
radeon_modeset = 1;
if (radeon_modeset == 1) {
DRM_INFO("radeon kernel modesetting enabled.\n");
driver = &kms_driver;
pdriver = &radeon_kms_pci_driver;
driver->driver_features |= DRIVER_MODESET;
driver->num_ioctls = radeon_max_kms_ioctl;
radeon_register_atpx_handler();
} else {
#ifdef CONFIG_DRM_RADEON_UMS
DRM_INFO("radeon userspace modesetting enabled.\n");
driver = &driver_old;
pdriver = &radeon_pci_driver;
driver->driver_features &= ~DRIVER_MODESET;
driver->num_ioctls = radeon_max_ioctl;
#else
DRM_ERROR("No UMS support in radeon module!\n");
return -EINVAL;
#endif
}
return drm_pci_init(driver, pdriver);
}
static void __exit radeon_exit(void)
{
drm_pci_exit(driver, pdriver);
radeon_unregister_atpx_handler();
}
