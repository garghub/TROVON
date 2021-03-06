static int wm831x_power_check_online(struct wm831x *wm831x, int supply,
union power_supply_propval *val)
{
int ret;
ret = wm831x_reg_read(wm831x, WM831X_SYSTEM_STATUS);
if (ret < 0)
return ret;
if (ret & supply)
val->intval = 1;
else
val->intval = 0;
return 0;
}
static int wm831x_power_read_voltage(struct wm831x *wm831x,
enum wm831x_auxadc src,
union power_supply_propval *val)
{
int ret;
ret = wm831x_auxadc_read_uv(wm831x, src);
if (ret >= 0)
val->intval = ret;
return ret;
}
static int wm831x_wall_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wm831x_power *wm831x_power = dev_get_drvdata(psy->dev->parent);
struct wm831x *wm831x = wm831x_power->wm831x;
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
ret = wm831x_power_check_online(wm831x, WM831X_PWR_WALL, val);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = wm831x_power_read_voltage(wm831x, WM831X_AUX_WALL, val);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int wm831x_usb_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wm831x_power *wm831x_power = dev_get_drvdata(psy->dev->parent);
struct wm831x *wm831x = wm831x_power->wm831x;
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
ret = wm831x_power_check_online(wm831x, WM831X_PWR_USB, val);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = wm831x_power_read_voltage(wm831x, WM831X_AUX_USB, val);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void wm831x_battey_apply_config(struct wm831x *wm831x,
struct chg_map *map, int count, int val,
int *reg, const char *name,
const char *units)
{
int i;
for (i = 0; i < count; i++)
if (val == map[i].val)
break;
if (i == count) {
dev_err(wm831x->dev, "Invalid %s %d%s\n",
name, val, units);
} else {
*reg |= map[i].reg_val;
dev_dbg(wm831x->dev, "Set %s of %d%s\n", name, val, units);
}
}
static void wm831x_config_battery(struct wm831x *wm831x)
{
struct wm831x_pdata *wm831x_pdata = wm831x->dev->platform_data;
struct wm831x_battery_pdata *pdata;
int ret, reg1, reg2;
if (!wm831x_pdata || !wm831x_pdata->battery) {
dev_warn(wm831x->dev,
"No battery charger configuration\n");
return;
}
pdata = wm831x_pdata->battery;
reg1 = 0;
reg2 = 0;
if (!pdata->enable) {
dev_info(wm831x->dev, "Battery charger disabled\n");
return;
}
reg1 |= WM831X_CHG_ENA;
if (pdata->off_mask)
reg2 |= WM831X_CHG_OFF_MSK;
if (pdata->fast_enable)
reg1 |= WM831X_CHG_FAST;
wm831x_battey_apply_config(wm831x, trickle_ilims,
ARRAY_SIZE(trickle_ilims),
pdata->trickle_ilim, &reg2,
"trickle charge current limit", "mA");
wm831x_battey_apply_config(wm831x, vsels, ARRAY_SIZE(vsels),
pdata->vsel, &reg2,
"target voltage", "mV");
wm831x_battey_apply_config(wm831x, fast_ilims, ARRAY_SIZE(fast_ilims),
pdata->fast_ilim, &reg2,
"fast charge current limit", "mA");
wm831x_battey_apply_config(wm831x, eoc_iterms, ARRAY_SIZE(eoc_iterms),
pdata->eoc_iterm, &reg1,
"end of charge current threshold", "mA");
wm831x_battey_apply_config(wm831x, chg_times, ARRAY_SIZE(chg_times),
pdata->timeout, &reg2,
"charger timeout", "min");
ret = wm831x_reg_unlock(wm831x);
if (ret != 0) {
dev_err(wm831x->dev, "Failed to unlock registers: %d\n", ret);
return;
}
ret = wm831x_set_bits(wm831x, WM831X_CHARGER_CONTROL_1,
WM831X_CHG_ENA_MASK |
WM831X_CHG_FAST_MASK |
WM831X_CHG_ITERM_MASK,
reg1);
if (ret != 0)
dev_err(wm831x->dev, "Failed to set charger control 1: %d\n",
ret);
ret = wm831x_set_bits(wm831x, WM831X_CHARGER_CONTROL_2,
WM831X_CHG_OFF_MSK |
WM831X_CHG_TIME_MASK |
WM831X_CHG_FAST_ILIM_MASK |
WM831X_CHG_TRKL_ILIM_MASK |
WM831X_CHG_VSEL_MASK,
reg2);
if (ret != 0)
dev_err(wm831x->dev, "Failed to set charger control 2: %d\n",
ret);
wm831x_reg_lock(wm831x);
}
static int wm831x_bat_check_status(struct wm831x *wm831x, int *status)
{
int ret;
ret = wm831x_reg_read(wm831x, WM831X_SYSTEM_STATUS);
if (ret < 0)
return ret;
if (ret & WM831X_PWR_SRC_BATT) {
*status = POWER_SUPPLY_STATUS_DISCHARGING;
return 0;
}
ret = wm831x_reg_read(wm831x, WM831X_CHARGER_STATUS);
if (ret < 0)
return ret;
switch (ret & WM831X_CHG_STATE_MASK) {
case WM831X_CHG_STATE_OFF:
*status = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case WM831X_CHG_STATE_TRICKLE:
case WM831X_CHG_STATE_FAST:
*status = POWER_SUPPLY_STATUS_CHARGING;
break;
default:
*status = POWER_SUPPLY_STATUS_UNKNOWN;
break;
}
return 0;
}
static int wm831x_bat_check_type(struct wm831x *wm831x, int *type)
{
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CHARGER_STATUS);
if (ret < 0)
return ret;
switch (ret & WM831X_CHG_STATE_MASK) {
case WM831X_CHG_STATE_TRICKLE:
case WM831X_CHG_STATE_TRICKLE_OT:
*type = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case WM831X_CHG_STATE_FAST:
case WM831X_CHG_STATE_FAST_OT:
*type = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
default:
*type = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
}
return 0;
}
static int wm831x_bat_check_health(struct wm831x *wm831x, int *health)
{
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CHARGER_STATUS);
if (ret < 0)
return ret;
if (ret & WM831X_BATT_HOT_STS) {
*health = POWER_SUPPLY_HEALTH_OVERHEAT;
return 0;
}
if (ret & WM831X_BATT_COLD_STS) {
*health = POWER_SUPPLY_HEALTH_COLD;
return 0;
}
if (ret & WM831X_BATT_OV_STS) {
*health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
return 0;
}
switch (ret & WM831X_CHG_STATE_MASK) {
case WM831X_CHG_STATE_TRICKLE_OT:
case WM831X_CHG_STATE_FAST_OT:
*health = POWER_SUPPLY_HEALTH_OVERHEAT;
break;
case WM831X_CHG_STATE_DEFECTIVE:
*health = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
default:
*health = POWER_SUPPLY_HEALTH_GOOD;
break;
}
return 0;
}
static int wm831x_bat_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wm831x_power *wm831x_power = dev_get_drvdata(psy->dev->parent);
struct wm831x *wm831x = wm831x_power->wm831x;
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = wm831x_bat_check_status(wm831x, &val->intval);
break;
case POWER_SUPPLY_PROP_ONLINE:
ret = wm831x_power_check_online(wm831x, WM831X_PWR_SRC_BATT,
val);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = wm831x_power_read_voltage(wm831x, WM831X_AUX_BATT, val);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = wm831x_bat_check_health(wm831x, &val->intval);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = wm831x_bat_check_type(wm831x, &val->intval);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static irqreturn_t wm831x_bat_irq(int irq, void *data)
{
struct wm831x_power *wm831x_power = data;
struct wm831x *wm831x = wm831x_power->wm831x;
dev_dbg(wm831x->dev, "Battery status changed: %d\n", irq);
if (wm831x_power->have_battery)
power_supply_changed(&wm831x_power->battery);
return IRQ_HANDLED;
}
static irqreturn_t wm831x_syslo_irq(int irq, void *data)
{
struct wm831x_power *wm831x_power = data;
struct wm831x *wm831x = wm831x_power->wm831x;
dev_crit(wm831x->dev, "SYSVDD under voltage\n");
return IRQ_HANDLED;
}
static irqreturn_t wm831x_pwr_src_irq(int irq, void *data)
{
struct wm831x_power *wm831x_power = data;
struct wm831x *wm831x = wm831x_power->wm831x;
dev_dbg(wm831x->dev, "Power source changed\n");
if (wm831x_power->have_battery)
power_supply_changed(&wm831x_power->battery);
power_supply_changed(&wm831x_power->usb);
power_supply_changed(&wm831x_power->wall);
return IRQ_HANDLED;
}
static int wm831x_power_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_pdata *wm831x_pdata = wm831x->dev->platform_data;
struct wm831x_power *power;
struct power_supply *usb;
struct power_supply *battery;
struct power_supply *wall;
int ret, irq, i;
power = kzalloc(sizeof(struct wm831x_power), GFP_KERNEL);
if (power == NULL)
return -ENOMEM;
power->wm831x = wm831x;
platform_set_drvdata(pdev, power);
usb = &power->usb;
battery = &power->battery;
wall = &power->wall;
if (wm831x_pdata && wm831x_pdata->wm831x_num) {
snprintf(power->wall_name, sizeof(power->wall_name),
"wm831x-wall.%d", wm831x_pdata->wm831x_num);
snprintf(power->battery_name, sizeof(power->wall_name),
"wm831x-battery.%d", wm831x_pdata->wm831x_num);
snprintf(power->usb_name, sizeof(power->wall_name),
"wm831x-usb.%d", wm831x_pdata->wm831x_num);
} else {
snprintf(power->wall_name, sizeof(power->wall_name),
"wm831x-wall");
snprintf(power->battery_name, sizeof(power->wall_name),
"wm831x-battery");
snprintf(power->usb_name, sizeof(power->wall_name),
"wm831x-usb");
}
wm831x_config_battery(wm831x);
wall->name = power->wall_name;
wall->type = POWER_SUPPLY_TYPE_MAINS;
wall->properties = wm831x_wall_props;
wall->num_properties = ARRAY_SIZE(wm831x_wall_props);
wall->get_property = wm831x_wall_get_prop;
ret = power_supply_register(&pdev->dev, wall);
if (ret)
goto err_kmalloc;
usb->name = power->usb_name,
usb->type = POWER_SUPPLY_TYPE_USB;
usb->properties = wm831x_usb_props;
usb->num_properties = ARRAY_SIZE(wm831x_usb_props);
usb->get_property = wm831x_usb_get_prop;
ret = power_supply_register(&pdev->dev, usb);
if (ret)
goto err_wall;
ret = wm831x_reg_read(wm831x, WM831X_CHARGER_CONTROL_1);
if (ret < 0)
goto err_wall;
power->have_battery = ret & WM831X_CHG_ENA;
if (power->have_battery) {
battery->name = power->battery_name;
battery->properties = wm831x_bat_props;
battery->num_properties = ARRAY_SIZE(wm831x_bat_props);
battery->get_property = wm831x_bat_get_prop;
battery->use_for_apm = 1;
ret = power_supply_register(&pdev->dev, battery);
if (ret)
goto err_usb;
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "SYSLO"));
ret = request_threaded_irq(irq, NULL, wm831x_syslo_irq,
IRQF_TRIGGER_RISING, "System power low",
power);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to request SYSLO IRQ %d: %d\n",
irq, ret);
goto err_battery;
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "PWR SRC"));
ret = request_threaded_irq(irq, NULL, wm831x_pwr_src_irq,
IRQF_TRIGGER_RISING, "Power source",
power);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to request PWR SRC IRQ %d: %d\n",
irq, ret);
goto err_syslo;
}
for (i = 0; i < ARRAY_SIZE(wm831x_bat_irqs); i++) {
irq = wm831x_irq(wm831x,
platform_get_irq_byname(pdev,
wm831x_bat_irqs[i]));
ret = request_threaded_irq(irq, NULL, wm831x_bat_irq,
IRQF_TRIGGER_RISING,
wm831x_bat_irqs[i],
power);
if (ret != 0) {
dev_err(&pdev->dev,
"Failed to request %s IRQ %d: %d\n",
wm831x_bat_irqs[i], irq, ret);
goto err_bat_irq;
}
}
return ret;
err_bat_irq:
for (; i >= 0; i--) {
irq = platform_get_irq_byname(pdev, wm831x_bat_irqs[i]);
free_irq(irq, power);
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "PWR SRC"));
free_irq(irq, power);
err_syslo:
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "SYSLO"));
free_irq(irq, power);
err_battery:
if (power->have_battery)
power_supply_unregister(battery);
err_usb:
power_supply_unregister(usb);
err_wall:
power_supply_unregister(wall);
err_kmalloc:
kfree(power);
return ret;
}
static int wm831x_power_remove(struct platform_device *pdev)
{
struct wm831x_power *wm831x_power = platform_get_drvdata(pdev);
struct wm831x *wm831x = wm831x_power->wm831x;
int irq, i;
for (i = 0; i < ARRAY_SIZE(wm831x_bat_irqs); i++) {
irq = wm831x_irq(wm831x,
platform_get_irq_byname(pdev,
wm831x_bat_irqs[i]));
free_irq(irq, wm831x_power);
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "PWR SRC"));
free_irq(irq, wm831x_power);
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "SYSLO"));
free_irq(irq, wm831x_power);
if (wm831x_power->have_battery)
power_supply_unregister(&wm831x_power->battery);
power_supply_unregister(&wm831x_power->wall);
power_supply_unregister(&wm831x_power->usb);
kfree(wm831x_power);
return 0;
}
