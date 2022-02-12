static inline void start_sample(struct ad2s1210_state *st)
{
gpio_set_value(st->sample, 0);
}
static inline void stop_sample(struct ad2s1210_state *st)
{
gpio_set_value(st->sample, 1);
}
static inline void set_mode(enum ad2s1210_mode mode, struct ad2s1210_state *st)
{
switch (mode) {
case MOD_POS:
gpio_set_value(st->a0, 0);
gpio_set_value(st->a1, 0);
break;
case MOD_VEL:
gpio_set_value(st->a0, 0);
gpio_set_value(st->a1, 1);
break;
case MOD_CONFIG:
gpio_set_value(st->a0, 1);
gpio_set_value(st->a1, 1);
break;
default:
gpio_set_value(st->a0, 1);
gpio_set_value(st->a1, 0);
}
st->mode = mode;
}
static int config_write(struct ad2s1210_state *st,
unsigned char data)
{
struct spi_message msg;
int ret = 0;
st->xfer.len = 1;
set_mode(MOD_CONFIG, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
st->tx[0] = data;
ret = spi_sync(st->sdev, &msg);
if (ret)
return ret;
st->old_data = 1;
return ret;
}
static int config_read(struct ad2s1210_state *st,
unsigned char address,
unsigned char *data)
{
struct spi_message msg;
int ret = 0;
st->xfer.len = 2;
set_mode(MOD_CONFIG, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
st->tx[0] = address | MSB_IS_HIGH;
st->tx[1] = REG_FAULT;
ret = spi_sync(st->sdev, &msg);
if (ret)
return ret;
*data = st->rx[1];
st->old_data = 1;
return ret;
}
static inline void update_frequency_control_word(struct ad2s1210_state *st)
{
unsigned char fcw;
fcw = (unsigned char)(st->fexcit * (1 << 15) / st->fclkin);
if (fcw >= AD2S1210_MIN_FCW && fcw <= AD2S1210_MAX_FCW) {
config_write(st, REG_EXCIT_FREQ);
config_write(st, fcw);
} else
pr_err("ad2s1210: FCW out of range\n");
}
static inline unsigned char read_resolution_pin(struct ad2s1210_state *st)
{
unsigned int data;
data = (gpio_get_value(st->res0) << 1) |
gpio_get_value(st->res1);
return resolution_value[data];
}
static inline void set_resolution_pin(struct ad2s1210_state *st)
{
switch (st->resolution) {
case RES_10:
gpio_set_value(st->res0, 0);
gpio_set_value(st->res1, 0);
break;
case RES_12:
gpio_set_value(st->res0, 0);
gpio_set_value(st->res1, 1);
break;
case RES_14:
gpio_set_value(st->res0, 1);
gpio_set_value(st->res1, 0);
break;
case RES_16:
gpio_set_value(st->res0, 1);
gpio_set_value(st->res1, 1);
break;
}
}
static inline void soft_reset(struct ad2s1210_state *st)
{
config_write(st, REG_SOFT_RESET);
config_write(st, 0x0);
}
static ssize_t ad2s1210_show_raw(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
int ret;
mutex_lock(&st->lock);
if (st->old_data) {
ret = sprintf(buf, "0x%x\n", st->rx[0]);
st->old_data = 0;
} else
ret = 0;
mutex_unlock(&st->lock);
return ret;
}
static ssize_t ad2s1210_store_raw(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned long udata;
unsigned char data;
int ret;
ret = strict_strtoul(buf, 16, &udata);
if (ret)
return -EINVAL;
data = udata & 0xff;
mutex_lock(&st->lock);
config_write(st, data);
mutex_unlock(&st->lock);
return 1;
}
static ssize_t ad2s1210_store_softreset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
mutex_lock(&st->lock);
soft_reset(st);
mutex_unlock(&st->lock);
return len;
}
static ssize_t ad2s1210_show_fclkin(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
return sprintf(buf, "%d\n", st->fclkin);
}
static ssize_t ad2s1210_store_fclkin(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned long fclkin;
int ret;
ret = strict_strtoul(buf, 10, &fclkin);
if (!ret && fclkin >= AD2S1210_MIN_CLKIN &&
fclkin <= AD2S1210_MAX_CLKIN) {
mutex_lock(&st->lock);
st->fclkin = fclkin;
} else {
pr_err("ad2s1210: fclkin out of range\n");
return -EINVAL;
}
update_frequency_control_word(st);
soft_reset(st);
mutex_unlock(&st->lock);
return len;
}
static ssize_t ad2s1210_show_fexcit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
return sprintf(buf, "%d\n", st->fexcit);
}
static ssize_t ad2s1210_store_fexcit(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned long fexcit;
int ret;
ret = strict_strtoul(buf, 10, &fexcit);
if (!ret && fexcit >= AD2S1210_MIN_EXCIT &&
fexcit <= AD2S1210_MAX_EXCIT) {
mutex_lock(&st->lock);
st->fexcit = fexcit;
} else {
pr_err("ad2s1210: excitation frequency out of range\n");
return -EINVAL;
}
update_frequency_control_word(st);
soft_reset(st);
mutex_unlock(&st->lock);
return len;
}
static ssize_t ad2s1210_show_control(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned char data;
mutex_lock(&st->lock);
config_read(st, REG_CONTROL, &data);
mutex_unlock(&st->lock);
return sprintf(buf, "0x%x\n", data);
}
static ssize_t ad2s1210_store_control(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned long udata;
unsigned char data;
int ret;
ret = strict_strtoul(buf, 16, &udata);
if (ret) {
ret = -EINVAL;
goto error_ret;
}
mutex_lock(&st->lock);
config_write(st, REG_CONTROL);
data = udata & MSB_IS_LOW;
config_write(st, data);
config_read(st, REG_CONTROL, &data);
if (data & MSB_IS_HIGH) {
ret = -EIO;
pr_err("ad2s1210: write control register fail\n");
goto error_ret;
}
st->resolution = resolution_value[data & SET_RESOLUTION];
#if defined(CONFIG_AD2S1210_GPIO_INPUT)
data = read_resolution_pin(st);
if (data != st->resolution)
pr_warning("ad2s1210: resolution settings not match\n");
#elif defined(CONFIG_AD2S1210_GPIO_OUTPUT)
set_resolution_pin(st);
#endif
ret = len;
if (data & ENABLE_HYSTERESIS)
st->hysteresis = 1;
else
st->hysteresis = 0;
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t ad2s1210_show_resolution(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
return sprintf(buf, "%d\n", st->resolution);
}
static ssize_t ad2s1210_store_resolution(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned char data;
unsigned long udata;
int ret;
ret = strict_strtoul(buf, 10, &udata);
if (ret || udata < RES_10 || udata > RES_16) {
pr_err("ad2s1210: resolution out of range\n");
return -EINVAL;
}
mutex_lock(&st->lock);
config_read(st, REG_CONTROL, &data);
data &= ~SET_RESOLUTION;
data |= (udata - RES_10) >> 1;
config_write(st, REG_CONTROL);
config_write(st, data & MSB_IS_LOW);
config_read(st, REG_CONTROL, &data);
if (data & MSB_IS_HIGH) {
ret = -EIO;
pr_err("ad2s1210: setting resolution fail\n");
goto error_ret;
}
st->resolution = resolution_value[data & SET_RESOLUTION];
#if defined(CONFIG_AD2S1210_GPIO_INPUT)
data = read_resolution_pin(st);
if (data != st->resolution)
pr_warning("ad2s1210: resolution settings not match\n");
#elif defined(CONFIG_AD2S1210_GPIO_OUTPUT)
set_resolution_pin(st);
#endif
ret = len;
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static ssize_t ad2s1210_show_fault(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret = 0;
ssize_t len = 0;
unsigned char data;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
mutex_lock(&st->lock);
ret = config_read(st, REG_FAULT, &data);
if (ret)
goto error_ret;
len = sprintf(buf, "0x%x\n", data);
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t ad2s1210_clear_fault(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned char data;
mutex_lock(&st->lock);
start_sample(st);
udelay(1);
stop_sample(st);
config_read(st, REG_FAULT, &data);
start_sample(st);
stop_sample(st);
mutex_unlock(&st->lock);
return 0;
}
static ssize_t ad2s1210_show_reg(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned char data;
struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
mutex_lock(&st->lock);
config_read(st, iattr->address, &data);
mutex_unlock(&st->lock);
return sprintf(buf, "%d\n", data);
}
static ssize_t ad2s1210_store_reg(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
unsigned long data;
int ret;
struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
ret = strict_strtoul(buf, 10, &data);
if (ret)
return -EINVAL;
mutex_lock(&st->lock);
config_write(st, iattr->address);
config_write(st, data & MSB_IS_LOW);
mutex_unlock(&st->lock);
return len;
}
static ssize_t ad2s1210_show_pos(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct spi_message msg;
int ret = 0;
ssize_t len = 0;
u16 pos;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
st->xfer.len = 2;
mutex_lock(&st->lock);
start_sample(st);
udelay(1);
set_mode(MOD_POS, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
pos = ((((u16)(st->rx[0])) << 8) | (st->rx[1]));
if (st->hysteresis)
pos >>= 16 - st->resolution;
len = sprintf(buf, "%d\n", pos);
error_ret:
stop_sample(st);
udelay(1);
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t ad2s1210_show_vel(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct spi_message msg;
unsigned short negative;
int ret = 0;
ssize_t len = 0;
s16 vel;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
st->xfer.len = 2;
mutex_lock(&st->lock);
start_sample(st);
udelay(1);
set_mode(MOD_VEL, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
negative = st->rx[0] & 0x80;
vel = ((((s16)(st->rx[0])) << 8) | (st->rx[1]));
vel >>= 16 - st->resolution;
if (negative) {
negative = (0xffff >> st->resolution) << st->resolution;
vel |= negative;
}
len = sprintf(buf, "%d\n", vel);
error_ret:
stop_sample(st);
udelay(1);
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t ad2s1210_show_pos_vel(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct spi_message msg;
unsigned short negative;
int ret = 0;
ssize_t len = 0;
u16 pos;
s16 vel;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s1210_state *st = idev->dev_data;
st->xfer.len = 2;
mutex_lock(&st->lock);
start_sample(st);
udelay(1);
set_mode(MOD_POS, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
pos = ((((u16)(st->rx[0])) << 8) | (st->rx[1]));
if (st->hysteresis)
pos >>= 16 - st->resolution;
len = sprintf(buf, "%d ", pos);
st->xfer.len = 2;
set_mode(MOD_VEL, st);
spi_message_init(&msg);
spi_message_add_tail(&st->xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
negative = st->rx[0] & 0x80;
vel = ((((s16)(st->rx[0])) << 8) | (st->rx[1]));
vel >>= 16 - st->resolution;
if (negative) {
negative = (0xffff >> st->resolution) << st->resolution;
vel |= negative;
}
len += sprintf(buf + len, "%d\n", vel);
error_ret:
stop_sample(st);
udelay(1);
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int __devinit ad2s1210_initial(struct ad2s1210_state *st)
{
unsigned char data;
int ret;
mutex_lock(&st->lock);
#if defined(CONFIG_AD2S1210_GPIO_INPUT)
st->resolution = read_resolution_pin(st);
#elif defined(CONFIG_AD2S1210_GPIO_OUTPUT)
set_resolution_pin(st);
#endif
config_write(st, REG_CONTROL);
data = DEF_CONTROL & ~(SET_RESOLUTION);
data |= (st->resolution - RES_10) >> 1;
config_write(st, data);
ret = config_read(st, REG_CONTROL, &data);
if (ret)
goto error_ret;
if (data & MSB_IS_HIGH) {
ret = -EIO;
goto error_ret;
}
update_frequency_control_word(st);
soft_reset(st);
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int __devinit ad2s1210_probe(struct spi_device *spi)
{
struct ad2s1210_state *st;
int pn, ret = 0;
unsigned short *pins = spi->dev.platform_data;
for (pn = 0; pn < AD2S1210_PN; pn++) {
if (gpio_request(pins[pn], DRV_NAME)) {
pr_err("%s: request gpio pin %d failed\n",
DRV_NAME, pins[pn]);
goto error_ret;
}
if (pn < AD2S1210_SAA)
gpio_direction_output(pins[pn], 1);
else {
#if defined(CONFIG_AD2S1210_GPIO_INPUT)
gpio_direction_input(pins[pn]);
#elif defined(CONFIG_AD2S1210_GPIO_OUTPUT)
gpio_direction_output(pins[pn], 1);
#endif
}
}
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
mutex_init(&st->lock);
st->sdev = spi;
st->xfer.tx_buf = st->tx;
st->xfer.rx_buf = st->rx;
st->hysteresis = 1;
st->mode = MOD_CONFIG;
st->resolution = RES_12;
st->fclkin = AD2S1210_DEF_CLKIN;
st->fexcit = AD2S1210_DEF_EXCIT;
st->sample = pins[0];
st->a0 = pins[1];
st->a1 = pins[2];
st->res0 = pins[3];
st->res1 = pins[4];
st->idev = iio_allocate_device(0);
if (st->idev == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->idev->dev.parent = &spi->dev;
st->idev->info = &ad2s1210_info;
st->idev->dev_data = (void *)(st);
st->idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
if (spi->max_speed_hz != AD2S1210_DEF_CLKIN)
st->fclkin = spi->max_speed_hz;
spi->mode = SPI_MODE_3;
spi_setup(spi);
ad2s1210_initial(st);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_free_st:
kfree(st);
error_ret:
for (--pn; pn >= 0; pn--)
gpio_free(pins[pn]);
return ret;
}
static int __devexit ad2s1210_remove(struct spi_device *spi)
{
struct ad2s1210_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->idev);
kfree(st);
return 0;
}
static __init int ad2s1210_spi_init(void)
{
return spi_register_driver(&ad2s1210_driver);
}
static __exit void ad2s1210_spi_exit(void)
{
spi_unregister_driver(&ad2s1210_driver);
}
