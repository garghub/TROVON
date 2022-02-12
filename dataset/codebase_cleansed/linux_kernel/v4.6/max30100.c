static bool max30100_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX30100_REG_INT_STATUS:
case MAX30100_REG_MODE_CONFIG:
case MAX30100_REG_FIFO_WR_PTR:
case MAX30100_REG_FIFO_OVR_CTR:
case MAX30100_REG_FIFO_RD_PTR:
case MAX30100_REG_FIFO_DATA:
case MAX30100_REG_TEMP_INTEGER:
case MAX30100_REG_TEMP_FRACTION:
return true;
default:
return false;
}
}
static int max30100_set_powermode(struct max30100_data *data, bool state)
{
return regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
MAX30100_REG_MODE_CONFIG_PWR,
state ? 0 : MAX30100_REG_MODE_CONFIG_PWR);
}
static int max30100_clear_fifo(struct max30100_data *data)
{
int ret;
ret = regmap_write(data->regmap, MAX30100_REG_FIFO_WR_PTR, 0);
if (ret)
return ret;
ret = regmap_write(data->regmap, MAX30100_REG_FIFO_OVR_CTR, 0);
if (ret)
return ret;
return regmap_write(data->regmap, MAX30100_REG_FIFO_RD_PTR, 0);
}
static int max30100_buffer_postenable(struct iio_dev *indio_dev)
{
struct max30100_data *data = iio_priv(indio_dev);
int ret;
ret = max30100_set_powermode(data, true);
if (ret)
return ret;
return max30100_clear_fifo(data);
}
static int max30100_buffer_predisable(struct iio_dev *indio_dev)
{
struct max30100_data *data = iio_priv(indio_dev);
return max30100_set_powermode(data, false);
}
static inline int max30100_fifo_count(struct max30100_data *data)
{
unsigned int val;
int ret;
ret = regmap_read(data->regmap, MAX30100_REG_INT_STATUS, &val);
if (ret)
return ret;
if (val & MAX30100_REG_INT_STATUS_FIFO_RDY)
return MAX30100_REG_FIFO_DATA_ENTRY_COUNT - 1;
return 0;
}
static int max30100_read_measurement(struct max30100_data *data)
{
int ret;
ret = i2c_smbus_read_i2c_block_data(data->client,
MAX30100_REG_FIFO_DATA,
MAX30100_REG_FIFO_DATA_ENTRY_LEN,
(u8 *) &data->buffer);
return (ret == MAX30100_REG_FIFO_DATA_ENTRY_LEN) ? 0 : ret;
}
static irqreturn_t max30100_interrupt_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct max30100_data *data = iio_priv(indio_dev);
int ret, cnt = 0;
mutex_lock(&data->lock);
while (cnt || (cnt = max30100_fifo_count(data) > 0)) {
ret = max30100_read_measurement(data);
if (ret)
break;
iio_push_to_buffers(data->indio_dev, data->buffer);
cnt--;
}
mutex_unlock(&data->lock);
return IRQ_HANDLED;
}
static int max30100_get_current_idx(unsigned int val, int *reg)
{
int idx;
if (val == 0) {
*reg = 0;
return 0;
}
for (idx = 0; idx < ARRAY_SIZE(max30100_led_current_mapping); idx++) {
if (max30100_led_current_mapping[idx] == val) {
*reg = idx + 1;
return 0;
}
}
return -EINVAL;
}
static int max30100_led_init(struct max30100_data *data)
{
struct device *dev = &data->client->dev;
struct device_node *np = dev->of_node;
unsigned int val[2];
int reg, ret;
ret = of_property_read_u32_array(np, "maxim,led-current-microamp",
(unsigned int *) &val, 2);
if (ret) {
reg = (MAX30100_REG_LED_CONFIG_24MA <<
MAX30100_REG_LED_CONFIG_RED_LED_SHIFT) |
MAX30100_REG_LED_CONFIG_50MA;
dev_warn(dev, "no led-current-microamp set");
return regmap_write(data->regmap, MAX30100_REG_LED_CONFIG, reg);
}
ret = max30100_get_current_idx(val[0], &reg);
if (ret) {
dev_err(dev, "invalid RED current setting %d", val[0]);
return ret;
}
ret = regmap_update_bits(data->regmap, MAX30100_REG_LED_CONFIG,
MAX30100_REG_LED_CONFIG_LED_MASK <<
MAX30100_REG_LED_CONFIG_RED_LED_SHIFT,
reg << MAX30100_REG_LED_CONFIG_RED_LED_SHIFT);
if (ret)
return ret;
ret = max30100_get_current_idx(val[1], &reg);
if (ret) {
dev_err(dev, "invalid IR current setting %d", val[1]);
return ret;
}
return regmap_update_bits(data->regmap, MAX30100_REG_LED_CONFIG,
MAX30100_REG_LED_CONFIG_LED_MASK, reg);
}
static int max30100_chip_init(struct max30100_data *data)
{
int ret;
ret = max30100_led_init(data);
if (ret)
return ret;
ret = regmap_write(data->regmap, MAX30100_REG_SPO2_CONFIG,
MAX30100_REG_SPO2_CONFIG_HI_RES_EN |
MAX30100_REG_SPO2_CONFIG_100HZ);
if (ret)
return ret;
ret = regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
MAX30100_REG_MODE_CONFIG_MODE_MASK,
MAX30100_REG_MODE_CONFIG_MODE_HR_EN |
MAX30100_REG_MODE_CONFIG_MODE_SPO2_EN);
if (ret)
return ret;
return regmap_update_bits(data->regmap, MAX30100_REG_INT_ENABLE,
MAX30100_REG_INT_ENABLE_MASK,
MAX30100_REG_INT_ENABLE_FIFO_EN
<< MAX30100_REG_INT_ENABLE_MASK_SHIFT);
}
static int max30100_read_temp(struct max30100_data *data, int *val)
{
int ret;
unsigned int reg;
ret = regmap_read(data->regmap, MAX30100_REG_TEMP_INTEGER, &reg);
if (ret < 0)
return ret;
*val = reg << 4;
ret = regmap_read(data->regmap, MAX30100_REG_TEMP_FRACTION, &reg);
if (ret < 0)
return ret;
*val |= reg & 0xf;
*val = sign_extend32(*val, 11);
return 0;
}
static int max30100_get_temp(struct max30100_data *data, int *val)
{
int ret;
ret = regmap_update_bits(data->regmap, MAX30100_REG_MODE_CONFIG,
MAX30100_REG_MODE_CONFIG_TEMP_EN,
MAX30100_REG_MODE_CONFIG_TEMP_EN);
if (ret)
return ret;
usleep_range(35000, 50000);
return max30100_read_temp(data, val);
}
static int max30100_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max30100_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (!iio_buffer_enabled(indio_dev))
ret = -EAGAIN;
else {
ret = max30100_get_temp(data, val);
if (!ret)
ret = IIO_VAL_INT;
}
mutex_unlock(&indio_dev->mlock);
break;
case IIO_CHAN_INFO_SCALE:
*val = 1;
*val2 = 16;
ret = IIO_VAL_FRACTIONAL;
break;
}
return ret;
}
static int max30100_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max30100_data *data;
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
indio_dev->name = MAX30100_DRV_NAME;
indio_dev->channels = max30100_channels;
indio_dev->info = &max30100_info;
indio_dev->num_channels = ARRAY_SIZE(max30100_channels);
indio_dev->available_scan_masks = max30100_scan_masks;
indio_dev->modes = (INDIO_BUFFER_SOFTWARE | INDIO_DIRECT_MODE);
indio_dev->setup_ops = &max30100_buffer_setup_ops;
data = iio_priv(indio_dev);
data->indio_dev = indio_dev;
data->client = client;
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
data->regmap = devm_regmap_init_i2c(client, &max30100_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "regmap initialization failed.\n");
return PTR_ERR(data->regmap);
}
max30100_set_powermode(data, false);
ret = max30100_chip_init(data);
if (ret)
return ret;
if (client->irq <= 0) {
dev_err(&client->dev, "no valid irq defined\n");
return -EINVAL;
}
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, max30100_interrupt_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max30100_irq", indio_dev);
if (ret) {
dev_err(&client->dev, "request irq (%d) failed\n", client->irq);
return ret;
}
return iio_device_register(indio_dev);
}
static int max30100_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct max30100_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
max30100_set_powermode(data, false);
return 0;
}
