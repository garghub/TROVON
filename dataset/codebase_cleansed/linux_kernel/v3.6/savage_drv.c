static int __init savage_init(void)
{
driver.num_ioctls = savage_max_ioctl;
return drm_pci_init(&driver, &savage_pci_driver);
}
static void __exit savage_exit(void)
{
drm_pci_exit(&driver, &savage_pci_driver);
}
