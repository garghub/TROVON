static int ade7759_spi_write_reg_8(struct device *dev,
u8 reg_address,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7759_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7759_spi_write_reg_16(struct device *dev,
u8 reg_address,
u16 value)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7759_WRITE_REG(reg_address);
st->tx[1] = (value >> 8) & 0xFF;
st->tx[2] = value & 0xFF;
ret = spi_write(st->us, st->tx, 3);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7759_spi_read_reg_8(struct device *dev,
u8 reg_address,
u8 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
int ret;
ret = spi_w8r8(st->us, ADE7759_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 8 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
return 0;
}
static int ade7759_spi_read_reg_16(struct device *dev,
u8 reg_address,
u16 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
int ret;
ret = spi_w8r16(st->us, ADE7759_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 16 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
*val = be16_to_cpup(val);
return 0;
}
static int ade7759_spi_read_reg_40(struct device *dev,
u8 reg_address,
u64 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 6,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7759_READ_REG(reg_address);
memset(&st->tx[1], 0 , 5);
ret = spi_sync_transfer(st->us, xfers, ARRAY_SIZE(xfers));
if (ret) {
dev_err(&st->us->dev, "problem when reading 40 bit register 0x%02X",
reg_address);
goto error_ret;
}
*val = ((u64)st->rx[1] << 32) | (st->rx[2] << 24) |
(st->rx[3] << 16) | (st->rx[4] << 8) | st->rx[5];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t ade7759_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7759_spi_read_reg_8(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7759_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7759_spi_read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7759_read_40bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u64 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7759_spi_read_reg_40(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%llu\n", val);
}
static ssize_t ade7759_write_8bit(struct device *dev,
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
ret = ade7759_spi_write_reg_8(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7759_write_16bit(struct device *dev,
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
ret = ade7759_spi_write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7759_reset(struct device *dev)
{
int ret;
u16 val;
ade7759_spi_read_reg_16(dev,
ADE7759_MODE,
&val);
val |= 1 << 6;
ret = ade7759_spi_write_reg_16(dev,
ADE7759_MODE,
val);
return ret;
}
static ssize_t ade7759_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return ade7759_reset(dev);
}
return -1;
}
static int ade7759_set_irq(struct device *dev, bool enable)
{
int ret;
u8 irqen;
ret = ade7759_spi_read_reg_8(dev, ADE7759_IRQEN, &irqen);
if (ret)
goto error_ret;
if (enable)
irqen |= 1 << 3;
else
irqen &= ~(1 << 3);
ret = ade7759_spi_write_reg_8(dev, ADE7759_IRQEN, irqen);
error_ret:
return ret;
}
static int ade7759_stop_device(struct device *dev)
{
u16 val;
ade7759_spi_read_reg_16(dev,
ADE7759_MODE,
&val);
val |= 1 << 4;
return ade7759_spi_write_reg_16(dev, ADE7759_MODE, val);
}
static int ade7759_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct ade7759_state *st = iio_priv(indio_dev);
struct device *dev = &indio_dev->dev;
st->us->mode = SPI_MODE_3;
spi_setup(st->us);
ret = ade7759_set_irq(dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ade7759_reset(dev);
msleep(ADE7759_STARTUP_DELAY);
err_ret:
return ret;
}
static ssize_t ade7759_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 t;
int sps;
ret = ade7759_spi_read_reg_16(dev,
ADE7759_MODE,
&t);
if (ret)
return ret;
t = (t >> 3) & 0x3;
sps = 27900 / (1 + t);
return sprintf(buf, "%d\n", sps);
}
static ssize_t ade7759_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7759_state *st = iio_priv(indio_dev);
unsigned long val;
int ret;
u16 reg, t;
ret = strict_strtol(buf, 10, &val);
if (ret)
return ret;
if (val == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
t = (27900 / val);
if (t > 0)
t--;
if (t > 1)
st->us->max_speed_hz = ADE7759_SPI_SLOW;
else
st->us->max_speed_hz = ADE7759_SPI_FAST;
ret = ade7759_spi_read_reg_16(dev, ADE7759_MODE, &reg);
if (ret)
goto out;
reg &= ~(3 << 13);
reg |= t << 13;
ret = ade7759_spi_write_reg_16(dev, ADE7759_MODE, reg);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ade7759_probe(struct spi_device *spi)
{
int ret;
struct ade7759_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ade7759_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ade7759_initial_setup(indio_dev);
if (ret)
goto error_free_dev;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
return 0;
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int ade7759_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
ade7759_stop_device(&indio_dev->dev);
iio_device_free(indio_dev);
return 0;
}
