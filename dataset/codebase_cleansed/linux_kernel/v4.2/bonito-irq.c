static inline void bonito_irq_enable(struct irq_data *d)
{
LOONGSON_INTENSET = (1 << (d->irq - LOONGSON_IRQ_BASE));
mmiowb();
}
static inline void bonito_irq_disable(struct irq_data *d)
{
LOONGSON_INTENCLR = (1 << (d->irq - LOONGSON_IRQ_BASE));
mmiowb();
}
void bonito_irq_init(void)
{
u32 i;
for (i = LOONGSON_IRQ_BASE; i < LOONGSON_IRQ_BASE + 32; i++)
irq_set_chip_and_handler(i, &bonito_irq_type,
handle_level_irq);
#ifdef CONFIG_CPU_LOONGSON2E
setup_irq(LOONGSON_IRQ_BASE + 10, &dma_timeout_irqaction);
#endif
}
