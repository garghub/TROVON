static int adis16400_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16400_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16400_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16400_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16400_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
}, {
.tx_buf = st->tx + 2,
.bits_per_word = 8,
.len = 2,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16400_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16400_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16400_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16400_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
}, {
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16400_READ_REG(lower_reg_address);
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
static int adis16400_get_freq(struct iio_dev *indio_dev)
{
u16 t;
int sps, ret;
ret = adis16400_spi_read_reg_16(indio_dev, ADIS16400_SMPL_PRD, &t);
if (ret < 0)
return ret;
sps = (t & ADIS16400_SMPL_PRD_TIME_BASE) ? 53 : 1638;
sps /= (t & ADIS16400_SMPL_PRD_DIV_MASK) + 1;
return sps;
}
static ssize_t adis16400_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
int ret, len = 0;
ret = adis16400_get_freq(indio_dev);
if (ret < 0)
return ret;
len = sprintf(buf, "%d SPS\n", ret);
return len;
}
static int adis16400_set_filter(struct iio_dev *indio_dev, int sps, int val)
{
int i, ret;
u16 val16;
for (i = ARRAY_SIZE(adis16400_3db_divisors) - 1; i >= 0; i--)
if (sps/adis16400_3db_divisors[i] > val)
break;
if (i == -1)
ret = -EINVAL;
else {
ret = adis16400_spi_read_reg_16(indio_dev,
ADIS16400_SENS_AVG,
&val16);
if (ret < 0)
goto error_ret;
ret = adis16400_spi_write_reg_16(indio_dev,
ADIS16400_SENS_AVG,
(val16 & ~0x03) | i);
}
error_ret:
return ret;
}
static ssize_t adis16400_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct adis16400_state *st = iio_priv(indio_dev);
long val;
int ret;
u8 t;
ret = strict_strtol(buf, 10, &val);
if (ret)
return ret;
if (val == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
t = (1638 / val);
if (t > 0)
t--;
t &= ADIS16400_SMPL_PRD_DIV_MASK;
if ((t & ADIS16400_SMPL_PRD_DIV_MASK) >= 0x0A)
st->us->max_speed_hz = ADIS16400_SPI_SLOW;
else
st->us->max_speed_hz = ADIS16400_SPI_FAST;
ret = adis16400_spi_write_reg_8(indio_dev,
ADIS16400_SMPL_PRD,
t);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int adis16400_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16400_spi_write_reg_8(indio_dev,
ADIS16400_GLOB_CMD,
ADIS16400_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
int adis16400_set_irq(struct iio_dev *indio_dev, bool enable)
{
int ret;
u16 msc;
ret = adis16400_spi_read_reg_16(indio_dev, ADIS16400_MSC_CTRL, &msc);
if (ret)
goto error_ret;
msc |= ADIS16400_MSC_CTRL_DATA_RDY_POL_HIGH;
if (enable)
msc |= ADIS16400_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS16400_MSC_CTRL_DATA_RDY_EN;
ret = adis16400_spi_write_reg_16(indio_dev, ADIS16400_MSC_CTRL, msc);
if (ret)
goto error_ret;
error_ret:
return ret;
}
static int adis16400_stop_device(struct iio_dev *indio_dev)
{
int ret;
u16 val = ADIS16400_SLP_CNT_POWER_OFF;
ret = adis16400_spi_write_reg_16(indio_dev, ADIS16400_SLP_CNT, val);
if (ret)
dev_err(&indio_dev->dev,
"problem with turning device off: SLP_CNT");
return ret;
}
static int adis16400_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16400_spi_read_reg_16(indio_dev,
ADIS16400_DIAG_STAT, &status);
if (ret < 0) {
dev_err(dev, "Reading status failed\n");
goto error_ret;
}
ret = status;
if (status & ADIS16400_DIAG_STAT_ZACCL_FAIL)
dev_err(dev, "Z-axis accelerometer self-test failure\n");
if (status & ADIS16400_DIAG_STAT_YACCL_FAIL)
dev_err(dev, "Y-axis accelerometer self-test failure\n");
if (status & ADIS16400_DIAG_STAT_XACCL_FAIL)
dev_err(dev, "X-axis accelerometer self-test failure\n");
if (status & ADIS16400_DIAG_STAT_XGYRO_FAIL)
dev_err(dev, "X-axis gyroscope self-test failure\n");
if (status & ADIS16400_DIAG_STAT_YGYRO_FAIL)
dev_err(dev, "Y-axis gyroscope self-test failure\n");
if (status & ADIS16400_DIAG_STAT_ZGYRO_FAIL)
dev_err(dev, "Z-axis gyroscope self-test failure\n");
if (status & ADIS16400_DIAG_STAT_ALARM2)
dev_err(dev, "Alarm 2 active\n");
if (status & ADIS16400_DIAG_STAT_ALARM1)
dev_err(dev, "Alarm 1 active\n");
if (status & ADIS16400_DIAG_STAT_FLASH_CHK)
dev_err(dev, "Flash checksum error\n");
if (status & ADIS16400_DIAG_STAT_SELF_TEST)
dev_err(dev, "Self test error\n");
if (status & ADIS16400_DIAG_STAT_OVERFLOW)
dev_err(dev, "Sensor overrange\n");
if (status & ADIS16400_DIAG_STAT_SPI_FAIL)
dev_err(dev, "SPI failure\n");
if (status & ADIS16400_DIAG_STAT_FLASH_UPT)
dev_err(dev, "Flash update failed\n");
if (status & ADIS16400_DIAG_STAT_POWER_HIGH)
dev_err(dev, "Power supply above 5.25V\n");
if (status & ADIS16400_DIAG_STAT_POWER_LOW)
dev_err(dev, "Power supply below 4.75V\n");
error_ret:
return ret;
}
static int adis16400_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16400_spi_write_reg_16(indio_dev,
ADIS16400_MSC_CTRL,
ADIS16400_MSC_CTRL_MEM_TEST);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
msleep(ADIS16400_MTEST_DELAY);
adis16400_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16400_initial_setup(struct iio_dev *indio_dev)
{
int ret;
u16 prod_id, smp_prd;
struct adis16400_state *st = iio_priv(indio_dev);
st->us->max_speed_hz = ADIS16400_SPI_SLOW;
st->us->mode = SPI_MODE_3;
spi_setup(st->us);
ret = adis16400_set_irq(indio_dev, false);
if (ret) {
dev_err(&indio_dev->dev, "disable irq failed");
goto err_ret;
}
ret = adis16400_self_test(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "self test failure");
goto err_ret;
}
ret = adis16400_check_status(indio_dev);
if (ret) {
adis16400_reset(indio_dev);
dev_err(&indio_dev->dev, "device not playing ball -> reset");
msleep(ADIS16400_STARTUP_DELAY);
ret = adis16400_check_status(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "giving up");
goto err_ret;
}
}
if (st->variant->flags & ADIS16400_HAS_PROD_ID) {
ret = adis16400_spi_read_reg_16(indio_dev,
ADIS16400_PRODUCT_ID, &prod_id);
if (ret)
goto err_ret;
if ((prod_id & 0xF000) != st->variant->product_id)
dev_warn(&indio_dev->dev, "incorrect id");
dev_info(&indio_dev->dev, "%s: prod_id 0x%04x at CS%d (irq %d)\n",
indio_dev->name, prod_id,
st->us->chip_select, st->us->irq);
}
ret = adis16400_spi_read_reg_16(indio_dev,
ADIS16400_SMPL_PRD, &smp_prd);
if (!ret && (smp_prd & ADIS16400_SMPL_PRD_DIV_MASK) < 0x0A) {
st->us->max_speed_hz = ADIS16400_SPI_SLOW;
spi_setup(st->us);
}
err_ret:
return ret;
}
static int adis16400_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct adis16400_state *st = iio_priv(indio_dev);
int ret, sps;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
mutex_lock(&indio_dev->mlock);
ret = adis16400_spi_write_reg_16(indio_dev,
adis16400_addresses[chan->address][1],
val);
mutex_unlock(&indio_dev->mlock);
return ret;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
mutex_lock(&indio_dev->mlock);
st->filt_int = val;
sps = adis16400_get_freq(indio_dev);
if (sps < 0) {
mutex_unlock(&indio_dev->mlock);
return sps;
}
ret = adis16400_set_filter(indio_dev, sps, val);
mutex_unlock(&indio_dev->mlock);
return ret;
default:
return -EINVAL;
}
}
static int adis16400_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct adis16400_state *st = iio_priv(indio_dev);
int ret, shift;
s16 val16;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = adis16400_spi_read_reg_16(indio_dev,
adis16400_addresses[chan->address][0],
&val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << chan->scan_type.realbits) - 1;
if (chan->scan_type.sign == 's') {
shift = 16 - chan->scan_type.realbits;
val16 = (s16)(val16 << shift) >> shift;
}
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = 0;
*val2 = st->variant->gyro_scale_micro;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_VOLTAGE:
*val = 0;
if (chan->channel == 0)
*val2 = 2418;
else
*val2 = 806;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val = 0;
*val2 = st->variant->accel_scale_micro;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_MAGN:
*val = 0;
*val2 = 500;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = 140000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_CALIBBIAS:
mutex_lock(&indio_dev->mlock);
ret = adis16400_spi_read_reg_16(indio_dev,
adis16400_addresses[chan->address][1],
&val16);
mutex_unlock(&indio_dev->mlock);
if (ret)
return ret;
val16 = ((val16 & 0xFFF) << 4) >> 4;
*val = val16;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
*val = 198;
*val2 = 160000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
mutex_lock(&indio_dev->mlock);
ret = adis16400_spi_read_reg_16(indio_dev,
ADIS16400_SENS_AVG,
&val16);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
ret = adis16400_get_freq(indio_dev);
if (ret > 0)
*val = ret/adis16400_3db_divisors[val16 & 0x03];
*val2 = 0;
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int __devinit adis16400_probe(struct spi_device *spi)
{
int ret;
struct adis16400_state *st;
struct iio_dev *indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
st->variant = &adis16400_chips[spi_get_device_id(spi)->driver_data];
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->channels = st->variant->channels;
indio_dev->num_channels = st->variant->num_channels;
indio_dev->info = &adis16400_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis16400_configure_ring(indio_dev);
if (ret)
goto error_free_dev;
ret = iio_buffer_register(indio_dev,
st->variant->channels,
st->variant->num_channels);
if (ret) {
dev_err(&spi->dev, "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
if (spi->irq) {
ret = adis16400_probe_trigger(indio_dev);
if (ret)
goto error_uninitialize_ring;
}
ret = adis16400_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
if (spi->irq)
adis16400_remove_trigger(indio_dev);
error_uninitialize_ring:
iio_buffer_unregister(indio_dev);
error_unreg_ring_funcs:
adis16400_unconfigure_ring(indio_dev);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int adis16400_remove(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
ret = adis16400_stop_device(indio_dev);
if (ret)
goto err_ret;
adis16400_remove_trigger(indio_dev);
iio_buffer_unregister(indio_dev);
adis16400_unconfigure_ring(indio_dev);
iio_device_free(indio_dev);
return 0;
err_ret:
return ret;
}
