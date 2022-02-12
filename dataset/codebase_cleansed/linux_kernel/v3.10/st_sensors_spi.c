static unsigned int st_sensors_spi_get_irq(struct iio_dev *indio_dev)
{
struct st_sensor_data *sdata = iio_priv(indio_dev);
return to_spi_device(sdata->dev)->irq;
}
static int st_sensors_spi_read(struct st_sensor_transfer_buffer *tb,
struct device *dev, u8 reg_addr, int len, u8 *data, bool multiread_bit)
{
int err;
struct spi_transfer xfers[] = {
{
.tx_buf = tb->tx_buf,
.bits_per_word = 8,
.len = 1,
},
{
.rx_buf = tb->rx_buf,
.bits_per_word = 8,
.len = len,
}
};
mutex_lock(&tb->buf_lock);
if ((multiread_bit) && (len > 1))
tb->tx_buf[0] = reg_addr | ST_SENSORS_SPI_MULTIREAD;
else
tb->tx_buf[0] = reg_addr | ST_SENSORS_SPI_READ;
err = spi_sync_transfer(to_spi_device(dev), xfers, ARRAY_SIZE(xfers));
if (err)
goto acc_spi_read_error;
memcpy(data, tb->rx_buf, len*sizeof(u8));
mutex_unlock(&tb->buf_lock);
return len;
acc_spi_read_error:
mutex_unlock(&tb->buf_lock);
return err;
}
static int st_sensors_spi_read_byte(struct st_sensor_transfer_buffer *tb,
struct device *dev, u8 reg_addr, u8 *res_byte)
{
return st_sensors_spi_read(tb, dev, reg_addr, 1, res_byte, false);
}
static int st_sensors_spi_read_multiple_byte(
struct st_sensor_transfer_buffer *tb, struct device *dev,
u8 reg_addr, int len, u8 *data, bool multiread_bit)
{
return st_sensors_spi_read(tb, dev, reg_addr, len, data, multiread_bit);
}
static int st_sensors_spi_write_byte(struct st_sensor_transfer_buffer *tb,
struct device *dev, u8 reg_addr, u8 data)
{
int err;
struct spi_transfer xfers = {
.tx_buf = tb->tx_buf,
.bits_per_word = 8,
.len = 2,
};
mutex_lock(&tb->buf_lock);
tb->tx_buf[0] = reg_addr;
tb->tx_buf[1] = data;
err = spi_sync_transfer(to_spi_device(dev), &xfers, 1);
mutex_unlock(&tb->buf_lock);
return err;
}
void st_sensors_spi_configure(struct iio_dev *indio_dev,
struct spi_device *spi, struct st_sensor_data *sdata)
{
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi->modalias;
sdata->tf = &st_sensors_tf_spi;
sdata->get_irq_data_ready = st_sensors_spi_get_irq;
}
