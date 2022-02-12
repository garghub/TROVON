static void icoll_ack_irq(struct irq_data *d)
{
__raw_writel(BV_ICOLL_LEVELACK_IRQLEVELACK__LEVEL0,
icoll_base + HW_ICOLL_LEVELACK);
}
static void icoll_mask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTERRUPTn_ENABLE,
icoll_base + HW_ICOLL_INTERRUPTn_CLR(d->hwirq));
}
static void icoll_unmask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTERRUPTn_ENABLE,
icoll_base + HW_ICOLL_INTERRUPTn_SET(d->hwirq));
}
asmlinkage void __exception_irq_entry icoll_handle_irq(struct pt_regs *regs)
{
u32 irqnr;
irqnr = __raw_readl(icoll_base + HW_ICOLL_STAT_OFFSET);
__raw_writel(irqnr, icoll_base + HW_ICOLL_VECTOR);
handle_domain_irq(icoll_domain, irqnr, regs);
}
static int icoll_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &mxs_icoll_chip, handle_level_irq);
return 0;
}
static int __init icoll_of_init(struct device_node *np,
struct device_node *interrupt_parent)
{
icoll_base = of_iomap(np, 0);
WARN_ON(!icoll_base);
stmp_reset_block(icoll_base + HW_ICOLL_CTRL);
icoll_domain = irq_domain_add_linear(np, ICOLL_NUM_IRQS,
&icoll_irq_domain_ops, NULL);
return icoll_domain ? 0 : -ENODEV;
}
