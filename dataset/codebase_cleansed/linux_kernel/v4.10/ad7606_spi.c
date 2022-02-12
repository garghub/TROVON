static int ad7606_spi_read_block(struct device *dev,
int count, void *buf)
{
struct spi_device *spi = to_spi_device(dev);
int i, ret;
unsigned short *data = buf;
__be16 *bdata = buf;
ret = spi_read(spi, buf, count * 2);
if (ret < 0) {
dev_err(&spi->dev, "SPI read error\n");
return ret;
}
for (i = 0; i < count; i++)
data[i] = be16_to_cpu(bdata[i]);
return 0;
}
static int ad7606_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
return ad7606_probe(&spi->dev, spi->irq, NULL,
id->name, id->driver_data,
&ad7606_spi_bops);
}
static int ad7606_spi_remove(struct spi_device *spi)
{
return ad7606_remove(&spi->dev, spi->irq);
}
