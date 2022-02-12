static int adav80x_spi_probe(struct spi_device *spi)
{
struct regmap_config config;
config = adav80x_regmap_config;
config.read_flag_mask = 0x01;
return adav80x_bus_probe(&spi->dev, devm_regmap_init_spi(spi, &config));
}
static int adav80x_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
