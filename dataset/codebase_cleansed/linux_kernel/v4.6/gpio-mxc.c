static int gpio_set_irq_type(struct irq_data *d, u32 type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxc_gpio_port *port = gc->private;
u32 bit, val;
u32 gpio_idx = d->hwirq;
u32 gpio = port->gc.base + gpio_idx;
int edge;
void __iomem *reg = port->base;
port->both_edges &= ~(1 << gpio_idx);
switch (type) {
case IRQ_TYPE_EDGE_RISING:
edge = GPIO_INT_RISE_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
edge = GPIO_INT_FALL_EDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
if (GPIO_EDGE_SEL >= 0) {
edge = GPIO_INT_BOTH_EDGES;
} else {
val = gpio_get_value(gpio);
if (val) {
edge = GPIO_INT_LOW_LEV;
pr_debug("mxc: set GPIO %d to low trigger\n", gpio);
} else {
edge = GPIO_INT_HIGH_LEV;
pr_debug("mxc: set GPIO %d to high trigger\n", gpio);
}
port->both_edges |= 1 << gpio_idx;
}
break;
case IRQ_TYPE_LEVEL_LOW:
edge = GPIO_INT_LOW_LEV;
break;
case IRQ_TYPE_LEVEL_HIGH:
edge = GPIO_INT_HIGH_LEV;
break;
default:
return -EINVAL;
}
if (GPIO_EDGE_SEL >= 0) {
val = readl(port->base + GPIO_EDGE_SEL);
if (edge == GPIO_INT_BOTH_EDGES)
writel(val | (1 << gpio_idx),
port->base + GPIO_EDGE_SEL);
else
writel(val & ~(1 << gpio_idx),
port->base + GPIO_EDGE_SEL);
}
if (edge != GPIO_INT_BOTH_EDGES) {
reg += GPIO_ICR1 + ((gpio_idx & 0x10) >> 2);
bit = gpio_idx & 0xf;
val = readl(reg) & ~(0x3 << (bit << 1));
writel(val | (edge << (bit << 1)), reg);
}
writel(1 << gpio_idx, port->base + GPIO_ISR);
return 0;
}
static void mxc_flip_edge(struct mxc_gpio_port *port, u32 gpio)
{
void __iomem *reg = port->base;
u32 bit, val;
int edge;
reg += GPIO_ICR1 + ((gpio & 0x10) >> 2);
bit = gpio & 0xf;
val = readl(reg);
edge = (val >> (bit << 1)) & 3;
val &= ~(0x3 << (bit << 1));
if (edge == GPIO_INT_HIGH_LEV) {
edge = GPIO_INT_LOW_LEV;
pr_debug("mxc: switch GPIO %d to low trigger\n", gpio);
} else if (edge == GPIO_INT_LOW_LEV) {
edge = GPIO_INT_HIGH_LEV;
pr_debug("mxc: switch GPIO %d to high trigger\n", gpio);
} else {
pr_err("mxc: invalid configuration for GPIO %d: %x\n",
gpio, edge);
return;
}
writel(val | (edge << (bit << 1)), reg);
}
static void mxc_gpio_irq_handler(struct mxc_gpio_port *port, u32 irq_stat)
{
while (irq_stat != 0) {
int irqoffset = fls(irq_stat) - 1;
if (port->both_edges & (1 << irqoffset))
mxc_flip_edge(port, irqoffset);
generic_handle_irq(irq_find_mapping(port->domain, irqoffset));
irq_stat &= ~(1 << irqoffset);
}
}
static void mx3_gpio_irq_handler(struct irq_desc *desc)
{
u32 irq_stat;
struct mxc_gpio_port *port = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
irq_stat = readl(port->base + GPIO_ISR) & readl(port->base + GPIO_IMR);
mxc_gpio_irq_handler(port, irq_stat);
chained_irq_exit(chip, desc);
}
static void mx2_gpio_irq_handler(struct irq_desc *desc)
{
u32 irq_msk, irq_stat;
struct mxc_gpio_port *port;
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
list_for_each_entry(port, &mxc_gpio_ports, node) {
irq_msk = readl(port->base + GPIO_IMR);
if (!irq_msk)
continue;
irq_stat = readl(port->base + GPIO_ISR) & irq_msk;
if (irq_stat)
mxc_gpio_irq_handler(port, irq_stat);
}
chained_irq_exit(chip, desc);
}
static int gpio_set_wake_irq(struct irq_data *d, u32 enable)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxc_gpio_port *port = gc->private;
u32 gpio_idx = d->hwirq;
if (enable) {
if (port->irq_high && (gpio_idx >= 16))
enable_irq_wake(port->irq_high);
else
enable_irq_wake(port->irq);
} else {
if (port->irq_high && (gpio_idx >= 16))
disable_irq_wake(port->irq_high);
else
disable_irq_wake(port->irq);
}
return 0;
}
static int mxc_gpio_init_gc(struct mxc_gpio_port *port, int irq_base)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("gpio-mxc", 1, irq_base,
port->base, handle_level_irq);
if (!gc)
return -ENOMEM;
gc->private = port;
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_set_type = gpio_set_irq_type;
ct->chip.irq_set_wake = gpio_set_wake_irq;
ct->chip.flags = IRQCHIP_MASK_ON_SUSPEND;
ct->regs.ack = GPIO_ISR;
ct->regs.mask = GPIO_IMR;
irq_setup_generic_chip(gc, IRQ_MSK(32), IRQ_GC_INIT_NESTED_LOCK,
IRQ_NOREQUEST, 0);
return 0;
}
static void mxc_gpio_get_hw(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxc_gpio_dt_ids, &pdev->dev);
enum mxc_gpio_hwtype hwtype;
if (of_id)
pdev->id_entry = of_id->data;
hwtype = pdev->id_entry->driver_data;
if (mxc_gpio_hwtype) {
BUG_ON(mxc_gpio_hwtype != hwtype);
return;
}
if (hwtype == IMX35_GPIO)
mxc_gpio_hwdata = &imx35_gpio_hwdata;
else if (hwtype == IMX31_GPIO)
mxc_gpio_hwdata = &imx31_gpio_hwdata;
else
mxc_gpio_hwdata = &imx1_imx21_gpio_hwdata;
mxc_gpio_hwtype = hwtype;
}
static int mxc_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct mxc_gpio_port *port = gpiochip_get_data(gc);
return irq_find_mapping(port->domain, offset);
}
static int mxc_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mxc_gpio_port *port;
struct resource *iores;
int irq_base;
int err;
mxc_gpio_get_hw(pdev);
port = devm_kzalloc(&pdev->dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
port->base = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(port->base))
return PTR_ERR(port->base);
port->irq_high = platform_get_irq(pdev, 1);
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0)
return port->irq;
writel(0, port->base + GPIO_IMR);
writel(~0, port->base + GPIO_ISR);
if (mxc_gpio_hwtype == IMX21_GPIO) {
irq_set_chained_handler(port->irq, mx2_gpio_irq_handler);
} else {
irq_set_chained_handler_and_data(port->irq,
mx3_gpio_irq_handler, port);
if (port->irq_high > 0)
irq_set_chained_handler_and_data(port->irq_high,
mx3_gpio_irq_handler,
port);
}
err = bgpio_init(&port->gc, &pdev->dev, 4,
port->base + GPIO_PSR,
port->base + GPIO_DR, NULL,
port->base + GPIO_GDIR, NULL,
BGPIOF_READ_OUTPUT_REG_SET);
if (err)
goto out_bgio;
port->gc.to_irq = mxc_gpio_to_irq;
port->gc.base = (pdev->id < 0) ? of_alias_get_id(np, "gpio") * 32 :
pdev->id * 32;
err = devm_gpiochip_add_data(&pdev->dev, &port->gc, port);
if (err)
goto out_bgio;
irq_base = irq_alloc_descs(-1, 0, 32, numa_node_id());
if (irq_base < 0) {
err = irq_base;
goto out_bgio;
}
port->domain = irq_domain_add_legacy(np, 32, irq_base, 0,
&irq_domain_simple_ops, NULL);
if (!port->domain) {
err = -ENODEV;
goto out_irqdesc_free;
}
err = mxc_gpio_init_gc(port, irq_base);
if (err < 0)
goto out_irqdomain_remove;
list_add_tail(&port->node, &mxc_gpio_ports);
return 0;
out_irqdomain_remove:
irq_domain_remove(port->domain);
out_irqdesc_free:
irq_free_descs(irq_base, 32);
out_bgio:
dev_info(&pdev->dev, "%s failed with errno %d\n", __func__, err);
return err;
}
static int __init gpio_mxc_init(void)
{
return platform_driver_register(&mxc_gpio_driver);
}
