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
static void mcs5000_ts_phys_init(struct mcs5000_ts_data *data)
{
const struct mcs_platform_data *platform_data =
data->platform_data;
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
static int __devinit mcs5000_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mcs5000_ts_data *data;
struct input_dev *input_dev;
int ret;
if (!client->dev.platform_data)
return -EINVAL;
data = kzalloc(sizeof(struct mcs5000_ts_data), GFP_KERNEL);
input_dev = input_allocate_device();
if (!data || !input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
ret = -ENOMEM;
goto err_free_mem;
}
data->client = client;
data->input_dev = input_dev;
data->platform_data = client->dev.platform_data;
input_dev->name = "MELPAS MCS-5000 Touchscreen";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, MCS5000_MAX_XC, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MCS5000_MAX_YC, 0, 0);
input_set_drvdata(input_dev, data);
if (data->platform_data->cfg_pin)
data->platform_data->cfg_pin();
ret = request_threaded_irq(client->irq, NULL, mcs5000_ts_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT, "mcs5000_ts", data);
if (ret < 0) {
dev_err(&client->dev, "Failed to register interrupt\n");
goto err_free_mem;
}
ret = input_register_device(data->input_dev);
if (ret < 0)
goto err_free_irq;
mcs5000_ts_phys_init(data);
i2c_set_clientdata(client, data);
return 0;
err_free_irq:
free_irq(client->irq, data);
err_free_mem:
input_free_device(input_dev);
kfree(data);
return ret;
}
static int __devexit mcs5000_ts_remove(struct i2c_client *client)
{
struct mcs5000_ts_data *data = i2c_get_clientdata(client);
free_irq(client->irq, data);
input_unregister_device(data->input_dev);
kfree(data);
return 0;
}
static int mcs5000_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
i2c_smbus_write_byte_data(client, MCS5000_TS_OP_MODE, OP_MODE_SLEEP);
return 0;
}
static int mcs5000_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mcs5000_ts_data *data = i2c_get_clientdata(client);
mcs5000_ts_phys_init(data);
return 0;
}
static int __init mcs5000_ts_init(void)
{
return i2c_add_driver(&mcs5000_ts_driver);
}
static void __exit mcs5000_ts_exit(void)
{
i2c_del_driver(&mcs5000_ts_driver);
}
