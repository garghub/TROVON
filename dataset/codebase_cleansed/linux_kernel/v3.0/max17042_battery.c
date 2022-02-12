static int max17042_write_reg(struct i2c_client *client, u8 reg, u16 value)
{
int ret = i2c_smbus_write_word_data(client, reg, value);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static int max17042_read_reg(struct i2c_client *client, u8 reg)
{
int ret = i2c_smbus_read_word_data(client, reg);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static int max17042_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max17042_chip *chip = container_of(psy,
struct max17042_chip, battery);
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = max17042_read_reg(chip->client,
MAX17042_VCELL) * 83;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
val->intval = max17042_read_reg(chip->client,
MAX17042_AvgVCELL) * 83;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = max17042_read_reg(chip->client,
MAX17042_SOC) / 256;
break;
default:
return -EINVAL;
}
return 0;
}
static int __devinit max17042_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct max17042_chip *chip;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EIO;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
chip->pdata = client->dev.platform_data;
i2c_set_clientdata(client, chip);
chip->battery.name = "max17042_battery";
chip->battery.type = POWER_SUPPLY_TYPE_BATTERY;
chip->battery.get_property = max17042_get_property;
chip->battery.properties = max17042_battery_props;
chip->battery.num_properties = ARRAY_SIZE(max17042_battery_props);
ret = power_supply_register(&client->dev, &chip->battery);
if (ret) {
dev_err(&client->dev, "failed: power supply register\n");
i2c_set_clientdata(client, NULL);
kfree(chip);
return ret;
}
if (!chip->pdata->enable_current_sense) {
max17042_write_reg(client, MAX17042_CGAIN, 0x0000);
max17042_write_reg(client, MAX17042_MiscCFG, 0x0003);
max17042_write_reg(client, MAX17042_LearnCFG, 0x0007);
}
return 0;
}
static int __devexit max17042_remove(struct i2c_client *client)
{
struct max17042_chip *chip = i2c_get_clientdata(client);
power_supply_unregister(&chip->battery);
i2c_set_clientdata(client, NULL);
kfree(chip);
return 0;
}
static int __init max17042_init(void)
{
return i2c_add_driver(&max17042_i2c_driver);
}
static void __exit max17042_exit(void)
{
i2c_del_driver(&max17042_i2c_driver);
}
