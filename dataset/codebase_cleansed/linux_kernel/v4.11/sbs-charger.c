static int sbs_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct sbs_info *chip = power_supply_get_drvdata(psy);
unsigned int reg;
reg = chip->last_state;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = !!(reg & SBS_CHARGER_STATUS_BATTERY_PRESENT);
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = !!(reg & SBS_CHARGER_STATUS_AC_PRESENT);
break;
case POWER_SUPPLY_PROP_STATUS:
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
if (!(reg & SBS_CHARGER_STATUS_BATTERY_PRESENT))
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (reg & SBS_CHARGER_STATUS_AC_PRESENT &&
!(reg & SBS_CHARGER_STATUS_CHARGE_INHIBITED))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_HEALTH:
if (reg & SBS_CHARGER_STATUS_RES_COLD)
val->intval = POWER_SUPPLY_HEALTH_COLD;
if (reg & SBS_CHARGER_STATUS_RES_HOT)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
default:
return -EINVAL;
}
return 0;
}
static int sbs_check_state(struct sbs_info *chip)
{
unsigned int reg;
int ret;
ret = regmap_read(chip->regmap, SBS_CHARGER_REG_STATUS, &reg);
if (!ret && reg != chip->last_state) {
chip->last_state = reg;
power_supply_changed(chip->power_supply);
return 1;
}
return 0;
}
static void sbs_delayed_work(struct work_struct *work)
{
struct sbs_info *chip = container_of(work, struct sbs_info, work.work);
sbs_check_state(chip);
schedule_delayed_work(&chip->work,
msecs_to_jiffies(SBS_CHARGER_POLL_TIME));
}
static irqreturn_t sbs_irq_thread(int irq, void *data)
{
struct sbs_info *chip = data;
int ret;
ret = sbs_check_state(chip);
return ret ? IRQ_HANDLED : IRQ_NONE;
}
static bool sbs_readable_reg(struct device *dev, unsigned int reg)
{
if (reg < SBS_CHARGER_REG_SPEC_INFO)
return false;
else
return true;
}
static bool sbs_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SBS_CHARGER_REG_STATUS:
return true;
}
return false;
}
static int sbs_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct power_supply_config psy_cfg = {};
struct sbs_info *chip;
int ret, val;
chip = devm_kzalloc(&client->dev, sizeof(struct sbs_info), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
psy_cfg.of_node = client->dev.of_node;
psy_cfg.drv_data = chip;
i2c_set_clientdata(client, chip);
chip->regmap = devm_regmap_init_i2c(client, &sbs_regmap);
if (IS_ERR(chip->regmap))
return PTR_ERR(chip->regmap);
ret = regmap_read(chip->regmap, SBS_CHARGER_REG_STATUS, &val);
if (ret) {
dev_err(&client->dev, "Failed to get device status\n");
return ret;
}
chip->last_state = val;
chip->power_supply = devm_power_supply_register(&client->dev, &sbs_desc,
&psy_cfg);
if (IS_ERR(chip->power_supply)) {
dev_err(&client->dev, "Failed to register power supply\n");
return PTR_ERR(chip->power_supply);
}
if (client->irq) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, sbs_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(&client->dev), chip);
if (ret) {
dev_err(&client->dev, "Failed to request irq, %d\n", ret);
return ret;
}
} else {
INIT_DELAYED_WORK(&chip->work, sbs_delayed_work);
schedule_delayed_work(&chip->work,
msecs_to_jiffies(SBS_CHARGER_POLL_TIME));
}
dev_info(&client->dev,
"%s: smart charger device registered\n", client->name);
return 0;
}
static int sbs_remove(struct i2c_client *client)
{
struct sbs_info *chip = i2c_get_clientdata(client);
cancel_delayed_work_sync(&chip->work);
return 0;
}
