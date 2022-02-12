static int overo_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 26000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return 0;
}
static int __init overo_soc_init(void)
{
int ret;
if (!(machine_is_overo() || machine_is_cm_t35())) {
pr_debug("Incomatible machine!\n");
return -ENODEV;
}
printk(KERN_INFO "overo SoC init\n");
overo_snd_device = platform_device_alloc("soc-audio", -1);
if (!overo_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(overo_snd_device, &snd_soc_card_overo);
ret = platform_device_add(overo_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(overo_snd_device);
return ret;
}
static void __exit overo_soc_exit(void)
{
platform_device_unregister(overo_snd_device);
}
