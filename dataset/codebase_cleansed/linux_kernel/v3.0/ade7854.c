static ssize_t ade7854_read_8bit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
u8 val = 0;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
struct ade7854_state *st = iio_dev_get_devdata(indio_dev);
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
static int ade7854_initial_setup(struct ade7854_state *st)
{
int ret;
struct device *dev = &st->indio_dev->dev;
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
int ade7854_probe(struct ade7854_state *st, struct device *dev)
{
int ret;
st->rx = kzalloc(sizeof(*st->rx)*ADE7854_MAX_RX, GFP_KERNEL);
if (st->rx == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->tx = kzalloc(sizeof(*st->tx)*ADE7854_MAX_TX, GFP_KERNEL);
if (st->tx == NULL) {
ret = -ENOMEM;
goto error_free_rx;
}
mutex_init(&st->buf_lock);
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_tx;
}
st->indio_dev->dev.parent = dev;
st->indio_dev->info = &ade7854_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_dev;
ret = ade7854_initial_setup(st);
if (ret)
goto error_unreg_dev;
return 0;
error_unreg_dev:
iio_device_unregister(st->indio_dev);
error_free_dev:
iio_free_device(st->indio_dev);
error_free_tx:
kfree(st->tx);
error_free_rx:
kfree(st->rx);
error_free_st:
kfree(st);
return ret;
}
int ade7854_remove(struct ade7854_state *st)
{
struct iio_dev *indio_dev = st->indio_dev;
iio_device_unregister(indio_dev);
kfree(st->tx);
kfree(st->rx);
kfree(st);
return 0;
}
