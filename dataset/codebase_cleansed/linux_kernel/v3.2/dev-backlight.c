static int samsung_bl_init(struct device *dev)
{
int ret = 0;
struct platform_device *timer_dev =
container_of(dev->parent, struct platform_device, dev);
struct samsung_bl_gpio_info *bl_gpio_info =
timer_dev->dev.platform_data;
ret = gpio_request(bl_gpio_info->no, "Backlight");
if (ret) {
printk(KERN_ERR "failed to request GPIO for LCD Backlight\n");
return ret;
}
s3c_gpio_cfgpin(bl_gpio_info->no, bl_gpio_info->func);
return 0;
}
static void samsung_bl_exit(struct device *dev)
{
struct platform_device *timer_dev =
container_of(dev->parent, struct platform_device, dev);
struct samsung_bl_gpio_info *bl_gpio_info =
timer_dev->dev.platform_data;
s3c_gpio_cfgpin(bl_gpio_info->no, S3C_GPIO_OUTPUT);
gpio_free(bl_gpio_info->no);
}
void samsung_bl_set(struct samsung_bl_gpio_info *gpio_info,
struct platform_pwm_backlight_data *bl_data)
{
int ret = 0;
struct platform_device *samsung_bl_device;
struct platform_pwm_backlight_data *samsung_bl_data;
samsung_bl_device = kmemdup(&samsung_dfl_bl_device,
sizeof(struct platform_device), GFP_KERNEL);
if (!samsung_bl_device) {
printk(KERN_ERR "%s: no memory for platform dev\n", __func__);
return;
}
samsung_bl_data = s3c_set_platdata(&samsung_dfl_bl_data,
sizeof(struct platform_pwm_backlight_data), samsung_bl_device);
if (!samsung_bl_data) {
printk(KERN_ERR "%s: no memory for platform dev\n", __func__);
goto err_data;
}
samsung_bl_data->pwm_id = bl_data->pwm_id;
samsung_bl_device->dev.parent =
&s3c_device_timer[samsung_bl_data->pwm_id].dev;
if (bl_data->max_brightness)
samsung_bl_data->max_brightness = bl_data->max_brightness;
if (bl_data->dft_brightness)
samsung_bl_data->dft_brightness = bl_data->dft_brightness;
if (bl_data->lth_brightness)
samsung_bl_data->lth_brightness = bl_data->lth_brightness;
if (bl_data->pwm_period_ns)
samsung_bl_data->pwm_period_ns = bl_data->pwm_period_ns;
if (bl_data->init)
samsung_bl_data->init = bl_data->init;
if (bl_data->notify)
samsung_bl_data->notify = bl_data->notify;
if (bl_data->exit)
samsung_bl_data->exit = bl_data->exit;
if (bl_data->check_fb)
samsung_bl_data->check_fb = bl_data->check_fb;
s3c_device_timer[samsung_bl_data->pwm_id].dev.platform_data = gpio_info;
ret = platform_device_register(
&s3c_device_timer[samsung_bl_data->pwm_id]);
if (ret) {
printk(KERN_ERR "failed to register pwm timer for backlight: %d\n", ret);
goto err_plat_reg1;
}
ret = platform_device_register(samsung_bl_device);
if (ret) {
printk(KERN_ERR "failed to register backlight device: %d\n", ret);
goto err_plat_reg2;
}
return;
err_plat_reg2:
platform_device_unregister(&s3c_device_timer[samsung_bl_data->pwm_id]);
err_plat_reg1:
kfree(samsung_bl_data);
err_data:
kfree(samsung_bl_device);
return;
}
