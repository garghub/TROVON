static int apds9960_set_it_time(struct apds9960_data *data, int val2)
{
int ret = -EINVAL;
int idx;
for (idx = 0; idx < ARRAY_SIZE(apds9960_int_time); idx++) {
if (apds9960_int_time[idx][0] == val2) {
mutex_lock(&data->lock);
ret = regmap_write(data->regmap, APDS9960_REG_ATIME,
apds9960_int_time[idx][1]);
if (!ret)
data->als_adc_int_us = val2;
mutex_unlock(&data->lock);
break;
}
}
return ret;
}
static int apds9960_set_pxs_gain(struct apds9960_data *data, int val)
{
int ret = -EINVAL;
int idx;
for (idx = 0; idx < ARRAY_SIZE(apds9960_pxs_gain_map); idx++) {
if (apds9960_pxs_gain_map[idx] == val) {
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap,
APDS9960_REG_CONTROL,
APDS9960_REG_CONTROL_PGAIN_MASK,
idx << APDS9960_REG_CONTROL_PGAIN_MASK_SHIFT);
if (ret) {
mutex_unlock(&data->lock);
break;
}
ret = regmap_update_bits(data->regmap,
APDS9960_REG_CONFIG_2,
APDS9960_REG_CONFIG_2_GGAIN_MASK,
idx << APDS9960_REG_CONFIG_2_GGAIN_MASK_SHIFT);
if (!ret)
data->pxs_gain = idx;
mutex_unlock(&data->lock);
break;
}
}
return ret;
}
static int apds9960_set_als_gain(struct apds9960_data *data, int val)
{
int ret = -EINVAL;
int idx;
for (idx = 0; idx < ARRAY_SIZE(apds9960_als_gain_map); idx++) {
if (apds9960_als_gain_map[idx] == val) {
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap,
APDS9960_REG_CONTROL,
APDS9960_REG_CONTROL_AGAIN_MASK, idx);
if (!ret)
data->als_gain = idx;
mutex_unlock(&data->lock);
break;
}
}
return ret;
}
static int apds9960_set_power_state(struct apds9960_data *data, bool on)
{
struct device *dev = &data->client->dev;
int ret = 0;
mutex_lock(&data->lock);
if (on) {
int suspended;
suspended = pm_runtime_suspended(dev);
ret = pm_runtime_get_sync(dev);
if (suspended)
usleep_range(data->als_adc_int_us,
APDS9960_MAX_INT_TIME_IN_US);
} else {
pm_runtime_mark_last_busy(dev);
ret = pm_runtime_put_autosuspend(dev);
}
mutex_unlock(&data->lock);
return ret;
}
static int apds9960_set_power_state(struct apds9960_data *data, bool on)
{
return 0;
}
static int apds9960_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct apds9960_data *data = iio_priv(indio_dev);
__le16 buf;
int ret = -EINVAL;
if (data->gesture_mode_running)
return -EBUSY;
switch (mask) {
case IIO_CHAN_INFO_RAW:
apds9960_set_power_state(data, true);
switch (chan->type) {
case IIO_PROXIMITY:
ret = regmap_read(data->regmap, chan->address, val);
if (!ret)
ret = IIO_VAL_INT;
break;
case IIO_INTENSITY:
ret = regmap_bulk_read(data->regmap, chan->address,
&buf, 2);
if (!ret)
ret = IIO_VAL_INT;
*val = le16_to_cpu(buf);
break;
default:
ret = -EINVAL;
}
apds9960_set_power_state(data, false);
break;
case IIO_CHAN_INFO_INT_TIME:
mutex_lock(&data->lock);
switch (chan->type) {
case IIO_INTENSITY:
*val = 0;
*val2 = data->als_adc_int_us;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&data->lock);
break;
case IIO_CHAN_INFO_SCALE:
mutex_lock(&data->lock);
switch (chan->type) {
case IIO_PROXIMITY:
*val = apds9960_pxs_gain_map[data->pxs_gain];
ret = IIO_VAL_INT;
break;
case IIO_INTENSITY:
*val = apds9960_als_gain_map[data->als_gain];
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&data->lock);
break;
}
return ret;
}
static int apds9960_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct apds9960_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
switch (chan->type) {
case IIO_INTENSITY:
if (val != 0)
return -EINVAL;
return apds9960_set_it_time(data, val2);
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
if (val2 != 0)
return -EINVAL;
switch (chan->type) {
case IIO_PROXIMITY:
return apds9960_set_pxs_gain(data, val);
case IIO_INTENSITY:
return apds9960_set_als_gain(data, val);
default:
return -EINVAL;
}
default:
return -EINVAL;
};
return 0;
}
static inline int apds9960_get_thres_reg(const struct iio_chan_spec *chan,
enum iio_event_direction dir,
u8 *reg)
{
switch (dir) {
case IIO_EV_DIR_RISING:
switch (chan->type) {
case IIO_PROXIMITY:
*reg = APDS9960_REG_PIHT;
break;
case IIO_INTENSITY:
*reg = APDS9960_REG_AIHTL;
break;
default:
return -EINVAL;
}
break;
case IIO_EV_DIR_FALLING:
switch (chan->type) {
case IIO_PROXIMITY:
*reg = APDS9960_REG_PILT;
break;
case IIO_INTENSITY:
*reg = APDS9960_REG_AILTL;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int apds9960_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
u8 reg;
__le16 buf;
int ret = 0;
struct apds9960_data *data = iio_priv(indio_dev);
if (info != IIO_EV_INFO_VALUE)
return -EINVAL;
ret = apds9960_get_thres_reg(chan, dir, &reg);
if (ret < 0)
return ret;
if (chan->type == IIO_PROXIMITY) {
ret = regmap_read(data->regmap, reg, val);
if (ret < 0)
return ret;
} else if (chan->type == IIO_INTENSITY) {
ret = regmap_bulk_read(data->regmap, reg, &buf, 2);
if (ret < 0)
return ret;
*val = le16_to_cpu(buf);
} else
return -EINVAL;
*val2 = 0;
return IIO_VAL_INT;
}
static int apds9960_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
u8 reg;
__le16 buf;
int ret = 0;
struct apds9960_data *data = iio_priv(indio_dev);
if (info != IIO_EV_INFO_VALUE)
return -EINVAL;
ret = apds9960_get_thres_reg(chan, dir, &reg);
if (ret < 0)
return ret;
if (chan->type == IIO_PROXIMITY) {
if (val < 0 || val > APDS9960_MAX_PXS_THRES_VAL)
return -EINVAL;
ret = regmap_write(data->regmap, reg, val);
if (ret < 0)
return ret;
} else if (chan->type == IIO_INTENSITY) {
if (val < 0 || val > APDS9960_MAX_ALS_THRES_VAL)
return -EINVAL;
buf = cpu_to_le16(val);
ret = regmap_bulk_write(data->regmap, reg, &buf, 2);
if (ret < 0)
return ret;
} else
return -EINVAL;
return 0;
}
static int apds9960_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct apds9960_data *data = iio_priv(indio_dev);
switch (chan->type) {
case IIO_PROXIMITY:
return data->pxs_int;
case IIO_INTENSITY:
return data->als_int;
default:
return -EINVAL;
}
return 0;
}
static int apds9960_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct apds9960_data *data = iio_priv(indio_dev);
int ret;
state = !!state;
switch (chan->type) {
case IIO_PROXIMITY:
if (data->pxs_int == state)
return -EINVAL;
ret = regmap_field_write(data->reg_int_pxs, state);
if (ret)
return ret;
data->pxs_int = state;
apds9960_set_power_state(data, state);
break;
case IIO_INTENSITY:
if (data->als_int == state)
return -EINVAL;
ret = regmap_field_write(data->reg_int_als, state);
if (ret)
return ret;
data->als_int = state;
apds9960_set_power_state(data, state);
break;
default:
return -EINVAL;
}
return 0;
}
static inline int apds9660_fifo_is_empty(struct apds9960_data *data)
{
int cnt;
int ret;
ret = regmap_read(data->regmap, APDS9960_REG_GFLVL, &cnt);
if (ret)
return ret;
return cnt;
}
static void apds9960_read_gesture_fifo(struct apds9960_data *data)
{
int ret, cnt = 0;
mutex_lock(&data->lock);
data->gesture_mode_running = 1;
while (cnt-- || (cnt = apds9660_fifo_is_empty(data) > 0)) {
ret = regmap_bulk_read(data->regmap, APDS9960_REG_GFIFO_BASE,
&data->buffer, 4);
if (ret)
goto err_read;
iio_push_to_buffers(data->indio_dev, data->buffer);
}
err_read:
data->gesture_mode_running = 0;
mutex_unlock(&data->lock);
}
static irqreturn_t apds9960_interrupt_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct apds9960_data *data = iio_priv(indio_dev);
int ret, status;
ret = regmap_read(data->regmap, APDS9960_REG_STATUS, &status);
if (ret < 0) {
dev_err(&data->client->dev, "irq status reg read failed\n");
return IRQ_HANDLED;
}
if ((status & APDS9960_REG_STATUS_ALS_INT) && data->als_int) {
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_INTENSITY, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns());
regmap_write(data->regmap, APDS9960_REG_CICLEAR, 1);
}
if ((status & APDS9960_REG_STATUS_PS_INT) && data->pxs_int) {
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns());
regmap_write(data->regmap, APDS9960_REG_PICLEAR, 1);
}
if (status & APDS9960_REG_STATUS_GINT)
apds9960_read_gesture_fifo(data);
return IRQ_HANDLED;
}
static int apds9960_set_powermode(struct apds9960_data *data, bool state)
{
return regmap_update_bits(data->regmap, APDS9960_REG_ENABLE, 1, state);
}
static int apds9960_buffer_postenable(struct iio_dev *indio_dev)
{
struct apds9960_data *data = iio_priv(indio_dev);
int ret;
ret = regmap_field_write(data->reg_int_ges, 1);
if (ret)
return ret;
ret = regmap_field_write(data->reg_enable_ges, 1);
if (ret)
return ret;
pm_runtime_get_sync(&data->client->dev);
return 0;
}
static int apds9960_buffer_predisable(struct iio_dev *indio_dev)
{
struct apds9960_data *data = iio_priv(indio_dev);
int ret;
ret = regmap_field_write(data->reg_enable_ges, 0);
if (ret)
return ret;
ret = regmap_field_write(data->reg_int_ges, 0);
if (ret)
return ret;
pm_runtime_put_autosuspend(&data->client->dev);
return 0;
}
static int apds9960_regfield_init(struct apds9960_data *data)
{
struct device *dev = &data->client->dev;
struct regmap *regmap = data->regmap;
data->reg_int_als = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_int_als);
if (IS_ERR(data->reg_int_als)) {
dev_err(dev, "INT ALS reg field init failed\n");
return PTR_ERR(data->reg_int_als);
}
data->reg_int_ges = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_int_ges);
if (IS_ERR(data->reg_int_ges)) {
dev_err(dev, "INT gesture reg field init failed\n");
return PTR_ERR(data->reg_int_ges);
}
data->reg_int_pxs = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_int_pxs);
if (IS_ERR(data->reg_int_pxs)) {
dev_err(dev, "INT pxs reg field init failed\n");
return PTR_ERR(data->reg_int_pxs);
}
data->reg_enable_als = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_enable_als);
if (IS_ERR(data->reg_enable_als)) {
dev_err(dev, "Enable ALS reg field init failed\n");
return PTR_ERR(data->reg_enable_als);
}
data->reg_enable_ges = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_enable_ges);
if (IS_ERR(data->reg_enable_ges)) {
dev_err(dev, "Enable gesture reg field init failed\n");
return PTR_ERR(data->reg_enable_ges);
}
data->reg_enable_pxs = devm_regmap_field_alloc(dev, regmap,
apds9960_reg_field_enable_pxs);
if (IS_ERR(data->reg_enable_pxs)) {
dev_err(dev, "Enable PXS reg field init failed\n");
return PTR_ERR(data->reg_enable_pxs);
}
return 0;
}
static int apds9960_chip_init(struct apds9960_data *data)
{
int ret;
ret = apds9960_set_it_time(data, 28000);
if (ret)
return ret;
ret = regmap_field_write(data->reg_int_ges, 0);
if (ret)
return ret;
ret = regmap_field_write(data->reg_enable_ges, 0);
if (ret)
return ret;
ret = regmap_field_write(data->reg_int_pxs, 0);
if (ret)
return ret;
ret = regmap_field_write(data->reg_enable_pxs, 1);
if (ret)
return ret;
ret = regmap_field_write(data->reg_int_als, 0);
if (ret)
return ret;
ret = regmap_field_write(data->reg_enable_als, 1);
if (ret)
return ret;
ret = regmap_write(data->regmap, APDS9960_REG_PERS,
APDS9960_DEFAULT_PERS);
if (ret)
return ret;
ret = regmap_update_bits(data->regmap, APDS9960_REG_GCONF_1,
APDS9960_REG_GCONF_1_GFIFO_THRES_MASK,
BIT(0) << APDS9960_REG_GCONF_1_GFIFO_THRES_MASK_SHIFT);
if (ret)
return ret;
ret = regmap_write(data->regmap, APDS9960_REG_GPENTH,
APDS9960_DEFAULT_GPENTH);
if (ret)
return ret;
ret = regmap_write(data->regmap, APDS9960_REG_GEXTH,
APDS9960_DEFAULT_GEXTH);
if (ret)
return ret;
return apds9960_set_powermode(data, 1);
}
static int apds9960_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct apds9960_data *data;
struct iio_buffer *buffer;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
buffer = devm_iio_kfifo_allocate(&client->dev);
if (!buffer)
return -ENOMEM;
iio_device_attach_buffer(indio_dev, buffer);
indio_dev->info = &apds9960_info;
indio_dev->name = APDS9960_DRV_NAME;
indio_dev->channels = apds9960_channels;
indio_dev->num_channels = ARRAY_SIZE(apds9960_channels);
indio_dev->available_scan_masks = apds9960_scan_masks;
indio_dev->modes = (INDIO_BUFFER_SOFTWARE | INDIO_DIRECT_MODE);
indio_dev->setup_ops = &apds9960_buffer_setup_ops;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->regmap = devm_regmap_init_i2c(client, &apds9960_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "regmap initialization failed.\n");
return PTR_ERR(data->regmap);
}
data->client = client;
data->indio_dev = indio_dev;
mutex_init(&data->lock);
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto error_power_down;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev, 5000);
pm_runtime_use_autosuspend(&client->dev);
apds9960_set_power_state(data, true);
ret = apds9960_regfield_init(data);
if (ret)
goto error_power_down;
ret = apds9960_chip_init(data);
if (ret)
goto error_power_down;
if (client->irq <= 0) {
dev_err(&client->dev, "no valid irq defined\n");
ret = -EINVAL;
goto error_power_down;
}
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, apds9960_interrupt_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"apds9960_event",
indio_dev);
if (ret) {
dev_err(&client->dev, "request irq (%d) failed\n", client->irq);
goto error_power_down;
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_power_down;
apds9960_set_power_state(data, false);
return 0;
error_power_down:
apds9960_set_power_state(data, false);
return ret;
}
static int apds9960_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct apds9960_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
apds9960_set_powermode(data, 0);
return 0;
}
static int apds9960_runtime_suspend(struct device *dev)
{
struct apds9960_data *data =
iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return apds9960_set_powermode(data, 0);
}
static int apds9960_runtime_resume(struct device *dev)
{
struct apds9960_data *data =
iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return apds9960_set_powermode(data, 1);
}
