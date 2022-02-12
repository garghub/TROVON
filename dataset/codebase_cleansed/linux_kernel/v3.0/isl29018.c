static int isl29018_write_data(struct i2c_client *client, u8 reg,
u8 val, u8 mask, u8 shift)
{
u8 regval;
int ret = 0;
struct isl29018_chip *chip = i2c_get_clientdata(client);
regval = chip->reg_cache[reg];
regval &= ~mask;
regval |= val << shift;
ret = i2c_smbus_write_byte_data(client, reg, regval);
if (ret) {
dev_err(&client->dev, "Write to device fails status %x\n", ret);
return ret;
}
chip->reg_cache[reg] = regval;
return 0;
}
static int isl29018_set_range(struct i2c_client *client, unsigned long range,
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
return isl29018_write_data(client, ISL29018_REG_ADD_COMMANDII,
i, COMMANDII_RANGE_MASK, COMMANDII_RANGE_SHIFT);
}
static int isl29018_set_resolution(struct i2c_client *client,
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
return isl29018_write_data(client, ISL29018_REG_ADD_COMMANDII,
i, COMMANDII_RESOLUTION_MASK,
COMMANDII_RESOLUTION_SHIFT);
}
static int isl29018_read_sensor_input(struct i2c_client *client, int mode)
{
int status;
int lsb;
int msb;
status = isl29018_write_data(client, ISL29018_REG_ADD_COMMAND1,
mode, COMMMAND1_OPMODE_MASK, COMMMAND1_OPMODE_SHIFT);
if (status) {
dev_err(&client->dev, "Error in setting operating mode\n");
return status;
}
msleep(CONVERSION_TIME_MS);
lsb = i2c_smbus_read_byte_data(client, ISL29018_REG_ADD_DATA_LSB);
if (lsb < 0) {
dev_err(&client->dev, "Error in reading LSB DATA\n");
return lsb;
}
msb = i2c_smbus_read_byte_data(client, ISL29018_REG_ADD_DATA_MSB);
if (msb < 0) {
dev_err(&client->dev, "Error in reading MSB DATA\n");
return msb;
}
dev_vdbg(&client->dev, "MSB 0x%x and LSB 0x%x\n", msb, lsb);
return (msb << 8) | lsb;
}
static int isl29018_read_lux(struct i2c_client *client, int *lux)
{
int lux_data;
struct isl29018_chip *chip = i2c_get_clientdata(client);
lux_data = isl29018_read_sensor_input(client,
COMMMAND1_OPMODE_ALS_ONCE);
if (lux_data < 0)
return lux_data;
*lux = (lux_data * chip->range) >> chip->adc_bit;
return 0;
}
static int isl29018_read_ir(struct i2c_client *client, int *ir)
{
int ir_data;
ir_data = isl29018_read_sensor_input(client, COMMMAND1_OPMODE_IR_ONCE);
if (ir_data < 0)
return ir_data;
*ir = ir_data;
return 0;
}
static int isl29018_read_proximity_ir(struct i2c_client *client, int scheme,
int *near_ir)
{
int status;
int prox_data = -1;
int ir_data = -1;
status = isl29018_write_data(client, ISL29018_REG_ADD_COMMANDII,
scheme, COMMANDII_SCHEME_MASK, COMMANDII_SCHEME_SHIFT);
if (status) {
dev_err(&client->dev, "Error in setting operating mode\n");
return status;
}
prox_data = isl29018_read_sensor_input(client,
COMMMAND1_OPMODE_PROX_ONCE);
if (prox_data < 0)
return prox_data;
if (scheme == 1) {
*near_ir = prox_data;
return 0;
}
ir_data = isl29018_read_sensor_input(client,
COMMMAND1_OPMODE_IR_ONCE);
if (ir_data < 0)
return ir_data;
if (prox_data >= ir_data)
*near_ir = prox_data - ir_data;
else
*near_ir = 0;
return 0;
}
static ssize_t get_sensor_data(struct device *dev, char *buf, int mode)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
struct i2c_client *client = chip->client;
int value = 0;
int status;
mutex_lock(&chip->lock);
switch (mode) {
case COMMMAND1_OPMODE_PROX_ONCE:
status = isl29018_read_proximity_ir(client,
chip->prox_scheme, &value);
break;
case COMMMAND1_OPMODE_ALS_ONCE:
status = isl29018_read_lux(client, &value);
break;
case COMMMAND1_OPMODE_IR_ONCE:
status = isl29018_read_ir(client, &value);
break;
default:
dev_err(&client->dev, "Mode %d is not supported\n", mode);
mutex_unlock(&chip->lock);
return -EBUSY;
}
if (status < 0) {
dev_err(&client->dev, "Error in Reading data");
mutex_unlock(&chip->lock);
return status;
}
mutex_unlock(&chip->lock);
return sprintf(buf, "%d\n", value);
}
static ssize_t show_range(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
return sprintf(buf, "%u\n", chip->range);
}
static ssize_t store_range(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
struct i2c_client *client = chip->client;
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
status = isl29018_set_range(client, lval, &new_range);
if (status < 0) {
mutex_unlock(&chip->lock);
dev_err(dev, "Error in setting max range\n");
return status;
}
chip->range = new_range;
mutex_unlock(&chip->lock);
return count;
}
static ssize_t show_resolution(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
return sprintf(buf, "%u\n", chip->adc_bit);
}
static ssize_t store_resolution(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
struct i2c_client *client = chip->client;
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
status = isl29018_set_resolution(client, lval, &new_adc_bit);
if (status < 0) {
mutex_unlock(&chip->lock);
dev_err(dev, "Error in setting resolution\n");
return status;
}
chip->adc_bit = new_adc_bit;
mutex_unlock(&chip->lock);
return count;
}
static ssize_t show_prox_infrared_supression(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
return sprintf(buf, "%d\n", chip->prox_scheme);
}
static ssize_t store_prox_infrared_supression(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct isl29018_chip *chip = indio_dev->dev_data;
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
static ssize_t show_lux(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return get_sensor_data(dev, buf, COMMMAND1_OPMODE_ALS_ONCE);
}
static ssize_t show_ir(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return get_sensor_data(dev, buf, COMMMAND1_OPMODE_IR_ONCE);
}
static ssize_t show_proxim_ir(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return get_sensor_data(dev, buf, COMMMAND1_OPMODE_PROX_ONCE);
}
static int isl29018_chip_init(struct i2c_client *client)
{
struct isl29018_chip *chip = i2c_get_clientdata(client);
int status;
int new_adc_bit;
unsigned int new_range;
memset(chip->reg_cache, 0, sizeof(chip->reg_cache));
status = isl29018_set_range(client, chip->range, &new_range);
if (status < 0) {
dev_err(&client->dev, "Init of isl29018 fails\n");
return status;
}
status = isl29018_set_resolution(client, chip->adc_bit,
&new_adc_bit);
return 0;
}
static int __devinit isl29018_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct isl29018_chip *chip;
int err;
chip = kzalloc(sizeof(struct isl29018_chip), GFP_KERNEL);
if (!chip) {
dev_err(&client->dev, "Memory allocation fails\n");
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, chip);
chip->client = client;
mutex_init(&chip->lock);
chip->range = 1000;
chip->adc_bit = 16;
err = isl29018_chip_init(client);
if (err)
goto exit_free;
chip->indio_dev = iio_allocate_device(0);
if (!chip->indio_dev) {
dev_err(&client->dev, "iio allocation fails\n");
goto exit_free;
}
chip->indio_dev->info = &isl29108_info;
chip->indio_dev->name = id->name;
chip->indio_dev->dev.parent = &client->dev;
chip->indio_dev->dev_data = (void *)(chip);
chip->indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_device_register(chip->indio_dev);
if (err) {
dev_err(&client->dev, "iio registration fails\n");
goto exit_iio_free;
}
return 0;
exit_iio_free:
iio_free_device(chip->indio_dev);
exit_free:
kfree(chip);
exit:
return err;
}
static int __devexit isl29018_remove(struct i2c_client *client)
{
struct isl29018_chip *chip = i2c_get_clientdata(client);
dev_dbg(&client->dev, "%s()\n", __func__);
iio_device_unregister(chip->indio_dev);
kfree(chip);
return 0;
}
static int __init isl29018_init(void)
{
return i2c_add_driver(&isl29018_driver);
}
static void __exit isl29018_exit(void)
{
i2c_del_driver(&isl29018_driver);
}
