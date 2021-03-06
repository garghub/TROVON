static int __set_charger(struct max8925_power_info *info, int enable)
{
struct max8925_chip *chip = info->chip;
if (enable) {
if (info->set_charger)
info->set_charger(1);
max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 0);
} else {
max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 1 << 7);
if (info->set_charger)
info->set_charger(0);
}
dev_dbg(chip->dev, "%s\n", (enable) ? "Enable charger"
: "Disable charger");
return 0;
}
static irqreturn_t max8925_charger_handler(int irq, void *data)
{
struct max8925_power_info *info = (struct max8925_power_info *)data;
struct max8925_chip *chip = info->chip;
switch (irq - chip->irq_base) {
case MAX8925_IRQ_VCHG_DC_R:
info->ac_online = 1;
__set_charger(info, 1);
dev_dbg(chip->dev, "Adapter inserted\n");
break;
case MAX8925_IRQ_VCHG_DC_F:
info->ac_online = 0;
__set_charger(info, 0);
dev_dbg(chip->dev, "Adapter removed\n");
break;
case MAX8925_IRQ_VCHG_THM_OK_F:
dev_dbg(chip->dev, "Battery temperature is out of range\n");
case MAX8925_IRQ_VCHG_DC_OVP:
dev_dbg(chip->dev, "Error detection\n");
__set_charger(info, 0);
break;
case MAX8925_IRQ_VCHG_THM_OK_R:
dev_dbg(chip->dev, "Battery temperature is in range\n");
break;
case MAX8925_IRQ_VCHG_SYSLOW_R:
dev_info(chip->dev, "Sys power is too low\n");
break;
case MAX8925_IRQ_VCHG_SYSLOW_F:
dev_dbg(chip->dev, "Sys power is above low threshold\n");
break;
case MAX8925_IRQ_VCHG_DONE:
__set_charger(info, 0);
dev_dbg(chip->dev, "Charging is done\n");
break;
case MAX8925_IRQ_VCHG_TOPOFF:
dev_dbg(chip->dev, "Charging in top-off mode\n");
break;
case MAX8925_IRQ_VCHG_TMR_FAULT:
__set_charger(info, 0);
dev_dbg(chip->dev, "Safe timer is expired\n");
break;
case MAX8925_IRQ_VCHG_RST:
__set_charger(info, 0);
dev_dbg(chip->dev, "Charger is reset\n");
break;
}
return IRQ_HANDLED;
}
static int start_measure(struct max8925_power_info *info, int type)
{
unsigned char buf[2] = {0, 0};
int meas_cmd;
int meas_reg = 0, ret;
switch (type) {
case MEASURE_VCHG:
meas_cmd = MAX8925_CMD_VCHG;
meas_reg = MAX8925_ADC_VCHG;
break;
case MEASURE_VBBATT:
meas_cmd = MAX8925_CMD_VBBATT;
meas_reg = MAX8925_ADC_VBBATT;
break;
case MEASURE_VMBATT:
meas_cmd = MAX8925_CMD_VMBATT;
meas_reg = MAX8925_ADC_VMBATT;
break;
case MEASURE_ISNS:
meas_cmd = MAX8925_CMD_ISNS;
meas_reg = MAX8925_ADC_ISNS;
break;
default:
return -EINVAL;
}
max8925_reg_write(info->adc, meas_cmd, 0);
max8925_bulk_read(info->adc, meas_reg, 2, buf);
ret = ((buf[0]<<8) | buf[1]) >> 4;
return ret;
}
static int max8925_ac_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max8925_power_info *info = dev_get_drvdata(psy->dev->parent);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = info->ac_online;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (info->ac_online) {
ret = start_measure(info, MEASURE_VCHG);
if (ret >= 0) {
val->intval = ret * 2000;
goto out;
}
}
ret = -ENODATA;
break;
default:
ret = -ENODEV;
break;
}
out:
return ret;
}
static int max8925_usb_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max8925_power_info *info = dev_get_drvdata(psy->dev->parent);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = info->usb_online;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (info->usb_online) {
ret = start_measure(info, MEASURE_VCHG);
if (ret >= 0) {
val->intval = ret * 2000;
goto out;
}
}
ret = -ENODATA;
break;
default:
ret = -ENODEV;
break;
}
out:
return ret;
}
static int max8925_bat_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max8925_power_info *info = dev_get_drvdata(psy->dev->parent);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = info->bat_online;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (info->bat_online) {
ret = start_measure(info, MEASURE_VMBATT);
if (ret >= 0) {
val->intval = ret * 2000;
ret = 0;
break;
}
}
ret = -ENODATA;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
if (info->bat_online) {
ret = start_measure(info, MEASURE_ISNS);
if (ret >= 0) {
ret = ((ret * 6250) - 3125) ;
val->intval = 0;
if (ret > 0)
val->intval = ret;
ret = 0;
break;
}
}
ret = -ENODATA;
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
if (!info->bat_online) {
ret = -ENODATA;
break;
}
ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
ret = (ret & MAX8925_CHG_STAT_MODE_MASK) >> 2;
switch (ret) {
case 1:
val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
case 0:
case 2:
val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case 3:
val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
}
ret = 0;
break;
case POWER_SUPPLY_PROP_STATUS:
if (!info->bat_online) {
ret = -ENODATA;
break;
}
ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
if (info->usb_online || info->ac_online) {
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
if (ret & MAX8925_CHG_STAT_EN_MASK)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
} else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
ret = 0;
break;
default:
ret = -ENODEV;
break;
}
return ret;
}
static int max8925_init_charger(struct max8925_chip *chip,
struct max8925_power_info *info)
{
int ret;
REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_OVP, "ac-ovp");
if (!info->no_insert_detect) {
REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_F, "ac-remove");
REQUEST_IRQ(MAX8925_IRQ_VCHG_DC_R, "ac-insert");
}
if (!info->no_temp_support) {
REQUEST_IRQ(MAX8925_IRQ_VCHG_THM_OK_R, "batt-temp-in-range");
REQUEST_IRQ(MAX8925_IRQ_VCHG_THM_OK_F, "batt-temp-out-range");
}
REQUEST_IRQ(MAX8925_IRQ_VCHG_SYSLOW_F, "vsys-high");
REQUEST_IRQ(MAX8925_IRQ_VCHG_SYSLOW_R, "vsys-low");
REQUEST_IRQ(MAX8925_IRQ_VCHG_RST, "charger-reset");
REQUEST_IRQ(MAX8925_IRQ_VCHG_DONE, "charger-done");
REQUEST_IRQ(MAX8925_IRQ_VCHG_TOPOFF, "charger-topoff");
REQUEST_IRQ(MAX8925_IRQ_VCHG_TMR_FAULT, "charger-timer-expire");
info->usb_online = 0;
info->bat_online = 0;
if (start_measure(info, MEASURE_VCHG) * 2000 > 500000)
info->ac_online = 1;
else
info->ac_online = 0;
ret = max8925_reg_read(info->gpm, MAX8925_CHG_STATUS);
if (ret >= 0) {
if (info->batt_detect)
info->bat_online = (ret & MAX8925_CHG_MBDET) ? 0 : 1;
else
info->bat_online = 1;
if (ret & MAX8925_CHG_AC_RANGE_MASK)
info->ac_online = 1;
else
info->ac_online = 0;
}
max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 1 << 7, 1 << 7);
max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 3 << 5,
info->topoff_threshold << 5);
max8925_set_bits(info->gpm, MAX8925_CHG_CNTL1, 7, info->fast_charge);
return 0;
}
static int max8925_deinit_charger(struct max8925_power_info *info)
{
struct max8925_chip *chip = info->chip;
int irq;
irq = chip->irq_base + MAX8925_IRQ_VCHG_DC_OVP;
for (; irq <= chip->irq_base + MAX8925_IRQ_VCHG_TMR_FAULT; irq++)
free_irq(irq, info);
return 0;
}
static struct max8925_power_pdata *
max8925_power_dt_init(struct platform_device *pdev)
{
struct device_node *nproot = pdev->dev.parent->of_node;
struct device_node *np;
int batt_detect;
int topoff_threshold;
int fast_charge;
int no_temp_support;
int no_insert_detect;
struct max8925_power_pdata *pdata;
if (!nproot)
return pdev->dev.platform_data;
np = of_find_node_by_name(nproot, "charger");
if (!np) {
dev_err(&pdev->dev, "failed to find charger node\n");
return NULL;
}
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct max8925_power_pdata),
GFP_KERNEL);
of_property_read_u32(np, "topoff-threshold", &topoff_threshold);
of_property_read_u32(np, "batt-detect", &batt_detect);
of_property_read_u32(np, "fast-charge", &fast_charge);
of_property_read_u32(np, "no-insert-detect", &no_insert_detect);
of_property_read_u32(np, "no-temp-support", &no_temp_support);
of_node_put(np);
pdata->batt_detect = batt_detect;
pdata->fast_charge = fast_charge;
pdata->topoff_threshold = topoff_threshold;
pdata->no_insert_detect = no_insert_detect;
pdata->no_temp_support = no_temp_support;
return pdata;
}
static struct max8925_power_pdata *
max8925_power_dt_init(struct platform_device *pdev)
{
return pdev->dev.platform_data;
}
static int max8925_power_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct max8925_power_pdata *pdata = NULL;
struct max8925_power_info *info;
int ret;
pdata = max8925_power_dt_init(pdev);
if (!pdata) {
dev_err(&pdev->dev, "platform data isn't assigned to "
"power supply\n");
return -EINVAL;
}
info = devm_kzalloc(&pdev->dev, sizeof(struct max8925_power_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->chip = chip;
info->gpm = chip->i2c;
info->adc = chip->adc;
platform_set_drvdata(pdev, info);
info->ac.name = "max8925-ac";
info->ac.type = POWER_SUPPLY_TYPE_MAINS;
info->ac.properties = max8925_ac_props;
info->ac.num_properties = ARRAY_SIZE(max8925_ac_props);
info->ac.get_property = max8925_ac_get_prop;
info->ac.supplied_to = pdata->supplied_to;
info->ac.num_supplicants = pdata->num_supplicants;
ret = power_supply_register(&pdev->dev, &info->ac);
if (ret)
goto out;
info->ac.dev->parent = &pdev->dev;
info->usb.name = "max8925-usb";
info->usb.type = POWER_SUPPLY_TYPE_USB;
info->usb.properties = max8925_usb_props;
info->usb.num_properties = ARRAY_SIZE(max8925_usb_props);
info->usb.get_property = max8925_usb_get_prop;
info->usb.supplied_to = pdata->supplied_to;
info->usb.num_supplicants = pdata->num_supplicants;
ret = power_supply_register(&pdev->dev, &info->usb);
if (ret)
goto out_usb;
info->usb.dev->parent = &pdev->dev;
info->battery.name = "max8925-battery";
info->battery.type = POWER_SUPPLY_TYPE_BATTERY;
info->battery.properties = max8925_battery_props;
info->battery.num_properties = ARRAY_SIZE(max8925_battery_props);
info->battery.get_property = max8925_bat_get_prop;
ret = power_supply_register(&pdev->dev, &info->battery);
if (ret)
goto out_battery;
info->battery.dev->parent = &pdev->dev;
info->batt_detect = pdata->batt_detect;
info->topoff_threshold = pdata->topoff_threshold;
info->fast_charge = pdata->fast_charge;
info->set_charger = pdata->set_charger;
info->no_temp_support = pdata->no_temp_support;
info->no_insert_detect = pdata->no_insert_detect;
max8925_init_charger(chip, info);
return 0;
out_battery:
power_supply_unregister(&info->battery);
out_usb:
power_supply_unregister(&info->ac);
out:
return ret;
}
static int max8925_power_remove(struct platform_device *pdev)
{
struct max8925_power_info *info = platform_get_drvdata(pdev);
if (info) {
power_supply_unregister(&info->ac);
power_supply_unregister(&info->usb);
power_supply_unregister(&info->battery);
max8925_deinit_charger(info);
}
return 0;
}
