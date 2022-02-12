static int ad7879_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
if (spi->max_speed_hz > MAX_SPI_FREQ_HZ) {
dev_err(&spi->dev, "SPI CLK %d Hz?\n", spi->max_speed_hz);
return -EINVAL;
}
regmap = devm_regmap_init_spi(spi, &ad7879_spi_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return ad7879_probe(&spi->dev, regmap, spi->irq, BUS_SPI, AD7879_DEVID);
}
