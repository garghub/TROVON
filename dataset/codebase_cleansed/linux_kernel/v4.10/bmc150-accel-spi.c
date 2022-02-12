static int bmc150_accel_probe(struct spi_device *spi)
{
struct regmap *regmap;
const struct spi_device_id *id = spi_get_device_id(spi);
regmap = devm_regmap_init_spi(spi, &bmc150_regmap_conf);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "Failed to initialize spi regmap\n");
return PTR_ERR(regmap);
}
return bmc150_accel_core_probe(&spi->dev, regmap, spi->irq, id->name,
true);
}
static int bmc150_accel_remove(struct spi_device *spi)
{
return bmc150_accel_core_remove(&spi->dev);
}
