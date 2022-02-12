static void icu_mask_irq(struct irq_data *d)
{
__raw_writel(PRIORITY_NONE, ICU_INT_CONF(d->irq));
}
static void icu_unmask_irq(struct irq_data *d)
{
__raw_writel(IRQ_ROUTE_TO_AP | PRIORITY_DEFAULT, ICU_INT_CONF(d->irq));
}
void __init icu_init_irq(void)
{
int irq;
for (irq = 0; irq < 64; irq++) {
icu_mask_irq(irq_get_irq_data(irq));
irq_set_chip_and_handler(irq, &icu_irq_chip, handle_level_irq);
set_irq_flags(irq, IRQF_VALID);
}
}
