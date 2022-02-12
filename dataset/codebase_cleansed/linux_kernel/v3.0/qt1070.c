static int qt1070_read(struct i2c_client *client, u8 reg)
{
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
dev_err(&client->dev,
"can not read register, returned %d\n", ret);
return ret;
}
static int qt1070_write(struct i2c_client *client, u8 reg, u8 data)
{
int ret;
ret = i2c_smbus_write_byte_data(client, reg, data);
if (ret < 0)
dev_err(&client->dev,
"can not write register, returned %d\n", ret);
return ret;
}
static bool __devinit qt1070_identify(struct i2c_client *client)
{
int id, ver;
id = qt1070_read(client, CHIP_ID);
if (id != QT1070_CHIP_ID) {
dev_err(&client->dev, "ID %d not supported\n", id);
return false;
}
ver = qt1070_read(client, FW_VERSION);
if (ver < 0) {
dev_err(&client->dev, "could not read the firmware version\n");
return false;
}
dev_info(&client->dev, "AT42QT1070 firmware version %x\n", ver);
return true;
}
static irqreturn_t qt1070_interrupt(int irq, void *dev_id)
{
struct qt1070_data *data = dev_id;
struct i2c_client *client = data->client;
struct input_dev *input = data->input;
int i;
u8 new_keys, keyval, mask = 0x01;
qt1070_read(client, DET_STATUS);
new_keys = qt1070_read(client, KEY_STATUS);
for (i = 0; i < ARRAY_SIZE(qt1070_key2code); i++) {
keyval = new_keys & mask;
if ((data->last_keys & mask) != keyval)
input_report_key(input, data->keycodes[i], keyval);
mask <<= 1;
}
input_sync(input);
data->last_keys = new_keys;
return IRQ_HANDLED;
}
static int __devinit qt1070_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct qt1070_data *data;
struct input_dev *input;
int i;
int err;
err = i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE);
if (!err) {
dev_err(&client->dev, "%s adapter not supported\n",
dev_driver_string(&client->adapter->dev));
return -ENODEV;
}
if (!client->irq) {
dev_err(&client->dev, "please assign the irq to this device\n");
return -EINVAL;
}
if (!qt1070_identify(client))
return -ENODEV;
data = kzalloc(sizeof(struct qt1070_data), GFP_KERNEL);
input = input_allocate_device();
if (!data || !input) {
dev_err(&client->dev, "insufficient memory\n");
err = -ENOMEM;
goto err_free_mem;
}
data->client = client;
data->input = input;
data->irq = client->irq;
input->name = "AT42QT1070 QTouch Sensor";
input->dev.parent = &client->dev;
input->id.bustype = BUS_I2C;
input->keycode = data->keycodes;
input->keycodesize = sizeof(data->keycodes[0]);
input->keycodemax = ARRAY_SIZE(qt1070_key2code);
__set_bit(EV_KEY, input->evbit);
for (i = 0; i < ARRAY_SIZE(qt1070_key2code); i++) {
data->keycodes[i] = qt1070_key2code[i];
__set_bit(qt1070_key2code[i], input->keybit);
}
qt1070_write(client, CALIBRATE_CMD, 1);
msleep(QT1070_CAL_TIME);
qt1070_write(client, RESET, 1);
msleep(QT1070_RESET_TIME);
err = request_threaded_irq(client->irq, NULL, qt1070_interrupt,
IRQF_TRIGGER_NONE, client->dev.driver->name, data);
if (err) {
dev_err(&client->dev, "fail to request irq\n");
goto err_free_mem;
}
err = input_register_device(data->input);
if (err) {
dev_err(&client->dev, "Failed to register input device\n");
goto err_free_irq;
}
i2c_set_clientdata(client, data);
qt1070_read(client, DET_STATUS);
return 0;
err_free_irq:
free_irq(client->irq, data);
err_free_mem:
input_free_device(input);
kfree(data);
return err;
}
static int __devexit qt1070_remove(struct i2c_client *client)
{
struct qt1070_data *data = i2c_get_clientdata(client);
free_irq(client->irq, data);
input_unregister_device(data->input);
kfree(data);
i2c_set_clientdata(client, NULL);
return 0;
}
static int __init qt1070_init(void)
{
return i2c_add_driver(&qt1070_driver);
}
static void __exit qt1070_exit(void)
{
i2c_del_driver(&qt1070_driver);
}
