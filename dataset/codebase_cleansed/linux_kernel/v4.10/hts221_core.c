static int hts221_write_with_mask(struct hts221_hw *hw, u8 addr, u8 mask,
u8 val)
{
u8 data;
int err;
mutex_lock(&hw->lock);
err = hw->tf->read(hw->dev, addr, sizeof(data), &data);
if (err < 0) {
dev_err(hw->dev, "failed to read %02x register\n", addr);
goto unlock;
}
data = (data & ~mask) | (val & mask);
err = hw->tf->write(hw->dev, addr, sizeof(data), &data);
if (err < 0)
dev_err(hw->dev, "failed to write %02x register\n", addr);
unlock:
mutex_unlock(&hw->lock);
return err;
}
static int hts221_check_whoami(struct hts221_hw *hw)
{
u8 data;
int err;
err = hw->tf->read(hw->dev, HTS221_REG_WHOAMI_ADDR, sizeof(data),
&data);
if (err < 0) {
dev_err(hw->dev, "failed to read whoami register\n");
return err;
}
if (data != HTS221_REG_WHOAMI_VAL) {
dev_err(hw->dev, "wrong whoami {%02x vs %02x}\n",
data, HTS221_REG_WHOAMI_VAL);
return -ENODEV;
}
return 0;
}
int hts221_config_drdy(struct hts221_hw *hw, bool enable)
{
u8 val = enable ? BIT(2) : 0;
int err;
err = hts221_write_with_mask(hw, HTS221_REG_CNTRL3_ADDR,
HTS221_DRDY_MASK, val);
return err < 0 ? err : 0;
}
static int hts221_update_odr(struct hts221_hw *hw, u8 odr)
{
int i, err;
u8 val;
for (i = 0; i < ARRAY_SIZE(hts221_odr_table); i++)
if (hts221_odr_table[i].hz == odr)
break;
if (i == ARRAY_SIZE(hts221_odr_table))
return -EINVAL;
val = HTS221_ENABLE_SENSOR | HTS221_BDU_MASK | hts221_odr_table[i].val;
err = hts221_write_with_mask(hw, HTS221_REG_CNTRL1_ADDR,
HTS221_ODR_MASK, val);
if (err < 0)
return err;
hw->odr = odr;
return 0;
}
static int hts221_update_avg(struct hts221_hw *hw,
enum hts221_sensor_type type,
u16 val)
{
int i, err;
const struct hts221_avg *avg = &hts221_avg_list[type];
for (i = 0; i < HTS221_AVG_DEPTH; i++)
if (avg->avg_avl[i].avg == val)
break;
if (i == HTS221_AVG_DEPTH)
return -EINVAL;
err = hts221_write_with_mask(hw, avg->addr, avg->mask,
avg->avg_avl[i].val);
if (err < 0)
return err;
hw->sensors[type].cur_avg_idx = i;
return 0;
}
static ssize_t hts221_sysfs_sampling_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int i;
ssize_t len = 0;
for (i = 0; i < ARRAY_SIZE(hts221_odr_table); i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ",
hts221_odr_table[i].hz);
buf[len - 1] = '\n';
return len;
}
static ssize_t
hts221_sysfs_rh_oversampling_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
const struct hts221_avg *avg = &hts221_avg_list[HTS221_SENSOR_H];
ssize_t len = 0;
int i;
for (i = 0; i < ARRAY_SIZE(avg->avg_avl); i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ",
avg->avg_avl[i].avg);
buf[len - 1] = '\n';
return len;
}
static ssize_t
hts221_sysfs_temp_oversampling_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
const struct hts221_avg *avg = &hts221_avg_list[HTS221_SENSOR_T];
ssize_t len = 0;
int i;
for (i = 0; i < ARRAY_SIZE(avg->avg_avl); i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ",
avg->avg_avl[i].avg);
buf[len - 1] = '\n';
return len;
}
int hts221_power_on(struct hts221_hw *hw)
{
return hts221_update_odr(hw, hw->odr);
}
int hts221_power_off(struct hts221_hw *hw)
{
u8 data[] = {0x00, 0x00};
return hw->tf->write(hw->dev, HTS221_REG_CNTRL1_ADDR, sizeof(data),
data);
}
static int hts221_parse_temp_caldata(struct hts221_hw *hw)
{
int err, *slope, *b_gen;
s16 cal_x0, cal_x1, cal_y0, cal_y1;
u8 cal0, cal1;
err = hw->tf->read(hw->dev, HTS221_REG_0T_CAL_Y_H,
sizeof(cal0), &cal0);
if (err < 0)
return err;
err = hw->tf->read(hw->dev, HTS221_REG_T1_T0_CAL_Y_H,
sizeof(cal1), &cal1);
if (err < 0)
return err;
cal_y0 = (le16_to_cpu(cal1 & 0x3) << 8) | cal0;
err = hw->tf->read(hw->dev, HTS221_REG_1T_CAL_Y_H,
sizeof(cal0), &cal0);
if (err < 0)
return err;
cal_y1 = (((cal1 & 0xc) >> 2) << 8) | cal0;
err = hw->tf->read(hw->dev, HTS221_REG_0T_CAL_X_L, sizeof(cal_x0),
(u8 *)&cal_x0);
if (err < 0)
return err;
cal_x0 = le16_to_cpu(cal_x0);
err = hw->tf->read(hw->dev, HTS221_REG_1T_CAL_X_L, sizeof(cal_x1),
(u8 *)&cal_x1);
if (err < 0)
return err;
cal_x1 = le16_to_cpu(cal_x1);
slope = &hw->sensors[HTS221_SENSOR_T].slope;
b_gen = &hw->sensors[HTS221_SENSOR_T].b_gen;
*slope = ((cal_y1 - cal_y0) * 8000) / (cal_x1 - cal_x0);
*b_gen = (((s32)cal_x1 * cal_y0 - (s32)cal_x0 * cal_y1) * 1000) /
(cal_x1 - cal_x0);
*b_gen *= 8;
return 0;
}
static int hts221_parse_rh_caldata(struct hts221_hw *hw)
{
int err, *slope, *b_gen;
s16 cal_x0, cal_x1, cal_y0, cal_y1;
u8 data;
err = hw->tf->read(hw->dev, HTS221_REG_0RH_CAL_Y_H, sizeof(data),
&data);
if (err < 0)
return err;
cal_y0 = data;
err = hw->tf->read(hw->dev, HTS221_REG_1RH_CAL_Y_H, sizeof(data),
&data);
if (err < 0)
return err;
cal_y1 = data;
err = hw->tf->read(hw->dev, HTS221_REG_0RH_CAL_X_H, sizeof(cal_x0),
(u8 *)&cal_x0);
if (err < 0)
return err;
cal_x0 = le16_to_cpu(cal_x0);
err = hw->tf->read(hw->dev, HTS221_REG_1RH_CAL_X_H, sizeof(cal_x1),
(u8 *)&cal_x1);
if (err < 0)
return err;
cal_x1 = le16_to_cpu(cal_x1);
slope = &hw->sensors[HTS221_SENSOR_H].slope;
b_gen = &hw->sensors[HTS221_SENSOR_H].b_gen;
*slope = ((cal_y1 - cal_y0) * 8000) / (cal_x1 - cal_x0);
*b_gen = (((s32)cal_x1 * cal_y0 - (s32)cal_x0 * cal_y1) * 1000) /
(cal_x1 - cal_x0);
*b_gen *= 8;
return 0;
}
static int hts221_get_sensor_scale(struct hts221_hw *hw,
enum iio_chan_type ch_type,
int *val, int *val2)
{
s64 tmp;
s32 rem, div, data;
switch (ch_type) {
case IIO_HUMIDITYRELATIVE:
data = hw->sensors[HTS221_SENSOR_H].slope;
div = (1 << 4) * 1000;
break;
case IIO_TEMP:
data = hw->sensors[HTS221_SENSOR_T].slope;
div = (1 << 6) * 1000;
break;
default:
return -EINVAL;
}
tmp = div_s64(data * 1000000000LL, div);
tmp = div_s64_rem(tmp, 1000000000LL, &rem);
*val = tmp;
*val2 = rem;
return IIO_VAL_INT_PLUS_NANO;
}
static int hts221_get_sensor_offset(struct hts221_hw *hw,
enum iio_chan_type ch_type,
int *val, int *val2)
{
s64 tmp;
s32 rem, div, data;
switch (ch_type) {
case IIO_HUMIDITYRELATIVE:
data = hw->sensors[HTS221_SENSOR_H].b_gen;
div = hw->sensors[HTS221_SENSOR_H].slope;
break;
case IIO_TEMP:
data = hw->sensors[HTS221_SENSOR_T].b_gen;
div = hw->sensors[HTS221_SENSOR_T].slope;
break;
default:
return -EINVAL;
}
tmp = div_s64(data * 1000000000LL, div);
tmp = div_s64_rem(tmp, 1000000000LL, &rem);
*val = tmp;
*val2 = rem;
return IIO_VAL_INT_PLUS_NANO;
}
static int hts221_read_oneshot(struct hts221_hw *hw, u8 addr, int *val)
{
u8 data[HTS221_DATA_SIZE];
int err;
err = hts221_power_on(hw);
if (err < 0)
return err;
msleep(50);
err = hw->tf->read(hw->dev, addr, sizeof(data), data);
if (err < 0)
return err;
hts221_power_off(hw);
*val = (s16)get_unaligned_le16(data);
return IIO_VAL_INT;
}
static int hts221_read_raw(struct iio_dev *iio_dev,
struct iio_chan_spec const *ch,
int *val, int *val2, long mask)
{
struct hts221_hw *hw = iio_priv(iio_dev);
int ret;
ret = iio_device_claim_direct_mode(iio_dev);
if (ret)
return ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = hts221_read_oneshot(hw, ch->address, val);
break;
case IIO_CHAN_INFO_SCALE:
ret = hts221_get_sensor_scale(hw, ch->type, val, val2);
break;
case IIO_CHAN_INFO_OFFSET:
ret = hts221_get_sensor_offset(hw, ch->type, val, val2);
break;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = hw->odr;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO: {
u8 idx;
const struct hts221_avg *avg;
switch (ch->type) {
case IIO_HUMIDITYRELATIVE:
avg = &hts221_avg_list[HTS221_SENSOR_H];
idx = hw->sensors[HTS221_SENSOR_H].cur_avg_idx;
*val = avg->avg_avl[idx].avg;
ret = IIO_VAL_INT;
break;
case IIO_TEMP:
avg = &hts221_avg_list[HTS221_SENSOR_T];
idx = hw->sensors[HTS221_SENSOR_T].cur_avg_idx;
*val = avg->avg_avl[idx].avg;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
break;
}
default:
ret = -EINVAL;
break;
}
iio_device_release_direct_mode(iio_dev);
return ret;
}
static int hts221_write_raw(struct iio_dev *iio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct hts221_hw *hw = iio_priv(iio_dev);
int ret;
ret = iio_device_claim_direct_mode(iio_dev);
if (ret)
return ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
ret = hts221_update_odr(hw, val);
break;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
switch (chan->type) {
case IIO_HUMIDITYRELATIVE:
ret = hts221_update_avg(hw, HTS221_SENSOR_H, val);
break;
case IIO_TEMP:
ret = hts221_update_avg(hw, HTS221_SENSOR_T, val);
break;
default:
ret = -EINVAL;
break;
}
break;
default:
ret = -EINVAL;
break;
}
iio_device_release_direct_mode(iio_dev);
return ret;
}
static int hts221_validate_trigger(struct iio_dev *iio_dev,
struct iio_trigger *trig)
{
struct hts221_hw *hw = iio_priv(iio_dev);
return hw->trig == trig ? 0 : -EINVAL;
}
int hts221_probe(struct iio_dev *iio_dev)
{
struct hts221_hw *hw = iio_priv(iio_dev);
int err;
u8 data;
mutex_init(&hw->lock);
err = hts221_check_whoami(hw);
if (err < 0)
return err;
hw->odr = hts221_odr_table[0].hz;
iio_dev->modes = INDIO_DIRECT_MODE;
iio_dev->dev.parent = hw->dev;
iio_dev->available_scan_masks = hts221_scan_masks;
iio_dev->channels = hts221_channels;
iio_dev->num_channels = ARRAY_SIZE(hts221_channels);
iio_dev->name = HTS221_DEV_NAME;
iio_dev->info = &hts221_info;
err = hts221_parse_rh_caldata(hw);
if (err < 0) {
dev_err(hw->dev, "failed to get rh calibration data\n");
return err;
}
data = hts221_avg_list[HTS221_SENSOR_H].avg_avl[3].avg;
err = hts221_update_avg(hw, HTS221_SENSOR_H, data);
if (err < 0) {
dev_err(hw->dev, "failed to set rh oversampling ratio\n");
return err;
}
err = hts221_parse_temp_caldata(hw);
if (err < 0) {
dev_err(hw->dev,
"failed to get temperature calibration data\n");
return err;
}
data = hts221_avg_list[HTS221_SENSOR_T].avg_avl[3].avg;
err = hts221_update_avg(hw, HTS221_SENSOR_T, data);
if (err < 0) {
dev_err(hw->dev,
"failed to set temperature oversampling ratio\n");
return err;
}
if (hw->irq > 0) {
err = hts221_allocate_buffers(hw);
if (err < 0)
return err;
err = hts221_allocate_trigger(hw);
if (err)
return err;
}
return devm_iio_device_register(hw->dev, iio_dev);
}
