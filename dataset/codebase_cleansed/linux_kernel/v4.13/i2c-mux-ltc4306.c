static bool ltc4306_is_volatile_reg(struct device *dev, unsigned int reg)
{
return (reg == LTC_REG_CONFIG) ? true : false;
}
static int ltc4306_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct ltc4306 *data = gpiochip_get_data(chip);
unsigned int val;
int ret;
ret = regmap_read(data->regmap, LTC_REG_CONFIG, &val);
if (ret < 0)
return ret;
return !!(val & BIT(1 - offset));
}
static void ltc4306_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct ltc4306 *data = gpiochip_get_data(chip);
regmap_update_bits(data->regmap, LTC_REG_CONFIG, BIT(5 - offset),
value ? BIT(5 - offset) : 0);
}
static int ltc4306_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct ltc4306 *data = gpiochip_get_data(chip);
unsigned int val;
int ret;
ret = regmap_read(data->regmap, LTC_REG_MODE, &val);
if (ret < 0)
return ret;
return !!(val & BIT(7 - offset));
}
static int ltc4306_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct ltc4306 *data = gpiochip_get_data(chip);
return regmap_update_bits(data->regmap, LTC_REG_MODE,
BIT(7 - offset), BIT(7 - offset));
}
static int ltc4306_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct ltc4306 *data = gpiochip_get_data(chip);
ltc4306_gpio_set(chip, offset, value);
return regmap_update_bits(data->regmap, LTC_REG_MODE,
BIT(7 - offset), 0);
}
static int ltc4306_gpio_set_config(struct gpio_chip *chip,
unsigned int offset, unsigned long config)
{
struct ltc4306 *data = gpiochip_get_data(chip);
unsigned int val;
switch (pinconf_to_config_param(config)) {
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
val = 0;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
val = BIT(4 - offset);
break;
default:
return -ENOTSUPP;
}
return regmap_update_bits(data->regmap, LTC_REG_MODE,
BIT(4 - offset), val);
}
static int ltc4306_gpio_init(struct ltc4306 *data)
{
struct device *dev = regmap_get_device(data->regmap);
if (!data->chip->num_gpios)
return 0;
data->gpiochip.label = dev_name(dev);
data->gpiochip.base = -1;
data->gpiochip.ngpio = data->chip->num_gpios;
data->gpiochip.parent = dev;
data->gpiochip.can_sleep = true;
data->gpiochip.get_direction = ltc4306_gpio_get_direction;
data->gpiochip.direction_input = ltc4306_gpio_direction_input;
data->gpiochip.direction_output = ltc4306_gpio_direction_output;
data->gpiochip.get = ltc4306_gpio_get;
data->gpiochip.set = ltc4306_gpio_set;
data->gpiochip.set_config = ltc4306_gpio_set_config;
data->gpiochip.owner = THIS_MODULE;
regmap_write(data->regmap, LTC_REG_MODE, LTC_GPIO_ALL_INPUT);
return devm_gpiochip_add_data(dev, &data->gpiochip, data);
}
static int ltc4306_select_mux(struct i2c_mux_core *muxc, u32 chan)
{
struct ltc4306 *data = i2c_mux_priv(muxc);
return regmap_update_bits(data->regmap, LTC_REG_SWITCH,
LTC_SWITCH_MASK, BIT(7 - chan));
}
static int ltc4306_deselect_mux(struct i2c_mux_core *muxc, u32 chan)
{
struct ltc4306 *data = i2c_mux_priv(muxc);
return regmap_update_bits(data->regmap, LTC_REG_SWITCH,
LTC_SWITCH_MASK, 0);
}
static int ltc4306_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
const struct chip_desc *chip;
struct i2c_mux_core *muxc;
struct ltc4306 *data;
struct gpio_desc *gpio;
bool idle_disc;
unsigned int val = 0;
int num, ret;
chip = of_device_get_match_data(&client->dev);
if (!chip)
chip = &chips[id->driver_data];
idle_disc = device_property_read_bool(&client->dev,
"i2c-mux-idle-disconnect");
muxc = i2c_mux_alloc(adap, &client->dev,
chip->nchans, sizeof(*data),
I2C_MUX_LOCKED, ltc4306_select_mux,
idle_disc ? ltc4306_deselect_mux : NULL);
if (!muxc)
return -ENOMEM;
data = i2c_mux_priv(muxc);
data->chip = chip;
i2c_set_clientdata(client, muxc);
data->regmap = devm_regmap_init_i2c(client, &ltc4306_regmap_config);
if (IS_ERR(data->regmap)) {
ret = PTR_ERR(data->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
gpio = devm_gpiod_get_optional(&client->dev, "enable", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
if (gpio) {
udelay(1);
gpiod_set_value(gpio, 1);
}
if (regmap_write(data->regmap, LTC_REG_SWITCH, 0) < 0) {
dev_warn(&client->dev, "probe failed\n");
return -ENODEV;
}
if (device_property_read_bool(&client->dev,
"ltc,downstream-accelerators-enable"))
val |= LTC_DOWNSTREAM_ACCL_EN;
if (device_property_read_bool(&client->dev,
"ltc,upstream-accelerators-enable"))
val |= LTC_UPSTREAM_ACCL_EN;
if (regmap_write(data->regmap, LTC_REG_CONFIG, val) < 0)
return -ENODEV;
ret = ltc4306_gpio_init(data);
if (ret < 0)
return ret;
for (num = 0; num < chip->nchans; num++) {
ret = i2c_mux_add_adapter(muxc, 0, num, 0);
if (ret) {
i2c_mux_del_adapters(muxc);
return ret;
}
}
dev_info(&client->dev,
"registered %d multiplexed busses for I2C switch %s\n",
num, client->name);
return 0;
}
static int ltc4306_remove(struct i2c_client *client)
{
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
i2c_mux_del_adapters(muxc);
return 0;
}
