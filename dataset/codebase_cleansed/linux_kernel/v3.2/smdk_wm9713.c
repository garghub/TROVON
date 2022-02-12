static int __init smdk_init(void)
{
int ret;
smdk_snd_wm9713_device = platform_device_alloc("wm9713-codec", -1);
if (!smdk_snd_wm9713_device)
return -ENOMEM;
ret = platform_device_add(smdk_snd_wm9713_device);
if (ret)
goto err1;
smdk_snd_ac97_device = platform_device_alloc("soc-audio", -1);
if (!smdk_snd_ac97_device) {
ret = -ENOMEM;
goto err2;
}
platform_set_drvdata(smdk_snd_ac97_device, &smdk);
ret = platform_device_add(smdk_snd_ac97_device);
if (ret)
goto err3;
return 0;
err3:
platform_device_put(smdk_snd_ac97_device);
err2:
platform_device_del(smdk_snd_wm9713_device);
err1:
platform_device_put(smdk_snd_wm9713_device);
return ret;
}
static void __exit smdk_exit(void)
{
platform_device_unregister(smdk_snd_ac97_device);
platform_device_unregister(smdk_snd_wm9713_device);
}
