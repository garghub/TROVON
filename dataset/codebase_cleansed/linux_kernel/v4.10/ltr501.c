static int ltr501_match_samp_freq(const struct ltr501_samp_table *tab,
int len, int val, int val2)
{
int i, freq;
freq = val * 1000000 + val2;
for (i = 0; i < len; i++) {
if (tab[i].freq_val == freq)
return i;
}
return -EINVAL;
}
static int ltr501_als_read_samp_freq(struct ltr501_data *data,
int *val, int *val2)
{
int ret, i;
ret = regmap_field_read(data->reg_als_rate, &i);
if (ret < 0)
return ret;
if (i < 0 || i >= ARRAY_SIZE(ltr501_als_samp_table))
return -EINVAL;
*val = ltr501_als_samp_table[i].freq_val / 1000000;
*val2 = ltr501_als_samp_table[i].freq_val % 1000000;
return IIO_VAL_INT_PLUS_MICRO;
}
static int ltr501_ps_read_samp_freq(struct ltr501_data *data,
int *val, int *val2)
{
int ret, i;
ret = regmap_field_read(data->reg_ps_rate, &i);
if (ret < 0)
return ret;
if (i < 0 || i >= ARRAY_SIZE(ltr501_ps_samp_table))
return -EINVAL;
*val = ltr501_ps_samp_table[i].freq_val / 1000000;
*val2 = ltr501_ps_samp_table[i].freq_val % 1000000;
return IIO_VAL_INT_PLUS_MICRO;
}
static int ltr501_als_write_samp_freq(struct ltr501_data *data,
int val, int val2)
{
int i, ret;
i = ltr501_match_samp_freq(ltr501_als_samp_table,
ARRAY_SIZE(ltr501_als_samp_table),
val, val2);
if (i < 0)
return i;
mutex_lock(&data->lock_als);
ret = regmap_field_write(data->reg_als_rate, i);
mutex_unlock(&data->lock_als);
return ret;
}
static int ltr501_ps_write_samp_freq(struct ltr501_data *data,
int val, int val2)
{
int i, ret;
i = ltr501_match_samp_freq(ltr501_ps_samp_table,
ARRAY_SIZE(ltr501_ps_samp_table),
val, val2);
if (i < 0)
return i;
mutex_lock(&data->lock_ps);
ret = regmap_field_write(data->reg_ps_rate, i);
mutex_unlock(&data->lock_ps);
return ret;
}
static int ltr501_als_read_samp_period(struct ltr501_data *data, int *val)
{
int ret, i;
ret = regmap_field_read(data->reg_als_rate, &i);
if (ret < 0)
return ret;
if (i < 0 || i >= ARRAY_SIZE(ltr501_als_samp_table))
return -EINVAL;
*val = ltr501_als_samp_table[i].time_val;
return IIO_VAL_INT;
}
static int ltr501_ps_read_samp_period(struct ltr501_data *data, int *val)
{
int ret, i;
ret = regmap_field_read(data->reg_ps_rate, &i);
if (ret < 0)
return ret;
if (i < 0 || i >= ARRAY_SIZE(ltr501_ps_samp_table))
return -EINVAL;
*val = ltr501_ps_samp_table[i].time_val;
return IIO_VAL_INT;
}
static unsigned long ltr501_calculate_lux(u16 vis_data, u16 ir_data)
{
unsigned long ratio, lux;
if (vis_data == 0)
return 0;
ratio = DIV_ROUND_UP(ir_data * 100, ir_data + vis_data);
if (ratio < 45)
lux = LTR501_LUX_CONV(1774, vis_data, -1105, ir_data);
else if (ratio >= 45 && ratio < 64)
lux = LTR501_LUX_CONV(3772, vis_data, 1336, ir_data);
else if (ratio >= 64 && ratio < 85)
lux = LTR501_LUX_CONV(1690, vis_data, 169, ir_data);
else
lux = 0;
return lux / 1000;
}
static int ltr501_drdy(struct ltr501_data *data, u8 drdy_mask)
{
int tries = 100;
int ret, status;
while (tries--) {
ret = regmap_read(data->regmap, LTR501_ALS_PS_STATUS, &status);
if (ret < 0)
return ret;
if ((status & drdy_mask) == drdy_mask)
return 0;
msleep(25);
}
dev_err(&data->client->dev, "ltr501_drdy() failed, data not ready\n");
return -EIO;
}
static int ltr501_set_it_time(struct ltr501_data *data, int it)
{
int ret, i, index = -1, status;
for (i = 0; i < ARRAY_SIZE(int_time_mapping); i++) {
if (int_time_mapping[i] == it) {
index = i;
break;
}
}
if (index < 0)
return -EINVAL;
ret = regmap_read(data->regmap, LTR501_ALS_CONTR, &status);
if (ret < 0)
return ret;
if (status & LTR501_CONTR_ALS_GAIN_MASK) {
if (index > 1)
return -EINVAL;
} else
if (index == 1)
return -EINVAL;
return regmap_field_write(data->reg_it, index);
}
static int ltr501_read_it_time(struct ltr501_data *data, int *val, int *val2)
{
int ret, index;
ret = regmap_field_read(data->reg_it, &index);
if (ret < 0)
return ret;
if (index < 0 || index >= ARRAY_SIZE(int_time_mapping))
return -EINVAL;
*val2 = int_time_mapping[index];
*val = 0;
return IIO_VAL_INT_PLUS_MICRO;
}
static int ltr501_read_als(struct ltr501_data *data, __le16 buf[2])
{
int ret;
ret = ltr501_drdy(data, LTR501_STATUS_ALS_RDY);
if (ret < 0)
return ret;
return regmap_bulk_read(data->regmap, LTR501_ALS_DATA1,
buf, 2 * sizeof(__le16));
}
static int ltr501_read_ps(struct ltr501_data *data)
{
int ret, status;
ret = ltr501_drdy(data, LTR501_STATUS_PS_RDY);
if (ret < 0)
return ret;
ret = regmap_bulk_read(data->regmap, LTR501_PS_DATA,
&status, 2);
if (ret < 0)
return ret;
return status;
}
static int ltr501_read_intr_prst(struct ltr501_data *data,
enum iio_chan_type type,
int *val2)
{
int ret, samp_period, prst;
switch (type) {
case IIO_INTENSITY:
ret = regmap_field_read(data->reg_als_prst, &prst);
if (ret < 0)
return ret;
ret = ltr501_als_read_samp_period(data, &samp_period);
if (ret < 0)
return ret;
*val2 = samp_period * prst;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_PROXIMITY:
ret = regmap_field_read(data->reg_ps_prst, &prst);
if (ret < 0)
return ret;
ret = ltr501_ps_read_samp_period(data, &samp_period);
if (ret < 0)
return ret;
*val2 = samp_period * prst;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_write_intr_prst(struct ltr501_data *data,
enum iio_chan_type type,
int val, int val2)
{
int ret, samp_period, new_val;
unsigned long period;
if (val < 0 || val2 < 0)
return -EINVAL;
period = ((val * 1000000) + val2);
switch (type) {
case IIO_INTENSITY:
ret = ltr501_als_read_samp_period(data, &samp_period);
if (ret < 0)
return ret;
if (period < samp_period)
return -EINVAL;
new_val = DIV_ROUND_UP(period, samp_period);
if (new_val < 0 || new_val > 0x0f)
return -EINVAL;
mutex_lock(&data->lock_als);
ret = regmap_field_write(data->reg_als_prst, new_val);
mutex_unlock(&data->lock_als);
if (ret >= 0)
data->als_period = period;
return ret;
case IIO_PROXIMITY:
ret = ltr501_ps_read_samp_period(data, &samp_period);
if (ret < 0)
return ret;
if (period < samp_period)
return -EINVAL;
new_val = DIV_ROUND_UP(period, samp_period);
if (new_val < 0 || new_val > 0x0f)
return -EINVAL;
mutex_lock(&data->lock_ps);
ret = regmap_field_write(data->reg_ps_prst, new_val);
mutex_unlock(&data->lock_ps);
if (ret >= 0)
data->ps_period = period;
return ret;
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ltr501_data *data = iio_priv(indio_dev);
__le16 buf[2];
int ret, i;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_LIGHT:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
mutex_lock(&data->lock_als);
ret = ltr501_read_als(data, buf);
mutex_unlock(&data->lock_als);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = ltr501_calculate_lux(le16_to_cpu(buf[1]),
le16_to_cpu(buf[0]));
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
switch (chan->type) {
case IIO_INTENSITY:
mutex_lock(&data->lock_als);
ret = ltr501_read_als(data, buf);
mutex_unlock(&data->lock_als);
if (ret < 0)
break;
*val = le16_to_cpu(chan->address == LTR501_ALS_DATA1 ?
buf[0] : buf[1]);
ret = IIO_VAL_INT;
break;
case IIO_PROXIMITY:
mutex_lock(&data->lock_ps);
ret = ltr501_read_ps(data);
mutex_unlock(&data->lock_ps);
if (ret < 0)
break;
*val = ret & LTR501_PS_DATA_MASK;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
iio_device_release_direct_mode(indio_dev);
return ret;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_INTENSITY:
i = (data->als_contr & data->chip_info->als_gain_mask)
>> data->chip_info->als_gain_shift;
*val = data->chip_info->als_gain[i].scale;
*val2 = data->chip_info->als_gain[i].uscale;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_PROXIMITY:
i = (data->ps_contr & LTR501_CONTR_PS_GAIN_MASK) >>
LTR501_CONTR_PS_GAIN_SHIFT;
*val = data->chip_info->ps_gain[i].scale;
*val2 = data->chip_info->ps_gain[i].uscale;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_INT_TIME:
switch (chan->type) {
case IIO_INTENSITY:
return ltr501_read_it_time(data, val, val2);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
switch (chan->type) {
case IIO_INTENSITY:
return ltr501_als_read_samp_freq(data, val, val2);
case IIO_PROXIMITY:
return ltr501_ps_read_samp_freq(data, val, val2);
default:
return -EINVAL;
}
}
return -EINVAL;
}
static int ltr501_get_gain_index(struct ltr501_gain *gain, int size,
int val, int val2)
{
int i;
for (i = 0; i < size; i++)
if (val == gain[i].scale && val2 == gain[i].uscale)
return i;
return -1;
}
static int ltr501_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ltr501_data *data = iio_priv(indio_dev);
int i, ret, freq_val, freq_val2;
struct ltr501_chip_info *info = data->chip_info;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_INTENSITY:
i = ltr501_get_gain_index(info->als_gain,
info->als_gain_tbl_size,
val, val2);
if (i < 0) {
ret = -EINVAL;
break;
}
data->als_contr &= ~info->als_gain_mask;
data->als_contr |= i << info->als_gain_shift;
ret = regmap_write(data->regmap, LTR501_ALS_CONTR,
data->als_contr);
break;
case IIO_PROXIMITY:
i = ltr501_get_gain_index(info->ps_gain,
info->ps_gain_tbl_size,
val, val2);
if (i < 0) {
ret = -EINVAL;
break;
}
data->ps_contr &= ~LTR501_CONTR_PS_GAIN_MASK;
data->ps_contr |= i << LTR501_CONTR_PS_GAIN_SHIFT;
ret = regmap_write(data->regmap, LTR501_PS_CONTR,
data->ps_contr);
break;
default:
ret = -EINVAL;
break;
}
break;
case IIO_CHAN_INFO_INT_TIME:
switch (chan->type) {
case IIO_INTENSITY:
if (val != 0) {
ret = -EINVAL;
break;
}
mutex_lock(&data->lock_als);
ret = ltr501_set_it_time(data, val2);
mutex_unlock(&data->lock_als);
break;
default:
ret = -EINVAL;
break;
}
break;
case IIO_CHAN_INFO_SAMP_FREQ:
switch (chan->type) {
case IIO_INTENSITY:
ret = ltr501_als_read_samp_freq(data, &freq_val,
&freq_val2);
if (ret < 0)
break;
ret = ltr501_als_write_samp_freq(data, val, val2);
if (ret < 0)
break;
ret = ltr501_write_intr_prst(data, chan->type,
0, data->als_period);
if (ret < 0)
ret = ltr501_als_write_samp_freq(data, freq_val,
freq_val2);
break;
case IIO_PROXIMITY:
ret = ltr501_ps_read_samp_freq(data, &freq_val,
&freq_val2);
if (ret < 0)
break;
ret = ltr501_ps_write_samp_freq(data, val, val2);
if (ret < 0)
break;
ret = ltr501_write_intr_prst(data, chan->type,
0, data->ps_period);
if (ret < 0)
ret = ltr501_ps_write_samp_freq(data, freq_val,
freq_val2);
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
iio_device_release_direct_mode(indio_dev);
return ret;
}
static int ltr501_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct ltr501_data *data = iio_priv(indio_dev);
int ret, thresh_data;
switch (chan->type) {
case IIO_INTENSITY:
switch (dir) {
case IIO_EV_DIR_RISING:
ret = regmap_bulk_read(data->regmap,
LTR501_ALS_THRESH_UP,
&thresh_data, 2);
if (ret < 0)
return ret;
*val = thresh_data & LTR501_ALS_THRESH_MASK;
return IIO_VAL_INT;
case IIO_EV_DIR_FALLING:
ret = regmap_bulk_read(data->regmap,
LTR501_ALS_THRESH_LOW,
&thresh_data, 2);
if (ret < 0)
return ret;
*val = thresh_data & LTR501_ALS_THRESH_MASK;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_PROXIMITY:
switch (dir) {
case IIO_EV_DIR_RISING:
ret = regmap_bulk_read(data->regmap,
LTR501_PS_THRESH_UP,
&thresh_data, 2);
if (ret < 0)
return ret;
*val = thresh_data & LTR501_PS_THRESH_MASK;
return IIO_VAL_INT;
case IIO_EV_DIR_FALLING:
ret = regmap_bulk_read(data->regmap,
LTR501_PS_THRESH_LOW,
&thresh_data, 2);
if (ret < 0)
return ret;
*val = thresh_data & LTR501_PS_THRESH_MASK;
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct ltr501_data *data = iio_priv(indio_dev);
int ret;
if (val < 0)
return -EINVAL;
switch (chan->type) {
case IIO_INTENSITY:
if (val > LTR501_ALS_THRESH_MASK)
return -EINVAL;
switch (dir) {
case IIO_EV_DIR_RISING:
mutex_lock(&data->lock_als);
ret = regmap_bulk_write(data->regmap,
LTR501_ALS_THRESH_UP,
&val, 2);
mutex_unlock(&data->lock_als);
return ret;
case IIO_EV_DIR_FALLING:
mutex_lock(&data->lock_als);
ret = regmap_bulk_write(data->regmap,
LTR501_ALS_THRESH_LOW,
&val, 2);
mutex_unlock(&data->lock_als);
return ret;
default:
return -EINVAL;
}
case IIO_PROXIMITY:
if (val > LTR501_PS_THRESH_MASK)
return -EINVAL;
switch (dir) {
case IIO_EV_DIR_RISING:
mutex_lock(&data->lock_ps);
ret = regmap_bulk_write(data->regmap,
LTR501_PS_THRESH_UP,
&val, 2);
mutex_unlock(&data->lock_ps);
return ret;
case IIO_EV_DIR_FALLING:
mutex_lock(&data->lock_ps);
ret = regmap_bulk_write(data->regmap,
LTR501_PS_THRESH_LOW,
&val, 2);
mutex_unlock(&data->lock_ps);
return ret;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
int ret;
switch (info) {
case IIO_EV_INFO_VALUE:
return ltr501_read_thresh(indio_dev, chan, type, dir,
info, val, val2);
case IIO_EV_INFO_PERIOD:
ret = ltr501_read_intr_prst(iio_priv(indio_dev),
chan->type, val2);
*val = *val2 / 1000000;
*val2 = *val2 % 1000000;
return ret;
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
switch (info) {
case IIO_EV_INFO_VALUE:
if (val2 != 0)
return -EINVAL;
return ltr501_write_thresh(indio_dev, chan, type, dir,
info, val, val2);
case IIO_EV_INFO_PERIOD:
return ltr501_write_intr_prst(iio_priv(indio_dev), chan->type,
val, val2);
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct ltr501_data *data = iio_priv(indio_dev);
int ret, status;
switch (chan->type) {
case IIO_INTENSITY:
ret = regmap_field_read(data->reg_als_intr, &status);
if (ret < 0)
return ret;
return status;
case IIO_PROXIMITY:
ret = regmap_field_read(data->reg_ps_intr, &status);
if (ret < 0)
return ret;
return status;
default:
return -EINVAL;
}
return -EINVAL;
}
static int ltr501_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct ltr501_data *data = iio_priv(indio_dev);
int ret;
if (state != 1 && state != 0)
return -EINVAL;
switch (chan->type) {
case IIO_INTENSITY:
mutex_lock(&data->lock_als);
ret = regmap_field_write(data->reg_als_intr, state);
mutex_unlock(&data->lock_als);
return ret;
case IIO_PROXIMITY:
mutex_lock(&data->lock_ps);
ret = regmap_field_write(data->reg_ps_intr, state);
mutex_unlock(&data->lock_ps);
return ret;
default:
return -EINVAL;
}
return -EINVAL;
}
static ssize_t ltr501_show_proximity_scale_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ltr501_data *data = iio_priv(dev_to_iio_dev(dev));
struct ltr501_chip_info *info = data->chip_info;
ssize_t len = 0;
int i;
for (i = 0; i < info->ps_gain_tbl_size; i++) {
if (info->ps_gain[i].scale == LTR501_RESERVED_GAIN)
continue;
len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06d ",
info->ps_gain[i].scale,
info->ps_gain[i].uscale);
}
buf[len - 1] = '\n';
return len;
}
static ssize_t ltr501_show_intensity_scale_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ltr501_data *data = iio_priv(dev_to_iio_dev(dev));
struct ltr501_chip_info *info = data->chip_info;
ssize_t len = 0;
int i;
for (i = 0; i < info->als_gain_tbl_size; i++) {
if (info->als_gain[i].scale == LTR501_RESERVED_GAIN)
continue;
len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06d ",
info->als_gain[i].scale,
info->als_gain[i].uscale);
}
buf[len - 1] = '\n';
return len;
}
static int ltr501_write_contr(struct ltr501_data *data, u8 als_val, u8 ps_val)
{
int ret;
ret = regmap_write(data->regmap, LTR501_ALS_CONTR, als_val);
if (ret < 0)
return ret;
return regmap_write(data->regmap, LTR501_PS_CONTR, ps_val);
}
static irqreturn_t ltr501_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ltr501_data *data = iio_priv(indio_dev);
u16 buf[8];
__le16 als_buf[2];
u8 mask = 0;
int j = 0;
int ret, psdata;
memset(buf, 0, sizeof(buf));
if (test_bit(0, indio_dev->active_scan_mask) ||
test_bit(1, indio_dev->active_scan_mask))
mask |= LTR501_STATUS_ALS_RDY;
if (test_bit(2, indio_dev->active_scan_mask))
mask |= LTR501_STATUS_PS_RDY;
ret = ltr501_drdy(data, mask);
if (ret < 0)
goto done;
if (mask & LTR501_STATUS_ALS_RDY) {
ret = regmap_bulk_read(data->regmap, LTR501_ALS_DATA1,
(u8 *)als_buf, sizeof(als_buf));
if (ret < 0)
return ret;
if (test_bit(0, indio_dev->active_scan_mask))
buf[j++] = le16_to_cpu(als_buf[1]);
if (test_bit(1, indio_dev->active_scan_mask))
buf[j++] = le16_to_cpu(als_buf[0]);
}
if (mask & LTR501_STATUS_PS_RDY) {
ret = regmap_bulk_read(data->regmap, LTR501_PS_DATA,
&psdata, 2);
if (ret < 0)
goto done;
buf[j++] = psdata & LTR501_PS_DATA_MASK;
}
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static irqreturn_t ltr501_interrupt_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ltr501_data *data = iio_priv(indio_dev);
int ret, status;
ret = regmap_read(data->regmap, LTR501_ALS_PS_STATUS, &status);
if (ret < 0) {
dev_err(&data->client->dev,
"irq read int reg failed\n");
return IRQ_HANDLED;
}
if (status & LTR501_STATUS_ALS_INTR)
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_INTENSITY, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns(indio_dev));
if (status & LTR501_STATUS_PS_INTR)
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns(indio_dev));
return IRQ_HANDLED;
}
static int ltr501_init(struct ltr501_data *data)
{
int ret, status;
ret = regmap_read(data->regmap, LTR501_ALS_CONTR, &status);
if (ret < 0)
return ret;
data->als_contr = status | data->chip_info->als_mode_active;
ret = regmap_read(data->regmap, LTR501_PS_CONTR, &status);
if (ret < 0)
return ret;
data->ps_contr = status | LTR501_CONTR_ACTIVE;
ret = ltr501_read_intr_prst(data, IIO_INTENSITY, &data->als_period);
if (ret < 0)
return ret;
ret = ltr501_read_intr_prst(data, IIO_PROXIMITY, &data->ps_period);
if (ret < 0)
return ret;
return ltr501_write_contr(data, data->als_contr, data->ps_contr);
}
static bool ltr501_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTR501_ALS_DATA1:
case LTR501_ALS_DATA0:
case LTR501_ALS_PS_STATUS:
case LTR501_PS_DATA:
return true;
default:
return false;
}
}
static int ltr501_powerdown(struct ltr501_data *data)
{
return ltr501_write_contr(data, data->als_contr &
~data->chip_info->als_mode_active,
data->ps_contr & ~LTR501_CONTR_ACTIVE);
}
static const char *ltr501_match_acpi_device(struct device *dev, int *chip_idx)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
*chip_idx = id->driver_data;
return dev_name(dev);
}
static int ltr501_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ltr501_data *data;
struct iio_dev *indio_dev;
struct regmap *regmap;
int ret, partid, chip_idx = 0;
const char *name = NULL;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
regmap = devm_regmap_init_i2c(client, &ltr501_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Regmap initialization failed.\n");
return PTR_ERR(regmap);
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->regmap = regmap;
mutex_init(&data->lock_als);
mutex_init(&data->lock_ps);
data->reg_it = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_it);
if (IS_ERR(data->reg_it)) {
dev_err(&client->dev, "Integ time reg field init failed.\n");
return PTR_ERR(data->reg_it);
}
data->reg_als_intr = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_als_intr);
if (IS_ERR(data->reg_als_intr)) {
dev_err(&client->dev, "ALS intr mode reg field init failed\n");
return PTR_ERR(data->reg_als_intr);
}
data->reg_ps_intr = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_ps_intr);
if (IS_ERR(data->reg_ps_intr)) {
dev_err(&client->dev, "PS intr mode reg field init failed.\n");
return PTR_ERR(data->reg_ps_intr);
}
data->reg_als_rate = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_als_rate);
if (IS_ERR(data->reg_als_rate)) {
dev_err(&client->dev, "ALS samp rate field init failed.\n");
return PTR_ERR(data->reg_als_rate);
}
data->reg_ps_rate = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_ps_rate);
if (IS_ERR(data->reg_ps_rate)) {
dev_err(&client->dev, "PS samp rate field init failed.\n");
return PTR_ERR(data->reg_ps_rate);
}
data->reg_als_prst = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_als_prst);
if (IS_ERR(data->reg_als_prst)) {
dev_err(&client->dev, "ALS prst reg field init failed\n");
return PTR_ERR(data->reg_als_prst);
}
data->reg_ps_prst = devm_regmap_field_alloc(&client->dev, regmap,
reg_field_ps_prst);
if (IS_ERR(data->reg_ps_prst)) {
dev_err(&client->dev, "PS prst reg field init failed.\n");
return PTR_ERR(data->reg_ps_prst);
}
ret = regmap_read(data->regmap, LTR501_PART_ID, &partid);
if (ret < 0)
return ret;
if (id) {
name = id->name;
chip_idx = id->driver_data;
} else if (ACPI_HANDLE(&client->dev)) {
name = ltr501_match_acpi_device(&client->dev, &chip_idx);
} else {
return -ENODEV;
}
data->chip_info = &ltr501_chip_info_tbl[chip_idx];
if ((partid >> 4) != data->chip_info->partid)
return -ENODEV;
indio_dev->dev.parent = &client->dev;
indio_dev->info = data->chip_info->info;
indio_dev->channels = data->chip_info->channels;
indio_dev->num_channels = data->chip_info->no_channels;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ltr501_init(data);
if (ret < 0)
return ret;
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, ltr501_interrupt_handler,
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
"ltr501_thresh_event",
indio_dev);
if (ret) {
dev_err(&client->dev, "request irq (%d) failed\n",
client->irq);
return ret;
}
} else {
indio_dev->info = data->chip_info->info_no_irq;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ltr501_trigger_handler, NULL);
if (ret)
goto powerdown_on_error;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_buffer;
return 0;
error_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
powerdown_on_error:
ltr501_powerdown(data);
return ret;
}
static int ltr501_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
ltr501_powerdown(iio_priv(indio_dev));
return 0;
}
static int ltr501_suspend(struct device *dev)
{
struct ltr501_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return ltr501_powerdown(data);
}
static int ltr501_resume(struct device *dev)
{
struct ltr501_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return ltr501_write_contr(data, data->als_contr,
data->ps_contr);
}
