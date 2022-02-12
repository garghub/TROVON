static inline int tsc2007_xfer(struct tsc2007 *tsc, u8 cmd)
{
s32 data;
u16 val;
data = i2c_smbus_read_word_data(tsc->client, cmd);
if (data < 0) {
dev_err(&tsc->client->dev, "i2c io error: %d\n", data);
return data;
}
val = swab16(data) >> 4;
dev_dbg(&tsc->client->dev, "data: 0x%x, val: 0x%x\n", data, val);
return val;
}
static void tsc2007_read_values(struct tsc2007 *tsc, struct ts_event *tc)
{
tc->y = tsc2007_xfer(tsc, READ_Y);
tc->x = tsc2007_xfer(tsc, READ_X);
tc->z1 = tsc2007_xfer(tsc, READ_Z1);
tc->z2 = tsc2007_xfer(tsc, READ_Z2);
tsc2007_xfer(tsc, PWRDOWN);
}
static u32 tsc2007_calculate_pressure(struct tsc2007 *tsc, struct ts_event *tc)
{
u32 rt = 0;
if (tc->x == MAX_12BIT)
tc->x = 0;
if (likely(tc->x && tc->z1)) {
rt = tc->z2 - tc->z1;
rt *= tc->x;
rt *= tsc->x_plate_ohms;
rt /= tc->z1;
rt = (rt + 2047) >> 12;
}
return rt;
}
static bool tsc2007_is_pen_down(struct tsc2007 *ts)
{
if (!ts->get_pendown_state)
return true;
return ts->get_pendown_state();
}
static irqreturn_t tsc2007_soft_irq(int irq, void *handle)
{
struct tsc2007 *ts = handle;
struct input_dev *input = ts->input;
struct ts_event tc;
u32 rt;
while (!ts->stopped && tsc2007_is_pen_down(ts)) {
tsc2007_read_values(ts, &tc);
rt = tsc2007_calculate_pressure(ts, &tc);
if (rt == 0 && !ts->get_pendown_state) {
break;
}
if (rt <= ts->max_rt) {
dev_dbg(&ts->client->dev,
"DOWN point(%4d,%4d), pressure (%4u)\n",
tc.x, tc.y, rt);
input_report_key(input, BTN_TOUCH, 1);
input_report_abs(input, ABS_X, tc.x);
input_report_abs(input, ABS_Y, tc.y);
input_report_abs(input, ABS_PRESSURE, rt);
input_sync(input);
} else {
dev_dbg(&ts->client->dev, "ignored pressure %d\n", rt);
}
wait_event_timeout(ts->wait, ts->stopped,
msecs_to_jiffies(ts->poll_period));
}
dev_dbg(&ts->client->dev, "UP\n");
input_report_key(input, BTN_TOUCH, 0);
input_report_abs(input, ABS_PRESSURE, 0);
input_sync(input);
if (ts->clear_penirq)
ts->clear_penirq();
return IRQ_HANDLED;
}
static irqreturn_t tsc2007_hard_irq(int irq, void *handle)
{
struct tsc2007 *ts = handle;
if (!ts->get_pendown_state || likely(ts->get_pendown_state()))
return IRQ_WAKE_THREAD;
if (ts->clear_penirq)
ts->clear_penirq();
return IRQ_HANDLED;
}
static void tsc2007_stop(struct tsc2007 *ts)
{
ts->stopped = true;
mb();
wake_up(&ts->wait);
disable_irq(ts->irq);
}
static int tsc2007_open(struct input_dev *input_dev)
{
struct tsc2007 *ts = input_get_drvdata(input_dev);
int err;
ts->stopped = false;
mb();
enable_irq(ts->irq);
err = tsc2007_xfer(ts, PWRDOWN);
if (err < 0) {
tsc2007_stop(ts);
return err;
}
return 0;
}
static void tsc2007_close(struct input_dev *input_dev)
{
struct tsc2007 *ts = input_get_drvdata(input_dev);
tsc2007_stop(ts);
}
static int __devinit tsc2007_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tsc2007 *ts;
struct tsc2007_platform_data *pdata = client->dev.platform_data;
struct input_dev *input_dev;
int err;
if (!pdata) {
dev_err(&client->dev, "platform data is required!\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -EIO;
ts = kzalloc(sizeof(struct tsc2007), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ts || !input_dev) {
err = -ENOMEM;
goto err_free_mem;
}
ts->client = client;
ts->irq = client->irq;
ts->input = input_dev;
init_waitqueue_head(&ts->wait);
ts->model = pdata->model;
ts->x_plate_ohms = pdata->x_plate_ohms;
ts->max_rt = pdata->max_rt ? : MAX_12BIT;
ts->poll_delay = pdata->poll_delay ? : 1;
ts->poll_period = pdata->poll_period ? : 1;
ts->get_pendown_state = pdata->get_pendown_state;
ts->clear_penirq = pdata->clear_penirq;
if (pdata->x_plate_ohms == 0) {
dev_err(&client->dev, "x_plate_ohms is not set up in platform data");
err = -EINVAL;
goto err_free_mem;
}
snprintf(ts->phys, sizeof(ts->phys),
"%s/input0", dev_name(&client->dev));
input_dev->name = "TSC2007 Touchscreen";
input_dev->phys = ts->phys;
input_dev->id.bustype = BUS_I2C;
input_dev->open = tsc2007_open;
input_dev->close = tsc2007_close;
input_set_drvdata(input_dev, ts);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, MAX_12BIT, pdata->fuzzx, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MAX_12BIT, pdata->fuzzy, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, MAX_12BIT,
pdata->fuzzz, 0);
if (pdata->init_platform_hw)
pdata->init_platform_hw();
err = request_threaded_irq(ts->irq, tsc2007_hard_irq, tsc2007_soft_irq,
IRQF_ONESHOT, client->dev.driver->name, ts);
if (err < 0) {
dev_err(&client->dev, "irq %d busy?\n", ts->irq);
goto err_free_mem;
}
tsc2007_stop(ts);
err = input_register_device(input_dev);
if (err)
goto err_free_irq;
i2c_set_clientdata(client, ts);
return 0;
err_free_irq:
free_irq(ts->irq, ts);
if (pdata->exit_platform_hw)
pdata->exit_platform_hw();
err_free_mem:
input_free_device(input_dev);
kfree(ts);
return err;
}
static int __devexit tsc2007_remove(struct i2c_client *client)
{
struct tsc2007 *ts = i2c_get_clientdata(client);
struct tsc2007_platform_data *pdata = client->dev.platform_data;
free_irq(ts->irq, ts);
if (pdata->exit_platform_hw)
pdata->exit_platform_hw();
input_unregister_device(ts->input);
kfree(ts);
return 0;
}
