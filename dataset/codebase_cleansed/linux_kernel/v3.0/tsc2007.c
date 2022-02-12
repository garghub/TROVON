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
static void tsc2007_send_up_event(struct tsc2007 *tsc)
{
struct input_dev *input = tsc->input;
dev_dbg(&tsc->client->dev, "UP\n");
input_report_key(input, BTN_TOUCH, 0);
input_report_abs(input, ABS_PRESSURE, 0);
input_sync(input);
}
static void tsc2007_work(struct work_struct *work)
{
struct tsc2007 *ts =
container_of(to_delayed_work(work), struct tsc2007, work);
bool debounced = false;
struct ts_event tc;
u32 rt;
if (ts->get_pendown_state) {
if (unlikely(!ts->get_pendown_state())) {
tsc2007_send_up_event(ts);
ts->pendown = false;
goto out;
}
dev_dbg(&ts->client->dev, "pen is still down\n");
}
tsc2007_read_values(ts, &tc);
rt = tsc2007_calculate_pressure(ts, &tc);
if (rt > ts->max_rt) {
dev_dbg(&ts->client->dev, "ignored pressure %d\n", rt);
debounced = true;
goto out;
}
if (rt) {
struct input_dev *input = ts->input;
if (!ts->pendown) {
dev_dbg(&ts->client->dev, "DOWN\n");
input_report_key(input, BTN_TOUCH, 1);
ts->pendown = true;
}
input_report_abs(input, ABS_X, tc.x);
input_report_abs(input, ABS_Y, tc.y);
input_report_abs(input, ABS_PRESSURE, rt);
input_sync(input);
dev_dbg(&ts->client->dev, "point(%4d,%4d), pressure (%4u)\n",
tc.x, tc.y, rt);
} else if (!ts->get_pendown_state && ts->pendown) {
tsc2007_send_up_event(ts);
ts->pendown = false;
}
out:
if (ts->pendown || debounced)
schedule_delayed_work(&ts->work,
msecs_to_jiffies(ts->poll_period));
else
enable_irq(ts->irq);
}
static irqreturn_t tsc2007_irq(int irq, void *handle)
{
struct tsc2007 *ts = handle;
if (!ts->get_pendown_state || likely(ts->get_pendown_state())) {
disable_irq_nosync(ts->irq);
schedule_delayed_work(&ts->work,
msecs_to_jiffies(ts->poll_delay));
}
if (ts->clear_penirq)
ts->clear_penirq();
return IRQ_HANDLED;
}
static void tsc2007_free_irq(struct tsc2007 *ts)
{
free_irq(ts->irq, ts);
if (cancel_delayed_work_sync(&ts->work)) {
enable_irq(ts->irq);
}
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
INIT_DELAYED_WORK(&ts->work, tsc2007_work);
ts->model = pdata->model;
ts->x_plate_ohms = pdata->x_plate_ohms;
ts->max_rt = pdata->max_rt ? : MAX_12BIT;
ts->poll_delay = pdata->poll_delay ? : 1;
ts->poll_period = pdata->poll_period ? : 1;
ts->get_pendown_state = pdata->get_pendown_state;
ts->clear_penirq = pdata->clear_penirq;
snprintf(ts->phys, sizeof(ts->phys),
"%s/input0", dev_name(&client->dev));
input_dev->name = "TSC2007 Touchscreen";
input_dev->phys = ts->phys;
input_dev->id.bustype = BUS_I2C;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, MAX_12BIT, pdata->fuzzx, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MAX_12BIT, pdata->fuzzy, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, MAX_12BIT,
pdata->fuzzz, 0);
if (pdata->init_platform_hw)
pdata->init_platform_hw();
err = request_irq(ts->irq, tsc2007_irq, 0,
client->dev.driver->name, ts);
if (err < 0) {
dev_err(&client->dev, "irq %d busy?\n", ts->irq);
goto err_free_mem;
}
err = tsc2007_xfer(ts, PWRDOWN);
if (err < 0)
goto err_free_irq;
err = input_register_device(input_dev);
if (err)
goto err_free_irq;
i2c_set_clientdata(client, ts);
return 0;
err_free_irq:
tsc2007_free_irq(ts);
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
tsc2007_free_irq(ts);
if (pdata->exit_platform_hw)
pdata->exit_platform_hw();
input_unregister_device(ts->input);
kfree(ts);
return 0;
}
static int __init tsc2007_init(void)
{
return i2c_add_driver(&tsc2007_driver);
}
static void __exit tsc2007_exit(void)
{
i2c_del_driver(&tsc2007_driver);
}
