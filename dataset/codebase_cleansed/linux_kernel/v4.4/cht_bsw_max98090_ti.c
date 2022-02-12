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
static int cht_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, M98090_REG_SYSTEM_CLOCK,
CHT_PLAT_CLK_3_HZ, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk: %d\n", ret);
return ret;
}
return 0;
}
static int cht_ti_jack_event(struct notifier_block *nb,
unsigned long event, void *data)
{
struct snd_soc_jack *jack = (struct snd_soc_jack *)data;
struct snd_soc_dapm_context *dapm = &jack->card->dapm;
if (event & SND_JACK_MICROPHONE) {
snd_soc_dapm_force_enable_pin(dapm, "SHDN");
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS");
snd_soc_dapm_sync(dapm);
} else {
snd_soc_dapm_disable_pin(dapm, "MICBIAS");
snd_soc_dapm_disable_pin(dapm, "SHDN");
snd_soc_dapm_sync(dapm);
}
return 0;
}
static int cht_codec_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
int jack_type;
struct cht_mc_private *ctx = snd_soc_card_get_drvdata(runtime->card);
struct snd_soc_jack *jack = &ctx->jack;
if (ctx->ts3a227e_present)
jack_type = SND_JACK_HEADPHONE | SND_JACK_MICROPHONE |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3;
else
jack_type = SND_JACK_HEADPHONE | SND_JACK_MICROPHONE;
ret = snd_soc_card_jack_new(runtime->card, "Headset Jack",
jack_type, jack, NULL, 0);
if (ret) {
dev_err(runtime->dev, "Headset Jack creation failed %d\n", ret);
return ret;
}
if (ctx->ts3a227e_present)
snd_soc_jack_notifier_register(jack, &cht_jack_nb);
return ret;
}
static int cht_codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
int ret = 0;
unsigned int fmt = 0;
ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x3, 0x3, 2, 16);
if (ret < 0) {
dev_err(rtd->dev, "can't set cpu_dai slot fmt: %d\n", ret);
return ret;
}
fmt = SND_SOC_DAIFMT_LEFT_J | SND_SOC_DAIFMT_NB_NF
| SND_SOC_DAIFMT_CBS_CFS;
ret = snd_soc_dai_set_fmt(rtd->cpu_dai, fmt);
if (ret < 0) {
dev_err(rtd->dev, "can't set cpu_dai set fmt: %d\n", ret);
return ret;
}
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
static int cht_max98090_headset_init(struct snd_soc_component *component)
{
struct snd_soc_card *card = component->card;
struct cht_mc_private *ctx = snd_soc_card_get_drvdata(card);
return ts3a227e_enable_jack_detect(component, &ctx->jack);
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
bool found = false;
struct cht_mc_private *drv;
drv = devm_kzalloc(&pdev->dev, sizeof(*drv), GFP_ATOMIC);
if (!drv)
return -ENOMEM;
if (ACPI_SUCCESS(acpi_get_devices(
"104C227E",
snd_acpi_codec_match,
&found, NULL)) && found) {
drv->ts3a227e_present = true;
} else {
snd_soc_card_cht.aux_dev = NULL;
snd_soc_card_cht.num_aux_devs = 0;
drv->ts3a227e_present = false;
}
snd_soc_card_cht.dev = &pdev->dev;
snd_soc_card_set_drvdata(&snd_soc_card_cht, drv);
ret_val = devm_snd_soc_register_card(&pdev->dev, &snd_soc_card_cht);
if (ret_val) {
dev_err(&pdev->dev,
"snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &snd_soc_card_cht);
return ret_val;
}
