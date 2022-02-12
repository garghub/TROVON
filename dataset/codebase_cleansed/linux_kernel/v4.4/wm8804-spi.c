static int wm8804_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
regmap = devm_regmap_init_spi(spi, &wm8804_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return wm8804_probe(&spi->dev, regmap);
}
static int wm8804_spi_remove(struct spi_device *spi)
{
wm8804_remove(&spi->dev);
return 0;
}
