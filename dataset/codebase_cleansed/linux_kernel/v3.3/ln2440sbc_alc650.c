static int __init ln2440sbc_init(void)
{
int ret;
ln2440sbc_snd_ac97_device = platform_device_alloc("soc-audio", -1);
if (!ln2440sbc_snd_ac97_device)
return -ENOMEM;
platform_set_drvdata(ln2440sbc_snd_ac97_device, &ln2440sbc);
ret = platform_device_add(ln2440sbc_snd_ac97_device);
if (ret)
platform_device_put(ln2440sbc_snd_ac97_device);
return ret;
}
static void __exit ln2440sbc_exit(void)
{
platform_device_unregister(ln2440sbc_snd_ac97_device);
}
