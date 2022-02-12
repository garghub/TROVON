static int __init clevo_mail_led_dmi_callback(const struct dmi_system_id *id)
{
printk(KERN_INFO KBUILD_MODNAME ": '%s' found\n", id->ident);
return 1;
}
static void clevo_mail_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
i8042_lock_chip();
if (value == LED_OFF)
i8042_command(NULL, CLEVO_MAIL_LED_OFF);
else if (value <= LED_HALF)
i8042_command(NULL, CLEVO_MAIL_LED_BLINK_0_5HZ);
else
i8042_command(NULL, CLEVO_MAIL_LED_BLINK_1HZ);
i8042_unlock_chip();
}
static int clevo_mail_led_blink(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
int status = -EINVAL;
i8042_lock_chip();
if (*delay_on == 0 && *delay_off == 0 ) {
*delay_on = 1000;
*delay_off = 1000;
i8042_command(NULL, CLEVO_MAIL_LED_BLINK_0_5HZ);
status = 0;
} else if (*delay_on == 500 && *delay_off == 500 ) {
i8042_command(NULL, CLEVO_MAIL_LED_BLINK_1HZ);
status = 0;
} else if (*delay_on == 1000 && *delay_off == 1000 ) {
i8042_command(NULL, CLEVO_MAIL_LED_BLINK_0_5HZ);
status = 0;
} else {
printk(KERN_DEBUG KBUILD_MODNAME
": clevo_mail_led_blink(..., %lu, %lu),"
" returning -EINVAL (unsupported)\n",
*delay_on, *delay_off);
}
i8042_unlock_chip();
return status;
}
static int __devinit clevo_mail_led_probe(struct platform_device *pdev)
{
return led_classdev_register(&pdev->dev, &clevo_mail_led);
}
static int clevo_mail_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&clevo_mail_led);
return 0;
}
static int __init clevo_mail_led_init(void)
{
int error = 0;
int count = 0;
if (!nodetect) {
count = dmi_check_system(clevo_mail_led_dmi_table);
} else {
count = 1;
printk(KERN_ERR KBUILD_MODNAME ": Skipping DMI detection. "
"If the driver works on your hardware please "
"report model and the output of dmidecode in tracker "
"at http://sourceforge.net/projects/clevo-mailled/\n");
}
if (!count)
return -ENODEV;
pdev = platform_device_register_simple(KBUILD_MODNAME, -1, NULL, 0);
if (!IS_ERR(pdev)) {
error = platform_driver_probe(&clevo_mail_led_driver,
clevo_mail_led_probe);
if (error) {
printk(KERN_ERR KBUILD_MODNAME
": Can't probe platform driver\n");
platform_device_unregister(pdev);
}
} else
error = PTR_ERR(pdev);
return error;
}
static void __exit clevo_mail_led_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&clevo_mail_led_driver);
clevo_mail_led_set(NULL, LED_OFF);
}
