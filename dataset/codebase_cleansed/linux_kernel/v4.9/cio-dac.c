static int cio_dac_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
struct cio_dac_iio *const priv = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
*val = priv->chan_out_states[chan->channel];
return IIO_VAL_INT;
}
static int cio_dac_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct cio_dac_iio *const priv = iio_priv(indio_dev);
const unsigned int chan_addr_offset = 2 * chan->channel;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
if ((unsigned int)val > 65535)
return -EINVAL;
priv->chan_out_states[chan->channel] = val;
outw(val, priv->base + chan_addr_offset);
return 0;
}
static int cio_dac_probe(struct device *dev, unsigned int id)
{
struct iio_dev *indio_dev;
struct cio_dac_iio *priv;
unsigned int i;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev)
return -ENOMEM;
if (!devm_request_region(dev, base[id], CIO_DAC_EXTENT,
dev_name(dev))) {
dev_err(dev, "Unable to request port addresses (0x%X-0x%X)\n",
base[id], base[id] + CIO_DAC_EXTENT);
return -EBUSY;
}
indio_dev->info = &cio_dac_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = cio_dac_channels;
indio_dev->num_channels = CIO_DAC_NUM_CHAN;
indio_dev->name = dev_name(dev);
priv = iio_priv(indio_dev);
priv->base = base[id];
for (i = 0; i < 32; i += 2)
outw(0, base[id] + i);
return devm_iio_device_register(dev, indio_dev);
}
