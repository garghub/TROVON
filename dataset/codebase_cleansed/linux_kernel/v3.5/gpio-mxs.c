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
u32 gpio = irq_to_gpio(d->irq);
u32 pin_mask = 1 << (gpio & 31);
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxs_gpio_port *port = gc->private;
void __iomem *pin_addr;
int edge;
switch (type) {
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
writel(1 << (gpio & 0x1f),
port->base + PINCTRL_IRQSTAT(port) + MXS_CLR);
return 0;
}
static void mxs_gpio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 irq_stat;
struct mxs_gpio_port *port = irq_get_handler_data(irq);
u32 gpio_irq_no_base = port->virtual_irq_start;
desc->irq_data.chip->irq_ack(&desc->irq_data);
irq_stat = readl(port->base + PINCTRL_IRQSTAT(port)) &
readl(port->base + PINCTRL_IRQEN(port));
while (irq_stat != 0) {
int irqoffset = fls(irq_stat) - 1;
generic_handle_irq(gpio_irq_no_base + irqoffset);
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
static void __init mxs_gpio_init_gc(struct mxs_gpio_port *port)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("gpio-mxs", 1, port->virtual_irq_start,
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
irq_setup_generic_chip(gc, IRQ_MSK(32), 0, IRQ_NOREQUEST, 0);
}
static int mxs_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
struct mxs_gpio_port *port =
container_of(bgc, struct mxs_gpio_port, bgc);
return port->virtual_irq_start + offset;
}
static int __devinit mxs_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxs_gpio_dt_ids, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
struct device_node *parent;
static void __iomem *base;
struct mxs_gpio_port *port;
struct resource *iores = NULL;
int err;
port = devm_kzalloc(&pdev->dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
if (np) {
port->id = of_alias_get_id(np, "gpio");
if (port->id < 0)
return port->id;
port->devid = (enum mxs_gpio_id) of_id->data;
} else {
port->id = pdev->id;
port->devid = pdev->id_entry->driver_data;
}
port->virtual_irq_start = MXS_GPIO_IRQ_START + port->id * 32;
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0)
return port->irq;
if (!base) {
if (np) {
parent = of_get_parent(np);
base = of_iomap(parent, 0);
of_node_put(parent);
} else {
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_request_and_ioremap(&pdev->dev, iores);
}
if (!base)
return -EADDRNOTAVAIL;
}
port->base = base;
writel(~0U, port->base + PINCTRL_PIN2IRQ(port));
writel(0, port->base + PINCTRL_IRQEN(port));
writel(~0U, port->base + PINCTRL_IRQSTAT(port) + MXS_CLR);
mxs_gpio_init_gc(port);
irq_set_chained_handler(port->irq, mxs_gpio_irq_handler);
irq_set_handler_data(port->irq, port);
err = bgpio_init(&port->bgc, &pdev->dev, 4,
port->base + PINCTRL_DIN(port),
port->base + PINCTRL_DOUT(port), NULL,
port->base + PINCTRL_DOE(port), NULL, 0);
if (err)
return err;
port->bgc.gc.to_irq = mxs_gpio_to_irq;
port->bgc.gc.base = port->id * 32;
err = gpiochip_add(&port->bgc.gc);
if (err) {
bgpio_remove(&port->bgc);
return err;
}
return 0;
}
static int __init mxs_gpio_init(void)
{
return platform_driver_register(&mxs_gpio_driver);
}
