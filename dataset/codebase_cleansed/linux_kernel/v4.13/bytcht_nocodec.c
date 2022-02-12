static int codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
int ret;
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
params_set_format(params, SNDRV_PCM_FORMAT_S24_LE);
ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0) {
dev_err(rtd->dev, "can't set format to I2S, err %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x3, 0x3, 2, 24);
if (ret < 0) {
dev_err(rtd->dev, "can't set I2S config, err %d\n", ret);
return ret;
}
return 0;
}
static int aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_48000);
}
static int snd_bytcht_nocodec_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
bytcht_nocodec_card.dev = &pdev->dev;
ret_val = devm_snd_soc_register_card(&pdev->dev, &bytcht_nocodec_card);
if (ret_val) {
dev_err(&pdev->dev, "devm_snd_soc_register_card failed %d\n",
ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &bytcht_nocodec_card);
return ret_val;
}
