void __iomem *pci_iomap(struct pci_dev *dev, int bar, unsigned long maxlen)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
unsigned long flags = pci_resource_flags(dev, bar);
if (!len || !start)
return NULL;
if ((flags & IORESOURCE_IO) || (flags & IORESOURCE_MEM))
return (void __iomem *) start;
return NULL;
}
