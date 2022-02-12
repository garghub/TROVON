void arc_init_IRQ(void)
{
int level_mask = 0;
level_mask |= IS_ENABLED(CONFIG_ARC_IRQ3_LV2) << 3;
level_mask |= IS_ENABLED(CONFIG_ARC_IRQ5_LV2) << 5;
level_mask |= IS_ENABLED(CONFIG_ARC_IRQ6_LV2) << 6;
write_aux_reg(AUX_IRQ_LEV, level_mask);
if (level_mask)
pr_info("Level-2 interrupts bitset %x\n", level_mask);
}
static void arc_irq_mask(struct irq_data *data)
{
unsigned int ienb;
ienb = read_aux_reg(AUX_IENABLE);
ienb &= ~(1 << data->irq);
write_aux_reg(AUX_IENABLE, ienb);
}
static void arc_irq_unmask(struct irq_data *data)
{
unsigned int ienb;
ienb = read_aux_reg(AUX_IENABLE);
ienb |= (1 << data->irq);
write_aux_reg(AUX_IENABLE, ienb);
}
static int arc_intc_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (irq == TIMER0_IRQ)
irq_set_chip_and_handler(irq, &onchip_intc, handle_percpu_irq);
else
irq_set_chip_and_handler(irq, &onchip_intc, handle_level_irq);
return 0;
}
static int __init
init_onchip_IRQ(struct device_node *intc, struct device_node *parent)
{
if (parent)
panic("DeviceTree incore intc not a root irq controller\n");
root_domain = irq_domain_add_legacy(intc, NR_CPU_IRQS, 0, 0,
&arc_intc_domain_ops, NULL);
if (!root_domain)
panic("root irq domain not avail\n");
irq_set_default_host(root_domain);
return 0;
}
void arch_local_irq_enable(void)
{
unsigned long flags = arch_local_save_flags();
flags |= (STATUS_E1_MASK | STATUS_E2_MASK);
if (in_irq()) {
if (flags & STATUS_A2_MASK)
flags &= ~(STATUS_E1_MASK | STATUS_E2_MASK);
else if (flags & STATUS_A1_MASK)
flags &= ~(STATUS_E1_MASK);
}
else if (in_softirq()) {
struct pt_regs *pt = get_irq_regs();
if ((flags & STATUS_A2_MASK) && pt &&
(pt->status32 & STATUS_A1_MASK)) {
flags &= ~(STATUS_E1_MASK);
}
}
arch_local_irq_restore(flags);
}
void arch_local_irq_enable(void)
{
unsigned long flags;
if (in_irq()) {
WARN_ONCE(1, "IRQ enabled from hard-isr");
return;
}
flags = arch_local_save_flags();
flags |= (STATUS_E1_MASK | STATUS_E2_MASK);
arch_local_irq_restore(flags);
}
