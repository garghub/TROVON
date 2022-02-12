static irqreturn_t sh73a0_intcs_demux(int irq, void *dev_id)
{
unsigned int evtcodeas = ioread32((void __iomem *)dev_id);
generic_handle_irq(intcs_evt2irq(evtcodeas));
return IRQ_HANDLED;
}
static int sh73a0_set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
void __init sh73a0_init_irq(void)
{
void __iomem *gic_dist_base = __io(0xf0001000);
void __iomem *gic_cpu_base = __io(0xf0000100);
void __iomem *intevtsa = ioremap_nocache(0xffd20100, PAGE_SIZE);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
gic_arch_extn.irq_set_wake = sh73a0_set_wake;
register_intc_controller(&intcs_desc);
sh73a0_intcs_cascade.name = "INTCS cascade";
sh73a0_intcs_cascade.handler = sh73a0_intcs_demux;
sh73a0_intcs_cascade.dev_id = intevtsa;
setup_irq(gic_spi(50), &sh73a0_intcs_cascade);
}
