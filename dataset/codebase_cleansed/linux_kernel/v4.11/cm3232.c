static int cm3232_reg_init(struct cm3232_chip *chip)
{
struct i2c_client *client = chip->client;
s32 ret;
chip->als_info = &cm3232_als_info_default;
ret = i2c_smbus_read_word_data(client, CM3232_REG_ADDR_ID);
if (ret < 0) {
dev_err(&chip->client->dev, "Error reading addr_id\n");
return ret;
}
if ((ret & 0xFF) != chip->als_info->hw_id)
return -ENODEV;
chip->regs_cmd = CM3232_CMD_ALS_DISABLE | CM3232_CMD_ALS_RESET;
ret = i2c_smbus_write_byte_data(client, CM3232_REG_ADDR_CMD,
chip->regs_cmd);
if (ret < 0) {
dev_err(&chip->client->dev, "Error writing reg_cmd\n");
return ret;
}
chip->regs_cmd = chip->als_info->regs_cmd_default;
ret = i2c_smbus_write_byte_data(client, CM3232_REG_ADDR_CMD,
chip->regs_cmd);
if (ret < 0)
dev_err(&chip->client->dev, "Error writing reg_cmd\n");
return ret;
}
static int cm3232_read_als_it(struct cm3232_chip *chip, int *val, int *val2)
{
u16 als_it;
int i;
als_it = chip->regs_cmd;
als_it &= CM3232_CMD_ALS_IT_MASK;
als_it >>= CM3232_CMD_ALS_IT_SHIFT;
for (i = 0; i < ARRAY_SIZE(cm3232_als_it_scales); i++) {
if (als_it == cm3232_als_it_scales[i].it) {
*val = cm3232_als_it_scales[i].val;
*val2 = cm3232_als_it_scales[i].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int cm3232_write_als_it(struct cm3232_chip *chip, int val, int val2)
{
struct i2c_client *client = chip->client;
u16 als_it, cmd;
int i;
s32 ret;
for (i = 0; i < ARRAY_SIZE(cm3232_als_it_scales); i++) {
if (val == cm3232_als_it_scales[i].val &&
val2 == cm3232_als_it_scales[i].val2) {
als_it = cm3232_als_it_scales[i].it;
als_it <<= CM3232_CMD_ALS_IT_SHIFT;
cmd = chip->regs_cmd & ~CM3232_CMD_ALS_IT_MASK;
cmd |= als_it;
ret = i2c_smbus_write_byte_data(client,
CM3232_REG_ADDR_CMD,
cmd);
if (ret < 0)
return ret;
chip->regs_cmd = cmd;
return 0;
}
}
return -EINVAL;
}
static int cm3232_get_lux(struct cm3232_chip *chip)
{
struct i2c_client *client = chip->client;
struct cm3232_als_info *als_info = chip->als_info;
int ret;
int val, val2;
int als_it;
u64 lux;
ret = cm3232_read_als_it(chip, &val, &val2);
if (ret < 0)
return -EINVAL;
als_it = val * 1000000 + val2;
lux = (__force u64)als_info->mlux_per_bit;
lux *= als_info->mlux_per_bit_base_it;
lux = div_u64(lux, als_it);
ret = i2c_smbus_read_word_data(client, CM3232_REG_ADDR_ALS);
if (ret < 0) {
dev_err(&client->dev, "Error reading reg_addr_als\n");
return ret;
}
chip->regs_als = (u16)ret;
lux *= chip->regs_als;
lux *= als_info->calibscale;
lux = div_u64(lux, CM3232_CALIBSCALE_RESOLUTION);
lux = div_u64(lux, CM3232_MLUX_PER_LUX);
if (lux > 0xFFFF)
lux = 0xFFFF;
return (int)lux;
}
static int cm3232_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cm3232_chip *chip = iio_priv(indio_dev);
struct cm3232_als_info *als_info = chip->als_info;
int ret;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ret = cm3232_get_lux(chip);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
*val = als_info->calibscale;
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
return cm3232_read_als_it(chip, val, val2);
}
return -EINVAL;
}
static int cm3232_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct cm3232_chip *chip = iio_priv(indio_dev);
struct cm3232_als_info *als_info = chip->als_info;
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
als_info->calibscale = val;
return 0;
case IIO_CHAN_INFO_INT_TIME:
return cm3232_write_als_it(chip, val, val2);
}
return -EINVAL;
}
static ssize_t cm3232_get_it_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i, len;
for (i = 0, len = 0; i < ARRAY_SIZE(cm3232_als_it_scales); i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "%u.%06u ",
cm3232_als_it_scales[i].val,
cm3232_als_it_scales[i].val2);
return len + scnprintf(buf + len, PAGE_SIZE - len, "\n");
}
static int cm3232_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cm3232_chip *chip;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = cm3232_channels;
indio_dev->num_channels = ARRAY_SIZE(cm3232_channels);
indio_dev->info = &cm3232_info;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = cm3232_reg_init(chip);
if (ret) {
dev_err(&client->dev,
"%s: register init failed\n",
__func__);
return ret;
}
return iio_device_register(indio_dev);
}
static int cm3232_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
i2c_smbus_write_byte_data(client, CM3232_REG_ADDR_CMD,
CM3232_CMD_ALS_DISABLE);
iio_device_unregister(indio_dev);
return 0;
}
static int cm3232_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct cm3232_chip *chip = iio_priv(indio_dev);
struct i2c_client *client = chip->client;
int ret;
chip->regs_cmd |= CM3232_CMD_ALS_DISABLE;
ret = i2c_smbus_write_byte_data(client, CM3232_REG_ADDR_CMD,
chip->regs_cmd);
return ret;
}
static int cm3232_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct cm3232_chip *chip = iio_priv(indio_dev);
struct i2c_client *client = chip->client;
int ret;
chip->regs_cmd &= ~CM3232_CMD_ALS_DISABLE;
ret = i2c_smbus_write_byte_data(client, CM3232_REG_ADDR_CMD,
chip->regs_cmd | CM3232_CMD_ALS_RESET);
return ret;
}
