static int isl29018_set_range(struct isl29018_chip *chip, unsigned long range,
unsigned int *new_range)
{
static const unsigned long supp_ranges[] = {1000, 4000, 16000, 64000};
int i;
for (i = 0; i < ARRAY_SIZE(supp_ranges); ++i) {
if (range <= supp_ranges[i]) {
*new_range = (unsigned int)supp_ranges[i];
break;
}
}
if (i >= ARRAY_SIZE(supp_ranges))
return -EINVAL;
return regmap_update_bits(chip->regmap, ISL29018_REG_ADD_COMMANDII,
COMMANDII_RANGE_MASK, i << COMMANDII_RANGE_SHIFT);
}
static int isl29018_set_resolution(struct isl29018_chip *chip,
unsigned long adcbit, unsigned int *conf_adc_bit)
{
static const unsigned long supp_adcbit[] = {16, 12, 8, 4};
int i;
for (i = 0; i < ARRAY_SIZE(supp_adcbit); ++i) {
if (adcbit >= supp_adcbit[i]) {
*conf_adc_bit = (unsigned int)supp_adcbit[i];
break;
}
}
if (i >= ARRAY_SIZE(supp_adcbit))
return -EINVAL;
return regmap_update_bits(chip->regmap, ISL29018_REG_ADD_COMMANDII,
COMMANDII_RESOLUTION_MASK,
i << COMMANDII_RESOLUTION_SHIFT);
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
unsigned int data_x_range, lux_unshifted;
lux_data = isl29018_read_sensor_input(chip, COMMMAND1_OPMODE_ALS_ONCE);
if (lux_data < 0)
return lux_data;
data_x_range = lux_data * chip->range;
lux_unshifted = data_x_range * chip->lux_scale;
lux_unshifted += data_x_range / 1000 * chip->lux_uscale / 1000;
*lux = lux_unshifted >> chip->adc_bit;
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
static ssize_t show_range(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
return sprintf(buf, "%u\n", chip->range);
}
static ssize_t store_range(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
int status;
unsigned long lval;
unsigned int new_range;
if (strict_strtoul(buf, 10, &lval))
return -EINVAL;
if (!(lval == 1000UL || lval == 4000UL ||
lval == 16000UL || lval == 64000UL)) {
dev_err(dev, "The range is not supported\n");
return -EINVAL;
}
mutex_lock(&chip->lock);
status = isl29018_set_range(chip, lval, &new_range);
if (status < 0) {
mutex_unlock(&chip->lock);
dev_err(dev,
"Error in setting max range with err %d\n", status);
return status;
}
chip->range = new_range;
mutex_unlock(&chip->lock);
return count;
}
static ssize_t show_resolution(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
return sprintf(buf, "%u\n", chip->adc_bit);
}
static ssize_t store_resolution(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct isl29018_chip *chip = iio_priv(indio_dev);
int status;
unsigned long lval;
unsigned int new_adc_bit;
if (strict_strtoul(buf, 10, &lval))
return -EINVAL;
if (!(lval == 4 || lval == 8 || lval == 12 || lval == 16)) {
dev_err(dev, "The resolution is not supported\n");
return -EINVAL;
}
mutex_lock(&chip->lock);
status = isl29018_set_resolution(chip, lval, &new_adc_bit);
if (status < 0) {
mutex_unlock(&chip->lock);
dev_err(dev, "Error in setting resolution\n");
return status;
}
chip->adc_bit = new_adc_bit;
mutex_unlock(&chip->lock);
return count;
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
unsigned long lval;
if (strict_strtoul(buf, 10, &lval))
return -EINVAL;
if (!(lval == 0UL || lval == 1UL)) {
dev_err(dev, "The mode is not supported\n");
return -EINVAL;
}
mutex_lock(&chip->lock);
chip->prox_scheme = (int)lval;
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
if (mask == IIO_CHAN_INFO_CALIBSCALE && chan->type == IIO_LIGHT) {
chip->lux_scale = val;
chip->lux_uscale = val2;
ret = 0;
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
case IIO_CHAN_INFO_CALIBSCALE:
if (chan->type == IIO_LIGHT) {
*val = chip->lux_scale;
*val2 = chip->lux_uscale;
ret = IIO_VAL_INT_PLUS_MICRO;
}
break;
default:
break;
}
mutex_unlock(&chip->lock);
return ret;
}
static int isl29018_chip_init(struct isl29018_chip *chip)
{
int status;
int new_adc_bit;
unsigned int new_range;
status = regmap_write(chip->regmap, ISL29018_REG_TEST, 0x0);
if (status < 0) {
dev_err(chip->dev, "Failed to clear isl29018 TEST reg."
"(%d)\n", status);
return status;
}
status = regmap_write(chip->regmap, ISL29018_REG_ADD_COMMAND1, 0);
if (status < 0) {
dev_err(chip->dev, "Failed to clear isl29018 CMD1 reg."
"(%d)\n", status);
return status;
}
msleep(1);
status = isl29018_set_range(chip, chip->range, &new_range);
if (status < 0) {
dev_err(chip->dev, "Init of isl29018 fails\n");
return status;
}
status = isl29018_set_resolution(chip, chip->adc_bit,
&new_adc_bit);
return 0;
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case ISL29018_REG_ADD_DATA_LSB:
case ISL29018_REG_ADD_DATA_MSB:
case ISL29018_REG_ADD_COMMAND1:
case ISL29018_REG_TEST:
return true;
default:
return false;
}
}
static int isl29018_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct isl29018_chip *chip;
struct iio_dev *indio_dev;
int err;
indio_dev = iio_device_alloc(sizeof(*chip));
if (indio_dev == NULL) {
dev_err(&client->dev, "iio allocation fails\n");
err = -ENOMEM;
goto exit;
}
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->dev = &client->dev;
mutex_init(&chip->lock);
chip->lux_scale = 1;
chip->range = 1000;
chip->adc_bit = 16;
chip->suspended = false;
chip->regmap = devm_regmap_init_i2c(client, &isl29018_regmap_config);
if (IS_ERR(chip->regmap)) {
err = PTR_ERR(chip->regmap);
dev_err(chip->dev, "regmap initialization failed: %d\n", err);
goto exit;
}
err = isl29018_chip_init(chip);
if (err)
goto exit_iio_free;
indio_dev->info = &isl29108_info;
indio_dev->channels = isl29018_channels;
indio_dev->num_channels = ARRAY_SIZE(isl29018_channels);
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(indio_dev);
if (err) {
dev_err(&client->dev, "iio registration fails\n");
goto exit_iio_free;
}
return 0;
exit_iio_free:
iio_device_free(indio_dev);
exit:
return err;
}
static int isl29018_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "%s()\n", __func__);
iio_device_unregister(indio_dev);
iio_device_free(indio_dev);
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
