int adis_write_reg(struct adis *adis, unsigned int reg,
unsigned int value, unsigned int size)
{
unsigned int page = reg / ADIS_PAGE_SIZE;
int ret, i;
struct spi_message msg;
struct spi_transfer xfers[] = {
{
.tx_buf = adis->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->write_delay,
}, {
.tx_buf = adis->tx + 2,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->write_delay,
}, {
.tx_buf = adis->tx + 4,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->write_delay,
}, {
.tx_buf = adis->tx + 6,
.bits_per_word = 8,
.len = 2,
.delay_usecs = adis->data->write_delay,
}, {
.tx_buf = adis->tx + 8,
.bits_per_word = 8,
.len = 2,
.delay_usecs = adis->data->write_delay,
},
};
mutex_lock(&adis->txrx_lock);
spi_message_init(&msg);
if (adis->current_page != page) {
adis->tx[0] = ADIS_WRITE_REG(ADIS_REG_PAGE_ID);
adis->tx[1] = page;
spi_message_add_tail(&xfers[0], &msg);
}
switch (size) {
case 4:
adis->tx[8] = ADIS_WRITE_REG(reg + 3);
adis->tx[9] = (value >> 24) & 0xff;
adis->tx[6] = ADIS_WRITE_REG(reg + 2);
adis->tx[7] = (value >> 16) & 0xff;
case 2:
adis->tx[4] = ADIS_WRITE_REG(reg + 1);
adis->tx[5] = (value >> 8) & 0xff;
case 1:
adis->tx[2] = ADIS_WRITE_REG(reg);
adis->tx[3] = value & 0xff;
break;
default:
ret = -EINVAL;
goto out_unlock;
}
xfers[size].cs_change = 0;
for (i = 1; i <= size; i++)
spi_message_add_tail(&xfers[i], &msg);
ret = spi_sync(adis->spi, &msg);
if (ret) {
dev_err(&adis->spi->dev, "Failed to write register 0x%02X: %d\n",
reg, ret);
} else {
adis->current_page = page;
}
out_unlock:
mutex_unlock(&adis->txrx_lock);
return ret;
}
int adis_read_reg(struct adis *adis, unsigned int reg,
unsigned int *val, unsigned int size)
{
unsigned int page = reg / ADIS_PAGE_SIZE;
struct spi_message msg;
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = adis->tx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->write_delay,
}, {
.tx_buf = adis->tx + 2,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->read_delay,
}, {
.tx_buf = adis->tx + 4,
.rx_buf = adis->rx,
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.delay_usecs = adis->data->read_delay,
}, {
.rx_buf = adis->rx + 2,
.bits_per_word = 8,
.len = 2,
.delay_usecs = adis->data->read_delay,
},
};
mutex_lock(&adis->txrx_lock);
spi_message_init(&msg);
if (adis->current_page != page) {
adis->tx[0] = ADIS_WRITE_REG(ADIS_REG_PAGE_ID);
adis->tx[1] = page;
spi_message_add_tail(&xfers[0], &msg);
}
switch (size) {
case 4:
adis->tx[2] = ADIS_READ_REG(reg + 2);
adis->tx[3] = 0;
spi_message_add_tail(&xfers[1], &msg);
case 2:
adis->tx[4] = ADIS_READ_REG(reg);
adis->tx[5] = 0;
spi_message_add_tail(&xfers[2], &msg);
spi_message_add_tail(&xfers[3], &msg);
break;
default:
ret = -EINVAL;
goto out_unlock;
}
ret = spi_sync(adis->spi, &msg);
if (ret) {
dev_err(&adis->spi->dev, "Failed to read register 0x%02X: %d\n",
reg, ret);
goto out_unlock;
} else {
adis->current_page = page;
}
switch (size) {
case 4:
*val = get_unaligned_be32(adis->rx);
break;
case 2:
*val = get_unaligned_be16(adis->rx + 2);
break;
}
out_unlock:
mutex_unlock(&adis->txrx_lock);
return ret;
}
int adis_debugfs_reg_access(struct iio_dev *indio_dev,
unsigned int reg, unsigned int writeval, unsigned int *readval)
{
struct adis *adis = iio_device_get_drvdata(indio_dev);
if (readval) {
uint16_t val16;
int ret;
ret = adis_read_reg_16(adis, reg, &val16);
*readval = val16;
return ret;
} else {
return adis_write_reg_16(adis, reg, writeval);
}
}
int adis_enable_irq(struct adis *adis, bool enable)
{
int ret = 0;
uint16_t msc;
if (adis->data->enable_irq)
return adis->data->enable_irq(adis, enable);
ret = adis_read_reg_16(adis, adis->data->msc_ctrl_reg, &msc);
if (ret)
goto error_ret;
msc |= ADIS_MSC_CTRL_DATA_RDY_POL_HIGH;
msc &= ~ADIS_MSC_CTRL_DATA_RDY_DIO2;
if (enable)
msc |= ADIS_MSC_CTRL_DATA_RDY_EN;
else
msc &= ~ADIS_MSC_CTRL_DATA_RDY_EN;
ret = adis_write_reg_16(adis, adis->data->msc_ctrl_reg, msc);
error_ret:
return ret;
}
int adis_check_status(struct adis *adis)
{
uint16_t status;
int ret;
int i;
ret = adis_read_reg_16(adis, adis->data->diag_stat_reg, &status);
if (ret < 0)
return ret;
status &= adis->data->status_error_mask;
if (status == 0)
return 0;
for (i = 0; i < 16; ++i) {
if (status & BIT(i)) {
dev_err(&adis->spi->dev, "%s.\n",
adis->data->status_error_msgs[i]);
}
}
return -EIO;
}
int adis_reset(struct adis *adis)
{
int ret;
ret = adis_write_reg_8(adis, adis->data->glob_cmd_reg,
ADIS_GLOB_CMD_SW_RESET);
if (ret)
dev_err(&adis->spi->dev, "Failed to reset device: %d\n", ret);
return ret;
}
static int adis_self_test(struct adis *adis)
{
int ret;
ret = adis_write_reg_16(adis, adis->data->msc_ctrl_reg,
adis->data->self_test_mask);
if (ret) {
dev_err(&adis->spi->dev, "Failed to initiate self test: %d\n",
ret);
return ret;
}
msleep(adis->data->startup_delay);
return adis_check_status(adis);
}
int adis_initial_startup(struct adis *adis)
{
int ret;
ret = adis_self_test(adis);
if (ret) {
dev_err(&adis->spi->dev, "Self-test failed, trying reset.\n");
adis_reset(adis);
msleep(adis->data->startup_delay);
ret = adis_self_test(adis);
if (ret) {
dev_err(&adis->spi->dev, "Second self-test failed, giving up.\n");
return ret;
}
}
return 0;
}
int adis_single_conversion(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int error_mask, int *val)
{
struct adis *adis = iio_device_get_drvdata(indio_dev);
unsigned int uval;
int ret;
mutex_lock(&indio_dev->mlock);
ret = adis_read_reg(adis, chan->address, &uval,
chan->scan_type.storagebits / 8);
if (ret)
goto err_unlock;
if (uval & error_mask) {
ret = adis_check_status(adis);
if (ret)
goto err_unlock;
}
if (chan->scan_type.sign == 's')
*val = sign_extend32(uval, chan->scan_type.realbits - 1);
else
*val = uval & ((1 << chan->scan_type.realbits) - 1);
ret = IIO_VAL_INT;
err_unlock:
mutex_unlock(&indio_dev->mlock);
return ret;
}
int adis_init(struct adis *adis, struct iio_dev *indio_dev,
struct spi_device *spi, const struct adis_data *data)
{
mutex_init(&adis->txrx_lock);
adis->spi = spi;
adis->data = data;
iio_device_set_drvdata(indio_dev, adis);
if (data->has_paging) {
adis->current_page = -1;
} else {
adis->current_page = 0;
}
return adis_enable_irq(adis, false);
}
