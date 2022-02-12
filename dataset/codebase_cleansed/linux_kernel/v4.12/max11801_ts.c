static u8 read_register(struct i2c_client *client, int addr)
{
return i2c_smbus_read_byte_data(client, addr << 1);
}
static int max11801_write_reg(struct i2c_client *client, int addr, int data)
{
return i2c_smbus_write_byte_data(client, addr << 1, data);
}
static irqreturn_t max11801_ts_interrupt(int irq, void *dev_id)
{
struct max11801_data *data = dev_id;
struct i2c_client *client = data->client;
int status, i, ret;
u8 buf[XY_BUFSIZE];
int x = -1;
int y = -1;
status = read_register(data->client, GENERNAL_STATUS_REG);
if (status & (MAX11801_FIFO_INT | MAX11801_FIFO_OVERFLOW)) {
status = read_register(data->client, GENERNAL_STATUS_REG);
ret = i2c_smbus_read_i2c_block_data(client, FIFO_RD_CMD,
XY_BUFSIZE, buf);
if (ret < XY_BUFSIZE)
goto out;
for (i = 0; i < XY_BUFSIZE; i += XY_BUFSIZE / 2) {
if ((buf[i + 1] & MEASURE_TAG_MASK) == MEASURE_X_TAG)
x = (buf[i] << XY_BUF_OFFSET) +
(buf[i + 1] >> XY_BUF_OFFSET);
else if ((buf[i + 1] & MEASURE_TAG_MASK) == MEASURE_Y_TAG)
y = (buf[i] << XY_BUF_OFFSET) +
(buf[i + 1] >> XY_BUF_OFFSET);
}
if ((buf[1] & EVENT_TAG_MASK) != (buf[3] & EVENT_TAG_MASK))
goto out;
switch (buf[1] & EVENT_TAG_MASK) {
case EVENT_INIT:
case EVENT_MIDDLE:
input_report_abs(data->input_dev, ABS_X, x);
input_report_abs(data->input_dev, ABS_Y, y);
input_event(data->input_dev, EV_KEY, BTN_TOUCH, 1);
input_sync(data->input_dev);
break;
case EVENT_RELEASE:
input_event(data->input_dev, EV_KEY, BTN_TOUCH, 0);
input_sync(data->input_dev);
break;
case EVENT_FIFO_END:
break;
}
}
out:
return IRQ_HANDLED;
}
static void max11801_ts_phy_init(struct max11801_data *data)
{
struct i2c_client *client = data->client;
max11801_write_reg(client, MESURE_AVER_CONF_REG, 0xff);
max11801_write_reg(client, PANEL_SETUPTIME_CONF_REG, 0x11);
max11801_write_reg(client, TOUCH_DETECT_PULLUP_CONF_REG, 0x10);
max11801_write_reg(client, AUTO_MODE_TIME_CONF_REG, 0xaa);
max11801_write_reg(client, APERTURE_CONF_REG, 0x33);
max11801_write_reg(client, OP_MODE_CONF_REG, 0x36);
}
static int max11801_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max11801_data *data;
struct input_dev *input_dev;
int error;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
input_dev = devm_input_allocate_device(&client->dev);
if (!data || !input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
return -ENOMEM;
}
data->client = client;
data->input_dev = input_dev;
input_dev->name = "max11801_ts";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, MAX11801_MAX_X, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MAX11801_MAX_Y, 0, 0);
max11801_ts_phy_init(data);
error = devm_request_threaded_irq(&client->dev, client->irq, NULL,
max11801_ts_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"max11801_ts", data);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
return error;
}
error = input_register_device(data->input_dev);
if (error)
return error;
return 0;
}
