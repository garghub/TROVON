static int ft6236_read(struct i2c_client *client, u8 reg, u8 len, void *data)
{
int error;
error = i2c_smbus_read_i2c_block_data(client, reg, len, data);
if (error < 0)
return error;
if (error != len)
return -EIO;
return 0;
}
static irqreturn_t ft6236_interrupt(int irq, void *dev_id)
{
struct ft6236_data *ft6236 = dev_id;
struct device *dev = &ft6236->client->dev;
struct input_dev *input = ft6236->input;
struct ft6236_packet buf;
u8 touches;
int i, error;
error = ft6236_read(ft6236->client, 0, sizeof(buf), &buf);
if (error) {
dev_err(dev, "read touchdata failed %d\n", error);
return IRQ_HANDLED;
}
touches = buf.touches & 0xf;
if (touches > FT6236_MAX_TOUCH_POINTS) {
dev_dbg(dev,
"%d touch points reported, only %d are supported\n",
touches, FT6236_MAX_TOUCH_POINTS);
touches = FT6236_MAX_TOUCH_POINTS;
}
for (i = 0; i < touches; i++) {
struct ft6236_touchpoint *point = &buf.points[i];
u16 x = ((point->xhi & 0xf) << 8) | buf.points[i].xlo;
u16 y = ((point->yhi & 0xf) << 8) | buf.points[i].ylo;
u8 event = point->event >> 6;
u8 id = point->id >> 4;
bool act = (event == FT6236_EVENT_PRESS_DOWN ||
event == FT6236_EVENT_CONTACT);
input_mt_slot(input, id);
input_mt_report_slot_state(input, MT_TOOL_FINGER, act);
if (!act)
continue;
if (ft6236->invert_x)
x = ft6236->max_x - x;
if (ft6236->invert_y)
y = ft6236->max_y - y;
if (ft6236->swap_xy) {
input_report_abs(input, ABS_MT_POSITION_X, y);
input_report_abs(input, ABS_MT_POSITION_Y, x);
} else {
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
}
input_mt_sync_frame(input);
input_sync(input);
return IRQ_HANDLED;
}
static u8 ft6236_debug_read_byte(struct ft6236_data *ft6236, u8 reg)
{
struct i2c_client *client = ft6236->client;
u8 val = 0;
int error;
error = ft6236_read(client, reg, 1, &val);
if (error)
dev_dbg(&client->dev,
"error reading register 0x%02x: %d\n", reg, error);
return val;
}
static void ft6236_debug_info(struct ft6236_data *ft6236)
{
struct device *dev = &ft6236->client->dev;
dev_dbg(dev, "Touch threshold is %d\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_TH_GROUP) * 4);
dev_dbg(dev, "Report rate is %dHz\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_PERIODACTIVE) * 10);
dev_dbg(dev, "Firmware library version 0x%02x%02x\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_LIB_VER_H),
ft6236_debug_read_byte(ft6236, FT6236_REG_LIB_VER_L));
dev_dbg(dev, "Firmware version 0x%02x\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_FIRMID));
dev_dbg(dev, "Chip vendor ID 0x%02x\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_CIPHER));
dev_dbg(dev, "CTPM vendor ID 0x%02x\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_FOCALTECH_ID));
dev_dbg(dev, "Release code version 0x%02x\n",
ft6236_debug_read_byte(ft6236, FT6236_REG_RELEASE_CODE_ID));
}
static void ft6236_reset(struct ft6236_data *ft6236)
{
if (!ft6236->reset_gpio)
return;
gpiod_set_value_cansleep(ft6236->reset_gpio, 1);
usleep_range(5000, 20000);
gpiod_set_value_cansleep(ft6236->reset_gpio, 0);
msleep(300);
}
static int ft6236_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ft6236_data *ft6236;
struct input_dev *input;
u32 fuzz_x = 0, fuzz_y = 0;
u8 val;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENXIO;
if (!client->irq) {
dev_err(dev, "irq is missing\n");
return -EINVAL;
}
ft6236 = devm_kzalloc(dev, sizeof(*ft6236), GFP_KERNEL);
if (!ft6236)
return -ENOMEM;
ft6236->client = client;
ft6236->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(ft6236->reset_gpio)) {
error = PTR_ERR(ft6236->reset_gpio);
if (error != -EPROBE_DEFER)
dev_err(dev, "error getting reset gpio: %d\n", error);
return error;
}
ft6236_reset(ft6236);
error = ft6236_read(client, 0x00, 1, &val);
if (error) {
dev_err(dev, "failed to read from controller: %d\n", error);
return error;
}
ft6236_debug_info(ft6236);
input = devm_input_allocate_device(dev);
if (!input)
return -ENOMEM;
ft6236->input = input;
input->name = client->name;
input->id.bustype = BUS_I2C;
if (device_property_read_u32(dev, "touchscreen-size-x",
&ft6236->max_x) ||
device_property_read_u32(dev, "touchscreen-size-y",
&ft6236->max_y)) {
dev_err(dev, "touchscreen-size-x and/or -y missing\n");
return -EINVAL;
}
device_property_read_u32(dev, "touchscreen-fuzz-x", &fuzz_x);
device_property_read_u32(dev, "touchscreen-fuzz-y", &fuzz_y);
ft6236->invert_x = device_property_read_bool(dev,
"touchscreen-inverted-x");
ft6236->invert_y = device_property_read_bool(dev,
"touchscreen-inverted-y");
ft6236->swap_xy = device_property_read_bool(dev,
"touchscreen-swapped-x-y");
if (ft6236->swap_xy) {
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
ft6236->max_y, fuzz_y, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
ft6236->max_x, fuzz_x, 0);
} else {
input_set_abs_params(input, ABS_MT_POSITION_X, 0,
ft6236->max_x, fuzz_x, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0,
ft6236->max_y, fuzz_y, 0);
}
error = input_mt_init_slots(input, FT6236_MAX_TOUCH_POINTS,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
if (error)
return error;
error = devm_request_threaded_irq(dev, client->irq, NULL,
ft6236_interrupt, IRQF_ONESHOT,
client->name, ft6236);
if (error) {
dev_err(dev, "request irq %d failed: %d\n", client->irq, error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "failed to register input device: %d\n", error);
return error;
}
return 0;
}
