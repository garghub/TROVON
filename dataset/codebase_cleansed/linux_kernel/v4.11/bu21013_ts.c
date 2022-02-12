static int bu21013_read_block_data(struct bu21013_ts_data *data, u8 *buf)
{
int ret, i;
for (i = 0; i < I2C_RETRY_COUNT; i++) {
ret = i2c_smbus_read_i2c_block_data
(data->client, BU21013_SENSORS_BTN_0_7_REG,
LENGTH_OF_BUFFER, buf);
if (ret == LENGTH_OF_BUFFER)
return 0;
}
return -EINVAL;
}
static int bu21013_do_touch_report(struct bu21013_ts_data *data)
{
u8 buf[LENGTH_OF_BUFFER];
unsigned int pos_x[2], pos_y[2];
bool has_x_sensors, has_y_sensors;
int finger_down_count = 0;
int i;
if (data == NULL)
return -EINVAL;
if (bu21013_read_block_data(data, buf) < 0)
return -EINVAL;
has_x_sensors = hweight32(buf[0] & BU21013_SENSORS_EN_0_7);
has_y_sensors = hweight32(((buf[1] & BU21013_SENSORS_EN_8_15) |
((buf[2] & BU21013_SENSORS_EN_16_23) << SHIFT_8)) >> SHIFT_2);
if (!has_x_sensors || !has_y_sensors)
return 0;
for (i = 0; i < MAX_FINGERS; i++) {
const u8 *p = &buf[4 * i + 3];
unsigned int x = p[0] << SHIFT_2 | (p[1] & MASK_BITS);
unsigned int y = p[2] << SHIFT_2 | (p[3] & MASK_BITS);
if (x == 0 || y == 0)
continue;
pos_x[finger_down_count] = x;
pos_y[finger_down_count] = y;
finger_down_count++;
}
if (finger_down_count) {
if (finger_down_count == 2 &&
(abs(pos_x[0] - pos_x[1]) < DELTA_MIN ||
abs(pos_y[0] - pos_y[1]) < DELTA_MIN)) {
return 0;
}
for (i = 0; i < finger_down_count; i++) {
if (data->chip->x_flip)
pos_x[i] = data->chip->touch_x_max - pos_x[i];
if (data->chip->y_flip)
pos_y[i] = data->chip->touch_y_max - pos_y[i];
input_report_abs(data->in_dev,
ABS_MT_POSITION_X, pos_x[i]);
input_report_abs(data->in_dev,
ABS_MT_POSITION_Y, pos_y[i]);
input_mt_sync(data->in_dev);
}
} else
input_mt_sync(data->in_dev);
input_sync(data->in_dev);
return 0;
}
static irqreturn_t bu21013_gpio_irq(int irq, void *device_data)
{
struct bu21013_ts_data *data = device_data;
struct i2c_client *i2c = data->client;
int retval;
do {
retval = bu21013_do_touch_report(data);
if (retval < 0) {
dev_err(&i2c->dev, "bu21013_do_touch_report failed\n");
return IRQ_NONE;
}
data->intr_pin = gpio_get_value(data->chip->touch_pin);
if (data->intr_pin == PEN_DOWN_INTR)
wait_event_timeout(data->wait, data->touch_stopped,
msecs_to_jiffies(2));
} while (!data->intr_pin && !data->touch_stopped);
return IRQ_HANDLED;
}
static int bu21013_init_chip(struct bu21013_ts_data *data)
{
int retval;
struct i2c_client *i2c = data->client;
retval = i2c_smbus_write_byte_data(i2c, BU21013_RESET_REG,
BU21013_RESET_ENABLE);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_RESET reg write failed\n");
return retval;
}
msleep(RESET_DELAY);
retval = i2c_smbus_write_byte_data(i2c, BU21013_SENSOR_0_7_REG,
BU21013_SENSORS_EN_0_7);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_SENSOR_0_7 reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_SENSOR_8_15_REG,
BU21013_SENSORS_EN_8_15);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_SENSOR_8_15 reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_SENSOR_16_23_REG,
BU21013_SENSORS_EN_16_23);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_SENSOR_16_23 reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_POS_MODE1_REG,
(BU21013_POS_MODE1_0 | BU21013_POS_MODE1_1));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_POS_MODE1 reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_POS_MODE2_REG,
(BU21013_POS_MODE2_ZERO | BU21013_POS_MODE2_AVG1 |
BU21013_POS_MODE2_AVG2 | BU21013_POS_MODE2_EN_RAW |
BU21013_POS_MODE2_MULTI));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_POS_MODE2 reg write failed\n");
return retval;
}
if (data->chip->ext_clk)
retval = i2c_smbus_write_byte_data(i2c, BU21013_CLK_MODE_REG,
(BU21013_CLK_MODE_EXT | BU21013_CLK_MODE_CALIB));
else
retval = i2c_smbus_write_byte_data(i2c, BU21013_CLK_MODE_REG,
(BU21013_CLK_MODE_DIV | BU21013_CLK_MODE_CALIB));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_CLK_MODE reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_IDLE_REG,
(BU21013_IDLET_0 | BU21013_IDLE_INTERMIT_EN));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_IDLE reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_INT_MODE_REG,
BU21013_INT_MODE_LEVEL);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_INT_MODE reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_FILTER_REG,
(BU21013_DELTA_0_6 |
BU21013_FILTER_EN));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_FILTER reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_TH_ON_REG,
BU21013_TH_ON_5);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_TH_ON reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_TH_OFF_REG,
BU21013_TH_OFF_4 | BU21013_TH_OFF_3);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_TH_OFF reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_GAIN_REG,
(BU21013_GAIN_0 | BU21013_GAIN_1));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_GAIN reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_OFFSET_MODE_REG,
BU21013_OFFSET_MODE_DEFAULT);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_OFFSET_MODE reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_XY_EDGE_REG,
(BU21013_X_EDGE_0 | BU21013_X_EDGE_2 |
BU21013_Y_EDGE_1 | BU21013_Y_EDGE_3));
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_XY_EDGE reg write failed\n");
return retval;
}
retval = i2c_smbus_write_byte_data(i2c, BU21013_DONE_REG,
BU21013_DONE);
if (retval < 0) {
dev_err(&i2c->dev, "BU21013_REG_DONE reg write failed\n");
return retval;
}
return 0;
}
static void bu21013_free_irq(struct bu21013_ts_data *bu21013_data)
{
bu21013_data->touch_stopped = true;
wake_up(&bu21013_data->wait);
free_irq(bu21013_data->irq, bu21013_data);
}
static void bu21013_cs_disable(struct bu21013_ts_data *bu21013_data)
{
int error;
error = gpio_direction_output(bu21013_data->chip->cs_pin, 0);
if (error < 0)
dev_warn(&bu21013_data->client->dev,
"%s: gpio direction failed, error: %d\n",
__func__, error);
else
gpio_set_value(bu21013_data->chip->cs_pin, 0);
gpio_free(bu21013_data->chip->cs_pin);
}
static const struct bu21013_platform_device *
bu21013_parse_dt(struct device *dev)
{
struct device_node *np = dev->of_node;
struct bu21013_platform_device *pdata;
if (!np) {
dev_err(dev, "no device tree or platform data\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->y_flip = pdata->x_flip = false;
pdata->x_flip = of_property_read_bool(np, "rohm,flip-x");
pdata->y_flip = of_property_read_bool(np, "rohm,flip-y");
of_property_read_u32(np, "rohm,touch-max-x", &pdata->touch_x_max);
of_property_read_u32(np, "rohm,touch-max-y", &pdata->touch_y_max);
pdata->touch_pin = of_get_named_gpio(np, "touch-gpio", 0);
pdata->cs_pin = of_get_named_gpio(np, "reset-gpio", 0);
pdata->ext_clk = false;
return pdata;
}
static inline const struct bu21013_platform_device *
bu21013_parse_dt(struct device *dev)
{
dev_err(dev, "no platform data available\n");
return ERR_PTR(-EINVAL);
}
static int bu21013_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct bu21013_platform_device *pdata =
dev_get_platdata(&client->dev);
struct bu21013_ts_data *bu21013_data;
struct input_dev *in_dev;
int error;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "i2c smbus byte data not supported\n");
return -EIO;
}
if (!pdata) {
pdata = bu21013_parse_dt(&client->dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
}
if (!gpio_is_valid(pdata->touch_pin)) {
dev_err(&client->dev, "invalid touch_pin supplied\n");
return -EINVAL;
}
bu21013_data = kzalloc(sizeof(struct bu21013_ts_data), GFP_KERNEL);
in_dev = input_allocate_device();
if (!bu21013_data || !in_dev) {
dev_err(&client->dev, "device memory alloc failed\n");
error = -ENOMEM;
goto err_free_mem;
}
bu21013_data->in_dev = in_dev;
bu21013_data->chip = pdata;
bu21013_data->client = client;
bu21013_data->irq = gpio_to_irq(pdata->touch_pin);
bu21013_data->regulator = regulator_get(&client->dev, "avdd");
if (IS_ERR(bu21013_data->regulator)) {
dev_err(&client->dev, "regulator_get failed\n");
error = PTR_ERR(bu21013_data->regulator);
goto err_free_mem;
}
error = regulator_enable(bu21013_data->regulator);
if (error < 0) {
dev_err(&client->dev, "regulator enable failed\n");
goto err_put_regulator;
}
bu21013_data->touch_stopped = false;
init_waitqueue_head(&bu21013_data->wait);
error = gpio_request_one(pdata->cs_pin, GPIOF_OUT_INIT_HIGH,
"touchp_reset");
if (error < 0) {
dev_err(&client->dev, "Unable to request gpio reset_pin\n");
goto err_disable_regulator;
}
error = bu21013_init_chip(bu21013_data);
if (error) {
dev_err(&client->dev, "error in bu21013 config\n");
goto err_cs_disable;
}
in_dev->name = DRIVER_TP;
in_dev->id.bustype = BUS_I2C;
in_dev->dev.parent = &client->dev;
__set_bit(EV_SYN, in_dev->evbit);
__set_bit(EV_KEY, in_dev->evbit);
__set_bit(EV_ABS, in_dev->evbit);
input_set_abs_params(in_dev, ABS_MT_POSITION_X, 0,
pdata->touch_x_max, 0, 0);
input_set_abs_params(in_dev, ABS_MT_POSITION_Y, 0,
pdata->touch_y_max, 0, 0);
input_set_drvdata(in_dev, bu21013_data);
error = request_threaded_irq(bu21013_data->irq, NULL, bu21013_gpio_irq,
IRQF_TRIGGER_FALLING | IRQF_SHARED |
IRQF_ONESHOT,
DRIVER_TP, bu21013_data);
if (error) {
dev_err(&client->dev, "request irq %d failed\n",
bu21013_data->irq);
goto err_cs_disable;
}
error = input_register_device(in_dev);
if (error) {
dev_err(&client->dev, "failed to register input device\n");
goto err_free_irq;
}
device_init_wakeup(&client->dev, pdata->wakeup);
i2c_set_clientdata(client, bu21013_data);
return 0;
err_free_irq:
bu21013_free_irq(bu21013_data);
err_cs_disable:
bu21013_cs_disable(bu21013_data);
err_disable_regulator:
regulator_disable(bu21013_data->regulator);
err_put_regulator:
regulator_put(bu21013_data->regulator);
err_free_mem:
input_free_device(in_dev);
kfree(bu21013_data);
return error;
}
static int bu21013_remove(struct i2c_client *client)
{
struct bu21013_ts_data *bu21013_data = i2c_get_clientdata(client);
bu21013_free_irq(bu21013_data);
bu21013_cs_disable(bu21013_data);
input_unregister_device(bu21013_data->in_dev);
regulator_disable(bu21013_data->regulator);
regulator_put(bu21013_data->regulator);
kfree(bu21013_data);
return 0;
}
static int bu21013_suspend(struct device *dev)
{
struct bu21013_ts_data *bu21013_data = dev_get_drvdata(dev);
struct i2c_client *client = bu21013_data->client;
bu21013_data->touch_stopped = true;
if (device_may_wakeup(&client->dev))
enable_irq_wake(bu21013_data->irq);
else
disable_irq(bu21013_data->irq);
regulator_disable(bu21013_data->regulator);
return 0;
}
static int bu21013_resume(struct device *dev)
{
struct bu21013_ts_data *bu21013_data = dev_get_drvdata(dev);
struct i2c_client *client = bu21013_data->client;
int retval;
retval = regulator_enable(bu21013_data->regulator);
if (retval < 0) {
dev_err(&client->dev, "bu21013 regulator enable failed\n");
return retval;
}
retval = bu21013_init_chip(bu21013_data);
if (retval < 0) {
dev_err(&client->dev, "bu21013 controller config failed\n");
return retval;
}
bu21013_data->touch_stopped = false;
if (device_may_wakeup(&client->dev))
disable_irq_wake(bu21013_data->irq);
else
enable_irq(bu21013_data->irq);
return 0;
}
