static int
qxl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
if (pdev->revision < 4) {
DRM_ERROR("qxl too old, doesn't support client_monitors_config,"
" use xf86-video-qxl in user mode");
return -EINVAL;
}
return drm_get_pci_dev(pdev, ent, &qxl_driver);
}
static void
qxl_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int __init qxl_init(void)
{
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && qxl_modeset == -1)
return -EINVAL;
#endif
if (qxl_modeset == 0)
return -EINVAL;
qxl_driver.num_ioctls = qxl_max_ioctls;
return drm_pci_init(&qxl_driver, &qxl_pci_driver);
}
static void __exit qxl_exit(void)
{
drm_pci_exit(&qxl_driver, &qxl_pci_driver);
}
