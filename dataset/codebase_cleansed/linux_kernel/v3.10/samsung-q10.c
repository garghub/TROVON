static int samsungq10_bl_set_intensity(struct backlight_device *bd)
{
int brightness = bd->props.brightness;
unsigned char c[3] = SAMSUNGQ10_BL_8042_DATA;
c[2] = (unsigned char)brightness;
i8042_lock_chip();
i8042_command(c, (0x30 << 8) | SAMSUNGQ10_BL_8042_CMD);
i8042_unlock_chip();
samsungq10_bl_brightness = brightness;
return 0;
}
static int samsungq10_bl_get_intensity(struct backlight_device *bd)
{
return samsungq10_bl_brightness;
}
static int samsungq10_suspend(struct device *dev)
{
return 0;
}
static int samsungq10_resume(struct device *dev)
{
struct backlight_device *bd = dev_get_drvdata(dev);
samsungq10_bl_set_intensity(bd);
return 0;
}
static int samsungq10_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bd;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = SAMSUNGQ10_BL_MAX_INTENSITY;
bd = backlight_device_register("samsung", &pdev->dev, NULL,
&samsungq10_bl_ops, &props);
if (IS_ERR(bd))
return PTR_ERR(bd);
platform_set_drvdata(pdev, bd);
bd->props.brightness = SAMSUNGQ10_BL_DEFAULT_INTENSITY;
samsungq10_bl_set_intensity(bd);
return 0;
}
static int samsungq10_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
bd->props.brightness = SAMSUNGQ10_BL_DEFAULT_INTENSITY;
samsungq10_bl_set_intensity(bd);
backlight_device_unregister(bd);
return 0;
}
static int __init dmi_check_callback(const struct dmi_system_id *id)
{
printk(KERN_INFO KBUILD_MODNAME ": found model '%s'\n", id->ident);
return 1;
}
static int __init samsungq10_init(void)
{
if (!force && !dmi_check_system(samsungq10_dmi_table))
return -ENODEV;
samsungq10_device = platform_create_bundle(&samsungq10_driver,
samsungq10_probe,
NULL, 0, NULL, 0);
return PTR_RET(samsungq10_device);
}
static void __exit samsungq10_exit(void)
{
platform_device_unregister(samsungq10_device);
platform_driver_unregister(&samsungq10_driver);
}
