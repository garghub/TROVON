static irqreturn_t ar1021_i2c_irq(int irq, void *dev_id)
{
struct ar1021_i2c *ar1021 = dev_id;
struct input_dev *input = ar1021->input;
u8 *data = ar1021->data;
unsigned int x, y, button;
int retval;
retval = i2c_master_recv(ar1021->client,
ar1021->data, sizeof(ar1021->data));
if (retval != sizeof(ar1021->data))
goto out;
if ((data[0] & 0x80) == 0)
goto out;
button = data[0] & BIT(0);
x = ((data[2] & 0x1f) << 7) | (data[1] & 0x7f);
y = ((data[4] & 0x1f) << 7) | (data[3] & 0x7f);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
input_report_key(input, BTN_TOUCH, button);
input_sync(input);
out:
return IRQ_HANDLED;
}
static int ar1021_i2c_open(struct input_dev *dev)
{
struct ar1021_i2c *ar1021 = input_get_drvdata(dev);
struct i2c_client *client = ar1021->client;
enable_irq(client->irq);
return 0;
}
static void ar1021_i2c_close(struct input_dev *dev)
{
struct ar1021_i2c *ar1021 = input_get_drvdata(dev);
struct i2c_client *client = ar1021->client;
disable_irq(client->irq);
}
static int ar1021_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ar1021_i2c *ar1021;
struct input_dev *input;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "i2c_check_functionality error\n");
return -ENXIO;
}
ar1021 = devm_kzalloc(&client->dev, sizeof(*ar1021), GFP_KERNEL);
if (!ar1021)
return -ENOMEM;
input = devm_input_allocate_device(&client->dev);
if (!input)
return -ENOMEM;
ar1021->client = client;
ar1021->input = input;
input->name = "ar1021 I2C Touchscreen";
input->id.bustype = BUS_I2C;
input->dev.parent = &client->dev;
input->open = ar1021_i2c_open;
input->close = ar1021_i2c_close;
input_set_capability(input, EV_KEY, BTN_TOUCH);
input_set_abs_params(input, ABS_X, 0, AR1021_MAX_X, 0, 0);
input_set_abs_params(input, ABS_Y, 0, AR1021_MAX_Y, 0, 0);
input_set_drvdata(input, ar1021);
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, ar1021_i2c_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"ar1021_i2c", ar1021);
if (error) {
dev_err(&client->dev,
"Failed to enable IRQ, error: %d\n", error);
return error;
}
disable_irq(client->irq);
error = input_register_device(ar1021->input);
if (error) {
dev_err(&client->dev,
"Failed to register input device, error: %d\n", error);
return error;
}
i2c_set_clientdata(client, ar1021);
return 0;
}
static int __maybe_unused ar1021_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
disable_irq(client->irq);
return 0;
}
static int __maybe_unused ar1021_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
enable_irq(client->irq);
return 0;
}
