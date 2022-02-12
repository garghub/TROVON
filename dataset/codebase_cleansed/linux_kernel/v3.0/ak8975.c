static int ak8975_write_data(struct i2c_client *client,
u8 reg, u8 val, u8 mask, u8 shift)
{
u8 regval;
struct i2c_msg msg;
u8 w_data[2];
int ret = 0;
struct ak8975_data *data = i2c_get_clientdata(client);
regval = data->reg_cache[reg];
regval &= ~mask;
regval |= val << shift;
w_data[0] = reg;
w_data[1] = regval;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
msg.buf = w_data;
ret = i2c_transfer(client->adapter, &msg, 1);
if (ret < 0) {
dev_err(&client->dev, "Write to device fails status %x\n", ret);
return ret;
}
data->reg_cache[reg] = regval;
return 0;
}
static int ak8975_read_data(struct i2c_client *client,
u8 reg, u8 length, u8 *buffer)
{
struct i2c_msg msg[2];
u8 w_data[2];
int ret;
w_data[0] = reg;
msg[0].addr = client->addr;
msg[0].flags = I2C_M_NOSTART;
msg[0].len = 1;
msg[0].buf = w_data;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = length;
msg[1].buf = buffer;
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0) {
dev_err(&client->dev, "Read from device fails\n");
return ret;
}
return 0;
}
static int ak8975_setup(struct i2c_client *client)
{
struct ak8975_data *data = i2c_get_clientdata(client);
u8 device_id;
int ret;
ret = ak8975_read_data(client, AK8975_REG_WIA, 1, &device_id);
if (ret < 0) {
dev_err(&client->dev, "Error reading WIA\n");
return ret;
}
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
ret = ak8975_read_data(client, AK8975_REG_ASAX, 3, data->asa);
if (ret < 0) {
dev_err(&client->dev, "Not able to read asa data\n");
return ret;
}
data->raw_to_gauss[0] = ((data->asa[0] + 128) * 30) >> 8;
data->raw_to_gauss[1] = ((data->asa[1] + 128) * 30) >> 8;
data->raw_to_gauss[2] = ((data->asa[2] + 128) * 30) >> 8;
return 0;
}
static ssize_t show_mode(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ak8975_data *data = indio_dev->dev_data;
return sprintf(buf, "%lu\n", data->mode);
}
static ssize_t store_mode(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ak8975_data *data = indio_dev->dev_data;
struct i2c_client *client = data->client;
unsigned long oval;
int ret;
if (strict_strtoul(buf, 10, &oval))
return -EINVAL;
if (oval > 1) {
dev_err(dev, "mode value is not supported\n");
return -EINVAL;
}
mutex_lock(&data->lock);
if (data->mode != oval) {
ret = ak8975_write_data(client,
AK8975_REG_CNTL,
(u8)oval,
AK8975_REG_CNTL_MODE_MASK,
AK8975_REG_CNTL_MODE_SHIFT);
if (ret < 0) {
dev_err(&client->dev, "Error in setting mode\n");
mutex_unlock(&data->lock);
return ret;
}
data->mode = oval;
}
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_scale(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ak8975_data *data = indio_dev->dev_data;
struct iio_dev_attr *this_attr = to_iio_dev_attr(devattr);
return sprintf(buf, "%ld\n", data->raw_to_gauss[this_attr->address]);
}
static int wait_conversion_complete_gpio(struct ak8975_data *data)
{
struct i2c_client *client = data->client;
u8 read_status;
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
ret = ak8975_read_data(client, AK8975_REG_ST1, 1, &read_status);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST1\n");
return ret;
}
return read_status;
}
static int wait_conversion_complete_polled(struct ak8975_data *data)
{
struct i2c_client *client = data->client;
u8 read_status;
u32 timeout_ms = AK8975_MAX_CONVERSION_TIMEOUT;
int ret;
while (timeout_ms) {
msleep(AK8975_CONVERSION_DONE_POLL_TIME);
ret = ak8975_read_data(client, AK8975_REG_ST1, 1, &read_status);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST1\n");
return ret;
}
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
static ssize_t show_raw(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ak8975_data *data = indio_dev->dev_data;
struct i2c_client *client = data->client;
struct iio_dev_attr *this_attr = to_iio_dev_attr(devattr);
u16 meas_reg;
s16 raw;
u8 read_status;
int ret;
mutex_lock(&data->lock);
if (data->mode == 0) {
dev_err(&client->dev, "Operating mode is in power down mode\n");
ret = -EBUSY;
goto exit;
}
ret = ak8975_write_data(client,
AK8975_REG_CNTL,
AK8975_REG_CNTL_MODE_ONCE,
AK8975_REG_CNTL_MODE_MASK,
AK8975_REG_CNTL_MODE_SHIFT);
if (ret < 0) {
dev_err(&client->dev, "Error in setting operating mode\n");
goto exit;
}
if (data->eoc_gpio)
ret = wait_conversion_complete_gpio(data);
else
ret = wait_conversion_complete_polled(data);
if (ret < 0)
goto exit;
read_status = ret;
if (read_status & AK8975_REG_ST1_DRDY_MASK) {
ret = ak8975_read_data(client, AK8975_REG_ST2, 1, &read_status);
if (ret < 0) {
dev_err(&client->dev, "Error in reading ST2\n");
goto exit;
}
if (read_status & (AK8975_REG_ST2_DERR_MASK |
AK8975_REG_ST2_HOFL_MASK)) {
dev_err(&client->dev, "ST2 status error 0x%x\n",
read_status);
ret = -EINVAL;
goto exit;
}
}
ret = ak8975_read_data(client, this_attr->address, 2, (u8 *)&meas_reg);
if (ret < 0) {
dev_err(&client->dev, "Read axis data fails\n");
goto exit;
}
mutex_unlock(&data->lock);
raw = (s16) (le16_to_cpu(meas_reg));
raw = clamp_t(s16, raw, -4096, 4095);
return sprintf(buf, "%d\n", raw);
exit:
mutex_unlock(&data->lock);
return ret;
}
static int ak8975_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ak8975_data *data;
int err;
data = kzalloc(sizeof(struct ak8975_data), GFP_KERNEL);
if (!data) {
dev_err(&client->dev, "Memory allocation fails\n");
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
data->client = client;
mutex_init(&data->lock);
data->eoc_irq = client->irq;
data->eoc_gpio = irq_to_gpio(client->irq);
if (data->eoc_gpio > 0) {
err = gpio_request(data->eoc_gpio, "ak_8975");
if (err < 0) {
dev_err(&client->dev,
"failed to request GPIO %d, error %d\n",
data->eoc_gpio, err);
goto exit_free;
}
err = gpio_direction_input(data->eoc_gpio);
if (err < 0) {
dev_err(&client->dev,
"Failed to configure input direction for GPIO %d, error %d\n",
data->eoc_gpio, err);
goto exit_gpio;
}
} else
data->eoc_gpio = 0;
err = ak8975_setup(client);
if (err < 0) {
dev_err(&client->dev, "AK8975 initialization fails\n");
goto exit_gpio;
}
data->indio_dev = iio_allocate_device(0);
if (data->indio_dev == NULL) {
err = -ENOMEM;
goto exit_gpio;
}
data->indio_dev->dev.parent = &client->dev;
data->indio_dev->info = &ak8975_info;
data->indio_dev->dev_data = (void *)(data);
data->indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(data->indio_dev);
if (err < 0)
goto exit_free_iio;
return 0;
exit_free_iio:
iio_free_device(data->indio_dev);
exit_gpio:
if (data->eoc_gpio)
gpio_free(data->eoc_gpio);
exit_free:
kfree(data);
exit:
return err;
}
static int ak8975_remove(struct i2c_client *client)
{
struct ak8975_data *data = i2c_get_clientdata(client);
iio_device_unregister(data->indio_dev);
iio_free_device(data->indio_dev);
if (data->eoc_gpio)
gpio_free(data->eoc_gpio);
kfree(data);
return 0;
}
static int __init ak8975_init(void)
{
return i2c_add_driver(&ak8975_driver);
}
static void __exit ak8975_exit(void)
{
i2c_del_driver(&ak8975_driver);
}
