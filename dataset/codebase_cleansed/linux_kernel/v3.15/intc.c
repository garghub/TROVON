static void intc_write32(u32 val, void __iomem *addr)
{
iowrite32(val, addr);
}
static unsigned int intc_read32(void __iomem *addr)
{
return ioread32(addr);
}
static void intc_write32_be(u32 val, void __iomem *addr)
{
iowrite32be(val, addr);
}
static unsigned int intc_read32_be(void __iomem *addr)
{
return ioread32be(addr);
}
static void intc_enable_or_unmask(struct irq_data *d)
{
unsigned long mask = 1 << d->hwirq;
pr_debug("enable_or_unmask: %ld\n", d->hwirq);
if (irqd_is_level_type(d))
write_fn(mask, intc_baseaddr + IAR);
write_fn(mask, intc_baseaddr + SIE);
}
static void intc_disable_or_mask(struct irq_data *d)
{
pr_debug("disable: %ld\n", d->hwirq);
write_fn(1 << d->hwirq, intc_baseaddr + CIE);
}
static void intc_ack(struct irq_data *d)
{
pr_debug("ack: %ld\n", d->hwirq);
write_fn(1 << d->hwirq, intc_baseaddr + IAR);
}
static void intc_mask_ack(struct irq_data *d)
{
unsigned long mask = 1 << d->hwirq;
pr_debug("disable_and_ack: %ld\n", d->hwirq);
write_fn(mask, intc_baseaddr + CIE);
write_fn(mask, intc_baseaddr + IAR);
}
unsigned int get_irq(void)
{
unsigned int hwirq, irq = -1;
hwirq = read_fn(intc_baseaddr + IVR);
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
static int __init xilinx_intc_of_init(struct device_node *intc,
struct device_node *parent)
{
u32 nr_irq, intr_mask;
int ret;
intc_baseaddr = of_iomap(intc, 0);
BUG_ON(!intc_baseaddr);
ret = of_property_read_u32(intc, "xlnx,num-intr-inputs", &nr_irq);
if (ret < 0) {
pr_err("%s: unable to read xlnx,num-intr-inputs\n", __func__);
return -EINVAL;
}
ret = of_property_read_u32(intc, "xlnx,kind-of-intr", &intr_mask);
if (ret < 0) {
pr_err("%s: unable to read xlnx,kind-of-intr\n", __func__);
return -EINVAL;
}
if (intr_mask > (u32)((1ULL << nr_irq) - 1))
pr_info(" ERROR: Mismatch in kind-of-intr param\n");
pr_info("%s: num_irq=%d, edge=0x%x\n",
intc->full_name, nr_irq, intr_mask);
write_fn = intc_write32;
read_fn = intc_read32;
write_fn(0, intc_baseaddr + IER);
write_fn(0xffffffff, intc_baseaddr + IAR);
write_fn(MER_HIE | MER_ME, intc_baseaddr + MER);
if (!(read_fn(intc_baseaddr + MER) & (MER_HIE | MER_ME))) {
write_fn = intc_write32_be;
read_fn = intc_read32_be;
write_fn(MER_HIE | MER_ME, intc_baseaddr + MER);
}
root_domain = irq_domain_add_linear(intc, nr_irq, &xintc_irq_domain_ops,
(void *)intr_mask);
irq_set_default_host(root_domain);
return 0;
}
