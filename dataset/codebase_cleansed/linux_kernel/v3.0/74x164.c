static struct gen_74x164_chip *gpio_to_chip(struct gpio_chip *gc)
{
return container_of(gc, struct gen_74x164_chip, gpio_chip);
}
static int __gen_74x164_write_config(struct gen_74x164_chip *chip)
{
return spi_write(chip->spi,
&chip->port_config, sizeof(chip->port_config));
}
static int gen_74x164_direction_output(struct gpio_chip *gc,
unsigned offset, int val)
{
gen_74x164_set_value(gc, offset, val);
return 0;
}
static int gen_74x164_get_value(struct gpio_chip *gc, unsigned offset)
{
struct gen_74x164_chip *chip = gpio_to_chip(gc);
int ret;
mutex_lock(&chip->lock);
ret = (chip->port_config >> offset) & 0x1;
mutex_unlock(&chip->lock);
return ret;
}
static void gen_74x164_set_value(struct gpio_chip *gc,
unsigned offset, int val)
{
struct gen_74x164_chip *chip = gpio_to_chip(gc);
mutex_lock(&chip->lock);
if (val)
chip->port_config |= (1 << offset);
else
chip->port_config &= ~(1 << offset);
__gen_74x164_write_config(chip);
mutex_unlock(&chip->lock);
}
static int __devinit gen_74x164_probe(struct spi_device *spi)
{
struct gen_74x164_chip *chip;
struct gen_74x164_chip_platform_data *pdata;
int ret;
pdata = spi->dev.platform_data;
if (!pdata || !pdata->base) {
dev_dbg(&spi->dev, "incorrect or missing platform data\n");
return -EINVAL;
}
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret < 0)
return ret;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
mutex_init(&chip->lock);
dev_set_drvdata(&spi->dev, chip);
chip->spi = spi;
chip->gpio_chip.label = GEN_74X164_DRIVER_NAME,
chip->gpio_chip.direction_output = gen_74x164_direction_output;
chip->gpio_chip.get = gen_74x164_get_value;
chip->gpio_chip.set = gen_74x164_set_value;
chip->gpio_chip.base = pdata->base;
chip->gpio_chip.ngpio = GEN_74X164_GPIO_COUNT;
chip->gpio_chip.can_sleep = 1;
chip->gpio_chip.dev = &spi->dev;
chip->gpio_chip.owner = THIS_MODULE;
ret = __gen_74x164_write_config(chip);
if (ret) {
dev_err(&spi->dev, "Failed writing: %d\n", ret);
goto exit_destroy;
}
ret = gpiochip_add(&chip->gpio_chip);
if (ret)
goto exit_destroy;
return ret;
exit_destroy:
dev_set_drvdata(&spi->dev, NULL);
mutex_destroy(&chip->lock);
kfree(chip);
return ret;
}
static int __devexit gen_74x164_remove(struct spi_device *spi)
{
struct gen_74x164_chip *chip;
int ret;
chip = dev_get_drvdata(&spi->dev);
if (chip == NULL)
return -ENODEV;
dev_set_drvdata(&spi->dev, NULL);
ret = gpiochip_remove(&chip->gpio_chip);
if (!ret) {
mutex_destroy(&chip->lock);
kfree(chip);
} else
dev_err(&spi->dev, "Failed to remove the GPIO controller: %d\n",
ret);
return ret;
}
static int __init gen_74x164_init(void)
{
return spi_register_driver(&gen_74x164_driver);
}
static void __exit gen_74x164_exit(void)
{
spi_unregister_driver(&gen_74x164_driver);
}
