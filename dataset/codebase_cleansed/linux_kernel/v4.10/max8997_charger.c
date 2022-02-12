static int max8997_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct charger_data *charger = power_supply_get_drvdata(psy);
struct i2c_client *i2c = charger->iodev->i2c;
int ret;
u8 reg;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = 0;
ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
if (ret)
return ret;
if ((reg & (1 << 0)) == 0x1)
val->intval = POWER_SUPPLY_STATUS_FULL;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = 0;
ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
if (ret)
return ret;
if ((reg & (1 << 2)) == 0x0)
val->intval = 1;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = 0;
ret = max8997_read_reg(i2c, MAX8997_REG_STATUS4, &reg);
if (ret)
return ret;
if (reg & (1 << 1))
val->intval = 1;
break;
default:
return -EINVAL;
}
return 0;
}
static int max8997_battery_probe(struct platform_device *pdev)
{
int ret = 0;
struct charger_data *charger;
struct max8997_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max8997_platform_data *pdata = dev_get_platdata(iodev->dev);
struct power_supply_config psy_cfg = {};
if (!pdata)
return -EINVAL;
if (pdata->eoc_mA) {
int val = (pdata->eoc_mA - 50) / 10;
if (val < 0)
val = 0;
if (val > 0xf)
val = 0xf;
ret = max8997_update_reg(iodev->i2c,
MAX8997_REG_MBCCTRL5, val, 0xf);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot use i2c bus.\n");
return ret;
}
}
switch (pdata->timeout) {
case 5:
ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
0x2 << 4, 0x7 << 4);
break;
case 6:
ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
0x3 << 4, 0x7 << 4);
break;
case 7:
ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
0x4 << 4, 0x7 << 4);
break;
case 0:
ret = max8997_update_reg(iodev->i2c, MAX8997_REG_MBCCTRL1,
0x7 << 4, 0x7 << 4);
break;
default:
dev_err(&pdev->dev, "incorrect timeout value (%d)\n",
pdata->timeout);
return -EINVAL;
}
if (ret < 0) {
dev_err(&pdev->dev, "Cannot use i2c bus.\n");
return ret;
}
charger = devm_kzalloc(&pdev->dev, sizeof(struct charger_data),
GFP_KERNEL);
if (charger == NULL) {
dev_err(&pdev->dev, "Cannot allocate memory.\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, charger);
charger->dev = &pdev->dev;
charger->iodev = iodev;
psy_cfg.drv_data = charger;
charger->battery = power_supply_register(&pdev->dev,
&max8997_battery_desc,
&psy_cfg);
if (IS_ERR(charger->battery)) {
dev_err(&pdev->dev, "failed: power supply register\n");
return PTR_ERR(charger->battery);
}
return 0;
}
static int max8997_battery_remove(struct platform_device *pdev)
{
struct charger_data *charger = platform_get_drvdata(pdev);
power_supply_unregister(charger->battery);
return 0;
}
static int __init max8997_battery_init(void)
{
return platform_driver_register(&max8997_battery_driver);
}
static void __exit max8997_battery_cleanup(void)
{
platform_driver_unregister(&max8997_battery_driver);
}
