static int __power_supply_changed_work(struct device *dev, void *data)
{
struct power_supply *psy = (struct power_supply *)data;
struct power_supply *pst = dev_get_drvdata(dev);
int i;
for (i = 0; i < psy->num_supplicants; i++)
if (!strcmp(psy->supplied_to[i], pst->name)) {
if (pst->external_power_changed)
pst->external_power_changed(pst);
}
return 0;
}
static void power_supply_changed_work(struct work_struct *work)
{
struct power_supply *psy = container_of(work, struct power_supply,
changed_work);
dev_dbg(psy->dev, "%s\n", __func__);
class_for_each_device(power_supply_class, NULL, psy,
__power_supply_changed_work);
power_supply_update_leds(psy);
kobject_uevent(&psy->dev->kobj, KOBJ_CHANGE);
}
void power_supply_changed(struct power_supply *psy)
{
dev_dbg(psy->dev, "%s\n", __func__);
schedule_work(&psy->changed_work);
}
static int __power_supply_am_i_supplied(struct device *dev, void *data)
{
union power_supply_propval ret = {0,};
struct power_supply *psy = (struct power_supply *)data;
struct power_supply *epsy = dev_get_drvdata(dev);
int i;
for (i = 0; i < epsy->num_supplicants; i++) {
if (!strcmp(epsy->supplied_to[i], psy->name)) {
if (epsy->get_property(epsy,
POWER_SUPPLY_PROP_ONLINE, &ret))
continue;
if (ret.intval)
return ret.intval;
}
}
return 0;
}
int power_supply_am_i_supplied(struct power_supply *psy)
{
int error;
error = class_for_each_device(power_supply_class, NULL, psy,
__power_supply_am_i_supplied);
dev_dbg(psy->dev, "%s %d\n", __func__, error);
return error;
}
static int __power_supply_is_system_supplied(struct device *dev, void *data)
{
union power_supply_propval ret = {0,};
struct power_supply *psy = dev_get_drvdata(dev);
unsigned int *count = data;
(*count)++;
if (psy->type != POWER_SUPPLY_TYPE_BATTERY) {
if (psy->get_property(psy, POWER_SUPPLY_PROP_ONLINE, &ret))
return 0;
if (ret.intval)
return ret.intval;
}
return 0;
}
int power_supply_is_system_supplied(void)
{
int error;
unsigned int count = 0;
error = class_for_each_device(power_supply_class, NULL, &count,
__power_supply_is_system_supplied);
if (count == 0)
return 1;
return error;
}
int power_supply_set_battery_charged(struct power_supply *psy)
{
if (psy->type == POWER_SUPPLY_TYPE_BATTERY && psy->set_charged) {
psy->set_charged(psy);
return 0;
}
return -EINVAL;
}
static int power_supply_match_device_by_name(struct device *dev, void *data)
{
const char *name = data;
struct power_supply *psy = dev_get_drvdata(dev);
return strcmp(psy->name, name) == 0;
}
struct power_supply *power_supply_get_by_name(char *name)
{
struct device *dev = class_find_device(power_supply_class, NULL, name,
power_supply_match_device_by_name);
return dev ? dev_get_drvdata(dev) : NULL;
}
int power_supply_powers(struct power_supply *psy, struct device *dev)
{
return sysfs_create_link(&psy->dev->kobj, &dev->kobj, "powers");
}
static void power_supply_dev_release(struct device *dev)
{
pr_debug("device: '%s': %s\n", dev_name(dev), __func__);
kfree(dev);
}
static int power_supply_read_temp(struct thermal_zone_device *tzd,
unsigned long *temp)
{
struct power_supply *psy;
union power_supply_propval val;
int ret;
WARN_ON(tzd == NULL);
psy = tzd->devdata;
ret = psy->get_property(psy, POWER_SUPPLY_PROP_TEMP, &val);
if (!ret)
*temp = val.intval * 100;
return ret;
}
static int psy_register_thermal(struct power_supply *psy)
{
int i;
for (i = 0; i < psy->num_properties; i++) {
if (psy->properties[i] == POWER_SUPPLY_PROP_TEMP) {
psy->tzd = thermal_zone_device_register(psy->name, 0, 0,
psy, &psy_tzd_ops, NULL, 0, 0);
if (IS_ERR(psy->tzd))
return PTR_ERR(psy->tzd);
break;
}
}
return 0;
}
static void psy_unregister_thermal(struct power_supply *psy)
{
if (IS_ERR_OR_NULL(psy->tzd))
return;
thermal_zone_device_unregister(psy->tzd);
}
static int ps_get_max_charge_cntl_limit(struct thermal_cooling_device *tcd,
unsigned long *state)
{
struct power_supply *psy;
union power_supply_propval val;
int ret;
psy = tcd->devdata;
ret = psy->get_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX, &val);
if (!ret)
*state = val.intval;
return ret;
}
static int ps_get_cur_chrage_cntl_limit(struct thermal_cooling_device *tcd,
unsigned long *state)
{
struct power_supply *psy;
union power_supply_propval val;
int ret;
psy = tcd->devdata;
ret = psy->get_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT, &val);
if (!ret)
*state = val.intval;
return ret;
}
static int ps_set_cur_charge_cntl_limit(struct thermal_cooling_device *tcd,
unsigned long state)
{
struct power_supply *psy;
union power_supply_propval val;
int ret;
psy = tcd->devdata;
val.intval = state;
ret = psy->set_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT, &val);
return ret;
}
static int psy_register_cooler(struct power_supply *psy)
{
int i;
for (i = 0; i < psy->num_properties; i++) {
if (psy->properties[i] ==
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT) {
psy->tcd = thermal_cooling_device_register(
(char *)psy->name,
psy, &psy_tcd_ops);
if (IS_ERR(psy->tcd))
return PTR_ERR(psy->tcd);
break;
}
}
return 0;
}
static void psy_unregister_cooler(struct power_supply *psy)
{
if (IS_ERR_OR_NULL(psy->tcd))
return;
thermal_cooling_device_unregister(psy->tcd);
}
static int psy_register_thermal(struct power_supply *psy)
{
return 0;
}
static void psy_unregister_thermal(struct power_supply *psy)
{
}
static int psy_register_cooler(struct power_supply *psy)
{
return 0;
}
static void psy_unregister_cooler(struct power_supply *psy)
{
}
int power_supply_register(struct device *parent, struct power_supply *psy)
{
struct device *dev;
int rc;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
device_initialize(dev);
dev->class = power_supply_class;
dev->type = &power_supply_dev_type;
dev->parent = parent;
dev->release = power_supply_dev_release;
dev_set_drvdata(dev, psy);
psy->dev = dev;
INIT_WORK(&psy->changed_work, power_supply_changed_work);
rc = kobject_set_name(&dev->kobj, "%s", psy->name);
if (rc)
goto kobject_set_name_failed;
rc = device_add(dev);
if (rc)
goto device_add_failed;
rc = psy_register_thermal(psy);
if (rc)
goto register_thermal_failed;
rc = psy_register_cooler(psy);
if (rc)
goto register_cooler_failed;
rc = power_supply_create_triggers(psy);
if (rc)
goto create_triggers_failed;
power_supply_changed(psy);
goto success;
create_triggers_failed:
psy_unregister_cooler(psy);
register_cooler_failed:
psy_unregister_thermal(psy);
register_thermal_failed:
device_del(dev);
kobject_set_name_failed:
device_add_failed:
put_device(dev);
success:
return rc;
}
void power_supply_unregister(struct power_supply *psy)
{
cancel_work_sync(&psy->changed_work);
sysfs_remove_link(&psy->dev->kobj, "powers");
power_supply_remove_triggers(psy);
psy_unregister_cooler(psy);
psy_unregister_thermal(psy);
device_unregister(psy->dev);
}
static int __init power_supply_class_init(void)
{
power_supply_class = class_create(THIS_MODULE, "power_supply");
if (IS_ERR(power_supply_class))
return PTR_ERR(power_supply_class);
power_supply_class->dev_uevent = power_supply_uevent;
power_supply_init_attrs(&power_supply_dev_type);
return 0;
}
static void __exit power_supply_class_exit(void)
{
class_destroy(power_supply_class);
}
