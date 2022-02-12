static inline void ad2s1210_set_mode(enum ad2s1210_mode mode,
struct ad2s1210_state *st)
{
gpio_set_value(st->pdata->a[0], ad2s1210_mode_vals[mode][0]);
gpio_set_value(st->pdata->a[1], ad2s1210_mode_vals[mode][1]);
st->mode = mode;
}
static int ad2s1210_config_write(struct ad2s1210_state *st, u8 data)
{
int ret;
ad2s1210_set_mode(MOD_CONFIG, st);
st->tx[0] = data;
ret = spi_write(st->sdev, st->tx, 1);
if (ret < 0)
return ret;
st->old_data = true;
return 0;
}
static int ad2s1210_config_read(struct ad2s1210_state *st,
unsigned char address)
{
struct spi_transfer xfer = {
.len = 2,
.rx_buf = st->rx,
.tx_buf = st->tx,
};
struct spi_message msg;
int ret = 0;
ad2s1210_set_mode(MOD_CONFIG, st);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
st->tx[0] = address | AD2S1210_MSB_IS_HIGH;
st->tx[1] = AD2S1210_REG_FAULT;
ret = spi_sync(st->sdev, &msg);
if (ret < 0)
return ret;
st->old_data = true;
return st->rx[1];
}
static inline
int ad2s1210_update_frequency_control_word(struct ad2s1210_state *st)
{
int ret;
unsigned char fcw;
fcw = (unsigned char)(st->fexcit * (1 << 15) / st->fclkin);
if (fcw < AD2S1210_MIN_FCW || fcw > AD2S1210_MAX_FCW) {
pr_err("ad2s1210: FCW out of range\n");
return -ERANGE;
}
ret = ad2s1210_config_write(st, AD2S1210_REG_EXCIT_FREQ);
if (ret < 0)
return ret;
return ad2s1210_config_write(st, fcw);
}
static unsigned char ad2s1210_read_resolution_pin(struct ad2s1210_state *st)
{
return ad2s1210_resolution_value[
(gpio_get_value(st->pdata->res[0]) << 1) |
gpio_get_value(st->pdata->res[1])];
}
static inline void ad2s1210_set_resolution_pin(struct ad2s1210_state *st)
{
gpio_set_value(st->pdata->res[0],
ad2s1210_res_pins[(st->resolution - 10)/2][0]);
gpio_set_value(st->pdata->res[1],
ad2s1210_res_pins[(st->resolution - 10)/2][1]);
}
static inline int ad2s1210_soft_reset(struct ad2s1210_state *st)
{
int ret;
ret = ad2s1210_config_write(st, AD2S1210_REG_SOFT_RESET);
if (ret < 0)
return ret;
return ad2s1210_config_write(st, 0x0);
}
static ssize_t ad2s1210_store_softreset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
int ret;
mutex_lock(&st->lock);
ret = ad2s1210_soft_reset(st);
mutex_unlock(&st->lock);
return ret < 0 ? ret : len;
}
static ssize_t ad2s1210_show_fclkin(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", st->fclkin);
}
static ssize_t ad2s1210_store_fclkin(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned long fclkin;
int ret;
ret = strict_strtoul(buf, 10, &fclkin);
if (ret)
return ret;
if (fclkin < AD2S1210_MIN_CLKIN || fclkin > AD2S1210_MAX_CLKIN) {
pr_err("ad2s1210: fclkin out of range\n");
return -EINVAL;
}
mutex_lock(&st->lock);
st->fclkin = fclkin;
ret = ad2s1210_update_frequency_control_word(st);
if (ret < 0)
goto error_ret;
ret = ad2s1210_soft_reset(st);
error_ret:
mutex_unlock(&st->lock);
return ret < 0 ? ret : len;
}
static ssize_t ad2s1210_show_fexcit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", st->fexcit);
}
static ssize_t ad2s1210_store_fexcit(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned long fexcit;
int ret;
ret = strict_strtoul(buf, 10, &fexcit);
if (ret < 0)
return ret;
if (fexcit < AD2S1210_MIN_EXCIT || fexcit > AD2S1210_MAX_EXCIT) {
pr_err("ad2s1210: excitation frequency out of range\n");
return -EINVAL;
}
mutex_lock(&st->lock);
st->fexcit = fexcit;
ret = ad2s1210_update_frequency_control_word(st);
if (ret < 0)
goto error_ret;
ret = ad2s1210_soft_reset(st);
error_ret:
mutex_unlock(&st->lock);
return ret < 0 ? ret : len;
}
static ssize_t ad2s1210_show_control(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
int ret;
mutex_lock(&st->lock);
ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
mutex_unlock(&st->lock);
return ret < 0 ? ret : sprintf(buf, "0x%x\n", ret);
}
static ssize_t ad2s1210_store_control(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned long udata;
unsigned char data;
int ret;
ret = strict_strtoul(buf, 16, &udata);
if (ret)
return -EINVAL;
mutex_lock(&st->lock);
ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
data = udata & AD2S1210_MSB_IS_LOW;
ret = ad2s1210_config_write(st, data);
if (ret < 0)
goto error_ret;
ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
if (ret & AD2S1210_MSB_IS_HIGH) {
ret = -EIO;
pr_err("ad2s1210: write control register fail\n");
goto error_ret;
}
st->resolution
= ad2s1210_resolution_value[data & AD2S1210_SET_RESOLUTION];
if (st->pdata->gpioin) {
data = ad2s1210_read_resolution_pin(st);
if (data != st->resolution)
pr_warning("ad2s1210: resolution settings not match\n");
} else
ad2s1210_set_resolution_pin(st);
ret = len;
st->hysteresis = !!(data & AD2S1210_ENABLE_HYSTERESIS);
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t ad2s1210_show_resolution(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", st->resolution);
}
static ssize_t ad2s1210_store_resolution(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned char data;
unsigned long udata;
int ret;
ret = strict_strtoul(buf, 10, &udata);
if (ret || udata < 10 || udata > 16) {
pr_err("ad2s1210: resolution out of range\n");
return -EINVAL;
}
mutex_lock(&st->lock);
ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
data = ret;
data &= ~AD2S1210_SET_RESOLUTION;
data |= (udata - 10) >> 1;
ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
ret = ad2s1210_config_write(st, data & AD2S1210_MSB_IS_LOW);
if (ret < 0)
goto error_ret;
ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
data = ret;
if (data & AD2S1210_MSB_IS_HIGH) {
ret = -EIO;
pr_err("ad2s1210: setting resolution fail\n");
goto error_ret;
}
st->resolution
= ad2s1210_resolution_value[data & AD2S1210_SET_RESOLUTION];
if (st->pdata->gpioin) {
data = ad2s1210_read_resolution_pin(st);
if (data != st->resolution)
pr_warning("ad2s1210: resolution settings not match\n");
} else
ad2s1210_set_resolution_pin(st);
ret = len;
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t ad2s1210_show_fault(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
int ret;
mutex_lock(&st->lock);
ret = ad2s1210_config_read(st, AD2S1210_REG_FAULT);
mutex_unlock(&st->lock);
return ret ? ret : sprintf(buf, "0x%x\n", ret);
}
static ssize_t ad2s1210_clear_fault(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
int ret;
mutex_lock(&st->lock);
gpio_set_value(st->pdata->sample, 0);
udelay(1);
gpio_set_value(st->pdata->sample, 1);
ret = ad2s1210_config_read(st, AD2S1210_REG_FAULT);
if (ret < 0)
goto error_ret;
gpio_set_value(st->pdata->sample, 0);
gpio_set_value(st->pdata->sample, 1);
error_ret:
mutex_unlock(&st->lock);
return ret < 0 ? ret : len;
}
static ssize_t ad2s1210_show_reg(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
int ret;
mutex_lock(&st->lock);
ret = ad2s1210_config_read(st, iattr->address);
mutex_unlock(&st->lock);
return ret < 0 ? ret : sprintf(buf, "%d\n", ret);
}
static ssize_t ad2s1210_store_reg(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned long data;
int ret;
struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
ret = strict_strtoul(buf, 10, &data);
if (ret)
return -EINVAL;
mutex_lock(&st->lock);
ret = ad2s1210_config_write(st, iattr->address);
if (ret < 0)
goto error_ret;
ret = ad2s1210_config_write(st, data & AD2S1210_MSB_IS_LOW);
error_ret:
mutex_unlock(&st->lock);
return ret < 0 ? ret : len;
}
static int ad2s1210_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad2s1210_state *st = iio_priv(indio_dev);
bool negative;
int ret = 0;
u16 pos;
s16 vel;
mutex_lock(&st->lock);
gpio_set_value(st->pdata->sample, 0);
udelay(1);
switch (chan->type) {
case IIO_ANGL:
ad2s1210_set_mode(MOD_POS, st);
break;
case IIO_ANGL_VEL:
ad2s1210_set_mode(MOD_VEL, st);
break;
default:
ret = -EINVAL;
break;
}
if (ret < 0)
goto error_ret;
ret = spi_read(st->sdev, st->rx, 2);
if (ret < 0)
goto error_ret;
switch (chan->type) {
case IIO_ANGL:
pos = be16_to_cpup((u16 *)st->rx);
if (st->hysteresis)
pos >>= 16 - st->resolution;
*val = pos;
ret = IIO_VAL_INT;
break;
case IIO_ANGL_VEL:
negative = st->rx[0] & 0x80;
vel = be16_to_cpup((s16 *)st->rx);
vel >>= 16 - st->resolution;
if (vel & 0x8000) {
negative = (0xffff >> st->resolution) << st->resolution;
vel |= negative;
}
*val = vel;
ret = IIO_VAL_INT;
break;
default:
mutex_unlock(&st->lock);
return -EINVAL;
}
error_ret:
gpio_set_value(st->pdata->sample, 1);
udelay(1);
mutex_unlock(&st->lock);
return ret;
}
static int __devinit ad2s1210_initial(struct ad2s1210_state *st)
{
unsigned char data;
int ret;
mutex_lock(&st->lock);
if (st->pdata->gpioin)
st->resolution = ad2s1210_read_resolution_pin(st);
else
ad2s1210_set_resolution_pin(st);
ret = ad2s1210_config_write(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
data = AD2S1210_DEF_CONTROL & ~(AD2S1210_SET_RESOLUTION);
data |= (st->resolution - 10) >> 1;
ret = ad2s1210_config_write(st, data);
if (ret < 0)
goto error_ret;
ret = ad2s1210_config_read(st, AD2S1210_REG_CONTROL);
if (ret < 0)
goto error_ret;
if (ret & AD2S1210_MSB_IS_HIGH) {
ret = -EIO;
goto error_ret;
}
ret = ad2s1210_update_frequency_control_word(st);
if (ret < 0)
goto error_ret;
ret = ad2s1210_soft_reset(st);
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int ad2s1210_setup_gpios(struct ad2s1210_state *st)
{
unsigned long flags = st->pdata->gpioin ? GPIOF_DIR_IN : GPIOF_DIR_OUT;
struct gpio ad2s1210_gpios[] = {
{ st->pdata->sample, GPIOF_DIR_IN, "sample" },
{ st->pdata->a[0], flags, "a0" },
{ st->pdata->a[1], flags, "a1" },
{ st->pdata->res[0], flags, "res0" },
{ st->pdata->res[0], flags, "res1" },
};
return gpio_request_array(ad2s1210_gpios, ARRAY_SIZE(ad2s1210_gpios));
}
static void ad2s1210_free_gpios(struct ad2s1210_state *st)
{
unsigned long flags = st->pdata->gpioin ? GPIOF_DIR_IN : GPIOF_DIR_OUT;
struct gpio ad2s1210_gpios[] = {
{ st->pdata->sample, GPIOF_DIR_IN, "sample" },
{ st->pdata->a[0], flags, "a0" },
{ st->pdata->a[1], flags, "a1" },
{ st->pdata->res[0], flags, "res0" },
{ st->pdata->res[0], flags, "res1" },
};
gpio_free_array(ad2s1210_gpios, ARRAY_SIZE(ad2s1210_gpios));
}
static int __devinit ad2s1210_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct ad2s1210_state *st;
int ret;
if (spi->dev.platform_data == NULL)
return -EINVAL;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
st->pdata = spi->dev.platform_data;
ret = ad2s1210_setup_gpios(st);
if (ret < 0)
goto error_free_dev;
spi_set_drvdata(spi, indio_dev);
mutex_init(&st->lock);
st->sdev = spi;
st->hysteresis = true;
st->mode = MOD_CONFIG;
st->resolution = 12;
st->fexcit = AD2S1210_DEF_EXCIT;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad2s1210_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad2s1210_channels;
indio_dev->num_channels = ARRAY_SIZE(ad2s1210_channels);
indio_dev->name = spi_get_device_id(spi)->name;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_gpios;
st->fclkin = spi->max_speed_hz;
spi->mode = SPI_MODE_3;
spi_setup(spi);
ad2s1210_initial(st);
return 0;
error_free_gpios:
ad2s1210_free_gpios(st);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int __devexit ad2s1210_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
ad2s1210_free_gpios(iio_priv(indio_dev));
iio_device_free(indio_dev);
return 0;
}
