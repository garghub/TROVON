bool cyapa_is_pip_bl_mode(struct cyapa *cyapa)
{
if (cyapa->gen == CYAPA_GEN6 && cyapa->state == CYAPA_STATE_GEN6_BL)
return true;
if (cyapa->gen == CYAPA_GEN5 && cyapa->state == CYAPA_STATE_GEN5_BL)
return true;
return false;
}
bool cyapa_is_pip_app_mode(struct cyapa *cyapa)
{
if (cyapa->gen == CYAPA_GEN6 && cyapa->state == CYAPA_STATE_GEN6_APP)
return true;
if (cyapa->gen == CYAPA_GEN5 && cyapa->state == CYAPA_STATE_GEN5_APP)
return true;
return false;
}
static bool cyapa_is_bootloader_mode(struct cyapa *cyapa)
{
if (cyapa_is_pip_bl_mode(cyapa))
return true;
if (cyapa->gen == CYAPA_GEN3 &&
cyapa->state >= CYAPA_STATE_BL_BUSY &&
cyapa->state <= CYAPA_STATE_BL_ACTIVE)
return true;
return false;
}
static inline bool cyapa_is_operational_mode(struct cyapa *cyapa)
{
if (cyapa_is_pip_app_mode(cyapa))
return true;
if (cyapa->gen == CYAPA_GEN3 && cyapa->state == CYAPA_STATE_OP)
return true;
return false;
}
static ssize_t cyapa_i2c_read(struct cyapa *cyapa, u8 reg, size_t len,
u8 *values)
{
struct i2c_client *client = cyapa->client;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &reg,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = len,
.buf = values,
},
};
int ret;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret != ARRAY_SIZE(msgs))
return ret < 0 ? ret : -EIO;
return 0;
}
static int cyapa_i2c_write(struct cyapa *cyapa, u8 reg,
size_t len, const void *values)
{
struct i2c_client *client = cyapa->client;
char buf[32];
int ret;
if (len > sizeof(buf) - 1)
return -ENOMEM;
buf[0] = reg;
memcpy(&buf[1], values, len);
ret = i2c_master_send(client, buf, len + 1);
if (ret != len + 1)
return ret < 0 ? ret : -EIO;
return 0;
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
static int cyapa_get_state(struct cyapa *cyapa)
{
u8 status[BL_STATUS_SIZE];
u8 cmd[32];
bool even_addr = ((cyapa->client->addr & 0x0001) == 0);
bool smbus = false;
int retries = 2;
int error;
cyapa->state = CYAPA_STATE_NO_DEVICE;
error = cyapa_i2c_reg_read_block(cyapa, BL_HEAD_OFFSET, BL_STATUS_SIZE,
status);
if (cyapa->smbus && (error == -ETIMEDOUT || error == -ENXIO)) {
if (!even_addr)
error = cyapa_read_block(cyapa,
CYAPA_CMD_BL_STATUS, status);
smbus = true;
}
if (error != BL_STATUS_SIZE)
goto error;
do {
cyapa->status[REG_OP_STATUS] = status[REG_OP_STATUS];
cyapa->status[REG_BL_STATUS] = status[REG_BL_STATUS];
cyapa->status[REG_BL_ERROR] = status[REG_BL_ERROR];
if (cyapa->gen == CYAPA_GEN_UNKNOWN ||
cyapa->gen == CYAPA_GEN3) {
error = cyapa_gen3_ops.state_parse(cyapa,
status, BL_STATUS_SIZE);
if (!error)
goto out_detected;
}
if (cyapa->gen == CYAPA_GEN_UNKNOWN ||
cyapa->gen == CYAPA_GEN6 ||
cyapa->gen == CYAPA_GEN5) {
error = cyapa_pip_state_parse(cyapa,
status, BL_STATUS_SIZE);
if (!error)
goto out_detected;
}
if ((cyapa->gen == CYAPA_GEN_UNKNOWN ||
cyapa->gen == CYAPA_GEN5) &&
!smbus && even_addr) {
error = cyapa_gen5_ops.state_parse(cyapa,
status, BL_STATUS_SIZE);
if (!error)
goto out_detected;
}
if (!smbus) {
cmd[0] = 0x00;
cmd[1] = 0x00;
error = cyapa_i2c_write(cyapa, 0, 2, cmd);
if (error)
goto error;
msleep(50);
error = cyapa_i2c_read(cyapa, BL_HEAD_OFFSET,
BL_STATUS_SIZE, status);
if (error)
goto error;
}
} while (--retries > 0 && !smbus);
goto error;
out_detected:
if (cyapa->state <= CYAPA_STATE_BL_BUSY)
return -EAGAIN;
return 0;
error:
return (error < 0) ? error : -EAGAIN;
}
int cyapa_poll_state(struct cyapa *cyapa, unsigned int timeout)
{
int error;
int tries = timeout / 100;
do {
error = cyapa_get_state(cyapa);
if (!error && cyapa->state > CYAPA_STATE_BL_BUSY)
return 0;
msleep(100);
} while (tries--);
return (error == -EAGAIN || error == -ETIMEDOUT) ? -ETIMEDOUT : error;
}
static int cyapa_check_is_operational(struct cyapa *cyapa)
{
int error;
error = cyapa_poll_state(cyapa, 4000);
if (error)
return error;
switch (cyapa->gen) {
case CYAPA_GEN6:
cyapa->ops = &cyapa_gen6_ops;
break;
case CYAPA_GEN5:
cyapa->ops = &cyapa_gen5_ops;
break;
case CYAPA_GEN3:
cyapa->ops = &cyapa_gen3_ops;
break;
default:
return -ENODEV;
}
error = cyapa->ops->operational_check(cyapa);
if (!error && cyapa_is_operational_mode(cyapa))
cyapa->operational = true;
else
cyapa->operational = false;
return error;
}
static int cyapa_detect(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
int error;
error = cyapa_check_is_operational(cyapa);
if (error) {
if (error != -ETIMEDOUT && error != -ENODEV &&
cyapa_is_bootloader_mode(cyapa)) {
dev_warn(dev, "device detected but not operational\n");
return 0;
}
dev_err(dev, "no device detected: %d\n", error);
return error;
}
return 0;
}
static int cyapa_open(struct input_dev *input)
{
struct cyapa *cyapa = input_get_drvdata(input);
struct i2c_client *client = cyapa->client;
struct device *dev = &client->dev;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
if (cyapa->operational) {
error = cyapa->ops->set_power_mode(cyapa,
PWR_MODE_FULL_ACTIVE, 0, false);
if (error) {
dev_warn(dev, "set active power failed: %d\n", error);
goto out;
}
} else {
error = cyapa_reinitialize(cyapa);
if (error || !cyapa->operational) {
error = error ? error : -EAGAIN;
goto out;
}
}
enable_irq(client->irq);
if (!pm_runtime_enabled(dev)) {
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
pm_runtime_get_sync(dev);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_sync_autosuspend(dev);
out:
mutex_unlock(&cyapa->state_sync_lock);
return error;
}
static void cyapa_close(struct input_dev *input)
{
struct cyapa *cyapa = input_get_drvdata(input);
struct i2c_client *client = cyapa->client;
struct device *dev = &cyapa->client->dev;
mutex_lock(&cyapa->state_sync_lock);
disable_irq(client->irq);
if (pm_runtime_enabled(dev))
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
if (cyapa->operational)
cyapa->ops->set_power_mode(cyapa, PWR_MODE_OFF, 0, false);
mutex_unlock(&cyapa->state_sync_lock);
}
static int cyapa_create_input_dev(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
struct input_dev *input;
int error;
if (!cyapa->physical_size_x || !cyapa->physical_size_y)
return -EINVAL;
input = devm_input_allocate_device(dev);
if (!input) {
dev_err(dev, "failed to allocate memory for input device.\n");
return -ENOMEM;
}
input->name = CYAPA_NAME;
input->phys = cyapa->phys;
input->id.bustype = BUS_I2C;
input->id.version = 1;
input->id.product = 0;
input->dev.parent = &cyapa->client->dev;
input->open = cyapa_open;
input->close = cyapa_close;
input_set_drvdata(input, cyapa);
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_MT_POSITION_X, 0, cyapa->max_abs_x, 0,
0);
input_set_abs_params(input, ABS_MT_POSITION_Y, 0, cyapa->max_abs_y, 0,
0);
input_set_abs_params(input, ABS_MT_PRESSURE, 0, cyapa->max_z, 0, 0);
if (cyapa->gen > CYAPA_GEN3) {
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR, 0, 255, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MINOR, 0, 255, 0, 0);
input_set_abs_params(input, ABS_MT_ORIENTATION,
-127, 127, 0, 0);
}
if (cyapa->gen >= CYAPA_GEN5) {
input_set_abs_params(input, ABS_MT_WIDTH_MAJOR, 0, 255, 0, 0);
input_set_abs_params(input, ABS_MT_WIDTH_MINOR, 0, 255, 0, 0);
input_set_abs_params(input, ABS_DISTANCE, 0, 1, 0, 0);
}
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
error = input_mt_init_slots(input, CYAPA_MAX_MT_SLOTS,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED);
if (error) {
dev_err(dev, "failed to initialize MT slots: %d\n", error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "failed to register input device: %d\n", error);
return error;
}
cyapa->input = input;
return 0;
}
static void cyapa_enable_irq_for_cmd(struct cyapa *cyapa)
{
struct input_dev *input = cyapa->input;
if (!input || !input->users) {
if (!input || cyapa->operational)
cyapa->ops->set_power_mode(cyapa,
PWR_MODE_FULL_ACTIVE, 0, false);
if (cyapa->gen >= CYAPA_GEN5)
enable_irq(cyapa->client->irq);
}
}
static void cyapa_disable_irq_for_cmd(struct cyapa *cyapa)
{
struct input_dev *input = cyapa->input;
if (!input || !input->users) {
if (cyapa->gen >= CYAPA_GEN5)
disable_irq(cyapa->client->irq);
if (!input || cyapa->operational)
cyapa->ops->set_power_mode(cyapa,
PWR_MODE_OFF, 0, false);
}
}
u8 cyapa_sleep_time_to_pwr_cmd(u16 sleep_time)
{
u16 encoded_time;
sleep_time = clamp_val(sleep_time, 20, 1000);
encoded_time = sleep_time < 100 ? sleep_time / 10 : sleep_time / 20 + 5;
return (encoded_time << 2) & PWR_MODE_MASK;
}
u16 cyapa_pwr_cmd_to_sleep_time(u8 pwr_mode)
{
u8 encoded_time = pwr_mode >> 2;
return (encoded_time < 10) ? encoded_time * 10
: (encoded_time - 5) * 20;
}
static int cyapa_initialize(struct cyapa *cyapa)
{
int error = 0;
cyapa->state = CYAPA_STATE_NO_DEVICE;
cyapa->gen = CYAPA_GEN_UNKNOWN;
mutex_init(&cyapa->state_sync_lock);
cyapa->suspend_power_mode = PWR_MODE_SLEEP;
cyapa->suspend_sleep_time =
cyapa_pwr_cmd_to_sleep_time(cyapa->suspend_power_mode);
error = cyapa_gen3_ops.initialize(cyapa);
if (!error)
error = cyapa_gen5_ops.initialize(cyapa);
if (!error)
error = cyapa_gen6_ops.initialize(cyapa);
if (error)
return error;
error = cyapa_detect(cyapa);
if (error)
return error;
if (cyapa->operational)
cyapa->ops->set_power_mode(cyapa, PWR_MODE_OFF, 0, false);
return 0;
}
static int cyapa_reinitialize(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
struct input_dev *input = cyapa->input;
int error;
if (pm_runtime_enabled(dev))
pm_runtime_disable(dev);
if (cyapa->operational)
cyapa->ops->set_power_mode(cyapa,
PWR_MODE_FULL_ACTIVE, 0, false);
error = cyapa_detect(cyapa);
if (error)
goto out;
if (!input && cyapa->operational) {
error = cyapa_create_input_dev(cyapa);
if (error) {
dev_err(dev, "create input_dev instance failed: %d\n",
error);
goto out;
}
}
out:
if (!input || !input->users) {
if (cyapa->operational)
cyapa->ops->set_power_mode(cyapa,
PWR_MODE_OFF, 0, false);
} else if (!error && cyapa->operational) {
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_sync_autosuspend(dev);
}
return error;
}
static irqreturn_t cyapa_irq(int irq, void *dev_id)
{
struct cyapa *cyapa = dev_id;
struct device *dev = &cyapa->client->dev;
int error;
if (device_may_wakeup(dev))
pm_wakeup_event(dev, 0);
if (cyapa->ops->irq_cmd_handler(cyapa)) {
if (!cyapa->input) {
cyapa->ops->sort_empty_output_data(cyapa,
NULL, NULL, NULL);
goto out;
}
if (cyapa->operational) {
error = cyapa->ops->irq_handler(cyapa);
pm_runtime_get_sync(dev);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_sync_autosuspend(dev);
}
if (!cyapa->operational || error) {
if (!mutex_trylock(&cyapa->state_sync_lock)) {
cyapa->ops->sort_empty_output_data(cyapa,
NULL, NULL, NULL);
goto out;
}
cyapa_reinitialize(cyapa);
mutex_unlock(&cyapa->state_sync_lock);
}
}
out:
return IRQ_HANDLED;
}
static ssize_t cyapa_show_suspend_scanrate(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
u8 pwr_cmd = cyapa->suspend_power_mode;
u16 sleep_time;
int len;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
pwr_cmd = cyapa->suspend_power_mode;
sleep_time = cyapa->suspend_sleep_time;
mutex_unlock(&cyapa->state_sync_lock);
switch (pwr_cmd) {
case PWR_MODE_BTN_ONLY:
len = scnprintf(buf, PAGE_SIZE, "%s\n", BTN_ONLY_MODE_NAME);
break;
case PWR_MODE_OFF:
len = scnprintf(buf, PAGE_SIZE, "%s\n", OFF_MODE_NAME);
break;
default:
len = scnprintf(buf, PAGE_SIZE, "%u\n",
cyapa->gen == CYAPA_GEN3 ?
cyapa_pwr_cmd_to_sleep_time(pwr_cmd) :
sleep_time);
break;
}
return len;
}
static ssize_t cyapa_update_suspend_scanrate(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
u16 sleep_time;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
if (sysfs_streq(buf, BTN_ONLY_MODE_NAME)) {
cyapa->suspend_power_mode = PWR_MODE_BTN_ONLY;
} else if (sysfs_streq(buf, OFF_MODE_NAME)) {
cyapa->suspend_power_mode = PWR_MODE_OFF;
} else if (!kstrtou16(buf, 10, &sleep_time)) {
cyapa->suspend_sleep_time = min_t(u16, sleep_time, 1000);
cyapa->suspend_power_mode =
cyapa_sleep_time_to_pwr_cmd(cyapa->suspend_sleep_time);
} else {
count = -EINVAL;
}
mutex_unlock(&cyapa->state_sync_lock);
return count;
}
static void cyapa_remove_power_wakeup_group(void *data)
{
struct cyapa *cyapa = data;
sysfs_unmerge_group(&cyapa->client->dev.kobj,
&cyapa_power_wakeup_group);
}
static int cyapa_prepare_wakeup_controls(struct cyapa *cyapa)
{
struct i2c_client *client = cyapa->client;
struct device *dev = &client->dev;
int error;
if (device_can_wakeup(dev)) {
error = sysfs_merge_group(&client->dev.kobj,
&cyapa_power_wakeup_group);
if (error) {
dev_err(dev, "failed to add power wakeup group: %d\n",
error);
return error;
}
error = devm_add_action(dev,
cyapa_remove_power_wakeup_group, cyapa);
if (error) {
cyapa_remove_power_wakeup_group(cyapa);
dev_err(dev, "failed to add power cleanup action: %d\n",
error);
return error;
}
}
return 0;
}
static inline int cyapa_prepare_wakeup_controls(struct cyapa *cyapa)
{
return 0;
}
static ssize_t cyapa_show_rt_suspend_scanrate(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
u8 pwr_cmd;
u16 sleep_time;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
pwr_cmd = cyapa->runtime_suspend_power_mode;
sleep_time = cyapa->runtime_suspend_sleep_time;
mutex_unlock(&cyapa->state_sync_lock);
return scnprintf(buf, PAGE_SIZE, "%u\n",
cyapa->gen == CYAPA_GEN3 ?
cyapa_pwr_cmd_to_sleep_time(pwr_cmd) :
sleep_time);
}
static ssize_t cyapa_update_rt_suspend_scanrate(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
u16 time;
int error;
if (buf == NULL || count == 0 || kstrtou16(buf, 10, &time)) {
dev_err(dev, "invalid runtime suspend scanrate ms parameter\n");
return -EINVAL;
}
pm_runtime_get_sync(dev);
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
cyapa->runtime_suspend_sleep_time = min_t(u16, time, 1000);
cyapa->runtime_suspend_power_mode =
cyapa_sleep_time_to_pwr_cmd(cyapa->runtime_suspend_sleep_time);
mutex_unlock(&cyapa->state_sync_lock);
pm_runtime_put_sync_autosuspend(dev);
return count;
}
static void cyapa_remove_power_runtime_group(void *data)
{
struct cyapa *cyapa = data;
sysfs_unmerge_group(&cyapa->client->dev.kobj,
&cyapa_power_runtime_group);
}
static int cyapa_start_runtime(struct cyapa *cyapa)
{
struct device *dev = &cyapa->client->dev;
int error;
cyapa->runtime_suspend_power_mode = PWR_MODE_IDLE;
cyapa->runtime_suspend_sleep_time =
cyapa_pwr_cmd_to_sleep_time(cyapa->runtime_suspend_power_mode);
error = sysfs_merge_group(&dev->kobj, &cyapa_power_runtime_group);
if (error) {
dev_err(dev,
"failed to create power runtime group: %d\n", error);
return error;
}
error = devm_add_action(dev, cyapa_remove_power_runtime_group, cyapa);
if (error) {
cyapa_remove_power_runtime_group(cyapa);
dev_err(dev,
"failed to add power runtime cleanup action: %d\n",
error);
return error;
}
pm_runtime_set_suspended(dev);
pm_runtime_use_autosuspend(dev);
pm_runtime_set_autosuspend_delay(dev, AUTOSUSPEND_DELAY);
return 0;
}
static inline int cyapa_start_runtime(struct cyapa *cyapa)
{
return 0;
}
static ssize_t cyapa_show_fm_ver(struct device *dev,
struct device_attribute *attr, char *buf)
{
int error;
struct cyapa *cyapa = dev_get_drvdata(dev);
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
error = scnprintf(buf, PAGE_SIZE, "%d.%d\n", cyapa->fw_maj_ver,
cyapa->fw_min_ver);
mutex_unlock(&cyapa->state_sync_lock);
return error;
}
static ssize_t cyapa_show_product_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int size;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
size = scnprintf(buf, PAGE_SIZE, "%s\n", cyapa->product_id);
mutex_unlock(&cyapa->state_sync_lock);
return size;
}
static int cyapa_firmware(struct cyapa *cyapa, const char *fw_name)
{
struct device *dev = &cyapa->client->dev;
const struct firmware *fw;
int error;
error = request_firmware(&fw, fw_name, dev);
if (error) {
dev_err(dev, "Could not load firmware from %s: %d\n",
fw_name, error);
return error;
}
error = cyapa->ops->check_fw(cyapa, fw);
if (error) {
dev_err(dev, "Invalid CYAPA firmware image: %s\n",
fw_name);
goto done;
}
pm_runtime_get_sync(dev);
cyapa_enable_irq_for_cmd(cyapa);
error = cyapa->ops->bl_enter(cyapa);
if (error) {
dev_err(dev, "bl_enter failed, %d\n", error);
goto err_detect;
}
error = cyapa->ops->bl_activate(cyapa);
if (error) {
dev_err(dev, "bl_activate failed, %d\n", error);
goto err_detect;
}
error = cyapa->ops->bl_initiate(cyapa, fw);
if (error) {
dev_err(dev, "bl_initiate failed, %d\n", error);
goto err_detect;
}
error = cyapa->ops->update_fw(cyapa, fw);
if (error) {
dev_err(dev, "update_fw failed, %d\n", error);
goto err_detect;
}
err_detect:
cyapa_disable_irq_for_cmd(cyapa);
pm_runtime_put_noidle(dev);
done:
release_firmware(fw);
return error;
}
static ssize_t cyapa_update_fw_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
char fw_name[NAME_MAX];
int ret, error;
if (count >= NAME_MAX) {
dev_err(dev, "File name too long\n");
return -EINVAL;
}
memcpy(fw_name, buf, count);
if (fw_name[count - 1] == '\n')
fw_name[count - 1] = '\0';
else
fw_name[count] = '\0';
if (cyapa->input) {
input_unregister_device(cyapa->input);
cyapa->input = NULL;
}
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error) {
cyapa_reinitialize(cyapa);
return error;
}
error = cyapa_firmware(cyapa, fw_name);
if (error)
dev_err(dev, "firmware update failed: %d\n", error);
else
dev_dbg(dev, "firmware update successfully done.\n");
ret = cyapa_reinitialize(cyapa);
if (ret) {
dev_err(dev, "failed to re-detect after updated: %d\n", ret);
error = error ? error : ret;
}
mutex_unlock(&cyapa->state_sync_lock);
return error ? error : count;
}
static ssize_t cyapa_calibrate_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
if (cyapa->operational) {
cyapa_enable_irq_for_cmd(cyapa);
error = cyapa->ops->calibrate_store(dev, attr, buf, count);
cyapa_disable_irq_for_cmd(cyapa);
} else {
error = -EBUSY;
}
mutex_unlock(&cyapa->state_sync_lock);
return error < 0 ? error : count;
}
static ssize_t cyapa_show_baseline(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
ssize_t error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
if (cyapa->operational) {
cyapa_enable_irq_for_cmd(cyapa);
error = cyapa->ops->show_baseline(dev, attr, buf);
cyapa_disable_irq_for_cmd(cyapa);
} else {
error = -EBUSY;
}
mutex_unlock(&cyapa->state_sync_lock);
return error;
}
static char *cyapa_state_to_string(struct cyapa *cyapa)
{
switch (cyapa->state) {
case CYAPA_STATE_BL_BUSY:
return "bootloader busy";
case CYAPA_STATE_BL_IDLE:
return "bootloader idle";
case CYAPA_STATE_BL_ACTIVE:
return "bootloader active";
case CYAPA_STATE_GEN5_BL:
case CYAPA_STATE_GEN6_BL:
return "bootloader";
case CYAPA_STATE_OP:
case CYAPA_STATE_GEN5_APP:
case CYAPA_STATE_GEN6_APP:
return "operational";
default:
return "invalid mode";
}
}
static ssize_t cyapa_show_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int size;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
size = scnprintf(buf, PAGE_SIZE, "gen%d %s\n",
cyapa->gen, cyapa_state_to_string(cyapa));
mutex_unlock(&cyapa->state_sync_lock);
return size;
}
static void cyapa_remove_sysfs_group(void *data)
{
struct cyapa *cyapa = data;
sysfs_remove_group(&cyapa->client->dev.kobj, &cyapa_sysfs_group);
}
static void cyapa_disable_regulator(void *data)
{
struct cyapa *cyapa = data;
regulator_disable(cyapa->vcc);
}
static int cyapa_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
struct device *dev = &client->dev;
struct cyapa *cyapa;
u8 adapter_func;
union i2c_smbus_data dummy;
int error;
adapter_func = cyapa_check_adapter_functionality(client);
if (adapter_func == CYAPA_ADAPTER_FUNC_NONE) {
dev_err(dev, "not a supported I2C/SMBus adapter\n");
return -EIO;
}
if (i2c_smbus_xfer(client->adapter, client->addr, 0,
I2C_SMBUS_READ, 0, I2C_SMBUS_BYTE, &dummy) < 0)
return -ENODEV;
cyapa = devm_kzalloc(dev, sizeof(struct cyapa), GFP_KERNEL);
if (!cyapa)
return -ENOMEM;
if (adapter_func == CYAPA_ADAPTER_FUNC_SMBUS)
cyapa->smbus = true;
cyapa->client = client;
i2c_set_clientdata(client, cyapa);
sprintf(cyapa->phys, "i2c-%d-%04x/input0", client->adapter->nr,
client->addr);
cyapa->vcc = devm_regulator_get(dev, "vcc");
if (IS_ERR(cyapa->vcc)) {
error = PTR_ERR(cyapa->vcc);
dev_err(dev, "failed to get vcc regulator: %d\n", error);
return error;
}
error = regulator_enable(cyapa->vcc);
if (error) {
dev_err(dev, "failed to enable regulator: %d\n", error);
return error;
}
error = devm_add_action(dev, cyapa_disable_regulator, cyapa);
if (error) {
cyapa_disable_regulator(cyapa);
dev_err(dev, "failed to add disable regulator action: %d\n",
error);
return error;
}
error = cyapa_initialize(cyapa);
if (error) {
dev_err(dev, "failed to detect and initialize tp device.\n");
return error;
}
error = sysfs_create_group(&client->dev.kobj, &cyapa_sysfs_group);
if (error) {
dev_err(dev, "failed to create sysfs entries: %d\n", error);
return error;
}
error = devm_add_action(dev, cyapa_remove_sysfs_group, cyapa);
if (error) {
cyapa_remove_sysfs_group(cyapa);
dev_err(dev, "failed to add sysfs cleanup action: %d\n", error);
return error;
}
error = cyapa_prepare_wakeup_controls(cyapa);
if (error) {
dev_err(dev, "failed to prepare wakeup controls: %d\n", error);
return error;
}
error = cyapa_start_runtime(cyapa);
if (error) {
dev_err(dev, "failed to start pm_runtime: %d\n", error);
return error;
}
error = devm_request_threaded_irq(dev, client->irq,
NULL, cyapa_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"cyapa", cyapa);
if (error) {
dev_err(dev, "failed to request threaded irq: %d\n", error);
return error;
}
disable_irq(client->irq);
if (cyapa->operational) {
error = cyapa_create_input_dev(cyapa);
if (error) {
dev_err(dev, "create input_dev instance failed: %d\n",
error);
return error;
}
}
return 0;
}
static int __maybe_unused cyapa_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct cyapa *cyapa = i2c_get_clientdata(client);
u8 power_mode;
int error;
error = mutex_lock_interruptible(&cyapa->state_sync_lock);
if (error)
return error;
if (pm_runtime_enabled(dev))
pm_runtime_disable(dev);
disable_irq(client->irq);
if (cyapa->operational) {
power_mode = device_may_wakeup(dev) ? cyapa->suspend_power_mode
: PWR_MODE_OFF;
error = cyapa->ops->set_power_mode(cyapa, power_mode,
cyapa->suspend_sleep_time, true);
if (error)
dev_err(dev, "suspend set power mode failed: %d\n",
error);
}
if (cyapa->dev_pwr_mode != PWR_MODE_OFF)
cyapa->ops->set_proximity(cyapa, false);
if (device_may_wakeup(dev))
cyapa->irq_wake = (enable_irq_wake(client->irq) == 0);
mutex_unlock(&cyapa->state_sync_lock);
return 0;
}
static int __maybe_unused cyapa_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct cyapa *cyapa = i2c_get_clientdata(client);
int error;
mutex_lock(&cyapa->state_sync_lock);
if (device_may_wakeup(dev) && cyapa->irq_wake) {
disable_irq_wake(client->irq);
cyapa->irq_wake = false;
}
error = cyapa_reinitialize(cyapa);
if (error)
dev_warn(dev, "failed to reinitialize TP device: %d\n", error);
enable_irq(client->irq);
mutex_unlock(&cyapa->state_sync_lock);
return 0;
}
static int __maybe_unused cyapa_runtime_suspend(struct device *dev)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int error;
error = cyapa->ops->set_power_mode(cyapa,
cyapa->runtime_suspend_power_mode,
cyapa->runtime_suspend_sleep_time,
false);
if (error)
dev_warn(dev, "runtime suspend failed: %d\n", error);
return 0;
}
static int __maybe_unused cyapa_runtime_resume(struct device *dev)
{
struct cyapa *cyapa = dev_get_drvdata(dev);
int error;
error = cyapa->ops->set_power_mode(cyapa,
PWR_MODE_FULL_ACTIVE, 0, false);
if (error)
dev_warn(dev, "runtime resume failed: %d\n", error);
return 0;
}
