static int kxcjk1013_set_mode(struct kxcjk1013_data *data,
enum kxcjk1013_mode mode)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (mode == STANDBY)
ret &= ~KXCJK1013_REG_CTRL1_BIT_PC1;
else
ret |= KXCJK1013_REG_CTRL1_BIT_PC1;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
return 0;
}
static int kxcjk1013_chip_init(struct kxcjk1013_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_WHO_AM_I);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading who_am_i\n");
return ret;
}
dev_dbg(&data->client->dev, "KXCJK1013 Chip Id %x\n", ret);
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
ret |= KXCJK1013_REG_CTRL1_BIT_GSEL0;
ret &= ~KXCJK1013_REG_CTRL1_BIT_GSEL1;
ret |= KXCJK1013_REG_CTRL1_BIT_RES;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl\n");
return ret;
}
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_DATA_CTRL);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_data_ctrl\n");
return ret;
}
data->odr_bits = ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
return ret;
}
if (data->active_high_intr)
ret |= KXCJK1013_REG_INT_REG1_BIT_IEA;
else
ret &= ~KXCJK1013_REG_INT_REG1_BIT_IEA;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
return ret;
}
return 0;
}
static int kxcjk1013_chip_setup_interrupt(struct kxcjk1013_data *data,
bool status)
{
int ret;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_INT_REG1_BIT_IEN;
else
ret &= ~KXCJK1013_REG_INT_REG1_BIT_IEN;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_INT_CTRL1,
ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_int_ctrl1\n");
return ret;
}
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_CTRL1);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_ctrl1\n");
return ret;
}
if (status)
ret |= KXCJK1013_REG_CTRL1_BIT_DRDY;
else
ret &= ~KXCJK1013_REG_CTRL1_BIT_DRDY;
ret = i2c_smbus_write_byte_data(data->client,
KXCJK1013_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing reg_ctrl1\n");
return ret;
}
return ret;
}
static int kxcjk1013_convert_freq_to_bit(int val, int val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(samp_freq_table); ++i) {
if (samp_freq_table[i].val == val &&
samp_freq_table[i].val2 == val2) {
return samp_freq_table[i].odr_bits;
}
}
return -EINVAL;
}
static int kxcjk1013_set_odr(struct kxcjk1013_data *data, int val, int val2)
{
int ret;
int odr_bits;
odr_bits = kxcjk1013_convert_freq_to_bit(val, val2);
if (odr_bits < 0)
return odr_bits;
ret = kxcjk1013_set_mode(data, STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client, KXCJK1013_REG_DATA_CTRL,
odr_bits);
if (ret < 0) {
dev_err(&data->client->dev, "Error writing data_ctrl\n");
return ret;
}
data->odr_bits = odr_bits;
if (data->power_state) {
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0)
return ret;
}
return 0;
}
static int kxcjk1013_get_odr(struct kxcjk1013_data *data, int *val, int *val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(samp_freq_table); ++i) {
if (samp_freq_table[i].odr_bits == data->odr_bits) {
*val = samp_freq_table[i].val;
*val2 = samp_freq_table[i].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int kxcjk1013_get_acc_reg(struct kxcjk1013_data *data, int axis)
{
u8 reg = KXCJK1013_REG_XOUT_L + axis * 2;
int ret;
ret = i2c_smbus_read_word_data(data->client, reg);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read accel_%c registers\n", 'x' + axis);
return ret;
}
return ret;
}
static int kxcjk1013_get_startup_times(struct kxcjk1013_data *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(odr_start_up_times); ++i) {
if (odr_start_up_times[i].odr_bits == data->odr_bits)
return odr_start_up_times[i].usec;
}
return KXCJK1013_MAX_STARTUP_TIME_US;
}
static int kxcjk1013_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->mutex);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else {
int sleep_val;
ret = kxcjk1013_set_mode(data, OPERATION);
if (ret < 0) {
mutex_unlock(&data->mutex);
return ret;
}
++data->power_state;
sleep_val = kxcjk1013_get_startup_times(data);
if (sleep_val < 20000)
usleep_range(sleep_val, 20000);
else
msleep_interruptible(sleep_val/1000);
ret = kxcjk1013_get_acc_reg(data, chan->scan_index);
if (--data->power_state == 0)
kxcjk1013_set_mode(data, STANDBY);
}
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
*val = sign_extend32(ret >> 4, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 19163;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = kxcjk1013_get_odr(data, val, val2);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int kxcjk1013_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->mutex);
ret = kxcjk1013_set_odr(data, val, val2);
mutex_unlock(&data->mutex);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int kxcjk1013_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct kxcjk1013_data *data = iio_priv(indio_dev);
if (data->trig != trig)
return -EINVAL;
return 0;
}
static irqreturn_t kxcjk1013_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct kxcjk1013_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
ret = kxcjk1013_get_acc_reg(data, bit);
if (ret < 0) {
mutex_unlock(&data->mutex);
goto err;
}
data->buffer[i++] = ret;
}
mutex_unlock(&data->mutex);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int kxcjk1013_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct kxcjk1013_data *data = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_read_byte_data(data->client, KXCJK1013_REG_INT_REL);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg_int_rel\n");
return ret;
}
return 0;
}
static int kxcjk1013_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct kxcjk1013_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
if (state) {
kxcjk1013_chip_setup_interrupt(data, true);
kxcjk1013_set_mode(data, OPERATION);
++data->power_state;
} else {
if (--data->power_state) {
mutex_unlock(&data->mutex);
return 0;
}
kxcjk1013_chip_setup_interrupt(data, false);
kxcjk1013_set_mode(data, STANDBY);
}
mutex_unlock(&data->mutex);
return 0;
}
static int kxcjk1013_acpi_gpio_probe(struct i2c_client *client,
struct kxcjk1013_data *data)
{
const struct acpi_device_id *id;
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
if (!ACPI_HANDLE(dev))
return -ENODEV;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
gpio = devm_gpiod_get_index(dev, "kxcjk1013_int", 0);
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
static int kxcjk1013_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct kxcjk1013_data *data;
struct iio_dev *indio_dev;
struct iio_trigger *trig = NULL;
struct kxcjk_1013_platform_data *pdata;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
pdata = dev_get_platdata(&client->dev);
if (pdata)
data->active_high_intr = pdata->active_high_intr;
else
data->active_high_intr = true;
ret = kxcjk1013_chip_init(data);
if (ret < 0)
return ret;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = kxcjk1013_channels;
indio_dev->num_channels = ARRAY_SIZE(kxcjk1013_channels);
indio_dev->name = KXCJK1013_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &kxcjk1013_info;
if (client->irq < 0)
client->irq = kxcjk1013_acpi_gpio_probe(client, data);
if (client->irq >= 0) {
trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
indio_dev->id);
if (!trig)
return -ENOMEM;
data->trig_mode = true;
ret = devm_request_irq(&client->dev, client->irq,
iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING,
KXCJK1013_IRQ_NAME,
trig);
if (ret) {
dev_err(&client->dev, "unable to request IRQ\n");
goto err_trigger_free;
}
trig->dev.parent = &client->dev;
trig->ops = &kxcjk1013_trigger_ops;
iio_trigger_set_drvdata(trig, indio_dev);
data->trig = trig;
indio_dev->trig = trig;
iio_trigger_get(indio_dev->trig);
ret = iio_trigger_register(trig);
if (ret)
goto err_trigger_free;
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time,
kxcjk1013_trigger_handler,
NULL);
if (ret < 0) {
dev_err(&client->dev,
"iio triggered buffer setup failed\n");
goto err_trigger_unregister;
}
}
ret = devm_iio_device_register(&client->dev, indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
if (data->trig_mode)
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->trig_mode)
iio_trigger_unregister(trig);
err_trigger_free:
if (data->trig_mode)
iio_trigger_free(trig);
return ret;
}
static int kxcjk1013_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct kxcjk1013_data *data = iio_priv(indio_dev);
if (data->trig_mode) {
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(data->trig);
iio_trigger_free(data->trig);
}
mutex_lock(&data->mutex);
kxcjk1013_set_mode(data, STANDBY);
mutex_unlock(&data->mutex);
return 0;
}
static int kxcjk1013_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
kxcjk1013_set_mode(data, STANDBY);
mutex_unlock(&data->mutex);
return 0;
}
static int kxcjk1013_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct kxcjk1013_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
if (data->power_state)
kxcjk1013_set_mode(data, OPERATION);
mutex_unlock(&data->mutex);
return 0;
}
