static int adxrs450_spi_read_reg_16(struct iio_dev *indio_dev,
u8 reg_address,
u16 *val)
{
struct adxrs450_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->buf_lock);
st->tx[0] = ADXRS450_READ_DATA | (reg_address >> 7);
st->tx[1] = reg_address << 1;
st->tx[2] = 0;
st->tx[3] = 0;
if (!(hweight32(be32_to_cpu(*(u32 *)st->tx)) & 1))
st->tx[3] |= ADXRS450_P;
ret = spi_write(st->us, st->tx, 4);
if (ret) {
dev_err(&st->us->dev, "problem while reading 16 bit register 0x%02x\n",
reg_address);
goto error_ret;
}
ret = spi_read(st->us, st->rx, 4);
if (ret) {
dev_err(&st->us->dev, "problem while reading 16 bit register 0x%02x\n",
reg_address);
goto error_ret;
}
*val = (be32_to_cpu(*(u32 *)st->rx) >> 5) & 0xFFFF;
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int adxrs450_spi_write_reg_16(struct iio_dev *indio_dev,
u8 reg_address,
u16 val)
{
struct adxrs450_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->buf_lock);
st->tx[0] = ADXRS450_WRITE_DATA | reg_address >> 7;
st->tx[1] = reg_address << 1 | val >> 15;
st->tx[2] = val >> 7;
st->tx[3] = val << 1;
if (!(hweight32(be32_to_cpu(*(u32 *)st->tx)) & 1))
st->tx[3] |= ADXRS450_P;
ret = spi_write(st->us, st->tx, 4);
if (ret)
dev_err(&st->us->dev, "problem while writing 16 bit register 0x%02x\n",
reg_address);
msleep(1);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adxrs450_spi_sensor_data(struct iio_dev *indio_dev, s16 *val)
{
struct adxrs450_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&st->buf_lock);
st->tx[0] = ADXRS450_SENSOR_DATA;
st->tx[1] = 0;
st->tx[2] = 0;
st->tx[3] = 0;
ret = spi_write(st->us, st->tx, 4);
if (ret) {
dev_err(&st->us->dev, "Problem while reading sensor data\n");
goto error_ret;
}
ret = spi_read(st->us, st->rx, 4);
if (ret) {
dev_err(&st->us->dev, "Problem while reading sensor data\n");
goto error_ret;
}
*val = (be32_to_cpu(*(u32 *)st->rx) >> 10) & 0xFFFF;
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int adxrs450_spi_initial(struct adxrs450_state *st,
u32 *val, char chk)
{
struct spi_message msg;
int ret;
struct spi_transfer xfers = {
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 4,
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADXRS450_SENSOR_DATA;
st->tx[1] = 0;
st->tx[2] = 0;
st->tx[3] = 0;
if (chk)
st->tx[3] |= (ADXRS450_CHK | ADXRS450_P);
spi_message_init(&msg);
spi_message_add_tail(&xfers, &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev, "Problem while reading initializing data\n");
goto error_ret;
}
*val = be32_to_cpu(*(u32 *)st->rx);
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int adxrs450_initial_setup(struct iio_dev *indio_dev)
{
u32 t;
u16 data;
int ret;
struct adxrs450_state *st = iio_priv(indio_dev);
msleep(ADXRS450_STARTUP_DELAY*2);
ret = adxrs450_spi_initial(st, &t, 1);
if (ret)
return ret;
if (t != 0x01)
dev_warn(&st->us->dev, "The initial power on response "
"is not correct! Restart without reset?\n");
msleep(ADXRS450_STARTUP_DELAY);
ret = adxrs450_spi_initial(st, &t, 0);
if (ret)
return ret;
msleep(ADXRS450_STARTUP_DELAY);
ret = adxrs450_spi_initial(st, &t, 0);
if (ret)
return ret;
if (((t & 0xff) | 0x01) != 0xff || ADXRS450_GET_ST(t) != 2) {
dev_err(&st->us->dev, "The second response is not correct!\n");
return -EIO;
}
ret = adxrs450_spi_initial(st, &t, 0);
if (ret)
return ret;
if (((t & 0xff) | 0x01) != 0xff || ADXRS450_GET_ST(t) != 2) {
dev_err(&st->us->dev, "The third response is not correct!\n");
return -EIO;
}
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_FAULT1, &data);
if (ret)
return ret;
if (data & 0x0fff) {
dev_err(&st->us->dev, "The device is not in normal status!\n");
return -EINVAL;
}
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_PID1, &data);
if (ret)
return ret;
dev_info(&st->us->dev, "The Part ID is 0x%x\n", data);
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_SNL, &data);
if (ret)
return ret;
t = data;
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_SNH, &data);
if (ret)
return ret;
t |= data << 16;
dev_info(&st->us->dev, "The Serial Number is 0x%x\n", t);
return 0;
}
static int adxrs450_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int ret;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
ret = adxrs450_spi_write_reg_16(indio_dev,
ADXRS450_DNC1,
val & 0x3FF);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int adxrs450_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret;
s16 t;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_ANGL_VEL:
ret = adxrs450_spi_sensor_data(indio_dev, &t);
if (ret)
break;
*val = t;
ret = IIO_VAL_INT;
break;
case IIO_TEMP:
ret = adxrs450_spi_read_reg_16(indio_dev,
ADXRS450_TEMP1, &t);
if (ret)
break;
*val = (t >> 6) + 225;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = 0;
*val2 = 218166;
return IIO_VAL_INT_PLUS_NANO;
case IIO_TEMP:
*val = 200;
*val2 = 0;
return IIO_VAL_INT;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_QUADRATURE_CORRECTION_RAW:
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_QUAD1, &t);
if (ret)
break;
*val = t;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_CALIBBIAS:
ret = adxrs450_spi_read_reg_16(indio_dev, ADXRS450_DNC1, &t);
if (ret)
break;
*val = t;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int __devinit adxrs450_probe(struct spi_device *spi)
{
int ret;
struct adxrs450_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adxrs450_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels =
adxrs450_channels[spi_get_device_id(spi)->driver_data];
indio_dev->num_channels = ARRAY_SIZE(adxrs450_channels);
indio_dev->name = spi->dev.driver->name;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
ret = adxrs450_initial_setup(indio_dev);
if (ret)
goto error_initial;
return 0;
error_initial:
iio_device_unregister(indio_dev);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int adxrs450_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
iio_device_free(spi_get_drvdata(spi));
return 0;
}
