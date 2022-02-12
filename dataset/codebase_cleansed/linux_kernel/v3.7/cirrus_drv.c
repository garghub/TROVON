static void cirrus_kick_out_firmware_fb(struct pci_dev *pdev)
{
struct apertures_struct *ap;
bool primary = false;
ap = alloc_apertures(1);
ap->ranges[0].base = pci_resource_start(pdev, 0);
ap->ranges[0].size = pci_resource_len(pdev, 0);
#ifdef CONFIG_X86
primary = pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
#endif
remove_conflicting_framebuffers(ap, "cirrusdrmfb", primary);
kfree(ap);
}
static int __devinit
cirrus_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
cirrus_kick_out_firmware_fb(pdev);
return drm_get_pci_dev(pdev, ent, &driver);
}
static void cirrus_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int __init cirrus_init(void)
{
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && cirrus_modeset == -1)
return -EINVAL;
#endif
if (cirrus_modeset == 0)
return -EINVAL;
return drm_pci_init(&driver, &cirrus_pci_driver);
}
static void __exit cirrus_exit(void)
{
drm_pci_exit(&driver, &cirrus_pci_driver);
}
