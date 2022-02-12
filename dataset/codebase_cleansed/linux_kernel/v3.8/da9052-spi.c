static int da9052_spi_probe(struct spi_device *spi)
{
int ret;
const struct spi_device_id *id = spi_get_device_id(spi);
struct da9052 *da9052;
da9052 = devm_kzalloc(&spi->dev, sizeof(struct da9052), GFP_KERNEL);
if (!da9052)
return -ENOMEM;
spi->mode = SPI_MODE_0 | SPI_CPOL;
spi->bits_per_word = 8;
spi_setup(spi);
da9052->dev = &spi->dev;
da9052->chip_irq = spi->irq;
dev_set_drvdata(&spi->dev, da9052);
da9052_regmap_config.read_flag_mask = 1;
da9052_regmap_config.write_flag_mask = 0;
da9052->regmap = devm_regmap_init_spi(spi, &da9052_regmap_config);
if (IS_ERR(da9052->regmap)) {
ret = PTR_ERR(da9052->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = da9052_device_init(da9052, id->driver_data);
if (ret != 0)
return ret;
return 0;
}
static int da9052_spi_remove(struct spi_device *spi)
{
struct da9052 *da9052 = dev_get_drvdata(&spi->dev);
da9052_device_exit(da9052);
return 0;
}
static int __init da9052_spi_init(void)
{
int ret;
ret = spi_register_driver(&da9052_spi_driver);
if (ret != 0) {
pr_err("Failed to register DA9052 SPI driver, %d\n", ret);
return ret;
}
return 0;
}
static void __exit da9052_spi_exit(void)
{
spi_unregister_driver(&da9052_spi_driver);
}
