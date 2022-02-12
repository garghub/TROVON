static bool cap11xx_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case CAP11XX_REG_MAIN_CONTROL:
case CAP11XX_REG_SENSOR_INPUT:
case CAP11XX_REG_SENOR_DELTA(0):
case CAP11XX_REG_SENOR_DELTA(1):
case CAP11XX_REG_SENOR_DELTA(2):
case CAP11XX_REG_SENOR_DELTA(3):
case CAP11XX_REG_SENOR_DELTA(4):
case CAP11XX_REG_SENOR_DELTA(5):
case CAP11XX_REG_PRODUCT_ID:
case CAP11XX_REG_MANUFACTURER_ID:
case CAP11XX_REG_REVISION:
return true;
}
return false;
}
static irqreturn_t cap11xx_thread_func(int irq_num, void *data)
{
struct cap11xx_priv *priv = data;
unsigned int status;
int ret, i;
ret = regmap_update_bits(priv->regmap, CAP11XX_REG_MAIN_CONTROL, 1, 0);
if (ret < 0)
goto out;
ret = regmap_read(priv->regmap, CAP11XX_REG_SENSOR_INPUT, &status);
if (ret < 0)
goto out;
for (i = 0; i < priv->idev->keycodemax; i++)
input_report_key(priv->idev, priv->keycodes[i],
status & (1 << i));
input_sync(priv->idev);
out:
return IRQ_HANDLED;
}
static int cap11xx_set_sleep(struct cap11xx_priv *priv, bool sleep)
{
if (IS_ENABLED(CONFIG_LEDS_CLASS) && priv->num_leds)
return 0;
return regmap_update_bits(priv->regmap, CAP11XX_REG_MAIN_CONTROL,
CAP11XX_REG_MAIN_CONTROL_DLSEEP,
sleep ? CAP11XX_REG_MAIN_CONTROL_DLSEEP : 0);
}
static int cap11xx_input_open(struct input_dev *idev)
{
struct cap11xx_priv *priv = input_get_drvdata(idev);
return cap11xx_set_sleep(priv, false);
}
static void cap11xx_input_close(struct input_dev *idev)
{
struct cap11xx_priv *priv = input_get_drvdata(idev);
cap11xx_set_sleep(priv, true);
}
static void cap11xx_led_work(struct work_struct *work)
{
struct cap11xx_led *led = container_of(work, struct cap11xx_led, work);
struct cap11xx_priv *priv = led->priv;
int value = led->new_brightness;
regmap_update_bits(priv->regmap, CAP11XX_REG_LED_OUTPUT_CONTROL,
BIT(led->reg), value ? BIT(led->reg) : 0);
}
static void cap11xx_led_set(struct led_classdev *cdev,
enum led_brightness value)
{
struct cap11xx_led *led = container_of(cdev, struct cap11xx_led, cdev);
if (led->new_brightness == value)
return;
led->new_brightness = value;
schedule_work(&led->work);
}
static int cap11xx_init_leds(struct device *dev,
struct cap11xx_priv *priv, int num_leds)
{
struct device_node *node = dev->of_node, *child;
struct cap11xx_led *led;
int cnt = of_get_child_count(node);
int error;
if (!num_leds || !cnt)
return 0;
if (cnt > num_leds)
return -EINVAL;
led = devm_kcalloc(dev, cnt, sizeof(struct cap11xx_led), GFP_KERNEL);
if (!led)
return -ENOMEM;
priv->leds = led;
error = regmap_update_bits(priv->regmap,
CAP11XX_REG_LED_OUTPUT_CONTROL, 0xff, 0);
if (error)
return error;
error = regmap_update_bits(priv->regmap, CAP11XX_REG_LED_DUTY_CYCLE_4,
CAP11XX_REG_LED_DUTY_MAX_MASK,
CAP11XX_REG_LED_DUTY_MAX_VALUE <<
CAP11XX_REG_LED_DUTY_MAX_MASK_SHIFT);
if (error)
return error;
for_each_child_of_node(node, child) {
u32 reg;
led->cdev.name =
of_get_property(child, "label", NULL) ? : child->name;
led->cdev.default_trigger =
of_get_property(child, "linux,default-trigger", NULL);
led->cdev.flags = 0;
led->cdev.brightness_set = cap11xx_led_set;
led->cdev.max_brightness = 1;
led->cdev.brightness = LED_OFF;
error = of_property_read_u32(child, "reg", &reg);
if (error != 0 || reg >= num_leds) {
of_node_put(child);
return -EINVAL;
}
led->reg = reg;
led->priv = priv;
INIT_WORK(&led->work, cap11xx_led_work);
error = devm_led_classdev_register(dev, &led->cdev);
if (error) {
of_node_put(child);
return error;
}
priv->num_leds++;
led++;
}
return 0;
}
static int cap11xx_init_leds(struct device *dev,
struct cap11xx_priv *priv, int num_leds)
{
return 0;
}
static int cap11xx_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct device *dev = &i2c_client->dev;
struct cap11xx_priv *priv;
struct device_node *node;
const struct cap11xx_hw_model *cap;
int i, error, irq, gain = 0;
unsigned int val, rev;
u32 gain32;
if (id->driver_data >= ARRAY_SIZE(cap11xx_devices)) {
dev_err(dev, "Invalid device ID %lu\n", id->driver_data);
return -EINVAL;
}
cap = &cap11xx_devices[id->driver_data];
if (!cap || !cap->num_channels) {
dev_err(dev, "Invalid device configuration\n");
return -EINVAL;
}
priv = devm_kzalloc(dev,
sizeof(*priv) +
cap->num_channels * sizeof(priv->keycodes[0]),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(i2c_client, &cap11xx_regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
error = regmap_read(priv->regmap, CAP11XX_REG_PRODUCT_ID, &val);
if (error)
return error;
if (val != cap->product_id) {
dev_err(dev, "Product ID: Got 0x%02x, expected 0x%02x\n",
val, cap->product_id);
return -ENXIO;
}
error = regmap_read(priv->regmap, CAP11XX_REG_MANUFACTURER_ID, &val);
if (error)
return error;
if (val != CAP11XX_MANUFACTURER_ID) {
dev_err(dev, "Manufacturer ID: Got 0x%02x, expected 0x%02x\n",
val, CAP11XX_MANUFACTURER_ID);
return -ENXIO;
}
error = regmap_read(priv->regmap, CAP11XX_REG_REVISION, &rev);
if (error < 0)
return error;
dev_info(dev, "CAP11XX detected, revision 0x%02x\n", rev);
i2c_set_clientdata(i2c_client, priv);
node = dev->of_node;
if (!of_property_read_u32(node, "microchip,sensor-gain", &gain32)) {
if (is_power_of_2(gain32) && gain32 <= 8)
gain = ilog2(gain32);
else
dev_err(dev, "Invalid sensor-gain value %d\n", gain32);
}
if (of_property_read_bool(node, "microchip,irq-active-high")) {
error = regmap_update_bits(priv->regmap, CAP11XX_REG_CONFIG2,
CAP11XX_REG_CONFIG2_ALT_POL, 0);
if (error)
return error;
}
for (i = 0; i < cap->num_channels; i++)
priv->keycodes[i] = KEY_A + i;
of_property_read_u32_array(node, "linux,keycodes",
priv->keycodes, cap->num_channels);
error = regmap_update_bits(priv->regmap, CAP11XX_REG_MAIN_CONTROL,
CAP11XX_REG_MAIN_CONTROL_GAIN_MASK,
gain << CAP11XX_REG_MAIN_CONTROL_GAIN_SHIFT);
if (error)
return error;
error = regmap_write(priv->regmap, CAP11XX_REG_REPEAT_RATE, 0);
if (error)
return error;
priv->idev = devm_input_allocate_device(dev);
if (!priv->idev)
return -ENOMEM;
priv->idev->name = "CAP11XX capacitive touch sensor";
priv->idev->id.bustype = BUS_I2C;
priv->idev->evbit[0] = BIT_MASK(EV_KEY);
if (of_property_read_bool(node, "autorepeat"))
__set_bit(EV_REP, priv->idev->evbit);
for (i = 0; i < cap->num_channels; i++)
__set_bit(priv->keycodes[i], priv->idev->keybit);
__clear_bit(KEY_RESERVED, priv->idev->keybit);
priv->idev->keycode = priv->keycodes;
priv->idev->keycodesize = sizeof(priv->keycodes[0]);
priv->idev->keycodemax = cap->num_channels;
priv->idev->id.vendor = CAP11XX_MANUFACTURER_ID;
priv->idev->id.product = cap->product_id;
priv->idev->id.version = rev;
priv->idev->open = cap11xx_input_open;
priv->idev->close = cap11xx_input_close;
error = cap11xx_init_leds(dev, priv, cap->num_leds);
if (error)
return error;
input_set_drvdata(priv->idev, priv);
cap11xx_set_sleep(priv, true);
error = input_register_device(priv->idev);
if (error)
return error;
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
dev_err(dev, "Unable to parse or map IRQ\n");
return -ENXIO;
}
error = devm_request_threaded_irq(dev, irq, NULL, cap11xx_thread_func,
IRQF_ONESHOT, dev_name(dev), priv);
if (error)
return error;
return 0;
}
