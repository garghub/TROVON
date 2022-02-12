static void eeti_ts_report_event(struct eeti_ts *eeti, u8 *buf)
{
unsigned int res;
u16 x, y;
res = REPORT_RES_BITS(buf[0] & (REPORT_BIT_AD0 | REPORT_BIT_AD1));
x = get_unaligned_be16(&buf[1]);
y = get_unaligned_be16(&buf[3]);
x >>= res - EETI_TS_BITDEPTH;
y >>= res - EETI_TS_BITDEPTH;
if (flip_x)
x = EETI_MAXVAL - x;
if (flip_y)
y = EETI_MAXVAL - y;
if (buf[0] & REPORT_BIT_HAS_PRESSURE)
input_report_abs(eeti->input, ABS_PRESSURE, buf[5]);
input_report_abs(eeti->input, ABS_X, x);
input_report_abs(eeti->input, ABS_Y, y);
input_report_key(eeti->input, BTN_TOUCH, buf[0] & REPORT_BIT_PRESSED);
input_sync(eeti->input);
}
static irqreturn_t eeti_ts_isr(int irq, void *dev_id)
{
struct eeti_ts *eeti = dev_id;
int len;
int error;
char buf[6];
do {
len = i2c_master_recv(eeti->client, buf, sizeof(buf));
if (len != sizeof(buf)) {
error = len < 0 ? len : -EIO;
dev_err(&eeti->client->dev,
"failed to read touchscreen data: %d\n",
error);
break;
}
if (buf[0] & 0x80) {
eeti_ts_report_event(eeti, buf);
}
} while (eeti->running &&
eeti->attn_gpio && gpiod_get_value_cansleep(eeti->attn_gpio));
return IRQ_HANDLED;
}
static void eeti_ts_start(struct eeti_ts *eeti)
{
eeti->running = true;
wmb();
enable_irq(eeti->client->irq);
}
static void eeti_ts_stop(struct eeti_ts *eeti)
{
eeti->running = false;
wmb();
disable_irq(eeti->client->irq);
}
static int eeti_ts_open(struct input_dev *dev)
{
struct eeti_ts *eeti = input_get_drvdata(dev);
eeti_ts_start(eeti);
return 0;
}
static void eeti_ts_close(struct input_dev *dev)
{
struct eeti_ts *eeti = input_get_drvdata(dev);
eeti_ts_stop(eeti);
}
static int eeti_ts_probe(struct i2c_client *client,
const struct i2c_device_id *idp)
{
struct device *dev = &client->dev;
struct eeti_ts *eeti;
struct input_dev *input;
int error;
eeti = devm_kzalloc(dev, sizeof(*eeti), GFP_KERNEL);
if (!eeti) {
dev_err(dev, "failed to allocate driver data\n");
return -ENOMEM;
}
input = devm_input_allocate_device(dev);
if (!input) {
dev_err(dev, "Failed to allocate input device.\n");
return -ENOMEM;
}
input_set_capability(input, EV_KEY, BTN_TOUCH);
input_set_abs_params(input, ABS_X, 0, EETI_MAXVAL, 0, 0);
input_set_abs_params(input, ABS_Y, 0, EETI_MAXVAL, 0, 0);
input_set_abs_params(input, ABS_PRESSURE, 0, 0xff, 0, 0);
input->name = client->name;
input->id.bustype = BUS_I2C;
input->open = eeti_ts_open;
input->close = eeti_ts_close;
eeti->client = client;
eeti->input = input;
eeti->attn_gpio = devm_gpiod_get_optional(dev, "attn", GPIOD_IN);
if (IS_ERR(eeti->attn_gpio))
return PTR_ERR(eeti->attn_gpio);
i2c_set_clientdata(client, eeti);
input_set_drvdata(input, eeti);
error = devm_request_threaded_irq(dev, client->irq,
NULL, eeti_ts_isr,
IRQF_ONESHOT,
client->name, eeti);
if (error) {
dev_err(dev, "Unable to request touchscreen IRQ: %d\n",
error);
return error;
}
eeti_ts_stop(eeti);
error = input_register_device(input);
if (error)
return error;
return 0;
}
static int __maybe_unused eeti_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct eeti_ts *eeti = i2c_get_clientdata(client);
struct input_dev *input_dev = eeti->input;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
eeti_ts_stop(eeti);
mutex_unlock(&input_dev->mutex);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
return 0;
}
static int __maybe_unused eeti_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct eeti_ts *eeti = i2c_get_clientdata(client);
struct input_dev *input_dev = eeti->input;
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
mutex_lock(&input_dev->mutex);
if (input_dev->users)
eeti_ts_start(eeti);
mutex_unlock(&input_dev->mutex);
return 0;
}
