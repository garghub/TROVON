static int mc33880_write_config(struct mc33880 *mc)
{
return spi_write(mc->spi, &mc->port_config, sizeof(mc->port_config));
}
static int __mc33880_set(struct mc33880 *mc, unsigned offset, int value)
{
if (value)
mc->port_config |= 1 << offset;
else
mc->port_config &= ~(1 << offset);
return mc33880_write_config(mc);
}
static void mc33880_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct mc33880 *mc = container_of(chip, struct mc33880, chip);
mutex_lock(&mc->lock);
__mc33880_set(mc, offset, value);
mutex_unlock(&mc->lock);
}
static int mc33880_probe(struct spi_device *spi)
{
struct mc33880 *mc;
struct mc33880_platform_data *pdata;
int ret;
pdata = dev_get_platdata(&spi->dev);
if (!pdata || !pdata->base) {
dev_dbg(&spi->dev, "incorrect or missing platform data\n");
return -EINVAL;
}
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret < 0)
return ret;
mc = devm_kzalloc(&spi->dev, sizeof(struct mc33880), GFP_KERNEL);
if (!mc)
return -ENOMEM;
mutex_init(&mc->lock);
spi_set_drvdata(spi, mc);
mc->spi = spi;
mc->chip.label = DRIVER_NAME,
mc->chip.set = mc33880_set;
mc->chip.base = pdata->base;
mc->chip.ngpio = PIN_NUMBER;
mc->chip.can_sleep = 1;
mc->chip.dev = &spi->dev;
mc->chip.owner = THIS_MODULE;
mc->port_config = 0x00;
ret = mc33880_write_config(mc);
mc->port_config = 0x00;
if (!ret)
ret = mc33880_write_config(mc);
if (ret) {
dev_err(&spi->dev, "Failed writing to " DRIVER_NAME ": %d\n",
ret);
goto exit_destroy;
}
ret = gpiochip_add(&mc->chip);
if (ret)
goto exit_destroy;
return ret;
exit_destroy:
mutex_destroy(&mc->lock);
return ret;
}
static int mc33880_remove(struct spi_device *spi)
{
struct mc33880 *mc;
int ret;
mc = spi_get_drvdata(spi);
if (mc == NULL)
return -ENODEV;
ret = gpiochip_remove(&mc->chip);
if (!ret)
mutex_destroy(&mc->lock);
else
dev_err(&spi->dev, "Failed to remove the GPIO controller: %d\n",
ret);
return ret;
}
static int __init mc33880_init(void)
{
return spi_register_driver(&mc33880_driver);
}
static void __exit mc33880_exit(void)
{
spi_unregister_driver(&mc33880_driver);
}
