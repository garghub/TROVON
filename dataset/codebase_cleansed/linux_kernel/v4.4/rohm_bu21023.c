static int rohm_i2c_burst_read(struct i2c_client *client, u8 start, void *buf,
size_t len)
{
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg[2];
int i, ret = 0;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = 1;
msg[0].buf = &start;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = len;
msg[1].buf = buf;
i2c_lock_adapter(adap);
for (i = 0; i < 2; i++) {
if (__i2c_transfer(adap, &msg[i], 1) < 0) {
ret = -EIO;
break;
}
}
i2c_unlock_adapter(adap);
return ret;
}
static int rohm_ts_manual_calibration(struct rohm_ts_data *ts)
{
struct i2c_client *client = ts->client;
struct device *dev = &client->dev;
u8 buf[33];
int retry;
bool success = false;
bool first_time = true;
bool calibration_done;
u8 reg1, reg2, reg3;
s32 reg1_orig, reg2_orig, reg3_orig;
s32 val;
int calib_x = 0, calib_y = 0;
int reg_x, reg_y;
int err_x, err_y;
int error, error2;
int i;
reg1_orig = i2c_smbus_read_byte_data(client, CALIBRATION_REG1);
if (reg1_orig < 0)
return reg1_orig;
reg2_orig = i2c_smbus_read_byte_data(client, CALIBRATION_REG2);
if (reg2_orig < 0)
return reg2_orig;
reg3_orig = i2c_smbus_read_byte_data(client, CALIBRATION_REG3);
if (reg3_orig < 0)
return reg3_orig;
error = i2c_smbus_write_byte_data(client, INT_MASK,
COORD_UPDATE | SLEEP_IN | SLEEP_OUT |
PROGRAM_LOAD_DONE);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, TEST1,
DUALTOUCH_STABILIZE_ON);
if (error)
goto out;
for (retry = 0; retry < CALIBRATION_RETRY_MAX; retry++) {
mdelay(2 * SAMPLING_DELAY);
#define READ_CALIB_BUF(reg) buf[((reg) - PRM1_X_H)]
error = rohm_i2c_burst_read(client, PRM1_X_H, buf, sizeof(buf));
if (error)
goto out;
if (READ_CALIB_BUF(TOUCH) & TOUCH_DETECT)
continue;
if (first_time) {
calib_x = ((int)READ_CALIB_BUF(PRM1_X_H) << 2 |
READ_CALIB_BUF(PRM1_X_L)) - AXIS_OFFSET;
calib_y = ((int)READ_CALIB_BUF(PRM1_Y_H) << 2 |
READ_CALIB_BUF(PRM1_Y_L)) - AXIS_OFFSET;
error = i2c_smbus_write_byte_data(client, TEST1,
DUALTOUCH_STABILIZE_ON | DUALTOUCH_REG_ON);
if (error)
goto out;
first_time = false;
} else {
err_x = (int)READ_CALIB_BUF(PRM1_X_H) << 2 |
READ_CALIB_BUF(PRM1_X_L);
err_y = (int)READ_CALIB_BUF(PRM1_Y_H) << 2 |
READ_CALIB_BUF(PRM1_Y_L);
if (err_x <= 4)
calib_x -= AXIS_ADJUST;
else if (err_x >= 60)
calib_x += AXIS_ADJUST;
if (err_y <= 4)
calib_y -= AXIS_ADJUST;
else if (err_y >= 60)
calib_y += AXIS_ADJUST;
}
reg_x = calib_x + ((calib_x & 0x200) << 1);
reg_y = calib_y + ((calib_y & 0x200) << 1);
reg1 = reg_x >> 3;
reg2 = (reg_y & 0x7) << 4 | (reg_x & 0x7);
reg3 = reg_y >> 3;
error = i2c_smbus_write_byte_data(client,
CALIBRATION_REG1, reg1);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client,
CALIBRATION_REG2, reg2);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client,
CALIBRATION_REG3, reg3);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, FORCE_CALIBRATION,
FORCE_CALIBRATION_OFF);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, FORCE_CALIBRATION,
FORCE_CALIBRATION_ON);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
if (error)
goto out;
calibration_done = false;
for (i = 0; i < 10; i++) {
mdelay(SAMPLING_DELAY);
val = i2c_smbus_read_byte_data(client, TOUCH_GESTURE);
if (!(val & CALIBRATION_MASK)) {
calibration_done = true;
break;
} else if (val < 0) {
error = val;
goto out;
}
}
if (calibration_done) {
val = i2c_smbus_read_byte_data(client, INT_STATUS);
if (val == CALIBRATION_DONE) {
success = true;
break;
} else if (val < 0) {
error = val;
goto out;
}
} else {
dev_warn(dev, "calibration timeout\n");
}
}
if (!success) {
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG1,
reg1_orig);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG2,
reg2_orig);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG3,
reg3_orig);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, TEST1,
DUALTOUCH_STABILIZE_ON |
DUALTOUCH_REG_ON);
if (error)
goto out;
mdelay(10 * SAMPLING_DELAY);
error = -EBUSY;
}
out:
error2 = i2c_smbus_write_byte_data(client, INT_MASK, INT_ALL);
if (!error2)
error2 = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
return error ? error : error2;
}
static irqreturn_t rohm_ts_soft_irq(int irq, void *dev_id)
{
struct rohm_ts_data *ts = dev_id;
struct i2c_client *client = ts->client;
struct input_dev *input_dev = ts->input;
struct device *dev = &client->dev;
u8 buf[10];
struct input_mt_pos pos[MAX_CONTACTS];
int slots[MAX_CONTACTS];
u8 touch_flags;
unsigned int threshold;
int finger_count = -1;
int prev_finger_count = ts->finger_count;
int count;
int error;
int i;
error = i2c_smbus_write_byte_data(client, INT_MASK, INT_ALL);
if (error)
return IRQ_HANDLED;
error = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
if (error)
return IRQ_HANDLED;
#define READ_POS_BUF(reg) buf[((reg) - POS_X1_H)]
error = rohm_i2c_burst_read(client, POS_X1_H, buf, sizeof(buf));
if (error)
return IRQ_HANDLED;
touch_flags = READ_POS_BUF(TOUCH_GESTURE) & TOUCH_MASK;
if (touch_flags) {
pos[0].x = ((s16)READ_POS_BUF(POS_X1_H) << 2) |
READ_POS_BUF(POS_X1_L);
pos[0].y = ((s16)READ_POS_BUF(POS_Y1_H) << 2) |
READ_POS_BUF(POS_Y1_L);
pos[1].x = ((s16)READ_POS_BUF(POS_X2_H) << 2) |
READ_POS_BUF(POS_X2_L);
pos[1].y = ((s16)READ_POS_BUF(POS_Y2_H) << 2) |
READ_POS_BUF(POS_Y2_L);
}
switch (touch_flags) {
case 0:
threshold = untouch_threshold[prev_finger_count];
if (++ts->contact_count[0] >= threshold)
finger_count = 0;
break;
case SINGLE_TOUCH:
threshold = single_touch_threshold[prev_finger_count];
if (++ts->contact_count[1] >= threshold)
finger_count = 1;
if (finger_count == 1) {
if (pos[1].x != 0 && pos[1].y != 0) {
pos[0].x = pos[1].x;
pos[0].y = pos[1].y;
pos[1].x = 0;
pos[1].y = 0;
}
}
break;
case DUAL_TOUCH:
threshold = dual_touch_threshold[prev_finger_count];
if (++ts->contact_count[2] >= threshold)
finger_count = 2;
break;
default:
dev_dbg(dev,
"Three or more touches are not supported\n");
return IRQ_HANDLED;
}
if (finger_count >= 0) {
if (prev_finger_count != finger_count) {
count = ts->contact_count[finger_count];
memset(ts->contact_count, 0, sizeof(ts->contact_count));
ts->contact_count[finger_count] = count;
}
input_mt_assign_slots(input_dev, slots, pos,
finger_count, ROHM_TS_DISPLACEMENT_MAX);
for (i = 0; i < finger_count; i++) {
input_mt_slot(input_dev, slots[i]);
input_mt_report_slot_state(input_dev,
MT_TOOL_FINGER, true);
input_report_abs(input_dev,
ABS_MT_POSITION_X, pos[i].x);
input_report_abs(input_dev,
ABS_MT_POSITION_Y, pos[i].y);
}
input_mt_sync_frame(input_dev);
input_mt_report_pointer_emulation(input_dev, true);
input_sync(input_dev);
ts->finger_count = finger_count;
}
if (READ_POS_BUF(TOUCH_GESTURE) & CALIBRATION_REQUEST) {
error = rohm_ts_manual_calibration(ts);
if (error)
dev_warn(dev, "manual calibration failed: %d\n",
error);
}
i2c_smbus_write_byte_data(client, INT_MASK,
CALIBRATION_DONE | SLEEP_OUT | SLEEP_IN |
PROGRAM_LOAD_DONE);
return IRQ_HANDLED;
}
static int rohm_ts_load_firmware(struct i2c_client *client,
const char *firmware_name)
{
struct device *dev = &client->dev;
const struct firmware *fw;
s32 status;
unsigned int offset, len, xfer_len;
unsigned int retry = 0;
int error, error2;
error = request_firmware(&fw, firmware_name, dev);
if (error) {
dev_err(dev, "unable to retrieve firmware %s: %d\n",
firmware_name, error);
return error;
}
error = i2c_smbus_write_byte_data(client, INT_MASK,
COORD_UPDATE | CALIBRATION_DONE |
SLEEP_IN | SLEEP_OUT);
if (error)
goto out;
do {
if (retry) {
dev_warn(dev, "retrying firmware load\n");
error = i2c_smbus_write_byte_data(client, EX_WDAT, 0);
if (error)
goto out;
}
error = i2c_smbus_write_byte_data(client, EX_ADDR_H, 0);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, EX_ADDR_L, 0);
if (error)
goto out;
error = i2c_smbus_write_byte_data(client, COMMON_SETUP1,
COMMON_SETUP1_DEFAULT);
if (error)
goto out;
offset = 0;
len = fw->size;
while (len) {
xfer_len = min(FIRMWARE_BLOCK_SIZE, len);
error = i2c_smbus_write_i2c_block_data(client, EX_WDAT,
xfer_len, &fw->data[offset]);
if (error)
goto out;
len -= xfer_len;
offset += xfer_len;
}
status = i2c_smbus_read_byte_data(client, INT_STATUS);
if (status < 0) {
error = status;
goto out;
}
error = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
if (error)
goto out;
if (status == PROGRAM_LOAD_DONE)
break;
error = -EIO;
} while (++retry >= FIRMWARE_RETRY_MAX);
out:
error2 = i2c_smbus_write_byte_data(client, INT_MASK, INT_ALL);
release_firmware(fw);
return error ? error : error2;
}
static ssize_t swap_xy_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
return sprintf(buf, "%d\n", !!(ts->setup2 & SWAP_XY));
}
static ssize_t swap_xy_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
unsigned int val;
int error;
error = kstrtouint(buf, 0, &val);
if (error)
return error;
error = mutex_lock_interruptible(&ts->input->mutex);
if (error)
return error;
if (val)
ts->setup2 |= SWAP_XY;
else
ts->setup2 &= ~SWAP_XY;
if (ts->initialized)
error = i2c_smbus_write_byte_data(ts->client, COMMON_SETUP2,
ts->setup2);
mutex_unlock(&ts->input->mutex);
return error ? error : count;
}
static ssize_t inv_x_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
return sprintf(buf, "%d\n", !!(ts->setup2 & INV_X));
}
static ssize_t inv_x_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
unsigned int val;
int error;
error = kstrtouint(buf, 0, &val);
if (error)
return error;
error = mutex_lock_interruptible(&ts->input->mutex);
if (error)
return error;
if (val)
ts->setup2 |= INV_X;
else
ts->setup2 &= ~INV_X;
if (ts->initialized)
error = i2c_smbus_write_byte_data(ts->client, COMMON_SETUP2,
ts->setup2);
mutex_unlock(&ts->input->mutex);
return error ? error : count;
}
static ssize_t inv_y_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
return sprintf(buf, "%d\n", !!(ts->setup2 & INV_Y));
}
static ssize_t inv_y_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct rohm_ts_data *ts = i2c_get_clientdata(client);
unsigned int val;
int error;
error = kstrtouint(buf, 0, &val);
if (error)
return error;
error = mutex_lock_interruptible(&ts->input->mutex);
if (error)
return error;
if (val)
ts->setup2 |= INV_Y;
else
ts->setup2 &= ~INV_Y;
if (ts->initialized)
error = i2c_smbus_write_byte_data(client, COMMON_SETUP2,
ts->setup2);
mutex_unlock(&ts->input->mutex);
return error ? error : count;
}
static int rohm_ts_device_init(struct i2c_client *client, u8 setup2)
{
struct device *dev = &client->dev;
int error;
disable_irq(client->irq);
udelay(200);
error = i2c_smbus_write_byte_data(client, SYSTEM,
ANALOG_POWER_ON | CPU_POWER_OFF);
if (error)
return error;
udelay(200);
error = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, EX_WDAT, 0);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, COMMON_SETUP1, 0);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, COMMON_SETUP2, setup2);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, COMMON_SETUP3,
SEL_TBL_DEFAULT | EN_MULTI);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, THRESHOLD_GESTURE,
THRESHOLD_GESTURE_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, INTERVAL_TIME,
INTERVAL_TIME_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, CPU_FREQ, CPU_FREQ_10MHZ);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, PRM_SWOFF_TIME,
PRM_SWOFF_TIME_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, ADC_CTRL, ADC_DIV_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, ADC_WAIT, ADC_WAIT_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, STEP_X, STEP_X_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, STEP_Y, STEP_Y_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, OFFSET_X, OFFSET_X_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, OFFSET_Y, OFFSET_Y_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, THRESHOLD_TOUCH,
THRESHOLD_TOUCH_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, EVR_XY, EVR_XY_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, EVR_X, EVR_X_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, EVR_Y, EVR_Y_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, CALIBRATION_ADJUST,
CALIBRATION_ADJUST_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, SWCONT, SWCONT_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, TEST1,
DUALTOUCH_STABILIZE_ON |
DUALTOUCH_REG_ON);
if (error)
return error;
error = rohm_ts_load_firmware(client, BU21023_FIRMWARE_NAME);
if (error) {
dev_err(dev, "failed to load firmware: %d\n", error);
return error;
}
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG1,
CALIBRATION_REG1_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG2,
CALIBRATION_REG2_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, CALIBRATION_REG3,
CALIBRATION_REG3_DEFAULT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, FORCE_CALIBRATION,
FORCE_CALIBRATION_OFF);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, FORCE_CALIBRATION,
FORCE_CALIBRATION_ON);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, INT_CLEAR, 0xff);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, INT_MASK,
CALIBRATION_DONE | SLEEP_OUT |
SLEEP_IN | PROGRAM_LOAD_DONE);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, ERR_MASK,
PROGRAM_LOAD_ERR | CPU_TIMEOUT |
ADC_TIMEOUT);
if (error)
return error;
error = i2c_smbus_write_byte_data(client, SYSTEM,
ANALOG_POWER_ON | CPU_POWER_ON);
enable_irq(client->irq);
return error;
}
static int rohm_ts_power_off(struct i2c_client *client)
{
int error;
error = i2c_smbus_write_byte_data(client, SYSTEM,
ANALOG_POWER_ON | CPU_POWER_OFF);
if (error) {
dev_err(&client->dev,
"failed to power off device CPU: %d\n", error);
return error;
}
error = i2c_smbus_write_byte_data(client, SYSTEM,
ANALOG_POWER_OFF | CPU_POWER_OFF);
if (error)
dev_err(&client->dev,
"failed to power off the device: %d\n", error);
return error;
}
static int rohm_ts_open(struct input_dev *input_dev)
{
struct rohm_ts_data *ts = input_get_drvdata(input_dev);
struct i2c_client *client = ts->client;
int error;
if (!ts->initialized) {
error = rohm_ts_device_init(client, ts->setup2);
if (error) {
dev_err(&client->dev,
"device initialization failed: %d\n", error);
return error;
}
ts->initialized = true;
}
return 0;
}
static void rohm_ts_close(struct input_dev *input_dev)
{
struct rohm_ts_data *ts = input_get_drvdata(input_dev);
rohm_ts_power_off(ts->client);
ts->initialized = false;
}
static void rohm_ts_remove_sysfs_group(void *_dev)
{
struct device *dev = _dev;
sysfs_remove_group(&dev->kobj, &rohm_ts_attr_group);
}
static int rohm_bu21023_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct rohm_ts_data *ts;
struct input_dev *input;
int error;
if (!client->irq) {
dev_err(dev, "IRQ is not assigned\n");
return -EINVAL;
}
if (!client->adapter->algo->master_xfer) {
dev_err(dev, "I2C level transfers not supported\n");
return -EOPNOTSUPP;
}
error = rohm_ts_power_off(client);
if (error)
return error;
ts = devm_kzalloc(dev, sizeof(struct rohm_ts_data), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->client = client;
ts->setup2 = MAF_1SAMPLE;
i2c_set_clientdata(client, ts);
input = devm_input_allocate_device(dev);
if (!input)
return -ENOMEM;
input->name = BU21023_NAME;
input->id.bustype = BUS_I2C;
input->open = rohm_ts_open;
input->close = rohm_ts_close;
ts->input = input;
input_set_drvdata(input, ts);
input_set_abs_params(input, ABS_MT_POSITION_X,
ROHM_TS_ABS_X_MIN, ROHM_TS_ABS_X_MAX, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y,
ROHM_TS_ABS_Y_MIN, ROHM_TS_ABS_Y_MAX, 0, 0);
error = input_mt_init_slots(input, MAX_CONTACTS,
INPUT_MT_DIRECT | INPUT_MT_TRACK |
INPUT_MT_DROP_UNUSED);
if (error) {
dev_err(dev, "failed to multi touch slots initialization\n");
return error;
}
error = devm_request_threaded_irq(dev, client->irq,
NULL, rohm_ts_soft_irq,
IRQF_ONESHOT, client->name, ts);
if (error) {
dev_err(dev, "failed to request IRQ: %d\n", error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "failed to register input device: %d\n", error);
return error;
}
error = sysfs_create_group(&dev->kobj, &rohm_ts_attr_group);
if (error) {
dev_err(dev, "failed to create sysfs group: %d\n", error);
return error;
}
error = devm_add_action(dev, rohm_ts_remove_sysfs_group, dev);
if (error) {
rohm_ts_remove_sysfs_group(dev);
dev_err(&client->dev,
"Failed to add sysfs cleanup action: %d\n",
error);
return error;
}
return error;
}
