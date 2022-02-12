static void mask_irq(struct irq_data *data)
{
__vmintop_locdis((long) data->irq);
}
static void mask_irq_num(unsigned int irq)
{
__vmintop_locdis((long) irq);
}
static void unmask_irq(struct irq_data *data)
{
__vmintop_locen((long) data->irq);
}
static void eoi_irq(struct irq_data *data)
{
__vmintop_globen((long) data->irq);
}
static int set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
void __init init_IRQ(void)
{
int irq;
for (irq = 0; irq < HEXAGON_CPUINTS; irq++) {
mask_irq_num(irq);
irq_set_chip_and_handler(irq, &hexagon_irq_chip,
handle_fasteoi_irq);
}
}
