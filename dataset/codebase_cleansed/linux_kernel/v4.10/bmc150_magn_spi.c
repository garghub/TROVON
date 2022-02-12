static int bmc150_magn_spi_probe(struct spi_device *spi)
{
struct regmap *regmap;
const struct spi_device_id *id = spi_get_device_id(spi);
regmap = devm_regmap_init_spi(spi, &bmc150_magn_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "Failed to register spi regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return bmc150_magn_probe(&spi->dev, regmap, spi->irq, id->name);
}
static int bmc150_magn_spi_remove(struct spi_device *spi)
{
bmc150_magn_remove(&spi->dev);
return 0;
}
