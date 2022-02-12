static inline int led_regulator_get_max_brightness(struct regulator *supply)
{
int ret;
int voltage = regulator_list_voltage(supply, 0);
if (voltage <= 0)
return 1;
ret = regulator_set_voltage(supply, voltage, voltage);
if (ret < 0)
return 1;
return regulator_count_voltages(supply);
}
static int led_regulator_get_voltage(struct regulator *supply,
enum led_brightness brightness)
{
if (brightness == 0)
return -EINVAL;
return regulator_list_voltage(supply, brightness - 1);
}
static void regulator_led_enable(struct regulator_led *led)
{
int ret;
if (led->enabled)
return;
ret = regulator_enable(led->vcc);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to enable vcc: %d\n", ret);
return;
}
led->enabled = 1;
}
static void regulator_led_disable(struct regulator_led *led)
{
int ret;
if (!led->enabled)
return;
ret = regulator_disable(led->vcc);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to disable vcc: %d\n", ret);
return;
}
led->enabled = 0;
}
static void regulator_led_set_value(struct regulator_led *led)
{
int voltage;
int ret;
mutex_lock(&led->mutex);
if (led->value == LED_OFF) {
regulator_led_disable(led);
goto out;
}
if (led->cdev.max_brightness > 1) {
voltage = led_regulator_get_voltage(led->vcc, led->value);
dev_dbg(led->cdev.dev, "brightness: %d voltage: %d\n",
led->value, voltage);
ret = regulator_set_voltage(led->vcc, voltage, voltage);
if (ret != 0)
dev_err(led->cdev.dev, "Failed to set voltage %d: %d\n",
voltage, ret);
}
regulator_led_enable(led);
out:
mutex_unlock(&led->mutex);
}
static void led_work(struct work_struct *work)
{
struct regulator_led *led;
led = container_of(work, struct regulator_led, work);
regulator_led_set_value(led);
}
static void regulator_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct regulator_led *led = to_regulator_led(led_cdev);
led->value = value;
schedule_work(&led->work);
}
static int __devinit regulator_led_probe(struct platform_device *pdev)
{
struct led_regulator_platform_data *pdata = pdev->dev.platform_data;
struct regulator_led *led;
struct regulator *vcc;
int ret = 0;
if (pdata == NULL) {
dev_err(&pdev->dev, "no platform data\n");
return -ENODEV;
}
vcc = regulator_get_exclusive(&pdev->dev, "vled");
if (IS_ERR(vcc)) {
dev_err(&pdev->dev, "Cannot get vcc for %s\n", pdata->name);
return PTR_ERR(vcc);
}
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (led == NULL) {
ret = -ENOMEM;
goto err_vcc;
}
led->cdev.max_brightness = led_regulator_get_max_brightness(vcc);
if (pdata->brightness > led->cdev.max_brightness) {
dev_err(&pdev->dev, "Invalid default brightness %d\n",
pdata->brightness);
ret = -EINVAL;
goto err_led;
}
led->value = pdata->brightness;
led->cdev.brightness_set = regulator_led_brightness_set;
led->cdev.name = pdata->name;
led->cdev.flags |= LED_CORE_SUSPENDRESUME;
led->vcc = vcc;
if (regulator_is_enabled(led->vcc))
led->enabled = 1;
mutex_init(&led->mutex);
INIT_WORK(&led->work, led_work);
platform_set_drvdata(pdev, led);
ret = led_classdev_register(&pdev->dev, &led->cdev);
if (ret < 0) {
cancel_work_sync(&led->work);
goto err_led;
}
led->cdev.brightness = led->value;
regulator_led_set_value(led);
return 0;
err_led:
kfree(led);
err_vcc:
regulator_put(vcc);
return ret;
}
static int __devexit regulator_led_remove(struct platform_device *pdev)
{
struct regulator_led *led = platform_get_drvdata(pdev);
led_classdev_unregister(&led->cdev);
cancel_work_sync(&led->work);
regulator_led_disable(led);
regulator_put(led->vcc);
kfree(led);
return 0;
}
