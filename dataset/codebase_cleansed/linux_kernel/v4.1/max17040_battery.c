static int max17040_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max17040_chip *chip = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = chip->status;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = chip->online;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = chip->vcell;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = chip->soc;
break;
default:
return -EINVAL;
}
return 0;
}
static int max17040_write_reg(struct i2c_client *client, int reg, u8 value)
{
int ret;
ret = i2c_smbus_write_byte_data(client, reg, value);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static int max17040_read_reg(struct i2c_client *client, int reg)
{
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static void max17040_reset(struct i2c_client *client)
{
max17040_write_reg(client, MAX17040_CMD_MSB, 0x54);
max17040_write_reg(client, MAX17040_CMD_LSB, 0x00);
}
static void max17040_get_vcell(struct i2c_client *client)
{
struct max17040_chip *chip = i2c_get_clientdata(client);
u8 msb;
u8 lsb;
msb = max17040_read_reg(client, MAX17040_VCELL_MSB);
lsb = max17040_read_reg(client, MAX17040_VCELL_LSB);
chip->vcell = (msb << 4) + (lsb >> 4);
}
static void max17040_get_soc(struct i2c_client *client)
{
struct max17040_chip *chip = i2c_get_clientdata(client);
u8 msb;
u8 lsb;
msb = max17040_read_reg(client, MAX17040_SOC_MSB);
lsb = max17040_read_reg(client, MAX17040_SOC_LSB);
chip->soc = msb;
}
static void max17040_get_version(struct i2c_client *client)
{
u8 msb;
u8 lsb;
msb = max17040_read_reg(client, MAX17040_VER_MSB);
lsb = max17040_read_reg(client, MAX17040_VER_LSB);
dev_info(&client->dev, "MAX17040 Fuel-Gauge Ver %d%d\n", msb, lsb);
}
static void max17040_get_online(struct i2c_client *client)
{
struct max17040_chip *chip = i2c_get_clientdata(client);
if (chip->pdata && chip->pdata->battery_online)
chip->online = chip->pdata->battery_online();
else
chip->online = 1;
}
static void max17040_get_status(struct i2c_client *client)
{
struct max17040_chip *chip = i2c_get_clientdata(client);
if (!chip->pdata || !chip->pdata->charger_online
|| !chip->pdata->charger_enable) {
chip->status = POWER_SUPPLY_STATUS_UNKNOWN;
return;
}
if (chip->pdata->charger_online()) {
if (chip->pdata->charger_enable())
chip->status = POWER_SUPPLY_STATUS_CHARGING;
else
chip->status = POWER_SUPPLY_STATUS_NOT_CHARGING;
} else {
chip->status = POWER_SUPPLY_STATUS_DISCHARGING;
}
if (chip->soc > MAX17040_BATTERY_FULL)
chip->status = POWER_SUPPLY_STATUS_FULL;
}
static void max17040_work(struct work_struct *work)
{
struct max17040_chip *chip;
chip = container_of(work, struct max17040_chip, work.work);
max17040_get_vcell(chip->client);
max17040_get_soc(chip->client);
max17040_get_online(chip->client);
max17040_get_status(chip->client);
queue_delayed_work(system_power_efficient_wq, &chip->work,
MAX17040_DELAY);
}
static int max17040_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct power_supply_config psy_cfg = {};
struct max17040_chip *chip;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
return -EIO;
chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
chip->pdata = client->dev.platform_data;
i2c_set_clientdata(client, chip);
psy_cfg.drv_data = chip;
chip->battery = power_supply_register(&client->dev,
&max17040_battery_desc, &psy_cfg);
if (IS_ERR(chip->battery)) {
dev_err(&client->dev, "failed: power supply register\n");
return PTR_ERR(chip->battery);
}
max17040_reset(client);
max17040_get_version(client);
INIT_DEFERRABLE_WORK(&chip->work, max17040_work);
queue_delayed_work(system_power_efficient_wq, &chip->work,
MAX17040_DELAY);
return 0;
}
static int max17040_remove(struct i2c_client *client)
{
struct max17040_chip *chip = i2c_get_clientdata(client);
power_supply_unregister(chip->battery);
cancel_delayed_work(&chip->work);
return 0;
}
static int max17040_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max17040_chip *chip = i2c_get_clientdata(client);
cancel_delayed_work(&chip->work);
return 0;
}
static int max17040_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max17040_chip *chip = i2c_get_clientdata(client);
queue_delayed_work(system_power_efficient_wq, &chip->work,
MAX17040_DELAY);
return 0;
}
