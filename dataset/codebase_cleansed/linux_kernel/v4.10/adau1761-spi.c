static void adau1761_spi_switch_mode(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
spi_w8r8(spi, 0x00);
spi_w8r8(spi, 0x00);
spi_w8r8(spi, 0x00);
}
static int adau1761_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct regmap_config config;
if (!id)
return -EINVAL;
config = adau1761_regmap_config;
config.val_bits = 8;
config.reg_bits = 24;
config.read_flag_mask = 0x1;
return adau1761_probe(&spi->dev,
devm_regmap_init_spi(spi, &config),
id->driver_data, adau1761_spi_switch_mode);
}
static int adau1761_spi_remove(struct spi_device *spi)
{
adau17x1_remove(&spi->dev);
return 0;
}
