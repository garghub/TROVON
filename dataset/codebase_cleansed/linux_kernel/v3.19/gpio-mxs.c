static inline int is_imx23_gpio(struct mxs_gpio_port *port)
{
return port->devid == IMX23_GPIO;
}
static inline int is_imx28_gpio(struct mxs_gpio_port *port)
{
return port->devid == IMX28_GPIO;
}
static int mxs_gpio_set_irq_type(struct irq_data *d, unsigned int type)
{
u32 val;
u32 pin_mask = 1 << d->hwirq;
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxs_gpio_port *port = gc->private;
void __iomem *pin_addr;
int edge;
port->both_edges &= ~pin_mask;
switch (type) {
case IRQ_TYPE_EDGE_BOTH:
val = gpio_get_value(port->bgc.gc.base + d->hwirq);
if (val)
edge = GPIO_INT_FALL_EDGE;
else
edge = GPIO_INT_RISE_EDGE;
port->both_edges |= pin_mask;
break;
case IRQ_TYPE_EDGE_RISING:
edge = GPIO_INT_RISE_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
edge = GPIO_INT_FALL_EDGE;
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
pin_addr = port->base + PINCTRL_IRQLEV(port);
if (edge & GPIO_INT_LEV_MASK)
writel(pin_mask, pin_addr + MXS_SET);
else
writel(pin_mask, pin_addr + MXS_CLR);
pin_addr = port->base + PINCTRL_IRQPOL(port);
if (edge & GPIO_INT_POL_MASK)
writel(pin_mask, pin_addr + MXS_SET);
else
writel(pin_mask, pin_addr + MXS_CLR);
writel(pin_mask,
port->base + PINCTRL_IRQSTAT(port) + MXS_CLR);
return 0;
}
static void mxs_flip_edge(struct mxs_gpio_port *port, u32 gpio)
{
u32 bit, val, edge;
void __iomem *pin_addr;
bit = 1 << gpio;
pin_addr = port->base + PINCTRL_IRQPOL(port);
val = readl(pin_addr);
edge = val & bit;
if (edge)
writel(bit, pin_addr + MXS_CLR);
else
writel(bit, pin_addr + MXS_SET);
}
static void mxs_gpio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 irq_stat;
struct mxs_gpio_port *port = irq_get_handler_data(irq);
desc->irq_data.chip->irq_ack(&desc->irq_data);
irq_stat = readl(port->base + PINCTRL_IRQSTAT(port)) &
readl(port->base + PINCTRL_IRQEN(port));
while (irq_stat != 0) {
int irqoffset = fls(irq_stat) - 1;
if (port->both_edges & (1 << irqoffset))
mxs_flip_edge(port, irqoffset);
generic_handle_irq(irq_find_mapping(port->domain, irqoffset));
irq_stat &= ~(1 << irqoffset);
}
}
static int mxs_gpio_set_wake_irq(struct irq_data *d, unsigned int enable)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxs_gpio_port *port = gc->private;
if (enable)
enable_irq_wake(port->irq);
else
disable_irq_wake(port->irq);
return 0;
}
static void __init mxs_gpio_init_gc(struct mxs_gpio_port *port, int irq_base)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("gpio-mxs", 1, irq_base,
port->base, handle_level_irq);
gc->private = port;
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_set_type = mxs_gpio_set_irq_type;
ct->chip.irq_set_wake = mxs_gpio_set_wake_irq;
ct->regs.ack = PINCTRL_IRQSTAT(port) + MXS_CLR;
ct->regs.mask = PINCTRL_IRQEN(port);
irq_setup_generic_chip(gc, IRQ_MSK(32), IRQ_GC_INIT_NESTED_LOCK,
IRQ_NOREQUEST, 0);
}
static int mxs_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
struct mxs_gpio_port *port =
container_of(bgc, struct mxs_gpio_port, bgc);
return irq_find_mapping(port->domain, offset);
}
static int mxs_gpio_get_direction(struct gpio_chip *gc, unsigned offset)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
struct mxs_gpio_port *port =
container_of(bgc, struct mxs_gpio_port, bgc);
u32 mask = 1 << offset;
u32 dir;
dir = readl(port->base + PINCTRL_DOE(port));
return !(dir & mask);
}
static int mxs_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxs_gpio_dt_ids, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
struct device_node *parent;
static void __iomem *base;
struct mxs_gpio_port *port;
int irq_base;
int err;
port = devm_kzalloc(&pdev->dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
port->id = of_alias_get_id(np, "gpio");
if (port->id < 0)
return port->id;
port->devid = (enum mxs_gpio_id) of_id->data;
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0)
return port->irq;
if (!base) {
parent = of_get_parent(np);
base = of_iomap(parent, 0);
of_node_put(parent);
if (!base)
return -EADDRNOTAVAIL;
}
port->base = base;
writel(~0U, port->base + PINCTRL_PIN2IRQ(port));
writel(0, port->base + PINCTRL_IRQEN(port));
writel(~0U, port->base + PINCTRL_IRQSTAT(port) + MXS_CLR);
irq_base = irq_alloc_descs(-1, 0, 32, numa_node_id());
if (irq_base < 0)
return irq_base;
port->domain = irq_domain_add_legacy(np, 32, irq_base, 0,
&irq_domain_simple_ops, NULL);
if (!port->domain) {
err = -ENODEV;
goto out_irqdesc_free;
}
mxs_gpio_init_gc(port, irq_base);
irq_set_chained_handler(port->irq, mxs_gpio_irq_handler);
irq_set_handler_data(port->irq, port);
err = bgpio_init(&port->bgc, &pdev->dev, 4,
port->base + PINCTRL_DIN(port),
port->base + PINCTRL_DOUT(port) + MXS_SET,
port->base + PINCTRL_DOUT(port) + MXS_CLR,
port->base + PINCTRL_DOE(port), NULL, 0);
if (err)
goto out_irqdesc_free;
port->bgc.gc.to_irq = mxs_gpio_to_irq;
port->bgc.gc.get_direction = mxs_gpio_get_direction;
port->bgc.gc.base = port->id * 32;
err = gpiochip_add(&port->bgc.gc);
if (err)
goto out_bgpio_remove;
return 0;
out_bgpio_remove:
bgpio_remove(&port->bgc);
out_irqdesc_free:
irq_free_descs(irq_base, 32);
return err;
}
static int __init mxs_gpio_init(void)
{
return platform_driver_register(&mxs_gpio_driver);
}
