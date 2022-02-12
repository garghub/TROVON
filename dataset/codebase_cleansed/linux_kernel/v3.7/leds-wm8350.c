static void wm8350_led_enable(struct wm8350_led *led)
{
int ret;
if (led->enabled)
return;
ret = regulator_enable(led->isink);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to enable ISINK: %d\n", ret);
return;
}
ret = regulator_enable(led->dcdc);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to enable DCDC: %d\n", ret);
regulator_disable(led->isink);
return;
}
led->enabled = 1;
}
static void wm8350_led_disable(struct wm8350_led *led)
{
int ret;
if (!led->enabled)
return;
ret = regulator_disable(led->dcdc);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to disable DCDC: %d\n", ret);
return;
}
ret = regulator_disable(led->isink);
if (ret != 0) {
dev_err(led->cdev.dev, "Failed to disable ISINK: %d\n", ret);
regulator_enable(led->dcdc);
return;
}
led->enabled = 0;
}
static void led_work(struct work_struct *work)
{
struct wm8350_led *led = container_of(work, struct wm8350_led, work);
int ret;
int uA;
unsigned long flags;
mutex_lock(&led->mutex);
spin_lock_irqsave(&led->value_lock, flags);
if (led->value == LED_OFF) {
spin_unlock_irqrestore(&led->value_lock, flags);
wm8350_led_disable(led);
goto out;
}
uA = (led->max_uA_index * led->value) / LED_FULL;
spin_unlock_irqrestore(&led->value_lock, flags);
BUG_ON(uA >= ARRAY_SIZE(isink_cur));
ret = regulator_set_current_limit(led->isink, isink_cur[uA],
isink_cur[uA]);
if (ret != 0)
dev_err(led->cdev.dev, "Failed to set %duA: %d\n",
isink_cur[uA], ret);
wm8350_led_enable(led);
out:
mutex_unlock(&led->mutex);
}
static void wm8350_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct wm8350_led *led = to_wm8350_led(led_cdev);
unsigned long flags;
spin_lock_irqsave(&led->value_lock, flags);
led->value = value;
schedule_work(&led->work);
spin_unlock_irqrestore(&led->value_lock, flags);
}
static void wm8350_led_shutdown(struct platform_device *pdev)
{
struct wm8350_led *led = platform_get_drvdata(pdev);
mutex_lock(&led->mutex);
led->value = LED_OFF;
wm8350_led_disable(led);
mutex_unlock(&led->mutex);
}
static int wm8350_led_probe(struct platform_device *pdev)
{
struct regulator *isink, *dcdc;
struct wm8350_led *led;
struct wm8350_led_platform_data *pdata = pdev->dev.platform_data;
int i;
if (pdata == NULL) {
dev_err(&pdev->dev, "no platform data\n");
return -ENODEV;
}
if (pdata->max_uA < isink_cur[0]) {
dev_err(&pdev->dev, "Invalid maximum current %duA\n",
pdata->max_uA);
return -EINVAL;
}
isink = devm_regulator_get(&pdev->dev, "led_isink");
if (IS_ERR(isink)) {
printk(KERN_ERR "%s: can't get ISINK\n", __func__);
return PTR_ERR(isink);
}
dcdc = devm_regulator_get(&pdev->dev, "led_vcc");
if (IS_ERR(dcdc)) {
printk(KERN_ERR "%s: can't get DCDC\n", __func__);
return PTR_ERR(dcdc);
}
led = devm_kzalloc(&pdev->dev, sizeof(*led), GFP_KERNEL);
if (led == NULL)
return -ENOMEM;
led->cdev.brightness_set = wm8350_led_set;
led->cdev.default_trigger = pdata->default_trigger;
led->cdev.name = pdata->name;
led->cdev.flags |= LED_CORE_SUSPENDRESUME;
led->enabled = regulator_is_enabled(isink);
led->isink = isink;
led->dcdc = dcdc;
for (i = 0; i < ARRAY_SIZE(isink_cur) - 1; i++)
if (isink_cur[i] >= pdata->max_uA)
break;
led->max_uA_index = i;
if (pdata->max_uA != isink_cur[i])
dev_warn(&pdev->dev,
"Maximum current %duA is not directly supported,"
" check platform data\n",
pdata->max_uA);
spin_lock_init(&led->value_lock);
mutex_init(&led->mutex);
INIT_WORK(&led->work, led_work);
led->value = LED_OFF;
platform_set_drvdata(pdev, led);
return led_classdev_register(&pdev->dev, &led->cdev);
}
static int wm8350_led_remove(struct platform_device *pdev)
{
struct wm8350_led *led = platform_get_drvdata(pdev);
led_classdev_unregister(&led->cdev);
flush_work(&led->work);
wm8350_led_disable(led);
return 0;
}
