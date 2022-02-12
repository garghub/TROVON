static int ad193x_spi_probe(struct spi_device *spi)
{
struct regmap_config config;
config = ad193x_regmap_config;
config.val_bits = 8;
config.reg_bits = 16;
config.read_flag_mask = 0x09;
config.write_flag_mask = 0x08;
return ad193x_probe(&spi->dev, devm_regmap_init_spi(spi, &config));
}
static int ad193x_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
