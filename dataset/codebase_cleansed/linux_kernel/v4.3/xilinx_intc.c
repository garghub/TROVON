static void xilinx_intc_mask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void * regs = irq_data_get_irq_chip_data(d);
pr_debug("mask: %d\n", irq);
out_be32(regs + XINTC_CIE, 1 << irq);
}
static int xilinx_intc_set_type(struct irq_data *d, unsigned int flow_type)
{
return 0;
}
static void xilinx_intc_level_unmask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void * regs = irq_data_get_irq_chip_data(d);
pr_debug("unmask: %d\n", irq);
out_be32(regs + XINTC_SIE, 1 << irq);
out_be32(regs + XINTC_IAR, 1 << irq);
}
static void xilinx_intc_edge_unmask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void *regs = irq_data_get_irq_chip_data(d);
pr_debug("unmask: %d\n", irq);
out_be32(regs + XINTC_SIE, 1 << irq);
}
static void xilinx_intc_edge_ack(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void * regs = irq_data_get_irq_chip_data(d);
pr_debug("ack: %d\n", irq);
out_be32(regs + XINTC_IAR, 1 << irq);
}
static int xilinx_intc_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_flags)
{
if ((intsize < 2) || (intspec[0] >= XILINX_INTC_MAXIRQS))
return -EINVAL;
xilinx_intc_typetable[intspec[0]] = xilinx_intc_map_senses[intspec[1]];
*out_hwirq = intspec[0];
*out_flags = xilinx_intc_map_senses[intspec[1]];
return 0;
}
static int xilinx_intc_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t irq)
{
irq_set_chip_data(virq, h->host_data);
if (xilinx_intc_typetable[irq] == IRQ_TYPE_LEVEL_HIGH ||
xilinx_intc_typetable[irq] == IRQ_TYPE_LEVEL_LOW) {
irq_set_chip_and_handler(virq, &xilinx_intc_level_irqchip,
handle_level_irq);
} else {
irq_set_chip_and_handler(virq, &xilinx_intc_edge_irqchip,
handle_edge_irq);
}
return 0;
}
struct irq_domain * __init
xilinx_intc_init(struct device_node *np)
{
struct irq_domain * irq;
void * regs;
regs = of_iomap(np, 0);
if (!regs) {
pr_err("xilinx_intc: could not map registers\n");
return NULL;
}
out_be32(regs + XINTC_IER, 0);
out_be32(regs + XINTC_IAR, ~(u32) 0);
out_be32(regs + XINTC_MER, 0x3UL);
irq = irq_domain_add_linear(np, XILINX_INTC_MAXIRQS, &xilinx_intc_ops,
regs);
if (!irq)
panic(__FILE__ ": Cannot allocate IRQ host\n");
return irq;
}
int xilinx_intc_get_irq(void)
{
void * regs = master_irqhost->host_data;
pr_debug("get_irq:\n");
return irq_linear_revmap(master_irqhost, in_be32(regs + XINTC_IVR));
}
static void xilinx_i8259_cascade(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq = i8259_irq();
if (cascade_irq)
generic_handle_irq(cascade_irq);
chip->irq_unmask(&desc->irq_data);
}
static void __init xilinx_i8259_setup_cascade(void)
{
struct device_node *cascade_node;
int cascade_irq;
cascade_node = of_find_compatible_node(NULL, NULL, "chrp,iic");
if (!cascade_node)
return;
cascade_irq = irq_of_parse_and_map(cascade_node, 0);
if (!cascade_irq) {
pr_err("virtex_ml510: Failed to map cascade interrupt\n");
goto out;
}
i8259_init(cascade_node, 0);
irq_set_chained_handler(cascade_irq, xilinx_i8259_cascade);
outb(0xc0, 0x4d0);
outb(0xc0, 0x4d1);
out:
of_node_put(cascade_node);
}
static inline void xilinx_i8259_setup_cascade(void) { return; }
void __init xilinx_intc_init_tree(void)
{
struct device_node *np;
for_each_matching_node(np, xilinx_intc_match) {
if (!of_get_property(np, "interrupts", NULL))
break;
}
BUG_ON(!np);
master_irqhost = xilinx_intc_init(np);
BUG_ON(!master_irqhost);
irq_set_default_host(master_irqhost);
of_node_put(np);
xilinx_i8259_setup_cascade();
}
