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
error = class_for_each_device(power_supply_class, NULL, NULL,
__power_supply_is_system_supplied);
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
static void power_supply_dev_release(struct device *dev)
{
pr_debug("device: '%s': %s\n", dev_name(dev), __func__);
kfree(dev);
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
rc = power_supply_create_triggers(psy);
if (rc)
goto create_triggers_failed;
power_supply_changed(psy);
goto success;
create_triggers_failed:
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
power_supply_remove_triggers(psy);
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
