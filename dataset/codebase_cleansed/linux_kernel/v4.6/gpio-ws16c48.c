static int ws16c48_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
return !!(ws16c48gpio->io_state[port] & mask);
}
static int ws16c48_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
unsigned long flags;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
ws16c48gpio->io_state[port] |= mask;
ws16c48gpio->out_state[port] &= ~mask;
outb(ws16c48gpio->out_state[port], ws16c48gpio->base + port);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return 0;
}
static int ws16c48_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
unsigned long flags;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
ws16c48gpio->io_state[port] &= ~mask;
if (value)
ws16c48gpio->out_state[port] |= mask;
else
ws16c48gpio->out_state[port] &= ~mask;
outb(ws16c48gpio->out_state[port], ws16c48gpio->base + port);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return 0;
}
static int ws16c48_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
unsigned long flags;
unsigned port_state;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
if (!(ws16c48gpio->io_state[port] & mask)) {
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return -EINVAL;
}
port_state = inb(ws16c48gpio->base + port);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return !!(port_state & mask);
}
static void ws16c48_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
unsigned long flags;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
if (ws16c48gpio->io_state[port] & mask) {
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return;
}
if (value)
ws16c48gpio->out_state[port] |= mask;
else
ws16c48gpio->out_state[port] &= ~mask;
outb(ws16c48gpio->out_state[port], ws16c48gpio->base + port);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
}
static void ws16c48_irq_ack(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
unsigned long flags;
unsigned port_state;
if (port > 2)
return;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
port_state = ws16c48gpio->irq_mask >> (8*port);
outb(0x80, ws16c48gpio->base + 7);
outb(port_state & ~mask, ws16c48gpio->base + 8 + port);
outb(port_state | mask, ws16c48gpio->base + 8 + port);
outb(0xC0, ws16c48gpio->base + 7);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
}
static void ws16c48_irq_mask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
const unsigned long mask = BIT(offset);
const unsigned port = offset / 8;
unsigned long flags;
if (port > 2)
return;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
ws16c48gpio->irq_mask &= ~mask;
outb(0x80, ws16c48gpio->base + 7);
outb(ws16c48gpio->irq_mask >> (8*port), ws16c48gpio->base + 8 + port);
outb(0xC0, ws16c48gpio->base + 7);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
}
static void ws16c48_irq_unmask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
const unsigned long mask = BIT(offset);
const unsigned port = offset / 8;
unsigned long flags;
if (port > 2)
return;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
ws16c48gpio->irq_mask |= mask;
outb(0x80, ws16c48gpio->base + 7);
outb(ws16c48gpio->irq_mask >> (8*port), ws16c48gpio->base + 8 + port);
outb(0xC0, ws16c48gpio->base + 7);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
}
static int ws16c48_irq_set_type(struct irq_data *data, unsigned flow_type)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct ws16c48_gpio *const ws16c48gpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
const unsigned long mask = BIT(offset);
const unsigned port = offset / 8;
unsigned long flags;
if (port > 2)
return -EINVAL;
spin_lock_irqsave(&ws16c48gpio->lock, flags);
switch (flow_type) {
case IRQ_TYPE_NONE:
break;
case IRQ_TYPE_EDGE_RISING:
ws16c48gpio->flow_mask |= mask;
break;
case IRQ_TYPE_EDGE_FALLING:
ws16c48gpio->flow_mask &= ~mask;
break;
default:
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return -EINVAL;
}
outb(0x40, ws16c48gpio->base + 7);
outb(ws16c48gpio->flow_mask >> (8*port), ws16c48gpio->base + 8 + port);
outb(0xC0, ws16c48gpio->base + 7);
spin_unlock_irqrestore(&ws16c48gpio->lock, flags);
return 0;
}
static irqreturn_t ws16c48_irq_handler(int irq, void *dev_id)
{
struct ws16c48_gpio *const ws16c48gpio = dev_id;
struct gpio_chip *const chip = &ws16c48gpio->chip;
unsigned long int_pending;
unsigned long port;
unsigned long int_id;
unsigned long gpio;
int_pending = inb(ws16c48gpio->base + 6) & 0x7;
if (!int_pending)
return IRQ_NONE;
do {
for_each_set_bit(port, &int_pending, 3) {
int_id = inb(ws16c48gpio->base + 8 + port);
for_each_set_bit(gpio, &int_id, 8)
generic_handle_irq(irq_find_mapping(
chip->irqdomain, gpio + 8*port));
}
int_pending = inb(ws16c48gpio->base + 6) & 0x7;
} while (int_pending);
return IRQ_HANDLED;
}
static int __init ws16c48_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ws16c48_gpio *ws16c48gpio;
const unsigned base = ws16c48_base;
const unsigned extent = 16;
const char *const name = dev_name(dev);
int err;
const unsigned irq = ws16c48_irq;
ws16c48gpio = devm_kzalloc(dev, sizeof(*ws16c48gpio), GFP_KERNEL);
if (!ws16c48gpio)
return -ENOMEM;
if (!devm_request_region(dev, base, extent, name)) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base, base + extent);
return -EBUSY;
}
ws16c48gpio->chip.label = name;
ws16c48gpio->chip.parent = dev;
ws16c48gpio->chip.owner = THIS_MODULE;
ws16c48gpio->chip.base = -1;
ws16c48gpio->chip.ngpio = 48;
ws16c48gpio->chip.get_direction = ws16c48_gpio_get_direction;
ws16c48gpio->chip.direction_input = ws16c48_gpio_direction_input;
ws16c48gpio->chip.direction_output = ws16c48_gpio_direction_output;
ws16c48gpio->chip.get = ws16c48_gpio_get;
ws16c48gpio->chip.set = ws16c48_gpio_set;
ws16c48gpio->base = base;
ws16c48gpio->irq = irq;
spin_lock_init(&ws16c48gpio->lock);
dev_set_drvdata(dev, ws16c48gpio);
err = gpiochip_add_data(&ws16c48gpio->chip, ws16c48gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
outb(0x80, base + 7);
outb(0, base + 8);
outb(0, base + 9);
outb(0, base + 10);
outb(0xC0, base + 7);
err = gpiochip_irqchip_add(&ws16c48gpio->chip, &ws16c48_irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(dev, "Could not add irqchip (%d)\n", err);
goto err_gpiochip_remove;
}
err = request_irq(irq, ws16c48_irq_handler, IRQF_SHARED, name,
ws16c48gpio);
if (err) {
dev_err(dev, "IRQ handler registering failed (%d)\n", err);
goto err_gpiochip_remove;
}
return 0;
err_gpiochip_remove:
gpiochip_remove(&ws16c48gpio->chip);
return err;
}
static int ws16c48_remove(struct platform_device *pdev)
{
struct ws16c48_gpio *const ws16c48gpio = platform_get_drvdata(pdev);
free_irq(ws16c48gpio->irq, ws16c48gpio);
gpiochip_remove(&ws16c48gpio->chip);
return 0;
}
static void __exit ws16c48_exit(void)
{
platform_device_unregister(ws16c48_device);
platform_driver_unregister(&ws16c48_driver);
}
static int __init ws16c48_init(void)
{
int err;
ws16c48_device = platform_device_alloc(ws16c48_driver.driver.name, -1);
if (!ws16c48_device)
return -ENOMEM;
err = platform_device_add(ws16c48_device);
if (err)
goto err_platform_device;
err = platform_driver_probe(&ws16c48_driver, ws16c48_probe);
if (err)
goto err_platform_driver;
return 0;
err_platform_driver:
platform_device_del(ws16c48_device);
err_platform_device:
platform_device_put(ws16c48_device);
return err;
}
