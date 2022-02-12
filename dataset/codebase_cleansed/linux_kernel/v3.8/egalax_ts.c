static irqreturn_t egalax_ts_interrupt(int irq, void *dev_id)
{
struct egalax_ts *ts = dev_id;
struct input_dev *input_dev = ts->input_dev;
struct i2c_client *client = ts->client;
u8 buf[MAX_I2C_DATA_LEN];
int id, ret, x, y, z;
int tries = 0;
bool down, valid;
u8 state;
do {
ret = i2c_master_recv(client, buf, MAX_I2C_DATA_LEN);
} while (ret == -EAGAIN && tries++ < EGALAX_MAX_TRIES);
if (ret < 0)
return IRQ_HANDLED;
if (buf[0] != REPORT_MODE_MTTOUCH) {
return IRQ_HANDLED;
}
state = buf[1];
x = (buf[3] << 8) | buf[2];
y = (buf[5] << 8) | buf[4];
z = (buf[7] << 8) | buf[6];
valid = state & EVENT_VALID_MASK;
id = (state & EVENT_ID_MASK) >> EVENT_ID_OFFSET;
down = state & EVENT_DOWN_UP;
if (!valid || id > MAX_SUPPORT_POINTS) {
dev_dbg(&client->dev, "point invalid\n");
return IRQ_HANDLED;
}
input_mt_slot(input_dev, id);
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER, down);
dev_dbg(&client->dev, "%s id:%d x:%d y:%d z:%d",
down ? "down" : "up", id, x, y, z);
if (down) {
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
input_report_abs(input_dev, ABS_MT_PRESSURE, z);
}
input_mt_report_pointer_emulation(input_dev, true);
input_sync(input_dev);
return IRQ_HANDLED;
}
static int egalax_wake_up_device(struct i2c_client *client)
{
struct device_node *np = client->dev.of_node;
int gpio;
int ret;
if (!np)
return -ENODEV;
gpio = of_get_named_gpio(np, "wakeup-gpios", 0);
if (!gpio_is_valid(gpio))
return -ENODEV;
ret = gpio_request(gpio, "egalax_irq");
if (ret < 0) {
dev_err(&client->dev,
"request gpio failed, cannot wake up controller: %d\n",
ret);
return ret;
}
gpio_direction_output(gpio, 0);
gpio_set_value(gpio, 1);
gpio_direction_input(gpio);
gpio_free(gpio);
return 0;
}
static int egalax_firmware_version(struct i2c_client *client)
{
static const u8 cmd[MAX_I2C_DATA_LEN] = { 0x03, 0x03, 0xa, 0x01, 0x41 };
int ret;
ret = i2c_master_send(client, cmd, MAX_I2C_DATA_LEN);
if (ret < 0)
return ret;
return 0;
}
static int egalax_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct egalax_ts *ts;
struct input_dev *input_dev;
int ret;
int error;
ts = kzalloc(sizeof(struct egalax_ts), GFP_KERNEL);
if (!ts) {
dev_err(&client->dev, "Failed to allocate memory\n");
return -ENOMEM;
}
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
error = -ENOMEM;
goto err_free_ts;
}
ts->client = client;
ts->input_dev = input_dev;
error = egalax_wake_up_device(client);
if (error) {
dev_err(&client->dev, "Failed to wake up the controller\n");
goto err_free_dev;
}
ret = egalax_firmware_version(client);
if (ret < 0) {
dev_err(&client->dev, "Failed to read firmware version\n");
error = -EIO;
goto err_free_dev;
}
input_dev->name = "EETI eGalax Touch Screen";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, EGALAX_MAX_X, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, EGALAX_MAX_Y, 0, 0);
input_set_abs_params(input_dev,
ABS_MT_POSITION_X, 0, EGALAX_MAX_X, 0, 0);
input_set_abs_params(input_dev,
ABS_MT_POSITION_X, 0, EGALAX_MAX_Y, 0, 0);
input_mt_init_slots(input_dev, MAX_SUPPORT_POINTS, 0);
input_set_drvdata(input_dev, ts);
error = request_threaded_irq(client->irq, NULL, egalax_ts_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"egalax_ts", ts);
if (error < 0) {
dev_err(&client->dev, "Failed to register interrupt\n");
goto err_free_dev;
}
error = input_register_device(ts->input_dev);
if (error)
goto err_free_irq;
i2c_set_clientdata(client, ts);
return 0;
err_free_irq:
free_irq(client->irq, ts);
err_free_dev:
input_free_device(input_dev);
err_free_ts:
kfree(ts);
return error;
}
static int egalax_ts_remove(struct i2c_client *client)
{
struct egalax_ts *ts = i2c_get_clientdata(client);
free_irq(client->irq, ts);
input_unregister_device(ts->input_dev);
kfree(ts);
return 0;
}
static int egalax_ts_suspend(struct device *dev)
{
static const u8 suspend_cmd[MAX_I2C_DATA_LEN] = {
0x3, 0x6, 0xa, 0x3, 0x36, 0x3f, 0x2, 0, 0, 0
};
struct i2c_client *client = to_i2c_client(dev);
int ret;
ret = i2c_master_send(client, suspend_cmd, MAX_I2C_DATA_LEN);
return ret > 0 ? 0 : ret;
}
static int egalax_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
return egalax_wake_up_device(client);
}
