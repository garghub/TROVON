static int kxsd9_write_scale(struct iio_dev *indio_dev, int micro)
{
int ret, i;
struct kxsd9_state *st = iio_priv(indio_dev);
bool foundit = false;
for (i = 0; i < 4; i++)
if (micro == kxsd9_micro_scales[i]) {
foundit = true;
break;
}
if (!foundit)
return -EINVAL;
mutex_lock(&st->buf_lock);
ret = spi_w8r8(st->us, KXSD9_READ(KXSD9_REG_CTRL_C));
if (ret)
goto error_ret;
st->tx[0] = KXSD9_WRITE(KXSD9_REG_CTRL_C);
st->tx[1] = (ret & ~KXSD9_FS_MASK) | i;
ret = spi_write(st->us, st->tx, 2);
error_ret:
mutex_unlock(&st->buf_lock);
return ret;
}
static int kxsd9_read(struct iio_dev *indio_dev, u8 address)
{
struct spi_message msg;
int ret;
struct kxsd9_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.bits_per_word = 8,
.len = 1,
.delay_usecs = 200,
.tx_buf = st->tx,
}, {
.bits_per_word = 8,
.len = 2,
.rx_buf = st->rx,
},
};
mutex_lock(&st->buf_lock);
st->tx[0] = KXSD9_READ(address);
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(st->us, &msg);
if (ret)
return ret;
return (((u16)(st->rx[0])) << 8) | (st->rx[1] & 0xF0);
}
static int kxsd9_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int ret = -EINVAL;
if (mask == IIO_CHAN_INFO_SCALE) {
if (val)
return -EINVAL;
ret = kxsd9_write_scale(indio_dev, val2);
}
return ret;
}
static int kxsd9_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret = -EINVAL;
struct kxsd9_state *st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = kxsd9_read(indio_dev, chan->address);
if (ret < 0)
goto error_ret;
*val = ret;
break;
case IIO_CHAN_INFO_SCALE:
ret = spi_w8r8(st->us, KXSD9_READ(KXSD9_REG_CTRL_C));
if (ret)
goto error_ret;
*val2 = kxsd9_micro_scales[ret & KXSD9_FS_MASK];
ret = IIO_VAL_INT_PLUS_MICRO;
break;
};
error_ret:
return ret;
}
static int __devinit kxsd9_power_up(struct kxsd9_state *st)
{
int ret;
st->tx[0] = 0x0d;
st->tx[1] = 0x40;
ret = spi_write(st->us, st->tx, 2);
if (ret)
return ret;
st->tx[0] = 0x0c;
st->tx[1] = 0x9b;
return spi_write(st->us, st->tx, 2);
}
static int __devinit kxsd9_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct kxsd9_state *st;
int ret = 0;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->channels = kxsd9_channels;
indio_dev->num_channels = ARRAY_SIZE(kxsd9_channels);
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &kxsd9_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
spi->mode = SPI_MODE_0;
spi_setup(spi);
kxsd9_power_up(st);
return 0;
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int __devexit kxsd9_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
iio_device_free(spi_get_drvdata(spi));
return 0;
}
