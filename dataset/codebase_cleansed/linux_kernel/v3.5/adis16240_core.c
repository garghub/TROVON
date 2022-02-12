static int adis16240_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16240_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16240_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16240_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16240_state *st = iio_priv(indio_dev);
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
st->tx[0] = ADIS16240_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16240_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16240_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16240_state *st = iio_priv(indio_dev);
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
st->tx[0] = ADIS16240_READ_REG(lower_reg_address);
st->tx[1] = 0;
st->tx[2] = 0;
st->tx[3] = 0;
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
static ssize_t adis16240_spi_read_signed(struct device *dev,
struct device_attribute *attr,
char *buf,
unsigned bits)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
int ret;
s16 val = 0;
unsigned shift = 16 - bits;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = adis16240_spi_read_reg_16(indio_dev,
this_attr->address, (u16 *)&val);
if (ret)
return ret;
if (val & ADIS16240_ERROR_ACTIVE)
adis16240_check_status(indio_dev);
val = ((s16)(val << shift) >> shift);
return sprintf(buf, "%d\n", val);
}
static ssize_t adis16240_read_12bit_signed(struct device *dev,
struct device_attribute *attr,
char *buf)
{
ssize_t ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
mutex_lock(&indio_dev->mlock);
ret = adis16240_spi_read_signed(dev, attr, buf, 12);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int adis16240_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16240_spi_write_reg_8(indio_dev,
ADIS16240_GLOB_CMD,
ADIS16240_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
static ssize_t adis16240_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
if (len < 1)
return -EINVAL;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return adis16240_reset(indio_dev);
}
return -EINVAL;
}
int adis16240_set_irq(struct iio_dev *indio_dev, bool enable)
{
int ret = 0;
u16 msc;
ret = adis16240_spi_read_reg_16(indio_dev,
ADIS16240_MSC_CTRL, &msc);
if (ret)
goto error_ret;
msc |= ADIS16240_MSC_CTRL_ACTIVE_HIGH;
msc &= ~ADIS16240_MSC_CTRL_DATA_RDY_DIO2;
if (enable)
msc |= ADIS16240_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS16240_MSC_CTRL_DATA_RDY_EN;
ret = adis16240_spi_write_reg_16(indio_dev,
ADIS16240_MSC_CTRL, msc);
error_ret:
return ret;
}
static int adis16240_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16240_spi_write_reg_16(indio_dev,
ADIS16240_MSC_CTRL,
ADIS16240_MSC_CTRL_SELF_TEST_EN);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
msleep(ADIS16240_STARTUP_DELAY);
adis16240_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16240_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16240_spi_read_reg_16(indio_dev,
ADIS16240_DIAG_STAT, &status);
if (ret < 0) {
dev_err(dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x2F;
if (status & ADIS16240_DIAG_STAT_PWRON_FAIL)
dev_err(dev, "Power-on, self-test fail\n");
if (status & ADIS16240_DIAG_STAT_SPI_FAIL)
dev_err(dev, "SPI failure\n");
if (status & ADIS16240_DIAG_STAT_FLASH_UPT)
dev_err(dev, "Flash update failed\n");
if (status & ADIS16240_DIAG_STAT_POWER_HIGH)
dev_err(dev, "Power supply above 3.625V\n");
if (status & ADIS16240_DIAG_STAT_POWER_LOW)
dev_err(dev, "Power supply below 2.225V\n");
error_ret:
return ret;
}
static int adis16240_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct device *dev = &indio_dev->dev;
ret = adis16240_set_irq(indio_dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ret = adis16240_self_test(indio_dev);
if (ret) {
dev_err(dev, "self test failure");
goto err_ret;
}
ret = adis16240_check_status(indio_dev);
if (ret) {
adis16240_reset(indio_dev);
dev_err(dev, "device not playing ball -> reset");
msleep(ADIS16240_STARTUP_DELAY);
ret = adis16240_check_status(indio_dev);
if (ret) {
dev_err(dev, "giving up");
goto err_ret;
}
}
err_ret:
return ret;
}
static int adis16240_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
int ret;
int bits;
u8 addr;
s16 val16;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
addr = adis16240_addresses[chan->address][0];
ret = adis16240_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
if (val16 & ADIS16240_ERROR_ACTIVE) {
ret = adis16240_check_status(indio_dev);
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
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
*val = 0;
if (chan->channel == 0)
*val2 = 4880;
else
return -EINVAL;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = 244000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val = 0;
*val2 = 504062;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_PEAK_SCALE:
*val = 6;
*val2 = 629295;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
*val = 25;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
bits = 10;
mutex_lock(&indio_dev->mlock);
addr = adis16240_addresses[chan->address][1];
ret = adis16240_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_PEAK:
bits = 10;
mutex_lock(&indio_dev->mlock);
addr = adis16240_addresses[chan->address][2];
ret = adis16240_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int adis16240_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int bits = 10;
s16 val16;
u8 addr;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
val16 = val & ((1 << bits) - 1);
addr = adis16240_addresses[chan->address][1];
return adis16240_spi_write_reg_16(indio_dev, addr, val16);
}
return -EINVAL;
}
static int __devinit adis16240_probe(struct spi_device *spi)
{
int ret;
struct adis16240_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_device_alloc(sizeof(*st));
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
indio_dev->info = &adis16240_info;
indio_dev->channels = adis16240_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16240_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis16240_configure_ring(indio_dev);
if (ret)
goto error_free_dev;
ret = iio_buffer_register(indio_dev,
adis16240_channels,
ARRAY_SIZE(adis16240_channels));
if (ret) {
printk(KERN_ERR "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
if (spi->irq) {
ret = adis16240_probe_trigger(indio_dev);
if (ret)
goto error_uninitialize_ring;
}
ret = adis16240_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
adis16240_remove_trigger(indio_dev);
error_uninitialize_ring:
iio_buffer_unregister(indio_dev);
error_unreg_ring_funcs:
adis16240_unconfigure_ring(indio_dev);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int adis16240_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
flush_scheduled_work();
iio_device_unregister(indio_dev);
adis16240_remove_trigger(indio_dev);
iio_buffer_unregister(indio_dev);
adis16240_unconfigure_ring(indio_dev);
iio_device_free(indio_dev);
return 0;
}
