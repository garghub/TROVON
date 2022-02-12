static int sa1100_gpio_get(struct gpio_chip *chip, unsigned offset)
{
return readl_relaxed(sa1100_gpio_chip(chip)->membase + R_GPLR) &
BIT(offset);
}
static void sa1100_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
int reg = value ? R_GPSR : R_GPCR;
writel_relaxed(BIT(offset), sa1100_gpio_chip(chip)->membase + reg);
}
static int sa1100_get_direction(struct gpio_chip *chip, unsigned offset)
{
void __iomem *gpdr = sa1100_gpio_chip(chip)->membase + R_GPDR;
return !(readl_relaxed(gpdr) & BIT(offset));
}
static int sa1100_direction_input(struct gpio_chip *chip, unsigned offset)
{
void __iomem *gpdr = sa1100_gpio_chip(chip)->membase + R_GPDR;
unsigned long flags;
local_irq_save(flags);
writel_relaxed(readl_relaxed(gpdr) & ~BIT(offset), gpdr);
local_irq_restore(flags);
return 0;
}
static int sa1100_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
void __iomem *gpdr = sa1100_gpio_chip(chip)->membase + R_GPDR;
unsigned long flags;
local_irq_save(flags);
sa1100_gpio_set(chip, offset, value);
writel_relaxed(readl_relaxed(gpdr) | BIT(offset), gpdr);
local_irq_restore(flags);
return 0;
}
static int sa1100_to_irq(struct gpio_chip *chip, unsigned offset)
{
return sa1100_gpio_chip(chip)->irqbase + offset;
}
static void sa1100_update_edge_regs(struct sa1100_gpio_chip *sgc)
{
void *base = sgc->membase;
u32 grer, gfer;
grer = sgc->irqrising & sgc->irqmask;
gfer = sgc->irqfalling & sgc->irqmask;
writel_relaxed(grer, base + R_GRER);
writel_relaxed(gfer, base + R_GFER);
}
static int sa1100_gpio_type(struct irq_data *d, unsigned int type)
{
struct sa1100_gpio_chip *sgc = irq_data_get_irq_chip_data(d);
unsigned int mask = BIT(d->hwirq);
if (type == IRQ_TYPE_PROBE) {
if ((sgc->irqrising | sgc->irqfalling) & mask)
return 0;
type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
}
if (type & IRQ_TYPE_EDGE_RISING)
sgc->irqrising |= mask;
else
sgc->irqrising &= ~mask;
if (type & IRQ_TYPE_EDGE_FALLING)
sgc->irqfalling |= mask;
else
sgc->irqfalling &= ~mask;
sa1100_update_edge_regs(sgc);
return 0;
}
static void sa1100_gpio_ack(struct irq_data *d)
{
struct sa1100_gpio_chip *sgc = irq_data_get_irq_chip_data(d);
writel_relaxed(BIT(d->hwirq), sgc->membase + R_GEDR);
}
static void sa1100_gpio_mask(struct irq_data *d)
{
struct sa1100_gpio_chip *sgc = irq_data_get_irq_chip_data(d);
unsigned int mask = BIT(d->hwirq);
sgc->irqmask &= ~mask;
sa1100_update_edge_regs(sgc);
}
static void sa1100_gpio_unmask(struct irq_data *d)
{
struct sa1100_gpio_chip *sgc = irq_data_get_irq_chip_data(d);
unsigned int mask = BIT(d->hwirq);
sgc->irqmask |= mask;
sa1100_update_edge_regs(sgc);
}
static int sa1100_gpio_wake(struct irq_data *d, unsigned int on)
{
struct sa1100_gpio_chip *sgc = irq_data_get_irq_chip_data(d);
int ret = sa11x0_gpio_set_wake(d->hwirq, on);
if (!ret) {
if (on)
sgc->irqwake |= BIT(d->hwirq);
else
sgc->irqwake &= ~BIT(d->hwirq);
}
return ret;
}
static int sa1100_gpio_irqdomain_map(struct irq_domain *d,
unsigned int irq, irq_hw_number_t hwirq)
{
struct sa1100_gpio_chip *sgc = d->host_data;
irq_set_chip_data(irq, sgc);
irq_set_chip_and_handler(irq, &sa1100_gpio_irq_chip, handle_edge_irq);
irq_set_probe(irq);
return 0;
}
static void sa1100_gpio_handler(struct irq_desc *desc)
{
struct sa1100_gpio_chip *sgc = irq_desc_get_handler_data(desc);
unsigned int irq, mask;
void __iomem *gedr = sgc->membase + R_GEDR;
mask = readl_relaxed(gedr);
do {
writel_relaxed(mask, gedr);
irq = sgc->irqbase;
do {
if (mask & 1)
generic_handle_irq(irq);
mask >>= 1;
irq++;
} while (mask);
mask = readl_relaxed(gedr);
} while (mask);
}
static int sa1100_gpio_suspend(void)
{
struct sa1100_gpio_chip *sgc = &sa1100_gpio_chip;
writel_relaxed(sgc->irqwake & sgc->irqrising, sgc->membase + R_GRER);
writel_relaxed(sgc->irqwake & sgc->irqfalling, sgc->membase + R_GFER);
writel_relaxed(readl_relaxed(sgc->membase + R_GEDR),
sgc->membase + R_GEDR);
return 0;
}
static void sa1100_gpio_resume(void)
{
sa1100_update_edge_regs(&sa1100_gpio_chip);
}
static int __init sa1100_gpio_init_devicefs(void)
{
register_syscore_ops(&sa1100_gpio_syscore_ops);
return 0;
}
void __init sa1100_init_gpio(void)
{
struct sa1100_gpio_chip *sgc = &sa1100_gpio_chip;
int i;
writel_relaxed(0, sgc->membase + R_GFER);
writel_relaxed(0, sgc->membase + R_GRER);
writel_relaxed(-1, sgc->membase + R_GEDR);
gpiochip_add_data(&sa1100_gpio_chip.chip, NULL);
sa1100_gpio_irqdomain = irq_domain_add_simple(NULL,
28, IRQ_GPIO0,
&sa1100_gpio_irqdomain_ops, sgc);
for (i = 0; i < ARRAY_SIZE(sa1100_gpio_irqs); i++)
irq_set_chained_handler_and_data(sa1100_gpio_irqs[i],
sa1100_gpio_handler, sgc);
}
