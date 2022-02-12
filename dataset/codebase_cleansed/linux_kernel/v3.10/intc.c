static void intc_enable_or_unmask(struct irq_data *d)
{
unsigned long mask = 1 << d->hwirq;
pr_debug("enable_or_unmask: %ld\n", d->hwirq);
if (irqd_is_level_type(d))
out_be32(INTC_BASE + IAR, mask);
out_be32(INTC_BASE + SIE, mask);
}
static void intc_disable_or_mask(struct irq_data *d)
{
pr_debug("disable: %ld\n", d->hwirq);
out_be32(INTC_BASE + CIE, 1 << d->hwirq);
}
static void intc_ack(struct irq_data *d)
{
pr_debug("ack: %ld\n", d->hwirq);
out_be32(INTC_BASE + IAR, 1 << d->hwirq);
}
static void intc_mask_ack(struct irq_data *d)
{
unsigned long mask = 1 << d->hwirq;
pr_debug("disable_and_ack: %ld\n", d->hwirq);
out_be32(INTC_BASE + CIE, mask);
out_be32(INTC_BASE + IAR, mask);
}
unsigned int get_irq(void)
{
unsigned int hwirq, irq = -1;
hwirq = in_be32(INTC_BASE + IVR);
if (hwirq != -1U)
irq = irq_find_mapping(root_domain, hwirq);
pr_debug("get_irq: hwirq=%d, irq=%d\n", hwirq, irq);
return irq;
}
static int xintc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
u32 intr_mask = (u32)d->host_data;
if (intr_mask & (1 << hw)) {
irq_set_chip_and_handler_name(irq, &intc_dev,
handle_edge_irq, "edge");
irq_clear_status_flags(irq, IRQ_LEVEL);
} else {
irq_set_chip_and_handler_name(irq, &intc_dev,
handle_level_irq, "level");
irq_set_status_flags(irq, IRQ_LEVEL);
}
return 0;
}
void __init init_IRQ(void)
{
u32 nr_irq, intr_mask;
struct device_node *intc = NULL;
#ifdef CONFIG_SELFMOD_INTC
unsigned int intc_baseaddr = 0;
static int arr_func[] = {
(int)&get_irq,
(int)&intc_enable_or_unmask,
(int)&intc_disable_or_mask,
(int)&intc_mask_ack,
(int)&intc_ack,
(int)&intc_end,
0
};
#endif
intc = of_find_compatible_node(NULL, NULL, "xlnx,xps-intc-1.00.a");
BUG_ON(!intc);
intc_baseaddr = be32_to_cpup(of_get_property(intc, "reg", NULL));
intc_baseaddr = (unsigned long) ioremap(intc_baseaddr, PAGE_SIZE);
nr_irq = be32_to_cpup(of_get_property(intc,
"xlnx,num-intr-inputs", NULL));
intr_mask =
be32_to_cpup(of_get_property(intc, "xlnx,kind-of-intr", NULL));
if (intr_mask > (u32)((1ULL << nr_irq) - 1))
pr_info(" ERROR: Mismatch in kind-of-intr param\n");
#ifdef CONFIG_SELFMOD_INTC
selfmod_function((int *) arr_func, intc_baseaddr);
#endif
pr_info("%s #0 at 0x%08x, num_irq=%d, edge=0x%x\n",
intc->name, intc_baseaddr, nr_irq, intr_mask);
out_be32(intc_baseaddr + IER, 0);
out_be32(intc_baseaddr + IAR, 0xffffffff);
out_be32(intc_baseaddr + MER, MER_HIE | MER_ME);
root_domain = irq_domain_add_linear(intc, nr_irq, &xintc_irq_domain_ops,
(void *)intr_mask);
irq_set_default_host(root_domain);
}
