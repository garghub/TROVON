static int adis16220_spi_write_reg_8(struct device *dev,
u8 reg_address,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16220_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16220_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16220_spi_write_reg_16(struct device *dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
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
.cs_change = 1,
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
static int adis16220_spi_read_reg_16(struct device *dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
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
static ssize_t adis16220_spi_read_signed(struct device *dev,
struct device_attribute *attr,
char *buf,
unsigned bits)
{
int ret;
s16 val = 0;
unsigned shift = 16 - bits;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = adis16220_spi_read_reg_16(dev, this_attr->address, (u16 *)&val);
if (ret)
return ret;
val = ((s16)(val << shift) >> shift);
return sprintf(buf, "%d\n", val);
}
static ssize_t adis16220_read_12bit_unsigned(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = adis16220_spi_read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val & 0x0FFF);
}
static ssize_t adis16220_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
ssize_t ret;
mutex_lock(&indio_dev->mlock);
ret = adis16220_spi_read_signed(dev, attr, buf, 16);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static ssize_t adis16220_write_16bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = adis16220_spi_write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int adis16220_capture(struct device *dev)
{
int ret;
ret = adis16220_spi_write_reg_16(dev,
ADIS16220_GLOB_CMD,
0xBF08);
if (ret)
dev_err(dev, "problem beginning capture");
msleep(10);
return ret;
}
static int adis16220_reset(struct device *dev)
{
int ret;
ret = adis16220_spi_write_reg_8(dev,
ADIS16220_GLOB_CMD,
ADIS16220_GLOB_CMD_SW_RESET);
if (ret)
dev_err(dev, "problem resetting device");
return ret;
}
static ssize_t adis16220_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return adis16220_reset(dev) == 0 ? len : -EIO;
}
return -1;
}
static ssize_t adis16220_write_capture(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return adis16220_capture(dev) == 0 ? len : -EIO;
}
return -1;
}
static int adis16220_check_status(struct device *dev)
{
u16 status;
int ret;
ret = adis16220_spi_read_reg_16(dev, ADIS16220_DIAG_STAT, &status);
if (ret < 0) {
dev_err(dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x7F;
if (status & ADIS16220_DIAG_STAT_VIOLATION)
dev_err(dev, "Capture period violation/interruption\n");
if (status & ADIS16220_DIAG_STAT_SPI_FAIL)
dev_err(dev, "SPI failure\n");
if (status & ADIS16220_DIAG_STAT_FLASH_UPT)
dev_err(dev, "Flash update failed\n");
if (status & ADIS16220_DIAG_STAT_POWER_HIGH)
dev_err(dev, "Power supply above 3.625V\n");
if (status & ADIS16220_DIAG_STAT_POWER_LOW)
dev_err(dev, "Power supply below 3.15V\n");
error_ret:
return ret;
}
static int adis16220_self_test(struct device *dev)
{
int ret;
ret = adis16220_spi_write_reg_16(dev,
ADIS16220_MSC_CTRL,
ADIS16220_MSC_CTRL_SELF_TEST_EN);
if (ret) {
dev_err(dev, "problem starting self test");
goto err_ret;
}
adis16220_check_status(dev);
err_ret:
return ret;
}
static int adis16220_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16220_self_test(dev);
if (ret) {
dev_err(dev, "self test failure");
goto err_ret;
}
ret = adis16220_check_status(dev);
if (ret) {
adis16220_reset(dev);
dev_err(dev, "device not playing ball -> reset");
msleep(ADIS16220_STARTUP_DELAY);
ret = adis16220_check_status(dev);
if (ret) {
dev_err(dev, "giving up");
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
ret = adis16220_spi_write_reg_16(&indio_dev->dev,
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
static int __devinit adis16220_probe(struct spi_device *spi)
{
int ret, regdone = 0;
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
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
regdone = 1;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &accel_bin);
if (ret)
goto error_free_dev;
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
error_free_dev:
if (regdone)
iio_device_unregister(indio_dev);
else
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
