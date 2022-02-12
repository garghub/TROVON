static int tsc2005_cmd(struct tsc2005 *ts, u8 cmd)
{
u8 tx = TSC2005_CMD | TSC2005_CMD_12BIT | cmd;
struct spi_transfer xfer = {
.tx_buf = &tx,
.len = 1,
.bits_per_word = 8,
};
struct spi_message msg;
int error;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
error = spi_sync(ts->spi, &msg);
if (error) {
dev_err(&ts->spi->dev, "%s: failed, command: %x, error: %d\n",
__func__, cmd, error);
return error;
}
return 0;
}
static int tsc2005_write(struct tsc2005 *ts, u8 reg, u16 value)
{
u32 tx = ((reg | TSC2005_REG_PND0) << 16) | value;
struct spi_transfer xfer = {
.tx_buf = &tx,
.len = 4,
.bits_per_word = 24,
};
struct spi_message msg;
int error;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
error = spi_sync(ts->spi, &msg);
if (error) {
dev_err(&ts->spi->dev,
"%s: failed, register: %x, value: %x, error: %d\n",
__func__, reg, value, error);
return error;
}
return 0;
}
static void tsc2005_setup_read(struct tsc2005_spi_rd *rd, u8 reg, bool last)
{
memset(rd, 0, sizeof(*rd));
rd->spi_tx = (reg | TSC2005_REG_READ) << 16;
rd->spi_xfer.tx_buf = &rd->spi_tx;
rd->spi_xfer.rx_buf = &rd->spi_rx;
rd->spi_xfer.len = 4;
rd->spi_xfer.bits_per_word = 24;
rd->spi_xfer.cs_change = !last;
}
static int tsc2005_read(struct tsc2005 *ts, u8 reg, u16 *value)
{
struct tsc2005_spi_rd spi_rd;
struct spi_message msg;
int error;
tsc2005_setup_read(&spi_rd, reg, true);
spi_message_init(&msg);
spi_message_add_tail(&spi_rd.spi_xfer, &msg);
error = spi_sync(ts->spi, &msg);
if (error)
return error;
*value = spi_rd.spi_rx;
return 0;
}
static void tsc2005_update_pen_state(struct tsc2005 *ts,
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
dev_dbg(&ts->spi->dev, "point(%4d,%4d), pressure (%4d)\n", x, y,
pressure);
}
static irqreturn_t tsc2005_irq_thread(int irq, void *_ts)
{
struct tsc2005 *ts = _ts;
unsigned long flags;
unsigned int pressure;
u32 x, y;
u32 z1, z2;
int error;
error = spi_sync(ts->spi, &ts->spi_read_msg);
if (unlikely(error))
goto out;
x = ts->spi_x.spi_rx;
y = ts->spi_y.spi_rx;
z1 = ts->spi_z1.spi_rx;
z2 = ts->spi_z2.spi_rx;
if (unlikely(x > MAX_12BIT || y > MAX_12BIT))
goto out;
if (unlikely(z1 == 0 || z2 > MAX_12BIT || z1 >= z2))
goto out;
if (!ts->pen_down &&
ts->in_x == x && ts->in_y == y &&
ts->in_z1 == z1 && ts->in_z2 == z2) {
goto out;
}
ts->in_x = x;
ts->in_y = y;
ts->in_z1 = z1;
ts->in_z2 = z2;
pressure = x * (z2 - z1) / z1;
pressure = pressure * ts->x_plate_ohm / 4096;
if (unlikely(pressure > MAX_12BIT))
goto out;
spin_lock_irqsave(&ts->lock, flags);
tsc2005_update_pen_state(ts, x, y, pressure);
mod_timer(&ts->penup_timer,
jiffies + msecs_to_jiffies(TSC2005_PENUP_TIME_MS));
spin_unlock_irqrestore(&ts->lock, flags);
ts->last_valid_interrupt = jiffies;
out:
return IRQ_HANDLED;
}
static void tsc2005_penup_timer(unsigned long data)
{
struct tsc2005 *ts = (struct tsc2005 *)data;
unsigned long flags;
spin_lock_irqsave(&ts->lock, flags);
tsc2005_update_pen_state(ts, 0, 0, 0);
spin_unlock_irqrestore(&ts->lock, flags);
}
static void tsc2005_start_scan(struct tsc2005 *ts)
{
tsc2005_write(ts, TSC2005_REG_CFR0, TSC2005_CFR0_INITVALUE);
tsc2005_write(ts, TSC2005_REG_CFR1, TSC2005_CFR1_INITVALUE);
tsc2005_write(ts, TSC2005_REG_CFR2, TSC2005_CFR2_INITVALUE);
tsc2005_cmd(ts, TSC2005_CMD_NORMAL);
}
static void tsc2005_stop_scan(struct tsc2005 *ts)
{
tsc2005_cmd(ts, TSC2005_CMD_STOP);
}
static void __tsc2005_disable(struct tsc2005 *ts)
{
tsc2005_stop_scan(ts);
disable_irq(ts->spi->irq);
del_timer_sync(&ts->penup_timer);
cancel_delayed_work_sync(&ts->esd_work);
enable_irq(ts->spi->irq);
}
static void __tsc2005_enable(struct tsc2005 *ts)
{
tsc2005_start_scan(ts);
if (ts->esd_timeout && ts->set_reset) {
ts->last_valid_interrupt = jiffies;
schedule_delayed_work(&ts->esd_work,
round_jiffies_relative(
msecs_to_jiffies(ts->esd_timeout)));
}
}
static ssize_t tsc2005_selftest_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct spi_device *spi = to_spi_device(dev);
struct tsc2005 *ts = spi_get_drvdata(spi);
u16 temp_high;
u16 temp_high_orig;
u16 temp_high_test;
bool success = true;
int error;
mutex_lock(&ts->mutex);
__tsc2005_disable(ts);
error = tsc2005_read(ts, TSC2005_REG_TEMP_HIGH, &temp_high_orig);
if (error) {
dev_warn(dev, "selftest failed: read error %d\n", error);
success = false;
goto out;
}
temp_high_test = (temp_high_orig - 1) & MAX_12BIT;
error = tsc2005_write(ts, TSC2005_REG_TEMP_HIGH, temp_high_test);
if (error) {
dev_warn(dev, "selftest failed: write error %d\n", error);
success = false;
goto out;
}
error = tsc2005_read(ts, TSC2005_REG_TEMP_HIGH, &temp_high);
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
ts->set_reset(false);
usleep_range(100, 500);
ts->set_reset(true);
if (!success)
goto out;
error = tsc2005_read(ts, TSC2005_REG_TEMP_HIGH, &temp_high);
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
__tsc2005_enable(ts);
mutex_unlock(&ts->mutex);
return sprintf(buf, "%d\n", success);
}
static umode_t tsc2005_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct spi_device *spi = to_spi_device(dev);
struct tsc2005 *ts = spi_get_drvdata(spi);
umode_t mode = attr->mode;
if (attr == &dev_attr_selftest.attr) {
if (!ts->set_reset)
mode = 0;
}
return mode;
}
static void tsc2005_esd_work(struct work_struct *work)
{
struct tsc2005 *ts = container_of(work, struct tsc2005, esd_work.work);
int error;
u16 r;
if (!mutex_trylock(&ts->mutex)) {
goto reschedule;
}
if (time_is_after_jiffies(ts->last_valid_interrupt +
msecs_to_jiffies(ts->esd_timeout)))
goto out;
error = tsc2005_read(ts, TSC2005_REG_CFR0, &r);
if (!error &&
!((r ^ TSC2005_CFR0_INITVALUE) & TSC2005_CFR0_RW_MASK)) {
goto out;
}
dev_info(&ts->spi->dev, "TSC2005 not responding - resetting\n");
disable_irq(ts->spi->irq);
del_timer_sync(&ts->penup_timer);
tsc2005_update_pen_state(ts, 0, 0, 0);
ts->set_reset(false);
usleep_range(100, 500);
ts->set_reset(true);
enable_irq(ts->spi->irq);
tsc2005_start_scan(ts);
out:
mutex_unlock(&ts->mutex);
reschedule:
schedule_delayed_work(&ts->esd_work,
round_jiffies_relative(
msecs_to_jiffies(ts->esd_timeout)));
}
static int tsc2005_open(struct input_dev *input)
{
struct tsc2005 *ts = input_get_drvdata(input);
mutex_lock(&ts->mutex);
if (!ts->suspended)
__tsc2005_enable(ts);
ts->opened = true;
mutex_unlock(&ts->mutex);
return 0;
}
static void tsc2005_close(struct input_dev *input)
{
struct tsc2005 *ts = input_get_drvdata(input);
mutex_lock(&ts->mutex);
if (!ts->suspended)
__tsc2005_disable(ts);
ts->opened = false;
mutex_unlock(&ts->mutex);
}
static void __devinit tsc2005_setup_spi_xfer(struct tsc2005 *ts)
{
tsc2005_setup_read(&ts->spi_x, TSC2005_REG_X, false);
tsc2005_setup_read(&ts->spi_y, TSC2005_REG_Y, false);
tsc2005_setup_read(&ts->spi_z1, TSC2005_REG_Z1, false);
tsc2005_setup_read(&ts->spi_z2, TSC2005_REG_Z2, true);
spi_message_init(&ts->spi_read_msg);
spi_message_add_tail(&ts->spi_x.spi_xfer, &ts->spi_read_msg);
spi_message_add_tail(&ts->spi_y.spi_xfer, &ts->spi_read_msg);
spi_message_add_tail(&ts->spi_z1.spi_xfer, &ts->spi_read_msg);
spi_message_add_tail(&ts->spi_z2.spi_xfer, &ts->spi_read_msg);
}
static int __devinit tsc2005_probe(struct spi_device *spi)
{
const struct tsc2005_platform_data *pdata = spi->dev.platform_data;
struct tsc2005 *ts;
struct input_dev *input_dev;
unsigned int max_x, max_y, max_p;
unsigned int fudge_x, fudge_y, fudge_p;
int error;
if (!pdata) {
dev_dbg(&spi->dev, "no platform data\n");
return -ENODEV;
}
fudge_x = pdata->ts_x_fudge ? : 4;
fudge_y = pdata->ts_y_fudge ? : 8;
fudge_p = pdata->ts_pressure_fudge ? : 2;
max_x = pdata->ts_x_max ? : MAX_12BIT;
max_y = pdata->ts_y_max ? : MAX_12BIT;
max_p = pdata->ts_pressure_max ? : MAX_12BIT;
if (spi->irq <= 0) {
dev_dbg(&spi->dev, "no irq\n");
return -ENODEV;
}
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
if (!spi->max_speed_hz)
spi->max_speed_hz = TSC2005_SPI_MAX_SPEED_HZ;
error = spi_setup(spi);
if (error)
return error;
ts = kzalloc(sizeof(*ts), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ts || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
ts->spi = spi;
ts->idev = input_dev;
ts->x_plate_ohm = pdata->ts_x_plate_ohm ? : 280;
ts->esd_timeout = pdata->esd_timeout_ms;
ts->set_reset = pdata->set_reset;
mutex_init(&ts->mutex);
spin_lock_init(&ts->lock);
setup_timer(&ts->penup_timer, tsc2005_penup_timer, (unsigned long)ts);
INIT_DELAYED_WORK(&ts->esd_work, tsc2005_esd_work);
tsc2005_setup_spi_xfer(ts);
snprintf(ts->phys, sizeof(ts->phys),
"%s/input-ts", dev_name(&spi->dev));
input_dev->name = "TSC2005 touchscreen";
input_dev->phys = ts->phys;
input_dev->id.bustype = BUS_SPI;
input_dev->dev.parent = &spi->dev;
input_dev->evbit[0] = BIT(EV_ABS) | BIT(EV_KEY);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, max_x, fudge_x, 0);
input_set_abs_params(input_dev, ABS_Y, 0, max_y, fudge_y, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, max_p, fudge_p, 0);
input_dev->open = tsc2005_open;
input_dev->close = tsc2005_close;
input_set_drvdata(input_dev, ts);
tsc2005_stop_scan(ts);
error = request_threaded_irq(spi->irq, NULL, tsc2005_irq_thread,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"tsc2005", ts);
if (error) {
dev_err(&spi->dev, "Failed to request irq, err: %d\n", error);
goto err_free_mem;
}
spi_set_drvdata(spi, ts);
error = sysfs_create_group(&spi->dev.kobj, &tsc2005_attr_group);
if (error) {
dev_err(&spi->dev,
"Failed to create sysfs attributes, err: %d\n", error);
goto err_clear_drvdata;
}
error = input_register_device(ts->idev);
if (error) {
dev_err(&spi->dev,
"Failed to register input device, err: %d\n", error);
goto err_remove_sysfs;
}
irq_set_irq_wake(spi->irq, 1);
return 0;
err_remove_sysfs:
sysfs_remove_group(&spi->dev.kobj, &tsc2005_attr_group);
err_clear_drvdata:
spi_set_drvdata(spi, NULL);
free_irq(spi->irq, ts);
err_free_mem:
input_free_device(input_dev);
kfree(ts);
return error;
}
static int __devexit tsc2005_remove(struct spi_device *spi)
{
struct tsc2005 *ts = spi_get_drvdata(spi);
sysfs_remove_group(&ts->spi->dev.kobj, &tsc2005_attr_group);
free_irq(ts->spi->irq, ts);
input_unregister_device(ts->idev);
kfree(ts);
spi_set_drvdata(spi, NULL);
return 0;
}
static int tsc2005_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct tsc2005 *ts = spi_get_drvdata(spi);
mutex_lock(&ts->mutex);
if (!ts->suspended && ts->opened)
__tsc2005_disable(ts);
ts->suspended = true;
mutex_unlock(&ts->mutex);
return 0;
}
static int tsc2005_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct tsc2005 *ts = spi_get_drvdata(spi);
mutex_lock(&ts->mutex);
if (ts->suspended && ts->opened)
__tsc2005_enable(ts);
ts->suspended = false;
mutex_unlock(&ts->mutex);
return 0;
}
