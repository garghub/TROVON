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
case MXT_TOUCH_MULTITOUCHSCREEN_T100:
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
static void mxt_dump_message(struct mxt_data *data, u8 *message)
{
dev_dbg(&data->client->dev, "message: %*ph\n",
data->T5_msg_size, message);
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
static int mxt_lookup_bootloader_address(struct mxt_data *data, bool retry)
{
u8 appmode = data->client->addr;
u8 bootloader;
switch (appmode) {
case 0x4a:
case 0x4b:
if (retry || data->info.family_id >= 0xa2) {
bootloader = appmode - 0x24;
break;
}
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
static int mxt_probe_bootloader(struct mxt_data *data, bool alt_address)
{
struct device *dev = &data->client->dev;
int error;
u8 val;
bool crc_failure;
error = mxt_lookup_bootloader_address(data, alt_address);
if (error)
return error;
error = mxt_bootloader_read(data, &val, 1);
if (error)
return error;
crc_failure = (val & ~MXT_BOOT_STATUS_MASK) == MXT_APP_CRC_FAIL;
dev_err(dev, "Detected bootloader, status:%02X%s\n",
val, crc_failure ? ", APP_CRC_FAIL" : "");
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
static int mxt_check_bootloader(struct mxt_data *data, unsigned int state,
bool wait)
{
struct device *dev = &data->client->dev;
u8 val;
int ret;
recheck:
if (wait) {
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
case MXT_APP_CRC_FAIL:
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
static int mxt_send_bootloader_cmd(struct mxt_data *data, bool unlock)
{
int ret;
u8 buf[2];
if (unlock) {
buf[0] = MXT_UNLOCK_CMD_LSB;
buf[1] = MXT_UNLOCK_CMD_MSB;
} else {
buf[0] = 0x01;
buf[1] = 0x01;
}
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
dev_warn(&data->client->dev, "Invalid object type T%u\n", type);
return NULL;
}
static void mxt_proc_t6_messages(struct mxt_data *data, u8 *msg)
{
struct device *dev = &data->client->dev;
u8 status = msg[1];
u32 crc = msg[2] | (msg[3] << 8) | (msg[4] << 16);
complete(&data->crc_completion);
if (crc != data->config_crc) {
data->config_crc = crc;
dev_dbg(dev, "T6 Config Checksum: 0x%06X\n", crc);
}
if (status & MXT_T6_STATUS_RESET)
complete(&data->reset_completion);
if (status != data->t6_status)
dev_dbg(dev, "T6 Status 0x%02X%s%s%s%s%s%s%s\n",
status,
status == 0 ? " OK" : "",
status & MXT_T6_STATUS_RESET ? " RESET" : "",
status & MXT_T6_STATUS_OFL ? " OFL" : "",
status & MXT_T6_STATUS_SIGERR ? " SIGERR" : "",
status & MXT_T6_STATUS_CAL ? " CAL" : "",
status & MXT_T6_STATUS_CFGERR ? " CFGERR" : "",
status & MXT_T6_STATUS_COMSERR ? " COMSERR" : "");
data->t6_status = status;
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
static void mxt_input_button(struct mxt_data *data, u8 *message)
{
struct input_dev *input = data->input_dev;
const struct mxt_platform_data *pdata = data->pdata;
int i;
for (i = 0; i < pdata->t19_num_keys; i++) {
if (pdata->t19_keymap[i] == KEY_RESERVED)
continue;
input_report_key(input, pdata->t19_keymap[i],
!(message[1] & BIT(i)));
}
}
static void mxt_input_sync(struct mxt_data *data)
{
input_mt_report_pointer_emulation(data->input_dev,
data->pdata->t19_num_keys);
input_sync(data->input_dev);
}
static void mxt_proc_t9_message(struct mxt_data *data, u8 *message)
{
struct device *dev = &data->client->dev;
struct input_dev *input_dev = data->input_dev;
int id;
u8 status;
int x;
int y;
int area;
int amplitude;
id = message[0] - data->T9_reportid_min;
status = message[1];
x = (message[2] << 4) | ((message[4] >> 4) & 0xf);
y = (message[3] << 4) | ((message[4] & 0xf));
if (data->max_x < 1024)
x >>= 2;
if (data->max_y < 1024)
y >>= 2;
area = message[5];
amplitude = message[6];
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
mxt_input_sync(data);
}
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER, 1);
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
input_report_abs(input_dev, ABS_MT_PRESSURE, amplitude);
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR, area);
} else {
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER, 0);
}
data->update_input = true;
}
static void mxt_proc_t100_message(struct mxt_data *data, u8 *message)
{
struct device *dev = &data->client->dev;
struct input_dev *input_dev = data->input_dev;
int id;
u8 status;
u8 type = 0;
u16 x;
u16 y;
int distance = 0;
int tool = 0;
u8 major = 0;
u8 pressure = 0;
u8 orientation = 0;
id = message[0] - data->T100_reportid_min - 2;
if (id < 0)
return;
status = message[1];
x = get_unaligned_le16(&message[2]);
y = get_unaligned_le16(&message[4]);
if (status & MXT_T100_DETECT) {
type = (status & MXT_T100_TYPE_MASK) >> 4;
switch (type) {
case MXT_T100_TYPE_HOVERING_FINGER:
tool = MT_TOOL_FINGER;
distance = MXT_DISTANCE_HOVERING;
if (data->t100_aux_vect)
orientation = message[data->t100_aux_vect];
break;
case MXT_T100_TYPE_FINGER:
case MXT_T100_TYPE_GLOVE:
tool = MT_TOOL_FINGER;
distance = MXT_DISTANCE_ACTIVE_TOUCH;
if (data->t100_aux_area)
major = message[data->t100_aux_area];
if (data->t100_aux_ampl)
pressure = message[data->t100_aux_ampl];
if (data->t100_aux_vect)
orientation = message[data->t100_aux_vect];
break;
case MXT_T100_TYPE_PASSIVE_STYLUS:
tool = MT_TOOL_PEN;
major = MXT_TOUCH_MAJOR_DEFAULT;
if (data->t100_aux_ampl)
pressure = message[data->t100_aux_ampl];
break;
case MXT_T100_TYPE_LARGE_TOUCH:
break;
default:
dev_dbg(dev, "Unexpected T100 type\n");
return;
}
}
if (!pressure && type != MXT_T100_TYPE_HOVERING_FINGER)
pressure = MXT_PRESSURE_DEFAULT;
input_mt_slot(input_dev, id);
if (status & MXT_T100_DETECT) {
dev_dbg(dev, "[%u] type:%u x:%u y:%u a:%02X p:%02X v:%02X\n",
id, type, x, y, major, pressure, orientation);
input_mt_report_slot_state(input_dev, tool, 1);
input_report_abs(input_dev, ABS_MT_POSITION_X, x);
input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR, major);
input_report_abs(input_dev, ABS_MT_PRESSURE, pressure);
input_report_abs(input_dev, ABS_MT_DISTANCE, distance);
input_report_abs(input_dev, ABS_MT_ORIENTATION, orientation);
} else {
dev_dbg(dev, "[%u] release\n", id);
input_mt_report_slot_state(input_dev, 0, 0);
}
data->update_input = true;
}
static int mxt_proc_message(struct mxt_data *data, u8 *message)
{
u8 report_id = message[0];
if (report_id == MXT_RPTID_NOMSG)
return 0;
if (report_id == data->T6_reportid) {
mxt_proc_t6_messages(data, message);
} else if (!data->input_dev) {
mxt_dump_message(data, message);
} else if (report_id >= data->T9_reportid_min &&
report_id <= data->T9_reportid_max) {
mxt_proc_t9_message(data, message);
} else if (report_id >= data->T100_reportid_min &&
report_id <= data->T100_reportid_max) {
mxt_proc_t100_message(data, message);
} else if (report_id == data->T19_reportid) {
mxt_input_button(data, message);
data->update_input = true;
} else {
mxt_dump_message(data, message);
}
return 1;
}
static int mxt_read_and_process_messages(struct mxt_data *data, u8 count)
{
struct device *dev = &data->client->dev;
int ret;
int i;
u8 num_valid = 0;
if (count > data->max_reportid)
return -EINVAL;
ret = __mxt_read_reg(data->client, data->T5_address,
data->T5_msg_size * count, data->msg_buf);
if (ret) {
dev_err(dev, "Failed to read %u messages (%d)\n", count, ret);
return ret;
}
for (i = 0; i < count; i++) {
ret = mxt_proc_message(data,
data->msg_buf + data->T5_msg_size * i);
if (ret == 1)
num_valid++;
}
return num_valid;
}
static irqreturn_t mxt_process_messages_t44(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
int ret;
u8 count, num_left;
ret = __mxt_read_reg(data->client, data->T44_address,
data->T5_msg_size + 1, data->msg_buf);
if (ret) {
dev_err(dev, "Failed to read T44 and T5 (%d)\n", ret);
return IRQ_NONE;
}
count = data->msg_buf[0];
if (count == 0)
return IRQ_NONE;
if (count > data->max_reportid) {
dev_warn(dev, "T44 count %d exceeded max report id\n", count);
count = data->max_reportid;
}
ret = mxt_proc_message(data, data->msg_buf + 1);
if (ret < 0) {
dev_warn(dev, "Unexpected invalid message\n");
return IRQ_NONE;
}
num_left = count - 1;
if (num_left) {
ret = mxt_read_and_process_messages(data, num_left);
if (ret < 0)
goto end;
else if (ret != num_left)
dev_warn(dev, "Unexpected invalid message\n");
}
end:
if (data->update_input) {
mxt_input_sync(data);
data->update_input = false;
}
return IRQ_HANDLED;
}
static int mxt_process_messages_until_invalid(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
int count, read;
u8 tries = 2;
count = data->max_reportid;
do {
read = mxt_read_and_process_messages(data, count);
if (read < count)
return 0;
} while (--tries);
if (data->update_input) {
mxt_input_sync(data);
data->update_input = false;
}
dev_err(dev, "CHG pin isn't cleared\n");
return -EBUSY;
}
static irqreturn_t mxt_process_messages(struct mxt_data *data)
{
int total_handled, num_handled;
u8 count = data->last_message_count;
if (count < 1 || count > data->max_reportid)
count = 1;
total_handled = mxt_read_and_process_messages(data, count + 1);
if (total_handled < 0)
return IRQ_NONE;
else if (total_handled <= count)
goto update_count;
do {
num_handled = mxt_read_and_process_messages(data, 2);
if (num_handled < 0)
return IRQ_NONE;
total_handled += num_handled;
if (num_handled < 2)
break;
} while (total_handled < data->num_touchids);
update_count:
data->last_message_count = total_handled;
if (data->update_input) {
mxt_input_sync(data);
data->update_input = false;
}
return IRQ_HANDLED;
}
static irqreturn_t mxt_interrupt(int irq, void *dev_id)
{
struct mxt_data *data = dev_id;
if (data->in_bootloader) {
complete(&data->bl_completion);
return IRQ_HANDLED;
}
if (!data->object_table)
return IRQ_HANDLED;
if (data->T44_address) {
return mxt_process_messages_t44(data);
} else {
return mxt_process_messages(data);
}
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
static int mxt_acquire_irq(struct mxt_data *data)
{
int error;
enable_irq(data->irq);
error = mxt_process_messages_until_invalid(data);
if (error)
return error;
return 0;
}
static int mxt_soft_reset(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
int ret = 0;
dev_info(dev, "Resetting device\n");
disable_irq(data->irq);
reinit_completion(&data->reset_completion);
ret = mxt_t6_command(data, MXT_COMMAND_RESET, MXT_RESET_VALUE, false);
if (ret)
return ret;
msleep(100);
mxt_acquire_irq(data);
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
static void mxt_calc_crc24(u32 *crc, u8 firstbyte, u8 secondbyte)
{
static const unsigned int crcpoly = 0x80001B;
u32 result;
u32 data_word;
data_word = (secondbyte << 8) | firstbyte;
result = ((*crc << 1) ^ data_word);
if (result & 0x1000000)
result ^= crcpoly;
*crc = result;
}
static u32 mxt_calculate_crc(u8 *base, off_t start_off, off_t end_off)
{
u32 crc = 0;
u8 *ptr = base + start_off;
u8 *last_val = base + end_off - 1;
if (end_off < start_off)
return -EINVAL;
while (ptr < last_val) {
mxt_calc_crc24(&crc, *ptr, *(ptr + 1));
ptr += 2;
}
if (ptr == last_val)
mxt_calc_crc24(&crc, *ptr, 0);
crc &= 0x00FFFFFF;
return crc;
}
static int mxt_prepare_cfg_mem(struct mxt_data *data,
const struct firmware *cfg,
unsigned int data_pos,
unsigned int cfg_start_ofs,
u8 *config_mem,
size_t config_mem_size)
{
struct device *dev = &data->client->dev;
struct mxt_object *object;
unsigned int type, instance, size, byte_offset;
int offset;
int ret;
int i;
u16 reg;
u8 val;
while (data_pos < cfg->size) {
ret = sscanf(cfg->data + data_pos, "%x %x %x%n",
&type, &instance, &size, &offset);
if (ret == 0) {
break;
} else if (ret != 3) {
dev_err(dev, "Bad format: failed to parse object\n");
return -EINVAL;
}
data_pos += offset;
object = mxt_get_object(data, type);
if (!object) {
for (i = 0; i < size; i++) {
ret = sscanf(cfg->data + data_pos, "%hhx%n",
&val, &offset);
if (ret != 1) {
dev_err(dev, "Bad format in T%d at %d\n",
type, i);
return -EINVAL;
}
data_pos += offset;
}
continue;
}
if (size > mxt_obj_size(object)) {
dev_warn(dev, "Discarding %zu byte(s) in T%u\n",
size - mxt_obj_size(object), type);
} else if (mxt_obj_size(object) > size) {
dev_warn(dev, "Zeroing %zu byte(s) in T%d\n",
mxt_obj_size(object) - size, type);
}
if (instance >= mxt_obj_instances(object)) {
dev_err(dev, "Object instances exceeded!\n");
return -EINVAL;
}
reg = object->start_address + mxt_obj_size(object) * instance;
for (i = 0; i < size; i++) {
ret = sscanf(cfg->data + data_pos, "%hhx%n",
&val,
&offset);
if (ret != 1) {
dev_err(dev, "Bad format in T%d at %d\n",
type, i);
return -EINVAL;
}
data_pos += offset;
if (i > mxt_obj_size(object))
continue;
byte_offset = reg + i - cfg_start_ofs;
if (byte_offset >= 0 && byte_offset < config_mem_size) {
*(config_mem + byte_offset) = val;
} else {
dev_err(dev, "Bad object: reg:%d, T%d, ofs=%d\n",
reg, object->type, byte_offset);
return -EINVAL;
}
}
}
return 0;
}
static int mxt_upload_cfg_mem(struct mxt_data *data, unsigned int cfg_start,
u8 *config_mem, size_t config_mem_size)
{
unsigned int byte_offset = 0;
int error;
while (byte_offset < config_mem_size) {
unsigned int size = config_mem_size - byte_offset;
if (size > MXT_MAX_BLOCK_WRITE)
size = MXT_MAX_BLOCK_WRITE;
error = __mxt_write_reg(data->client,
cfg_start + byte_offset,
size, config_mem + byte_offset);
if (error) {
dev_err(&data->client->dev,
"Config write error, ret=%d\n", error);
return error;
}
byte_offset += size;
}
return 0;
}
static int mxt_update_cfg(struct mxt_data *data, const struct firmware *cfg)
{
struct device *dev = &data->client->dev;
struct mxt_info cfg_info;
int ret;
int offset;
int data_pos;
int i;
int cfg_start_ofs;
u32 info_crc, config_crc, calculated_crc;
u8 *config_mem;
size_t config_mem_size;
mxt_update_crc(data, MXT_COMMAND_REPORTALL, 1);
if (strncmp(cfg->data, MXT_CFG_MAGIC, strlen(MXT_CFG_MAGIC))) {
dev_err(dev, "Unrecognised config file\n");
return -EINVAL;
}
data_pos = strlen(MXT_CFG_MAGIC);
for (i = 0; i < sizeof(struct mxt_info); i++) {
ret = sscanf(cfg->data + data_pos, "%hhx%n",
(unsigned char *)&cfg_info + i,
&offset);
if (ret != 1) {
dev_err(dev, "Bad format\n");
return -EINVAL;
}
data_pos += offset;
}
if (cfg_info.family_id != data->info.family_id) {
dev_err(dev, "Family ID mismatch!\n");
return -EINVAL;
}
if (cfg_info.variant_id != data->info.variant_id) {
dev_err(dev, "Variant ID mismatch!\n");
return -EINVAL;
}
ret = sscanf(cfg->data + data_pos, "%x%n", &info_crc, &offset);
if (ret != 1) {
dev_err(dev, "Bad format: failed to parse Info CRC\n");
return -EINVAL;
}
data_pos += offset;
ret = sscanf(cfg->data + data_pos, "%x%n", &config_crc, &offset);
if (ret != 1) {
dev_err(dev, "Bad format: failed to parse Config CRC\n");
return -EINVAL;
}
data_pos += offset;
if (info_crc == data->info_crc) {
if (config_crc == 0 || data->config_crc == 0) {
dev_info(dev, "CRC zero, attempting to apply config\n");
} else if (config_crc == data->config_crc) {
dev_dbg(dev, "Config CRC 0x%06X: OK\n",
data->config_crc);
return 0;
} else {
dev_info(dev, "Config CRC 0x%06X: does not match file 0x%06X\n",
data->config_crc, config_crc);
}
} else {
dev_warn(dev,
"Warning: Info CRC error - device=0x%06X file=0x%06X\n",
data->info_crc, info_crc);
}
cfg_start_ofs = MXT_OBJECT_START +
data->info.object_num * sizeof(struct mxt_object) +
MXT_INFO_CHECKSUM_SIZE;
config_mem_size = data->mem_size - cfg_start_ofs;
config_mem = kzalloc(config_mem_size, GFP_KERNEL);
if (!config_mem) {
dev_err(dev, "Failed to allocate memory\n");
return -ENOMEM;
}
ret = mxt_prepare_cfg_mem(data, cfg, data_pos, cfg_start_ofs,
config_mem, config_mem_size);
if (ret)
goto release_mem;
if (data->T7_address < cfg_start_ofs) {
dev_err(dev, "Bad T7 address, T7addr = %x, config offset %x\n",
data->T7_address, cfg_start_ofs);
ret = 0;
goto release_mem;
}
calculated_crc = mxt_calculate_crc(config_mem,
data->T7_address - cfg_start_ofs,
config_mem_size);
if (config_crc > 0 && config_crc != calculated_crc)
dev_warn(dev, "Config CRC error, calculated=%06X, file=%06X\n",
calculated_crc, config_crc);
ret = mxt_upload_cfg_mem(data, cfg_start_ofs,
config_mem, config_mem_size);
if (ret)
goto release_mem;
mxt_update_crc(data, MXT_COMMAND_BACKUPNV, MXT_BACKUP_VALUE);
ret = mxt_soft_reset(data);
if (ret)
goto release_mem;
dev_info(dev, "Config successfully updated\n");
mxt_init_t7_power_cfg(data);
release_mem:
kfree(config_mem);
return ret;
}
static int mxt_get_info(struct mxt_data *data)
{
struct i2c_client *client = data->client;
struct mxt_info *info = &data->info;
int error;
error = __mxt_read_reg(client, 0, sizeof(*info), info);
if (error)
return error;
return 0;
}
static void mxt_free_input_device(struct mxt_data *data)
{
if (data->input_dev) {
input_unregister_device(data->input_dev);
data->input_dev = NULL;
}
}
static void mxt_free_object_table(struct mxt_data *data)
{
#ifdef CONFIG_TOUCHSCREEN_ATMEL_MXT_T37
video_unregister_device(&data->dbg.vdev);
v4l2_device_unregister(&data->dbg.v4l2);
#endif
kfree(data->object_table);
data->object_table = NULL;
kfree(data->msg_buf);
data->msg_buf = NULL;
data->T5_address = 0;
data->T5_msg_size = 0;
data->T6_reportid = 0;
data->T7_address = 0;
data->T9_reportid_min = 0;
data->T9_reportid_max = 0;
data->T19_reportid = 0;
data->T44_address = 0;
data->T100_reportid_min = 0;
data->T100_reportid_max = 0;
data->max_reportid = 0;
}
static int mxt_get_object_table(struct mxt_data *data)
{
struct i2c_client *client = data->client;
size_t table_size;
struct mxt_object *object_table;
int error;
int i;
u8 reportid;
u16 end_address;
table_size = data->info.object_num * sizeof(struct mxt_object);
object_table = kzalloc(table_size, GFP_KERNEL);
if (!object_table) {
dev_err(&data->client->dev, "Failed to allocate memory\n");
return -ENOMEM;
}
error = __mxt_read_reg(client, MXT_OBJECT_START, table_size,
object_table);
if (error) {
kfree(object_table);
return error;
}
reportid = 1;
data->mem_size = 0;
for (i = 0; i < data->info.object_num; i++) {
struct mxt_object *object = object_table + i;
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
case MXT_GEN_MESSAGE_T5:
if (data->info.family_id == 0x80 &&
data->info.version < 0x20) {
data->T5_msg_size = mxt_obj_size(object);
} else {
data->T5_msg_size = mxt_obj_size(object) - 1;
}
data->T5_address = object->start_address;
break;
case MXT_GEN_COMMAND_T6:
data->T6_reportid = min_id;
data->T6_address = object->start_address;
break;
case MXT_GEN_POWER_T7:
data->T7_address = object->start_address;
break;
case MXT_TOUCH_MULTI_T9:
data->multitouch = MXT_TOUCH_MULTI_T9;
data->T9_reportid_min = min_id;
data->T9_reportid_max = max_id;
data->num_touchids = object->num_report_ids
* mxt_obj_instances(object);
break;
case MXT_SPT_MESSAGECOUNT_T44:
data->T44_address = object->start_address;
break;
case MXT_SPT_GPIOPWM_T19:
data->T19_reportid = min_id;
break;
case MXT_TOUCH_MULTITOUCHSCREEN_T100:
data->multitouch = MXT_TOUCH_MULTITOUCHSCREEN_T100;
data->T100_reportid_min = min_id;
data->T100_reportid_max = max_id;
data->num_touchids = object->num_report_ids - 2;
break;
}
end_address = object->start_address
+ mxt_obj_size(object) * mxt_obj_instances(object) - 1;
if (end_address >= data->mem_size)
data->mem_size = end_address + 1;
}
data->max_reportid = reportid;
if (data->T44_address && (data->T5_address != data->T44_address + 1)) {
dev_err(&client->dev, "Invalid T44 position\n");
error = -EINVAL;
goto free_object_table;
}
data->msg_buf = kcalloc(data->max_reportid,
data->T5_msg_size, GFP_KERNEL);
if (!data->msg_buf) {
dev_err(&client->dev, "Failed to allocate message buffer\n");
error = -ENOMEM;
goto free_object_table;
}
data->object_table = object_table;
return 0;
free_object_table:
mxt_free_object_table(data);
return error;
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
object->start_address + MXT_T9_XSIZE,
sizeof(data->xsize), &data->xsize);
if (error)
return error;
error = __mxt_read_reg(client,
object->start_address + MXT_T9_YSIZE,
sizeof(data->ysize), &data->ysize);
if (error)
return error;
error = __mxt_read_reg(client,
object->start_address + MXT_T9_RANGE,
sizeof(range), &range);
if (error)
return error;
data->max_x = get_unaligned_le16(&range.x);
data->max_y = get_unaligned_le16(&range.y);
error = __mxt_read_reg(client,
object->start_address + MXT_T9_ORIENT,
1, &orient);
if (error)
return error;
data->xy_switch = orient & MXT_T9_ORIENT_SWITCH;
data->invertx = orient & MXT_T9_ORIENT_INVERTX;
data->inverty = orient & MXT_T9_ORIENT_INVERTY;
return 0;
}
static int mxt_read_t100_config(struct mxt_data *data)
{
struct i2c_client *client = data->client;
int error;
struct mxt_object *object;
u16 range_x, range_y;
u8 cfg, tchaux;
u8 aux;
object = mxt_get_object(data, MXT_TOUCH_MULTITOUCHSCREEN_T100);
if (!object)
return -EINVAL;
error = __mxt_read_reg(client,
object->start_address + MXT_T100_XRANGE,
sizeof(range_x), &range_x);
if (error)
return error;
data->max_x = get_unaligned_le16(&range_x);
error = __mxt_read_reg(client,
object->start_address + MXT_T100_YRANGE,
sizeof(range_y), &range_y);
if (error)
return error;
data->max_y = get_unaligned_le16(&range_y);
error = __mxt_read_reg(client,
object->start_address + MXT_T100_XSIZE,
sizeof(data->xsize), &data->xsize);
if (error)
return error;
error = __mxt_read_reg(client,
object->start_address + MXT_T100_YSIZE,
sizeof(data->ysize), &data->ysize);
if (error)
return error;
error = __mxt_read_reg(client,
object->start_address + MXT_T100_CFG1,
1, &cfg);
if (error)
return error;
data->xy_switch = cfg & MXT_T100_CFG_SWITCHXY;
data->invertx = cfg & MXT_T100_CFG_INVERTX;
data->inverty = cfg & MXT_T100_CFG_INVERTY;
error = __mxt_read_reg(client,
object->start_address + MXT_T100_TCHAUX,
1, &tchaux);
if (error)
return error;
aux = 6;
if (tchaux & MXT_T100_TCHAUX_VECT)
data->t100_aux_vect = aux++;
if (tchaux & MXT_T100_TCHAUX_AMPL)
data->t100_aux_ampl = aux++;
if (tchaux & MXT_T100_TCHAUX_AREA)
data->t100_aux_area = aux++;
dev_dbg(&client->dev,
"T100 aux mappings vect:%u ampl:%u area:%u\n",
data->t100_aux_vect, data->t100_aux_ampl, data->t100_aux_area);
return 0;
}
static void mxt_set_up_as_touchpad(struct input_dev *input_dev,
struct mxt_data *data)
{
const struct mxt_platform_data *pdata = data->pdata;
int i;
input_dev->name = "Atmel maXTouch Touchpad";
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
input_abs_set_res(input_dev, ABS_X, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_Y, MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_X,
MXT_PIXELS_PER_MM);
input_abs_set_res(input_dev, ABS_MT_POSITION_Y,
MXT_PIXELS_PER_MM);
for (i = 0; i < pdata->t19_num_keys; i++)
if (pdata->t19_keymap[i] != KEY_RESERVED)
input_set_capability(input_dev, EV_KEY,
pdata->t19_keymap[i]);
}
static int mxt_initialize_input_device(struct mxt_data *data)
{
const struct mxt_platform_data *pdata = data->pdata;
struct device *dev = &data->client->dev;
struct input_dev *input_dev;
int error;
unsigned int num_mt_slots;
unsigned int mt_flags = 0;
switch (data->multitouch) {
case MXT_TOUCH_MULTI_T9:
num_mt_slots = data->T9_reportid_max - data->T9_reportid_min + 1;
error = mxt_read_t9_resolution(data);
if (error)
dev_warn(dev, "Failed to initialize T9 resolution\n");
break;
case MXT_TOUCH_MULTITOUCHSCREEN_T100:
num_mt_slots = data->num_touchids;
error = mxt_read_t100_config(data);
if (error)
dev_warn(dev, "Failed to read T100 config\n");
break;
default:
dev_err(dev, "Invalid multitouch object\n");
return -EINVAL;
}
if (data->max_x == 0)
data->max_x = 1023;
if (data->max_y == 0)
data->max_y = 1023;
if (data->xy_switch)
swap(data->max_x, data->max_y);
dev_info(dev, "Touchscreen size X%uY%u\n", data->max_x, data->max_y);
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(dev, "Failed to allocate memory\n");
return -ENOMEM;
}
input_dev->name = "Atmel maXTouch Touchscreen";
input_dev->phys = data->phys;
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = dev;
input_dev->open = mxt_input_open;
input_dev->close = mxt_input_close;
input_set_capability(input_dev, EV_KEY, BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, data->max_y, 0, 0);
if (data->multitouch == MXT_TOUCH_MULTI_T9 ||
(data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_ampl)) {
input_set_abs_params(input_dev, ABS_PRESSURE, 0, 255, 0, 0);
}
if (pdata->t19_num_keys) {
mxt_set_up_as_touchpad(input_dev, data);
mt_flags |= INPUT_MT_POINTER;
} else {
mt_flags |= INPUT_MT_DIRECT;
}
error = input_mt_init_slots(input_dev, num_mt_slots, mt_flags);
if (error) {
dev_err(dev, "Error %d initialising slots\n", error);
goto err_free_mem;
}
if (data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100) {
input_set_abs_params(input_dev, ABS_MT_TOOL_TYPE,
0, MT_TOOL_MAX, 0, 0);
input_set_abs_params(input_dev, ABS_MT_DISTANCE,
MXT_DISTANCE_ACTIVE_TOUCH,
MXT_DISTANCE_HOVERING,
0, 0);
}
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
0, data->max_y, 0, 0);
if (data->multitouch == MXT_TOUCH_MULTI_T9 ||
(data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_area)) {
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,
0, MXT_MAX_AREA, 0, 0);
}
if (data->multitouch == MXT_TOUCH_MULTI_T9 ||
(data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_ampl)) {
input_set_abs_params(input_dev, ABS_MT_PRESSURE,
0, 255, 0, 0);
}
if (data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_vect) {
input_set_abs_params(input_dev, ABS_MT_ORIENTATION,
0, 255, 0, 0);
}
if (data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_ampl) {
input_set_abs_params(input_dev, ABS_MT_PRESSURE,
0, 255, 0, 0);
}
if (data->multitouch == MXT_TOUCH_MULTITOUCHSCREEN_T100 &&
data->t100_aux_vect) {
input_set_abs_params(input_dev, ABS_MT_ORIENTATION,
0, 255, 0, 0);
}
input_set_drvdata(input_dev, data);
error = input_register_device(input_dev);
if (error) {
dev_err(dev, "Error %d registering input device\n", error);
goto err_free_mem;
}
data->input_dev = input_dev;
return 0;
err_free_mem:
input_free_device(input_dev);
return error;
}
static void mxt_config_cb(const struct firmware *cfg, void *ctx)
{
mxt_configure_objects(ctx, cfg);
release_firmware(cfg);
}
static int mxt_initialize(struct mxt_data *data)
{
struct i2c_client *client = data->client;
int recovery_attempts = 0;
int error;
while (1) {
error = mxt_get_info(data);
if (!error)
break;
error = mxt_probe_bootloader(data, false);
if (error) {
dev_info(&client->dev, "Trying alternate bootloader address\n");
error = mxt_probe_bootloader(data, true);
if (error) {
return error;
}
}
if (++recovery_attempts > 1) {
dev_err(&client->dev, "Could not recover from bootloader mode\n");
data->in_bootloader = true;
return 0;
}
mxt_send_bootloader_cmd(data, false);
msleep(MXT_FW_RESET_TIME);
}
error = mxt_get_object_table(data);
if (error) {
dev_err(&client->dev, "Error %d reading object table\n", error);
return error;
}
error = mxt_acquire_irq(data);
if (error)
goto err_free_object_table;
error = request_firmware_nowait(THIS_MODULE, true, MXT_CFG_NAME,
&client->dev, GFP_KERNEL, data,
mxt_config_cb);
if (error) {
dev_err(&client->dev, "Failed to invoke firmware loader: %d\n",
error);
goto err_free_object_table;
}
return 0;
err_free_object_table:
mxt_free_object_table(data);
return error;
}
static int mxt_set_t7_power_cfg(struct mxt_data *data, u8 sleep)
{
struct device *dev = &data->client->dev;
int error;
struct t7_config *new_config;
struct t7_config deepsleep = { .active = 0, .idle = 0 };
if (sleep == MXT_POWER_CFG_DEEPSLEEP)
new_config = &deepsleep;
else
new_config = &data->t7_cfg;
error = __mxt_write_reg(data->client, data->T7_address,
sizeof(data->t7_cfg), new_config);
if (error)
return error;
dev_dbg(dev, "Set T7 ACTV:%d IDLE:%d\n",
new_config->active, new_config->idle);
return 0;
}
static int mxt_init_t7_power_cfg(struct mxt_data *data)
{
struct device *dev = &data->client->dev;
int error;
bool retry = false;
recheck:
error = __mxt_read_reg(data->client, data->T7_address,
sizeof(data->t7_cfg), &data->t7_cfg);
if (error)
return error;
if (data->t7_cfg.active == 0 || data->t7_cfg.idle == 0) {
if (!retry) {
dev_dbg(dev, "T7 cfg zero, resetting\n");
mxt_soft_reset(data);
retry = true;
goto recheck;
} else {
dev_dbg(dev, "T7 cfg zero after reset, overriding\n");
data->t7_cfg.active = 20;
data->t7_cfg.idle = 100;
return mxt_set_t7_power_cfg(data, MXT_POWER_CFG_RUN);
}
}
dev_dbg(dev, "Initialized power cfg: ACTV %d, IDLE %d\n",
data->t7_cfg.active, data->t7_cfg.idle);
return 0;
}
static u16 mxt_get_debug_value(struct mxt_data *data, unsigned int x,
unsigned int y)
{
struct mxt_info *info = &data->info;
struct mxt_dbg *dbg = &data->dbg;
unsigned int ofs, page;
unsigned int col = 0;
unsigned int col_width;
if (info->family_id == MXT_FAMILY_1386) {
col_width = info->matrix_ysize / MXT1386_COLUMNS;
col = y / col_width;
y = y % col_width;
} else {
col_width = info->matrix_ysize;
}
ofs = (y + (x * col_width)) * sizeof(u16);
page = ofs / MXT_DIAGNOSTIC_SIZE;
ofs %= MXT_DIAGNOSTIC_SIZE;
if (info->family_id == MXT_FAMILY_1386)
page += col * MXT1386_PAGES_PER_COLUMN;
return get_unaligned_le16(&dbg->t37_buf[page].data[ofs]);
}
static int mxt_convert_debug_pages(struct mxt_data *data, u16 *outbuf)
{
struct mxt_dbg *dbg = &data->dbg;
unsigned int x = 0;
unsigned int y = 0;
unsigned int i, rx, ry;
for (i = 0; i < dbg->t37_nodes; i++) {
rx = data->xy_switch ? y : x;
ry = data->xy_switch ? x : y;
rx = data->invertx ? (data->xsize - 1 - rx) : rx;
ry = data->inverty ? (data->ysize - 1 - ry) : ry;
outbuf[i] = mxt_get_debug_value(data, rx, ry);
if (++x >= (data->xy_switch ? data->ysize : data->xsize)) {
x = 0;
y++;
}
}
return 0;
}
static int mxt_read_diagnostic_debug(struct mxt_data *data, u8 mode,
u16 *outbuf)
{
struct mxt_dbg *dbg = &data->dbg;
int retries = 0;
int page;
int ret;
u8 cmd = mode;
struct t37_debug *p;
u8 cmd_poll;
for (page = 0; page < dbg->t37_pages; page++) {
p = dbg->t37_buf + page;
ret = mxt_write_reg(data->client, dbg->diag_cmd_address,
cmd);
if (ret)
return ret;
retries = 0;
msleep(20);
wait_cmd:
ret = __mxt_read_reg(data->client, dbg->diag_cmd_address,
sizeof(cmd_poll), &cmd_poll);
if (ret)
return ret;
if (cmd_poll) {
if (retries++ > 100)
return -EINVAL;
msleep(20);
goto wait_cmd;
}
ret = __mxt_read_reg(data->client, dbg->t37_address,
sizeof(struct t37_debug), p);
if (ret)
return ret;
if (p->mode != mode || p->page != page) {
dev_err(&data->client->dev, "T37 page mismatch\n");
return -EINVAL;
}
dev_dbg(&data->client->dev, "%s page:%d retries:%d\n",
__func__, page, retries);
cmd = MXT_DIAGNOSTIC_PAGEUP;
}
return mxt_convert_debug_pages(data, outbuf);
}
static int mxt_queue_setup(struct vb2_queue *q,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct mxt_data *data = q->drv_priv;
size_t size = data->dbg.t37_nodes * sizeof(u16);
if (*nplanes)
return sizes[0] < size ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = size;
return 0;
}
static void mxt_buffer_queue(struct vb2_buffer *vb)
{
struct mxt_data *data = vb2_get_drv_priv(vb->vb2_queue);
u16 *ptr;
int ret;
u8 mode;
ptr = vb2_plane_vaddr(vb, 0);
if (!ptr) {
dev_err(&data->client->dev, "Error acquiring frame ptr\n");
goto fault;
}
switch (data->dbg.input) {
case MXT_V4L_INPUT_DELTAS:
default:
mode = MXT_DIAGNOSTIC_DELTAS;
break;
case MXT_V4L_INPUT_REFS:
mode = MXT_DIAGNOSTIC_REFS;
break;
}
ret = mxt_read_diagnostic_debug(data, mode, ptr);
if (ret)
goto fault;
vb2_set_plane_payload(vb, 0, data->dbg.t37_nodes * sizeof(u16));
vb2_buffer_done(vb, VB2_BUF_STATE_DONE);
return;
fault:
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
static int mxt_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct mxt_data *data = video_drvdata(file);
strlcpy(cap->driver, "atmel_mxt_ts", sizeof(cap->driver));
strlcpy(cap->card, "atmel_mxt_ts touch", sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info),
"I2C:%s", dev_name(&data->client->dev));
return 0;
}
static int mxt_vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index >= MXT_V4L_INPUT_MAX)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_TOUCH;
switch (i->index) {
case MXT_V4L_INPUT_REFS:
strlcpy(i->name, "Mutual Capacitance References",
sizeof(i->name));
break;
case MXT_V4L_INPUT_DELTAS:
strlcpy(i->name, "Mutual Capacitance Deltas", sizeof(i->name));
break;
}
return 0;
}
static int mxt_set_input(struct mxt_data *data, unsigned int i)
{
struct v4l2_pix_format *f = &data->dbg.format;
if (i >= MXT_V4L_INPUT_MAX)
return -EINVAL;
if (i == MXT_V4L_INPUT_DELTAS)
f->pixelformat = V4L2_TCH_FMT_DELTA_TD16;
else
f->pixelformat = V4L2_TCH_FMT_TU16;
f->width = data->xy_switch ? data->ysize : data->xsize;
f->height = data->xy_switch ? data->xsize : data->ysize;
f->field = V4L2_FIELD_NONE;
f->colorspace = V4L2_COLORSPACE_RAW;
f->bytesperline = f->width * sizeof(u16);
f->sizeimage = f->width * f->height * sizeof(u16);
data->dbg.input = i;
return 0;
}
static int mxt_vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return mxt_set_input(video_drvdata(file), i);
}
static int mxt_vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct mxt_data *data = video_drvdata(file);
*i = data->dbg.input;
return 0;
}
static int mxt_vidioc_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct mxt_data *data = video_drvdata(file);
f->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
f->fmt.pix = data->dbg.format;
return 0;
}
static int mxt_vidioc_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
if (fmt->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
switch (fmt->index) {
case 0:
fmt->pixelformat = V4L2_TCH_FMT_TU16;
break;
case 1:
fmt->pixelformat = V4L2_TCH_FMT_DELTA_TD16;
break;
default:
return -EINVAL;
}
return 0;
}
static int mxt_vidioc_g_parm(struct file *file, void *fh,
struct v4l2_streamparm *a)
{
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
a->parm.capture.readbuffers = 1;
a->parm.capture.timeperframe.numerator = 1;
a->parm.capture.timeperframe.denominator = 10;
return 0;
}
static void mxt_debug_init(struct mxt_data *data)
{
struct mxt_info *info = &data->info;
struct mxt_dbg *dbg = &data->dbg;
struct mxt_object *object;
int error;
object = mxt_get_object(data, MXT_GEN_COMMAND_T6);
if (!object)
goto error;
dbg->diag_cmd_address = object->start_address + MXT_COMMAND_DIAGNOSTIC;
object = mxt_get_object(data, MXT_DEBUG_DIAGNOSTIC_T37);
if (!object)
goto error;
if (mxt_obj_size(object) != sizeof(struct t37_debug)) {
dev_warn(&data->client->dev, "Bad T37 size");
goto error;
}
dbg->t37_address = object->start_address;
dbg->t37_nodes = data->xsize * data->ysize;
if (info->family_id == MXT_FAMILY_1386)
dbg->t37_pages = MXT1386_COLUMNS * MXT1386_PAGES_PER_COLUMN;
else
dbg->t37_pages = DIV_ROUND_UP(data->xsize *
info->matrix_ysize *
sizeof(u16),
sizeof(dbg->t37_buf->data));
dbg->t37_buf = devm_kmalloc_array(&data->client->dev, dbg->t37_pages,
sizeof(struct t37_debug), GFP_KERNEL);
if (!dbg->t37_buf)
goto error;
mxt_set_input(data, 0);
snprintf(dbg->v4l2.name, sizeof(dbg->v4l2.name), "%s", "atmel_mxt_ts");
error = v4l2_device_register(&data->client->dev, &dbg->v4l2);
if (error)
goto error;
mutex_init(&dbg->lock);
dbg->queue = mxt_queue;
dbg->queue.drv_priv = data;
dbg->queue.lock = &dbg->lock;
dbg->queue.dev = &data->client->dev;
error = vb2_queue_init(&dbg->queue);
if (error)
goto error_unreg_v4l2;
dbg->vdev = mxt_video_device;
dbg->vdev.v4l2_dev = &dbg->v4l2;
dbg->vdev.lock = &dbg->lock;
dbg->vdev.vfl_dir = VFL_DIR_RX;
dbg->vdev.queue = &dbg->queue;
video_set_drvdata(&dbg->vdev, data);
error = video_register_device(&dbg->vdev, VFL_TYPE_TOUCH, -1);
if (error)
goto error_unreg_v4l2;
return;
error_unreg_v4l2:
v4l2_device_unregister(&dbg->v4l2);
error:
dev_warn(&data->client->dev, "Error initializing T37\n");
}
static void mxt_debug_init(struct mxt_data *data)
{
}
static int mxt_configure_objects(struct mxt_data *data,
const struct firmware *cfg)
{
struct device *dev = &data->client->dev;
struct mxt_info *info = &data->info;
int error;
error = mxt_init_t7_power_cfg(data);
if (error) {
dev_err(dev, "Failed to initialize power cfg\n");
return error;
}
if (cfg) {
error = mxt_update_cfg(data, cfg);
if (error)
dev_warn(dev, "Error %d updating config\n", error);
}
if (data->multitouch) {
error = mxt_initialize_input_device(data);
if (error)
return error;
} else {
dev_warn(dev, "No touch object detected\n");
}
mxt_debug_init(data);
dev_info(dev,
"Family: %u Variant: %u Firmware V%u.%u.%02X Objects: %u\n",
info->family_id, info->variant_id, info->version >> 4,
info->version & 0xf, info->build, info->object_num);
return 0;
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
if (!data->in_bootloader) {
data->in_bootloader = true;
ret = mxt_t6_command(data, MXT_COMMAND_RESET,
MXT_BOOT_VALUE, false);
if (ret)
goto release_firmware;
msleep(MXT_RESET_TIME);
ret = mxt_lookup_bootloader_address(data, 0);
if (ret)
goto release_firmware;
mxt_free_input_device(data);
mxt_free_object_table(data);
} else {
enable_irq(data->irq);
}
reinit_completion(&data->bl_completion);
ret = mxt_check_bootloader(data, MXT_WAITING_BOOTLOAD_CMD, false);
if (ret) {
ret = mxt_check_bootloader(data, MXT_WAITING_FRAME_DATA, false);
if (ret)
goto disable_irq;
} else {
dev_info(dev, "Unlocking bootloader\n");
ret = mxt_send_bootloader_cmd(data, true);
if (ret)
goto disable_irq;
}
while (pos < fw->size) {
ret = mxt_check_bootloader(data, MXT_WAITING_FRAME_DATA, true);
if (ret)
goto disable_irq;
frame_size = ((*(fw->data + pos) << 8) | *(fw->data + pos + 1));
frame_size += 2;
ret = mxt_bootloader_write(data, fw->data + pos, frame_size);
if (ret)
goto disable_irq;
ret = mxt_check_bootloader(data, MXT_FRAME_CRC_PASS, true);
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
error = mxt_initialize(data);
if (error)
return error;
}
return count;
}
static void mxt_start(struct mxt_data *data)
{
switch (data->pdata->suspend_mode) {
case MXT_SUSPEND_T9_CTRL:
mxt_soft_reset(data);
mxt_write_object(data,
MXT_TOUCH_MULTI_T9, MXT_T9_CTRL, 0x83);
break;
case MXT_SUSPEND_DEEP_SLEEP:
default:
mxt_set_t7_power_cfg(data, MXT_POWER_CFG_RUN);
mxt_t6_command(data, MXT_COMMAND_CALIBRATE, 1, false);
break;
}
}
static void mxt_stop(struct mxt_data *data)
{
switch (data->pdata->suspend_mode) {
case MXT_SUSPEND_T9_CTRL:
mxt_write_object(data,
MXT_TOUCH_MULTI_T9, MXT_T9_CTRL, 0);
break;
case MXT_SUSPEND_DEEP_SLEEP:
default:
mxt_set_t7_power_cfg(data, MXT_POWER_CFG_DEEPSLEEP);
break;
}
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
static const struct mxt_platform_data *mxt_parse_dt(struct i2c_client *client)
{
struct mxt_platform_data *pdata;
struct device_node *np = client->dev.of_node;
u32 *keymap;
int proplen, ret;
if (!np)
return ERR_PTR(-ENOENT);
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
if (of_find_property(np, "linux,gpio-keymap", &proplen)) {
pdata->t19_num_keys = proplen / sizeof(u32);
keymap = devm_kzalloc(&client->dev,
pdata->t19_num_keys * sizeof(keymap[0]),
GFP_KERNEL);
if (!keymap)
return ERR_PTR(-ENOMEM);
ret = of_property_read_u32_array(np, "linux,gpio-keymap",
keymap, pdata->t19_num_keys);
if (ret)
dev_warn(&client->dev,
"Couldn't read linux,gpio-keymap: %d\n", ret);
pdata->t19_keymap = keymap;
}
pdata->suspend_mode = MXT_SUSPEND_DEEP_SLEEP;
return pdata;
}
static const struct mxt_platform_data *mxt_parse_dt(struct i2c_client *client)
{
return ERR_PTR(-ENOENT);
}
static const struct mxt_platform_data *mxt_parse_acpi(struct i2c_client *client)
{
struct acpi_device *adev;
const struct dmi_system_id *system_id;
const struct mxt_acpi_platform_data *acpi_pdata;
if (client->addr < 0x40)
return ERR_PTR(-ENXIO);
adev = ACPI_COMPANION(&client->dev);
if (!adev)
return ERR_PTR(-ENOENT);
system_id = dmi_first_match(mxt_dmi_table);
if (!system_id)
return ERR_PTR(-ENOENT);
acpi_pdata = system_id->driver_data;
if (!acpi_pdata)
return ERR_PTR(-ENOENT);
while (acpi_pdata->hid) {
if (!strcmp(acpi_device_hid(adev), acpi_pdata->hid))
return &acpi_pdata->pdata;
acpi_pdata++;
}
return ERR_PTR(-ENOENT);
}
static const struct mxt_platform_data *mxt_parse_acpi(struct i2c_client *client)
{
return ERR_PTR(-ENOENT);
}
static const struct mxt_platform_data *
mxt_get_platform_data(struct i2c_client *client)
{
const struct mxt_platform_data *pdata;
pdata = dev_get_platdata(&client->dev);
if (pdata)
return pdata;
pdata = mxt_parse_dt(client);
if (!IS_ERR(pdata) || PTR_ERR(pdata) != -ENOENT)
return pdata;
pdata = mxt_parse_acpi(client);
if (!IS_ERR(pdata) || PTR_ERR(pdata) != -ENOENT)
return pdata;
dev_err(&client->dev, "No platform data specified\n");
return ERR_PTR(-EINVAL);
}
static int mxt_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct mxt_data *data;
const struct mxt_platform_data *pdata;
int error;
pdata = mxt_get_platform_data(client);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
data = devm_kzalloc(&client->dev, sizeof(struct mxt_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
snprintf(data->phys, sizeof(data->phys), "i2c-%u-%04x/input0",
client->adapter->nr, client->addr);
data->client = client;
data->pdata = pdata;
data->irq = client->irq;
i2c_set_clientdata(client, data);
init_completion(&data->bl_completion);
init_completion(&data->reset_completion);
init_completion(&data->crc_completion);
data->reset_gpio = devm_gpiod_get_optional(&client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(data->reset_gpio)) {
error = PTR_ERR(data->reset_gpio);
dev_err(&client->dev, "Failed to get reset gpio: %d\n", error);
return error;
}
error = devm_request_threaded_irq(&client->dev, client->irq,
NULL, mxt_interrupt,
pdata->irqflags | IRQF_ONESHOT,
client->name, data);
if (error) {
dev_err(&client->dev, "Failed to register interrupt\n");
return error;
}
if (data->reset_gpio) {
data->in_bootloader = true;
msleep(MXT_RESET_TIME);
reinit_completion(&data->bl_completion);
gpiod_set_value(data->reset_gpio, 1);
error = mxt_wait_for_completion(data, &data->bl_completion,
MXT_RESET_TIMEOUT);
if (error)
return error;
data->in_bootloader = false;
}
disable_irq(client->irq);
error = mxt_initialize(data);
if (error)
return error;
error = sysfs_create_group(&client->dev.kobj, &mxt_attr_group);
if (error) {
dev_err(&client->dev, "Failure %d creating sysfs group\n",
error);
goto err_free_object;
}
return 0;
err_free_object:
mxt_free_input_device(data);
mxt_free_object_table(data);
return error;
}
static int mxt_remove(struct i2c_client *client)
{
struct mxt_data *data = i2c_get_clientdata(client);
disable_irq(data->irq);
sysfs_remove_group(&client->dev.kobj, &mxt_attr_group);
mxt_free_input_device(data);
mxt_free_object_table(data);
return 0;
}
static int __maybe_unused mxt_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mxt_data *data = i2c_get_clientdata(client);
struct input_dev *input_dev = data->input_dev;
if (!input_dev)
return 0;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
mxt_stop(data);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int __maybe_unused mxt_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct mxt_data *data = i2c_get_clientdata(client);
struct input_dev *input_dev = data->input_dev;
if (!input_dev)
return 0;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
mxt_start(data);
mutex_unlock(&input_dev->mutex);
return 0;
}
