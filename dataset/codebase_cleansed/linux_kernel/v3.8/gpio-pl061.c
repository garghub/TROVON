static int pl061_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct pl061_gpio *chip = container_of(gc, struct pl061_gpio, gc);
unsigned long flags;
unsigned char gpiodir;
if (offset >= gc->ngpio)
return -EINVAL;
spin_lock_irqsave(&chip->lock, flags);
gpiodir = readb(chip->base + GPIODIR);
gpiodir &= ~(1 << offset);
writeb(gpiodir, chip->base + GPIODIR);
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int pl061_direction_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct pl061_gpio *chip = container_of(gc, struct pl061_gpio, gc);
unsigned long flags;
unsigned char gpiodir;
if (offset >= gc->ngpio)
return -EINVAL;
spin_lock_irqsave(&chip->lock, flags);
writeb(!!value << offset, chip->base + (1 << (offset + 2)));
gpiodir = readb(chip->base + GPIODIR);
gpiodir |= 1 << offset;
writeb(gpiodir, chip->base + GPIODIR);
writeb(!!value << offset, chip->base + (1 << (offset + 2)));
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int pl061_get_value(struct gpio_chip *gc, unsigned offset)
{
struct pl061_gpio *chip = container_of(gc, struct pl061_gpio, gc);
return !!readb(chip->base + (1 << (offset + 2)));
}
static void pl061_set_value(struct gpio_chip *gc, unsigned offset, int value)
{
struct pl061_gpio *chip = container_of(gc, struct pl061_gpio, gc);
writeb(!!value << offset, chip->base + (1 << (offset + 2)));
}
static int pl061_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct pl061_gpio *chip = container_of(gc, struct pl061_gpio, gc);
if (chip->irq_base <= 0)
return -EINVAL;
return chip->irq_base + offset;
}
static int pl061_irq_type(struct irq_data *d, unsigned trigger)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct pl061_gpio *chip = gc->private;
int offset = d->irq - chip->irq_base;
unsigned long flags;
u8 gpiois, gpioibe, gpioiev;
if (offset < 0 || offset >= PL061_GPIO_NR)
return -EINVAL;
raw_spin_lock_irqsave(&gc->lock, flags);
gpioiev = readb(chip->base + GPIOIEV);
gpiois = readb(chip->base + GPIOIS);
if (trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
gpiois |= 1 << offset;
if (trigger & IRQ_TYPE_LEVEL_HIGH)
gpioiev |= 1 << offset;
else
gpioiev &= ~(1 << offset);
} else
gpiois &= ~(1 << offset);
writeb(gpiois, chip->base + GPIOIS);
gpioibe = readb(chip->base + GPIOIBE);
if ((trigger & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH)
gpioibe |= 1 << offset;
else {
gpioibe &= ~(1 << offset);
if (trigger & IRQ_TYPE_EDGE_RISING)
gpioiev |= 1 << offset;
else if (trigger & IRQ_TYPE_EDGE_FALLING)
gpioiev &= ~(1 << offset);
}
writeb(gpioibe, chip->base + GPIOIBE);
writeb(gpioiev, chip->base + GPIOIEV);
raw_spin_unlock_irqrestore(&gc->lock, flags);
return 0;
}
static void pl061_irq_handler(unsigned irq, struct irq_desc *desc)
{
unsigned long pending;
int offset;
struct pl061_gpio *chip = irq_desc_get_handler_data(desc);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
chained_irq_enter(irqchip, desc);
pending = readb(chip->base + GPIOMIS);
writeb(pending, chip->base + GPIOIC);
if (pending) {
for_each_set_bit(offset, &pending, PL061_GPIO_NR)
generic_handle_irq(pl061_to_irq(&chip->gc, offset));
}
chained_irq_exit(irqchip, desc);
}
static void __init pl061_init_gc(struct pl061_gpio *chip, int irq_base)
{
struct irq_chip_type *ct;
chip->irq_gc = irq_alloc_generic_chip("gpio-pl061", 1, irq_base,
chip->base, handle_simple_irq);
chip->irq_gc->private = chip;
ct = chip->irq_gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_set_type = pl061_irq_type;
ct->chip.irq_set_wake = irq_gc_set_wake;
ct->regs.mask = GPIOIE;
irq_setup_generic_chip(chip->irq_gc, IRQ_MSK(PL061_GPIO_NR),
IRQ_GC_INIT_NESTED_LOCK, IRQ_NOREQUEST, 0);
}
static int pl061_probe(struct amba_device *adev, const struct amba_id *id)
{
struct device *dev = &adev->dev;
struct pl061_platform_data *pdata = dev->platform_data;
struct pl061_gpio *chip;
int ret, irq, i;
chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
if (pdata) {
chip->gc.base = pdata->gpio_base;
chip->irq_base = pdata->irq_base;
} else if (adev->dev.of_node) {
chip->gc.base = -1;
chip->irq_base = 0;
} else
return -ENODEV;
if (!devm_request_mem_region(dev, adev->res.start,
resource_size(&adev->res), "pl061"))
return -EBUSY;
chip->base = devm_ioremap(dev, adev->res.start,
resource_size(&adev->res));
if (chip->base == NULL)
return -ENOMEM;
spin_lock_init(&chip->lock);
chip->gc.direction_input = pl061_direction_input;
chip->gc.direction_output = pl061_direction_output;
chip->gc.get = pl061_get_value;
chip->gc.set = pl061_set_value;
chip->gc.to_irq = pl061_to_irq;
chip->gc.ngpio = PL061_GPIO_NR;
chip->gc.label = dev_name(dev);
chip->gc.dev = dev;
chip->gc.owner = THIS_MODULE;
ret = gpiochip_add(&chip->gc);
if (ret)
return ret;
if (chip->irq_base <= 0)
return 0;
pl061_init_gc(chip, chip->irq_base);
writeb(0, chip->base + GPIOIE);
irq = adev->irq[0];
if (irq < 0)
return -ENODEV;
irq_set_chained_handler(irq, pl061_irq_handler);
irq_set_handler_data(irq, chip);
for (i = 0; i < PL061_GPIO_NR; i++) {
if (pdata) {
if (pdata->directions & (1 << i))
pl061_direction_output(&chip->gc, i,
pdata->values & (1 << i));
else
pl061_direction_input(&chip->gc, i);
}
}
amba_set_drvdata(adev, chip);
return 0;
}
static int pl061_suspend(struct device *dev)
{
struct pl061_gpio *chip = dev_get_drvdata(dev);
int offset;
chip->csave_regs.gpio_data = 0;
chip->csave_regs.gpio_dir = readb(chip->base + GPIODIR);
chip->csave_regs.gpio_is = readb(chip->base + GPIOIS);
chip->csave_regs.gpio_ibe = readb(chip->base + GPIOIBE);
chip->csave_regs.gpio_iev = readb(chip->base + GPIOIEV);
chip->csave_regs.gpio_ie = readb(chip->base + GPIOIE);
for (offset = 0; offset < PL061_GPIO_NR; offset++) {
if (chip->csave_regs.gpio_dir & (1 << offset))
chip->csave_regs.gpio_data |=
pl061_get_value(&chip->gc, offset) << offset;
}
return 0;
}
static int pl061_resume(struct device *dev)
{
struct pl061_gpio *chip = dev_get_drvdata(dev);
int offset;
for (offset = 0; offset < PL061_GPIO_NR; offset++) {
if (chip->csave_regs.gpio_dir & (1 << offset))
pl061_direction_output(&chip->gc, offset,
chip->csave_regs.gpio_data &
(1 << offset));
else
pl061_direction_input(&chip->gc, offset);
}
writeb(chip->csave_regs.gpio_is, chip->base + GPIOIS);
writeb(chip->csave_regs.gpio_ibe, chip->base + GPIOIBE);
writeb(chip->csave_regs.gpio_iev, chip->base + GPIOIEV);
writeb(chip->csave_regs.gpio_ie, chip->base + GPIOIE);
return 0;
}
static int __init pl061_gpio_init(void)
{
return amba_driver_register(&pl061_gpio_driver);
}
