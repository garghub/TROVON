static int samsungq10_bl_set_intensity(struct backlight_device *bd)
{
acpi_status status;
int i;
for (i = 0; i < SAMSUNGQ10_BL_MAX_INTENSITY; i++) {
status = acpi_evaluate_object(ec_handle, "_Q63", NULL, NULL);
if (ACPI_FAILURE(status))
return -EIO;
}
for (i = 0; i < bd->props.brightness; i++) {
status = acpi_evaluate_object(ec_handle, "_Q64", NULL, NULL);
if (ACPI_FAILURE(status))
return -EIO;
}
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
return 0;
}
static int samsungq10_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
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
ec_handle = ec_get_handle();
if (!ec_handle)
return -ENODEV;
samsungq10_device = platform_create_bundle(&samsungq10_driver,
samsungq10_probe,
NULL, 0, NULL, 0);
return PTR_ERR_OR_ZERO(samsungq10_device);
}
static void __exit samsungq10_exit(void)
{
platform_device_unregister(samsungq10_device);
platform_driver_unregister(&samsungq10_driver);
}
