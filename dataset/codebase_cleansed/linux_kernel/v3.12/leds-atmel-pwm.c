static void pwmled_brightness(struct led_classdev *cdev, enum led_brightness b)
{
struct pwmled *led;
led = container_of(cdev, struct pwmled, cdev);
pwm_channel_writel(&led->pwmc, PWM_CUPD, led->mult * (unsigned) b);
}
static int pwmled_probe(struct platform_device *pdev)
{
const struct gpio_led_platform_data *pdata;
struct pwmled *leds;
int i;
int status;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata || pdata->num_leds < 1)
return -ENODEV;
leds = devm_kzalloc(&pdev->dev, pdata->num_leds * sizeof(*leds),
GFP_KERNEL);
if (!leds)
return -ENOMEM;
for (i = 0; i < pdata->num_leds; i++) {
struct pwmled *led = leds + i;
const struct gpio_led *dat = pdata->leds + i;
u32 tmp;
led->cdev.name = dat->name;
led->cdev.brightness = LED_OFF;
led->cdev.brightness_set = pwmled_brightness;
led->cdev.default_trigger = dat->default_trigger;
led->active_low = dat->active_low;
status = pwm_channel_alloc(dat->gpio, &led->pwmc);
if (status < 0)
goto err;
tmp = 5;
if (!led->active_low)
tmp |= PWM_CPR_CPOL;
pwm_channel_writel(&led->pwmc, PWM_CMR, tmp);
tmp = (led->pwmc.mck / (1 << 5)) / 100;
tmp /= 255;
led->mult = tmp;
pwm_channel_writel(&led->pwmc, PWM_CDTY,
led->cdev.brightness * 255);
pwm_channel_writel(&led->pwmc, PWM_CPRD,
LED_FULL * tmp);
pwm_channel_enable(&led->pwmc);
status = led_classdev_register(&pdev->dev, &led->cdev);
if (status < 0) {
pwm_channel_free(&led->pwmc);
goto err;
}
}
platform_set_drvdata(pdev, leds);
return 0;
err:
if (i > 0) {
for (i = i - 1; i >= 0; i--) {
led_classdev_unregister(&leds[i].cdev);
pwm_channel_free(&leds[i].pwmc);
}
}
return status;
}
static int pwmled_remove(struct platform_device *pdev)
{
const struct gpio_led_platform_data *pdata;
struct pwmled *leds;
unsigned i;
pdata = dev_get_platdata(&pdev->dev);
leds = platform_get_drvdata(pdev);
for (i = 0; i < pdata->num_leds; i++) {
struct pwmled *led = leds + i;
led_classdev_unregister(&led->cdev);
pwm_channel_free(&led->pwmc);
}
return 0;
}
