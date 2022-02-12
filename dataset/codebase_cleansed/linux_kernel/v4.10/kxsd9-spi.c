static int kxsd9_spi_probe(struct spi_device *spi)
{
static const struct regmap_config config = {
.reg_bits = 8,
.val_bits = 8,
.max_register = 0x0e,
};
struct regmap *regmap;
spi->mode = SPI_MODE_0;
regmap = devm_regmap_init_spi(spi, &config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "%s: regmap allocation failed: %ld\n",
__func__, PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return kxsd9_common_probe(&spi->dev,
regmap,
spi_get_device_id(spi)->name);
}
static int kxsd9_spi_remove(struct spi_device *spi)
{
return kxsd9_common_remove(&spi->dev);
}
