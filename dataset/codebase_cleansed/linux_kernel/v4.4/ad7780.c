static struct ad7780_state *ad_sigma_delta_to_ad7780(struct ad_sigma_delta *sd)
{
return container_of(sd, struct ad7780_state, sd);
}
static int ad7780_set_mode(struct ad_sigma_delta *sigma_delta,
enum ad_sigma_delta_mode mode)
{
struct ad7780_state *st = ad_sigma_delta_to_ad7780(sigma_delta);
unsigned val;
switch (mode) {
case AD_SD_MODE_SINGLE:
case AD_SD_MODE_CONTINUOUS:
val = 1;
break;
default:
val = 0;
break;
}
if (gpio_is_valid(st->powerdown_gpio))
gpio_set_value(st->powerdown_gpio, val);
return 0;
}
static int ad7780_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad7780_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
return ad_sigma_delta_single_conversion(indio_dev, chan, val);
case IIO_CHAN_INFO_SCALE:
*val = st->int_vref_mv * st->gain;
*val2 = chan->scan_type.realbits - 1;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
*val -= (1 << (chan->scan_type.realbits - 1));
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad7780_postprocess_sample(struct ad_sigma_delta *sigma_delta,
unsigned int raw_sample)
{
struct ad7780_state *st = ad_sigma_delta_to_ad7780(sigma_delta);
const struct ad7780_chip_info *chip_info = st->chip_info;
if ((raw_sample & AD7780_ERR) ||
((raw_sample & chip_info->pattern_mask) != chip_info->pattern))
return -EIO;
if (raw_sample & AD7780_GAIN)
st->gain = 1;
else
st->gain = 128;
return 0;
}
static int ad7780_probe(struct spi_device *spi)
{
struct ad7780_platform_data *pdata = spi->dev.platform_data;
struct ad7780_state *st;
struct iio_dev *indio_dev;
int ret, voltage_uv = 0;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->gain = 1;
ad_sd_init(&st->sd, indio_dev, spi, &ad7780_sigma_delta_info);
st->reg = devm_regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
return ret;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad7780_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &st->chip_info->channel;
indio_dev->num_channels = 1;
indio_dev->info = &ad7780_info;
if (pdata && gpio_is_valid(pdata->gpio_pdrst)) {
ret = devm_gpio_request_one(&spi->dev,
pdata->gpio_pdrst,
GPIOF_OUT_INIT_LOW,
"AD7780 /PDRST");
if (ret) {
dev_err(&spi->dev, "failed to request GPIO PDRST\n");
goto error_disable_reg;
}
st->powerdown_gpio = pdata->gpio_pdrst;
} else {
st->powerdown_gpio = -1;
}
ret = ad_sd_setup_buffer_and_trigger(indio_dev);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_buffer_and_trigger;
return 0;
error_cleanup_buffer_and_trigger:
ad_sd_cleanup_buffer_and_trigger(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return ret;
}
static int ad7780_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7780_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad_sd_cleanup_buffer_and_trigger(indio_dev);
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return 0;
}
