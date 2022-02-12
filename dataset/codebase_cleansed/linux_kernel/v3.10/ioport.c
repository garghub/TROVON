void __iomem *__ioport_map(unsigned long addr, unsigned int size)
{
if (sh_mv.mv_ioport_map)
return sh_mv.mv_ioport_map(addr, size);
return (void __iomem *)(addr + sh_io_port_base);
}
void __iomem *ioport_map(unsigned long port, unsigned int nr)
{
void __iomem *ret;
ret = __ioport_map_trapped(port, nr);
if (ret)
return ret;
return __ioport_map(port, nr);
}
void ioport_unmap(void __iomem *addr)
{
if (sh_mv.mv_ioport_unmap)
sh_mv.mv_ioport_unmap(addr);
}
