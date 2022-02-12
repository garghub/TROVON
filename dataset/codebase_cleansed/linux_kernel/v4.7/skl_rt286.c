static int skylake_rt286_fe_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dapm_context *dapm;
struct snd_soc_component *component = rtd->cpu_dai->component;
dapm = snd_soc_component_get_dapm(component);
snd_soc_dapm_ignore_suspend(dapm, "Reference Capture");
return 0;
}
static int skylake_rt286_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret;
ret = snd_soc_card_jack_new(rtd->card, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&skylake_headset,
skylake_headset_pins, ARRAY_SIZE(skylake_headset_pins));
if (ret)
return ret;
rt286_mic_detect(codec, &skylake_headset);
snd_soc_dapm_ignore_suspend(&rtd->card->dapm, "SoC DMIC");
return 0;
}
static int skylake_hdmi_init(struct snd_soc_pcm_runtime *rtd)
{
struct skl_rt286_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai = rtd->codec_dai;
struct skl_hdmi_pcm *pcm;
pcm = devm_kzalloc(rtd->card->dev, sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->device = SKL_DPCM_AUDIO_HDMI1_PB + dai->id;
pcm->codec_dai = dai;
list_add_tail(&pcm->head, &ctx->hdmi_pcm_list);
return 0;
}
static int skl_fe_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = 2;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_channels);
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
snd_pcm_hw_constraint_msbits(runtime, 0, 16, 16);
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
return 0;
}
static int skylake_ssp0_fixup(struct snd_soc_pcm_runtime *rtd,
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
static int skylake_rt286_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT286_SCLK_S_PLL, 24000000,
SND_SOC_CLOCK_IN);
if (ret < 0)
dev_err(rtd->dev, "set codec sysclk failed: %d\n", ret);
return ret;
}
static int skylake_dmic_fixup(struct snd_soc_pcm_runtime *rtd,
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
static int skylake_dmic_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = 4;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_dmic_channels);
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
}
static int skylake_card_late_probe(struct snd_soc_card *card)
{
struct skl_rt286_private *ctx = snd_soc_card_get_drvdata(card);
struct skl_hdmi_pcm *pcm;
int err;
list_for_each_entry(pcm, &ctx->hdmi_pcm_list, head) {
err = hdac_hdmi_jack_init(pcm->codec_dai, pcm->device);
if (err < 0)
return err;
}
return 0;
}
static int skylake_audio_probe(struct platform_device *pdev)
{
struct skl_rt286_private *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_ATOMIC);
if (!ctx)
return -ENOMEM;
INIT_LIST_HEAD(&ctx->hdmi_pcm_list);
skylake_rt286.dev = &pdev->dev;
snd_soc_card_set_drvdata(&skylake_rt286, ctx);
return devm_snd_soc_register_card(&pdev->dev, &skylake_rt286);
}
