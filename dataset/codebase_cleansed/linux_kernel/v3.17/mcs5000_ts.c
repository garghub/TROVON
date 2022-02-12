static irqreturn_t mcs5000_ts_interrupt(int irq, void *dev_id)
{
struct mcs5000_ts_data *data = dev_id;
struct i2c_client *client = data->client;
u8 buffer[READ_BLOCK_SIZE];
int err;
int x;
int y;
err = i2c_smbus_read_i2c_block_data(client, MCS5000_TS_INPUT_INFO,
READ_BLOCK_SIZE, buffer);
if (err < 0) {
dev_err(&client->dev, "%s, err[%d]\n", __func__, err);
goto out;
}
switch (buffer[READ_INPUT_INFO]) {
case INPUT_TYPE_NONTOUCH:
input_report_key(data->input_dev, BTN_TOUCH, 0);
input_sync(data->input_dev);
break;
case INPUT_TYPE_SINGLE:
x = (buffer[READ_X_POS_UPPER] << 8) | buffer[READ_X_POS_LOWER];
y = (buffer[READ_Y_POS_UPPER] << 8) | buffer[READ_Y_POS_LOWER];
input_report_key(data->input_dev, BTN_TOUCH, 1);
input_report_abs(data->input_dev, ABS_X, x);
input_report_abs(data->input_dev, ABS_Y, y);
input_sync(data->input_dev);
break;
case INPUT_TYPE_DUAL:
break;
case INPUT_TYPE_PALM:
break;
case INPUT_TYPE_PROXIMITY:
break;
default:
dev_err(&client->dev, "Unknown ts input type %d\n",
buffer[READ_INPUT_INFO]);
break;
}
out:
return IRQ_HANDLED;
}
static void mcs5000_ts_phys_init(struct mcs5000_ts_data *data,
const struct mcs_platform_data *platform_data)
{
struct i2c_client *client = data->client;
i2c_smbus_write_byte_data(client, MCS5000_TS_OP_MODE,
RESET_EXT_SOFT | OP_MODE_SLEEP);
i2c_smbus_write_byte_data(client, MCS5000_TS_X_SIZE_UPPER,
platform_data->x_size >> 8);
i2c_smbus_write_byte_data(client, MCS5000_TS_X_SIZE_LOWER,
platform_data->x_size & 0xff);
i2c_smbus_write_byte_data(client, MCS5000_TS_Y_SIZE_UPPER,
platform_data->y_size >> 8);
i2c_smbus_write_byte_data(client, MCS5000_TS_Y_SIZE_LOWER,
platform_data->y_size & 0xff);
i2c_smbus_write_byte_data(data->client, MCS5000_TS_OP_MODE,
OP_MODE_ACTIVE | REPORT_RATE_80);
}
static int mcs5000_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct mcs_platform_data *pdata;
struct mcs5000_ts_data *data;
struct input_dev *input_dev;
int error;
pdata = dev_get_platdata(&client->dev);
if (!pdata)
return -EINVAL;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&client->dev, "Failed to allocate memory\n");
return -ENOMEM;
}
data->client = client;
input_dev = devm_input_allocate_device(&client->dev);
if (!input_dev) {
dev_err(&client->dev, "Failed to allocate input device\n");
return -ENOMEM;
}
input_dev->name = "MELFAS MCS-5000 Touchscreen";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, MCS5000_MAX_XC, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MCS5000_MAX_YC, 0, 0);
input_set_drvdata(input_dev, data);
data->input_dev = input_dev;
if (pdata->cfg_pin)
pdata->cfg_pin();
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, mcs5000_ts_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"mcs5000_ts", data);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
return error;
}
error = input_register_device(data->input_dev);
if (error) {
dev_err(&client->dev, "Failed to register input device\n");
return error;
}
mcs5000_ts_phys_init(data, pdata);
i2c_set_clientdata(client, data);
return 0;
}
static int __maybe_unused mcs5000_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
i2c_smbus_write_byte_data(client, MCS5000_TS_OP_MODE, OP_MODE_SLEEP);
return 0;
}
static int __maybe_unused mcs5000_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mcs5000_ts_data *data = i2c_get_clientdata(client);
const struct mcs_platform_data *pdata = dev_get_platdata(dev);
mcs5000_ts_phys_init(data, pdata);
return 0;
}
