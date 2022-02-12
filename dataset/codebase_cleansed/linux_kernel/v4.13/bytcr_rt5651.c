static int byt_rt5651_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
snd_soc_dai_set_bclk_ratio(codec_dai, 50);
ret = snd_soc_dai_set_sysclk(codec_dai, RT5651_SCLK_S_PLL1,
params_rate(params) * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5651_PLL1_S_BCLK1,
params_rate(params) * 50,
params_rate(params) * 512);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
return ret;
}
return 0;
}
static int byt_rt5651_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_card *card = runtime->card;
const struct snd_soc_dapm_route *custom_map;
int num_routes;
card->dapm.idle_bias_off = true;
dmi_check_system(byt_rt5651_quirk_table);
switch (BYT_RT5651_MAP(byt_rt5651_quirk)) {
case BYT_RT5651_IN1_MAP:
custom_map = byt_rt5651_intmic_in1_map;
num_routes = ARRAY_SIZE(byt_rt5651_intmic_in1_map);
break;
case BYT_RT5651_DMIC2_MAP:
custom_map = byt_rt5651_intmic_dmic2_map;
num_routes = ARRAY_SIZE(byt_rt5651_intmic_dmic2_map);
break;
default:
custom_map = byt_rt5651_intmic_dmic1_map;
num_routes = ARRAY_SIZE(byt_rt5651_intmic_dmic1_map);
}
ret = snd_soc_add_card_controls(card, byt_rt5651_controls,
ARRAY_SIZE(byt_rt5651_controls));
if (ret) {
dev_err(card->dev, "unable to add card controls\n");
return ret;
}
snd_soc_dapm_ignore_suspend(&card->dapm, "Headphone");
snd_soc_dapm_ignore_suspend(&card->dapm, "Speaker");
return ret;
}
static int byt_rt5651_codec_fixup(struct snd_soc_pcm_runtime *rtd,
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
SND_SOC_DAIFMT_CBS_CFS
);
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
static int byt_rt5651_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_48000);
}
static int snd_byt_rt5651_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
byt_rt5651_card.dev = &pdev->dev;
ret_val = devm_snd_soc_register_card(&pdev->dev, &byt_rt5651_card);
if (ret_val) {
dev_err(&pdev->dev, "devm_snd_soc_register_card failed %d\n",
ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &byt_rt5651_card);
return ret_val;
}
