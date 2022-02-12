int r128_driver_load(struct drm_device *dev, unsigned long flags)
{
return drm_vblank_init(dev, 1);
}
static int __init r128_init(void)
{
driver.num_ioctls = r128_max_ioctl;
return drm_pci_init(&driver, &r128_pci_driver);
}
static void __exit r128_exit(void)
{
drm_pci_exit(&driver, &r128_pci_driver);
}
