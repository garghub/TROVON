static int bmc150_accel_set_mode(struct bmc150_accel_data *data,
enum bmc150_power_modes mode,
int dur_us)
{
int i;
int ret;
u8 lpw_bits;
int dur_val = -1;
if (dur_us > 0) {
for (i = 0; i < ARRAY_SIZE(bmc150_accel_sleep_value_table);
++i) {
if (bmc150_accel_sleep_value_table[i].sleep_dur ==
dur_us)
dur_val =
bmc150_accel_sleep_value_table[i].reg_value;
}
} else
dur_val = 0;
if (dur_val < 0)
return -EINVAL;
lpw_bits = mode << BMC150_ACCEL_PMU_MODE_SHIFT;
lpw_bits |= (dur_val << BMC150_ACCEL_PMU_BIT_SLEEP_DUR_SHIFT);
dev_dbg(&data->client->dev, "Set Mode bits %x\n", lpw_bits);
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_PMU_LPW, lpw_bits);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_pmu_lpw\n");
return ret;
}
return 0;
}
static int bmc150_accel_set_bw(struct bmc150_accel_data *data, int val,
int val2)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_samp_freq_table); ++i) {
if (bmc150_accel_samp_freq_table[i].val == val &&
bmc150_accel_samp_freq_table[i].val2 == val2) {
ret = i2c_smbus_write_byte_data(
data->client,
BMC150_ACCEL_REG_PMU_BW,
bmc150_accel_samp_freq_table[i].bw_bits);
if (ret < 0)
return ret;
data->bw_bits =
bmc150_accel_samp_freq_table[i].bw_bits;
return 0;
}
}
return -EINVAL;
}
static int bmc150_accel_chip_init(struct bmc150_accel_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, BMC150_ACCEL_REG_CHIP_ID);
if (ret < 0) {
dev_err(&data->client->dev,
"Error: Reading chip id\n");
return ret;
}
dev_dbg(&data->client->dev, "Chip Id %x\n", ret);
if (ret != data->chip_info->chip_id) {
dev_err(&data->client->dev, "Invalid chip %x\n", ret);
return -ENODEV;
}
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
if (ret < 0)
return ret;
ret = bmc150_accel_set_bw(data, BMC150_ACCEL_DEF_BW, 0);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_PMU_RANGE,
BMC150_ACCEL_DEF_RANGE_4G);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_pmu_range\n");
return ret;
}
data->range = BMC150_ACCEL_DEF_RANGE_4G;
ret = i2c_smbus_read_byte_data(data->client, BMC150_ACCEL_REG_INT_5);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_5\n");
return ret;
}
data->slope_dur |= BMC150_ACCEL_DEF_SLOPE_DURATION;
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_5,
data->slope_dur);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_5\n");
return ret;
}
dev_dbg(&data->client->dev, "slope_dur %x\n", data->slope_dur);
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_6,
BMC150_ACCEL_DEF_SLOPE_THRESHOLD);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_6\n");
return ret;
}
data->slope_thres = BMC150_ACCEL_DEF_SLOPE_THRESHOLD;
dev_dbg(&data->client->dev, "slope_thres %x\n", data->slope_thres);
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_int_rst_latch\n");
return ret;
}
return 0;
}
static int bmc150_accel_setup_any_motion_interrupt(
struct bmc150_accel_data *data,
bool status)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client,
BMC150_ACCEL_REG_INT_MAP_0);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_map_0\n");
return ret;
}
if (status)
ret |= BMC150_ACCEL_INT_MAP_0_BIT_SLOPE;
else
ret &= ~BMC150_ACCEL_INT_MAP_0_BIT_SLOPE;
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_MAP_0,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_map_0\n");
return ret;
}
if (status) {
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_5,
data->slope_dur);
if (ret < 0) {
dev_err(&data->client->dev, "Error write reg_int_5\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_6,
data->slope_thres);
if (ret < 0) {
dev_err(&data->client->dev, "Error write reg_int_6\n");
return ret;
}
if (!data->dready_trigger_on) {
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_int_rst_latch\n");
return ret;
}
}
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_EN_0,
BMC150_ACCEL_INT_EN_BIT_SLP_X |
BMC150_ACCEL_INT_EN_BIT_SLP_Y |
BMC150_ACCEL_INT_EN_BIT_SLP_Z);
} else
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_EN_0,
0);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_en_0\n");
return ret;
}
return 0;
}
static int bmc150_accel_setup_new_data_interrupt(struct bmc150_accel_data *data,
bool status)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client,
BMC150_ACCEL_REG_INT_MAP_1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_map_1\n");
return ret;
}
if (status)
ret |= BMC150_ACCEL_INT_MAP_1_BIT_DATA;
else
ret &= ~BMC150_ACCEL_INT_MAP_1_BIT_DATA;
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_MAP_1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_map_1\n");
return ret;
}
if (status) {
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_NON_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_int_rst_latch\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_EN_1,
BMC150_ACCEL_INT_EN_BIT_DATA_EN);
} else {
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_int_rst_latch\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_EN_1,
0);
}
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_en_1\n");
return ret;
}
return 0;
}
static int bmc150_accel_get_bw(struct bmc150_accel_data *data, int *val,
int *val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_samp_freq_table); ++i) {
if (bmc150_accel_samp_freq_table[i].bw_bits == data->bw_bits) {
*val = bmc150_accel_samp_freq_table[i].val;
*val2 = bmc150_accel_samp_freq_table[i].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int bmc150_accel_get_startup_times(struct bmc150_accel_data *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmc150_accel_sample_upd_time); ++i) {
if (bmc150_accel_sample_upd_time[i].bw_bits == data->bw_bits)
return bmc150_accel_sample_upd_time[i].msec;
}
return BMC150_ACCEL_MAX_STARTUP_TIME_MS;
}
static int bmc150_accel_set_power_state(struct bmc150_accel_data *data, bool on)
{
int ret;
if (on)
ret = pm_runtime_get_sync(&data->client->dev);
else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
if (ret < 0) {
dev_err(&data->client->dev,
"Failed: bmc150_accel_set_power_state for %d\n", on);
if (on)
pm_runtime_put_noidle(&data->client->dev);
return ret;
}
return 0;
}
static int bmc150_accel_set_power_state(struct bmc150_accel_data *data, bool on)
{
return 0;
}
static int bmc150_accel_set_scale(struct bmc150_accel_data *data, int val)
{
int ret, i;
for (i = 0; i < ARRAY_SIZE(data->chip_info->scale_table); ++i) {
if (data->chip_info->scale_table[i].scale == val) {
ret = i2c_smbus_write_byte_data(
data->client,
BMC150_ACCEL_REG_PMU_RANGE,
data->chip_info->scale_table[i].reg_range);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing pmu_range\n");
return ret;
}
data->range = data->chip_info->scale_table[i].reg_range;
return 0;
}
}
return -EINVAL;
}
static int bmc150_accel_get_temp(struct bmc150_accel_data *data, int *val)
{
int ret;
mutex_lock(&data->mutex);
ret = i2c_smbus_read_byte_data(data->client, BMC150_ACCEL_REG_TEMP);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_temp\n");
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(ret, 7);
mutex_unlock(&data->mutex);
return IIO_VAL_INT;
}
static int bmc150_accel_get_axis(struct bmc150_accel_data *data,
struct iio_chan_spec const *chan,
int *val)
{
int ret;
int axis = chan->scan_index;
mutex_lock(&data->mutex);
ret = bmc150_accel_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = i2c_smbus_read_word_data(data->client,
BMC150_ACCEL_AXIS_TO_REG(axis));
if (ret < 0) {
dev_err(&data->client->dev, "Error reading axis %d\n", axis);
bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(ret >> chan->scan_type.shift,
chan->scan_type.realbits - 1);
ret = bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
return IIO_VAL_INT;
}
static int bmc150_accel_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_TEMP:
return bmc150_accel_get_temp(data, val);
case IIO_ACCEL:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
else
return bmc150_accel_get_axis(data, chan, val);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP) {
*val = BMC150_ACCEL_TEMP_CENTER_VAL;
return IIO_VAL_INT;
} else
return -EINVAL;
case IIO_CHAN_INFO_SCALE:
*val = 0;
switch (chan->type) {
case IIO_TEMP:
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
{
int i;
const struct bmc150_scale_info *si;
int st_size = ARRAY_SIZE(data->chip_info->scale_table);
for (i = 0; i < st_size; ++i) {
si = &data->chip_info->scale_table[i];
if (si->reg_range == data->range) {
*val2 = si->scale;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = bmc150_accel_get_bw(data, val, val2);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int bmc150_accel_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = bmc150_accel_set_bw(data, val, val2);
mutex_unlock(&data->mutex);
break;
case IIO_CHAN_INFO_SCALE:
if (val)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmc150_accel_set_scale(data, val2);
mutex_unlock(&data->mutex);
return ret;
default:
ret = -EINVAL;
}
return ret;
}
static int bmc150_accel_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
*val2 = 0;
switch (info) {
case IIO_EV_INFO_VALUE:
*val = data->slope_thres;
break;
case IIO_EV_INFO_PERIOD:
*val = data->slope_dur & BMC150_ACCEL_SLOPE_DUR_MASK;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int bmc150_accel_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
if (data->ev_enable_state)
return -EBUSY;
switch (info) {
case IIO_EV_INFO_VALUE:
data->slope_thres = val;
break;
case IIO_EV_INFO_PERIOD:
data->slope_dur &= ~BMC150_ACCEL_SLOPE_DUR_MASK;
data->slope_dur |= val & BMC150_ACCEL_SLOPE_DUR_MASK;
break;
default:
return -EINVAL;
}
return 0;
}
static int bmc150_accel_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
return data->ev_enable_state;
}
static int bmc150_accel_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
if (state && data->ev_enable_state)
return 0;
mutex_lock(&data->mutex);
if (!state && data->motion_trigger_on) {
data->ev_enable_state = 0;
mutex_unlock(&data->mutex);
return 0;
}
ret = bmc150_accel_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = bmc150_accel_setup_any_motion_interrupt(data, state);
if (ret < 0) {
bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
data->ev_enable_state = state;
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct bmc150_accel_data *data = iio_priv(indio_dev);
if (data->dready_trig != trig && data->motion_trig != trig)
return -EINVAL;
return 0;
}
static irqreturn_t bmc150_accel_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bmc150_accel_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = i2c_smbus_read_word_data(data->client,
BMC150_ACCEL_AXIS_TO_REG(bit));
if (ret < 0) {
mutex_unlock(&data->mutex);
goto err_read;
}
data->buffer[i++] = ret;
}
mutex_unlock(&data->mutex);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
data->timestamp);
err_read:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bmc150_accel_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
if (data->dready_trigger_on)
return 0;
mutex_lock(&data->mutex);
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
mutex_unlock(&data->mutex);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_int_rst_latch\n");
return ret;
}
return 0;
}
static int bmc150_accel_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
if (!state && data->ev_enable_state && data->motion_trigger_on) {
data->motion_trigger_on = false;
mutex_unlock(&data->mutex);
return 0;
}
ret = bmc150_accel_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
ret = bmc150_accel_setup_any_motion_interrupt(data, state);
else
ret = bmc150_accel_setup_new_data_interrupt(data, state);
if (ret < 0) {
bmc150_accel_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
data->motion_trigger_on = state;
else
data->dready_trigger_on = state;
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t bmc150_accel_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
int dir;
ret = i2c_smbus_read_byte_data(data->client,
BMC150_ACCEL_REG_INT_STATUS_2);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_status_2\n");
goto ack_intr_status;
}
if (ret & BMC150_ACCEL_ANY_MOTION_BIT_SIGN)
dir = IIO_EV_DIR_FALLING;
else
dir = IIO_EV_DIR_RISING;
if (ret & BMC150_ACCEL_ANY_MOTION_BIT_X)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (ret & BMC150_ACCEL_ANY_MOTION_BIT_Y)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (ret & BMC150_ACCEL_ANY_MOTION_BIT_Z)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ACCEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
ack_intr_status:
if (!data->dready_trigger_on)
ret = i2c_smbus_write_byte_data(data->client,
BMC150_ACCEL_REG_INT_RST_LATCH,
BMC150_ACCEL_INT_MODE_LATCH_INT |
BMC150_ACCEL_INT_MODE_LATCH_RESET);
return IRQ_HANDLED;
}
static irqreturn_t bmc150_accel_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmc150_accel_data *data = iio_priv(indio_dev);
data->timestamp = iio_get_time_ns();
if (data->dready_trigger_on)
iio_trigger_poll(data->dready_trig);
else if (data->motion_trigger_on)
iio_trigger_poll(data->motion_trig);
if (data->ev_enable_state)
return IRQ_WAKE_THREAD;
else
return IRQ_HANDLED;
}
static const char *bmc150_accel_match_acpi_device(struct device *dev, int *data)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
*data = (int) id->driver_data;
return dev_name(dev);
}
static int bmc150_accel_gpio_probe(struct i2c_client *client,
struct bmc150_accel_data *data)
{
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
gpio = devm_gpiod_get_index(dev, BMC150_ACCEL_GPIO_NAME, 0);
if (IS_ERR(gpio)) {
dev_err(dev, "Failed: gpio get index\n");
return PTR_ERR(gpio);
}
ret = gpiod_direction_input(gpio);
if (ret)
return ret;
ret = gpiod_to_irq(gpio);
dev_dbg(dev, "GPIO resource, no:%d irq:%d\n", desc_to_gpio(gpio), ret);
return ret;
}
static int bmc150_accel_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bmc150_accel_data *data;
struct iio_dev *indio_dev;
int ret;
const char *name = NULL;
int chip_id = 0;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
if (id) {
name = id->name;
chip_id = id->driver_data;
}
if (ACPI_HANDLE(&client->dev))
name = bmc150_accel_match_acpi_device(&client->dev, &chip_id);
data->chip_info = &bmc150_accel_chip_info_tbl[chip_id];
ret = bmc150_accel_chip_init(data);
if (ret < 0)
return ret;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = data->chip_info->channels;
indio_dev->num_channels = data->chip_info->num_channels;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bmc150_accel_info;
if (client->irq < 0)
client->irq = bmc150_accel_gpio_probe(client, data);
if (client->irq >= 0) {
ret = devm_request_threaded_irq(
&client->dev, client->irq,
bmc150_accel_data_rdy_trig_poll,
bmc150_accel_event_handler,
IRQF_TRIGGER_RISING,
BMC150_ACCEL_IRQ_NAME,
indio_dev);
if (ret)
return ret;
data->dready_trig = devm_iio_trigger_alloc(&client->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->dready_trig)
return -ENOMEM;
data->motion_trig = devm_iio_trigger_alloc(&client->dev,
"%s-any-motion-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->motion_trig)
return -ENOMEM;
data->dready_trig->dev.parent = &client->dev;
data->dready_trig->ops = &bmc150_accel_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
ret = iio_trigger_register(data->dready_trig);
if (ret)
return ret;
data->motion_trig->dev.parent = &client->dev;
data->motion_trig->ops = &bmc150_accel_trigger_ops;
iio_trigger_set_drvdata(data->motion_trig, indio_dev);
ret = iio_trigger_register(data->motion_trig);
if (ret) {
data->motion_trig = NULL;
goto err_trigger_unregister;
}
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time,
bmc150_accel_trigger_handler,
NULL);
if (ret < 0) {
dev_err(&client->dev,
"Failed: iio triggered buffer setup\n");
goto err_trigger_unregister;
}
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "Unable to register iio device\n");
goto err_buffer_cleanup;
}
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto err_iio_unregister;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
BMC150_AUTO_SUSPEND_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
return 0;
err_iio_unregister:
iio_device_unregister(indio_dev);
err_buffer_cleanup:
if (data->dready_trig)
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
if (data->motion_trig)
iio_trigger_unregister(data->motion_trig);
return ret;
}
static int bmc150_accel_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bmc150_accel_data *data = iio_priv(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
iio_device_unregister(indio_dev);
if (data->dready_trig) {
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(data->dready_trig);
iio_trigger_unregister(data->motion_trig);
}
mutex_lock(&data->mutex);
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_DEEP_SUSPEND, 0);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_accel_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_SUSPEND, 0);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_accel_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
if (data->dready_trigger_on || data->motion_trigger_on ||
data->ev_enable_state)
bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
mutex_unlock(&data->mutex);
return 0;
}
static int bmc150_accel_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
dev_dbg(&data->client->dev, __func__);
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_SUSPEND, 0);
if (ret < 0)
return -EAGAIN;
return 0;
}
static int bmc150_accel_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmc150_accel_data *data = iio_priv(indio_dev);
int ret;
int sleep_val;
dev_dbg(&data->client->dev, __func__);
ret = bmc150_accel_set_mode(data, BMC150_ACCEL_SLEEP_MODE_NORMAL, 0);
if (ret < 0)
return ret;
sleep_val = bmc150_accel_get_startup_times(data);
if (sleep_val < 20)
usleep_range(sleep_val * 1000, 20000);
else
msleep_interruptible(sleep_val);
return 0;
}
