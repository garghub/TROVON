static void intcs_demux(unsigned int irq, struct irq_desc *desc)
{
void __iomem *reg = (void *)irq_get_handler_data(irq);
unsigned int evtcodeas = ioread32(reg);
generic_handle_irq(intcs_evt2irq(evtcodeas));
}
void __init sh7372_init_irq(void)
{
void __iomem *intevtsa;
intcs_ffd2 = ioremap_nocache(0xffd20000, PAGE_SIZE);
intevtsa = intcs_ffd2 + 0x100;
intcs_ffd5 = ioremap_nocache(0xffd50000, PAGE_SIZE);
register_intc_controller(&intca_desc);
register_intc_controller(&intca_irq_pins_desc);
register_intc_controller(&intcs_desc);
irq_set_handler_data(evt2irq(0xf80), (void *)intevtsa);
irq_set_chained_handler(evt2irq(0xf80), intcs_demux);
}
void sh7372_intcs_suspend(void)
{
int k;
for (k = 0x00; k <= 0x30; k += 4)
ffd2[k] = __raw_readw(intcs_ffd2 + k);
for (k = 0x80; k <= 0xb0; k += 4)
ffd2[k] = __raw_readb(intcs_ffd2 + k);
for (k = 0x180; k <= 0x188; k += 4)
ffd2[k] = __raw_readb(intcs_ffd2 + k);
for (k = 0x00; k <= 0x3c; k += 4)
ffd5[k] = __raw_readw(intcs_ffd5 + k);
for (k = 0x80; k <= 0x9c; k += 4)
ffd5[k] = __raw_readb(intcs_ffd5 + k);
}
void sh7372_intcs_resume(void)
{
int k;
for (k = 0x00; k <= 0x30; k += 4)
__raw_writew(ffd2[k], intcs_ffd2 + k);
for (k = 0x80; k <= 0xb0; k += 4)
__raw_writeb(ffd2[k], intcs_ffd2 + k);
for (k = 0x180; k <= 0x188; k += 4)
__raw_writeb(ffd2[k], intcs_ffd2 + k);
for (k = 0x00; k <= 0x3c; k += 4)
__raw_writew(ffd5[k], intcs_ffd5 + k);
for (k = 0x80; k <= 0x9c; k += 4)
__raw_writeb(ffd5[k], intcs_ffd5 + k);
}
