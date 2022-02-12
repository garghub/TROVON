static int smbb_vbat_weak_fn(unsigned int index)
{
return 2100000 + index * 100000;
}
static int smbb_vin_fn(unsigned int index)
{
if (index > 42)
return 5600000 + (index - 43) * 200000;
return 3400000 + index * 50000;
}
static int smbb_vmax_fn(unsigned int index)
{
return 3240000 + index * 10000;
}
static int smbb_vbat_det_fn(unsigned int index)
{
return 3240000 + index * 20000;
}
static int smbb_imax_fn(unsigned int index)
{
if (index < 2)
return 100000 + index * 50000;
return index * 100000;
}
static int smbb_bat_imax_fn(unsigned int index)
{
return index * 50000;
}
static unsigned int smbb_hw_lookup(unsigned int val, int (*fn)(unsigned int))
{
unsigned int widx;
unsigned int sel;
for (widx = sel = 0; (*fn)(widx) <= val; ++widx)
sel = widx;
return sel;
}
static int smbb_charger_attr_write(struct smbb_charger *chg,
enum smbb_attr which, unsigned int val)
{
const struct smbb_charger_attr *prop;
unsigned int wval;
unsigned int out;
int rc;
prop = &smbb_charger_attrs[which];
if (val > prop->max || val < prop->min) {
dev_err(chg->dev, "value out of range for %s [%u:%u]\n",
prop->name, prop->min, prop->max);
return -EINVAL;
}
if (prop->safe_reg) {
rc = regmap_read(chg->regmap,
chg->addr + prop->safe_reg, &wval);
if (rc) {
dev_err(chg->dev,
"unable to read safe value for '%s'\n",
prop->name);
return rc;
}
wval = prop->hw_fn(wval);
if (val > wval) {
dev_warn(chg->dev,
"%s above safe value, clamping at %u\n",
prop->name, wval);
val = wval;
}
}
wval = smbb_hw_lookup(val, prop->hw_fn);
rc = regmap_write(chg->regmap, chg->addr + prop->reg, wval);
if (rc) {
dev_err(chg->dev, "unable to update %s", prop->name);
return rc;
}
out = prop->hw_fn(wval);
if (out != val) {
dev_warn(chg->dev,
"%s inaccurate, rounded to %u\n",
prop->name, out);
}
dev_dbg(chg->dev, "%s <= %d\n", prop->name, out);
chg->attr[which] = out;
return 0;
}
static int smbb_charger_attr_read(struct smbb_charger *chg,
enum smbb_attr which)
{
const struct smbb_charger_attr *prop;
unsigned int val;
int rc;
prop = &smbb_charger_attrs[which];
rc = regmap_read(chg->regmap, chg->addr + prop->reg, &val);
if (rc) {
dev_err(chg->dev, "failed to read %s\n", prop->name);
return rc;
}
val = prop->hw_fn(val);
dev_dbg(chg->dev, "%s => %d\n", prop->name, val);
chg->attr[which] = val;
return 0;
}
static int smbb_charger_attr_parse(struct smbb_charger *chg,
enum smbb_attr which)
{
const struct smbb_charger_attr *prop;
unsigned int val;
int rc;
prop = &smbb_charger_attrs[which];
rc = of_property_read_u32(chg->dev->of_node, prop->name, &val);
if (rc == 0) {
rc = smbb_charger_attr_write(chg, which, val);
if (!rc || !prop->fail_ok)
return rc;
}
return smbb_charger_attr_read(chg, which);
}
static void smbb_set_line_flag(struct smbb_charger *chg, int irq, int flag)
{
bool state;
int ret;
ret = irq_get_irqchip_state(irq, IRQCHIP_STATE_LINE_LEVEL, &state);
if (ret < 0) {
dev_err(chg->dev, "failed to read irq line\n");
return;
}
mutex_lock(&chg->statlock);
if (state)
chg->status |= flag;
else
chg->status &= ~flag;
mutex_unlock(&chg->statlock);
dev_dbg(chg->dev, "status = %03lx\n", chg->status);
}
static irqreturn_t smbb_usb_valid_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_USBIN_VALID);
power_supply_changed(chg->usb_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_dc_valid_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_DCIN_VALID);
if (!chg->dc_disabled)
power_supply_changed(chg->dc_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_bat_temp_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
unsigned int val;
int rc;
rc = regmap_read(chg->regmap, chg->addr + SMBB_BAT_TEMP_STATUS, &val);
if (rc)
return IRQ_HANDLED;
mutex_lock(&chg->statlock);
if (val & TEMP_STATUS_OK) {
chg->status |= STATUS_BAT_OK;
} else {
chg->status &= ~STATUS_BAT_OK;
if (val & TEMP_STATUS_HOT)
chg->status |= STATUS_BAT_HOT;
}
mutex_unlock(&chg->statlock);
power_supply_changed(chg->bat_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_bat_present_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_BAT_PRESENT);
power_supply_changed(chg->bat_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_chg_done_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_CHG_DONE);
power_supply_changed(chg->bat_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_chg_gone_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_CHG_GONE);
power_supply_changed(chg->bat_psy);
power_supply_changed(chg->usb_psy);
if (!chg->dc_disabled)
power_supply_changed(chg->dc_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_chg_fast_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_CHG_FAST);
power_supply_changed(chg->bat_psy);
return IRQ_HANDLED;
}
static irqreturn_t smbb_chg_trkl_handler(int irq, void *_data)
{
struct smbb_charger *chg = _data;
smbb_set_line_flag(chg, irq, STATUS_CHG_TRKL);
power_supply_changed(chg->bat_psy);
return IRQ_HANDLED;
}
static int smbb_usbin_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
int rc = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
mutex_lock(&chg->statlock);
val->intval = !(chg->status & STATUS_CHG_GONE) &&
(chg->status & STATUS_USBIN_VALID);
mutex_unlock(&chg->statlock);
break;
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
val->intval = chg->attr[ATTR_USBIN_IMAX];
break;
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX:
val->intval = 2500000;
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_usbin_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
int rc;
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
rc = smbb_charger_attr_write(chg, ATTR_USBIN_IMAX,
val->intval);
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_dcin_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
int rc = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
mutex_lock(&chg->statlock);
val->intval = !(chg->status & STATUS_CHG_GONE) &&
(chg->status & STATUS_DCIN_VALID);
mutex_unlock(&chg->statlock);
break;
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
val->intval = chg->attr[ATTR_DCIN_IMAX];
break;
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX:
val->intval = 2500000;
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_dcin_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
int rc;
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
rc = smbb_charger_attr_write(chg, ATTR_DCIN_IMAX,
val->intval);
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_charger_writable_property(struct power_supply *psy,
enum power_supply_property psp)
{
return psp == POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT;
}
static int smbb_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
unsigned long status;
int rc = 0;
mutex_lock(&chg->statlock);
status = chg->status;
mutex_unlock(&chg->statlock);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (status & STATUS_CHG_GONE)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (!(status & (STATUS_DCIN_VALID | STATUS_USBIN_VALID)))
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (status & STATUS_CHG_DONE)
val->intval = POWER_SUPPLY_STATUS_FULL;
else if (!(status & STATUS_BAT_OK))
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (status & (STATUS_CHG_FAST | STATUS_CHG_TRKL))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_HEALTH:
if (status & STATUS_BAT_OK)
val->intval = POWER_SUPPLY_HEALTH_GOOD;
else if (status & STATUS_BAT_HOT)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else
val->intval = POWER_SUPPLY_HEALTH_COLD;
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
if (status & STATUS_CHG_FAST)
val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
else if (status & STATUS_CHG_TRKL)
val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
else
val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = !!(status & STATUS_BAT_PRESENT);
break;
case POWER_SUPPLY_PROP_CURRENT_MAX:
val->intval = chg->attr[ATTR_BAT_IMAX];
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX:
val->intval = chg->attr[ATTR_BAT_VMAX];
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = 3000000;
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_battery_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct smbb_charger *chg = power_supply_get_drvdata(psy);
int rc;
switch (psp) {
case POWER_SUPPLY_PROP_CURRENT_MAX:
rc = smbb_charger_attr_write(chg, ATTR_BAT_IMAX, val->intval);
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX:
rc = smbb_charger_attr_write(chg, ATTR_BAT_VMAX, val->intval);
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static int smbb_battery_writable_property(struct power_supply *psy,
enum power_supply_property psp)
{
switch (psp) {
case POWER_SUPPLY_PROP_CURRENT_MAX:
case POWER_SUPPLY_PROP_VOLTAGE_MAX:
return 1;
default:
return 0;
}
}
static int smbb_charger_probe(struct platform_device *pdev)
{
struct power_supply_config bat_cfg = {};
struct power_supply_config usb_cfg = {};
struct power_supply_config dc_cfg = {};
struct smbb_charger *chg;
int rc, i;
chg = devm_kzalloc(&pdev->dev, sizeof(*chg), GFP_KERNEL);
if (!chg)
return -ENOMEM;
chg->dev = &pdev->dev;
mutex_init(&chg->statlock);
chg->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!chg->regmap) {
dev_err(&pdev->dev, "failed to locate regmap\n");
return -ENODEV;
}
rc = of_property_read_u32(pdev->dev.of_node, "reg", &chg->addr);
if (rc) {
dev_err(&pdev->dev, "missing or invalid 'reg' property\n");
return rc;
}
rc = regmap_read(chg->regmap, chg->addr + SMBB_MISC_REV2, &chg->revision);
if (rc) {
dev_err(&pdev->dev, "unable to read revision\n");
return rc;
}
chg->revision += 1;
if (chg->revision != 2 && chg->revision != 3) {
dev_err(&pdev->dev, "v1 hardware not supported\n");
return -ENODEV;
}
dev_info(&pdev->dev, "Initializing SMBB rev %u", chg->revision);
chg->dc_disabled = of_property_read_bool(pdev->dev.of_node, "qcom,disable-dc");
for (i = 0; i < _ATTR_CNT; ++i) {
rc = smbb_charger_attr_parse(chg, i);
if (rc) {
dev_err(&pdev->dev, "failed to parse/apply settings\n");
return rc;
}
}
bat_cfg.drv_data = chg;
bat_cfg.of_node = pdev->dev.of_node;
chg->bat_psy = devm_power_supply_register(&pdev->dev,
&bat_psy_desc,
&bat_cfg);
if (IS_ERR(chg->bat_psy)) {
dev_err(&pdev->dev, "failed to register battery\n");
return PTR_ERR(chg->bat_psy);
}
usb_cfg.drv_data = chg;
usb_cfg.supplied_to = smbb_bif;
usb_cfg.num_supplicants = ARRAY_SIZE(smbb_bif);
chg->usb_psy = devm_power_supply_register(&pdev->dev,
&usb_psy_desc,
&usb_cfg);
if (IS_ERR(chg->usb_psy)) {
dev_err(&pdev->dev, "failed to register USB power supply\n");
return PTR_ERR(chg->usb_psy);
}
if (!chg->dc_disabled) {
dc_cfg.drv_data = chg;
dc_cfg.supplied_to = smbb_bif;
dc_cfg.num_supplicants = ARRAY_SIZE(smbb_bif);
chg->dc_psy = devm_power_supply_register(&pdev->dev,
&dc_psy_desc,
&dc_cfg);
if (IS_ERR(chg->dc_psy)) {
dev_err(&pdev->dev, "failed to register DC power supply\n");
return PTR_ERR(chg->dc_psy);
}
}
for (i = 0; i < ARRAY_SIZE(smbb_charger_irqs); ++i) {
int irq;
irq = platform_get_irq_byname(pdev, smbb_charger_irqs[i].name);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq '%s'\n",
smbb_charger_irqs[i].name);
return irq;
}
smbb_charger_irqs[i].handler(irq, chg);
rc = devm_request_threaded_irq(&pdev->dev, irq, NULL,
smbb_charger_irqs[i].handler, IRQF_ONESHOT,
smbb_charger_irqs[i].name, chg);
if (rc) {
dev_err(&pdev->dev, "failed to request irq '%s'\n",
smbb_charger_irqs[i].name);
return rc;
}
}
chg->jeita_ext_temp = of_property_read_bool(pdev->dev.of_node,
"qcom,jeita-extended-temp-range");
rc = regmap_update_bits(chg->regmap, chg->addr + SMBB_BAT_BTC_CTRL,
BTC_CTRL_COLD_EXT | BTC_CTRL_HOT_EXT_N,
chg->jeita_ext_temp ?
BTC_CTRL_COLD_EXT :
BTC_CTRL_HOT_EXT_N);
if (rc) {
dev_err(&pdev->dev,
"unable to set %s temperature range\n",
chg->jeita_ext_temp ? "JEITA extended" : "normal");
return rc;
}
for (i = 0; i < ARRAY_SIZE(smbb_charger_setup); ++i) {
const struct reg_off_mask_default *r = &smbb_charger_setup[i];
if (r->rev_mask & BIT(chg->revision))
continue;
rc = regmap_update_bits(chg->regmap, chg->addr + r->offset,
r->mask, r->value);
if (rc) {
dev_err(&pdev->dev,
"unable to initializing charging, bailing\n");
return rc;
}
}
platform_set_drvdata(pdev, chg);
return 0;
}
static int smbb_charger_remove(struct platform_device *pdev)
{
struct smbb_charger *chg;
chg = platform_get_drvdata(pdev);
regmap_update_bits(chg->regmap, chg->addr + SMBB_CHG_CTRL, CTRL_EN, 0);
return 0;
}
