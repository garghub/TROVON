static int ad7780_read(struct ad7780_state *st, int *val)
{
int ret;
spi_bus_lock(st->spi->master);
enable_irq(st->spi->irq);
st->done = false;
gpio_set_value(st->pdata->gpio_pdrst, 1);
ret = wait_event_interruptible(st->wq_data_avail, st->done);
disable_irq_nosync(st->spi->irq);
if (ret)
goto out;
ret = spi_sync_locked(st->spi, &st->msg);
*val = be32_to_cpu(st->data);
out:
gpio_set_value(st->pdata->gpio_pdrst, 0);
spi_bus_unlock(st->spi->master);
return ret;
}
static int ad7780_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad7780_state *st = iio_priv(indio_dev);
struct iio_chan_spec channel = st->chip_info->channel;
int ret, smpl = 0;
unsigned long scale_uv;
switch (m) {
case 0:
mutex_lock(&indio_dev->mlock);
ret = ad7780_read(st, &smpl);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
if ((smpl & AD7780_ERR) ||
!((smpl & AD7780_PAT0) && !(smpl & AD7780_PAT1)))
return -EIO;
*val = (smpl >> channel.scan_type.shift) &
((1 << (channel.scan_type.realbits)) - 1);
*val -= (1 << (channel.scan_type.realbits - 1));
if (!(smpl & AD7780_GAIN))
*val *= 128;
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_SCALE_SHARED):
scale_uv = (st->int_vref_mv * 100000)
>> (channel.scan_type.realbits - 1);
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static irqreturn_t ad7780_interrupt(int irq, void *dev_id)
{
struct ad7780_state *st = dev_id;
st->done = true;
wake_up_interruptible(&st->wq_data_avail);
return IRQ_HANDLED;
}
static int __devinit ad7780_probe(struct spi_device *spi)
{
struct ad7780_platform_data *pdata = spi->dev.platform_data;
struct ad7780_state *st;
struct iio_dev *indio_dev;
int ret, voltage_uv = 0;
if (!pdata) {
dev_dbg(&spi->dev, "no platform data?\n");
return -ENODEV;
}
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad7780_chip_info_tbl[spi_get_device_id(spi)->driver_data];
st->pdata = pdata;
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &st->chip_info->channel;
indio_dev->num_channels = 1;
indio_dev->info = &ad7780_info;
init_waitqueue_head(&st->wq_data_avail);
st->xfer.rx_buf = &st->data;
st->xfer.len = st->chip_info->channel.scan_type.storagebits / 8;
spi_message_init(&st->msg);
spi_message_add_tail(&st->xfer, &st->msg);
ret = gpio_request_one(st->pdata->gpio_pdrst, GPIOF_OUT_INIT_LOW,
"AD7780 /PDRST");
if (ret) {
dev_err(&spi->dev, "failed to request GPIO PDRST\n");
goto error_disable_reg;
}
ret = request_irq(spi->irq, ad7780_interrupt,
IRQF_TRIGGER_FALLING, spi_get_device_id(spi)->name, st);
if (ret)
goto error_free_gpio;
disable_irq(spi->irq);
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
free_irq(spi->irq, st);
error_free_gpio:
gpio_free(st->pdata->gpio_pdrst);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_free_device(indio_dev);
return ret;
}
static int ad7780_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7780_state *st = iio_priv(indio_dev);
free_irq(spi->irq, st);
gpio_free(st->pdata->gpio_pdrst);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_unregister(indio_dev);
return 0;
}
static int __init ad7780_init(void)
{
return spi_register_driver(&ad7780_driver);
}
static void __exit ad7780_exit(void)
{
spi_unregister_driver(&ad7780_driver);
}
