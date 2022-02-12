static int sis_read_packet(struct i2c_client *client, u8 *buf,
unsigned int *num_contacts,
unsigned int *contact_size)
{
int count_idx;
int ret;
u16 len;
u16 crc, pkg_crc;
u8 report_id;
ret = i2c_master_recv(client, buf, SIS_MAX_PACKET_SIZE);
if (ret <= 0)
return -EIO;
len = get_unaligned_le16(&buf[SIS_PKT_LEN_OFFSET]);
if (len > SIS_MAX_PACKET_SIZE) {
dev_err(&client->dev,
"%s: invalid packet length (%d vs %d)\n",
__func__, len, SIS_MAX_PACKET_SIZE);
return -E2BIG;
}
if (len < 10)
return -EINVAL;
report_id = buf[SIS_PKT_REPORT_OFFSET];
count_idx = len - 1;
*contact_size = SIS_BASE_LEN_PER_CONTACT;
if (report_id != SIS_ALL_IN_ONE_PACKAGE) {
if (SIS_PKT_IS_TOUCH(report_id)) {
crc = crc_itu_t(0, buf + 2, len - 2 - 2);
pkg_crc = get_unaligned_le16(&buf[len - 2]);
if (crc != pkg_crc) {
dev_err(&client->dev,
"%s: CRC Error (%d vs %d)\n",
__func__, crc, pkg_crc);
return -EINVAL;
}
count_idx -= 2;
} else if (!SIS_PKT_IS_HIDI2C(report_id)) {
dev_err(&client->dev,
"%s: invalid packet ID %#02x\n",
__func__, report_id);
return -EINVAL;
}
if (SIS_PKT_HAS_SCANTIME(report_id))
count_idx -= SIS_SCAN_TIME_LEN;
if (SIS_PKT_HAS_AREA(report_id))
*contact_size += SIS_AREA_LEN_PER_CONTACT;
if (SIS_PKT_HAS_PRESSURE(report_id))
*contact_size += SIS_PRESSURE_LEN_PER_CONTACT;
}
*num_contacts = buf[count_idx];
return 0;
}
static int sis_ts_report_contact(struct sis_ts_data *ts, const u8 *data, u8 id)
{
struct input_dev *input = ts->input;
int slot;
u8 status = data[SIS_CONTACT_STATUS_OFFSET];
u8 pressure;
u8 height, width;
u16 x, y;
if (status != SIS_STATUS_DOWN && status != SIS_STATUS_UP) {
dev_err(&ts->client->dev, "Unexpected touch status: %#02x\n",
data[SIS_CONTACT_STATUS_OFFSET]);
return -EINVAL;
}
slot = input_mt_get_slot_by_key(input, data[SIS_CONTACT_ID_OFFSET]);
if (slot < 0)
return -ENOENT;
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER,
status == SIS_STATUS_DOWN);
if (status == SIS_STATUS_DOWN) {
pressure = height = width = 1;
if (id != SIS_ALL_IN_ONE_PACKAGE) {
if (SIS_PKT_HAS_AREA(id)) {
width = data[SIS_CONTACT_WIDTH_OFFSET];
height = data[SIS_CONTACT_HEIGHT_OFFSET];
}
if (SIS_PKT_HAS_PRESSURE(id))
pressure =
data[SIS_CONTACT_PRESSURE_OFFSET(id)];
}
x = get_unaligned_le16(&data[SIS_CONTACT_X_OFFSET]);
y = get_unaligned_le16(&data[SIS_CONTACT_Y_OFFSET]);
input_report_abs(input, ABS_MT_TOUCH_MAJOR,
width * SIS_AREA_UNIT);
input_report_abs(input, ABS_MT_TOUCH_MINOR,
height * SIS_AREA_UNIT);
input_report_abs(input, ABS_MT_PRESSURE, pressure);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
}
return 0;
}
static void sis_ts_handle_packet(struct sis_ts_data *ts)
{
const u8 *contact;
unsigned int num_to_report = 0;
unsigned int num_contacts;
unsigned int num_reported;
unsigned int contact_size;
int error;
u8 report_id;
do {
error = sis_read_packet(ts->client, ts->packet,
&num_contacts, &contact_size);
if (error)
break;
if (num_to_report == 0) {
num_to_report = num_contacts;
} else if (num_contacts != 0) {
dev_err(&ts->client->dev,
"%s: nonzero (%d) point count in tail packet\n",
__func__, num_contacts);
break;
}
report_id = ts->packet[SIS_PKT_REPORT_OFFSET];
contact = &ts->packet[SIS_PKT_CONTACT_OFFSET];
num_reported = 0;
while (num_to_report > 0) {
error = sis_ts_report_contact(ts, contact, report_id);
if (error)
break;
contact += contact_size;
num_to_report--;
num_reported++;
if (report_id != SIS_ALL_IN_ONE_PACKAGE &&
num_reported >= 5) {
break;
}
}
} while (num_to_report > 0);
input_mt_sync_frame(ts->input);
input_sync(ts->input);
}
static irqreturn_t sis_ts_irq_handler(int irq, void *dev_id)
{
struct sis_ts_data *ts = dev_id;
do {
sis_ts_handle_packet(ts);
} while (ts->attn_gpio && gpiod_get_value_cansleep(ts->attn_gpio));
return IRQ_HANDLED;
}
static void sis_ts_reset(struct sis_ts_data *ts)
{
if (ts->reset_gpio) {
usleep_range(1000, 2000);
gpiod_set_value(ts->reset_gpio, 1);
usleep_range(1000, 2000);
gpiod_set_value(ts->reset_gpio, 0);
msleep(100);
}
}
static int sis_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sis_ts_data *ts;
struct input_dev *input;
int error;
ts = devm_kzalloc(&client->dev, sizeof(*ts), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->client = client;
ts->attn_gpio = devm_gpiod_get_optional(&client->dev,
"attn", GPIOD_IN);
if (IS_ERR(ts->attn_gpio)) {
error = PTR_ERR(ts->attn_gpio);
if (error != -EPROBE_DEFER)
dev_err(&client->dev,
"Failed to get attention GPIO: %d\n", error);
return error;
}
ts->reset_gpio = devm_gpiod_get_optional(&client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(ts->reset_gpio)) {
error = PTR_ERR(ts->reset_gpio);
if (error != -EPROBE_DEFER)
dev_err(&client->dev,
"Failed to get reset GPIO: %d\n", error);
return error;
}
sis_ts_reset(ts);
ts->input = input = devm_input_allocate_device(&client->dev);
if (!input) {
dev_err(&client->dev, "Failed to allocate input device\n");
return -ENOMEM;
}
input->name = "SiS Touchscreen";
input->id.bustype = BUS_I2C;
input_set_abs_params(input, ABS_MT_POSITION_X, 0, SIS_MAX_X, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0, SIS_MAX_Y, 0, 0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0, SIS_MAX_PRESSURE, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR,
0, SIS_AREA_LENGTH_LONGER, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MINOR,
0, SIS_AREA_LENGTH_SHORT, 0, 0);
error = input_mt_init_slots(input, SIS_MAX_FINGERS, INPUT_MT_DIRECT);
if (error) {
dev_err(&client->dev,
"Failed to initialize MT slots: %d\n", error);
return error;
}
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, sis_ts_irq_handler,
IRQF_ONESHOT,
client->name, ts);
if (error) {
dev_err(&client->dev, "Failed to request IRQ: %d\n", error);
return error;
}
error = input_register_device(ts->input);
if (error) {
dev_err(&client->dev,
"Failed to register input device: %d\n", error);
return error;
}
return 0;
}
