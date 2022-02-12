static struct ad7192_state *ad_sigma_delta_to_ad7192(struct ad_sigma_delta *sd)
{
return container_of(sd, struct ad7192_state, sd);
}
static int ad7192_set_channel(struct ad_sigma_delta *sd, unsigned int channel)
{
struct ad7192_state *st = ad_sigma_delta_to_ad7192(sd);
st->conf &= ~AD7192_CONF_CHAN_MASK;
st->conf |= AD7192_CONF_CHAN(channel);
return ad_sd_write_reg(&st->sd, AD7192_REG_CONF, 3, st->conf);
}
static int ad7192_set_mode(struct ad_sigma_delta *sd,
enum ad_sigma_delta_mode mode)
{
struct ad7192_state *st = ad_sigma_delta_to_ad7192(sd);
st->mode &= ~AD7192_MODE_SEL_MASK;
st->mode |= AD7192_MODE_SEL(mode);
return ad_sd_write_reg(&st->sd, AD7192_REG_MODE, 3, st->mode);
}
static int ad7192_calibrate_all(struct ad7192_state *st)
{
return ad_sd_calibrate_all(&st->sd, ad7192_calib_arr,
ARRAY_SIZE(ad7192_calib_arr));
}
static int ad7192_setup(struct ad7192_state *st,
const struct ad7192_platform_data *pdata)
{
struct iio_dev *indio_dev = spi_get_drvdata(st->sd.spi);
unsigned long long scale_uv;
int i, ret, id;
u8 ones[6];
memset(&ones, 0xFF, 6);
ret = spi_write(st->sd.spi, &ones, 6);
if (ret < 0)
goto out;
usleep_range(500, 1000);
ret = ad_sd_read_reg(&st->sd, AD7192_REG_ID, 1, &id);
if (ret)
goto out;
id &= AD7192_ID_MASK;
if (id != st->devid)
dev_warn(&st->sd.spi->dev, "device ID query failed (0x%X)\n",
id);
switch (pdata->clock_source_sel) {
case AD7192_CLK_EXT_MCLK1_2:
case AD7192_CLK_EXT_MCLK2:
st->mclk = AD7192_INT_FREQ_MHZ;
break;
case AD7192_CLK_INT:
case AD7192_CLK_INT_CO:
if (pdata->ext_clk_hz)
st->mclk = pdata->ext_clk_hz;
else
st->mclk = AD7192_INT_FREQ_MHZ;
break;
default:
ret = -EINVAL;
goto out;
}
st->mode = AD7192_MODE_SEL(AD7192_MODE_IDLE) |
AD7192_MODE_CLKSRC(pdata->clock_source_sel) |
AD7192_MODE_RATE(480);
st->conf = AD7192_CONF_GAIN(0);
if (pdata->rej60_en)
st->mode |= AD7192_MODE_REJ60;
if (pdata->sinc3_en)
st->mode |= AD7192_MODE_SINC3;
if (pdata->refin2_en && (st->devid != ID_AD7195))
st->conf |= AD7192_CONF_REFSEL;
if (pdata->chop_en) {
st->conf |= AD7192_CONF_CHOP;
if (pdata->sinc3_en)
st->f_order = 3;
else
st->f_order = 4;
} else {
st->f_order = 1;
}
if (pdata->buf_en)
st->conf |= AD7192_CONF_BUF;
if (pdata->unipolar_en)
st->conf |= AD7192_CONF_UNIPOLAR;
if (pdata->burnout_curr_en)
st->conf |= AD7192_CONF_BURN;
ret = ad_sd_write_reg(&st->sd, AD7192_REG_MODE, 3, st->mode);
if (ret)
goto out;
ret = ad_sd_write_reg(&st->sd, AD7192_REG_CONF, 3, st->conf);
if (ret)
goto out;
ret = ad7192_calibrate_all(st);
if (ret)
goto out;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++) {
scale_uv = ((u64)st->int_vref_mv * 100000000)
>> (indio_dev->channels[0].scan_type.realbits -
((st->conf & AD7192_CONF_UNIPOLAR) ? 0 : 1));
scale_uv >>= i;
st->scale_avail[i][1] = do_div(scale_uv, 100000000) * 10;
st->scale_avail[i][0] = scale_uv;
}
return 0;
out:
dev_err(&st->sd.spi->dev, "setup failed\n");
return ret;
}
static ssize_t ad7192_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->mclk /
(st->f_order * 1024 * AD7192_MODE_RATE(st->mode)));
}
static ssize_t ad7192_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
unsigned long lval;
int div, ret;
ret = kstrtoul(buf, 10, &lval);
if (ret)
return ret;
if (lval == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
div = st->mclk / (lval * st->f_order * 1024);
if (div < 1 || div > 1023) {
ret = -EINVAL;
goto out;
}
st->mode &= ~AD7192_MODE_RATE(-1);
st->mode |= AD7192_MODE_RATE(div);
ad_sd_write_reg(&st->sd, AD7192_REG_MODE, 3, st->mode);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t
ad7192_show_scale_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(st->scale_avail); i++)
len += sprintf(buf + len, "%d.%09u ", st->scale_avail[i][0],
st->scale_avail[i][1]);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t ad7192_show_ac_excitation(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", !!(st->mode & AD7192_MODE_ACX));
}
static ssize_t ad7192_show_bridge_switch(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", !!(st->gpocon & AD7192_GPOCON_BPDSW));
}
static ssize_t ad7192_set(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7192_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
bool val;
ret = strtobool(buf, &val);
if (ret < 0)
return ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
switch ((u32)this_attr->address) {
case AD7192_REG_GPOCON:
if (val)
st->gpocon |= AD7192_GPOCON_BPDSW;
else
st->gpocon &= ~AD7192_GPOCON_BPDSW;
ad_sd_write_reg(&st->sd, AD7192_REG_GPOCON, 1, st->gpocon);
break;
case AD7192_REG_MODE:
if (val)
st->mode |= AD7192_MODE_ACX;
else
st->mode &= ~AD7192_MODE_ACX;
ad_sd_write_reg(&st->sd, AD7192_REG_MODE, 3, st->mode);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static unsigned int ad7192_get_temp_scale(bool unipolar)
{
return unipolar ? 2815 * 2 : 2815;
}
static int ad7192_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad7192_state *st = iio_priv(indio_dev);
bool unipolar = !!(st->conf & AD7192_CONF_UNIPOLAR);
switch (m) {
case IIO_CHAN_INFO_RAW:
return ad_sigma_delta_single_conversion(indio_dev, chan, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
mutex_lock(&indio_dev->mlock);
*val = st->scale_avail[AD7192_CONF_GAIN(st->conf)][0];
*val2 = st->scale_avail[AD7192_CONF_GAIN(st->conf)][1];
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT_PLUS_NANO;
case IIO_TEMP:
*val = 0;
*val2 = 1000000000 / ad7192_get_temp_scale(unipolar);
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (!unipolar)
*val = -(1 << (chan->scan_type.realbits - 1));
else
*val = 0;
if (chan->type == IIO_TEMP)
*val -= 273 * ad7192_get_temp_scale(unipolar);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad7192_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad7192_state *st = iio_priv(indio_dev);
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
st->conf &= ~AD7192_CONF_GAIN(-1);
st->conf |= AD7192_CONF_GAIN(i);
if (tmp == st->conf)
break;
ad_sd_write_reg(&st->sd, AD7192_REG_CONF,
3, st->conf);
ad7192_calibrate_all(st);
break;
}
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7192_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
return IIO_VAL_INT_PLUS_NANO;
}
static int ad7192_probe(struct spi_device *spi)
{
const struct ad7192_platform_data *pdata = dev_get_platdata(&spi->dev);
struct ad7192_state *st;
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
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = devm_regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
return ret;
voltage_uv = regulator_get_voltage(st->reg);
}
if (pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage undefined\n");
spi_set_drvdata(spi, indio_dev);
st->devid = spi_get_device_id(spi)->driver_data;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad7192_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7192_channels);
if (st->devid == ID_AD7195)
indio_dev->info = &ad7195_info;
else
indio_dev->info = &ad7192_info;
ad_sd_init(&st->sd, indio_dev, spi, &ad7192_sigma_delta_info);
ret = ad_sd_setup_buffer_and_trigger(indio_dev);
if (ret)
goto error_disable_reg;
ret = ad7192_setup(st, pdata);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto error_remove_trigger;
return 0;
error_remove_trigger:
ad_sd_cleanup_buffer_and_trigger(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return ret;
}
static int ad7192_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7192_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad_sd_cleanup_buffer_and_trigger(indio_dev);
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return 0;
}
