static int dio48e_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
return !!(dio48egpio->io_state[port] & mask);
}
static int dio48e_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned io_port = offset / 8;
const unsigned int control_port = io_port / 3;
const unsigned control_addr = dio48egpio->base + 3 + control_port*4;
unsigned long flags;
unsigned control;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (io_port == 2 || io_port == 5) {
if (offset % 8 > 3) {
dio48egpio->io_state[io_port] |= 0xF0;
dio48egpio->control[control_port] |= BIT(3);
} else {
dio48egpio->io_state[io_port] |= 0x0F;
dio48egpio->control[control_port] |= BIT(0);
}
} else {
dio48egpio->io_state[io_port] |= 0xFF;
if (io_port == 0 || io_port == 3)
dio48egpio->control[control_port] |= BIT(4);
else
dio48egpio->control[control_port] |= BIT(1);
}
control = BIT(7) | dio48egpio->control[control_port];
outb(control, control_addr);
control &= ~BIT(7);
outb(control, control_addr);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
return 0;
}
static int dio48e_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned io_port = offset / 8;
const unsigned int control_port = io_port / 3;
const unsigned mask = BIT(offset % 8);
const unsigned control_addr = dio48egpio->base + 3 + control_port*4;
const unsigned out_port = (io_port > 2) ? io_port + 1 : io_port;
unsigned long flags;
unsigned control;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (io_port == 2 || io_port == 5) {
if (offset % 8 > 3) {
dio48egpio->io_state[io_port] &= 0x0F;
dio48egpio->control[control_port] &= ~BIT(3);
} else {
dio48egpio->io_state[io_port] &= 0xF0;
dio48egpio->control[control_port] &= ~BIT(0);
}
} else {
dio48egpio->io_state[io_port] &= 0x00;
if (io_port == 0 || io_port == 3)
dio48egpio->control[control_port] &= ~BIT(4);
else
dio48egpio->control[control_port] &= ~BIT(1);
}
if (value)
dio48egpio->out_state[io_port] |= mask;
else
dio48egpio->out_state[io_port] &= ~mask;
control = BIT(7) | dio48egpio->control[control_port];
outb(control, control_addr);
outb(dio48egpio->out_state[io_port], dio48egpio->base + out_port);
control &= ~BIT(7);
outb(control, control_addr);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
return 0;
}
static int dio48e_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
const unsigned in_port = (port > 2) ? port + 1 : port;
unsigned long flags;
unsigned port_state;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (!(dio48egpio->io_state[port] & mask)) {
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
return -EINVAL;
}
port_state = inb(dio48egpio->base + in_port);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
return !!(port_state & mask);
}
static void dio48e_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned port = offset / 8;
const unsigned mask = BIT(offset % 8);
const unsigned out_port = (port > 2) ? port + 1 : port;
unsigned long flags;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (value)
dio48egpio->out_state[port] |= mask;
else
dio48egpio->out_state[port] &= ~mask;
outb(dio48egpio->out_state[port], dio48egpio->base + out_port);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
}
static void dio48e_gpio_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
unsigned int i;
const unsigned int gpio_reg_size = 8;
unsigned int port;
unsigned int out_port;
unsigned int bitmask;
unsigned long flags;
for (i = 0; i < chip->ngpio; i += gpio_reg_size) {
if (!mask[BIT_WORD(i)]) {
i = (BIT_WORD(i) + 1) * BITS_PER_LONG - gpio_reg_size;
continue;
}
port = i / gpio_reg_size;
out_port = (port > 2) ? port + 1 : port;
bitmask = mask[BIT_WORD(i)] & bits[BIT_WORD(i)];
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
dio48egpio->out_state[port] &= ~mask[BIT_WORD(i)];
dio48egpio->out_state[port] |= bitmask;
outb(dio48egpio->out_state[port], dio48egpio->base + out_port);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
mask[BIT_WORD(i)] >>= gpio_reg_size;
bits[BIT_WORD(i)] >>= gpio_reg_size;
}
}
static void dio48e_irq_ack(struct irq_data *data)
{
}
static void dio48e_irq_mask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
unsigned long flags;
if (offset != 19 && offset != 43)
return;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (offset == 19)
dio48egpio->irq_mask &= ~BIT(0);
else
dio48egpio->irq_mask &= ~BIT(1);
if (!dio48egpio->irq_mask)
inb(dio48egpio->base + 0xB);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
}
static void dio48e_irq_unmask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct dio48e_gpio *const dio48egpio = gpiochip_get_data(chip);
const unsigned long offset = irqd_to_hwirq(data);
unsigned long flags;
if (offset != 19 && offset != 43)
return;
raw_spin_lock_irqsave(&dio48egpio->lock, flags);
if (!dio48egpio->irq_mask) {
outb(0x00, dio48egpio->base + 0xF);
outb(0x00, dio48egpio->base + 0xB);
}
if (offset == 19)
dio48egpio->irq_mask |= BIT(0);
else
dio48egpio->irq_mask |= BIT(1);
raw_spin_unlock_irqrestore(&dio48egpio->lock, flags);
}
static int dio48e_irq_set_type(struct irq_data *data, unsigned flow_type)
{
const unsigned long offset = irqd_to_hwirq(data);
if (offset != 19 && offset != 43)
return -EINVAL;
if (flow_type != IRQ_TYPE_NONE && flow_type != IRQ_TYPE_EDGE_RISING)
return -EINVAL;
return 0;
}
static irqreturn_t dio48e_irq_handler(int irq, void *dev_id)
{
struct dio48e_gpio *const dio48egpio = dev_id;
struct gpio_chip *const chip = &dio48egpio->chip;
const unsigned long irq_mask = dio48egpio->irq_mask;
unsigned long gpio;
for_each_set_bit(gpio, &irq_mask, 2)
generic_handle_irq(irq_find_mapping(chip->irqdomain,
19 + gpio*24));
raw_spin_lock(&dio48egpio->lock);
outb(0x00, dio48egpio->base + 0xF);
raw_spin_unlock(&dio48egpio->lock);
return IRQ_HANDLED;
}
static int dio48e_probe(struct device *dev, unsigned int id)
{
struct dio48e_gpio *dio48egpio;
const char *const name = dev_name(dev);
int err;
dio48egpio = devm_kzalloc(dev, sizeof(*dio48egpio), GFP_KERNEL);
if (!dio48egpio)
return -ENOMEM;
if (!devm_request_region(dev, base[id], DIO48E_EXTENT, name)) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + DIO48E_EXTENT);
return -EBUSY;
}
dio48egpio->chip.label = name;
dio48egpio->chip.parent = dev;
dio48egpio->chip.owner = THIS_MODULE;
dio48egpio->chip.base = -1;
dio48egpio->chip.ngpio = DIO48E_NGPIO;
dio48egpio->chip.names = dio48e_names;
dio48egpio->chip.get_direction = dio48e_gpio_get_direction;
dio48egpio->chip.direction_input = dio48e_gpio_direction_input;
dio48egpio->chip.direction_output = dio48e_gpio_direction_output;
dio48egpio->chip.get = dio48e_gpio_get;
dio48egpio->chip.set = dio48e_gpio_set;
dio48egpio->chip.set_multiple = dio48e_gpio_set_multiple;
dio48egpio->base = base[id];
raw_spin_lock_init(&dio48egpio->lock);
err = devm_gpiochip_add_data(dev, &dio48egpio->chip, dio48egpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
outb(0x80, base[id] + 3);
outb(0x00, base[id]);
outb(0x00, base[id] + 1);
outb(0x00, base[id] + 2);
outb(0x00, base[id] + 3);
outb(0x80, base[id] + 7);
outb(0x00, base[id] + 4);
outb(0x00, base[id] + 5);
outb(0x00, base[id] + 6);
outb(0x00, base[id] + 7);
inb(base[id] + 0xB);
err = gpiochip_irqchip_add(&dio48egpio->chip, &dio48e_irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(dev, "Could not add irqchip (%d)\n", err);
return err;
}
err = devm_request_irq(dev, irq[id], dio48e_irq_handler, 0, name,
dio48egpio);
if (err) {
dev_err(dev, "IRQ handler registering failed (%d)\n", err);
return err;
}
return 0;
}
