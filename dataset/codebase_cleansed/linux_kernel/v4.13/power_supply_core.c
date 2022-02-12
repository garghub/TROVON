static bool __power_supply_is_supplied_by(struct power_supply *supplier,
struct power_supply *supply)
{
int i;
if (!supply->supplied_from && !supplier->supplied_to)
return false;
if (supply->supplied_from) {
if (!supplier->desc->name)
return false;
for (i = 0; i < supply->num_supplies; i++)
if (!strcmp(supplier->desc->name, supply->supplied_from[i]))
return true;
} else {
if (!supply->desc->name)
return false;
for (i = 0; i < supplier->num_supplicants; i++)
if (!strcmp(supplier->supplied_to[i], supply->desc->name))
return true;
}
return false;
}
static int __power_supply_changed_work(struct device *dev, void *data)
{
struct power_supply *psy = data;
struct power_supply *pst = dev_get_drvdata(dev);
if (__power_supply_is_supplied_by(psy, pst)) {
if (pst->desc->external_power_changed)
pst->desc->external_power_changed(pst);
}
return 0;
}
static void power_supply_changed_work(struct work_struct *work)
{
unsigned long flags;
struct power_supply *psy = container_of(work, struct power_supply,
changed_work);
dev_dbg(&psy->dev, "%s\n", __func__);
spin_lock_irqsave(&psy->changed_lock, flags);
if (likely(psy->changed)) {
psy->changed = false;
spin_unlock_irqrestore(&psy->changed_lock, flags);
class_for_each_device(power_supply_class, NULL, psy,
__power_supply_changed_work);
power_supply_update_leds(psy);
atomic_notifier_call_chain(&power_supply_notifier,
PSY_EVENT_PROP_CHANGED, psy);
kobject_uevent(&psy->dev.kobj, KOBJ_CHANGE);
spin_lock_irqsave(&psy->changed_lock, flags);
}
if (likely(!psy->changed))
pm_relax(&psy->dev);
spin_unlock_irqrestore(&psy->changed_lock, flags);
}
void power_supply_changed(struct power_supply *psy)
{
unsigned long flags;
dev_dbg(&psy->dev, "%s\n", __func__);
spin_lock_irqsave(&psy->changed_lock, flags);
psy->changed = true;
pm_stay_awake(&psy->dev);
spin_unlock_irqrestore(&psy->changed_lock, flags);
schedule_work(&psy->changed_work);
}
static void power_supply_deferred_register_work(struct work_struct *work)
{
struct power_supply *psy = container_of(work, struct power_supply,
deferred_register_work.work);
if (psy->dev.parent)
mutex_lock(&psy->dev.parent->mutex);
power_supply_changed(psy);
if (psy->dev.parent)
mutex_unlock(&psy->dev.parent->mutex);
}
static int __power_supply_populate_supplied_from(struct device *dev,
void *data)
{
struct power_supply *psy = data;
struct power_supply *epsy = dev_get_drvdata(dev);
struct device_node *np;
int i = 0;
do {
np = of_parse_phandle(psy->of_node, "power-supplies", i++);
if (!np)
break;
if (np == epsy->of_node) {
dev_info(&psy->dev, "%s: Found supply : %s\n",
psy->desc->name, epsy->desc->name);
psy->supplied_from[i-1] = (char *)epsy->desc->name;
psy->num_supplies++;
of_node_put(np);
break;
}
of_node_put(np);
} while (np);
return 0;
}
static int power_supply_populate_supplied_from(struct power_supply *psy)
{
int error;
error = class_for_each_device(power_supply_class, NULL, psy,
__power_supply_populate_supplied_from);
dev_dbg(&psy->dev, "%s %d\n", __func__, error);
return error;
}
static int __power_supply_find_supply_from_node(struct device *dev,
void *data)
{
struct device_node *np = data;
struct power_supply *epsy = dev_get_drvdata(dev);
if (epsy->of_node == np)
return 1;
return 0;
}
static int power_supply_find_supply_from_node(struct device_node *supply_node)
{
int error;
error = class_for_each_device(power_supply_class, NULL, supply_node,
__power_supply_find_supply_from_node);
return error ? (error == 1 ? 0 : error) : -EPROBE_DEFER;
}
static int power_supply_check_supplies(struct power_supply *psy)
{
struct device_node *np;
int cnt = 0;
if (psy->supplied_from && psy->num_supplies > 0)
return 0;
if (!psy->of_node)
return 0;
do {
int ret;
np = of_parse_phandle(psy->of_node, "power-supplies", cnt++);
if (!np)
break;
ret = power_supply_find_supply_from_node(np);
of_node_put(np);
if (ret) {
dev_dbg(&psy->dev, "Failed to find supply!\n");
return ret;
}
} while (np);
if (cnt == 1)
return 0;
psy->supplied_from = devm_kzalloc(&psy->dev, sizeof(psy->supplied_from),
GFP_KERNEL);
if (!psy->supplied_from) {
dev_err(&psy->dev, "Couldn't allocate memory for supply list\n");
return -ENOMEM;
}
*psy->supplied_from = devm_kzalloc(&psy->dev,
sizeof(char *) * (cnt - 1),
GFP_KERNEL);
if (!*psy->supplied_from) {
dev_err(&psy->dev, "Couldn't allocate memory for supply list\n");
return -ENOMEM;
}
return power_supply_populate_supplied_from(psy);
}
static int power_supply_check_supplies(struct power_supply *psy)
{
int nval, ret;
if (!psy->dev.parent)
return 0;
nval = device_property_read_string_array(psy->dev.parent,
"supplied-from", NULL, 0);
if (nval <= 0)
return 0;
psy->supplied_from = devm_kmalloc_array(&psy->dev, nval,
sizeof(char *), GFP_KERNEL);
if (!psy->supplied_from)
return -ENOMEM;
ret = device_property_read_string_array(psy->dev.parent,
"supplied-from", (const char **)psy->supplied_from, nval);
if (ret < 0)
return ret;
psy->num_supplies = nval;
return 0;
}
static int __power_supply_am_i_supplied(struct device *dev, void *_data)
{
union power_supply_propval ret = {0,};
struct power_supply *epsy = dev_get_drvdata(dev);
struct psy_am_i_supplied_data *data = _data;
data->count++;
if (__power_supply_is_supplied_by(epsy, data->psy))
if (!epsy->desc->get_property(epsy, POWER_SUPPLY_PROP_ONLINE,
&ret))
return ret.intval;
return 0;
}
int power_supply_am_i_supplied(struct power_supply *psy)
{
struct psy_am_i_supplied_data data = { psy, 0 };
int error;
error = class_for_each_device(power_supply_class, NULL, &data,
__power_supply_am_i_supplied);
dev_dbg(&psy->dev, "%s count %u err %d\n", __func__, data.count, error);
if (data.count == 0)
return -ENODEV;
return error;
}
static int __power_supply_is_system_supplied(struct device *dev, void *data)
{
union power_supply_propval ret = {0,};
struct power_supply *psy = dev_get_drvdata(dev);
unsigned int *count = data;
(*count)++;
if (psy->desc->type != POWER_SUPPLY_TYPE_BATTERY)
if (!psy->desc->get_property(psy, POWER_SUPPLY_PROP_ONLINE,
&ret))
return ret.intval;
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
if (atomic_read(&psy->use_cnt) >= 0 &&
psy->desc->type == POWER_SUPPLY_TYPE_BATTERY &&
psy->desc->set_charged) {
psy->desc->set_charged(psy);
return 0;
}
return -EINVAL;
}
static int power_supply_match_device_by_name(struct device *dev, const void *data)
{
const char *name = data;
struct power_supply *psy = dev_get_drvdata(dev);
return strcmp(psy->desc->name, name) == 0;
}
struct power_supply *power_supply_get_by_name(const char *name)
{
struct power_supply *psy = NULL;
struct device *dev = class_find_device(power_supply_class, NULL, name,
power_supply_match_device_by_name);
if (dev) {
psy = dev_get_drvdata(dev);
atomic_inc(&psy->use_cnt);
}
return psy;
}
void power_supply_put(struct power_supply *psy)
{
might_sleep();
atomic_dec(&psy->use_cnt);
put_device(&psy->dev);
}
static int power_supply_match_device_node(struct device *dev, const void *data)
{
return dev->parent && dev->parent->of_node == data;
}
struct power_supply *power_supply_get_by_phandle(struct device_node *np,
const char *property)
{
struct device_node *power_supply_np;
struct power_supply *psy = NULL;
struct device *dev;
power_supply_np = of_parse_phandle(np, property, 0);
if (!power_supply_np)
return ERR_PTR(-ENODEV);
dev = class_find_device(power_supply_class, NULL, power_supply_np,
power_supply_match_device_node);
of_node_put(power_supply_np);
if (dev) {
psy = dev_get_drvdata(dev);
atomic_inc(&psy->use_cnt);
}
return psy;
}
static void devm_power_supply_put(struct device *dev, void *res)
{
struct power_supply **psy = res;
power_supply_put(*psy);
}
struct power_supply *devm_power_supply_get_by_phandle(struct device *dev,
const char *property)
{
struct power_supply **ptr, *psy;
if (!dev->of_node)
return ERR_PTR(-ENODEV);
ptr = devres_alloc(devm_power_supply_put, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
psy = power_supply_get_by_phandle(dev->of_node, property);
if (IS_ERR_OR_NULL(psy)) {
devres_free(ptr);
} else {
*ptr = psy;
devres_add(dev, ptr);
}
return psy;
}
int power_supply_get_battery_info(struct power_supply *psy,
struct power_supply_battery_info *info)
{
struct device_node *battery_np;
const char *value;
int err;
info->energy_full_design_uwh = -EINVAL;
info->charge_full_design_uah = -EINVAL;
info->voltage_min_design_uv = -EINVAL;
info->precharge_current_ua = -EINVAL;
info->charge_term_current_ua = -EINVAL;
info->constant_charge_current_max_ua = -EINVAL;
info->constant_charge_voltage_max_uv = -EINVAL;
if (!psy->of_node) {
dev_warn(&psy->dev, "%s currently only supports devicetree\n",
__func__);
return -ENXIO;
}
battery_np = of_parse_phandle(psy->of_node, "monitored-battery", 0);
if (!battery_np)
return -ENODEV;
err = of_property_read_string(battery_np, "compatible", &value);
if (err)
return err;
if (strcmp("simple-battery", value))
return -ENODEV;
of_property_read_u32(battery_np, "energy-full-design-microwatt-hours",
&info->energy_full_design_uwh);
of_property_read_u32(battery_np, "charge-full-design-microamp-hours",
&info->charge_full_design_uah);
of_property_read_u32(battery_np, "voltage-min-design-microvolt",
&info->voltage_min_design_uv);
of_property_read_u32(battery_np, "precharge-current-microamp",
&info->precharge_current_ua);
of_property_read_u32(battery_np, "charge-term-current-microamp",
&info->charge_term_current_ua);
of_property_read_u32(battery_np, "constant_charge_current_max_microamp",
&info->constant_charge_current_max_ua);
of_property_read_u32(battery_np, "constant_charge_voltage_max_microvolt",
&info->constant_charge_voltage_max_uv);
return 0;
}
int power_supply_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
if (atomic_read(&psy->use_cnt) <= 0) {
if (!psy->initialized)
return -EAGAIN;
return -ENODEV;
}
return psy->desc->get_property(psy, psp, val);
}
int power_supply_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
if (atomic_read(&psy->use_cnt) <= 0 || !psy->desc->set_property)
return -ENODEV;
return psy->desc->set_property(psy, psp, val);
}
int power_supply_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
if (atomic_read(&psy->use_cnt) <= 0 ||
!psy->desc->property_is_writeable)
return -ENODEV;
return psy->desc->property_is_writeable(psy, psp);
}
void power_supply_external_power_changed(struct power_supply *psy)
{
if (atomic_read(&psy->use_cnt) <= 0 ||
!psy->desc->external_power_changed)
return;
psy->desc->external_power_changed(psy);
}
int power_supply_powers(struct power_supply *psy, struct device *dev)
{
return sysfs_create_link(&psy->dev.kobj, &dev->kobj, "powers");
}
static void power_supply_dev_release(struct device *dev)
{
struct power_supply *psy = container_of(dev, struct power_supply, dev);
pr_debug("device: '%s': %s\n", dev_name(dev), __func__);
kfree(psy);
}
int power_supply_reg_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&power_supply_notifier, nb);
}
void power_supply_unreg_notifier(struct notifier_block *nb)
{
atomic_notifier_chain_unregister(&power_supply_notifier, nb);
}
static int power_supply_read_temp(struct thermal_zone_device *tzd,
int *temp)
{
struct power_supply *psy;
union power_supply_propval val;
int ret;
WARN_ON(tzd == NULL);
psy = tzd->devdata;
ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_TEMP, &val);
if (ret)
return ret;
*temp = val.intval * 100;
return ret;
}
static int psy_register_thermal(struct power_supply *psy)
{
int i;
if (psy->desc->no_thermal)
return 0;
for (i = 0; i < psy->desc->num_properties; i++) {
if (psy->desc->properties[i] == POWER_SUPPLY_PROP_TEMP) {
psy->tzd = thermal_zone_device_register(psy->desc->name,
0, 0, psy, &psy_tzd_ops, NULL, 0, 0);
return PTR_ERR_OR_ZERO(psy->tzd);
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
ret = power_supply_get_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX, &val);
if (ret)
return ret;
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
ret = power_supply_get_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT, &val);
if (ret)
return ret;
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
ret = psy->desc->set_property(psy,
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT, &val);
return ret;
}
static int psy_register_cooler(struct power_supply *psy)
{
int i;
for (i = 0; i < psy->desc->num_properties; i++) {
if (psy->desc->properties[i] ==
POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT) {
psy->tcd = thermal_cooling_device_register(
(char *)psy->desc->name,
psy, &psy_tcd_ops);
return PTR_ERR_OR_ZERO(psy->tcd);
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
static struct power_supply *__must_check
__power_supply_register(struct device *parent,
const struct power_supply_desc *desc,
const struct power_supply_config *cfg,
bool ws)
{
struct device *dev;
struct power_supply *psy;
int rc;
if (!parent)
pr_warn("%s: Expected proper parent device for '%s'\n",
__func__, desc->name);
psy = kzalloc(sizeof(*psy), GFP_KERNEL);
if (!psy)
return ERR_PTR(-ENOMEM);
dev = &psy->dev;
device_initialize(dev);
dev->class = power_supply_class;
dev->type = &power_supply_dev_type;
dev->parent = parent;
dev->release = power_supply_dev_release;
dev_set_drvdata(dev, psy);
psy->desc = desc;
if (cfg) {
psy->drv_data = cfg->drv_data;
psy->of_node = cfg->of_node;
psy->supplied_to = cfg->supplied_to;
psy->num_supplicants = cfg->num_supplicants;
}
rc = dev_set_name(dev, "%s", desc->name);
if (rc)
goto dev_set_name_failed;
INIT_WORK(&psy->changed_work, power_supply_changed_work);
INIT_DELAYED_WORK(&psy->deferred_register_work,
power_supply_deferred_register_work);
rc = power_supply_check_supplies(psy);
if (rc) {
dev_info(dev, "Not all required supplies found, defer probe\n");
goto check_supplies_failed;
}
spin_lock_init(&psy->changed_lock);
rc = device_init_wakeup(dev, ws);
if (rc)
goto wakeup_init_failed;
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
atomic_inc(&psy->use_cnt);
psy->initialized = true;
queue_delayed_work(system_power_efficient_wq,
&psy->deferred_register_work,
POWER_SUPPLY_DEFERRED_REGISTER_TIME);
return psy;
create_triggers_failed:
psy_unregister_cooler(psy);
register_cooler_failed:
psy_unregister_thermal(psy);
register_thermal_failed:
device_del(dev);
device_add_failed:
wakeup_init_failed:
check_supplies_failed:
dev_set_name_failed:
put_device(dev);
return ERR_PTR(rc);
}
struct power_supply *__must_check power_supply_register(struct device *parent,
const struct power_supply_desc *desc,
const struct power_supply_config *cfg)
{
return __power_supply_register(parent, desc, cfg, true);
}
struct power_supply *__must_check
power_supply_register_no_ws(struct device *parent,
const struct power_supply_desc *desc,
const struct power_supply_config *cfg)
{
return __power_supply_register(parent, desc, cfg, false);
}
static void devm_power_supply_release(struct device *dev, void *res)
{
struct power_supply **psy = res;
power_supply_unregister(*psy);
}
struct power_supply *__must_check
devm_power_supply_register(struct device *parent,
const struct power_supply_desc *desc,
const struct power_supply_config *cfg)
{
struct power_supply **ptr, *psy;
ptr = devres_alloc(devm_power_supply_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
psy = __power_supply_register(parent, desc, cfg, true);
if (IS_ERR(psy)) {
devres_free(ptr);
} else {
*ptr = psy;
devres_add(parent, ptr);
}
return psy;
}
struct power_supply *__must_check
devm_power_supply_register_no_ws(struct device *parent,
const struct power_supply_desc *desc,
const struct power_supply_config *cfg)
{
struct power_supply **ptr, *psy;
ptr = devres_alloc(devm_power_supply_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
psy = __power_supply_register(parent, desc, cfg, false);
if (IS_ERR(psy)) {
devres_free(ptr);
} else {
*ptr = psy;
devres_add(parent, ptr);
}
return psy;
}
void power_supply_unregister(struct power_supply *psy)
{
WARN_ON(atomic_dec_return(&psy->use_cnt));
cancel_work_sync(&psy->changed_work);
cancel_delayed_work_sync(&psy->deferred_register_work);
sysfs_remove_link(&psy->dev.kobj, "powers");
power_supply_remove_triggers(psy);
psy_unregister_cooler(psy);
psy_unregister_thermal(psy);
device_init_wakeup(&psy->dev, false);
device_unregister(&psy->dev);
}
void *power_supply_get_drvdata(struct power_supply *psy)
{
return psy->drv_data;
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
