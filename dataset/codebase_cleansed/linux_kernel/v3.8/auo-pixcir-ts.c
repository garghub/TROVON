static int auo_pixcir_collect_data(struct auo_pixcir_ts *ts,
struct auo_point_t *point)
{
struct i2c_client *client = ts->client;
const struct auo_pixcir_ts_platdata *pdata = client->dev.platform_data;
uint8_t raw_coord[8];
uint8_t raw_area[4];
int i, ret;
ret = i2c_smbus_read_i2c_block_data(client, AUO_PIXCIR_REG_X1_LSB,
8, raw_coord);
if (ret < 0) {
dev_err(&client->dev, "failed to read coordinate, %d\n", ret);
return ret;
}
ret = i2c_smbus_read_i2c_block_data(client, AUO_PIXCIR_REG_TOUCHAREA_X1,
4, raw_area);
if (ret < 0) {
dev_err(&client->dev, "could not read touch area, %d\n", ret);
return ret;
}
for (i = 0; i < AUO_PIXCIR_REPORT_POINTS; i++) {
point[i].coord_x =
raw_coord[4 * i + 1] << 8 | raw_coord[4 * i];
point[i].coord_y =
raw_coord[4 * i + 3] << 8 | raw_coord[4 * i + 2];
if (point[i].coord_x > pdata->x_max ||
point[i].coord_y > pdata->y_max) {
dev_warn(&client->dev, "coordinates (%d,%d) invalid\n",
point[i].coord_x, point[i].coord_y);
point[i].coord_x = point[i].coord_y = 0;
}
point[i].area_major = max(raw_area[2 * i], raw_area[2 * i + 1]);
point[i].area_minor = min(raw_area[2 * i], raw_area[2 * i + 1]);
point[i].orientation = raw_area[2 * i] > raw_area[2 * i + 1];
}
return 0;
}
static irqreturn_t auo_pixcir_interrupt(int irq, void *dev_id)
{
struct auo_pixcir_ts *ts = dev_id;
struct i2c_client *client = ts->client;
const struct auo_pixcir_ts_platdata *pdata = client->dev.platform_data;
struct auo_point_t point[AUO_PIXCIR_REPORT_POINTS];
int i;
int ret;
int fingers = 0;
int abs = -1;
while (!ts->stopped) {
if (ts->touch_ind_mode) {
if (gpio_get_value(pdata->gpio_int) == 0) {
input_mt_sync(ts->input);
input_report_key(ts->input, BTN_TOUCH, 0);
input_sync(ts->input);
break;
}
}
ret = auo_pixcir_collect_data(ts, point);
if (ret < 0) {
if (!ts->touch_ind_mode)
break;
wait_event_timeout(ts->wait, ts->stopped,
msecs_to_jiffies(AUO_PIXCIR_PENUP_TIMEOUT_MS));
continue;
}
for (i = 0; i < AUO_PIXCIR_REPORT_POINTS; i++) {
if (point[i].coord_x > 0 || point[i].coord_y > 0) {
input_report_abs(ts->input, ABS_MT_POSITION_X,
point[i].coord_x);
input_report_abs(ts->input, ABS_MT_POSITION_Y,
point[i].coord_y);
input_report_abs(ts->input, ABS_MT_TOUCH_MAJOR,
point[i].area_major);
input_report_abs(ts->input, ABS_MT_TOUCH_MINOR,
point[i].area_minor);
input_report_abs(ts->input, ABS_MT_ORIENTATION,
point[i].orientation);
input_mt_sync(ts->input);
if (fingers == 0)
abs = i;
fingers++;
}
}
input_report_key(ts->input, BTN_TOUCH, fingers > 0);
if (abs > -1) {
input_report_abs(ts->input, ABS_X, point[abs].coord_x);
input_report_abs(ts->input, ABS_Y, point[abs].coord_y);
}
input_sync(ts->input);
if (!ts->touch_ind_mode)
break;
wait_event_timeout(ts->wait, ts->stopped,
msecs_to_jiffies(AUO_PIXCIR_PENUP_TIMEOUT_MS));
}
return IRQ_HANDLED;
}
static int auo_pixcir_power_mode(struct auo_pixcir_ts *ts, int mode)
{
struct i2c_client *client = ts->client;
int ret;
ret = i2c_smbus_read_byte_data(client, AUO_PIXCIR_REG_POWER_MODE);
if (ret < 0) {
dev_err(&client->dev, "unable to read reg %Xh, %d\n",
AUO_PIXCIR_REG_POWER_MODE, ret);
return ret;
}
ret &= ~AUO_PIXCIR_POWER_MASK;
ret |= mode;
ret = i2c_smbus_write_byte_data(client, AUO_PIXCIR_REG_POWER_MODE, ret);
if (ret) {
dev_err(&client->dev, "unable to write reg %Xh, %d\n",
AUO_PIXCIR_REG_POWER_MODE, ret);
return ret;
}
return 0;
}
static int auo_pixcir_int_config(struct auo_pixcir_ts *ts,
int int_setting)
{
struct i2c_client *client = ts->client;
struct auo_pixcir_ts_platdata *pdata = client->dev.platform_data;
int ret;
ret = i2c_smbus_read_byte_data(client, AUO_PIXCIR_REG_INT_SETTING);
if (ret < 0) {
dev_err(&client->dev, "unable to read reg %Xh, %d\n",
AUO_PIXCIR_REG_INT_SETTING, ret);
return ret;
}
ret &= ~AUO_PIXCIR_INT_MODE_MASK;
ret |= int_setting;
ret |= AUO_PIXCIR_INT_POL_HIGH;
ret = i2c_smbus_write_byte_data(client, AUO_PIXCIR_REG_INT_SETTING,
ret);
if (ret < 0) {
dev_err(&client->dev, "unable to write reg %Xh, %d\n",
AUO_PIXCIR_REG_INT_SETTING, ret);
return ret;
}
ts->touch_ind_mode = pdata->int_setting == AUO_PIXCIR_INT_TOUCH_IND;
return 0;
}
static int auo_pixcir_int_toggle(struct auo_pixcir_ts *ts, bool enable)
{
struct i2c_client *client = ts->client;
int ret;
ret = i2c_smbus_read_byte_data(client, AUO_PIXCIR_REG_INT_SETTING);
if (ret < 0) {
dev_err(&client->dev, "unable to read reg %Xh, %d\n",
AUO_PIXCIR_REG_INT_SETTING, ret);
return ret;
}
if (enable)
ret |= AUO_PIXCIR_INT_ENABLE;
else
ret &= ~AUO_PIXCIR_INT_ENABLE;
ret = i2c_smbus_write_byte_data(client, AUO_PIXCIR_REG_INT_SETTING,
ret);
if (ret < 0) {
dev_err(&client->dev, "unable to write reg %Xh, %d\n",
AUO_PIXCIR_REG_INT_SETTING, ret);
return ret;
}
return 0;
}
static int auo_pixcir_start(struct auo_pixcir_ts *ts)
{
struct i2c_client *client = ts->client;
int ret;
ret = auo_pixcir_power_mode(ts, AUO_PIXCIR_POWER_ACTIVE);
if (ret < 0) {
dev_err(&client->dev, "could not set power mode, %d\n",
ret);
return ret;
}
ts->stopped = false;
mb();
enable_irq(client->irq);
ret = auo_pixcir_int_toggle(ts, 1);
if (ret < 0) {
dev_err(&client->dev, "could not enable interrupt, %d\n",
ret);
disable_irq(client->irq);
return ret;
}
return 0;
}
static int auo_pixcir_stop(struct auo_pixcir_ts *ts)
{
struct i2c_client *client = ts->client;
int ret;
ret = auo_pixcir_int_toggle(ts, 0);
if (ret < 0) {
dev_err(&client->dev, "could not disable interrupt, %d\n",
ret);
return ret;
}
disable_irq(client->irq);
ts->stopped = true;
mb();
wake_up(&ts->wait);
return auo_pixcir_power_mode(ts, AUO_PIXCIR_POWER_DEEP_SLEEP);
}
static int auo_pixcir_input_open(struct input_dev *dev)
{
struct auo_pixcir_ts *ts = input_get_drvdata(dev);
int ret;
ret = auo_pixcir_start(ts);
if (ret)
return ret;
return 0;
}
static void auo_pixcir_input_close(struct input_dev *dev)
{
struct auo_pixcir_ts *ts = input_get_drvdata(dev);
auo_pixcir_stop(ts);
return;
}
static int auo_pixcir_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct auo_pixcir_ts *ts = i2c_get_clientdata(client);
struct input_dev *input = ts->input;
int ret = 0;
mutex_lock(&input->mutex);
if (device_may_wakeup(&client->dev)) {
if (!input->users) {
ret = auo_pixcir_start(ts);
if (ret)
goto unlock;
}
enable_irq_wake(client->irq);
ret = auo_pixcir_power_mode(ts, AUO_PIXCIR_POWER_SLEEP);
} else if (input->users) {
ret = auo_pixcir_stop(ts);
}
unlock:
mutex_unlock(&input->mutex);
return ret;
}
static int auo_pixcir_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct auo_pixcir_ts *ts = i2c_get_clientdata(client);
struct input_dev *input = ts->input;
int ret = 0;
mutex_lock(&input->mutex);
if (device_may_wakeup(&client->dev)) {
disable_irq_wake(client->irq);
if (!input->users) {
ret = auo_pixcir_stop(ts);
if (ret)
goto unlock;
}
} else if (input->users) {
ret = auo_pixcir_start(ts);
}
unlock:
mutex_unlock(&input->mutex);
return ret;
}
static int auo_pixcir_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct auo_pixcir_ts_platdata *pdata = client->dev.platform_data;
struct auo_pixcir_ts *ts;
struct input_dev *input_dev;
int ret;
if (!pdata)
return -EINVAL;
ts = kzalloc(sizeof(struct auo_pixcir_ts), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ret = gpio_request(pdata->gpio_int, "auo_pixcir_ts_int");
if (ret) {
dev_err(&client->dev, "request of gpio %d failed, %d\n",
pdata->gpio_int, ret);
goto err_gpio_int;
}
if (pdata->init_hw)
pdata->init_hw(client);
ts->client = client;
ts->touch_ind_mode = 0;
init_waitqueue_head(&ts->wait);
snprintf(ts->phys, sizeof(ts->phys),
"%s/input0", dev_name(&client->dev));
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(&client->dev, "could not allocate input device\n");
goto err_input_alloc;
}
ts->input = input_dev;
input_dev->name = "AUO-Pixcir touchscreen";
input_dev->phys = ts->phys;
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
input_dev->open = auo_pixcir_input_open;
input_dev->close = auo_pixcir_input_close;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, pdata->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, pdata->y_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0,
pdata->x_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0,
pdata->y_max, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR, 0,
AUO_PIXCIR_MAX_AREA, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR, 0,
AUO_PIXCIR_MAX_AREA, 0, 0);
input_set_abs_params(input_dev, ABS_MT_ORIENTATION, 0, 1, 0, 0);
ret = i2c_smbus_read_byte_data(client, AUO_PIXCIR_REG_VERSION);
if (ret < 0)
goto err_fw_vers;
dev_info(&client->dev, "firmware version 0x%X\n", ret);
ret = auo_pixcir_int_config(ts, pdata->int_setting);
if (ret)
goto err_fw_vers;
input_set_drvdata(ts->input, ts);
ts->stopped = true;
ret = request_threaded_irq(client->irq, NULL, auo_pixcir_interrupt,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
input_dev->name, ts);
if (ret) {
dev_err(&client->dev, "irq %d requested failed\n", client->irq);
goto err_fw_vers;
}
ret = auo_pixcir_stop(ts);
if (ret < 0)
goto err_input_register;
ret = input_register_device(input_dev);
if (ret) {
dev_err(&client->dev, "could not register input device\n");
goto err_input_register;
}
i2c_set_clientdata(client, ts);
return 0;
err_input_register:
free_irq(client->irq, ts);
err_fw_vers:
input_free_device(input_dev);
err_input_alloc:
if (pdata->exit_hw)
pdata->exit_hw(client);
gpio_free(pdata->gpio_int);
err_gpio_int:
kfree(ts);
return ret;
}
static int auo_pixcir_remove(struct i2c_client *client)
{
struct auo_pixcir_ts *ts = i2c_get_clientdata(client);
const struct auo_pixcir_ts_platdata *pdata = client->dev.platform_data;
free_irq(client->irq, ts);
input_unregister_device(ts->input);
if (pdata->exit_hw)
pdata->exit_hw(client);
gpio_free(pdata->gpio_int);
kfree(ts);
return 0;
}
