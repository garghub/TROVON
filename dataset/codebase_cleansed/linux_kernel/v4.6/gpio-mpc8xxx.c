static int mpc8572_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
u32 val;
struct mpc8xxx_gpio_chip *mpc8xxx_gc = gpiochip_get_data(gc);
u32 out_mask, out_shadow;
out_mask = gc->read_reg(mpc8xxx_gc->regs + GPIO_DIR);
val = gc->read_reg(mpc8xxx_gc->regs + GPIO_DAT) & ~out_mask;
out_shadow = gc->bgpio_data & out_mask;
return !!((val | out_shadow) & gc->pin2mask(gc, gpio));
}
static int mpc5121_gpio_dir_out(struct gpio_chip *gc,
unsigned int gpio, int val)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = gpiochip_get_data(gc);
if (gpio >= 28)
return -EINVAL;
return mpc8xxx_gc->direction_output(gc, gpio, val);
}
static int mpc5125_gpio_dir_out(struct gpio_chip *gc,
unsigned int gpio, int val)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = gpiochip_get_data(gc);
if (gpio <= 3)
return -EINVAL;
return mpc8xxx_gc->direction_output(gc, gpio, val);
}
static int mpc8xxx_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = gpiochip_get_data(gc);
if (mpc8xxx_gc->irq && offset < MPC8XXX_GPIO_PINS)
return irq_create_mapping(mpc8xxx_gc->irq, offset);
else
return -ENXIO;
}
static void mpc8xxx_gpio_irq_cascade(struct irq_desc *desc)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
unsigned int mask;
mask = gc->read_reg(mpc8xxx_gc->regs + GPIO_IER)
& gc->read_reg(mpc8xxx_gc->regs + GPIO_IMR);
if (mask)
generic_handle_irq(irq_linear_revmap(mpc8xxx_gc->irq,
32 - ffs(mask)));
if (chip->irq_eoi)
chip->irq_eoi(&desc->irq_data);
}
static void mpc8xxx_irq_unmask(struct irq_data *d)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_data_get_irq_chip_data(d);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
unsigned long flags;
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(mpc8xxx_gc->regs + GPIO_IMR,
gc->read_reg(mpc8xxx_gc->regs + GPIO_IMR)
| gc->pin2mask(gc, irqd_to_hwirq(d)));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
}
static void mpc8xxx_irq_mask(struct irq_data *d)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_data_get_irq_chip_data(d);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
unsigned long flags;
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(mpc8xxx_gc->regs + GPIO_IMR,
gc->read_reg(mpc8xxx_gc->regs + GPIO_IMR)
& ~(gc->pin2mask(gc, irqd_to_hwirq(d))));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
}
static void mpc8xxx_irq_ack(struct irq_data *d)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_data_get_irq_chip_data(d);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
gc->write_reg(mpc8xxx_gc->regs + GPIO_IER,
gc->pin2mask(gc, irqd_to_hwirq(d)));
}
static int mpc8xxx_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_data_get_irq_chip_data(d);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
unsigned long flags;
switch (flow_type) {
case IRQ_TYPE_EDGE_FALLING:
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(mpc8xxx_gc->regs + GPIO_ICR,
gc->read_reg(mpc8xxx_gc->regs + GPIO_ICR)
| gc->pin2mask(gc, irqd_to_hwirq(d)));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
break;
case IRQ_TYPE_EDGE_BOTH:
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(mpc8xxx_gc->regs + GPIO_ICR,
gc->read_reg(mpc8xxx_gc->regs + GPIO_ICR)
& ~(gc->pin2mask(gc, irqd_to_hwirq(d))));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
break;
default:
return -EINVAL;
}
return 0;
}
static int mpc512x_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = irq_data_get_irq_chip_data(d);
struct gpio_chip *gc = &mpc8xxx_gc->gc;
unsigned long gpio = irqd_to_hwirq(d);
void __iomem *reg;
unsigned int shift;
unsigned long flags;
if (gpio < 16) {
reg = mpc8xxx_gc->regs + GPIO_ICR;
shift = (15 - gpio) * 2;
} else {
reg = mpc8xxx_gc->regs + GPIO_ICR2;
shift = (15 - (gpio % 16)) * 2;
}
switch (flow_type) {
case IRQ_TYPE_EDGE_FALLING:
case IRQ_TYPE_LEVEL_LOW:
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(reg, (gc->read_reg(reg) & ~(3 << shift))
| (2 << shift));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
break;
case IRQ_TYPE_EDGE_RISING:
case IRQ_TYPE_LEVEL_HIGH:
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(reg, (gc->read_reg(reg) & ~(3 << shift))
| (1 << shift));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
break;
case IRQ_TYPE_EDGE_BOTH:
raw_spin_lock_irqsave(&mpc8xxx_gc->lock, flags);
gc->write_reg(reg, (gc->read_reg(reg) & ~(3 << shift)));
raw_spin_unlock_irqrestore(&mpc8xxx_gc->lock, flags);
break;
default:
return -EINVAL;
}
return 0;
}
static int mpc8xxx_gpio_irq_map(struct irq_domain *h, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_data(irq, h->host_data);
irq_set_chip_and_handler(irq, &mpc8xxx_irq_chip, handle_level_irq);
return 0;
}
static int mpc8xxx_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mpc8xxx_gpio_chip *mpc8xxx_gc;
struct gpio_chip *gc;
const struct mpc8xxx_gpio_devtype *devtype =
of_device_get_match_data(&pdev->dev);
int ret;
mpc8xxx_gc = devm_kzalloc(&pdev->dev, sizeof(*mpc8xxx_gc), GFP_KERNEL);
if (!mpc8xxx_gc)
return -ENOMEM;
platform_set_drvdata(pdev, mpc8xxx_gc);
raw_spin_lock_init(&mpc8xxx_gc->lock);
mpc8xxx_gc->regs = of_iomap(np, 0);
if (!mpc8xxx_gc->regs)
return -ENOMEM;
gc = &mpc8xxx_gc->gc;
if (of_property_read_bool(np, "little-endian")) {
ret = bgpio_init(gc, &pdev->dev, 4,
mpc8xxx_gc->regs + GPIO_DAT,
NULL, NULL,
mpc8xxx_gc->regs + GPIO_DIR, NULL,
BGPIOF_BIG_ENDIAN);
if (ret)
goto err;
dev_dbg(&pdev->dev, "GPIO registers are LITTLE endian\n");
} else {
ret = bgpio_init(gc, &pdev->dev, 4,
mpc8xxx_gc->regs + GPIO_DAT,
NULL, NULL,
mpc8xxx_gc->regs + GPIO_DIR, NULL,
BGPIOF_BIG_ENDIAN
| BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (ret)
goto err;
dev_dbg(&pdev->dev, "GPIO registers are BIG endian\n");
}
mpc8xxx_gc->direction_output = gc->direction_output;
if (!devtype)
devtype = &mpc8xxx_gpio_devtype_default;
mpc8xxx_irq_chip.irq_set_type = devtype->irq_set_type;
if (devtype->gpio_dir_out)
gc->direction_output = devtype->gpio_dir_out;
if (devtype->gpio_get)
gc->get = devtype->gpio_get;
gc->to_irq = mpc8xxx_gpio_to_irq;
ret = gpiochip_add_data(gc, mpc8xxx_gc);
if (ret) {
pr_err("%s: GPIO chip registration failed with status %d\n",
np->full_name, ret);
goto err;
}
mpc8xxx_gc->irqn = irq_of_parse_and_map(np, 0);
if (!mpc8xxx_gc->irqn)
return 0;
mpc8xxx_gc->irq = irq_domain_add_linear(np, MPC8XXX_GPIO_PINS,
&mpc8xxx_gpio_irq_ops, mpc8xxx_gc);
if (!mpc8xxx_gc->irq)
return 0;
gc->write_reg(mpc8xxx_gc->regs + GPIO_IER, 0xffffffff);
gc->write_reg(mpc8xxx_gc->regs + GPIO_IMR, 0);
irq_set_chained_handler_and_data(mpc8xxx_gc->irqn,
mpc8xxx_gpio_irq_cascade, mpc8xxx_gc);
return 0;
err:
iounmap(mpc8xxx_gc->regs);
return ret;
}
static int mpc8xxx_remove(struct platform_device *pdev)
{
struct mpc8xxx_gpio_chip *mpc8xxx_gc = platform_get_drvdata(pdev);
if (mpc8xxx_gc->irq) {
irq_set_chained_handler_and_data(mpc8xxx_gc->irqn, NULL, NULL);
irq_domain_remove(mpc8xxx_gc->irq);
}
gpiochip_remove(&mpc8xxx_gc->gc);
iounmap(mpc8xxx_gc->regs);
return 0;
}
static int __init mpc8xxx_init(void)
{
return platform_driver_register(&mpc8xxx_plat_driver);
}
