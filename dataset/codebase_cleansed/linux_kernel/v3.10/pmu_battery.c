static int pmu_get_ac_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = (!!(pmu_power_flags & PMU_PWR_AC_PRESENT)) ||
(pmu_battery_count == 0);
break;
default:
return -EINVAL;
}
return 0;
}
static char *pmu_bat_get_model_name(struct pmu_battery_info *pbi)
{
switch (pbi->flags & PMU_BATT_TYPE_MASK) {
case PMU_BATT_TYPE_SMART:
return pmu_batt_types[0];
case PMU_BATT_TYPE_COMET:
return pmu_batt_types[1];
case PMU_BATT_TYPE_HOOPER:
return pmu_batt_types[2];
default: break;
}
return pmu_batt_types[3];
}
static int pmu_bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pmu_battery_dev *pbat = to_pmu_battery_dev(psy);
struct pmu_battery_info *pbi = pbat->pbi;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (pbi->flags & PMU_BATT_CHARGING)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (pmu_power_flags & PMU_PWR_AC_PRESENT)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = !!(pbi->flags & PMU_BATT_PRESENT);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = pmu_bat_get_model_name(pbi);
break;
case POWER_SUPPLY_PROP_ENERGY_AVG:
val->intval = pbi->charge * 1000;
break;
case POWER_SUPPLY_PROP_ENERGY_FULL:
val->intval = pbi->max_charge * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
val->intval = pbi->amperage * 1000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
val->intval = pbi->voltage * 1000;
break;
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
val->intval = pbi->time_remaining;
break;
default:
return -EINVAL;
}
return 0;
}
static int __init pmu_bat_init(void)
{
int ret;
int i;
bat_pdev = platform_device_register_simple("pmu-battery",
0, NULL, 0);
if (IS_ERR(bat_pdev)) {
ret = PTR_ERR(bat_pdev);
goto pdev_register_failed;
}
ret = power_supply_register(&bat_pdev->dev, &pmu_ac);
if (ret)
goto ac_register_failed;
for (i = 0; i < pmu_battery_count; i++) {
struct pmu_battery_dev *pbat = kzalloc(sizeof(*pbat),
GFP_KERNEL);
if (!pbat)
break;
sprintf(pbat->name, "PMU_battery_%d", i);
pbat->bat.name = pbat->name;
pbat->bat.properties = pmu_bat_props;
pbat->bat.num_properties = ARRAY_SIZE(pmu_bat_props);
pbat->bat.get_property = pmu_bat_get_property;
pbat->pbi = &pmu_batteries[i];
ret = power_supply_register(&bat_pdev->dev, &pbat->bat);
if (ret) {
kfree(pbat);
goto battery_register_failed;
}
pbats[i] = pbat;
}
goto success;
battery_register_failed:
while (i--) {
if (!pbats[i])
continue;
power_supply_unregister(&pbats[i]->bat);
kfree(pbats[i]);
}
power_supply_unregister(&pmu_ac);
ac_register_failed:
platform_device_unregister(bat_pdev);
pdev_register_failed:
success:
return ret;
}
static void __exit pmu_bat_exit(void)
{
int i;
for (i = 0; i < PMU_MAX_BATTERIES; i++) {
if (!pbats[i])
continue;
power_supply_unregister(&pbats[i]->bat);
kfree(pbats[i]);
}
power_supply_unregister(&pmu_ac);
platform_device_unregister(bat_pdev);
}
