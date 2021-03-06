static int idio_16_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
if (offset > 15)
return 1;
return 0;
}
static int idio_16_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
return 0;
}
static int idio_16_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
chip->set(chip, offset, value);
return 0;
}
static int idio_16_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
const unsigned mask = BIT(offset-16);
if (offset < 16)
return -EINVAL;
if (offset < 24)
return !!(inb(idio16gpio->base + 1) & mask);
return !!(inb(idio16gpio->base + 5) & (mask>>8));
}
static void idio_16_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
const unsigned mask = BIT(offset);
unsigned long flags;
if (offset > 15)
return;
spin_lock_irqsave(&idio16gpio->lock, flags);
if (value)
idio16gpio->out_state |= mask;
else
idio16gpio->out_state &= ~mask;
if (offset > 7)
outb(idio16gpio->out_state >> 8, idio16gpio->base + 4);
else
outb(idio16gpio->out_state, idio16gpio->base);
spin_unlock_irqrestore(&idio16gpio->lock, flags);
}
static void idio_16_irq_ack(struct irq_data *data)
{
}
static void idio_16_irq_mask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
const unsigned long mask = BIT(irqd_to_hwirq(data));
unsigned long flags;
idio16gpio->irq_mask &= ~mask;
if (!idio16gpio->irq_mask) {
spin_lock_irqsave(&idio16gpio->lock, flags);
outb(0, idio16gpio->base + 2);
spin_unlock_irqrestore(&idio16gpio->lock, flags);
}
}
static void idio_16_irq_unmask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
const unsigned long mask = BIT(irqd_to_hwirq(data));
const unsigned long prev_irq_mask = idio16gpio->irq_mask;
unsigned long flags;
idio16gpio->irq_mask |= mask;
if (!prev_irq_mask) {
spin_lock_irqsave(&idio16gpio->lock, flags);
inb(idio16gpio->base + 2);
spin_unlock_irqrestore(&idio16gpio->lock, flags);
}
}
static int idio_16_irq_set_type(struct irq_data *data, unsigned flow_type)
{
if (flow_type != IRQ_TYPE_NONE &&
(flow_type & IRQ_TYPE_EDGE_BOTH) != IRQ_TYPE_EDGE_BOTH)
return -EINVAL;
return 0;
}
static irqreturn_t idio_16_irq_handler(int irq, void *dev_id)
{
struct idio_16_gpio *const idio16gpio = dev_id;
struct gpio_chip *const chip = &idio16gpio->chip;
int gpio;
for_each_set_bit(gpio, &idio16gpio->irq_mask, chip->ngpio)
generic_handle_irq(irq_find_mapping(chip->irqdomain, gpio));
spin_lock(&idio16gpio->lock);
outb(0, idio16gpio->base + 1);
spin_unlock(&idio16gpio->lock);
return IRQ_HANDLED;
}
static int __init idio_16_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct idio_16_gpio *idio16gpio;
const unsigned base = idio_16_base;
const unsigned extent = 8;
const char *const name = dev_name(dev);
int err;
const unsigned irq = idio_16_irq;
idio16gpio = devm_kzalloc(dev, sizeof(*idio16gpio), GFP_KERNEL);
if (!idio16gpio)
return -ENOMEM;
if (!request_region(base, extent, name)) {
dev_err(dev, "Unable to lock %s port addresses (0x%X-0x%X)\n",
name, base, base + extent);
err = -EBUSY;
goto err_lock_io_port;
}
idio16gpio->chip.label = name;
idio16gpio->chip.parent = dev;
idio16gpio->chip.owner = THIS_MODULE;
idio16gpio->chip.base = -1;
idio16gpio->chip.ngpio = 32;
idio16gpio->chip.get_direction = idio_16_gpio_get_direction;
idio16gpio->chip.direction_input = idio_16_gpio_direction_input;
idio16gpio->chip.direction_output = idio_16_gpio_direction_output;
idio16gpio->chip.get = idio_16_gpio_get;
idio16gpio->chip.set = idio_16_gpio_set;
idio16gpio->base = base;
idio16gpio->extent = extent;
idio16gpio->irq = irq;
idio16gpio->out_state = 0xFFFF;
spin_lock_init(&idio16gpio->lock);
dev_set_drvdata(dev, idio16gpio);
err = gpiochip_add_data(&idio16gpio->chip, idio16gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
goto err_gpio_register;
}
outb(0, base + 2);
outb(0, base + 1);
err = gpiochip_irqchip_add(&idio16gpio->chip, &idio_16_irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(dev, "Could not add irqchip (%d)\n", err);
goto err_gpiochip_irqchip_add;
}
err = request_irq(irq, idio_16_irq_handler, 0, name, idio16gpio);
if (err) {
dev_err(dev, "IRQ handler registering failed (%d)\n", err);
goto err_request_irq;
}
return 0;
err_request_irq:
err_gpiochip_irqchip_add:
gpiochip_remove(&idio16gpio->chip);
err_gpio_register:
release_region(base, extent);
err_lock_io_port:
return err;
}
static int idio_16_remove(struct platform_device *pdev)
{
struct idio_16_gpio *const idio16gpio = platform_get_drvdata(pdev);
free_irq(idio16gpio->irq, idio16gpio);
gpiochip_remove(&idio16gpio->chip);
release_region(idio16gpio->base, idio16gpio->extent);
return 0;
}
static void __exit idio_16_exit(void)
{
platform_device_unregister(idio_16_device);
platform_driver_unregister(&idio_16_driver);
}
static int __init idio_16_init(void)
{
int err;
idio_16_device = platform_device_alloc(idio_16_driver.driver.name, -1);
if (!idio_16_device)
return -ENOMEM;
err = platform_device_add(idio_16_device);
if (err)
goto err_platform_device;
err = platform_driver_probe(&idio_16_driver, idio_16_probe);
if (err)
goto err_platform_driver;
return 0;
err_platform_driver:
platform_device_del(idio_16_device);
err_platform_device:
platform_device_put(idio_16_device);
return err;
}
