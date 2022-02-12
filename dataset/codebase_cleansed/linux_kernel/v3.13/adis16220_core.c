static ssize_t adis16220_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct adis16220_state *st = iio_priv(indio_dev);
ssize_t ret;
s16 val = 0;
mutex_lock(&indio_dev->mlock);
ret = adis_read_reg_16(&st->adis, this_attr->address,
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct adis16220_state *st = iio_priv(indio_dev);
int ret;
u16 val;
ret = kstrtou16(buf, 10, &val);
if (ret)
goto error_ret;
ret = adis_write_reg_16(&st->adis, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int adis16220_capture(struct iio_dev *indio_dev)
{
struct adis16220_state *st = iio_priv(indio_dev);
int ret;
ret = adis_write_reg_16(&st->adis, ADIS16220_GLOB_CMD, 0xBF08);
if (ret)
dev_err(&indio_dev->dev, "problem beginning capture");
msleep(10);
return ret;
}
static ssize_t adis16220_write_capture(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
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
static ssize_t adis16220_capture_buffer_read(struct iio_dev *indio_dev,
char *buf,
loff_t off,
size_t count,
int addr)
{
struct adis16220_state *st = iio_priv(indio_dev);
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
ret = adis_write_reg_16(&st->adis,
ADIS16220_CAPT_PNTR,
off > 1);
if (ret)
return -EIO;
mutex_lock(&st->buf_lock);
for (i = 0; i < count; i += 2) {
st->tx[i] = ADIS_READ_REG(addr);
st->tx[i + 1] = 0;
}
xfers[1].len = count;
ret = spi_sync_transfer(st->adis.spi, xfers, ARRAY_SIZE(xfers));
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
struct iio_dev *indio_dev = dev_to_iio_dev(kobj_to_dev(kobj));
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUFA);
}
static ssize_t adis16220_adc1_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off,
size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(kobj_to_dev(kobj));
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUF1);
}
static ssize_t adis16220_adc2_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off,
size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(kobj_to_dev(kobj));
return adis16220_capture_buffer_read(indio_dev, buf,
off, count,
ADIS16220_CAPT_BUF2);
}
static int adis16220_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct adis16220_state *st = iio_priv(indio_dev);
const struct adis16220_address_spec *addr;
int ret = -EINVAL;
int addrind = 0;
u16 uval;
s16 sval;
u8 bits;
switch (mask) {
case IIO_CHAN_INFO_RAW:
addrind = 0;
break;
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP) {
*val = 25000 / -470 - 1278;
return IIO_VAL_INT;
}
addrind = 1;
break;
case IIO_CHAN_INFO_PEAK:
addrind = 2;
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_TEMP:
*val = -470;
*val2 = 0;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val2 = IIO_G_TO_M_S_2(19073);
return IIO_VAL_INT_PLUS_MICRO;
case IIO_VOLTAGE:
if (chan->channel == 0) {
*val = 1;
*val2 = 220700;
} else {
*val2 = 305180;
}
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
addr = &adis16220_addresses[chan->address][addrind];
if (addr->sign) {
ret = adis_read_reg_16(&st->adis, addr->addr, &sval);
if (ret)
return ret;
bits = addr->bits;
sval &= (1 << bits) - 1;
sval = (s16)(sval << (16 - bits)) >> (16 - bits);
*val = sval;
return IIO_VAL_INT;
} else {
ret = adis_read_reg_16(&st->adis, addr->addr, &uval);
if (ret)
return ret;
bits = addr->bits;
uval &= (1 << bits) - 1;
*val = uval;
return IIO_VAL_INT;
}
}
static int adis16220_probe(struct spi_device *spi)
{
int ret;
struct adis16220_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16220_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = adis16220_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16220_channels);
ret = iio_device_register(indio_dev);
if (ret)
return ret;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &accel_bin);
if (ret)
goto error_unregister_dev;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &adc1_bin);
if (ret)
goto error_rm_accel_bin;
ret = sysfs_create_bin_file(&indio_dev->dev.kobj, &adc2_bin);
if (ret)
goto error_rm_adc1_bin;
ret = adis_init(&st->adis, indio_dev, spi, &adis16220_data);
if (ret)
goto error_rm_adc2_bin;
ret = adis_initial_startup(&st->adis);
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
return ret;
}
static int adis16220_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc2_bin);
sysfs_remove_bin_file(&indio_dev->dev.kobj, &adc1_bin);
sysfs_remove_bin_file(&indio_dev->dev.kobj, &accel_bin);
iio_device_unregister(indio_dev);
return 0;
}
