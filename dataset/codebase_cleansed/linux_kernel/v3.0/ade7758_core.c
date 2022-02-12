int ade7758_spi_write_reg_8(struct device *dev,
u8 reg_address,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_WRITE_REG(reg_address);
st->tx[1] = val;
ret = spi_write(st->us, st->tx, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7758_spi_write_reg_16(struct device *dev,
u8 reg_address,
u16 value)
{
int ret;
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 3,
}
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_WRITE_REG(reg_address);
st->tx[1] = (value >> 8) & 0xFF;
st->tx[2] = value & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(xfers, &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7758_spi_write_reg_24(struct device *dev,
u8 reg_address,
u32 value)
{
int ret;
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 4,
}
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_WRITE_REG(reg_address);
st->tx[1] = (value >> 16) & 0xFF;
st->tx[2] = (value >> 8) & 0xFF;
st->tx[3] = value & 0xFF;
spi_message_init(&msg);
spi_message_add_tail(xfers, &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
return ret;
}
int ade7758_spi_read_reg_8(struct device *dev,
u8 reg_address,
u8 *val)
{
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 1,
.delay_usecs = 4,
},
{
.tx_buf = &st->tx[1],
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 1,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_READ_REG(reg_address);
st->tx[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev, "problem when reading 8 bit register 0x%02X",
reg_address);
goto error_ret;
}
*val = st->rx[0];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7758_spi_read_reg_16(struct device *dev,
u8 reg_address,
u16 *val)
{
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 1,
.delay_usecs = 4,
},
{
.tx_buf = &st->tx[1],
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 2,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_READ_REG(reg_address);
st->tx[1] = 0;
st->tx[2] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(&st->us->dev, "problem when reading 16 bit register 0x%02X",
reg_address);
goto error_ret;
}
*val = (st->rx[0] << 8) | st->rx[1];
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int ade7758_spi_read_reg_24(struct device *dev,
u8 reg_address,
u32 *val)
{
struct spi_message msg;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7758_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = st->tx,
.bits_per_word = 8,
.len = 1,
.delay_usecs = 4,
},
{
.tx_buf = &st->tx[1],
.rx_buf = st->rx,
.bits_per_word = 8,
.len = 3,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = ADE7758_READ_REG(reg_address);
st->tx[1] = 0;
st->tx[2] = 0;
st->tx[3] = 0;
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
static ssize_t ade7758_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7758_spi_read_reg_8(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7758_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7758_spi_read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7758_read_24bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u32 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = ade7758_spi_read_reg_24(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val & 0xFFFFFF);
}
static ssize_t ade7758_write_8bit(struct device *dev,
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
ret = ade7758_spi_write_reg_8(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7758_write_16bit(struct device *dev,
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
ret = ade7758_spi_write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7758_reset(struct device *dev)
{
int ret;
u8 val;
ade7758_spi_read_reg_8(dev,
ADE7758_OPMODE,
&val);
val |= 1 << 6;
ret = ade7758_spi_write_reg_8(dev,
ADE7758_OPMODE,
val);
return ret;
}
static ssize_t ade7758_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return ade7758_reset(dev);
}
return len;
}
int ade7758_set_irq(struct device *dev, bool enable)
{
int ret;
u32 irqen;
ret = ade7758_spi_read_reg_24(dev, ADE7758_MASK, &irqen);
if (ret)
goto error_ret;
if (enable)
irqen |= 1 << 16;
else
irqen &= ~(1 << 16);
ret = ade7758_spi_write_reg_24(dev, ADE7758_MASK, irqen);
if (ret)
goto error_ret;
error_ret:
return ret;
}
static int ade7758_stop_device(struct device *dev)
{
int ret;
u8 val;
ade7758_spi_read_reg_8(dev,
ADE7758_OPMODE,
&val);
val |= 7 << 3;
ret = ade7758_spi_write_reg_8(dev,
ADE7758_OPMODE,
val);
return ret;
}
static int ade7758_initial_setup(struct iio_dev *indio_dev)
{
struct ade7758_state *st = iio_priv(indio_dev);
struct device *dev = &indio_dev->dev;
int ret;
st->us->mode = SPI_MODE_1;
spi_setup(st->us);
ret = ade7758_set_irq(dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ade7758_reset(dev);
msleep(ADE7758_STARTUP_DELAY);
err_ret:
return ret;
}
static ssize_t ade7758_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret, len = 0;
u8 t;
int sps;
ret = ade7758_spi_read_reg_8(dev,
ADE7758_WAVMODE,
&t);
if (ret)
return ret;
t = (t >> 5) & 0x3;
sps = 26040 / (1 << t);
len = sprintf(buf, "%d SPS\n", sps);
return len;
}
static ssize_t ade7758_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
unsigned long val;
int ret;
u8 reg, t;
ret = strict_strtol(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
switch (val) {
case 26040:
t = 0;
break;
case 13020:
t = 1;
break;
case 6510:
t = 2;
break;
case 3255:
t = 3;
break;
default:
ret = -EINVAL;
goto out;
}
ret = ade7758_spi_read_reg_8(dev,
ADE7758_WAVMODE,
&reg);
if (ret)
goto out;
reg &= ~(5 << 3);
reg |= t << 5;
ret = ade7758_spi_write_reg_8(dev,
ADE7758_WAVMODE,
reg);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int __devinit ade7758_probe(struct spi_device *spi)
{
int i, ret, regdone = 0;
struct ade7758_state *st;
struct iio_dev *indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->rx = kzalloc(sizeof(*st->rx)*ADE7758_MAX_RX, GFP_KERNEL);
if (st->rx == NULL) {
ret = -ENOMEM;
goto error_free_dev;
}
st->tx = kzalloc(sizeof(*st->tx)*ADE7758_MAX_TX, GFP_KERNEL);
if (st->tx == NULL) {
ret = -ENOMEM;
goto error_free_rx;
}
st->us = spi;
st->ade7758_ring_channels = &ade7758_channels[0];
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ade7758_info;
indio_dev->modes = INDIO_DIRECT_MODE;
for (i = 0; i < AD7758_NUM_WAVESRC; i++)
st->available_scan_masks[i] = 1 << i;
indio_dev->available_scan_masks = st->available_scan_masks;
ret = ade7758_configure_ring(indio_dev);
if (ret)
goto error_free_tx;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_ring_funcs;
regdone = 1;
ret = iio_ring_buffer_register_ex(indio_dev->ring, 0,
&ade7758_channels[0],
ARRAY_SIZE(ade7758_channels));
if (ret) {
dev_err(&spi->dev, "failed to initialize the ring\n");
goto error_unreg_ring_funcs;
}
ret = ade7758_initial_setup(indio_dev);
if (ret)
goto error_uninitialize_ring;
if (spi->irq) {
ret = ade7758_probe_trigger(indio_dev);
if (ret)
goto error_remove_trigger;
}
return 0;
error_remove_trigger:
if (indio_dev->modes & INDIO_RING_TRIGGERED)
ade7758_remove_trigger(indio_dev);
error_uninitialize_ring:
ade7758_uninitialize_ring(indio_dev->ring);
error_unreg_ring_funcs:
ade7758_unconfigure_ring(indio_dev);
error_free_tx:
kfree(st->tx);
error_free_rx:
kfree(st->rx);
error_free_dev:
if (regdone)
iio_device_unregister(indio_dev);
else
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int ade7758_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ade7758_state *st = iio_priv(indio_dev);
int ret;
ret = ade7758_stop_device(&indio_dev->dev);
if (ret)
goto err_ret;
ade7758_remove_trigger(indio_dev);
ade7758_uninitialize_ring(indio_dev->ring);
ade7758_unconfigure_ring(indio_dev);
kfree(st->tx);
kfree(st->rx);
iio_device_unregister(indio_dev);
return 0;
err_ret:
return ret;
}
static __init int ade7758_init(void)
{
return spi_register_driver(&ade7758_driver);
}
static __exit void ade7758_exit(void)
{
spi_unregister_driver(&ade7758_driver);
}
