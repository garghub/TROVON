void __iomem *pci_iomap_range(struct pci_dev *dev,
int bar,
unsigned long offset,
unsigned long maxlen)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
unsigned long flags = pci_resource_flags(dev, bar);
if (len <= offset || !start)
return NULL;
len -= offset;
start += offset;
if (maxlen && len > maxlen)
len = maxlen;
if (flags & IORESOURCE_IO)
return __pci_ioport_map(dev, start, len);
if (flags & IORESOURCE_MEM)
return ioremap(start, len);
return NULL;
}
void __iomem *pci_iomap_wc_range(struct pci_dev *dev,
int bar,
unsigned long offset,
unsigned long maxlen)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
unsigned long flags = pci_resource_flags(dev, bar);
if (flags & IORESOURCE_IO)
return NULL;
if (len <= offset || !start)
return NULL;
len -= offset;
start += offset;
if (maxlen && len > maxlen)
len = maxlen;
if (flags & IORESOURCE_MEM)
return ioremap_wc(start, len);
return NULL;
}
void __iomem *pci_iomap(struct pci_dev *dev, int bar, unsigned long maxlen)
{
return pci_iomap_range(dev, bar, 0, maxlen);
}
void __iomem *pci_iomap_wc(struct pci_dev *dev, int bar, unsigned long maxlen)
{
return pci_iomap_wc_range(dev, bar, 0, maxlen);
}
