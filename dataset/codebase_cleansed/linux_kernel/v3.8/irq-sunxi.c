void sunxi_irq_ack(struct irq_data *irqd)
{
unsigned int irq = irqd_to_hwirq(irqd);
unsigned int irq_off = irq % 32;
int reg = irq / 32;
u32 val;
val = readl(sunxi_irq_base + SUNXI_IRQ_PENDING_REG(reg));
writel(val | (1 << irq_off),
sunxi_irq_base + SUNXI_IRQ_PENDING_REG(reg));
}
static void sunxi_irq_mask(struct irq_data *irqd)
{
unsigned int irq = irqd_to_hwirq(irqd);
unsigned int irq_off = irq % 32;
int reg = irq / 32;
u32 val;
val = readl(sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(reg));
writel(val & ~(1 << irq_off),
sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(reg));
}
static void sunxi_irq_unmask(struct irq_data *irqd)
{
unsigned int irq = irqd_to_hwirq(irqd);
unsigned int irq_off = irq % 32;
int reg = irq / 32;
u32 val;
val = readl(sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(reg));
writel(val | (1 << irq_off),
sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(reg));
}
static int sunxi_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &sunxi_irq_chip,
handle_level_irq);
set_irq_flags(virq, IRQF_VALID | IRQF_PROBE);
return 0;
}
static int __init sunxi_of_init(struct device_node *node,
struct device_node *parent)
{
sunxi_irq_base = of_iomap(node, 0);
if (!sunxi_irq_base)
panic("%s: unable to map IC registers\n",
node->full_name);
writel(0, sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(0));
writel(0, sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(1));
writel(0, sunxi_irq_base + SUNXI_IRQ_ENABLE_REG(2));
writel(0, sunxi_irq_base + SUNXI_IRQ_MASK_REG(0));
writel(0, sunxi_irq_base + SUNXI_IRQ_MASK_REG(1));
writel(0, sunxi_irq_base + SUNXI_IRQ_MASK_REG(2));
writel(0xffffffff, sunxi_irq_base + SUNXI_IRQ_PENDING_REG(0));
writel(0xffffffff, sunxi_irq_base + SUNXI_IRQ_PENDING_REG(1));
writel(0xffffffff, sunxi_irq_base + SUNXI_IRQ_PENDING_REG(2));
writel(0x01, sunxi_irq_base + SUNXI_IRQ_PROTECTION_REG);
writel(0x00, sunxi_irq_base + SUNXI_IRQ_NMI_CTRL_REG);
sunxi_irq_domain = irq_domain_add_linear(node, 3 * 32,
&sunxi_irq_ops, NULL);
if (!sunxi_irq_domain)
panic("%s: unable to create IRQ domain\n", node->full_name);
return 0;
}
void __init sunxi_init_irq(void)
{
of_irq_init(sunxi_irq_dt_ids);
}
asmlinkage void __exception_irq_entry sunxi_handle_irq(struct pt_regs *regs)
{
u32 irq, hwirq;
hwirq = readl(sunxi_irq_base + SUNXI_IRQ_VECTOR_REG) >> 2;
while (hwirq != 0) {
irq = irq_find_mapping(sunxi_irq_domain, hwirq);
handle_IRQ(irq, regs);
hwirq = readl(sunxi_irq_base + SUNXI_IRQ_VECTOR_REG) >> 2;
}
}
