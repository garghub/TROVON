void __init r8a7740_init_irq(void)
{
void __iomem *gic_dist_base = ioremap_nocache(0xc2800000, 0x1000);
void __iomem *gic_cpu_base = ioremap_nocache(0xc2000000, 0x1000);
void __iomem *intc_prio_base = ioremap_nocache(0xe6900010, 0x10);
void __iomem *intc_msk_base = ioremap_nocache(0xe6900040, 0x10);
void __iomem *pfc_inta_ctrl = ioremap_nocache(0xe605807c, 0x4);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
iowrite32(0x0, pfc_inta_ctrl);
iowrite32(0x0, intc_prio_base + 0x0);
iowrite32(0x0, intc_prio_base + 0x4);
iowrite32(0x0, intc_prio_base + 0x8);
iowrite32(0x0, intc_prio_base + 0xc);
iowrite8(0xff, intc_msk_base + 0x0);
iowrite8(0xff, intc_msk_base + 0x4);
iowrite8(0xff, intc_msk_base + 0x8);
iowrite8(0xff, intc_msk_base + 0xc);
iounmap(intc_prio_base);
iounmap(intc_msk_base);
iounmap(pfc_inta_ctrl);
}
