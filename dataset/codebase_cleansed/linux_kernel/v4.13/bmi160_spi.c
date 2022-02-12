static int bmi160_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
const struct spi_device_id *id = spi_get_device_id(spi);
regmap = devm_regmap_init_spi(spi, &bmi160_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "Failed to register spi regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return bmi160_core_probe(&spi->dev, regmap, id->name, true);
}
static int bmi160_spi_remove(struct spi_device *spi)
{
bmi160_core_remove(&spi->dev);
return 0;
}
