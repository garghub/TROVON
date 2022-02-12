static void intc_enable_or_unmask(struct irq_data *d)
{
unsigned long mask = 1 << d->irq;
pr_debug("enable_or_unmask: %d\n", d->irq);
out_be32(INTC_BASE + SIE, mask);
if (irqd_is_level_type(d))
out_be32(INTC_BASE + IAR, mask);
}
static void intc_disable_or_mask(struct irq_data *d)
{
pr_debug("disable: %d\n", d->irq);
out_be32(INTC_BASE + CIE, 1 << d->irq);
}
static void intc_ack(struct irq_data *d)
{
pr_debug("ack: %d\n", d->irq);
out_be32(INTC_BASE + IAR, 1 << d->irq);
}
static void intc_mask_ack(struct irq_data *d)
{
unsigned long mask = 1 << d->irq;
pr_debug("disable_and_ack: %d\n", d->irq);
out_be32(INTC_BASE + CIE, mask);
out_be32(INTC_BASE + IAR, mask);
}
unsigned int get_irq(struct pt_regs *regs)
{
int irq;
irq = in_be32(INTC_BASE + IVR);
pr_debug("get_irq: %d\n", irq);
return irq;
}
void __init init_IRQ(void)
{
u32 i, j, intr_type;
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
const char * const intc_list[] = {
"xlnx,xps-intc-1.00.a",
NULL
};
for (j = 0; intc_list[j] != NULL; j++) {
intc = of_find_compatible_node(NULL, NULL, intc_list[j]);
if (intc)
break;
}
BUG_ON(!intc);
intc_baseaddr = be32_to_cpup(of_get_property(intc,
"reg", NULL));
intc_baseaddr = (unsigned long) ioremap(intc_baseaddr, PAGE_SIZE);
nr_irq = be32_to_cpup(of_get_property(intc,
"xlnx,num-intr-inputs", NULL));
intr_type =
be32_to_cpup(of_get_property(intc,
"xlnx,kind-of-intr", NULL));
if (intr_type > (u32)((1ULL << nr_irq) - 1))
printk(KERN_INFO " ERROR: Mismatch in kind-of-intr param\n");
#ifdef CONFIG_SELFMOD_INTC
selfmod_function((int *) arr_func, intc_baseaddr);
#endif
printk(KERN_INFO "%s #0 at 0x%08x, num_irq=%d, edge=0x%x\n",
intc_list[j], intc_baseaddr, nr_irq, intr_type);
out_be32(intc_baseaddr + IER, 0);
out_be32(intc_baseaddr + IAR, 0xffffffff);
out_be32(intc_baseaddr + MER, MER_HIE | MER_ME);
for (i = 0; i < nr_irq; ++i) {
if (intr_type & (0x00000001 << i)) {
irq_set_chip_and_handler_name(i, &intc_dev,
handle_edge_irq, "edge");
irq_clear_status_flags(i, IRQ_LEVEL);
} else {
irq_set_chip_and_handler_name(i, &intc_dev,
handle_level_irq, "level");
irq_set_status_flags(i, IRQ_LEVEL);
}
}
}
