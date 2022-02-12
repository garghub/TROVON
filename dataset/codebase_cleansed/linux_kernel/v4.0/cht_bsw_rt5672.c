static inline struct snd_soc_dai *cht_get_codec_dai(struct snd_soc_card *card)
{
int i;
for (i = 0; i < card->num_rtd; i++) {
struct snd_soc_pcm_runtime *rtd;
rtd = card->rtd + i;
if (!strncmp(rtd->codec_dai->name, CHT_CODEC_DAI,
strlen(CHT_CODEC_DAI)))
return rtd->codec_dai;
}
return NULL;
}
static int platform_clock_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct snd_soc_dai *codec_dai;
codec_dai = cht_get_codec_dai(card);
if (!codec_dai) {
dev_err(card->dev, "Codec dai not found; Unable to set platform clock\n");
return -EIO;
}
if (!SND_SOC_DAPM_EVENT_OFF(event))
return 0;
snd_soc_dai_set_sysclk(codec_dai, RT5670_SCLK_S_RCCLK,
0, SND_SOC_CLOCK_IN);
return 0;
}
static int cht_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5670_PLL1_S_MCLK,
CHT_PLAT_CLK_3_HZ, params_rate(params) * 512);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, RT5670_SCLK_S_PLL1,
params_rate(params) * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk: %d\n", ret);
return ret;
}
return 0;
}
static int cht_codec_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_dai *codec_dai = runtime->codec_dai;
struct snd_soc_codec *codec = codec_dai->codec;
ret = snd_soc_dai_set_tdm_slot(codec_dai, 0xF, 0xF, 4, 24);
if (ret < 0) {
dev_err(runtime->dev, "can't set codec TDM slot %d\n", ret);
return ret;
}
rt5670_sel_asrc_clk_src(codec,
RT5670_DA_STEREO_FILTER
| RT5670_DA_MONO_L_FILTER
| RT5670_DA_MONO_R_FILTER
| RT5670_AD_STEREO_FILTER
| RT5670_AD_MONO_L_FILTER
| RT5670_AD_MONO_R_FILTER,
RT5670_CLK_SEL_I2S1_ASRC);
return 0;
}
static int cht_codec_fixup(struct snd_soc_pcm_runtime *rtd,
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
static int cht_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_48000);
}
static int snd_cht_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
snd_soc_card_cht.dev = &pdev->dev;
ret_val = devm_snd_soc_register_card(&pdev->dev, &snd_soc_card_cht);
if (ret_val) {
dev_err(&pdev->dev,
"snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &snd_soc_card_cht);
return ret_val;
}
