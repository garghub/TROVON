static void ath79_misc_irq_handler(struct irq_desc *desc)
{
struct irq_domain *domain = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
void __iomem *base = domain->host_data;
u32 pending;
chained_irq_enter(chip, desc);
pending = __raw_readl(base + AR71XX_RESET_REG_MISC_INT_STATUS) &
__raw_readl(base + AR71XX_RESET_REG_MISC_INT_ENABLE);
if (!pending) {
spurious_interrupt();
chained_irq_exit(chip, desc);
return;
}
while (pending) {
int bit = __ffs(pending);
generic_handle_irq(irq_linear_revmap(domain, bit));
pending &= ~BIT(bit);
}
chained_irq_exit(chip, desc);
}
static void ar71xx_misc_irq_unmask(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->hwirq;
u32 t;
t = __raw_readl(base + AR71XX_RESET_REG_MISC_INT_ENABLE);
__raw_writel(t | BIT(irq), base + AR71XX_RESET_REG_MISC_INT_ENABLE);
__raw_readl(base + AR71XX_RESET_REG_MISC_INT_ENABLE);
}
static void ar71xx_misc_irq_mask(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->hwirq;
u32 t;
t = __raw_readl(base + AR71XX_RESET_REG_MISC_INT_ENABLE);
__raw_writel(t & ~BIT(irq), base + AR71XX_RESET_REG_MISC_INT_ENABLE);
__raw_readl(base + AR71XX_RESET_REG_MISC_INT_ENABLE);
}
static void ar724x_misc_irq_ack(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->hwirq;
u32 t;
t = __raw_readl(base + AR71XX_RESET_REG_MISC_INT_STATUS);
__raw_writel(t & ~BIT(irq), base + AR71XX_RESET_REG_MISC_INT_STATUS);
__raw_readl(base + AR71XX_RESET_REG_MISC_INT_STATUS);
}
static int misc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &ath79_misc_irq_chip, handle_level_irq);
irq_set_chip_data(irq, d->host_data);
return 0;
}
static void __init ath79_misc_intc_domain_init(
struct irq_domain *domain, int irq)
{
void __iomem *base = domain->host_data;
__raw_writel(0, base + AR71XX_RESET_REG_MISC_INT_ENABLE);
__raw_writel(0, base + AR71XX_RESET_REG_MISC_INT_STATUS);
irq_set_chained_handler_and_data(irq, ath79_misc_irq_handler, domain);
}
static int __init ath79_misc_intc_of_init(
struct device_node *node, struct device_node *parent)
{
struct irq_domain *domain;
void __iomem *base;
int irq;
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
pr_err("Failed to get MISC IRQ\n");
return -EINVAL;
}
base = of_iomap(node, 0);
if (!base) {
pr_err("Failed to get MISC IRQ registers\n");
return -ENOMEM;
}
domain = irq_domain_add_linear(node, ATH79_MISC_IRQ_COUNT,
&misc_irq_domain_ops, base);
if (!domain) {
pr_err("Failed to add MISC irqdomain\n");
return -EINVAL;
}
ath79_misc_intc_domain_init(domain, irq);
return 0;
}
static int __init ar7100_misc_intc_of_init(
struct device_node *node, struct device_node *parent)
{
ath79_misc_irq_chip.irq_mask_ack = ar71xx_misc_irq_mask;
return ath79_misc_intc_of_init(node, parent);
}
static int __init ar7240_misc_intc_of_init(
struct device_node *node, struct device_node *parent)
{
ath79_misc_irq_chip.irq_ack = ar724x_misc_irq_ack;
return ath79_misc_intc_of_init(node, parent);
}
void __init ath79_misc_irq_init(void __iomem *regs, int irq,
int irq_base, bool is_ar71xx)
{
struct irq_domain *domain;
if (is_ar71xx)
ath79_misc_irq_chip.irq_mask_ack = ar71xx_misc_irq_mask;
else
ath79_misc_irq_chip.irq_ack = ar724x_misc_irq_ack;
domain = irq_domain_add_legacy(NULL, ATH79_MISC_IRQ_COUNT,
irq_base, 0, &misc_irq_domain_ops, regs);
if (!domain)
panic("Failed to create MISC irqdomain");
ath79_misc_intc_domain_init(domain, irq);
}
