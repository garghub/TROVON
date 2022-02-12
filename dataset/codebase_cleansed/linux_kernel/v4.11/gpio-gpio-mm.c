static int gpiomm_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
const unsigned int port = offset / 8;
const unsigned int mask = BIT(offset % 8);
return !!(gpiommgpio->io_state[port] & mask);
}
static int gpiomm_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
const unsigned int io_port = offset / 8;
const unsigned int control_port = io_port / 3;
const unsigned int control_addr = gpiommgpio->base + 3 + control_port*4;
unsigned long flags;
unsigned int control;
spin_lock_irqsave(&gpiommgpio->lock, flags);
if (io_port == 2 || io_port == 5) {
if (offset % 8 > 3) {
gpiommgpio->io_state[io_port] |= 0xF0;
gpiommgpio->control[control_port] |= BIT(3);
} else {
gpiommgpio->io_state[io_port] |= 0x0F;
gpiommgpio->control[control_port] |= BIT(0);
}
} else {
gpiommgpio->io_state[io_port] |= 0xFF;
if (io_port == 0 || io_port == 3)
gpiommgpio->control[control_port] |= BIT(4);
else
gpiommgpio->control[control_port] |= BIT(1);
}
control = BIT(7) | gpiommgpio->control[control_port];
outb(control, control_addr);
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
return 0;
}
static int gpiomm_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
const unsigned int io_port = offset / 8;
const unsigned int control_port = io_port / 3;
const unsigned int mask = BIT(offset % 8);
const unsigned int control_addr = gpiommgpio->base + 3 + control_port*4;
const unsigned int out_port = (io_port > 2) ? io_port + 1 : io_port;
unsigned long flags;
unsigned int control;
spin_lock_irqsave(&gpiommgpio->lock, flags);
if (io_port == 2 || io_port == 5) {
if (offset % 8 > 3) {
gpiommgpio->io_state[io_port] &= 0x0F;
gpiommgpio->control[control_port] &= ~BIT(3);
} else {
gpiommgpio->io_state[io_port] &= 0xF0;
gpiommgpio->control[control_port] &= ~BIT(0);
}
} else {
gpiommgpio->io_state[io_port] &= 0x00;
if (io_port == 0 || io_port == 3)
gpiommgpio->control[control_port] &= ~BIT(4);
else
gpiommgpio->control[control_port] &= ~BIT(1);
}
if (value)
gpiommgpio->out_state[io_port] |= mask;
else
gpiommgpio->out_state[io_port] &= ~mask;
control = BIT(7) | gpiommgpio->control[control_port];
outb(control, control_addr);
outb(gpiommgpio->out_state[io_port], gpiommgpio->base + out_port);
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
return 0;
}
static int gpiomm_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
const unsigned int port = offset / 8;
const unsigned int mask = BIT(offset % 8);
const unsigned int in_port = (port > 2) ? port + 1 : port;
unsigned long flags;
unsigned int port_state;
spin_lock_irqsave(&gpiommgpio->lock, flags);
if (!(gpiommgpio->io_state[port] & mask)) {
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
return -EINVAL;
}
port_state = inb(gpiommgpio->base + in_port);
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
return !!(port_state & mask);
}
static void gpiomm_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
const unsigned int port = offset / 8;
const unsigned int mask = BIT(offset % 8);
const unsigned int out_port = (port > 2) ? port + 1 : port;
unsigned long flags;
spin_lock_irqsave(&gpiommgpio->lock, flags);
if (value)
gpiommgpio->out_state[port] |= mask;
else
gpiommgpio->out_state[port] &= ~mask;
outb(gpiommgpio->out_state[port], gpiommgpio->base + out_port);
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
}
static void gpiomm_gpio_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
struct gpiomm_gpio *const gpiommgpio = gpiochip_get_data(chip);
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
spin_lock_irqsave(&gpiommgpio->lock, flags);
gpiommgpio->out_state[port] &= ~mask[BIT_WORD(i)];
gpiommgpio->out_state[port] |= bitmask;
outb(gpiommgpio->out_state[port], gpiommgpio->base + out_port);
spin_unlock_irqrestore(&gpiommgpio->lock, flags);
mask[BIT_WORD(i)] >>= gpio_reg_size;
bits[BIT_WORD(i)] >>= gpio_reg_size;
}
}
static int gpiomm_probe(struct device *dev, unsigned int id)
{
struct gpiomm_gpio *gpiommgpio;
const char *const name = dev_name(dev);
int err;
gpiommgpio = devm_kzalloc(dev, sizeof(*gpiommgpio), GFP_KERNEL);
if (!gpiommgpio)
return -ENOMEM;
if (!devm_request_region(dev, base[id], GPIOMM_EXTENT, name)) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + GPIOMM_EXTENT);
return -EBUSY;
}
gpiommgpio->chip.label = name;
gpiommgpio->chip.parent = dev;
gpiommgpio->chip.owner = THIS_MODULE;
gpiommgpio->chip.base = -1;
gpiommgpio->chip.ngpio = GPIOMM_NGPIO;
gpiommgpio->chip.names = gpiomm_names;
gpiommgpio->chip.get_direction = gpiomm_gpio_get_direction;
gpiommgpio->chip.direction_input = gpiomm_gpio_direction_input;
gpiommgpio->chip.direction_output = gpiomm_gpio_direction_output;
gpiommgpio->chip.get = gpiomm_gpio_get;
gpiommgpio->chip.set = gpiomm_gpio_set;
gpiommgpio->chip.set_multiple = gpiomm_gpio_set_multiple;
gpiommgpio->base = base[id];
spin_lock_init(&gpiommgpio->lock);
err = devm_gpiochip_add_data(dev, &gpiommgpio->chip, gpiommgpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
outb(0x80, base[id] + 3);
outb(0x00, base[id]);
outb(0x00, base[id] + 1);
outb(0x00, base[id] + 2);
outb(0x80, base[id] + 7);
outb(0x00, base[id] + 4);
outb(0x00, base[id] + 5);
outb(0x00, base[id] + 6);
return 0;
}
