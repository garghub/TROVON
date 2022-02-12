static int twl4030_clear_set(u8 mod_no, u8 clear, u8 set, u8 reg)
{
u8 val = 0;
int ret;
ret = twl_i2c_read_u8(mod_no, &val, reg);
if (ret)
return ret;
val &= ~clear;
val |= set;
return twl_i2c_write_u8(mod_no, val, reg);
}
static int twl4030_bci_read(u8 reg, u8 *val)
{
return twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE, val, reg);
}
static int twl4030_clear_set_boot_bci(u8 clear, u8 set)
{
return twl4030_clear_set(TWL_MODULE_PM_MASTER, clear,
TWL4030_CONFIG_DONE | TWL4030_BCIAUTOWEN | set,
TWL4030_PM_MASTER_BOOT_BCI);
}
static int twl4030bci_read_adc_val(u8 reg)
{
int ret, temp;
u8 val;
ret = twl4030_bci_read(reg + 1, &val);
if (ret)
return ret;
temp = (int)(val & 0x03) << 8;
ret = twl4030_bci_read(reg, &val);
if (ret)
return ret;
return temp | val;
}
static int twl4030_is_battery_present(struct twl4030_bci *bci)
{
int ret;
u8 val = 0;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE, &val, TWL4030_BCIMFSTS3);
if (ret)
return ret;
if (val & TWL4030_BATSTSMCHG)
return 0;
ret = twl_i2c_read_u8(TWL4030_MODULE_PRECHARGE, &val,
TWL4030_BCIMFSTS1);
if (ret)
return ret;
if (val & TWL4030_BATSTSPCHG)
return 0;
return -ENODEV;
}
static int twl4030_bci_have_vbus(struct twl4030_bci *bci)
{
int ret;
u8 hwsts;
ret = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &hwsts,
TWL4030_PM_MASTER_STS_HW_CONDITIONS);
if (ret < 0)
return 0;
dev_dbg(bci->dev, "check_vbus: HW_CONDITIONS %02x\n", hwsts);
if ((hwsts & TWL4030_STS_VBUS) && !(hwsts & TWL4030_STS_USB_ID))
return 1;
return 0;
}
static int twl4030_charger_enable_usb(struct twl4030_bci *bci, bool enable)
{
int ret;
if (enable) {
if (!twl4030_bci_have_vbus(bci))
return -ENODEV;
if (!allow_usb) {
dev_warn(bci->dev, "USB charging is disabled.\n");
return -EACCES;
}
if (!bci->usb_enabled) {
ret = regulator_enable(bci->usb_reg);
if (ret) {
dev_err(bci->dev,
"Failed to enable regulator\n");
return ret;
}
bci->usb_enabled = 1;
}
ret = twl4030_clear_set_boot_bci(0, TWL4030_BCIAUTOUSB);
if (ret < 0)
return ret;
ret = twl4030_clear_set(TWL_MODULE_MAIN_CHARGE, 0,
TWL4030_USBFASTMCHG, TWL4030_BCIMFSTS4);
} else {
ret = twl4030_clear_set_boot_bci(TWL4030_BCIAUTOUSB, 0);
if (bci->usb_enabled) {
regulator_disable(bci->usb_reg);
bci->usb_enabled = 0;
}
}
return ret;
}
static int twl4030_charger_enable_ac(bool enable)
{
int ret;
if (enable)
ret = twl4030_clear_set_boot_bci(0, TWL4030_BCIAUTOAC);
else
ret = twl4030_clear_set_boot_bci(TWL4030_BCIAUTOAC, 0);
return ret;
}
static int twl4030_charger_enable_backup(int uvolt, int uamp)
{
int ret;
u8 flags;
if (uvolt < 2500000 ||
uamp < 25) {
ret = twl4030_clear_set(TWL_MODULE_PM_RECEIVER,
TWL4030_BBCHEN, 0, TWL4030_BB_CFG);
return ret;
}
flags = TWL4030_BBCHEN;
if (uvolt >= 3200000)
flags |= TWL4030_BBSEL_3V2;
else if (uvolt >= 3100000)
flags |= TWL4030_BBSEL_3V1;
else if (uvolt >= 3000000)
flags |= TWL4030_BBSEL_3V0;
else
flags |= TWL4030_BBSEL_2V5;
if (uamp >= 1000)
flags |= TWL4030_BBISEL_1000uA;
else if (uamp >= 500)
flags |= TWL4030_BBISEL_500uA;
else if (uamp >= 150)
flags |= TWL4030_BBISEL_150uA;
else
flags |= TWL4030_BBISEL_25uA;
ret = twl4030_clear_set(TWL_MODULE_PM_RECEIVER,
TWL4030_BBSEL_MASK | TWL4030_BBISEL_MASK,
flags,
TWL4030_BB_CFG);
return ret;
}
static irqreturn_t twl4030_charger_interrupt(int irq, void *arg)
{
struct twl4030_bci *bci = arg;
dev_dbg(bci->dev, "CHG_PRES irq\n");
power_supply_changed(bci->ac);
power_supply_changed(bci->usb);
return IRQ_HANDLED;
}
static irqreturn_t twl4030_bci_interrupt(int irq, void *arg)
{
struct twl4030_bci *bci = arg;
u8 irqs1, irqs2;
int ret;
ret = twl_i2c_read_u8(TWL4030_MODULE_INTERRUPTS, &irqs1,
TWL4030_INTERRUPTS_BCIISR1A);
if (ret < 0)
return IRQ_HANDLED;
ret = twl_i2c_read_u8(TWL4030_MODULE_INTERRUPTS, &irqs2,
TWL4030_INTERRUPTS_BCIISR2A);
if (ret < 0)
return IRQ_HANDLED;
dev_dbg(bci->dev, "BCI irq %02x %02x\n", irqs2, irqs1);
if (irqs1 & (TWL4030_ICHGLOW | TWL4030_ICHGEOC)) {
power_supply_changed(bci->ac);
power_supply_changed(bci->usb);
}
if (irqs1 & (TWL4030_TBATOR2 | TWL4030_TBATOR1))
dev_warn(bci->dev, "battery temperature out of range\n");
if (irqs1 & TWL4030_BATSTS)
dev_crit(bci->dev, "battery disconnected\n");
if (irqs2 & TWL4030_VBATOV)
dev_crit(bci->dev, "VBAT overvoltage\n");
if (irqs2 & TWL4030_VBUSOV)
dev_crit(bci->dev, "VBUS overvoltage\n");
if (irqs2 & TWL4030_ACCHGOV)
dev_crit(bci->dev, "Ac charger overvoltage\n");
return IRQ_HANDLED;
}
static void twl4030_bci_usb_work(struct work_struct *data)
{
struct twl4030_bci *bci = container_of(data, struct twl4030_bci, work);
switch (bci->event) {
case USB_EVENT_VBUS:
case USB_EVENT_CHARGER:
twl4030_charger_enable_usb(bci, true);
break;
case USB_EVENT_NONE:
twl4030_charger_enable_usb(bci, false);
break;
}
}
static int twl4030_bci_usb_ncb(struct notifier_block *nb, unsigned long val,
void *priv)
{
struct twl4030_bci *bci = container_of(nb, struct twl4030_bci, usb_nb);
dev_dbg(bci->dev, "OTG notify %lu\n", val);
bci->event = val;
schedule_work(&bci->work);
return NOTIFY_OK;
}
static int twl4030_charger_get_current(void)
{
int curr;
int ret;
u8 bcictl1;
curr = twl4030bci_read_adc_val(TWL4030_BCIICHG);
if (curr < 0)
return curr;
ret = twl4030_bci_read(TWL4030_BCICTL1, &bcictl1);
if (ret)
return ret;
ret = (curr * 16618 - 850 * 10000) / 10;
if (bcictl1 & TWL4030_CGAIN)
ret *= 2;
return ret;
}
static int twl4030bci_state(struct twl4030_bci *bci)
{
int ret;
u8 state;
ret = twl4030_bci_read(TWL4030_BCIMSTATEC, &state);
if (ret) {
pr_err("twl4030_bci: error reading BCIMSTATEC\n");
return ret;
}
dev_dbg(bci->dev, "state: %02x\n", state);
return state;
}
static int twl4030_bci_state_to_status(int state)
{
state &= TWL4030_MSTATEC_MASK;
if (TWL4030_MSTATEC_QUICK1 <= state && state <= TWL4030_MSTATEC_QUICK7)
return POWER_SUPPLY_STATUS_CHARGING;
else if (TWL4030_MSTATEC_COMPLETE1 <= state &&
state <= TWL4030_MSTATEC_COMPLETE4)
return POWER_SUPPLY_STATUS_FULL;
else
return POWER_SUPPLY_STATUS_NOT_CHARGING;
}
static int twl4030_bci_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct twl4030_bci *bci = dev_get_drvdata(psy->dev.parent);
int is_charging;
int state;
int ret;
state = twl4030bci_state(bci);
if (state < 0)
return state;
if (psy->desc->type == POWER_SUPPLY_TYPE_USB)
is_charging = state & TWL4030_MSTATEC_USB;
else
is_charging = state & TWL4030_MSTATEC_AC;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (is_charging)
val->intval = twl4030_bci_state_to_status(state);
else
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (!is_charging)
return -ENODATA;
if (psy->desc->type == POWER_SUPPLY_TYPE_USB) {
ret = twl4030bci_read_adc_val(TWL4030_BCIVBUS);
if (ret < 0)
return ret;
val->intval = ret * 6843;
} else {
ret = twl4030bci_read_adc_val(TWL4030_BCIVAC);
if (ret < 0)
return ret;
val->intval = ret * 9775;
}
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
if (!is_charging)
return -ENODATA;
ret = twl4030_charger_get_current();
if (ret < 0)
return ret;
val->intval = ret;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = is_charging &&
twl4030_bci_state_to_status(state) !=
POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
default:
return -EINVAL;
}
return 0;
}
static const struct twl4030_bci_platform_data *
twl4030_bci_parse_dt(struct device *dev)
{
struct device_node *np = dev->of_node;
struct twl4030_bci_platform_data *pdata;
u32 num;
if (!np)
return NULL;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return pdata;
if (of_property_read_u32(np, "ti,bb-uvolt", &num) == 0)
pdata->bb_uvolt = num;
if (of_property_read_u32(np, "ti,bb-uamp", &num) == 0)
pdata->bb_uamp = num;
return pdata;
}
static inline const struct twl4030_bci_platform_data *
twl4030_bci_parse_dt(struct device *dev)
{
return NULL;
}
static int __init twl4030_bci_probe(struct platform_device *pdev)
{
struct twl4030_bci *bci;
const struct twl4030_bci_platform_data *pdata = pdev->dev.platform_data;
int ret;
u32 reg;
bci = kzalloc(sizeof(*bci), GFP_KERNEL);
if (bci == NULL)
return -ENOMEM;
if (!pdata)
pdata = twl4030_bci_parse_dt(&pdev->dev);
bci->dev = &pdev->dev;
bci->irq_chg = platform_get_irq(pdev, 0);
bci->irq_bci = platform_get_irq(pdev, 1);
ret = twl4030_is_battery_present(bci);
if (ret) {
dev_crit(&pdev->dev, "Battery was not detected:%d\n", ret);
goto fail_no_battery;
}
platform_set_drvdata(pdev, bci);
bci->ac = power_supply_register(&pdev->dev, &twl4030_bci_ac_desc,
NULL);
if (IS_ERR(bci->ac)) {
ret = PTR_ERR(bci->ac);
dev_err(&pdev->dev, "failed to register ac: %d\n", ret);
goto fail_register_ac;
}
bci->usb_reg = regulator_get(bci->dev, "bci3v1");
bci->usb = power_supply_register(&pdev->dev, &twl4030_bci_usb_desc,
NULL);
if (IS_ERR(bci->usb)) {
ret = PTR_ERR(bci->usb);
dev_err(&pdev->dev, "failed to register usb: %d\n", ret);
goto fail_register_usb;
}
ret = request_threaded_irq(bci->irq_chg, NULL,
twl4030_charger_interrupt, IRQF_ONESHOT, pdev->name,
bci);
if (ret < 0) {
dev_err(&pdev->dev, "could not request irq %d, status %d\n",
bci->irq_chg, ret);
goto fail_chg_irq;
}
ret = request_threaded_irq(bci->irq_bci, NULL,
twl4030_bci_interrupt, IRQF_ONESHOT, pdev->name, bci);
if (ret < 0) {
dev_err(&pdev->dev, "could not request irq %d, status %d\n",
bci->irq_bci, ret);
goto fail_bci_irq;
}
INIT_WORK(&bci->work, twl4030_bci_usb_work);
bci->usb_nb.notifier_call = twl4030_bci_usb_ncb;
if (bci->dev->of_node) {
struct device_node *phynode;
phynode = of_find_compatible_node(bci->dev->of_node->parent,
NULL, "ti,twl4030-usb");
if (phynode)
bci->transceiver = devm_usb_get_phy_by_node(
bci->dev, phynode, &bci->usb_nb);
}
reg = ~(u32)(TWL4030_ICHGLOW | TWL4030_ICHGEOC | TWL4030_TBATOR2 |
TWL4030_TBATOR1 | TWL4030_BATSTS);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTERRUPTS, reg,
TWL4030_INTERRUPTS_BCIIMR1A);
if (ret < 0) {
dev_err(&pdev->dev, "failed to unmask interrupts: %d\n", ret);
goto fail_unmask_interrupts;
}
reg = ~(u32)(TWL4030_VBATOV | TWL4030_VBUSOV | TWL4030_ACCHGOV);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTERRUPTS, reg,
TWL4030_INTERRUPTS_BCIIMR2A);
if (ret < 0)
dev_warn(&pdev->dev, "failed to unmask interrupts: %d\n", ret);
twl4030_charger_enable_ac(true);
twl4030_charger_enable_usb(bci, true);
if (pdata)
twl4030_charger_enable_backup(pdata->bb_uvolt,
pdata->bb_uamp);
else
twl4030_charger_enable_backup(0, 0);
return 0;
fail_unmask_interrupts:
free_irq(bci->irq_bci, bci);
fail_bci_irq:
free_irq(bci->irq_chg, bci);
fail_chg_irq:
power_supply_unregister(bci->usb);
fail_register_usb:
power_supply_unregister(bci->ac);
fail_register_ac:
fail_no_battery:
kfree(bci);
return ret;
}
static int __exit twl4030_bci_remove(struct platform_device *pdev)
{
struct twl4030_bci *bci = platform_get_drvdata(pdev);
twl4030_charger_enable_ac(false);
twl4030_charger_enable_usb(bci, false);
twl4030_charger_enable_backup(0, 0);
twl_i2c_write_u8(TWL4030_MODULE_INTERRUPTS, 0xff,
TWL4030_INTERRUPTS_BCIIMR1A);
twl_i2c_write_u8(TWL4030_MODULE_INTERRUPTS, 0xff,
TWL4030_INTERRUPTS_BCIIMR2A);
free_irq(bci->irq_bci, bci);
free_irq(bci->irq_chg, bci);
power_supply_unregister(bci->usb);
power_supply_unregister(bci->ac);
kfree(bci);
return 0;
}
