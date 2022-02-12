static int __init smdk2443_init(void)
{
int ret;
smdk2443_snd_ac97_device = platform_device_alloc("soc-audio", -1);
if (!smdk2443_snd_ac97_device)
return -ENOMEM;
platform_set_drvdata(smdk2443_snd_ac97_device, &smdk2443);
ret = platform_device_add(smdk2443_snd_ac97_device);
if (ret)
platform_device_put(smdk2443_snd_ac97_device);
return ret;
}
static void __exit smdk2443_exit(void)
{
platform_device_unregister(smdk2443_snd_ac97_device);
}
