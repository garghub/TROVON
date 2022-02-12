static irqreturn_t intc_cascade(int irq, void *data)
{
struct ingenic_intc_data *intc = irq_get_handler_data(irq);
uint32_t irq_reg;
unsigned i;
for (i = 0; i < intc->num_chips; i++) {
irq_reg = readl(intc->base + (i * CHIP_SIZE) +
JZ_REG_INTC_PENDING);
if (!irq_reg)
continue;
generic_handle_irq(__fls(irq_reg) + (i * 32) + JZ4740_IRQ_BASE);
}
return IRQ_HANDLED;
}
static void intc_irq_set_mask(struct irq_chip_generic *gc, uint32_t mask)
{
struct irq_chip_regs *regs = &gc->chip_types->regs;
writel(mask, gc->reg_base + regs->enable);
writel(~mask, gc->reg_base + regs->disable);
}
void ingenic_intc_irq_suspend(struct irq_data *data)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
intc_irq_set_mask(gc, gc->wake_active);
}
void ingenic_intc_irq_resume(struct irq_data *data)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
intc_irq_set_mask(gc, gc->mask_cache);
}
static int __init ingenic_intc_of_init(struct device_node *node,
unsigned num_chips)
{
struct ingenic_intc_data *intc;
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
struct irq_domain *domain;
int parent_irq, err = 0;
unsigned i;
intc = kzalloc(sizeof(*intc), GFP_KERNEL);
if (!intc) {
err = -ENOMEM;
goto out_err;
}
parent_irq = irq_of_parse_and_map(node, 0);
if (!parent_irq) {
err = -EINVAL;
goto out_free;
}
err = irq_set_handler_data(parent_irq, intc);
if (err)
goto out_unmap_irq;
intc->num_chips = num_chips;
intc->base = of_iomap(node, 0);
if (!intc->base) {
err = -ENODEV;
goto out_unmap_irq;
}
for (i = 0; i < num_chips; i++) {
writel(0xffffffff, intc->base + (i * CHIP_SIZE) +
JZ_REG_INTC_SET_MASK);
gc = irq_alloc_generic_chip("INTC", 1,
JZ4740_IRQ_BASE + (i * 32),
intc->base + (i * CHIP_SIZE),
handle_level_irq);
gc->wake_enabled = IRQ_MSK(32);
ct = gc->chip_types;
ct->regs.enable = JZ_REG_INTC_CLEAR_MASK;
ct->regs.disable = JZ_REG_INTC_SET_MASK;
ct->chip.irq_unmask = irq_gc_unmask_enable_reg;
ct->chip.irq_mask = irq_gc_mask_disable_reg;
ct->chip.irq_mask_ack = irq_gc_mask_disable_reg;
ct->chip.irq_set_wake = irq_gc_set_wake;
ct->chip.irq_suspend = ingenic_intc_irq_suspend;
ct->chip.irq_resume = ingenic_intc_irq_resume;
irq_setup_generic_chip(gc, IRQ_MSK(32), 0, 0,
IRQ_NOPROBE | IRQ_LEVEL);
}
domain = irq_domain_add_legacy(node, num_chips * 32, JZ4740_IRQ_BASE, 0,
&irq_domain_simple_ops, NULL);
if (!domain)
pr_warn("unable to register IRQ domain\n");
setup_irq(parent_irq, &intc_cascade_action);
return 0;
out_unmap_irq:
irq_dispose_mapping(parent_irq);
out_free:
kfree(intc);
out_err:
return err;
}
static int __init intc_1chip_of_init(struct device_node *node,
struct device_node *parent)
{
return ingenic_intc_of_init(node, 1);
}
static int __init intc_2chip_of_init(struct device_node *node,
struct device_node *parent)
{
return ingenic_intc_of_init(node, 2);
}
