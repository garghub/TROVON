static int ts4900_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
unsigned int reg;
regmap_read(priv->regmap, offset, &reg);
return !(reg & TS4900_GPIO_OE);
}
static int ts4900_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
return regmap_write(priv->regmap, offset, 0);
}
static int ts4900_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
int ret;
if (value)
ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE |
TS4900_GPIO_OUT);
else
ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE);
return ret;
}
static int ts4900_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
unsigned int reg;
regmap_read(priv->regmap, offset, &reg);
return !!(reg & priv->input_bit);
}
static void ts4900_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
if (value)
regmap_update_bits(priv->regmap, offset, TS4900_GPIO_OUT,
TS4900_GPIO_OUT);
else
regmap_update_bits(priv->regmap, offset, TS4900_GPIO_OUT, 0);
}
static int ts4900_gpio_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct of_device_id *match;
struct ts4900_gpio_priv *priv;
u32 ngpio;
int ret;
match = of_match_device(ts4900_gpio_of_match_table, &client->dev);
if (!match)
return -EINVAL;
if (of_property_read_u32(client->dev.of_node, "ngpios", &ngpio))
ngpio = DEFAULT_PIN_NUMBER;
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->gpio_chip = template_chip;
priv->gpio_chip.label = "ts4900-gpio";
priv->gpio_chip.ngpio = ngpio;
priv->gpio_chip.parent = &client->dev;
priv->input_bit = (uintptr_t)match->data;
priv->regmap = devm_regmap_init_i2c(client, &ts4900_regmap_config);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = devm_gpiochip_add_data(&client->dev, &priv->gpio_chip, priv);
if (ret < 0) {
dev_err(&client->dev, "Unable to register gpiochip\n");
return ret;
}
i2c_set_clientdata(client, priv);
return 0;
}
