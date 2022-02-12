static int isl29018_set_integration_time(struct isl29018_chip *chip,
unsigned int utime)
{
int i, ret;
unsigned int int_time, new_int_time;
for (i = 0; i < ARRAY_SIZE(isl29018_int_utimes[chip->type]); ++i) {
if (utime == isl29018_int_utimes[chip->type][i]) {
new_int_time = i;
break;
}
}
if (i >= ARRAY_SIZE(isl29018_int_utimes[chip->type]))
return -EINVAL;
ret = regmap_update_bits(chip->regmap, ISL29018_REG_ADD_COMMANDII,
COMMANDII_RESOLUTION_MASK,
i << COMMANDII_RESOLUTION_SHIFT);
if (ret < 0)
return ret;
int_time = chip->int_time;
for (i = 0; i < ARRAY_SIZE(isl29018_scales[int_time]); ++i) {
if (chip->scale.scale == isl29018_scales[int_time][i].scale &&
chip->scale.uscale == isl29018_scales[int_time][i].uscale) {
chip->scale = isl29018_scales[new_int_time][i];
break;
}
}
chip->int_time = new_int_time;
return 0;
}
static int isl29018_set_scale(struct isl29018_chip *chip, int scale, int uscale)
{
int i, ret;
struct isl29018_scale new_scale;
for (i = 0; i < ARRAY_SIZE(isl29018_scales[chip->int_time]); ++i) {
if (scale == isl29018_scales[chip->int_time][i].scale &&
uscale == isl29018_scales[chip->int_time][i].uscale) {
new_scale = isl29018_scales[chip->int_time][i];
break;
}
}
if (i >= ARRAY_SIZE(isl29018_scales[chip->int_time]))
return -EINVAL;
ret = regmap_update_bits(chip->regmap, ISL29018_REG_ADD_COMMANDII,
COMMANDII_RANGE_MASK,
i << COMMANDII_RANGE_SHIFT);
if (ret < 0)
return ret;
chip->scale = new_scale;
return 0;
}
static int isl29018_read_sensor_input(struct isl29018_chip *chip, int mode)
{
int status;
unsigned int lsb;
unsigned int msb;
status = regmap_write(chip->regmap, ISL29018_REG_ADD_COMMAND1,
mode << COMMMAND1_OPMODE_SHIFT);
if (status) {
dev_err(chip->dev,
"Error in setting operating mode err %d\n", status);
return status;
}
msleep(CONVERSION_TIME_MS);
status = regmap_read(chip->regmap, ISL29018_REG_ADD_DATA_LSB, &lsb);
if (status < 0) {
dev_err(chip->dev,
"Error in reading LSB DATA with err %d\n", status);
return status;
}
status = regmap_read(chip->regmap, ISL29018_REG_ADD_DATA_MSB, &msb);
if (status < 0) {
dev_err(chip->dev,
"Error in reading MSB DATA with error %d\n", status);
return status;
}
dev_vdbg(chip->dev, "MSB 0x%x and LSB 0x%x\n", msb, lsb);
return (msb << 8) | lsb;
}
static int isl29018_read_lux(struct isl29018_chip *chip, int *lux)
{
int lux_data;
unsigned int data_x_range;
lux_data = isl29018_read_sensor_input(chip, COMMMAND1_OPMODE_ALS_ONCE);
if (lux_data < 0)
return lux_data;
data_x_range = lux_data * chip->scale.scale +
lux_data * chip->scale.uscale / 1000000;
*lux = data_x_range * chip->calibscale +
data_x_range * chip->ucalibscale / 1000000;
return 0;
}
static int isl29018_read_ir(struct isl29018_chip *chip, int *ir)
{
int ir_data;
ir_data = isl29018_read_sensor_input(chip, COMMMAND1_OPMODE_IR_ONCE);
if (ir_data < 0)
return ir_data;
*ir = ir_data;
return 0;
}
static int isl29018_read_proximity_ir(struct isl29018_chip *chip, int scheme,
int *near_ir)
{
int status;
int prox_data = -1;
int ir_data = -1;
status = regmap_update_bits(chip->regmap, ISL29018_REG_ADD_COMMANDII,
COMMANDII_SCHEME_MASK,
scheme << COMMANDII_SCHEME_SHIFT);
if (status) {
dev_err(chip->dev, "Error in setting operating mode\n");
return status;
}
prox_data = isl29018_read_sensor_input(chip,
COMMMAND1_OPMODE_PROX_ONCE);
if (prox_data < 0)
return prox_data;
if (scheme == 1) {
*near_ir = prox_data;
return 0;
}
ir_data = isl29018_read_sensor_input(chip, COMMMAND1_OPMODE_IR_ONCE);
if (ir_data < 0)
return ir_data;
if (prox_data >= ir_data)
*near_ir = prox_data - ir_data;
else
*near_ir = 0;
return 0;
}
static ssize_t show_scale_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(isl29018_scales[chip->int_time]); ++i)
len += sprintf(buf + len, "%d.%06d ",
isl29018_scales[chip->int_time][i].scale,
isl29018_scales[chip->int_time][i].uscale);
buf[len - 1] = '\n';
return len;
}
static ssize_t show_int_time_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(isl29018_int_utimes[chip->type]); ++i)
len += sprintf(buf + len, "0.%06d ",
isl29018_int_utimes[chip->type][i]);
buf[len - 1] = '\n';
return len;
}
static ssize_t show_prox_infrared_suppression(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
return sprintf(buf, "%d\n", chip->prox_scheme);
}
static ssize_t store_prox_infrared_suppression(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
int val;
if (kstrtoint(buf, 10, &val))
return -EINVAL;
if (!(val == 0 || val == 1)) {
dev_err(dev, "The mode is not supported\n");
return -EINVAL;
}
mutex_lock(&chip->lock);
chip->prox_scheme = val;
mutex_unlock(&chip->lock);
return count;
}
static int isl29018_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct isl29018_chip *chip = iio_priv(indio_dev);
int ret = -EINVAL;
mutex_lock(&chip->lock);
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT) {
chip->calibscale = val;
chip->ucalibscale = val2;
ret = 0;
}
break;
case IIO_CHAN_INFO_INT_TIME:
if (chan->type == IIO_LIGHT) {
if (val) {
mutex_unlock(&chip->lock);
return -EINVAL;
}
ret = isl29018_set_integration_time(chip, val2);
}
break;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_LIGHT)
ret = isl29018_set_scale(chip, val, val2);
break;
default:
break;
}
mutex_unlock(&chip->lock);
return ret;
}
static int isl29018_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret = -EINVAL;
struct isl29018_chip *chip = iio_priv(indio_dev);
mutex_lock(&chip->lock);
if (chip->suspended) {
mutex_unlock(&chip->lock);
return -EBUSY;
}
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_LIGHT:
ret = isl29018_read_lux(chip, val);
break;
case IIO_INTENSITY:
ret = isl29018_read_ir(chip, val);
break;
case IIO_PROXIMITY:
ret = isl29018_read_proximity_ir(chip,
chip->prox_scheme, val);
break;
default:
break;
}
if (!ret)
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_INT_TIME:
if (chan->type == IIO_LIGHT) {
*val = 0;
*val2 = isl29018_int_utimes[chip->type][chip->int_time];
ret = IIO_VAL_INT_PLUS_MICRO;
}
break;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_LIGHT) {
*val = chip->scale.scale;
*val2 = chip->scale.uscale;
ret = IIO_VAL_INT_PLUS_MICRO;
}
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT) {
*val = chip->calibscale;
*val2 = chip->ucalibscale;
ret = IIO_VAL_INT_PLUS_MICRO;
}
break;
default:
break;
}
mutex_unlock(&chip->lock);
return ret;
}
static int isl29035_detect(struct isl29018_chip *chip)
{
int status;
unsigned int id;
status = regmap_read(chip->regmap, ISL29035_REG_DEVICE_ID, &id);
if (status < 0) {
dev_err(chip->dev,
"Error reading ID register with error %d\n",
status);
return status;
}
id = (id & ISL29035_DEVICE_ID_MASK) >> ISL29035_DEVICE_ID_SHIFT;
if (id != ISL29035_DEVICE_ID)
return -ENODEV;
return regmap_update_bits(chip->regmap, ISL29035_REG_DEVICE_ID,
ISL29035_BOUT_MASK, 0);
}
static int isl29018_chip_init(struct isl29018_chip *chip)
{
int status;
if (chip->type == isl29035) {
status = isl29035_detect(chip);
if (status < 0)
return status;
}
status = regmap_write(chip->regmap, ISL29018_REG_TEST, 0x0);
if (status < 0) {
dev_err(chip->dev, "Failed to clear isl29018 TEST reg.(%d)\n",
status);
return status;
}
status = regmap_write(chip->regmap, ISL29018_REG_ADD_COMMAND1, 0);
if (status < 0) {
dev_err(chip->dev, "Failed to clear isl29018 CMD1 reg.(%d)\n",
status);
return status;
}
usleep_range(1000, 2000);
status = isl29018_set_scale(chip, chip->scale.scale,
chip->scale.uscale);
if (status < 0) {
dev_err(chip->dev, "Init of isl29018 fails\n");
return status;
}
status = isl29018_set_integration_time(chip,
isl29018_int_utimes[chip->type][chip->int_time]);
if (status < 0) {
dev_err(chip->dev, "Init of isl29018 fails\n");
return status;
}
return 0;
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case ISL29018_REG_ADD_DATA_LSB:
case ISL29018_REG_ADD_DATA_MSB:
case ISL29018_REG_ADD_COMMAND1:
case ISL29018_REG_TEST:
case ISL29035_REG_DEVICE_ID:
return true;
default:
return false;
}
}
static const char *isl29018_match_acpi_device(struct device *dev, int *data)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
*data = (int) id->driver_data;
return dev_name(dev);
}
static int isl29018_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct isl29018_chip *chip;
struct iio_dev *indio_dev;
int err;
const char *name = NULL;
int dev_id = 0;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation fails\n");
return -ENOMEM;
}
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->dev = &client->dev;
if (id) {
name = id->name;
dev_id = id->driver_data;
}
if (ACPI_HANDLE(&client->dev))
name = isl29018_match_acpi_device(&client->dev, &dev_id);
mutex_init(&chip->lock);
chip->type = dev_id;
chip->calibscale = 1;
chip->ucalibscale = 0;
chip->int_time = ISL29018_INT_TIME_16;
chip->scale = isl29018_scales[chip->int_time][0];
chip->suspended = false;
chip->regmap = devm_regmap_init_i2c(client,
chip_info_tbl[dev_id].regmap_cfg);
if (IS_ERR(chip->regmap)) {
err = PTR_ERR(chip->regmap);
dev_err(chip->dev, "regmap initialization failed: %d\n", err);
return err;
}
err = isl29018_chip_init(chip);
if (err)
return err;
indio_dev->info = chip_info_tbl[dev_id].indio_info;
indio_dev->channels = chip_info_tbl[dev_id].channels;
indio_dev->num_channels = chip_info_tbl[dev_id].num_channels;
indio_dev->name = name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
err = devm_iio_device_register(&client->dev, indio_dev);
if (err) {
dev_err(&client->dev, "iio registration fails\n");
return err;
}
return 0;
}
static int isl29018_suspend(struct device *dev)
{
struct isl29018_chip *chip = iio_priv(dev_get_drvdata(dev));
mutex_lock(&chip->lock);
chip->suspended = true;
mutex_unlock(&chip->lock);
return 0;
}
static int isl29018_resume(struct device *dev)
{
struct isl29018_chip *chip = iio_priv(dev_get_drvdata(dev));
int err;
mutex_lock(&chip->lock);
err = isl29018_chip_init(chip);
if (!err)
chip->suspended = false;
mutex_unlock(&chip->lock);
return err;
}
