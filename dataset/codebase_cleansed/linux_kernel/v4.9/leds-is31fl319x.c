static int is31fl319x_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct is31fl319x_led *led = container_of(cdev, struct is31fl319x_led,
cdev);
struct is31fl319x_chip *is31 = led->chip;
int chan = led - is31->leds;
int ret;
int i;
u8 ctrl1 = 0, ctrl2 = 0;
dev_dbg(&is31->client->dev, "%s %d: %d\n", __func__, chan, brightness);
mutex_lock(&is31->lock);
ret = regmap_write(is31->regmap, IS31FL319X_PWM(chan), brightness);
if (ret < 0)
goto out;
for (i = 0; i < is31->cdef->num_leds; i++) {
unsigned int pwm_value;
bool on;
ret = regmap_read(is31->regmap, IS31FL319X_PWM(i), &pwm_value);
dev_dbg(&is31->client->dev, "%s read %d: ret=%d: %d\n",
__func__, i, ret, pwm_value);
on = ret >= 0 && pwm_value > LED_OFF;
if (i < 3)
ctrl1 |= on << i;
else if (i < 6)
ctrl1 |= on << (i + 1);
else
ctrl2 |= on << (i - 6);
}
if (ctrl1 > 0 || ctrl2 > 0) {
dev_dbg(&is31->client->dev, "power up %02x %02x\n",
ctrl1, ctrl2);
regmap_write(is31->regmap, IS31FL319X_CTRL1, ctrl1);
regmap_write(is31->regmap, IS31FL319X_CTRL2, ctrl2);
regmap_write(is31->regmap, IS31FL319X_DATA_UPDATE, 0x00);
ret = regmap_write(is31->regmap, IS31FL319X_SHUTDOWN, 0x01);
} else {
dev_dbg(&is31->client->dev, "power down\n");
ret = regmap_write(is31->regmap, IS31FL319X_SHUTDOWN, 0x00);
}
out:
mutex_unlock(&is31->lock);
return ret;
}
static int is31fl319x_parse_child_dt(const struct device *dev,
const struct device_node *child,
struct is31fl319x_led *led)
{
struct led_classdev *cdev = &led->cdev;
int ret;
if (of_property_read_string(child, "label", &cdev->name))
cdev->name = child->name;
ret = of_property_read_string(child, "linux,default-trigger",
&cdev->default_trigger);
if (ret < 0 && ret != -EINVAL)
return ret;
led->max_microamp = IS31FL319X_CURRENT_DEFAULT;
ret = of_property_read_u32(child, "led-max-microamp",
&led->max_microamp);
if (!ret) {
if (led->max_microamp < IS31FL319X_CURRENT_MIN)
return -EINVAL;
led->max_microamp = min(led->max_microamp,
IS31FL319X_CURRENT_MAX);
}
return 0;
}
static int is31fl319x_parse_dt(struct device *dev,
struct is31fl319x_chip *is31)
{
struct device_node *np = dev->of_node, *child;
const struct of_device_id *of_dev_id;
int count;
int ret;
if (!np)
return -ENODEV;
of_dev_id = of_match_device(of_is31fl319x_match, dev);
if (!of_dev_id) {
dev_err(dev, "Failed to match device with supported chips\n");
return -EINVAL;
}
is31->cdef = of_dev_id->data;
count = of_get_child_count(np);
dev_dbg(dev, "probe %s with %d leds defined in DT\n",
of_dev_id->compatible, count);
if (!count || count > is31->cdef->num_leds) {
dev_err(dev, "Number of leds defined must be between 1 and %u\n",
is31->cdef->num_leds);
return -ENODEV;
}
for_each_child_of_node(np, child) {
struct is31fl319x_led *led;
u32 reg;
ret = of_property_read_u32(child, "reg", &reg);
if (ret) {
dev_err(dev, "Failed to read led 'reg' property\n");
goto put_child_node;
}
if (reg < 1 || reg > is31->cdef->num_leds) {
dev_err(dev, "invalid led reg %u\n", reg);
ret = -EINVAL;
goto put_child_node;
}
led = &is31->leds[reg - 1];
if (led->configured) {
dev_err(dev, "led %u is already configured\n", reg);
ret = -EINVAL;
goto put_child_node;
}
ret = is31fl319x_parse_child_dt(dev, child, led);
if (ret) {
dev_err(dev, "led %u DT parsing failed\n", reg);
goto put_child_node;
}
led->configured = true;
}
is31->audio_gain_db = 0;
ret = of_property_read_u32(np, "audio-gain-db", &is31->audio_gain_db);
if (!ret)
is31->audio_gain_db = min(is31->audio_gain_db,
IS31FL319X_AUDIO_GAIN_DB_MAX);
return 0;
put_child_node:
of_node_put(child);
return ret;
}
static bool is31fl319x_readable_reg(struct device *dev, unsigned int reg)
{
return false;
}
static bool is31fl319x_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case IS31FL319X_DATA_UPDATE:
case IS31FL319X_TIME_UPDATE:
case IS31FL319X_RESET:
return true;
default:
return false;
}
}
static inline int is31fl319x_microamp_to_cs(struct device *dev, u32 microamp)
{
u32 step = microamp / IS31FL319X_CURRENT_STEP;
return ((IS31FL319X_CONFIG2_CS_STEP_REF - step) &
IS31FL319X_CONFIG2_CS_MASK) <<
IS31FL319X_CONFIG2_CS_SHIFT;
}
static inline int is31fl319x_db_to_gain(u32 dezibel)
{
return dezibel / IS31FL319X_AUDIO_GAIN_DB_STEP;
}
static int is31fl319x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct is31fl319x_chip *is31;
struct device *dev = &client->dev;
struct i2c_adapter *adapter = to_i2c_adapter(dev->parent);
int err;
int i = 0;
u32 aggregated_led_microamp = IS31FL319X_CURRENT_MAX;
if (!i2c_check_functionality(adapter, I2C_FUNC_I2C))
return -EIO;
is31 = devm_kzalloc(&client->dev, sizeof(*is31), GFP_KERNEL);
if (!is31)
return -ENOMEM;
mutex_init(&is31->lock);
err = is31fl319x_parse_dt(&client->dev, is31);
if (err)
goto free_mutex;
is31->client = client;
is31->regmap = devm_regmap_init_i2c(client, &regmap_config);
if (IS_ERR(is31->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
err = PTR_ERR(is31->regmap);
goto free_mutex;
}
i2c_set_clientdata(client, is31);
err = regmap_write(is31->regmap, IS31FL319X_RESET, 0x00);
if (err < 0) {
dev_err(&client->dev, "no response from chip write: err = %d\n",
err);
err = -EIO;
goto free_mutex;
}
for (i = 0; i < is31->cdef->num_leds; i++)
if (is31->leds[i].configured &&
is31->leds[i].max_microamp < aggregated_led_microamp)
aggregated_led_microamp = is31->leds[i].max_microamp;
regmap_write(is31->regmap, IS31FL319X_CONFIG2,
is31fl319x_microamp_to_cs(dev, aggregated_led_microamp) |
is31fl319x_db_to_gain(is31->audio_gain_db));
for (i = 0; i < is31->cdef->num_leds; i++) {
struct is31fl319x_led *led = &is31->leds[i];
if (!led->configured)
continue;
led->chip = is31;
led->cdev.brightness_set_blocking = is31fl319x_brightness_set;
err = devm_led_classdev_register(&client->dev, &led->cdev);
if (err < 0)
goto free_mutex;
}
return 0;
free_mutex:
mutex_destroy(&is31->lock);
return err;
}
static int is31fl319x_remove(struct i2c_client *client)
{
struct is31fl319x_chip *is31 = i2c_get_clientdata(client);
mutex_destroy(&is31->lock);
return 0;
}
