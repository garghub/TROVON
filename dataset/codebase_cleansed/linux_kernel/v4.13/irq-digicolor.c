static void __exception_irq_entry digicolor_handle_irq(struct pt_regs *regs)
{
struct irq_domain_chip_generic *dgc = digicolor_irq_domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
u32 status, hwirq;
do {
status = irq_reg_readl(gc, IC_INT0STATUS_LO);
if (status) {
hwirq = ffs(status) - 1;
} else {
status = irq_reg_readl(gc, IC_INT0STATUS_XLO);
if (status)
hwirq = ffs(status) - 1 + 32;
else
return;
}
handle_domain_irq(digicolor_irq_domain, hwirq, regs);
} while (1);
}
static void __init digicolor_set_gc(void __iomem *reg_base, unsigned irq_base,
unsigned en_reg, unsigned ack_reg)
{
struct irq_chip_generic *gc;
gc = irq_get_domain_generic_chip(digicolor_irq_domain, irq_base);
gc->reg_base = reg_base;
gc->chip_types[0].regs.ack = ack_reg;
gc->chip_types[0].regs.mask = en_reg;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
}
static int __init digicolor_of_init(struct device_node *node,
struct device_node *parent)
{
void __iomem *reg_base;
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
struct regmap *ucregs;
int ret;
reg_base = of_iomap(node, 0);
if (!reg_base) {
pr_err("%s: unable to map IC registers\n", node->full_name);
return -ENXIO;
}
writel(0, reg_base + IC_INT0ENABLE_LO);
writel(0, reg_base + IC_INT0ENABLE_XLO);
ucregs = syscon_regmap_lookup_by_phandle(node, "syscon");
if (IS_ERR(ucregs)) {
pr_err("%s: unable to map UC registers\n", node->full_name);
return PTR_ERR(ucregs);
}
regmap_write(ucregs, UC_IRQ_CONTROL, 1);
digicolor_irq_domain =
irq_domain_add_linear(node, 64, &irq_generic_chip_ops, NULL);
if (!digicolor_irq_domain) {
pr_err("%s: unable to create IRQ domain\n", node->full_name);
return -ENOMEM;
}
ret = irq_alloc_domain_generic_chips(digicolor_irq_domain, 32, 1,
"digicolor_irq", handle_level_irq,
clr, 0, 0);
if (ret) {
pr_err("%s: unable to allocate IRQ gc\n", node->full_name);
return ret;
}
digicolor_set_gc(reg_base, 0, IC_INT0ENABLE_LO, IC_FLAG_CLEAR_LO);
digicolor_set_gc(reg_base, 32, IC_INT0ENABLE_XLO, IC_FLAG_CLEAR_XLO);
set_handle_irq(digicolor_handle_irq);
return 0;
}
