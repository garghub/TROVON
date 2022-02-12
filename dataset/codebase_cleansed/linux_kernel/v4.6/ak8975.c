static long ak8975_raw_to_gauss(u16 data)
{
return (((long)data + 128) * 3000) / 256;
}
static long ak8963_09911_raw_to_gauss(u16 data)
{
return (((long)data + 128) * 6000) / 256;
}
static long ak09912_raw_to_gauss(u16 data)
{
return (((long)data + 128) * 1500) / 256;
}
static int ak8975_who_i_am(struct i2c_client *client,
enum asahi_compass_chipset type)
{
u8 wia_val[2];
int ret;
ret = i2c_smbus_read_i2c_block_data(client, AK09912_REG_WIA1,
2, wia_val);
if (ret < 0) {
dev_err(&client->dev, "Error reading WIA\n");
return ret;
}
if (wia_val[0] != AK8975_DEVICE_ID)
return -ENODEV;
switch (type) {
case AK8975:
case AK8963:
return 0;
case AK09911:
if (wia_val[1] == AK09911_DEVICE_ID)
return 0;
break;
case AK09912:
if (wia_val[1] == AK09912_DEVICE_ID)
return 0;
break;
default:
dev_err(&client->dev, "Type %d unknown\n", type);
}
return -ENODEV;
}
static int ak8975_set_mode(struct ak8975_data *data, enum ak_ctrl_mode mode)
{
u8 regval;
int ret;
regval = (data->cntl_cache & ~data->def->ctrl_masks[CNTL_MODE]) |
data->def->ctrl_modes[mode];
ret = i2c_smbus_write_byte_data(data->client,
data->def->ctrl_regs[CNTL], regval);
if (ret < 0) {
return ret;
}
data->cntl_cache = regval;
usleep_range(100, 500);
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
init_waitqueue_head(&data->data_ready_queue);
clear_bit(0, &data->flags);
if (client->irq)
irq = client->irq;
else
irq = gpio_to_irq(data->eoc_gpio);
rc = devm_request_irq(&client->dev, irq, ak8975_irq_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(&client->dev), data);
if (rc < 0) {
dev_err(&client->dev,
"irq %d request failed, (gpio %d): %d\n",
irq, data->eoc_gpio, rc);
return rc;
}
data->eoc_irq = irq;
return rc;
}
static int ak8975_setup(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ak8975_data *data = iio_priv(indio_dev);
int ret;
ret = ak8975_set_mode(data, FUSE_ROM);
if (ret < 0) {
dev_err(&client->dev, "Error in setting fuse access mode\n");
return ret;
}
ret = i2c_smbus_read_i2c_block_data(client,
data->def->ctrl_regs[ASA_BASE],
3, data->asa);
if (ret < 0) {
dev_err(&client->dev, "Not able to read asa data\n");
return ret;
}
ret = ak8975_set_mode(data, POWER_DOWN);
if (ret < 0) {
dev_err(&client->dev, "Error in setting power-down mode\n");
return ret;
}
if (data->eoc_gpio > 0 || client->irq > 0) {
ret = ak8975_setup_irq(data);
if (ret < 0) {
dev_err(&client->dev,
"Error setting data ready interrupt\n");
return ret;
}
}
data->raw_to_gauss[0] = data->def->raw_to_gauss(data->asa[0]);
data->raw_to_gauss[1] = data->def->raw_to_gauss(data->asa[1]);
data->raw_to_gauss[2] = data->def->raw_to_gauss(data->asa[2]);
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
ret = i2c_smbus_read_byte_data(client, data->def->ctrl_regs[ST1]);
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
ret = i2c_smbus_read_byte_data(client,
data->def->ctrl_regs[ST1]);
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
int ret;
mutex_lock(&data->lock);
ret = ak8975_set_mode(data, MODE_ONCE);
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
if (ret & data->def->ctrl_masks[ST1_DRDY]) {
ret = i2c_smbus_read_byte_data(client,
data->def->ctrl_regs[ST2]);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST2\n");
goto exit;
}
if (ret & (data->def->ctrl_masks[ST2_DERR] |
data->def->ctrl_masks[ST2_HOFL])) {
dev_err(&client->dev, "ST2 status error 0x%x\n", ret);
ret = -EINVAL;
goto exit;
}
}
ret = i2c_smbus_read_word_data(client, data->def->data_regs[index]);
if (ret < 0) {
dev_err(&client->dev, "Read axis data fails\n");
goto exit;
}
mutex_unlock(&data->lock);
*val = clamp_t(s16, ret, -data->def->range, data->def->range);
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
static const char *ak8975_match_acpi_device(struct device *dev,
enum asahi_compass_chipset *chipset)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
*chipset = (int)id->driver_data;
return dev_name(dev);
}
static int ak8975_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ak8975_data *data;
struct iio_dev *indio_dev;
int eoc_gpio;
int err;
const char *name = NULL;
enum asahi_compass_chipset chipset = AK_MAX_TYPE;
if (client->dev.platform_data)
eoc_gpio = *(int *)(client->dev.platform_data);
else if (client->dev.of_node)
eoc_gpio = of_get_gpio(client->dev.of_node, 0);
else
eoc_gpio = -1;
if (eoc_gpio == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (gpio_is_valid(eoc_gpio)) {
err = devm_gpio_request_one(&client->dev, eoc_gpio,
GPIOF_IN, "ak_8975");
if (err < 0) {
dev_err(&client->dev,
"failed to request GPIO %d, error %d\n",
eoc_gpio, err);
return err;
}
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->eoc_gpio = eoc_gpio;
data->eoc_irq = 0;
if (id) {
chipset = (enum asahi_compass_chipset)(id->driver_data);
name = id->name;
} else if (ACPI_HANDLE(&client->dev))
name = ak8975_match_acpi_device(&client->dev, &chipset);
else
return -ENOSYS;
if (chipset >= AK_MAX_TYPE) {
dev_err(&client->dev, "AKM device type unsupported: %d\n",
chipset);
return -ENODEV;
}
data->def = &ak_def_array[chipset];
err = ak8975_who_i_am(client, data->def->type);
if (err < 0) {
dev_err(&client->dev, "Unexpected device\n");
return err;
}
dev_dbg(&client->dev, "Asahi compass chip %s\n", name);
err = ak8975_setup(client);
if (err < 0) {
dev_err(&client->dev, "%s initialization fails\n", name);
return err;
}
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = ak8975_channels;
indio_dev->num_channels = ARRAY_SIZE(ak8975_channels);
indio_dev->info = &ak8975_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->name = name;
return devm_iio_device_register(&client->dev, indio_dev);
}
