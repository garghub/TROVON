static int tpic2810_get_direction(struct gpio_chip *chip,
unsigned offset)
{
return 0;
}
static int tpic2810_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return -EINVAL;
}
static int tpic2810_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
tpic2810_set(chip, offset, value);
return 0;
}
static void tpic2810_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct tpic2810 *gpio = gpiochip_get_data(chip);
mutex_lock(&gpio->lock);
if (value)
gpio->buffer |= BIT(offset);
else
gpio->buffer &= ~BIT(offset);
i2c_smbus_write_byte_data(gpio->client, TPIC2810_WS_COMMAND,
gpio->buffer);
mutex_unlock(&gpio->lock);
}
static void tpic2810_set_multiple(struct gpio_chip *chip, unsigned long *mask,
unsigned long *bits)
{
struct tpic2810 *gpio = gpiochip_get_data(chip);
mutex_lock(&gpio->lock);
gpio->buffer &= ~(*mask);
gpio->buffer |= ((*mask) & (*bits));
i2c_smbus_write_byte_data(gpio->client, TPIC2810_WS_COMMAND,
gpio->buffer);
mutex_unlock(&gpio->lock);
}
static int tpic2810_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tpic2810 *gpio;
int ret;
gpio = devm_kzalloc(&client->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
i2c_set_clientdata(client, gpio);
gpio->chip = template_chip;
gpio->chip.parent = &client->dev;
gpio->client = client;
mutex_init(&gpio->lock);
ret = gpiochip_add_data(&gpio->chip, gpio);
if (ret < 0) {
dev_err(&client->dev, "Unable to register gpiochip\n");
return ret;
}
return 0;
}
static int tpic2810_remove(struct i2c_client *client)
{
struct tpic2810 *gpio = i2c_get_clientdata(client);
gpiochip_remove(&gpio->chip);
return 0;
}
