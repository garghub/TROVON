static inline void unmask_rm7k_irq(struct irq_data *d)
{
set_c0_intcontrol(0x100 << (d->irq - RM7K_CPU_IRQ_BASE));
}
static inline void mask_rm7k_irq(struct irq_data *d)
{
clear_c0_intcontrol(0x100 << (d->irq - RM7K_CPU_IRQ_BASE));
}
void __init rm7k_cpu_irq_init(void)
{
int base = RM7K_CPU_IRQ_BASE;
int i;
clear_c0_intcontrol(0x00000f00);
for (i = base; i < base + 4; i++)
irq_set_chip_and_handler(i, &rm7k_irq_controller,
handle_percpu_irq);
}
