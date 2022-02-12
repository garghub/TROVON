static bool bmc150_magn_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMC150_MAGN_REG_POWER:
case BMC150_MAGN_REG_OPMODE_ODR:
case BMC150_MAGN_REG_INT:
case BMC150_MAGN_REG_INT_DRDY:
case BMC150_MAGN_REG_LOW_THRESH:
case BMC150_MAGN_REG_HIGH_THRESH:
case BMC150_MAGN_REG_REP_XY:
case BMC150_MAGN_REG_REP_Z:
return true;
default:
return false;
};
}
static bool bmc150_magn_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMC150_MAGN_REG_X_L:
case BMC150_MAGN_REG_X_M:
case BMC150_MAGN_REG_Y_L:
case BMC150_MAGN_REG_Y_M:
case BMC150_MAGN_REG_Z_L:
case BMC150_MAGN_REG_Z_M:
case BMC150_MAGN_REG_RHALL_L:
case BMC150_MAGN_REG_RHALL_M:
case BMC150_MAGN_REG_INT_STATUS:
return true;
default:
return false;
}
}
static int bmc150_magn_set_power_mode(struct bmc150_magn_data *data,
enum bmc150_magn_power_modes mode,
bool state)
{
int ret;
switch (mode) {
case BMC150_MAGN_POWER_MODE_SUSPEND:
ret = regmap_update_bits(data->regmap, BMC150_MAGN_REG_POWER,
BMC150_MAGN_MASK_POWER_CTL, !state);
if (ret < 0)
return ret;
usleep_range(BMC150_MAGN_START_UP_TIME_MS * 1000, 20000);
return 0;
case BMC150_MAGN_POWER_MODE_SLEEP:
return regmap_update_bits(data->regmap,
BMC150_MAGN_REG_OPMODE_ODR,
BMC150_MAGN_MASK_OPMODE,
BMC150_MAGN_MODE_SLEEP <<
BMC150_MAGN_SHIFT_OPMODE);
case BMC150_MAGN_POWER_MODE_NORMAL:
return regmap_update_bits(data->regmap,
BMC150_MAGN_REG_OPMODE_ODR,
BMC150_MAGN_MASK_OPMODE,
BMC150_MAGN_MODE_NORMAL <<
BMC150_MAGN_SHIFT_OPMODE);
}
return -EINVAL;
}
static int bmc150_magn_set_power_state(struct bmc150_magn_data *data, bool on)
{
#ifdef CONFIG_PM
int ret;
if (on) {
ret = pm_runtime_get_sync(&data->client->dev);
} else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
if (ret < 0) {
dev_err(&data->client->dev,
"failed to change power state to %d\n", on);
if (on)
pm_runtime_put_noidle(&data->client->dev);
return ret;
}
#endif
return 0;
}
static int bmc150_magn_get_odr(struct bmc150_magn_data *data, int *val)
{
int ret, reg_val;
u8 i, odr_val;
ret = regmap_read(data->regmap, BMC150_MAGN_REG_OPMODE_ODR, &reg_val);
if (ret < 0)
return ret;
odr_val = (reg_val & BMC150_MAGN_MASK_ODR) >> BMC150_MAGN_SHIFT_ODR;
for (i = 0; i < ARRAY_SIZE(bmc150_magn_samp_freq_table); i++)
if (bmc150_magn_samp_freq_table[i].reg_val == odr_val) {
*val = bmc150_magn_samp_freq_table[i].freq;
return 0;
}
return -EINVAL;
}
static int bmc150_magn_set_odr(struct bmc150_magn_data *data, int val)
{
int ret;
u8 i;
for (i = 0; i < ARRAY_SIZE(bmc150_magn_samp_freq_table); i++) {
if (bmc150_magn_samp_freq_table[i].freq == val) {
ret = regmap_update_bits(data->regmap,
BMC150_MAGN_REG_OPMODE_ODR,
BMC150_MAGN_MASK_ODR,
bmc150_magn_samp_freq_table[i].
reg_val <<
BMC150_MAGN_SHIFT_ODR);
if (ret < 0)
return ret;
return 0;
}
}
return -EINVAL;
}
static int bmc150_magn_set_max_odr(struct bmc150_magn_data *data, int rep_xy,
int rep_z, int odr)
{
int ret, reg_val, max_odr;
if (rep_xy <= 0) {
ret = regmap_read(data->regmap, BMC150_MAGN_REG_REP_XY,
&reg_val);
if (ret < 0)
return ret;
rep_xy = BMC150_MAGN_REGVAL_TO_REPXY(reg_val);
}
if (rep_z <= 0) {
ret = regmap_read(data->regmap, BMC150_MAGN_REG_REP_Z,
&reg_val);
if (ret < 0)
return ret;
rep_z = BMC150_MAGN_REGVAL_TO_REPZ(reg_val);
}
if (odr <= 0) {
ret = bmc150_magn_get_odr(data, &odr);
if (ret < 0)
return ret;
}
max_odr = 1000000 / (145 * rep_xy + 500 * rep_z + 980);
if (odr > max_odr) {
dev_err(&data->client->dev,
"Can't set oversampling with sampling freq %d\n",
odr);
return -EINVAL;
}
data->max_odr = max_odr;
return 0;
}
static s32 bmc150_magn_compensate_x(struct bmc150_magn_trim_regs *tregs, s16 x,
u16 rhall)
{
s16 val;
u16 xyz1 = le16_to_cpu(tregs->xyz1);
if (x == BMC150_MAGN_XY_OVERFLOW_VAL)
return S32_MIN;
if (!rhall)
rhall = xyz1;
val = ((s16)(((u16)((((s32)xyz1) << 14) / rhall)) - ((u16)0x4000)));
val = ((s16)((((s32)x) * ((((((((s32)tregs->xy2) * ((((s32)val) *
((s32)val)) >> 7)) + (((s32)val) *
((s32)(((s16)tregs->xy1) << 7)))) >> 9) + ((s32)0x100000)) *
((s32)(((s16)tregs->x2) + ((s16)0xA0)))) >> 12)) >> 13)) +
(((s16)tregs->x1) << 3);
return (s32)val;
}
static s32 bmc150_magn_compensate_y(struct bmc150_magn_trim_regs *tregs, s16 y,
u16 rhall)
{
s16 val;
u16 xyz1 = le16_to_cpu(tregs->xyz1);
if (y == BMC150_MAGN_XY_OVERFLOW_VAL)
return S32_MIN;
if (!rhall)
rhall = xyz1;
val = ((s16)(((u16)((((s32)xyz1) << 14) / rhall)) - ((u16)0x4000)));
val = ((s16)((((s32)y) * ((((((((s32)tregs->xy2) * ((((s32)val) *
((s32)val)) >> 7)) + (((s32)val) *
((s32)(((s16)tregs->xy1) << 7)))) >> 9) + ((s32)0x100000)) *
((s32)(((s16)tregs->y2) + ((s16)0xA0)))) >> 12)) >> 13)) +
(((s16)tregs->y1) << 3);
return (s32)val;
}
static s32 bmc150_magn_compensate_z(struct bmc150_magn_trim_regs *tregs, s16 z,
u16 rhall)
{
s32 val;
u16 xyz1 = le16_to_cpu(tregs->xyz1);
u16 z1 = le16_to_cpu(tregs->z1);
s16 z2 = le16_to_cpu(tregs->z2);
s16 z3 = le16_to_cpu(tregs->z3);
s16 z4 = le16_to_cpu(tregs->z4);
if (z == BMC150_MAGN_Z_OVERFLOW_VAL)
return S32_MIN;
val = (((((s32)(z - z4)) << 15) - ((((s32)z3) * ((s32)(((s16)rhall) -
((s16)xyz1)))) >> 2)) / (z2 + ((s16)(((((s32)z1) *
((((s16)rhall) << 1))) + (1 << 15)) >> 16))));
return val;
}
static int bmc150_magn_read_xyz(struct bmc150_magn_data *data, s32 *buffer)
{
int ret;
__le16 values[AXIS_XYZR_MAX];
s16 raw_x, raw_y, raw_z;
u16 rhall;
struct bmc150_magn_trim_regs tregs;
ret = regmap_bulk_read(data->regmap, BMC150_MAGN_REG_X_L,
values, sizeof(values));
if (ret < 0)
return ret;
raw_x = (s16)le16_to_cpu(values[AXIS_X]) >> BMC150_MAGN_SHIFT_XY_L;
raw_y = (s16)le16_to_cpu(values[AXIS_Y]) >> BMC150_MAGN_SHIFT_XY_L;
raw_z = (s16)le16_to_cpu(values[AXIS_Z]) >> BMC150_MAGN_SHIFT_Z_L;
rhall = le16_to_cpu(values[RHALL]) >> BMC150_MAGN_SHIFT_RHALL_L;
ret = regmap_bulk_read(data->regmap, BMC150_MAGN_REG_TRIM_START,
&tregs, sizeof(tregs));
if (ret < 0)
return ret;
buffer[AXIS_X] = bmc150_magn_compensate_x(&tregs, raw_x, rhall);
buffer[AXIS_Y] = bmc150_magn_compensate_y(&tregs, raw_y, rhall);
buffer[AXIS_Z] = bmc150_magn_compensate_z(&tregs, raw_z, rhall);
return 0;
}
static int bmc150_magn_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret, tmp;
s32 values[AXIS_XYZ_MAX];
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = bmc150_magn_read_xyz(data, values);
if (ret < 0) {
bmc150_magn_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = values[chan->scan_index];
ret = bmc150_magn_set_power_state(data, false);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
mutex_unlock(&data->mutex);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 625;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = bmc150_magn_get_odr(data, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
switch (chan->channel2) {
case IIO_MOD_X:
case IIO_MOD_Y:
ret = regmap_read(data->regmap, BMC150_MAGN_REG_REP_XY,
&tmp);
if (ret < 0)
return ret;
*val = BMC150_MAGN_REGVAL_TO_REPXY(tmp);
return IIO_VAL_INT;
case IIO_MOD_Z:
ret = regmap_read(data->regmap, BMC150_MAGN_REG_REP_Z,
&tmp);
if (ret < 0)
return ret;
*val = BMC150_MAGN_REGVAL_TO_REPZ(tmp);
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int bmc150_magn_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val > data->max_odr)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_odr(data, val);
mutex_unlock(&data->mutex);
return ret;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
switch (chan->channel2) {
case IIO_MOD_X:
case IIO_MOD_Y:
if (val < 1 || val > 511)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_max_odr(data, val, 0, 0);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = regmap_update_bits(data->regmap,
BMC150_MAGN_REG_REP_XY,
BMC150_MAGN_REG_REP_DATAMASK,
BMC150_MAGN_REPXY_TO_REGVAL
(val));
mutex_unlock(&data->mutex);
return ret;
case IIO_MOD_Z:
if (val < 1 || val > 256)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_max_odr(data, 0, val, 0);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = regmap_update_bits(data->regmap,
BMC150_MAGN_REG_REP_Z,
BMC150_MAGN_REG_REP_DATAMASK,
BMC150_MAGN_REPZ_TO_REGVAL
(val));
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static ssize_t bmc150_magn_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct bmc150_magn_data *data = iio_priv(indio_dev);
size_t len = 0;
u8 i;
for (i = 0; i < ARRAY_SIZE(bmc150_magn_samp_freq_table); i++) {
if (bmc150_magn_samp_freq_table[i].freq > data->max_odr)
break;
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ",
bmc150_magn_samp_freq_table[i].freq);
}
buf[len - 1] = '\n';
return len;
}
static irqreturn_t bmc150_magn_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bmc150_magn_read_xyz(data, data->buffer);
if (ret < 0)
goto err;
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
mutex_unlock(&data->mutex);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bmc150_magn_init(struct bmc150_magn_data *data)
{
int ret, chip_id;
struct bmc150_magn_preset preset;
ret = bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SUSPEND,
false);
if (ret < 0) {
dev_err(&data->client->dev,
"Failed to bring up device from suspend mode\n");
return ret;
}
ret = regmap_read(data->regmap, BMC150_MAGN_REG_CHIP_ID, &chip_id);
if (ret < 0) {
dev_err(&data->client->dev, "Failed reading chip id\n");
goto err_poweroff;
}
if (chip_id != BMC150_MAGN_CHIP_ID_VAL) {
dev_err(&data->client->dev, "Invalid chip id 0x%x\n", chip_id);
ret = -ENODEV;
goto err_poweroff;
}
dev_dbg(&data->client->dev, "Chip id %x\n", chip_id);
preset = bmc150_magn_presets_table[BMC150_MAGN_DEFAULT_PRESET];
ret = bmc150_magn_set_odr(data, preset.odr);
if (ret < 0) {
dev_err(&data->client->dev, "Failed to set ODR to %d\n",
preset.odr);
goto err_poweroff;
}
ret = regmap_write(data->regmap, BMC150_MAGN_REG_REP_XY,
BMC150_MAGN_REPXY_TO_REGVAL(preset.rep_xy));
if (ret < 0) {
dev_err(&data->client->dev, "Failed to set REP XY to %d\n",
preset.rep_xy);
goto err_poweroff;
}
ret = regmap_write(data->regmap, BMC150_MAGN_REG_REP_Z,
BMC150_MAGN_REPZ_TO_REGVAL(preset.rep_z));
if (ret < 0) {
dev_err(&data->client->dev, "Failed to set REP Z to %d\n",
preset.rep_z);
goto err_poweroff;
}
ret = bmc150_magn_set_max_odr(data, preset.rep_xy, preset.rep_z,
preset.odr);
if (ret < 0)
goto err_poweroff;
ret = bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_NORMAL,
true);
if (ret < 0) {
dev_err(&data->client->dev, "Failed to power on device\n");
goto err_poweroff;
}
return 0;
err_poweroff:
bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SUSPEND, true);
return ret;
}
static int bmc150_magn_reset_intr(struct bmc150_magn_data *data)
{
int tmp;
return regmap_read(data->regmap, BMC150_MAGN_REG_X_L, &tmp);
}
static int bmc150_magn_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
if (!data->dready_trigger_on)
return 0;
mutex_lock(&data->mutex);
ret = bmc150_magn_reset_intr(data);
mutex_unlock(&data->mutex);
return ret;
}
static int bmc150_magn_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&data->mutex);
if (state == data->dready_trigger_on)
goto err_unlock;
ret = regmap_update_bits(data->regmap, BMC150_MAGN_REG_INT_DRDY,
BMC150_MAGN_MASK_DRDY_EN,
state << BMC150_MAGN_SHIFT_DRDY_EN);
if (ret < 0)
goto err_unlock;
data->dready_trigger_on = state;
if (state) {
ret = bmc150_magn_reset_intr(data);
if (ret < 0)
goto err_unlock;
}
mutex_unlock(&data->mutex);
return 0;
err_unlock:
mutex_unlock(&data->mutex);
return ret;
}
static int bmc150_magn_buffer_preenable(struct iio_dev *indio_dev)
{
struct bmc150_magn_data *data = iio_priv(indio_dev);
return bmc150_magn_set_power_state(data, true);
}
static int bmc150_magn_buffer_postdisable(struct iio_dev *indio_dev)
{
struct bmc150_magn_data *data = iio_priv(indio_dev);
return bmc150_magn_set_power_state(data, false);
}
static const char *bmc150_magn_match_acpi_device(struct device *dev)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
return dev_name(dev);
}
static int bmc150_magn_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bmc150_magn_data *data;
struct iio_dev *indio_dev;
const char *name = NULL;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
if (id)
name = id->name;
else if (ACPI_HANDLE(&client->dev))
name = bmc150_magn_match_acpi_device(&client->dev);
else
return -ENOSYS;
mutex_init(&data->mutex);
data->regmap = devm_regmap_init_i2c(client, &bmc150_magn_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "Failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = bmc150_magn_init(data);
if (ret < 0)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = bmc150_magn_channels;
indio_dev->num_channels = ARRAY_SIZE(bmc150_magn_channels);
indio_dev->available_scan_masks = bmc150_magn_scan_masks;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bmc150_magn_info;
if (client->irq > 0) {
data->dready_trig = devm_iio_trigger_alloc(&client->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->dready_trig) {
ret = -ENOMEM;
dev_err(&client->dev, "iio trigger alloc failed\n");
goto err_poweroff;
}
data->dready_trig->dev.parent = &client->dev;
data->dready_trig->ops = &bmc150_magn_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
ret = iio_trigger_register(data->dready_trig);
if (ret) {
dev_err(&client->dev, "iio trigger register failed\n");
goto err_poweroff;
}
ret = request_threaded_irq(client->irq,
iio_trigger_generic_data_rdy_poll,
NULL,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
BMC150_MAGN_IRQ_NAME,
data->dready_trig);
if (ret < 0) {
dev_err(&client->dev, "request irq %d failed\n",
client->irq);
goto err_trigger_unregister;
}
}
ret = iio_triggered_buffer_setup(indio_dev,
iio_pollfunc_store_time,
bmc150_magn_trigger_handler,
&bmc150_magn_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev,
"iio triggered buffer setup failed\n");
goto err_free_irq;
}
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto err_buffer_cleanup;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
BMC150_MAGN_AUTO_SUSPEND_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
dev_dbg(&indio_dev->dev, "Registered device %s\n", name);
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_free_irq:
if (client->irq > 0)
free_irq(client->irq, data->dready_trig);
err_trigger_unregister:
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
err_poweroff:
bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SUSPEND, true);
return ret;
}
static int bmc150_magn_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bmc150_magn_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
iio_triggered_buffer_cleanup(indio_dev);
if (client->irq > 0)
free_irq(data->client->irq, data->dready_trig);
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
mutex_lock(&data->mutex);
bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SUSPEND, true);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_magn_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SLEEP,
true);
mutex_unlock(&data->mutex);
if (ret < 0) {
dev_err(&data->client->dev, "powering off device failed\n");
return ret;
}
return 0;
}
static int bmc150_magn_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_magn_data *data = iio_priv(indio_dev);
return bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_NORMAL,
true);
}
static int bmc150_magn_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_SLEEP,
true);
mutex_unlock(&data->mutex);
return ret;
}
static int bmc150_magn_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_magn_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bmc150_magn_set_power_mode(data, BMC150_MAGN_POWER_MODE_NORMAL,
true);
mutex_unlock(&data->mutex);
return ret;
}
