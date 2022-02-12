static int goodix_i2c_read(struct i2c_client *client,
u16 reg, u8 *buf, int len)
{
struct i2c_msg msgs[2];
u16 wbuf = cpu_to_be16(reg);
int ret;
msgs[0].flags = 0;
msgs[0].addr = client->addr;
msgs[0].len = 2;
msgs[0].buf = (u8 *) &wbuf;
msgs[1].flags = I2C_M_RD;
msgs[1].addr = client->addr;
msgs[1].len = len;
msgs[1].buf = buf;
ret = i2c_transfer(client->adapter, msgs, 2);
return ret < 0 ? ret : (ret != ARRAY_SIZE(msgs) ? -EIO : 0);
}
static int goodix_ts_read_input_report(struct goodix_ts_data *ts, u8 *data)
{
int touch_num;
int error;
error = goodix_i2c_read(ts->client, GOODIX_READ_COOR_ADDR, data,
GOODIX_CONTACT_SIZE + 1);
if (error) {
dev_err(&ts->client->dev, "I2C transfer error: %d\n", error);
return error;
}
touch_num = data[0] & 0x0f;
if (touch_num > ts->max_touch_num)
return -EPROTO;
if (touch_num > 1) {
data += 1 + GOODIX_CONTACT_SIZE;
error = goodix_i2c_read(ts->client,
GOODIX_READ_COOR_ADDR +
1 + GOODIX_CONTACT_SIZE,
data,
GOODIX_CONTACT_SIZE * (touch_num - 1));
if (error)
return error;
}
return touch_num;
}
static void goodix_ts_report_touch(struct goodix_ts_data *ts, u8 *coor_data)
{
int id = coor_data[0] & 0x0F;
int input_x = get_unaligned_le16(&coor_data[1]);
int input_y = get_unaligned_le16(&coor_data[3]);
int input_w = get_unaligned_le16(&coor_data[5]);
input_mt_slot(ts->input_dev, id);
input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, true);
input_report_abs(ts->input_dev, ABS_MT_POSITION_X, input_x);
input_report_abs(ts->input_dev, ABS_MT_POSITION_Y, input_y);
input_report_abs(ts->input_dev, ABS_MT_TOUCH_MAJOR, input_w);
input_report_abs(ts->input_dev, ABS_MT_WIDTH_MAJOR, input_w);
}
static void goodix_process_events(struct goodix_ts_data *ts)
{
u8 point_data[1 + GOODIX_CONTACT_SIZE * ts->max_touch_num];
int touch_num;
int i;
touch_num = goodix_ts_read_input_report(ts, point_data);
if (touch_num < 0)
return;
for (i = 0; i < touch_num; i++)
goodix_ts_report_touch(ts,
&point_data[1 + GOODIX_CONTACT_SIZE * i]);
input_mt_sync_frame(ts->input_dev);
input_sync(ts->input_dev);
}
static irqreturn_t goodix_ts_irq_handler(int irq, void *dev_id)
{
static const u8 end_cmd[] = {
GOODIX_READ_COOR_ADDR >> 8,
GOODIX_READ_COOR_ADDR & 0xff,
0
};
struct goodix_ts_data *ts = dev_id;
goodix_process_events(ts);
if (i2c_master_send(ts->client, end_cmd, sizeof(end_cmd)) < 0)
dev_err(&ts->client->dev, "I2C write end_cmd error\n");
return IRQ_HANDLED;
}
static void goodix_read_config(struct goodix_ts_data *ts)
{
u8 config[GOODIX_CONFIG_MAX_LENGTH];
int error;
error = goodix_i2c_read(ts->client, GOODIX_REG_CONFIG_DATA,
config,
GOODIX_CONFIG_MAX_LENGTH);
if (error) {
dev_warn(&ts->client->dev,
"Error reading config (%d), using defaults\n",
error);
ts->abs_x_max = GOODIX_MAX_WIDTH;
ts->abs_y_max = GOODIX_MAX_HEIGHT;
ts->int_trigger_type = GOODIX_INT_TRIGGER;
ts->max_touch_num = GOODIX_MAX_CONTACTS;
return;
}
ts->abs_x_max = get_unaligned_le16(&config[RESOLUTION_LOC]);
ts->abs_y_max = get_unaligned_le16(&config[RESOLUTION_LOC + 2]);
ts->int_trigger_type = config[TRIGGER_LOC] & 0x03;
ts->max_touch_num = config[MAX_CONTACTS_LOC] & 0x0f;
if (!ts->abs_x_max || !ts->abs_y_max || !ts->max_touch_num) {
dev_err(&ts->client->dev,
"Invalid config, using defaults\n");
ts->abs_x_max = GOODIX_MAX_WIDTH;
ts->abs_y_max = GOODIX_MAX_HEIGHT;
ts->max_touch_num = GOODIX_MAX_CONTACTS;
}
}
static int goodix_read_version(struct i2c_client *client, u16 *version)
{
int error;
u8 buf[6];
error = goodix_i2c_read(client, GOODIX_REG_VERSION, buf, sizeof(buf));
if (error) {
dev_err(&client->dev, "read version failed: %d\n", error);
return error;
}
if (version)
*version = get_unaligned_le16(&buf[4]);
dev_info(&client->dev, "IC VERSION: %6ph\n", buf);
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
ts->input_dev->evbit[0] = BIT_MASK(EV_SYN) |
BIT_MASK(EV_KEY) |
BIT_MASK(EV_ABS);
input_set_abs_params(ts->input_dev, ABS_MT_POSITION_X, 0,
ts->abs_x_max, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_POSITION_Y, 0,
ts->abs_y_max, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_WIDTH_MAJOR, 0, 255, 0, 0);
input_set_abs_params(ts->input_dev, ABS_MT_TOUCH_MAJOR, 0, 255, 0, 0);
input_mt_init_slots(ts->input_dev, ts->max_touch_num,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
ts->input_dev->name = "Goodix Capacitive TouchScreen";
ts->input_dev->phys = "input/ts";
ts->input_dev->id.bustype = BUS_I2C;
ts->input_dev->id.vendor = 0x0416;
ts->input_dev->id.product = 0x1001;
ts->input_dev->id.version = 10427;
error = input_register_device(ts->input_dev);
if (error) {
dev_err(&ts->client->dev,
"Failed to register input device: %d", error);
return error;
}
return 0;
}
static int goodix_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct goodix_ts_data *ts;
unsigned long irq_flags;
int error;
u16 version_info;
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
error = goodix_i2c_test(client);
if (error) {
dev_err(&client->dev, "I2C communication failure: %d\n", error);
return error;
}
error = goodix_read_version(client, &version_info);
if (error) {
dev_err(&client->dev, "Read version failed.\n");
return error;
}
goodix_read_config(ts);
error = goodix_request_input_dev(ts);
if (error)
return error;
irq_flags = goodix_irq_flags[ts->int_trigger_type] | IRQF_ONESHOT;
error = devm_request_threaded_irq(&ts->client->dev, client->irq,
NULL, goodix_ts_irq_handler,
irq_flags, client->name, ts);
if (error) {
dev_err(&client->dev, "request IRQ failed: %d\n", error);
return error;
}
return 0;
}
