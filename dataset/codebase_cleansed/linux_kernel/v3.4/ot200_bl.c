static int ot200_backlight_update_status(struct backlight_device *bl)
{
struct ot200_backlight_data *data = bl_get_data(bl);
int brightness = bl->props.brightness;
if (bl->props.state & BL_CORE_FBBLANK)
brightness = 0;
if (brightness == 0)
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_SETUP, 0);
else if (data->current_brightness == 0) {
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_COUNTER, 0);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_SETUP,
MFGPT_SETUP_CNTEN);
}
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_CMP1,
MAX_COMP2 - dim_table[brightness]);
data->current_brightness = brightness;
return 0;
}
static int ot200_backlight_get_brightness(struct backlight_device *bl)
{
struct ot200_backlight_data *data = bl_get_data(bl);
return data->current_brightness;
}
static int ot200_backlight_probe(struct platform_device *pdev)
{
struct backlight_device *bl;
struct ot200_backlight_data *data;
struct backlight_properties props;
int retval = 0;
if (gpio_request(GPIO_DIMM, "ot200 backlight dimmer") < 0) {
dev_err(&pdev->dev, "failed to request GPIO %d\n", GPIO_DIMM);
return -ENODEV;
}
pwm_timer = cs5535_mfgpt_alloc_timer(7, MFGPT_DOMAIN_ANY);
if (!pwm_timer) {
dev_err(&pdev->dev, "MFGPT 7 not available\n");
retval = -ENODEV;
goto error_mfgpt_alloc;
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
retval = -ENOMEM;
goto error_kzalloc;
}
cs5535_gpio_set(GPIO_DIMM, GPIO_OUTPUT_ENABLE);
cs5535_gpio_set(GPIO_DIMM, GPIO_OUTPUT_AUX1);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_CMP1, 0);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_CMP2, MAX_COMP2);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_SETUP, PWM_SETUP);
data->current_brightness = 100;
props.max_brightness = 100;
props.brightness = 100;
props.type = BACKLIGHT_RAW;
bl = backlight_device_register(dev_name(&pdev->dev), &pdev->dev, data,
&ot200_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
retval = PTR_ERR(bl);
goto error_backlight_device_register;
}
platform_set_drvdata(pdev, bl);
return 0;
error_backlight_device_register:
kfree(data);
error_kzalloc:
cs5535_mfgpt_free_timer(pwm_timer);
error_mfgpt_alloc:
gpio_free(GPIO_DIMM);
return retval;
}
static int ot200_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
struct ot200_backlight_data *data = bl_get_data(bl);
backlight_device_unregister(bl);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_COUNTER, 0);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_SETUP, MFGPT_SETUP_CNTEN);
cs5535_mfgpt_write(pwm_timer, MFGPT_REG_CMP1,
MAX_COMP2 - dim_table[100]);
cs5535_mfgpt_free_timer(pwm_timer);
gpio_free(GPIO_DIMM);
kfree(data);
return 0;
}
