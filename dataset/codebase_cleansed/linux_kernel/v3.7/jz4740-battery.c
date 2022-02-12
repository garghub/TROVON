static inline struct jz_battery *psy_to_jz_battery(struct power_supply *psy)
{
return container_of(psy, struct jz_battery, battery);
}
static irqreturn_t jz_battery_irq_handler(int irq, void *devid)
{
struct jz_battery *battery = devid;
complete(&battery->read_completion);
return IRQ_HANDLED;
}
static long jz_battery_read_voltage(struct jz_battery *battery)
{
long t;
unsigned long val;
long voltage;
mutex_lock(&battery->lock);
INIT_COMPLETION(battery->read_completion);
enable_irq(battery->irq);
battery->cell->enable(battery->pdev);
t = wait_for_completion_interruptible_timeout(&battery->read_completion,
HZ);
if (t > 0) {
val = readw(battery->base) & 0xfff;
if (battery->pdata->info.voltage_max_design <= 2500000)
val = (val * 78125UL) >> 7UL;
else
val = ((val * 924375UL) >> 9UL) + 33000;
voltage = (long)val;
} else {
voltage = t ? t : -ETIMEDOUT;
}
battery->cell->disable(battery->pdev);
disable_irq(battery->irq);
mutex_unlock(&battery->lock);
return voltage;
}
static int jz_battery_get_capacity(struct power_supply *psy)
{
struct jz_battery *jz_battery = psy_to_jz_battery(psy);
struct power_supply_info *info = &jz_battery->pdata->info;
long voltage;
int ret;
int voltage_span;
voltage = jz_battery_read_voltage(jz_battery);
if (voltage < 0)
return voltage;
voltage_span = info->voltage_max_design - info->voltage_min_design;
ret = ((voltage - info->voltage_min_design) * 100) / voltage_span;
if (ret > 100)
ret = 100;
else if (ret < 0)
ret = 0;
return ret;
}
static int jz_battery_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct jz_battery *jz_battery = psy_to_jz_battery(psy);
struct power_supply_info *info = &jz_battery->pdata->info;
long voltage;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = jz_battery->status;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = jz_battery->pdata->info.technology;
break;
case POWER_SUPPLY_PROP_HEALTH:
voltage = jz_battery_read_voltage(jz_battery);
if (voltage < info->voltage_min_design)
val->intval = POWER_SUPPLY_HEALTH_DEAD;
else
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = jz_battery_get_capacity(psy);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = jz_battery_read_voltage(jz_battery);
if (val->intval < 0)
return val->intval;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = info->voltage_max_design;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = info->voltage_min_design;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = 1;
break;
default:
return -EINVAL;
}
return 0;
}
static void jz_battery_external_power_changed(struct power_supply *psy)
{
struct jz_battery *jz_battery = psy_to_jz_battery(psy);
mod_delayed_work(system_wq, &jz_battery->work, 0);
}
static irqreturn_t jz_battery_charge_irq(int irq, void *data)
{
struct jz_battery *jz_battery = data;
mod_delayed_work(system_wq, &jz_battery->work, 0);
return IRQ_HANDLED;
}
static void jz_battery_update(struct jz_battery *jz_battery)
{
int status;
long voltage;
bool has_changed = false;
int is_charging;
if (gpio_is_valid(jz_battery->pdata->gpio_charge)) {
is_charging = gpio_get_value(jz_battery->pdata->gpio_charge);
is_charging ^= jz_battery->pdata->gpio_charge_active_low;
if (is_charging)
status = POWER_SUPPLY_STATUS_CHARGING;
else
status = POWER_SUPPLY_STATUS_NOT_CHARGING;
if (status != jz_battery->status) {
jz_battery->status = status;
has_changed = true;
}
}
voltage = jz_battery_read_voltage(jz_battery);
if (abs(voltage - jz_battery->voltage) < 50000) {
jz_battery->voltage = voltage;
has_changed = true;
}
if (has_changed)
power_supply_changed(&jz_battery->battery);
}
static void jz_battery_work(struct work_struct *work)
{
const int interval = HZ * 30;
struct jz_battery *jz_battery = container_of(work, struct jz_battery,
work.work);
jz_battery_update(jz_battery);
schedule_delayed_work(&jz_battery->work, interval);
}
static int __devinit jz_battery_probe(struct platform_device *pdev)
{
int ret = 0;
struct jz_battery_platform_data *pdata = pdev->dev.parent->platform_data;
struct jz_battery *jz_battery;
struct power_supply *battery;
if (!pdata) {
dev_err(&pdev->dev, "No platform_data supplied\n");
return -ENXIO;
}
jz_battery = kzalloc(sizeof(*jz_battery), GFP_KERNEL);
if (!jz_battery) {
dev_err(&pdev->dev, "Failed to allocate driver structure\n");
return -ENOMEM;
}
jz_battery->cell = mfd_get_cell(pdev);
jz_battery->irq = platform_get_irq(pdev, 0);
if (jz_battery->irq < 0) {
ret = jz_battery->irq;
dev_err(&pdev->dev, "Failed to get platform irq: %d\n", ret);
goto err_free;
}
jz_battery->mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!jz_battery->mem) {
ret = -ENOENT;
dev_err(&pdev->dev, "Failed to get platform mmio resource\n");
goto err_free;
}
jz_battery->mem = request_mem_region(jz_battery->mem->start,
resource_size(jz_battery->mem), pdev->name);
if (!jz_battery->mem) {
ret = -EBUSY;
dev_err(&pdev->dev, "Failed to request mmio memory region\n");
goto err_free;
}
jz_battery->base = ioremap_nocache(jz_battery->mem->start,
resource_size(jz_battery->mem));
if (!jz_battery->base) {
ret = -EBUSY;
dev_err(&pdev->dev, "Failed to ioremap mmio memory\n");
goto err_release_mem_region;
}
battery = &jz_battery->battery;
battery->name = pdata->info.name;
battery->type = POWER_SUPPLY_TYPE_BATTERY;
battery->properties = jz_battery_properties;
battery->num_properties = ARRAY_SIZE(jz_battery_properties);
battery->get_property = jz_battery_get_property;
battery->external_power_changed = jz_battery_external_power_changed;
battery->use_for_apm = 1;
jz_battery->pdata = pdata;
jz_battery->pdev = pdev;
init_completion(&jz_battery->read_completion);
mutex_init(&jz_battery->lock);
INIT_DELAYED_WORK(&jz_battery->work, jz_battery_work);
ret = request_irq(jz_battery->irq, jz_battery_irq_handler, 0, pdev->name,
jz_battery);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq %d\n", ret);
goto err_iounmap;
}
disable_irq(jz_battery->irq);
if (gpio_is_valid(pdata->gpio_charge)) {
ret = gpio_request(pdata->gpio_charge, dev_name(&pdev->dev));
if (ret) {
dev_err(&pdev->dev, "charger state gpio request failed.\n");
goto err_free_irq;
}
ret = gpio_direction_input(pdata->gpio_charge);
if (ret) {
dev_err(&pdev->dev, "charger state gpio set direction failed.\n");
goto err_free_gpio;
}
jz_battery->charge_irq = gpio_to_irq(pdata->gpio_charge);
if (jz_battery->charge_irq >= 0) {
ret = request_irq(jz_battery->charge_irq,
jz_battery_charge_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), jz_battery);
if (ret) {
dev_err(&pdev->dev, "Failed to request charge irq: %d\n", ret);
goto err_free_gpio;
}
}
} else {
jz_battery->charge_irq = -1;
}
if (jz_battery->pdata->info.voltage_max_design <= 2500000)
jz4740_adc_set_config(pdev->dev.parent, JZ_ADC_CONFIG_BAT_MB,
JZ_ADC_CONFIG_BAT_MB);
else
jz4740_adc_set_config(pdev->dev.parent, JZ_ADC_CONFIG_BAT_MB, 0);
ret = power_supply_register(&pdev->dev, &jz_battery->battery);
if (ret) {
dev_err(&pdev->dev, "power supply battery register failed.\n");
goto err_free_charge_irq;
}
platform_set_drvdata(pdev, jz_battery);
schedule_delayed_work(&jz_battery->work, 0);
return 0;
err_free_charge_irq:
if (jz_battery->charge_irq >= 0)
free_irq(jz_battery->charge_irq, jz_battery);
err_free_gpio:
if (gpio_is_valid(pdata->gpio_charge))
gpio_free(jz_battery->pdata->gpio_charge);
err_free_irq:
free_irq(jz_battery->irq, jz_battery);
err_iounmap:
platform_set_drvdata(pdev, NULL);
iounmap(jz_battery->base);
err_release_mem_region:
release_mem_region(jz_battery->mem->start, resource_size(jz_battery->mem));
err_free:
kfree(jz_battery);
return ret;
}
static int __devexit jz_battery_remove(struct platform_device *pdev)
{
struct jz_battery *jz_battery = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&jz_battery->work);
if (gpio_is_valid(jz_battery->pdata->gpio_charge)) {
if (jz_battery->charge_irq >= 0)
free_irq(jz_battery->charge_irq, jz_battery);
gpio_free(jz_battery->pdata->gpio_charge);
}
power_supply_unregister(&jz_battery->battery);
free_irq(jz_battery->irq, jz_battery);
iounmap(jz_battery->base);
release_mem_region(jz_battery->mem->start, resource_size(jz_battery->mem));
kfree(jz_battery);
return 0;
}
static int jz_battery_suspend(struct device *dev)
{
struct jz_battery *jz_battery = dev_get_drvdata(dev);
cancel_delayed_work_sync(&jz_battery->work);
jz_battery->status = POWER_SUPPLY_STATUS_UNKNOWN;
return 0;
}
static int jz_battery_resume(struct device *dev)
{
struct jz_battery *jz_battery = dev_get_drvdata(dev);
schedule_delayed_work(&jz_battery->work, 0);
return 0;
}
