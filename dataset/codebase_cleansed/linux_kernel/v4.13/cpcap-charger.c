static bool cpcap_charger_battery_found(struct cpcap_charger_ddata *ddata)
{
struct iio_channel *channel;
int error, value;
channel = ddata->channels[CPCAP_CHARGER_IIO_BATTDET];
error = iio_read_channel_raw(channel, &value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
return false;
}
return value == 1;
}
static int cpcap_charger_get_charge_voltage(struct cpcap_charger_ddata *ddata)
{
struct iio_channel *channel;
int error, value = 0;
channel = ddata->channels[CPCAP_CHARGER_IIO_VOLTAGE];
error = iio_read_channel_processed(channel, &value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
return 0;
}
return value;
}
static int cpcap_charger_get_charge_current(struct cpcap_charger_ddata *ddata)
{
struct iio_channel *channel;
int error, value = 0;
channel = ddata->channels[CPCAP_CHARGER_IIO_CHRG_CURRENT];
error = iio_read_channel_processed(channel, &value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
return 0;
}
return value;
}
static int cpcap_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct cpcap_charger_ddata *ddata = dev_get_drvdata(psy->dev.parent);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = ddata->status;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (ddata->status == POWER_SUPPLY_STATUS_CHARGING)
val->intval = cpcap_charger_get_charge_voltage(ddata) *
1000;
else
val->intval = 0;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
if (ddata->status == POWER_SUPPLY_STATUS_CHARGING)
val->intval = cpcap_charger_get_charge_current(ddata) *
1000;
else
val->intval = 0;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = ddata->status == POWER_SUPPLY_STATUS_CHARGING;
break;
default:
return -EINVAL;
}
return 0;
}
static void cpcap_charger_set_cable_path(struct cpcap_charger_ddata *ddata,
bool enabled)
{
if (!ddata->gpio[0])
return;
gpiod_set_value(ddata->gpio[0], enabled);
}
static void cpcap_charger_set_inductive_path(struct cpcap_charger_ddata *ddata,
bool enabled)
{
if (!ddata->gpio[1])
return;
gpiod_set_value(ddata->gpio[1], enabled);
}
static int cpcap_charger_set_state(struct cpcap_charger_ddata *ddata,
int max_voltage, int charge_current,
int trickle_current)
{
bool enable;
int error;
enable = (charge_current || trickle_current);
dev_dbg(ddata->dev, "%s enable: %i\n", __func__, enable);
if (!enable) {
error = regmap_update_bits(ddata->reg, CPCAP_REG_CRM,
0x3fff,
CPCAP_REG_CRM_FET_OVRD |
CPCAP_REG_CRM_FET_CTRL);
if (error) {
ddata->status = POWER_SUPPLY_STATUS_UNKNOWN;
goto out_err;
}
ddata->status = POWER_SUPPLY_STATUS_DISCHARGING;
return 0;
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_CRM, 0x3fff,
CPCAP_REG_CRM_CHRG_LED_EN |
trickle_current |
CPCAP_REG_CRM_FET_OVRD |
CPCAP_REG_CRM_FET_CTRL |
max_voltage |
charge_current);
if (error) {
ddata->status = POWER_SUPPLY_STATUS_UNKNOWN;
goto out_err;
}
ddata->status = POWER_SUPPLY_STATUS_CHARGING;
return 0;
out_err:
dev_err(ddata->dev, "%s failed with %i\n", __func__, error);
return error;
}
static bool cpcap_charger_vbus_valid(struct cpcap_charger_ddata *ddata)
{
int error, value = 0;
struct iio_channel *channel =
ddata->channels[CPCAP_CHARGER_IIO_VBUS];
error = iio_read_channel_processed(channel, &value);
if (error >= 0)
return value > 3900 ? true : false;
dev_err(ddata->dev, "error reading VBUS: %i\n", error);
return false;
}
static void cpcap_charger_vbus_work(struct work_struct *work)
{
struct cpcap_charger_ddata *ddata;
bool vbus = false;
int error;
ddata = container_of(work, struct cpcap_charger_ddata,
vbus_work.work);
if (ddata->vbus_enabled) {
vbus = cpcap_charger_vbus_valid(ddata);
if (vbus) {
dev_info(ddata->dev, "VBUS already provided\n");
return;
}
cpcap_charger_set_cable_path(ddata, false);
cpcap_charger_set_inductive_path(ddata, false);
error = cpcap_charger_set_state(ddata, 0, 0, 0);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_CRM,
CPCAP_REG_CRM_RVRSMODE,
CPCAP_REG_CRM_RVRSMODE);
if (error)
goto out_err;
} else {
error = regmap_update_bits(ddata->reg, CPCAP_REG_CRM,
CPCAP_REG_CRM_RVRSMODE, 0);
if (error)
goto out_err;
cpcap_charger_set_cable_path(ddata, true);
cpcap_charger_set_inductive_path(ddata, true);
}
return;
out_err:
dev_err(ddata->dev, "%s could not %s vbus: %i\n", __func__,
ddata->vbus_enabled ? "enable" : "disable", error);
}
static int cpcap_charger_set_vbus(struct phy_companion *comparator,
bool enabled)
{
struct cpcap_charger_ddata *ddata =
container_of(comparator, struct cpcap_charger_ddata,
comparator);
ddata->vbus_enabled = enabled;
schedule_delayed_work(&ddata->vbus_work, 0);
return 0;
}
static int cpcap_charger_get_ints_state(struct cpcap_charger_ddata *ddata,
struct cpcap_charger_ints_state *s)
{
int val, error;
error = regmap_read(ddata->reg, CPCAP_REG_INTS1, &val);
if (error)
return error;
s->chrg_det = val & BIT(13);
s->rvrs_chrg = val & BIT(12);
s->vbusov = val & BIT(11);
error = regmap_read(ddata->reg, CPCAP_REG_INTS2, &val);
if (error)
return error;
s->chrg_se1b = val & BIT(13);
s->rvrs_mode = val & BIT(6);
s->chrgcurr1 = val & BIT(4);
s->vbusvld = val & BIT(3);
error = regmap_read(ddata->reg, CPCAP_REG_INTS4, &val);
if (error)
return error;
s->battdetb = val & BIT(6);
return 0;
}
static void cpcap_usb_detect(struct work_struct *work)
{
struct cpcap_charger_ddata *ddata;
struct cpcap_charger_ints_state s;
int error;
ddata = container_of(work, struct cpcap_charger_ddata,
detect_work.work);
error = cpcap_charger_get_ints_state(ddata, &s);
if (error)
return;
if (cpcap_charger_vbus_valid(ddata) && s.chrgcurr1) {
int max_current;
if (cpcap_charger_battery_found(ddata))
max_current = CPCAP_REG_CRM_ICHRG_1A596;
else
max_current = CPCAP_REG_CRM_ICHRG_0A532;
error = cpcap_charger_set_state(ddata,
CPCAP_REG_CRM_VCHRG_4V35,
max_current, 0);
if (error)
goto out_err;
} else {
error = cpcap_charger_set_state(ddata, 0, 0, 0);
if (error)
goto out_err;
}
return;
out_err:
dev_err(ddata->dev, "%s failed with %i\n", __func__, error);
}
static irqreturn_t cpcap_charger_irq_thread(int irq, void *data)
{
struct cpcap_charger_ddata *ddata = data;
if (!atomic_read(&ddata->active))
return IRQ_NONE;
schedule_delayed_work(&ddata->detect_work, 0);
return IRQ_HANDLED;
}
static int cpcap_usb_init_irq(struct platform_device *pdev,
struct cpcap_charger_ddata *ddata,
const char *name)
{
struct cpcap_interrupt_desc *d;
int irq, error;
irq = platform_get_irq_byname(pdev, name);
if (!irq)
return -ENODEV;
error = devm_request_threaded_irq(ddata->dev, irq, NULL,
cpcap_charger_irq_thread,
IRQF_SHARED,
name, ddata);
if (error) {
dev_err(ddata->dev, "could not get irq %s: %i\n",
name, error);
return error;
}
d = devm_kzalloc(ddata->dev, sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->name = name;
d->irq = irq;
list_add(&d->node, &ddata->irq_list);
return 0;
}
static int cpcap_usb_init_interrupts(struct platform_device *pdev,
struct cpcap_charger_ddata *ddata)
{
int i, error;
for (i = 0; i < ARRAY_SIZE(cpcap_charger_irqs); i++) {
error = cpcap_usb_init_irq(pdev, ddata, cpcap_charger_irqs[i]);
if (error)
return error;
}
return 0;
}
static void cpcap_charger_init_optional_gpios(struct cpcap_charger_ddata *ddata)
{
int i;
for (i = 0; i < 2; i++) {
ddata->gpio[i] = devm_gpiod_get_index(ddata->dev, "mode",
i, GPIOD_OUT_HIGH);
if (IS_ERR(ddata->gpio[i])) {
dev_info(ddata->dev, "no mode change GPIO%i: %li\n",
i, PTR_ERR(ddata->gpio[i]));
ddata->gpio[i] = NULL;
}
}
}
static int cpcap_charger_init_iio(struct cpcap_charger_ddata *ddata)
{
const char * const names[CPCAP_CHARGER_IIO_NR] = {
"battdetb", "battp", "vbus", "chg_isense", "batti",
};
int error, i;
for (i = 0; i < CPCAP_CHARGER_IIO_NR; i++) {
ddata->channels[i] = devm_iio_channel_get(ddata->dev,
names[i]);
if (IS_ERR(ddata->channels[i])) {
error = PTR_ERR(ddata->channels[i]);
goto out_err;
}
if (!ddata->channels[i]->indio_dev) {
error = -ENXIO;
goto out_err;
}
}
return 0;
out_err:
dev_err(ddata->dev, "could not initialize VBUS or ID IIO: %i\n",
error);
return error;
}
static int cpcap_charger_probe(struct platform_device *pdev)
{
struct cpcap_charger_ddata *ddata;
const struct of_device_id *of_id;
struct power_supply_config psy_cfg = {};
int error;
of_id = of_match_device(of_match_ptr(cpcap_charger_id_table),
&pdev->dev);
if (!of_id)
return -EINVAL;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
ddata->dev = &pdev->dev;
ddata->reg = dev_get_regmap(ddata->dev->parent, NULL);
if (!ddata->reg)
return -ENODEV;
INIT_LIST_HEAD(&ddata->irq_list);
INIT_DELAYED_WORK(&ddata->detect_work, cpcap_usb_detect);
INIT_DELAYED_WORK(&ddata->vbus_work, cpcap_charger_vbus_work);
platform_set_drvdata(pdev, ddata);
error = cpcap_charger_init_iio(ddata);
if (error)
return error;
atomic_set(&ddata->active, 1);
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = ddata;
ddata->usb = devm_power_supply_register(ddata->dev,
&cpcap_charger_usb_desc,
&psy_cfg);
if (IS_ERR(ddata->usb)) {
error = PTR_ERR(ddata->usb);
dev_err(ddata->dev, "failed to register USB charger: %i\n",
error);
return error;
}
error = cpcap_usb_init_interrupts(pdev, ddata);
if (error)
return error;
ddata->comparator.set_vbus = cpcap_charger_set_vbus;
error = omap_usb2_set_comparator(&ddata->comparator);
if (error == -ENODEV) {
dev_info(ddata->dev, "charger needs phy, deferring probe\n");
return -EPROBE_DEFER;
}
cpcap_charger_init_optional_gpios(ddata);
schedule_delayed_work(&ddata->detect_work, 0);
return 0;
}
static int cpcap_charger_remove(struct platform_device *pdev)
{
struct cpcap_charger_ddata *ddata = platform_get_drvdata(pdev);
int error;
atomic_set(&ddata->active, 0);
error = omap_usb2_set_comparator(NULL);
if (error)
dev_warn(ddata->dev, "could not clear USB comparator: %i\n",
error);
error = cpcap_charger_set_state(ddata, 0, 0, 0);
if (error)
dev_warn(ddata->dev, "could not clear charger: %i\n",
error);
cancel_delayed_work_sync(&ddata->vbus_work);
cancel_delayed_work_sync(&ddata->detect_work);
return 0;
}
