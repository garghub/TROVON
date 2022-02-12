int fb_is_primary_device(struct fb_info *info)
{
struct device *device = info->device;
struct pci_dev *pci_dev = NULL;
struct resource *res = NULL;
int retval = 0;
if (device)
pci_dev = to_pci_dev(device);
if (pci_dev)
res = &pci_dev->resource[PCI_ROM_RESOURCE];
if (res && res->flags & IORESOURCE_ROM_SHADOW)
retval = 1;
return retval;
}
