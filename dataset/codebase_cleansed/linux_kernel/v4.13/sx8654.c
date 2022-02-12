static irqreturn_t sx8654_irq(int irq, void *handle)
{
struct sx8654 *sx8654 = handle;
int irqsrc;
u8 data[4];
unsigned int x, y;
int retval;
irqsrc = i2c_smbus_read_byte_data(sx8654->client,
CMD_READ_REGISTER | I2C_REG_IRQSRC);
dev_dbg(&sx8654->client->dev, "irqsrc = 0x%x", irqsrc);
if (irqsrc < 0)
goto out;
if (irqsrc & IRQ_PENRELEASE) {
dev_dbg(&sx8654->client->dev, "pen release interrupt");
input_report_key(sx8654->input, BTN_TOUCH, 0);
input_sync(sx8654->input);
}
if (irqsrc & IRQ_PENTOUCH_TOUCHCONVDONE) {
dev_dbg(&sx8654->client->dev, "pen touch interrupt");
retval = i2c_master_recv(sx8654->client, data, sizeof(data));
if (retval != sizeof(data))
goto out;
if (unlikely(data[0] & 0x80 || data[2] & 0x80))
goto out;
x = ((data[0] & 0xf) << 8) | (data[1]);
y = ((data[2] & 0xf) << 8) | (data[3]);
input_report_abs(sx8654->input, ABS_X, x);
input_report_abs(sx8654->input, ABS_Y, y);
input_report_key(sx8654->input, BTN_TOUCH, 1);
input_sync(sx8654->input);
dev_dbg(&sx8654->client->dev, "point(%4d,%4d)\n", x, y);
}
out:
return IRQ_HANDLED;
}
static int sx8654_open(struct input_dev *dev)
{
struct sx8654 *sx8654 = input_get_drvdata(dev);
struct i2c_client *client = sx8654->client;
int error;
error = i2c_smbus_write_byte_data(client, I2C_REG_TOUCH0,
RATE_5000CPS | POWDLY_1_1MS);
if (error) {
dev_err(&client->dev, "writing to I2C_REG_TOUCH0 failed");
return error;
}
error = i2c_smbus_write_byte(client, CMD_PENTRG);
if (error) {
dev_err(&client->dev, "writing command CMD_PENTRG failed");
return error;
}
enable_irq(client->irq);
return 0;
}
static void sx8654_close(struct input_dev *dev)
{
struct sx8654 *sx8654 = input_get_drvdata(dev);
struct i2c_client *client = sx8654->client;
int error;
disable_irq(client->irq);
error = i2c_smbus_write_byte(client, CMD_MANUAL);
if (error) {
dev_err(&client->dev, "writing command CMD_MANUAL failed");
return;
}
error = i2c_smbus_write_byte_data(client, I2C_REG_TOUCH0, 0);
if (error) {
dev_err(&client->dev, "writing to I2C_REG_TOUCH0 failed");
return;
}
}
static int sx8654_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sx8654 *sx8654;
struct input_dev *input;
int error;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENXIO;
sx8654 = devm_kzalloc(&client->dev, sizeof(*sx8654), GFP_KERNEL);
if (!sx8654)
return -ENOMEM;
input = devm_input_allocate_device(&client->dev);
if (!input)
return -ENOMEM;
input->name = "SX8654 I2C Touchscreen";
input->id.bustype = BUS_I2C;
input->dev.parent = &client->dev;
input->open = sx8654_open;
input->close = sx8654_close;
__set_bit(INPUT_PROP_DIRECT, input->propbit);
input_set_capability(input, EV_KEY, BTN_TOUCH);
input_set_abs_params(input, ABS_X, 0, MAX_12BIT, 0, 0);
input_set_abs_params(input, ABS_Y, 0, MAX_12BIT, 0, 0);
sx8654->client = client;
sx8654->input = input;
input_set_drvdata(sx8654->input, sx8654);
error = i2c_smbus_write_byte_data(client, I2C_REG_SOFTRESET,
SOFTRESET_VALUE);
if (error) {
dev_err(&client->dev, "writing softreset value failed");
return error;
}
error = i2c_smbus_write_byte_data(client, I2C_REG_CHANMASK,
CONV_X | CONV_Y);
if (error) {
dev_err(&client->dev, "writing to I2C_REG_CHANMASK failed");
return error;
}
error = i2c_smbus_write_byte_data(client, I2C_REG_IRQMASK,
IRQ_PENTOUCH_TOUCHCONVDONE |
IRQ_PENRELEASE);
if (error) {
dev_err(&client->dev, "writing to I2C_REG_IRQMASK failed");
return error;
}
error = i2c_smbus_write_byte_data(client, I2C_REG_TOUCH1,
CONDIRQ | FILT_7SA);
if (error) {
dev_err(&client->dev, "writing to I2C_REG_TOUCH1 failed");
return error;
}
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, sx8654_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
client->name, sx8654);
if (error) {
dev_err(&client->dev,
"Failed to enable IRQ %d, error: %d\n",
client->irq, error);
return error;
}
disable_irq(client->irq);
error = input_register_device(sx8654->input);
if (error)
return error;
return 0;
}
