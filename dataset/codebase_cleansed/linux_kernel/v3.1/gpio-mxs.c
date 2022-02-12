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
pin_addr = port->base + PINCTRL_IRQLEV(port->id);
if (edge & GPIO_INT_LEV_MASK)
writel(pin_mask, pin_addr + MXS_SET);
else
writel(pin_mask, pin_addr + MXS_CLR);
pin_addr = port->base + PINCTRL_IRQPOL(port->id);
if (edge & GPIO_INT_POL_MASK)
writel(pin_mask, pin_addr + MXS_SET);
else
writel(pin_mask, pin_addr + MXS_CLR);
writel(1 << (gpio & 0x1f),
port->base + PINCTRL_IRQSTAT(port->id) + MXS_CLR);
return 0;
}
static void mxs_gpio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 irq_stat;
struct mxs_gpio_port *port = irq_get_handler_data(irq);
u32 gpio_irq_no_base = port->virtual_irq_start;
desc->irq_data.chip->irq_ack(&desc->irq_data);
irq_stat = readl(port->base + PINCTRL_IRQSTAT(port->id)) &
readl(port->base + PINCTRL_IRQEN(port->id));
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
ct->regs.ack = PINCTRL_IRQSTAT(port->id) + MXS_CLR;
ct->regs.mask = PINCTRL_IRQEN(port->id);
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
static void __iomem *base;
struct mxs_gpio_port *port;
struct resource *iores = NULL;
int err;
port = kzalloc(sizeof(struct mxs_gpio_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
port->id = pdev->id;
port->virtual_irq_start = MXS_GPIO_IRQ_START + port->id * 32;
if (!base) {
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores) {
err = -ENODEV;
goto out_kfree;
}
if (!request_mem_region(iores->start, resource_size(iores),
pdev->name)) {
err = -EBUSY;
goto out_kfree;
}
base = ioremap(iores->start, resource_size(iores));
if (!base) {
err = -ENOMEM;
goto out_release_mem;
}
}
port->base = base;
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0) {
err = -EINVAL;
goto out_iounmap;
}
writel(~0U, port->base + PINCTRL_PIN2IRQ(port->id));
writel(0, port->base + PINCTRL_IRQEN(port->id));
writel(~0U, port->base + PINCTRL_IRQSTAT(port->id) + MXS_CLR);
mxs_gpio_init_gc(port);
irq_set_chained_handler(port->irq, mxs_gpio_irq_handler);
irq_set_handler_data(port->irq, port);
err = bgpio_init(&port->bgc, &pdev->dev, 4,
port->base + PINCTRL_DIN(port->id),
port->base + PINCTRL_DOUT(port->id), NULL,
port->base + PINCTRL_DOE(port->id), NULL, false);
if (err)
goto out_iounmap;
port->bgc.gc.to_irq = mxs_gpio_to_irq;
port->bgc.gc.base = port->id * 32;
err = gpiochip_add(&port->bgc.gc);
if (err)
goto out_bgpio_remove;
return 0;
out_bgpio_remove:
bgpio_remove(&port->bgc);
out_iounmap:
if (iores)
iounmap(port->base);
out_release_mem:
if (iores)
release_mem_region(iores->start, resource_size(iores));
out_kfree:
kfree(port);
dev_info(&pdev->dev, "%s failed with errno %d\n", __func__, err);
return err;
}
static int __init mxs_gpio_init(void)
{
return platform_driver_register(&mxs_gpio_driver);
}
