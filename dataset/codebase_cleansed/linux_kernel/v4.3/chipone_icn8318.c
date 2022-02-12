static int icn8318_read_touch_data(struct i2c_client *client,
struct icn8318_touch_data *touch_data)
{
u8 reg = ICN8318_REG_TOUCHDATA;
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.len = 1,
.buf = &reg
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = sizeof(struct icn8318_touch_data),
.buf = (u8 *)touch_data
}
};
return i2c_transfer(client->adapter, msg, 2);
}
static inline bool icn8318_touch_active(u8 event)
{
return (event == ICN8318_EVENT_UPDATE1) ||
(event == ICN8318_EVENT_UPDATE2);
}
static irqreturn_t icn8318_irq(int irq, void *dev_id)
{
struct icn8318_data *data = dev_id;
struct device *dev = &data->client->dev;
struct icn8318_touch_data touch_data;
int i, ret, x, y;
ret = icn8318_read_touch_data(data->client, &touch_data);
if (ret < 0) {
dev_err(dev, "Error reading touch data: %d\n", ret);
return IRQ_HANDLED;
}
if (touch_data.softbutton) {
return IRQ_HANDLED;
}
if (touch_data.touch_count > ICN8318_MAX_TOUCHES) {
dev_warn(dev, "Too much touches %d > %d\n",
touch_data.touch_count, ICN8318_MAX_TOUCHES);
touch_data.touch_count = ICN8318_MAX_TOUCHES;
}
for (i = 0; i < touch_data.touch_count; i++) {
struct icn8318_touch *touch = &touch_data.touches[i];
bool act = icn8318_touch_active(touch->event);
input_mt_slot(data->input, touch->slot);
input_mt_report_slot_state(data->input, MT_TOOL_FINGER, act);
if (!act)
continue;
x = be16_to_cpu(touch->x);
y = be16_to_cpu(touch->y);
if (data->invert_x)
x = data->max_x - x;
if (data->invert_y)
y = data->max_y - y;
if (!data->swap_x_y) {
input_event(data->input, EV_ABS, ABS_MT_POSITION_X, x);
input_event(data->input, EV_ABS, ABS_MT_POSITION_Y, y);
} else {
input_event(data->input, EV_ABS, ABS_MT_POSITION_X, y);
input_event(data->input, EV_ABS, ABS_MT_POSITION_Y, x);
}
}
input_mt_sync_frame(data->input);
input_sync(data->input);
return IRQ_HANDLED;
}
static int icn8318_start(struct input_dev *dev)
{
struct icn8318_data *data = input_get_drvdata(dev);
enable_irq(data->client->irq);
gpiod_set_value_cansleep(data->wake_gpio, 1);
return 0;
}
static void icn8318_stop(struct input_dev *dev)
{
struct icn8318_data *data = input_get_drvdata(dev);
disable_irq(data->client->irq);
i2c_smbus_write_byte_data(data->client, ICN8318_REG_POWER,
ICN8318_POWER_HIBERNATE);
gpiod_set_value_cansleep(data->wake_gpio, 0);
}
static int icn8318_suspend(struct device *dev)
{
struct icn8318_data *data = i2c_get_clientdata(to_i2c_client(dev));
mutex_lock(&data->input->mutex);
if (data->input->users)
icn8318_stop(data->input);
mutex_unlock(&data->input->mutex);
return 0;
}
static int icn8318_resume(struct device *dev)
{
struct icn8318_data *data = i2c_get_clientdata(to_i2c_client(dev));
mutex_lock(&data->input->mutex);
if (data->input->users)
icn8318_start(data->input);
mutex_unlock(&data->input->mutex);
return 0;
}
static int icn8318_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device_node *np = dev->of_node;
struct icn8318_data *data;
struct input_dev *input;
u32 fuzz_x = 0, fuzz_y = 0;
int error;
if (!client->irq) {
dev_err(dev, "Error no irq specified\n");
return -EINVAL;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->wake_gpio = devm_gpiod_get(dev, "wake", GPIOD_OUT_LOW);
if (IS_ERR(data->wake_gpio)) {
error = PTR_ERR(data->wake_gpio);
if (error != -EPROBE_DEFER)
dev_err(dev, "Error getting wake gpio: %d\n", error);
return error;
}
if (of_property_read_u32(np, "touchscreen-size-x", &data->max_x) ||
of_property_read_u32(np, "touchscreen-size-y", &data->max_y)) {
dev_err(dev, "Error touchscreen-size-x and/or -y missing\n");
return -EINVAL;
}
of_property_read_u32(np, "touchscreen-fuzz-x", &fuzz_x);
of_property_read_u32(np, "touchscreen-fuzz-y", &fuzz_y);
data->invert_x = of_property_read_bool(np, "touchscreen-inverted-x");
data->invert_y = of_property_read_bool(np, "touchscreen-inverted-y");
data->swap_x_y = of_property_read_bool(np, "touchscreen-swapped-x-y");
input = devm_input_allocate_device(dev);
if (!input)
return -ENOMEM;
input->name = client->name;
input->id.bustype = BUS_I2C;
input->open = icn8318_start;
input->close = icn8318_stop;
input->dev.parent = dev;
if (!data->swap_x_y) {
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
data->max_x, fuzz_x, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
data->max_y, fuzz_y, 0);
} else {
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
data->max_y, fuzz_y, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
data->max_x, fuzz_x, 0);
}
error = input_mt_init_slots(input, ICN8318_MAX_TOUCHES,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
if (error)
return error;
data->client = client;
data->input = input;
input_set_drvdata(input, data);
error = devm_request_threaded_irq(dev, client->irq, NULL, icn8318_irq,
IRQF_ONESHOT, client->name, data);
if (error) {
dev_err(dev, "Error requesting irq: %d\n", error);
return error;
}
icn8318_stop(data->input);
error = input_register_device(input);
if (error)
return error;
i2c_set_clientdata(client, data);
return 0;
}
