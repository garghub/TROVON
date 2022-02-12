static int arizona_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct arizona *arizona;
const struct regmap_config *regmap_config;
int ret;
switch (id->driver_data) {
#ifdef CONFIG_MFD_WM5102
case WM5102:
regmap_config = &wm5102_spi_regmap;
break;
#endif
#ifdef CONFIG_MFD_WM5110
case WM5110:
regmap_config = &wm5110_spi_regmap;
break;
#endif
default:
dev_err(&spi->dev, "Unknown device type %ld\n",
id->driver_data);
return -EINVAL;
}
arizona = devm_kzalloc(&spi->dev, sizeof(*arizona), GFP_KERNEL);
if (arizona == NULL)
return -ENOMEM;
arizona->regmap = devm_regmap_init_spi(spi, regmap_config);
if (IS_ERR(arizona->regmap)) {
ret = PTR_ERR(arizona->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
arizona->type = id->driver_data;
arizona->dev = &spi->dev;
arizona->irq = spi->irq;
return arizona_dev_init(arizona);
}
static int arizona_spi_remove(struct spi_device *spi)
{
struct arizona *arizona = spi_get_drvdata(spi);
arizona_dev_exit(arizona);
return 0;
}
