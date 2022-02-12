static inline u32 intc_readl(struct tangox_irq_chip *chip, int reg)
{
return readl_relaxed(chip->base + reg);
}
static inline void intc_writel(struct tangox_irq_chip *chip, int reg, u32 val)
{
writel_relaxed(val, chip->base + reg);
}
static void tangox_dispatch_irqs(struct irq_domain *dom, unsigned int status,
int base)
{
unsigned int hwirq;
unsigned int virq;
while (status) {
hwirq = __ffs(status);
virq = irq_find_mapping(dom, base + hwirq);
if (virq)
generic_handle_irq(virq);
status &= ~BIT(hwirq);
}
}
static void tangox_irq_handler(struct irq_desc *desc)
{
struct irq_domain *dom = irq_desc_get_handler_data(desc);
struct irq_chip *host_chip = irq_desc_get_chip(desc);
struct tangox_irq_chip *chip = dom->host_data;
unsigned int status_lo, status_hi;
chained_irq_enter(host_chip, desc);
status_lo = intc_readl(chip, chip->ctl + IRQ_STATUS);
status_hi = intc_readl(chip, chip->ctl + IRQ_CTL_HI + IRQ_STATUS);
tangox_dispatch_irqs(dom, status_lo, 0);
tangox_dispatch_irqs(dom, status_hi, 32);
chained_irq_exit(host_chip, desc);
}
static int tangox_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct tangox_irq_chip *chip = gc->domain->host_data;
struct irq_chip_regs *regs = &gc->chip_types[0].regs;
switch (flow_type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
intc_writel(chip, regs->type + EDGE_CFG_RISE_SET, d->mask);
intc_writel(chip, regs->type + EDGE_CFG_FALL_CLR, d->mask);
break;
case IRQ_TYPE_EDGE_FALLING:
intc_writel(chip, regs->type + EDGE_CFG_RISE_CLR, d->mask);
intc_writel(chip, regs->type + EDGE_CFG_FALL_SET, d->mask);
break;
case IRQ_TYPE_LEVEL_HIGH:
intc_writel(chip, regs->type + EDGE_CFG_RISE_CLR, d->mask);
intc_writel(chip, regs->type + EDGE_CFG_FALL_CLR, d->mask);
break;
case IRQ_TYPE_LEVEL_LOW:
intc_writel(chip, regs->type + EDGE_CFG_RISE_SET, d->mask);
intc_writel(chip, regs->type + EDGE_CFG_FALL_SET, d->mask);
break;
default:
pr_err("Invalid trigger mode %x for IRQ %d\n",
flow_type, d->irq);
return -EINVAL;
}
return irq_setup_alt_chip(d, flow_type);
}
static void __init tangox_irq_init_chip(struct irq_chip_generic *gc,
unsigned long ctl_offs,
unsigned long edge_offs)
{
struct tangox_irq_chip *chip = gc->domain->host_data;
struct irq_chip_type *ct = gc->chip_types;
unsigned long ctl_base = chip->ctl + ctl_offs;
unsigned long edge_base = EDGE_CTL_BASE + edge_offs;
int i;
gc->reg_base = chip->base;
gc->unused = 0;
for (i = 0; i < 2; i++) {
ct[i].chip.irq_ack = irq_gc_ack_set_bit;
ct[i].chip.irq_mask = irq_gc_mask_disable_reg;
ct[i].chip.irq_mask_ack = irq_gc_mask_disable_reg_and_ack;
ct[i].chip.irq_unmask = irq_gc_unmask_enable_reg;
ct[i].chip.irq_set_type = tangox_irq_set_type;
ct[i].chip.name = gc->domain->name;
ct[i].regs.enable = ctl_base + IRQ_EN_SET;
ct[i].regs.disable = ctl_base + IRQ_EN_CLR;
ct[i].regs.ack = edge_base + EDGE_RAWSTAT;
ct[i].regs.type = edge_base;
}
ct[0].type = IRQ_TYPE_LEVEL_MASK;
ct[0].handler = handle_level_irq;
ct[1].type = IRQ_TYPE_EDGE_BOTH;
ct[1].handler = handle_edge_irq;
intc_writel(chip, ct->regs.disable, 0xffffffff);
intc_writel(chip, ct->regs.ack, 0xffffffff);
}
static void __init tangox_irq_domain_init(struct irq_domain *dom)
{
struct irq_chip_generic *gc;
int i;
for (i = 0; i < 2; i++) {
gc = irq_get_domain_generic_chip(dom, i * 32);
tangox_irq_init_chip(gc, i * IRQ_CTL_HI, i * EDGE_CTL_HI);
}
}
static int __init tangox_irq_init(void __iomem *base, struct resource *baseres,
struct device_node *node)
{
struct tangox_irq_chip *chip;
struct irq_domain *dom;
struct resource res;
int irq;
int err;
irq = irq_of_parse_and_map(node, 0);
if (!irq)
panic("%s: failed to get IRQ", node->name);
err = of_address_to_resource(node, 0, &res);
if (err)
panic("%s: failed to get address", node->name);
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
chip->ctl = res.start - baseres->start;
chip->base = base;
dom = irq_domain_add_linear(node, 64, &irq_generic_chip_ops, chip);
if (!dom)
panic("%s: failed to create irqdomain", node->name);
err = irq_alloc_domain_generic_chips(dom, 32, 2, node->name,
handle_level_irq, 0, 0, 0);
if (err)
panic("%s: failed to allocate irqchip", node->name);
tangox_irq_domain_init(dom);
irq_set_chained_handler(irq, tangox_irq_handler);
irq_set_handler_data(irq, dom);
return 0;
}
static int __init tangox_of_irq_init(struct device_node *node,
struct device_node *parent)
{
struct device_node *c;
struct resource res;
void __iomem *base;
base = of_iomap(node, 0);
if (!base)
panic("%s: of_iomap failed", node->name);
of_address_to_resource(node, 0, &res);
for_each_child_of_node(node, c)
tangox_irq_init(base, &res, c);
return 0;
}
