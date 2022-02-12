static ssize_t ade7854_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u8 val;
ret = kstrtou8(buf, 10, &val);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u16 val;
ret = kstrtou16(buf, 10, &val);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u32 val;
ret = kstrtou32(buf, 10, &val);
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
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u32 val;
ret = kstrtou32(buf, 10, &val);
if (ret)
goto error_ret;
ret = st->write_reg_32(dev, this_attr->address, val);
error_ret:
return ret ? ret : len;
}
static int ade7854_reset(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
u16 val;
st->read_reg_16(dev, ADE7854_CONFIG, &val);
val |= BIT(7);
return st->write_reg_16(dev, ADE7854_CONFIG, val);
}
static int ade7854_set_irq(struct device *dev, bool enable)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ade7854_state *st = iio_priv(indio_dev);
int ret;
u32 irqen;
ret = st->read_reg_32(dev, ADE7854_MASK0, &irqen);
if (ret)
return ret;
if (enable)
irqen |= BIT(17);
else
irqen &= ~BIT(17);
ret = st->write_reg_32(dev, ADE7854_MASK0, irqen);
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
usleep_range(ADE7854_STARTUP_DELAY, ADE7854_STARTUP_DELAY + 100);
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
ret = devm_iio_device_register(dev, indio_dev);
if (ret)
return ret;
return ade7854_initial_setup(indio_dev);
}
