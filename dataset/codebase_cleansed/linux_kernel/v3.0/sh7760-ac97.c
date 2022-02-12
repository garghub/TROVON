static int machine_init(struct snd_soc_pcm_runtime *rtd)
{
snd_soc_dapm_sync(&rtd->codec->dapm);
return 0;
}
static int __init sh7760_ac97_init(void)
{
int ret;
unsigned short ipsel;
ipsel = __raw_readw(IPSEL);
__raw_writew(ipsel | (3 << 10), IPSEL);
ret = -ENOMEM;
sh7760_ac97_snd_device = platform_device_alloc("soc-audio", -1);
if (!sh7760_ac97_snd_device)
goto out;
platform_set_drvdata(sh7760_ac97_snd_device,
&sh7760_ac97_soc_machine);
ret = platform_device_add(sh7760_ac97_snd_device);
if (ret)
platform_device_put(sh7760_ac97_snd_device);
out:
return ret;
}
static void __exit sh7760_ac97_exit(void)
{
platform_device_unregister(sh7760_ac97_snd_device);
}
