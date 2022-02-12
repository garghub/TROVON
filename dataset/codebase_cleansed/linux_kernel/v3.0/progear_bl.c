static int progearbl_set_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
pci_write_config_byte(pmu_dev, PMU_LPCR, intensity + HW_LEVEL_MIN);
return 0;
}
static int progearbl_get_intensity(struct backlight_device *bd)
{
u8 intensity;
pci_read_config_byte(pmu_dev, PMU_LPCR, &intensity);
return intensity - HW_LEVEL_MIN;
}
static int progearbl_probe(struct platform_device *pdev)
{
struct backlight_properties props;
u8 temp;
struct backlight_device *progear_backlight_device;
int ret;
pmu_dev = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M7101, NULL);
if (!pmu_dev) {
printk("ALI M7101 PMU not found.\n");
return -ENODEV;
}
sb_dev = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M1533, NULL);
if (!sb_dev) {
printk("ALI 1533 SB not found.\n");
ret = -ENODEV;
goto put_pmu;
}
pci_read_config_byte(sb_dev, SB_MPS1, &temp);
pci_write_config_byte(sb_dev, SB_MPS1, temp | 0x20);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = HW_LEVEL_MAX - HW_LEVEL_MIN;
progear_backlight_device = backlight_device_register("progear-bl",
&pdev->dev, NULL,
&progearbl_ops,
&props);
if (IS_ERR(progear_backlight_device)) {
ret = PTR_ERR(progear_backlight_device);
goto put_sb;
}
platform_set_drvdata(pdev, progear_backlight_device);
progear_backlight_device->props.power = FB_BLANK_UNBLANK;
progear_backlight_device->props.brightness = HW_LEVEL_MAX - HW_LEVEL_MIN;
progearbl_set_intensity(progear_backlight_device);
return 0;
put_sb:
pci_dev_put(sb_dev);
put_pmu:
pci_dev_put(pmu_dev);
return ret;
}
static int progearbl_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
backlight_device_unregister(bd);
return 0;
}
static int __init progearbl_init(void)
{
int ret = platform_driver_register(&progearbl_driver);
if (ret)
return ret;
progearbl_device = platform_device_register_simple("progear-bl", -1,
NULL, 0);
if (IS_ERR(progearbl_device)) {
platform_driver_unregister(&progearbl_driver);
return PTR_ERR(progearbl_device);
}
return 0;
}
static void __exit progearbl_exit(void)
{
pci_dev_put(pmu_dev);
pci_dev_put(sb_dev);
platform_device_unregister(progearbl_device);
platform_driver_unregister(&progearbl_driver);
}
