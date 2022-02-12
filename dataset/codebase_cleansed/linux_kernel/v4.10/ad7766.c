static irqreturn_t ad7766_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7766 *ad7766 = iio_priv(indio_dev);
int ret;
ret = spi_sync(ad7766->spi, &ad7766->msg);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, ad7766->data,
pf->timestamp);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ad7766_preenable(struct iio_dev *indio_dev)
{
struct ad7766 *ad7766 = iio_priv(indio_dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ad7766->reg), ad7766->reg);
if (ret < 0) {
dev_err(&ad7766->spi->dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
ret = clk_prepare_enable(ad7766->mclk);
if (ret < 0) {
dev_err(&ad7766->spi->dev, "Failed to enable MCLK: %d\n", ret);
regulator_bulk_disable(ARRAY_SIZE(ad7766->reg), ad7766->reg);
return ret;
}
if (ad7766->pd_gpio)
gpiod_set_value(ad7766->pd_gpio, 0);
return 0;
}
static int ad7766_postdisable(struct iio_dev *indio_dev)
{
struct ad7766 *ad7766 = iio_priv(indio_dev);
if (ad7766->pd_gpio)
gpiod_set_value(ad7766->pd_gpio, 1);
msleep(20);
clk_disable_unprepare(ad7766->mclk);
regulator_bulk_disable(ARRAY_SIZE(ad7766->reg), ad7766->reg);
return 0;
}
static int ad7766_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
struct ad7766 *ad7766 = iio_priv(indio_dev);
struct regulator *vref = ad7766->reg[AD7766_SUPPLY_VREF].consumer;
int scale_uv;
switch (info) {
case IIO_CHAN_INFO_SCALE:
scale_uv = regulator_get_voltage(vref);
if (scale_uv < 0)
return scale_uv;
*val = scale_uv / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = clk_get_rate(ad7766->mclk) /
ad7766->chip_info->decimation_factor;
return IIO_VAL_INT;
}
return -EINVAL;
}
static irqreturn_t ad7766_irq(int irq, void *private)
{
iio_trigger_poll(private);
return IRQ_HANDLED;
}
static int ad7766_set_trigger_state(struct iio_trigger *trig, bool enable)
{
struct ad7766 *ad7766 = iio_trigger_get_drvdata(trig);
if (enable)
enable_irq(ad7766->spi->irq);
else
disable_irq(ad7766->spi->irq);
return 0;
}
static int ad7766_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct iio_dev *indio_dev;
struct ad7766 *ad7766;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*ad7766));
if (!indio_dev)
return -ENOMEM;
ad7766 = iio_priv(indio_dev);
ad7766->chip_info = &ad7766_chip_info[id->driver_data];
ad7766->mclk = devm_clk_get(&spi->dev, "mclk");
if (IS_ERR(ad7766->mclk))
return PTR_ERR(ad7766->mclk);
ad7766->reg[AD7766_SUPPLY_AVDD].supply = "avdd";
ad7766->reg[AD7766_SUPPLY_DVDD].supply = "dvdd";
ad7766->reg[AD7766_SUPPLY_VREF].supply = "vref";
ret = devm_regulator_bulk_get(&spi->dev, ARRAY_SIZE(ad7766->reg),
ad7766->reg);
if (ret)
return ret;
ad7766->pd_gpio = devm_gpiod_get_optional(&spi->dev, "powerdown",
GPIOD_OUT_HIGH);
if (IS_ERR(ad7766->pd_gpio))
return PTR_ERR(ad7766->pd_gpio);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad7766_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7766_channels);
indio_dev->info = &ad7766_info;
if (spi->irq > 0) {
ad7766->trig = devm_iio_trigger_alloc(&spi->dev, "%s-dev%d",
indio_dev->name, indio_dev->id);
if (!ad7766->trig)
return -ENOMEM;
ad7766->trig->ops = &ad7766_trigger_ops;
ad7766->trig->dev.parent = &spi->dev;
iio_trigger_set_drvdata(ad7766->trig, ad7766);
ret = devm_request_irq(&spi->dev, spi->irq, ad7766_irq,
IRQF_TRIGGER_FALLING, dev_name(&spi->dev),
ad7766->trig);
if (ret < 0)
return ret;
disable_irq(spi->irq);
ret = devm_iio_trigger_register(&spi->dev, ad7766->trig);
if (ret)
return ret;
}
spi_set_drvdata(spi, indio_dev);
ad7766->spi = spi;
ad7766->xfer.rx_buf = &ad7766->data[1];
ad7766->xfer.len = 3;
spi_message_init(&ad7766->msg);
spi_message_add_tail(&ad7766->xfer, &ad7766->msg);
ret = devm_iio_triggered_buffer_setup(&spi->dev, indio_dev,
&iio_pollfunc_store_time, &ad7766_trigger_handler,
&ad7766_buffer_setup_ops);
if (ret)
return ret;
ret = devm_iio_device_register(&spi->dev, indio_dev);
if (ret)
return ret;
return 0;
}
