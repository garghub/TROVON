static int zpa2326_probe_spi(struct spi_device *spi)
{
struct regmap *regmap;
int err;
regmap = devm_regmap_init_spi(spi, &zpa2326_regmap_spi_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "failed to init registers map");
return PTR_ERR(regmap);
}
spi->mode = SPI_MODE_3;
spi->max_speed_hz = min(spi->max_speed_hz, 1000000U);
spi->bits_per_word = 8;
err = spi_setup(spi);
if (err < 0)
return err;
return zpa2326_probe(&spi->dev, spi_get_device_id(spi)->name,
spi->irq, ZPA2326_DEVICE_ID, regmap);
}
static int zpa2326_remove_spi(struct spi_device *spi)
{
zpa2326_remove(&spi->dev);
return 0;
}
