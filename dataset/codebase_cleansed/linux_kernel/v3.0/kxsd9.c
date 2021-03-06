static ssize_t kxsd9_read_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
ssize_t len = 0;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = indio_dev->dev_data;
struct spi_transfer xfer = {
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.tx_buf = st->tx,
.rx_buf = st->rx,
};
struct spi_message msg;
mutex_lock(&st->buf_lock);
st->tx[0] = KXSD9_READ(KXSD9_REG_CTRL_C);
st->tx[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->us, &msg);
if (ret)
goto error_ret;
switch (st->rx[1] & KXSD9_FS_MASK) {
case KXSD9_FS_8:
len += sprintf(buf, "%s\n", KXSD9_SCALE_8G);
break;
case KXSD9_FS_6:
len += sprintf(buf, "%s\n", KXSD9_SCALE_6G);
break;
case KXSD9_FS_4:
len += sprintf(buf, "%s\n", KXSD9_SCALE_4G);
break;
case KXSD9_FS_2:
len += sprintf(buf, "%s\n", KXSD9_SCALE_2G);
break;
}
error_ret:
mutex_unlock(&st->buf_lock);
return ret ? ret : len;
}
static ssize_t kxsd9_write_scale(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_message msg;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = indio_dev->dev_data;
u8 val;
struct spi_transfer xfers[] = {
{
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.tx_buf = st->tx,
.rx_buf = st->rx,
}, {
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.tx_buf = st->tx,
},
};
if (!strncmp(buf, KXSD9_SCALE_8G,
strlen(buf) < strlen(KXSD9_SCALE_8G)
? strlen(buf) : strlen(KXSD9_SCALE_8G)))
val = KXSD9_FS_8;
else if (!strncmp(buf, KXSD9_SCALE_6G,
strlen(buf) < strlen(KXSD9_SCALE_6G)
? strlen(buf) : strlen(KXSD9_SCALE_6G)))
val = KXSD9_FS_6;
else if (!strncmp(buf, KXSD9_SCALE_4G,
strlen(buf) < strlen(KXSD9_SCALE_4G)
? strlen(buf) : strlen(KXSD9_SCALE_4G)))
val = KXSD9_FS_4;
else if (!strncmp(buf, KXSD9_SCALE_2G,
strlen(buf) < strlen(KXSD9_SCALE_2G)
? strlen(buf) : strlen(KXSD9_SCALE_2G)))
val = KXSD9_FS_2;
else
return -EINVAL;
mutex_lock(&st->buf_lock);
st->tx[0] = KXSD9_READ(KXSD9_REG_CTRL_C);
st->tx[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
ret = spi_sync(st->us, &msg);
if (ret)
goto error_ret;
st->tx[0] = KXSD9_WRITE(KXSD9_REG_CTRL_C);
st->tx[1] = (st->rx[1] & ~KXSD9_FS_MASK) | val;
spi_message_init(&msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
error_ret:
mutex_unlock(&st->buf_lock);
return ret ? ret : len;
}
static ssize_t kxsd9_read_accel(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct spi_message msg;
int ret;
ssize_t len = 0;
u16 val;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = indio_dev->dev_data;
struct spi_transfer xfers[] = {
{
.bits_per_word = 8,
.len = 1,
.cs_change = 0,
.delay_usecs = 200,
.tx_buf = st->tx,
}, {
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
.rx_buf = st->rx,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = KXSD9_READ(this_attr->address);
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret)
goto error_ret;
val = (((u16)(st->rx[0])) << 8) | (st->rx[1] & 0xF0);
len = sprintf(buf, "%d\n", val);
error_ret:
mutex_unlock(&st->buf_lock);
return ret ? ret : len;
}
static int __devinit kxsd9_power_up(struct spi_device *spi)
{
int ret;
struct spi_transfer xfers[2] = {
{
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
}, {
.bits_per_word = 8,
.len = 2,
.cs_change = 1,
},
};
struct spi_message msg;
u8 *tx2;
u8 *tx = kmalloc(2, GFP_KERNEL);
if (tx == NULL) {
ret = -ENOMEM;
goto error_ret;
}
tx2 = kmalloc(2, GFP_KERNEL);
if (tx2 == NULL) {
ret = -ENOMEM;
goto error_free_tx;
}
tx[0] = 0x0d;
tx[1] = 0x40;
tx2[0] = 0x0c;
tx2[1] = 0x9b;
xfers[0].tx_buf = tx;
xfers[1].tx_buf = tx2;
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(spi, &msg);
kfree(tx2);
error_free_tx:
kfree(tx);
error_ret:
return ret;
}
static int __devinit kxsd9_probe(struct spi_device *spi)
{
struct kxsd9_state *st;
int ret = 0;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
st->rx = kmalloc(sizeof(*st->rx)*KXSD9_STATE_RX_SIZE,
GFP_KERNEL);
if (st->rx == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->tx = kmalloc(sizeof(*st->tx)*KXSD9_STATE_TX_SIZE,
GFP_KERNEL);
if (st->tx == NULL) {
ret = -ENOMEM;
goto error_free_rx;
}
st->us = spi;
mutex_init(&st->buf_lock);
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_tx;
}
st->indio_dev->dev.parent = &spi->dev;
st->indio_dev->info = &kxsd9_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_dev;
spi->mode = SPI_MODE_0;
spi_setup(spi);
kxsd9_power_up(spi);
return 0;
error_free_dev:
iio_free_device(st->indio_dev);
error_free_tx:
kfree(st->tx);
error_free_rx:
kfree(st->rx);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int __devexit kxsd9_remove(struct spi_device *spi)
{
struct kxsd9_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->indio_dev);
kfree(st->tx);
kfree(st->rx);
kfree(st);
return 0;
}
static __init int kxsd9_spi_init(void)
{
return spi_register_driver(&kxsd9_driver);
}
static __exit void kxsd9_spi_exit(void)
{
spi_unregister_driver(&kxsd9_driver);
}
