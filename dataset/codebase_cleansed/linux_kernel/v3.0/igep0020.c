static int igep2_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set cpu DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 26000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return 0;
}
static int __init igep2_soc_init(void)
{
int ret;
if (!machine_is_igep0020())
return -ENODEV;
printk(KERN_INFO "IGEP v2 SoC init\n");
igep2_snd_device = platform_device_alloc("soc-audio", -1);
if (!igep2_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(igep2_snd_device, &snd_soc_card_igep2);
ret = platform_device_add(igep2_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(igep2_snd_device);
return ret;
}
static void __exit igep2_soc_exit(void)
{
platform_device_unregister(igep2_snd_device);
}
