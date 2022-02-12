unsigned int ioread8(void __iomem *addr)
{
return readb(addr);
}
unsigned int ioread16(void __iomem *addr)
{
return readw(addr);
}
unsigned int ioread16be(void __iomem *addr)
{
return in_be16(addr);
}
unsigned int ioread32(void __iomem *addr)
{
return readl(addr);
}
unsigned int ioread32be(void __iomem *addr)
{
return in_be32(addr);
}
void iowrite8(u8 val, void __iomem *addr)
{
writeb(val, addr);
}
void iowrite16(u16 val, void __iomem *addr)
{
writew(val, addr);
}
void iowrite16be(u16 val, void __iomem *addr)
{
out_be16(addr, val);
}
void iowrite32(u32 val, void __iomem *addr)
{
writel(val, addr);
}
void iowrite32be(u32 val, void __iomem *addr)
{
out_be32(addr, val);
}
void ioread8_rep(void __iomem *addr, void *dst, unsigned long count)
{
_insb((u8 __iomem *) addr, dst, count);
}
void ioread16_rep(void __iomem *addr, void *dst, unsigned long count)
{
_insw_ns((u16 __iomem *) addr, dst, count);
}
void ioread32_rep(void __iomem *addr, void *dst, unsigned long count)
{
_insl_ns((u32 __iomem *) addr, dst, count);
}
void iowrite8_rep(void __iomem *addr, const void *src, unsigned long count)
{
_outsb((u8 __iomem *) addr, src, count);
}
void iowrite16_rep(void __iomem *addr, const void *src, unsigned long count)
{
_outsw_ns((u16 __iomem *) addr, src, count);
}
void iowrite32_rep(void __iomem *addr, const void *src, unsigned long count)
{
_outsl_ns((u32 __iomem *) addr, src, count);
}
void __iomem *ioport_map(unsigned long port, unsigned int len)
{
return (void __iomem *) (port + _IO_BASE);
}
void ioport_unmap(void __iomem *addr)
{
}
void __iomem *pci_iomap(struct pci_dev *dev, int bar, unsigned long max)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
unsigned long flags = pci_resource_flags(dev, bar);
if (!len)
return NULL;
if (max && len > max)
len = max;
if (flags & IORESOURCE_IO)
return ioport_map(start, len);
if (flags & IORESOURCE_MEM)
return ioremap(start, len);
return NULL;
}
void pci_iounmap(struct pci_dev *dev, void __iomem *addr)
{
if (isa_vaddr_is_ioport(addr))
return;
if (pcibios_vaddr_is_ioport(addr))
return;
iounmap(addr);
}
