static int max8903_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max8903_data *data = container_of(psy,
struct max8903_data, psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
if (data->pdata.chg) {
if (gpio_get_value(data->pdata.chg) == 0)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (data->usb_in || data->ta_in)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
}
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = 0;
if (data->usb_in || data->ta_in)
val->intval = 1;
break;
case POWER_SUPPLY_PROP_HEALTH:
val->intval = POWER_SUPPLY_HEALTH_GOOD;
if (data->fault)
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
default:
return -EINVAL;
}
return 0;
}
static irqreturn_t max8903_dcin(int irq, void *_data)
{
struct max8903_data *data = _data;
struct max8903_pdata *pdata = &data->pdata;
bool ta_in;
enum power_supply_type old_type;
ta_in = gpio_get_value(pdata->dok) ? false : true;
if (ta_in == data->ta_in)
return IRQ_HANDLED;
data->ta_in = ta_in;
if (pdata->dcm)
gpio_set_value(pdata->dcm, ta_in ? 1 : 0);
if (pdata->cen)
gpio_set_value(pdata->cen, ta_in ? 0 :
(data->usb_in ? 0 : 1));
dev_dbg(data->dev, "TA(DC-IN) Charger %s.\n", ta_in ?
"Connected" : "Disconnected");
old_type = data->psy.type;
if (data->ta_in)
data->psy.type = POWER_SUPPLY_TYPE_MAINS;
else if (data->usb_in)
data->psy.type = POWER_SUPPLY_TYPE_USB;
else
data->psy.type = POWER_SUPPLY_TYPE_BATTERY;
if (old_type != data->psy.type)
power_supply_changed(&data->psy);
return IRQ_HANDLED;
}
static irqreturn_t max8903_usbin(int irq, void *_data)
{
struct max8903_data *data = _data;
struct max8903_pdata *pdata = &data->pdata;
bool usb_in;
enum power_supply_type old_type;
usb_in = gpio_get_value(pdata->uok) ? false : true;
if (usb_in == data->usb_in)
return IRQ_HANDLED;
data->usb_in = usb_in;
if (pdata->cen)
gpio_set_value(pdata->cen, usb_in ? 0 :
(data->ta_in ? 0 : 1));
dev_dbg(data->dev, "USB Charger %s.\n", usb_in ?
"Connected" : "Disconnected");
old_type = data->psy.type;
if (data->ta_in)
data->psy.type = POWER_SUPPLY_TYPE_MAINS;
else if (data->usb_in)
data->psy.type = POWER_SUPPLY_TYPE_USB;
else
data->psy.type = POWER_SUPPLY_TYPE_BATTERY;
if (old_type != data->psy.type)
power_supply_changed(&data->psy);
return IRQ_HANDLED;
}
static irqreturn_t max8903_fault(int irq, void *_data)
{
struct max8903_data *data = _data;
struct max8903_pdata *pdata = &data->pdata;
bool fault;
fault = gpio_get_value(pdata->flt) ? false : true;
if (fault == data->fault)
return IRQ_HANDLED;
data->fault = fault;
if (fault)
dev_err(data->dev, "Charger suffers a fault and stops.\n");
else
dev_err(data->dev, "Charger recovered from a fault.\n");
return IRQ_HANDLED;
}
static __devinit int max8903_probe(struct platform_device *pdev)
{
struct max8903_data *data;
struct device *dev = &pdev->dev;
struct max8903_pdata *pdata = pdev->dev.platform_data;
int ret = 0;
int gpio;
int ta_in = 0;
int usb_in = 0;
data = kzalloc(sizeof(struct max8903_data), GFP_KERNEL);
if (data == NULL) {
dev_err(dev, "Cannot allocate memory.\n");
return -ENOMEM;
}
memcpy(&data->pdata, pdata, sizeof(struct max8903_pdata));
data->dev = dev;
platform_set_drvdata(pdev, data);
if (pdata->dc_valid == false && pdata->usb_valid == false) {
dev_err(dev, "No valid power sources.\n");
ret = -EINVAL;
goto err;
}
if (pdata->dc_valid) {
if (pdata->dok && gpio_is_valid(pdata->dok) &&
pdata->dcm && gpio_is_valid(pdata->dcm)) {
gpio = pdata->dok;
ta_in = gpio_get_value(gpio) ? 0 : 1;
gpio = pdata->dcm;
gpio_set_value(gpio, ta_in);
} else {
dev_err(dev, "When DC is wired, DOK and DCM should"
" be wired as well.\n");
ret = -EINVAL;
goto err;
}
} else {
if (pdata->dcm) {
if (gpio_is_valid(pdata->dcm))
gpio_set_value(pdata->dcm, 0);
else {
dev_err(dev, "Invalid pin: dcm.\n");
ret = -EINVAL;
goto err;
}
}
}
if (pdata->usb_valid) {
if (pdata->uok && gpio_is_valid(pdata->uok)) {
gpio = pdata->uok;
usb_in = gpio_get_value(gpio) ? 0 : 1;
} else {
dev_err(dev, "When USB is wired, UOK should be wired."
"as well.\n");
ret = -EINVAL;
goto err;
}
}
if (pdata->cen) {
if (gpio_is_valid(pdata->cen)) {
gpio_set_value(pdata->cen, (ta_in || usb_in) ? 0 : 1);
} else {
dev_err(dev, "Invalid pin: cen.\n");
ret = -EINVAL;
goto err;
}
}
if (pdata->chg) {
if (!gpio_is_valid(pdata->chg)) {
dev_err(dev, "Invalid pin: chg.\n");
ret = -EINVAL;
goto err;
}
}
if (pdata->flt) {
if (!gpio_is_valid(pdata->flt)) {
dev_err(dev, "Invalid pin: flt.\n");
ret = -EINVAL;
goto err;
}
}
if (pdata->usus) {
if (!gpio_is_valid(pdata->usus)) {
dev_err(dev, "Invalid pin: usus.\n");
ret = -EINVAL;
goto err;
}
}
data->fault = false;
data->ta_in = ta_in;
data->usb_in = usb_in;
data->psy.name = "max8903_charger";
data->psy.type = (ta_in) ? POWER_SUPPLY_TYPE_MAINS :
((usb_in) ? POWER_SUPPLY_TYPE_USB :
POWER_SUPPLY_TYPE_BATTERY);
data->psy.get_property = max8903_get_property;
data->psy.properties = max8903_charger_props;
data->psy.num_properties = ARRAY_SIZE(max8903_charger_props);
ret = power_supply_register(dev, &data->psy);
if (ret) {
dev_err(dev, "failed: power supply register.\n");
goto err;
}
if (pdata->dc_valid) {
ret = request_threaded_irq(gpio_to_irq(pdata->dok),
NULL, max8903_dcin,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"MAX8903 DC IN", data);
if (ret) {
dev_err(dev, "Cannot request irq %d for DC (%d)\n",
gpio_to_irq(pdata->dok), ret);
goto err_psy;
}
}
if (pdata->usb_valid) {
ret = request_threaded_irq(gpio_to_irq(pdata->uok),
NULL, max8903_usbin,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"MAX8903 USB IN", data);
if (ret) {
dev_err(dev, "Cannot request irq %d for USB (%d)\n",
gpio_to_irq(pdata->uok), ret);
goto err_dc_irq;
}
}
if (pdata->flt) {
ret = request_threaded_irq(gpio_to_irq(pdata->flt),
NULL, max8903_fault,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"MAX8903 Fault", data);
if (ret) {
dev_err(dev, "Cannot request irq %d for Fault (%d)\n",
gpio_to_irq(pdata->flt), ret);
goto err_usb_irq;
}
}
return 0;
err_usb_irq:
if (pdata->usb_valid)
free_irq(gpio_to_irq(pdata->uok), data);
err_dc_irq:
if (pdata->dc_valid)
free_irq(gpio_to_irq(pdata->dok), data);
err_psy:
power_supply_unregister(&data->psy);
err:
kfree(data);
return ret;
}
static __devexit int max8903_remove(struct platform_device *pdev)
{
struct max8903_data *data = platform_get_drvdata(pdev);
if (data) {
struct max8903_pdata *pdata = &data->pdata;
if (pdata->flt)
free_irq(gpio_to_irq(pdata->flt), data);
if (pdata->usb_valid)
free_irq(gpio_to_irq(pdata->uok), data);
if (pdata->dc_valid)
free_irq(gpio_to_irq(pdata->dok), data);
power_supply_unregister(&data->psy);
kfree(data);
}
return 0;
}
static int __init max8903_init(void)
{
return platform_driver_register(&max8903_driver);
}
static void __exit max8903_exit(void)
{
platform_driver_unregister(&max8903_driver);
}
