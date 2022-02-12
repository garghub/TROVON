static void intc2_irq_gpio_mask(struct irq_data *d)
{
u32 imr = readl(MCFSIM2_GPIOINTENABLE);
u32 type = irqd_get_trigger_type(d);
int irq = d->irq - MCF_IRQ_GPIO0;
if (type & IRQ_TYPE_EDGE_RISING)
imr &= ~(0x001 << irq);
if (type & IRQ_TYPE_EDGE_FALLING)
imr &= ~(0x100 << irq);
writel(imr, MCFSIM2_GPIOINTENABLE);
}
static void intc2_irq_gpio_unmask(struct irq_data *d)
{
u32 imr = readl(MCFSIM2_GPIOINTENABLE);
u32 type = irqd_get_trigger_type(d);
int irq = d->irq - MCF_IRQ_GPIO0;
if (type & IRQ_TYPE_EDGE_RISING)
imr |= (0x001 << irq);
if (type & IRQ_TYPE_EDGE_FALLING)
imr |= (0x100 << irq);
writel(imr, MCFSIM2_GPIOINTENABLE);
}
static void intc2_irq_gpio_ack(struct irq_data *d)
{
u32 imr = 0;
u32 type = irqd_get_trigger_type(d);
int irq = d->irq - MCF_IRQ_GPIO0;
if (type & IRQ_TYPE_EDGE_RISING)
imr |= (0x001 << irq);
if (type & IRQ_TYPE_EDGE_FALLING)
imr |= (0x100 << irq);
writel(imr, MCFSIM2_GPIOINTCLEAR);
}
static int intc2_irq_gpio_set_type(struct irq_data *d, unsigned int f)
{
if (f & ~IRQ_TYPE_EDGE_BOTH)
return -EINVAL;
return 0;
}
static int __init mcf_intc2_init(void)
{
int irq;
writel(MCFINTC2_VECBASE, MCFINTC2_INTBASE);
for (irq = MCF_IRQ_GPIO0; (irq <= MCF_IRQ_GPIO6); irq++) {
irq_set_chip(irq, &intc2_irq_gpio_chip);
irq_set_handler(irq, handle_edge_irq);
}
return 0;
}
