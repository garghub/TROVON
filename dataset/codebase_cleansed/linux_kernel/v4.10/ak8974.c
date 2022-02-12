static int ak8974_set_power(struct ak8974 *ak8974, bool mode)
{
int ret;
u8 val;
val = mode ? AK8974_CTRL1_POWER : 0;
val |= AK8974_CTRL1_FORCE_EN;
ret = regmap_write(ak8974->map, AK8974_CTRL1, val);
if (ret < 0)
return ret;
if (mode)
msleep(AK8974_ACTIVATE_DELAY);
return 0;
}
static int ak8974_reset(struct ak8974 *ak8974)
{
int ret;
ret = ak8974_set_power(ak8974, AK8974_PWR_ON);
if (ret)
return ret;
ret = regmap_write(ak8974->map, AK8974_CTRL2, AK8974_CTRL2_RESDEF);
if (ret)
return ret;
ret = regmap_write(ak8974->map, AK8974_CTRL3, AK8974_CTRL3_RESDEF);
if (ret)
return ret;
ret = regmap_write(ak8974->map, AK8974_INT_CTRL,
AK8974_INT_CTRL_RESDEF);
if (ret)
return ret;
return ak8974_set_power(ak8974, AK8974_PWR_OFF);
}
static int ak8974_configure(struct ak8974 *ak8974)
{
int ret;
ret = regmap_write(ak8974->map, AK8974_CTRL2, AK8974_CTRL2_DRDY_EN |
AK8974_CTRL2_INT_EN);
if (ret)
return ret;
ret = regmap_write(ak8974->map, AK8974_CTRL3, 0);
if (ret)
return ret;
ret = regmap_write(ak8974->map, AK8974_INT_CTRL, AK8974_INT_CTRL_POL);
if (ret)
return ret;
return regmap_write(ak8974->map, AK8974_PRESET, 0);
}
static int ak8974_trigmeas(struct ak8974 *ak8974)
{
unsigned int clear;
u8 mask;
u8 val;
int ret;
ret = regmap_read(ak8974->map, AK8974_INT_CLEAR, &clear);
if (ret)
return ret;
if (ak8974->drdy_irq) {
mask = AK8974_CTRL2_INT_EN |
AK8974_CTRL2_DRDY_EN |
AK8974_CTRL2_DRDY_POL;
val = AK8974_CTRL2_DRDY_EN;
if (!ak8974->drdy_active_low)
val |= AK8974_CTRL2_DRDY_POL;
init_completion(&ak8974->drdy_complete);
ret = regmap_update_bits(ak8974->map, AK8974_CTRL2,
mask, val);
if (ret)
return ret;
}
return regmap_update_bits(ak8974->map,
AK8974_CTRL3,
AK8974_CTRL3_FORCE,
AK8974_CTRL3_FORCE);
}
static int ak8974_await_drdy(struct ak8974 *ak8974)
{
int timeout = 2;
unsigned int val;
int ret;
if (ak8974->drdy_irq) {
ret = wait_for_completion_timeout(&ak8974->drdy_complete,
1 + msecs_to_jiffies(1000));
if (!ret) {
dev_err(&ak8974->i2c->dev,
"timeout waiting for DRDY IRQ\n");
return -ETIMEDOUT;
}
return 0;
}
do {
msleep(AK8974_MEASTIME);
ret = regmap_read(ak8974->map, AK8974_STATUS, &val);
if (ret < 0)
return ret;
if (val & AK8974_STATUS_DRDY)
return 0;
} while (--timeout);
if (!timeout) {
dev_err(&ak8974->i2c->dev,
"timeout waiting for DRDY\n");
return -ETIMEDOUT;
}
return 0;
}
static int ak8974_getresult(struct ak8974 *ak8974, __le16 *result)
{
unsigned int src;
int ret;
ret = ak8974_await_drdy(ak8974);
if (ret)
return ret;
ret = regmap_read(ak8974->map, AK8974_INT_SRC, &src);
if (ret < 0)
return ret;
if (src & AK8974_INT_RANGE) {
dev_err(&ak8974->i2c->dev,
"range overflow in sensor\n");
return -ERANGE;
}
ret = regmap_bulk_read(ak8974->map, AK8974_DATA_X, result, 6);
if (ret)
return ret;
return ret;
}
static irqreturn_t ak8974_drdy_irq(int irq, void *d)
{
struct ak8974 *ak8974 = d;
if (!ak8974->drdy_irq)
return IRQ_NONE;
return IRQ_WAKE_THREAD;
}
static irqreturn_t ak8974_drdy_irq_thread(int irq, void *d)
{
struct ak8974 *ak8974 = d;
unsigned int val;
int ret;
ret = regmap_read(ak8974->map, AK8974_STATUS, &val);
if (ret < 0) {
dev_err(&ak8974->i2c->dev, "error reading DRDY status\n");
return IRQ_HANDLED;
}
if (val & AK8974_STATUS_DRDY) {
complete(&ak8974->drdy_complete);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int ak8974_selftest(struct ak8974 *ak8974)
{
struct device *dev = &ak8974->i2c->dev;
unsigned int val;
int ret;
ret = regmap_read(ak8974->map, AK8974_SELFTEST, &val);
if (ret)
return ret;
if (val != AK8974_SELFTEST_IDLE) {
dev_err(dev, "selftest not idle before test\n");
return -EIO;
}
ret = regmap_update_bits(ak8974->map,
AK8974_CTRL3,
AK8974_CTRL3_SELFTEST,
AK8974_CTRL3_SELFTEST);
if (ret) {
dev_err(dev, "could not write CTRL3\n");
return ret;
}
msleep(AK8974_SELFTEST_DELAY);
ret = regmap_read(ak8974->map, AK8974_SELFTEST, &val);
if (ret)
return ret;
if (val != AK8974_SELFTEST_OK) {
dev_err(dev, "selftest result NOT OK (%02x)\n", val);
return -EIO;
}
ret = regmap_read(ak8974->map, AK8974_SELFTEST, &val);
if (ret)
return ret;
if (val != AK8974_SELFTEST_IDLE) {
dev_err(dev, "selftest not idle after test (%02x)\n", val);
return -EIO;
}
dev_dbg(dev, "passed self-test\n");
return 0;
}
static int ak8974_get_u16_val(struct ak8974 *ak8974, u8 reg, u16 *val)
{
int ret;
__le16 bulk;
ret = regmap_bulk_read(ak8974->map, reg, &bulk, 2);
if (ret)
return ret;
*val = le16_to_cpu(bulk);
return 0;
}
static int ak8974_detect(struct ak8974 *ak8974)
{
unsigned int whoami;
const char *name;
int ret;
unsigned int fw;
u16 sn;
ret = regmap_read(ak8974->map, AK8974_WHOAMI, &whoami);
if (ret)
return ret;
switch (whoami) {
case AK8974_WHOAMI_VALUE_AMI305:
name = "ami305";
ret = regmap_read(ak8974->map, AMI305_VER, &fw);
if (ret)
return ret;
fw &= 0x7f;
ret = ak8974_get_u16_val(ak8974, AMI305_SN, &sn);
if (ret)
return ret;
dev_info(&ak8974->i2c->dev,
"detected %s, FW ver %02x, S/N: %04x\n",
name, fw, sn);
break;
case AK8974_WHOAMI_VALUE_AK8974:
name = "ak8974";
dev_info(&ak8974->i2c->dev, "detected AK8974\n");
break;
default:
dev_err(&ak8974->i2c->dev, "unsupported device (%02x) ",
whoami);
return -ENODEV;
}
ak8974->name = name;
ak8974->variant = whoami;
return 0;
}
static int ak8974_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct ak8974 *ak8974 = iio_priv(indio_dev);
__le16 hw_values[3];
int ret = -EINVAL;
pm_runtime_get_sync(&ak8974->i2c->dev);
mutex_lock(&ak8974->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->address > 2) {
dev_err(&ak8974->i2c->dev, "faulty channel address\n");
ret = -EIO;
goto out_unlock;
}
ret = ak8974_trigmeas(ak8974);
if (ret)
goto out_unlock;
ret = ak8974_getresult(ak8974, hw_values);
if (ret)
goto out_unlock;
*val = le16_to_cpu(hw_values[chan->address]);
ret = IIO_VAL_INT;
}
out_unlock:
mutex_unlock(&ak8974->lock);
pm_runtime_mark_last_busy(&ak8974->i2c->dev);
pm_runtime_put_autosuspend(&ak8974->i2c->dev);
return ret;
}
static void ak8974_fill_buffer(struct iio_dev *indio_dev)
{
struct ak8974 *ak8974 = iio_priv(indio_dev);
int ret;
__le16 hw_values[8];
pm_runtime_get_sync(&ak8974->i2c->dev);
mutex_lock(&ak8974->lock);
ret = ak8974_trigmeas(ak8974);
if (ret) {
dev_err(&ak8974->i2c->dev, "error triggering measure\n");
goto out_unlock;
}
ret = ak8974_getresult(ak8974, hw_values);
if (ret) {
dev_err(&ak8974->i2c->dev, "error getting measures\n");
goto out_unlock;
}
iio_push_to_buffers_with_timestamp(indio_dev, hw_values,
iio_get_time_ns(indio_dev));
out_unlock:
mutex_unlock(&ak8974->lock);
pm_runtime_mark_last_busy(&ak8974->i2c->dev);
pm_runtime_put_autosuspend(&ak8974->i2c->dev);
}
static irqreturn_t ak8974_handle_trigger(int irq, void *p)
{
const struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
ak8974_fill_buffer(indio_dev);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static const struct iio_mount_matrix *
ak8974_get_mount_matrix(const struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ak8974 *ak8974 = iio_priv(indio_dev);
return &ak8974->orientation;
}
static bool ak8974_writeable_reg(struct device *dev, unsigned int reg)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct iio_dev *indio_dev = i2c_get_clientdata(i2c);
struct ak8974 *ak8974 = iio_priv(indio_dev);
switch (reg) {
case AK8974_CTRL1:
case AK8974_CTRL2:
case AK8974_CTRL3:
case AK8974_INT_CTRL:
case AK8974_INT_THRES:
case AK8974_INT_THRES + 1:
case AK8974_PRESET:
case AK8974_PRESET + 1:
return true;
case AK8974_OFFSET_X:
case AK8974_OFFSET_X + 1:
case AK8974_OFFSET_Y:
case AK8974_OFFSET_Y + 1:
case AK8974_OFFSET_Z:
case AK8974_OFFSET_Z + 1:
if (ak8974->variant == AK8974_WHOAMI_VALUE_AK8974)
return true;
return false;
case AMI305_OFFSET_X:
case AMI305_OFFSET_X + 1:
case AMI305_OFFSET_Y:
case AMI305_OFFSET_Y + 1:
case AMI305_OFFSET_Z:
case AMI305_OFFSET_Z + 1:
if (ak8974->variant == AK8974_WHOAMI_VALUE_AMI305)
return true;
return false;
default:
return false;
}
}
static int ak8974_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ak8974 *ak8974;
unsigned long irq_trig;
int irq = i2c->irq;
int ret;
indio_dev = devm_iio_device_alloc(&i2c->dev, sizeof(*ak8974));
if (indio_dev == NULL)
return -ENOMEM;
ak8974 = iio_priv(indio_dev);
i2c_set_clientdata(i2c, indio_dev);
ak8974->i2c = i2c;
mutex_init(&ak8974->lock);
ret = of_iio_read_mount_matrix(&i2c->dev,
"mount-matrix",
&ak8974->orientation);
if (ret)
return ret;
ak8974->regs[0].supply = ak8974_reg_avdd;
ak8974->regs[1].supply = ak8974_reg_dvdd;
ret = devm_regulator_bulk_get(&i2c->dev,
ARRAY_SIZE(ak8974->regs),
ak8974->regs);
if (ret < 0) {
dev_err(&i2c->dev, "cannot get regulators\n");
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
if (ret < 0) {
dev_err(&i2c->dev, "cannot enable regulators\n");
return ret;
}
pm_runtime_get_noresume(&i2c->dev);
pm_runtime_set_active(&i2c->dev);
pm_runtime_enable(&i2c->dev);
ak8974->map = devm_regmap_init_i2c(i2c, &ak8974_regmap_config);
if (IS_ERR(ak8974->map)) {
dev_err(&i2c->dev, "failed to allocate register map\n");
return PTR_ERR(ak8974->map);
}
ret = ak8974_set_power(ak8974, AK8974_PWR_ON);
if (ret) {
dev_err(&i2c->dev, "could not power on\n");
goto power_off;
}
ret = ak8974_detect(ak8974);
if (ret) {
dev_err(&i2c->dev, "neither AK8974 nor AMI305 found\n");
goto power_off;
}
ret = ak8974_selftest(ak8974);
if (ret)
dev_err(&i2c->dev, "selftest failed (continuing anyway)\n");
ret = ak8974_reset(ak8974);
if (ret) {
dev_err(&i2c->dev, "AK8974 reset failed\n");
goto power_off;
}
pm_runtime_set_autosuspend_delay(&i2c->dev,
AK8974_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(&i2c->dev);
pm_runtime_put(&i2c->dev);
indio_dev->dev.parent = &i2c->dev;
indio_dev->channels = ak8974_channels;
indio_dev->num_channels = ARRAY_SIZE(ak8974_channels);
indio_dev->info = &ak8974_info;
indio_dev->available_scan_masks = ak8974_scan_masks;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->name = ak8974->name;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ak8974_handle_trigger,
NULL);
if (ret) {
dev_err(&i2c->dev, "triggered buffer setup failed\n");
goto disable_pm;
}
if (irq > 0) {
irq_trig = irqd_get_trigger_type(irq_get_irq_data(irq));
if (irq_trig == IRQF_TRIGGER_RISING) {
dev_info(&i2c->dev, "enable rising edge DRDY IRQ\n");
} else if (irq_trig == IRQF_TRIGGER_FALLING) {
ak8974->drdy_active_low = true;
dev_info(&i2c->dev, "enable falling edge DRDY IRQ\n");
} else {
irq_trig = IRQF_TRIGGER_RISING;
}
irq_trig |= IRQF_ONESHOT;
irq_trig |= IRQF_SHARED;
ret = devm_request_threaded_irq(&i2c->dev,
irq,
ak8974_drdy_irq,
ak8974_drdy_irq_thread,
irq_trig,
ak8974->name,
ak8974);
if (ret) {
dev_err(&i2c->dev, "unable to request DRDY IRQ "
"- proceeding without IRQ\n");
goto no_irq;
}
ak8974->drdy_irq = true;
}
no_irq:
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&i2c->dev, "device register failed\n");
goto cleanup_buffer;
}
return 0;
cleanup_buffer:
iio_triggered_buffer_cleanup(indio_dev);
disable_pm:
pm_runtime_put_noidle(&i2c->dev);
pm_runtime_disable(&i2c->dev);
ak8974_set_power(ak8974, AK8974_PWR_OFF);
power_off:
regulator_bulk_disable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
return ret;
}
static int __exit ak8974_remove(struct i2c_client *i2c)
{
struct iio_dev *indio_dev = i2c_get_clientdata(i2c);
struct ak8974 *ak8974 = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
pm_runtime_get_sync(&i2c->dev);
pm_runtime_put_noidle(&i2c->dev);
pm_runtime_disable(&i2c->dev);
ak8974_set_power(ak8974, AK8974_PWR_OFF);
regulator_bulk_disable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
return 0;
}
static int __maybe_unused ak8974_runtime_suspend(struct device *dev)
{
struct ak8974 *ak8974 =
iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
ak8974_set_power(ak8974, AK8974_PWR_OFF);
regulator_bulk_disable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
return 0;
}
static int __maybe_unused ak8974_runtime_resume(struct device *dev)
{
struct ak8974 *ak8974 =
iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
if (ret)
return ret;
msleep(AK8974_POWERON_DELAY);
ret = ak8974_set_power(ak8974, AK8974_PWR_ON);
if (ret)
goto out_regulator_disable;
ret = ak8974_configure(ak8974);
if (ret)
goto out_disable_power;
return 0;
out_disable_power:
ak8974_set_power(ak8974, AK8974_PWR_OFF);
out_regulator_disable:
regulator_bulk_disable(ARRAY_SIZE(ak8974->regs), ak8974->regs);
return ret;
}
