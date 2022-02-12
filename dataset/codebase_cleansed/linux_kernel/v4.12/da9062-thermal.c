static void da9062_thermal_poll_on(struct work_struct *work)
{
struct da9062_thermal *thermal = container_of(work,
struct da9062_thermal,
work.work);
unsigned long delay;
unsigned int val;
int ret;
ret = regmap_write(thermal->hw->regmap,
DA9062AA_EVENT_B,
DA9062AA_E_TEMP_MASK);
if (ret < 0) {
dev_err(thermal->dev,
"Cannot clear the TJUNC temperature status\n");
goto err_enable_irq;
}
ret = regmap_read(thermal->hw->regmap,
DA9062AA_EVENT_B,
&val);
if (ret < 0) {
dev_err(thermal->dev,
"Cannot check the TJUNC temperature status\n");
goto err_enable_irq;
}
if (val & DA9062AA_E_TEMP_MASK) {
mutex_lock(&thermal->lock);
thermal->temperature = DA9062_MILLI_CELSIUS(125);
mutex_unlock(&thermal->lock);
thermal_zone_device_update(thermal->zone,
THERMAL_EVENT_UNSPECIFIED);
delay = msecs_to_jiffies(thermal->zone->passive_delay);
schedule_delayed_work(&thermal->work, delay);
return;
}
mutex_lock(&thermal->lock);
thermal->temperature = DA9062_MILLI_CELSIUS(0);
mutex_unlock(&thermal->lock);
thermal_zone_device_update(thermal->zone,
THERMAL_EVENT_UNSPECIFIED);
err_enable_irq:
enable_irq(thermal->irq);
}
static irqreturn_t da9062_thermal_irq_handler(int irq, void *data)
{
struct da9062_thermal *thermal = data;
disable_irq_nosync(thermal->irq);
schedule_delayed_work(&thermal->work, 0);
return IRQ_HANDLED;
}
static int da9062_thermal_get_mode(struct thermal_zone_device *z,
enum thermal_device_mode *mode)
{
struct da9062_thermal *thermal = z->devdata;
*mode = thermal->mode;
return 0;
}
static int da9062_thermal_get_trip_type(struct thermal_zone_device *z,
int trip,
enum thermal_trip_type *type)
{
struct da9062_thermal *thermal = z->devdata;
switch (trip) {
case 0:
*type = THERMAL_TRIP_HOT;
break;
default:
dev_err(thermal->dev,
"Driver does not support more than 1 trip-wire\n");
return -EINVAL;
}
return 0;
}
static int da9062_thermal_get_trip_temp(struct thermal_zone_device *z,
int trip,
int *temp)
{
struct da9062_thermal *thermal = z->devdata;
switch (trip) {
case 0:
*temp = DA9062_MILLI_CELSIUS(125);
break;
default:
dev_err(thermal->dev,
"Driver does not support more than 1 trip-wire\n");
return -EINVAL;
}
return 0;
}
static int da9062_thermal_get_temp(struct thermal_zone_device *z,
int *temp)
{
struct da9062_thermal *thermal = z->devdata;
mutex_lock(&thermal->lock);
*temp = thermal->temperature;
mutex_unlock(&thermal->lock);
return 0;
}
static int da9062_thermal_probe(struct platform_device *pdev)
{
struct da9062 *chip = dev_get_drvdata(pdev->dev.parent);
struct da9062_thermal *thermal;
unsigned int pp_tmp = DA9062_DEFAULT_POLLING_MS_PERIOD;
const struct of_device_id *match;
int ret = 0;
match = of_match_node(da9062_compatible_reg_id_table,
pdev->dev.of_node);
if (!match)
return -ENXIO;
if (pdev->dev.of_node) {
if (!of_property_read_u32(pdev->dev.of_node,
"polling-delay-passive",
&pp_tmp)) {
if (pp_tmp < DA9062_MIN_POLLING_MS_PERIOD ||
pp_tmp > DA9062_MAX_POLLING_MS_PERIOD) {
dev_warn(&pdev->dev,
"Out-of-range polling period %d ms\n",
pp_tmp);
pp_tmp = DA9062_DEFAULT_POLLING_MS_PERIOD;
}
}
}
thermal = devm_kzalloc(&pdev->dev, sizeof(struct da9062_thermal),
GFP_KERNEL);
if (!thermal) {
ret = -ENOMEM;
goto err;
}
thermal->config = match->data;
thermal->hw = chip;
thermal->mode = THERMAL_DEVICE_ENABLED;
thermal->dev = &pdev->dev;
INIT_DELAYED_WORK(&thermal->work, da9062_thermal_poll_on);
mutex_init(&thermal->lock);
thermal->zone = thermal_zone_device_register(thermal->config->name,
1, 0, thermal,
&da9062_thermal_ops, NULL, pp_tmp,
0);
if (IS_ERR(thermal->zone)) {
dev_err(&pdev->dev, "Cannot register thermal zone device\n");
ret = PTR_ERR(thermal->zone);
goto err;
}
dev_dbg(&pdev->dev,
"TJUNC temperature polling period set at %d ms\n",
thermal->zone->passive_delay);
ret = platform_get_irq_byname(pdev, "THERMAL");
if (ret < 0) {
dev_err(&pdev->dev, "Failed to get platform IRQ.\n");
goto err_zone;
}
thermal->irq = ret;
ret = request_threaded_irq(thermal->irq, NULL,
da9062_thermal_irq_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"THERMAL", thermal);
if (ret) {
dev_err(&pdev->dev,
"Failed to request thermal device IRQ.\n");
goto err_zone;
}
platform_set_drvdata(pdev, thermal);
return 0;
err_zone:
thermal_zone_device_unregister(thermal->zone);
err:
return ret;
}
static int da9062_thermal_remove(struct platform_device *pdev)
{
struct da9062_thermal *thermal = platform_get_drvdata(pdev);
free_irq(thermal->irq, thermal);
cancel_delayed_work_sync(&thermal->work);
thermal_zone_device_unregister(thermal->zone);
return 0;
}
