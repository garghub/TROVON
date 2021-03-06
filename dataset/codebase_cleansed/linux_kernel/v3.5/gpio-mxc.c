static int gpio_set_irq_type(struct irq_data *d, u32 type)
{
u32 gpio = irq_to_gpio(d->irq);
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxc_gpio_port *port = gc->private;
u32 bit, val;
int edge;
void __iomem *reg = port->base;
port->both_edges &= ~(1 << (gpio & 31));
switch (type) {
case IRQ_TYPE_EDGE_RISING:
edge = GPIO_INT_RISE_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
edge = GPIO_INT_FALL_EDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
val = gpio_get_value(gpio);
if (val) {
edge = GPIO_INT_LOW_LEV;
pr_debug("mxc: set GPIO %d to low trigger\n", gpio);
} else {
edge = GPIO_INT_HIGH_LEV;
pr_debug("mxc: set GPIO %d to high trigger\n", gpio);
}
port->both_edges |= 1 << (gpio & 31);
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
reg += GPIO_ICR1 + ((gpio & 0x10) >> 2);
bit = gpio & 0xf;
val = readl(reg) & ~(0x3 << (bit << 1));
writel(val | (edge << (bit << 1)), reg);
writel(1 << (gpio & 0x1f), port->base + GPIO_ISR);
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
u32 gpio_irq_no_base = port->virtual_irq_start;
while (irq_stat != 0) {
int irqoffset = fls(irq_stat) - 1;
if (port->both_edges & (1 << irqoffset))
mxc_flip_edge(port, irqoffset);
generic_handle_irq(gpio_irq_no_base + irqoffset);
irq_stat &= ~(1 << irqoffset);
}
}
static void mx3_gpio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 irq_stat;
struct mxc_gpio_port *port = irq_get_handler_data(irq);
struct irq_chip *chip = irq_get_chip(irq);
chained_irq_enter(chip, desc);
irq_stat = readl(port->base + GPIO_ISR) & readl(port->base + GPIO_IMR);
mxc_gpio_irq_handler(port, irq_stat);
chained_irq_exit(chip, desc);
}
static void mx2_gpio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 irq_msk, irq_stat;
struct mxc_gpio_port *port;
list_for_each_entry(port, &mxc_gpio_ports, node) {
irq_msk = readl(port->base + GPIO_IMR);
if (!irq_msk)
continue;
irq_stat = readl(port->base + GPIO_ISR) & irq_msk;
if (irq_stat)
mxc_gpio_irq_handler(port, irq_stat);
}
}
static int gpio_set_wake_irq(struct irq_data *d, u32 enable)
{
u32 gpio = irq_to_gpio(d->irq);
u32 gpio_idx = gpio & 0x1F;
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mxc_gpio_port *port = gc->private;
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
static void __init mxc_gpio_init_gc(struct mxc_gpio_port *port)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("gpio-mxc", 1, port->virtual_irq_start,
port->base, handle_level_irq);
gc->private = port;
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_set_type = gpio_set_irq_type;
ct->chip.irq_set_wake = gpio_set_wake_irq;
ct->regs.ack = GPIO_ISR;
ct->regs.mask = GPIO_IMR;
irq_setup_generic_chip(gc, IRQ_MSK(32), IRQ_GC_INIT_NESTED_LOCK,
IRQ_NOREQUEST, 0);
}
static void __devinit mxc_gpio_get_hw(struct platform_device *pdev)
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
if (hwtype == IMX31_GPIO)
mxc_gpio_hwdata = &imx31_gpio_hwdata;
else
mxc_gpio_hwdata = &imx1_imx21_gpio_hwdata;
mxc_gpio_hwtype = hwtype;
}
static int mxc_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
struct mxc_gpio_port *port =
container_of(bgc, struct mxc_gpio_port, bgc);
return port->virtual_irq_start + offset;
}
static int __devinit mxc_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mxc_gpio_port *port;
struct resource *iores;
int err;
mxc_gpio_get_hw(pdev);
port = kzalloc(sizeof(struct mxc_gpio_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
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
port->base = ioremap(iores->start, resource_size(iores));
if (!port->base) {
err = -ENOMEM;
goto out_release_mem;
}
port->irq_high = platform_get_irq(pdev, 1);
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0) {
err = -EINVAL;
goto out_iounmap;
}
writel(0, port->base + GPIO_IMR);
writel(~0, port->base + GPIO_ISR);
if (mxc_gpio_hwtype == IMX21_GPIO) {
irq_set_chained_handler(port->irq, mx2_gpio_irq_handler);
} else {
irq_set_chained_handler(port->irq, mx3_gpio_irq_handler);
irq_set_handler_data(port->irq, port);
if (port->irq_high > 0) {
irq_set_chained_handler(port->irq_high,
mx3_gpio_irq_handler);
irq_set_handler_data(port->irq_high, port);
}
}
err = bgpio_init(&port->bgc, &pdev->dev, 4,
port->base + GPIO_PSR,
port->base + GPIO_DR, NULL,
port->base + GPIO_GDIR, NULL, 0);
if (err)
goto out_iounmap;
port->bgc.gc.to_irq = mxc_gpio_to_irq;
port->bgc.gc.base = pdev->id * 32;
port->bgc.dir = port->bgc.read_reg(port->bgc.reg_dir);
port->bgc.data = port->bgc.read_reg(port->bgc.reg_set);
err = gpiochip_add(&port->bgc.gc);
if (err)
goto out_bgpio_remove;
port->virtual_irq_start = MXC_GPIO_IRQ_START + (np ? port->bgc.gc.base :
pdev->id * 32);
mxc_gpio_init_gc(port);
list_add_tail(&port->node, &mxc_gpio_ports);
return 0;
out_bgpio_remove:
bgpio_remove(&port->bgc);
out_iounmap:
iounmap(port->base);
out_release_mem:
release_mem_region(iores->start, resource_size(iores));
out_kfree:
kfree(port);
dev_info(&pdev->dev, "%s failed with errno %d\n", __func__, err);
return err;
}
static int __init gpio_mxc_init(void)
{
return platform_driver_register(&mxc_gpio_driver);
}
