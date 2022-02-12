static void __init r8a7740_meram_workaround(void)
{
void __iomem *reg;
reg = ioremap_nocache(MEBUFCNTR, 4);
if (reg) {
iowrite32(0x01600164, reg);
iounmap(reg);
}
}
static void __init r8a7740_init_irq_of(void)
{
void __iomem *intc_prio_base = ioremap_nocache(0xe6900010, 0x10);
void __iomem *intc_msk_base = ioremap_nocache(0xe6900040, 0x10);
void __iomem *pfc_inta_ctrl = ioremap_nocache(0xe605807c, 0x4);
irqchip_init();
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
static void __init r8a7740_generic_init(void)
{
r8a7740_meram_workaround();
}
