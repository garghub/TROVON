static int bmg160_set_mode(struct bmg160_data *data, u8 mode)
{
int ret;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_PMU_LPW, mode);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_pmu_lpw\n");
return ret;
}
return 0;
}
static int bmg160_convert_freq_to_bit(int val)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
if (bmg160_samp_freq_table[i].val == val)
return bmg160_samp_freq_table[i].bw_bits;
}
return -EINVAL;
}
static int bmg160_set_bw(struct bmg160_data *data, int val)
{
int ret;
int bw_bits;
bw_bits = bmg160_convert_freq_to_bit(val);
if (bw_bits < 0)
return bw_bits;
ret = i2c_smbus_write_byte_data(data->client, BMG160_REG_PMU_BW,
bw_bits);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_pmu_bw\n");
return ret;
}
data->bw_bits = bw_bits;
return 0;
}
static int bmg160_chip_init(struct bmg160_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_CHIP_ID);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_chip_id\n");
return ret;
}
dev_dbg(&data->client->dev, "Chip Id %x\n", ret);
if (ret != BMG160_CHIP_ID_VAL) {
dev_err(&data->client->dev, "invalid chip %x\n", ret);
return -ENODEV;
}
ret = bmg160_set_mode(data, BMG160_MODE_NORMAL);
if (ret < 0)
return ret;
usleep_range(500, 1000);
ret = bmg160_set_bw(data, BMG160_DEF_BW);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_RANGE,
BMG160_RANGE_500DPS);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_range\n");
return ret;
}
data->dps_range = BMG160_RANGE_500DPS;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_SLOPE_THRES);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_slope_thres\n");
return ret;
}
data->slope_thres = ret;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_INT_EN_1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_en_1\n");
return ret;
}
ret &= ~BMG160_INT1_BIT_OD;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_EN_1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_en_1\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_motion_intr\n");
return ret;
}
return 0;
}
static int bmg160_set_power_state(struct bmg160_data *data, bool on)
{
#ifdef CONFIG_PM
int ret;
if (on)
ret = pm_runtime_get_sync(&data->client->dev);
else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
if (ret < 0) {
dev_err(&data->client->dev,
"Failed: bmg160_set_power_state for %d\n", on);
if (on)
pm_runtime_put_noidle(&data->client->dev);
return ret;
}
#endif
return 0;
}
static int bmg160_setup_any_motion_interrupt(struct bmg160_data *data,
bool status)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_INT_MAP_0);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_map0\n");
return ret;
}
if (status)
ret |= BMG160_INT_MAP_0_BIT_ANY;
else
ret &= ~BMG160_INT_MAP_0_BIT_ANY;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_MAP_0,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_map0\n");
return ret;
}
if (status) {
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_SLOPE_THRES,
data->slope_thres);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_slope_thres\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_MOTION_INTR,
BMG160_INT_MOTION_X |
BMG160_INT_MOTION_Y |
BMG160_INT_MOTION_Z);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_motion_intr\n");
return ret;
}
if (!data->dready_trigger_on) {
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_rst_latch\n");
return ret;
}
}
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_EN_0,
BMG160_DATA_ENABLE_INT);
} else
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_EN_0,
0);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_en0\n");
return ret;
}
return 0;
}
static int bmg160_setup_new_data_interrupt(struct bmg160_data *data,
bool status)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_INT_MAP_1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_map1\n");
return ret;
}
if (status)
ret |= BMG160_INT_MAP_1_BIT_NEW_DATA;
else
ret &= ~BMG160_INT_MAP_1_BIT_NEW_DATA;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_MAP_1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_map1\n");
return ret;
}
if (status) {
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_NON_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_rst_latch\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_EN_0,
BMG160_DATA_ENABLE_INT);
} else {
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_rst_latch\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_EN_0,
0);
}
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_en0\n");
return ret;
}
return 0;
}
static int bmg160_get_bw(struct bmg160_data *data, int *val)
{
int i;
for (i = 0; i < ARRAY_SIZE(bmg160_samp_freq_table); ++i) {
if (bmg160_samp_freq_table[i].bw_bits == data->bw_bits) {
*val = bmg160_samp_freq_table[i].val;
return IIO_VAL_INT;
}
}
return -EINVAL;
}
static int bmg160_set_scale(struct bmg160_data *data, int val)
{
int ret, i;
for (i = 0; i < ARRAY_SIZE(bmg160_scale_table); ++i) {
if (bmg160_scale_table[i].scale == val) {
ret = i2c_smbus_write_byte_data(
data->client,
BMG160_REG_RANGE,
bmg160_scale_table[i].dps_range);
if (ret < 0) {
dev_err(&data->client->dev,
"Error writing reg_range\n");
return ret;
}
data->dps_range = bmg160_scale_table[i].dps_range;
return 0;
}
}
return -EINVAL;
}
static int bmg160_get_temp(struct bmg160_data *data, int *val)
{
int ret;
mutex_lock(&data->mutex);
ret = bmg160_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_TEMP);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_temp\n");
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(ret, 7);
ret = bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
return IIO_VAL_INT;
}
static int bmg160_get_axis(struct bmg160_data *data, int axis, int *val)
{
int ret;
mutex_lock(&data->mutex);
ret = bmg160_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = i2c_smbus_read_word_data(data->client, BMG160_AXIS_TO_REG(axis));
if (ret < 0) {
dev_err(&data->client->dev, "Error reading axis %d\n", axis);
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
*val = sign_extend32(ret, 15);
ret = bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
return IIO_VAL_INT;
}
static int bmg160_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_TEMP:
return bmg160_get_temp(data, val);
case IIO_ANGL_VEL:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
else
return bmg160_get_axis(data, chan->scan_index,
val);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP) {
*val = BMG160_TEMP_CENTER_VAL;
return IIO_VAL_INT;
} else
return -EINVAL;
case IIO_CHAN_INFO_SCALE:
*val = 0;
switch (chan->type) {
case IIO_TEMP:
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ANGL_VEL:
{
int i;
for (i = 0; i < ARRAY_SIZE(bmg160_scale_table); ++i) {
if (bmg160_scale_table[i].dps_range ==
data->dps_range) {
*val2 = bmg160_scale_table[i].scale;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
*val2 = 0;
mutex_lock(&data->mutex);
ret = bmg160_get_bw(data, val);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int bmg160_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = bmg160_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = bmg160_set_bw(data, val);
if (ret < 0) {
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
ret = bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
case IIO_CHAN_INFO_SCALE:
if (val)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bmg160_set_power_state(data, true);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = bmg160_set_scale(data, val2);
if (ret < 0) {
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
ret = bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
return -EINVAL;
}
static int bmg160_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct bmg160_data *data = iio_priv(indio_dev);
*val2 = 0;
switch (info) {
case IIO_EV_INFO_VALUE:
*val = data->slope_thres & BMG160_SLOPE_THRES_MASK;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int bmg160_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct bmg160_data *data = iio_priv(indio_dev);
switch (info) {
case IIO_EV_INFO_VALUE:
if (data->ev_enable_state)
return -EBUSY;
data->slope_thres &= ~BMG160_SLOPE_THRES_MASK;
data->slope_thres |= (val & BMG160_SLOPE_THRES_MASK);
break;
default:
return -EINVAL;
}
return 0;
}
static int bmg160_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct bmg160_data *data = iio_priv(indio_dev);
return data->ev_enable_state;
}
static int bmg160_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
if (state && data->ev_enable_state)
return 0;
mutex_lock(&data->mutex);
if (!state && data->motion_trigger_on) {
data->ev_enable_state = 0;
mutex_unlock(&data->mutex);
return 0;
}
ret = bmg160_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
ret = bmg160_setup_any_motion_interrupt(data, state);
if (ret < 0) {
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
data->ev_enable_state = state;
mutex_unlock(&data->mutex);
return 0;
}
static int bmg160_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct bmg160_data *data = iio_priv(indio_dev);
if (data->dready_trig != trig && data->motion_trig != trig)
return -EINVAL;
return 0;
}
static irqreturn_t bmg160_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bmg160_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
ret = i2c_smbus_read_word_data(data->client,
BMG160_AXIS_TO_REG(bit));
if (ret < 0) {
mutex_unlock(&data->mutex);
goto err;
}
data->buffer[i++] = ret;
}
mutex_unlock(&data->mutex);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
data->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bmg160_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
if (data->dready_trigger_on)
return 0;
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_rst_latch\n");
return ret;
}
return 0;
}
static int bmg160_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
if (!state && data->ev_enable_state && data->motion_trigger_on) {
data->motion_trigger_on = false;
mutex_unlock(&data->mutex);
return 0;
}
ret = bmg160_set_power_state(data, state);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
ret = bmg160_setup_any_motion_interrupt(data, state);
else
ret = bmg160_setup_new_data_interrupt(data, state);
if (ret < 0) {
bmg160_set_power_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
if (data->motion_trig == trig)
data->motion_trigger_on = state;
else
data->dready_trigger_on = state;
mutex_unlock(&data->mutex);
return 0;
}
static irqreturn_t bmg160_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
int dir;
ret = i2c_smbus_read_byte_data(data->client, BMG160_REG_INT_STATUS_2);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_status2\n");
goto ack_intr_status;
}
if (ret & 0x08)
dir = IIO_EV_DIR_RISING;
else
dir = IIO_EV_DIR_FALLING;
if (ret & BMG160_ANY_MOTION_BIT_X)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
0,
IIO_MOD_X,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (ret & BMG160_ANY_MOTION_BIT_Y)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
0,
IIO_MOD_Y,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
if (ret & BMG160_ANY_MOTION_BIT_Z)
iio_push_event(indio_dev, IIO_MOD_EVENT_CODE(IIO_ANGL_VEL,
0,
IIO_MOD_Z,
IIO_EV_TYPE_ROC,
dir),
data->timestamp);
ack_intr_status:
if (!data->dready_trigger_on) {
ret = i2c_smbus_write_byte_data(data->client,
BMG160_REG_INT_RST_LATCH,
BMG160_INT_MODE_LATCH_INT |
BMG160_INT_MODE_LATCH_RESET);
if (ret < 0)
dev_err(&data->client->dev,
"Error writing reg_rst_latch\n");
}
return IRQ_HANDLED;
}
static irqreturn_t bmg160_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct bmg160_data *data = iio_priv(indio_dev);
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
static int bmg160_gpio_probe(struct i2c_client *client,
struct bmg160_data *data)
{
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
gpio = devm_gpiod_get_index(dev, BMG160_GPIO_NAME, 0);
if (IS_ERR(gpio)) {
dev_err(dev, "acpi gpio get index failed\n");
return PTR_ERR(gpio);
}
ret = gpiod_direction_input(gpio);
if (ret)
return ret;
ret = gpiod_to_irq(gpio);
dev_dbg(dev, "GPIO resource, no:%d irq:%d\n", desc_to_gpio(gpio), ret);
return ret;
}
static const char *bmg160_match_acpi_device(struct device *dev)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
return dev_name(dev);
}
static int bmg160_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bmg160_data *data;
struct iio_dev *indio_dev;
int ret;
const char *name = NULL;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
ret = bmg160_chip_init(data);
if (ret < 0)
return ret;
mutex_init(&data->mutex);
if (id)
name = id->name;
if (ACPI_HANDLE(&client->dev))
name = bmg160_match_acpi_device(&client->dev);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = bmg160_channels;
indio_dev->num_channels = ARRAY_SIZE(bmg160_channels);
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bmg160_info;
if (client->irq <= 0)
client->irq = bmg160_gpio_probe(client, data);
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev,
client->irq,
bmg160_data_rdy_trig_poll,
bmg160_event_handler,
IRQF_TRIGGER_RISING,
BMG160_IRQ_NAME,
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
data->dready_trig->ops = &bmg160_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
ret = iio_trigger_register(data->dready_trig);
if (ret)
return ret;
data->motion_trig->dev.parent = &client->dev;
data->motion_trig->ops = &bmg160_trigger_ops;
iio_trigger_set_drvdata(data->motion_trig, indio_dev);
ret = iio_trigger_register(data->motion_trig);
if (ret) {
data->motion_trig = NULL;
goto err_trigger_unregister;
}
ret = iio_triggered_buffer_setup(indio_dev,
NULL,
bmg160_trigger_handler,
NULL);
if (ret < 0) {
dev_err(&client->dev,
"iio triggered buffer setup failed\n");
goto err_trigger_unregister;
}
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto err_iio_unregister;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
BMG160_AUTO_SUSPEND_DELAY_MS);
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
static int bmg160_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bmg160_data *data = iio_priv(indio_dev);
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
bmg160_set_mode(data, BMG160_MODE_DEEP_SUSPEND);
mutex_unlock(&data->mutex);
return 0;
}
static int bmg160_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmg160_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
bmg160_set_mode(data, BMG160_MODE_SUSPEND);
mutex_unlock(&data->mutex);
return 0;
}
static int bmg160_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmg160_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
if (data->dready_trigger_on || data->motion_trigger_on ||
data->ev_enable_state)
bmg160_set_mode(data, BMG160_MODE_NORMAL);
mutex_unlock(&data->mutex);
return 0;
}
static int bmg160_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
ret = bmg160_set_mode(data, BMG160_MODE_SUSPEND);
if (ret < 0) {
dev_err(&data->client->dev, "set mode failed\n");
return -EAGAIN;
}
return 0;
}
static int bmg160_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bmg160_data *data = iio_priv(indio_dev);
int ret;
ret = bmg160_set_mode(data, BMG160_MODE_NORMAL);
if (ret < 0)
return ret;
msleep_interruptible(BMG160_MAX_STARTUP_TIME_MS);
return 0;
}
