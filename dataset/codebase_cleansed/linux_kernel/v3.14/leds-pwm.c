static void __led_pwm_set(struct led_pwm_data *led_dat)
{
int new_duty = led_dat->duty;
pwm_config(led_dat->pwm, new_duty, led_dat->period);
if (new_duty == 0)
pwm_disable(led_dat->pwm);
else
pwm_enable(led_dat->pwm);
}
static void led_pwm_work(struct work_struct *work)
{
struct led_pwm_data *led_dat =
container_of(work, struct led_pwm_data, work);
__led_pwm_set(led_dat);
}
static void led_pwm_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct led_pwm_data *led_dat =
container_of(led_cdev, struct led_pwm_data, cdev);
unsigned int max = led_dat->cdev.max_brightness;
unsigned long long duty = led_dat->period;
duty *= brightness;
do_div(duty, max);
led_dat->duty = duty;
if (led_dat->can_sleep)
schedule_work(&led_dat->work);
else
__led_pwm_set(led_dat);
}
static inline size_t sizeof_pwm_leds_priv(int num_leds)
{
return sizeof(struct led_pwm_priv) +
(sizeof(struct led_pwm_data) * num_leds);
}
static int led_pwm_create_of(struct platform_device *pdev,
struct led_pwm_priv *priv)
{
struct device_node *child;
int ret;
for_each_child_of_node(pdev->dev.of_node, child) {
struct led_pwm_data *led_dat = &priv->leds[priv->num_leds];
led_dat->cdev.name = of_get_property(child, "label",
NULL) ? : child->name;
led_dat->pwm = devm_of_pwm_get(&pdev->dev, child, NULL);
if (IS_ERR(led_dat->pwm)) {
dev_err(&pdev->dev, "unable to request PWM for %s\n",
led_dat->cdev.name);
ret = PTR_ERR(led_dat->pwm);
goto err;
}
led_dat->period = pwm_get_period(led_dat->pwm);
led_dat->cdev.default_trigger = of_get_property(child,
"linux,default-trigger", NULL);
of_property_read_u32(child, "max-brightness",
&led_dat->cdev.max_brightness);
led_dat->cdev.brightness_set = led_pwm_set;
led_dat->cdev.brightness = LED_OFF;
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
led_dat->can_sleep = pwm_can_sleep(led_dat->pwm);
if (led_dat->can_sleep)
INIT_WORK(&led_dat->work, led_pwm_work);
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register for %s\n",
led_dat->cdev.name);
of_node_put(child);
goto err;
}
priv->num_leds++;
}
return 0;
err:
while (priv->num_leds--)
led_classdev_unregister(&priv->leds[priv->num_leds].cdev);
return ret;
}
static int led_pwm_probe(struct platform_device *pdev)
{
struct led_pwm_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct led_pwm_priv *priv;
int count, i;
int ret = 0;
if (pdata)
count = pdata->num_leds;
else
count = of_get_child_count(pdev->dev.of_node);
if (!count)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof_pwm_leds_priv(count),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (pdata) {
for (i = 0; i < count; i++) {
struct led_pwm *cur_led = &pdata->leds[i];
struct led_pwm_data *led_dat = &priv->leds[i];
led_dat->pwm = devm_pwm_get(&pdev->dev, cur_led->name);
if (IS_ERR(led_dat->pwm)) {
ret = PTR_ERR(led_dat->pwm);
dev_err(&pdev->dev,
"unable to request PWM for %s\n",
cur_led->name);
goto err;
}
led_dat->cdev.name = cur_led->name;
led_dat->cdev.default_trigger = cur_led->default_trigger;
led_dat->active_low = cur_led->active_low;
led_dat->period = cur_led->pwm_period_ns;
led_dat->cdev.brightness_set = led_pwm_set;
led_dat->cdev.brightness = LED_OFF;
led_dat->cdev.max_brightness = cur_led->max_brightness;
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
led_dat->can_sleep = pwm_can_sleep(led_dat->pwm);
if (led_dat->can_sleep)
INIT_WORK(&led_dat->work, led_pwm_work);
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0)
goto err;
}
priv->num_leds = count;
} else {
ret = led_pwm_create_of(pdev, priv);
if (ret)
return ret;
}
platform_set_drvdata(pdev, priv);
return 0;
err:
while (i--)
led_classdev_unregister(&priv->leds[i].cdev);
return ret;
}
static int led_pwm_remove(struct platform_device *pdev)
{
struct led_pwm_priv *priv = platform_get_drvdata(pdev);
int i;
for (i = 0; i < priv->num_leds; i++) {
led_classdev_unregister(&priv->leds[i].cdev);
if (priv->leds[i].can_sleep)
cancel_work_sync(&priv->leds[i].work);
}
return 0;
}
