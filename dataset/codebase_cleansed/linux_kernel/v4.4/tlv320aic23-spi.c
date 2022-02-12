static int aic23_spi_probe(struct spi_device *spi)
{
int ret;
struct regmap *regmap;
dev_dbg(&spi->dev, "probing tlv320aic23 spi device\n");
spi->mode = SPI_MODE_0;
ret = spi_setup(spi);
if (ret < 0)
return ret;
regmap = devm_regmap_init_spi(spi, &tlv320aic23_regmap);
return tlv320aic23_probe(&spi->dev, regmap);
}
static int aic23_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
