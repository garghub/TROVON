static int pl061_gpio_request(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
return pinctrl_request_gpio(gpio);
}
static void pl061_gpio_free(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
pinctrl_free_gpio(gpio);
}
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
return irq_create_mapping(chip->domain, offset);
}
static int pl061_irq_type(struct irq_data *d, unsigned trigger)
{
struct pl061_gpio *chip = irq_data_get_irq_chip_data(d);
int offset = irqd_to_hwirq(d);
unsigned long flags;
u8 gpiois, gpioibe, gpioiev;
if (offset < 0 || offset >= PL061_GPIO_NR)
return -EINVAL;
spin_lock_irqsave(&chip->lock, flags);
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
spin_unlock_irqrestore(&chip->lock, flags);
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
static void pl061_irq_mask(struct irq_data *d)
{
struct pl061_gpio *chip = irq_data_get_irq_chip_data(d);
u8 mask = 1 << (irqd_to_hwirq(d) % PL061_GPIO_NR);
u8 gpioie;
spin_lock(&chip->lock);
gpioie = readb(chip->base + GPIOIE) & ~mask;
writeb(gpioie, chip->base + GPIOIE);
spin_unlock(&chip->lock);
}
static void pl061_irq_unmask(struct irq_data *d)
{
struct pl061_gpio *chip = irq_data_get_irq_chip_data(d);
u8 mask = 1 << (irqd_to_hwirq(d) % PL061_GPIO_NR);
u8 gpioie;
spin_lock(&chip->lock);
gpioie = readb(chip->base + GPIOIE) | mask;
writeb(gpioie, chip->base + GPIOIE);
spin_unlock(&chip->lock);
}
static int pl061_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
struct pl061_gpio *chip = d->host_data;
irq_set_chip_and_handler_name(virq, &pl061_irqchip, handle_simple_irq,
"pl061");
irq_set_chip_data(virq, chip);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
static int pl061_probe(struct amba_device *adev, const struct amba_id *id)
{
struct device *dev = &adev->dev;
struct pl061_platform_data *pdata = dev->platform_data;
struct pl061_gpio *chip;
int ret, irq, i, irq_base;
chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
if (pdata) {
chip->gc.base = pdata->gpio_base;
irq_base = pdata->irq_base;
if (irq_base <= 0)
return -ENODEV;
} else {
chip->gc.base = -1;
irq_base = 0;
}
if (!devm_request_mem_region(dev, adev->res.start,
resource_size(&adev->res), "pl061"))
return -EBUSY;
chip->base = devm_ioremap(dev, adev->res.start,
resource_size(&adev->res));
if (!chip->base)
return -ENOMEM;
chip->domain = irq_domain_add_simple(adev->dev.of_node, PL061_GPIO_NR,
irq_base, &pl061_domain_ops, chip);
if (!chip->domain)
return -ENODEV;
spin_lock_init(&chip->lock);
chip->gc.request = pl061_gpio_request;
chip->gc.free = pl061_gpio_free;
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
