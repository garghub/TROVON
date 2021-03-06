static int quad8_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel;
unsigned int flags;
unsigned int borrow;
unsigned int carry;
int i;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_INDEX) {
*val = !!(inb(priv->base + 0x16) & BIT(chan->channel));
return IIO_VAL_INT;
}
flags = inb(base_offset + 1);
borrow = flags & BIT(0);
carry = !!(flags & BIT(1));
*val = (borrow ^ carry) << 24;
outb(0x11, base_offset + 1);
for (i = 0; i < 3; i++)
*val |= (unsigned int)inb(base_offset) << (8 * i);
return IIO_VAL_INT;
case IIO_CHAN_INFO_ENABLE:
*val = priv->ab_enable[chan->channel];
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 1;
*val2 = priv->quadrature_scale[chan->channel];
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int quad8_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel;
int i;
unsigned int ior_cfg;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_INDEX)
return -EINVAL;
if ((unsigned int)val > 0xFFFFFF)
return -EINVAL;
outb(0x01, base_offset + 1);
for (i = 0; i < 3; i++)
outb(val >> (8 * i), base_offset);
outb(0x08, base_offset + 1);
outb(0x01, base_offset + 1);
val = priv->preset[chan->channel];
for (i = 0; i < 3; i++)
outb(val >> (8 * i), base_offset);
outb(0x02, base_offset + 1);
outb(0x06, base_offset + 1);
return 0;
case IIO_CHAN_INFO_ENABLE:
if (val < 0 || val > 1)
return -EINVAL;
priv->ab_enable[chan->channel] = val;
ior_cfg = val | priv->preset_enable[chan->channel] << 1;
outb(0x40 | ior_cfg, base_offset + 1);
return 0;
case IIO_CHAN_INFO_SCALE:
if (!priv->quadrature_mode[chan->channel] && (val2 || val != 1))
return -EINVAL;
if (val == 1 && !val2)
priv->quadrature_scale[chan->channel] = 0;
else if (!val)
switch (val2) {
case 500000:
priv->quadrature_scale[chan->channel] = 1;
break;
case 250000:
priv->quadrature_scale[chan->channel] = 2;
break;
default:
return -EINVAL;
}
else
return -EINVAL;
return 0;
}
return -EINVAL;
}
static ssize_t quad8_read_preset(struct iio_dev *indio_dev, uintptr_t private,
const struct iio_chan_spec *chan, char *buf)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return snprintf(buf, PAGE_SIZE, "%u\n", priv->preset[chan->channel]);
}
static ssize_t quad8_write_preset(struct iio_dev *indio_dev, uintptr_t private,
const struct iio_chan_spec *chan, const char *buf, size_t len)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel;
unsigned int preset;
int ret;
int i;
ret = kstrtouint(buf, 0, &preset);
if (ret)
return ret;
if (preset > 0xFFFFFF)
return -EINVAL;
priv->preset[chan->channel] = preset;
outb(0x01, base_offset + 1);
for (i = 0; i < 3; i++)
outb(preset >> (8 * i), base_offset);
return len;
}
static ssize_t quad8_read_set_to_preset_on_index(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return snprintf(buf, PAGE_SIZE, "%u\n",
!priv->preset_enable[chan->channel]);
}
static ssize_t quad8_write_set_to_preset_on_index(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel + 1;
bool preset_enable;
int ret;
unsigned int ior_cfg;
ret = kstrtobool(buf, &preset_enable);
if (ret)
return ret;
preset_enable = !preset_enable;
priv->preset_enable[chan->channel] = preset_enable;
ior_cfg = priv->ab_enable[chan->channel] |
(unsigned int)preset_enable << 1;
outb(0x40 | ior_cfg, base_offset);
return len;
}
static int quad8_get_noise_error(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel + 1;
return !!(inb(base_offset) & BIT(4));
}
static int quad8_get_count_direction(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const int base_offset = priv->base + 2 * chan->channel + 1;
return !!(inb(base_offset) & BIT(5));
}
static int quad8_set_count_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int count_mode)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
unsigned int mode_cfg = count_mode << 1;
const int base_offset = priv->base + 2 * chan->channel + 1;
priv->count_mode[chan->channel] = count_mode;
if (priv->quadrature_mode[chan->channel])
mode_cfg |= (priv->quadrature_scale[chan->channel] + 1) << 3;
outb(0x20 | mode_cfg, base_offset);
return 0;
}
static int quad8_get_count_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return priv->count_mode[chan->channel];
}
static int quad8_set_synchronous_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int synchronous_mode)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const unsigned int idr_cfg = synchronous_mode |
priv->index_polarity[chan->channel] << 1;
const int base_offset = priv->base + 2 * chan->channel + 1;
if (synchronous_mode && !priv->quadrature_mode[chan->channel])
return -EINVAL;
priv->synchronous_mode[chan->channel] = synchronous_mode;
outb(0x60 | idr_cfg, base_offset);
return 0;
}
static int quad8_get_synchronous_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return priv->synchronous_mode[chan->channel];
}
static int quad8_set_quadrature_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int quadrature_mode)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
unsigned int mode_cfg = priv->count_mode[chan->channel] << 1;
const int base_offset = priv->base + 2 * chan->channel + 1;
if (quadrature_mode)
mode_cfg |= (priv->quadrature_scale[chan->channel] + 1) << 3;
else {
priv->quadrature_scale[chan->channel] = 0;
if (priv->synchronous_mode[chan->channel])
quad8_set_synchronous_mode(indio_dev, chan, 0);
}
priv->quadrature_mode[chan->channel] = quadrature_mode;
outb(0x20 | mode_cfg, base_offset);
return 0;
}
static int quad8_get_quadrature_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return priv->quadrature_mode[chan->channel];
}
static int quad8_set_index_polarity(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int index_polarity)
{
struct quad8_iio *const priv = iio_priv(indio_dev);
const unsigned int idr_cfg = priv->synchronous_mode[chan->channel] |
index_polarity << 1;
const int base_offset = priv->base + 2 * chan->channel + 1;
priv->index_polarity[chan->channel] = index_polarity;
outb(0x60 | idr_cfg, base_offset);
return 0;
}
static int quad8_get_index_polarity(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
const struct quad8_iio *const priv = iio_priv(indio_dev);
return priv->index_polarity[chan->channel];
}
static int quad8_probe(struct device *dev, unsigned int id)
{
struct iio_dev *indio_dev;
struct quad8_iio *priv;
int i, j;
unsigned int base_offset;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev)
return -ENOMEM;
if (!devm_request_region(dev, base[id], QUAD8_EXTENT,
dev_name(dev))) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
base[id], base[id] + QUAD8_EXTENT);
return -EBUSY;
}
indio_dev->info = &quad8_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->num_channels = ARRAY_SIZE(quad8_channels);
indio_dev->channels = quad8_channels;
indio_dev->name = dev_name(dev);
priv = iio_priv(indio_dev);
priv->base = base[id];
outb(0x01, base[id] + 0x11);
for (i = 0; i < QUAD8_NUM_COUNTERS; i++) {
base_offset = base[id] + 2 * i;
outb(0x01, base_offset + 1);
for (j = 0; j < 3; j++)
outb(0x00, base_offset);
outb(0x04, base_offset + 1);
outb(0x06, base_offset + 1);
outb(0x20, base_offset + 1);
outb(0x40, base_offset + 1);
outb(0x60, base_offset + 1);
}
outb(0x00, base[id] + 0x11);
return devm_iio_device_register(dev, indio_dev);
}
