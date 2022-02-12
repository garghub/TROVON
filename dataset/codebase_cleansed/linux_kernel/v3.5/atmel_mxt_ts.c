static bool mxt_object_readable(unsigned int type)
{
switch (type) {
case MXT_GEN_MESSAGE_T5:
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
dev_dbg(dev, "reportid: %u\tmessage: %02x %02x %02x %02x %02x %02x %02x\n",
message->reportid, message->message[0], message->message[1],
message->message[2], message->message[3], message->message[4],
message->message[5], message->message[6]);
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
if (i2c_transfer(client->adapter, xfer, 2) != 2) {
dev_err(&client->dev, "%s: i2c transfer failed\n", __func__);
return -EIO;
}
return 0;
}
static int mxt_read_reg(struct i2c_client *client, u16 reg, u8 *val)
{
return __mxt_read_reg(client, reg, 1, val);
}
static int mxt_write_reg(struct i2c_client *client, u16 reg, u8 val)
{
u8 buf[3];
buf[0] = reg & 0xff;
buf[1] = (reg >> 8) & 0xff;
buf[2] = val;
if (i2c_master_send(client, buf, 3) != 3) {
dev_err(&client->dev, "%s: i2c send failed\n", __func__);
return -EIO;
}
return 0;
}
static int mxt_read_object_table(struct i2c_client *client,
u16 reg, u8 *object_buf)
{
return __mxt_read_reg(client, reg, MXT_OBJECT_SIZE,
object_buf);
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
static int mxt_read_object(struct mxt_data *data,
u8 type, u8 offset, u8 *val)
{
struct mxt_object *object;
u16 reg;
object = mxt_get_object(data, type);
if (!object)
return -EINVAL;
reg = object->start_address;
return __mxt_read_reg(data->client, reg + offset, 1, val);
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
static void mxt_input_report(struct mxt_data *data, int single_id)
{
struct mxt_finger *finger = data->finger;
struct input_dev *input_dev = data->input_dev;
int status = finger[single_id].status;
int finger_num = 0;
int id;
for (id = 0; id < MXT_MAX_FINGER; id++) {
if (!finger[id].status)
continue;
input_mt_slot(input_dev, id);
input_mt_report_slot_state(input_dev, MT_TOOL_FINGER,
finger[id].status != MXT_RELEASE);
if (finger[id].status != MXT_RELEASE) {
finger_num++;
input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR,
finger[id].area);
input_report_abs(input_dev, ABS_MT_POSITION_X,
finger[id].x);
input_report_abs(input_dev, ABS_MT_POSITION_Y,
finger[id].y);
input_report_abs(input_dev, ABS_MT_PRESSURE,
finger[id].pressure);
} else {
finger[id].status = 0;
}
}
input_report_key(input_dev, BTN_TOUCH, finger_num > 0);
if (status != MXT_RELEASE) {
input_report_abs(input_dev, ABS_X, finger[single_id].x);
input_report_abs(input_dev, ABS_Y, finger[single_id].y);
input_report_abs(input_dev,
ABS_PRESSURE, finger[single_id].pressure);
}
input_sync(input_dev);
}
static void mxt_input_touchevent(struct mxt_data *data,
struct mxt_message *message, int id)
{
struct mxt_finger *finger = data->finger;
struct device *dev = &data->client->dev;
u8 status = message->message[0];
int x;
int y;
int area;
int pressure;
if (!(status & MXT_DETECT)) {
if (status & MXT_RELEASE) {
dev_dbg(dev, "[%d] released\n", id);
finger[id].status = MXT_RELEASE;
mxt_input_report(data, id);
}
return;
}
if (!(status & (MXT_PRESS | MXT_MOVE)))
return;
x = (message->message[1] << 4) | ((message->message[3] >> 4) & 0xf);
y = (message->message[2] << 4) | ((message->message[3] & 0xf));
if (data->max_x < 1024)
x = x >> 2;
if (data->max_y < 1024)
y = y >> 2;
area = message->message[4];
pressure = message->message[5];
dev_dbg(dev, "[%d] %s x: %d, y: %d, area: %d\n", id,
status & MXT_MOVE ? "moved" : "pressed",
x, y, area);
finger[id].status = status & MXT_MOVE ?
MXT_MOVE : MXT_PRESS;
finger[id].x = x;
finger[id].y = y;
finger[id].area = area;
finger[id].pressure = pressure;
mxt_input_report(data, id);
}
static irqreturn_t mxt_interrupt(int irq, void *dev_id)
{
struct mxt_data *data = dev_id;
struct mxt_message message;
struct mxt_object *object;
struct device *dev = &data->client->dev;
int id;
u8 reportid;
u8 max_reportid;
u8 min_reportid;
do {
if (mxt_read_message(data, &message)) {
dev_err(dev, "Failed to read message\n");
goto end;
}
reportid = message.reportid;
object = mxt_get_object(data, MXT_TOUCH_MULTI_T9);
if (!object)
goto end;
max_reportid = object->max_reportid;
min_reportid = max_reportid - object->num_report_ids + 1;
id = reportid - min_reportid;
if (reportid >= min_reportid && reportid <= max_reportid)
mxt_input_touchevent(data, &message, id);
else
mxt_dump_message(dev, &message);
} while (reportid != 0xff);
end:
return IRQ_HANDLED;
}
static int mxt_check_reg_init(struct mxt_data *data)
{
const struct mxt_platform_data *pdata = data->pdata;
struct mxt_object *object;
struct device *dev = &data->client->dev;
int index = 0;
int i, j, config_offset;
if (!pdata->config) {
dev_dbg(dev, "No cfg data defined, skipping reg init\n");
return 0;
}
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
if (!mxt_object_writable(object->type))
continue;
for (j = 0;
j < (object->size + 1) * (object->instances + 1);
j++) {
config_offset = index + j;
if (config_offset > pdata->config_length) {
dev_err(dev, "Not enough config data!\n");
return -EINVAL;
}
mxt_write_object(data, object->type, j,
pdata->config[config_offset]);
}
index += (object->size + 1) * (object->instances + 1);
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
u8 val;
error = mxt_read_reg(client, MXT_FAMILY_ID, &val);
if (error)
return error;
info->family_id = val;
error = mxt_read_reg(client, MXT_VARIANT_ID, &val);
if (error)
return error;
info->variant_id = val;
error = mxt_read_reg(client, MXT_VERSION, &val);
if (error)
return error;
info->version = val;
error = mxt_read_reg(client, MXT_BUILD, &val);
if (error)
return error;
info->build = val;
error = mxt_read_reg(client, MXT_OBJECT_NUM, &val);
if (error)
return error;
info->object_num = val;
return 0;
}
static int mxt_get_object_table(struct mxt_data *data)
{
int error;
int i;
u16 reg;
u8 reportid = 0;
u8 buf[MXT_OBJECT_SIZE];
for (i = 0; i < data->info.object_num; i++) {
struct mxt_object *object = data->object_table + i;
reg = MXT_OBJECT_START + MXT_OBJECT_SIZE * i;
error = mxt_read_object_table(data->client, reg, buf);
if (error)
return error;
object->type = buf[0];
object->start_address = (buf[2] << 8) | buf[1];
object->size = buf[3];
object->instances = buf[4];
object->num_report_ids = buf[5];
if (object->num_report_ids) {
reportid += object->num_report_ids *
(object->instances + 1);
object->max_reportid = reportid;
}
}
return 0;
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
return error;
error = mxt_check_reg_init(data);
if (error)
return error;
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
return error;
info->matrix_xsize = val;
error = mxt_read_reg(client, MXT_MATRIX_Y_SIZE, &val);
if (error)
return error;
info->matrix_ysize = val;
dev_info(&client->dev,
"Family ID: %d Variant ID: %d Version: %d Build: %d\n",
info->family_id, info->variant_id, info->version,
info->build);
dev_info(&client->dev,
"Matrix X Size: %d Matrix Y Size: %d Object Num: %d\n",
info->matrix_xsize, info->matrix_ysize,
info->object_num);
return 0;
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
static ssize_t mxt_object_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mxt_data *data = dev_get_drvdata(dev);
struct mxt_object *object;
int count = 0;
int i, j;
int error;
u8 val;
for (i = 0; i < data->info.object_num; i++) {
object = data->object_table + i;
count += snprintf(buf + count, PAGE_SIZE - count,
"Object[%d] (Type %d)\n",
i + 1, object->type);
if (count >= PAGE_SIZE)
return PAGE_SIZE - 1;
if (!mxt_object_readable(object->type)) {
count += snprintf(buf + count, PAGE_SIZE - count,
"\n");
if (count >= PAGE_SIZE)
return PAGE_SIZE - 1;
continue;
}
for (j = 0; j < object->size + 1; j++) {
error = mxt_read_object(data,
object->type, j, &val);
if (error)
return error;
count += snprintf(buf + count, PAGE_SIZE - count,
"\t[%2d]: %02x (%d)\n", j, val, val);
if (count >= PAGE_SIZE)
return PAGE_SIZE - 1;
}
count += snprintf(buf + count, PAGE_SIZE - count, "\n");
if (count >= PAGE_SIZE)
return PAGE_SIZE - 1;
}
return count;
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
kfree(data->object_table);
data->object_table = NULL;
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
static int __devinit mxt_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct mxt_platform_data *pdata = client->dev.platform_data;
struct mxt_data *data;
struct input_dev *input_dev;
int error;
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
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &client->dev;
input_dev->open = mxt_input_open;
input_dev->close = mxt_input_close;
data->client = client;
data->input_dev = input_dev;
data->pdata = pdata;
data->irq = client->irq;
mxt_calc_resolution(data);
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X,
0, data->max_x, 0, 0);
input_set_abs_params(input_dev, ABS_Y,
0, data->max_y, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, 255, 0, 0);
input_mt_init_slots(input_dev, MXT_MAX_FINGER);
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
error = mxt_initialize(data);
if (error)
goto err_free_object;
error = request_threaded_irq(client->irq, NULL, mxt_interrupt,
pdata->irqflags | IRQF_ONESHOT,
client->dev.driver->name, data);
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
static int __devexit mxt_remove(struct i2c_client *client)
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
