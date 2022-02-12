static irqreturn_t sh73a0_intcs_demux(int irq, void *dev_id)
{
unsigned int evtcodeas = ioread32((void __iomem *)dev_id);
generic_handle_irq(intcs_evt2irq(evtcodeas));
return IRQ_HANDLED;
}
static void pint_demux(void __iomem *rr, void __iomem *er, int base_irq)
{
unsigned long value = ioread32(rr) & ioread32(er);
int k;
for (k = 0; k < 32; k++) {
if (value & (1 << (31 - k))) {
generic_handle_irq(base_irq + k);
iowrite32(~(1 << (31 - k)), rr);
}
}
}
static irqreturn_t sh73a0_pint0_demux(int irq, void *dev_id)
{
pint_demux(PINTRR0, PINTER0_VIRT, SH73A0_PINT0_IRQ(0));
return IRQ_HANDLED;
}
static irqreturn_t sh73a0_pint1_demux(int irq, void *dev_id)
{
pint_demux(PINTRR1, PINTER1_VIRT, SH73A0_PINT1_IRQ(0));
return IRQ_HANDLED;
}
void __init sh73a0_init_irq(void)
{
void __iomem *gic_dist_base = IOMEM(0xf0001000);
void __iomem *gic_cpu_base = IOMEM(0xf0000100);
void __iomem *intevtsa = ioremap_nocache(0xffd20100, PAGE_SIZE);
gic_set_irqchip_flags(IRQCHIP_SKIP_SET_WAKE);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
register_intc_controller(&intcs_desc);
register_intc_controller(&intc_pint0_desc);
register_intc_controller(&intc_pint1_desc);
sh73a0_intcs_cascade.name = "INTCS cascade";
sh73a0_intcs_cascade.handler = sh73a0_intcs_demux;
sh73a0_intcs_cascade.dev_id = intevtsa;
setup_irq(gic_spi(50), &sh73a0_intcs_cascade);
sh73a0_pint0_cascade.name = "PINT0 cascade";
sh73a0_pint0_cascade.handler = sh73a0_pint0_demux;
setup_irq(gic_spi(33), &sh73a0_pint0_cascade);
sh73a0_pint1_cascade.name = "PINT1 cascade";
sh73a0_pint1_cascade.handler = sh73a0_pint1_demux;
setup_irq(gic_spi(34), &sh73a0_pint1_cascade);
}
