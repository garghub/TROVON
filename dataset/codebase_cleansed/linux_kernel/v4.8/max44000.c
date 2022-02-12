static int max44000_read_alstim(struct max44000_data *data)
{
unsigned int val;
int ret;
ret = regmap_read(data->regmap, MAX44000_REG_CFG_RX, &val);
if (ret < 0)
return ret;
return (val & MAX44000_CFG_RX_ALSTIM_MASK) >> MAX44000_CFG_RX_ALSTIM_SHIFT;
}
static int max44000_write_alstim(struct max44000_data *data, int val)
{
return regmap_write_bits(data->regmap, MAX44000_REG_CFG_RX,
MAX44000_CFG_RX_ALSTIM_MASK,
val << MAX44000_CFG_RX_ALSTIM_SHIFT);
}
static int max44000_read_alspga(struct max44000_data *data)
{
unsigned int val;
int ret;
ret = regmap_read(data->regmap, MAX44000_REG_CFG_RX, &val);
if (ret < 0)
return ret;
return (val & MAX44000_CFG_RX_ALSPGA_MASK) >> MAX44000_CFG_RX_ALSPGA_SHIFT;
}
static int max44000_write_alspga(struct max44000_data *data, int val)
{
return regmap_write_bits(data->regmap, MAX44000_REG_CFG_RX,
MAX44000_CFG_RX_ALSPGA_MASK,
val << MAX44000_CFG_RX_ALSPGA_SHIFT);
}
static int max44000_read_alsval(struct max44000_data *data)
{
u16 regval;
int alstim, ret;
ret = regmap_bulk_read(data->regmap, MAX44000_REG_ALS_DATA_HI,
&regval, sizeof(regval));
if (ret < 0)
return ret;
alstim = ret = max44000_read_alstim(data);
if (ret < 0)
return ret;
regval = be16_to_cpu(regval);
if (regval & MAX44000_ALSDATA_OVERFLOW)
return 0x3FFF;
return regval << MAX44000_ALSTIM_SHIFT(alstim);
}
static int max44000_write_led_current_raw(struct max44000_data *data, int val)
{
if (val < 0 || val > MAX44000_LED_CURRENT_MAX)
return -ERANGE;
if (val >= 8)
val += 4;
return regmap_write_bits(data->regmap, MAX44000_REG_CFG_TX,
MAX44000_LED_CURRENT_MASK, val);
}
static int max44000_read_led_current_raw(struct max44000_data *data)
{
unsigned int regval;
int ret;
ret = regmap_read(data->regmap, MAX44000_REG_CFG_TX, &regval);
if (ret < 0)
return ret;
regval &= MAX44000_LED_CURRENT_MASK;
if (regval >= 8)
regval -= 4;
return regval;
}
static int max44000_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max44000_data *data = iio_priv(indio_dev);
int alstim, alspga;
unsigned int regval;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
mutex_lock(&data->lock);
ret = max44000_read_alsval(data);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_PROXIMITY:
mutex_lock(&data->lock);
ret = regmap_read(data->regmap, MAX44000_REG_PRX_DATA, &regval);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = regval;
return IIO_VAL_INT;
case IIO_CURRENT:
mutex_lock(&data->lock);
ret = max44000_read_led_current_raw(data);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_CURRENT:
*val = 10;
return IIO_VAL_INT;
case IIO_LIGHT:
mutex_lock(&data->lock);
alspga = ret = max44000_read_alspga(data);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = (1 << MAX44000_ALSPGA_MAX_SHIFT);
*val2 = MAX44000_ALS_TO_LUX_DEFAULT_FRACTION_LOG2
+ MAX44000_ALSPGA_MAX_SHIFT
- max44000_alspga_shift[alspga];
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_INT_TIME:
mutex_lock(&data->lock);
alstim = ret = max44000_read_alstim(data);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = 0;
*val2 = max44000_int_time_avail_ns_array[alstim];
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static int max44000_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct max44000_data *data = iio_priv(indio_dev);
int ret;
if (mask == IIO_CHAN_INFO_RAW && chan->type == IIO_CURRENT) {
mutex_lock(&data->lock);
ret = max44000_write_led_current_raw(data, val);
mutex_unlock(&data->lock);
return ret;
} else if (mask == IIO_CHAN_INFO_INT_TIME && chan->type == IIO_LIGHT) {
s64 valns = val * NSEC_PER_SEC + val2;
int alstim = find_closest_descending(valns,
max44000_int_time_avail_ns_array,
ARRAY_SIZE(max44000_int_time_avail_ns_array));
mutex_lock(&data->lock);
ret = max44000_write_alstim(data, alstim);
mutex_unlock(&data->lock);
return ret;
} else if (mask == IIO_CHAN_INFO_SCALE && chan->type == IIO_LIGHT) {
s64 valus = val * USEC_PER_SEC + val2;
int alspga = find_closest(valus,
max44000_scale_avail_ulux_array,
ARRAY_SIZE(max44000_scale_avail_ulux_array));
mutex_lock(&data->lock);
ret = max44000_write_alspga(data, alspga);
mutex_unlock(&data->lock);
return ret;
}
return -EINVAL;
}
static int max44000_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
if (mask == IIO_CHAN_INFO_INT_TIME && chan->type == IIO_LIGHT)
return IIO_VAL_INT_PLUS_NANO;
else if (mask == IIO_CHAN_INFO_SCALE && chan->type == IIO_LIGHT)
return IIO_VAL_INT_PLUS_MICRO;
else
return IIO_VAL_INT;
}
static bool max44000_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX44000_REG_STATUS:
case MAX44000_REG_CFG_MAIN:
case MAX44000_REG_CFG_RX:
case MAX44000_REG_CFG_TX:
case MAX44000_REG_ALS_DATA_HI:
case MAX44000_REG_ALS_DATA_LO:
case MAX44000_REG_PRX_DATA:
case MAX44000_REG_ALS_UPTHR_HI:
case MAX44000_REG_ALS_UPTHR_LO:
case MAX44000_REG_ALS_LOTHR_HI:
case MAX44000_REG_ALS_LOTHR_LO:
case MAX44000_REG_PST:
case MAX44000_REG_PRX_IND:
case MAX44000_REG_PRX_THR:
case MAX44000_REG_TRIM_GAIN_GREEN:
case MAX44000_REG_TRIM_GAIN_IR:
return true;
default:
return false;
}
}
static bool max44000_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX44000_REG_CFG_MAIN:
case MAX44000_REG_CFG_RX:
case MAX44000_REG_CFG_TX:
case MAX44000_REG_ALS_UPTHR_HI:
case MAX44000_REG_ALS_UPTHR_LO:
case MAX44000_REG_ALS_LOTHR_HI:
case MAX44000_REG_ALS_LOTHR_LO:
case MAX44000_REG_PST:
case MAX44000_REG_PRX_IND:
case MAX44000_REG_PRX_THR:
case MAX44000_REG_TRIM_GAIN_GREEN:
case MAX44000_REG_TRIM_GAIN_IR:
return true;
default:
return false;
}
}
static bool max44000_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX44000_REG_STATUS:
case MAX44000_REG_ALS_DATA_HI:
case MAX44000_REG_ALS_DATA_LO:
case MAX44000_REG_PRX_DATA:
return true;
default:
return false;
}
}
static bool max44000_precious_reg(struct device *dev, unsigned int reg)
{
return reg == MAX44000_REG_STATUS;
}
static irqreturn_t max44000_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct max44000_data *data = iio_priv(indio_dev);
u16 buf[8];
int index = 0;
unsigned int regval;
int ret;
mutex_lock(&data->lock);
if (test_bit(MAX44000_SCAN_INDEX_ALS, indio_dev->active_scan_mask)) {
ret = max44000_read_alsval(data);
if (ret < 0)
goto out_unlock;
buf[index++] = ret;
}
if (test_bit(MAX44000_SCAN_INDEX_PRX, indio_dev->active_scan_mask)) {
ret = regmap_read(data->regmap, MAX44000_REG_PRX_DATA, &regval);
if (ret < 0)
goto out_unlock;
buf[index] = regval;
}
mutex_unlock(&data->lock);
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
out_unlock:
mutex_unlock(&data->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int max44000_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max44000_data *data;
struct iio_dev *indio_dev;
int ret, reg;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->regmap = devm_regmap_init_i2c(client, &max44000_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "regmap_init failed!\n");
return PTR_ERR(data->regmap);
}
i2c_set_clientdata(client, indio_dev);
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &max44000_info;
indio_dev->name = MAX44000_DRV_NAME;
indio_dev->channels = max44000_channels;
indio_dev->num_channels = ARRAY_SIZE(max44000_channels);
ret = regmap_write(data->regmap, MAX44000_REG_CFG_RX,
MAX44000_REG_CFG_RX_DEFAULT);
if (ret < 0) {
dev_err(&client->dev, "failed to write default CFG_RX: %d\n",
ret);
return ret;
}
ret = max44000_write_led_current_raw(data, MAX44000_LED_CURRENT_DEFAULT);
if (ret < 0) {
dev_err(&client->dev, "failed to write init config: %d\n", ret);
return ret;
}
reg = MAX44000_CFG_TRIM | MAX44000_CFG_MODE_ALS_PRX;
ret = regmap_write(data->regmap, MAX44000_REG_CFG_MAIN, reg);
if (ret < 0) {
dev_err(&client->dev, "failed to write init config: %d\n", ret);
return ret;
}
ret = regmap_read(data->regmap, MAX44000_REG_STATUS, &reg);
if (ret < 0) {
dev_err(&client->dev, "failed to read init status: %d\n", ret);
return ret;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL, max44000_trigger_handler, NULL);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
return ret;
}
return iio_device_register(indio_dev);
}
static int max44000_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
