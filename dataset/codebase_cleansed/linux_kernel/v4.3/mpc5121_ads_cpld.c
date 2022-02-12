static void __iomem *
irq_to_pic_mask(unsigned int irq)
{
return irq <= 7 ? &cpld_regs->pci_mask : &cpld_regs->misc_mask;
}
static unsigned int
irq_to_pic_bit(unsigned int irq)
{
return 1 << (irq & 0x7);
}
static void
cpld_mask_irq(struct irq_data *d)
{
unsigned int cpld_irq = (unsigned int)irqd_to_hwirq(d);
void __iomem *pic_mask = irq_to_pic_mask(cpld_irq);
out_8(pic_mask,
in_8(pic_mask) | irq_to_pic_bit(cpld_irq));
}
static void
cpld_unmask_irq(struct irq_data *d)
{
unsigned int cpld_irq = (unsigned int)irqd_to_hwirq(d);
void __iomem *pic_mask = irq_to_pic_mask(cpld_irq);
out_8(pic_mask,
in_8(pic_mask) & ~irq_to_pic_bit(cpld_irq));
}
static int
cpld_pic_get_irq(int offset, u8 ignore, u8 __iomem *statusp,
u8 __iomem *maskp)
{
int cpld_irq;
u8 status = in_8(statusp);
u8 mask = in_8(maskp);
status |= (ignore | mask);
if (status == 0xff)
return NO_IRQ;
cpld_irq = ffz(status) + offset;
return irq_linear_revmap(cpld_pic_host, cpld_irq);
}
static void cpld_pic_cascade(struct irq_desc *desc)
{
unsigned int irq;
irq = cpld_pic_get_irq(0, PCI_IGNORE, &cpld_regs->pci_status,
&cpld_regs->pci_mask);
if (irq != NO_IRQ) {
generic_handle_irq(irq);
return;
}
irq = cpld_pic_get_irq(8, MISC_IGNORE, &cpld_regs->misc_status,
&cpld_regs->misc_mask);
if (irq != NO_IRQ) {
generic_handle_irq(irq);
return;
}
}
static int
cpld_pic_host_match(struct irq_domain *h, struct device_node *node,
enum irq_domain_bus_token bus_token)
{
return cpld_pic_node == node;
}
static int
cpld_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &cpld_pic, handle_level_irq);
return 0;
}
void __init
mpc5121_ads_cpld_map(void)
{
struct device_node *np = NULL;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121ads-cpld-pic");
if (!np) {
printk(KERN_ERR "CPLD PIC init: can not find cpld-pic node\n");
return;
}
cpld_regs = of_iomap(np, 0);
of_node_put(np);
}
void __init
mpc5121_ads_cpld_pic_init(void)
{
unsigned int cascade_irq;
struct device_node *np = NULL;
pr_debug("cpld_ic_init\n");
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121ads-cpld-pic");
if (!np) {
printk(KERN_ERR "CPLD PIC init: can not find cpld-pic node\n");
return;
}
if (!cpld_regs)
goto end;
cascade_irq = irq_of_parse_and_map(np, 0);
if (cascade_irq == NO_IRQ)
goto end;
out_8(&cpld_regs->route, 0xfd);
out_8(&cpld_regs->pci_mask, 0xff);
out_8(&cpld_regs->misc_mask, ~(MISC_IGNORE));
cpld_pic_node = of_node_get(np);
cpld_pic_host = irq_domain_add_linear(np, 16, &cpld_pic_host_ops, NULL);
if (!cpld_pic_host) {
printk(KERN_ERR "CPLD PIC: failed to allocate irq host!\n");
goto end;
}
irq_set_chained_handler(cascade_irq, cpld_pic_cascade);
end:
of_node_put(np);
}
