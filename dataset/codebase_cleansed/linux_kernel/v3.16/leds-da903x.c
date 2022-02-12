static void da903x_led_work(struct work_struct *work)
{
struct da903x_led *led = container_of(work, struct da903x_led, work);
uint8_t val;
int offset;
switch (led->id) {
case DA9030_ID_LED_1:
case DA9030_ID_LED_2:
case DA9030_ID_LED_3:
case DA9030_ID_LED_4:
case DA9030_ID_LED_PC:
offset = DA9030_LED_OFFSET(led->id);
val = led->flags & ~0x87;
val |= (led->new_brightness) ? 0x80 : 0;
val |= (0x7 - (led->new_brightness >> 5)) & 0x7;
da903x_write(led->master, DA9030_LED1_CONTROL + offset, val);
break;
case DA9030_ID_VIBRA:
val = led->flags & ~0x80;
val |= (led->new_brightness) ? 0x80 : 0;
da903x_write(led->master, DA9030_MISC_CONTROL_A, val);
break;
case DA9034_ID_LED_1:
case DA9034_ID_LED_2:
offset = DA9034_LED_OFFSET(led->id);
val = (led->new_brightness * 0x5f / LED_FULL) & 0x7f;
val |= (led->flags & DA9034_LED_RAMP) ? 0x80 : 0;
da903x_write(led->master, DA9034_LED1_CONTROL + offset, val);
break;
case DA9034_ID_VIBRA:
val = led->new_brightness & 0xfe;
da903x_write(led->master, DA9034_VIBRA, val);
break;
}
}
static void da903x_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct da903x_led *led;
led = container_of(led_cdev, struct da903x_led, cdev);
led->new_brightness = value;
schedule_work(&led->work);
}
static int da903x_led_probe(struct platform_device *pdev)
{
struct led_info *pdata = dev_get_platdata(&pdev->dev);
struct da903x_led *led;
int id, ret;
if (pdata == NULL)
return 0;
id = pdev->id;
if (!((id >= DA9030_ID_LED_1 && id <= DA9030_ID_VIBRA) ||
(id >= DA9034_ID_LED_1 && id <= DA9034_ID_VIBRA))) {
dev_err(&pdev->dev, "invalid LED ID (%d) specified\n", id);
return -EINVAL;
}
led = devm_kzalloc(&pdev->dev, sizeof(struct da903x_led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->cdev.name = pdata->name;
led->cdev.default_trigger = pdata->default_trigger;
led->cdev.brightness_set = da903x_led_set;
led->cdev.brightness = LED_OFF;
led->id = id;
led->flags = pdata->flags;
led->master = pdev->dev.parent;
led->new_brightness = LED_OFF;
INIT_WORK(&led->work, da903x_led_work);
ret = led_classdev_register(led->master, &led->cdev);
if (ret) {
dev_err(&pdev->dev, "failed to register LED %d\n", id);
return ret;
}
platform_set_drvdata(pdev, led);
return 0;
}
static int da903x_led_remove(struct platform_device *pdev)
{
struct da903x_led *led = platform_get_drvdata(pdev);
led_classdev_unregister(&led->cdev);
return 0;
}
