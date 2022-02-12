static int cs4271_spi_probe(struct spi_device *spi)
{
struct regmap_config config;
config = cs4271_regmap_config;
config.reg_bits = 16;
config.val_bits = 8;
config.read_flag_mask = 0x21;
config.write_flag_mask = 0x20;
return cs4271_probe(&spi->dev, devm_regmap_init_spi(spi, &config));
}
static int cs4271_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
