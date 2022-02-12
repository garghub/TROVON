static inline void unmask_mips_irq(struct irq_data *d)
{
set_c0_status(0x100 << (d->irq - MIPS_CPU_IRQ_BASE));
irq_enable_hazard();
}
static inline void mask_mips_irq(struct irq_data *d)
{
clear_c0_status(0x100 << (d->irq - MIPS_CPU_IRQ_BASE));
irq_disable_hazard();
}
static unsigned int mips_mt_cpu_irq_startup(struct irq_data *d)
{
unsigned int vpflags = dvpe();
clear_c0_cause(0x100 << (d->irq - MIPS_CPU_IRQ_BASE));
evpe(vpflags);
unmask_mips_irq(d);
return 0;
}
static void mips_mt_cpu_irq_ack(struct irq_data *d)
{
unsigned int vpflags = dvpe();
clear_c0_cause(0x100 << (d->irq - MIPS_CPU_IRQ_BASE));
evpe(vpflags);
mask_mips_irq(d);
}
void __init mips_cpu_irq_init(void)
{
int irq_base = MIPS_CPU_IRQ_BASE;
int i;
clear_c0_status(ST0_IM);
clear_c0_cause(CAUSEF_IP);
if (cpu_has_mipsmt)
for (i = irq_base; i < irq_base + 2; i++)
irq_set_chip_and_handler(i, &mips_mt_cpu_irq_controller,
handle_percpu_irq);
for (i = irq_base + 2; i < irq_base + 8; i++)
irq_set_chip_and_handler(i, &mips_cpu_irq_controller,
handle_percpu_irq);
}
