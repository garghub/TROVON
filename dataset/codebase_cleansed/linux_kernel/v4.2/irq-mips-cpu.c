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
asmlinkage void __weak plat_irq_dispatch(void)
{
unsigned long pending = read_c0_cause() & read_c0_status() & ST0_IM;
int irq;
if (!pending) {
spurious_interrupt();
return;
}
pending >>= CAUSEB_IP;
while (pending) {
irq = fls(pending) - 1;
do_IRQ(MIPS_CPU_IRQ_BASE + irq);
pending &= ~BIT(irq);
}
}
static int mips_cpu_intc_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
static struct irq_chip *chip;
if (hw < 2 && cpu_has_mipsmt) {
chip = &mips_mt_cpu_irq_controller;
} else {
chip = &mips_cpu_irq_controller;
}
if (cpu_has_vint)
set_vi_handler(hw, plat_irq_dispatch);
irq_set_chip_and_handler(irq, chip, handle_percpu_irq);
return 0;
}
static void __init __mips_cpu_irq_init(struct device_node *of_node)
{
struct irq_domain *domain;
clear_c0_status(ST0_IM);
clear_c0_cause(CAUSEF_IP);
domain = irq_domain_add_legacy(of_node, 8, MIPS_CPU_IRQ_BASE, 0,
&mips_cpu_intc_irq_domain_ops, NULL);
if (!domain)
panic("Failed to add irqdomain for MIPS CPU");
}
void __init mips_cpu_irq_init(void)
{
__mips_cpu_irq_init(NULL);
}
int __init mips_cpu_irq_of_init(struct device_node *of_node,
struct device_node *parent)
{
__mips_cpu_irq_init(of_node);
return 0;
}
