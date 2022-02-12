static bool mxt_object_readable(unsigned int type)
{
switch (type) {
case MXT_GEN_COMMAND_T6:
case MXT_GEN_POWER_T7:
case MXT_GEN_ACQUIRE_T8:
case MXT_GEN_DATASOURCE_T53:
case MXT_TOUCH_MULTI_T9:
case MXT_TOUCH_KEYARRAY_T15:
case MXT_TOUCH_PROXIMITY_T23:
case MXT_TOUCH_PROXKEY_T52:
case MXT_PROCI_GRIPFACE_T20:
case MXT_PROCG_NOISE_T22:
case MXT_PROCI_ONETOUCH_T24:
case MXT_PROCI_TWOTOUCH_T27:
case MXT_PROCI_GRIP_T40:
case MXT_PROCI_PALM_T41:
case MXT_PROCI_TOUCHSUPPRESSION_T42:
case MXT_PROCI_STYLUS_T47:
case MXT_PROCG_NOISESUPPRESSION_T48:
case MXT_SPT_COMMSCONFIG_T18:
case MXT_SPT_GPIOPWM_T19:
case MXT_SPT_SELFTEST_T25:
case MXT_SPT_CTECONFIG_T28:
case MXT_SPT_USERDATA_T38:
case MXT_SPT_DIGITIZER_T43:
case MXT_SPT_CTECONFIG_T46:
return true;
default:
return false;
}
}
static bool mxt_object_writable(unsigned int type)
{
switch (type) {
case MXT_GEN_COMMAND_T6:
case MXT_GEN_POWER_T7:
case MXT_GEN_ACQUIRE_T8:
case MXT_TOUCH_MULTI_T9:
case MXT_TOUCH_KEYARRAY_T15:
case MXT_TOUCH_PROXIMITY_T23:
case MXT_TOUCH_PROXKEY_T52:
case MXT_PROCI_GRIPFACE_T20:
case MXT_PROCG_NOISE_T22:
case MXT_PROCI_ONETOUCH_T24:
case MXT_PROCI_TWOTOUCH_T27:
case MXT_PROCI_GRIP_T40:
case MXT_PROCI_PALM_T41:
case MXT_PROCI_TOUCHSUPPRESSION_T42:
case MXT_PROCI_STYLUS_T47:
case MXT_PROCG_NOISESUPPRESSION_T48:
case MXT_SPT_COMMSCONFIG_T18:
case MXT_SPT_GPIOPWM_T19:
case MXT_SPT_SELFTEST_T25:
case MXT_SPT_CTECONFIG_T28:
case MXT_SPT_DIGITIZER_T43:
case MXT_SPT_CTECONFIG_T46:
return true;
default:
return false;
}
}
static void mxt_dump_message(struct device *dev,
struct mxt_message *message)
{
dev_dbg(dev, "reportid: %u\tmessage: %*ph\n",
message->reportid, 7, message->message);
}
static int mxt_check_bootloader(struct i2c_client *client,
unsigned int state)
{
u8 val;
recheck:
if (i2c_master_recv(client, &val, 1) != 1) {
dev_err(&client->dev, "%s: i2c recv failed\n", __func__);
return -EIO;
}
switch (state) {
case MXT_WAITING_BOOTLOAD_CMD:
case MXT_WAITING_FRAME_DATA:
val &= ~MXT_BOOT_STATUS_MASK;
break;
case MXT_FRAME_CRC_PASS:
if (val == MXT_FRAME_CRC_CHECK)
goto recheck;
break;
default:
return -EINVAL;
}
if (val != state) {
dev_err(&client->dev, "Unvalid bootloader mode state\n");
return -EINVAL;
}
return 0;
}
static int mxt_unlock_bootloader(struct i2c_client *client)
{
u8 buf[2];
buf[0] = MXT_UNLOCK_CMD_LSB;
buf[1] = MXT_UNLOCK_CMD_MSB;
if (i2c_master_send(client, buf, 2) != 2) {
dev_err(&client->dev, "%s: i2c send failed\n", __func__);
return -EIO;
}
return 0;
}
static int mxt_fw_write(struct i2c_client *client,
const u8 *data, unsigned int frame_size)
{
if (i2c_master_send(client, data, frame_size) != frame_size) {
dev_err(&client->dev, "%s: i2c send failed\n", __func__);
return -EIO;
}
return 0;
}
static int __mxt_read_reg(struct i2c_client *client,
u16 reg, u16 len, void *val)
{
struct i2c_msg xfer[2];
u8 buf[2];
int ret;
buf[0] = reg & 0xff;
buf[1] = (reg >> 8) & 0xff;
xfer[0].addr = client->addr;
xfer[0].flags = 0;
xfer[0].len = 2;
xfer[0].buf = buf;
xfer[1].addr = client->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = len;
xfer[1].buf = val;
ret = i2c_transfer(client->adapter, xfer, 2);
if (ret == 2) {
ret = 0;
} else {
if (ret >= 0)
ret = -EIO;
dev_err(&client->dev, "%s: i2c transfer failed (%d)\n",
__func__, ret);
}
return ret;
}
static int mxt_read_reg(struct i2c_client *client, u16 reg, u8 *val)
{
return __mxt_read_reg(client, reg, 1, val);
}
static int __mxt_write_reg(struct i2c_client *client, u16 reg, u16 len,
const void *val)
{
u8 *buf;
size_t count;
int ret;
count = len + 2;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
buf[0] = reg & 0xff;
buf[1] = (reg >> 8) & 0xff;
memcpy(&buf[2], val, len);
ret = i2c_master_send(client, buf, count);
if (ret == count) {
ret = 0;
} else {
if (ret >= 0)
ret = -EIO;
dev_err(&client->dev, "%s: i2c send failed (%d)\n",
__func__, ret);
}
kfree(buf);
return ret;
}
static int mxt_write_reg(struct i2c_client *client, u16 reg, u8 val)
{
return __mxt_write_reg(client, reg, 1, &val);
}
static struct mxt_object *
mxt_get_object(struct mxt_data *data, u8 type)
{
struct mxt_object *object;
int i;
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
if (object->type == type)
return object;
}
dev_err(&data->client->dev, "Invalid object type\n");
return NULL;
}
static int mxt_read_message(struct mxt_data *data,
struct mxt_message *message)
{
struct mxt_object *object;
u16 reg;
object = mxt_get_object(data, MXT_GEN_MESSAGE_T5);
if (!object)
return -EINVAL;
reg = object->start_address;
return __mxt_read_reg(data->client, reg,
sizeof(struct mxt_message), message);
}
static int mxt_write_object(struct mxt_data *data,
u8 type, u8 offset, u8 val)
{
struct mxt_object *object;
u16 reg;
object = mxt_get_object(data, type);
if (!object || offset >= object->size + 1)
return -EINVAL;
reg = object->start_address;
return mxt_write_reg(data->client, reg + offset, val);
}
static void mxt_input_button(struct mxt_data *data, struct mxt_message *message)
{
struct input_dev *input = data->input_dev;
bool button;
int i;
for (i = 0; i < MXT_NUM_GPIO; i++) {
if (data->pdata->key_map[i] == KEY_RESERVED)
continue;
button = !(message->message[0] & MXT_GPIO0_MASK << i);
input_report_key(input, data->pdata->key_map[i], button);
}
}
static void mxt_input_touchevent(struct mxt_data *data,
struct mxt_message *message, int id)
{
struct device *dev = &data->client->dev;
u8 status = message->message[0];
struct input_dev *input_dev = data->input_dev;
int x;
int y;
int area;
int pressure;
x = (message->message[1] << 4) | ((message->message[3] >> 4) & 0xf);
y = (message->message[2] << 4) | ((message->message[3] & 0xf));
if (data->max_x < 1024)
x = x >> 2;
if (data->max_y < 1024)
y = y >> 2;
area = message->message[4];
pressure = message->message[5];
dev_dbg(dev,
"[%u] %c%c%c%c%c%c%c%c x: %5u y: %5u area: %3u amp: %3u\n",
id,
(status & MXT_DETECT) ? 'D' : '.',
(status & MXT_PRESS) ? 'P' : '.',
(status & MXT_RELEASE) ? 'R' : '.',
(status & MXT_MOVE) ? 'M' : '.',
(status & MXT_VECTOR) ? 'V' : '.',
(status & MXT_AMP) ? 'A' : '.',
(status & MXT_SUPPRESS) ? 'S' : '.',
(status & MXT_UNGRIP) ? 'U' : '.',
x, y, area, pressure);
input_mt_slot(input_dev, id);
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER,
status & MXT_DETECT);
if (status & MXT_DETECT) {
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
input_report_abs(input_dev, ABS_MT_PRESSURE, pressure);
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR, area);
}
}
static unsigned mxt_extract_T6_csum(const u8 *csum)
{
return csum[0] | (csum[1] << 8) | (csum[2] << 16);
}
static bool mxt_is_T9_message(struct mxt_data *data, struct mxt_message *msg)
{
u8 id = msg->reportid;
return (id >= data->T9_reportid_min && id <= data->T9_reportid_max);
}
static irqreturn_t mxt_interrupt(int irq, void *dev_id)
{
struct mxt_data *data = dev_id;
struct mxt_message message;
const u8 *payload = &message.message[0];
struct device *dev = &data->client->dev;
u8 reportid;
bool update_input = false;
do {
if (mxt_read_message(data, &message)) {
dev_err(dev, "Failed to read message\n");
goto end;
}
reportid = message.reportid;
if (reportid == data->T6_reportid) {
u8 status = payload[0];
unsigned csum = mxt_extract_T6_csum(&payload[1]);
dev_dbg(dev, "Status: %02x Config Checksum: %06x\n",
status, csum);
} else if (mxt_is_T9_message(data, &message)) {
int id = reportid - data->T9_reportid_min;
mxt_input_touchevent(data, &message, id);
update_input = true;
} else if (message.reportid == data->T19_reportid) {
mxt_input_button(data, &message);
update_input = true;
} else {
mxt_dump_message(dev, &message);
}
} while (reportid != 0xff);
if (update_input) {
input_mt_report_pointer_emulation(data->input_dev, false);
input_sync(data->input_dev);
}
end:
return IRQ_HANDLED;
}
static int mxt_check_reg_init(struct mxt_data *data)
{
const struct mxt_platform_data *pdata = data->pdata;
struct mxt_object *object;
struct device *dev = &data->client->dev;
int index = 0;
int i, size;
int ret;
if (!pdata->config) {
dev_dbg(dev, "No cfg data defined, skipping reg init\n");
return 0;
}
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
if (!mxt_object_writable(object->type))
continue;
size = (object->size + 1) * (object->instances + 1);
if (index + size > pdata->config_length) {
dev_err(dev, "Not enough config data!\n");
return -EINVAL;
}
ret = __mxt_write_reg(data->client, object->start_address,
size, &pdata->config[index]);
if (ret)
return ret;
index += size;
}
return 0;
}
static int mxt_make_highchg(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
struct mxt_message message;
int count = 10;
int error;
do {
error = mxt_read_message(data, &message);
if (error)
return error;
} while (message.reportid != 0xff && --count);
if (!count) {
dev_err(dev, "CHG pin isn't cleared\n");
return -EBUSY;
}
return 0;
}
static void mxt_handle_pdata(struct mxt_data *data)
{
const struct mxt_platform_data *pdata = data->pdata;
u8 voltage;
mxt_write_object(data, MXT_TOUCH_MULTI_T9, MXT_TOUCH_XSIZE,
pdata->x_line);
mxt_write_object(data, MXT_TOUCH_MULTI_T9, MXT_TOUCH_YSIZE,
pdata->y_line);
mxt_write_object(data, MXT_TOUCH_MULTI_T9, MXT_TOUCH_ORIENT,
pdata->orient);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_BLEN, pdata->blen);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_TCHTHR, pdata->threshold);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_XRANGE_LSB, (pdata->x_size - 1) & 0xff);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_XRANGE_MSB, (pdata->x_size - 1) >> 8);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_YRANGE_LSB, (pdata->y_size - 1) & 0xff);
mxt_write_object(data, MXT_TOUCH_MULTI_T9,
MXT_TOUCH_YRANGE_MSB, (pdata->y_size - 1) >> 8);
if (pdata->voltage) {
if (pdata->voltage < MXT_VOLTAGE_DEFAULT) {
voltage = (MXT_VOLTAGE_DEFAULT - pdata->voltage) /
MXT_VOLTAGE_STEP;
voltage = 0xff - voltage + 1;
} else
voltage = (pdata->voltage - MXT_VOLTAGE_DEFAULT) /
MXT_VOLTAGE_STEP;
mxt_write_object(data, MXT_SPT_CTECONFIG_T28,
MXT_CTE_VOLTAGE, voltage);
}
}
static int mxt_get_info(struct mxt_data *data)
{
struct i2c_client *client = data->client;
struct mxt_info *info = &data->info;
int error;
error = __mxt_read_reg(client, MXT_INFO, sizeof(*info), info);
if (error)
return error;
return 0;
}
static int mxt_get_object_table(struct mxt_data *data)
{
struct i2c_client *client = data->client;
size_t table_size;
int error;
int i;
u8 reportid;
table_size = data->info.object_num * sizeof(struct mxt_object);
error = __mxt_read_reg(client, MXT_OBJECT_START, table_size,
data->object_table);
if (error)
return error;
reportid = 1;
for (i = 0; i < data->info.object_num; i++) {
struct mxt_object *object = data->object_table + i;
u8 min_id, max_id;
le16_to_cpus(&object->start_address);
if (object->num_report_ids) {
min_id = reportid;
reportid += object->num_report_ids *
(object->instances + 1);
max_id = reportid - 1;
} else {
min_id = 0;
max_id = 0;
}
dev_dbg(&data->client->dev,
"Type %2d Start %3d Size %3d Instances %2d ReportIDs %3u : %3u\n",
object->type, object->start_address, object->size + 1,
object->instances + 1, min_id, max_id);
switch (object->type) {
case MXT_GEN_COMMAND_T6:
data->T6_reportid = min_id;
break;
case MXT_TOUCH_MULTI_T9:
data->T9_reportid_min = min_id;
data->T9_reportid_max = max_id;
break;
case MXT_SPT_GPIOPWM_T19:
data->T19_reportid = min_id;
break;
}
}
return 0;
}
static void mxt_free_object_table(struct mxt_data *data)
{
kfree(data->object_table);
data->object_table = NULL;
data->T6_reportid = 0;
data->T9_reportid_min = 0;
data->T9_reportid_max = 0;
data->T19_reportid = 0;
}
static int mxt_initialize(struct mxt_data *data)
{
struct i2c_client *client = data->client;
struct mxt_info *info = &data->info;
int error;
u8 val;
error = mxt_get_info(data);
if (error)
return error;
data->object_table = kcalloc(info->object_num,
sizeof(struct mxt_object),
GFP_KERNEL);
if (!data->object_table) {
dev_err(&client->dev, "Failed to allocate memory\n");
return -ENOMEM;
}
error = mxt_get_object_table(data);
if (error)
goto err_free_object_table;
error = mxt_check_reg_init(data);
if (error)
goto err_free_object_table;
mxt_handle_pdata(data);
mxt_write_object(data, MXT_GEN_COMMAND_T6,
MXT_COMMAND_BACKUPNV,
MXT_BACKUP_VALUE);
msleep(MXT_BACKUP_TIME);
mxt_write_object(data, MXT_GEN_COMMAND_T6,
MXT_COMMAND_RESET, 1);
msleep(MXT_RESET_TIME);
error = mxt_read_reg(client, MXT_MATRIX_X_SIZE, &val);
if (error)
goto err_free_object_table;
info->matrix_xsize = val;
error = mxt_read_reg(client, MXT_MATRIX_Y_SIZE, &val);
if (error)
goto err_free_object_table;
info->matrix_ysize = val;
dev_info(&client->dev,
"Family ID: %u Variant ID: %u Major.Minor.Build: %u.%u.%02X\n",
info->family_id, info->variant_id, info->version >> 4,
info->version & 0xf, info->build);
dev_info(&client->dev,
"Matrix X Size: %u Matrix Y Size: %u Object Num: %u\n",
info->matrix_xsize, info->matrix_ysize,
info->object_num);
return 0;
err_free_object_table:
mxt_free_object_table(data);
return error;
}
static void mxt_calc_resolution(struct mxt_data *data)
{
unsigned int max_x = data->pdata->x_size - 1;
unsigned int max_y = data->pdata->y_size - 1;
if (data->pdata->orient & MXT_XY_SWITCH) {
data->max_x = max_y;
data->max_y = max_x;
} else {
data->max_x = max_x;
data->max_y = max_y;
}
}
static ssize_t mxt_fw_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mxt_data *data = dev_get_drvdata(dev);
struct mxt_info *info = &data->info;
return scnprintf(buf, PAGE_SIZE, "%u.%u.%02X\n",
info->version >> 4, info->version & 0xf, info->build);
}
static ssize_t mxt_hw_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mxt_data *data = dev_get_drvdata(dev);
struct mxt_info *info = &data->info;
return scnprintf(buf, PAGE_SIZE, "%u.%u\n",
info->family_id, info->variant_id);
}
static ssize_t mxt_show_instance(char *buf, int count,
struct mxt_object *object, int instance,
const u8 *val)
{
int i;
if (object->instances > 0)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Instance %u\n", instance);
for (i = 0; i < object->size + 1; i++)
count += scnprintf(buf + count, PAGE_SIZE - count,
"\t[%2u]: %02x (%d)\n", i, val[i], val[i]);
count += scnprintf(buf + count, PAGE_SIZE - count, "\n");
return count;
}
static ssize_t mxt_object_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mxt_data *data = dev_get_drvdata(dev);
struct mxt_object *object;
int count = 0;
int i, j;
int error;
u8 *obuf;
obuf = kmalloc(256, GFP_KERNEL);
if (!obuf)
return -ENOMEM;
error = 0;
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
if (!mxt_object_readable(object->type))
continue;
count += scnprintf(buf + count, PAGE_SIZE - count,
"T%u:\n", object->type);
for (j = 0; j < object->instances + 1; j++) {
u16 size = object->size + 1;
u16 addr = object->start_address + j * size;
error = __mxt_read_reg(data->client, addr, size, obuf);
if (error)
goto done;
count = mxt_show_instance(buf, count, object, j, obuf);
}
}
done:
kfree(obuf);
return error ?: count;
}
static int mxt_load_fw(struct device *dev, const char *fn)
{
struct mxt_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
const struct firmware *fw = NULL;
unsigned int frame_size;
unsigned int pos = 0;
int ret;
ret = request_firmware(&fw, fn, dev);
if (ret) {
dev_err(dev, "Unable to open firmware %s\n", fn);
return ret;
}
mxt_write_object(data, MXT_GEN_COMMAND_T6,
MXT_COMMAND_RESET, MXT_BOOT_VALUE);
msleep(MXT_RESET_TIME);
if (client->addr == MXT_APP_LOW)
client->addr = MXT_BOOT_LOW;
else
client->addr = MXT_BOOT_HIGH;
ret = mxt_check_bootloader(client, MXT_WAITING_BOOTLOAD_CMD);
if (ret)
goto out;
mxt_unlock_bootloader(client);
while (pos < fw->size) {
ret = mxt_check_bootloader(client,
MXT_WAITING_FRAME_DATA);
if (ret)
goto out;
frame_size = ((*(fw->data + pos) << 8) | *(fw->data + pos + 1));
frame_size += 2;
mxt_fw_write(client, fw->data + pos, frame_size);
ret = mxt_check_bootloader(client,
MXT_FRAME_CRC_PASS);
if (ret)
goto out;
pos += frame_size;
dev_dbg(dev, "Updated %d bytes / %zd bytes\n", pos, fw->size);
}
out:
release_firmware(fw);
if (client->addr == MXT_BOOT_LOW)
client->addr = MXT_APP_LOW;
else
client->addr = MXT_APP_HIGH;
return ret;
}
static ssize_t mxt_update_fw_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct mxt_data *data = dev_get_drvdata(dev);
int error;
disable_irq(data->irq);
error = mxt_load_fw(dev, MXT_FW_NAME);
if (error) {
dev_err(dev, "The firmware update failed(%d)\n", error);
count = error;
} else {
dev_dbg(dev, "The firmware update succeeded\n");
msleep(MXT_FWRESET_TIME);
mxt_free_object_table(data);
mxt_initialize(data);
}
enable_irq(data->irq);
error = mxt_make_highchg(data);
if (error)
return error;
return count;
}
static void mxt_start(struct mxt_data *data)
{
mxt_write_object(data,
MXT_TOUCH_MULTI_T9, MXT_TOUCH_CTRL, 0x83);
}
static void mxt_stop(struct mxt_data *data)
{
mxt_write_object(data,
MXT_TOUCH_MULTI_T9, MXT_TOUCH_CTRL, 0);
}
static int mxt_input_open(struct input_dev *dev)
{
struct mxt_data *data = input_get_drvdata(dev);
mxt_start(data);
return 0;
}
static void mxt_input_close(struct input_dev *dev)
{
struct mxt_data *data = input_get_drvdata(dev);
mxt_stop(data);
}
static int mxt_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct mxt_platform_data *pdata = dev_get_platdata(&client->dev);
struct mxt_data *data;
struct input_dev *input_dev;
int error;
unsigned int num_mt_slots;
if (!pdata)
return -EINVAL;
data = kzalloc(sizeof(struct mxt_data), GFP_KERNEL);
input_dev = input_allocate_device();
if (!data || !input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
error = -ENOMEM;
goto err_free_mem;
}
data->is_tp = pdata && pdata->is_tp;
input_dev->name = (data->is_tp) ? "Atmel maXTouch Touchpad" :
"Atmel maXTouch Touchscreen";
snprintf(data->phys, sizeof(data->phys), "i2c-%u-%04x/input0",
client->adapter->nr, client->addr);
input_dev->phys = data->phys;
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
input_dev->open = mxt_input_open;
input_dev->close = mxt_input_close;
data->client = client;
data->input_dev = input_dev;
data->pdata = pdata;
data->irq = client->irq;
mxt_calc_resolution(data);
error = mxt_initialize(data);
if (error)
goto err_free_mem;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
if (data->is_tp) {
int i;
__set_bit(INPUT_PROP_POINTER, input_dev->propbit);
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
for (i = 0; i < MXT_NUM_GPIO; i++)
if (pdata->key_map[i] != KEY_RESERVED)
__set_bit(pdata->key_map[i], input_dev->keybit);
__set_bit(BTN_TOOL_FINGER, input_dev->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, input_dev->keybit);
__set_bit(BTN_TOOL_TRIPLETAP, input_dev->keybit);
__set_bit(BTN_TOOL_QUADTAP, input_dev->keybit);
__set_bit(BTN_TOOL_QUINTTAP, input_dev->keybit);
input_abs_set_res(input_dev, ABS_X, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_Y, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_X,
MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_Y,
MXT_PIXELS_PER_MM);
}
input_set_abs_params(input_dev, ABS_X,
0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_Y,
0, data->max_y, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, 255, 0, 0);
num_mt_slots = data->T9_reportid_max - data->T9_reportid_min + 1;
error = input_mt_init_slots(input_dev, num_mt_slots, 0);
if (error)
goto err_free_object;
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,
0, MXT_MAX_AREA, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
0, data->max_y, 0, 0);
input_set_abs_params(input_dev, ABS_MT_PRESSURE,
0, 255, 0, 0);
input_set_drvdata(input_dev, data);
i2c_set_clientdata(client, data);
error = request_threaded_irq(client->irq, NULL, mxt_interrupt,
pdata->irqflags | IRQF_ONESHOT,
client->name, data);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
goto err_free_object;
}
error = mxt_make_highchg(data);
if (error)
goto err_free_irq;
error = input_register_device(input_dev);
if (error)
goto err_free_irq;
error = sysfs_create_group(&client->dev.kobj, &mxt_attr_group);
if (error)
goto err_unregister_device;
return 0;
err_unregister_device:
input_unregister_device(input_dev);
input_dev = NULL;
err_free_irq:
free_irq(client->irq, data);
err_free_object:
kfree(data->object_table);
err_free_mem:
input_free_device(input_dev);
kfree(data);
return error;
}
static int mxt_remove(struct i2c_client *client)
{
struct mxt_data *data = i2c_get_clientdata(client);
sysfs_remove_group(&client->dev.kobj, &mxt_attr_group);
free_irq(data->irq, data);
input_unregister_device(data->input_dev);
kfree(data->object_table);
kfree(data);
return 0;
}
static int mxt_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mxt_data *data = i2c_get_clientdata(client);
struct input_dev *input_dev = data->input_dev;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
mxt_stop(data);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int mxt_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mxt_data *data = i2c_get_clientdata(client);
struct input_dev *input_dev = data->input_dev;
mxt_write_object(data, MXT_GEN_COMMAND_T6,
MXT_COMMAND_RESET, 1);
msleep(MXT_RESET_TIME);
mutex_lock(&input_dev->mutex);
if (input_dev->users)
mxt_start(data);
mutex_unlock(&input_dev->mutex);
return 0;
}
