static int kabylake_rt5663_fe_init(struct snd_soc_pcm_runtime *rtd)
{
int ret;
struct snd_soc_dapm_context *dapm;
struct snd_soc_component *component = rtd->cpu_dai->component;
dapm = snd_soc_component_get_dapm(component);
ret = snd_soc_dapm_ignore_suspend(dapm, "Reference Capture");
if (ret) {
dev_err(rtd->dev, "Ref Cap ignore suspend failed %d\n", ret);
return ret;
}
return ret;
}
static int kabylake_rt5663_codec_init(struct snd_soc_pcm_runtime *rtd)
{
int ret;
struct kbl_rt5663_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_codec *codec = rtd->codec;
ret = snd_soc_card_jack_new(&kabylake_audio_card, "Headset Jack",
SND_JACK_HEADSET | SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3, &ctx->kabylake_headset,
NULL, 0);
if (ret) {
dev_err(rtd->dev, "Headset Jack creation failed %d\n", ret);
return ret;
}
rt5663_set_jack_detect(codec, &ctx->kabylake_headset);
ret = snd_soc_dapm_ignore_suspend(&rtd->card->dapm, "SoC DMIC");
if (ret) {
dev_err(rtd->dev, "SoC DMIC ignore suspend failed %d\n", ret);
return ret;
}
return ret;
}
static int kabylake_hdmi1_init(struct snd_soc_pcm_runtime *rtd)
{
struct kbl_rt5663_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai = rtd->codec_dai;
struct kbl_hdmi_pcm *pcm;
pcm = devm_kzalloc(rtd->card->dev, sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->device = KBL_DPCM_AUDIO_HDMI1_PB;
pcm->codec_dai = dai;
list_add_tail(&pcm->head, &ctx->hdmi_pcm_list);
return 0;
}
static int kabylake_hdmi2_init(struct snd_soc_pcm_runtime *rtd)
{
struct kbl_rt5663_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai = rtd->codec_dai;
struct kbl_hdmi_pcm *pcm;
pcm = devm_kzalloc(rtd->card->dev, sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->device = KBL_DPCM_AUDIO_HDMI2_PB;
pcm->codec_dai = dai;
list_add_tail(&pcm->head, &ctx->hdmi_pcm_list);
return 0;
}
static int kabylake_hdmi3_init(struct snd_soc_pcm_runtime *rtd)
{
struct kbl_rt5663_private *ctx = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_dai *dai = rtd->codec_dai;
struct kbl_hdmi_pcm *pcm;
pcm = devm_kzalloc(rtd->card->dev, sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->device = KBL_DPCM_AUDIO_HDMI3_PB;
pcm->codec_dai = dai;
list_add_tail(&pcm->head, &ctx->hdmi_pcm_list);
return 0;
}
static int kbl_fe_startup(struct snd_pcm_substream *substream)
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
static int kabylake_ssp_fixup(struct snd_soc_pcm_runtime *rtd,
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
static int kabylake_rt5663_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai,
RT5663_SCLK_S_MCLK, 24576000, SND_SOC_CLOCK_IN);
rt5663_sel_asrc_clk_src(codec_dai->codec, RT5663_DA_STEREO_FILTER, 1);
if (ret < 0)
dev_err(rtd->dev, "snd_soc_dai_set_sysclk err = %d\n", ret);
return ret;
}
static int kabylake_dmic_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
if (params_channels(params) == 2 || DMIC_CH(dmic_constraints) == 2)
channels->min = channels->max = 2;
else
channels->min = channels->max = 4;
return 0;
}
static int kabylake_dmic_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = DMIC_CH(dmic_constraints);
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
dmic_constraints);
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &constraints_rates);
}
static int kabylake_refcap_startup(struct snd_pcm_substream *substream)
{
substream->runtime->hw.channels_max = 1;
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
&constraints_refcap);
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_16000);
}
static int kabylake_card_late_probe(struct snd_soc_card *card)
{
struct kbl_rt5663_private *ctx = snd_soc_card_get_drvdata(card);
struct kbl_hdmi_pcm *pcm;
int err, i = 0;
char jack_name[NAME_SIZE];
list_for_each_entry(pcm, &ctx->hdmi_pcm_list, head) {
snprintf(jack_name, sizeof(jack_name),
"HDMI/DP, pcm=%d Jack", pcm->device);
err = snd_soc_card_jack_new(card, jack_name,
SND_JACK_AVOUT, &skylake_hdmi[i],
NULL, 0);
if (err)
return err;
err = hdac_hdmi_jack_init(pcm->codec_dai, pcm->device,
&skylake_hdmi[i]);
if (err < 0)
return err;
i++;
}
return 0;
}
static int kabylake_audio_probe(struct platform_device *pdev)
{
struct kbl_rt5663_private *ctx;
struct skl_machine_pdata *pdata;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_ATOMIC);
if (!ctx)
return -ENOMEM;
INIT_LIST_HEAD(&ctx->hdmi_pcm_list);
kabylake_audio_card.dev = &pdev->dev;
snd_soc_card_set_drvdata(&kabylake_audio_card, ctx);
pdata = dev_get_drvdata(&pdev->dev);
if (pdata)
dmic_constraints = pdata->dmic_num == 2 ?
&constraints_dmic_2ch : &constraints_dmic_channels;
return devm_snd_soc_register_card(&pdev->dev, &kabylake_audio_card);
}
