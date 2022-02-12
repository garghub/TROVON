static void sead3_pled_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
pr_debug("sead3_pled_set\n");
writel(value, (void __iomem *)0xBF000210);
}
static void sead3_fled_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
pr_debug("sead3_fled_set\n");
writel(value, (void __iomem *)0xBF000218);
}
static int sead3_led_suspend(struct platform_device *dev,
pm_message_t state)
{
led_classdev_suspend(&sead3_pled);
led_classdev_suspend(&sead3_fled);
return 0;
}
static int sead3_led_resume(struct platform_device *dev)
{
led_classdev_resume(&sead3_pled);
led_classdev_resume(&sead3_fled);
return 0;
}
static int sead3_led_probe(struct platform_device *pdev)
{
int ret;
ret = led_classdev_register(&pdev->dev, &sead3_pled);
if (ret < 0)
return ret;
ret = led_classdev_register(&pdev->dev, &sead3_fled);
if (ret < 0)
led_classdev_unregister(&sead3_pled);
return ret;
}
static int sead3_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&sead3_pled);
led_classdev_unregister(&sead3_fled);
return 0;
}
static int __init sead3_led_init(void)
{
int ret;
ret = platform_driver_register(&sead3_led_driver);
if (ret < 0)
goto out;
pdev = platform_device_register_simple(DRVNAME, -1, NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
platform_driver_unregister(&sead3_led_driver);
goto out;
}
out:
return ret;
}
static void __exit sead3_led_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&sead3_led_driver);
}
