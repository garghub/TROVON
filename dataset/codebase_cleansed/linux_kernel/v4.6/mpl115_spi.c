static int mpl115_spi_init(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct mpl115_spi_buf *buf;
buf = devm_kzalloc(dev, sizeof(*buf), GFP_KERNEL);
if (!buf)
return -ENOMEM;
spi_set_drvdata(spi, buf);
return 0;
}
static int mpl115_spi_read(struct device *dev, u8 address)
{
struct spi_device *spi = to_spi_device(dev);
struct mpl115_spi_buf *buf = spi_get_drvdata(spi);
struct spi_transfer xfer = {
.tx_buf = buf->tx,
.rx_buf = buf->rx,
.len = 4,
};
int ret;
buf->tx[0] = MPL115_SPI_READ(address);
buf->tx[2] = MPL115_SPI_READ(address + 1);
ret = spi_sync_transfer(spi, &xfer, 1);
if (ret)
return ret;
return (buf->rx[1] << 8) | buf->rx[3];
}
static int mpl115_spi_write(struct device *dev, u8 address, u8 value)
{
struct spi_device *spi = to_spi_device(dev);
struct mpl115_spi_buf *buf = spi_get_drvdata(spi);
struct spi_transfer xfer = {
.tx_buf = buf->tx,
.len = 2,
};
buf->tx[0] = MPL115_SPI_WRITE(address);
buf->tx[1] = value;
return spi_sync_transfer(spi, &xfer, 1);
}
static int mpl115_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
return mpl115_probe(&spi->dev, id->name, &mpl115_spi_ops);
}
