static int stk3310_get_index(const int table[][2], int table_size,
int val, int val2)
{
int i;
for (i = 0; i < table_size; i++) {
if (val == table[i][0] && val2 == table[i][1])
return i;
}
return -EINVAL;
}
static int stk3310_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
u8 reg;
__be16 buf;
int ret;
struct stk3310_data *data = iio_priv(indio_dev);
if (info != IIO_EV_INFO_VALUE)
return -EINVAL;
if (dir == IIO_EV_DIR_RISING)
reg = STK3310_REG_THDH_PS;
else if (dir == IIO_EV_DIR_FALLING)
reg = STK3310_REG_THDL_PS;
else
return -EINVAL;
mutex_lock(&data->lock);
ret = regmap_bulk_read(data->regmap, reg, &buf, 2);
mutex_unlock(&data->lock);
if (ret < 0) {
dev_err(&data->client->dev, "register read failed\n");
return ret;
}
*val = be16_to_cpu(buf);
return IIO_VAL_INT;
}
static int stk3310_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
u8 reg;
__be16 buf;
int ret;
unsigned int index;
struct stk3310_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
regmap_field_read(data->reg_ps_gain, &index);
if (val > stk3310_ps_max[index])
return -EINVAL;
if (dir == IIO_EV_DIR_RISING)
reg = STK3310_REG_THDH_PS;
else if (dir == IIO_EV_DIR_FALLING)
reg = STK3310_REG_THDL_PS;
else
return -EINVAL;
buf = cpu_to_be16(val);
ret = regmap_bulk_write(data->regmap, reg, &buf, 2);
if (ret < 0)
dev_err(&client->dev, "failed to set PS threshold!\n");
return ret;
}
static int stk3310_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
unsigned int event_val;
struct stk3310_data *data = iio_priv(indio_dev);
regmap_field_read(data->reg_int_ps, &event_val);
return event_val;
}
static int stk3310_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
int ret;
struct stk3310_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
if (state < 0 || state > 7)
return -EINVAL;
mutex_lock(&data->lock);
ret = regmap_field_write(data->reg_int_ps, state);
if (ret < 0)
dev_err(&client->dev, "failed to set interrupt mode\n");
mutex_unlock(&data->lock);
return ret;
}
static int stk3310_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
u8 reg;
__be16 buf;
int ret;
unsigned int index;
struct stk3310_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_LIGHT)
reg = STK3310_REG_ALS_DATA_MSB;
else if (chan->type == IIO_PROXIMITY)
reg = STK3310_REG_PS_DATA_MSB;
else
return -EINVAL;
mutex_lock(&data->lock);
ret = regmap_bulk_read(data->regmap, reg, &buf, 2);
if (ret < 0) {
dev_err(&client->dev, "register read failed\n");
mutex_unlock(&data->lock);
return ret;
}
*val = be16_to_cpu(buf);
mutex_unlock(&data->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
if (chan->type == IIO_LIGHT)
regmap_field_read(data->reg_als_it, &index);
else
regmap_field_read(data->reg_ps_it, &index);
*val = stk3310_it_table[index][0];
*val2 = stk3310_it_table[index][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_LIGHT)
regmap_field_read(data->reg_als_gain, &index);
else
regmap_field_read(data->reg_ps_gain, &index);
*val = stk3310_scale_table[index][0];
*val2 = stk3310_scale_table[index][1];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int stk3310_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret;
int index;
struct stk3310_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
index = stk3310_get_index(stk3310_it_table,
ARRAY_SIZE(stk3310_it_table),
val, val2);
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
if (chan->type == IIO_LIGHT)
ret = regmap_field_write(data->reg_als_it, index);
else
ret = regmap_field_write(data->reg_ps_it, index);
if (ret < 0)
dev_err(&data->client->dev,
"sensor configuration failed\n");
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_SCALE:
index = stk3310_get_index(stk3310_scale_table,
ARRAY_SIZE(stk3310_scale_table),
val, val2);
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
if (chan->type == IIO_LIGHT)
ret = regmap_field_write(data->reg_als_gain, index);
else
ret = regmap_field_write(data->reg_ps_gain, index);
if (ret < 0)
dev_err(&data->client->dev,
"sensor configuration failed\n");
mutex_unlock(&data->lock);
return ret;
}
return -EINVAL;
}
static int stk3310_set_state(struct stk3310_data *data, u8 state)
{
int ret;
struct i2c_client *client = data->client;
if (state > 7 || state == 4)
return -EINVAL;
mutex_lock(&data->lock);
ret = regmap_field_write(data->reg_state, state);
if (ret < 0) {
dev_err(&client->dev, "failed to change sensor state\n");
} else if (state != STK3310_STATE_STANDBY) {
data->ps_enabled = !!(state & 0x01);
data->als_enabled = !!(state & 0x02);
}
mutex_unlock(&data->lock);
return ret;
}
static int stk3310_init(struct iio_dev *indio_dev)
{
int ret;
int chipid;
u8 state;
struct stk3310_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
regmap_read(data->regmap, STK3310_REG_ID, &chipid);
if (chipid != STK3310_CHIP_ID_VAL &&
chipid != STK3311_CHIP_ID_VAL) {
dev_err(&client->dev, "invalid chip id: 0x%x\n", chipid);
return -ENODEV;
}
state = STK3310_STATE_EN_ALS | STK3310_STATE_EN_PS;
ret = stk3310_set_state(data, state);
if (ret < 0) {
dev_err(&client->dev, "failed to enable sensor");
return ret;
}
ret = regmap_field_write(data->reg_int_ps, STK3310_PSINT_EN);
if (ret < 0)
dev_err(&client->dev, "failed to enable interrupts!\n");
return ret;
}
static int stk3310_gpio_probe(struct i2c_client *client)
{
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
gpio = devm_gpiod_get_index(dev, STK3310_GPIO, 0);
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
static bool stk3310_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STK3310_REG_ALS_DATA_MSB:
case STK3310_REG_ALS_DATA_LSB:
case STK3310_REG_PS_DATA_LSB:
case STK3310_REG_PS_DATA_MSB:
case STK3310_REG_FLAG:
return true;
default:
return false;
}
}
static int stk3310_regmap_init(struct stk3310_data *data)
{
struct regmap *regmap;
struct i2c_client *client;
client = data->client;
regmap = devm_regmap_init_i2c(client, &stk3310_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "regmap initialization failed.\n");
return PTR_ERR(regmap);
}
data->regmap = regmap;
STK3310_REGFIELD(state);
STK3310_REGFIELD(als_gain);
STK3310_REGFIELD(ps_gain);
STK3310_REGFIELD(als_it);
STK3310_REGFIELD(ps_it);
STK3310_REGFIELD(int_ps);
STK3310_REGFIELD(flag_psint);
STK3310_REGFIELD(flag_nf);
return 0;
}
static irqreturn_t stk3310_irq_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct stk3310_data *data = iio_priv(indio_dev);
data->timestamp = iio_get_time_ns();
return IRQ_WAKE_THREAD;
}
static irqreturn_t stk3310_irq_event_handler(int irq, void *private)
{
int ret;
unsigned int dir;
u64 event;
struct iio_dev *indio_dev = private;
struct stk3310_data *data = iio_priv(indio_dev);
mutex_lock(&data->lock);
ret = regmap_field_read(data->reg_flag_nf, &dir);
if (ret < 0) {
dev_err(&data->client->dev, "register read failed\n");
mutex_unlock(&data->lock);
return ret;
}
event = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, 1,
IIO_EV_TYPE_THRESH,
(dir ? IIO_EV_DIR_FALLING :
IIO_EV_DIR_RISING));
iio_push_event(indio_dev, event, data->timestamp);
ret = regmap_field_write(data->reg_flag_psint, 0);
if (ret < 0)
dev_err(&data->client->dev, "failed to reset interrupts\n");
mutex_unlock(&data->lock);
return IRQ_HANDLED;
}
static int stk3310_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct stk3310_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation failed!\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
mutex_init(&data->lock);
ret = stk3310_regmap_init(data);
if (ret < 0)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &stk3310_info;
indio_dev->name = STK3310_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stk3310_channels;
indio_dev->num_channels = ARRAY_SIZE(stk3310_channels);
ret = stk3310_init(indio_dev);
if (ret < 0)
return ret;
if (client->irq < 0)
client->irq = stk3310_gpio_probe(client);
if (client->irq >= 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
stk3310_irq_handler,
stk3310_irq_event_handler,
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
STK3310_EVENT, indio_dev);
if (ret < 0)
dev_err(&client->dev, "request irq %d failed\n",
client->irq);
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
stk3310_set_state(data, STK3310_STATE_STANDBY);
}
return ret;
}
static int stk3310_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return stk3310_set_state(iio_priv(indio_dev), STK3310_STATE_STANDBY);
}
static int stk3310_suspend(struct device *dev)
{
struct stk3310_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk3310_set_state(data, STK3310_STATE_STANDBY);
}
static int stk3310_resume(struct device *dev)
{
int state = 0;
struct stk3310_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
if (data->ps_enabled)
state |= STK3310_STATE_EN_PS;
if (data->als_enabled)
state |= STK3310_STATE_EN_ALS;
return stk3310_set_state(data, state);
}
