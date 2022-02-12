static int exynos4_cfg_i2s(struct platform_device *pdev)
{
switch (pdev->id) {
case 0:
s3c_gpio_cfgpin_range(EXYNOS4_GPZ(0), 7, S3C_GPIO_SFN(2));
break;
case 1:
s3c_gpio_cfgpin_range(EXYNOS4_GPC0(0), 5, S3C_GPIO_SFN(2));
break;
case 2:
s3c_gpio_cfgpin_range(EXYNOS4_GPC1(0), 5, S3C_GPIO_SFN(4));
break;
default:
printk(KERN_ERR "Invalid Device %d\n", pdev->id);
return -EINVAL;
}
return 0;
}
static int exynos4_pcm_cfg_gpio(struct platform_device *pdev)
{
switch (pdev->id) {
case 0:
s3c_gpio_cfgpin_range(EXYNOS4_GPZ(0), 5, S3C_GPIO_SFN(3));
break;
case 1:
s3c_gpio_cfgpin_range(EXYNOS4_GPC0(0), 5, S3C_GPIO_SFN(3));
break;
case 2:
s3c_gpio_cfgpin_range(EXYNOS4_GPC1(0), 5, S3C_GPIO_SFN(3));
break;
default:
printk(KERN_DEBUG "Invalid PCM Controller number!");
return -EINVAL;
}
return 0;
}
static int exynos4_ac97_cfg_gpio(struct platform_device *pdev)
{
return s3c_gpio_cfgpin_range(EXYNOS4_GPC0(0), 5, S3C_GPIO_SFN(4));
}
static int exynos4_spdif_cfg_gpio(struct platform_device *pdev)
{
s3c_gpio_cfgpin_range(EXYNOS4_GPC1(0), 2, S3C_GPIO_SFN(4));
return 0;
}
