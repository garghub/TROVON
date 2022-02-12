static void stmfts_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct stmfts_data *sdata = container_of(led_cdev,
struct stmfts_data, led_cdev);
int err;
if (value == sdata->led_status || !sdata->ledvdd)
return;
if (!value) {
regulator_disable(sdata->ledvdd);
} else {
err = regulator_enable(sdata->ledvdd);
if (err)
dev_warn(&sdata->client->dev,
"failed to disable ledvdd regulator: %d\n",
err);
}
sdata->led_status = value;
}
static enum led_brightness stmfts_brightness_get(struct led_classdev *led_cdev)
{
struct stmfts_data *sdata = container_of(led_cdev,
struct stmfts_data, led_cdev);
return !!regulator_is_enabled(sdata->ledvdd);
}
static int stmfts_read_events(struct stmfts_data *sdata)
{
u8 cmd = STMFTS_READ_ALL_EVENT;
struct i2c_msg msgs[2] = {
{
.addr = sdata->client->addr,
.len = 1,
.buf = &cmd,
},
{
.addr = sdata->client->addr,
.flags = I2C_M_RD,
.len = STMFTS_DATA_MAX_SIZE,
.buf = sdata->data,
},
};
int ret;
ret = i2c_transfer(sdata->client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
return ret == ARRAY_SIZE(msgs) ? 0 : -EIO;
}
static void stmfts_report_contact_event(struct stmfts_data *sdata,
const u8 event[])
{
u8 slot_id = (event[0] & STMFTS_MASK_TOUCH_ID) >> 4;
u16 x = event[1] | ((event[2] & STMFTS_MASK_X_MSB) << 8);
u16 y = (event[2] >> 4) | (event[3] << 4);
u8 maj = event[4];
u8 min = event[5];
u8 orientation = event[6];
u8 area = event[7];
input_mt_slot(sdata->input, slot_id);
input_mt_report_slot_state(sdata->input, MT_TOOL_FINGER, true);
input_report_abs(sdata->input, ABS_MT_POSITION_X, x);
input_report_abs(sdata->input, ABS_MT_POSITION_Y, y);
input_report_abs(sdata->input, ABS_MT_TOUCH_MAJOR, maj);
input_report_abs(sdata->input, ABS_MT_TOUCH_MINOR, min);
input_report_abs(sdata->input, ABS_MT_PRESSURE, area);
input_report_abs(sdata->input, ABS_MT_ORIENTATION, orientation);
input_sync(sdata->input);
}
static void stmfts_report_contact_release(struct stmfts_data *sdata,
const u8 event[])
{
u8 slot_id = (event[0] & STMFTS_MASK_TOUCH_ID) >> 4;
input_mt_slot(sdata->input, slot_id);
input_mt_report_slot_state(sdata->input, MT_TOOL_FINGER, false);
input_sync(sdata->input);
}
static void stmfts_report_hover_event(struct stmfts_data *sdata,
const u8 event[])
{
u16 x = (event[2] << 4) | (event[4] >> 4);
u16 y = (event[3] << 4) | (event[4] & STMFTS_MASK_Y_LSB);
u8 z = event[5];
input_report_abs(sdata->input, ABS_X, x);
input_report_abs(sdata->input, ABS_Y, y);
input_report_abs(sdata->input, ABS_DISTANCE, z);
input_sync(sdata->input);
}
static void stmfts_report_key_event(struct stmfts_data *sdata, const u8 event[])
{
switch (event[2]) {
case 0:
input_report_key(sdata->input, KEY_BACK, 0);
input_report_key(sdata->input, KEY_MENU, 0);
break;
case STMFTS_MASK_KEY_BACK:
input_report_key(sdata->input, KEY_BACK, 1);
break;
case STMFTS_MASK_KEY_MENU:
input_report_key(sdata->input, KEY_MENU, 1);
break;
default:
dev_warn(&sdata->client->dev,
"unknown key event: %#02x\n", event[2]);
break;
}
input_sync(sdata->input);
}
static void stmfts_parse_events(struct stmfts_data *sdata)
{
int i;
for (i = 0; i < STMFTS_STACK_DEPTH; i++) {
u8 *event = &sdata->data[i * STMFTS_EVENT_SIZE];
switch (event[0]) {
case STMFTS_EV_CONTROLLER_READY:
case STMFTS_EV_SLEEP_OUT_CONTROLLER_READY:
case STMFTS_EV_STATUS:
complete(&sdata->cmd_done);
case STMFTS_EV_NO_EVENT:
case STMFTS_EV_DEBUG:
return;
}
switch (event[0] & STMFTS_MASK_EVENT_ID) {
case STMFTS_EV_MULTI_TOUCH_ENTER:
case STMFTS_EV_MULTI_TOUCH_MOTION:
stmfts_report_contact_event(sdata, event);
break;
case STMFTS_EV_MULTI_TOUCH_LEAVE:
stmfts_report_contact_release(sdata, event);
break;
case STMFTS_EV_HOVER_ENTER:
case STMFTS_EV_HOVER_LEAVE:
case STMFTS_EV_HOVER_MOTION:
stmfts_report_hover_event(sdata, event);
break;
case STMFTS_EV_KEY_STATUS:
stmfts_report_key_event(sdata, event);
break;
case STMFTS_EV_ERROR:
dev_warn(&sdata->client->dev,
"error code: 0x%x%x%x%x%x%x",
event[6], event[5], event[4],
event[3], event[2], event[1]);
break;
default:
dev_err(&sdata->client->dev,
"unknown event %#02x\n", event[0]);
}
}
}
static irqreturn_t stmfts_irq_handler(int irq, void *dev)
{
struct stmfts_data *sdata = dev;
int err;
mutex_lock(&sdata->mutex);
err = stmfts_read_events(sdata);
if (unlikely(err))
dev_err(&sdata->client->dev,
"failed to read events: %d\n", err);
else
stmfts_parse_events(sdata);
mutex_unlock(&sdata->mutex);
return IRQ_HANDLED;
}
static int stmfts_command(struct stmfts_data *sdata, const u8 cmd)
{
int err;
reinit_completion(&sdata->cmd_done);
err = i2c_smbus_write_byte(sdata->client, cmd);
if (err)
return err;
if (!wait_for_completion_timeout(&sdata->cmd_done,
msecs_to_jiffies(1000)))
return -ETIMEDOUT;
return 0;
}
static int stmfts_input_open(struct input_dev *dev)
{
struct stmfts_data *sdata = input_get_drvdata(dev);
int err;
err = pm_runtime_get_sync(&sdata->client->dev);
if (err < 0)
return err;
err = i2c_smbus_write_byte(sdata->client, STMFTS_MS_MT_SENSE_ON);
if (err)
return err;
mutex_lock(&sdata->mutex);
sdata->running = true;
if (sdata->hover_enabled) {
err = i2c_smbus_write_byte(sdata->client,
STMFTS_SS_HOVER_SENSE_ON);
if (err)
dev_warn(&sdata->client->dev,
"failed to enable hover\n");
}
mutex_unlock(&sdata->mutex);
if (sdata->use_key) {
err = i2c_smbus_write_byte(sdata->client,
STMFTS_MS_KEY_SENSE_ON);
if (err)
dev_warn(&sdata->client->dev,
"failed to enable touchkey\n");
}
return 0;
}
static void stmfts_input_close(struct input_dev *dev)
{
struct stmfts_data *sdata = input_get_drvdata(dev);
int err;
err = i2c_smbus_write_byte(sdata->client, STMFTS_MS_MT_SENSE_OFF);
if (err)
dev_warn(&sdata->client->dev,
"failed to disable touchscreen: %d\n", err);
mutex_lock(&sdata->mutex);
sdata->running = false;
if (sdata->hover_enabled) {
err = i2c_smbus_write_byte(sdata->client,
STMFTS_SS_HOVER_SENSE_OFF);
if (err)
dev_warn(&sdata->client->dev,
"failed to disable hover: %d\n", err);
}
mutex_unlock(&sdata->mutex);
if (sdata->use_key) {
err = i2c_smbus_write_byte(sdata->client,
STMFTS_MS_KEY_SENSE_OFF);
if (err)
dev_warn(&sdata->client->dev,
"failed to disable touchkey: %d\n", err);
}
pm_runtime_put_sync(&sdata->client->dev);
}
static ssize_t stmfts_sysfs_chip_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%#x\n", sdata->chip_id);
}
static ssize_t stmfts_sysfs_chip_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", sdata->chip_ver);
}
static ssize_t stmfts_sysfs_fw_ver(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", sdata->fw_ver);
}
static ssize_t stmfts_sysfs_config_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%#x\n", sdata->config_id);
}
static ssize_t stmfts_sysfs_config_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", sdata->config_ver);
}
static ssize_t stmfts_sysfs_read_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
u8 status[4];
int err;
err = i2c_smbus_read_i2c_block_data(sdata->client, STMFTS_READ_STATUS,
sizeof(status), status);
if (err)
return err;
return sprintf(buf, "%#02x\n", status[0]);
}
static ssize_t stmfts_sysfs_hover_enable_read(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", sdata->hover_enabled);
}
static ssize_t stmfts_sysfs_hover_enable_write(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
unsigned long value;
int err = 0;
if (kstrtoul(buf, 0, &value))
return -EINVAL;
mutex_lock(&sdata->mutex);
if (value & sdata->hover_enabled)
goto out;
if (sdata->running)
err = i2c_smbus_write_byte(sdata->client,
value ? STMFTS_SS_HOVER_SENSE_ON :
STMFTS_SS_HOVER_SENSE_OFF);
if (!err)
sdata->hover_enabled = !!value;
out:
mutex_unlock(&sdata->mutex);
return len;
}
static int stmfts_power_on(struct stmfts_data *sdata)
{
int err;
u8 reg[8];
err = regulator_bulk_enable(ARRAY_SIZE(sdata->regulators),
sdata->regulators);
if (err)
return err;
msleep(20);
err = i2c_smbus_read_i2c_block_data(sdata->client, STMFTS_READ_INFO,
sizeof(reg), reg);
if (err < 0)
return err;
if (err != sizeof(reg))
return -EIO;
sdata->chip_id = be16_to_cpup((__be16 *)&reg[6]);
sdata->chip_ver = reg[0];
sdata->fw_ver = be16_to_cpup((__be16 *)&reg[2]);
sdata->config_id = reg[4];
sdata->config_ver = reg[5];
enable_irq(sdata->client->irq);
msleep(50);
err = stmfts_command(sdata, STMFTS_SYSTEM_RESET);
if (err)
return err;
err = stmfts_command(sdata, STMFTS_SLEEP_OUT);
if (err)
return err;
err = stmfts_command(sdata, STMFTS_MS_CX_TUNING);
if (err)
dev_warn(&sdata->client->dev,
"failed to perform mutual auto tune: %d\n", err);
err = stmfts_command(sdata, STMFTS_SS_CX_TUNING);
if (err)
dev_warn(&sdata->client->dev,
"failed to perform self auto tune: %d\n", err);
err = stmfts_command(sdata, STMFTS_FULL_FORCE_CALIBRATION);
if (err)
return err;
(void) i2c_smbus_write_byte(sdata->client, STMFTS_SLEEP_IN);
return 0;
}
static void stmfts_power_off(void *data)
{
struct stmfts_data *sdata = data;
disable_irq(sdata->client->irq);
regulator_bulk_disable(ARRAY_SIZE(sdata->regulators),
sdata->regulators);
}
static int stmfts_enable_led(struct stmfts_data *sdata)
{
int err;
sdata->ledvdd = devm_regulator_get(&sdata->client->dev, "ledvdd");
if (IS_ERR(sdata->ledvdd))
return PTR_ERR(sdata->ledvdd);
sdata->led_cdev.name = STMFTS_DEV_NAME;
sdata->led_cdev.max_brightness = LED_ON;
sdata->led_cdev.brightness = LED_OFF;
sdata->led_cdev.brightness_set = stmfts_brightness_set;
sdata->led_cdev.brightness_get = stmfts_brightness_get;
err = devm_led_classdev_register(&sdata->client->dev, &sdata->led_cdev);
if (err) {
devm_regulator_put(sdata->ledvdd);
return err;
}
return 0;
}
static int stmfts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err;
struct stmfts_data *sdata;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK))
return -ENODEV;
sdata = devm_kzalloc(&client->dev, sizeof(*sdata), GFP_KERNEL);
if (!sdata)
return -ENOMEM;
i2c_set_clientdata(client, sdata);
sdata->client = client;
mutex_init(&sdata->mutex);
init_completion(&sdata->cmd_done);
sdata->regulators[STMFTS_REGULATOR_VDD].supply = "vdd";
sdata->regulators[STMFTS_REGULATOR_AVDD].supply = "avdd";
err = devm_regulator_bulk_get(&client->dev,
ARRAY_SIZE(sdata->regulators),
sdata->regulators);
if (err)
return err;
sdata->input = devm_input_allocate_device(&client->dev);
if (!sdata->input)
return -ENOMEM;
sdata->input->name = STMFTS_DEV_NAME;
sdata->input->id.bustype = BUS_I2C;
sdata->input->open = stmfts_input_open;
sdata->input->close = stmfts_input_close;
input_set_capability(sdata->input, EV_ABS, ABS_MT_POSITION_X);
input_set_capability(sdata->input, EV_ABS, ABS_MT_POSITION_Y);
touchscreen_parse_properties(sdata->input, true, &sdata->prop);
input_set_abs_params(sdata->input, ABS_MT_TOUCH_MAJOR, 0, 255, 0, 0);
input_set_abs_params(sdata->input, ABS_MT_TOUCH_MINOR, 0, 255, 0, 0);
input_set_abs_params(sdata->input, ABS_MT_ORIENTATION, 0, 255, 0, 0);
input_set_abs_params(sdata->input, ABS_MT_PRESSURE, 0, 255, 0, 0);
input_set_abs_params(sdata->input, ABS_DISTANCE, 0, 255, 0, 0);
sdata->use_key = device_property_read_bool(&client->dev,
"touch-key-connected");
if (sdata->use_key) {
input_set_capability(sdata->input, EV_KEY, KEY_MENU);
input_set_capability(sdata->input, EV_KEY, KEY_BACK);
}
err = input_mt_init_slots(sdata->input,
STMFTS_MAX_FINGERS, INPUT_MT_DIRECT);
if (err)
return err;
input_set_drvdata(sdata->input, sdata);
err = devm_request_threaded_irq(&client->dev, client->irq,
NULL, stmfts_irq_handler,
IRQF_ONESHOT,
"stmfts_irq", sdata);
if (err)
return err;
disable_irq(client->irq);
dev_dbg(&client->dev, "initializing ST-Microelectronics FTS...\n");
err = stmfts_power_on(sdata);
if (err)
return err;
err = devm_add_action_or_reset(&client->dev, stmfts_power_off, sdata);
if (err)
return err;
err = input_register_device(sdata->input);
if (err)
return err;
if (sdata->use_key) {
err = stmfts_enable_led(sdata);
if (err) {
dev_warn(&client->dev, "unable to use touchkey leds\n");
sdata->ledvdd = NULL;
}
}
err = sysfs_create_group(&sdata->client->dev.kobj,
&stmfts_attribute_group);
if (err)
return err;
pm_runtime_enable(&client->dev);
return 0;
}
static int stmfts_remove(struct i2c_client *client)
{
pm_runtime_disable(&client->dev);
sysfs_remove_group(&client->dev.kobj, &stmfts_attribute_group);
return 0;
}
static int __maybe_unused stmfts_runtime_suspend(struct device *dev)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
int ret;
ret = i2c_smbus_write_byte(sdata->client, STMFTS_SLEEP_IN);
if (ret)
dev_warn(dev, "failed to suspend device: %d\n", ret);
return ret;
}
static int __maybe_unused stmfts_runtime_resume(struct device *dev)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
int ret;
ret = i2c_smbus_write_byte(sdata->client, STMFTS_SLEEP_OUT);
if (ret)
dev_err(dev, "failed to resume device: %d\n", ret);
return ret;
}
static int __maybe_unused stmfts_suspend(struct device *dev)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
stmfts_power_off(sdata);
return 0;
}
static int __maybe_unused stmfts_resume(struct device *dev)
{
struct stmfts_data *sdata = dev_get_drvdata(dev);
return stmfts_power_on(sdata);
}
