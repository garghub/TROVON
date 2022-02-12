static void intcs_demux(unsigned int irq, struct irq_desc *desc)
{
void __iomem *reg = (void *)irq_get_handler_data(irq);
unsigned int evtcodeas = ioread32(reg);
generic_handle_irq(intcs_evt2irq(evtcodeas));
}
void __init sh7367_init_irq(void)
{
void __iomem *intevtsa = ioremap_nocache(0xffd20100, PAGE_SIZE);
register_intc_controller(&intca_desc);
register_intc_controller(&intcs_desc);
irq_set_handler_data(evt2irq(0xf80), (void *)intevtsa);
irq_set_chained_handler(evt2irq(0xf80), intcs_demux);
}
