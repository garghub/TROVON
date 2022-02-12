static int s3c64xx_i2s_cfg_gpio(struct platform_device *pdev)
{
unsigned int base;
switch (pdev->id) {
case 0:
base = S3C64XX_GPD(0);
break;
case 1:
base = S3C64XX_GPE(0);
break;
case 2:
s3c_gpio_cfgpin(S3C64XX_GPC(4), S3C_GPIO_SFN(5));
s3c_gpio_cfgpin(S3C64XX_GPC(5), S3C_GPIO_SFN(5));
s3c_gpio_cfgpin(S3C64XX_GPC(7), S3C_GPIO_SFN(5));
s3c_gpio_cfgpin_range(S3C64XX_GPH(6), 4, S3C_GPIO_SFN(5));
return 0;
default:
printk(KERN_DEBUG "Invalid I2S Controller number: %d\n",
pdev->id);
return -EINVAL;
}
s3c_gpio_cfgpin_range(base, 5, S3C_GPIO_SFN(3));
return 0;
}
static int s3c64xx_pcm_cfg_gpio(struct platform_device *pdev)
{
unsigned int base;
switch (pdev->id) {
case 0:
base = S3C64XX_GPD(0);
break;
case 1:
base = S3C64XX_GPE(0);
break;
default:
printk(KERN_DEBUG "Invalid PCM Controller number: %d\n",
pdev->id);
return -EINVAL;
}
s3c_gpio_cfgpin_range(base, 5, S3C_GPIO_SFN(2));
return 0;
}
static int s3c64xx_ac97_cfg_gpd(struct platform_device *pdev)
{
return s3c_gpio_cfgpin_range(S3C64XX_GPD(0), 5, S3C_GPIO_SFN(4));
}
static int s3c64xx_ac97_cfg_gpe(struct platform_device *pdev)
{
return s3c_gpio_cfgpin_range(S3C64XX_GPE(0), 5, S3C_GPIO_SFN(4));
}
void __init s3c64xx_ac97_setup_gpio(int num)
{
if (num == S3C64XX_AC97_GPD)
s3c_ac97_pdata.cfg_gpio = s3c64xx_ac97_cfg_gpd;
else
s3c_ac97_pdata.cfg_gpio = s3c64xx_ac97_cfg_gpe;
}
