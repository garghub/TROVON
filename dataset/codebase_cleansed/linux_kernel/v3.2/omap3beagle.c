static int omap3beagle_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int fmt;
int ret;
switch (params_channels(params)) {
case 2:
fmt = SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
break;
case 4:
fmt = SND_SOC_DAIFMT_DSP_A |
SND_SOC_DAIFMT_IB_NF |
SND_SOC_DAIFMT_CBM_CFM;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_fmt(codec_dai, fmt);
if (ret < 0) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai, fmt);
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
static int __init omap3beagle_soc_init(void)
{
int ret;
if (!(machine_is_omap3_beagle() || machine_is_devkit8000()))
return -ENODEV;
pr_info("OMAP3 Beagle/Devkit8000 SoC init\n");
omap3beagle_snd_device = platform_device_alloc("soc-audio", -1);
if (!omap3beagle_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(omap3beagle_snd_device, &snd_soc_omap3beagle);
ret = platform_device_add(omap3beagle_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(omap3beagle_snd_device);
return ret;
}
static void __exit omap3beagle_soc_exit(void)
{
platform_device_unregister(omap3beagle_snd_device);
}
