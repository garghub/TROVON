static int ad5398_calc_current(struct ad5398_chip_info *chip,
unsigned selector)
{
unsigned range_uA = chip->max_uA - chip->min_uA;
return chip->min_uA + (selector * range_uA / chip->current_level);
}
static int ad5398_read_reg(struct i2c_client *client, unsigned short *data)
{
unsigned short val;
int ret;
ret = i2c_master_recv(client, (char *)&val, 2);
if (ret < 0) {
dev_err(&client->dev, "I2C read error\n");
return ret;
}
*data = be16_to_cpu(val);
return ret;
}
static int ad5398_write_reg(struct i2c_client *client, const unsigned short data)
{
unsigned short val;
int ret;
val = cpu_to_be16(data);
ret = i2c_master_send(client, (char *)&val, 2);
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static int ad5398_get_current_limit(struct regulator_dev *rdev)
{
struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
struct i2c_client *client = chip->client;
unsigned short data;
int ret;
ret = ad5398_read_reg(client, &data);
if (ret < 0)
return ret;
ret = (data & chip->current_mask) >> chip->current_offset;
return ad5398_calc_current(chip, ret);
}
static int ad5398_set_current_limit(struct regulator_dev *rdev, int min_uA, int max_uA)
{
struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
struct i2c_client *client = chip->client;
unsigned range_uA = chip->max_uA - chip->min_uA;
unsigned selector;
unsigned short data;
int ret;
if (min_uA > chip->max_uA || min_uA < chip->min_uA)
return -EINVAL;
if (max_uA > chip->max_uA || max_uA < chip->min_uA)
return -EINVAL;
selector = ((min_uA - chip->min_uA) * chip->current_level +
range_uA - 1) / range_uA;
if (ad5398_calc_current(chip, selector) > max_uA)
return -EINVAL;
dev_dbg(&client->dev, "changing current %dmA\n",
ad5398_calc_current(chip, selector) / 1000);
ret = ad5398_read_reg(client, &data);
if (ret < 0)
return ret;
selector = (selector << chip->current_offset) & chip->current_mask;
data = (unsigned short)selector | (data & AD5398_CURRENT_EN_MASK);
ret = ad5398_write_reg(client, data);
return ret;
}
static int ad5398_is_enabled(struct regulator_dev *rdev)
{
struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
struct i2c_client *client = chip->client;
unsigned short data;
int ret;
ret = ad5398_read_reg(client, &data);
if (ret < 0)
return ret;
if (data & AD5398_CURRENT_EN_MASK)
return 1;
else
return 0;
}
static int ad5398_enable(struct regulator_dev *rdev)
{
struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
struct i2c_client *client = chip->client;
unsigned short data;
int ret;
ret = ad5398_read_reg(client, &data);
if (ret < 0)
return ret;
if (data & AD5398_CURRENT_EN_MASK)
return 0;
data |= AD5398_CURRENT_EN_MASK;
ret = ad5398_write_reg(client, data);
return ret;
}
static int ad5398_disable(struct regulator_dev *rdev)
{
struct ad5398_chip_info *chip = rdev_get_drvdata(rdev);
struct i2c_client *client = chip->client;
unsigned short data;
int ret;
ret = ad5398_read_reg(client, &data);
if (ret < 0)
return ret;
if (!(data & AD5398_CURRENT_EN_MASK))
return 0;
data &= ~AD5398_CURRENT_EN_MASK;
ret = ad5398_write_reg(client, data);
return ret;
}
static int __devinit ad5398_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regulator_init_data *init_data = client->dev.platform_data;
struct ad5398_chip_info *chip;
const struct ad5398_current_data_format *df =
(struct ad5398_current_data_format *)id->driver_data;
int ret;
if (!init_data)
return -EINVAL;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
chip->min_uA = df->min_uA;
chip->max_uA = df->max_uA;
chip->current_level = 1 << df->current_bits;
chip->current_offset = df->current_offset;
chip->current_mask = (chip->current_level - 1) << chip->current_offset;
chip->rdev = regulator_register(&ad5398_reg, &client->dev,
init_data, chip);
if (IS_ERR(chip->rdev)) {
ret = PTR_ERR(chip->rdev);
dev_err(&client->dev, "failed to register %s %s\n",
id->name, ad5398_reg.name);
goto err;
}
i2c_set_clientdata(client, chip);
dev_dbg(&client->dev, "%s regulator driver is registered.\n", id->name);
return 0;
err:
kfree(chip);
return ret;
}
static int __devexit ad5398_remove(struct i2c_client *client)
{
struct ad5398_chip_info *chip = i2c_get_clientdata(client);
regulator_unregister(chip->rdev);
kfree(chip);
return 0;
}
static int __init ad5398_init(void)
{
return i2c_add_driver(&ad5398_driver);
}
static void __exit ad5398_exit(void)
{
i2c_del_driver(&ad5398_driver);
}
