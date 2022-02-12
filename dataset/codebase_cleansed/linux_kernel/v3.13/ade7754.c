static int ade7754_spi_write_reg_8(struct device *dev,
u8 reg_address,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7754_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7754_spi_write_reg_16(struct device *dev,
u8 reg_address,
u16 value)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7754_WRITE_REG(reg_address);
st->tx[1] = (value >> 8) & 0xFF;
st->tx[2] = value & 0xFF;
ret = spi_write(st->us, st->tx, 3);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7754_spi_read_reg_8(struct device *dev,
u8 reg_address,
u8 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
int ret;
ret = spi_w8r8(st->us, ADE7754_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 8 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
return 0;
}
static int ade7754_spi_read_reg_16(struct device *dev,
u8 reg_address,
u16 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
int ret;
ret = spi_w8r16be(st->us, ADE7754_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 16 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
return 0;
}
static int ade7754_spi_read_reg_24(struct device *dev,
u8 reg_address,
u32 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 4,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7754_READ_REG(reg_address);
st->tx[1] = 0;
st->tx[2] = 0;
st->tx[3] = 0;
ret = spi_sync_transfer(st->us, xfers, ARRAY_SIZE(xfers));
if (ret) {
dev_err(&st->us->dev, "problem when reading 24 bit register 0x%02X",
reg_address);
goto error_ret;
}
*val = (st->rx[1] << 16) | (st->rx[2] << 8) | st->rx[3];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t ade7754_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7754_spi_read_reg_8(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7754_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7754_spi_read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7754_read_24bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u32 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7754_spi_read_reg_24(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val & 0xFFFFFF);
}
static ssize_t ade7754_write_8bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
u8 val;
ret = kstrtou8(buf, 10, &val);
if (ret)
goto error_ret;
ret = ade7754_spi_write_reg_8(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7754_write_16bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
u16 val;
ret = kstrtou16(buf, 10, &val);
if (ret)
goto error_ret;
ret = ade7754_spi_write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7754_reset(struct device *dev)
{
u8 val;
ade7754_spi_read_reg_8(dev, ADE7754_OPMODE, &val);
val |= 1 << 6;
return ade7754_spi_write_reg_8(dev, ADE7754_OPMODE, val);
}
static int ade7754_set_irq(struct device *dev, bool enable)
{
int ret;
u16 irqen;
ret = ade7754_spi_read_reg_16(dev, ADE7754_IRQEN, &irqen);
if (ret)
goto error_ret;
if (enable)
irqen |= 1 << 14;
else
irqen &= ~(1 << 14);
ret = ade7754_spi_write_reg_16(dev, ADE7754_IRQEN, irqen);
if (ret)
goto error_ret;
error_ret:
return ret;
}
static int ade7754_stop_device(struct device *dev)
{
u8 val;
ade7754_spi_read_reg_8(dev, ADE7754_OPMODE, &val);
val |= 7 << 3;
return ade7754_spi_write_reg_8(dev, ADE7754_OPMODE, val);
}
static int ade7754_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct ade7754_state *st = iio_priv(indio_dev);
struct device *dev = &indio_dev->dev;
st->us->mode = SPI_MODE_3;
spi_setup(st->us);
ret = ade7754_set_irq(dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ade7754_reset(dev);
msleep(ADE7754_STARTUP_DELAY);
err_ret:
return ret;
}
static ssize_t ade7754_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 t;
int sps;
ret = ade7754_spi_read_reg_8(dev,
ADE7754_WAVMODE,
&t);
if (ret)
return ret;
t = (t >> 3) & 0x3;
sps = 26000 / (1 + t);
return sprintf(buf, "%d\n", sps);
}
static ssize_t ade7754_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7754_state *st = iio_priv(indio_dev);
u16 val;
int ret;
u8 reg, t;
ret = kstrtou16(buf, 10, &val);
if (ret)
return ret;
if (val == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
t = (26000 / val);
if (t > 0)
t--;
if (t > 1)
st->us->max_speed_hz = ADE7754_SPI_SLOW;
else
st->us->max_speed_hz = ADE7754_SPI_FAST;
ret = ade7754_spi_read_reg_8(dev, ADE7754_WAVMODE, &reg);
if (ret)
goto out;
reg &= ~(3 << 3);
reg |= t << 3;
ret = ade7754_spi_write_reg_8(dev, ADE7754_WAVMODE, reg);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ade7754_probe(struct spi_device *spi)
{
int ret;
struct ade7754_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ade7754_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ade7754_initial_setup(indio_dev);
if (ret)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
return ret;
return 0;
}
static int ade7754_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
ade7754_stop_device(&indio_dev->dev);
return 0;
}
