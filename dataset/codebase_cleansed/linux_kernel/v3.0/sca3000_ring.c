static int sca3000_read_data(struct sca3000_state *st,
uint8_t reg_address_high,
u8 **rx_p,
int len)
{
int ret;
struct spi_message msg;
struct spi_transfer xfer[2] = {
{
.len = 1,
.tx_buf = st->tx,
}, {
.len = len,
}
};
*rx_p = kmalloc(len, GFP_KERNEL);
if (*rx_p == NULL) {
ret = -ENOMEM;
goto error_ret;
}
xfer[1].rx_buf = *rx_p;
st->tx[0] = SCA3000_READ_REG(reg_address_high);
spi_message_init(&msg);
spi_message_add_tail(&xfer[0], &msg);
spi_message_add_tail(&xfer[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret) {
dev_err(get_device(&st->us->dev), "problem reading register");
goto error_free_rx;
}
return 0;
error_free_rx:
kfree(*rx_p);
error_ret:
return ret;
}
static int sca3000_read_first_n_hw_rb(struct iio_ring_buffer *r,
size_t count, char __user *buf)
{
struct iio_hw_ring_buffer *hw_ring = iio_to_hw_ring_buf(r);
struct iio_dev *indio_dev = hw_ring->private;
struct sca3000_state *st = indio_dev->dev_data;
u8 *rx;
int ret, i, num_available, num_read = 0;
int bytes_per_sample = 1;
if (st->bpse == 11)
bytes_per_sample = 2;
mutex_lock(&st->lock);
if (count % bytes_per_sample) {
ret = -EINVAL;
goto error_ret;
}
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_BUF_COUNT, 1);
if (ret)
goto error_ret;
else
num_available = st->rx[0];
if (count > num_available * bytes_per_sample)
num_read = num_available*bytes_per_sample;
else
num_read = count;
ret = sca3000_read_data(st,
SCA3000_REG_ADDR_RING_OUT,
&rx, num_read);
if (ret)
goto error_ret;
for (i = 0; i < num_read; i++)
*(((u16 *)rx) + i) = be16_to_cpup((u16 *)rx + i);
if (copy_to_user(buf, rx, num_read))
ret = -EFAULT;
kfree(rx);
r->stufftoread = 0;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : num_read;
}
static int sca3000_ring_get_length(struct iio_ring_buffer *r)
{
return 64;
}
static int sca3000_ring_get_bytes_per_datum(struct iio_ring_buffer *r)
{
return 6;
}
static void sca3000_ring_release(struct device *dev)
{
struct iio_ring_buffer *r = to_iio_ring_buffer(dev);
kfree(iio_to_hw_ring_buf(r));
}
static ssize_t sca3000_query_ring_int(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret, val;
struct iio_ring_buffer *ring = dev_get_drvdata(dev);
struct iio_dev *indio_dev = ring->indio_dev;
struct sca3000_state *st = indio_dev->dev_data;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_MASK, 1);
val = st->rx[0];
mutex_unlock(&st->lock);
if (ret)
return ret;
return sprintf(buf, "%d\n", !!(val & this_attr->address));
}
static ssize_t sca3000_set_ring_int(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_ring_buffer *ring = dev_get_drvdata(dev);
struct iio_dev *indio_dev = ring->indio_dev;
struct sca3000_state *st = indio_dev->dev_data;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
long val;
int ret;
mutex_lock(&st->lock);
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_INT_MASK, 1);
if (ret)
goto error_ret;
if (val)
ret = sca3000_write_reg(st,
SCA3000_REG_ADDR_INT_MASK,
st->rx[0] | this_attr->address);
else
ret = sca3000_write_reg(st,
SCA3000_REG_ADDR_INT_MASK,
st->rx[0] & ~this_attr->address);
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t sca3000_show_ring_bpse(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int len = 0, ret;
struct iio_ring_buffer *ring = dev_get_drvdata(dev);
struct iio_dev *indio_dev = ring->indio_dev;
struct sca3000_state *st = indio_dev->dev_data;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
if (st->rx[0] & SCA3000_RING_BUF_8BIT)
len = sprintf(buf, "s8/8\n");
else
len = sprintf(buf, "s11/16\n");
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t sca3000_store_ring_bpse(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_ring_buffer *ring = dev_get_drvdata(dev);
struct iio_dev *indio_dev = ring->indio_dev;
struct sca3000_state *st = indio_dev->dev_data;
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
if (sysfs_streq(buf, "s8/8")) {
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
st->rx[0] | SCA3000_RING_BUF_8BIT);
st->bpse = 8;
} else if (sysfs_streq(buf, "s11/16")) {
ret = sca3000_write_reg(st, SCA3000_REG_ADDR_MODE,
st->rx[0] & ~SCA3000_RING_BUF_8BIT);
st->bpse = 11;
} else
ret = -EINVAL;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static ssize_t sca3000_show_buffer_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_ring_buffer *ring = dev_get_drvdata(dev);
struct iio_dev *indio_dev = ring->indio_dev;
struct sca3000_state *st = indio_dev->dev_data;
return sprintf(buf, "0.%06d\n", 4*st->info->scale);
}
static struct iio_ring_buffer *sca3000_rb_allocate(struct iio_dev *indio_dev)
{
struct iio_ring_buffer *buf;
struct iio_hw_ring_buffer *ring;
ring = kzalloc(sizeof *ring, GFP_KERNEL);
if (!ring)
return NULL;
ring->private = indio_dev;
buf = &ring->buf;
buf->stufftoread = 0;
iio_ring_buffer_init(buf, indio_dev);
buf->dev.type = &sca3000_ring_type;
buf->dev.parent = &indio_dev->dev;
dev_set_drvdata(&buf->dev, (void *)buf);
return buf;
}
static inline void sca3000_rb_free(struct iio_ring_buffer *r)
{
if (r)
iio_put_ring_buffer(r);
}
int sca3000_configure_ring(struct iio_dev *indio_dev)
{
indio_dev->ring = sca3000_rb_allocate(indio_dev);
if (indio_dev->ring == NULL)
return -ENOMEM;
indio_dev->modes |= INDIO_RING_HARDWARE_BUFFER;
indio_dev->ring->access = &sca3000_ring_access_funcs;
iio_scan_mask_set(indio_dev->ring, 0);
iio_scan_mask_set(indio_dev->ring, 1);
iio_scan_mask_set(indio_dev->ring, 2);
return 0;
}
void sca3000_unconfigure_ring(struct iio_dev *indio_dev)
{
sca3000_rb_free(indio_dev->ring);
}
static inline
int __sca3000_hw_ring_state_set(struct iio_dev *indio_dev, bool state)
{
struct sca3000_state *st = indio_dev->dev_data;
int ret;
mutex_lock(&st->lock);
ret = sca3000_read_data_short(st, SCA3000_REG_ADDR_MODE, 1);
if (ret)
goto error_ret;
if (state) {
printk(KERN_INFO "supposedly enabling ring buffer\n");
ret = sca3000_write_reg(st,
SCA3000_REG_ADDR_MODE,
(st->rx[0] | SCA3000_RING_BUF_ENABLE));
} else
ret = sca3000_write_reg(st,
SCA3000_REG_ADDR_MODE,
(st->rx[0] & ~SCA3000_RING_BUF_ENABLE));
error_ret:
mutex_unlock(&st->lock);
return ret;
}
static int sca3000_hw_ring_preenable(struct iio_dev *indio_dev)
{
return __sca3000_hw_ring_state_set(indio_dev, 1);
}
static int sca3000_hw_ring_postdisable(struct iio_dev *indio_dev)
{
return __sca3000_hw_ring_state_set(indio_dev, 0);
}
void sca3000_register_ring_funcs(struct iio_dev *indio_dev)
{
indio_dev->ring->setup_ops = &sca3000_ring_setup_ops;
}
void sca3000_ring_int_process(u8 val, struct iio_ring_buffer *ring)
{
if (val & (SCA3000_INT_STATUS_THREE_QUARTERS |
SCA3000_INT_STATUS_HALF)) {
ring->stufftoread = true;
wake_up_interruptible(&ring->pollq);
}
}
