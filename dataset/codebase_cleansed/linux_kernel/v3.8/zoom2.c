static int zoom2_hw_params(struct snd_pcm_substream *substream,
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
static int zoom2_twl4030_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "CARKITMIC");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC0");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC1");
snd_soc_dapm_nc_pin(dapm, "EARPIECE");
snd_soc_dapm_nc_pin(dapm, "PREDRIVEL");
snd_soc_dapm_nc_pin(dapm, "PREDRIVER");
snd_soc_dapm_nc_pin(dapm, "CARKITL");
snd_soc_dapm_nc_pin(dapm, "CARKITR");
return 0;
}
static int zoom2_twl4030_voice_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
unsigned short reg;
reg = codec->driver->read(codec, TWL4030_REG_VOICE_IF);
reg |= TWL4030_VIF_DIN_EN | TWL4030_VIF_DOUT_EN | TWL4030_VIF_EN;
codec->driver->write(codec, TWL4030_REG_VOICE_IF, reg);
return 0;
}
static int __init zoom2_soc_init(void)
{
int ret;
if (!machine_is_omap_zoom2())
return -ENODEV;
printk(KERN_INFO "Zoom2 SoC init\n");
zoom2_snd_device = platform_device_alloc("soc-audio", -1);
if (!zoom2_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(zoom2_snd_device, &snd_soc_zoom2);
ret = platform_device_add(zoom2_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(zoom2_snd_device);
return ret;
}
static void __exit zoom2_soc_exit(void)
{
platform_device_unregister(zoom2_snd_device);
}
