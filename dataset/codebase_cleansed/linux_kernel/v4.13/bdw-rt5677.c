static int bdw_rt5677_event_hp(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);
if (SND_SOC_DAPM_EVENT_ON(event))
msleep(70);
gpiod_set_value_cansleep(bdw_rt5677->gpio_hp_en,
SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int broadwell_ssp0_fixup(struct snd_soc_pcm_runtime *rtd,
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
SNDRV_PCM_FORMAT_S16_LE);
return 0;
}
static int bdw_rt5677_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5677_SCLK_S_MCLK, 24576000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
return ret;
}
static int bdw_rt5677_rtd_init(struct snd_soc_pcm_runtime *rtd)
{
struct sst_pdata *pdata = dev_get_platdata(rtd->platform->dev);
struct sst_hsw *broadwell = pdata->dsp;
int ret;
ret = sst_hsw_device_set_config(broadwell, SST_HSW_DEVICE_SSP_0,
SST_HSW_DEVICE_MCLK_FREQ_24_MHZ,
SST_HSW_DEVICE_CLOCK_MASTER, 9);
if (ret < 0) {
dev_err(rtd->dev, "error: failed to set device config\n");
return ret;
}
return 0;
}
static int bdw_rt5677_init(struct snd_soc_pcm_runtime *rtd)
{
struct bdw_rt5677_priv *bdw_rt5677 =
snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
int ret;
ret = devm_acpi_dev_add_driver_gpios(codec->dev, bdw_rt5677_gpios);
if (ret)
dev_warn(codec->dev, "Failed to add driver gpios\n");
rt5677_sel_asrc_clk_src(codec, RT5677_DA_STEREO_FILTER |
RT5677_AD_STEREO1_FILTER | RT5677_I2S1_SOURCE,
RT5677_CLK_SEL_I2S1_ASRC);
bdw_rt5677->gpio_hp_en = devm_gpiod_get(codec->dev, "headphone-enable",
GPIOD_OUT_LOW);
if (IS_ERR(bdw_rt5677->gpio_hp_en)) {
dev_err(codec->dev, "Can't find HP_AMP_SHDN_L gpio\n");
return PTR_ERR(bdw_rt5677->gpio_hp_en);
}
if (!snd_soc_card_jack_new(rtd->card, "Headphone Jack",
SND_JACK_HEADPHONE, &headphone_jack,
&headphone_jack_pin, 1)) {
headphone_jack_gpio.gpiod_dev = codec->dev;
if (snd_soc_jack_add_gpios(&headphone_jack, 1,
&headphone_jack_gpio))
dev_err(codec->dev, "Can't add headphone jack gpio\n");
} else {
dev_err(codec->dev, "Can't create headphone jack\n");
}
if (!snd_soc_card_jack_new(rtd->card, "Mic Jack",
SND_JACK_MICROPHONE, &mic_jack,
&mic_jack_pin, 1)) {
mic_jack_gpio.gpiod_dev = codec->dev;
if (snd_soc_jack_add_gpios(&mic_jack, 1, &mic_jack_gpio))
dev_err(codec->dev, "Can't add mic jack gpio\n");
} else {
dev_err(codec->dev, "Can't create mic jack\n");
}
bdw_rt5677->codec = codec;
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
return 0;
}
static int bdw_rt5677_suspend_pre(struct snd_soc_card *card)
{
struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);
struct snd_soc_dapm_context *dapm;
if (bdw_rt5677->codec) {
dapm = snd_soc_codec_get_dapm(bdw_rt5677->codec);
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
}
return 0;
}
static int bdw_rt5677_resume_post(struct snd_soc_card *card)
{
struct bdw_rt5677_priv *bdw_rt5677 = snd_soc_card_get_drvdata(card);
struct snd_soc_dapm_context *dapm;
if (bdw_rt5677->codec) {
dapm = snd_soc_codec_get_dapm(bdw_rt5677->codec);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
}
return 0;
}
static int bdw_rt5677_probe(struct platform_device *pdev)
{
struct bdw_rt5677_priv *bdw_rt5677;
bdw_rt5677_card.dev = &pdev->dev;
bdw_rt5677 = devm_kzalloc(&pdev->dev, sizeof(struct bdw_rt5677_priv),
GFP_KERNEL);
if (!bdw_rt5677) {
dev_err(&pdev->dev, "Can't allocate bdw_rt5677\n");
return -ENOMEM;
}
snd_soc_card_set_drvdata(&bdw_rt5677_card, bdw_rt5677);
return devm_snd_soc_register_card(&pdev->dev, &bdw_rt5677_card);
}
