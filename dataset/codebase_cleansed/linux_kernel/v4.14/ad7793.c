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
static int ad7793_check_platform_data(struct ad7793_state *st,
const struct ad7793_platform_data *pdata)
{
if ((pdata->current_source_direction == AD7793_IEXEC1_IEXEC2_IOUT1 ||
pdata->current_source_direction == AD7793_IEXEC1_IEXEC2_IOUT2) &&
((pdata->exitation_current != AD7793_IX_10uA) &&
(pdata->exitation_current != AD7793_IX_210uA)))
return -EINVAL;
if (!(st->chip_info->flags & AD7793_FLAG_HAS_CLKSEL) &&
pdata->clock_src != AD7793_CLK_SRC_INT)
return -EINVAL;
if (!(st->chip_info->flags & AD7793_FLAG_HAS_REFSEL) &&
pdata->refsel != AD7793_REFSEL_REFIN1)
return -EINVAL;
if (!(st->chip_info->flags & AD7793_FLAG_HAS_VBIAS) &&
pdata->bias_voltage != AD7793_BIAS_VOLTAGE_DISABLED)
return -EINVAL;
if (!(st->chip_info->flags & AD7793_HAS_EXITATION_CURRENT) &&
pdata->exitation_current != AD7793_IX_DISABLED)
return -EINVAL;
return 0;
}
static int ad7793_setup(struct iio_dev *indio_dev,
const struct ad7793_platform_data *pdata,
unsigned int vref_mv)
{
struct ad7793_state *st = iio_priv(indio_dev);
int i, ret;
unsigned long long scale_uv;
u32 id;
ret = ad7793_check_platform_data(st, pdata);
if (ret)
return ret;
ret = ad_sd_reset(&st->sd, 32);
if (ret < 0)
goto out;
usleep_range(500, 2000);
ret = ad_sd_read_reg(&st->sd, AD7793_REG_ID, 1, &id);
if (ret)
goto out;
id &= AD7793_ID_MASK;
if (id != st->chip_info->id) {
dev_err(&st->sd.spi->dev, "device ID query failed\n");
goto out;
}
st->mode = AD7793_MODE_RATE(1);
st->conf = 0;
if (st->chip_info->flags & AD7793_FLAG_HAS_CLKSEL)
st->mode |= AD7793_MODE_CLKSRC(pdata->clock_src);
if (st->chip_info->flags & AD7793_FLAG_HAS_REFSEL)
st->conf |= AD7793_CONF_REFSEL(pdata->refsel);
if (st->chip_info->flags & AD7793_FLAG_HAS_VBIAS)
st->conf |= AD7793_CONF_VBIAS(pdata->bias_voltage);
if (pdata->buffered || !(st->chip_info->flags & AD7793_FLAG_HAS_BUFFER))
st->conf |= AD7793_CONF_BUF;
if (pdata->boost_enable &&
(st->chip_info->flags & AD7793_FLAG_HAS_VBIAS))
st->conf |= AD7793_CONF_BOOST;
if (pdata->burnout_current)
st->conf |= AD7793_CONF_BO_EN;
if (pdata->unipolar)
st->conf |= AD7793_CONF_UNIPOLAR;
if (!(st->chip_info->flags & AD7793_FLAG_HAS_GAIN))
st->conf |= AD7793_CONF_GAIN(7);
ret = ad7793_set_mode(&st->sd, AD_SD_MODE_IDLE);
if (ret)
goto out;
ret = ad7793_set_channel(&st->sd, 0);
if (ret)
goto out;
if (st->chip_info->flags & AD7793_HAS_EXITATION_CURRENT) {
ret = ad_sd_write_reg(&st->sd, AD7793_REG_IO, 1,
pdata->exitation_current |
(pdata->current_source_direction << 2));
if (ret)
goto out;
}
ret = ad7793_calibrate_all(st);
if (ret)
goto out;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++) {
scale_uv = ((u64)vref_mv * 100000000)
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
st->chip_info->sample_freq_avail[AD7793_MODE_RATE(st->mode)]);
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
ret = kstrtol(buf, 10, &lval);
if (ret)
return ret;
if (lval == 0)
return -EINVAL;
for (i = 0; i < 16; i++)
if (lval == st->chip_info->sample_freq_avail[i])
break;
if (i == 16)
return -EINVAL;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
st->mode &= ~AD7793_MODE_RATE(-1);
st->mode |= AD7793_MODE_RATE(i);
ad_sd_write_reg(&st->sd, AD7793_REG_MODE, sizeof(st->mode), st->mode);
iio_device_release_direct_mode(indio_dev);
return len;
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
}
scale_uv = (1170ULL * 1000000000ULL * 6ULL);
break;
case IIO_TEMP:
scale_uv = 1444444444444444ULL;
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
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
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
iio_device_release_direct_mode(indio_dev);
return ret;
}
static int ad7793_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
return IIO_VAL_INT_PLUS_NANO;
}
static int ad7793_probe(struct spi_device *spi)
{
const struct ad7793_platform_data *pdata = spi->dev.platform_data;
struct ad7793_state *st;
struct iio_dev *indio_dev;
int ret, vref_mv = 0;
if (!pdata) {
dev_err(&spi->dev, "no platform data?\n");
return -ENODEV;
}
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ?\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
ad_sd_init(&st->sd, indio_dev, spi, &ad7793_sigma_delta_info);
if (pdata->refsel != AD7793_REFSEL_INTERNAL) {
st->reg = devm_regulator_get(&spi->dev, "refin");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
vref_mv = regulator_get_voltage(st->reg);
if (vref_mv < 0) {
ret = vref_mv;
goto error_disable_reg;
}
vref_mv /= 1000;
} else {
vref_mv = 1170;
}
st->chip_info =
&ad7793_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
indio_dev->info = st->chip_info->iio_info;
ret = ad_sd_setup_buffer_and_trigger(indio_dev);
if (ret)
goto error_disable_reg;
ret = ad7793_setup(indio_dev, pdata, vref_mv);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
ad_sd_cleanup_buffer_and_trigger(indio_dev);
error_disable_reg:
if (pdata->refsel != AD7793_REFSEL_INTERNAL)
regulator_disable(st->reg);
return ret;
}
static int ad7793_remove(struct spi_device *spi)
{
const struct ad7793_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7793_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad_sd_cleanup_buffer_and_trigger(indio_dev);
if (pdata->refsel != AD7793_REFSEL_INTERNAL)
regulator_disable(st->reg);
return 0;
}
