static int __init mga_init(void)
{
driver.num_ioctls = mga_max_ioctl;
return drm_pci_init(&driver, &mga_pci_driver);
}
static void __exit mga_exit(void)
{
drm_pci_exit(&driver, &mga_pci_driver);
}
static int mga_driver_device_is_agp(struct drm_device *dev)
{
const struct pci_dev *const pdev = dev->pdev;
if ((pdev->device == 0x0525) && pdev->bus->self
&& (pdev->bus->self->vendor == 0x3388)
&& (pdev->bus->self->device == 0x0021)) {
return 0;
}
return 2;
}
