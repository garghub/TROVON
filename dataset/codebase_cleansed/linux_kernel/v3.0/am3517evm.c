static int am3517evm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_DSP_B |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_DSP_B |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set cpu DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
CODEC_CLOCK, SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, OMAP_MCBSP_CLKR_SRC_CLKX, 0,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set CPU system clock OMAP_MCBSP_CLKR_SRC_CLKX\n");
return ret;
}
snd_soc_dai_set_sysclk(cpu_dai, OMAP_MCBSP_FSR_SRC_FSX, 0,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set CPU system clock OMAP_MCBSP_FSR_SRC_FSX\n");
return ret;
}
return 0;
}
static int am3517evm_aic23_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, tlv320aic23_dapm_widgets,
ARRAY_SIZE(tlv320aic23_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_enable_pin(dapm, "Line Out");
snd_soc_dapm_enable_pin(dapm, "Line In");
snd_soc_dapm_enable_pin(dapm, "Mic In");
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init am3517evm_soc_init(void)
{
int ret;
if (!machine_is_omap3517evm())
return -ENODEV;
pr_info("OMAP3517 / AM3517 EVM SoC init\n");
am3517evm_snd_device = platform_device_alloc("soc-audio", -1);
if (!am3517evm_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(am3517evm_snd_device, &snd_soc_am3517evm);
ret = platform_device_add(am3517evm_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(am3517evm_snd_device);
return ret;
}
static void __exit am3517evm_soc_exit(void)
{
platform_device_unregister(am3517evm_snd_device);
}
