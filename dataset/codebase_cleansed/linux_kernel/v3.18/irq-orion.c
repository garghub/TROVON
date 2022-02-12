static void
__exception_irq_entry orion_handle_irq(struct pt_regs *regs)
{
struct irq_domain_chip_generic *dgc = orion_irq_domain->gc;
int n, base = 0;
for (n = 0; n < dgc->num_chips; n++, base += ORION_IRQS_PER_CHIP) {
struct irq_chip_generic *gc =
irq_get_domain_generic_chip(orion_irq_domain, base);
u32 stat = readl_relaxed(gc->reg_base + ORION_IRQ_CAUSE) &
gc->mask_cache;
while (stat) {
u32 hwirq = __fls(stat);
handle_domain_irq(orion_irq_domain,
gc->irq_base + hwirq, regs);
stat &= ~(1 << hwirq);
}
}
}
static int __init orion_irq_init(struct device_node *np,
struct device_node *parent)
{
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
int n, ret, base, num_chips = 0;
struct resource r;
while (of_address_to_resource(np, num_chips, &r) == 0)
num_chips++;
orion_irq_domain = irq_domain_add_linear(np,
num_chips * ORION_IRQS_PER_CHIP,
&irq_generic_chip_ops, NULL);
if (!orion_irq_domain)
panic("%s: unable to add irq domain\n", np->name);
ret = irq_alloc_domain_generic_chips(orion_irq_domain,
ORION_IRQS_PER_CHIP, 1, np->name,
handle_level_irq, clr, 0,
IRQ_GC_INIT_MASK_CACHE);
if (ret)
panic("%s: unable to alloc irq domain gc\n", np->name);
for (n = 0, base = 0; n < num_chips; n++, base += ORION_IRQS_PER_CHIP) {
struct irq_chip_generic *gc =
irq_get_domain_generic_chip(orion_irq_domain, base);
of_address_to_resource(np, n, &r);
if (!request_mem_region(r.start, resource_size(&r), np->name))
panic("%s: unable to request mem region %d",
np->name, n);
gc->reg_base = ioremap(r.start, resource_size(&r));
if (!gc->reg_base)
panic("%s: unable to map resource %d", np->name, n);
gc->chip_types[0].regs.mask = ORION_IRQ_MASK;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
writel(0, gc->reg_base + ORION_IRQ_MASK);
}
set_handle_irq(orion_handle_irq);
return 0;
}
static void orion_bridge_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct irq_domain *d = irq_get_handler_data(irq);
struct irq_chip_generic *gc = irq_get_domain_generic_chip(d, 0);
u32 stat = readl_relaxed(gc->reg_base + ORION_BRIDGE_IRQ_CAUSE) &
gc->mask_cache;
while (stat) {
u32 hwirq = __fls(stat);
generic_handle_irq(irq_find_mapping(d, gc->irq_base + hwirq));
stat &= ~(1 << hwirq);
}
}
static unsigned int orion_bridge_irq_startup(struct irq_data *d)
{
struct irq_chip_type *ct = irq_data_get_chip_type(d);
ct->chip.irq_ack(d);
ct->chip.irq_unmask(d);
return 0;
}
static int __init orion_bridge_irq_init(struct device_node *np,
struct device_node *parent)
{
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
struct resource r;
struct irq_domain *domain;
struct irq_chip_generic *gc;
int ret, irq, nrirqs = 32;
of_property_read_u32(np, "marvell,#interrupts", &nrirqs);
domain = irq_domain_add_linear(np, nrirqs,
&irq_generic_chip_ops, NULL);
if (!domain) {
pr_err("%s: unable to add irq domain\n", np->name);
return -ENOMEM;
}
ret = irq_alloc_domain_generic_chips(domain, nrirqs, 1, np->name,
handle_edge_irq, clr, 0, IRQ_GC_INIT_MASK_CACHE);
if (ret) {
pr_err("%s: unable to alloc irq domain gc\n", np->name);
return ret;
}
ret = of_address_to_resource(np, 0, &r);
if (ret) {
pr_err("%s: unable to get resource\n", np->name);
return ret;
}
if (!request_mem_region(r.start, resource_size(&r), np->name)) {
pr_err("%s: unable to request mem region\n", np->name);
return -ENOMEM;
}
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0) {
pr_err("%s: unable to parse irq\n", np->name);
return -EINVAL;
}
gc = irq_get_domain_generic_chip(domain, 0);
gc->reg_base = ioremap(r.start, resource_size(&r));
if (!gc->reg_base) {
pr_err("%s: unable to map resource\n", np->name);
return -ENOMEM;
}
gc->chip_types[0].regs.ack = ORION_BRIDGE_IRQ_CAUSE;
gc->chip_types[0].regs.mask = ORION_BRIDGE_IRQ_MASK;
gc->chip_types[0].chip.irq_startup = orion_bridge_irq_startup;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_clr_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
writel(0, gc->reg_base + ORION_BRIDGE_IRQ_MASK);
writel(0, gc->reg_base + ORION_BRIDGE_IRQ_CAUSE);
irq_set_handler_data(irq, domain);
irq_set_chained_handler(irq, orion_bridge_irq_handler);
return 0;
}
