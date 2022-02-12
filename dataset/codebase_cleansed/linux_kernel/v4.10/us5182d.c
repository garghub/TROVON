static int us5182d_oneshot_en(struct us5182d_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG0);
if (ret < 0)
return ret;
ret = ret | US5182D_CFG0_ONESHOT_EN;
return i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG0, ret);
}
static int us5182d_set_opmode(struct us5182d_data *data, u8 mode)
{
int ret;
if (mode == data->opmode)
return 0;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG0);
if (ret < 0)
return ret;
ret = ret & ~US5182D_OPMODE_MASK;
ret = ret | (mode << US5182D_OPMODE_SHIFT);
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG0, ret);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_MODE_STORE,
US5182D_STORE_MODE);
if (ret < 0)
return ret;
data->opmode = mode;
msleep(US5182D_OPSTORE_SLEEP_TIME);
return 0;
}
static int us5182d_als_enable(struct us5182d_data *data)
{
int ret;
u8 mode;
if (data->power_mode == US5182D_ONESHOT) {
ret = us5182d_set_opmode(data, US5182D_ALS_ONLY);
if (ret < 0)
return ret;
data->px_enabled = false;
}
if (data->als_enabled)
return 0;
mode = data->px_enabled ? US5182D_ALS_PX : US5182D_ALS_ONLY;
ret = us5182d_set_opmode(data, mode);
if (ret < 0)
return ret;
data->als_enabled = true;
return 0;
}
static int us5182d_px_enable(struct us5182d_data *data)
{
int ret;
u8 mode;
if (data->power_mode == US5182D_ONESHOT) {
ret = us5182d_set_opmode(data, US5182D_PX_ONLY);
if (ret < 0)
return ret;
data->als_enabled = false;
}
if (data->px_enabled)
return 0;
mode = data->als_enabled ? US5182D_ALS_PX : US5182D_PX_ONLY;
ret = us5182d_set_opmode(data, mode);
if (ret < 0)
return ret;
data->px_enabled = true;
return 0;
}
static int us5182d_get_als(struct us5182d_data *data)
{
int ret;
unsigned long result;
ret = us5182d_als_enable(data);
if (ret < 0)
return ret;
ret = i2c_smbus_read_word_data(data->client,
US5182D_REG_ADL);
if (ret < 0)
return ret;
result = ret * data->ga / US5182D_GA_RESOLUTION;
if (result > 0xffff)
result = 0xffff;
return result;
}
static int us5182d_get_px(struct us5182d_data *data)
{
int ret;
ret = us5182d_px_enable(data);
if (ret < 0)
return ret;
return i2c_smbus_read_word_data(data->client,
US5182D_REG_PDL);
}
static int us5182d_shutdown_en(struct us5182d_data *data, u8 state)
{
int ret;
if (data->power_mode == US5182D_ONESHOT)
return 0;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG0);
if (ret < 0)
return ret;
ret = ret & ~US5182D_CFG0_SHUTDOWN_EN;
ret = ret | state;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG0, ret);
if (ret < 0)
return ret;
if (state & US5182D_CFG0_SHUTDOWN_EN) {
data->als_enabled = false;
data->px_enabled = false;
}
return ret;
}
static int us5182d_set_power_state(struct us5182d_data *data, bool on)
{
int ret;
if (data->power_mode == US5182D_ONESHOT)
return 0;
if (on) {
ret = pm_runtime_get_sync(&data->client->dev);
if (ret < 0)
pm_runtime_put_noidle(&data->client->dev);
} else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
return ret;
}
static int us5182d_read_value(struct us5182d_data *data,
struct iio_chan_spec const *chan)
{
int ret, value;
mutex_lock(&data->lock);
if (data->power_mode == US5182D_ONESHOT) {
ret = us5182d_oneshot_en(data);
if (ret < 0)
goto out_err;
}
ret = us5182d_set_power_state(data, true);
if (ret < 0)
goto out_err;
if (chan->type == IIO_LIGHT)
ret = us5182d_get_als(data);
else
ret = us5182d_get_px(data);
if (ret < 0)
goto out_poweroff;
value = ret;
ret = us5182d_set_power_state(data, false);
if (ret < 0)
goto out_err;
mutex_unlock(&data->lock);
return value;
out_poweroff:
us5182d_set_power_state(data, false);
out_err:
mutex_unlock(&data->lock);
return ret;
}
static int us5182d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = us5182d_read_value(data, chan);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG1);
if (ret < 0)
return ret;
*val = 0;
*val2 = us5182d_scales[ret & US5182D_AGAIN_MASK];
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int us5182d_update_dark_th(struct us5182d_data *data, int index)
{
__be16 dark_th = cpu_to_be16(data->us5182d_dark_ths[index]);
int ret;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_UDARK_TH,
((u8 *)&dark_th)[0]);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(data->client, US5182D_REG_UDARK_TH + 1,
((u8 *)&dark_th)[1]);
}
static int us5182d_apply_scale(struct us5182d_data *data, int index)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG1);
if (ret < 0)
return ret;
ret = ret & (~US5182D_AGAIN_MASK);
ret |= index;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG1, ret);
if (ret < 0)
return ret;
return us5182d_update_dark_th(data, index);
}
static int us5182d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret, i;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(us5182d_scales); i++)
if (val2 == us5182d_scales[i]) {
mutex_lock(&data->lock);
ret = us5182d_apply_scale(data, i);
mutex_unlock(&data->lock);
return ret;
}
break;
default:
return -EINVAL;
}
return -EINVAL;
}
static int us5182d_setup_prox(struct iio_dev *indio_dev,
enum iio_event_direction dir, u16 val)
{
struct us5182d_data *data = iio_priv(indio_dev);
if (dir == IIO_EV_DIR_FALLING)
return i2c_smbus_write_word_data(data->client,
US5182D_REG_PXL_TH, val);
else if (dir == IIO_EV_DIR_RISING)
return i2c_smbus_write_word_data(data->client,
US5182D_REG_PXH_TH, val);
return 0;
}
static int us5182d_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int *val,
int *val2)
{
struct us5182d_data *data = iio_priv(indio_dev);
switch (dir) {
case IIO_EV_DIR_RISING:
mutex_lock(&data->lock);
*val = data->px_high_th;
mutex_unlock(&data->lock);
break;
case IIO_EV_DIR_FALLING:
mutex_lock(&data->lock);
*val = data->px_low_th;
mutex_unlock(&data->lock);
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int us5182d_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int val,
int val2)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
if (val < 0 || val > USHRT_MAX || val2 != 0)
return -EINVAL;
switch (dir) {
case IIO_EV_DIR_RISING:
mutex_lock(&data->lock);
if (data->rising_en) {
ret = us5182d_setup_prox(indio_dev, dir, val);
if (ret < 0)
goto err;
}
data->px_high_th = val;
mutex_unlock(&data->lock);
break;
case IIO_EV_DIR_FALLING:
mutex_lock(&data->lock);
if (data->falling_en) {
ret = us5182d_setup_prox(indio_dev, dir, val);
if (ret < 0)
goto err;
}
data->px_low_th = val;
mutex_unlock(&data->lock);
break;
default:
return -EINVAL;
}
return 0;
err:
mutex_unlock(&data->lock);
return ret;
}
static int us5182d_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
switch (dir) {
case IIO_EV_DIR_RISING:
mutex_lock(&data->lock);
ret = data->rising_en;
mutex_unlock(&data->lock);
break;
case IIO_EV_DIR_FALLING:
mutex_lock(&data->lock);
ret = data->falling_en;
mutex_unlock(&data->lock);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int us5182d_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
u16 new_th;
mutex_lock(&data->lock);
switch (dir) {
case IIO_EV_DIR_RISING:
if (data->rising_en == state) {
mutex_unlock(&data->lock);
return 0;
}
new_th = US5182D_PXH_TH_DISABLE;
if (state) {
data->power_mode = US5182D_CONTINUOUS;
ret = us5182d_set_power_state(data, true);
if (ret < 0)
goto err;
ret = us5182d_px_enable(data);
if (ret < 0)
goto err_poweroff;
new_th = data->px_high_th;
}
ret = us5182d_setup_prox(indio_dev, dir, new_th);
if (ret < 0)
goto err_poweroff;
data->rising_en = state;
break;
case IIO_EV_DIR_FALLING:
if (data->falling_en == state) {
mutex_unlock(&data->lock);
return 0;
}
new_th = US5182D_PXL_TH_DISABLE;
if (state) {
data->power_mode = US5182D_CONTINUOUS;
ret = us5182d_set_power_state(data, true);
if (ret < 0)
goto err;
ret = us5182d_px_enable(data);
if (ret < 0)
goto err_poweroff;
new_th = data->px_low_th;
}
ret = us5182d_setup_prox(indio_dev, dir, new_th);
if (ret < 0)
goto err_poweroff;
data->falling_en = state;
break;
default:
ret = -EINVAL;
goto err;
}
if (!state) {
ret = us5182d_set_power_state(data, false);
if (ret < 0)
goto err;
}
if (!data->falling_en && !data->rising_en && !data->default_continuous)
data->power_mode = US5182D_ONESHOT;
mutex_unlock(&data->lock);
return 0;
err_poweroff:
if (state)
us5182d_set_power_state(data, false);
err:
mutex_unlock(&data->lock);
return ret;
}
static int us5182d_reset(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
return i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG3,
US5182D_RESET_CHIP);
}
static int us5182d_init(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
int i, ret;
ret = us5182d_reset(indio_dev);
if (ret < 0)
return ret;
data->opmode = 0;
data->power_mode = US5182D_CONTINUOUS;
data->px_low_th = US5182D_REG_PXL_TH_DEFAULT;
data->px_high_th = US5182D_REG_PXH_TH_DEFAULT;
for (i = 0; i < ARRAY_SIZE(us5182d_regvals); i++) {
ret = i2c_smbus_write_byte_data(data->client,
us5182d_regvals[i].reg,
us5182d_regvals[i].val);
if (ret < 0)
return ret;
}
data->als_enabled = true;
data->px_enabled = true;
if (!data->default_continuous) {
ret = us5182d_shutdown_en(data, US5182D_CFG0_SHUTDOWN_EN);
if (ret < 0)
return ret;
data->power_mode = US5182D_ONESHOT;
}
return ret;
}
static void us5182d_get_platform_data(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
if (device_property_read_u32(&data->client->dev, "upisemi,glass-coef",
&data->ga))
data->ga = US5182D_GA_RESOLUTION;
if (device_property_read_u16_array(&data->client->dev,
"upisemi,dark-ths",
data->us5182d_dark_ths,
ARRAY_SIZE(us5182d_dark_ths_vals)))
data->us5182d_dark_ths = us5182d_dark_ths_vals;
if (device_property_read_u8(&data->client->dev,
"upisemi,upper-dark-gain",
&data->upper_dark_gain))
data->upper_dark_gain = US5182D_REG_AUTO_HDARK_GAIN_DEFAULT;
if (device_property_read_u8(&data->client->dev,
"upisemi,lower-dark-gain",
&data->lower_dark_gain))
data->lower_dark_gain = US5182D_REG_AUTO_LDARK_GAIN_DEFAULT;
data->default_continuous = device_property_read_bool(&data->client->dev,
"upisemi,continuous");
}
static int us5182d_dark_gain_config(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
ret = us5182d_update_dark_th(data, US5182D_CFG1_AGAIN_DEFAULT);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
US5182D_REG_AUTO_LDARK_GAIN,
data->lower_dark_gain);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
US5182D_REG_AUTO_HDARK_GAIN,
data->upper_dark_gain);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(data->client, US5182D_REG_DARK_AUTO_EN,
US5182D_REG_DARK_AUTO_EN_DEFAULT);
}
static irqreturn_t us5182d_irq_thread_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct us5182d_data *data = iio_priv(indio_dev);
enum iio_event_direction dir;
int ret;
u64 ev;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG0);
if (ret < 0) {
dev_err(&data->client->dev, "i2c transfer error in irq\n");
return IRQ_HANDLED;
}
dir = ret & US5182D_CFG0_PROX ? IIO_EV_DIR_RISING : IIO_EV_DIR_FALLING;
ev = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, 1, IIO_EV_TYPE_THRESH, dir);
iio_push_event(indio_dev, ev, iio_get_time_ns(indio_dev));
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG0,
ret & ~US5182D_CFG0_PX_IRQ);
if (ret < 0)
dev_err(&data->client->dev, "i2c transfer error in irq\n");
return IRQ_HANDLED;
}
static int us5182d_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct us5182d_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &us5182d_info;
indio_dev->name = US5182D_DRV_NAME;
indio_dev->channels = us5182d_channels;
indio_dev->num_channels = ARRAY_SIZE(us5182d_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CHIPID);
if (ret != US5182D_CHIPID) {
dev_err(&data->client->dev,
"Failed to detect US5182 light chip\n");
return (ret < 0) ? ret : -ENODEV;
}
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq, NULL,
us5182d_irq_thread_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"us5182d-irq", indio_dev);
if (ret < 0)
return ret;
} else
dev_warn(&client->dev, "no valid irq found\n");
us5182d_get_platform_data(indio_dev);
ret = us5182d_init(indio_dev);
if (ret < 0)
return ret;
ret = us5182d_dark_gain_config(indio_dev);
if (ret < 0)
goto out_err;
if (data->default_continuous) {
ret = pm_runtime_set_active(&client->dev);
if (ret < 0)
goto out_err;
}
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
US5182D_SLEEP_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0)
goto out_err;
return 0;
out_err:
us5182d_shutdown_en(data, US5182D_CFG0_SHUTDOWN_EN);
return ret;
}
static int us5182d_remove(struct i2c_client *client)
{
struct us5182d_data *data = iio_priv(i2c_get_clientdata(client));
iio_device_unregister(i2c_get_clientdata(client));
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
return us5182d_shutdown_en(data, US5182D_CFG0_SHUTDOWN_EN);
}
static int us5182d_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct us5182d_data *data = iio_priv(indio_dev);
if (data->power_mode == US5182D_CONTINUOUS)
return us5182d_shutdown_en(data, US5182D_CFG0_SHUTDOWN_EN);
return 0;
}
static int us5182d_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct us5182d_data *data = iio_priv(indio_dev);
if (data->power_mode == US5182D_CONTINUOUS)
return us5182d_shutdown_en(data,
~US5182D_CFG0_SHUTDOWN_EN & 0xff);
return 0;
}
