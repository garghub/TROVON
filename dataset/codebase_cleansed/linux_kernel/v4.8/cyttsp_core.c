static int ttsp_read_block_data(struct cyttsp *ts, u8 command,
u8 length, void *buf)
{
int error;
int tries;
for (tries = 0; tries < CY_NUM_RETRY; tries++) {
error = ts->bus_ops->read(ts->dev, ts->xfer_buf, command,
length, buf);
if (!error)
return 0;
msleep(CY_DELAY_DFLT);
}
return -EIO;
}
static int ttsp_write_block_data(struct cyttsp *ts, u8 command,
u8 length, void *buf)
{
int error;
int tries;
for (tries = 0; tries < CY_NUM_RETRY; tries++) {
error = ts->bus_ops->write(ts->dev, ts->xfer_buf, command,
length, buf);
if (!error)
return 0;
msleep(CY_DELAY_DFLT);
}
return -EIO;
}
static int ttsp_send_command(struct cyttsp *ts, u8 cmd)
{
return ttsp_write_block_data(ts, CY_REG_BASE, sizeof(cmd), &cmd);
}
static int cyttsp_handshake(struct cyttsp *ts)
{
if (ts->use_hndshk)
return ttsp_send_command(ts,
ts->xy_data.hst_mode ^ CY_HNDSHK_BIT);
return 0;
}
static int cyttsp_load_bl_regs(struct cyttsp *ts)
{
memset(&ts->bl_data, 0, sizeof(ts->bl_data));
ts->bl_data.bl_status = 0x10;
return ttsp_read_block_data(ts, CY_REG_BASE,
sizeof(ts->bl_data), &ts->bl_data);
}
static int cyttsp_exit_bl_mode(struct cyttsp *ts)
{
int error;
u8 bl_cmd[sizeof(bl_command)];
memcpy(bl_cmd, bl_command, sizeof(bl_command));
if (ts->bl_keys)
memcpy(&bl_cmd[sizeof(bl_command) - CY_NUM_BL_KEYS],
ts->bl_keys, CY_NUM_BL_KEYS);
error = ttsp_write_block_data(ts, CY_REG_BASE,
sizeof(bl_cmd), bl_cmd);
if (error)
return error;
msleep(CY_DELAY_DFLT);
error = cyttsp_load_bl_regs(ts);
if (error)
return error;
if (GET_BOOTLOADERMODE(ts->bl_data.bl_status))
return -EIO;
return 0;
}
static int cyttsp_set_operational_mode(struct cyttsp *ts)
{
int error;
error = ttsp_send_command(ts, CY_OPERATE_MODE);
if (error)
return error;
error = ttsp_read_block_data(ts, CY_REG_BASE,
sizeof(ts->xy_data), &ts->xy_data);
if (error)
return error;
error = cyttsp_handshake(ts);
if (error)
return error;
return ts->xy_data.act_dist == CY_ACT_DIST_DFLT ? -EIO : 0;
}
static int cyttsp_set_sysinfo_mode(struct cyttsp *ts)
{
int error;
memset(&ts->sysinfo_data, 0, sizeof(ts->sysinfo_data));
error = ttsp_send_command(ts, CY_SYSINFO_MODE);
if (error)
return error;
msleep(CY_DELAY_DFLT);
error = ttsp_read_block_data(ts, CY_REG_BASE, sizeof(ts->sysinfo_data),
&ts->sysinfo_data);
if (error)
return error;
error = cyttsp_handshake(ts);
if (error)
return error;
if (!ts->sysinfo_data.tts_verh && !ts->sysinfo_data.tts_verl)
return -EIO;
return 0;
}
static int cyttsp_set_sysinfo_regs(struct cyttsp *ts)
{
int retval = 0;
if (ts->act_intrvl != CY_ACT_INTRVL_DFLT ||
ts->tch_tmout != CY_TCH_TMOUT_DFLT ||
ts->lp_intrvl != CY_LP_INTRVL_DFLT) {
u8 intrvl_ray[] = {
ts->act_intrvl,
ts->tch_tmout,
ts->lp_intrvl
};
retval = ttsp_write_block_data(ts, CY_REG_ACT_INTRVL,
sizeof(intrvl_ray), intrvl_ray);
msleep(CY_DELAY_DFLT);
}
return retval;
}
static void cyttsp_hard_reset(struct cyttsp *ts)
{
if (ts->reset_gpio) {
gpiod_set_value_cansleep(ts->reset_gpio, 1);
msleep(CY_DELAY_DFLT);
gpiod_set_value_cansleep(ts->reset_gpio, 0);
msleep(CY_DELAY_DFLT);
}
}
static int cyttsp_soft_reset(struct cyttsp *ts)
{
unsigned long timeout;
int retval;
reinit_completion(&ts->bl_ready);
ts->state = CY_BL_STATE;
enable_irq(ts->irq);
retval = ttsp_send_command(ts, CY_SOFT_RESET_MODE);
if (retval)
goto out;
timeout = wait_for_completion_timeout(&ts->bl_ready,
msecs_to_jiffies(CY_DELAY_DFLT * CY_DELAY_MAX));
retval = timeout ? 0 : -EIO;
out:
ts->state = CY_IDLE_STATE;
disable_irq(ts->irq);
return retval;
}
static int cyttsp_act_dist_setup(struct cyttsp *ts)
{
u8 act_dist_setup = ts->act_dist;
return ttsp_write_block_data(ts, CY_REG_ACT_DIST,
sizeof(act_dist_setup), &act_dist_setup);
}
static void cyttsp_extract_track_ids(struct cyttsp_xydata *xy_data, int *ids)
{
ids[0] = xy_data->touch12_id >> 4;
ids[1] = xy_data->touch12_id & 0xF;
ids[2] = xy_data->touch34_id >> 4;
ids[3] = xy_data->touch34_id & 0xF;
}
static const struct cyttsp_tch *cyttsp_get_tch(struct cyttsp_xydata *xy_data,
int idx)
{
switch (idx) {
case 0:
return &xy_data->tch1;
case 1:
return &xy_data->tch2;
case 2:
return &xy_data->tch3;
case 3:
return &xy_data->tch4;
default:
return NULL;
}
}
static void cyttsp_report_tchdata(struct cyttsp *ts)
{
struct cyttsp_xydata *xy_data = &ts->xy_data;
struct input_dev *input = ts->input;
int num_tch = GET_NUM_TOUCHES(xy_data->tt_stat);
const struct cyttsp_tch *tch;
int ids[CY_MAX_ID];
int i;
DECLARE_BITMAP(used, CY_MAX_ID);
if (IS_LARGE_AREA(xy_data->tt_stat) == 1) {
num_tch = 0;
dev_dbg(ts->dev, "%s: Large area detected\n", __func__);
} else if (num_tch > CY_MAX_FINGER) {
num_tch = 0;
dev_dbg(ts->dev, "%s: Num touch error detected\n", __func__);
} else if (IS_BAD_PKT(xy_data->tt_mode)) {
num_tch = 0;
dev_dbg(ts->dev, "%s: Invalid buffer detected\n", __func__);
}
cyttsp_extract_track_ids(xy_data, ids);
bitmap_zero(used, CY_MAX_ID);
for (i = 0; i < num_tch; i++) {
tch = cyttsp_get_tch(xy_data, i);
input_mt_slot(input, ids[i]);
input_mt_report_slot_state(input, MT_TOOL_FINGER, true);
input_report_abs(input, ABS_MT_POSITION_X, be16_to_cpu(tch->x));
input_report_abs(input, ABS_MT_POSITION_Y, be16_to_cpu(tch->y));
input_report_abs(input, ABS_MT_TOUCH_MAJOR, tch->z);
__set_bit(ids[i], used);
}
for (i = 0; i < CY_MAX_ID; i++) {
if (test_bit(i, used))
continue;
input_mt_slot(input, i);
input_mt_report_slot_state(input, MT_TOOL_FINGER, false);
}
input_sync(input);
}
static irqreturn_t cyttsp_irq(int irq, void *handle)
{
struct cyttsp *ts = handle;
int error;
if (unlikely(ts->state == CY_BL_STATE)) {
complete(&ts->bl_ready);
goto out;
}
error = ttsp_read_block_data(ts, CY_REG_BASE,
sizeof(struct cyttsp_xydata), &ts->xy_data);
if (error)
goto out;
error = cyttsp_handshake(ts);
if (error)
goto out;
if (unlikely(ts->state == CY_IDLE_STATE))
goto out;
if (GET_BOOTLOADERMODE(ts->xy_data.tt_mode)) {
error = cyttsp_exit_bl_mode(ts);
if (error) {
dev_err(ts->dev,
"Could not return to operational mode, err: %d\n",
error);
ts->state = CY_IDLE_STATE;
}
} else {
cyttsp_report_tchdata(ts);
}
out:
return IRQ_HANDLED;
}
static int cyttsp_power_on(struct cyttsp *ts)
{
int error;
error = cyttsp_soft_reset(ts);
if (error)
return error;
error = cyttsp_load_bl_regs(ts);
if (error)
return error;
if (GET_BOOTLOADERMODE(ts->bl_data.bl_status) &&
IS_VALID_APP(ts->bl_data.bl_status)) {
error = cyttsp_exit_bl_mode(ts);
if (error)
return error;
}
if (GET_HSTMODE(ts->bl_data.bl_file) != CY_OPERATE_MODE ||
IS_OPERATIONAL_ERR(ts->bl_data.bl_status)) {
return -ENODEV;
}
error = cyttsp_set_sysinfo_mode(ts);
if (error)
return error;
error = cyttsp_set_sysinfo_regs(ts);
if (error)
return error;
error = cyttsp_set_operational_mode(ts);
if (error)
return error;
error = cyttsp_act_dist_setup(ts);
if (error)
return error;
ts->state = CY_ACTIVE_STATE;
return 0;
}
static int cyttsp_enable(struct cyttsp *ts)
{
int error;
error = ttsp_read_block_data(ts, CY_REG_BASE,
sizeof(ts->xy_data), &ts->xy_data);
if (error)
return error;
if (GET_HSTMODE(ts->xy_data.hst_mode))
return -EIO;
enable_irq(ts->irq);
return 0;
}
static int cyttsp_disable(struct cyttsp *ts)
{
int error;
error = ttsp_send_command(ts, CY_LOW_POWER_MODE);
if (error)
return error;
disable_irq(ts->irq);
return 0;
}
static int __maybe_unused cyttsp_suspend(struct device *dev)
{
struct cyttsp *ts = dev_get_drvdata(dev);
int retval = 0;
mutex_lock(&ts->input->mutex);
if (ts->input->users) {
retval = cyttsp_disable(ts);
if (retval == 0)
ts->suspended = true;
}
mutex_unlock(&ts->input->mutex);
return retval;
}
static int __maybe_unused cyttsp_resume(struct device *dev)
{
struct cyttsp *ts = dev_get_drvdata(dev);
mutex_lock(&ts->input->mutex);
if (ts->input->users)
cyttsp_enable(ts);
ts->suspended = false;
mutex_unlock(&ts->input->mutex);
return 0;
}
static int cyttsp_open(struct input_dev *dev)
{
struct cyttsp *ts = input_get_drvdata(dev);
int retval = 0;
if (!ts->suspended)
retval = cyttsp_enable(ts);
return retval;
}
static void cyttsp_close(struct input_dev *dev)
{
struct cyttsp *ts = input_get_drvdata(dev);
if (!ts->suspended)
cyttsp_disable(ts);
}
static int cyttsp_parse_properties(struct cyttsp *ts)
{
struct device *dev = ts->dev;
u32 dt_value;
int ret;
ts->bl_keys = devm_kzalloc(dev, CY_NUM_BL_KEYS, GFP_KERNEL);
if (!ts->bl_keys)
return -ENOMEM;
ts->use_hndshk = false;
ts->act_dist = CY_ACT_DIST_DFLT;
ts->act_intrvl = CY_ACT_INTRVL_DFLT;
ts->tch_tmout = CY_TCH_TMOUT_DFLT;
ts->lp_intrvl = CY_LP_INTRVL_DFLT;
ret = device_property_read_u8_array(dev, "bootloader-key",
ts->bl_keys, CY_NUM_BL_KEYS);
if (ret) {
dev_err(dev,
"bootloader-key property could not be retrieved\n");
return ret;
}
ts->use_hndshk = device_property_present(dev, "use-handshake");
if (!device_property_read_u32(dev, "active-distance", &dt_value)) {
if (dt_value > 15) {
dev_err(dev, "active-distance (%u) must be [0-15]\n",
dt_value);
return -EINVAL;
}
ts->act_dist &= ~CY_ACT_DIST_MASK;
ts->act_dist |= dt_value;
}
if (!device_property_read_u32(dev, "active-interval-ms", &dt_value)) {
if (dt_value > 255) {
dev_err(dev, "active-interval-ms (%u) must be [0-255]\n",
dt_value);
return -EINVAL;
}
ts->act_intrvl = dt_value;
}
if (!device_property_read_u32(dev, "lowpower-interval-ms", &dt_value)) {
if (dt_value > 2550) {
dev_err(dev, "lowpower-interval-ms (%u) must be [0-2550]\n",
dt_value);
return -EINVAL;
}
ts->lp_intrvl = dt_value / 10;
}
if (!device_property_read_u32(dev, "touch-timeout-ms", &dt_value)) {
if (dt_value > 2550) {
dev_err(dev, "touch-timeout-ms (%u) must be [0-2550]\n",
dt_value);
return -EINVAL;
}
ts->tch_tmout = dt_value / 10;
}
return 0;
}
struct cyttsp *cyttsp_probe(const struct cyttsp_bus_ops *bus_ops,
struct device *dev, int irq, size_t xfer_buf_size)
{
struct cyttsp *ts;
struct input_dev *input_dev;
int error;
ts = devm_kzalloc(dev, sizeof(*ts) + xfer_buf_size, GFP_KERNEL);
if (!ts)
return ERR_PTR(-ENOMEM);
input_dev = devm_input_allocate_device(dev);
if (!input_dev)
return ERR_PTR(-ENOMEM);
ts->dev = dev;
ts->input = input_dev;
ts->bus_ops = bus_ops;
ts->irq = irq;
ts->reset_gpio = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(ts->reset_gpio)) {
error = PTR_ERR(ts->reset_gpio);
dev_err(dev, "Failed to request reset gpio, error %d\n", error);
return ERR_PTR(error);
}
error = cyttsp_parse_properties(ts);
if (error)
return ERR_PTR(error);
init_completion(&ts->bl_ready);
snprintf(ts->phys, sizeof(ts->phys), "%s/input0", dev_name(dev));
input_dev->name = "Cypress TTSP TouchScreen";
input_dev->phys = ts->phys;
input_dev->id.bustype = bus_ops->bustype;
input_dev->dev.parent = ts->dev;
input_dev->open = cyttsp_open;
input_dev->close = cyttsp_close;
input_set_drvdata(input_dev, ts);
input_set_capability(input_dev, EV_ABS, ABS_MT_POSITION_X);
input_set_capability(input_dev, EV_ABS, ABS_MT_POSITION_Y);
touchscreen_parse_properties(input_dev, true, NULL);
error = input_mt_init_slots(input_dev, CY_MAX_ID, 0);
if (error) {
dev_err(dev, "Unable to init MT slots.\n");
return ERR_PTR(error);
}
error = devm_request_threaded_irq(dev, ts->irq, NULL, cyttsp_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"cyttsp", ts);
if (error) {
dev_err(ts->dev, "failed to request IRQ %d, err: %d\n",
ts->irq, error);
return ERR_PTR(error);
}
disable_irq(ts->irq);
cyttsp_hard_reset(ts);
error = cyttsp_power_on(ts);
if (error)
return ERR_PTR(error);
error = input_register_device(input_dev);
if (error) {
dev_err(ts->dev, "failed to register input device: %d\n",
error);
return ERR_PTR(error);
}
return ts;
}
