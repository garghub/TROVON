static int adis16260_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16260_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16260_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16260_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16260_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 20,
}, {
.tx_buf = st->tx + 2,
.bits_per_word = 8,
.len = 2,
.delay_usecs = 20,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16260_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16260_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16260_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16260_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 30,
}, {
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
.delay_usecs = 30,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16260_READ_REG(lower_reg_address);
st->tx[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev,
"problem when reading 16 bit register 0x%02X",
lower_reg_address);
goto error_ret;
}
*val = (st->rx[0] << 8) | st->rx[1];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t adis16260_read_frequency_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16260_state *st = iio_priv(indio_dev);
if (spi_get_device_id(st->us)->driver_data)
return sprintf(buf, "%s\n", "0.129 ~ 256");
else
return sprintf(buf, "%s\n", "256 2048");
}
static ssize_t adis16260_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16260_state *st = iio_priv(indio_dev);
int ret, len = 0;
u16 t;
int sps;
ret = adis16260_spi_read_reg_16(indio_dev,
ADIS16260_SMPL_PRD,
&t);
if (ret)
return ret;
if (spi_get_device_id(st->us)->driver_data)
sps = (t & ADIS16260_SMPL_PRD_TIME_BASE) ? 8 : 256;
else
sps = (t & ADIS16260_SMPL_PRD_TIME_BASE) ? 66 : 2048;
sps /= (t & ADIS16260_SMPL_PRD_DIV_MASK) + 1;
len = sprintf(buf, "%d SPS\n", sps);
return len;
}
static ssize_t adis16260_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16260_state *st = iio_priv(indio_dev);
long val;
int ret;
u8 t;
ret = strict_strtol(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
if (spi_get_device_id(st->us)) {
t = (256 / val);
if (t > 0)
t--;
t &= ADIS16260_SMPL_PRD_DIV_MASK;
} else {
t = (2048 / val);
if (t > 0)
t--;
t &= ADIS16260_SMPL_PRD_DIV_MASK;
}
if ((t & ADIS16260_SMPL_PRD_DIV_MASK) >= 0x0A)
st->us->max_speed_hz = ADIS16260_SPI_SLOW;
else
st->us->max_speed_hz = ADIS16260_SPI_FAST;
ret = adis16260_spi_write_reg_8(indio_dev,
ADIS16260_SMPL_PRD,
t);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int adis16260_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16260_spi_write_reg_8(indio_dev,
ADIS16260_GLOB_CMD,
ADIS16260_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
static ssize_t adis16260_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
if (len < 1)
return -EINVAL;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return adis16260_reset(indio_dev);
}
return -EINVAL;
}
int adis16260_set_irq(struct iio_dev *indio_dev, bool enable)
{
int ret;
u16 msc;
ret = adis16260_spi_read_reg_16(indio_dev, ADIS16260_MSC_CTRL, &msc);
if (ret)
goto error_ret;
msc |= ADIS16260_MSC_CTRL_DATA_RDY_POL_HIGH;
if (enable)
msc |= ADIS16260_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS16260_MSC_CTRL_DATA_RDY_EN;
ret = adis16260_spi_write_reg_16(indio_dev, ADIS16260_MSC_CTRL, msc);
if (ret)
goto error_ret;
error_ret:
return ret;
}
static int adis16260_stop_device(struct iio_dev *indio_dev)
{
int ret;
u16 val = ADIS16260_SLP_CNT_POWER_OFF;
ret = adis16260_spi_write_reg_16(indio_dev, ADIS16260_SLP_CNT, val);
if (ret)
dev_err(&indio_dev->dev, "problem with turning device off: SLP_CNT");
return ret;
}
static int adis16260_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16260_spi_write_reg_16(indio_dev,
ADIS16260_MSC_CTRL,
ADIS16260_MSC_CTRL_MEM_TEST);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
adis16260_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16260_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16260_spi_read_reg_16(indio_dev,
ADIS16260_DIAG_STAT,
&status);
if (ret < 0) {
dev_err(dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x7F;
if (status & ADIS16260_DIAG_STAT_FLASH_CHK)
dev_err(dev, "Flash checksum error\n");
if (status & ADIS16260_DIAG_STAT_SELF_TEST)
dev_err(dev, "Self test error\n");
if (status & ADIS16260_DIAG_STAT_OVERFLOW)
dev_err(dev, "Sensor overrange\n");
if (status & ADIS16260_DIAG_STAT_SPI_FAIL)
dev_err(dev, "SPI failure\n");
if (status & ADIS16260_DIAG_STAT_FLASH_UPT)
dev_err(dev, "Flash update failed\n");
if (status & ADIS16260_DIAG_STAT_POWER_HIGH)
dev_err(dev, "Power supply above 5.25V\n");
if (status & ADIS16260_DIAG_STAT_POWER_LOW)
dev_err(dev, "Power supply below 4.75V\n");
error_ret:
return ret;
}
static int adis16260_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16260_set_irq(indio_dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ret = adis16260_self_test(indio_dev);
if (ret) {
dev_err(dev, "self test failure");
goto err_ret;
}
ret = adis16260_check_status(indio_dev);
if (ret) {
adis16260_reset(indio_dev);
dev_err(dev, "device not playing ball -> reset");
msleep(ADIS16260_STARTUP_DELAY);
ret = adis16260_check_status(indio_dev);
if (ret) {
dev_err(dev, "giving up");
goto err_ret;
}
}
err_ret:
return ret;
}
static int adis16260_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct adis16260_state *st = iio_priv(indio_dev);
int ret;
int bits;
u8 addr;
s16 val16;
switch (mask) {
case 0:
mutex_lock(&indio_dev->mlock);
addr = adis16260_addresses[chan->address][0];
ret = adis16260_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
if (val16 & ADIS16260_ERROR_ACTIVE) {
ret = adis16260_check_status(indio_dev);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
}
val16 = val16 & ((1 << chan->scan_type.realbits) - 1);
if (chan->scan_type.sign == 's')
val16 = (s16)(val16 <<
(16 - chan->scan_type.realbits)) >>
(16 - chan->scan_type.realbits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_SCALE_SEPARATE):
case (1 << IIO_CHAN_INFO_SCALE_SHARED):
switch (chan->type) {
case IIO_GYRO:
*val = 0;
if (spi_get_device_id(st->us)->driver_data)
*val2 = 320;
else
*val2 = 1278;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_IN:
*val = 0;
if (chan->channel == 0)
*val2 = 18315;
else
*val2 = 610500;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = 145300;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
break;
case (1 << IIO_CHAN_INFO_OFFSET_SEPARATE):
*val = 25;
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_CALIBBIAS_SEPARATE):
switch (chan->type) {
case IIO_GYRO:
bits = 12;
break;
default:
return -EINVAL;
};
mutex_lock(&indio_dev->mlock);
addr = adis16260_addresses[chan->address][1];
ret = adis16260_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_CALIBSCALE_SEPARATE):
switch (chan->type) {
case IIO_GYRO:
bits = 12;
break;
default:
return -EINVAL;
};
mutex_lock(&indio_dev->mlock);
addr = adis16260_addresses[chan->address][2];
ret = adis16260_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
*val = (1 << bits) - 1;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int adis16260_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int bits = 12;
s16 val16;
u8 addr;
switch (mask) {
case (1 << IIO_CHAN_INFO_CALIBBIAS_SEPARATE):
val16 = val & ((1 << bits) - 1);
addr = adis16260_addresses[chan->address][1];
return adis16260_spi_write_reg_16(indio_dev, addr, val16);
case (1 << IIO_CHAN_INFO_CALIBSCALE_SEPARATE):
val16 = val & ((1 << bits) - 1);
addr = adis16260_addresses[chan->address][2];
return adis16260_spi_write_reg_16(indio_dev, addr, val16);
}
return -EINVAL;
}
static int __devinit adis16260_probe(struct spi_device *spi)
{
int ret, regdone = 0;
struct adis16260_platform_data *pd = spi->dev.platform_data;
struct adis16260_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
if (pd)
st->negate = pd->negate;
spi_set_drvdata(spi, st);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi_get_device_id(st->us)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16260_info;
indio_dev->num_channels
= ARRAY_SIZE(adis16260_channels_x);
if (pd && pd->direction)
switch (pd->direction) {
case 'x':
indio_dev->channels = adis16260_channels_x;
break;
case 'y':
indio_dev->channels = adis16260_channels_y;
break;
case 'z':
indio_dev->channels = adis16260_channels_z;
break;
default:
return -EINVAL;
}
else
indio_dev->channels = adis16260_channels_x;
indio_dev->num_channels = ARRAY_SIZE(adis16260_channels_x);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis16260_configure_ring(indio_dev);
if (ret)
goto error_free_dev;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_ring_funcs;
regdone = 1;
ret = iio_ring_buffer_register_ex(indio_dev->ring, 0,
indio_dev->channels,
ARRAY_SIZE(adis16260_channels_x));
if (ret) {
printk(KERN_ERR "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
if (spi->irq) {
ret = adis16260_probe_trigger(indio_dev);
if (ret)
goto error_uninitialize_ring;
}
ret = adis16260_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
adis16260_remove_trigger(indio_dev);
error_uninitialize_ring:
iio_ring_buffer_unregister(indio_dev->ring);
error_unreg_ring_funcs:
adis16260_unconfigure_ring(indio_dev);
error_free_dev:
if (regdone)
iio_device_unregister(indio_dev);
else
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int adis16260_remove(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev = spi_get_drvdata(spi);
ret = adis16260_stop_device(indio_dev);
if (ret)
goto err_ret;
flush_scheduled_work();
adis16260_remove_trigger(indio_dev);
iio_ring_buffer_unregister(indio_dev->ring);
iio_device_unregister(indio_dev);
adis16260_unconfigure_ring(indio_dev);
err_ret:
return ret;
}
static __init int adis16260_init(void)
{
return spi_register_driver(&adis16260_driver);
}
static __exit void adis16260_exit(void)
{
spi_unregister_driver(&adis16260_driver);
}
