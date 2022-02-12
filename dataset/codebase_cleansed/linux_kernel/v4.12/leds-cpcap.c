static u16 cpcap_led_val(u8 current_limit, u8 duty_cycle)
{
current_limit &= 0x1f;
duty_cycle &= 0x0f;
return current_limit << 4 | duty_cycle;
}
static int cpcap_led_set_power(struct cpcap_led *led, bool status)
{
int err;
if (status == led->powered)
return 0;
if (status)
err = regulator_enable(led->vdd);
else
err = regulator_disable(led->vdd);
if (err) {
dev_err(led->dev, "regulator failure: %d", err);
return err;
}
led->powered = status;
return 0;
}
static int cpcap_led_set(struct led_classdev *ledc, enum led_brightness value)
{
struct cpcap_led *led = container_of(ledc, struct cpcap_led, led);
int brightness;
int err;
mutex_lock(&led->update_lock);
if (value > LED_OFF) {
err = cpcap_led_set_power(led, true);
if (err)
goto exit;
}
if (value == LED_OFF) {
err = regmap_update_bits(led->regmap,
led->info->reg, led->info->mask, CPCAP_LED_NO_CURRENT);
if (err) {
dev_err(led->dev, "regmap failed: %d", err);
goto exit;
}
brightness = cpcap_led_val(value, LED_OFF);
} else {
brightness = cpcap_led_val(value, LED_ON);
}
err = regmap_update_bits(led->regmap, led->info->reg, led->info->mask,
brightness);
if (err) {
dev_err(led->dev, "regmap failed: %d", err);
goto exit;
}
if (value == LED_OFF) {
err = cpcap_led_set_power(led, false);
if (err)
goto exit;
}
exit:
mutex_unlock(&led->update_lock);
return err;
}
static int cpcap_led_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct cpcap_led *led;
int err;
match = of_match_device(of_match_ptr(cpcap_led_of_match), &pdev->dev);
if (!match || !match->data)
return -EINVAL;
led = devm_kzalloc(&pdev->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
platform_set_drvdata(pdev, led);
led->info = match->data;
led->dev = &pdev->dev;
if (led->info->reg == 0x0000) {
dev_err(led->dev, "Unsupported LED");
return -ENODEV;
}
led->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!led->regmap)
return -ENODEV;
led->vdd = devm_regulator_get(&pdev->dev, "vdd");
if (IS_ERR(led->vdd)) {
err = PTR_ERR(led->vdd);
dev_err(led->dev, "Couldn't get regulator: %d", err);
return err;
}
err = device_property_read_string(&pdev->dev, "label", &led->led.name);
if (err) {
dev_err(led->dev, "Couldn't read LED label: %d", err);
return err;
}
if (led->info->init_mask) {
err = regmap_update_bits(led->regmap, led->info->reg,
led->info->init_mask, led->info->init_val);
if (err) {
dev_err(led->dev, "regmap failed: %d", err);
return err;
}
}
mutex_init(&led->update_lock);
led->led.max_brightness = led->info->limit;
led->led.brightness_set_blocking = cpcap_led_set;
err = devm_led_classdev_register(&pdev->dev, &led->led);
if (err) {
dev_err(led->dev, "Couldn't register LED: %d", err);
return err;
}
return 0;
}
