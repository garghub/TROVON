static int bmp280_regmap_spi_write(void *context, const void *data,
size_t count)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
u8 buf[2];
memcpy(buf, data, 2);
buf[0] &= ~0x80;
return spi_write_then_read(spi, buf, 2, NULL, 0);
}
static int bmp280_regmap_spi_read(void *context, const void *reg,
size_t reg_size, void *val, size_t val_size)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
return spi_write_then_read(spi, reg, reg_size, val, val_size);
}
static int bmp280_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct regmap *regmap;
const struct regmap_config *regmap_config;
int ret;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(&spi->dev, "spi_setup failed!\n");
return ret;
}
switch (id->driver_data) {
case BMP180_CHIP_ID:
regmap_config = &bmp180_regmap_config;
break;
case BMP280_CHIP_ID:
case BME280_CHIP_ID:
regmap_config = &bmp280_regmap_config;
break;
default:
return -EINVAL;
}
regmap = devm_regmap_init(&spi->dev,
&bmp280_regmap_bus,
&spi->dev,
regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
return bmp280_common_probe(&spi->dev,
regmap,
id->driver_data,
id->name,
spi->irq);
}
static int bmp280_spi_remove(struct spi_device *spi)
{
return bmp280_common_remove(&spi->dev);
}
