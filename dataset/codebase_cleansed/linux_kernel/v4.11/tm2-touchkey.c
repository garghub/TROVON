static void tm2_touchkey_led_brightness_set(struct led_classdev *led_dev,
enum led_brightness brightness)
{
struct tm2_touchkey_data *touchkey =
container_of(led_dev, struct tm2_touchkey_data, led_dev);
u32 volt;
u8 data;
if (brightness == LED_OFF) {
volt = TM2_TOUCHKEY_LED_VOLTAGE_MIN;
data = TM2_TOUCHKEY_CMD_LED_OFF;
} else {
volt = TM2_TOUCHKEY_LED_VOLTAGE_MAX;
data = TM2_TOUCHKEY_CMD_LED_ON;
}
regulator_set_voltage(touchkey->vdd, volt, volt);
i2c_smbus_write_byte_data(touchkey->client,
TM2_TOUCHKEY_BASE_REG, data);
}
static int tm2_touchkey_power_enable(struct tm2_touchkey_data *touchkey)
{
int error;
error = regulator_bulk_enable(ARRAY_SIZE(touchkey->regulators),
touchkey->regulators);
if (error)
return error;
msleep(150);
return 0;
}
static void tm2_touchkey_power_disable(void *data)
{
struct tm2_touchkey_data *touchkey = data;
regulator_bulk_disable(ARRAY_SIZE(touchkey->regulators),
touchkey->regulators);
}
static irqreturn_t tm2_touchkey_irq_handler(int irq, void *devid)
{
struct tm2_touchkey_data *touchkey = devid;
int data;
int key;
data = i2c_smbus_read_byte_data(touchkey->client,
TM2_TOUCHKEY_KEYCODE_REG);
if (data < 0) {
dev_err(&touchkey->client->dev,
"failed to read i2c data: %d\n", data);
goto out;
}
switch (data & TM2_TOUCHKEY_BIT_KEYCODE) {
case TM2_TOUCHKEY_KEY_MENU:
key = KEY_PHONE;
break;
case TM2_TOUCHKEY_KEY_BACK:
key = KEY_BACK;
break;
default:
dev_warn(&touchkey->client->dev,
"unhandled keycode, data %#02x\n", data);
goto out;
}
if (data & TM2_TOUCHKEY_BIT_PRESS_EV) {
input_report_key(touchkey->input_dev, KEY_PHONE, 0);
input_report_key(touchkey->input_dev, KEY_BACK, 0);
} else {
input_report_key(touchkey->input_dev, key, 1);
}
input_sync(touchkey->input_dev);
out:
return IRQ_HANDLED;
}
static int tm2_touchkey_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tm2_touchkey_data *touchkey;
int error;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "incompatible I2C adapter\n");
return -EIO;
}
touchkey = devm_kzalloc(&client->dev, sizeof(*touchkey), GFP_KERNEL);
if (!touchkey)
return -ENOMEM;
touchkey->client = client;
i2c_set_clientdata(client, touchkey);
touchkey->regulators[0].supply = "vcc";
touchkey->regulators[1].supply = "vdd";
error = devm_regulator_bulk_get(&client->dev,
ARRAY_SIZE(touchkey->regulators),
touchkey->regulators);
if (error) {
dev_err(&client->dev, "failed to get regulators: %d\n", error);
return error;
}
touchkey->vdd = touchkey->regulators[1].consumer;
error = tm2_touchkey_power_enable(touchkey);
if (error) {
dev_err(&client->dev, "failed to power up device: %d\n", error);
return error;
}
error = devm_add_action_or_reset(&client->dev,
tm2_touchkey_power_disable, touchkey);
if (error) {
dev_err(&client->dev,
"failed to install poweroff handler: %d\n", error);
return error;
}
touchkey->input_dev = devm_input_allocate_device(&client->dev);
if (!touchkey->input_dev) {
dev_err(&client->dev, "failed to allocate input device\n");
return -ENOMEM;
}
touchkey->input_dev->name = TM2_TOUCHKEY_DEV_NAME;
touchkey->input_dev->id.bustype = BUS_I2C;
input_set_capability(touchkey->input_dev, EV_KEY, KEY_PHONE);
input_set_capability(touchkey->input_dev, EV_KEY, KEY_BACK);
error = input_register_device(touchkey->input_dev);
if (error) {
dev_err(&client->dev,
"failed to register input device: %d\n", error);
return error;
}
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, tm2_touchkey_irq_handler,
IRQF_ONESHOT,
TM2_TOUCHKEY_DEV_NAME, touchkey);
if (error) {
dev_err(&client->dev,
"failed to request threaded irq: %d\n", error);
return error;
}
touchkey->led_dev.name = TM2_TOUCHKEY_DEV_NAME;
touchkey->led_dev.brightness = LED_FULL;
touchkey->led_dev.max_brightness = LED_FULL;
touchkey->led_dev.brightness_set = tm2_touchkey_led_brightness_set;
error = devm_led_classdev_register(&client->dev, &touchkey->led_dev);
if (error) {
dev_err(&client->dev,
"failed to register touchkey led: %d\n", error);
return error;
}
return 0;
}
static int __maybe_unused tm2_touchkey_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tm2_touchkey_data *touchkey = i2c_get_clientdata(client);
disable_irq(client->irq);
tm2_touchkey_power_disable(touchkey);
return 0;
}
static int __maybe_unused tm2_touchkey_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tm2_touchkey_data *touchkey = i2c_get_clientdata(client);
int ret;
enable_irq(client->irq);
ret = tm2_touchkey_power_enable(touchkey);
if (ret)
dev_err(dev, "failed to enable power: %d\n", ret);
return ret;
}
