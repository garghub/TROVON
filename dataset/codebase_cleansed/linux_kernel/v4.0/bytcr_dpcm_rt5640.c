static int byt_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
snd_soc_dai_set_bclk_ratio(codec_dai, 50);
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
params_rate(params) * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5640_PLL1_S_BCLK1,
params_rate(params) * 50,
params_rate(params) * 512);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
return ret;
}
return 0;
}
static int byt_codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
snd_mask_set(&params->masks[SNDRV_PCM_HW_PARAM_FORMAT -
SNDRV_PCM_HW_PARAM_FIRST_MASK],
SNDRV_PCM_FORMAT_S24_LE);
return 0;
}
static int byt_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_48000);
}
static int snd_byt_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
snd_soc_card_byt.dev = &pdev->dev;
ret_val = devm_snd_soc_register_card(&pdev->dev, &snd_soc_card_byt);
if (ret_val) {
dev_err(&pdev->dev, "devm_snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &snd_soc_card_byt);
return ret_val;
}
