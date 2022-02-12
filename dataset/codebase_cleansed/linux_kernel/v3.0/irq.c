static void int1_mask(struct irq_data *d)
{
u32 intmr1;
intmr1 = clps_readl(INTMR1);
intmr1 &= ~(1 << d->irq);
clps_writel(intmr1, INTMR1);
}
static void int1_ack(struct irq_data *d)
{
u32 intmr1;
intmr1 = clps_readl(INTMR1);
intmr1 &= ~(1 << d->irq);
clps_writel(intmr1, INTMR1);
switch (d->irq) {
case IRQ_CSINT: clps_writel(0, COEOI); break;
case IRQ_TC1OI: clps_writel(0, TC1EOI); break;
case IRQ_TC2OI: clps_writel(0, TC2EOI); break;
case IRQ_RTCMI: clps_writel(0, RTCEOI); break;
case IRQ_TINT: clps_writel(0, TEOI); break;
case IRQ_UMSINT: clps_writel(0, UMSEOI); break;
}
}
static void int1_unmask(struct irq_data *d)
{
u32 intmr1;
intmr1 = clps_readl(INTMR1);
intmr1 |= 1 << d->irq;
clps_writel(intmr1, INTMR1);
}
static void int2_mask(struct irq_data *d)
{
u32 intmr2;
intmr2 = clps_readl(INTMR2);
intmr2 &= ~(1 << (d->irq - 16));
clps_writel(intmr2, INTMR2);
}
static void int2_ack(struct irq_data *d)
{
u32 intmr2;
intmr2 = clps_readl(INTMR2);
intmr2 &= ~(1 << (d->irq - 16));
clps_writel(intmr2, INTMR2);
switch (d->irq) {
case IRQ_KBDINT: clps_writel(0, KBDEOI); break;
}
}
static void int2_unmask(struct irq_data *d)
{
u32 intmr2;
intmr2 = clps_readl(INTMR2);
intmr2 |= 1 << (d->irq - 16);
clps_writel(intmr2, INTMR2);
}
void __init clps711x_init_irq(void)
{
unsigned int i;
for (i = 0; i < NR_IRQS; i++) {
if (INT1_IRQS & (1 << i)) {
irq_set_chip_and_handler(i, &int1_chip,
handle_level_irq);
set_irq_flags(i, IRQF_VALID | IRQF_PROBE);
}
if (INT2_IRQS & (1 << i)) {
irq_set_chip_and_handler(i, &int2_chip,
handle_level_irq);
set_irq_flags(i, IRQF_VALID | IRQF_PROBE);
}
}
clps_writel(0, INTMR1);
clps_writel(0, INTMR2);
clps_writel(0, COEOI);
clps_writel(0, TC1EOI);
clps_writel(0, TC2EOI);
clps_writel(0, RTCEOI);
clps_writel(0, TEOI);
clps_writel(0, UMSEOI);
clps_writel(0, SYNCIO);
clps_writel(0, KBDEOI);
}
