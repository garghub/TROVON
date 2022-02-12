static int pcm3168a_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
regmap = devm_regmap_init_spi(spi, &pcm3168a_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return pcm3168a_probe(&spi->dev, regmap);
}
static int pcm3168a_spi_remove(struct spi_device *spi)
{
pcm3168a_remove(&spi->dev);
return 0;
}
