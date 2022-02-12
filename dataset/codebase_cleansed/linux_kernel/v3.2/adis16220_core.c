static int adis16220_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16220_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16220_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16220_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16220_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 35,
}, {
.tx_buf = st->tx + 2,
.bits_per_word = 8,
.len = 2,
.delay_usecs = 35,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16220_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16220_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16220_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16220_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 35,
}, {
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 35,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16220_READ_REG(lower_reg_address);
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
static ssize_t adis16220_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
ssize_t ret;
s16 val = 0;
mutex_lock(&indio_dev->mlock);
ret = adis16220_spi_read_reg_16(indio_dev, this_attr->address,
(u16 *)&val);
mutex_unlock(&indio_dev->mlock);
if (ret)
return ret;
return sprintf(buf, "%d\n", val);
}
static ssize_t adis16220_write_16bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = adis16220_spi_write_reg_16(indio_dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int adis16220_capture(struct iio_dev *indio_dev)
{
int ret;
ret = adis16220_spi_write_reg_16(indio_dev,
ADIS16220_GLOB_CMD,
0xBF08);
if (ret)
dev_err(&indio_dev->dev, "problem beginning capture");
msleep(10);
return ret;
}
static int adis16220_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16220_spi_write_reg_8(indio_dev,
ADIS16220_GLOB_CMD,
ADIS16220_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
static ssize_t adis16220_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
bool val;
int ret;
ret = strtobool(buf, &val);
if (ret)
return ret;
if (!val)
return -EINVAL;
ret = adis16220_reset(indio_dev);
if (ret)
return ret;
return len;
}
static ssize_t adis16220_write_capture(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
bool val;
int ret;
ret = strtobool(buf, &val);
if (ret)
return ret;
if (!val)
return -EINVAL;
ret = adis16220_capture(indio_dev);
if (ret)
return ret;
return len;
}
static int adis16220_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
ret = adis16220_spi_read_reg_16(indio_dev, ADIS16220_DIAG_STAT,
&status);
if (ret < 0) {
dev_err(&indio_dev->dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x7F;
if (status & ADIS16220_DIAG_STAT_VIOLATION)
dev_err(&indio_dev->dev,
"Capture period violation/interruption\n");
if (status & ADIS16220_DIAG_STAT_SPI_FAIL)
dev_err(&indio_dev->dev, "SPI failure\n");
if (status & ADIS16220_DIAG_STAT_FLASH_UPT)
dev_err(&indio_dev->dev, "Flash update failed\n");
if (status & ADIS16220_DIAG_STAT_POWER_HIGH)
dev_err(&indio_dev->dev, "Power supply above 3.625V\n");
if (status & ADIS16220_DIAG_STAT_POWER_LOW)
dev_err(&indio_dev->dev, "Power supply below 3.15V\n");
error_ret:
return ret;
}
static int adis16220_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16220_spi_write_reg_16(indio_dev,
ADIS16220_MSC_CTRL,
ADIS16220_MSC_CTRL_SELF_TEST_EN);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
adis16220_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16220_initial_setup(struct iio_dev *indio_dev)
{
int ret;
ret = adis16220_self_test(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "self test failure");
goto err_ret;
}
ret = adis16220_check_status(indio_dev);
if (ret) {
adis16220_reset(indio_dev);
dev_err(&indio_dev->dev, "device not playing ball -> reset");
msleep(ADIS16220_STARTUP_DELAY);
ret = adis16220_check_status(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "giving up");
goto err_ret;
}
}
err_ret:
return ret;
}
static ssize_t adis16220_capture_buffer_read(struct iio_dev *indio_dev,
char *buf,
loff_t off,
size_t count,
int addr)
{
struct adis16220_state *st = iio_priv(indio_dev);
struct spi_message msg;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 25,
}, {
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.cs_change = 1,
.delay_usecs = 25,
},
};
int ret;
int i;
if (unlikely(!count))
return count;
if ((off >= ADIS16220_CAPTURE_SIZE) || (count & 1) || (off & 1))
return -EINVAL;
if (off + count > ADIS16220_CAPTURE_SIZE)
count = ADIS16220_CAPTURE_SIZE - off;
ret = adis16220_spi_write_reg_16(indio_dev,
ADIS16220_CAPT_PNTR,
off > 1);
if (ret)
return -EIO;
mutex_lock(&st->buf_lock);
for (i = 0; i < count; i += 2) {
st->tx[i] = ADIS16220_READ_REG(addr);
st->tx[i + 1] = 0;
}
xfers[1].len = count;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
mutex_unlock(&st->buf_lock);
return -EIO;
}
memcpy(buf, st->rx, count);
mutex_unlock(&st->buf_lock);
return count;
}
static ssize_t adis16220_accel_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf,
loff_t off,
size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUFA);
}
static ssize_t adis16220_adc1_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUF1);
}
static ssize_t adis16220_adc2_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUF2);
}
static int adis16220_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
int ret = -EINVAL;
int addrind = 0;
u16 uval;
s16 sval;
u8 bits;
switch (mask) {
case 0:
addrind = 0;
break;
case (1 << IIO_CHAN_INFO_OFFSET_SEPARATE):
if (chan->type == IIO_TEMP) {
*val = 25;
return IIO_VAL_INT;
}
addrind = 1;
break;
case (1 << IIO_CHAN_INFO_PEAK_SEPARATE):
addrind = 2;
break;
case (1 << IIO_CHAN_INFO_SCALE_SEPARATE):
*val = 0;
switch (chan->type) {
case IIO_TEMP:
*val2 = -470000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val2 = 1887042;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_VOLTAGE:
if (chan->channel == 0)
*val2 = 0012221;
else
*val2 = 305;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
if (adis16220_addresses[chan->address][addrind].sign) {
ret = adis16220_spi_read_reg_16(indio_dev,
adis16220_addresses[chan
->address]
[addrind].addr,
&sval);
if (ret)
return ret;
bits = adis16220_addresses[chan->address][addrind].bits;
sval &= (1 << bits) - 1;
sval = (s16)(sval << (16 - bits)) >> (16 - bits);
*val = sval;
return IIO_VAL_INT;
} else {
ret = adis16220_spi_read_reg_16(indio_dev,
adis16220_addresses[chan
->address]
[addrind].addr,
&uval);
if (ret)
return ret;
bits = adis16220_addresses[chan->address][addrind].bits;
uval &= (1 << bits) - 1;
*val = uval;
return IIO_VAL_INT;
}
}
static int __devinit adis16220_probe(struct spi_device *spi)
{
int ret;
struct adis16220_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16220_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = adis16220_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16220_channels);
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &accel_bin);
if (ret)
goto error_unregister_dev;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &adc1_bin);
if (ret)
goto error_rm_accel_bin;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &adc2_bin);
if (ret)
goto error_rm_adc1_bin;
ret = adis16220_initial_setup(indio_dev);
if (ret)
goto error_rm_adc2_bin;
return 0;
error_rm_adc2_bin:
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc2_bin);
error_rm_adc1_bin:
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc1_bin);
error_rm_accel_bin:
sysfs_remove_bin_file(&indio_dev->dev.kobj, &accel_bin);
error_unregister_dev:
iio_device_unregister(indio_dev);
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int adis16220_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
flush_scheduled_work();
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc2_bin);
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc1_bin);
sysfs_remove_bin_file(&indio_dev->dev.kobj, &accel_bin);
iio_device_unregister(indio_dev);
iio_free_device(indio_dev);
return 0;
}
static __init int adis16220_init(void)
{
return spi_register_driver(&adis16220_driver);
}
static __exit void adis16220_exit(void)
{
spi_unregister_driver(&adis16220_driver);
}
