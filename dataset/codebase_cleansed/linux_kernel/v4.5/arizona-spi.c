static int arizona_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct arizona *arizona;
const struct regmap_config *regmap_config = NULL;
unsigned long type;
int ret;
if (spi->dev.of_node)
type = arizona_of_get_type(&spi->dev);
else
type = id->driver_data;
switch (type) {
case WM5102:
if (IS_ENABLED(CONFIG_MFD_WM5102))
regmap_config = &wm5102_spi_regmap;
break;
case WM5110:
case WM8280:
if (IS_ENABLED(CONFIG_MFD_WM5110))
regmap_config = &wm5110_spi_regmap;
break;
case WM1831:
case CS47L24:
if (IS_ENABLED(CONFIG_MFD_CS47L24))
regmap_config = &cs47l24_spi_regmap;
break;
default:
dev_err(&spi->dev, "Unknown device type %ld\n", type);
return -EINVAL;
}
if (!regmap_config) {
dev_err(&spi->dev,
"No kernel support for device type %ld\n", type);
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
arizona->type = type;
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
