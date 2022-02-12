static ssize_t cyapa_i2c_reg_read_block(struct cyapa *cyapa, u8 reg, size_t len,
u8 *values)
{
return i2c_smbus_read_i2c_block_data(cyapa->client, reg, len, values);
}
static ssize_t cyapa_i2c_reg_write_block(struct cyapa *cyapa, u8 reg,
size_t len, const u8 *values)
{
return i2c_smbus_write_i2c_block_data(cyapa->client, reg, len, values);
}
static ssize_t cyapa_smbus_read_block(struct cyapa *cyapa, u8 cmd, size_t len,
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
static ssize_t cyapa_read_block(struct cyapa *cyapa, u8 cmd_idx, u8 *values)
{
u8 cmd;
size_t len;
if (cyapa->smbus) {
cmd = cyapa_smbus_cmds[cmd_idx].cmd;
len = cyapa_smbus_cmds[cmd_idx].len;
return cyapa_smbus_read_block(cyapa, cmd, len, values);
} else {
cmd = cyapa_i2c_cmds[cmd_idx].cmd;
len = cyapa_i2c_cmds[cmd_idx].len;
return cyapa_i2c_reg_read_block(cyapa, cmd, len, values);
}
}
static int cyapa_get_state(struct cyapa *cyapa)
{
int ret;
u8 status[BL_STATUS_SIZE];
cyapa->state = CYAPA_STATE_NO_DEVICE;
ret = cyapa_i2c_reg_read_block(cyapa, BL_HEAD_OFFSET, BL_STATUS_SIZE,
status);
if (cyapa->smbus && (ret == -ETIMEDOUT || ret == -ENXIO))
ret = cyapa_read_block(cyapa, CYAPA_CMD_BL_STATUS, status);
if (ret != BL_STATUS_SIZE)
goto error;
if ((status[REG_OP_STATUS] & OP_STATUS_SRC) == OP_STATUS_SRC) {
switch (status[REG_OP_STATUS] & OP_STATUS_DEV) {
case CYAPA_DEV_NORMAL:
case CYAPA_DEV_BUSY:
cyapa->state = CYAPA_STATE_OP;
break;
default:
ret = -EAGAIN;
goto error;
}
} else {
if (status[REG_BL_STATUS] & BL_STATUS_BUSY)
cyapa->state = CYAPA_STATE_BL_BUSY;
else if (status[REG_BL_ERROR] & BL_ERROR_BOOTLOADING)
cyapa->state = CYAPA_STATE_BL_ACTIVE;
else
cyapa->state = CYAPA_STATE_BL_IDLE;
}
return 0;
error:
return (ret < 0) ? ret : -EAGAIN;
}
static int cyapa_poll_state(struct cyapa *cyapa, unsigned int timeout)
{
int ret;
int tries = timeout / 100;
ret = cyapa_get_state(cyapa);
while ((ret || cyapa->state >= CYAPA_STATE_BL_BUSY) && tries--) {
msleep(100);
ret = cyapa_get_state(cyapa);
}
return (ret == -EAGAIN || ret == -ETIMEDOUT) ? -ETIMEDOUT : ret;
}
static int cyapa_bl_deactivate(struct cyapa *cyapa)
{
int ret;
ret = cyapa_i2c_reg_write_block(cyapa, 0, sizeof(bl_deactivate),
bl_deactivate);
if (ret < 0)
return ret;
msleep(100);
ret = cyapa_poll_state(cyapa, 500);
if (ret < 0)
return ret;
if (cyapa->state != CYAPA_STATE_BL_IDLE)
return -EAGAIN;
return 0;
}
static int cyapa_bl_exit(struct cyapa *cyapa)
{
int ret;
ret = cyapa_i2c_reg_write_block(cyapa, 0, sizeof(bl_exit), bl_exit);
if (ret < 0)
return ret;
usleep_range(50000, 100000);
ret = cyapa_poll_state(cyapa, 2000);
if (ret < 0)
return ret;
if (cyapa->state != CYAPA_STATE_OP)
return -EAGAIN;
return 0;
}
static int cyapa_set_power_mode(struct cyapa *cyapa, u8 power_mode)
{
struct device *dev = &cyapa->client->dev;
int ret;
u8 power;
if (cyapa->state != CYAPA_STATE_OP)
return 0;
ret = cyapa_read_byte(cyapa, CYAPA_CMD_POWER_MODE);
if (ret < 0)
return ret;
power = ret & ~PWR_MODE_MASK;
power |= power_mode & PWR_MODE_MASK;
ret = cyapa_write_byte(cyapa, CYAPA_CMD_POWER_MODE, power);
if (ret < 0)
dev_err(dev, "failed to set power_mode 0x%02x err = %d\n",
power_mode, ret);
return ret;
}
static int cyapa_get_query_data(struct cyapa *cyapa)
{
u8 query_data[QUERY_DATA_SIZE];
int ret;
if (cyapa->state != CYAPA_STATE_OP)
return -EBUSY;
ret = cyapa_read_block(cyapa, CYAPA_CMD_GROUP_QUERY, query_data);
if (ret < 0)
return ret;
if (ret != QUERY_DATA_SIZE)
return -EIO;
memcpy(&cyapa->product_id[0], &query_data[0], 5);
cyapa->product_id[5] = '-';
memcpy(&cyapa->product_id[6], &query_data[5], 6);
cyapa->product_id[12] = '-';
memcpy(&cyapa->product_id[13], &query_data[11], 2);
cyapa->product_id[15] = '\0';
cyapa->btn_capability = query_data[19] & CAPABILITY_BTN_MASK;
cyapa->gen = query_data[20] & 0x0f;
cyapa->max_abs_x = ((query_data[21] & 0xf0) << 4) | query_data[22];
cyapa->max_abs_y = ((query_data[21] & 0x0f) << 8) | query_data[23];
cyapa->physical_size_x =
((query_data[24] & 0xf0) << 4) | query_data[25];
cyapa->physical_size_y =
((query_data[24] & 0x0f) << 8) | query_data[26];
return 0;
}
static int cyapa_check_is_operational(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
static const char unique_str[] = "CYTRA";
int ret;
ret = cyapa_poll_state(cyapa, 2000);
if (ret < 0)
return ret;
switch (cyapa->state) {
case CYAPA_STATE_BL_ACTIVE:
ret = cyapa_bl_deactivate(cyapa);
if (ret)
return ret;
case CYAPA_STATE_BL_IDLE:
ret = cyapa_bl_exit(cyapa);
if (ret)
return ret;
case CYAPA_STATE_OP:
ret = cyapa_get_query_data(cyapa);
if (ret < 0)
return ret;
if (cyapa->gen != CYAPA_GEN3) {
dev_err(dev, "unsupported protocol version (%d)",
cyapa->gen);
return -EINVAL;
}
if (memcmp(cyapa->product_id, unique_str,
sizeof(unique_str) - 1) != 0) {
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
static irqreturn_t cyapa_irq(int irq, void *dev_id)
{
struct cyapa *cyapa = dev_id;
struct device *dev = &cyapa->client->dev;
struct input_dev *input = cyapa->input;
struct cyapa_reg_data data;
int i;
int ret;
int num_fingers;
if (device_may_wakeup(dev))
pm_wakeup_event(dev, 0);
ret = cyapa_read_block(cyapa, CYAPA_CMD_GROUP_DATA, (u8 *)&data);
if (ret != sizeof(data))
goto out;
if ((data.device_status & OP_STATUS_SRC) != OP_STATUS_SRC ||
(data.device_status & OP_STATUS_DEV) != CYAPA_DEV_NORMAL ||
(data.finger_btn & OP_DATA_VALID) != OP_DATA_VALID) {
goto out;
}
num_fingers = (data.finger_btn >> 4) & 0x0f;
for (i = 0; i < num_fingers; i++) {
const struct cyapa_touch *touch = &data.touches[i];
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
data.finger_btn & OP_DATA_LEFT_BTN);
if (cyapa->btn_capability & CAPABILITY_MIDDLE_BTN_MASK)
input_report_key(input, BTN_MIDDLE,
data.finger_btn & OP_DATA_MIDDLE_BTN);
if (cyapa->btn_capability & CAPABILITY_RIGHT_BTN_MASK)
input_report_key(input, BTN_RIGHT,
data.finger_btn & OP_DATA_RIGHT_BTN);
input_sync(input);
out:
return IRQ_HANDLED;
}
static u8 cyapa_check_adapter_functionality(struct i2c_client *client)
{
u8 ret = CYAPA_ADAPTER_FUNC_NONE;
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
ret |= CYAPA_ADAPTER_FUNC_I2C;
if (i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK))
ret |= CYAPA_ADAPTER_FUNC_SMBUS;
return ret;
}
static int cyapa_create_input_dev(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
int ret;
struct input_dev *input;
if (!cyapa->physical_size_x || !cyapa->physical_size_y)
return -EINVAL;
input = cyapa->input = input_allocate_device();
if (!input) {
dev_err(dev, "allocate memory for input device failed\n");
return -ENOMEM;
}
input->name = CYAPA_NAME;
input->phys = cyapa->phys;
input->id.bustype = BUS_I2C;
input->id.version = 1;
input->id.product = 0;
input->dev.parent = &cyapa->client->dev;
input_set_drvdata(input, cyapa);
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_MT_POSITION_X, 0, cyapa->max_abs_x, 0,
0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0, cyapa->max_abs_y, 0,
0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0, 255, 0, 0);
input_abs_set_res(input, ABS_MT_POSITION_X,
cyapa->max_abs_x / cyapa->physical_size_x);
input_abs_set_res(input, ABS_MT_POSITION_Y,
cyapa->max_abs_y / cyapa->physical_size_y);
if (cyapa->btn_capability & CAPABILITY_LEFT_BTN_MASK)
__set_bit(BTN_LEFT, input->keybit);
if (cyapa->btn_capability & CAPABILITY_MIDDLE_BTN_MASK)
__set_bit(BTN_MIDDLE, input->keybit);
if (cyapa->btn_capability & CAPABILITY_RIGHT_BTN_MASK)
__set_bit(BTN_RIGHT, input->keybit);
if (cyapa->btn_capability == CAPABILITY_LEFT_BTN_MASK)
__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);
ret = input_mt_init_slots(input, CYAPA_MAX_MT_SLOTS,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED);
if (ret) {
dev_err(dev, "allocate memory for MT slots failed, %d\n", ret);
goto err_free_device;
}
ret = input_register_device(input);
if (ret) {
dev_err(dev, "input device register failed, %d\n", ret);
goto err_free_device;
}
return 0;
err_free_device:
input_free_device(input);
cyapa->input = NULL;
return ret;
}
static int cyapa_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
int ret;
u8 adapter_func;
struct cyapa *cyapa;
struct device *dev = &client->dev;
adapter_func = cyapa_check_adapter_functionality(client);
if (adapter_func == CYAPA_ADAPTER_FUNC_NONE) {
dev_err(dev, "not a supported I2C/SMBus adapter\n");
return -EIO;
}
cyapa = kzalloc(sizeof(struct cyapa), GFP_KERNEL);
if (!cyapa) {
dev_err(dev, "allocate memory for cyapa failed\n");
return -ENOMEM;
}
cyapa->gen = CYAPA_GEN3;
cyapa->client = client;
i2c_set_clientdata(client, cyapa);
sprintf(cyapa->phys, "i2c-%d-%04x/input0", client->adapter->nr,
client->addr);
if (adapter_func == CYAPA_ADAPTER_FUNC_SMBUS)
cyapa->smbus = true;
cyapa->state = CYAPA_STATE_NO_DEVICE;
ret = cyapa_check_is_operational(cyapa);
if (ret) {
dev_err(dev, "device not operational, %d\n", ret);
goto err_mem_free;
}
ret = cyapa_create_input_dev(cyapa);
if (ret) {
dev_err(dev, "create input_dev instance failed, %d\n", ret);
goto err_mem_free;
}
ret = cyapa_set_power_mode(cyapa, PWR_MODE_FULL_ACTIVE);
if (ret) {
dev_err(dev, "set active power failed, %d\n", ret);
goto err_unregister_device;
}
cyapa->irq = client->irq;
ret = request_threaded_irq(cyapa->irq,
NULL,
cyapa_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"cyapa",
cyapa);
if (ret) {
dev_err(dev, "IRQ request failed: %d\n, ", ret);
goto err_unregister_device;
}
return 0;
err_unregister_device:
input_unregister_device(cyapa->input);
err_mem_free:
kfree(cyapa);
return ret;
}
static int cyapa_remove(struct i2c_client *client)
{
struct cyapa *cyapa = i2c_get_clientdata(client);
free_irq(cyapa->irq, cyapa);
input_unregister_device(cyapa->input);
cyapa_set_power_mode(cyapa, PWR_MODE_OFF);
kfree(cyapa);
return 0;
}
static int cyapa_suspend(struct device *dev)
{
int ret;
u8 power_mode;
struct cyapa *cyapa = dev_get_drvdata(dev);
disable_irq(cyapa->irq);
power_mode = device_may_wakeup(dev) ? PWR_MODE_IDLE
: PWR_MODE_OFF;
ret = cyapa_set_power_mode(cyapa, power_mode);
if (ret < 0)
dev_err(dev, "set power mode failed, %d\n", ret);
if (device_may_wakeup(dev))
cyapa->irq_wake = (enable_irq_wake(cyapa->irq) == 0);
return 0;
}
static int cyapa_resume(struct device *dev)
{
int ret;
struct cyapa *cyapa = dev_get_drvdata(dev);
if (device_may_wakeup(dev) && cyapa->irq_wake)
disable_irq_wake(cyapa->irq);
ret = cyapa_set_power_mode(cyapa, PWR_MODE_FULL_ACTIVE);
if (ret)
dev_warn(dev, "resume active power failed, %d\n", ret);
enable_irq(cyapa->irq);
return 0;
}
