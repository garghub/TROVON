static s32 hmc5843_configure(struct i2c_client *client,
u8 operating_mode)
{
return i2c_smbus_write_byte_data(client,
HMC5843_MODE_REG,
operating_mode & HMC5843_MODE_MASK);
}
static int hmc5843_read_measurement(struct iio_dev *indio_dev,
int address,
int *val)
{
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
s32 result;
mutex_lock(&data->lock);
result = i2c_smbus_read_byte_data(client, HMC5843_STATUS_REG);
while (!(result & HMC5843_DATA_READY))
result = i2c_smbus_read_byte_data(client, HMC5843_STATUS_REG);
result = i2c_smbus_read_word_data(client, address);
mutex_unlock(&data->lock);
if (result < 0)
return -EINVAL;
*val = (s16)swab16((u16)result);
return IIO_VAL_INT;
}
static ssize_t hmc5843_show_operating_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
return sprintf(buf, "%d\n", data->operating_mode);
}
static ssize_t hmc5843_set_operating_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
unsigned long operating_mode = 0;
s32 status;
int error;
mutex_lock(&data->lock);
error = kstrtoul(buf, 10, &operating_mode);
if (error) {
count = error;
goto exit;
}
dev_dbg(dev, "set conversion mode to %lu\n", operating_mode);
if (operating_mode > HMC5843_MODE_SLEEP) {
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
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct hmc5843_data *data = iio_priv(indio_dev);
u8 reg_val;
reg_val = (meas_conf & HMC5843_MEAS_CONF_MASK) |
(data->rate << HMC5843_RATE_OFFSET);
return i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_A, reg_val);
}
static ssize_t hmc5843_show_measurement_configuration(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
return sprintf(buf, "%d\n", data->meas_conf);
}
static ssize_t hmc5843_set_measurement_configuration(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
unsigned long meas_conf = 0;
int error;
error = kstrtoul(buf, 10, &meas_conf);
if (error)
return error;
if (meas_conf >= HMC5843_MEAS_CONF_NOT_USED)
return -EINVAL;
mutex_lock(&data->lock);
dev_dbg(dev, "set measurement configuration to %lu\n", meas_conf);
if (hmc5843_set_meas_conf(client, meas_conf)) {
count = -EINVAL;
goto exit;
}
data->meas_conf = meas_conf;
exit:
mutex_unlock(&data->lock);
return count;
}
static ssize_t hmc5843_show_sampling_frequencies_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
ssize_t total_n = 0;
int i;
for (i = 0; i < HMC5843_RATE_NOT_USED; i++) {
ssize_t n = sprintf(buf, "%s ", data->variant->regval_to_sample_freq[i]);
buf += n;
total_n += n;
}
buf[-1] = '\n';
return total_n;
}
static s32 hmc5843_set_rate(struct i2c_client *client,
u8 rate)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct hmc5843_data *data = iio_priv(indio_dev);
u8 reg_val;
if (rate >= HMC5843_RATE_NOT_USED) {
dev_err(&client->dev,
"data output rate is not supported\n");
return -EINVAL;
}
reg_val = data->meas_conf | (rate << HMC5843_RATE_OFFSET);
return i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_A, reg_val);
}
static int hmc5843_check_sampling_frequency(struct hmc5843_data *data,
const char *buf)
{
const char * const *samp_freq = data->variant->regval_to_sample_freq;
int i;
for (i = 0; i < HMC5843_RATE_NOT_USED; i++) {
if (sysfs_streq(buf, samp_freq[i]))
return i;
}
return -EINVAL;
}
static ssize_t hmc5843_set_sampling_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct hmc5843_data *data = iio_priv(indio_dev);
int rate;
rate = hmc5843_check_sampling_frequency(data, buf);
if (rate < 0) {
dev_err(&client->dev,
"sampling frequency is not supported\n");
return rate;
}
mutex_lock(&data->lock);
dev_dbg(dev, "set rate to %d\n", rate);
if (hmc5843_set_rate(client, rate)) {
count = -EINVAL;
goto exit;
}
data->rate = rate;
exit:
mutex_unlock(&data->lock);
return count;
}
static ssize_t hmc5843_show_sampling_frequency(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct hmc5843_data *data = iio_priv(indio_dev);
s32 rate;
rate = i2c_smbus_read_byte_data(client, this_attr->address);
if (rate < 0)
return rate;
rate = (rate & HMC5843_RATE_BITMASK) >> HMC5843_RATE_OFFSET;
return sprintf(buf, "%s\n", data->variant->regval_to_sample_freq[rate]);
}
static ssize_t hmc5843_show_range_gain(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 range;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct hmc5843_data *data = iio_priv(indio_dev);
range = data->range;
return sprintf(buf, "%d\n", data->variant->regval_to_input_field_mga[range]);
}
static ssize_t hmc5843_set_range_gain(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct i2c_client *client = to_i2c_client(indio_dev->dev.parent);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct hmc5843_data *data = iio_priv(indio_dev);
unsigned long range = 0;
int error;
mutex_lock(&data->lock);
error = kstrtoul(buf, 10, &range);
if (error) {
count = error;
goto exit;
}
dev_dbg(dev, "set range to %lu\n", range);
if (range > HMC5843_RANGE_GAIN_MAX) {
count = -EINVAL;
goto exit;
}
data->range = range;
range = range << HMC5843_RANGE_GAIN_OFFSET;
if (i2c_smbus_write_byte_data(client, this_attr->address, range))
count = -EINVAL;
exit:
mutex_unlock(&data->lock);
return count;
}
static int hmc5843_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct hmc5843_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
return hmc5843_read_measurement(indio_dev,
chan->address,
val);
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = data->variant->regval_to_nanoscale[data->range];
return IIO_VAL_INT_PLUS_NANO;
}
return -EINVAL;
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
static void hmc5843_init_client(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct hmc5843_data *data = iio_priv(indio_dev);
data->variant = &hmc5843_chip_info_tbl[id->driver_data];
indio_dev->channels = data->variant->channels;
indio_dev->num_channels = data->variant->num_channels;
hmc5843_set_meas_conf(client, data->meas_conf);
hmc5843_set_rate(client, data->rate);
hmc5843_configure(client, data->operating_mode);
i2c_smbus_write_byte_data(client, HMC5843_CONFIG_REG_B, data->range);
mutex_init(&data->lock);
pr_info("%s initialized\n", id->name);
}
static int hmc5843_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hmc5843_data *data;
struct iio_dev *indio_dev;
int err = 0;
indio_dev = iio_device_alloc(sizeof(*data));
if (indio_dev == NULL) {
err = -ENOMEM;
goto exit;
}
data = iio_priv(indio_dev);
data->meas_conf = HMC5843_MEAS_CONF_NORMAL;
data->range = HMC5843_RANGE_GAIN_DEFAULT;
data->operating_mode = HMC5843_MODE_CONVERSION_CONTINUOUS;
i2c_set_clientdata(client, indio_dev);
hmc5843_init_client(client, id);
indio_dev->info = &hmc5843_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(indio_dev);
if (err)
goto exit_free2;
return 0;
exit_free2:
iio_device_free(indio_dev);
exit:
return err;
}
static int hmc5843_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
hmc5843_configure(client, HMC5843_MODE_SLEEP);
iio_device_free(indio_dev);
return 0;
}
static int hmc5843_suspend(struct device *dev)
{
hmc5843_configure(to_i2c_client(dev), HMC5843_MODE_SLEEP);
return 0;
}
static int hmc5843_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct hmc5843_data *data = iio_priv(indio_dev);
hmc5843_configure(client, data->operating_mode);
return 0;
}
