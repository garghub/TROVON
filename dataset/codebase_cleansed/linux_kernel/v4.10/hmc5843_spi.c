static int hmc5843_spi_probe(struct spi_device *spi)
{
int ret;
const struct spi_device_id *id = spi_get_device_id(spi);
spi->mode = SPI_MODE_3;
spi->max_speed_hz = 8000000;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret)
return ret;
return hmc5843_common_probe(&spi->dev,
devm_regmap_init_spi(spi, &hmc5843_spi_regmap_config),
id->driver_data, id->name);
}
static int hmc5843_spi_remove(struct spi_device *spi)
{
return hmc5843_common_remove(&spi->dev);
}
