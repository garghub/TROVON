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
int ret;
codec_dai = cht_get_codec_dai(card);
if (!codec_dai) {
dev_err(card->dev, "Codec dai not found; Unable to set platform clock\n");
return -EIO;
}
if (!SND_SOC_DAPM_EVENT_OFF(event))
return 0;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5645_SCLK_S_RCCLK,
0, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(card->dev, "can't set codec sysclk: %d\n", ret);
return ret;
}
return 0;
}
static int cht_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5645_PLL1_S_MCLK,
CHT_PLAT_CLK_3_HZ, params_rate(params) * 512);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, RT5645_SCLK_S_PLL1,
params_rate(params) * 512, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk: %d\n", ret);
return ret;
}
return 0;
}
static int cht_codec_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
int jack_type;
struct snd_soc_codec *codec = runtime->codec;
struct snd_soc_dai *codec_dai = runtime->codec_dai;
struct cht_mc_private *ctx = snd_soc_card_get_drvdata(runtime->card);
rt5645_sel_asrc_clk_src(codec,
RT5645_DA_STEREO_FILTER |
RT5645_DA_MONO_L_FILTER |
RT5645_DA_MONO_R_FILTER |
RT5645_AD_STEREO_FILTER,
RT5645_CLK_SEL_I2S1_ASRC);
ret = snd_soc_dai_set_tdm_slot(codec_dai, 0xF, 0xF, 4, 24);
if (ret < 0) {
dev_err(runtime->dev, "can't set codec TDM slot %d\n", ret);
return ret;
}
if (ctx->acpi_card->codec_type == CODEC_TYPE_RT5650)
jack_type = SND_JACK_HEADPHONE | SND_JACK_MICROPHONE |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3;
else
jack_type = SND_JACK_HEADPHONE | SND_JACK_MICROPHONE;
ret = snd_soc_card_jack_new(runtime->card, "Headset Jack",
jack_type, &ctx->jack,
NULL, 0);
if (ret) {
dev_err(runtime->dev, "Headset jack creation failed %d\n", ret);
return ret;
}
rt5645_set_jack_detect(codec, &ctx->jack, &ctx->jack, &ctx->jack);
return ret;
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
params_set_format(params, SNDRV_PCM_FORMAT_S24_LE);
return 0;
}
static int cht_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, 48000);
}
static acpi_status snd_acpi_codec_match(acpi_handle handle, u32 level,
void *context, void **ret)
{
*(bool *)context = true;
return AE_OK;
}
static int snd_cht_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
int i;
struct cht_mc_private *drv;
struct snd_soc_card *card = snd_soc_cards[0].soc_card;
bool found = false;
char codec_name[16];
drv = devm_kzalloc(&pdev->dev, sizeof(*drv), GFP_ATOMIC);
if (!drv)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(snd_soc_cards); i++) {
if (ACPI_SUCCESS(acpi_get_devices(
snd_soc_cards[i].codec_id,
snd_acpi_codec_match,
&found, NULL)) && found) {
dev_dbg(&pdev->dev,
"found codec %s\n", snd_soc_cards[i].codec_id);
card = snd_soc_cards[i].soc_card;
drv->acpi_card = &snd_soc_cards[i];
break;
}
}
card->dev = &pdev->dev;
sprintf(codec_name, "i2c-%s:00", drv->acpi_card->codec_id);
strcpy((char *)card->dai_link[2].codec_name, codec_name);
snd_soc_card_set_drvdata(card, drv);
ret_val = devm_snd_soc_register_card(&pdev->dev, card);
if (ret_val) {
dev_err(&pdev->dev,
"snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
platform_set_drvdata(pdev, card);
return ret_val;
}
