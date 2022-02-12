static int ade7753_spi_write_reg_8(struct device *dev,
u8 reg_address,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7753_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7753_spi_write_reg_16(struct device *dev,
u8 reg_address,
u16 value)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7753_WRITE_REG(reg_address);
st->tx[1] = (value >> 8) & 0xFF;
st->tx[2] = value & 0xFF;
ret = spi_write(st->us, st->tx, 3);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7753_spi_read_reg_8(struct device *dev,
u8 reg_address,
u8 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
ssize_t ret;
ret = spi_w8r8(st->us, ADE7753_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 8 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
return 0;
}
static int ade7753_spi_read_reg_16(struct device *dev,
u8 reg_address,
u16 *val)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
ssize_t ret;
ret = spi_w8r16(st->us, ADE7753_READ_REG(reg_address));
if (ret < 0) {
dev_err(&st->us->dev, "problem when reading 16 bit register 0x%02X",
reg_address);
return ret;
}
*val = ret;
*val = be16_to_cpup(val);
return 0;
}
static int ade7753_spi_read_reg_24(struct device *dev,
u8 reg_address,
u32 *val)
{
struct spi_message msg;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 1,
}, {
.rx_buf = st->tx,
.bits_per_word = 8,
.len = 3,
}
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7753_READ_REG(reg_address);
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev, "problem when reading 24 bit register 0x%02X",
reg_address);
goto error_ret;
}
*val = (st->rx[0] << 16) | (st->rx[1] << 8) | st->rx[2];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t ade7753_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7753_spi_read_reg_8(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7753_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7753_spi_read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7753_read_24bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u32 val;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7753_spi_read_reg_24(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7753_write_8bit(struct device *dev,
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
ret = ade7753_spi_write_reg_8(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7753_write_16bit(struct device *dev,
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
ret = ade7753_spi_write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7753_reset(struct device *dev)
{
u16 val;
ade7753_spi_read_reg_16(dev, ADE7753_MODE, &val);
val |= 1 << 6;
return ade7753_spi_write_reg_16(dev, ADE7753_MODE, val);
}
static ssize_t ade7753_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return ade7753_reset(dev);
}
return -1;
}
static int ade7753_set_irq(struct device *dev, bool enable)
{
int ret;
u8 irqen;
ret = ade7753_spi_read_reg_8(dev, ADE7753_IRQEN, &irqen);
if (ret)
goto error_ret;
if (enable)
irqen |= 1 << 3;
else
irqen &= ~(1 << 3);
ret = ade7753_spi_write_reg_8(dev, ADE7753_IRQEN, irqen);
error_ret:
return ret;
}
static int ade7753_stop_device(struct device *dev)
{
u16 val;
ade7753_spi_read_reg_16(dev, ADE7753_MODE, &val);
val |= 1 << 4;
return ade7753_spi_write_reg_16(dev, ADE7753_MODE, val);
}
static int ade7753_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct device *dev = &indio_dev->dev;
struct ade7753_state *st = iio_priv(indio_dev);
st->us->mode = SPI_MODE_3;
spi_setup(st->us);
ret = ade7753_set_irq(dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ade7753_reset(dev);
msleep(ADE7753_STARTUP_DELAY);
err_ret:
return ret;
}
static ssize_t ade7753_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret, len = 0;
u16 t;
int sps;
ret = ade7753_spi_read_reg_16(dev, ADE7753_MODE, &t);
if (ret)
return ret;
t = (t >> 11) & 0x3;
sps = 27900 / (1 + t);
len = sprintf(buf, "%d\n", sps);
return len;
}
static ssize_t ade7753_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7753_state *st = iio_priv(indio_dev);
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
st->us->max_speed_hz = ADE7753_SPI_SLOW;
else
st->us->max_speed_hz = ADE7753_SPI_FAST;
ret = ade7753_spi_read_reg_16(dev, ADE7753_MODE, &reg);
if (ret)
goto out;
reg &= ~(3 << 11);
reg |= t << 11;
ret = ade7753_spi_write_reg_16(dev, ADE7753_MODE, reg);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int __devinit ade7753_probe(struct spi_device *spi)
{
int ret;
struct ade7753_state *st;
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
indio_dev->info = &ade7753_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ade7753_initial_setup(indio_dev);
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
static int __devexit ade7753_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
ade7753_stop_device(&indio_dev->dev);
iio_device_free(indio_dev);
return 0;
}
