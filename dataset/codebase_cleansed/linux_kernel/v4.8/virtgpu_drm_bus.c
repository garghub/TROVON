static void virtio_pci_kick_out_firmware_fb(struct pci_dev *pci_dev)
{
struct apertures_struct *ap;
bool primary;
ap = alloc_apertures(1);
if (!ap)
return;
ap->ranges[0].base = pci_resource_start(pci_dev, 0);
ap->ranges[0].size = pci_resource_len(pci_dev, 0);
primary = pci_dev->resource[PCI_ROM_RESOURCE].flags
& IORESOURCE_ROM_SHADOW;
remove_conflicting_framebuffers(ap, "virtiodrmfb", primary);
kfree(ap);
}
int drm_virtio_init(struct drm_driver *driver, struct virtio_device *vdev)
{
struct drm_device *dev;
int ret;
dev = drm_dev_alloc(driver, &vdev->dev);
if (!dev)
return -ENOMEM;
dev->virtdev = vdev;
vdev->priv = dev;
if (strcmp(vdev->dev.parent->bus->name, "pci") == 0) {
struct pci_dev *pdev = to_pci_dev(vdev->dev.parent);
bool vga = (pdev->class >> 8) == PCI_CLASS_DISPLAY_VGA;
DRM_INFO("pci: %s detected\n",
vga ? "virtio-vga" : "virtio-gpu-pci");
dev->pdev = pdev;
if (vga)
virtio_pci_kick_out_firmware_fb(pdev);
}
ret = drm_dev_register(dev, 0);
if (ret)
goto err_free;
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n", driver->name,
driver->major, driver->minor, driver->patchlevel,
driver->date, dev->primary->index);
return 0;
err_free:
drm_dev_unref(dev);
return ret;
}
