void __iomem *
__ioremap(unsigned long phys_addr, unsigned long size, unsigned long flags)
{
return (void *)phys_addr;
}
void iounmap(volatile void __iomem *addr)
{
}
