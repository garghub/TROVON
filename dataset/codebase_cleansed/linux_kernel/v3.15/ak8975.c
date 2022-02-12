static int ak8975_write_data(struct i2c_client *client,
u8 reg, u8 val, u8 mask, u8 shift)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ak8975_data *data = iio_priv(indio_dev);
u8 regval;
int ret;
regval = (data->reg_cache[reg] & ~mask) | (val << shift);
ret = i2c_smbus_write_byte_data(client, reg, regval);
if (ret < 0) {
dev_err(&client->dev, "Write to device fails status %x\n", ret);
return ret;
}
data->reg_cache[reg] = regval;
return 0;
}
static irqreturn_t ak8975_irq_handler(int irq, void *data)
{
struct ak8975_data *ak8975 = data;
set_bit(0, &ak8975->flags);
wake_up(&ak8975->data_ready_queue);
return IRQ_HANDLED;
}
static int ak8975_setup_irq(struct ak8975_data *data)
{
struct i2c_client *client = data->client;
int rc;
int irq;
if (client->irq)
irq = client->irq;
else
irq = gpio_to_irq(data->eoc_gpio);
rc = request_irq(irq, ak8975_irq_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(&client->dev), data);
if (rc < 0) {
dev_err(&client->dev,
"irq %d request failed, (gpio %d): %d\n",
irq, data->eoc_gpio, rc);
return rc;
}
init_waitqueue_head(&data->data_ready_queue);
clear_bit(0, &data->flags);
data->eoc_irq = irq;
return rc;
}
static int ak8975_setup(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ak8975_data *data = iio_priv(indio_dev);
u8 device_id;
int ret;
ret = i2c_smbus_read_byte_data(client, AK8975_REG_WIA);
if (ret < 0) {
dev_err(&client->dev, "Error reading WIA\n");
return ret;
}
device_id = ret;
if (device_id != AK8975_DEVICE_ID) {
dev_err(&client->dev, "Device ak8975 not found\n");
return -ENODEV;
}
ret = ak8975_write_data(client,
AK8975_REG_CNTL,
AK8975_REG_CNTL_MODE_FUSE_ROM,
AK8975_REG_CNTL_MODE_MASK,
AK8975_REG_CNTL_MODE_SHIFT);
if (ret < 0) {
dev_err(&client->dev, "Error in setting fuse access mode\n");
return ret;
}
ret = i2c_smbus_read_i2c_block_data(client, AK8975_REG_ASAX,
3, data->asa);
if (ret < 0) {
dev_err(&client->dev, "Not able to read asa data\n");
return ret;
}
ret = ak8975_write_data(client,
AK8975_REG_CNTL,
AK8975_REG_CNTL_MODE_POWER_DOWN,
AK8975_REG_CNTL_MODE_MASK,
AK8975_REG_CNTL_MODE_SHIFT);
if (data->eoc_gpio > 0 || client->irq) {
ret = ak8975_setup_irq(data);
if (ret < 0) {
dev_err(&client->dev,
"Error setting data ready interrupt\n");
return ret;
}
}
if (ret < 0) {
dev_err(&client->dev, "Error in setting power-down mode\n");
return ret;
}
data->raw_to_gauss[0] = RAW_TO_GAUSS(data->asa[0]);
data->raw_to_gauss[1] = RAW_TO_GAUSS(data->asa[1]);
data->raw_to_gauss[2] = RAW_TO_GAUSS(data->asa[2]);
return 0;
}
static int wait_conversion_complete_gpio(struct ak8975_data *data)
{
struct i2c_client *client = data->client;
u32 timeout_ms = AK8975_MAX_CONVERSION_TIMEOUT;
int ret;
while (timeout_ms) {
msleep(AK8975_CONVERSION_DONE_POLL_TIME);
if (gpio_get_value(data->eoc_gpio))
break;
timeout_ms -= AK8975_CONVERSION_DONE_POLL_TIME;
}
if (!timeout_ms) {
dev_err(&client->dev, "Conversion timeout happened\n");
return -EINVAL;
}
ret = i2c_smbus_read_byte_data(client, AK8975_REG_ST1);
if (ret < 0)
dev_err(&client->dev, "Error in reading ST1\n");
return ret;
}
static int wait_conversion_complete_polled(struct ak8975_data *data)
{
struct i2c_client *client = data->client;
u8 read_status;
u32 timeout_ms = AK8975_MAX_CONVERSION_TIMEOUT;
int ret;
while (timeout_ms) {
msleep(AK8975_CONVERSION_DONE_POLL_TIME);
ret = i2c_smbus_read_byte_data(client, AK8975_REG_ST1);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST1\n");
return ret;
}
read_status = ret;
if (read_status)
break;
timeout_ms -= AK8975_CONVERSION_DONE_POLL_TIME;
}
if (!timeout_ms) {
dev_err(&client->dev, "Conversion timeout happened\n");
return -EINVAL;
}
return read_status;
}
static int wait_conversion_complete_interrupt(struct ak8975_data *data)
{
int ret;
ret = wait_event_timeout(data->data_ready_queue,
test_bit(0, &data->flags),
AK8975_DATA_READY_TIMEOUT);
clear_bit(0, &data->flags);
return ret > 0 ? 0 : -ETIME;
}
static int ak8975_read_axis(struct iio_dev *indio_dev, int index, int *val)
{
struct ak8975_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
u16 meas_reg;
s16 raw;
int ret;
mutex_lock(&data->lock);
ret = ak8975_write_data(client,
AK8975_REG_CNTL,
AK8975_REG_CNTL_MODE_ONCE,
AK8975_REG_CNTL_MODE_MASK,
AK8975_REG_CNTL_MODE_SHIFT);
if (ret < 0) {
dev_err(&client->dev, "Error in setting operating mode\n");
goto exit;
}
if (data->eoc_irq)
ret = wait_conversion_complete_interrupt(data);
else if (gpio_is_valid(data->eoc_gpio))
ret = wait_conversion_complete_gpio(data);
else
ret = wait_conversion_complete_polled(data);
if (ret < 0)
goto exit;
if (ret & AK8975_REG_ST1_DRDY_MASK) {
ret = i2c_smbus_read_byte_data(client, AK8975_REG_ST2);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST2\n");
goto exit;
}
if (ret & (AK8975_REG_ST2_DERR_MASK |
AK8975_REG_ST2_HOFL_MASK)) {
dev_err(&client->dev, "ST2 status error 0x%x\n", ret);
ret = -EINVAL;
goto exit;
}
}
ret = i2c_smbus_read_word_data(client, ak8975_index_to_reg[index]);
if (ret < 0) {
dev_err(&client->dev, "Read axis data fails\n");
goto exit;
}
meas_reg = ret;
mutex_unlock(&data->lock);
raw = (s16) (le16_to_cpu(meas_reg));
raw = clamp_t(s16, raw, -4096, 4095);
*val = raw;
return IIO_VAL_INT;
exit:
mutex_unlock(&data->lock);
return ret;
}
static int ak8975_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct ak8975_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
return ak8975_read_axis(indio_dev, chan->address, val);
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = data->raw_to_gauss[chan->address];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int ak8975_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ak8975_data *data;
struct iio_dev *indio_dev;
int eoc_gpio;
int err;
if (client->dev.platform_data)
eoc_gpio = *(int *)(client->dev.platform_data);
else if (client->dev.of_node)
eoc_gpio = of_get_gpio(client->dev.of_node, 0);
else
eoc_gpio = -1;
if (eoc_gpio == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (gpio_is_valid(eoc_gpio)) {
err = gpio_request_one(eoc_gpio, GPIOF_IN, "ak_8975");
if (err < 0) {
dev_err(&client->dev,
"failed to request GPIO %d, error %d\n",
eoc_gpio, err);
goto exit;
}
}
indio_dev = iio_device_alloc(sizeof(*data));
if (indio_dev == NULL) {
err = -ENOMEM;
goto exit_gpio;
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->eoc_gpio = eoc_gpio;
data->eoc_irq = 0;
err = ak8975_setup(client);
if (err < 0) {
dev_err(&client->dev, "AK8975 initialization fails\n");
goto exit_free_iio;
}
data->client = client;
mutex_init(&data->lock);
data->eoc_gpio = eoc_gpio;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = ak8975_channels;
indio_dev->num_channels = ARRAY_SIZE(ak8975_channels);
indio_dev->info = &ak8975_info;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(indio_dev);
if (err < 0)
goto exit_free_iio;
return 0;
exit_free_iio:
iio_device_free(indio_dev);
if (data->eoc_irq)
free_irq(data->eoc_irq, data);
exit_gpio:
if (gpio_is_valid(eoc_gpio))
gpio_free(eoc_gpio);
exit:
return err;
}
static int ak8975_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ak8975_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (data->eoc_irq)
free_irq(data->eoc_irq, data);
if (gpio_is_valid(data->eoc_gpio))
gpio_free(data->eoc_gpio);
iio_device_free(indio_dev);
return 0;
}
