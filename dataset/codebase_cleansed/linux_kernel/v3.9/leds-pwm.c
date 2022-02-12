static void led_pwm_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct led_pwm_data *led_dat =
container_of(led_cdev, struct led_pwm_data, cdev);
unsigned int max = led_dat->cdev.max_brightness;
unsigned int period = led_dat->period;
if (brightness == 0) {
pwm_config(led_dat->pwm, 0, period);
pwm_disable(led_dat->pwm);
} else {
pwm_config(led_dat->pwm, brightness * period / max, period);
pwm_enable(led_dat->pwm);
}
}
static inline size_t sizeof_pwm_leds_priv(int num_leds)
{
return sizeof(struct led_pwm_priv) +
(sizeof(struct led_pwm_data) * num_leds);
}
static struct led_pwm_priv *led_pwm_create_of(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device_node *child;
struct led_pwm_priv *priv;
int count, ret;
count = of_get_child_count(node);
if (!count)
return NULL;
priv = devm_kzalloc(&pdev->dev, sizeof_pwm_leds_priv(count),
GFP_KERNEL);
if (!priv)
return NULL;
for_each_child_of_node(node, child) {
struct led_pwm_data *led_dat = &priv->leds[priv->num_leds];
led_dat->cdev.name = of_get_property(child, "label",
NULL) ? : child->name;
led_dat->pwm = devm_of_pwm_get(&pdev->dev, child, NULL);
if (IS_ERR(led_dat->pwm)) {
dev_err(&pdev->dev, "unable to request PWM for %s\n",
led_dat->cdev.name);
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
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register for %s\n",
led_dat->cdev.name);
of_node_put(child);
goto err;
}
priv->num_leds++;
}
return priv;
err:
while (priv->num_leds--)
led_classdev_unregister(&priv->leds[priv->num_leds].cdev);
return NULL;
}
static int led_pwm_probe(struct platform_device *pdev)
{
struct led_pwm_platform_data *pdata = pdev->dev.platform_data;
struct led_pwm_priv *priv;
int i, ret = 0;
if (pdata && pdata->num_leds) {
priv = devm_kzalloc(&pdev->dev,
sizeof_pwm_leds_priv(pdata->num_leds),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
for (i = 0; i < pdata->num_leds; i++) {
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
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0)
goto err;
}
priv->num_leds = pdata->num_leds;
} else {
priv = led_pwm_create_of(pdev);
if (!priv)
return -ENODEV;
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
for (i = 0; i < priv->num_leds; i++)
led_classdev_unregister(&priv->leds[i].cdev);
return 0;
}
