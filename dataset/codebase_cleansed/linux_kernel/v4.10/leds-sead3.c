static void sead3_pled_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
writel(value, (void __iomem *)SEAD3_CPLD_P_LED);
}
static void sead3_fled_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
writel(value, (void __iomem *)SEAD3_CPLD_F_LED);
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
