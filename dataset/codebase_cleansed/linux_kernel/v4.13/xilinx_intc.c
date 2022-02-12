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
irqchip_init();
xilinx_i8259_setup_cascade();
}
