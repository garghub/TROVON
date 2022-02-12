static void adxl34x_get_triple(struct adxl34x *ac, struct axis_triple *axis)
{
short buf[3];
ac->bops->read_block(ac->dev, DATAX0, DATAZ1 - DATAX0 + 1, buf);
mutex_lock(&ac->mutex);
ac->saved.x = (s16) le16_to_cpu(buf[0]);
axis->x = ac->saved.x;
ac->saved.y = (s16) le16_to_cpu(buf[1]);
axis->y = ac->saved.y;
ac->saved.z = (s16) le16_to_cpu(buf[2]);
axis->z = ac->saved.z;
mutex_unlock(&ac->mutex);
}
static void adxl34x_service_ev_fifo(struct adxl34x *ac)
{
struct adxl34x_platform_data *pdata = &ac->pdata;
struct axis_triple axis;
adxl34x_get_triple(ac, &axis);
input_event(ac->input, pdata->ev_type, pdata->ev_code_x,
axis.x - ac->swcal.x);
input_event(ac->input, pdata->ev_type, pdata->ev_code_y,
axis.y - ac->swcal.y);
input_event(ac->input, pdata->ev_type, pdata->ev_code_z,
axis.z - ac->swcal.z);
}
static void adxl34x_report_key_single(struct input_dev *input, int key)
{
input_report_key(input, key, true);
input_sync(input);
input_report_key(input, key, false);
}
static void adxl34x_send_key_events(struct adxl34x *ac,
struct adxl34x_platform_data *pdata, int status, int press)
{
int i;
for (i = ADXL_X_AXIS; i <= ADXL_Z_AXIS; i++) {
if (status & (1 << (ADXL_Z_AXIS - i)))
input_report_key(ac->input,
pdata->ev_code_tap[i], press);
}
}
static void adxl34x_do_tap(struct adxl34x *ac,
struct adxl34x_platform_data *pdata, int status)
{
adxl34x_send_key_events(ac, pdata, status, true);
input_sync(ac->input);
adxl34x_send_key_events(ac, pdata, status, false);
}
static irqreturn_t adxl34x_irq(int irq, void *handle)
{
struct adxl34x *ac = handle;
struct adxl34x_platform_data *pdata = &ac->pdata;
int int_stat, tap_stat, samples, orient, orient_code;
if (pdata->tap_axis_control & (TAP_X_EN | TAP_Y_EN | TAP_Z_EN))
tap_stat = AC_READ(ac, ACT_TAP_STATUS);
else
tap_stat = 0;
int_stat = AC_READ(ac, INT_SOURCE);
if (int_stat & FREE_FALL)
adxl34x_report_key_single(ac->input, pdata->ev_code_ff);
if (int_stat & OVERRUN)
dev_dbg(ac->dev, "OVERRUN\n");
if (int_stat & (SINGLE_TAP | DOUBLE_TAP)) {
adxl34x_do_tap(ac, pdata, tap_stat);
if (int_stat & DOUBLE_TAP)
adxl34x_do_tap(ac, pdata, tap_stat);
}
if (pdata->ev_code_act_inactivity) {
if (int_stat & ACTIVITY)
input_report_key(ac->input,
pdata->ev_code_act_inactivity, 1);
if (int_stat & INACTIVITY)
input_report_key(ac->input,
pdata->ev_code_act_inactivity, 0);
}
if (pdata->orientation_enable) {
orient = AC_READ(ac, ORIENT);
if ((pdata->orientation_enable & ADXL_EN_ORIENTATION_2D) &&
(orient & ADXL346_2D_VALID)) {
orient_code = ADXL346_2D_ORIENT(orient);
if (ac->orient2d_saved != orient_code) {
ac->orient2d_saved = orient_code;
adxl34x_report_key_single(ac->input,
pdata->ev_codes_orient_2d[orient_code]);
}
}
if ((pdata->orientation_enable & ADXL_EN_ORIENTATION_3D) &&
(orient & ADXL346_3D_VALID)) {
orient_code = ADXL346_3D_ORIENT(orient) - 1;
if (ac->orient3d_saved != orient_code) {
ac->orient3d_saved = orient_code;
adxl34x_report_key_single(ac->input,
pdata->ev_codes_orient_3d[orient_code]);
}
}
}
if (int_stat & (DATA_READY | WATERMARK)) {
if (pdata->fifo_mode)
samples = ENTRIES(AC_READ(ac, FIFO_STATUS)) + 1;
else
samples = 1;
for (; samples > 0; samples--) {
adxl34x_service_ev_fifo(ac);
if (ac->fifo_delay && (samples > 1))
udelay(3);
}
}
input_sync(ac->input);
return IRQ_HANDLED;
}
static void __adxl34x_disable(struct adxl34x *ac)
{
AC_WRITE(ac, POWER_CTL, 0);
}
static void __adxl34x_enable(struct adxl34x *ac)
{
AC_WRITE(ac, POWER_CTL, ac->pdata.power_mode | PCTL_MEASURE);
}
void adxl34x_suspend(struct adxl34x *ac)
{
mutex_lock(&ac->mutex);
if (!ac->suspended && !ac->disabled && ac->opened)
__adxl34x_disable(ac);
ac->suspended = true;
mutex_unlock(&ac->mutex);
}
void adxl34x_resume(struct adxl34x *ac)
{
mutex_lock(&ac->mutex);
if (ac->suspended && !ac->disabled && ac->opened)
__adxl34x_enable(ac);
ac->suspended = false;
mutex_unlock(&ac->mutex);
}
static ssize_t adxl34x_disable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adxl34x *ac = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ac->disabled);
}
static ssize_t adxl34x_disable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adxl34x *ac = dev_get_drvdata(dev);
unsigned long val;
int error;
error = strict_strtoul(buf, 10, &val);
if (error)
return error;
mutex_lock(&ac->mutex);
if (!ac->suspended && ac->opened) {
if (val) {
if (!ac->disabled)
__adxl34x_disable(ac);
} else {
if (ac->disabled)
__adxl34x_enable(ac);
}
}
ac->disabled = !!val;
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_calibrate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adxl34x *ac = dev_get_drvdata(dev);
ssize_t count;
mutex_lock(&ac->mutex);
count = sprintf(buf, "%d,%d,%d\n",
ac->hwcal.x * 4 + ac->swcal.x,
ac->hwcal.y * 4 + ac->swcal.y,
ac->hwcal.z * 4 + ac->swcal.z);
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_calibrate_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adxl34x *ac = dev_get_drvdata(dev);
mutex_lock(&ac->mutex);
ac->hwcal.x -= (ac->saved.x / 4);
ac->swcal.x = ac->saved.x % 4;
ac->hwcal.y -= (ac->saved.y / 4);
ac->swcal.y = ac->saved.y % 4;
ac->hwcal.z -= (ac->saved.z / 4);
ac->swcal.z = ac->saved.z % 4;
AC_WRITE(ac, OFSX, (s8) ac->hwcal.x);
AC_WRITE(ac, OFSY, (s8) ac->hwcal.y);
AC_WRITE(ac, OFSZ, (s8) ac->hwcal.z);
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_rate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adxl34x *ac = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", RATE(ac->pdata.data_rate));
}
static ssize_t adxl34x_rate_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adxl34x *ac = dev_get_drvdata(dev);
unsigned long val;
int error;
error = strict_strtoul(buf, 10, &val);
if (error)
return error;
mutex_lock(&ac->mutex);
ac->pdata.data_rate = RATE(val);
AC_WRITE(ac, BW_RATE,
ac->pdata.data_rate |
(ac->pdata.low_power_mode ? LOW_POWER : 0));
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_autosleep_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adxl34x *ac = dev_get_drvdata(dev);
return sprintf(buf, "%u\n",
ac->pdata.power_mode & (PCTL_AUTO_SLEEP | PCTL_LINK) ? 1 : 0);
}
static ssize_t adxl34x_autosleep_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adxl34x *ac = dev_get_drvdata(dev);
unsigned long val;
int error;
error = strict_strtoul(buf, 10, &val);
if (error)
return error;
mutex_lock(&ac->mutex);
if (val)
ac->pdata.power_mode |= (PCTL_AUTO_SLEEP | PCTL_LINK);
else
ac->pdata.power_mode &= ~(PCTL_AUTO_SLEEP | PCTL_LINK);
if (!ac->disabled && !ac->suspended && ac->opened)
AC_WRITE(ac, POWER_CTL, ac->pdata.power_mode | PCTL_MEASURE);
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_position_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adxl34x *ac = dev_get_drvdata(dev);
ssize_t count;
mutex_lock(&ac->mutex);
count = sprintf(buf, "(%d, %d, %d)\n",
ac->saved.x, ac->saved.y, ac->saved.z);
mutex_unlock(&ac->mutex);
return count;
}
static ssize_t adxl34x_write_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adxl34x *ac = dev_get_drvdata(dev);
unsigned long val;
int error;
error = strict_strtoul(buf, 16, &val);
if (error)
return error;
mutex_lock(&ac->mutex);
AC_WRITE(ac, val >> 8, val & 0xFF);
mutex_unlock(&ac->mutex);
return count;
}
static int adxl34x_input_open(struct input_dev *input)
{
struct adxl34x *ac = input_get_drvdata(input);
mutex_lock(&ac->mutex);
if (!ac->suspended && !ac->disabled)
__adxl34x_enable(ac);
ac->opened = true;
mutex_unlock(&ac->mutex);
return 0;
}
static void adxl34x_input_close(struct input_dev *input)
{
struct adxl34x *ac = input_get_drvdata(input);
mutex_lock(&ac->mutex);
if (!ac->suspended && !ac->disabled)
__adxl34x_disable(ac);
ac->opened = false;
mutex_unlock(&ac->mutex);
}
struct adxl34x *adxl34x_probe(struct device *dev, int irq,
bool fifo_delay_default,
const struct adxl34x_bus_ops *bops)
{
struct adxl34x *ac;
struct input_dev *input_dev;
const struct adxl34x_platform_data *pdata;
int err, range, i;
unsigned char revid;
if (!irq) {
dev_err(dev, "no IRQ?\n");
err = -ENODEV;
goto err_out;
}
ac = kzalloc(sizeof(*ac), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ac || !input_dev) {
err = -ENOMEM;
goto err_free_mem;
}
ac->fifo_delay = fifo_delay_default;
pdata = dev->platform_data;
if (!pdata) {
dev_dbg(dev,
"No platform data: Using default initialization\n");
pdata = &adxl34x_default_init;
}
ac->pdata = *pdata;
pdata = &ac->pdata;
ac->input = input_dev;
ac->dev = dev;
ac->irq = irq;
ac->bops = bops;
mutex_init(&ac->mutex);
input_dev->name = "ADXL34x accelerometer";
revid = ac->bops->read(dev, DEVID);
switch (revid) {
case ID_ADXL345:
ac->model = 345;
break;
case ID_ADXL346:
ac->model = 346;
break;
default:
dev_err(dev, "Failed to probe %s\n", input_dev->name);
err = -ENODEV;
goto err_free_mem;
}
snprintf(ac->phys, sizeof(ac->phys), "%s/input0", dev_name(dev));
input_dev->phys = ac->phys;
input_dev->dev.parent = dev;
input_dev->id.product = ac->model;
input_dev->id.bustype = bops->bustype;
input_dev->open = adxl34x_input_open;
input_dev->close = adxl34x_input_close;
input_set_drvdata(input_dev, ac);
__set_bit(ac->pdata.ev_type, input_dev->evbit);
if (ac->pdata.ev_type == EV_REL) {
__set_bit(REL_X, input_dev->relbit);
__set_bit(REL_Y, input_dev->relbit);
__set_bit(REL_Z, input_dev->relbit);
} else {
__set_bit(ABS_X, input_dev->absbit);
__set_bit(ABS_Y, input_dev->absbit);
__set_bit(ABS_Z, input_dev->absbit);
if (pdata->data_range & FULL_RES)
range = ADXL_FULLRES_MAX_VAL;
else
range = ADXL_FIXEDRES_MAX_VAL;
input_set_abs_params(input_dev, ABS_X, -range, range, 3, 3);
input_set_abs_params(input_dev, ABS_Y, -range, range, 3, 3);
input_set_abs_params(input_dev, ABS_Z, -range, range, 3, 3);
}
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(pdata->ev_code_tap[ADXL_X_AXIS], input_dev->keybit);
__set_bit(pdata->ev_code_tap[ADXL_Y_AXIS], input_dev->keybit);
__set_bit(pdata->ev_code_tap[ADXL_Z_AXIS], input_dev->keybit);
if (pdata->ev_code_ff) {
ac->int_mask = FREE_FALL;
__set_bit(pdata->ev_code_ff, input_dev->keybit);
}
if (pdata->ev_code_act_inactivity)
__set_bit(pdata->ev_code_act_inactivity, input_dev->keybit);
ac->int_mask |= ACTIVITY | INACTIVITY;
if (pdata->watermark) {
ac->int_mask |= WATERMARK;
if (!FIFO_MODE(pdata->fifo_mode))
ac->pdata.fifo_mode |= FIFO_STREAM;
} else {
ac->int_mask |= DATA_READY;
}
if (pdata->tap_axis_control & (TAP_X_EN | TAP_Y_EN | TAP_Z_EN))
ac->int_mask |= SINGLE_TAP | DOUBLE_TAP;
if (FIFO_MODE(pdata->fifo_mode) == FIFO_BYPASS)
ac->fifo_delay = false;
ac->bops->write(dev, POWER_CTL, 0);
err = request_threaded_irq(ac->irq, NULL, adxl34x_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
dev_name(dev), ac);
if (err) {
dev_err(dev, "irq %d busy?\n", ac->irq);
goto err_free_mem;
}
err = sysfs_create_group(&dev->kobj, &adxl34x_attr_group);
if (err)
goto err_free_irq;
err = input_register_device(input_dev);
if (err)
goto err_remove_attr;
AC_WRITE(ac, THRESH_TAP, pdata->tap_threshold);
AC_WRITE(ac, OFSX, pdata->x_axis_offset);
ac->hwcal.x = pdata->x_axis_offset;
AC_WRITE(ac, OFSY, pdata->y_axis_offset);
ac->hwcal.y = pdata->y_axis_offset;
AC_WRITE(ac, OFSZ, pdata->z_axis_offset);
ac->hwcal.z = pdata->z_axis_offset;
AC_WRITE(ac, THRESH_TAP, pdata->tap_threshold);
AC_WRITE(ac, DUR, pdata->tap_duration);
AC_WRITE(ac, LATENT, pdata->tap_latency);
AC_WRITE(ac, WINDOW, pdata->tap_window);
AC_WRITE(ac, THRESH_ACT, pdata->activity_threshold);
AC_WRITE(ac, THRESH_INACT, pdata->inactivity_threshold);
AC_WRITE(ac, TIME_INACT, pdata->inactivity_time);
AC_WRITE(ac, THRESH_FF, pdata->free_fall_threshold);
AC_WRITE(ac, TIME_FF, pdata->free_fall_time);
AC_WRITE(ac, TAP_AXES, pdata->tap_axis_control);
AC_WRITE(ac, ACT_INACT_CTL, pdata->act_axis_control);
AC_WRITE(ac, BW_RATE, RATE(ac->pdata.data_rate) |
(pdata->low_power_mode ? LOW_POWER : 0));
AC_WRITE(ac, DATA_FORMAT, pdata->data_range);
AC_WRITE(ac, FIFO_CTL, FIFO_MODE(pdata->fifo_mode) |
SAMPLES(pdata->watermark));
if (pdata->use_int2) {
AC_WRITE(ac, INT_MAP, ac->int_mask | OVERRUN);
} else {
AC_WRITE(ac, INT_MAP, 0);
}
if (ac->model == 346 && ac->pdata.orientation_enable) {
AC_WRITE(ac, ORIENT_CONF,
ORIENT_DEADZONE(ac->pdata.deadzone_angle) |
ORIENT_DIVISOR(ac->pdata.divisor_length));
ac->orient2d_saved = 1234;
ac->orient3d_saved = 1234;
if (pdata->orientation_enable & ADXL_EN_ORIENTATION_3D)
for (i = 0; i < ARRAY_SIZE(pdata->ev_codes_orient_3d); i++)
__set_bit(pdata->ev_codes_orient_3d[i],
input_dev->keybit);
if (pdata->orientation_enable & ADXL_EN_ORIENTATION_2D)
for (i = 0; i < ARRAY_SIZE(pdata->ev_codes_orient_2d); i++)
__set_bit(pdata->ev_codes_orient_2d[i],
input_dev->keybit);
} else {
ac->pdata.orientation_enable = 0;
}
AC_WRITE(ac, INT_ENABLE, ac->int_mask | OVERRUN);
ac->pdata.power_mode &= (PCTL_AUTO_SLEEP | PCTL_LINK);
return ac;
err_remove_attr:
sysfs_remove_group(&dev->kobj, &adxl34x_attr_group);
err_free_irq:
free_irq(ac->irq, ac);
err_free_mem:
input_free_device(input_dev);
kfree(ac);
err_out:
return ERR_PTR(err);
}
int adxl34x_remove(struct adxl34x *ac)
{
sysfs_remove_group(&ac->dev->kobj, &adxl34x_attr_group);
free_irq(ac->irq, ac);
input_unregister_device(ac->input);
dev_dbg(ac->dev, "unregistered accelerometer\n");
kfree(ac);
return 0;
}
