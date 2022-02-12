static int st_lsm6dsx_spi_read(struct device *dev, u8 addr, int len,
u8 *data)
{
struct spi_device *spi = to_spi_device(dev);
struct st_lsm6dsx_hw *hw = spi_get_drvdata(spi);
int err;
struct spi_transfer xfers[] = {
{
.tx_buf = hw->tb.tx_buf,
.bits_per_word = 8,
.len = 1,
},
{
.rx_buf = hw->tb.rx_buf,
.bits_per_word = 8,
.len = len,
}
};
hw->tb.tx_buf[0] = addr | SENSORS_SPI_READ;
err = spi_sync_transfer(spi, xfers, ARRAY_SIZE(xfers));
if (err < 0)
return err;
memcpy(data, hw->tb.rx_buf, len * sizeof(u8));
return len;
}
static int st_lsm6dsx_spi_write(struct device *dev, u8 addr, int len,
u8 *data)
{
struct st_lsm6dsx_hw *hw;
struct spi_device *spi;
if (len >= ST_LSM6DSX_TX_MAX_LENGTH)
return -ENOMEM;
spi = to_spi_device(dev);
hw = spi_get_drvdata(spi);
hw->tb.tx_buf[0] = addr;
memcpy(&hw->tb.tx_buf[1], data, len);
return spi_write(spi, hw->tb.tx_buf, len + 1);
}
static int st_lsm6dsx_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
return st_lsm6dsx_probe(&spi->dev, spi->irq,
(int)id->driver_data,
&st_lsm6dsx_transfer_fn);
}
