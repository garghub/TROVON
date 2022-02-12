static inline void unmask_rm9k_irq(struct irq_data *d)
{
set_c0_intcontrol(0x1000 << (d->irq - RM9K_CPU_IRQ_BASE));
}
static inline void mask_rm9k_irq(struct irq_data *d)
{
clear_c0_intcontrol(0x1000 << (d->irq - RM9K_CPU_IRQ_BASE));
}
static inline void rm9k_cpu_irq_enable(struct irq_data *d)
{
unsigned long flags;
local_irq_save(flags);
unmask_rm9k_irq(d);
local_irq_restore(flags);
}
static void local_rm9k_perfcounter_irq_startup(void *args)
{
rm9k_cpu_irq_enable(args);
}
static unsigned int rm9k_perfcounter_irq_startup(struct irq_data *d)
{
on_each_cpu(local_rm9k_perfcounter_irq_startup, d, 1);
return 0;
}
static void local_rm9k_perfcounter_irq_shutdown(void *args)
{
unsigned long flags;
local_irq_save(flags);
mask_rm9k_irq(args);
local_irq_restore(flags);
}
static void rm9k_perfcounter_irq_shutdown(struct irq_data *d)
{
on_each_cpu(local_rm9k_perfcounter_irq_shutdown, d, 1);
}
void __init rm9k_cpu_irq_init(void)
{
int base = RM9K_CPU_IRQ_BASE;
int i;
clear_c0_intcontrol(0x0000f000);
for (i = base; i < base + 4; i++)
irq_set_chip_and_handler(i, &rm9k_irq_controller,
handle_level_irq);
rm9000_perfcount_irq = base + 1;
irq_set_chip_and_handler(rm9000_perfcount_irq, &rm9k_perfcounter_irq,
handle_percpu_irq);
}
