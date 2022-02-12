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
do {
irqnr = __raw_readl(icoll_base + HW_ICOLL_STAT_OFFSET);
if (irqnr != 0x7f) {
__raw_writel(irqnr, icoll_base + HW_ICOLL_VECTOR);
irqnr = irq_find_mapping(icoll_domain, irqnr);
handle_IRQ(irqnr, regs);
continue;
}
break;
} while (1);
}
static int icoll_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &mxs_icoll_chip, handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
void __init icoll_of_init(struct device_node *np,
struct device_node *interrupt_parent)
{
mxs_reset_block(icoll_base + HW_ICOLL_CTRL);
icoll_domain = irq_domain_add_linear(np, ICOLL_NUM_IRQS,
&icoll_irq_domain_ops, NULL);
WARN_ON(!icoll_domain);
}
void __init icoll_init_irq(void)
{
of_irq_init(icoll_of_match);
}
