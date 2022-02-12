static s32 hmc5843_configure(struct i2c_client *client,
u8 operating_mode)
{
return i2c_smbus_write_byte_data(client,
HMC5843_MODE_REG,
(operating_mode & 0x03));
}
static ssize_t hmc5843_read_measurement(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
s16 coordinate_val;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct hmc5843_data *data = iio_priv(indio_dev);
s32 result;
mutex_lock(&data->lock);
result = i2c_smbus_read_byte_data(client, HMC5843_STATUS_REG);
while (!(result & DATA_READY))
result = i2c_smbus_read_byte_data(client, HMC5843_STATUS_REG);
result = i2c_smbus_read_word_data(client, this_attr->address);
mutex_unlock(&data->lock);
if (result < 0)
return -EINVAL;
coordinate_val = (s16)swab16((u16)result);
return sprintf(buf, "%d\n", coordinate_val);
}
static ssize_t hmc5843_show_operating_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
return sprintf(buf, "%d\n", data->operating_mode);
}
static ssize_t hmc5843_set_operating_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
unsigned long operating_mode = 0;
s32 status;
int error;
mutex_lock(&data->lock);
error = strict_strtoul(buf, 10, &operating_mode);
if (error) {
count = error;
goto exit;
}
dev_dbg(dev, "set Conversion mode to %lu\n", operating_mode);
if (operating_mode > MODE_SLEEP) {
count = -EINVAL;
goto exit;
}
status = i2c_smbus_write_byte_data(client, this_attr->address,
operating_mode);
if (status) {
count = -EINVAL;
goto exit;
}
data->operating_mode = operating_mode;
exit:
mutex_unlock(&data->lock);
return count;
}
static s32 hmc5843_set_meas_conf(struct i2c_client *client,
u8 meas_conf)
{
struct hmc5843_data *data = i2c_get_clientdata(client);
u8 reg_val;
reg_val = (meas_conf & MEAS_CONF_MASK) | (data->rate << RATE_OFFSET);
return i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_A, reg_val);
}
static ssize_t hmc5843_show_measurement_configuration(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
return sprintf(buf, "%d\n", data->meas_conf);
}
static ssize_t hmc5843_set_measurement_configuration(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = i2c_get_clientdata(client);
unsigned long meas_conf = 0;
int error = strict_strtoul(buf, 10, &meas_conf);
if (error)
return error;
mutex_lock(&data->lock);
dev_dbg(dev, "set mode to %lu\n", meas_conf);
if (hmc5843_set_meas_conf(client, meas_conf)) {
count = -EINVAL;
goto exit;
}
data->meas_conf = meas_conf;
exit:
mutex_unlock(&data->lock);
return count;
}
static s32 hmc5843_set_rate(struct i2c_client *client,
u8 rate)
{
struct hmc5843_data *data = i2c_get_clientdata(client);
u8 reg_val;
reg_val = (data->meas_conf) | (rate << RATE_OFFSET);
if (rate >= RATE_NOT_USED) {
dev_err(&client->dev,
"This data output rate is not supported \n");
return -EINVAL;
}
return i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_A, reg_val);
}
static ssize_t set_sampling_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
unsigned long rate = 0;
if (strncmp(buf, "0.5" , 3) == 0)
rate = RATE_5;
else if (strncmp(buf, "1" , 1) == 0)
rate = RATE_10;
else if (strncmp(buf, "2", 1) == 0)
rate = RATE_20;
else if (strncmp(buf, "5", 1) == 0)
rate = RATE_50;
else if (strncmp(buf, "10", 2) == 0)
rate = RATE_100;
else if (strncmp(buf, "20" , 2) == 0)
rate = RATE_200;
else if (strncmp(buf, "50" , 2) == 0)
rate = RATE_500;
else
return -EINVAL;
mutex_lock(&data->lock);
dev_dbg(dev, "set rate to %lu\n", rate);
if (hmc5843_set_rate(client, rate)) {
count = -EINVAL;
goto exit;
}
data->rate = rate;
exit:
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_sampling_frequency(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
s32 rate;
rate = i2c_smbus_read_byte_data(client, this_attr->address);
if (rate < 0)
return rate;
rate = (rate & RATE_BITMASK) >> RATE_OFFSET;
return sprintf(buf, "%s\n", regval_to_samp_freq[rate]);
}
static ssize_t show_range(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 range;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
range = data->range;
return sprintf(buf, "%d\n", regval_to_input_field_mg[range]);
}
static ssize_t set_range(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct hmc5843_data *data = iio_priv(indio_dev);
unsigned long range = 0;
int error;
mutex_lock(&data->lock);
error = strict_strtoul(buf, 10, &range);
if (error) {
count = error;
goto exit;
}
dev_dbg(dev, "set range to %lu\n", range);
if (range > RANGE_6_5) {
count = -EINVAL;
goto exit;
}
data->range = range;
range = range << RANGE_GAIN_OFFSET;
if (i2c_smbus_write_byte_data(client, this_attr->address, range))
count = -EINVAL;
exit:
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
return strlen(strcpy(buf, regval_to_scale[data->range]));
}
static int hmc5843_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
unsigned char id_str[HMC5843_ID_REG_LENGTH];
if (client->addr != HMC5843_I2C_ADDRESS)
return -ENODEV;
if (i2c_smbus_read_i2c_block_data(client, HMC5843_ID_REG_A,
HMC5843_ID_REG_LENGTH, id_str)
!= HMC5843_ID_REG_LENGTH)
return -ENODEV;
if (0 != strncmp(id_str, HMC5843_ID_STRING, HMC5843_ID_REG_LENGTH))
return -ENODEV;
return 0;
}
static void hmc5843_init_client(struct i2c_client *client)
{
struct hmc5843_data *data = i2c_get_clientdata(client);
hmc5843_set_meas_conf(client, data->meas_conf);
hmc5843_set_rate(client, data->rate);
hmc5843_configure(client, data->operating_mode);
i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_B, data->range);
mutex_init(&data->lock);
pr_info("HMC5843 initialized\n");
}
static int hmc5843_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hmc5843_data *data;
struct iio_dev *indio_dev;
int err = 0;
indio_dev = iio_allocate_device(sizeof(*data));
if (indio_dev == NULL) {
err = -ENOMEM;
goto exit;
}
data = iio_priv(indio_dev);
data->meas_conf = CONF_NORMAL;
data->range = RANGE_1_0;
data->operating_mode = MODE_CONVERSION_CONTINUOUS;
i2c_set_clientdata(client, indio_dev);
hmc5843_init_client(client);
indio_dev->info = &hmc5843_info;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(indio_dev);
if (err)
goto exit_free2;
return 0;
exit_free2:
iio_free_device(indio_dev);
exit:
return err;
}
static int hmc5843_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
hmc5843_configure(client, MODE_SLEEP);
iio_device_unregister(indio_dev);
return 0;
}
static int hmc5843_suspend(struct i2c_client *client, pm_message_t mesg)
{
hmc5843_configure(client, MODE_SLEEP);
return 0;
}
static int hmc5843_resume(struct i2c_client *client)
{
struct hmc5843_data *data = i2c_get_clientdata(client);
hmc5843_configure(client, data->operating_mode);
return 0;
}
static int __init hmc5843_init(void)
{
return i2c_add_driver(&hmc5843_driver);
}
static void __exit hmc5843_exit(void)
{
i2c_del_driver(&hmc5843_driver);
}
