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
static int stx104_probe(struct device *dev, unsigned int id)
{
struct iio_dev *indio_dev;
struct stx104_iio *priv;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev)
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
return devm_iio_device_register(dev, indio_dev);
}
