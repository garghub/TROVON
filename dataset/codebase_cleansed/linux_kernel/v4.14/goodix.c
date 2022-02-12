static int goodix_i2c_read(struct i2c_client *client,
u16 reg, u8 *buf, int len)
{
struct i2c_msg msgs[2];
u16 wbuf = cpu_to_be16(reg);
int ret;
msgs[0].flags = 0;
msgs[0].addr = client->addr;
msgs[0].len = 2;
msgs[0].buf = (u8 *)&wbuf;
msgs[1].flags = I2C_M_RD;
msgs[1].addr = client->addr;
msgs[1].len = len;
msgs[1].buf = buf;
ret = i2c_transfer(client->adapter, msgs, 2);
return ret < 0 ? ret : (ret != ARRAY_SIZE(msgs) ? -EIO : 0);
}
static int goodix_i2c_write(struct i2c_client *client, u16 reg, const u8 *buf,
unsigned len)
{
u8 *addr_buf;
struct i2c_msg msg;
int ret;
addr_buf = kmalloc(len + 2, GFP_KERNEL);
if (!addr_buf)
return -ENOMEM;
addr_buf[0] = reg >> 8;
addr_buf[1] = reg & 0xFF;
memcpy(&addr_buf[2], buf, len);
msg.flags = 0;
msg.addr = client->addr;
msg.buf = addr_buf;
msg.len = len + 2;
ret = i2c_transfer(client->adapter, &msg, 1);
kfree(addr_buf);
return ret < 0 ? ret : (ret != 1 ? -EIO : 0);
}
static int goodix_i2c_write_u8(struct i2c_client *client, u16 reg, u8 value)
{
return goodix_i2c_write(client, reg, &value, sizeof(value));
}
static int goodix_get_cfg_len(u16 id)
{
switch (id) {
case 911:
case 9271:
case 9110:
case 927:
case 928:
return GOODIX_CONFIG_911_LENGTH;
case 912:
case 967:
return GOODIX_CONFIG_967_LENGTH;
default:
return GOODIX_CONFIG_MAX_LENGTH;
}
}
static int goodix_ts_read_input_report(struct goodix_ts_data *ts, u8 *data)
{
unsigned long max_timeout;
int touch_num;
int error;
max_timeout = jiffies + msecs_to_jiffies(GOODIX_BUFFER_STATUS_TIMEOUT);
do {
error = goodix_i2c_read(ts->client, GOODIX_READ_COOR_ADDR,
data, GOODIX_CONTACT_SIZE + 1);
if (error) {
dev_err(&ts->client->dev, "I2C transfer error: %d\n",
error);
return error;
}
if (data[0] & GOODIX_BUFFER_STATUS_READY) {
touch_num = data[0] & 0x0f;
if (touch_num > ts->max_touch_num)
return -EPROTO;
if (touch_num > 1) {
data += 1 + GOODIX_CONTACT_SIZE;
error = goodix_i2c_read(ts->client,
GOODIX_READ_COOR_ADDR +
1 + GOODIX_CONTACT_SIZE,
data,
GOODIX_CONTACT_SIZE *
(touch_num - 1));
if (error)
return error;
}
return touch_num;
}
usleep_range(1000, 2000);
} while (time_before(jiffies, max_timeout));
return 0;
}
static void goodix_ts_report_touch(struct goodix_ts_data *ts, u8 *coor_data)
{
int id = coor_data[0] & 0x0F;
int input_x = get_unaligned_le16(&coor_data[1]);
int input_y = get_unaligned_le16(&coor_data[3]);
int input_w = get_unaligned_le16(&coor_data[5]);
if (ts->inverted_x)
input_x = ts->abs_x_max - input_x;
if (ts->inverted_y)
input_y = ts->abs_y_max - input_y;
if (ts->swapped_x_y)
swap(input_x, input_y);
input_mt_slot(ts->input_dev, id);
input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, true);
input_report_abs(ts->input_dev, ABS_MT_POSITION_X, input_x);
input_report_abs(ts->input_dev, ABS_MT_POSITION_Y, input_y);
input_report_abs(ts->input_dev, ABS_MT_TOUCH_MAJOR, input_w);
input_report_abs(ts->input_dev, ABS_MT_WIDTH_MAJOR, input_w);
}
static void goodix_process_events(struct goodix_ts_data *ts)
{
u8 point_data[1 + GOODIX_CONTACT_SIZE * GOODIX_MAX_CONTACTS];
int touch_num;
int i;
touch_num = goodix_ts_read_input_report(ts, point_data);
if (touch_num < 0)
return;
input_report_key(ts->input_dev, KEY_LEFTMETA, point_data[0] & BIT(4));
for (i = 0; i < touch_num; i++)
goodix_ts_report_touch(ts,
&point_data[1 + GOODIX_CONTACT_SIZE * i]);
input_mt_sync_frame(ts->input_dev);
input_sync(ts->input_dev);
}
static irqreturn_t goodix_ts_irq_handler(int irq, void *dev_id)
{
struct goodix_ts_data *ts = dev_id;
goodix_process_events(ts);
if (goodix_i2c_write_u8(ts->client, GOODIX_READ_COOR_ADDR, 0) < 0)
dev_err(&ts->client->dev, "I2C write end_cmd error\n");
return IRQ_HANDLED;
}
static void goodix_free_irq(struct goodix_ts_data *ts)
{
devm_free_irq(&ts->client->dev, ts->client->irq, ts);
}
static int goodix_request_irq(struct goodix_ts_data *ts)
{
return devm_request_threaded_irq(&ts->client->dev, ts->client->irq,
NULL, goodix_ts_irq_handler,
ts->irq_flags, ts->client->name, ts);
}
static int goodix_check_cfg(struct goodix_ts_data *ts,
const struct firmware *cfg)
{
int i, raw_cfg_len;
u8 check_sum = 0;
if (cfg->size > GOODIX_CONFIG_MAX_LENGTH) {
dev_err(&ts->client->dev,
"The length of the config fw is not correct");
return -EINVAL;
}
raw_cfg_len = cfg->size - 2;
for (i = 0; i < raw_cfg_len; i++)
check_sum += cfg->data[i];
check_sum = (~check_sum) + 1;
if (check_sum != cfg->data[raw_cfg_len]) {
dev_err(&ts->client->dev,
"The checksum of the config fw is not correct");
return -EINVAL;
}
if (cfg->data[raw_cfg_len + 1] != 1) {
dev_err(&ts->client->dev,
"Config fw must have Config_Fresh register set");
return -EINVAL;
}
return 0;
}
static int goodix_send_cfg(struct goodix_ts_data *ts,
const struct firmware *cfg)
{
int error;
error = goodix_check_cfg(ts, cfg);
if (error)
return error;
error = goodix_i2c_write(ts->client, GOODIX_REG_CONFIG_DATA, cfg->data,
cfg->size);
if (error) {
dev_err(&ts->client->dev, "Failed to write config data: %d",
error);
return error;
}
dev_dbg(&ts->client->dev, "Config sent successfully.");
usleep_range(10000, 11000);
return 0;
}
static int goodix_int_sync(struct goodix_ts_data *ts)
{
int error;
error = gpiod_direction_output(ts->gpiod_int, 0);
if (error)
return error;
msleep(50);
error = gpiod_direction_input(ts->gpiod_int);
if (error)
return error;
return 0;
}
static int goodix_reset(struct goodix_ts_data *ts)
{
int error;
error = gpiod_direction_output(ts->gpiod_rst, 0);
if (error)
return error;
msleep(20);
error = gpiod_direction_output(ts->gpiod_int, ts->client->addr == 0x14);
if (error)
return error;
usleep_range(100, 2000);
error = gpiod_direction_output(ts->gpiod_rst, 1);
if (error)
return error;
usleep_range(6000, 10000);
error = gpiod_direction_input(ts->gpiod_rst);
if (error)
return error;
error = goodix_int_sync(ts);
if (error)
return error;
return 0;
}
static int goodix_get_gpio_config(struct goodix_ts_data *ts)
{
int error;
struct device *dev;
struct gpio_desc *gpiod;
if (!ts->client)
return -EINVAL;
dev = &ts->client->dev;
gpiod = devm_gpiod_get_optional(dev, GOODIX_GPIO_INT_NAME, GPIOD_IN);
if (IS_ERR(gpiod)) {
error = PTR_ERR(gpiod);
if (error != -EPROBE_DEFER)
dev_dbg(dev, "Failed to get %s GPIO: %d\n",
GOODIX_GPIO_INT_NAME, error);
return error;
}
ts->gpiod_int = gpiod;
gpiod = devm_gpiod_get_optional(dev, GOODIX_GPIO_RST_NAME, GPIOD_IN);
if (IS_ERR(gpiod)) {
error = PTR_ERR(gpiod);
if (error != -EPROBE_DEFER)
dev_dbg(dev, "Failed to get %s GPIO: %d\n",
GOODIX_GPIO_RST_NAME, error);
return error;
}
ts->gpiod_rst = gpiod;
return 0;
}
static void goodix_read_config(struct goodix_ts_data *ts)
{
u8 config[GOODIX_CONFIG_MAX_LENGTH];
int error;
error = goodix_i2c_read(ts->client, GOODIX_REG_CONFIG_DATA,
config, ts->cfg_len);
if (error) {
dev_warn(&ts->client->dev,
"Error reading config (%d), using defaults\n",
error);
ts->abs_x_max = GOODIX_MAX_WIDTH;
ts->abs_y_max = GOODIX_MAX_HEIGHT;
if (ts->swapped_x_y)
swap(ts->abs_x_max, ts->abs_y_max);
ts->int_trigger_type = GOODIX_INT_TRIGGER;
ts->max_touch_num = GOODIX_MAX_CONTACTS;
return;
}
ts->abs_x_max = get_unaligned_le16(&config[RESOLUTION_LOC]);
ts->abs_y_max = get_unaligned_le16(&config[RESOLUTION_LOC + 2]);
if (ts->swapped_x_y)
swap(ts->abs_x_max, ts->abs_y_max);
ts->int_trigger_type = config[TRIGGER_LOC] & 0x03;
ts->max_touch_num = config[MAX_CONTACTS_LOC] & 0x0f;
if (!ts->abs_x_max || !ts->abs_y_max || !ts->max_touch_num) {
dev_err(&ts->client->dev,
"Invalid config, using defaults\n");
ts->abs_x_max = GOODIX_MAX_WIDTH;
ts->abs_y_max = GOODIX_MAX_HEIGHT;
if (ts->swapped_x_y)
swap(ts->abs_x_max, ts->abs_y_max);
ts->max_touch_num = GOODIX_MAX_CONTACTS;
}
if (dmi_check_system(rotated_screen)) {
ts->inverted_x = true;
ts->inverted_y = true;
dev_dbg(&ts->client->dev,
"Applying '180 degrees rotated screen' quirk\n");
}
}
static int goodix_read_version(struct goodix_ts_data *ts)
{
int error;
u8 buf[6];
char id_str[5];
error = goodix_i2c_read(ts->client, GOODIX_REG_ID, buf, sizeof(buf));
if (error) {
dev_err(&ts->client->dev, "read version failed: %d\n", error);
return error;
}
memcpy(id_str, buf, 4);
id_str[4] = 0;
if (kstrtou16(id_str, 10, &ts->id))
ts->id = 0x1001;
ts->version = get_unaligned_le16(&buf[4]);
dev_info(&ts->client->dev, "ID %d, version: %04x\n", ts->id,
ts->version);
return 0;
}
static int goodix_i2c_test(struct i2c_client *client)
{
int retry = 0;
int error;
u8 test;
while (retry++ < 2) {
error = goodix_i2c_read(client, GOODIX_REG_CONFIG_DATA,
&test, 1);
if (!error)
return 0;
dev_err(&client->dev, "i2c test failed attempt %d: %d\n",
retry, error);
msleep(20);
}
return error;
}
static int goodix_request_input_dev(struct goodix_ts_data *ts)
{
int error;
ts->input_dev = devm_input_allocate_device(&ts->client->dev);
if (!ts->input_dev) {
dev_err(&ts->client->dev, "Failed to allocate input device.");
return -ENOMEM;
}
input_set_abs_params(ts->input_dev, ABS_MT_POSITION_X,
0, ts->abs_x_max, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_POSITION_Y,
0, ts->abs_y_max, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_WIDTH_MAJOR, 0, 255, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_TOUCH_MAJOR, 0, 255, 0, 0);
input_mt_init_slots(ts->input_dev, ts->max_touch_num,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
ts->input_dev->name = "Goodix Capacitive TouchScreen";
ts->input_dev->phys = "input/ts";
ts->input_dev->id.bustype = BUS_I2C;
ts->input_dev->id.vendor = 0x0416;
ts->input_dev->id.product = ts->id;
ts->input_dev->id.version = ts->version;
input_set_capability(ts->input_dev, EV_KEY, KEY_LEFTMETA);
error = input_register_device(ts->input_dev);
if (error) {
dev_err(&ts->client->dev,
"Failed to register input device: %d", error);
return error;
}
return 0;
}
static int goodix_configure_dev(struct goodix_ts_data *ts)
{
int error;
ts->swapped_x_y = device_property_read_bool(&ts->client->dev,
"touchscreen-swapped-x-y");
ts->inverted_x = device_property_read_bool(&ts->client->dev,
"touchscreen-inverted-x");
ts->inverted_y = device_property_read_bool(&ts->client->dev,
"touchscreen-inverted-y");
goodix_read_config(ts);
error = goodix_request_input_dev(ts);
if (error)
return error;
ts->irq_flags = goodix_irq_flags[ts->int_trigger_type] | IRQF_ONESHOT;
error = goodix_request_irq(ts);
if (error) {
dev_err(&ts->client->dev, "request IRQ failed: %d\n", error);
return error;
}
return 0;
}
static void goodix_config_cb(const struct firmware *cfg, void *ctx)
{
struct goodix_ts_data *ts = ctx;
int error;
if (cfg) {
error = goodix_send_cfg(ts, cfg);
if (error)
goto err_release_cfg;
}
goodix_configure_dev(ts);
err_release_cfg:
release_firmware(cfg);
complete_all(&ts->firmware_loading_complete);
}
static int goodix_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct goodix_ts_data *ts;
int error;
dev_dbg(&client->dev, "I2C Address: 0x%02x\n", client->addr);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C check functionality failed.\n");
return -ENXIO;
}
ts = devm_kzalloc(&client->dev, sizeof(*ts), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->client = client;
i2c_set_clientdata(client, ts);
init_completion(&ts->firmware_loading_complete);
error = goodix_get_gpio_config(ts);
if (error)
return error;
if (ts->gpiod_int && ts->gpiod_rst) {
error = goodix_reset(ts);
if (error) {
dev_err(&client->dev, "Controller reset failed.\n");
return error;
}
}
error = goodix_i2c_test(client);
if (error) {
dev_err(&client->dev, "I2C communication failure: %d\n", error);
return error;
}
error = goodix_read_version(ts);
if (error) {
dev_err(&client->dev, "Read version failed.\n");
return error;
}
ts->cfg_len = goodix_get_cfg_len(ts->id);
if (ts->gpiod_int && ts->gpiod_rst) {
ts->cfg_name = devm_kasprintf(&client->dev, GFP_KERNEL,
"goodix_%d_cfg.bin", ts->id);
if (!ts->cfg_name)
return -ENOMEM;
error = request_firmware_nowait(THIS_MODULE, true, ts->cfg_name,
&client->dev, GFP_KERNEL, ts,
goodix_config_cb);
if (error) {
dev_err(&client->dev,
"Failed to invoke firmware loader: %d\n",
error);
return error;
}
return 0;
} else {
error = goodix_configure_dev(ts);
if (error)
return error;
}
return 0;
}
static int goodix_ts_remove(struct i2c_client *client)
{
struct goodix_ts_data *ts = i2c_get_clientdata(client);
if (ts->gpiod_int && ts->gpiod_rst)
wait_for_completion(&ts->firmware_loading_complete);
return 0;
}
static int __maybe_unused goodix_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct goodix_ts_data *ts = i2c_get_clientdata(client);
int error;
if (!ts->gpiod_int || !ts->gpiod_rst)
return 0;
wait_for_completion(&ts->firmware_loading_complete);
goodix_free_irq(ts);
error = gpiod_direction_output(ts->gpiod_int, 0);
if (error) {
goodix_request_irq(ts);
return error;
}
usleep_range(5000, 6000);
error = goodix_i2c_write_u8(ts->client, GOODIX_REG_COMMAND,
GOODIX_CMD_SCREEN_OFF);
if (error) {
dev_err(&ts->client->dev, "Screen off command failed\n");
gpiod_direction_input(ts->gpiod_int);
goodix_request_irq(ts);
return -EAGAIN;
}
msleep(58);
return 0;
}
static int __maybe_unused goodix_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct goodix_ts_data *ts = i2c_get_clientdata(client);
int error;
if (!ts->gpiod_int || !ts->gpiod_rst)
return 0;
error = gpiod_direction_output(ts->gpiod_int, 1);
if (error)
return error;
usleep_range(2000, 5000);
error = goodix_int_sync(ts);
if (error)
return error;
error = goodix_request_irq(ts);
if (error)
return error;
return 0;
}
