static int stx104_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
struct stx104_iio *const priv = iio_priv(indio_dev);
unsigned int adc_config;
int adbu;
int gain;
switch (mask) {
case IIO_CHAN_INFO_HARDWAREGAIN:
adc_config = inb(priv->base + 11);
gain = adc_config & 0x3;
*val = 1 << gain;
return IIO_VAL_INT;
case IIO_CHAN_INFO_RAW:
if (chan->output) {
*val = priv->chan_out_states[chan->channel];
return IIO_VAL_INT;
}
outb(chan->channel | (chan->channel << 4), priv->base + 2);
outb(0, priv->base);
while (inb(priv->base + 8) & BIT(7));
*val = inw(priv->base);
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
adc_config = inb(priv->base + 11);
adbu = !(adc_config & BIT(2));
*val = -32768 * adbu;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
adc_config = inb(priv->base + 11);
adbu = !(adc_config & BIT(2));
gain = adc_config & 0x3;
*val = 5;
*val2 = 15 - adbu + gain;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int stx104_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct stx104_iio *const priv = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_HARDWAREGAIN:
switch (val) {
case 1:
outb(0, priv->base + 11);
break;
case 2:
outb(1, priv->base + 11);
break;
case 4:
outb(2, priv->base + 11);
break;
case 8:
outb(3, priv->base + 11);
break;
default:
return -EINVAL;
}
return 0;
case IIO_CHAN_INFO_RAW:
if (chan->output) {
if ((unsigned int)val > 65535)
return -EINVAL;
priv->chan_out_states[chan->channel] = val;
outw(val, priv->base + 4 + 2 * chan->channel);
return 0;
}
return -EINVAL;
}
return -EINVAL;
}
static int stx104_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
if (offset < 4)
return 1;
return 0;
}
static int stx104_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
if (offset >= 4)
return -EINVAL;
return 0;
}
static int stx104_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
if (offset < 4)
return -EINVAL;
chip->set(chip, offset, value);
return 0;
}
static int stx104_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct stx104_gpio *const stx104gpio = gpiochip_get_data(chip);
if (offset >= 4)
return -EINVAL;
return !!(inb(stx104gpio->base) & BIT(offset));
}
static void stx104_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct stx104_gpio *const stx104gpio = gpiochip_get_data(chip);
const unsigned int mask = BIT(offset) >> 4;
unsigned long flags;
if (offset < 4)
return;
spin_lock_irqsave(&stx104gpio->lock, flags);
if (value)
stx104gpio->out_state |= mask;
else
stx104gpio->out_state &= ~mask;
outb(stx104gpio->out_state, stx104gpio->base);
spin_unlock_irqrestore(&stx104gpio->lock, flags);
}
static void stx104_gpio_set_multiple(struct gpio_chip *chip,
unsigned long *mask, unsigned long *bits)
{
struct stx104_gpio *const stx104gpio = gpiochip_get_data(chip);
unsigned long flags;
if (!(*mask & 0xF0))
return;
*mask >>= 4;
*bits >>= 4;
spin_lock_irqsave(&stx104gpio->lock, flags);
stx104gpio->out_state &= ~*mask;
stx104gpio->out_state |= *mask & *bits;
outb(stx104gpio->out_state, stx104gpio->base);
spin_unlock_irqrestore(&stx104gpio->lock, flags);
}
static int stx104_probe(struct device *dev, unsigned int id)
{
struct iio_dev *indio_dev;
struct stx104_iio *priv;
struct stx104_gpio *stx104gpio;
int err;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev)
return -ENOMEM;
stx104gpio = devm_kzalloc(dev, sizeof(*stx104gpio), GFP_KERNEL);
if (!stx104gpio)
return -ENOMEM;
if (!devm_request_region(dev, base[id], STX104_EXTENT,
dev_name(dev))) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + STX104_EXTENT);
return -EBUSY;
}
indio_dev->info = &stx104_info;
indio_dev->modes = INDIO_DIRECT_MODE;
if (inb(base[id] + 8) & BIT(5)) {
indio_dev->num_channels = ARRAY_SIZE(stx104_channels_diff);
indio_dev->channels = stx104_channels_diff;
} else {
indio_dev->num_channels = ARRAY_SIZE(stx104_channels_sing);
indio_dev->channels = stx104_channels_sing;
}
indio_dev->name = dev_name(dev);
indio_dev->dev.parent = dev;
priv = iio_priv(indio_dev);
priv->base = base[id];
outb(0, base[id] + 9);
outb(0, base[id] + 11);
outw(0, base[id] + 4);
outw(0, base[id] + 6);
stx104gpio->chip.label = dev_name(dev);
stx104gpio->chip.parent = dev;
stx104gpio->chip.owner = THIS_MODULE;
stx104gpio->chip.base = -1;
stx104gpio->chip.ngpio = STX104_NGPIO;
stx104gpio->chip.names = stx104_names;
stx104gpio->chip.get_direction = stx104_gpio_get_direction;
stx104gpio->chip.direction_input = stx104_gpio_direction_input;
stx104gpio->chip.direction_output = stx104_gpio_direction_output;
stx104gpio->chip.get = stx104_gpio_get;
stx104gpio->chip.set = stx104_gpio_set;
stx104gpio->chip.set_multiple = stx104_gpio_set_multiple;
stx104gpio->base = base[id] + 3;
stx104gpio->out_state = 0x0;
spin_lock_init(&stx104gpio->lock);
err = devm_gpiochip_add_data(dev, &stx104gpio->chip, stx104gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
return devm_iio_device_register(dev, indio_dev);
}
