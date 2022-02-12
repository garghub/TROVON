static int aic32x4_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
struct regmap_config config;
config = aic32x4_regmap_config;
config.reg_bits = 7;
config.pad_bits = 1;
config.val_bits = 8;
config.read_flag_mask = 0x01;
regmap = devm_regmap_init_spi(spi, &config);
return aic32x4_probe(&spi->dev, regmap);
}
static int aic32x4_spi_remove(struct spi_device *spi)
{
return aic32x4_remove(&spi->dev);
}
