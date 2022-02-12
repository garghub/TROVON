static int idio_16_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
if (offset > 15)
return 1;
return 0;
}
static int idio_16_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
return 0;
}
static int idio_16_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
chip->set(chip, offset, value);
return 0;
}
static int idio_16_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
unsigned long mask = BIT(offset);
if (offset < 8)
return !!(ioread8(&idio16gpio->reg->out0_7) & mask);
if (offset < 16)
return !!(ioread8(&idio16gpio->reg->out8_15) & (mask >> 8));
if (offset < 24)
return !!(ioread8(&idio16gpio->reg->in0_7) & (mask >> 16));
return !!(ioread8(&idio16gpio->reg->in8_15) & (mask >> 24));
}
static void idio_16_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
unsigned int mask = BIT(offset);
void __iomem *base;
unsigned long flags;
unsigned int out_state;
if (offset > 15)
return;
if (offset > 7) {
mask >>= 8;
base = &idio16gpio->reg->out8_15;
} else
base = &idio16gpio->reg->out0_7;
raw_spin_lock_irqsave(&idio16gpio->lock, flags);
if (value)
out_state = ioread8(base) | mask;
else
out_state = ioread8(base) & ~mask;
iowrite8(out_state, base);
raw_spin_unlock_irqrestore(&idio16gpio->lock, flags);
}
static void idio_16_gpio_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
struct idio_16_gpio *const idio16gpio = gpiochip_get_data(chip);
unsigned long flags;
unsigned int out_state;
raw_spin_lock_irqsave(&idio16gpio->lock, flags);
if (*mask & 0xFF) {
out_state = ioread8(&idio16gpio->reg->out0_7) & ~*mask;
out_state |= *mask & *bits;
iowrite8(out_state, &idio16gpio->reg->out0_7);
}
*mask >>= 8;
if (*mask & 0xFF) {
*bits >>= 8;
out_state = ioread8(&idio16gpio->reg->out8_15) & ~*mask;
out_state |= *mask & *bits;
iowrite8(out_state, &idio16gpio->reg->out8_15);
}
raw_spin_unlock_irqrestore(&idio16gpio->lock, flags);
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
raw_spin_lock_irqsave(&idio16gpio->lock, flags);
iowrite8(0, &idio16gpio->reg->irq_ctl);
raw_spin_unlock_irqrestore(&idio16gpio->lock, flags);
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
raw_spin_lock_irqsave(&idio16gpio->lock, flags);
ioread8(&idio16gpio->reg->irq_ctl);
raw_spin_unlock_irqrestore(&idio16gpio->lock, flags);
}
}
static int idio_16_irq_set_type(struct irq_data *data, unsigned int flow_type)
{
if (flow_type != IRQ_TYPE_NONE &&
(flow_type & IRQ_TYPE_EDGE_BOTH) != IRQ_TYPE_EDGE_BOTH)
return -EINVAL;
return 0;
}
static irqreturn_t idio_16_irq_handler(int irq, void *dev_id)
{
struct idio_16_gpio *const idio16gpio = dev_id;
unsigned int irq_status;
struct gpio_chip *const chip = &idio16gpio->chip;
int gpio;
raw_spin_lock(&idio16gpio->lock);
irq_status = ioread8(&idio16gpio->reg->irq_status);
raw_spin_unlock(&idio16gpio->lock);
if (!(irq_status & 0x3) || !(irq_status & 0x4))
return IRQ_NONE;
for_each_set_bit(gpio, &idio16gpio->irq_mask, chip->ngpio)
generic_handle_irq(irq_find_mapping(chip->irqdomain, gpio));
raw_spin_lock(&idio16gpio->lock);
iowrite8(0, &idio16gpio->reg->in0_7);
raw_spin_unlock(&idio16gpio->lock);
return IRQ_HANDLED;
}
static int idio_16_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct device *const dev = &pdev->dev;
struct idio_16_gpio *idio16gpio;
int err;
const size_t pci_bar_index = 2;
const char *const name = pci_name(pdev);
idio16gpio = devm_kzalloc(dev, sizeof(*idio16gpio), GFP_KERNEL);
if (!idio16gpio)
return -ENOMEM;
err = pcim_enable_device(pdev);
if (err) {
dev_err(dev, "Failed to enable PCI device (%d)\n", err);
return err;
}
err = pcim_iomap_regions(pdev, BIT(pci_bar_index), name);
if (err) {
dev_err(dev, "Unable to map PCI I/O addresses (%d)\n", err);
return err;
}
idio16gpio->reg = pcim_iomap_table(pdev)[pci_bar_index];
iowrite8(0, &idio16gpio->reg->filter_ctl);
idio16gpio->chip.label = name;
idio16gpio->chip.parent = dev;
idio16gpio->chip.owner = THIS_MODULE;
idio16gpio->chip.base = -1;
idio16gpio->chip.ngpio = IDIO_16_NGPIO;
idio16gpio->chip.names = idio_16_names;
idio16gpio->chip.get_direction = idio_16_gpio_get_direction;
idio16gpio->chip.direction_input = idio_16_gpio_direction_input;
idio16gpio->chip.direction_output = idio_16_gpio_direction_output;
idio16gpio->chip.get = idio_16_gpio_get;
idio16gpio->chip.set = idio_16_gpio_set;
idio16gpio->chip.set_multiple = idio_16_gpio_set_multiple;
raw_spin_lock_init(&idio16gpio->lock);
err = devm_gpiochip_add_data(dev, &idio16gpio->chip, idio16gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
iowrite8(0, &idio16gpio->reg->irq_ctl);
iowrite8(0, &idio16gpio->reg->in0_7);
err = gpiochip_irqchip_add(&idio16gpio->chip, &idio_16_irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(dev, "Could not add irqchip (%d)\n", err);
return err;
}
err = devm_request_irq(dev, pdev->irq, idio_16_irq_handler, IRQF_SHARED,
name, idio16gpio);
if (err) {
dev_err(dev, "IRQ handler registering failed (%d)\n", err);
return err;
}
return 0;
}
