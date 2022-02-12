static const struct zpa2326_frequency *zpa2326_highest_frequency(void)
{
return &zpa2326_sampling_frequencies[
ARRAY_SIZE(zpa2326_sampling_frequencies) - 1];
}
bool zpa2326_isreg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case ZPA2326_REF_P_XL_REG:
case ZPA2326_REF_P_L_REG:
case ZPA2326_REF_P_H_REG:
case ZPA2326_RES_CONF_REG:
case ZPA2326_CTRL_REG0_REG:
case ZPA2326_CTRL_REG1_REG:
case ZPA2326_CTRL_REG2_REG:
case ZPA2326_CTRL_REG3_REG:
case ZPA2326_THS_P_LOW_REG:
case ZPA2326_THS_P_HIGH_REG:
return true;
default:
return false;
}
}
bool zpa2326_isreg_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case ZPA2326_REF_P_XL_REG:
case ZPA2326_REF_P_L_REG:
case ZPA2326_REF_P_H_REG:
case ZPA2326_DEVICE_ID_REG:
case ZPA2326_RES_CONF_REG:
case ZPA2326_CTRL_REG0_REG:
case ZPA2326_CTRL_REG1_REG:
case ZPA2326_CTRL_REG2_REG:
case ZPA2326_CTRL_REG3_REG:
case ZPA2326_INT_SOURCE_REG:
case ZPA2326_THS_P_LOW_REG:
case ZPA2326_THS_P_HIGH_REG:
case ZPA2326_STATUS_REG:
case ZPA2326_PRESS_OUT_XL_REG:
case ZPA2326_PRESS_OUT_L_REG:
case ZPA2326_PRESS_OUT_H_REG:
case ZPA2326_TEMP_OUT_L_REG:
case ZPA2326_TEMP_OUT_H_REG:
return true;
default:
return false;
}
}
bool zpa2326_isreg_precious(struct device *dev, unsigned int reg)
{
switch (reg) {
case ZPA2326_INT_SOURCE_REG:
case ZPA2326_PRESS_OUT_H_REG:
return true;
default:
return false;
}
}
static int zpa2326_enable_device(const struct iio_dev *indio_dev)
{
int err;
err = regmap_write(((struct zpa2326_private *)
iio_priv(indio_dev))->regmap,
ZPA2326_CTRL_REG0_REG, ZPA2326_CTRL_REG0_ENABLE);
if (err) {
zpa2326_err(indio_dev, "failed to enable device (%d)", err);
return err;
}
zpa2326_dbg(indio_dev, "enabled");
return 0;
}
static int zpa2326_sleep(const struct iio_dev *indio_dev)
{
int err;
err = regmap_write(((struct zpa2326_private *)
iio_priv(indio_dev))->regmap,
ZPA2326_CTRL_REG0_REG, 0);
if (err) {
zpa2326_err(indio_dev, "failed to sleep (%d)", err);
return err;
}
zpa2326_dbg(indio_dev, "sleeping");
return 0;
}
static int zpa2326_reset_device(const struct iio_dev *indio_dev)
{
int err;
err = regmap_write(((struct zpa2326_private *)
iio_priv(indio_dev))->regmap,
ZPA2326_CTRL_REG2_REG, ZPA2326_CTRL_REG2_SWRESET);
if (err) {
zpa2326_err(indio_dev, "failed to reset device (%d)", err);
return err;
}
usleep_range(ZPA2326_TPUP_USEC_MIN, ZPA2326_TPUP_USEC_MAX);
zpa2326_dbg(indio_dev, "reset");
return 0;
}
static int zpa2326_start_oneshot(const struct iio_dev *indio_dev)
{
int err;
err = regmap_write(((struct zpa2326_private *)
iio_priv(indio_dev))->regmap,
ZPA2326_CTRL_REG0_REG,
ZPA2326_CTRL_REG0_ENABLE |
ZPA2326_CTRL_REG0_ONE_SHOT);
if (err) {
zpa2326_err(indio_dev, "failed to start one shot cycle (%d)",
err);
return err;
}
zpa2326_dbg(indio_dev, "one shot cycle started");
return 0;
}
static int zpa2326_power_on(const struct iio_dev *indio_dev,
const struct zpa2326_private *private)
{
int err;
err = regulator_enable(private->vref);
if (err)
return err;
err = regulator_enable(private->vdd);
if (err)
goto vref;
zpa2326_dbg(indio_dev, "powered on");
err = zpa2326_enable_device(indio_dev);
if (err)
goto vdd;
err = zpa2326_reset_device(indio_dev);
if (err)
goto sleep;
return 0;
sleep:
zpa2326_sleep(indio_dev);
vdd:
regulator_disable(private->vdd);
vref:
regulator_disable(private->vref);
zpa2326_dbg(indio_dev, "powered off");
return err;
}
static void zpa2326_power_off(const struct iio_dev *indio_dev,
const struct zpa2326_private *private)
{
regulator_disable(private->vdd);
regulator_disable(private->vref);
zpa2326_dbg(indio_dev, "powered off");
}
static int zpa2326_config_oneshot(const struct iio_dev *indio_dev,
int irq)
{
struct regmap *regs = ((struct zpa2326_private *)
iio_priv(indio_dev))->regmap;
const struct zpa2326_frequency *freq = zpa2326_highest_frequency();
int err;
err = regmap_write(regs, ZPA2326_CTRL_REG3_REG, freq->odr);
if (err)
return err;
if (irq > 0) {
err = regmap_write(regs, ZPA2326_CTRL_REG1_REG,
(u8)~ZPA2326_CTRL_REG1_MASK_DATA_READY);
if (err) {
dev_err(indio_dev->dev.parent,
"failed to setup one shot mode (%d)", err);
return err;
}
}
zpa2326_dbg(indio_dev, "one shot mode setup @%dHz", freq->hz);
return 0;
}
static int zpa2326_clear_fifo(const struct iio_dev *indio_dev,
unsigned int min_count)
{
struct regmap *regs = ((struct zpa2326_private *)
iio_priv(indio_dev))->regmap;
int err;
unsigned int val;
if (!min_count) {
err = regmap_read(regs, ZPA2326_STATUS_REG, &val);
if (err < 0)
goto err;
if (val & ZPA2326_STATUS_FIFO_E)
return 0;
}
do {
err = regmap_read(regs, ZPA2326_PRESS_OUT_H_REG, &val);
if (err < 0)
goto err;
if (min_count) {
min_count--;
continue;
}
err = regmap_read(regs, ZPA2326_STATUS_REG, &val);
if (err < 0)
goto err;
} while (!(val & ZPA2326_STATUS_FIFO_E));
zpa2326_dbg(indio_dev, "FIFO cleared");
return 0;
err:
zpa2326_err(indio_dev, "failed to clear FIFO (%d)", err);
return err;
}
static int zpa2326_dequeue_pressure(const struct iio_dev *indio_dev,
u32 *pressure)
{
struct regmap *regs = ((struct zpa2326_private *)
iio_priv(indio_dev))->regmap;
unsigned int val;
int err;
int cleared = -1;
err = regmap_read(regs, ZPA2326_STATUS_REG, &val);
if (err < 0)
return err;
*pressure = 0;
if (val & ZPA2326_STATUS_P_OR) {
zpa2326_warn(indio_dev, "FIFO overflow");
err = regmap_bulk_read(regs, ZPA2326_PRESS_OUT_XL_REG, pressure,
3);
if (err)
return err;
#define ZPA2326_FIFO_DEPTH (16U)
return zpa2326_clear_fifo(indio_dev, ZPA2326_FIFO_DEPTH - 1);
}
do {
err = regmap_bulk_read(regs, ZPA2326_PRESS_OUT_XL_REG, pressure,
3);
if (err)
return err;
err = regmap_read(regs, ZPA2326_STATUS_REG, &val);
if (err < 0)
return err;
cleared++;
} while (!(val & ZPA2326_STATUS_FIFO_E));
if (cleared)
zpa2326_dbg(indio_dev, "cleared %d FIFO entries", cleared);
return 0;
}
static int zpa2326_fill_sample_buffer(struct iio_dev *indio_dev,
const struct zpa2326_private *private)
{
struct {
u32 pressure;
u16 temperature;
u64 timestamp;
} sample;
int err;
if (test_bit(0, indio_dev->active_scan_mask)) {
err = zpa2326_dequeue_pressure(indio_dev, &sample.pressure);
if (err) {
zpa2326_warn(indio_dev, "failed to fetch pressure (%d)",
err);
return err;
}
}
if (test_bit(1, indio_dev->active_scan_mask)) {
err = regmap_bulk_read(private->regmap, ZPA2326_TEMP_OUT_L_REG,
&sample.temperature, 2);
if (err) {
zpa2326_warn(indio_dev,
"failed to fetch temperature (%d)", err);
return err;
}
}
zpa2326_dbg(indio_dev, "filling raw samples buffer");
iio_push_to_buffers_with_timestamp(indio_dev, &sample,
private->timestamp);
return 0;
}
static int zpa2326_runtime_suspend(struct device *parent)
{
const struct iio_dev *indio_dev = dev_get_drvdata(parent);
if (pm_runtime_autosuspend_expiration(parent))
return -EAGAIN;
zpa2326_power_off(indio_dev, iio_priv(indio_dev));
return 0;
}
static int zpa2326_runtime_resume(struct device *parent)
{
const struct iio_dev *indio_dev = dev_get_drvdata(parent);
return zpa2326_power_on(indio_dev, iio_priv(indio_dev));
}
static int zpa2326_resume(const struct iio_dev *indio_dev)
{
int err;
err = pm_runtime_get_sync(indio_dev->dev.parent);
if (err < 0)
return err;
if (err > 0) {
zpa2326_enable_device(indio_dev);
return 1;
}
return 0;
}
static void zpa2326_suspend(struct iio_dev *indio_dev)
{
struct device *parent = indio_dev->dev.parent;
zpa2326_sleep(indio_dev);
pm_runtime_mark_last_busy(parent);
pm_runtime_put_autosuspend(parent);
}
static void zpa2326_init_runtime(struct device *parent)
{
pm_runtime_get_noresume(parent);
pm_runtime_set_active(parent);
pm_runtime_enable(parent);
pm_runtime_set_autosuspend_delay(parent, 1000);
pm_runtime_use_autosuspend(parent);
pm_runtime_mark_last_busy(parent);
pm_runtime_put_autosuspend(parent);
}
static void zpa2326_fini_runtime(struct device *parent)
{
pm_runtime_disable(parent);
pm_runtime_set_suspended(parent);
}
static int zpa2326_resume(const struct iio_dev *indio_dev)
{
zpa2326_enable_device(indio_dev);
return 0;
}
static void zpa2326_suspend(struct iio_dev *indio_dev)
{
zpa2326_sleep(indio_dev);
}
static irqreturn_t zpa2326_handle_irq(int irq, void *data)
{
struct iio_dev *indio_dev = data;
if (iio_buffer_enabled(indio_dev)) {
((struct zpa2326_private *)
iio_priv(indio_dev))->timestamp = iio_get_time_ns(indio_dev);
}
return IRQ_WAKE_THREAD;
}
static irqreturn_t zpa2326_handle_threaded_irq(int irq, void *data)
{
struct iio_dev *indio_dev = data;
struct zpa2326_private *priv = iio_priv(indio_dev);
unsigned int val;
bool cont;
irqreturn_t ret = IRQ_NONE;
cont = (iio_buffer_enabled(indio_dev) &&
iio_trigger_using_own(indio_dev));
priv->result = regmap_read(priv->regmap, ZPA2326_INT_SOURCE_REG, &val);
if (priv->result < 0) {
if (cont)
return IRQ_NONE;
goto complete;
}
if (!(val & ZPA2326_INT_SOURCE_DATA_READY)) {
zpa2326_warn(indio_dev, "unexpected interrupt status %02x",
val);
if (cont)
return IRQ_NONE;
priv->result = -ENODATA;
goto complete;
}
iio_trigger_poll_chained(priv->trigger);
if (cont)
return IRQ_HANDLED;
ret = IRQ_HANDLED;
complete:
complete(&priv->data_ready);
return ret;
}
static int zpa2326_wait_oneshot_completion(const struct iio_dev *indio_dev,
struct zpa2326_private *private)
{
int ret;
unsigned int val;
zpa2326_dbg(indio_dev, "waiting for one shot completion interrupt");
ret = wait_for_completion_interruptible_timeout(
&private->data_ready, ZPA2326_CONVERSION_JIFFIES);
if (ret > 0)
return private->result;
regmap_read(private->regmap, ZPA2326_INT_SOURCE_REG, &val);
if (!ret)
ret = -ETIME;
if (ret != -ERESTARTSYS)
zpa2326_warn(indio_dev, "no one shot interrupt occurred (%d)",
ret);
return ret;
}
static int zpa2326_init_managed_irq(struct device *parent,
struct iio_dev *indio_dev,
struct zpa2326_private *private,
int irq)
{
int err;
private->irq = irq;
if (irq <= 0) {
dev_info(parent, "no interrupt found, running in polling mode");
return 0;
}
init_completion(&private->data_ready);
err = devm_request_threaded_irq(parent, irq, zpa2326_handle_irq,
zpa2326_handle_threaded_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(parent), indio_dev);
if (err) {
dev_err(parent, "failed to request interrupt %d (%d)", irq,
err);
return err;
}
dev_info(parent, "using interrupt %d", irq);
return 0;
}
static int zpa2326_poll_oneshot_completion(const struct iio_dev *indio_dev)
{
unsigned long tmout = jiffies + ZPA2326_CONVERSION_JIFFIES;
struct regmap *regs = ((struct zpa2326_private *)
iio_priv(indio_dev))->regmap;
unsigned int val;
int err;
zpa2326_dbg(indio_dev, "polling for one shot completion");
if (msleep_interruptible(100))
return -ERESTARTSYS;
while (true) {
err = regmap_read(regs, ZPA2326_CTRL_REG0_REG, &val);
if (err < 0)
goto err;
if (!(val & ZPA2326_CTRL_REG0_ONE_SHOT))
break;
if (time_after(jiffies, tmout)) {
err = -ETIME;
goto err;
}
usleep_range(10000, 20000);
}
err = regmap_read(regs, ZPA2326_STATUS_REG, &val);
if (err < 0)
goto err;
if (!(val & ZPA2326_STATUS_P_DA)) {
err = -ENODATA;
goto err;
}
return 0;
err:
zpa2326_warn(indio_dev, "failed to poll one shot completion (%d)", err);
return err;
}
static int zpa2326_fetch_raw_sample(const struct iio_dev *indio_dev,
enum iio_chan_type type,
int *value)
{
struct regmap *regs = ((struct zpa2326_private *)
iio_priv(indio_dev))->regmap;
int err;
switch (type) {
case IIO_PRESSURE:
zpa2326_dbg(indio_dev, "fetching raw pressure sample");
err = regmap_bulk_read(regs, ZPA2326_PRESS_OUT_XL_REG, value,
3);
if (err) {
zpa2326_warn(indio_dev, "failed to fetch pressure (%d)",
err);
return err;
}
*value = (((u8 *)value)[2] << 16) | (((u8 *)value)[1] << 8) |
((u8 *)value)[0];
return IIO_VAL_INT;
case IIO_TEMP:
zpa2326_dbg(indio_dev, "fetching raw temperature sample");
err = regmap_bulk_read(regs, ZPA2326_TEMP_OUT_L_REG, value, 2);
if (err) {
zpa2326_warn(indio_dev,
"failed to fetch temperature (%d)", err);
return err;
}
*value = (int)le16_to_cpup((__le16 *)value);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int zpa2326_sample_oneshot(struct iio_dev *indio_dev,
enum iio_chan_type type,
int *value)
{
int ret;
struct zpa2326_private *priv;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = zpa2326_resume(indio_dev);
if (ret < 0)
goto release;
priv = iio_priv(indio_dev);
if (ret > 0) {
if (type == IIO_PRESSURE) {
ret = zpa2326_clear_fifo(indio_dev, 0);
if (ret)
goto suspend;
}
} else {
ret = zpa2326_config_oneshot(indio_dev, priv->irq);
if (ret)
goto suspend;
}
ret = zpa2326_start_oneshot(indio_dev);
if (ret)
goto suspend;
if (priv->irq > 0)
ret = zpa2326_wait_oneshot_completion(indio_dev, priv);
else
ret = zpa2326_poll_oneshot_completion(indio_dev);
if (ret)
goto suspend;
ret = zpa2326_fetch_raw_sample(indio_dev, type, value);
suspend:
zpa2326_suspend(indio_dev);
release:
iio_device_release_direct_mode(indio_dev);
return ret;
}
static irqreturn_t zpa2326_trigger_handler(int irq, void *data)
{
struct iio_dev *indio_dev = ((struct iio_poll_func *)
data)->indio_dev;
struct zpa2326_private *priv = iio_priv(indio_dev);
bool cont;
cont = iio_trigger_using_own(indio_dev);
if (!cont) {
if (zpa2326_start_oneshot(indio_dev))
goto out;
if (priv->irq <= 0) {
if (zpa2326_poll_oneshot_completion(indio_dev))
goto out;
priv->timestamp = iio_get_time_ns(indio_dev);
} else {
if (zpa2326_wait_oneshot_completion(indio_dev, priv))
goto out;
}
}
zpa2326_fill_sample_buffer(indio_dev, priv);
out:
if (!cont)
zpa2326_sleep(indio_dev);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int zpa2326_preenable_buffer(struct iio_dev *indio_dev)
{
int ret = zpa2326_resume(indio_dev);
if (ret < 0)
return ret;
((struct zpa2326_private *)
iio_priv(indio_dev))->waken = iio_priv(indio_dev);
return 0;
}
static int zpa2326_postenable_buffer(struct iio_dev *indio_dev)
{
const struct zpa2326_private *priv = iio_priv(indio_dev);
int err;
if (!priv->waken) {
err = zpa2326_clear_fifo(indio_dev, 0);
if (err)
goto err;
}
if (!iio_trigger_using_own(indio_dev) && priv->waken) {
err = zpa2326_config_oneshot(indio_dev, priv->irq);
if (err)
goto err;
}
err = iio_triggered_buffer_postenable(indio_dev);
if (err)
goto err;
return 0;
err:
zpa2326_err(indio_dev, "failed to enable buffering (%d)", err);
return err;
}
static int zpa2326_postdisable_buffer(struct iio_dev *indio_dev)
{
zpa2326_suspend(indio_dev);
return 0;
}
static int zpa2326_set_trigger_state(struct iio_trigger *trig, bool state)
{
const struct iio_dev *indio_dev = dev_get_drvdata(
trig->dev.parent);
const struct zpa2326_private *priv = iio_priv(indio_dev);
int err;
if (!state) {
unsigned int val;
disable_irq(priv->irq);
err = regmap_write(priv->regmap, ZPA2326_CTRL_REG3_REG,
zpa2326_highest_frequency()->odr);
if (err)
return err;
err = regmap_read(priv->regmap, ZPA2326_INT_SOURCE_REG, &val);
if (err < 0)
return err;
enable_irq(priv->irq);
zpa2326_dbg(indio_dev, "continuous mode stopped");
} else {
if (priv->waken) {
err = regmap_write(priv->regmap, ZPA2326_CTRL_REG1_REG,
(u8)
~ZPA2326_CTRL_REG1_MASK_DATA_READY);
if (err)
return err;
}
err = regmap_write(priv->regmap, ZPA2326_CTRL_REG3_REG,
ZPA2326_CTRL_REG3_ENABLE_MEAS |
priv->frequency->odr);
if (err)
return err;
zpa2326_dbg(indio_dev, "continuous mode setup @%dHz",
priv->frequency->hz);
}
return 0;
}
static int zpa2326_init_managed_trigger(struct device *parent,
struct iio_dev *indio_dev,
struct zpa2326_private *private,
int irq)
{
struct iio_trigger *trigger;
int ret;
if (irq <= 0)
return 0;
trigger = devm_iio_trigger_alloc(parent, "%s-dev%d",
indio_dev->name, indio_dev->id);
if (!trigger)
return -ENOMEM;
trigger->dev.parent = parent;
trigger->ops = &zpa2326_trigger_ops;
private->trigger = trigger;
ret = devm_iio_trigger_register(parent, trigger);
if (ret)
dev_err(parent, "failed to register hardware trigger (%d)",
ret);
return ret;
}
static int zpa2326_get_frequency(const struct iio_dev *indio_dev)
{
return ((struct zpa2326_private *)iio_priv(indio_dev))->frequency->hz;
}
static int zpa2326_set_frequency(struct iio_dev *indio_dev, int hz)
{
struct zpa2326_private *priv = iio_priv(indio_dev);
int freq;
int err;
for (freq = 0; freq < ARRAY_SIZE(zpa2326_sampling_frequencies); freq++)
if (zpa2326_sampling_frequencies[freq].hz == hz)
break;
if (freq == ARRAY_SIZE(zpa2326_sampling_frequencies))
return -EINVAL;
err = iio_device_claim_direct_mode(indio_dev);
if (err)
return err;
priv->frequency = &zpa2326_sampling_frequencies[freq];
iio_device_release_direct_mode(indio_dev);
return 0;
}
static int zpa2326_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
switch (mask) {
case IIO_CHAN_INFO_RAW:
return zpa2326_sample_oneshot(indio_dev, chan->type, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_PRESSURE:
*val = 1;
*val2 = 64000;
return IIO_VAL_FRACTIONAL;
case IIO_TEMP:
*val = 6;
*val2 = 490000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_TEMP:
*val = -17683000;
*val2 = 649;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
*val = zpa2326_get_frequency(indio_dev);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int zpa2326_write_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int val,
int val2,
long mask)
{
if ((mask != IIO_CHAN_INFO_SAMP_FREQ) || val2)
return -EINVAL;
return zpa2326_set_frequency(indio_dev, val);
}
static struct iio_dev *zpa2326_create_managed_iiodev(struct device *device,
const char *name,
struct regmap *regmap)
{
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(device,
sizeof(struct zpa2326_private));
if (!indio_dev)
return NULL;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->dev.parent = device;
indio_dev->channels = zpa2326_channels;
indio_dev->num_channels = ARRAY_SIZE(zpa2326_channels);
indio_dev->name = name;
indio_dev->info = &zpa2326_info;
return indio_dev;
}
int zpa2326_probe(struct device *parent,
const char *name,
int irq,
unsigned int hwid,
struct regmap *regmap)
{
struct iio_dev *indio_dev;
struct zpa2326_private *priv;
int err;
unsigned int id;
indio_dev = zpa2326_create_managed_iiodev(parent, name, regmap);
if (!indio_dev)
return -ENOMEM;
priv = iio_priv(indio_dev);
priv->vref = devm_regulator_get(parent, "vref");
if (IS_ERR(priv->vref))
return PTR_ERR(priv->vref);
priv->vdd = devm_regulator_get(parent, "vdd");
if (IS_ERR(priv->vdd))
return PTR_ERR(priv->vdd);
priv->frequency = zpa2326_highest_frequency();
priv->regmap = regmap;
err = devm_iio_triggered_buffer_setup(parent, indio_dev, NULL,
zpa2326_trigger_handler,
&zpa2326_buffer_setup_ops);
if (err)
return err;
err = zpa2326_init_managed_trigger(parent, indio_dev, priv, irq);
if (err)
return err;
err = zpa2326_init_managed_irq(parent, indio_dev, priv, irq);
if (err)
return err;
err = zpa2326_power_on(indio_dev, priv);
if (err)
return err;
err = regmap_read(regmap, ZPA2326_DEVICE_ID_REG, &id);
if (err)
goto sleep;
if (id != hwid) {
dev_err(parent, "found device with unexpected id %02x", id);
err = -ENODEV;
goto sleep;
}
err = zpa2326_config_oneshot(indio_dev, irq);
if (err)
goto sleep;
err = zpa2326_sleep(indio_dev);
if (err)
goto poweroff;
dev_set_drvdata(parent, indio_dev);
zpa2326_init_runtime(parent);
err = iio_device_register(indio_dev);
if (err) {
zpa2326_fini_runtime(parent);
goto poweroff;
}
return 0;
sleep:
zpa2326_sleep(indio_dev);
poweroff:
zpa2326_power_off(indio_dev, priv);
return err;
}
void zpa2326_remove(const struct device *parent)
{
struct iio_dev *indio_dev = dev_get_drvdata(parent);
iio_device_unregister(indio_dev);
zpa2326_fini_runtime(indio_dev->dev.parent);
zpa2326_sleep(indio_dev);
zpa2326_power_off(indio_dev, iio_priv(indio_dev));
}
