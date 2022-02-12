static void ftgpio_gpio_ack_irq(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct ftgpio_gpio *g = gpiochip_get_data(gc);
writel(BIT(irqd_to_hwirq(d)), g->base + GPIO_INT_CLR);
}
static void ftgpio_gpio_mask_irq(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct ftgpio_gpio *g = gpiochip_get_data(gc);
u32 val;
val = readl(g->base + GPIO_INT_EN);
val &= ~BIT(irqd_to_hwirq(d));
writel(val, g->base + GPIO_INT_EN);
}
static void ftgpio_gpio_unmask_irq(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct ftgpio_gpio *g = gpiochip_get_data(gc);
u32 val;
val = readl(g->base + GPIO_INT_EN);
val |= BIT(irqd_to_hwirq(d));
writel(val, g->base + GPIO_INT_EN);
}
static int ftgpio_gpio_set_irq_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct ftgpio_gpio *g = gpiochip_get_data(gc);
u32 mask = BIT(irqd_to_hwirq(d));
u32 reg_both, reg_level, reg_type;
reg_type = readl(g->base + GPIO_INT_TYPE);
reg_level = readl(g->base + GPIO_INT_LEVEL);
reg_both = readl(g->base + GPIO_INT_BOTH_EDGE);
switch (type) {
case IRQ_TYPE_EDGE_BOTH:
irq_set_handler_locked(d, handle_edge_irq);
reg_type &= ~mask;
reg_both |= mask;
break;
case IRQ_TYPE_EDGE_RISING:
irq_set_handler_locked(d, handle_edge_irq);
reg_type &= ~mask;
reg_both &= ~mask;
reg_level &= ~mask;
break;
case IRQ_TYPE_EDGE_FALLING:
irq_set_handler_locked(d, handle_edge_irq);
reg_type &= ~mask;
reg_both &= ~mask;
reg_level |= mask;
break;
case IRQ_TYPE_LEVEL_HIGH:
irq_set_handler_locked(d, handle_level_irq);
reg_type |= mask;
reg_level &= ~mask;
break;
case IRQ_TYPE_LEVEL_LOW:
irq_set_handler_locked(d, handle_level_irq);
reg_type |= mask;
reg_level |= mask;
break;
default:
irq_set_handler_locked(d, handle_bad_irq);
return -EINVAL;
}
writel(reg_type, g->base + GPIO_INT_TYPE);
writel(reg_level, g->base + GPIO_INT_LEVEL);
writel(reg_both, g->base + GPIO_INT_BOTH_EDGE);
ftgpio_gpio_ack_irq(d);
return 0;
}
static void ftgpio_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct ftgpio_gpio *g = gpiochip_get_data(gc);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
int offset;
unsigned long stat;
chained_irq_enter(irqchip, desc);
stat = readl(g->base + GPIO_INT_STAT);
if (stat)
for_each_set_bit(offset, &stat, gc->ngpio)
generic_handle_irq(irq_find_mapping(gc->irqdomain,
offset));
chained_irq_exit(irqchip, desc);
}
static int ftgpio_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct ftgpio_gpio *g;
int irq;
int ret;
g = devm_kzalloc(dev, sizeof(*g), GFP_KERNEL);
if (!g)
return -ENOMEM;
g->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
g->base = devm_ioremap_resource(dev, res);
if (IS_ERR(g->base))
return PTR_ERR(g->base);
irq = platform_get_irq(pdev, 0);
if (!irq)
return -EINVAL;
ret = bgpio_init(&g->gc, dev, 4,
g->base + GPIO_DATA_IN,
g->base + GPIO_DATA_SET,
g->base + GPIO_DATA_CLR,
g->base + GPIO_DIR,
NULL,
0);
if (ret) {
dev_err(dev, "unable to init generic GPIO\n");
return ret;
}
g->gc.label = "FTGPIO010";
g->gc.base = -1;
g->gc.parent = dev;
g->gc.owner = THIS_MODULE;
ret = devm_gpiochip_add_data(dev, &g->gc, g);
if (ret)
return ret;
writel(0x0, g->base + GPIO_INT_EN);
writel(0x0, g->base + GPIO_INT_MASK);
writel(~0x0, g->base + GPIO_INT_CLR);
ret = gpiochip_irqchip_add(&g->gc, &ftgpio_gpio_irqchip,
0, handle_bad_irq,
IRQ_TYPE_NONE);
if (ret) {
dev_info(dev, "could not add irqchip\n");
return ret;
}
gpiochip_set_chained_irqchip(&g->gc, &ftgpio_gpio_irqchip,
irq, ftgpio_gpio_irq_handler);
dev_info(dev, "FTGPIO010 @%p registered\n", g->base);
return 0;
}
