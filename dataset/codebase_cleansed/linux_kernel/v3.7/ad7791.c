static struct ad7791_state *ad_sigma_delta_to_ad7791(struct ad_sigma_delta *sd)
{
return container_of(sd, struct ad7791_state, sd);
}
static int ad7791_set_channel(struct ad_sigma_delta *sd, unsigned int channel)
{
ad_sd_set_comm(sd, channel);
return 0;
}
static int ad7791_set_mode(struct ad_sigma_delta *sd,
enum ad_sigma_delta_mode mode)
{
struct ad7791_state *st = ad_sigma_delta_to_ad7791(sd);
switch (mode) {
case AD_SD_MODE_CONTINUOUS:
mode = AD7791_MODE_CONTINUOUS;
break;
case AD_SD_MODE_SINGLE:
mode = AD7791_MODE_SINGLE;
break;
case AD_SD_MODE_IDLE:
case AD_SD_MODE_POWERDOWN:
mode = AD7791_MODE_POWERDOWN;
break;
}
st->mode &= ~AD7791_MODE_SEL_MASK;
st->mode |= AD7791_MODE_SEL(mode);
return ad_sd_write_reg(sd, AD7791_REG_MODE, sizeof(st->mode), st->mode);
}
static int ad7791_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
struct ad7791_state *st = iio_priv(indio_dev);
bool unipolar = !!(st->mode & AD7791_MODE_UNIPOLAR);
unsigned long long scale_pv;
switch (info) {
case IIO_CHAN_INFO_RAW:
return ad_sigma_delta_single_conversion(indio_dev, chan, val);
case IIO_CHAN_INFO_OFFSET:
if (unipolar)
*val = 0;
else
*val = -(1 << (chan->scan_type.realbits - 1));
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->address == AD7791_CH_AVDD_MONITOR) {
scale_pv = 5850000000000ULL;
} else {
int voltage_uv;
voltage_uv = regulator_get_voltage(st->reg);
if (voltage_uv < 0)
return voltage_uv;
scale_pv = (unsigned long long)voltage_uv * 1000000;
}
if (unipolar)
scale_pv >>= chan->scan_type.realbits;
else
scale_pv >>= chan->scan_type.realbits - 1;
*val2 = do_div(scale_pv, 1000000000);
*val = scale_pv;
return IIO_VAL_INT_PLUS_NANO;
}
return -EINVAL;
}
static ssize_t ad7791_read_frequency(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7791_state *st = iio_priv(indio_dev);
unsigned int rate = st->filter & AD7791_FILTER_RATE_MASK;
return sprintf(buf, "%s\n", ad7791_sample_freq_avail[rate]);
}
static ssize_t ad7791_write_frequency(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7791_state *st = iio_priv(indio_dev);
int i, ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
mutex_unlock(&indio_dev->mlock);
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(ad7791_sample_freq_avail); i++) {
if (sysfs_streq(ad7791_sample_freq_avail[i], buf)) {
mutex_lock(&indio_dev->mlock);
st->filter &= ~AD7791_FILTER_RATE_MASK;
st->filter |= i;
ad_sd_write_reg(&st->sd, AD7791_REG_FILTER,
sizeof(st->filter), st->filter);
mutex_unlock(&indio_dev->mlock);
ret = 0;
break;
}
}
return ret ? ret : len;
}
static int __devinit ad7791_setup(struct ad7791_state *st,
struct ad7791_platform_data *pdata)
{
st->mode = AD7791_MODE_BUFFER;
st->filter = AD7791_FILTER_RATE_16_6;
if (!pdata)
return 0;
if ((st->info->flags & AD7791_FLAG_HAS_BUFFER) && !pdata->buffered)
st->mode &= ~AD7791_MODE_BUFFER;
if ((st->info->flags & AD7791_FLAG_HAS_BURNOUT) &&
pdata->burnout_current)
st->mode |= AD7791_MODE_BURNOUT;
if ((st->info->flags & AD7791_FLAG_HAS_UNIPOLAR) && pdata->unipolar)
st->mode |= AD7791_MODE_UNIPOLAR;
return ad_sd_write_reg(&st->sd, AD7791_REG_MODE, sizeof(st->mode),
st->mode);
}
static int __devinit ad7791_probe(struct spi_device *spi)
{
struct ad7791_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct ad7791_state *st;
int ret;
if (!spi->irq) {
dev_err(&spi->dev, "Missing IRQ.\n");
return -ENXIO;
}
indio_dev = iio_device_alloc(sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "refin");
if (IS_ERR(st->reg)) {
ret = PTR_ERR(st->reg);
goto err_iio_free;
}
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
st->info = &ad7791_chip_infos[spi_get_device_id(spi)->driver_data];
ad_sd_init(&st->sd, indio_dev, spi, &ad7791_sigma_delta_info);
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->info->channels;
indio_dev->num_channels = st->info->num_channels;
if (st->info->flags & AD7791_FLAG_HAS_FILTER)
indio_dev->info = &ad7791_info;
else
indio_dev->info = &ad7791_no_filter_info;
ret = ad_sd_setup_buffer_and_trigger(indio_dev);
if (ret)
goto error_disable_reg;
ret = ad7791_setup(st, pdata);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
ad_sd_cleanup_buffer_and_trigger(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
error_put_reg:
regulator_put(st->reg);
err_iio_free:
iio_device_free(indio_dev);
return ret;
}
static int __devexit ad7791_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7791_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad_sd_cleanup_buffer_and_trigger(indio_dev);
regulator_disable(st->reg);
regulator_put(st->reg);
iio_device_free(indio_dev);
return 0;
}
