static int zylonite_wm9713_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
if (clk_pout)
snd_soc_dai_set_pll(rtd->codec_dai, 0, 0,
clk_get_rate(pout), 0);
snd_soc_dapm_new_controls(dapm, zylonite_dapm_widgets,
ARRAY_SIZE(zylonite_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_enable_pin(dapm, "Headphone");
snd_soc_dapm_enable_pin(dapm, "Headset Earpiece");
snd_soc_dapm_sync(dapm);
return 0;
}
static int zylonite_voice_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int pll_out = 0;
unsigned int wm9713_div = 0;
int ret = 0;
int rate = params_rate(params);
int width = snd_pcm_format_physical_width(params_format(params));
switch (rate) {
case 8000:
wm9713_div = 12;
break;
case 16000:
wm9713_div = 6;
break;
case 48000:
wm9713_div = 2;
break;
default:
return -EINVAL;
}
pll_out = rate * (width + 1) * 8;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_AUDIO, 0, 1);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(cpu_dai, 0, 0, 0, pll_out);
if (ret < 0)
return ret;
if (clk_pout)
ret = snd_soc_dai_set_clkdiv(codec_dai, WM9713_PCMCLK_PLL_DIV,
WM9713_PCMDIV(wm9713_div));
else
ret = snd_soc_dai_set_clkdiv(codec_dai, WM9713_PCMCLK_DIV,
WM9713_PCMDIV(wm9713_div));
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
return 0;
}
static int zylonite_probe(struct snd_soc_card *card)
{
int ret;
if (clk_pout) {
pout = clk_get(NULL, "CLK_POUT");
if (IS_ERR(pout)) {
dev_err(&pdev->dev, "Unable to obtain CLK_POUT: %ld\n",
PTR_ERR(pout));
return PTR_ERR(pout);
}
ret = clk_enable(pout);
if (ret != 0) {
dev_err(&pdev->dev, "Unable to enable CLK_POUT: %d\n",
ret);
clk_put(pout);
return ret;
}
dev_dbg(&pdev->dev, "MCLK enabled at %luHz\n",
clk_get_rate(pout));
}
return 0;
}
static int zylonite_remove(struct snd_soc_card *card)
{
if (clk_pout) {
clk_disable(pout);
clk_put(pout);
}
return 0;
}
static int zylonite_suspend_post(struct snd_soc_card *card)
{
if (clk_pout)
clk_disable(pout);
return 0;
}
static int zylonite_resume_pre(struct snd_soc_card *card)
{
int ret = 0;
if (clk_pout) {
ret = clk_enable(pout);
if (ret != 0)
dev_err(&pdev->dev, "Unable to enable CLK_POUT: %d\n",
ret);
}
return ret;
}
static int __init zylonite_init(void)
{
int ret;
zylonite_snd_ac97_device = platform_device_alloc("soc-audio", -1);
if (!zylonite_snd_ac97_device)
return -ENOMEM;
platform_set_drvdata(zylonite_snd_ac97_device, &zylonite);
ret = platform_device_add(zylonite_snd_ac97_device);
if (ret != 0)
platform_device_put(zylonite_snd_ac97_device);
return ret;
}
static void __exit zylonite_exit(void)
{
platform_device_unregister(zylonite_snd_ac97_device);
}
