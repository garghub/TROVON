static int osk_startup(struct snd_pcm_substream *substream)
{
return clk_enable(tlv320aic23_mclk);
}
static void osk_shutdown(struct snd_pcm_substream *substream)
{
clk_disable(tlv320aic23_mclk);
}
static int osk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int err;
err = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_DSP_B |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (err < 0) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return err;
}
err = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_DSP_B |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (err < 0) {
printk(KERN_ERR "can't set cpu DAI configuration\n");
return err;
}
err =
snd_soc_dai_set_sysclk(codec_dai, 0, CODEC_CLOCK, SND_SOC_CLOCK_IN);
if (err < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return err;
}
return err;
}
static int osk_tlv320aic23_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, tlv320aic23_dapm_widgets,
ARRAY_SIZE(tlv320aic23_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Line In");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init osk_soc_init(void)
{
int err;
u32 curRate;
struct device *dev;
if (!(machine_is_omap_osk()))
return -ENODEV;
osk_snd_device = platform_device_alloc("soc-audio", -1);
if (!osk_snd_device)
return -ENOMEM;
platform_set_drvdata(osk_snd_device, &snd_soc_card_osk);
err = platform_device_add(osk_snd_device);
if (err)
goto err1;
dev = &osk_snd_device->dev;
tlv320aic23_mclk = clk_get(dev, "mclk");
if (IS_ERR(tlv320aic23_mclk)) {
printk(KERN_ERR "Could not get mclk clock\n");
err = PTR_ERR(tlv320aic23_mclk);
goto err2;
}
curRate = (uint) clk_get_rate(tlv320aic23_mclk);
if (curRate != CODEC_CLOCK) {
if (clk_set_rate(tlv320aic23_mclk, CODEC_CLOCK)) {
printk(KERN_ERR "Cannot set MCLK for AIC23 CODEC\n");
err = -ECANCELED;
goto err3;
}
}
printk(KERN_INFO "MCLK = %d [%d]\n",
(uint) clk_get_rate(tlv320aic23_mclk), CODEC_CLOCK);
return 0;
err3:
clk_put(tlv320aic23_mclk);
err2:
platform_device_del(osk_snd_device);
err1:
platform_device_put(osk_snd_device);
return err;
}
static void __exit osk_soc_exit(void)
{
clk_put(tlv320aic23_mclk);
platform_device_unregister(osk_snd_device);
}
