static int stx104_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
struct stx104_iio *const priv = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
*val = priv->chan_out_states[chan->channel];
return IIO_VAL_INT;
}
static int stx104_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct stx104_iio *const priv = iio_priv(indio_dev);
const unsigned chan_addr_offset = 2 * chan->channel;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
priv->chan_out_states[chan->channel] = val;
outw(val, priv->base + 4 + chan_addr_offset);
return 0;
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
static int stx104_probe(struct device *dev, unsigned int id)
{
struct iio_dev *indio_dev;
struct stx104_iio *priv;
struct stx104_gpio *stx104gpio;
struct stx104_dev *stx104dev;
int err;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev)
return -ENOMEM;
stx104gpio = devm_kzalloc(dev, sizeof(*stx104gpio), GFP_KERNEL);
if (!stx104gpio)
return -ENOMEM;
stx104dev = devm_kzalloc(dev, sizeof(*stx104dev), GFP_KERNEL);
if (!stx104dev)
return -ENOMEM;
if (!devm_request_region(dev, base[id], STX104_EXTENT,
dev_name(dev))) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + STX104_EXTENT);
return -EBUSY;
}
indio_dev->info = &stx104_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stx104_channels;
indio_dev->num_channels = STX104_NUM_CHAN;
indio_dev->name = dev_name(dev);
priv = iio_priv(indio_dev);
priv->base = base[id];
outw(0, base[id] + 4);
outw(0, base[id] + 6);
stx104gpio->chip.label = dev_name(dev);
stx104gpio->chip.parent = dev;
stx104gpio->chip.owner = THIS_MODULE;
stx104gpio->chip.base = -1;
stx104gpio->chip.ngpio = 8;
stx104gpio->chip.get_direction = stx104_gpio_get_direction;
stx104gpio->chip.direction_input = stx104_gpio_direction_input;
stx104gpio->chip.direction_output = stx104_gpio_direction_output;
stx104gpio->chip.get = stx104_gpio_get;
stx104gpio->chip.set = stx104_gpio_set;
stx104gpio->base = base[id] + 3;
stx104gpio->out_state = 0x0;
spin_lock_init(&stx104gpio->lock);
stx104dev->indio_dev = indio_dev;
stx104dev->chip = &stx104gpio->chip;
dev_set_drvdata(dev, stx104dev);
err = gpiochip_add_data(&stx104gpio->chip, stx104gpio);
if (err) {
dev_err(dev, "GPIO registering failed (%d)\n", err);
return err;
}
err = iio_device_register(indio_dev);
if (err) {
dev_err(dev, "IIO device registering failed (%d)\n", err);
gpiochip_remove(&stx104gpio->chip);
return err;
}
return 0;
}
static int stx104_remove(struct device *dev, unsigned int id)
{
struct stx104_dev *const stx104dev = dev_get_drvdata(dev);
iio_device_unregister(stx104dev->indio_dev);
gpiochip_remove(stx104dev->chip);
return 0;
}
