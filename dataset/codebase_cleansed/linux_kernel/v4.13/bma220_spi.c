static inline int bma220_read_reg(struct spi_device *spi, u8 reg)
{
return spi_w8r8(spi, reg | BMA220_READ_MASK);
}
static irqreturn_t bma220_trigger_handler(int irq, void *p)
{
int ret;
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bma220_data *data = iio_priv(indio_dev);
struct spi_device *spi = data->spi_device;
mutex_lock(&data->lock);
data->tx_buf[0] = BMA220_REG_ACCEL_X | BMA220_READ_MASK;
ret = spi_write_then_read(spi, data->tx_buf, 1, data->buffer,
ARRAY_SIZE(bma220_channels) - 1);
if (ret < 0)
goto err;
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
mutex_unlock(&data->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bma220_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
u8 range_idx;
struct bma220_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = bma220_read_reg(data->spi_device, chan->address);
if (ret < 0)
return -EINVAL;
*val = sign_extend32(ret >> BMA220_DATA_SHIFT, 5);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = bma220_read_reg(data->spi_device, BMA220_REG_RANGE);
if (ret < 0)
return ret;
range_idx = ret & BMA220_RANGE_MASK;
*val = bma220_scale_table[range_idx][0];
*val2 = bma220_scale_table[range_idx][1];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int bma220_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int i;
int ret;
int index = -1;
struct bma220_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
for (i = 0; i < ARRAY_SIZE(bma220_scale_table); i++)
if (val == bma220_scale_table[i][0] &&
val2 == bma220_scale_table[i][1]) {
index = i;
break;
}
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
data->tx_buf[0] = BMA220_REG_RANGE;
data->tx_buf[1] = index;
ret = spi_write(data->spi_device, data->tx_buf,
sizeof(data->tx_buf));
if (ret < 0)
dev_err(&data->spi_device->dev,
"failed to set measurement range\n");
mutex_unlock(&data->lock);
return 0;
}
return -EINVAL;
}
static int bma220_init(struct spi_device *spi)
{
int ret;
ret = bma220_read_reg(spi, BMA220_REG_ID);
if (ret != BMA220_CHIP_ID)
return -ENODEV;
ret = bma220_read_reg(spi, BMA220_REG_SUSPEND);
if (ret < 0)
return ret;
else if (ret == BMA220_SUSPEND_WAKE)
return bma220_read_reg(spi, BMA220_REG_SUSPEND);
return 0;
}
static int bma220_deinit(struct spi_device *spi)
{
int ret;
ret = bma220_read_reg(spi, BMA220_REG_SUSPEND);
if (ret < 0)
return ret;
else if (ret == BMA220_SUSPEND_SLEEP)
return bma220_read_reg(spi, BMA220_REG_SUSPEND);
return 0;
}
static int bma220_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev;
struct bma220_data *data;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&spi->dev, "iio allocation failed!\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->spi_device = spi;
spi_set_drvdata(spi, indio_dev);
mutex_init(&data->lock);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &bma220_info;
indio_dev->name = BMA220_DEVICE_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = bma220_channels;
indio_dev->num_channels = ARRAY_SIZE(bma220_channels);
indio_dev->available_scan_masks = bma220_accel_scan_masks;
ret = bma220_init(data->spi_device);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, iio_pollfunc_store_time,
bma220_trigger_handler, NULL);
if (ret < 0) {
dev_err(&spi->dev, "iio triggered buffer setup failed\n");
goto err_suspend;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&spi->dev, "iio_device_register failed\n");
iio_triggered_buffer_cleanup(indio_dev);
goto err_suspend;
}
return 0;
err_suspend:
return bma220_deinit(spi);
}
static int bma220_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return bma220_deinit(spi);
}
static int bma220_suspend(struct device *dev)
{
struct bma220_data *data =
iio_priv(spi_get_drvdata(to_spi_device(dev)));
return bma220_read_reg(data->spi_device, BMA220_REG_SUSPEND);
}
static int bma220_resume(struct device *dev)
{
struct bma220_data *data =
iio_priv(spi_get_drvdata(to_spi_device(dev)));
return bma220_read_reg(data->spi_device, BMA220_REG_SUSPEND);
}
