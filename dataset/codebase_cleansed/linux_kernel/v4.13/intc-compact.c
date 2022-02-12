void arc_init_IRQ(void)
{
unsigned int level_mask = 0, i;
level_mask |= IS_ENABLED(CONFIG_ARC_COMPACT_IRQ_LEVELS) << TIMER0_IRQ;
write_aux_reg(AUX_IRQ_LEV, level_mask);
if (level_mask)
pr_info("Level-2 interrupts bitset %x\n", level_mask);
for (i = TIMER0_IRQ; i < NR_CPU_IRQS; i++) {
unsigned int ienb;
ienb = read_aux_reg(AUX_IENABLE);
ienb &= ~(1 << i);
write_aux_reg(AUX_IENABLE, ienb);
}
}
static void arc_irq_mask(struct irq_data *data)
{
unsigned int ienb;
ienb = read_aux_reg(AUX_IENABLE);
ienb &= ~(1 << data->hwirq);
write_aux_reg(AUX_IENABLE, ienb);
}
static void arc_irq_unmask(struct irq_data *data)
{
unsigned int ienb;
ienb = read_aux_reg(AUX_IENABLE);
ienb |= (1 << data->hwirq);
write_aux_reg(AUX_IENABLE, ienb);
}
static int arc_intc_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
switch (hw) {
case TIMER0_IRQ:
irq_set_percpu_devid(irq);
irq_set_chip_and_handler(irq, &onchip_intc, handle_percpu_irq);
break;
default:
irq_set_chip_and_handler(irq, &onchip_intc, handle_level_irq);
}
return 0;
}
static int __init
init_onchip_IRQ(struct device_node *intc, struct device_node *parent)
{
struct irq_domain *root_domain;
if (parent)
panic("DeviceTree incore intc not a root irq controller\n");
root_domain = irq_domain_add_linear(intc, NR_CPU_IRQS,
&arc_intc_domain_ops, NULL);
if (!root_domain)
panic("root irq domain not avail\n");
irq_set_default_host(root_domain);
return 0;
}
void arch_local_irq_enable(void)
{
unsigned long flags = arch_local_save_flags();
if (flags & STATUS_A2_MASK)
flags |= STATUS_E2_MASK;
else if (flags & STATUS_A1_MASK)
flags |= STATUS_E1_MASK;
arch_local_irq_restore(flags);
}
