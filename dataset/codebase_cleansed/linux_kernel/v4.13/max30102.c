static int max30102_set_powermode(struct max30102_data *data, bool state)
{
return regmap_update_bits(data->regmap, MAX30102_REG_MODE_CONFIG,
MAX30102_REG_MODE_CONFIG_PWR,
state ? 0 : MAX30102_REG_MODE_CONFIG_PWR);
}
static int max30102_buffer_postenable(struct iio_dev *indio_dev)
{
struct max30102_data *data = iio_priv(indio_dev);
return max30102_set_powermode(data, true);
}
static int max30102_buffer_predisable(struct iio_dev *indio_dev)
{
struct max30102_data *data = iio_priv(indio_dev);
return max30102_set_powermode(data, false);
}
static inline int max30102_fifo_count(struct max30102_data *data)
{
unsigned int val;
int ret;
ret = regmap_read(data->regmap, MAX30102_REG_INT_STATUS, &val);
if (ret)
return ret;
if (val & MAX30102_REG_INT_STATUS_FIFO_RDY)
return 1;
return 0;
}
static int max30102_read_measurement(struct max30102_data *data)
{
int ret;
u8 *buffer = (u8 *) &data->buffer;
ret = i2c_smbus_read_i2c_block_data(data->client,
MAX30102_REG_FIFO_DATA,
MAX30102_REG_FIFO_DATA_ENTRY_LEN,
buffer);
memcpy(&data->processed_buffer[0], &buffer[0], 3);
memcpy(&data->processed_buffer[1], &buffer[3], 3);
return (ret == MAX30102_REG_FIFO_DATA_ENTRY_LEN) ? 0 : -EINVAL;
}
static irqreturn_t max30102_interrupt_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct max30102_data *data = iio_priv(indio_dev);
int ret, cnt = 0;
mutex_lock(&data->lock);
while (cnt || (cnt = max30102_fifo_count(data)) > 0) {
ret = max30102_read_measurement(data);
if (ret)
break;
iio_push_to_buffers(data->indio_dev, data->processed_buffer);
cnt--;
}
mutex_unlock(&data->lock);
return IRQ_HANDLED;
}
static int max30102_get_current_idx(unsigned int val, int *reg)
{
*reg = val / 200;
return *reg > 0xff ? -EINVAL : 0;
}
static int max30102_led_init(struct max30102_data *data)
{
struct device *dev = &data->client->dev;
struct device_node *np = dev->of_node;
unsigned int val;
int reg, ret;
ret = of_property_read_u32(np, "maxim,red-led-current-microamp", &val);
if (ret) {
dev_info(dev, "no red-led-current-microamp set\n");
val = 7000;
}
ret = max30102_get_current_idx(val, &reg);
if (ret) {
dev_err(dev, "invalid RED LED current setting %d\n", val);
return ret;
}
ret = regmap_write(data->regmap, MAX30102_REG_RED_LED_CONFIG, reg);
if (ret)
return ret;
ret = of_property_read_u32(np, "maxim,ir-led-current-microamp", &val);
if (ret) {
dev_info(dev, "no ir-led-current-microamp set\n");
val = 7000;
}
ret = max30102_get_current_idx(val, &reg);
if (ret) {
dev_err(dev, "invalid IR LED current setting %d", val);
return ret;
}
return regmap_write(data->regmap, MAX30102_REG_IR_LED_CONFIG, reg);
}
static int max30102_chip_init(struct max30102_data *data)
{
int ret;
ret = max30102_led_init(data);
if (ret)
return ret;
ret = regmap_write(data->regmap, MAX30102_REG_SPO2_CONFIG,
(MAX30102_REG_SPO2_CONFIG_ADC_4096_STEPS
<< MAX30102_REG_SPO2_CONFIG_ADC_MASK_SHIFT) |
(MAX30102_REG_SPO2_CONFIG_SR_400HZ
<< MAX30102_REG_SPO2_CONFIG_SR_MASK_SHIFT) |
MAX30102_REG_SPO2_CONFIG_PULSE_411_US);
if (ret)
return ret;
ret = regmap_update_bits(data->regmap, MAX30102_REG_MODE_CONFIG,
MAX30102_REG_MODE_CONFIG_MODE_MASK,
MAX30102_REG_MODE_CONFIG_MODE_HR_EN |
MAX30102_REG_MODE_CONFIG_MODE_SPO2_EN);
if (ret)
return ret;
ret = regmap_write(data->regmap, MAX30102_REG_FIFO_CONFIG,
(MAX30102_REG_FIFO_CONFIG_AVG_4SAMPLES
<< MAX30102_REG_FIFO_CONFIG_AVG_SHIFT) |
MAX30102_REG_FIFO_CONFIG_AFULL);
if (ret)
return ret;
return regmap_update_bits(data->regmap, MAX30102_REG_INT_ENABLE,
MAX30102_REG_INT_ENABLE_MASK,
MAX30102_REG_INT_ENABLE_FIFO_EN);
}
static int max30102_read_temp(struct max30102_data *data, int *val)
{
int ret;
unsigned int reg;
ret = regmap_read(data->regmap, MAX30102_REG_TEMP_INTEGER, &reg);
if (ret < 0)
return ret;
*val = reg << 4;
ret = regmap_read(data->regmap, MAX30102_REG_TEMP_FRACTION, &reg);
if (ret < 0)
return ret;
*val |= reg & 0xf;
*val = sign_extend32(*val, 11);
return 0;
}
static int max30102_get_temp(struct max30102_data *data, int *val)
{
int ret;
ret = regmap_update_bits(data->regmap, MAX30102_REG_TEMP_CONFIG,
MAX30102_REG_TEMP_CONFIG_TEMP_EN,
MAX30102_REG_TEMP_CONFIG_TEMP_EN);
if (ret)
return ret;
msleep(35);
return max30102_read_temp(data, val);
}
static int max30102_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max30102_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (!iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else {
ret = max30102_get_temp(data, val);
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
static int max30102_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max30102_data *data;
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
indio_dev->name = MAX30102_DRV_NAME;
indio_dev->channels = max30102_channels;
indio_dev->info = &max30102_info;
indio_dev->num_channels = ARRAY_SIZE(max30102_channels);
indio_dev->available_scan_masks = max30102_scan_masks;
indio_dev->modes = (INDIO_BUFFER_SOFTWARE | INDIO_DIRECT_MODE);
indio_dev->setup_ops = &max30102_buffer_setup_ops;
indio_dev->dev.parent = &client->dev;
data = iio_priv(indio_dev);
data->indio_dev = indio_dev;
data->client = client;
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
data->regmap = devm_regmap_init_i2c(client, &max30102_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "regmap initialization failed.\n");
return PTR_ERR(data->regmap);
}
max30102_set_powermode(data, false);
ret = max30102_chip_init(data);
if (ret)
return ret;
if (client->irq <= 0) {
dev_err(&client->dev, "no valid irq defined\n");
return -EINVAL;
}
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, max30102_interrupt_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max30102_irq", indio_dev);
if (ret) {
dev_err(&client->dev, "request irq (%d) failed\n", client->irq);
return ret;
}
return iio_device_register(indio_dev);
}
static int max30102_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct max30102_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
max30102_set_powermode(data, false);
return 0;
}
