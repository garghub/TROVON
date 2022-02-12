static void intcs_demux(unsigned int irq, struct irq_desc *desc)
{
void __iomem *reg = (void *)irq_get_handler_data(irq);
unsigned int evtcodeas = ioread32(reg);
generic_handle_irq(intcs_evt2irq(evtcodeas));
}
void __init sh7372_init_irq(void)
{
void __iomem *intevtsa;
int n;
intcs_ffd2 = ioremap_nocache(0xffd20000, PAGE_SIZE);
intevtsa = intcs_ffd2 + 0x100;
intcs_ffd5 = ioremap_nocache(0xffd50000, PAGE_SIZE);
register_intc_controller(&intca_desc);
register_intc_controller(&intca_irq_pins_lo_desc);
register_intc_controller(&intca_irq_pins_hi_desc);
register_intc_controller(&intcs_desc);
n = evt2irq(0xf80);
irq_alloc_desc_at(n, numa_node_id());
irq_set_chip_and_handler_name(n, &dummy_irq_chip,
handle_level_irq, "level");
set_irq_flags(n, IRQF_VALID);
irq_set_handler_data(n, (void *)intevtsa);
irq_set_chained_handler(n, intcs_demux);
iowrite16(0, intcs_ffd2 + 0x104);
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
void sh7372_intca_suspend(void)
{
int k;
for (k = 0x00; k <= 0x38; k += 4)
e694[k] = __raw_readw(E694_BASE + k);
for (k = 0x80; k <= 0xb4; k += 4)
e694[k] = __raw_readb(E694_BASE + k);
for (k = 0x180; k <= 0x1b4; k += 4)
e694[k] = __raw_readb(E694_BASE + k);
for (k = 0x00; k <= 0x50; k += 4)
e695[k] = __raw_readw(E695_BASE + k);
for (k = 0x80; k <= 0xa8; k += 4)
e695[k] = __raw_readb(E695_BASE + k);
for (k = 0x180; k <= 0x1a8; k += 4)
e695[k] = __raw_readb(E695_BASE + k);
}
void sh7372_intca_resume(void)
{
int k;
for (k = 0x00; k <= 0x38; k += 4)
__raw_writew(e694[k], E694_BASE + k);
for (k = 0x80; k <= 0xb4; k += 4)
__raw_writeb(e694[k], E694_BASE + k);
for (k = 0x180; k <= 0x1b4; k += 4)
__raw_writeb(e694[k], E694_BASE + k);
for (k = 0x00; k <= 0x50; k += 4)
__raw_writew(e695[k], E695_BASE + k);
for (k = 0x80; k <= 0xa8; k += 4)
__raw_writeb(e695[k], E695_BASE + k);
for (k = 0x180; k <= 0x1a8; k += 4)
__raw_writeb(e695[k], E695_BASE + k);
}
