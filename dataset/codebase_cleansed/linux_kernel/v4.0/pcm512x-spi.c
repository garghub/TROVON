static int pcm512x_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_spi(spi, &pcm512x_regmap);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
return ret;
}
return pcm512x_probe(&spi->dev, regmap);
}
static int pcm512x_spi_remove(struct spi_device *spi)
{
pcm512x_remove(&spi->dev);
return 0;
}
