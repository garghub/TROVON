static int es8328_spi_probe(struct spi_device *spi)
{
return es8328_probe(&spi->dev,
devm_regmap_init_spi(spi, &es8328_regmap_config));
}
static int es8328_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
