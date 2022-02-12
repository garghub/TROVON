static int max3107_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct max3107_port *s = container_of(chip, struct max3107_port, chip);
u16 buf[1];
if (offset >= MAX3107_GPIO_COUNT) {
dev_err(&s->spi->dev, "Invalid GPIO\n");
return -EINVAL;
}
buf[0] = MAX3107_GPIOCFG_REG;
if (max3107_rw(s, (u8 *)buf, (u8 *)buf, 2)) {
dev_err(&s->spi->dev, "SPI transfer GPIO read failed\n");
return -EIO;
}
buf[0] &= MAX3107_SPI_RX_DATA_MASK;
buf[0] &= ~(0x0001 << offset);
buf[0] |= (MAX3107_WRITE_BIT | MAX3107_GPIOCFG_REG);
if (max3107_rw(s, (u8 *)buf, NULL, 2)) {
dev_err(&s->spi->dev, "SPI transfer GPIO write failed\n");
return -EIO;
}
return 0;
}
static int max3107_gpio_direction_out(struct gpio_chip *chip, unsigned offset,
int value)
{
struct max3107_port *s = container_of(chip, struct max3107_port, chip);
u16 buf[2];
if (offset >= MAX3107_GPIO_COUNT) {
dev_err(&s->spi->dev, "Invalid GPIO\n");
return -EINVAL;
}
buf[0] = MAX3107_GPIOCFG_REG;
buf[1] = MAX3107_GPIODATA_REG;
if (max3107_rw(s, (u8 *)buf, (u8 *)buf, 4)) {
dev_err(&s->spi->dev, "SPI transfer gpio failed\n");
return -EIO;
}
buf[0] &= MAX3107_SPI_RX_DATA_MASK;
buf[1] &= MAX3107_SPI_RX_DATA_MASK;
buf[0] |= (0x0001 << offset);
if (value)
buf[1] |= (0x0001 << offset);
else
buf[1] &= ~(0x0001 << offset);
buf[0] |= (MAX3107_WRITE_BIT | MAX3107_GPIOCFG_REG);
buf[1] |= (MAX3107_WRITE_BIT | MAX3107_GPIODATA_REG);
if (max3107_rw(s, (u8 *)buf, NULL, 4)) {
dev_err(&s->spi->dev,
"SPI transfer for GPIO conf data w failed\n");
return -EIO;
}
return 0;
}
static int max3107_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct max3107_port *s = container_of(chip, struct max3107_port, chip);
u16 buf[1];
if (offset >= MAX3107_GPIO_COUNT) {
dev_err(&s->spi->dev, "Invalid GPIO\n");
return -EINVAL;
}
buf[0] = MAX3107_GPIODATA_REG;
if (max3107_rw(s, (u8 *)buf, (u8 *)buf, 2)) {
dev_err(&s->spi->dev, "SPI transfer GPIO data r failed\n");
return -EIO;
}
buf[0] &= MAX3107_SPI_RX_DATA_MASK;
return buf[0] & (0x0001 << offset);
}
static void max3107_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct max3107_port *s = container_of(chip, struct max3107_port, chip);
u16 buf[2];
if (offset >= MAX3107_GPIO_COUNT) {
dev_err(&s->spi->dev, "Invalid GPIO\n");
return;
}
buf[0] = MAX3107_GPIODATA_REG;
buf[1] = MAX3107_GPIOCFG_REG;
if (max3107_rw(s, (u8 *)buf, (u8 *)buf, 4)) {
dev_err(&s->spi->dev,
"SPI transfer for GPIO data and config read failed\n");
return;
}
buf[0] &= MAX3107_SPI_RX_DATA_MASK;
buf[1] &= MAX3107_SPI_RX_DATA_MASK;
if (!(buf[1] & (0x0001 << offset))) {
dev_warn(&s->spi->dev,
"Trying to set value for input GPIO\n");
return;
}
if (value)
buf[0] |= (0x0001 << offset);
else
buf[0] &= ~(0x0001 << offset);
buf[0] |= (MAX3107_WRITE_BIT | MAX3107_GPIODATA_REG);
if (max3107_rw(s, (u8 *)buf, NULL, 2))
dev_err(&s->spi->dev, "SPI transfer GPIO data w failed\n");
}
static int max3107_aava_reset(struct spi_device *spi)
{
if (gpio_request(MAX3107_RESET_GPIO, "max3107")) {
pr_err("Requesting RESET GPIO failed\n");
return -EIO;
}
if (gpio_direction_output(MAX3107_RESET_GPIO, 0)) {
pr_err("Setting RESET GPIO to 0 failed\n");
gpio_free(MAX3107_RESET_GPIO);
return -EIO;
}
msleep(MAX3107_RESET_DELAY);
if (gpio_direction_output(MAX3107_RESET_GPIO, 1)) {
pr_err("Setting RESET GPIO to 1 failed\n");
gpio_free(MAX3107_RESET_GPIO);
return -EIO;
}
gpio_free(MAX3107_RESET_GPIO);
msleep(MAX3107_WAKEUP_DELAY);
return 0;
}
static int max3107_aava_configure(struct max3107_port *s)
{
int retval;
s->chip = max3107_gpio_chip;
s->chip.label = s->spi->modalias;
s->chip.dev = &s->spi->dev;
retval = gpiochip_add(&s->chip);
if (retval) {
dev_err(&s->spi->dev, "Adding GPIO chip failed\n");
return retval;
}
max3107_gpio_direction_out(&s->chip, 3, 0);
return 0;
}
static int __devexit max3107_aava_remove(struct spi_device *spi)
{
struct max3107_port *s = dev_get_drvdata(&spi->dev);
if (gpiochip_remove(&s->chip))
dev_warn(&spi->dev, "Removing GPIO chip failed\n");
return max3107_remove(spi);
}
static int __devinit max3107_probe_aava(struct spi_device *spi)
{
int err = max3107_aava_reset(spi);
if (err < 0)
return err;
return max3107_probe(spi, &aava_plat_data);
}
static int __init max3107_init(void)
{
return spi_register_driver(&max3107_driver);
}
static void __exit max3107_exit(void)
{
spi_unregister_driver(&max3107_driver);
}
