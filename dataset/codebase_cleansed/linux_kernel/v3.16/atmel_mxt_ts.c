static size_t mxt_obj_size(const struct mxt_object *obj)
{
return obj->size_minus_one + 1;
}
static size_t mxt_obj_instances(const struct mxt_object *obj)
{
return obj->instances_minus_one + 1;
}
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
static int mxt_wait_for_completion(struct mxt_data *data,
struct completion *comp,
unsigned int timeout_ms)
{
struct device *dev = &data->client->dev;
unsigned long timeout = msecs_to_jiffies(timeout_ms);
long ret;
ret = wait_for_completion_interruptible_timeout(comp, timeout);
if (ret < 0) {
return ret;
} else if (ret == 0) {
dev_err(dev, "Wait for completion timed out.\n");
return -ETIMEDOUT;
}
return 0;
}
static int mxt_bootloader_read(struct mxt_data *data,
u8 *val, unsigned int count)
{
int ret;
struct i2c_msg msg;
msg.addr = data->bootloader_addr;
msg.flags = data->client->flags & I2C_M_TEN;
msg.flags |= I2C_M_RD;
msg.len = count;
msg.buf = val;
ret = i2c_transfer(data->client->adapter, &msg, 1);
if (ret == 1) {
ret = 0;
} else {
ret = ret < 0 ? ret : -EIO;
dev_err(&data->client->dev, "%s: i2c recv failed (%d)\n",
__func__, ret);
}
return ret;
}
static int mxt_bootloader_write(struct mxt_data *data,
const u8 * const val, unsigned int count)
{
int ret;
struct i2c_msg msg;
msg.addr = data->bootloader_addr;
msg.flags = data->client->flags & I2C_M_TEN;
msg.len = count;
msg.buf = (u8 *)val;
ret = i2c_transfer(data->client->adapter, &msg, 1);
if (ret == 1) {
ret = 0;
} else {
ret = ret < 0 ? ret : -EIO;
dev_err(&data->client->dev, "%s: i2c send failed (%d)\n",
__func__, ret);
}
return ret;
}
static int mxt_lookup_bootloader_address(struct mxt_data *data)
{
u8 appmode = data->client->addr;
u8 bootloader;
switch (appmode) {
case 0x4a:
case 0x4b:
case 0x4c:
case 0x4d:
case 0x5a:
case 0x5b:
bootloader = appmode - 0x26;
break;
default:
dev_err(&data->client->dev,
"Appmode i2c address 0x%02x not found\n",
appmode);
return -EINVAL;
}
data->bootloader_addr = bootloader;
return 0;
}
static u8 mxt_get_bootloader_version(struct mxt_data *data, u8 val)
{
struct device *dev = &data->client->dev;
u8 buf[3];
if (val & MXT_BOOT_EXTENDED_ID) {
if (mxt_bootloader_read(data, &buf[0], 3) != 0) {
dev_err(dev, "%s: i2c failure\n", __func__);
return val;
}
dev_dbg(dev, "Bootloader ID:%d Version:%d\n", buf[1], buf[2]);
return buf[0];
} else {
dev_dbg(dev, "Bootloader ID:%d\n", val & MXT_BOOT_ID_MASK);
return val;
}
}
static int mxt_check_bootloader(struct mxt_data *data, unsigned int state)
{
struct device *dev = &data->client->dev;
u8 val;
int ret;
recheck:
if (state != MXT_WAITING_BOOTLOAD_CMD) {
ret = mxt_wait_for_completion(data, &data->bl_completion,
MXT_FW_CHG_TIMEOUT);
if (ret) {
dev_err(dev, "Update wait error %d\n", ret);
return ret;
}
}
ret = mxt_bootloader_read(data, &val, 1);
if (ret)
return ret;
if (state == MXT_WAITING_BOOTLOAD_CMD)
val = mxt_get_bootloader_version(data, val);
switch (state) {
case MXT_WAITING_BOOTLOAD_CMD:
case MXT_WAITING_FRAME_DATA:
val &= ~MXT_BOOT_STATUS_MASK;
break;
case MXT_FRAME_CRC_PASS:
if (val == MXT_FRAME_CRC_CHECK) {
goto recheck;
} else if (val == MXT_FRAME_CRC_FAIL) {
dev_err(dev, "Bootloader CRC fail\n");
return -EINVAL;
}
break;
default:
return -EINVAL;
}
if (val != state) {
dev_err(dev, "Invalid bootloader state %02X != %02X\n",
val, state);
return -EINVAL;
}
return 0;
}
static int mxt_unlock_bootloader(struct mxt_data *data)
{
int ret;
u8 buf[2];
buf[0] = MXT_UNLOCK_CMD_LSB;
buf[1] = MXT_UNLOCK_CMD_MSB;
ret = mxt_bootloader_write(data, buf, 2);
if (ret)
return ret;
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
dev_err(&data->client->dev, "Invalid object type T%u\n", type);
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
if (!object || offset >= mxt_obj_size(object))
return -EINVAL;
reg = object->start_address;
return mxt_write_reg(data->client, reg + offset, val);
}
static void mxt_input_button(struct mxt_data *data, struct mxt_message *message)
{
struct input_dev *input = data->input_dev;
const struct mxt_platform_data *pdata = data->pdata;
bool button;
int i;
for (i = 0; i < pdata->t19_num_keys; i++) {
if (pdata->t19_keymap[i] == KEY_RESERVED)
continue;
button = !(message->message[0] & (1 << i));
input_report_key(input, pdata->t19_keymap[i], button);
}
}
static void mxt_input_sync(struct input_dev *input_dev)
{
input_mt_report_pointer_emulation(input_dev, false);
input_sync(input_dev);
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
int amplitude;
x = (message->message[1] << 4) | ((message->message[3] >> 4) & 0xf);
y = (message->message[2] << 4) | ((message->message[3] & 0xf));
if (data->max_x < 1024)
x >>= 2;
if (data->max_y < 1024)
y >>= 2;
area = message->message[4];
amplitude = message->message[5];
dev_dbg(dev,
"[%u] %c%c%c%c%c%c%c%c x: %5u y: %5u area: %3u amp: %3u\n",
id,
(status & MXT_T9_DETECT) ? 'D' : '.',
(status & MXT_T9_PRESS) ? 'P' : '.',
(status & MXT_T9_RELEASE) ? 'R' : '.',
(status & MXT_T9_MOVE) ? 'M' : '.',
(status & MXT_T9_VECTOR) ? 'V' : '.',
(status & MXT_T9_AMP) ? 'A' : '.',
(status & MXT_T9_SUPPRESS) ? 'S' : '.',
(status & MXT_T9_UNGRIP) ? 'U' : '.',
x, y, area, amplitude);
input_mt_slot(input_dev, id);
if (status & MXT_T9_DETECT) {
if (status & MXT_T9_RELEASE) {
input_mt_report_slot_state(input_dev,
MT_TOOL_FINGER, 0);
mxt_input_sync(input_dev);
}
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER, 1);
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
input_report_abs(input_dev, ABS_MT_PRESSURE, amplitude);
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR, area);
} else {
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER, 0);
}
}
static u16 mxt_extract_T6_csum(const u8 *csum)
{
return csum[0] | (csum[1] << 8) | (csum[2] << 16);
}
static bool mxt_is_T9_message(struct mxt_data *data, struct mxt_message *msg)
{
u8 id = msg->reportid;
return (id >= data->T9_reportid_min && id <= data->T9_reportid_max);
}
static irqreturn_t mxt_process_messages_until_invalid(struct mxt_data *data)
{
struct mxt_message message;
const u8 *payload = &message.message[0];
struct device *dev = &data->client->dev;
u8 reportid;
bool update_input = false;
u32 crc;
do {
if (mxt_read_message(data, &message)) {
dev_err(dev, "Failed to read message\n");
return IRQ_NONE;
}
reportid = message.reportid;
if (reportid == data->T6_reportid) {
u8 status = payload[0];
crc = mxt_extract_T6_csum(&payload[1]);
if (crc != data->config_crc) {
data->config_crc = crc;
complete(&data->crc_completion);
}
dev_dbg(dev, "Status: %02x Config Checksum: %06x\n",
status, data->config_crc);
if (status & MXT_T6_STATUS_RESET)
complete(&data->reset_completion);
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
if (update_input)
mxt_input_sync(data->input_dev);
return IRQ_HANDLED;
}
static irqreturn_t mxt_interrupt(int irq, void *dev_id)
{
struct mxt_data *data = dev_id;
if (data->in_bootloader) {
complete(&data->bl_completion);
return IRQ_HANDLED;
}
return mxt_process_messages_until_invalid(data);
}
static int mxt_t6_command(struct mxt_data *data, u16 cmd_offset,
u8 value, bool wait)
{
u16 reg;
u8 command_register;
int timeout_counter = 0;
int ret;
reg = data->T6_address + cmd_offset;
ret = mxt_write_reg(data->client, reg, value);
if (ret)
return ret;
if (!wait)
return 0;
do {
msleep(20);
ret = __mxt_read_reg(data->client, reg, 1, &command_register);
if (ret)
return ret;
} while (command_register != 0 && timeout_counter++ <= 100);
if (timeout_counter > 100) {
dev_err(&data->client->dev, "Command failed!\n");
return -EIO;
}
return 0;
}
static int mxt_soft_reset(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
int ret = 0;
dev_info(dev, "Resetting chip\n");
reinit_completion(&data->reset_completion);
ret = mxt_t6_command(data, MXT_COMMAND_RESET, MXT_RESET_VALUE, false);
if (ret)
return ret;
ret = mxt_wait_for_completion(data, &data->reset_completion,
MXT_RESET_TIMEOUT);
if (ret)
return ret;
return 0;
}
static void mxt_update_crc(struct mxt_data *data, u8 cmd, u8 value)
{
data->config_crc = 0;
reinit_completion(&data->crc_completion);
mxt_t6_command(data, cmd, value, true);
mxt_wait_for_completion(data, &data->crc_completion, MXT_CRC_TIMEOUT);
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
mxt_update_crc(data, MXT_COMMAND_REPORTALL, 1);
if (data->config_crc == pdata->config_crc) {
dev_info(dev, "Config CRC 0x%06X: OK\n", data->config_crc);
return 0;
}
dev_info(dev, "Config CRC 0x%06X: does not match 0x%06X\n",
data->config_crc, pdata->config_crc);
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
if (!mxt_object_writable(object->type))
continue;
size = mxt_obj_size(object) * mxt_obj_instances(object);
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
mxt_update_crc(data, MXT_COMMAND_BACKUPNV, MXT_BACKUP_VALUE);
ret = mxt_soft_reset(data);
if (ret)
return ret;
dev_info(dev, "Config successfully updated\n");
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
mxt_obj_instances(object);
max_id = reportid - 1;
} else {
min_id = 0;
max_id = 0;
}
dev_dbg(&data->client->dev,
"T%u Start:%u Size:%zu Instances:%zu Report IDs:%u-%u\n",
object->type, object->start_address,
mxt_obj_size(object), mxt_obj_instances(object),
min_id, max_id);
switch (object->type) {
case MXT_GEN_COMMAND_T6:
data->T6_reportid = min_id;
data->T6_address = object->start_address;
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
static int mxt_read_t9_resolution(struct mxt_data *data)
{
struct i2c_client *client = data->client;
int error;
struct t9_range range;
unsigned char orient;
struct mxt_object *object;
object = mxt_get_object(data, MXT_TOUCH_MULTI_T9);
if (!object)
return -EINVAL;
error = __mxt_read_reg(client,
object->start_address + MXT_T9_RANGE,
sizeof(range), &range);
if (error)
return error;
le16_to_cpus(&range.x);
le16_to_cpus(&range.y);
error = __mxt_read_reg(client,
object->start_address + MXT_T9_ORIENT,
1, &orient);
if (error)
return error;
if (range.x == 0)
range.x = 1023;
if (range.y == 0)
range.y = 1023;
if (orient & MXT_T9_ORIENT_SWITCH) {
data->max_x = range.y;
data->max_y = range.x;
} else {
data->max_x = range.x;
data->max_y = range.y;
}
dev_dbg(&client->dev,
"Touchscreen size X%uY%u\n", data->max_x, data->max_y);
return 0;
}
static int mxt_initialize(struct mxt_data *data)
{
struct i2c_client *client = data->client;
struct mxt_info *info = &data->info;
int error;
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
if (error) {
dev_err(&client->dev, "Error %d reading object table\n", error);
goto err_free_object_table;
}
error = mxt_check_reg_init(data);
if (error) {
dev_err(&client->dev, "Error %d initializing configuration\n",
error);
goto err_free_object_table;
}
error = mxt_read_t9_resolution(data);
if (error) {
dev_err(&client->dev, "Failed to initialize T9 resolution\n");
goto err_free_object_table;
}
dev_info(&client->dev,
"Family: %u Variant: %u Firmware V%u.%u.%02X Objects: %u\n",
info->family_id, info->variant_id, info->version >> 4,
info->version & 0xf, info->build, info->object_num);
return 0;
err_free_object_table:
mxt_free_object_table(data);
return error;
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
if (mxt_obj_instances(object) > 1)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Instance %u\n", instance);
for (i = 0; i < mxt_obj_size(object); i++)
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
for (j = 0; j < mxt_obj_instances(object); j++) {
u16 size = mxt_obj_size(object);
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
static int mxt_check_firmware_format(struct device *dev,
const struct firmware *fw)
{
unsigned int pos = 0;
char c;
while (pos < fw->size) {
c = *(fw->data + pos);
if (c < '0' || (c > '9' && c < 'A') || c > 'F')
return 0;
pos++;
}
dev_err(dev, "Aborting: firmware file must be in binary format\n");
return -EINVAL;
}
static int mxt_load_fw(struct device *dev, const char *fn)
{
struct mxt_data *data = dev_get_drvdata(dev);
const struct firmware *fw = NULL;
unsigned int frame_size;
unsigned int pos = 0;
unsigned int retry = 0;
unsigned int frame = 0;
int ret;
ret = request_firmware(&fw, fn, dev);
if (ret) {
dev_err(dev, "Unable to open firmware %s\n", fn);
return ret;
}
ret = mxt_check_firmware_format(dev, fw);
if (ret)
goto release_firmware;
ret = mxt_lookup_bootloader_address(data);
if (ret)
goto release_firmware;
data->in_bootloader = true;
ret = mxt_t6_command(data, MXT_COMMAND_RESET, MXT_BOOT_VALUE, false);
if (ret)
goto release_firmware;
msleep(MXT_RESET_TIME);
reinit_completion(&data->bl_completion);
ret = mxt_check_bootloader(data, MXT_WAITING_BOOTLOAD_CMD);
if (ret)
goto disable_irq;
mxt_unlock_bootloader(data);
while (pos < fw->size) {
ret = mxt_check_bootloader(data, MXT_WAITING_FRAME_DATA);
if (ret)
goto disable_irq;
frame_size = ((*(fw->data + pos) << 8) | *(fw->data + pos + 1));
frame_size += 2;
ret = mxt_bootloader_write(data, fw->data + pos, frame_size);
if (ret)
goto disable_irq;
ret = mxt_check_bootloader(data, MXT_FRAME_CRC_PASS);
if (ret) {
retry++;
msleep(retry * 20);
if (retry > 20) {
dev_err(dev, "Retry count exceeded\n");
goto disable_irq;
}
} else {
retry = 0;
pos += frame_size;
frame++;
}
if (frame % 50 == 0)
dev_dbg(dev, "Sent %d frames, %d/%zd bytes\n",
frame, pos, fw->size);
}
ret = mxt_wait_for_completion(data, &data->bl_completion,
MXT_FW_RESET_TIME);
if (ret)
goto disable_irq;
dev_dbg(dev, "Sent %d frames, %d bytes\n", frame, pos);
mxt_wait_for_completion(data, &data->bl_completion, MXT_FW_RESET_TIME);
data->in_bootloader = false;
disable_irq:
disable_irq(data->irq);
release_firmware:
release_firmware(fw);
return ret;
}
static ssize_t mxt_update_fw_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct mxt_data *data = dev_get_drvdata(dev);
int error;
error = mxt_load_fw(dev, MXT_FW_NAME);
if (error) {
dev_err(dev, "The firmware update failed(%d)\n", error);
count = error;
} else {
dev_info(dev, "The firmware update succeeded\n");
mxt_free_object_table(data);
mxt_initialize(data);
enable_irq(data->irq);
error = mxt_make_highchg(data);
if (error)
return error;
}
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
unsigned int mt_flags = 0;
int i;
if (!pdata)
return -EINVAL;
data = kzalloc(sizeof(struct mxt_data), GFP_KERNEL);
input_dev = input_allocate_device();
if (!data || !input_dev) {
dev_err(&client->dev, "Failed to allocate memory\n");
error = -ENOMEM;
goto err_free_mem;
}
input_dev->name = "Atmel maXTouch Touchscreen";
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
init_completion(&data->bl_completion);
init_completion(&data->reset_completion);
init_completion(&data->crc_completion);
error = mxt_initialize(data);
if (error)
goto err_free_mem;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
if (pdata->t19_num_keys) {
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
for (i = 0; i < pdata->t19_num_keys; i++)
if (pdata->t19_keymap[i] != KEY_RESERVED)
input_set_capability(input_dev, EV_KEY,
pdata->t19_keymap[i]);
mt_flags |= INPUT_MT_POINTER;
input_abs_set_res(input_dev, ABS_X, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_Y, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_X,
MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_Y,
MXT_PIXELS_PER_MM);
input_dev->name = "Atmel maXTouch Touchpad";
}
input_set_abs_params(input_dev, ABS_X,
0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_Y,
0, data->max_y, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, 255, 0, 0);
num_mt_slots = data->T9_reportid_max - data->T9_reportid_min + 1;
error = input_mt_init_slots(input_dev, num_mt_slots, mt_flags);
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
if (error) {
dev_err(&client->dev, "Error %d registering input device\n",
error);
goto err_free_irq;
}
error = sysfs_create_group(&client->dev.kobj, &mxt_attr_group);
if (error) {
dev_err(&client->dev, "Failure %d creating sysfs group\n",
error);
goto err_unregister_device;
}
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
mxt_soft_reset(data);
mutex_lock(&input_dev->mutex);
if (input_dev->users)
mxt_start(data);
mutex_unlock(&input_dev->mutex);
return 0;
}
