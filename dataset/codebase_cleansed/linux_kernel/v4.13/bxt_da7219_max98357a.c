static inline struct snd_soc_dai *bxt_get_codec_dai(struct snd_soc_card *card)
{
struct snd_soc_pcm_runtime *rtd;
list_for_each_entry(rtd, &card->rtd_list, list) {
if (!strncmp(rtd->codec_dai->name, BXT_DIALOG_CODEC_DAI,
strlen(BXT_DIALOG_CODEC_DAI)))
return rtd->codec_dai;
}
return NULL;
}
static int platform_clock_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
int ret = 0;
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct snd_soc_dai *codec_dai;
codec_dai = bxt_get_codec_dai(card);
if (!codec_dai) {
dev_err(card->dev, "Codec dai not found; Unable to set/unset codec pll\n");
return -EIO;
}
if (SND_SOC_DAPM_EVENT_OFF(event)) {
ret = snd_soc_dai_set_pll(codec_dai, 0,
DA7219_SYSCLK_MCLK, 0, 0);
if (ret)
dev_err(card->dev, "failed to stop PLL: %d\n", ret);
} else if(SND_SOC_DAPM_EVENT_ON(event)) {
ret = snd_soc_dai_set_pll(codec_dai, 0,
DA7219_SYSCLK_PLL_SRM, 0, DA7219_PLL_FREQ_OUT_98304);
if (ret)
dev_err(card->dev, "failed to start PLL: %d\n", ret);
}
return ret;
}
static int broxton_ssp_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *fmt = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
rate->min = rate->max = 48000;
channels->min = channels->max = DUAL_CHANNEL;
snd_mask_none(fmt);
snd_mask_set(fmt, SNDRV_PCM_FORMAT_S24_LE);
return 0;
}
static int broxton_da7219_codec_init(struct snd_soc_pcm_runtime *rtd)
{
int ret;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
ret = snd_soc_dai_set_sysclk(codec_dai, DA7219_CLKSRC_MCLK, 19200000,
SND_SOC_CLOCK_IN);
if (ret) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
ret = snd_soc_card_jack_new(rtd->card, "Headset Jack",
SND_JACK_HEADSET | SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3 | SND_JACK_LINEOUT,
&broxton_headset, NULL, 0);
if (ret) {
dev_err(rtd->dev, "Headset Jack creation failed: %d\n", ret);
return ret;
}
da7219_aad_jack_det(codec, &broxton_headset);
snd_soc_dapm_ignore_suspend(&rtd->card->dapm, "SoC DMIC");
return ret;
}
static int broxton_hdmi_init(struct snd_soc_pcm_runtime *rtd)
{
struct bxt_card_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai = rtd->codec_dai;
struct bxt_hdmi_pcm *pcm;
pcm = devm_kzalloc(rtd->card->dev, sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->device = BXT_DPCM_AUDIO_HDMI1_PB + dai->id;
pcm->codec_dai = dai;
list_add_tail(&pcm->head, &ctx->hdmi_pcm_list);
return 0;
}
static int broxton_da7219_fe_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dapm_context *dapm;
struct snd_soc_component *component = rtd->cpu_dai->component;
dapm = snd_soc_component_get_dapm(component);
snd_soc_dapm_ignore_suspend(dapm, "Reference Capture");
return 0;
}
static int bxt_fe_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = DUAL_CHANNEL;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_channels);
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
snd_pcm_hw_constraint_msbits(runtime, 0, 16, 16);
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
return 0;
}
static int broxton_dmic_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
if (params_channels(params) == 2)
channels->min = channels->max = 2;
else
channels->min = channels->max = 4;
return 0;
}
static int broxton_dmic_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_min = runtime->hw.channels_max = QUAD_CHANNEL;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_channels_quad);
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
}
static int broxton_refcap_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_16000);
}
static int bxt_card_late_probe(struct snd_soc_card *card)
{
struct bxt_card_private *ctx = snd_soc_card_get_drvdata(card);
struct bxt_hdmi_pcm *pcm;
struct snd_soc_codec *codec = NULL;
int err, i = 0;
char jack_name[NAME_SIZE];
list_for_each_entry(pcm, &ctx->hdmi_pcm_list, head) {
codec = pcm->codec_dai->codec;
snprintf(jack_name, sizeof(jack_name),
"HDMI/DP, pcm=%d Jack", pcm->device);
err = snd_soc_card_jack_new(card, jack_name,
SND_JACK_AVOUT, &broxton_hdmi[i],
NULL, 0);
if (err)
return err;
err = hdac_hdmi_jack_init(pcm->codec_dai, pcm->device,
&broxton_hdmi[i]);
if (err < 0)
return err;
i++;
}
if (!codec)
return -EINVAL;
return hdac_hdmi_jack_port_init(codec, &card->dapm);
}
static int broxton_audio_probe(struct platform_device *pdev)
{
struct bxt_card_private *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_ATOMIC);
if (!ctx)
return -ENOMEM;
INIT_LIST_HEAD(&ctx->hdmi_pcm_list);
broxton_audio_card.dev = &pdev->dev;
snd_soc_card_set_drvdata(&broxton_audio_card, ctx);
return devm_snd_soc_register_card(&pdev->dev, &broxton_audio_card);
}
