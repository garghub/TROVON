ssize_t cyapa_smbus_read_block(struct cyapa *cyapa, u8 cmd, size_t len,
u8 *values)
{
ssize_t ret;
u8 index;
u8 smbus_cmd;
u8 *buf;
struct i2c_client *client = cyapa->client;
if (!(SMBUS_BYTE_BLOCK_CMD_MASK & cmd))
return -EINVAL;
if (SMBUS_GROUP_BLOCK_CMD_MASK & cmd) {
smbus_cmd = SMBUS_ENCODE_RW(cmd, SMBUS_READ);
ret = i2c_smbus_read_block_data(client, smbus_cmd, values);
goto out;
}
ret = 0;
for (index = 0; index * I2C_SMBUS_BLOCK_MAX < len; index++) {
smbus_cmd = SMBUS_ENCODE_IDX(cmd, index);
smbus_cmd = SMBUS_ENCODE_RW(smbus_cmd, SMBUS_READ);
buf = values + I2C_SMBUS_BLOCK_MAX * index;
ret = i2c_smbus_read_block_data(client, smbus_cmd, buf);
if (ret < 0)
goto out;
}
out:
return ret > 0 ? len : ret;
}
static s32 cyapa_read_byte(struct cyapa *cyapa, u8 cmd_idx)
{
u8 cmd;
if (cyapa->smbus) {
cmd = cyapa_smbus_cmds[cmd_idx].cmd;
cmd = SMBUS_ENCODE_RW(cmd, SMBUS_READ);
} else {
cmd = cyapa_i2c_cmds[cmd_idx].cmd;
}
return i2c_smbus_read_byte_data(cyapa->client, cmd);
}
static s32 cyapa_write_byte(struct cyapa *cyapa, u8 cmd_idx, u8 value)
{
u8 cmd;
if (cyapa->smbus) {
cmd = cyapa_smbus_cmds[cmd_idx].cmd;
cmd = SMBUS_ENCODE_RW(cmd, SMBUS_WRITE);
} else {
cmd = cyapa_i2c_cmds[cmd_idx].cmd;
}
return i2c_smbus_write_byte_data(cyapa->client, cmd, value);
}
ssize_t cyapa_i2c_reg_read_block(struct cyapa *cyapa, u8 reg, size_t len,
u8 *values)
{
return i2c_smbus_read_i2c_block_data(cyapa->client, reg, len, values);
}
static ssize_t cyapa_i2c_reg_write_block(struct cyapa *cyapa, u8 reg,
size_t len, const u8 *values)
{
return i2c_smbus_write_i2c_block_data(cyapa->client, reg, len, values);
}
ssize_t cyapa_read_block(struct cyapa *cyapa, u8 cmd_idx, u8 *values)
{
u8 cmd;
size_t len;
if (cyapa->smbus) {
cmd = cyapa_smbus_cmds[cmd_idx].cmd;
len = cyapa_smbus_cmds[cmd_idx].len;
return cyapa_smbus_read_block(cyapa, cmd, len, values);
}
cmd = cyapa_i2c_cmds[cmd_idx].cmd;
len = cyapa_i2c_cmds[cmd_idx].len;
return cyapa_i2c_reg_read_block(cyapa, cmd, len, values);
}
static int cyapa_gen3_state_parse(struct cyapa *cyapa, u8 *reg_data, int len)
{
cyapa->state = CYAPA_STATE_NO_DEVICE;
if (reg_data[REG_BL_FILE] == BL_FILE &&
reg_data[REG_BL_ERROR] == BL_ERROR_NO_ERR_IDLE &&
(reg_data[REG_BL_STATUS] ==
(BL_STATUS_RUNNING | BL_STATUS_CSUM_VALID) ||
reg_data[REG_BL_STATUS] == BL_STATUS_RUNNING)) {
cyapa->gen = CYAPA_GEN3;
cyapa->state = CYAPA_STATE_BL_IDLE;
} else if (reg_data[REG_BL_FILE] == BL_FILE &&
(reg_data[REG_BL_STATUS] & BL_STATUS_RUNNING) ==
BL_STATUS_RUNNING) {
cyapa->gen = CYAPA_GEN3;
if (reg_data[REG_BL_STATUS] & BL_STATUS_BUSY) {
cyapa->state = CYAPA_STATE_BL_BUSY;
} else {
if ((reg_data[REG_BL_ERROR] & BL_ERROR_BOOTLOADING) ==
BL_ERROR_BOOTLOADING)
cyapa->state = CYAPA_STATE_BL_ACTIVE;
else
cyapa->state = CYAPA_STATE_BL_IDLE;
}
} else if ((reg_data[REG_OP_STATUS] & OP_STATUS_SRC) &&
(reg_data[REG_OP_DATA1] & OP_DATA_VALID)) {
if (GEN3_FINGER_NUM(reg_data[REG_OP_DATA1]) <=
GEN3_MAX_FINGERS) {
cyapa->gen = CYAPA_GEN3;
cyapa->state = CYAPA_STATE_OP;
}
} else if (reg_data[REG_OP_STATUS] == 0x0C &&
reg_data[REG_OP_DATA1] == 0x08) {
cyapa->gen = CYAPA_GEN3;
cyapa->state = CYAPA_STATE_OP;
} else if (reg_data[REG_BL_STATUS] &
(BL_STATUS_RUNNING | BL_STATUS_BUSY)) {
cyapa->gen = CYAPA_GEN3;
cyapa->state = CYAPA_STATE_BL_BUSY;
}
if (cyapa->gen == CYAPA_GEN3 && (cyapa->state == CYAPA_STATE_OP ||
cyapa->state == CYAPA_STATE_BL_IDLE ||
cyapa->state == CYAPA_STATE_BL_ACTIVE ||
cyapa->state == CYAPA_STATE_BL_BUSY))
return 0;
return -EAGAIN;
}
static int cyapa_gen3_bl_enter(struct cyapa *cyapa)
{
int error;
int waiting_time;
error = cyapa_poll_state(cyapa, 500);
if (error)
return error;
if (cyapa->state == CYAPA_STATE_BL_IDLE) {
return 0;
}
if (cyapa->state != CYAPA_STATE_OP)
return -EAGAIN;
cyapa->operational = false;
cyapa->state = CYAPA_STATE_NO_DEVICE;
error = cyapa_write_byte(cyapa, CYAPA_CMD_SOFT_RESET, 0x01);
if (error)
return -EIO;
usleep_range(25000, 50000);
waiting_time = 2000;
do {
error = cyapa_poll_state(cyapa, 500);
if (error) {
if (error == -ETIMEDOUT) {
waiting_time -= 500;
continue;
}
return error;
}
if ((cyapa->state == CYAPA_STATE_BL_IDLE) &&
!(cyapa->status[REG_BL_STATUS] & BL_STATUS_WATCHDOG))
break;
msleep(100);
waiting_time -= 100;
} while (waiting_time > 0);
if ((cyapa->state != CYAPA_STATE_BL_IDLE) ||
(cyapa->status[REG_BL_STATUS] & BL_STATUS_WATCHDOG))
return -EAGAIN;
return 0;
}
static int cyapa_gen3_bl_activate(struct cyapa *cyapa)
{
int error;
error = cyapa_i2c_reg_write_block(cyapa, 0, sizeof(bl_activate),
bl_activate);
if (error)
return error;
msleep(2000);
error = cyapa_poll_state(cyapa, 11000);
if (error)
return error;
if (cyapa->state != CYAPA_STATE_BL_ACTIVE)
return -EAGAIN;
return 0;
}
static int cyapa_gen3_bl_deactivate(struct cyapa *cyapa)
{
int error;
error = cyapa_i2c_reg_write_block(cyapa, 0, sizeof(bl_deactivate),
bl_deactivate);
if (error)
return error;
msleep(100);
error = cyapa_poll_state(cyapa, 500);
if (error)
return error;
if (cyapa->state != CYAPA_STATE_BL_IDLE)
return -EAGAIN;
return 0;
}
static int cyapa_gen3_bl_exit(struct cyapa *cyapa)
{
int error;
error = cyapa_i2c_reg_write_block(cyapa, 0, sizeof(bl_exit), bl_exit);
if (error)
return error;
msleep(50);
error = cyapa_poll_state(cyapa, 4000);
if (error < 0)
return error;
if (cyapa->state != CYAPA_STATE_OP)
return -EAGAIN;
return 0;
}
static u16 cyapa_gen3_csum(const u8 *buf, size_t count)
{
int i;
u16 csum = 0;
for (i = 0; i < count; i++)
csum += buf[i];
return csum;
}
static int cyapa_gen3_check_fw(struct cyapa *cyapa, const struct firmware *fw)
{
struct device *dev = &cyapa->client->dev;
u16 csum;
u16 csum_expected;
if (fw->size != CYAPA_FW_SIZE) {
dev_err(dev, "invalid firmware size = %zu, expected %u.\n",
fw->size, CYAPA_FW_SIZE);
return -EINVAL;
}
csum_expected = (fw->data[0] << 8) | fw->data[1];
csum = cyapa_gen3_csum(&fw->data[2], CYAPA_FW_HDR_SIZE - 2);
if (csum != csum_expected) {
dev_err(dev, "%s %04x, expected: %04x\n",
"invalid firmware header checksum = ",
csum, csum_expected);
return -EINVAL;
}
csum_expected = (fw->data[CYAPA_FW_HDR_SIZE - 2] << 8) |
fw->data[CYAPA_FW_HDR_SIZE - 1];
csum = cyapa_gen3_csum(&fw->data[CYAPA_FW_HDR_SIZE],
CYAPA_FW_DATA_SIZE);
if (csum != csum_expected) {
dev_err(dev, "%s %04x, expected: %04x\n",
"invalid firmware header checksum = ",
csum, csum_expected);
return -EINVAL;
}
return 0;
}
static int cyapa_gen3_write_buffer(struct cyapa *cyapa,
const u8 *buf, size_t len)
{
int error;
size_t i;
unsigned char cmd[CYAPA_CMD_LEN + 1];
size_t cmd_len;
for (i = 0; i < len; i += CYAPA_CMD_LEN) {
const u8 *payload = &buf[i];
cmd_len = (len - i >= CYAPA_CMD_LEN) ? CYAPA_CMD_LEN : len - i;
cmd[0] = i;
memcpy(&cmd[1], payload, cmd_len);
error = cyapa_i2c_reg_write_block(cyapa, 0, cmd_len + 1, cmd);
if (error)
return error;
}
return 0;
}
static int cyapa_gen3_write_fw_block(struct cyapa *cyapa,
u16 block, const u8 *data)
{
int ret;
struct gen3_write_block_cmd write_block_cmd;
u8 status[BL_STATUS_SIZE];
int tries;
u8 bl_status, bl_error;
write_block_cmd.checksum_seed = GEN3_BL_CMD_CHECKSUM_SEED;
write_block_cmd.cmd_code = GEN3_BL_CMD_WRITE_BLOCK;
memcpy(write_block_cmd.key, security_key, sizeof(security_key));
put_unaligned_be16(block, &write_block_cmd.block_num);
memcpy(write_block_cmd.block_data, data, CYAPA_FW_BLOCK_SIZE);
write_block_cmd.block_checksum = cyapa_gen3_csum(
write_block_cmd.block_data, CYAPA_FW_BLOCK_SIZE);
write_block_cmd.cmd_checksum = cyapa_gen3_csum((u8 *)&write_block_cmd,
sizeof(write_block_cmd) - 1);
ret = cyapa_gen3_write_buffer(cyapa, (u8 *)&write_block_cmd,
sizeof(write_block_cmd));
if (ret)
return ret;
tries = 11;
do {
usleep_range(10000, 20000);
ret = cyapa_i2c_reg_read_block(cyapa, BL_HEAD_OFFSET,
BL_STATUS_SIZE, status);
if (ret != BL_STATUS_SIZE)
return (ret < 0) ? ret : -EIO;
} while ((status[REG_BL_STATUS] & BL_STATUS_BUSY) && --tries);
bl_status = status[REG_BL_STATUS] & ~BL_STATUS_REV_MASK;
bl_error = status[REG_BL_ERROR] & ~BL_ERROR_RESERVED;
if (bl_status & BL_STATUS_BUSY)
ret = -ETIMEDOUT;
else if (bl_status != BL_STATUS_RUNNING ||
bl_error != BL_ERROR_BOOTLOADING)
ret = -EIO;
else
ret = 0;
return ret;
}
static int cyapa_gen3_write_blocks(struct cyapa *cyapa,
size_t start_block, size_t block_count,
const u8 *image_data)
{
int error;
int i;
for (i = 0; i < block_count; i++) {
size_t block = start_block + i;
size_t addr = i * CYAPA_FW_BLOCK_SIZE;
const u8 *data = &image_data[addr];
error = cyapa_gen3_write_fw_block(cyapa, block, data);
if (error)
return error;
}
return 0;
}
static int cyapa_gen3_do_fw_update(struct cyapa *cyapa,
const struct firmware *fw)
{
struct device *dev = &cyapa->client->dev;
int error;
error = cyapa_gen3_write_blocks(cyapa,
CYAPA_FW_DATA_BLOCK_START, CYAPA_FW_DATA_BLOCK_COUNT,
&fw->data[CYAPA_FW_HDR_BLOCK_COUNT * CYAPA_FW_BLOCK_SIZE]);
if (error) {
dev_err(dev, "FW update aborted, write image: %d\n", error);
return error;
}
error = cyapa_gen3_write_blocks(cyapa,
CYAPA_FW_HDR_BLOCK_START, CYAPA_FW_HDR_BLOCK_COUNT,
&fw->data[0]);
if (error) {
dev_err(dev, "FW update aborted, write checksum: %d\n", error);
return error;
}
return 0;
}
static ssize_t cyapa_gen3_do_calibrate(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
unsigned long timeout;
int ret;
ret = cyapa_read_byte(cyapa, CYAPA_CMD_DEV_STATUS);
if (ret < 0) {
dev_err(dev, "Error reading dev status: %d\n", ret);
goto out;
}
if ((ret & CYAPA_DEV_NORMAL) != CYAPA_DEV_NORMAL) {
dev_warn(dev, "Trackpad device is busy, device state: 0x%02x\n",
ret);
ret = -EAGAIN;
goto out;
}
ret = cyapa_write_byte(cyapa, CYAPA_CMD_SOFT_RESET,
OP_RECALIBRATION_MASK);
if (ret < 0) {
dev_err(dev, "Failed to send calibrate command: %d\n",
ret);
goto out;
}
timeout = jiffies + 2 * HZ;
do {
msleep(100);
ret = cyapa_read_byte(cyapa, CYAPA_CMD_DEV_STATUS);
if (ret < 0) {
dev_err(dev, "Error reading dev status: %d\n", ret);
goto out;
}
if ((ret & CYAPA_DEV_NORMAL) == CYAPA_DEV_NORMAL) {
dev_dbg(dev, "Calibration successful.\n");
goto out;
}
} while (time_is_after_jiffies(timeout));
dev_err(dev, "Failed to calibrate. Timeout.\n");
ret = -ETIMEDOUT;
out:
return ret < 0 ? ret : count;
}
static ssize_t cyapa_gen3_show_baseline(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int max_baseline, min_baseline;
int tries;
int ret;
ret = cyapa_read_byte(cyapa, CYAPA_CMD_DEV_STATUS);
if (ret < 0) {
dev_err(dev, "Error reading dev status. err = %d\n", ret);
goto out;
}
if ((ret & CYAPA_DEV_NORMAL) != CYAPA_DEV_NORMAL) {
dev_warn(dev, "Trackpad device is busy. device state = 0x%x\n",
ret);
ret = -EAGAIN;
goto out;
}
ret = cyapa_write_byte(cyapa, CYAPA_CMD_SOFT_RESET,
OP_REPORT_BASELINE_MASK);
if (ret < 0) {
dev_err(dev, "Failed to send report baseline command. %d\n",
ret);
goto out;
}
tries = 3;
do {
usleep_range(10000, 20000);
ret = cyapa_read_byte(cyapa, CYAPA_CMD_DEV_STATUS);
if (ret < 0) {
dev_err(dev, "Error reading dev status. err = %d\n",
ret);
goto out;
}
if ((ret & CYAPA_DEV_NORMAL) == CYAPA_DEV_NORMAL)
break;
} while (--tries);
if (tries == 0) {
dev_err(dev, "Device timed out going to Normal state.\n");
ret = -ETIMEDOUT;
goto out;
}
ret = cyapa_read_byte(cyapa, CYAPA_CMD_MAX_BASELINE);
if (ret < 0) {
dev_err(dev, "Failed to read max baseline. err = %d\n", ret);
goto out;
}
max_baseline = ret;
ret = cyapa_read_byte(cyapa, CYAPA_CMD_MIN_BASELINE);
if (ret < 0) {
dev_err(dev, "Failed to read min baseline. err = %d\n", ret);
goto out;
}
min_baseline = ret;
dev_dbg(dev, "Baseline report successful. Max: %d Min: %d\n",
max_baseline, min_baseline);
ret = scnprintf(buf, PAGE_SIZE, "%d %d\n", max_baseline, min_baseline);
out:
return ret;
}
static u16 cyapa_get_wait_time_for_pwr_cmd(u8 pwr_mode)
{
switch (pwr_mode) {
case PWR_MODE_FULL_ACTIVE: return 20;
case PWR_MODE_BTN_ONLY: return 20;
case PWR_MODE_OFF: return 20;
default: return cyapa_pwr_cmd_to_sleep_time(pwr_mode) + 50;
}
}
static int cyapa_gen3_set_power_mode(struct cyapa *cyapa, u8 power_mode,
u16 always_unused, enum cyapa_pm_stage pm_stage)
{
struct input_dev *input = cyapa->input;
u8 power;
int tries;
int sleep_time;
int interval;
int ret;
if (cyapa->state != CYAPA_STATE_OP)
return 0;
tries = SET_POWER_MODE_TRIES;
while (tries--) {
ret = cyapa_read_byte(cyapa, CYAPA_CMD_POWER_MODE);
if (ret >= 0)
break;
usleep_range(SET_POWER_MODE_DELAY, 2 * SET_POWER_MODE_DELAY);
}
if (ret < 0)
return ret;
if ((ret & PWR_MODE_MASK) == power_mode)
return 0;
sleep_time = (int)cyapa_get_wait_time_for_pwr_cmd(ret & PWR_MODE_MASK);
power = ret;
power &= ~PWR_MODE_MASK;
power |= power_mode & PWR_MODE_MASK;
tries = SET_POWER_MODE_TRIES;
while (tries--) {
ret = cyapa_write_byte(cyapa, CYAPA_CMD_POWER_MODE, power);
if (!ret)
break;
usleep_range(SET_POWER_MODE_DELAY, 2 * SET_POWER_MODE_DELAY);
}
if (cyapa->operational && input && input->users &&
(pm_stage == CYAPA_PM_RUNTIME_SUSPEND ||
pm_stage == CYAPA_PM_RUNTIME_RESUME)) {
interval = 1000 / 120;
while (sleep_time > 0) {
if (sleep_time > interval)
msleep(interval);
else
msleep(sleep_time);
sleep_time -= interval;
cyapa_gen3_try_poll_handler(cyapa);
}
} else {
msleep(sleep_time);
}
return ret;
}
static int cyapa_gen3_set_proximity(struct cyapa *cyapa, bool enable)
{
return -EOPNOTSUPP;
}
static int cyapa_gen3_get_query_data(struct cyapa *cyapa)
{
u8 query_data[QUERY_DATA_SIZE];
int ret;
if (cyapa->state != CYAPA_STATE_OP)
return -EBUSY;
ret = cyapa_read_block(cyapa, CYAPA_CMD_GROUP_QUERY, query_data);
if (ret != QUERY_DATA_SIZE)
return (ret < 0) ? ret : -EIO;
memcpy(&cyapa->product_id[0], &query_data[0], 5);
cyapa->product_id[5] = '-';
memcpy(&cyapa->product_id[6], &query_data[5], 6);
cyapa->product_id[12] = '-';
memcpy(&cyapa->product_id[13], &query_data[11], 2);
cyapa->product_id[15] = '\0';
cyapa->fw_maj_ver = query_data[15];
cyapa->fw_min_ver = query_data[16];
cyapa->btn_capability = query_data[19] & CAPABILITY_BTN_MASK;
cyapa->gen = query_data[20] & 0x0f;
cyapa->max_abs_x = ((query_data[21] & 0xf0) << 4) | query_data[22];
cyapa->max_abs_y = ((query_data[21] & 0x0f) << 8) | query_data[23];
cyapa->physical_size_x =
((query_data[24] & 0xf0) << 4) | query_data[25];
cyapa->physical_size_y =
((query_data[24] & 0x0f) << 8) | query_data[26];
cyapa->max_z = 255;
return 0;
}
static int cyapa_gen3_bl_query_data(struct cyapa *cyapa)
{
u8 bl_data[CYAPA_CMD_LEN];
int ret;
ret = cyapa_i2c_reg_read_block(cyapa, 0, CYAPA_CMD_LEN, bl_data);
if (ret != CYAPA_CMD_LEN)
return (ret < 0) ? ret : -EIO;
if (bl_data[REG_BL_STATUS] ==
(BL_STATUS_RUNNING | BL_STATUS_CSUM_VALID)) {
cyapa->fw_maj_ver = bl_data[GEN3_BL_IDLE_FW_MAJ_VER_OFFSET];
cyapa->fw_min_ver = bl_data[GEN3_BL_IDLE_FW_MIN_VER_OFFSET];
}
return 0;
}
static int cyapa_gen3_do_operational_check(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
int error;
switch (cyapa->state) {
case CYAPA_STATE_BL_ACTIVE:
error = cyapa_gen3_bl_deactivate(cyapa);
if (error) {
dev_err(dev, "failed to bl_deactivate: %d\n", error);
return error;
}
case CYAPA_STATE_BL_IDLE:
cyapa_gen3_bl_query_data(cyapa);
error = cyapa_gen3_bl_exit(cyapa);
if (error) {
dev_err(dev, "failed to bl_exit: %d\n", error);
return error;
}
case CYAPA_STATE_OP:
error = cyapa_gen3_set_power_mode(cyapa,
PWR_MODE_FULL_ACTIVE, 0, CYAPA_PM_ACTIVE);
if (error)
dev_err(dev, "%s: set full power mode failed: %d\n",
__func__, error);
error = cyapa_gen3_get_query_data(cyapa);
if (error < 0)
return error;
if (cyapa->gen != CYAPA_GEN3) {
dev_err(dev, "unsupported protocol version (%d)",
cyapa->gen);
return -EINVAL;
}
if (memcmp(cyapa->product_id, product_id,
strlen(product_id)) != 0) {
dev_err(dev, "unsupported product ID (%s)\n",
cyapa->product_id);
return -EINVAL;
}
return 0;
default:
return -EIO;
}
return 0;
}
static bool cyapa_gen3_irq_cmd_handler(struct cyapa *cyapa)
{
if (cyapa->gen != CYAPA_GEN3)
return true;
if (cyapa->operational)
return true;
return false;
}
static int cyapa_gen3_event_process(struct cyapa *cyapa,
struct cyapa_reg_data *data)
{
struct input_dev *input = cyapa->input;
int num_fingers;
int i;
num_fingers = (data->finger_btn >> 4) & 0x0f;
for (i = 0; i < num_fingers; i++) {
const struct cyapa_touch *touch = &data->touches[i];
int slot = touch->id - 1;
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, true);
input_report_abs(input, ABS_MT_POSITION_X,
((touch->xy_hi & 0xf0) << 4) | touch->x_lo);
input_report_abs(input, ABS_MT_POSITION_Y,
((touch->xy_hi & 0x0f) << 8) | touch->y_lo);
input_report_abs(input, ABS_MT_PRESSURE, touch->pressure);
}
input_mt_sync_frame(input);
if (cyapa->btn_capability & CAPABILITY_LEFT_BTN_MASK)
input_report_key(input, BTN_LEFT,
!!(data->finger_btn & OP_DATA_LEFT_BTN));
if (cyapa->btn_capability & CAPABILITY_MIDDLE_BTN_MASK)
input_report_key(input, BTN_MIDDLE,
!!(data->finger_btn & OP_DATA_MIDDLE_BTN));
if (cyapa->btn_capability & CAPABILITY_RIGHT_BTN_MASK)
input_report_key(input, BTN_RIGHT,
!!(data->finger_btn & OP_DATA_RIGHT_BTN));
input_sync(input);
return 0;
}
static int cyapa_gen3_irq_handler(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
struct cyapa_reg_data data;
int ret;
ret = cyapa_read_block(cyapa, CYAPA_CMD_GROUP_DATA, (u8 *)&data);
if (ret != sizeof(data)) {
dev_err(dev, "failed to read report data, (%d)\n", ret);
return -EINVAL;
}
if ((data.device_status & OP_STATUS_SRC) != OP_STATUS_SRC ||
(data.device_status & OP_STATUS_DEV) != CYAPA_DEV_NORMAL ||
(data.finger_btn & OP_DATA_VALID) != OP_DATA_VALID) {
dev_err(dev, "invalid device state bytes: %02x %02x\n",
data.device_status, data.finger_btn);
return -EINVAL;
}
return cyapa_gen3_event_process(cyapa, &data);
}
static int cyapa_gen3_try_poll_handler(struct cyapa *cyapa)
{
struct cyapa_reg_data data;
int ret;
ret = cyapa_read_block(cyapa, CYAPA_CMD_GROUP_DATA, (u8 *)&data);
if (ret != sizeof(data))
return -EINVAL;
if ((data.device_status & OP_STATUS_SRC) != OP_STATUS_SRC ||
(data.device_status & OP_STATUS_DEV) != CYAPA_DEV_NORMAL ||
(data.finger_btn & OP_DATA_VALID) != OP_DATA_VALID)
return -EINVAL;
return cyapa_gen3_event_process(cyapa, &data);
}
static int cyapa_gen3_initialize(struct cyapa *cyapa) { return 0; }
static int cyapa_gen3_bl_initiate(struct cyapa *cyapa,
const struct firmware *fw) { return 0; }
static int cyapa_gen3_empty_output_data(struct cyapa *cyapa,
u8 *buf, int *len, cb_sort func) { return 0; }
