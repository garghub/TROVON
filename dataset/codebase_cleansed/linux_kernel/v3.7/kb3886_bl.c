static void kb3886_bl_set_intensity(int intensity)
{
mutex_lock(&bl_mutex);
intensity = intensity&0xff;
outb(KB3886_ADC_DAC_PWM, KB3886_PARENT);
usleep_range(10000, 11000);
outb(KB3886_PWM0_WRITE, KB3886_IO);
usleep_range(10000, 11000);
outb(intensity, KB3886_IO);
mutex_unlock(&bl_mutex);
}
static int kb3886bl_send_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
if (kb3886bl_flags & KB3886BL_SUSPENDED)
intensity = 0;
bl_machinfo->set_bl_intensity(intensity);
kb3886bl_intensity = intensity;
return 0;
}
static int kb3886bl_suspend(struct platform_device *pdev, pm_message_t state)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
kb3886bl_flags |= KB3886BL_SUSPENDED;
backlight_update_status(bd);
return 0;
}
static int kb3886bl_resume(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
kb3886bl_flags &= ~KB3886BL_SUSPENDED;
backlight_update_status(bd);
return 0;
}
static int kb3886bl_get_intensity(struct backlight_device *bd)
{
return kb3886bl_intensity;
}
static int kb3886bl_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct kb3886bl_machinfo *machinfo = pdev->dev.platform_data;
bl_machinfo = machinfo;
if (!machinfo->limit_mask)
machinfo->limit_mask = -1;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = machinfo->max_intensity;
kb3886_backlight_device = backlight_device_register("kb3886-bl",
&pdev->dev, NULL,
&kb3886bl_ops,
&props);
if (IS_ERR(kb3886_backlight_device))
return PTR_ERR(kb3886_backlight_device);
platform_set_drvdata(pdev, kb3886_backlight_device);
kb3886_backlight_device->props.power = FB_BLANK_UNBLANK;
kb3886_backlight_device->props.brightness = machinfo->default_intensity;
backlight_update_status(kb3886_backlight_device);
return 0;
}
static int kb3886bl_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
backlight_device_unregister(bd);
return 0;
}
static int __init kb3886_init(void)
{
if (!dmi_check_system(kb3886bl_device_table))
return -ENODEV;
platform_add_devices(devices, ARRAY_SIZE(devices));
return platform_driver_register(&kb3886bl_driver);
}
static void __exit kb3886_exit(void)
{
platform_driver_unregister(&kb3886bl_driver);
}
