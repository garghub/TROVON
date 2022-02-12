static int pcm179x_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_spi(spi, &pcm179x_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&spi->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
return pcm179x_common_init(&spi->dev, regmap);
}
static int pcm179x_spi_remove(struct spi_device *spi)
{
return pcm179x_common_exit(&spi->dev);
}
