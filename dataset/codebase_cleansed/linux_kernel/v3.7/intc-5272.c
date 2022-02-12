static void intc_irq_mask(struct irq_data *d)
{
unsigned int irq = d->irq;
if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
u32 v;
irq -= MCFINT_VECBASE;
v = 0x8 << intc_irqmap[irq].index;
writel(v, intc_irqmap[irq].icr);
}
}
static void intc_irq_unmask(struct irq_data *d)
{
unsigned int irq = d->irq;
if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
u32 v;
irq -= MCFINT_VECBASE;
v = 0xd << intc_irqmap[irq].index;
writel(v, intc_irqmap[irq].icr);
}
}
static void intc_irq_ack(struct irq_data *d)
{
unsigned int irq = d->irq;
if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
irq -= MCFINT_VECBASE;
if (intc_irqmap[irq].ack) {
u32 v;
v = readl(intc_irqmap[irq].icr);
v &= (0x7 << intc_irqmap[irq].index);
v |= (0x8 << intc_irqmap[irq].index);
writel(v, intc_irqmap[irq].icr);
}
}
}
static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = d->irq;
if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
irq -= MCFINT_VECBASE;
if (intc_irqmap[irq].ack) {
u32 v;
v = readl(MCFSIM_PITR);
if (type == IRQ_TYPE_EDGE_FALLING)
v &= ~(0x1 << (32 - irq));
else
v |= (0x1 << (32 - irq));
writel(v, MCFSIM_PITR);
}
}
return 0;
}
static void intc_external_irq(unsigned int irq, struct irq_desc *desc)
{
irq_desc_get_chip(desc)->irq_ack(&desc->irq_data);
handle_simple_irq(irq, desc);
}
void __init init_IRQ(void)
{
int irq, edge;
writel(0x88888888, MCFSIM_ICR1);
writel(0x88888888, MCFSIM_ICR2);
writel(0x88888888, MCFSIM_ICR3);
writel(0x88888888, MCFSIM_ICR4);
for (irq = 0; (irq < NR_IRQS); irq++) {
irq_set_chip(irq, &intc_irq_chip);
edge = 0;
if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX))
edge = intc_irqmap[irq - MCFINT_VECBASE].ack;
if (edge) {
irq_set_irq_type(irq, IRQ_TYPE_EDGE_RISING);
irq_set_handler(irq, intc_external_irq);
} else {
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
irq_set_handler(irq, handle_level_irq);
}
}
}
