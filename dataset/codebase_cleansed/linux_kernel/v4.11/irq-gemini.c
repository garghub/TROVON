static void gemini_irq_mask(struct irq_data *d)
{
struct gemini_irq_data *g = irq_data_get_irq_chip_data(d);
unsigned int mask;
mask = readl(GEMINI_IRQ_MASK(g->base));
mask &= ~BIT(irqd_to_hwirq(d));
writel(mask, GEMINI_IRQ_MASK(g->base));
}
static void gemini_irq_unmask(struct irq_data *d)
{
struct gemini_irq_data *g = irq_data_get_irq_chip_data(d);
unsigned int mask;
mask = readl(GEMINI_IRQ_MASK(g->base));
mask |= BIT(irqd_to_hwirq(d));
writel(mask, GEMINI_IRQ_MASK(g->base));
}
static void gemini_irq_ack(struct irq_data *d)
{
struct gemini_irq_data *g = irq_data_get_irq_chip_data(d);
writel(BIT(irqd_to_hwirq(d)), GEMINI_IRQ_CLEAR(g->base));
}
static int gemini_irq_set_type(struct irq_data *d, unsigned int trigger)
{
struct gemini_irq_data *g = irq_data_get_irq_chip_data(d);
int offset = irqd_to_hwirq(d);
u32 mode, polarity;
mode = readl(GEMINI_IRQ_MODE(g->base));
polarity = readl(GEMINI_IRQ_POLARITY(g->base));
if (trigger & (IRQ_TYPE_LEVEL_HIGH)) {
irq_set_handler_locked(d, handle_level_irq);
mode &= ~BIT(offset);
polarity &= ~BIT(offset);
} else if (trigger & IRQ_TYPE_EDGE_RISING) {
irq_set_handler_locked(d, handle_edge_irq);
mode |= BIT(offset);
polarity |= BIT(offset);
} else if (trigger & IRQ_TYPE_EDGE_FALLING) {
irq_set_handler_locked(d, handle_edge_irq);
mode |= BIT(offset);
polarity &= ~BIT(offset);
} else {
irq_set_handler_locked(d, handle_bad_irq);
pr_warn("GEMINI IRQ: no supported trigger selected for line %d\n",
offset);
}
writel(mode, GEMINI_IRQ_MODE(g->base));
writel(polarity, GEMINI_IRQ_POLARITY(g->base));
return 0;
}
asmlinkage void __exception_irq_entry gemini_irqchip_handle_irq(struct pt_regs *regs)
{
struct gemini_irq_data *g = &girq;
int irq;
u32 status;
while ((status = readl(GEMINI_IRQ_STATUS(g->base)))) {
irq = ffs(status) - 1;
handle_domain_irq(g->domain, irq, regs);
}
}
static int gemini_irqdomain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct gemini_irq_data *g = d->host_data;
irq_set_chip_data(irq, g);
irq_set_chip_and_handler(irq, &gemini_irq_chip, handle_bad_irq);
irq_set_probe(irq);
return 0;
}
static void gemini_irqdomain_unmap(struct irq_domain *d, unsigned int irq)
{
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
int __init gemini_of_init_irq(struct device_node *node,
struct device_node *parent)
{
struct gemini_irq_data *g = &girq;
cpu_idle_poll_ctrl(true);
g->base = of_iomap(node, 0);
WARN(!g->base, "unable to map gemini irq registers\n");
writel(0, GEMINI_IRQ_MASK(g->base));
writel(0, GEMINI_FIQ_MASK(g->base));
g->domain = irq_domain_add_simple(node, GEMINI_NUM_IRQS, 0,
&gemini_irqdomain_ops, g);
set_handle_irq(gemini_irqchip_handle_irq);
return 0;
}
