static int kxsd9_write_scale(struct iio_dev *indio_dev, int micro)
{
int ret, i;
struct kxsd9_state *st = iio_priv(indio_dev);
bool foundit = false;
for (i = 0; i < 4; i++)
if (micro == kxsd9_micro_scales[i]) {
foundit = true;
break;
}
if (!foundit)
return -EINVAL;
ret = regmap_update_bits(st->map,
KXSD9_REG_CTRL_C,
KXSD9_CTRL_C_FS_MASK,
i);
if (ret < 0)
goto error_ret;
st->scale = i;
error_ret:
return ret;
}
static int kxsd9_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int ret = -EINVAL;
struct kxsd9_state *st = iio_priv(indio_dev);
pm_runtime_get_sync(st->dev);
if (mask == IIO_CHAN_INFO_SCALE) {
if (val)
return -EINVAL;
ret = kxsd9_write_scale(indio_dev, val2);
}
pm_runtime_mark_last_busy(st->dev);
pm_runtime_put_autosuspend(st->dev);
return ret;
}
static int kxsd9_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret = -EINVAL;
struct kxsd9_state *st = iio_priv(indio_dev);
unsigned int regval;
__be16 raw_val;
u16 nval;
pm_runtime_get_sync(st->dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_bulk_read(st->map, chan->address, &raw_val,
sizeof(raw_val));
if (ret)
goto error_ret;
nval = be16_to_cpu(raw_val);
nval >>= 4;
*val = nval;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_OFFSET:
*val = KXSD9_ZERO_G_OFFSET;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
ret = regmap_read(st->map,
KXSD9_REG_CTRL_C,
&regval);
if (ret < 0)
goto error_ret;
*val = 0;
*val2 = kxsd9_micro_scales[regval & KXSD9_CTRL_C_FS_MASK];
ret = IIO_VAL_INT_PLUS_MICRO;
break;
}
error_ret:
pm_runtime_mark_last_busy(st->dev);
pm_runtime_put_autosuspend(st->dev);
return ret;
}
static irqreturn_t kxsd9_trigger_handler(int irq, void *p)
{
const struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct kxsd9_state *st = iio_priv(indio_dev);
int ret;
__be16 hw_values[8];
ret = regmap_bulk_read(st->map,
KXSD9_REG_X,
&hw_values,
8);
if (ret) {
dev_err(st->dev,
"error reading data\n");
return ret;
}
iio_push_to_buffers_with_timestamp(indio_dev,
hw_values,
iio_get_time_ns(indio_dev));
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int kxsd9_buffer_preenable(struct iio_dev *indio_dev)
{
struct kxsd9_state *st = iio_priv(indio_dev);
pm_runtime_get_sync(st->dev);
return 0;
}
static int kxsd9_buffer_postdisable(struct iio_dev *indio_dev)
{
struct kxsd9_state *st = iio_priv(indio_dev);
pm_runtime_mark_last_busy(st->dev);
pm_runtime_put_autosuspend(st->dev);
return 0;
}
static const struct iio_mount_matrix *
kxsd9_get_mount_matrix(const struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct kxsd9_state *st = iio_priv(indio_dev);
return &st->orientation;
}
static int kxsd9_power_up(struct kxsd9_state *st)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(st->regs), st->regs);
if (ret) {
dev_err(st->dev, "Cannot enable regulators\n");
return ret;
}
ret = regmap_write(st->map,
KXSD9_REG_CTRL_B,
KXSD9_CTRL_B_ENABLE);
if (ret)
return ret;
ret = regmap_write(st->map,
KXSD9_REG_CTRL_C,
KXSD9_CTRL_C_LP_1000HZ |
KXSD9_CTRL_C_MOT_LEV |
KXSD9_CTRL_C_MOT_LAT |
st->scale);
if (ret)
return ret;
msleep(20);
return 0;
}
static int kxsd9_power_down(struct kxsd9_state *st)
{
int ret;
ret = regmap_update_bits(st->map,
KXSD9_REG_CTRL_B,
KXSD9_CTRL_B_ENABLE,
0);
if (ret)
return ret;
ret = regulator_bulk_disable(ARRAY_SIZE(st->regs), st->regs);
if (ret) {
dev_err(st->dev, "Cannot disable regulators\n");
return ret;
}
return 0;
}
int kxsd9_common_probe(struct device *dev,
struct regmap *map,
const char *name)
{
struct iio_dev *indio_dev;
struct kxsd9_state *st;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->dev = dev;
st->map = map;
indio_dev->channels = kxsd9_channels;
indio_dev->num_channels = ARRAY_SIZE(kxsd9_channels);
indio_dev->name = name;
indio_dev->dev.parent = dev;
indio_dev->info = &kxsd9_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->available_scan_masks = kxsd9_scan_masks;
ret = of_iio_read_mount_matrix(dev,
"mount-matrix",
&st->orientation);
if (ret)
return ret;
st->regs[0].supply = kxsd9_reg_vdd;
st->regs[1].supply = kxsd9_reg_iovdd;
ret = devm_regulator_bulk_get(dev,
ARRAY_SIZE(st->regs),
st->regs);
if (ret) {
dev_err(dev, "Cannot get regulators\n");
return ret;
}
st->scale = KXSD9_CTRL_C_FS_2G;
kxsd9_power_up(st);
ret = iio_triggered_buffer_setup(indio_dev,
iio_pollfunc_store_time,
kxsd9_trigger_handler,
&kxsd9_buffer_setup_ops);
if (ret) {
dev_err(dev, "triggered buffer setup failed\n");
goto err_power_down;
}
ret = iio_device_register(indio_dev);
if (ret)
goto err_cleanup_buffer;
dev_set_drvdata(dev, indio_dev);
pm_runtime_get_noresume(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_set_autosuspend_delay(dev, 2000);
pm_runtime_use_autosuspend(dev);
pm_runtime_put(dev);
return 0;
err_cleanup_buffer:
iio_triggered_buffer_cleanup(indio_dev);
err_power_down:
kxsd9_power_down(st);
return ret;
}
int kxsd9_common_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = iio_priv(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_get_sync(dev);
pm_runtime_put_noidle(dev);
pm_runtime_disable(dev);
kxsd9_power_down(st);
return 0;
}
static int kxsd9_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = iio_priv(indio_dev);
return kxsd9_power_down(st);
}
static int kxsd9_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct kxsd9_state *st = iio_priv(indio_dev);
return kxsd9_power_up(st);
}
