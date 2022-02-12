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
static int idio_16_probe(struct device *dev, unsigned int id)
{
struct idio_16_gpio *idio16gpio;
const char *const name = dev_name(dev);
int err;
idio16gpio = devm_kzalloc(dev, sizeof(*idio16gpio), GFP_KERNEL);
if (!idio16gpio)
return -ENOMEM;
if (!devm_request_region(dev, base[id], IDIO_16_EXTENT, name)) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + IDIO_16_EXTENT);
return -EBUSY;
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
idio16gpio->base = base[id];
idio16gpio->irq = irq[id];
idio16gpio->out_state = 0xFFFF;
spin_lock_init(&idio16gpio->lock);
dev_set_drvdata(dev, idio16gpio);
err = gpiochip_add_data(&idio16gpio->chip, idio16gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
outb(0, base[id] + 2);
outb(0, base[id] + 1);
err = gpiochip_irqchip_add(&idio16gpio->chip, &idio_16_irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(dev, "Could not add irqchip (%d)\n", err);
goto err_gpiochip_remove;
}
err = request_irq(irq[id], idio_16_irq_handler, 0, name, idio16gpio);
if (err) {
dev_err(dev, "IRQ handler registering failed (%d)\n", err);
goto err_gpiochip_remove;
}
return 0;
err_gpiochip_remove:
gpiochip_remove(&idio16gpio->chip);
return err;
}
static int idio_16_remove(struct device *dev, unsigned int id)
{
struct idio_16_gpio *const idio16gpio = dev_get_drvdata(dev);
free_irq(idio16gpio->irq, idio16gpio);
gpiochip_remove(&idio16gpio->chip);
return 0;
}
