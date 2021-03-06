static void __iomem *__iop13xx_ioremap_caller(unsigned long cookie,
size_t size, unsigned int mtype, void *caller)
{
void __iomem * retval;
switch (cookie) {
case IOP13XX_PCIX_LOWER_MEM_RA ... IOP13XX_PCIX_UPPER_MEM_RA:
if (unlikely(!iop13xx_atux_mem_base))
retval = NULL;
else
retval = (iop13xx_atux_mem_base +
(cookie - IOP13XX_PCIX_LOWER_MEM_RA));
break;
case IOP13XX_PCIE_LOWER_MEM_RA ... IOP13XX_PCIE_UPPER_MEM_RA:
if (unlikely(!iop13xx_atue_mem_base))
retval = NULL;
else
retval = (iop13xx_atue_mem_base +
(cookie - IOP13XX_PCIE_LOWER_MEM_RA));
break;
case IOP13XX_PBI_LOWER_MEM_RA ... IOP13XX_PBI_UPPER_MEM_RA:
retval = __arm_ioremap_caller(IOP13XX_PBI_LOWER_MEM_PA +
(cookie - IOP13XX_PBI_LOWER_MEM_RA),
size, mtype, __builtin_return_address(0));
break;
case IOP13XX_PMMR_PHYS_MEM_BASE ... IOP13XX_PMMR_UPPER_MEM_PA:
retval = IOP13XX_PMMR_PHYS_TO_VIRT(cookie);
break;
default:
retval = __arm_ioremap_caller(cookie, size, mtype,
caller);
}
return retval;
}
static void __iop13xx_iounmap(volatile void __iomem *addr)
{
if (iop13xx_atue_mem_base)
if (addr >= (void __iomem *) iop13xx_atue_mem_base &&
addr < (void __iomem *) (iop13xx_atue_mem_base +
iop13xx_atue_mem_size))
goto skip;
if (iop13xx_atux_mem_base)
if (addr >= (void __iomem *) iop13xx_atux_mem_base &&
addr < (void __iomem *) (iop13xx_atux_mem_base +
iop13xx_atux_mem_size))
goto skip;
switch ((u32) addr) {
case (u32)IOP13XX_PMMR_VIRT_MEM_BASE ... (u32)IOP13XX_PMMR_UPPER_MEM_VA:
goto skip;
}
__iounmap(addr);
skip:
return;
}
void __init iop13xx_init_early(void)
{
arch_ioremap_caller = __iop13xx_ioremap_caller;
arch_iounmap = __iop13xx_iounmap;
}
