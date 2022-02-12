static inline int volt_reg_to_mV(int value)
{
return ((value * 1000) / 512) + 2500;
}
static inline int ichg_reg_to_mA(int value)
{
return (value * 3900) / 1000;
}
static int da9052_read_chgend_current(struct da9052_battery *bat,
int *current_mA)
{
int ret;
if (bat->status == POWER_SUPPLY_STATUS_DISCHARGING)
return -EINVAL;
ret = da9052_reg_read(bat->da9052, DA9052_ICHG_END_REG);
if (ret < 0)
return ret;
*current_mA = ichg_reg_to_mA(ret & DA9052_ICHGEND_ICHGEND);
return 0;
}
static int da9052_read_chg_current(struct da9052_battery *bat, int *current_mA)
{
int ret;
if (bat->status == POWER_SUPPLY_STATUS_DISCHARGING)
return -EINVAL;
ret = da9052_reg_read(bat->da9052, DA9052_ICHG_AV_REG);
if (ret < 0)
return ret;
*current_mA = ichg_reg_to_mA(ret & DA9052_ICHGAV_ICHGAV);
return 0;
}
static int da9052_bat_check_status(struct da9052_battery *bat, int *status)
{
u8 v[2] = {0, 0};
u8 bat_status;
u8 chg_end;
int ret;
int chg_current;
int chg_end_current;
bool dcinsel;
bool dcindet;
bool vbussel;
bool vbusdet;
bool dc;
bool vbus;
ret = da9052_group_read(bat->da9052, DA9052_STATUS_A_REG, 2, v);
if (ret < 0)
return ret;
bat_status = v[0];
chg_end = v[1];
dcinsel = bat_status & DA9052_STATUSA_DCINSEL;
dcindet = bat_status & DA9052_STATUSA_DCINDET;
vbussel = bat_status & DA9052_STATUSA_VBUSSEL;
vbusdet = bat_status & DA9052_STATUSA_VBUSDET;
dc = dcinsel && dcindet;
vbus = vbussel && vbusdet;
if (dc || vbus) {
bat->charger_type = DA9052_CHARGER;
if ((chg_end & DA9052_STATUSB_CHGEND) != 0) {
ret = da9052_read_chg_current(bat, &chg_current);
if (ret < 0)
return ret;
ret = da9052_read_chgend_current(bat, &chg_end_current);
if (ret < 0)
return ret;
if (chg_current >= chg_end_current)
bat->status = POWER_SUPPLY_STATUS_CHARGING;
else
bat->status = POWER_SUPPLY_STATUS_NOT_CHARGING;
} else {
bat->status = POWER_SUPPLY_STATUS_CHARGING;
}
} else if (dcindet || vbusdet) {
bat->charger_type = DA9052_CHARGER;
bat->status = POWER_SUPPLY_STATUS_NOT_CHARGING;
} else {
bat->charger_type = DA9052_NOCHARGER;
bat->status = POWER_SUPPLY_STATUS_DISCHARGING;
}
if (status != NULL)
*status = bat->status;
return 0;
}
static int da9052_bat_read_volt(struct da9052_battery *bat, int *volt_mV)
{
int volt;
volt = da9052_adc_manual_read(bat->da9052, DA9052_ADC_MAN_MUXSEL_VBAT);
if (volt < 0)
return volt;
*volt_mV = volt_reg_to_mV(volt);
return 0;
}
static int da9052_bat_check_presence(struct da9052_battery *bat, int *illegal)
{
int bat_temp;
bat_temp = da9052_adc_read_temp(bat->da9052);
if (bat_temp < 0)
return bat_temp;
if (bat_temp > DA9052_BAT_TSH)
*illegal = 1;
else
*illegal = 0;
return 0;
}
static int da9052_bat_interpolate(int vbat_lower, int vbat_upper,
int level_lower, int level_upper,
int bat_voltage)
{
int tmp;
tmp = ((level_upper - level_lower) * 1000) / (vbat_upper - vbat_lower);
tmp = level_lower + (((bat_voltage - vbat_lower) * tmp) / 1000);
return tmp;
}
static unsigned char da9052_determine_vc_tbl_index(unsigned char adc_temp)
{
int i;
if (adc_temp <= vc_tbl_ref[0])
return 0;
if (adc_temp > vc_tbl_ref[DA9052_VC_TBL_REF_SZ - 1])
return DA9052_VC_TBL_REF_SZ - 1;
for (i = 0; i < DA9052_VC_TBL_REF_SZ; i++) {
if ((adc_temp > vc_tbl_ref[i]) &&
(adc_temp <= DA9052_MEAN(vc_tbl_ref[i], vc_tbl_ref[i + 1])))
return i;
if ((adc_temp > DA9052_MEAN(vc_tbl_ref[i], vc_tbl_ref[i + 1]))
&& (adc_temp <= vc_tbl_ref[i]))
return i + 1;
}
WARN_ON(1);
return 0;
}
static int da9052_bat_read_capacity(struct da9052_battery *bat, int *capacity)
{
int adc_temp;
int bat_voltage;
int vbat_lower;
int vbat_upper;
int level_upper;
int level_lower;
int ret;
int flag;
int i = 0;
int j;
ret = da9052_bat_read_volt(bat, &bat_voltage);
if (ret < 0)
return ret;
adc_temp = da9052_adc_read_temp(bat->da9052);
if (adc_temp < 0)
return adc_temp;
i = da9052_determine_vc_tbl_index(adc_temp);
if (bat_voltage >= vc_tbl[i][0][0]) {
*capacity = 100;
return 0;
}
if (bat_voltage <= vc_tbl[i][DA9052_VC_TBL_SZ - 1][0]) {
*capacity = 0;
return 0;
}
flag = 0;
for (j = 0; j < (DA9052_VC_TBL_SZ-1); j++) {
if ((bat_voltage <= vc_tbl[i][j][0]) &&
(bat_voltage >= vc_tbl[i][j + 1][0])) {
vbat_upper = vc_tbl[i][j][0];
vbat_lower = vc_tbl[i][j + 1][0];
level_upper = vc_tbl[i][j][1];
level_lower = vc_tbl[i][j + 1][1];
flag = 1;
break;
}
}
if (!flag)
return -EIO;
*capacity = da9052_bat_interpolate(vbat_lower, vbat_upper, level_lower,
level_upper, bat_voltage);
return 0;
}
static int da9052_bat_check_health(struct da9052_battery *bat, int *health)
{
int ret;
int bat_illegal;
int capacity;
ret = da9052_bat_check_presence(bat, &bat_illegal);
if (ret < 0)
return ret;
if (bat_illegal) {
bat->health = POWER_SUPPLY_HEALTH_UNKNOWN;
return 0;
}
if (bat->health != POWER_SUPPLY_HEALTH_OVERHEAT) {
ret = da9052_bat_read_capacity(bat, &capacity);
if (ret < 0)
return ret;
if (capacity < DA9052_BAT_LOW_CAP)
bat->health = POWER_SUPPLY_HEALTH_DEAD;
else
bat->health = POWER_SUPPLY_HEALTH_GOOD;
}
*health = bat->health;
return 0;
}
static irqreturn_t da9052_bat_irq(int irq, void *data)
{
struct da9052_battery *bat = data;
irq -= bat->da9052->irq_base;
if (irq == DA9052_IRQ_CHGEND)
bat->status = POWER_SUPPLY_STATUS_FULL;
else
da9052_bat_check_status(bat, NULL);
if (irq == DA9052_IRQ_CHGEND || irq == DA9052_IRQ_DCIN ||
irq == DA9052_IRQ_VBUS || irq == DA9052_IRQ_TBAT) {
power_supply_changed(&bat->psy);
}
return IRQ_HANDLED;
}
static int da9052_USB_current_notifier(struct notifier_block *nb,
unsigned long events, void *data)
{
u8 row;
u8 col;
int *current_mA = data;
int ret;
struct da9052_battery *bat = container_of(nb, struct da9052_battery,
nb);
if (bat->status == POWER_SUPPLY_STATUS_DISCHARGING)
return -EPERM;
ret = da9052_reg_read(bat->da9052, DA9052_CHGBUCK_REG);
if (ret & DA9052_CHG_USB_ILIM_MASK)
return -EPERM;
if (bat->da9052->chip_id == DA9052)
row = 0;
else
row = 1;
if (*current_mA < da9052_chg_current_lim[row][0] ||
*current_mA > da9052_chg_current_lim[row][DA9052_CHG_LIM_COLS - 1])
return -EINVAL;
for (col = 0; col <= DA9052_CHG_LIM_COLS - 1 ; col++) {
if (*current_mA <= da9052_chg_current_lim[row][col])
break;
}
return da9052_reg_update(bat->da9052, DA9052_ISET_REG,
DA9052_ISET_USB_MASK, col);
}
static int da9052_bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret;
int illegal;
struct da9052_battery *bat = container_of(psy, struct da9052_battery,
psy);
ret = da9052_bat_check_presence(bat, &illegal);
if (ret < 0)
return ret;
if (illegal && psp != POWER_SUPPLY_PROP_PRESENT)
return -ENODEV;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = da9052_bat_check_status(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval =
(bat->charger_type == DA9052_NOCHARGER) ? 0 : 1;
break;
case POWER_SUPPLY_PROP_PRESENT:
ret = da9052_bat_check_presence(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = da9052_bat_check_health(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = DA9052_BAT_CUTOFF_VOLT * 1000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
ret = da9052_bat_read_volt(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
ret = da9052_read_chg_current(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = da9052_bat_read_capacity(bat, &val->intval);
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = da9052_adc_read_temp(bat->da9052);
ret = val->intval;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
default:
return -EINVAL;
}
return ret;
}
static s32 __devinit da9052_bat_probe(struct platform_device *pdev)
{
struct da9052_pdata *pdata;
struct da9052_battery *bat;
int ret;
int irq;
int i;
bat = kzalloc(sizeof(struct da9052_battery), GFP_KERNEL);
if (!bat)
return -ENOMEM;
bat->da9052 = dev_get_drvdata(pdev->dev.parent);
bat->psy = template_battery;
bat->charger_type = DA9052_NOCHARGER;
bat->status = POWER_SUPPLY_STATUS_UNKNOWN;
bat->health = POWER_SUPPLY_HEALTH_UNKNOWN;
bat->nb.notifier_call = da9052_USB_current_notifier;
pdata = bat->da9052->dev->platform_data;
if (pdata != NULL && pdata->use_for_apm)
bat->psy.use_for_apm = pdata->use_for_apm;
else
bat->psy.use_for_apm = 1;
for (i = 0; i < ARRAY_SIZE(da9052_bat_irqs); i++) {
irq = platform_get_irq_byname(pdev, da9052_bat_irqs[i]);
ret = request_threaded_irq(bat->da9052->irq_base + irq,
NULL, da9052_bat_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
da9052_bat_irqs[i], bat);
if (ret != 0) {
dev_err(bat->da9052->dev,
"DA9052 failed to request %s IRQ %d: %d\n",
da9052_bat_irqs[i], irq, ret);
goto err;
}
}
ret = power_supply_register(&pdev->dev, &bat->psy);
if (ret)
goto err;
platform_set_drvdata(pdev, bat);
return 0;
err:
while (--i >= 0) {
irq = platform_get_irq_byname(pdev, da9052_bat_irqs[i]);
free_irq(bat->da9052->irq_base + irq, bat);
}
kfree(bat);
return ret;
}
static int __devexit da9052_bat_remove(struct platform_device *pdev)
{
int i;
int irq;
struct da9052_battery *bat = platform_get_drvdata(pdev);
for (i = 0; i < ARRAY_SIZE(da9052_bat_irqs); i++) {
irq = platform_get_irq_byname(pdev, da9052_bat_irqs[i]);
free_irq(bat->da9052->irq_base + irq, bat);
}
power_supply_unregister(&bat->psy);
kfree(bat);
return 0;
}
