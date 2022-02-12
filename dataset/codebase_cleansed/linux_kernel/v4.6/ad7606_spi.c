static int ad7606_spi_read_block(struct device *dev,
int count, void *buf)
{
struct spi_device *spi = to_spi_device(dev);
int i, ret;
unsigned short *data = buf;
ret = spi_read(spi, buf, count * 2);
if (ret < 0) {
dev_err(&spi->dev, "SPI read error\n");
return ret;
}
for (i = 0; i < count; i++)
data[i] = be16_to_cpu(data[i]);
return 0;
}
static int ad7606_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
indio_dev = ad7606_probe(&spi->dev, spi->irq, NULL,
spi_get_device_id(spi)->driver_data,
&ad7606_spi_bops);
if (IS_ERR(indio_dev))
return PTR_ERR(indio_dev);
spi_set_drvdata(spi, indio_dev);
return 0;
}
static int ad7606_spi_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = dev_get_drvdata(&spi->dev);
return ad7606_remove(indio_dev, spi->irq);
}
