static int adis16204_spi_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address,
u8 val)
{
int ret;
struct adis16204_state *st = iio_dev_get_devdata(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16204_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16204_spi_write_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct adis16204_state *st = iio_dev_get_devdata(indio_dev);
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
.cs_change = 1,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADIS16204_WRITE_REG(lower_reg_address);
st->tx[1] = value & 0xFF;
st->tx[2] = ADIS16204_WRITE_REG(lower_reg_address + 1);
st->tx[3] = (value >> 8) & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16204_spi_read_reg_16(struct iio_dev *indio_dev,
u8 lower_reg_address,
u16 *val)
{
struct spi_message msg;
struct adis16204_state *st = iio_dev_get_devdata(indio_dev);
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
st->tx[0] = ADIS16204_READ_REG(lower_reg_address);
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
static int adis16204_check_status(struct iio_dev *indio_dev)
{
u16 status;
int ret;
ret = adis16204_spi_read_reg_16(indio_dev,
ADIS16204_DIAG_STAT, &status);
if (ret < 0) {
dev_err(&indio_dev->dev, "Reading status failed\n");
goto error_ret;
}
ret = status & 0x1F;
if (status & ADIS16204_DIAG_STAT_SELFTEST_FAIL)
dev_err(&indio_dev->dev, "Self test failure\n");
if (status & ADIS16204_DIAG_STAT_SPI_FAIL)
dev_err(&indio_dev->dev, "SPI failure\n");
if (status & ADIS16204_DIAG_STAT_FLASH_UPT)
dev_err(&indio_dev->dev, "Flash update failed\n");
if (status & ADIS16204_DIAG_STAT_POWER_HIGH)
dev_err(&indio_dev->dev, "Power supply above 3.625V\n");
if (status & ADIS16204_DIAG_STAT_POWER_LOW)
dev_err(&indio_dev->dev, "Power supply below 2.975V\n");
error_ret:
return ret;
}
static ssize_t adis16204_read_14bit_signed(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
s16 val = 0;
ssize_t ret;
mutex_lock(&indio_dev->mlock);
ret = adis16204_spi_read_reg_16(indio_dev,
this_attr->address, (u16 *)&val);
if (!ret) {
if (val & ADIS16204_ERROR_ACTIVE)
adis16204_check_status(indio_dev);
val = ((s16)(val << 2) >> 2);
ret = sprintf(buf, "%d\n", val);
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int adis16204_reset(struct iio_dev *indio_dev)
{
int ret;
ret = adis16204_spi_write_reg_8(indio_dev,
ADIS16204_GLOB_CMD,
ADIS16204_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&indio_dev->dev, "problem resetting device");
return ret;
}
static ssize_t adis16204_write_reset(struct device *dev,
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
return adis16204_reset(indio_dev);
}
return -EINVAL;
}
int adis16204_set_irq(struct iio_dev *indio_dev, bool enable)
{
int ret = 0;
u16 msc;
ret = adis16204_spi_read_reg_16(indio_dev, ADIS16204_MSC_CTRL, &msc);
if (ret)
goto error_ret;
msc |= ADIS16204_MSC_CTRL_ACTIVE_HIGH;
msc &= ~ADIS16204_MSC_CTRL_DATA_RDY_DIO2;
if (enable)
msc |= ADIS16204_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS16204_MSC_CTRL_DATA_RDY_EN;
ret = adis16204_spi_write_reg_16(indio_dev, ADIS16204_MSC_CTRL, msc);
error_ret:
return ret;
}
static int adis16204_self_test(struct iio_dev *indio_dev)
{
int ret;
ret = adis16204_spi_write_reg_16(indio_dev,
ADIS16204_MSC_CTRL,
ADIS16204_MSC_CTRL_SELF_TEST_EN);
if (ret) {
dev_err(&indio_dev->dev, "problem starting self test");
goto err_ret;
}
adis16204_check_status(indio_dev);
err_ret:
return ret;
}
static int adis16204_initial_setup(struct iio_dev *indio_dev)
{
int ret;
ret = adis16204_set_irq(indio_dev, false);
if (ret) {
dev_err(&indio_dev->dev, "disable irq failed");
goto err_ret;
}
ret = adis16204_self_test(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "self test failure");
goto err_ret;
}
ret = adis16204_check_status(indio_dev);
if (ret) {
adis16204_reset(indio_dev);
dev_err(&indio_dev->dev, "device not playing ball -> reset");
msleep(ADIS16204_STARTUP_DELAY);
ret = adis16204_check_status(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "giving up");
goto err_ret;
}
}
err_ret:
return ret;
}
static int adis16204_read_raw(struct iio_dev *indio_dev,
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
addr = adis16204_addresses[chan->address][0];
ret = adis16204_spi_read_reg_16(indio_dev, addr, &val16);
if (ret)
return ret;
if (val16 & ADIS16204_ERROR_ACTIVE) {
ret = adis16204_check_status(indio_dev);
if (ret)
return ret;
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
switch (chan->type) {
case IIO_IN:
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
case IIO_ACCEL:
*val = 0;
if (chan->channel == 'x')
*val2 = 17125;
else
*val2 = 8407;
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
case IIO_ACCEL:
bits = 12;
break;
default:
return -EINVAL;
};
mutex_lock(&indio_dev->mlock);
addr = adis16204_addresses[chan->address][1];
ret = adis16204_spi_read_reg_16(indio_dev, addr, &val16);
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
static int adis16204_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int bits;
s16 val16;
u8 addr;
switch (mask) {
case (1 << IIO_CHAN_INFO_CALIBBIAS_SEPARATE):
switch (chan->type) {
case IIO_ACCEL:
bits = 12;
break;
default:
return -EINVAL;
};
val16 = val & ((1 << bits) - 1);
addr = adis16204_addresses[chan->address][1];
return adis16204_spi_write_reg_16(indio_dev, addr, val16);
}
return -EINVAL;
}
static int __devinit adis16204_probe(struct spi_device *spi)
{
int ret, regdone = 0;
struct adis16204_state *st = kzalloc(sizeof *st, GFP_KERNEL);
if (!st) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
st->rx = kzalloc(sizeof(*st->rx)*ADIS16204_MAX_RX, GFP_KERNEL);
if (st->rx == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->tx = kzalloc(sizeof(*st->tx)*ADIS16204_MAX_TX, GFP_KERNEL);
if (st->tx == NULL) {
ret = -ENOMEM;
goto error_free_rx;
}
st->us = spi;
mutex_init(&st->buf_lock);
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_tx;
}
st->indio_dev->name = spi->dev.driver->name;
st->indio_dev->dev.parent = &spi->dev;
st->indio_dev->info = &adis16204_info;
st->indio_dev->channels = adis16204_channels;
st->indio_dev->num_channels = ARRAY_SIZE(adis16204_channels);
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis16204_configure_ring(st->indio_dev);
if (ret)
goto error_free_dev;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_unreg_ring_funcs;
regdone = 1;
ret = iio_ring_buffer_register_ex(st->indio_dev->ring, 0,
adis16204_channels,
ARRAY_SIZE(adis16204_channels));
if (ret) {
printk(KERN_ERR "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
if (spi->irq) {
ret = adis16204_probe_trigger(st->indio_dev);
if (ret)
goto error_uninitialize_ring;
}
ret = adis16204_initial_setup(st->indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
adis16204_remove_trigger(st->indio_dev);
error_uninitialize_ring:
iio_ring_buffer_unregister(st->indio_dev->ring);
error_unreg_ring_funcs:
adis16204_unconfigure_ring(st->indio_dev);
error_free_dev:
if (regdone)
iio_device_unregister(st->indio_dev);
else
iio_free_device(st->indio_dev);
error_free_tx:
kfree(st->tx);
error_free_rx:
kfree(st->rx);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int adis16204_remove(struct spi_device *spi)
{
struct adis16204_state *st = spi_get_drvdata(spi);
struct iio_dev *indio_dev = st->indio_dev;
adis16204_remove_trigger(indio_dev);
iio_ring_buffer_unregister(st->indio_dev->ring);
iio_device_unregister(indio_dev);
adis16204_unconfigure_ring(indio_dev);
kfree(st->tx);
kfree(st->rx);
kfree(st);
return 0;
}
static __init int adis16204_init(void)
{
return spi_register_driver(&adis16204_driver);
}
static __exit void adis16204_exit(void)
{
spi_unregister_driver(&adis16204_driver);
}
