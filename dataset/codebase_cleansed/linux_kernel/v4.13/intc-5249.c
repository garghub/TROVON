static void intc2_irq_gpio_mask(struct irq_data *d)
{
u32 imr;
imr = readl(MCFSIM2_GPIOINTENABLE);
imr &= ~(0x1 << (d->irq - MCF_IRQ_GPIO0));
writel(imr, MCFSIM2_GPIOINTENABLE);
}
static void intc2_irq_gpio_unmask(struct irq_data *d)
{
u32 imr;
imr = readl(MCFSIM2_GPIOINTENABLE);
imr |= (0x1 << (d->irq - MCF_IRQ_GPIO0));
writel(imr, MCFSIM2_GPIOINTENABLE);
}
static void intc2_irq_gpio_ack(struct irq_data *d)
{
writel(0x1 << (d->irq - MCF_IRQ_GPIO0), MCFSIM2_GPIOINTCLEAR);
}
static int __init mcf_intc2_init(void)
{
int irq;
for (irq = MCF_IRQ_GPIO0; (irq <= MCF_IRQ_GPIO7); irq++) {
irq_set_chip(irq, &intc2_irq_gpio_chip);
irq_set_handler(irq, handle_edge_irq);
}
return 0;
}
