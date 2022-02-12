static int mma8452_drdy(struct mma8452_data *data)
{
int tries = 150;
while (tries-- > 0) {
int ret = i2c_smbus_read_byte_data(data->client,
MMA8452_STATUS);
if (ret < 0)
return ret;
if ((ret & MMA8452_STATUS_DRDY) == MMA8452_STATUS_DRDY)
return 0;
msleep(20);
}
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
static int mma8452_set_runtime_pm_state(struct i2c_client *client, bool on)
{
#ifdef CONFIG_PM
int ret;
if (on) {
ret = pm_runtime_get_sync(&client->dev);
} else {
pm_runtime_mark_last_busy(&client->dev);
ret = pm_runtime_put_autosuspend(&client->dev);
}
if (ret < 0) {
dev_err(&client->dev,
"failed to change power state to %d\n", on);
if (on)
pm_runtime_put_noidle(&client->dev);
return ret;
}
#endif
return 0;
}
static int mma8452_read(struct mma8452_data *data, __be16 buf[3])
{
int ret = mma8452_drdy(data);
if (ret < 0)
return ret;
ret = mma8452_set_runtime_pm_state(data->client, true);
if (ret)
return ret;
ret = i2c_smbus_read_i2c_block_data(data->client, MMA8452_OUT_X,
3 * sizeof(__be16), (u8 *)buf);
ret = mma8452_set_runtime_pm_state(data->client, false);
return ret;
}
static unsigned int mma8452_get_odr_index(struct mma8452_data *data)
{
return (data->ctrl_reg1 & MMA8452_CTRL_DR_MASK) >>
MMA8452_CTRL_DR_SHIFT;
}
static int mma8452_get_power_mode(struct mma8452_data *data)
{
int reg;
reg = i2c_smbus_read_byte_data(data->client,
MMA8452_CTRL_REG2);
if (reg < 0)
return reg;
return ((reg & MMA8452_CTRL_REG2_MODS_MASK) >>
MMA8452_CTRL_REG2_MODS_SHIFT);
}
static ssize_t mma8452_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return mma8452_show_int_plus_micros(buf, mma8452_samp_freq,
ARRAY_SIZE(mma8452_samp_freq));
}
static ssize_t mma8452_show_scale_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct mma8452_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return mma8452_show_int_plus_micros(buf, data->chip_info->mma_scales,
ARRAY_SIZE(data->chip_info->mma_scales));
}
static ssize_t mma8452_show_hp_cutoff_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct mma8452_data *data = iio_priv(indio_dev);
int i, j;
i = mma8452_get_odr_index(data);
j = mma8452_get_power_mode(data);
if (j < 0)
return j;
return mma8452_show_int_plus_micros(buf, mma8452_hp_filter_cutoff[j][i],
ARRAY_SIZE(mma8452_hp_filter_cutoff[0][0]));
}
static ssize_t mma8452_show_os_ratio_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct mma8452_data *data = iio_priv(indio_dev);
int i = mma8452_get_odr_index(data);
int j;
u16 val = 0;
size_t len = 0;
for (j = 0; j < ARRAY_SIZE(mma8452_os_ratio); j++) {
if (val == mma8452_os_ratio[j][i])
continue;
val = mma8452_os_ratio[j][i];
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ", val);
}
buf[len - 1] = '\n';
return len;
}
static int mma8452_get_samp_freq_index(struct mma8452_data *data,
int val, int val2)
{
return mma8452_get_int_plus_micros_index(mma8452_samp_freq,
ARRAY_SIZE(mma8452_samp_freq),
val, val2);
}
static int mma8452_get_scale_index(struct mma8452_data *data, int val, int val2)
{
return mma8452_get_int_plus_micros_index(data->chip_info->mma_scales,
ARRAY_SIZE(data->chip_info->mma_scales), val, val2);
}
static int mma8452_get_hp_filter_index(struct mma8452_data *data,
int val, int val2)
{
int i, j;
i = mma8452_get_odr_index(data);
j = mma8452_get_power_mode(data);
if (j < 0)
return j;
return mma8452_get_int_plus_micros_index(mma8452_hp_filter_cutoff[j][i],
ARRAY_SIZE(mma8452_hp_filter_cutoff[0][0]), val, val2);
}
static int mma8452_read_hp_filter(struct mma8452_data *data, int *hz, int *uHz)
{
int j, i, ret;
ret = i2c_smbus_read_byte_data(data->client, MMA8452_HP_FILTER_CUTOFF);
if (ret < 0)
return ret;
i = mma8452_get_odr_index(data);
j = mma8452_get_power_mode(data);
if (j < 0)
return j;
ret &= MMA8452_HP_FILTER_CUTOFF_SEL_MASK;
*hz = mma8452_hp_filter_cutoff[j][i][ret][0];
*uHz = mma8452_hp_filter_cutoff[j][i][ret][1];
return 0;
}
static int mma8452_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mma8452_data *data = iio_priv(indio_dev);
__be16 buffer[3];
int i, ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
mutex_lock(&data->lock);
ret = mma8452_read(data, buffer);
mutex_unlock(&data->lock);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = sign_extend32(be16_to_cpu(
buffer[chan->scan_index]) >> chan->scan_type.shift,
chan->scan_type.realbits - 1);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
i = data->data_cfg & MMA8452_DATA_CFG_FS_MASK;
*val = data->chip_info->mma_scales[i][0];
*val2 = data->chip_info->mma_scales[i][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
i = mma8452_get_odr_index(data);
*val = mma8452_samp_freq[i][0];
*val2 = mma8452_samp_freq[i][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_CALIBBIAS:
ret = i2c_smbus_read_byte_data(data->client,
MMA8452_OFF_X +
chan->scan_index);
if (ret < 0)
return ret;
*val = sign_extend32(ret, 7);
return IIO_VAL_INT;
case IIO_CHAN_INFO_HIGH_PASS_FILTER_3DB_FREQUENCY:
if (data->data_cfg & MMA8452_DATA_CFG_HPF_MASK) {
ret = mma8452_read_hp_filter(data, val, val2);
if (ret < 0)
return ret;
} else {
*val = 0;
*val2 = 0;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
ret = mma8452_get_power_mode(data);
if (ret < 0)
return ret;
i = mma8452_get_odr_index(data);
*val = mma8452_os_ratio[ret][i];
return IIO_VAL_INT;
}
return -EINVAL;
}
static int mma8452_standby(struct mma8452_data *data)
{
return i2c_smbus_write_byte_data(data->client, MMA8452_CTRL_REG1,
data->ctrl_reg1 & ~MMA8452_CTRL_ACTIVE);
}
static int mma8452_active(struct mma8452_data *data)
{
return i2c_smbus_write_byte_data(data->client, MMA8452_CTRL_REG1,
data->ctrl_reg1);
}
static int mma8452_is_active(struct mma8452_data *data)
{
int reg;
reg = i2c_smbus_read_byte_data(data->client, MMA8452_CTRL_REG1);
if (reg < 0)
return reg;
return reg & MMA8452_CTRL_ACTIVE;
}
static int mma8452_change_config(struct mma8452_data *data, u8 reg, u8 val)
{
int ret;
int is_active;
mutex_lock(&data->lock);
is_active = mma8452_is_active(data);
if (is_active < 0) {
ret = is_active;
goto fail;
}
if (is_active > 0) {
ret = mma8452_standby(data);
if (ret < 0)
goto fail;
}
ret = i2c_smbus_write_byte_data(data->client, reg, val);
if (ret < 0)
goto fail;
if (is_active > 0) {
ret = mma8452_active(data);
if (ret < 0)
goto fail;
}
ret = 0;
fail:
mutex_unlock(&data->lock);
return ret;
}
static int mma8452_set_power_mode(struct mma8452_data *data, u8 mode)
{
int reg;
reg = i2c_smbus_read_byte_data(data->client,
MMA8452_CTRL_REG2);
if (reg < 0)
return reg;
reg &= ~MMA8452_CTRL_REG2_MODS_MASK;
reg |= mode << MMA8452_CTRL_REG2_MODS_SHIFT;
return mma8452_change_config(data, MMA8452_CTRL_REG2, reg);
}
static int mma8452_freefall_mode_enabled(struct mma8452_data *data)
{
int val;
const struct mma_chip_info *chip = data->chip_info;
val = i2c_smbus_read_byte_data(data->client, chip->ev_cfg);
if (val < 0)
return val;
return !(val & MMA8452_FF_MT_CFG_OAE);
}
static int mma8452_set_freefall_mode(struct mma8452_data *data, bool state)
{
int val;
const struct mma_chip_info *chip = data->chip_info;
if ((state && mma8452_freefall_mode_enabled(data)) ||
(!state && !(mma8452_freefall_mode_enabled(data))))
return 0;
val = i2c_smbus_read_byte_data(data->client, chip->ev_cfg);
if (val < 0)
return val;
if (state) {
val |= BIT(idx_x + chip->ev_cfg_chan_shift);
val |= BIT(idx_y + chip->ev_cfg_chan_shift);
val |= BIT(idx_z + chip->ev_cfg_chan_shift);
val &= ~MMA8452_FF_MT_CFG_OAE;
} else {
val &= ~BIT(idx_x + chip->ev_cfg_chan_shift);
val &= ~BIT(idx_y + chip->ev_cfg_chan_shift);
val &= ~BIT(idx_z + chip->ev_cfg_chan_shift);
val |= MMA8452_FF_MT_CFG_OAE;
}
return mma8452_change_config(data, chip->ev_cfg, val);
}
static int mma8452_set_hp_filter_frequency(struct mma8452_data *data,
int val, int val2)
{
int i, reg;
i = mma8452_get_hp_filter_index(data, val, val2);
if (i < 0)
return i;
reg = i2c_smbus_read_byte_data(data->client,
MMA8452_HP_FILTER_CUTOFF);
if (reg < 0)
return reg;
reg &= ~MMA8452_HP_FILTER_CUTOFF_SEL_MASK;
reg |= i;
return mma8452_change_config(data, MMA8452_HP_FILTER_CUTOFF, reg);
}
static int mma8452_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mma8452_data *data = iio_priv(indio_dev);
int i, ret;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
i = mma8452_get_samp_freq_index(data, val, val2);
if (i < 0) {
ret = i;
break;
}
data->ctrl_reg1 &= ~MMA8452_CTRL_DR_MASK;
data->ctrl_reg1 |= i << MMA8452_CTRL_DR_SHIFT;
ret = mma8452_change_config(data, MMA8452_CTRL_REG1,
data->ctrl_reg1);
break;
case IIO_CHAN_INFO_SCALE:
i = mma8452_get_scale_index(data, val, val2);
if (i < 0) {
ret = i;
break;
}
data->data_cfg &= ~MMA8452_DATA_CFG_FS_MASK;
data->data_cfg |= i;
ret = mma8452_change_config(data, MMA8452_DATA_CFG,
data->data_cfg);
break;
case IIO_CHAN_INFO_CALIBBIAS:
if (val < -128 || val > 127) {
ret = -EINVAL;
break;
}
ret = mma8452_change_config(data,
MMA8452_OFF_X + chan->scan_index,
val);
break;
case IIO_CHAN_INFO_HIGH_PASS_FILTER_3DB_FREQUENCY:
if (val == 0 && val2 == 0) {
data->data_cfg &= ~MMA8452_DATA_CFG_HPF_MASK;
} else {
data->data_cfg |= MMA8452_DATA_CFG_HPF_MASK;
ret = mma8452_set_hp_filter_frequency(data, val, val2);
if (ret < 0)
break;
}
ret = mma8452_change_config(data, MMA8452_DATA_CFG,
data->data_cfg);
break;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
ret = mma8452_get_odr_index(data);
for (i = 0; i < ARRAY_SIZE(mma8452_os_ratio); i++) {
if (mma8452_os_ratio[i][ret] == val) {
ret = mma8452_set_power_mode(data, i);
break;
}
}
break;
default:
ret = -EINVAL;
break;
}
iio_device_release_direct_mode(indio_dev);
return ret;
}
static int mma8452_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct mma8452_data *data = iio_priv(indio_dev);
int ret, us, power_mode;
switch (info) {
case IIO_EV_INFO_VALUE:
ret = i2c_smbus_read_byte_data(data->client,
data->chip_info->ev_ths);
if (ret < 0)
return ret;
*val = ret & data->chip_info->ev_ths_mask;
return IIO_VAL_INT;
case IIO_EV_INFO_PERIOD:
ret = i2c_smbus_read_byte_data(data->client,
data->chip_info->ev_count);
if (ret < 0)
return ret;
power_mode = mma8452_get_power_mode(data);
if (power_mode < 0)
return power_mode;
us = ret * mma8452_transient_time_step_us[power_mode][
mma8452_get_odr_index(data)];
*val = us / USEC_PER_SEC;
*val2 = us % USEC_PER_SEC;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_EV_INFO_HIGH_PASS_FILTER_3DB:
ret = i2c_smbus_read_byte_data(data->client,
MMA8452_TRANSIENT_CFG);
if (ret < 0)
return ret;
if (ret & MMA8452_TRANSIENT_CFG_HPF_BYP) {
*val = 0;
*val2 = 0;
} else {
ret = mma8452_read_hp_filter(data, val, val2);
if (ret < 0)
return ret;
}
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int mma8452_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct mma8452_data *data = iio_priv(indio_dev);
int ret, reg, steps;
switch (info) {
case IIO_EV_INFO_VALUE:
if (val < 0 || val > MMA8452_TRANSIENT_THS_MASK)
return -EINVAL;
return mma8452_change_config(data, data->chip_info->ev_ths,
val);
case IIO_EV_INFO_PERIOD:
ret = mma8452_get_power_mode(data);
if (ret < 0)
return ret;
steps = (val * USEC_PER_SEC + val2) /
mma8452_transient_time_step_us[ret][
mma8452_get_odr_index(data)];
if (steps < 0 || steps > 0xff)
return -EINVAL;
return mma8452_change_config(data, data->chip_info->ev_count,
steps);
case IIO_EV_INFO_HIGH_PASS_FILTER_3DB:
reg = i2c_smbus_read_byte_data(data->client,
MMA8452_TRANSIENT_CFG);
if (reg < 0)
return reg;
if (val == 0 && val2 == 0) {
reg |= MMA8452_TRANSIENT_CFG_HPF_BYP;
} else {
reg &= ~MMA8452_TRANSIENT_CFG_HPF_BYP;
ret = mma8452_set_hp_filter_frequency(data, val, val2);
if (ret < 0)
return ret;
}
return mma8452_change_config(data, MMA8452_TRANSIENT_CFG, reg);
default:
return -EINVAL;
}
}
static int mma8452_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct mma8452_data *data = iio_priv(indio_dev);
const struct mma_chip_info *chip = data->chip_info;
int ret;
switch (dir) {
case IIO_EV_DIR_FALLING:
return mma8452_freefall_mode_enabled(data);
case IIO_EV_DIR_RISING:
if (mma8452_freefall_mode_enabled(data))
return 0;
ret = i2c_smbus_read_byte_data(data->client,
data->chip_info->ev_cfg);
if (ret < 0)
return ret;
return !!(ret & BIT(chan->scan_index +
chip->ev_cfg_chan_shift));
default:
return -EINVAL;
}
}
static int mma8452_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct mma8452_data *data = iio_priv(indio_dev);
const struct mma_chip_info *chip = data->chip_info;
int val, ret;
ret = mma8452_set_runtime_pm_state(data->client, state);
if (ret)
return ret;
switch (dir) {
case IIO_EV_DIR_FALLING:
return mma8452_set_freefall_mode(data, state);
case IIO_EV_DIR_RISING:
val = i2c_smbus_read_byte_data(data->client, chip->ev_cfg);
if (val < 0)
return val;
if (state) {
if (mma8452_freefall_mode_enabled(data)) {
val &= ~BIT(idx_x + chip->ev_cfg_chan_shift);
val &= ~BIT(idx_y + chip->ev_cfg_chan_shift);
val &= ~BIT(idx_z + chip->ev_cfg_chan_shift);
val |= MMA8452_FF_MT_CFG_OAE;
}
val |= BIT(chan->scan_index + chip->ev_cfg_chan_shift);
} else {
if (mma8452_freefall_mode_enabled(data))
return 0;
val &= ~BIT(chan->scan_index + chip->ev_cfg_chan_shift);
}
val |= chip->ev_cfg_ele;
return mma8452_change_config(data, chip->ev_cfg, val);
default:
return -EINVAL;
}
}
static void mma8452_transient_interrupt(struct iio_dev *indio_dev)
{
struct mma8452_data *data = iio_priv(indio_dev);
s64 ts = iio_get_time_ns(indio_dev);
int src;
src = i2c_smbus_read_byte_data(data->client, data->chip_info->ev_src);
if (src < 0)
return;
if (mma8452_freefall_mode_enabled(data)) {
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL, 0,
IIO_MOD_X_AND_Y_AND_Z,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_FALLING),
ts);
return;
}
if (src & data->chip_info->ev_src_xe)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL, 0, IIO_MOD_X,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
ts);
if (src & data->chip_info->ev_src_ye)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL, 0, IIO_MOD_Y,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
ts);
if (src & data->chip_info->ev_src_ze)
iio_push_event(indio_dev,
IIO_MOD_EVENT_CODE(IIO_ACCEL, 0, IIO_MOD_Z,
IIO_EV_TYPE_MAG,
IIO_EV_DIR_RISING),
ts);
}
static irqreturn_t mma8452_interrupt(int irq, void *p)
{
struct iio_dev *indio_dev = p;
struct mma8452_data *data = iio_priv(indio_dev);
const struct mma_chip_info *chip = data->chip_info;
int ret = IRQ_NONE;
int src;
src = i2c_smbus_read_byte_data(data->client, MMA8452_INT_SRC);
if (src < 0)
return IRQ_NONE;
if (src & MMA8452_INT_DRDY) {
iio_trigger_poll_chained(indio_dev->trig);
ret = IRQ_HANDLED;
}
if ((src & MMA8452_INT_TRANS &&
chip->ev_src == MMA8452_TRANSIENT_SRC) ||
(src & MMA8452_INT_FF_MT &&
chip->ev_src == MMA8452_FF_MT_SRC)) {
mma8452_transient_interrupt(indio_dev);
ret = IRQ_HANDLED;
}
return ret;
}
static irqreturn_t mma8452_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct mma8452_data *data = iio_priv(indio_dev);
u8 buffer[16];
int ret;
ret = mma8452_read(data, (__be16 *)buffer);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, buffer,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int mma8452_reg_access_dbg(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
int ret;
struct mma8452_data *data = iio_priv(indio_dev);
if (reg > MMA8452_MAX_REG)
return -EINVAL;
if (!readval)
return mma8452_change_config(data, reg, writeval);
ret = i2c_smbus_read_byte_data(data->client, reg);
if (ret < 0)
return ret;
*readval = ret;
return 0;
}
static int mma8452_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct mma8452_data *data = iio_priv(indio_dev);
int reg, ret;
ret = mma8452_set_runtime_pm_state(data->client, state);
if (ret)
return ret;
reg = i2c_smbus_read_byte_data(data->client, MMA8452_CTRL_REG4);
if (reg < 0)
return reg;
if (state)
reg |= MMA8452_INT_DRDY;
else
reg &= ~MMA8452_INT_DRDY;
return mma8452_change_config(data, MMA8452_CTRL_REG4, reg);
}
static int mma8452_trigger_setup(struct iio_dev *indio_dev)
{
struct mma8452_data *data = iio_priv(indio_dev);
struct iio_trigger *trig;
int ret;
trig = devm_iio_trigger_alloc(&data->client->dev, "%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!trig)
return -ENOMEM;
trig->dev.parent = &data->client->dev;
trig->ops = &mma8452_trigger_ops;
iio_trigger_set_drvdata(trig, indio_dev);
ret = iio_trigger_register(trig);
if (ret)
return ret;
indio_dev->trig = trig;
return 0;
}
static void mma8452_trigger_cleanup(struct iio_dev *indio_dev)
{
if (indio_dev->trig)
iio_trigger_unregister(indio_dev->trig);
}
static int mma8452_reset(struct i2c_client *client)
{
int i;
int ret;
ret = i2c_smbus_write_byte_data(client, MMA8452_CTRL_REG2,
MMA8452_CTRL_REG2_RST);
if (ret < 0)
return ret;
for (i = 0; i < 10; i++) {
usleep_range(100, 200);
ret = i2c_smbus_read_byte_data(client, MMA8452_CTRL_REG2);
if (ret == -EIO)
continue;
if (ret < 0)
return ret;
if (!(ret & MMA8452_CTRL_REG2_RST))
return 0;
}
return -ETIMEDOUT;
}
static int mma8452_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mma8452_data *data;
struct iio_dev *indio_dev;
int ret;
const struct of_device_id *match;
match = of_match_device(mma8452_dt_ids, &client->dev);
if (!match) {
dev_err(&client->dev, "unknown device model\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
mutex_init(&data->lock);
data->chip_info = match->data;
ret = i2c_smbus_read_byte_data(client, MMA8452_WHO_AM_I);
if (ret < 0)
return ret;
switch (ret) {
case MMA8451_DEVICE_ID:
case MMA8452_DEVICE_ID:
case MMA8453_DEVICE_ID:
case MMA8652_DEVICE_ID:
case MMA8653_DEVICE_ID:
case FXLS8471_DEVICE_ID:
if (ret == data->chip_info->chip_id)
break;
default:
return -ENODEV;
}
dev_info(&client->dev, "registering %s accelerometer; ID 0x%x\n",
match->compatible, data->chip_info->chip_id);
i2c_set_clientdata(client, indio_dev);
indio_dev->info = &mma8452_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = data->chip_info->channels;
indio_dev->num_channels = data->chip_info->num_channels;
indio_dev->available_scan_masks = mma8452_scan_masks;
ret = mma8452_reset(client);
if (ret < 0)
return ret;
data->data_cfg = MMA8452_DATA_CFG_FS_2G;
ret = i2c_smbus_write_byte_data(client, MMA8452_DATA_CFG,
data->data_cfg);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, MMA8452_TRANSIENT_THS,
MMA8452_TRANSIENT_THS_MASK);
if (ret < 0)
return ret;
if (client->irq) {
int supported_interrupts = MMA8452_INT_DRDY |
MMA8452_INT_TRANS |
MMA8452_INT_FF_MT;
int enabled_interrupts = MMA8452_INT_TRANS |
MMA8452_INT_FF_MT;
int irq2;
irq2 = of_irq_get_byname(client->dev.of_node, "INT2");
if (irq2 == client->irq) {
dev_dbg(&client->dev, "using interrupt line INT2\n");
} else {
ret = i2c_smbus_write_byte_data(client,
MMA8452_CTRL_REG5,
supported_interrupts);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "using interrupt line INT1\n");
}
ret = i2c_smbus_write_byte_data(client,
MMA8452_CTRL_REG4,
enabled_interrupts);
if (ret < 0)
return ret;
ret = mma8452_trigger_setup(indio_dev);
if (ret < 0)
return ret;
}
data->ctrl_reg1 = MMA8452_CTRL_ACTIVE |
(MMA8452_CTRL_DR_DEFAULT << MMA8452_CTRL_DR_SHIFT);
ret = i2c_smbus_write_byte_data(client, MMA8452_CTRL_REG1,
data->ctrl_reg1);
if (ret < 0)
goto trigger_cleanup;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
mma8452_trigger_handler, NULL);
if (ret < 0)
goto trigger_cleanup;
if (client->irq) {
ret = devm_request_threaded_irq(&client->dev,
client->irq,
NULL, mma8452_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
client->name, indio_dev);
if (ret)
goto buffer_cleanup;
}
ret = pm_runtime_set_active(&client->dev);
if (ret < 0)
goto buffer_cleanup;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
MMA8452_AUTO_SUSPEND_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0)
goto buffer_cleanup;
ret = mma8452_set_freefall_mode(data, false);
if (ret < 0)
goto buffer_cleanup;
return 0;
buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
trigger_cleanup:
mma8452_trigger_cleanup(indio_dev);
return ret;
}
static int mma8452_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
iio_triggered_buffer_cleanup(indio_dev);
mma8452_trigger_cleanup(indio_dev);
mma8452_standby(iio_priv(indio_dev));
return 0;
}
static int mma8452_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma8452_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->lock);
ret = mma8452_standby(data);
mutex_unlock(&data->lock);
if (ret < 0) {
dev_err(&data->client->dev, "powering off device failed\n");
return -EAGAIN;
}
return 0;
}
static int mma8452_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma8452_data *data = iio_priv(indio_dev);
int ret, sleep_val;
ret = mma8452_active(data);
if (ret < 0)
return ret;
ret = mma8452_get_odr_index(data);
sleep_val = 1000 / mma8452_samp_freq[ret][0];
if (sleep_val < 20)
usleep_range(sleep_val * 1000, 20000);
else
msleep_interruptible(sleep_val);
return 0;
}
static int mma8452_suspend(struct device *dev)
{
return mma8452_standby(iio_priv(i2c_get_clientdata(
to_i2c_client(dev))));
}
static int mma8452_resume(struct device *dev)
{
return mma8452_active(iio_priv(i2c_get_clientdata(
to_i2c_client(dev))));
}
