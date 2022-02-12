static void dw_apb_ictl_handler(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct irq_chip_generic *gc = irq_get_handler_data(irq);
struct irq_domain *d = gc->private;
u32 stat;
int n;
chained_irq_enter(chip, desc);
for (n = 0; n < gc->num_ct; n++) {
stat = readl_relaxed(gc->reg_base +
APB_INT_FINALSTATUS_L + 4 * n);
while (stat) {
u32 hwirq = ffs(stat) - 1;
generic_handle_irq(irq_find_mapping(d,
gc->irq_base + hwirq + 32 * n));
stat &= ~(1 << hwirq);
}
}
chained_irq_exit(chip, desc);
}
static int __init dw_apb_ictl_init(struct device_node *np,
struct device_node *parent)
{
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
struct resource r;
struct irq_domain *domain;
struct irq_chip_generic *gc;
void __iomem *iobase;
int ret, nrirqs, irq;
u32 reg;
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0) {
pr_err("%s: unable to parse irq\n", np->full_name);
return -EINVAL;
}
ret = of_address_to_resource(np, 0, &r);
if (ret) {
pr_err("%s: unable to get resource\n", np->full_name);
return ret;
}
if (!request_mem_region(r.start, resource_size(&r), np->full_name)) {
pr_err("%s: unable to request mem region\n", np->full_name);
return -ENOMEM;
}
iobase = ioremap(r.start, resource_size(&r));
if (!iobase) {
pr_err("%s: unable to map resource\n", np->full_name);
ret = -ENOMEM;
goto err_release;
}
writel(~0, iobase + APB_INT_MASK_L);
writel(~0, iobase + APB_INT_MASK_H);
writel(~0, iobase + APB_INT_ENABLE_L);
writel(~0, iobase + APB_INT_ENABLE_H);
reg = readl(iobase + APB_INT_ENABLE_H);
if (reg)
nrirqs = 32 + fls(reg);
else
nrirqs = fls(readl(iobase + APB_INT_ENABLE_L));
domain = irq_domain_add_linear(np, nrirqs,
&irq_generic_chip_ops, NULL);
if (!domain) {
pr_err("%s: unable to add irq domain\n", np->full_name);
ret = -ENOMEM;
goto err_unmap;
}
ret = irq_alloc_domain_generic_chips(domain, 32, (nrirqs > 32) ? 2 : 1,
np->name, handle_level_irq, clr, 0,
IRQ_GC_INIT_MASK_CACHE);
if (ret) {
pr_err("%s: unable to alloc irq domain gc\n", np->full_name);
goto err_unmap;
}
gc = irq_get_domain_generic_chip(domain, 0);
gc->private = domain;
gc->reg_base = iobase;
gc->chip_types[0].regs.mask = APB_INT_MASK_L;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_clr_bit;
if (nrirqs > 32) {
gc->chip_types[1].regs.mask = APB_INT_MASK_H;
gc->chip_types[1].chip.irq_mask = irq_gc_mask_set_bit;
gc->chip_types[1].chip.irq_unmask = irq_gc_mask_clr_bit;
}
irq_set_handler_data(irq, gc);
irq_set_chained_handler(irq, dw_apb_ictl_handler);
return 0;
err_unmap:
iounmap(iobase);
err_release:
release_mem_region(r.start, resource_size(&r));
return ret;
}
