static void armada_370_xp_irq_mask(struct irq_data *d)
{
writel(irqd_to_hwirq(d),
per_cpu_int_base + ARMADA_370_XP_INT_SET_MASK_OFFS);
}
static void armada_370_xp_irq_unmask(struct irq_data *d)
{
writel(irqd_to_hwirq(d),
per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
}
static int armada_370_xp_mpic_irq_map(struct irq_domain *h,
unsigned int virq, irq_hw_number_t hw)
{
armada_370_xp_irq_mask(irq_get_irq_data(virq));
writel(hw, main_int_base + ARMADA_370_XP_INT_SET_ENABLE_OFFS);
irq_set_chip_and_handler(virq, &armada_370_xp_irq_chip,
handle_level_irq);
irq_set_status_flags(virq, IRQ_LEVEL);
set_irq_flags(virq, IRQF_VALID | IRQF_PROBE);
return 0;
}
static int __init armada_370_xp_mpic_of_init(struct device_node *node,
struct device_node *parent)
{
u32 control;
main_int_base = of_iomap(node, 0);
per_cpu_int_base = of_iomap(node, 1);
BUG_ON(!main_int_base);
BUG_ON(!per_cpu_int_base);
control = readl(main_int_base + ARMADA_370_XP_INT_CONTROL);
armada_370_xp_mpic_domain =
irq_domain_add_linear(node, (control >> 2) & 0x3ff,
&armada_370_xp_mpic_irq_ops, NULL);
if (!armada_370_xp_mpic_domain)
panic("Unable to add Armada_370_Xp MPIC irq domain (DT)\n");
irq_set_default_host(armada_370_xp_mpic_domain);
return 0;
}
asmlinkage void __exception_irq_entry armada_370_xp_handle_irq(struct pt_regs
*regs)
{
u32 irqstat, irqnr;
do {
irqstat = readl_relaxed(per_cpu_int_base +
ARMADA_370_XP_CPU_INTACK_OFFS);
irqnr = irqstat & 0x3FF;
if (irqnr < 1023) {
irqnr =
irq_find_mapping(armada_370_xp_mpic_domain, irqnr);
handle_IRQ(irqnr, regs);
continue;
}
break;
} while (1);
}
void __init armada_370_xp_init_irq(void)
{
of_irq_init(mpic_of_match);
}
