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
return readw_be(addr);
}
unsigned int ioread32(void __iomem *addr)
{
return readl(addr);
}
unsigned int ioread32be(void __iomem *addr)
{
return readl_be(addr);
}
u64 ioread64(void __iomem *addr)
{
return readq(addr);
}
u64 ioread64be(void __iomem *addr)
{
return readq_be(addr);
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
writew_be(val, addr);
}
void iowrite32(u32 val, void __iomem *addr)
{
writel(val, addr);
}
void iowrite32be(u32 val, void __iomem *addr)
{
writel_be(val, addr);
}
void iowrite64(u64 val, void __iomem *addr)
{
writeq(val, addr);
}
void iowrite64be(u64 val, void __iomem *addr)
{
writeq_be(val, addr);
}
void ioread8_rep(void __iomem *addr, void *dst, unsigned long count)
{
readsb(addr, dst, count);
}
void ioread16_rep(void __iomem *addr, void *dst, unsigned long count)
{
readsw(addr, dst, count);
}
void ioread32_rep(void __iomem *addr, void *dst, unsigned long count)
{
readsl(addr, dst, count);
}
void iowrite8_rep(void __iomem *addr, const void *src, unsigned long count)
{
writesb(addr, src, count);
}
void iowrite16_rep(void __iomem *addr, const void *src, unsigned long count)
{
writesw(addr, src, count);
}
void iowrite32_rep(void __iomem *addr, const void *src, unsigned long count)
{
writesl(addr, src, count);
}
void __iomem *ioport_map(unsigned long port, unsigned int len)
{
return (void __iomem *) (port + _IO_BASE);
}
void ioport_unmap(void __iomem *addr)
{
}
void pci_iounmap(struct pci_dev *dev, void __iomem *addr)
{
if (isa_vaddr_is_ioport(addr))
return;
if (pcibios_vaddr_is_ioport(addr))
return;
iounmap(addr);
}
