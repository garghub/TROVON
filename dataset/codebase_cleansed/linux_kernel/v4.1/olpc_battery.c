static int olpc_ac_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
uint8_t status;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
ret = olpc_ec_cmd(EC_BAT_STATUS, NULL, 0, &status, 1);
if (ret)
return ret;
val->intval = !!(status & BAT_STAT_AC);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int olpc_bat_get_status(union power_supply_propval *val, uint8_t ec_byte)
{
if (olpc_platform_info.ecver > 0x44) {
if (ec_byte & (BAT_STAT_CHARGING | BAT_STAT_TRICKLE))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (ec_byte & BAT_STAT_DISCHARGING)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (ec_byte & BAT_STAT_FULL)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
} else {
if (!(ec_byte & BAT_STAT_AC))
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (ec_byte & BAT_STAT_FULL)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_CHARGING;
}
return 0;
}
static int olpc_bat_get_health(union power_supply_propval *val)
{
uint8_t ec_byte;
int ret;
ret = olpc_ec_cmd(EC_BAT_ERRCODE, NULL, 0, &ec_byte, 1);
if (ret)
return ret;
switch (ec_byte) {
case 0:
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case BAT_ERR_OVERTEMP:
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
break;
case BAT_ERR_OVERVOLTAGE:
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
break;
case BAT_ERR_INFOFAIL:
case BAT_ERR_OUT_OF_CONTROL:
case BAT_ERR_ID_FAIL:
case BAT_ERR_ACR_FAIL:
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
default:
ret = -EIO;
}
return ret;
}
static int olpc_bat_get_mfr(union power_supply_propval *val)
{
uint8_t ec_byte;
int ret;
ec_byte = BAT_ADDR_MFR_TYPE;
ret = olpc_ec_cmd(EC_BAT_EEPROM, &ec_byte, 1, &ec_byte, 1);
if (ret)
return ret;
switch (ec_byte >> 4) {
case 1:
val->strval = "Gold Peak";
break;
case 2:
val->strval = "BYD";
break;
default:
val->strval = "Unknown";
break;
}
return ret;
}
static int olpc_bat_get_tech(union power_supply_propval *val)
{
uint8_t ec_byte;
int ret;
ec_byte = BAT_ADDR_MFR_TYPE;
ret = olpc_ec_cmd(EC_BAT_EEPROM, &ec_byte, 1, &ec_byte, 1);
if (ret)
return ret;
switch (ec_byte & 0xf) {
case 1:
val->intval = POWER_SUPPLY_TECHNOLOGY_NiMH;
break;
case 2:
val->intval = POWER_SUPPLY_TECHNOLOGY_LiFe;
break;
default:
val->intval = POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
break;
}
return ret;
}
static int olpc_bat_get_charge_full_design(union power_supply_propval *val)
{
uint8_t ec_byte;
union power_supply_propval tech;
int ret, mfr;
ret = olpc_bat_get_tech(&tech);
if (ret)
return ret;
ec_byte = BAT_ADDR_MFR_TYPE;
ret = olpc_ec_cmd(EC_BAT_EEPROM, &ec_byte, 1, &ec_byte, 1);
if (ret)
return ret;
mfr = ec_byte >> 4;
switch (tech.intval) {
case POWER_SUPPLY_TECHNOLOGY_NiMH:
switch (mfr) {
case 1:
val->intval = 3000000*.8;
break;
default:
return -EIO;
}
break;
case POWER_SUPPLY_TECHNOLOGY_LiFe:
switch (mfr) {
case 1:
case 2:
val->intval = 2800000;
break;
default:
return -EIO;
}
break;
default:
return -EIO;
}
return ret;
}
static int olpc_bat_get_charge_now(union power_supply_propval *val)
{
uint8_t soc;
union power_supply_propval full;
int ret;
ret = olpc_ec_cmd(EC_BAT_SOC, NULL, 0, &soc, 1);
if (ret)
return ret;
ret = olpc_bat_get_charge_full_design(&full);
if (ret)
return ret;
val->intval = soc * (full.intval / 100);
return 0;
}
static int olpc_bat_get_voltage_max_design(union power_supply_propval *val)
{
uint8_t ec_byte;
union power_supply_propval tech;
int mfr;
int ret;
ret = olpc_bat_get_tech(&tech);
if (ret)
return ret;
ec_byte = BAT_ADDR_MFR_TYPE;
ret = olpc_ec_cmd(EC_BAT_EEPROM, &ec_byte, 1, &ec_byte, 1);
if (ret)
return ret;
mfr = ec_byte >> 4;
switch (tech.intval) {
case POWER_SUPPLY_TECHNOLOGY_NiMH:
switch (mfr) {
case 1:
val->intval = 6000000;
break;
default:
return -EIO;
}
break;
case POWER_SUPPLY_TECHNOLOGY_LiFe:
switch (mfr) {
case 1:
val->intval = 6400000;
break;
case 2:
val->intval = 6500000;
break;
default:
return -EIO;
}
break;
default:
return -EIO;
}
return ret;
}
static int olpc_bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
__be16 ec_word;
uint8_t ec_byte;
__be64 ser_buf;
ret = olpc_ec_cmd(EC_BAT_STATUS, NULL, 0, &ec_byte, 1);
if (ret)
return ret;
if (!(ec_byte & (BAT_STAT_PRESENT | BAT_STAT_TRICKLE)) &&
psp != POWER_SUPPLY_PROP_PRESENT)
return -ENODEV;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = olpc_bat_get_status(val, ec_byte);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
if (ec_byte & BAT_STAT_TRICKLE)
val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
else if (ec_byte & BAT_STAT_CHARGING)
val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
else
val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = !!(ec_byte & (BAT_STAT_PRESENT |
BAT_STAT_TRICKLE));
break;
case POWER_SUPPLY_PROP_HEALTH:
if (ec_byte & BAT_STAT_DESTROY)
val->intval = POWER_SUPPLY_HEALTH_DEAD;
else {
ret = olpc_bat_get_health(val);
if (ret)
return ret;
}
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
ret = olpc_bat_get_mfr(val);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
ret = olpc_bat_get_tech(val);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = olpc_ec_cmd(EC_BAT_VOLTAGE, NULL, 0, (void *)&ec_word, 2);
if (ret)
return ret;
val->intval = (s16)be16_to_cpu(ec_word) * 9760L / 32;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = olpc_ec_cmd(EC_BAT_CURRENT, NULL, 0, (void *)&ec_word, 2);
if (ret)
return ret;
val->intval = (s16)be16_to_cpu(ec_word) * 15625L / 120;
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = olpc_ec_cmd(EC_BAT_SOC, NULL, 0, &ec_byte, 1);
if (ret)
return ret;
val->intval = ec_byte;
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
if (ec_byte & BAT_STAT_FULL)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
else if (ec_byte & BAT_STAT_LOW)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
else
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
ret = olpc_bat_get_charge_full_design(val);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
ret = olpc_bat_get_charge_now(val);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_TEMP:
ret = olpc_ec_cmd(EC_BAT_TEMP, NULL, 0, (void *)&ec_word, 2);
if (ret)
return ret;
val->intval = (s16)be16_to_cpu(ec_word) * 100 / 256;
break;
case POWER_SUPPLY_PROP_TEMP_AMBIENT:
ret = olpc_ec_cmd(EC_AMB_TEMP, NULL, 0, (void *)&ec_word, 2);
if (ret)
return ret;
val->intval = (int)be16_to_cpu(ec_word) * 100 / 256;
break;
case POWER_SUPPLY_PROP_CHARGE_COUNTER:
ret = olpc_ec_cmd(EC_BAT_ACR, NULL, 0, (void *)&ec_word, 2);
if (ret)
return ret;
val->intval = (s16)be16_to_cpu(ec_word) * 6250 / 15;
break;
case POWER_SUPPLY_PROP_SERIAL_NUMBER:
ret = olpc_ec_cmd(EC_BAT_SERIAL, NULL, 0, (void *)&ser_buf, 8);
if (ret)
return ret;
sprintf(bat_serial, "%016llx", (long long)be64_to_cpu(ser_buf));
val->strval = bat_serial;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
ret = olpc_bat_get_voltage_max_design(val);
if (ret)
return ret;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static ssize_t olpc_bat_eeprom_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
uint8_t ec_byte;
int ret;
int i;
if (off >= EEPROM_SIZE)
return 0;
if (off + count > EEPROM_SIZE)
count = EEPROM_SIZE - off;
for (i = 0; i < count; i++) {
ec_byte = EEPROM_START + off + i;
ret = olpc_ec_cmd(EC_BAT_EEPROM, &ec_byte, 1, &buf[i], 1);
if (ret) {
pr_err("olpc-battery: "
"EC_BAT_EEPROM cmd @ 0x%x failed - %d!\n",
ec_byte, ret);
return -EIO;
}
}
return count;
}
static ssize_t olpc_bat_error_read(struct device *dev,
struct device_attribute *attr, char *buf)
{
uint8_t ec_byte;
ssize_t ret;
ret = olpc_ec_cmd(EC_BAT_ERRCODE, NULL, 0, &ec_byte, 1);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ec_byte);
}
static int olpc_battery_suspend(struct platform_device *pdev,
pm_message_t state)
{
if (device_may_wakeup(&olpc_ac->dev))
olpc_ec_wakeup_set(EC_SCI_SRC_ACPWR);
else
olpc_ec_wakeup_clear(EC_SCI_SRC_ACPWR);
if (device_may_wakeup(&olpc_bat->dev))
olpc_ec_wakeup_set(EC_SCI_SRC_BATTERY | EC_SCI_SRC_BATSOC
| EC_SCI_SRC_BATERR);
else
olpc_ec_wakeup_clear(EC_SCI_SRC_BATTERY | EC_SCI_SRC_BATSOC
| EC_SCI_SRC_BATERR);
return 0;
}
static int olpc_battery_probe(struct platform_device *pdev)
{
int ret;
uint8_t status;
if (olpc_platform_info.ecver < 0x44) {
printk(KERN_NOTICE "OLPC EC version 0x%02x too old for "
"battery driver.\n", olpc_platform_info.ecver);
return -ENXIO;
}
ret = olpc_ec_cmd(EC_BAT_STATUS, NULL, 0, &status, 1);
if (ret)
return ret;
olpc_ac = power_supply_register(&pdev->dev, &olpc_ac_desc, NULL);
if (IS_ERR(olpc_ac))
return PTR_ERR(olpc_ac);
if (olpc_board_at_least(olpc_board_pre(0xd0))) {
olpc_bat_desc.properties = olpc_xo15_bat_props;
olpc_bat_desc.num_properties = ARRAY_SIZE(olpc_xo15_bat_props);
} else {
olpc_bat_desc.properties = olpc_xo1_bat_props;
olpc_bat_desc.num_properties = ARRAY_SIZE(olpc_xo1_bat_props);
}
olpc_bat = power_supply_register(&pdev->dev, &olpc_bat_desc, NULL);
if (IS_ERR(olpc_bat)) {
ret = PTR_ERR(olpc_bat);
goto battery_failed;
}
ret = device_create_bin_file(&olpc_bat->dev, &olpc_bat_eeprom);
if (ret)
goto eeprom_failed;
ret = device_create_file(&olpc_bat->dev, &olpc_bat_error);
if (ret)
goto error_failed;
if (olpc_ec_wakeup_available()) {
device_set_wakeup_capable(&olpc_ac->dev, true);
device_set_wakeup_capable(&olpc_bat->dev, true);
}
return 0;
error_failed:
device_remove_bin_file(&olpc_bat->dev, &olpc_bat_eeprom);
eeprom_failed:
power_supply_unregister(olpc_bat);
battery_failed:
power_supply_unregister(olpc_ac);
return ret;
}
static int olpc_battery_remove(struct platform_device *pdev)
{
device_remove_file(&olpc_bat->dev, &olpc_bat_error);
device_remove_bin_file(&olpc_bat->dev, &olpc_bat_eeprom);
power_supply_unregister(olpc_bat);
power_supply_unregister(olpc_ac);
return 0;
}
