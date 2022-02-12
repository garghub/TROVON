static int __init imx_phycore_init(void)
{
int ret;
if (!machine_is_pcm043() && !machine_is_pca100())
return 0;
imx_phycore_snd_ac97_device = platform_device_alloc("soc-audio", -1);
if (!imx_phycore_snd_ac97_device)
return -ENOMEM;
platform_set_drvdata(imx_phycore_snd_ac97_device, &imx_phycore);
ret = platform_device_add(imx_phycore_snd_ac97_device);
if (ret)
goto fail1;
imx_phycore_snd_device = platform_device_alloc("wm9712-codec", -1);
if (!imx_phycore_snd_device) {
ret = -ENOMEM;
goto fail2;
}
ret = platform_device_add(imx_phycore_snd_device);
if (ret) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
goto fail3;
}
return 0;
fail3:
platform_device_put(imx_phycore_snd_device);
fail2:
platform_device_del(imx_phycore_snd_ac97_device);
fail1:
platform_device_put(imx_phycore_snd_ac97_device);
return ret;
}
static void __exit imx_phycore_exit(void)
{
platform_device_unregister(imx_phycore_snd_device);
platform_device_unregister(imx_phycore_snd_ac97_device);
}
