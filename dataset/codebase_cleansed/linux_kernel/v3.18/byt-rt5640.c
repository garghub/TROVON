static int byt_rt5640_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
params_rate(params) * 256,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(codec_dai->dev, "can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5640_PLL1_S_BCLK1,
params_rate(params) * 64,
params_rate(params) * 256);
if (ret < 0) {
dev_err(codec_dai->dev, "can't set codec pll: %d\n", ret);
return ret;
}
return 0;
}
static int byt_rt5640_quirk_cb(const struct dmi_system_id *id)
{
byt_rt5640_quirk = (unsigned long)id->driver_data;
return 1;
}
static int byt_rt5640_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_codec *codec = runtime->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct snd_soc_card *card = runtime->card;
const struct snd_soc_dapm_route *custom_map;
int num_routes;
card->dapm.idle_bias_off = true;
ret = snd_soc_add_card_controls(card, byt_rt5640_controls,
ARRAY_SIZE(byt_rt5640_controls));
if (ret) {
dev_err(card->dev, "unable to add card controls\n");
return ret;
}
dmi_check_system(byt_rt5640_quirk_table);
switch (BYT_RT5640_MAP(byt_rt5640_quirk)) {
case BYT_RT5640_IN1_MAP:
custom_map = byt_rt5640_intmic_in1_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_in1_map);
break;
case BYT_RT5640_DMIC2_MAP:
custom_map = byt_rt5640_intmic_dmic2_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic2_map);
break;
default:
custom_map = byt_rt5640_intmic_dmic1_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic1_map);
}
ret = snd_soc_dapm_add_routes(dapm, custom_map, num_routes);
if (ret)
return ret;
if (byt_rt5640_quirk & BYT_RT5640_DMIC_EN) {
ret = rt5640_dmic_enable(codec, 0, 0);
if (ret)
return ret;
}
snd_soc_dapm_ignore_suspend(dapm, "HPOL");
snd_soc_dapm_ignore_suspend(dapm, "HPOR");
snd_soc_dapm_ignore_suspend(dapm, "SPOLP");
snd_soc_dapm_ignore_suspend(dapm, "SPOLN");
snd_soc_dapm_ignore_suspend(dapm, "SPORP");
snd_soc_dapm_ignore_suspend(dapm, "SPORN");
return ret;
}
static int byt_rt5640_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &byt_rt5640_card;
card->dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, card);
}
