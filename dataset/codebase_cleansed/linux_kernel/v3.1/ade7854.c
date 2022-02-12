static ssize_t ade7854_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = st->read_reg_8(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7854_read_16bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u16 val = 0;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = st->read_reg_16(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7854_read_24bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u32 val;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = st->read_reg_24(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7854_read_32bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u32 val = 0;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
ret = st->read_reg_32(dev, this_attr->address, &val);
if (ret)
return ret;
return sprintf(buf, "%u\n", val);
}
static ssize_t ade7854_write_8bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = st->write_reg_8(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7854_write_16bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = st->write_reg_16(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7854_write_24bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = st->write_reg_24(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static ssize_t ade7854_write_32bit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = st->write_reg_32(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7854_reset(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
u16 val;
st->read_reg_16(dev, ADE7854_CONFIG, &val);
val |= 1 << 7;
return st->write_reg_16(dev, ADE7854_CONFIG, val);
}
static ssize_t ade7854_write_reset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
if (len < 1)
return -1;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
return ade7854_reset(dev);
}
return -1;
}
static int ade7854_set_irq(struct device *dev, bool enable)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u32 irqen;
ret = st->read_reg_32(dev, ADE7854_MASK0, &irqen);
if (ret)
goto error_ret;
if (enable)
irqen |= 1 << 17;
else
irqen &= ~(1 << 17);
ret = st->write_reg_32(dev, ADE7854_MASK0, irqen);
if (ret)
goto error_ret;
error_ret:
return ret;
}
static int ade7854_initial_setup(struct iio_dev *indio_dev)
{
int ret;
struct device *dev = &indio_dev->dev;
ret = ade7854_set_irq(dev, false);
if (ret) {
dev_err(dev, "disable irq failed");
goto err_ret;
}
ade7854_reset(dev);
msleep(ADE7854_STARTUP_DELAY);
err_ret:
return ret;
}
int ade7854_probe(struct iio_dev *indio_dev, struct device *dev)
{
int ret;
struct ade7854_state *st = iio_priv(indio_dev);
mutex_init(&st->buf_lock);
indio_dev->dev.parent = dev;
indio_dev->info = &ade7854_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
ret = ade7854_initial_setup(indio_dev);
if (ret)
goto error_unreg_dev;
return 0;
error_unreg_dev:
iio_device_unregister(indio_dev);
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
int ade7854_remove(struct iio_dev *indio_dev)
{
iio_device_unregister(indio_dev);
return 0;
}
