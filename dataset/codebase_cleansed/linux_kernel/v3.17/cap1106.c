static bool cap1106_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case CAP1106_REG_MAIN_CONTROL:
case CAP1106_REG_SENSOR_INPUT:
case CAP1106_REG_SENOR_DELTA(0):
case CAP1106_REG_SENOR_DELTA(1):
case CAP1106_REG_SENOR_DELTA(2):
case CAP1106_REG_SENOR_DELTA(3):
case CAP1106_REG_SENOR_DELTA(4):
case CAP1106_REG_SENOR_DELTA(5):
case CAP1106_REG_PRODUCT_ID:
case CAP1106_REG_MANUFACTURER_ID:
case CAP1106_REG_REVISION:
return true;
}
return false;
}
static irqreturn_t cap1106_thread_func(int irq_num, void *data)
{
struct cap1106_priv *priv = data;
unsigned int status;
int ret, i;
ret = regmap_update_bits(priv->regmap, CAP1106_REG_MAIN_CONTROL, 1, 0);
if (ret < 0)
goto out;
ret = regmap_read(priv->regmap, CAP1106_REG_SENSOR_INPUT, &status);
if (ret < 0)
goto out;
for (i = 0; i < CAP1106_NUM_CHN; i++)
input_report_key(priv->idev, priv->keycodes[i],
status & (1 << i));
input_sync(priv->idev);
out:
return IRQ_HANDLED;
}
static int cap1106_set_sleep(struct cap1106_priv *priv, bool sleep)
{
return regmap_update_bits(priv->regmap, CAP1106_REG_MAIN_CONTROL,
CAP1106_REG_MAIN_CONTROL_DLSEEP,
sleep ? CAP1106_REG_MAIN_CONTROL_DLSEEP : 0);
}
static int cap1106_input_open(struct input_dev *idev)
{
struct cap1106_priv *priv = input_get_drvdata(idev);
return cap1106_set_sleep(priv, false);
}
static void cap1106_input_close(struct input_dev *idev)
{
struct cap1106_priv *priv = input_get_drvdata(idev);
cap1106_set_sleep(priv, true);
}
static int cap1106_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct device *dev = &i2c_client->dev;
struct cap1106_priv *priv;
struct device_node *node;
int i, error, irq, gain = 0;
unsigned int val, rev;
u32 gain32, keycodes[CAP1106_NUM_CHN];
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(i2c_client, &cap1106_regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
error = regmap_read(priv->regmap, CAP1106_REG_PRODUCT_ID, &val);
if (error)
return error;
if (val != CAP1106_PRODUCT_ID) {
dev_err(dev, "Product ID: Got 0x%02x, expected 0x%02x\n",
val, CAP1106_PRODUCT_ID);
return -ENODEV;
}
error = regmap_read(priv->regmap, CAP1106_REG_MANUFACTURER_ID, &val);
if (error)
return error;
if (val != CAP1106_MANUFACTURER_ID) {
dev_err(dev, "Manufacturer ID: Got 0x%02x, expected 0x%02x\n",
val, CAP1106_MANUFACTURER_ID);
return -ENODEV;
}
error = regmap_read(priv->regmap, CAP1106_REG_REVISION, &rev);
if (error < 0)
return error;
dev_info(dev, "CAP1106 detected, revision 0x%02x\n", rev);
i2c_set_clientdata(i2c_client, priv);
node = dev->of_node;
if (!of_property_read_u32(node, "microchip,sensor-gain", &gain32)) {
if (is_power_of_2(gain32) && gain32 <= 8)
gain = ilog2(gain32);
else
dev_err(dev, "Invalid sensor-gain value %d\n", gain32);
}
BUILD_BUG_ON(ARRAY_SIZE(keycodes) != ARRAY_SIZE(priv->keycodes));
for (i = 0; i < ARRAY_SIZE(keycodes); i++)
keycodes[i] = KEY_A + i;
of_property_read_u32_array(node, "linux,keycodes",
keycodes, ARRAY_SIZE(keycodes));
for (i = 0; i < ARRAY_SIZE(keycodes); i++)
priv->keycodes[i] = keycodes[i];
error = regmap_update_bits(priv->regmap, CAP1106_REG_MAIN_CONTROL,
CAP1106_REG_MAIN_CONTROL_GAIN_MASK,
gain << CAP1106_REG_MAIN_CONTROL_GAIN_SHIFT);
if (error)
return error;
error = regmap_write(priv->regmap, CAP1106_REG_REPEAT_RATE, 0);
if (error)
return error;
priv->idev = devm_input_allocate_device(dev);
if (!priv->idev)
return -ENOMEM;
priv->idev->name = "CAP1106 capacitive touch sensor";
priv->idev->id.bustype = BUS_I2C;
priv->idev->evbit[0] = BIT_MASK(EV_KEY);
if (of_property_read_bool(node, "autorepeat"))
__set_bit(EV_REP, priv->idev->evbit);
for (i = 0; i < CAP1106_NUM_CHN; i++)
__set_bit(priv->keycodes[i], priv->idev->keybit);
__clear_bit(KEY_RESERVED, priv->idev->keybit);
priv->idev->keycode = priv->keycodes;
priv->idev->keycodesize = sizeof(priv->keycodes[0]);
priv->idev->keycodemax = ARRAY_SIZE(priv->keycodes);
priv->idev->id.vendor = CAP1106_MANUFACTURER_ID;
priv->idev->id.product = CAP1106_PRODUCT_ID;
priv->idev->id.version = rev;
priv->idev->open = cap1106_input_open;
priv->idev->close = cap1106_input_close;
input_set_drvdata(priv->idev, priv);
cap1106_set_sleep(priv, true);
error = input_register_device(priv->idev);
if (error)
return error;
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
dev_err(dev, "Unable to parse or map IRQ\n");
return -ENXIO;
}
error = devm_request_threaded_irq(dev, irq, NULL, cap1106_thread_func,
IRQF_ONESHOT, dev_name(dev), priv);
if (error)
return error;
return 0;
}
