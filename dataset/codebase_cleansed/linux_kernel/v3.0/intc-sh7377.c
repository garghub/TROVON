static void intcs_demux(unsigned int irq, struct irq_desc *desc)
{
void __iomem *reg = (void *)irq_get_handler_data(irq);
unsigned int evtcodeas = ioread32(reg);
generic_handle_irq(intcs_evt2irq(evtcodeas));
}
void __init sh7377_init_irq(void)
{
void __iomem *intevtsa = ioremap_nocache(INTEVTSA, PAGE_SIZE);
register_intc_controller(&intca_desc);
register_intc_controller(&intcs_desc);
irq_set_handler_data(evt2irq(INTCS_INTVECT), (void *)intevtsa);
irq_set_chained_handler(evt2irq(INTCS_INTVECT), intcs_demux);
}
