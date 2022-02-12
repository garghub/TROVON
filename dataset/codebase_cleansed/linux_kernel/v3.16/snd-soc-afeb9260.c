static int afeb9260_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int err;
err =
snd_soc_dai_set_sysclk(codec_dai, 0, CODEC_CLOCK, SND_SOC_CLOCK_IN);
if (err < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return err;
}
return err;
}
static int __init afeb9260_soc_init(void)
{
int err;
struct device *dev;
if (!(machine_is_afeb9260()))
return -ENODEV;
afeb9260_snd_device = platform_device_alloc("soc-audio", -1);
if (!afeb9260_snd_device) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(afeb9260_snd_device, &snd_soc_machine_afeb9260);
err = platform_device_add(afeb9260_snd_device);
if (err)
goto err1;
dev = &afeb9260_snd_device->dev;
return 0;
err1:
platform_device_put(afeb9260_snd_device);
return err;
}
static void __exit afeb9260_soc_exit(void)
{
platform_device_unregister(afeb9260_snd_device);
}
