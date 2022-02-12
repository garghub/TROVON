static void mpc86xx_8259_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq = i8259_irq();
if (cascade_irq != NO_IRQ)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
void __init mpc86xx_init_irq(void)
{
struct mpic *mpic;
struct device_node *np;
struct resource res;
#ifdef CONFIG_PPC_I8259
struct device_node *cascade_node = NULL;
int cascade_irq;
#endif
np = of_find_node_by_type(NULL, "open-pic");
if (np == NULL)
return;
of_address_to_resource(np, 0, &res);
mpic = mpic_alloc(np, res.start,
MPIC_PRIMARY | MPIC_WANTS_RESET |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS |
MPIC_SINGLE_DEST_CPU,
0, 256, " MPIC ");
of_node_put(np);
BUG_ON(mpic == NULL);
mpic_init(mpic);
#ifdef CONFIG_PPC_I8259
for_each_node_by_type(np, "interrupt-controller")
if (of_device_is_compatible(np, "chrp,iic")) {
cascade_node = np;
break;
}
if (cascade_node == NULL) {
printk(KERN_DEBUG "Could not find i8259 PIC\n");
return;
}
cascade_irq = irq_of_parse_and_map(cascade_node, 0);
if (cascade_irq == NO_IRQ) {
printk(KERN_ERR "Failed to map cascade interrupt\n");
return;
}
i8259_init(cascade_node, 0);
of_node_put(cascade_node);
irq_set_chained_handler(cascade_irq, mpc86xx_8259_cascade);
#endif
}
