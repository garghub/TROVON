static void mgag200_kick_out_firmware_fb(struct pci_dev *pdev)
{
struct apertures_struct *ap;
bool primary = false;
ap = alloc_apertures(1);
if (!ap)
return;
ap->ranges[0].base = pci_resource_start(pdev, 0);
ap->ranges[0].size = pci_resource_len(pdev, 0);
#ifdef CONFIG_X86
primary = pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
#endif
drm_fb_helper_remove_conflicting_framebuffers(ap, "mgag200drmfb", primary);
kfree(ap);
}
static int mga_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
mgag200_kick_out_firmware_fb(pdev);
return drm_get_pci_dev(pdev, ent, &driver);
}
static void mga_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int __init mgag200_init(void)
{
if (vgacon_text_force() && mgag200_modeset == -1)
return -EINVAL;
if (mgag200_modeset == 0)
return -EINVAL;
return drm_pci_init(&driver, &mgag200_pci_driver);
}
static void __exit mgag200_exit(void)
{
drm_pci_exit(&driver, &mgag200_pci_driver);
}
