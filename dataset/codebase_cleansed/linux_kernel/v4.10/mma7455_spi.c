static int mma7455_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct regmap *regmap;
regmap = devm_regmap_init_spi(spi, &mma7455_core_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return mma7455_core_probe(&spi->dev, regmap, id->name);
}
static int mma7455_spi_remove(struct spi_device *spi)
{
return mma7455_core_remove(&spi->dev);
}
