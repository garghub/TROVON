static int st1232_ts_read_data(struct st1232_ts_data *ts)
{
struct st1232_ts_finger *finger = ts->finger;
struct i2c_client *client = ts->client;
struct i2c_msg msg[2];
int error;
u8 start_reg;
u8 buf[10];
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = 1;
msg[0].buf = &start_reg;
start_reg = 0x10;
msg[1].addr = ts->client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = sizeof(buf);
msg[1].buf = buf;
error = i2c_transfer(client->adapter, msg, 2);
if (error < 0)
return error;
finger[0].is_valid = buf[2] >> 7;
finger[1].is_valid = buf[5] >> 7;
if (finger[0].is_valid) {
finger[0].x = ((buf[2] & 0x0070) << 4) | buf[3];
finger[0].y = ((buf[2] & 0x0007) << 8) | buf[4];
finger[0].t = buf[8];
}
if (finger[1].is_valid) {
finger[1].x = ((buf[5] & 0x0070) << 4) | buf[6];
finger[1].y = ((buf[5] & 0x0007) << 8) | buf[7];
finger[1].t = buf[9];
}
return 0;
}
static irqreturn_t st1232_ts_irq_handler(int irq, void *dev_id)
{
struct st1232_ts_data *ts = dev_id;
struct st1232_ts_finger *finger = ts->finger;
struct input_dev *input_dev = ts->input_dev;
int count = 0;
int i, ret;
ret = st1232_ts_read_data(ts);
if (ret < 0)
goto end;
for (i = 0; i < MAX_FINGERS; i++) {
if (!finger[i].is_valid)
continue;
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR, finger[i].t);
input_report_abs(input_dev, ABS_MT_POSITION_X, finger[i].x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, finger[i].y);
input_mt_sync(input_dev);
count++;
}
if (!count) {
input_mt_sync(input_dev);
if (ts->low_latency_req.dev) {
dev_pm_qos_remove_request(&ts->low_latency_req);
ts->low_latency_req.dev = NULL;
}
} else if (!ts->low_latency_req.dev) {
dev_pm_qos_add_ancestor_request(&ts->client->dev,
&ts->low_latency_req, 100);
}
input_sync(input_dev);
end:
return IRQ_HANDLED;
}
static int __devinit st1232_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct st1232_ts_data *ts;
struct input_dev *input_dev;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "need I2C_FUNC_I2C\n");
return -EIO;
}
if (!client->irq) {
dev_err(&client->dev, "no IRQ?\n");
return -EINVAL;
}
ts = kzalloc(sizeof(struct st1232_ts_data), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ts || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
ts->client = client;
ts->input_dev = input_dev;
input_dev->name = "st1232-touchscreen";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
__set_bit(EV_SYN, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR, 0, MAX_AREA, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_X, MIN_X, MAX_X, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, MIN_Y, MAX_Y, 0, 0);
error = request_threaded_irq(client->irq, NULL, st1232_ts_irq_handler,
IRQF_ONESHOT, client->name, ts);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
goto err_free_mem;
}
error = input_register_device(ts->input_dev);
if (error) {
dev_err(&client->dev, "Unable to register %s input device\n",
input_dev->name);
goto err_free_irq;
}
i2c_set_clientdata(client, ts);
device_init_wakeup(&client->dev, 1);
return 0;
err_free_irq:
free_irq(client->irq, ts);
err_free_mem:
input_free_device(input_dev);
kfree(ts);
return error;
}
static int __devexit st1232_ts_remove(struct i2c_client *client)
{
struct st1232_ts_data *ts = i2c_get_clientdata(client);
device_init_wakeup(&client->dev, 0);
free_irq(client->irq, ts);
input_unregister_device(ts->input_dev);
kfree(ts);
return 0;
}
static int st1232_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
else
disable_irq(client->irq);
return 0;
}
static int st1232_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
else
enable_irq(client->irq);
return 0;
}
static int __init st1232_ts_init(void)
{
return i2c_add_driver(&st1232_ts_driver);
}
static void __exit st1232_ts_exit(void)
{
i2c_del_driver(&st1232_ts_driver);
}
