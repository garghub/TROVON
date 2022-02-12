static int broxton_rt298_fe_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dapm_context *dapm;
struct snd_soc_component *component = rtd->cpu_dai->component;
dapm = snd_soc_component_get_dapm(component);
snd_soc_dapm_ignore_suspend(dapm, "Reference Capture");
return 0;
}
static int broxton_rt298_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret = 0;
ret = snd_soc_card_jack_new(rtd->card, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&broxton_headset,
broxton_headset_pins, ARRAY_SIZE(broxton_headset_pins));
if (ret)
return ret;
rt298_mic_detect(codec, &broxton_headset);
snd_soc_dapm_ignore_suspend(&rtd->card->dapm, "SoC DMIC");
return 0;
}
static int broxton_hdmi_init(struct snd_soc_pcm_runtime *rtd)
{
struct bxt_rt286_private *ctx = snd_soc_card_get_drvdata(rtd->card);
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
static int broxton_ssp5_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *fmt = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
snd_mask_none(fmt);
snd_mask_set(fmt, SNDRV_PCM_FORMAT_S24_LE);
return 0;
}
static int broxton_rt298_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT298_SCLK_S_PLL,
19200000, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
return ret;
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
runtime->hw.channels_max = 4;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_dmic_channels);
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
}
static int bxt_fe_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = 2;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_channels);
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
return 0;
}
static int bxt_card_late_probe(struct snd_soc_card *card)
{
struct bxt_rt286_private *ctx = snd_soc_card_get_drvdata(card);
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
struct bxt_rt286_private *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_ATOMIC);
if (!ctx)
return -ENOMEM;
INIT_LIST_HEAD(&ctx->hdmi_pcm_list);
broxton_rt298.dev = &pdev->dev;
snd_soc_card_set_drvdata(&broxton_rt298, ctx);
return devm_snd_soc_register_card(&pdev->dev, &broxton_rt298);
}
