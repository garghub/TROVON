static int tps65912_spi_probe(struct spi_device *spi)
{
struct tps65912 *tps;
tps = devm_kzalloc(&spi->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
spi_set_drvdata(spi, tps);
tps->dev = &spi->dev;
tps->irq = spi->irq;
tps->regmap = devm_regmap_init_spi(spi, &tps65912_regmap_config);
if (IS_ERR(tps->regmap)) {
dev_err(tps->dev, "Failed to initialize register map\n");
return PTR_ERR(tps->regmap);
}
return tps65912_device_init(tps);
}
static int tps65912_spi_remove(struct spi_device *spi)
{
struct tps65912 *tps = spi_get_drvdata(spi);
return tps65912_device_exit(tps);
}
