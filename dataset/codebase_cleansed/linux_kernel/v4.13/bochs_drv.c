static void bochs_unload(struct drm_device *dev)
{
struct bochs_device *bochs = dev->dev_private;
bochs_fbdev_fini(bochs);
bochs_kms_fini(bochs);
bochs_mm_fini(bochs);
bochs_hw_fini(dev);
kfree(bochs);
dev->dev_private = NULL;
}
static int bochs_load(struct drm_device *dev, unsigned long flags)
{
struct bochs_device *bochs;
int ret;
bochs = kzalloc(sizeof(*bochs), GFP_KERNEL);
if (bochs == NULL)
return -ENOMEM;
dev->dev_private = bochs;
bochs->dev = dev;
ret = bochs_hw_init(dev, flags);
if (ret)
goto err;
ret = bochs_mm_init(bochs);
if (ret)
goto err;
ret = bochs_kms_init(bochs);
if (ret)
goto err;
if (enable_fbdev)
bochs_fbdev_init(bochs);
return 0;
err:
bochs_unload(dev);
return ret;
}
static int bochs_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct bochs_device *bochs = drm_dev->dev_private;
drm_kms_helper_poll_disable(drm_dev);
if (bochs->fb.initialized) {
console_lock();
drm_fb_helper_set_suspend(&bochs->fb.helper, 1);
console_unlock();
}
return 0;
}
static int bochs_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct bochs_device *bochs = drm_dev->dev_private;
drm_helper_resume_force_mode(drm_dev);
if (bochs->fb.initialized) {
console_lock();
drm_fb_helper_set_suspend(&bochs->fb.helper, 0);
console_unlock();
}
drm_kms_helper_poll_enable(drm_dev);
return 0;
}
static int bochs_kick_out_firmware_fb(struct pci_dev *pdev)
{
struct apertures_struct *ap;
ap = alloc_apertures(1);
if (!ap)
return -ENOMEM;
ap->ranges[0].base = pci_resource_start(pdev, 0);
ap->ranges[0].size = pci_resource_len(pdev, 0);
drm_fb_helper_remove_conflicting_framebuffers(ap, "bochsdrmfb", false);
kfree(ap);
return 0;
}
static int bochs_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned long fbsize;
int ret;
fbsize = pci_resource_len(pdev, 0);
if (fbsize < 4 * 1024 * 1024) {
DRM_ERROR("less than 4 MB video memory, ignoring device\n");
return -ENOMEM;
}
ret = bochs_kick_out_firmware_fb(pdev);
if (ret)
return ret;
return drm_get_pci_dev(pdev, ent, &bochs_driver);
}
static void bochs_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int __init bochs_init(void)
{
if (vgacon_text_force() && bochs_modeset == -1)
return -EINVAL;
if (bochs_modeset == 0)
return -EINVAL;
return drm_pci_init(&bochs_driver, &bochs_pci_driver);
}
static void __exit bochs_exit(void)
{
drm_pci_exit(&bochs_driver, &bochs_pci_driver);
}
