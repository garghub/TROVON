static int wm831x_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct wm831x *wm831x;
enum wm831x_parent type;
int ret;
type = (enum wm831x_parent)id->driver_data;
wm831x = devm_kzalloc(&spi->dev, sizeof(struct wm831x), GFP_KERNEL);
if (wm831x == NULL)
return -ENOMEM;
spi->bits_per_word = 16;
spi->mode = SPI_MODE_0;
dev_set_drvdata(&spi->dev, wm831x);
wm831x->dev = &spi->dev;
wm831x->regmap = devm_regmap_init_spi(spi, &wm831x_regmap_config);
if (IS_ERR(wm831x->regmap)) {
ret = PTR_ERR(wm831x->regmap);
dev_err(wm831x->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
return wm831x_device_init(wm831x, type, spi->irq);
}
static int wm831x_spi_remove(struct spi_device *spi)
{
struct wm831x *wm831x = dev_get_drvdata(&spi->dev);
wm831x_device_exit(wm831x);
return 0;
}
static int wm831x_spi_suspend(struct device *dev)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
return wm831x_device_suspend(wm831x);
}
static void wm831x_spi_shutdown(struct spi_device *spi)
{
struct wm831x *wm831x = dev_get_drvdata(&spi->dev);
wm831x_device_shutdown(wm831x);
}
static int __init wm831x_spi_init(void)
{
int ret;
ret = spi_register_driver(&wm831x_spi_driver);
if (ret != 0)
pr_err("Failed to register WM831x SPI driver: %d\n", ret);
return 0;
}
static void __exit wm831x_spi_exit(void)
{
spi_unregister_driver(&wm831x_spi_driver);
}
