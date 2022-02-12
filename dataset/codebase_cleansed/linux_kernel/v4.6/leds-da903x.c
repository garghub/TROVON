static int da903x_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct da903x_led *led =
container_of(led_cdev, struct da903x_led, cdev);
uint8_t val;
int offset, ret = -EINVAL;
switch (led->id) {
case DA9030_ID_LED_1:
case DA9030_ID_LED_2:
case DA9030_ID_LED_3:
case DA9030_ID_LED_4:
case DA9030_ID_LED_PC:
offset = DA9030_LED_OFFSET(led->id);
val = led->flags & ~0x87;
val |= value ? 0x80 : 0;
val |= (0x7 - (value >> 5)) & 0x7;
ret = da903x_write(led->master, DA9030_LED1_CONTROL + offset,
val);
break;
case DA9030_ID_VIBRA:
val = led->flags & ~0x80;
val |= value ? 0x80 : 0;
ret = da903x_write(led->master, DA9030_MISC_CONTROL_A, val);
break;
case DA9034_ID_LED_1:
case DA9034_ID_LED_2:
offset = DA9034_LED_OFFSET(led->id);
val = (value * 0x5f / LED_FULL) & 0x7f;
val |= (led->flags & DA9034_LED_RAMP) ? 0x80 : 0;
ret = da903x_write(led->master, DA9034_LED1_CONTROL + offset,
val);
break;
case DA9034_ID_VIBRA:
val = value & 0xfe;
ret = da903x_write(led->master, DA9034_VIBRA, val);
break;
}
return ret;
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
led->cdev.brightness_set_blocking = da903x_led_set;
led->cdev.brightness = LED_OFF;
led->id = id;
led->flags = pdata->flags;
led->master = pdev->dev.parent;
ret = devm_led_classdev_register(led->master, &led->cdev);
if (ret) {
dev_err(&pdev->dev, "failed to register LED %d\n", id);
return ret;
}
return 0;
}
