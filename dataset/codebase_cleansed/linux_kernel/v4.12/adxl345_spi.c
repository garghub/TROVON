static int adxl345_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct regmap *regmap;
if (spi->max_speed_hz > ADXL345_MAX_SPI_FREQ_HZ) {
dev_err(&spi->dev, "SPI CLK, %d Hz exceeds 5 MHz\n",
spi->max_speed_hz);
return -EINVAL;
}
regmap = devm_regmap_init_spi(spi, &adxl345_spi_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "Error initializing spi regmap: %ld\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return adxl345_core_probe(&spi->dev, regmap, id->name);
}
static int adxl345_spi_remove(struct spi_device *spi)
{
return adxl345_core_remove(&spi->dev);
}
