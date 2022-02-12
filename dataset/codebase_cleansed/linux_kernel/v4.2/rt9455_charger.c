static unsigned int rt9455_find_idx(const int tbl[], int tbl_size, int v)
{
int i;
for (i = 0; i < tbl_size - 1; i++)
if (v <= tbl[i])
return i;
return (tbl_size - 1);
}
static int rt9455_get_field_val(struct rt9455_info *info,
enum rt9455_fields field,
const int tbl[], int tbl_size, int *val)
{
unsigned int v;
int ret;
ret = regmap_field_read(info->regmap_fields[field], &v);
if (ret)
return ret;
v = (v >= tbl_size) ? (tbl_size - 1) : v;
*val = tbl[v];
return 0;
}
static int rt9455_set_field_val(struct rt9455_info *info,
enum rt9455_fields field,
const int tbl[], int tbl_size, int val)
{
unsigned int idx = rt9455_find_idx(tbl, tbl_size, val);
return regmap_field_write(info->regmap_fields[field], idx);
}
static int rt9455_register_reset(struct rt9455_info *info)
{
struct device *dev = &info->client->dev;
unsigned int v;
int ret, limit = 100;
ret = regmap_field_write(info->regmap_fields[F_RST], 0x01);
if (ret) {
dev_err(dev, "Failed to set RST bit\n");
return ret;
}
do {
ret = regmap_field_read(info->regmap_fields[F_RST], &v);
if (ret) {
dev_err(dev, "Failed to read RST bit\n");
return ret;
}
if (!v)
break;
usleep_range(10, 100);
} while (--limit);
if (!limit)
return -EIO;
return 0;
}
static int rt9455_charger_get_status(struct rt9455_info *info,
union power_supply_propval *val)
{
unsigned int v, pwr_rdy;
int ret;
ret = regmap_field_read(info->regmap_fields[F_PWR_RDY],
&pwr_rdy);
if (ret) {
dev_err(&info->client->dev, "Failed to read PWR_RDY bit\n");
return ret;
}
if (!pwr_rdy) {
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
return 0;
}
ret = regmap_field_read(info->regmap_fields[F_STAT], &v);
if (ret) {
dev_err(&info->client->dev, "Failed to read STAT bits\n");
return ret;
}
switch (v) {
case 0:
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
return 0;
case 1:
val->intval = POWER_SUPPLY_STATUS_CHARGING;
return 0;
case 2:
val->intval = POWER_SUPPLY_STATUS_FULL;
return 0;
default:
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
return 0;
}
}
static int rt9455_charger_get_health(struct rt9455_info *info,
union power_supply_propval *val)
{
struct device *dev = &info->client->dev;
unsigned int v;
int ret;
val->intval = POWER_SUPPLY_HEALTH_GOOD;
ret = regmap_read(info->regmap, RT9455_REG_IRQ1, &v);
if (ret) {
dev_err(dev, "Failed to read IRQ1 register\n");
return ret;
}
if (v & GET_MASK(F_TSDI)) {
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
return 0;
}
if (v & GET_MASK(F_VINOVPI)) {
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
return 0;
}
if (v & GET_MASK(F_BATAB)) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
return 0;
}
ret = regmap_read(info->regmap, RT9455_REG_IRQ2, &v);
if (ret) {
dev_err(dev, "Failed to read IRQ2 register\n");
return ret;
}
if (v & GET_MASK(F_CHBATOVI)) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
return 0;
}
if (v & GET_MASK(F_CH32MI)) {
val->intval = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
return 0;
}
ret = regmap_read(info->regmap, RT9455_REG_IRQ3, &v);
if (ret) {
dev_err(dev, "Failed to read IRQ3 register\n");
return ret;
}
if (v & GET_MASK(F_BSTBUSOVI)) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
return 0;
}
if (v & GET_MASK(F_BSTOLI)) {
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
return 0;
}
if (v & GET_MASK(F_BSTLOWVI)) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
return 0;
}
if (v & GET_MASK(F_BST32SI)) {
val->intval = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
return 0;
}
ret = regmap_field_read(info->regmap_fields[F_STAT], &v);
if (ret) {
dev_err(dev, "Failed to read STAT bits\n");
return ret;
}
if (v == RT9455_FAULT) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
return 0;
}
return 0;
}
static int rt9455_charger_get_battery_presence(struct rt9455_info *info,
union power_supply_propval *val)
{
unsigned int v;
int ret;
ret = regmap_field_read(info->regmap_fields[F_BATAB], &v);
if (ret) {
dev_err(&info->client->dev, "Failed to read BATAB bit\n");
return ret;
}
val->intval = !v;
return 0;
}
static int rt9455_charger_get_online(struct rt9455_info *info,
union power_supply_propval *val)
{
unsigned int v;
int ret;
ret = regmap_field_read(info->regmap_fields[F_PWR_RDY], &v);
if (ret) {
dev_err(&info->client->dev, "Failed to read PWR_RDY bit\n");
return ret;
}
val->intval = (int)v;
return 0;
}
static int rt9455_charger_get_current(struct rt9455_info *info,
union power_supply_propval *val)
{
int curr;
int ret;
ret = rt9455_get_field_val(info, F_ICHRG,
rt9455_ichrg_values,
ARRAY_SIZE(rt9455_ichrg_values),
&curr);
if (ret) {
dev_err(&info->client->dev, "Failed to read ICHRG value\n");
return ret;
}
val->intval = curr;
return 0;
}
static int rt9455_charger_get_current_max(struct rt9455_info *info,
union power_supply_propval *val)
{
int idx = ARRAY_SIZE(rt9455_ichrg_values) - 1;
val->intval = rt9455_ichrg_values[idx];
return 0;
}
static int rt9455_charger_get_voltage(struct rt9455_info *info,
union power_supply_propval *val)
{
int voltage;
int ret;
ret = rt9455_get_field_val(info, F_VOREG,
rt9455_voreg_values,
ARRAY_SIZE(rt9455_voreg_values),
&voltage);
if (ret) {
dev_err(&info->client->dev, "Failed to read VOREG value\n");
return ret;
}
val->intval = voltage;
return 0;
}
static int rt9455_charger_get_voltage_max(struct rt9455_info *info,
union power_supply_propval *val)
{
int idx = ARRAY_SIZE(rt9455_vmreg_values) - 1;
val->intval = rt9455_vmreg_values[idx];
return 0;
}
static int rt9455_charger_get_term_current(struct rt9455_info *info,
union power_supply_propval *val)
{
struct device *dev = &info->client->dev;
int ichrg, ieoc_percentage, ret;
ret = rt9455_get_field_val(info, F_ICHRG,
rt9455_ichrg_values,
ARRAY_SIZE(rt9455_ichrg_values),
&ichrg);
if (ret) {
dev_err(dev, "Failed to read ICHRG value\n");
return ret;
}
ret = rt9455_get_field_val(info, F_IEOC_PERCENTAGE,
rt9455_ieoc_percentage_values,
ARRAY_SIZE(rt9455_ieoc_percentage_values),
&ieoc_percentage);
if (ret) {
dev_err(dev, "Failed to read IEOC value\n");
return ret;
}
val->intval = ichrg * ieoc_percentage / 100;
return 0;
}
static int rt9455_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct rt9455_info *info = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
return rt9455_charger_get_status(info, val);
case POWER_SUPPLY_PROP_HEALTH:
return rt9455_charger_get_health(info, val);
case POWER_SUPPLY_PROP_PRESENT:
return rt9455_charger_get_battery_presence(info, val);
case POWER_SUPPLY_PROP_ONLINE:
return rt9455_charger_get_online(info, val);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
return rt9455_charger_get_current(info, val);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
return rt9455_charger_get_current_max(info, val);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
return rt9455_charger_get_voltage(info, val);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
return rt9455_charger_get_voltage_max(info, val);
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
return 0;
case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
return rt9455_charger_get_term_current(info, val);
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = RT9455_MODEL_NAME;
return 0;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = RT9455_MANUFACTURER;
return 0;
default:
return -ENODATA;
}
}
static int rt9455_hw_init(struct rt9455_info *info, u32 ichrg,
u32 ieoc_percentage,
u32 mivr, u32 iaicr)
{
struct device *dev = &info->client->dev;
int idx, ret;
ret = rt9455_register_reset(info);
if (ret) {
dev_err(dev, "Power On Reset failed\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_TE], 1);
if (ret) {
dev_err(dev, "Failed to set TE bit\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_TE_SHDN_EN], 1);
if (ret) {
dev_err(dev, "Failed to set TE_SHDN_EN bit\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_BATD_EN], 1);
if (ret) {
dev_err(dev, "Failed to set BATD_EN bit\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_TMR_EN], 0x00);
if (ret) {
dev_err(dev, "Failed to disable Safety Timer\n");
return ret;
}
ret = rt9455_set_field_val(info, F_ICHRG,
rt9455_ichrg_values,
ARRAY_SIZE(rt9455_ichrg_values), ichrg);
if (ret) {
dev_err(dev, "Failed to set ICHRG value\n");
return ret;
}
ret = rt9455_set_field_val(info, F_IEOC_PERCENTAGE,
rt9455_ieoc_percentage_values,
ARRAY_SIZE(rt9455_ieoc_percentage_values),
ieoc_percentage);
if (ret) {
dev_err(dev, "Failed to set IEOC Percentage value\n");
return ret;
}
ret = rt9455_set_field_val(info, F_VOREG,
rt9455_voreg_values,
ARRAY_SIZE(rt9455_voreg_values),
info->voreg);
if (ret) {
dev_err(dev, "Failed to set VOREG value\n");
return ret;
}
idx = ARRAY_SIZE(rt9455_vmreg_values) - 1;
ret = rt9455_set_field_val(info, F_VMREG,
rt9455_vmreg_values,
ARRAY_SIZE(rt9455_vmreg_values),
rt9455_vmreg_values[idx]);
if (ret) {
dev_err(dev, "Failed to set VMREG value\n");
return ret;
}
if (mivr == -1)
mivr = 4500000;
ret = rt9455_set_field_val(info, F_MIVR,
rt9455_mivr_values,
ARRAY_SIZE(rt9455_mivr_values), mivr);
if (ret) {
dev_err(dev, "Failed to set MIVR value\n");
return ret;
}
if (iaicr == -1)
iaicr = 500000;
ret = rt9455_set_field_val(info, F_IAICR,
rt9455_iaicr_values,
ARRAY_SIZE(rt9455_iaicr_values), iaicr);
if (ret) {
dev_err(dev, "Failed to set IAICR value\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_IAICR_INT], 0x01);
if (ret) {
dev_err(dev, "Failed to set IAICR_INT bit\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_CHMIVRIM], 0x01);
if (ret) {
dev_err(dev, "Failed to mask CHMIVRI interrupt\n");
return ret;
}
return 0;
}
static int rt9455_set_boost_voltage_before_boost_mode(struct rt9455_info *info)
{
struct device *dev = &info->client->dev;
int ret;
ret = rt9455_set_field_val(info, F_VOREG,
rt9455_boost_voltage_values,
ARRAY_SIZE(rt9455_boost_voltage_values),
info->boost_voltage);
if (ret) {
dev_err(dev, "Failed to set boost output voltage value\n");
return ret;
}
return 0;
}
static int rt9455_set_voreg_before_charge_mode(struct rt9455_info *info)
{
struct device *dev = &info->client->dev;
int ret;
ret = rt9455_set_field_val(info, F_VOREG,
rt9455_voreg_values,
ARRAY_SIZE(rt9455_voreg_values),
info->voreg);
if (ret) {
dev_err(dev, "Failed to set VOREG value\n");
return ret;
}
return 0;
}
static int rt9455_irq_handler_check_irq1_register(struct rt9455_info *info,
bool *_is_battery_absent,
bool *_alert_userspace)
{
unsigned int irq1, mask1, mask2;
struct device *dev = &info->client->dev;
bool is_battery_absent = false;
bool alert_userspace = false;
int ret;
ret = regmap_read(info->regmap, RT9455_REG_IRQ1, &irq1);
if (ret) {
dev_err(dev, "Failed to read IRQ1 register\n");
return ret;
}
ret = regmap_read(info->regmap, RT9455_REG_MASK1, &mask1);
if (ret) {
dev_err(dev, "Failed to read MASK1 register\n");
return ret;
}
if (irq1 & GET_MASK(F_TSDI)) {
dev_err(dev, "Thermal shutdown fault occurred\n");
alert_userspace = true;
}
if (irq1 & GET_MASK(F_VINOVPI)) {
dev_err(dev, "Overvoltage input occurred\n");
alert_userspace = true;
}
if (irq1 & GET_MASK(F_BATAB)) {
dev_err(dev, "Battery absence occurred\n");
is_battery_absent = true;
alert_userspace = true;
if ((mask1 & GET_MASK(F_BATABM)) == 0) {
ret = regmap_field_write(info->regmap_fields[F_BATABM],
0x01);
if (ret) {
dev_err(dev, "Failed to mask BATAB interrupt\n");
return ret;
}
}
ret = regmap_read(info->regmap, RT9455_REG_MASK2, &mask2);
if (ret) {
dev_err(dev, "Failed to read MASK2 register\n");
return ret;
}
if (mask2 & GET_MASK(F_CHTERMIM)) {
ret = regmap_field_write(
info->regmap_fields[F_CHTERMIM], 0x00);
if (ret) {
dev_err(dev, "Failed to unmask CHTERMI interrupt\n");
return ret;
}
}
if (mask2 & GET_MASK(F_CHRCHGIM)) {
ret = regmap_field_write(
info->regmap_fields[F_CHRCHGIM], 0x00);
if (ret) {
dev_err(dev, "Failed to unmask CHRCHGI interrupt\n");
return ret;
}
}
cancel_delayed_work_sync(&info->max_charging_time_work);
queue_delayed_work(system_power_efficient_wq,
&info->batt_presence_work,
RT9455_BATT_PRESENCE_DELAY * HZ);
}
*_is_battery_absent = is_battery_absent;
if (alert_userspace)
*_alert_userspace = alert_userspace;
return 0;
}
static int rt9455_irq_handler_check_irq2_register(struct rt9455_info *info,
bool is_battery_absent,
bool *_alert_userspace)
{
unsigned int irq2, mask2;
struct device *dev = &info->client->dev;
bool alert_userspace = false;
int ret;
ret = regmap_read(info->regmap, RT9455_REG_IRQ2, &irq2);
if (ret) {
dev_err(dev, "Failed to read IRQ2 register\n");
return ret;
}
ret = regmap_read(info->regmap, RT9455_REG_MASK2, &mask2);
if (ret) {
dev_err(dev, "Failed to read MASK2 register\n");
return ret;
}
if (irq2 & GET_MASK(F_CHRVPI)) {
dev_dbg(dev, "Charger fault occurred\n");
alert_userspace = true;
queue_delayed_work(system_power_efficient_wq,
&info->pwr_rdy_work,
RT9455_PWR_RDY_DELAY * HZ);
}
if (irq2 & GET_MASK(F_CHBATOVI)) {
dev_err(dev, "Battery OVP occurred\n");
alert_userspace = true;
}
if (irq2 & GET_MASK(F_CHTERMI)) {
dev_dbg(dev, "Charge terminated\n");
if (!is_battery_absent) {
if ((mask2 & GET_MASK(F_CHTERMIM)) == 0) {
ret = regmap_field_write(
info->regmap_fields[F_CHTERMIM], 0x01);
if (ret) {
dev_err(dev, "Failed to mask CHTERMI interrupt\n");
return ret;
}
mask2 = mask2 | GET_MASK(F_CHTERMIM);
}
cancel_delayed_work_sync(&info->max_charging_time_work);
alert_userspace = true;
}
}
if (irq2 & GET_MASK(F_CHRCHGI)) {
dev_dbg(dev, "Recharge request\n");
ret = regmap_field_write(info->regmap_fields[F_CHG_EN],
RT9455_CHARGE_ENABLE);
if (ret) {
dev_err(dev, "Failed to enable charging\n");
return ret;
}
if (mask2 & GET_MASK(F_CHTERMIM)) {
ret = regmap_field_write(
info->regmap_fields[F_CHTERMIM], 0x00);
if (ret) {
dev_err(dev, "Failed to unmask CHTERMI interrupt\n");
return ret;
}
mask2 = mask2 & ~GET_MASK(F_CHTERMIM);
}
if (!is_battery_absent) {
queue_delayed_work(system_power_efficient_wq,
&info->max_charging_time_work,
RT9455_MAX_CHARGING_TIME * HZ);
alert_userspace = true;
}
}
if (irq2 & GET_MASK(F_CH32MI)) {
dev_err(dev, "Charger fault. 32 mins timeout occurred\n");
alert_userspace = true;
}
if (irq2 & GET_MASK(F_CHTREGI)) {
dev_warn(dev,
"Charger warning. Thermal regulation loop active\n");
alert_userspace = true;
}
if (irq2 & GET_MASK(F_CHMIVRI)) {
dev_dbg(dev,
"Charger warning. Input voltage MIVR loop active\n");
}
if (alert_userspace)
*_alert_userspace = alert_userspace;
return 0;
}
static int rt9455_irq_handler_check_irq3_register(struct rt9455_info *info,
bool *_alert_userspace)
{
unsigned int irq3, mask3;
struct device *dev = &info->client->dev;
bool alert_userspace = false;
int ret;
ret = regmap_read(info->regmap, RT9455_REG_IRQ3, &irq3);
if (ret) {
dev_err(dev, "Failed to read IRQ3 register\n");
return ret;
}
ret = regmap_read(info->regmap, RT9455_REG_MASK3, &mask3);
if (ret) {
dev_err(dev, "Failed to read MASK3 register\n");
return ret;
}
if (irq3 & GET_MASK(F_BSTBUSOVI)) {
dev_err(dev, "Boost fault. Overvoltage input occurred\n");
alert_userspace = true;
}
if (irq3 & GET_MASK(F_BSTOLI)) {
dev_err(dev, "Boost fault. Overload\n");
alert_userspace = true;
}
if (irq3 & GET_MASK(F_BSTLOWVI)) {
dev_err(dev, "Boost fault. Battery voltage too low\n");
alert_userspace = true;
}
if (irq3 & GET_MASK(F_BST32SI)) {
dev_err(dev, "Boost fault. 32 seconds timeout occurred.\n");
alert_userspace = true;
}
if (alert_userspace) {
dev_info(dev, "Boost fault occurred, therefore the charger goes into charge mode\n");
ret = rt9455_set_voreg_before_charge_mode(info);
if (ret) {
dev_err(dev, "Failed to set VOREG before entering charge mode\n");
return ret;
}
ret = regmap_field_write(info->regmap_fields[F_OPA_MODE],
RT9455_CHARGE_MODE);
if (ret) {
dev_err(dev, "Failed to set charger in charge mode\n");
return ret;
}
*_alert_userspace = alert_userspace;
}
return 0;
}
static irqreturn_t rt9455_irq_handler_thread(int irq, void *data)
{
struct rt9455_info *info = data;
struct device *dev;
bool alert_userspace = false;
bool is_battery_absent = false;
unsigned int status;
int ret;
if (!info)
return IRQ_NONE;
dev = &info->client->dev;
if (irq != info->client->irq) {
dev_err(dev, "Interrupt is not for RT9455 charger\n");
return IRQ_NONE;
}
ret = regmap_field_read(info->regmap_fields[F_STAT], &status);
if (ret) {
dev_err(dev, "Failed to read STAT bits\n");
return IRQ_HANDLED;
}
dev_dbg(dev, "Charger status is %d\n", status);
ret = rt9455_irq_handler_check_irq1_register(info, &is_battery_absent,
&alert_userspace);
if (ret) {
dev_err(dev, "Failed to handle IRQ1 register\n");
return IRQ_HANDLED;
}
ret = rt9455_irq_handler_check_irq2_register(info, is_battery_absent,
&alert_userspace);
if (ret) {
dev_err(dev, "Failed to handle IRQ2 register\n");
return IRQ_HANDLED;
}
ret = rt9455_irq_handler_check_irq3_register(info, &alert_userspace);
if (ret) {
dev_err(dev, "Failed to handle IRQ3 register\n");
return IRQ_HANDLED;
}
if (alert_userspace) {
if (info->charger)
power_supply_changed(info->charger);
}
return IRQ_HANDLED;
}
static int rt9455_discover_charger(struct rt9455_info *info, u32 *ichrg,
u32 *ieoc_percentage,
u32 *mivr, u32 *iaicr)
{
struct device *dev = &info->client->dev;
int ret;
if (!dev->of_node && !ACPI_HANDLE(dev)) {
dev_err(dev, "No support for either device tree or ACPI\n");
return -EINVAL;
}
ret = device_property_read_u32(dev, "richtek,output-charge-current",
ichrg);
if (ret) {
dev_err(dev, "Error: missing \"output-charge-current\" property\n");
return ret;
}
ret = device_property_read_u32(dev, "richtek,end-of-charge-percentage",
ieoc_percentage);
if (ret) {
dev_err(dev, "Error: missing \"end-of-charge-percentage\" property\n");
return ret;
}
ret = device_property_read_u32(dev,
"richtek,battery-regulation-voltage",
&info->voreg);
if (ret) {
dev_err(dev, "Error: missing \"battery-regulation-voltage\" property\n");
return ret;
}
ret = device_property_read_u32(dev, "richtek,boost-output-voltage",
&info->boost_voltage);
if (ret) {
dev_err(dev, "Error: missing \"boost-output-voltage\" property\n");
return ret;
}
device_property_read_u32(dev, "richtek,min-input-voltage-regulation",
mivr);
device_property_read_u32(dev, "richtek,avg-input-current-regulation",
iaicr);
return 0;
}
static int rt9455_usb_event_none(struct rt9455_info *info,
u8 opa_mode, u8 iaicr)
{
struct device *dev = &info->client->dev;
int ret;
if (opa_mode == RT9455_BOOST_MODE) {
ret = rt9455_set_voreg_before_charge_mode(info);
if (ret) {
dev_err(dev, "Failed to set VOREG before entering charge mode\n");
return ret;
}
dev_dbg(dev, "USB_EVENT_NONE received, therefore the charger goes into charge mode\n");
ret = regmap_field_write(info->regmap_fields[F_OPA_MODE],
RT9455_CHARGE_MODE);
if (ret) {
dev_err(dev, "Failed to set charger in charge mode\n");
return NOTIFY_DONE;
}
}
dev_dbg(dev, "USB_EVENT_NONE received, therefore IAICR is set to its minimum value\n");
if (iaicr != RT9455_IAICR_100MA) {
ret = regmap_field_write(info->regmap_fields[F_IAICR],
RT9455_IAICR_100MA);
if (ret) {
dev_err(dev, "Failed to set IAICR value\n");
return NOTIFY_DONE;
}
}
return NOTIFY_OK;
}
static int rt9455_usb_event_vbus(struct rt9455_info *info,
u8 opa_mode, u8 iaicr)
{
struct device *dev = &info->client->dev;
int ret;
if (opa_mode == RT9455_BOOST_MODE) {
ret = rt9455_set_voreg_before_charge_mode(info);
if (ret) {
dev_err(dev, "Failed to set VOREG before entering charge mode\n");
return ret;
}
dev_dbg(dev, "USB_EVENT_VBUS received, therefore the charger goes into charge mode\n");
ret = regmap_field_write(info->regmap_fields[F_OPA_MODE],
RT9455_CHARGE_MODE);
if (ret) {
dev_err(dev, "Failed to set charger in charge mode\n");
return NOTIFY_DONE;
}
}
dev_dbg(dev, "USB_EVENT_VBUS received, therefore IAICR is set to 500 mA\n");
if (iaicr != RT9455_IAICR_500MA) {
ret = regmap_field_write(info->regmap_fields[F_IAICR],
RT9455_IAICR_500MA);
if (ret) {
dev_err(dev, "Failed to set IAICR value\n");
return NOTIFY_DONE;
}
}
return NOTIFY_OK;
}
static int rt9455_usb_event_id(struct rt9455_info *info,
u8 opa_mode, u8 iaicr)
{
struct device *dev = &info->client->dev;
int ret;
if (opa_mode == RT9455_CHARGE_MODE) {
ret = rt9455_set_boost_voltage_before_boost_mode(info);
if (ret) {
dev_err(dev, "Failed to set boost output voltage before entering boost mode\n");
return ret;
}
dev_dbg(dev, "USB_EVENT_ID received, therefore the charger goes into boost mode\n");
ret = regmap_field_write(info->regmap_fields[F_OPA_MODE],
RT9455_BOOST_MODE);
if (ret) {
dev_err(dev, "Failed to set charger in boost mode\n");
return NOTIFY_DONE;
}
}
dev_dbg(dev, "USB_EVENT_ID received, therefore IAICR is set to its minimum value\n");
if (iaicr != RT9455_IAICR_100MA) {
ret = regmap_field_write(info->regmap_fields[F_IAICR],
RT9455_IAICR_100MA);
if (ret) {
dev_err(dev, "Failed to set IAICR value\n");
return NOTIFY_DONE;
}
}
return NOTIFY_OK;
}
static int rt9455_usb_event_charger(struct rt9455_info *info,
u8 opa_mode, u8 iaicr)
{
struct device *dev = &info->client->dev;
int ret;
if (opa_mode == RT9455_BOOST_MODE) {
ret = rt9455_set_voreg_before_charge_mode(info);
if (ret) {
dev_err(dev, "Failed to set VOREG before entering charge mode\n");
return ret;
}
dev_dbg(dev, "USB_EVENT_CHARGER received, therefore the charger goes into charge mode\n");
ret = regmap_field_write(info->regmap_fields[F_OPA_MODE],
RT9455_CHARGE_MODE);
if (ret) {
dev_err(dev, "Failed to set charger in charge mode\n");
return NOTIFY_DONE;
}
}
dev_dbg(dev, "USB_EVENT_CHARGER received, therefore IAICR is set to no current limit\n");
if (iaicr != RT9455_IAICR_NO_LIMIT) {
ret = regmap_field_write(info->regmap_fields[F_IAICR],
RT9455_IAICR_NO_LIMIT);
if (ret) {
dev_err(dev, "Failed to set IAICR value\n");
return NOTIFY_DONE;
}
}
return NOTIFY_OK;
}
static int rt9455_usb_event(struct notifier_block *nb,
unsigned long event, void *power)
{
struct rt9455_info *info = container_of(nb, struct rt9455_info, nb);
struct device *dev = &info->client->dev;
unsigned int opa_mode, iaicr;
int ret;
ret = regmap_field_read(info->regmap_fields[F_OPA_MODE],
&opa_mode);
if (ret) {
dev_err(dev, "Failed to read OPA_MODE value\n");
return NOTIFY_DONE;
}
ret = regmap_field_read(info->regmap_fields[F_IAICR],
&iaicr);
if (ret) {
dev_err(dev, "Failed to read IAICR value\n");
return NOTIFY_DONE;
}
dev_dbg(dev, "Received USB event %lu\n", event);
switch (event) {
case USB_EVENT_NONE:
return rt9455_usb_event_none(info, opa_mode, iaicr);
case USB_EVENT_VBUS:
return rt9455_usb_event_vbus(info, opa_mode, iaicr);
case USB_EVENT_ID:
return rt9455_usb_event_id(info, opa_mode, iaicr);
case USB_EVENT_CHARGER:
return rt9455_usb_event_charger(info, opa_mode, iaicr);
default:
dev_err(dev, "Unknown USB event\n");
}
return NOTIFY_DONE;
}
static void rt9455_pwr_rdy_work_callback(struct work_struct *work)
{
struct rt9455_info *info = container_of(work, struct rt9455_info,
pwr_rdy_work.work);
struct device *dev = &info->client->dev;
unsigned int pwr_rdy;
int ret;
ret = regmap_field_read(info->regmap_fields[F_PWR_RDY], &pwr_rdy);
if (ret) {
dev_err(dev, "Failed to read PWR_RDY bit\n");
return;
}
switch (pwr_rdy) {
case RT9455_PWR_FAULT:
dev_dbg(dev, "Charger disconnected from power source\n");
cancel_delayed_work_sync(&info->max_charging_time_work);
break;
case RT9455_PWR_GOOD:
dev_dbg(dev, "Charger connected to power source\n");
ret = regmap_field_write(info->regmap_fields[F_CHG_EN],
RT9455_CHARGE_ENABLE);
if (ret) {
dev_err(dev, "Failed to enable charging\n");
return;
}
queue_delayed_work(system_power_efficient_wq,
&info->max_charging_time_work,
RT9455_MAX_CHARGING_TIME * HZ);
break;
}
}
static void rt9455_max_charging_time_work_callback(struct work_struct *work)
{
struct rt9455_info *info = container_of(work, struct rt9455_info,
max_charging_time_work.work);
struct device *dev = &info->client->dev;
int ret;
dev_err(dev, "Battery has been charging for at least 6 hours and is not yet fully charged. Battery is dead, therefore charging is disabled.\n");
ret = regmap_field_write(info->regmap_fields[F_CHG_EN],
RT9455_CHARGE_DISABLE);
if (ret)
dev_err(dev, "Failed to disable charging\n");
}
static void rt9455_batt_presence_work_callback(struct work_struct *work)
{
struct rt9455_info *info = container_of(work, struct rt9455_info,
batt_presence_work.work);
struct device *dev = &info->client->dev;
unsigned int irq1, mask1;
int ret;
ret = regmap_read(info->regmap, RT9455_REG_IRQ1, &irq1);
if (ret) {
dev_err(dev, "Failed to read IRQ1 register\n");
return;
}
if (irq1 & GET_MASK(F_BATAB)) {
queue_delayed_work(system_power_efficient_wq,
&info->batt_presence_work,
RT9455_BATT_PRESENCE_DELAY * HZ);
} else {
queue_delayed_work(system_power_efficient_wq,
&info->max_charging_time_work,
RT9455_MAX_CHARGING_TIME * HZ);
ret = regmap_read(info->regmap, RT9455_REG_MASK1, &mask1);
if (ret) {
dev_err(dev, "Failed to read MASK1 register\n");
return;
}
if (mask1 & GET_MASK(F_BATABM)) {
ret = regmap_field_write(info->regmap_fields[F_BATABM],
0x00);
if (ret)
dev_err(dev, "Failed to unmask BATAB interrupt\n");
}
}
}
static bool rt9455_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT9455_REG_DEV_ID:
case RT9455_REG_IRQ1:
case RT9455_REG_IRQ2:
case RT9455_REG_IRQ3:
return false;
default:
return true;
}
}
static bool rt9455_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT9455_REG_DEV_ID:
case RT9455_REG_CTRL5:
case RT9455_REG_CTRL6:
return false;
default:
return true;
}
}
static int rt9455_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct device *dev = &client->dev;
struct rt9455_info *info;
struct power_supply_config rt9455_charger_config = {};
u32 ichrg, ieoc_percentage;
u32 mivr = -1, iaicr = -1;
int i, ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(dev, "No support for SMBUS_BYTE_DATA\n");
return -ENODEV;
}
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->client = client;
i2c_set_clientdata(client, info);
info->regmap = devm_regmap_init_i2c(client,
&rt9455_regmap_config);
if (IS_ERR(info->regmap)) {
dev_err(dev, "Failed to initialize register map\n");
return -EINVAL;
}
for (i = 0; i < F_MAX_FIELDS; i++) {
info->regmap_fields[i] =
devm_regmap_field_alloc(dev, info->regmap,
rt9455_reg_fields[i]);
if (IS_ERR(info->regmap_fields[i])) {
dev_err(dev,
"Failed to allocate regmap field = %d\n", i);
return PTR_ERR(info->regmap_fields[i]);
}
}
ret = rt9455_discover_charger(info, &ichrg, &ieoc_percentage,
&mivr, &iaicr);
if (ret) {
dev_err(dev, "Failed to discover charger\n");
return ret;
}
#if IS_ENABLED(CONFIG_USB_PHY)
info->usb_phy = devm_usb_get_phy(dev, USB_PHY_TYPE_USB2);
if (IS_ERR(info->usb_phy)) {
dev_err(dev, "Failed to get USB transceiver\n");
} else {
info->nb.notifier_call = rt9455_usb_event;
ret = usb_register_notifier(info->usb_phy, &info->nb);
if (ret) {
dev_err(dev, "Failed to register USB notifier\n");
info->nb.notifier_call = NULL;
}
}
#endif
INIT_DEFERRABLE_WORK(&info->pwr_rdy_work, rt9455_pwr_rdy_work_callback);
INIT_DEFERRABLE_WORK(&info->max_charging_time_work,
rt9455_max_charging_time_work_callback);
INIT_DEFERRABLE_WORK(&info->batt_presence_work,
rt9455_batt_presence_work_callback);
rt9455_charger_config.of_node = dev->of_node;
rt9455_charger_config.drv_data = info;
rt9455_charger_config.supplied_to = rt9455_charger_supplied_to;
rt9455_charger_config.num_supplicants =
ARRAY_SIZE(rt9455_charger_supplied_to);
ret = devm_request_threaded_irq(dev, client->irq, NULL,
rt9455_irq_handler_thread,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
RT9455_DRIVER_NAME, info);
if (ret) {
dev_err(dev, "Failed to register IRQ handler\n");
goto put_usb_notifier;
}
ret = rt9455_hw_init(info, ichrg, ieoc_percentage, mivr, iaicr);
if (ret) {
dev_err(dev, "Failed to set charger to its default values\n");
goto put_usb_notifier;
}
info->charger = devm_power_supply_register(dev, &rt9455_charger_desc,
&rt9455_charger_config);
if (IS_ERR(info->charger)) {
dev_err(dev, "Failed to register charger\n");
ret = PTR_ERR(info->charger);
goto put_usb_notifier;
}
return 0;
put_usb_notifier:
#if IS_ENABLED(CONFIG_USB_PHY)
if (info->nb.notifier_call) {
usb_unregister_notifier(info->usb_phy, &info->nb);
info->nb.notifier_call = NULL;
}
#endif
return ret;
}
static int rt9455_remove(struct i2c_client *client)
{
int ret;
struct rt9455_info *info = i2c_get_clientdata(client);
ret = rt9455_register_reset(info);
if (ret)
dev_err(&info->client->dev, "Failed to set charger to its default values\n");
#if IS_ENABLED(CONFIG_USB_PHY)
if (info->nb.notifier_call)
usb_unregister_notifier(info->usb_phy, &info->nb);
#endif
cancel_delayed_work_sync(&info->pwr_rdy_work);
cancel_delayed_work_sync(&info->max_charging_time_work);
cancel_delayed_work_sync(&info->batt_presence_work);
return ret;
}
