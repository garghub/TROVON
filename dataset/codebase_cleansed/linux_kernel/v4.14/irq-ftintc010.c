static void ft010_irq_mask(struct irq_data *d)
{
struct ft010_irq_data *f = irq_data_get_irq_chip_data(d);
unsigned int mask;
mask = readl(FT010_IRQ_MASK(f->base));
mask &= ~BIT(irqd_to_hwirq(d));
writel(mask, FT010_IRQ_MASK(f->base));
}
static void ft010_irq_unmask(struct irq_data *d)
{
struct ft010_irq_data *f = irq_data_get_irq_chip_data(d);
unsigned int mask;
mask = readl(FT010_IRQ_MASK(f->base));
mask |= BIT(irqd_to_hwirq(d));
writel(mask, FT010_IRQ_MASK(f->base));
}
static void ft010_irq_ack(struct irq_data *d)
{
struct ft010_irq_data *f = irq_data_get_irq_chip_data(d);
writel(BIT(irqd_to_hwirq(d)), FT010_IRQ_CLEAR(f->base));
}
static int ft010_irq_set_type(struct irq_data *d, unsigned int trigger)
{
struct ft010_irq_data *f = irq_data_get_irq_chip_data(d);
int offset = irqd_to_hwirq(d);
u32 mode, polarity;
mode = readl(FT010_IRQ_MODE(f->base));
polarity = readl(FT010_IRQ_POLARITY(f->base));
if (trigger & (IRQ_TYPE_LEVEL_LOW)) {
irq_set_handler_locked(d, handle_level_irq);
mode &= ~BIT(offset);
polarity |= BIT(offset);
} else if (trigger & (IRQ_TYPE_LEVEL_HIGH)) {
irq_set_handler_locked(d, handle_level_irq);
mode &= ~BIT(offset);
polarity &= ~BIT(offset);
} else if (trigger & IRQ_TYPE_EDGE_FALLING) {
irq_set_handler_locked(d, handle_edge_irq);
mode |= BIT(offset);
polarity |= BIT(offset);
} else if (trigger & IRQ_TYPE_EDGE_RISING) {
irq_set_handler_locked(d, handle_edge_irq);
mode |= BIT(offset);
polarity &= ~BIT(offset);
} else {
irq_set_handler_locked(d, handle_bad_irq);
pr_warn("Faraday IRQ: no supported trigger selected for line %d\n",
offset);
}
writel(mode, FT010_IRQ_MODE(f->base));
writel(polarity, FT010_IRQ_POLARITY(f->base));
return 0;
}
asmlinkage void __exception_irq_entry ft010_irqchip_handle_irq(struct pt_regs *regs)
{
struct ft010_irq_data *f = &firq;
int irq;
u32 status;
while ((status = readl(FT010_IRQ_STATUS(f->base)))) {
irq = ffs(status) - 1;
handle_domain_irq(f->domain, irq, regs);
}
}
static int ft010_irqdomain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct ft010_irq_data *f = d->host_data;
irq_set_chip_data(irq, f);
irq_set_chip_and_handler(irq, &ft010_irq_chip, handle_bad_irq);
irq_set_probe(irq);
return 0;
}
static void ft010_irqdomain_unmap(struct irq_domain *d, unsigned int irq)
{
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
int __init ft010_of_init_irq(struct device_node *node,
struct device_node *parent)
{
struct ft010_irq_data *f = &firq;
cpu_idle_poll_ctrl(true);
f->base = of_iomap(node, 0);
WARN(!f->base, "unable to map gemini irq registers\n");
writel(0, FT010_IRQ_MASK(f->base));
writel(0, FT010_FIQ_MASK(f->base));
f->domain = irq_domain_add_simple(node, FT010_NUM_IRQS, 0,
&ft010_irqdomain_ops, f);
set_handle_irq(ft010_irqchip_handle_irq);
return 0;
}
