static int samsung_bl_init(struct device *dev)
{
int ret = 0;
struct platform_pwm_backlight_data *pdata = dev->platform_data;
struct samsung_bl_drvdata *drvdata = container_of(pdata,
struct samsung_bl_drvdata, plat_data);
struct samsung_bl_gpio_info *bl_gpio_info = drvdata->gpio_info;
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
struct platform_pwm_backlight_data *pdata = dev->platform_data;
struct samsung_bl_drvdata *drvdata = container_of(pdata,
struct samsung_bl_drvdata, plat_data);
struct samsung_bl_gpio_info *bl_gpio_info = drvdata->gpio_info;
s3c_gpio_cfgpin(bl_gpio_info->no, S3C_GPIO_OUTPUT);
gpio_free(bl_gpio_info->no);
}
void __init samsung_bl_set(struct samsung_bl_gpio_info *gpio_info,
struct platform_pwm_backlight_data *bl_data)
{
int ret = 0;
struct platform_device *samsung_bl_device;
struct samsung_bl_drvdata *samsung_bl_drvdata;
struct platform_pwm_backlight_data *samsung_bl_data;
samsung_bl_device = kmemdup(&samsung_dfl_bl_device,
sizeof(struct platform_device), GFP_KERNEL);
if (!samsung_bl_device) {
printk(KERN_ERR "%s: no memory for platform dev\n", __func__);
return;
}
samsung_bl_drvdata = kmemdup(&samsung_dfl_bl_data,
sizeof(samsung_dfl_bl_data), GFP_KERNEL);
if (!samsung_bl_drvdata) {
printk(KERN_ERR "%s: no memory for platform dev\n", __func__);
goto err_data;
}
samsung_bl_device->dev.platform_data = &samsung_bl_drvdata->plat_data;
samsung_bl_drvdata->gpio_info = gpio_info;
samsung_bl_data = &samsung_bl_drvdata->plat_data;
samsung_bl_data->pwm_id = bl_data->pwm_id;
samsung_bl_device->dev.parent = &samsung_device_pwm.dev;
if (bl_data->max_brightness)
samsung_bl_data->max_brightness = bl_data->max_brightness;
if (bl_data->dft_brightness)
samsung_bl_data->dft_brightness = bl_data->dft_brightness;
if (bl_data->lth_brightness)
samsung_bl_data->lth_brightness = bl_data->lth_brightness;
if (bl_data->pwm_period_ns)
samsung_bl_data->pwm_period_ns = bl_data->pwm_period_ns;
if (bl_data->enable_gpio >= 0)
samsung_bl_data->enable_gpio = bl_data->enable_gpio;
if (bl_data->init)
samsung_bl_data->init = bl_data->init;
if (bl_data->notify)
samsung_bl_data->notify = bl_data->notify;
if (bl_data->notify_after)
samsung_bl_data->notify_after = bl_data->notify_after;
if (bl_data->exit)
samsung_bl_data->exit = bl_data->exit;
if (bl_data->check_fb)
samsung_bl_data->check_fb = bl_data->check_fb;
ret = platform_device_register(samsung_bl_device);
if (ret) {
printk(KERN_ERR "failed to register backlight device: %d\n", ret);
goto err_plat_reg2;
}
return;
err_plat_reg2:
kfree(samsung_bl_data);
err_data:
kfree(samsung_bl_device);
return;
}
