static int cirrus_kick_out_firmware_fb(struct pci_dev *pdev)
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
drm_fb_helper_remove_conflicting_framebuffers(ap, "cirrusdrmfb", primary);
kfree(ap);
return 0;
}
static int cirrus_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret;
ret = cirrus_kick_out_firmware_fb(pdev);
if (ret)
return ret;
return drm_get_pci_dev(pdev, ent, &driver);
}
static void cirrus_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int cirrus_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct cirrus_device *cdev = drm_dev->dev_private;
drm_kms_helper_poll_disable(drm_dev);
if (cdev->mode_info.gfbdev) {
console_lock();
drm_fb_helper_set_suspend(&cdev->mode_info.gfbdev->helper, 1);
console_unlock();
}
return 0;
}
static int cirrus_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct cirrus_device *cdev = drm_dev->dev_private;
drm_helper_resume_force_mode(drm_dev);
if (cdev->mode_info.gfbdev) {
console_lock();
drm_fb_helper_set_suspend(&cdev->mode_info.gfbdev->helper, 0);
console_unlock();
}
drm_kms_helper_poll_enable(drm_dev);
return 0;
}
static int __init cirrus_init(void)
{
if (vgacon_text_force() && cirrus_modeset == -1)
return -EINVAL;
if (cirrus_modeset == 0)
return -EINVAL;
return pci_register_driver(&cirrus_pci_driver);
}
static void __exit cirrus_exit(void)
{
pci_unregister_driver(&cirrus_pci_driver);
}
