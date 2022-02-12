static int pisosr_gpio_refresh(struct pisosr_gpio *gpio)
{
int ret;
mutex_lock(&gpio->lock);
if (gpio->load_gpio) {
gpiod_set_value_cansleep(gpio->load_gpio, 1);
udelay(1);
gpiod_set_value_cansleep(gpio->load_gpio, 0);
udelay(1);
}
ret = spi_read(gpio->spi, gpio->buffer, gpio->buffer_size);
mutex_unlock(&gpio->lock);
return ret;
}
static int pisosr_gpio_get_direction(struct gpio_chip *chip,
unsigned offset)
{
return 1;
}
static int pisosr_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return 0;
}
static int pisosr_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
return -EINVAL;
}
static int pisosr_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct pisosr_gpio *gpio = gpiochip_get_data(chip);
pisosr_gpio_refresh(gpio);
return (gpio->buffer[offset / 8] >> (offset % 8)) & 0x1;
}
static int pisosr_gpio_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
struct pisosr_gpio *gpio;
int ret;
gpio = devm_kzalloc(dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
spi_set_drvdata(spi, gpio);
gpio->chip = template_chip;
gpio->chip.parent = dev;
of_property_read_u16(dev->of_node, "ngpios", &gpio->chip.ngpio);
gpio->spi = spi;
gpio->buffer_size = DIV_ROUND_UP(gpio->chip.ngpio, 8);
gpio->buffer = devm_kzalloc(dev, gpio->buffer_size, GFP_KERNEL);
if (!gpio->buffer)
return -ENOMEM;
gpio->load_gpio = devm_gpiod_get_optional(dev, "load", GPIOD_OUT_LOW);
if (IS_ERR(gpio->load_gpio)) {
ret = PTR_ERR(gpio->load_gpio);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Unable to allocate load GPIO\n");
return ret;
}
mutex_init(&gpio->lock);
ret = gpiochip_add_data(&gpio->chip, gpio);
if (ret < 0) {
dev_err(dev, "Unable to register gpiochip\n");
return ret;
}
return 0;
}
static int pisosr_gpio_remove(struct spi_device *spi)
{
struct pisosr_gpio *gpio = spi_get_drvdata(spi);
gpiochip_remove(&gpio->chip);
mutex_destroy(&gpio->lock);
return 0;
}
