static int ssm2602_spi_probe(struct spi_device *spi)
{
return ssm2602_probe(&spi->dev, SSM2602,
devm_regmap_init_spi(spi, &ssm2602_regmap_config));
}
static int ssm2602_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
