void __iomem *pci_iomap(struct pci_dev *dev, int bar, unsigned long maxlen)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
unsigned long flags = pci_resource_flags(dev, bar);
if (!len || !start)
return NULL;
if ((flags & IORESOURCE_IO) || (flags & IORESOURCE_MEM)) {
if (flags & IORESOURCE_CACHEABLE && !(flags & IORESOURCE_IO))
return ioremap(start, len);
else
return ioremap_nocache(start, len);
}
return NULL;
}
