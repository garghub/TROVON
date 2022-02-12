static u8 mma9553_get_bits(u16 val, u16 mask)
{
return (val & mask) >> (ffs(mask) - 1);
}
static u16 mma9553_set_bits(u16 current_val, u16 val, u16 mask)
{
return (current_val & ~mask) | (val << (ffs(mask) - 1));
}
static enum iio_modifier mma9553_activity_to_mod(enum activity_level activity)
{
switch (activity) {
case ACTIVITY_RUNNING:
return IIO_MOD_RUNNING;
case ACTIVITY_JOGGING:
return IIO_MOD_JOGGING;
case ACTIVITY_WALKING:
return IIO_MOD_WALKING;
case ACTIVITY_REST:
return IIO_MOD_STILL;
case ACTIVITY_UNKNOWN:
default:
return IIO_NO_MOD;
}
}
static void mma9553_init_events(struct mma9553_data *data)
{
int i;
data->num_events = MMA9553_EVENTS_INFO_SIZE;
for (i = 0; i < data->num_events; i++) {
data->events[i].info = &mma9553_events_info[i];
data->events[i].enabled = false;
}
}
static struct mma9553_event *mma9553_get_event(struct mma9553_data *data,
enum iio_chan_type type,
enum iio_modifier mod,
enum iio_event_direction dir)
{
int i;
for (i = 0; i < data->num_events; i++)
if (data->events[i].info->type == type &&
data->events[i].info->mod == mod &&
data->events[i].info->dir == dir)
return &data->events[i];
return NULL;
}
static bool mma9553_is_any_event_enabled(struct mma9553_data *data,
bool check_type,
enum iio_chan_type type)
{
int i;
for (i = 0; i < data->num_events; i++)
if ((check_type && data->events[i].info->type == type &&
data->events[i].enabled) ||
(!check_type && data->events[i].enabled))
return true;
return false;
}
static int mma9553_set_config(struct mma9553_data *data, u16 reg,
u16 *p_reg_val, u16 val, u16 mask)
{
int ret, retries;
u16 reg_val, config;
reg_val = *p_reg_val;
if (val == mma9553_get_bits(reg_val, mask))
return 0;
reg_val = mma9553_set_bits(reg_val, val, mask);
ret = mma9551_write_config_word(data->client, MMA9551_APPID_PEDOMETER,
reg, reg_val);
if (ret < 0) {
dev_err(&data->client->dev,
"error writing config register 0x%x\n", reg);
return ret;
}
*p_reg_val = reg_val;
config = mma9553_set_bits(data->conf.config, 1,
MMA9553_MASK_CONF_CONFIG);
ret = mma9551_write_config_word(data->client, MMA9551_APPID_PEDOMETER,
MMA9553_REG_CONF_CONF_STEPLEN, config);
if (ret < 0) {
dev_err(&data->client->dev,
"error writing config register 0x%x\n",
MMA9553_REG_CONF_CONF_STEPLEN);
return ret;
}
retries = MMA9553_CONFIG_RETRIES;
do {
mma9551_sleep(MMA9553_DEFAULT_SAMPLE_RATE);
ret = mma9551_read_config_word(data->client,
MMA9551_APPID_PEDOMETER,
MMA9553_REG_CONF_CONF_STEPLEN,
&config);
if (ret < 0)
return ret;
} while (mma9553_get_bits(config, MMA9553_MASK_CONF_CONFIG) &&
--retries > 0);
return 0;
}
static int mma9553_read_activity_stepcnt(struct mma9553_data *data,
u8 *activity, u16 *stepcnt)
{
u16 buf[2];
int ret;
ret = mma9551_read_status_words(data->client, MMA9551_APPID_PEDOMETER,
MMA9553_REG_STATUS, sizeof(u32), buf);
if (ret < 0) {
dev_err(&data->client->dev,
"error reading status and stepcnt\n");
return ret;
}
*activity = mma9553_get_bits(buf[0], MMA9553_MASK_STATUS_ACTIVITY);
*stepcnt = buf[1];
return 0;
}
static int mma9553_conf_gpio(struct mma9553_data *data)
{
u8 bitnum = 0, appid = MMA9551_APPID_PEDOMETER;
int ret;
struct mma9553_event *ev_step_detect;
bool activity_enabled;
activity_enabled =
mma9553_is_any_event_enabled(data, true, IIO_ACTIVITY);
ev_step_detect =
mma9553_get_event(data, IIO_STEPS, IIO_NO_MOD, IIO_EV_DIR_NONE);
if (activity_enabled && ev_step_detect->enabled)
bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_MRGFL);
else if (ev_step_detect->enabled)
bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_STEPCHG);
else if (activity_enabled)
bitnum = MMA9553_STATUS_TO_BITNUM(MMA9553_MASK_STATUS_ACTCHG);
else
appid = MMA9551_APPID_NONE;
if (data->gpio_bitnum == bitnum)
return 0;
if (activity_enabled || ev_step_detect->enabled) {
ret = mma9553_read_activity_stepcnt(data, &data->activity,
&data->stepcnt);
if (ret < 0)
return ret;
}
ret = mma9551_gpio_config(data->client,
MMA9553_DEFAULT_GPIO_PIN,
appid, bitnum, MMA9553_DEFAULT_GPIO_POLARITY);
if (ret < 0)
return ret;
data->gpio_bitnum = bitnum;
return 0;
}
static int mma9553_init(struct mma9553_data *data)
{
int ret;
ret = mma9551_read_version(data->client);
if (ret)
return ret;
ret =
mma9551_read_config_words(data->client, MMA9551_APPID_PEDOMETER,
MMA9553_REG_CONF_SLEEPMIN,
sizeof(data->conf), (u16 *) &data->conf);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read configuration registers\n");
return ret;
}
data->gpio_bitnum = MMA9553_MAX_BITNUM;
ret = mma9553_conf_gpio(data);
if (ret < 0)
return ret;
ret = mma9551_app_reset(data->client, MMA9551_RSC_PED);
if (ret < 0)
return ret;
data->conf.sleepmin = MMA9553_DEFAULT_SLEEPMIN;
data->conf.sleepmax = MMA9553_DEFAULT_SLEEPMAX;
data->conf.sleepthd = MMA9553_DEFAULT_SLEEPTHD;
data->conf.config =
mma9553_set_bits(data->conf.config, 1, MMA9553_MASK_CONF_CONFIG);
data->conf.config = mma9553_set_bits(data->conf.config, 1,
MMA9553_MASK_CONF_ACT_DBCNTM);
ret =
mma9551_write_config_words(data->client, MMA9551_APPID_PEDOMETER,
MMA9553_REG_CONF_SLEEPMIN,
sizeof(data->conf), (u16 *) &data->conf);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to write configuration registers\n");
return ret;
}
return mma9551_set_device_state(data->client, true);
}
static int mma9553_read_status_word(struct mma9553_data *data, u16 reg,
u16 *tmp)
{
bool powered_on;
int ret;
powered_on = mma9553_is_any_event_enabled(data, false, 0) ||
data->stepcnt_enabled;
if (!powered_on) {
dev_err(&data->client->dev, "No channels enabled\n");
return -EINVAL;
}
mutex_lock(&data->mutex);
ret = mma9551_read_status_word(data->client, MMA9551_APPID_PEDOMETER,
reg, tmp);
mutex_unlock(&data->mutex);
return ret;
}
static int mma9553_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
u16 tmp;
u8 activity;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_STEPS:
ret = mma9553_read_status_word(data,
MMA9553_REG_STEPCNT,
&tmp);
if (ret < 0)
return ret;
*val = tmp;
return IIO_VAL_INT;
case IIO_DISTANCE:
ret = mma9553_read_status_word(data,
MMA9553_REG_DISTANCE,
&tmp);
if (ret < 0)
return ret;
*val = tmp;
return IIO_VAL_INT;
case IIO_ACTIVITY:
ret = mma9553_read_status_word(data,
MMA9553_REG_STATUS,
&tmp);
if (ret < 0)
return ret;
activity =
mma9553_get_bits(tmp, MMA9553_MASK_STATUS_ACTIVITY);
if (chan->channel2 == mma9553_activity_to_mod(activity))
*val = 100;
else
*val = 0;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_VELOCITY:
if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
return -EINVAL;
ret = mma9553_read_status_word(data,
MMA9553_REG_SPEED,
&tmp);
if (ret < 0)
return ret;
*val = tmp;
return IIO_VAL_INT;
case IIO_ENERGY:
ret = mma9553_read_status_word(data,
MMA9553_REG_CALORIES,
&tmp);
if (ret < 0)
return ret;
*val = tmp;
return IIO_VAL_INT;
case IIO_ACCEL:
mutex_lock(&data->mutex);
ret = mma9551_read_accel_chan(data->client,
chan, val, val2);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VELOCITY:
if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
return -EINVAL;
*val = 0;
*val2 = 277;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ENERGY:
*val = 4184;
return IIO_VAL_INT;
case IIO_ACCEL:
return mma9551_read_accel_scale(val, val2);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_ENABLE:
*val = data->stepcnt_enabled;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBHEIGHT:
tmp = mma9553_get_bits(data->conf.height_weight,
MMA9553_MASK_CONF_HEIGHT);
*val = tmp / 100;
*val2 = (tmp % 100) * 10000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_CALIBWEIGHT:
*val = mma9553_get_bits(data->conf.height_weight,
MMA9553_MASK_CONF_WEIGHT);
return IIO_VAL_INT;
case IIO_CHAN_INFO_DEBOUNCE_COUNT:
switch (chan->type) {
case IIO_STEPS:
*val = mma9553_get_bits(data->conf.filter,
MMA9553_MASK_CONF_FILTSTEP);
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_DEBOUNCE_TIME:
switch (chan->type) {
case IIO_STEPS:
*val = mma9553_get_bits(data->conf.filter,
MMA9553_MASK_CONF_FILTTIME);
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_INT_TIME:
switch (chan->type) {
case IIO_VELOCITY:
if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
return -EINVAL;
*val = mma9553_get_bits(data->conf.speed_step,
MMA9553_MASK_CONF_SPDPRD);
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int mma9553_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mma9553_data *data = iio_priv(indio_dev);
int ret, tmp;
switch (mask) {
case IIO_CHAN_INFO_ENABLE:
if (data->stepcnt_enabled == !!val)
return 0;
mutex_lock(&data->mutex);
ret = mma9551_set_power_state(data->client, val);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
data->stepcnt_enabled = val;
mutex_unlock(&data->mutex);
return 0;
case IIO_CHAN_INFO_CALIBHEIGHT:
tmp = val * 100 + val2 / 10000;
if (tmp < 0 || tmp > 255)
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data,
MMA9553_REG_CONF_HEIGHT_WEIGHT,
&data->conf.height_weight,
tmp, MMA9553_MASK_CONF_HEIGHT);
mutex_unlock(&data->mutex);
return ret;
case IIO_CHAN_INFO_CALIBWEIGHT:
if (val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data,
MMA9553_REG_CONF_HEIGHT_WEIGHT,
&data->conf.height_weight,
val, MMA9553_MASK_CONF_WEIGHT);
mutex_unlock(&data->mutex);
return ret;
case IIO_CHAN_INFO_DEBOUNCE_COUNT:
switch (chan->type) {
case IIO_STEPS:
if (val < 0)
return -EINVAL;
if (val > 6)
val = 6;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
&data->conf.filter, val,
MMA9553_MASK_CONF_FILTSTEP);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_DEBOUNCE_TIME:
switch (chan->type) {
case IIO_STEPS:
if (val < 0 || val > 127)
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
&data->conf.filter, val,
MMA9553_MASK_CONF_FILTTIME);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_INT_TIME:
switch (chan->type) {
case IIO_VELOCITY:
if (chan->channel2 != IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z)
return -EINVAL;
if (val < 2)
return -EINVAL;
if (val > 5)
val = 5;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data,
MMA9553_REG_CONF_SPEED_STEP,
&data->conf.speed_step, val,
MMA9553_MASK_CONF_SPDPRD);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int mma9553_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct mma9553_data *data = iio_priv(indio_dev);
struct mma9553_event *event;
event = mma9553_get_event(data, chan->type, chan->channel2, dir);
if (!event)
return -EINVAL;
return event->enabled;
}
static int mma9553_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct mma9553_data *data = iio_priv(indio_dev);
struct mma9553_event *event;
int ret;
event = mma9553_get_event(data, chan->type, chan->channel2, dir);
if (!event)
return -EINVAL;
if (event->enabled == state)
return 0;
mutex_lock(&data->mutex);
ret = mma9551_set_power_state(data->client, state);
if (ret < 0)
goto err_out;
event->enabled = state;
ret = mma9553_conf_gpio(data);
if (ret < 0)
goto err_conf_gpio;
mutex_unlock(&data->mutex);
return 0;
err_conf_gpio:
if (state) {
event->enabled = false;
mma9551_set_power_state(data->client, false);
}
err_out:
mutex_unlock(&data->mutex);
return ret;
}
static int mma9553_read_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct mma9553_data *data = iio_priv(indio_dev);
*val2 = 0;
switch (info) {
case IIO_EV_INFO_VALUE:
switch (chan->type) {
case IIO_STEPS:
*val = mma9553_get_bits(data->conf.speed_step,
MMA9553_MASK_CONF_STEPCOALESCE);
return IIO_VAL_INT;
case IIO_ACTIVITY:
*val = 50;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_EV_INFO_PERIOD:
switch (chan->type) {
case IIO_ACTIVITY:
*val = MMA9553_ACTIVITY_THD_TO_SEC(data->conf.actthd);
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int mma9553_write_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
switch (info) {
case IIO_EV_INFO_VALUE:
switch (chan->type) {
case IIO_STEPS:
if (val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data,
MMA9553_REG_CONF_SPEED_STEP,
&data->conf.speed_step, val,
MMA9553_MASK_CONF_STEPCOALESCE);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
case IIO_EV_INFO_PERIOD:
switch (chan->type) {
case IIO_ACTIVITY:
if (val < 0 || val > MMA9553_ACTIVITY_THD_TO_SEC(
MMA9553_MAX_ACTTHD))
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data, MMA9553_REG_CONF_ACTTHD,
&data->conf.actthd,
MMA9553_ACTIVITY_SEC_TO_THD
(val), MMA9553_MASK_CONF_WORD);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int mma9553_get_calibgender_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct mma9553_data *data = iio_priv(indio_dev);
u8 gender;
gender = mma9553_get_bits(data->conf.filter, MMA9553_MASK_CONF_MALE);
return !gender;
}
static int mma9553_set_calibgender_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct mma9553_data *data = iio_priv(indio_dev);
u8 gender = !mode;
int ret;
if ((mode != 0) && (mode != 1))
return -EINVAL;
mutex_lock(&data->mutex);
ret = mma9553_set_config(data, MMA9553_REG_CONF_FILTER,
&data->conf.filter, gender,
MMA9553_MASK_CONF_MALE);
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t mma9553_irq_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct mma9553_data *data = iio_priv(indio_dev);
data->timestamp = iio_get_time_ns();
return IRQ_WAKE_THREAD;
}
static irqreturn_t mma9553_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct mma9553_data *data = iio_priv(indio_dev);
u16 stepcnt;
u8 activity;
struct mma9553_event *ev_activity, *ev_prev_activity, *ev_step_detect;
int ret;
mutex_lock(&data->mutex);
ret = mma9553_read_activity_stepcnt(data, &activity, &stepcnt);
if (ret < 0) {
mutex_unlock(&data->mutex);
return IRQ_HANDLED;
}
ev_prev_activity =
mma9553_get_event(data, IIO_ACTIVITY,
mma9553_activity_to_mod(data->activity),
IIO_EV_DIR_FALLING);
ev_activity =
mma9553_get_event(data, IIO_ACTIVITY,
mma9553_activity_to_mod(activity),
IIO_EV_DIR_RISING);
ev_step_detect =
mma9553_get_event(data, IIO_STEPS, IIO_NO_MOD, IIO_EV_DIR_NONE);
if (ev_step_detect->enabled && (stepcnt != data->stepcnt)) {
data->stepcnt = stepcnt;
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_STEPS, 0, IIO_NO_MOD,
IIO_EV_DIR_NONE, IIO_EV_TYPE_CHANGE, 0, 0, 0),
data->timestamp);
}
if (activity != data->activity) {
data->activity = activity;
if (ev_prev_activity && ev_prev_activity->enabled)
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_ACTIVITY, 0,
ev_prev_activity->info->mod,
IIO_EV_DIR_FALLING,
IIO_EV_TYPE_THRESH, 0, 0, 0),
data->timestamp);
if (ev_activity && ev_activity->enabled)
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_ACTIVITY, 0,
ev_activity->info->mod,
IIO_EV_DIR_RISING,
IIO_EV_TYPE_THRESH, 0, 0, 0),
data->timestamp);
}
mutex_unlock(&data->mutex);
return IRQ_HANDLED;
}
static int mma9553_gpio_probe(struct i2c_client *client)
{
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
gpio = devm_gpiod_get_index(dev, MMA9553_GPIO_NAME, 0, GPIOD_IN);
if (IS_ERR(gpio)) {
dev_err(dev, "ACPI GPIO get index failed\n");
return PTR_ERR(gpio);
}
ret = gpiod_to_irq(gpio);
dev_dbg(dev, "GPIO resource, no:%d irq:%d\n", desc_to_gpio(gpio), ret);
return ret;
}
static const char *mma9553_match_acpi_device(struct device *dev)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
return dev_name(dev);
}
static int mma9553_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mma9553_data *data;
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
name = mma9553_match_acpi_device(&client->dev);
else
return -ENOSYS;
mutex_init(&data->mutex);
mma9553_init_events(data);
ret = mma9553_init(data);
if (ret < 0)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = mma9553_channels;
indio_dev->num_channels = ARRAY_SIZE(mma9553_channels);
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mma9553_info;
if (client->irq < 0)
client->irq = mma9553_gpio_probe(client);
if (client->irq >= 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
mma9553_irq_handler,
mma9553_event_handler,
IRQF_TRIGGER_RISING,
MMA9553_IRQ_NAME, indio_dev);
if (ret < 0) {
dev_err(&client->dev, "request irq %d failed\n",
client->irq);
goto out_poweroff;
}
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto out_poweroff;
}
ret = pm_runtime_set_active(&client->dev);
if (ret < 0)
goto out_iio_unregister;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
MMA9551_AUTO_SUSPEND_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
dev_dbg(&indio_dev->dev, "Registered device %s\n", name);
return 0;
out_iio_unregister:
iio_device_unregister(indio_dev);
out_poweroff:
mma9551_set_device_state(client, false);
return ret;
}
static int mma9553_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct mma9553_data *data = iio_priv(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
iio_device_unregister(indio_dev);
mutex_lock(&data->mutex);
mma9551_set_device_state(data->client, false);
mutex_unlock(&data->mutex);
return 0;
}
static int mma9553_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = mma9551_set_device_state(data->client, false);
mutex_unlock(&data->mutex);
if (ret < 0) {
dev_err(&data->client->dev, "powering off device failed\n");
return -EAGAIN;
}
return 0;
}
static int mma9553_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
ret = mma9551_set_device_state(data->client, true);
if (ret < 0)
return ret;
mma9551_sleep(MMA9553_DEFAULT_SAMPLE_RATE);
return 0;
}
static int mma9553_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = mma9551_set_device_state(data->client, false);
mutex_unlock(&data->mutex);
return ret;
}
static int mma9553_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct mma9553_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = mma9551_set_device_state(data->client, true);
mutex_unlock(&data->mutex);
return ret;
}
