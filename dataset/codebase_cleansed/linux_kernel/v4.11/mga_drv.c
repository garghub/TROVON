static int __init mga_init(void)
{
driver.num_ioctls = mga_max_ioctl;
return drm_pci_init(&driver, &mga_pci_driver);
}
static void __exit mga_exit(void)
{
drm_pci_exit(&driver, &mga_pci_driver);
}
