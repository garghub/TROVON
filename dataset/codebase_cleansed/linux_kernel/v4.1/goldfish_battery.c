static int goldfish_ac_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct goldfish_battery_data *data = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_AC_ONLINE);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int goldfish_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct goldfish_battery_data *data = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_STATUS);
break;
case POWER_SUPPLY_PROP_HEALTH:
val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_HEALTH);
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_PRESENT);
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = GOLDFISH_BATTERY_READ(data, BATTERY_CAPACITY);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static irqreturn_t goldfish_battery_interrupt(int irq, void *dev_id)
{
unsigned long irq_flags;
struct goldfish_battery_data *data = dev_id;
uint32_t status;
spin_lock_irqsave(&data->lock, irq_flags);
status = GOLDFISH_BATTERY_READ(data, BATTERY_INT_STATUS);
status &= BATTERY_INT_MASK;
if (status & BATTERY_STATUS_CHANGED)
power_supply_changed(data->battery);
if (status & AC_STATUS_CHANGED)
power_supply_changed(data->ac);
spin_unlock_irqrestore(&data->lock, irq_flags);
return status ? IRQ_HANDLED : IRQ_NONE;
}
static int goldfish_battery_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
struct goldfish_battery_data *data;
struct power_supply_config psy_cfg = {};
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
spin_lock_init(&data->lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&pdev->dev, "platform_get_resource failed\n");
return -ENODEV;
}
data->reg_base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (data->reg_base == NULL) {
dev_err(&pdev->dev, "unable to remap MMIO\n");
return -ENOMEM;
}
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0) {
dev_err(&pdev->dev, "platform_get_irq failed\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, data->irq, goldfish_battery_interrupt,
IRQF_SHARED, pdev->name, data);
if (ret)
return ret;
psy_cfg.drv_data = data;
data->ac = power_supply_register(&pdev->dev, &ac_desc, &psy_cfg);
if (IS_ERR(data->ac))
return PTR_ERR(data->ac);
data->battery = power_supply_register(&pdev->dev, &battery_desc,
&psy_cfg);
if (IS_ERR(data->battery)) {
power_supply_unregister(data->ac);
return PTR_ERR(data->battery);
}
platform_set_drvdata(pdev, data);
battery_data = data;
GOLDFISH_BATTERY_WRITE(data, BATTERY_INT_ENABLE, BATTERY_INT_MASK);
return 0;
}
static int goldfish_battery_remove(struct platform_device *pdev)
{
struct goldfish_battery_data *data = platform_get_drvdata(pdev);
power_supply_unregister(data->battery);
power_supply_unregister(data->ac);
battery_data = NULL;
return 0;
}
