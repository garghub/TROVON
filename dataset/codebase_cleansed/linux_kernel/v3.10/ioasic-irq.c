static void unmask_ioasic_irq(struct irq_data *d)
{
u32 simr;
simr = ioasic_read(IO_REG_SIMR);
simr |= (1 << (d->irq - ioasic_irq_base));
ioasic_write(IO_REG_SIMR, simr);
}
static void mask_ioasic_irq(struct irq_data *d)
{
u32 simr;
simr = ioasic_read(IO_REG_SIMR);
simr &= ~(1 << (d->irq - ioasic_irq_base));
ioasic_write(IO_REG_SIMR, simr);
}
static void ack_ioasic_irq(struct irq_data *d)
{
mask_ioasic_irq(d);
fast_iob();
}
void __init init_ioasic_irqs(int base)
{
int i;
ioasic_write(IO_REG_SIMR, 0);
fast_iob();
for (i = base; i < base + IO_INR_DMA; i++)
irq_set_chip_and_handler(i, &ioasic_irq_type,
handle_level_irq);
for (; i < base + IO_IRQ_LINES; i++)
irq_set_chip(i, &ioasic_dma_irq_type);
ioasic_irq_base = base;
}
