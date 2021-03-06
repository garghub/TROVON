static int timbgpio_update_bit(struct gpio_chip *gpio, unsigned index,
unsigned offset, bool enabled)
{
struct timbgpio *tgpio = container_of(gpio, struct timbgpio, gpio);
u32 reg;
spin_lock(&tgpio->lock);
reg = ioread32(tgpio->membase + offset);
if (enabled)
reg |= (1 << index);
else
reg &= ~(1 << index);
iowrite32(reg, tgpio->membase + offset);
spin_unlock(&tgpio->lock);
return 0;
}
static int timbgpio_gpio_direction_input(struct gpio_chip *gpio, unsigned nr)
{
return timbgpio_update_bit(gpio, nr, TGPIODIR, true);
}
static int timbgpio_gpio_get(struct gpio_chip *gpio, unsigned nr)
{
struct timbgpio *tgpio = container_of(gpio, struct timbgpio, gpio);
u32 value;
value = ioread32(tgpio->membase + TGPIOVAL);
return (value & (1 << nr)) ? 1 : 0;
}
static int timbgpio_gpio_direction_output(struct gpio_chip *gpio,
unsigned nr, int val)
{
return timbgpio_update_bit(gpio, nr, TGPIODIR, false);
}
static void timbgpio_gpio_set(struct gpio_chip *gpio,
unsigned nr, int val)
{
timbgpio_update_bit(gpio, nr, TGPIOVAL, val != 0);
}
static int timbgpio_to_irq(struct gpio_chip *gpio, unsigned offset)
{
struct timbgpio *tgpio = container_of(gpio, struct timbgpio, gpio);
if (tgpio->irq_base <= 0)
return -EINVAL;
return tgpio->irq_base + offset;
}
static void timbgpio_irq_disable(struct irq_data *d)
{
struct timbgpio *tgpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - tgpio->irq_base;
unsigned long flags;
spin_lock_irqsave(&tgpio->lock, flags);
tgpio->last_ier &= ~(1UL << offset);
iowrite32(tgpio->last_ier, tgpio->membase + TGPIO_IER);
spin_unlock_irqrestore(&tgpio->lock, flags);
}
static void timbgpio_irq_enable(struct irq_data *d)
{
struct timbgpio *tgpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - tgpio->irq_base;
unsigned long flags;
spin_lock_irqsave(&tgpio->lock, flags);
tgpio->last_ier |= 1UL << offset;
iowrite32(tgpio->last_ier, tgpio->membase + TGPIO_IER);
spin_unlock_irqrestore(&tgpio->lock, flags);
}
static int timbgpio_irq_type(struct irq_data *d, unsigned trigger)
{
struct timbgpio *tgpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - tgpio->irq_base;
unsigned long flags;
u32 lvr, flr, bflr = 0;
u32 ver;
int ret = 0;
if (offset < 0 || offset > tgpio->gpio.ngpio)
return -EINVAL;
ver = ioread32(tgpio->membase + TGPIO_VER);
spin_lock_irqsave(&tgpio->lock, flags);
lvr = ioread32(tgpio->membase + TGPIO_LVR);
flr = ioread32(tgpio->membase + TGPIO_FLR);
if (ver > 2)
bflr = ioread32(tgpio->membase + TGPIO_BFLR);
if (trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
bflr &= ~(1 << offset);
flr &= ~(1 << offset);
if (trigger & IRQ_TYPE_LEVEL_HIGH)
lvr |= 1 << offset;
else
lvr &= ~(1 << offset);
}
if ((trigger & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
if (ver < 3) {
ret = -EINVAL;
goto out;
}
else {
flr |= 1 << offset;
bflr |= 1 << offset;
}
} else {
bflr &= ~(1 << offset);
flr |= 1 << offset;
if (trigger & IRQ_TYPE_EDGE_FALLING)
lvr &= ~(1 << offset);
else
lvr |= 1 << offset;
}
iowrite32(lvr, tgpio->membase + TGPIO_LVR);
iowrite32(flr, tgpio->membase + TGPIO_FLR);
if (ver > 2)
iowrite32(bflr, tgpio->membase + TGPIO_BFLR);
iowrite32(1 << offset, tgpio->membase + TGPIO_ICR);
out:
spin_unlock_irqrestore(&tgpio->lock, flags);
return ret;
}
static void timbgpio_irq(unsigned int irq, struct irq_desc *desc)
{
struct timbgpio *tgpio = irq_get_handler_data(irq);
unsigned long ipr;
int offset;
desc->irq_data.chip->irq_ack(irq_get_irq_data(irq));
ipr = ioread32(tgpio->membase + TGPIO_IPR);
iowrite32(ipr, tgpio->membase + TGPIO_ICR);
iowrite32(0, tgpio->membase + TGPIO_IER);
for_each_set_bit(offset, &ipr, tgpio->gpio.ngpio)
generic_handle_irq(timbgpio_to_irq(&tgpio->gpio, offset));
iowrite32(tgpio->last_ier, tgpio->membase + TGPIO_IER);
}
static int timbgpio_probe(struct platform_device *pdev)
{
int err, i;
struct gpio_chip *gc;
struct timbgpio *tgpio;
struct resource *iomem;
struct timbgpio_platform_data *pdata = pdev->dev.platform_data;
int irq = platform_get_irq(pdev, 0);
if (!pdata || pdata->nr_pins > 32) {
err = -EINVAL;
goto err_mem;
}
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem) {
err = -EINVAL;
goto err_mem;
}
tgpio = kzalloc(sizeof(*tgpio), GFP_KERNEL);
if (!tgpio) {
err = -EINVAL;
goto err_mem;
}
tgpio->irq_base = pdata->irq_base;
spin_lock_init(&tgpio->lock);
if (!request_mem_region(iomem->start, resource_size(iomem),
DRIVER_NAME)) {
err = -EBUSY;
goto err_request;
}
tgpio->membase = ioremap(iomem->start, resource_size(iomem));
if (!tgpio->membase) {
err = -ENOMEM;
goto err_ioremap;
}
gc = &tgpio->gpio;
gc->label = dev_name(&pdev->dev);
gc->owner = THIS_MODULE;
gc->dev = &pdev->dev;
gc->direction_input = timbgpio_gpio_direction_input;
gc->get = timbgpio_gpio_get;
gc->direction_output = timbgpio_gpio_direction_output;
gc->set = timbgpio_gpio_set;
gc->to_irq = (irq >= 0 && tgpio->irq_base > 0) ? timbgpio_to_irq : NULL;
gc->dbg_show = NULL;
gc->base = pdata->gpio_base;
gc->ngpio = pdata->nr_pins;
gc->can_sleep = 0;
err = gpiochip_add(gc);
if (err)
goto err_chipadd;
platform_set_drvdata(pdev, tgpio);
iowrite32(0x0, tgpio->membase + TGPIO_IER);
if (irq < 0 || tgpio->irq_base <= 0)
return 0;
for (i = 0; i < pdata->nr_pins; i++) {
irq_set_chip_and_handler_name(tgpio->irq_base + i,
&timbgpio_irqchip, handle_simple_irq, "mux");
irq_set_chip_data(tgpio->irq_base + i, tgpio);
#ifdef CONFIG_ARM
set_irq_flags(tgpio->irq_base + i, IRQF_VALID | IRQF_PROBE);
#endif
}
irq_set_handler_data(irq, tgpio);
irq_set_chained_handler(irq, timbgpio_irq);
return 0;
err_chipadd:
iounmap(tgpio->membase);
err_ioremap:
release_mem_region(iomem->start, resource_size(iomem));
err_request:
kfree(tgpio);
err_mem:
printk(KERN_ERR DRIVER_NAME": Failed to register GPIOs: %d\n", err);
return err;
}
static int timbgpio_remove(struct platform_device *pdev)
{
int err;
struct timbgpio_platform_data *pdata = pdev->dev.platform_data;
struct timbgpio *tgpio = platform_get_drvdata(pdev);
struct resource *iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
int irq = platform_get_irq(pdev, 0);
if (irq >= 0 && tgpio->irq_base > 0) {
int i;
for (i = 0; i < pdata->nr_pins; i++) {
irq_set_chip(tgpio->irq_base + i, NULL);
irq_set_chip_data(tgpio->irq_base + i, NULL);
}
irq_set_handler(irq, NULL);
irq_set_handler_data(irq, NULL);
}
err = gpiochip_remove(&tgpio->gpio);
if (err)
printk(KERN_ERR DRIVER_NAME": failed to remove gpio_chip\n");
iounmap(tgpio->membase);
release_mem_region(iomem->start, resource_size(iomem));
kfree(tgpio);
platform_set_drvdata(pdev, NULL);
return 0;
}
