static void tsc200x_update_pen_state(struct tsc200x *ts,
int x, int y, int pressure)
{
if (pressure) {
input_report_abs(ts->idev, ABS_X, x);
input_report_abs(ts->idev, ABS_Y, y);
input_report_abs(ts->idev, ABS_PRESSURE, pressure);
if (!ts->pen_down) {
input_report_key(ts->idev, BTN_TOUCH, !!pressure);
ts->pen_down = true;
}
} else {
input_report_abs(ts->idev, ABS_PRESSURE, 0);
if (ts->pen_down) {
input_report_key(ts->idev, BTN_TOUCH, 0);
ts->pen_down = false;
}
}
input_sync(ts->idev);
dev_dbg(ts->dev, "point(%4d,%4d), pressure (%4d)\n", x, y,
pressure);
}
static irqreturn_t tsc200x_irq_thread(int irq, void *_ts)
{
struct tsc200x *ts = _ts;
unsigned long flags;
unsigned int pressure;
struct tsc200x_data tsdata;
int error;
error = regmap_bulk_read(ts->regmap, TSC200X_REG_X, &tsdata,
TSC200X_DATA_REGS);
if (unlikely(error))
goto out;
if (unlikely(tsdata.x > MAX_12BIT || tsdata.y > MAX_12BIT))
goto out;
if (unlikely(tsdata.z1 == 0 || tsdata.z2 > MAX_12BIT))
goto out;
if (unlikely(tsdata.z1 >= tsdata.z2))
goto out;
if (!ts->pen_down &&
ts->in_x == tsdata.x && ts->in_y == tsdata.y &&
ts->in_z1 == tsdata.z1 && ts->in_z2 == tsdata.z2) {
goto out;
}
ts->in_x = tsdata.x;
ts->in_y = tsdata.y;
ts->in_z1 = tsdata.z1;
ts->in_z2 = tsdata.z2;
pressure = tsdata.x * (tsdata.z2 - tsdata.z1) / tsdata.z1;
pressure = pressure * ts->x_plate_ohm / 4096;
if (unlikely(pressure > MAX_12BIT))
goto out;
spin_lock_irqsave(&ts->lock, flags);
tsc200x_update_pen_state(ts, tsdata.x, tsdata.y, pressure);
mod_timer(&ts->penup_timer,
jiffies + msecs_to_jiffies(TSC200X_PENUP_TIME_MS));
spin_unlock_irqrestore(&ts->lock, flags);
ts->last_valid_interrupt = jiffies;
out:
return IRQ_HANDLED;
}
static void tsc200x_penup_timer(unsigned long data)
{
struct tsc200x *ts = (struct tsc200x *)data;
unsigned long flags;
spin_lock_irqsave(&ts->lock, flags);
tsc200x_update_pen_state(ts, 0, 0, 0);
spin_unlock_irqrestore(&ts->lock, flags);
}
static void tsc200x_start_scan(struct tsc200x *ts)
{
regmap_write(ts->regmap, TSC200X_REG_CFR0, TSC200X_CFR0_INITVALUE);
regmap_write(ts->regmap, TSC200X_REG_CFR1, TSC200X_CFR1_INITVALUE);
regmap_write(ts->regmap, TSC200X_REG_CFR2, TSC200X_CFR2_INITVALUE);
ts->tsc200x_cmd(ts->dev, TSC200X_CMD_NORMAL);
}
static void tsc200x_stop_scan(struct tsc200x *ts)
{
ts->tsc200x_cmd(ts->dev, TSC200X_CMD_STOP);
}
static void tsc200x_reset(struct tsc200x *ts)
{
if (ts->reset_gpio) {
gpiod_set_value_cansleep(ts->reset_gpio, 1);
usleep_range(100, 500);
gpiod_set_value_cansleep(ts->reset_gpio, 0);
}
}
static void __tsc200x_disable(struct tsc200x *ts)
{
tsc200x_stop_scan(ts);
disable_irq(ts->irq);
del_timer_sync(&ts->penup_timer);
cancel_delayed_work_sync(&ts->esd_work);
enable_irq(ts->irq);
}
static void __tsc200x_enable(struct tsc200x *ts)
{
tsc200x_start_scan(ts);
if (ts->esd_timeout && ts->reset_gpio) {
ts->last_valid_interrupt = jiffies;
schedule_delayed_work(&ts->esd_work,
round_jiffies_relative(
msecs_to_jiffies(ts->esd_timeout)));
}
}
static ssize_t tsc200x_selftest_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct tsc200x *ts = dev_get_drvdata(dev);
unsigned int temp_high;
unsigned int temp_high_orig;
unsigned int temp_high_test;
bool success = true;
int error;
mutex_lock(&ts->mutex);
__tsc200x_disable(ts);
error = regmap_read(ts->regmap, TSC200X_REG_TEMP_HIGH, &temp_high_orig);
if (error) {
dev_warn(dev, "selftest failed: read error %d\n", error);
success = false;
goto out;
}
temp_high_test = (temp_high_orig - 1) & MAX_12BIT;
error = regmap_write(ts->regmap, TSC200X_REG_TEMP_HIGH, temp_high_test);
if (error) {
dev_warn(dev, "selftest failed: write error %d\n", error);
success = false;
goto out;
}
error = regmap_read(ts->regmap, TSC200X_REG_TEMP_HIGH, &temp_high);
if (error) {
dev_warn(dev, "selftest failed: read error %d after write\n",
error);
success = false;
goto out;
}
if (temp_high != temp_high_test) {
dev_warn(dev, "selftest failed: %d != %d\n",
temp_high, temp_high_test);
success = false;
}
tsc200x_reset(ts);
if (!success)
goto out;
error = regmap_read(ts->regmap, TSC200X_REG_TEMP_HIGH, &temp_high);
if (error) {
dev_warn(dev, "selftest failed: read error %d after reset\n",
error);
success = false;
goto out;
}
if (temp_high != temp_high_orig) {
dev_warn(dev, "selftest failed after reset: %d != %d\n",
temp_high, temp_high_orig);
success = false;
}
out:
__tsc200x_enable(ts);
mutex_unlock(&ts->mutex);
return sprintf(buf, "%d\n", success);
}
static umode_t tsc200x_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct tsc200x *ts = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (attr == &dev_attr_selftest.attr) {
if (!ts->reset_gpio)
mode = 0;
}
return mode;
}
static void tsc200x_esd_work(struct work_struct *work)
{
struct tsc200x *ts = container_of(work, struct tsc200x, esd_work.work);
int error;
unsigned int r;
if (!mutex_trylock(&ts->mutex)) {
goto reschedule;
}
if (time_is_after_jiffies(ts->last_valid_interrupt +
msecs_to_jiffies(ts->esd_timeout)))
goto out;
error = regmap_read(ts->regmap, TSC200X_REG_CFR0, &r);
if (!error &&
!((r ^ TSC200X_CFR0_INITVALUE) & TSC200X_CFR0_RW_MASK)) {
goto out;
}
dev_info(ts->dev, "TSC200X not responding - resetting\n");
disable_irq(ts->irq);
del_timer_sync(&ts->penup_timer);
tsc200x_update_pen_state(ts, 0, 0, 0);
tsc200x_reset(ts);
enable_irq(ts->irq);
tsc200x_start_scan(ts);
out:
mutex_unlock(&ts->mutex);
reschedule:
schedule_delayed_work(&ts->esd_work,
round_jiffies_relative(
msecs_to_jiffies(ts->esd_timeout)));
}
static int tsc200x_open(struct input_dev *input)
{
struct tsc200x *ts = input_get_drvdata(input);
mutex_lock(&ts->mutex);
if (!ts->suspended)
__tsc200x_enable(ts);
ts->opened = true;
mutex_unlock(&ts->mutex);
return 0;
}
static void tsc200x_close(struct input_dev *input)
{
struct tsc200x *ts = input_get_drvdata(input);
mutex_lock(&ts->mutex);
if (!ts->suspended)
__tsc200x_disable(ts);
ts->opened = false;
mutex_unlock(&ts->mutex);
}
int tsc200x_probe(struct device *dev, int irq, const struct input_id *tsc_id,
struct regmap *regmap,
int (*tsc200x_cmd)(struct device *dev, u8 cmd))
{
struct tsc200x *ts;
struct input_dev *input_dev;
u32 x_plate_ohm;
u32 esd_timeout;
int error;
if (irq <= 0) {
dev_err(dev, "no irq\n");
return -ENODEV;
}
if (IS_ERR(regmap))
return PTR_ERR(regmap);
if (!tsc200x_cmd) {
dev_err(dev, "no cmd function\n");
return -ENODEV;
}
ts = devm_kzalloc(dev, sizeof(*ts), GFP_KERNEL);
if (!ts)
return -ENOMEM;
input_dev = devm_input_allocate_device(dev);
if (!input_dev)
return -ENOMEM;
ts->irq = irq;
ts->dev = dev;
ts->idev = input_dev;
ts->regmap = regmap;
ts->tsc200x_cmd = tsc200x_cmd;
error = device_property_read_u32(dev, "ti,x-plate-ohms", &x_plate_ohm);
ts->x_plate_ohm = error ? TSC200X_DEF_RESISTOR : x_plate_ohm;
error = device_property_read_u32(dev, "ti,esd-recovery-timeout-ms",
&esd_timeout);
ts->esd_timeout = error ? 0 : esd_timeout;
ts->reset_gpio = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(ts->reset_gpio)) {
error = PTR_ERR(ts->reset_gpio);
dev_err(dev, "error acquiring reset gpio: %d\n", error);
return error;
}
ts->vio = devm_regulator_get(dev, "vio");
if (IS_ERR(ts->vio)) {
error = PTR_ERR(ts->vio);
dev_err(dev, "error acquiring vio regulator: %d", error);
return error;
}
mutex_init(&ts->mutex);
spin_lock_init(&ts->lock);
setup_timer(&ts->penup_timer, tsc200x_penup_timer, (unsigned long)ts);
INIT_DELAYED_WORK(&ts->esd_work, tsc200x_esd_work);
snprintf(ts->phys, sizeof(ts->phys),
"%s/input-ts", dev_name(dev));
if (tsc_id->product == 2004) {
input_dev->name = "TSC200X touchscreen";
} else {
input_dev->name = devm_kasprintf(dev, GFP_KERNEL,
"TSC%04d touchscreen",
tsc_id->product);
if (!input_dev->name)
return -ENOMEM;
}
input_dev->phys = ts->phys;
input_dev->id = *tsc_id;
input_dev->open = tsc200x_open;
input_dev->close = tsc200x_close;
input_set_drvdata(input_dev, ts);
__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
input_set_capability(input_dev, EV_KEY, BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X,
0, MAX_12BIT, TSC200X_DEF_X_FUZZ, 0);
input_set_abs_params(input_dev, ABS_Y,
0, MAX_12BIT, TSC200X_DEF_Y_FUZZ, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, MAX_12BIT, TSC200X_DEF_P_FUZZ, 0);
touchscreen_parse_properties(input_dev, false, NULL);
tsc200x_stop_scan(ts);
error = devm_request_threaded_irq(dev, irq, NULL,
tsc200x_irq_thread,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"tsc200x", ts);
if (error) {
dev_err(dev, "Failed to request irq, err: %d\n", error);
return error;
}
error = regulator_enable(ts->vio);
if (error)
return error;
dev_set_drvdata(dev, ts);
error = sysfs_create_group(&dev->kobj, &tsc200x_attr_group);
if (error) {
dev_err(dev,
"Failed to create sysfs attributes, err: %d\n", error);
goto disable_regulator;
}
error = input_register_device(ts->idev);
if (error) {
dev_err(dev,
"Failed to register input device, err: %d\n", error);
goto err_remove_sysfs;
}
irq_set_irq_wake(irq, 1);
return 0;
err_remove_sysfs:
sysfs_remove_group(&dev->kobj, &tsc200x_attr_group);
disable_regulator:
regulator_disable(ts->vio);
return error;
}
int tsc200x_remove(struct device *dev)
{
struct tsc200x *ts = dev_get_drvdata(dev);
sysfs_remove_group(&dev->kobj, &tsc200x_attr_group);
regulator_disable(ts->vio);
return 0;
}
static int __maybe_unused tsc200x_suspend(struct device *dev)
{
struct tsc200x *ts = dev_get_drvdata(dev);
mutex_lock(&ts->mutex);
if (!ts->suspended && ts->opened)
__tsc200x_disable(ts);
ts->suspended = true;
mutex_unlock(&ts->mutex);
return 0;
}
static int __maybe_unused tsc200x_resume(struct device *dev)
{
struct tsc200x *ts = dev_get_drvdata(dev);
mutex_lock(&ts->mutex);
if (ts->suspended && ts->opened)
__tsc200x_enable(ts);
ts->suspended = false;
mutex_unlock(&ts->mutex);
return 0;
}
