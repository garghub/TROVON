static int adis16203_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16203_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16203_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16203_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16203_state *st = iio_priv(indio_dev);
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
st->tx[0] = ADIS16203_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16203_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16203_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16203_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = 20,
}, {
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
.delay_usecs = 20,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16203_READ_REG(lower_reg_address);
st->tx[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev, "problem when reading 16 bit register 0x%02X",
lower_reg_address);
goto error_ret;
}
*val = (st->rx[0] << 8) | st->rx[1];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16203_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
ret = adis16203_spi_read_reg_16(indio_dev,
ADIS16203_DIAG_STAT,
&status);
if (ret < 0) {
dev_err(&indio_dev->dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x1F;
if (status & ADIS16203_DIAG_STAT_SELFTEST_FAIL)
dev_err(&indio_dev->dev, "Self test failure\n");
if (status & ADIS16203_DIAG_STAT_SPI_FAIL)
dev_err(&indio_dev->dev, "SPI failure\n");
if (status & ADIS16203_DIAG_STAT_FLASH_UPT)
dev_err(&indio_dev->dev, "Flash update failed\n");
if (status & ADIS16203_DIAG_STAT_POWER_HIGH)
dev_err(&indio_dev->dev, "Power supply above 3.625V\n");
if (status & ADIS16203_DIAG_STAT_POWER_LOW)
dev_err(&indio_dev->dev, "Power supply below 3.15V\n");
error_ret:
return ret;
}
static int adis16203_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16203_spi_write_reg_8(indio_dev,
ADIS16203_GLOB_CMD,
ADIS16203_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
static ssize_t adis16203_write_reset(struct device *dev,
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
return adis16203_reset(indio_dev);
}
return -EINVAL;
}
int adis16203_set_irq(struct iio_dev *indio_dev, bool enable)
{
int ret = 0;
u16 msc;
ret = adis16203_spi_read_reg_16(indio_dev, ADIS16203_MSC_CTRL, &msc);
if (ret)
goto error_ret;
msc |= ADIS16203_MSC_CTRL_ACTIVE_HIGH;
msc &= ~ADIS16203_MSC_CTRL_DATA_RDY_DIO1;
if (enable)
msc |= ADIS16203_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS16203_MSC_CTRL_DATA_RDY_EN;
ret = adis16203_spi_write_reg_16(indio_dev, ADIS16203_MSC_CTRL, msc);
error_ret:
return ret;
}
static int adis16203_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16203_spi_write_reg_16(indio_dev,
ADIS16203_MSC_CTRL,
ADIS16203_MSC_CTRL_SELF_TEST_EN);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
adis16203_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16203_initial_setup(struct iio_dev *indio_dev)
{
int ret;
ret = adis16203_set_irq(indio_dev, false);
if (ret) {
dev_err(&indio_dev->dev, "disable irq failed");
goto err_ret;
}
ret = adis16203_self_test(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "self test failure");
goto err_ret;
}
ret = adis16203_check_status(indio_dev);
if (ret) {
adis16203_reset(indio_dev);
dev_err(&indio_dev->dev, "device not playing ball -> reset");
msleep(ADIS16203_STARTUP_DELAY);
ret = adis16203_check_status(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "giving up");
goto err_ret;
}
}
err_ret:
return ret;
}
static int adis16203_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
u8 addr = adis16203_addresses[chan->address][1];
return adis16203_spi_write_reg_16(indio_dev, addr, val & 0x3FFF);
}
static int adis16203_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
int ret;
int bits;
u8 addr;
s16 val16;
switch (mask) {
case 0:
mutex_lock(&indio_dev->mlock);
addr = adis16203_addresses[chan->address][0];
ret = adis16203_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
if (val16 & ADIS16203_ERROR_ACTIVE) {
ret = adis16203_check_status(indio_dev);
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
case IIO_VOLTAGE:
*val = 0;
if (chan->channel == 0)
*val2 = 1220;
else
*val2 = 610;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = -470000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_INCLI:
*val = 0;
*val2 = 25000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case (1 << IIO_CHAN_INFO_OFFSET_SEPARATE):
*val = 25;
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_CALIBBIAS_SEPARATE):
bits = 14;
mutex_lock(&indio_dev->mlock);
addr = adis16203_addresses[chan->address][1];
ret = adis16203_spi_read_reg_16(indio_dev, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int __devinit adis16203_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev;
struct adis16203_state *st;
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
indio_dev->channels = adis16203_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16203_channels);
indio_dev->info = &adis16203_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis16203_configure_ring(indio_dev);
if (ret)
goto error_free_dev;
ret = iio_buffer_register(indio_dev,
adis16203_channels,
ARRAY_SIZE(adis16203_channels));
if (ret) {
printk(KERN_ERR "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
if (spi->irq) {
ret = adis16203_probe_trigger(indio_dev);
if (ret)
goto error_uninitialize_ring;
}
ret = adis16203_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
adis16203_remove_trigger(indio_dev);
error_uninitialize_ring:
iio_buffer_unregister(indio_dev);
error_unreg_ring_funcs:
adis16203_unconfigure_ring(indio_dev);
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int adis16203_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
adis16203_remove_trigger(indio_dev);
iio_buffer_unregister(indio_dev);
adis16203_unconfigure_ring(indio_dev);
iio_free_device(indio_dev);
return 0;
}
static __init int adis16203_init(void)
{
return spi_register_driver(&adis16203_driver);
}
static __exit void adis16203_exit(void)
{
spi_unregister_driver(&adis16203_driver);
}
