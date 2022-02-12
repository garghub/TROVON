static struct ad7793_state *ad_sigma_delta_to_ad7793(struct ad_sigma_delta *sd)
{
return container_of(sd, struct ad7793_state, sd);
}
static int ad7793_set_channel(struct ad_sigma_delta *sd, unsigned int channel)
{
struct ad7793_state *st = ad_sigma_delta_to_ad7793(sd);
st->conf &= ~AD7793_CONF_CHAN_MASK;
st->conf |= AD7793_CONF_CHAN(channel);
return ad_sd_write_reg(&st->sd, AD7793_REG_CONF, 2, st->conf);
}
static int ad7793_set_mode(struct ad_sigma_delta *sd,
enum ad_sigma_delta_mode mode)
{
struct ad7793_state *st = ad_sigma_delta_to_ad7793(sd);
st->mode &= ~AD7793_MODE_SEL_MASK;
st->mode |= AD7793_MODE_SEL(mode);
return ad_sd_write_reg(&st->sd, AD7793_REG_MODE, 2, st->mode);
}
static int ad7793_calibrate_all(struct ad7793_state *st)
{
return ad_sd_calibrate_all(&st->sd, ad7793_calib_arr,
ARRAY_SIZE(ad7793_calib_arr));
}
static int ad7793_setup(struct iio_dev *indio_dev,
const struct ad7793_platform_data *pdata)
{
struct ad7793_state *st = iio_priv(indio_dev);
int i, ret = -1;
unsigned long long scale_uv;
u32 id;
ret = spi_write(st->sd.spi, (u8 *)&ret, sizeof(ret));
if (ret < 0)
goto out;
msleep(1);
ret = ad_sd_read_reg(&st->sd, AD7793_REG_ID, 1, &id);
if (ret)
goto out;
id &= AD7793_ID_MASK;
if (!((id == AD7792_ID) || (id == AD7793_ID) || (id == AD7795_ID))) {
dev_err(&st->sd.spi->dev, "device ID query failed\n");
goto out;
}
st->mode = pdata->mode;
st->conf = pdata->conf;
ret = ad7793_set_mode(&st->sd, AD_SD_MODE_IDLE);
if (ret)
goto out;
ret = ad7793_set_channel(&st->sd, 0);
if (ret)
goto out;
ret = ad_sd_write_reg(&st->sd, AD7793_REG_IO,
sizeof(pdata->io), pdata->io);
if (ret)
goto out;
ret = ad7793_calibrate_all(st);
if (ret)
goto out;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++) {
scale_uv = ((u64)st->int_vref_mv * 100000000)
>> (st->chip_info->channels[0].scan_type.realbits -
(!!(st->conf & AD7793_CONF_UNIPOLAR) ? 0 : 1));
scale_uv >>= i;
st->scale_avail[i][1] = do_div(scale_uv, 100000000) * 10;
st->scale_avail[i][0] = scale_uv;
}
return 0;
out:
dev_err(&st->sd.spi->dev, "setup failed\n");
return ret;
}
static ssize_t ad7793_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7793_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
sample_freq_avail[AD7793_MODE_RATE(st->mode)]);
}
static ssize_t ad7793_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7793_state *st = iio_priv(indio_dev);
long lval;
int i, ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
mutex_unlock(&indio_dev->mlock);
ret = strict_strtol(buf, 10, &lval);
if (ret)
return ret;
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(sample_freq_avail); i++)
if (lval == sample_freq_avail[i]) {
mutex_lock(&indio_dev->mlock);
st->mode &= ~AD7793_MODE_RATE(-1);
st->mode |= AD7793_MODE_RATE(i);
ad_sd_write_reg(&st->sd, AD7793_REG_MODE,
sizeof(st->mode), st->mode);
mutex_unlock(&indio_dev->mlock);
ret = 0;
}
return ret ? ret : len;
}
static ssize_t ad7793_show_scale_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7793_state *st = iio_priv(indio_dev);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
len += sprintf(buf + len, "%d.%09u ", st->scale_avail[i][0],
st->scale_avail[i][1]);
len += sprintf(buf + len, "\n");
return len;
}
static int ad7793_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad7793_state *st = iio_priv(indio_dev);
int ret;
unsigned long long scale_uv;
bool unipolar = !!(st->conf & AD7793_CONF_UNIPOLAR);
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = ad_sigma_delta_single_conversion(indio_dev, chan, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
if (chan->differential) {
*val = st->
scale_avail[(st->conf >> 8) & 0x7][0];
*val2 = st->
scale_avail[(st->conf >> 8) & 0x7][1];
return IIO_VAL_INT_PLUS_NANO;
} else {
scale_uv = (1170ULL * 100000000ULL * 6ULL);
}
break;
case IIO_TEMP:
scale_uv = 1444444444444ULL;
break;
default:
return -EINVAL;
}
scale_uv >>= (chan->scan_type.realbits - (unipolar ? 0 : 1));
*val = 0;
*val2 = scale_uv;
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_OFFSET:
if (!unipolar)
*val = -(1 << (chan->scan_type.realbits - 1));
else
*val = 0;
if (chan->type == IIO_TEMP) {
unsigned long long offset;
unsigned int shift;
shift = chan->scan_type.realbits - (unipolar ? 0 : 1);
offset = 273ULL << shift;
do_div(offset, 1444);
*val -= offset;
}
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad7793_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad7793_state *st = iio_priv(indio_dev);
int ret, i;
unsigned int tmp;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
switch (mask) {
case IIO_CHAN_INFO_SCALE:
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
if (val2 == st->scale_avail[i][1]) {
ret = 0;
tmp = st->conf;
st->conf &= ~AD7793_CONF_GAIN(-1);
st->conf |= AD7793_CONF_GAIN(i);
if (tmp == st->conf)
break;
ad_sd_write_reg(&st->sd, AD7793_REG_CONF,
sizeof(st->conf), st->conf);
ad7793_calibrate_all(st);
break;
}
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7793_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
return IIO_VAL_INT_PLUS_NANO;
}
static int __devinit ad7793_probe(struct spi_device *spi)
{
const struct ad7793_platform_data *pdata = spi->dev.platform_data;
struct ad7793_state *st;
struct iio_dev *indio_dev;
int ret, voltage_uv = 0;
if (!pdata) {
dev_err(&spi->dev, "no platform data?\n");
return -ENODEV;
}
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ?\n");
return -ENODEV;
}
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
ad_sd_init(&st->sd, indio_dev, spi, &ad7793_sigma_delta_info);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad7793_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
st->int_vref_mv = 1170;
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
indio_dev->info = &ad7793_info;
ret = ad_sd_setup_buffer_and_trigger(indio_dev);
if (ret)
goto error_disable_reg;
ret = ad7793_setup(indio_dev, pdata);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
ad_sd_cleanup_buffer_and_trigger(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int __devexit ad7793_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7793_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad_sd_cleanup_buffer_and_trigger(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
