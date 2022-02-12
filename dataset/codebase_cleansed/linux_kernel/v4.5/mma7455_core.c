static int mma7455_drdy(struct mma7455_data *mma7455)
{
unsigned int reg;
int tries = 3;
int ret;
while (tries-- > 0) {
ret = regmap_read(mma7455->regmap, MMA7455_REG_STATUS, &reg);
if (ret)
return ret;
if (reg & MMA7455_STATUS_DRDY)
return 0;
msleep(20);
}
dev_warn(mma7455->dev, "data not ready\n");
return -EIO;
}
static irqreturn_t mma7455_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct mma7455_data *mma7455 = iio_priv(indio_dev);
u8 buf[16];
int ret;
ret = mma7455_drdy(mma7455);
if (ret)
goto done;
ret = regmap_bulk_read(mma7455->regmap, MMA7455_REG_XOUTL, buf,
sizeof(__le16) * 3);
if (ret)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, buf, iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int mma7455_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mma7455_data *mma7455 = iio_priv(indio_dev);
unsigned int reg;
__le16 data;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
ret = mma7455_drdy(mma7455);
if (ret)
return ret;
ret = regmap_bulk_read(mma7455->regmap, chan->address, &data,
sizeof(data));
if (ret)
return ret;
*val = sign_extend32(le16_to_cpu(data), 9);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = MMA7455_10BIT_SCALE;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = regmap_read(mma7455->regmap, MMA7455_REG_CTL1, &reg);
if (ret)
return ret;
if (reg & MMA7455_CTL1_DFBW_MASK)
*val = 250;
else
*val = 125;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int mma7455_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mma7455_data *mma7455 = iio_priv(indio_dev);
int i;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val == 250 && val2 == 0)
i = MMA7455_CTL1_DFBW_125HZ;
else if (val == 125 && val2 == 0)
i = MMA7455_CTL1_DFBW_62_5HZ;
else
return -EINVAL;
return regmap_update_bits(mma7455->regmap, MMA7455_REG_CTL1,
MMA7455_CTL1_DFBW_MASK, i);
case IIO_CHAN_INFO_SCALE:
if (val == 0 && val2 == MMA7455_10BIT_SCALE)
return 0;
break;
}
return -EINVAL;
}
int mma7455_core_probe(struct device *dev, struct regmap *regmap,
const char *name)
{
struct mma7455_data *mma7455;
struct iio_dev *indio_dev;
unsigned int reg;
int ret;
ret = regmap_read(regmap, MMA7455_REG_WHOAMI, &reg);
if (ret) {
dev_err(dev, "unable to read reg\n");
return ret;
}
if (reg != MMA7455_WHOAMI_ID) {
dev_err(dev, "device id mismatch\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(dev, sizeof(*mma7455));
if (!indio_dev)
return -ENOMEM;
dev_set_drvdata(dev, indio_dev);
mma7455 = iio_priv(indio_dev);
mma7455->regmap = regmap;
mma7455->dev = dev;
indio_dev->info = &mma7455_info;
indio_dev->name = name;
indio_dev->dev.parent = dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mma7455_channels;
indio_dev->num_channels = ARRAY_SIZE(mma7455_channels);
indio_dev->available_scan_masks = mma7455_scan_masks;
regmap_write(mma7455->regmap, MMA7455_REG_MCTL,
MMA7455_MCTL_MODE_MEASURE);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
mma7455_trigger_handler, NULL);
if (ret) {
dev_err(dev, "unable to setup triggered buffer\n");
return ret;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "unable to register device\n");
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
return 0;
}
int mma7455_core_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct mma7455_data *mma7455 = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regmap_write(mma7455->regmap, MMA7455_REG_MCTL,
MMA7455_MCTL_MODE_STANDBY);
return 0;
}
