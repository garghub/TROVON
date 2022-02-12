static int broadwell_rt286_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret = 0;
ret = snd_soc_card_jack_new(rtd->card, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0, &broadwell_headset,
broadwell_headset_pins, ARRAY_SIZE(broadwell_headset_pins));
if (ret)
return ret;
rt286_mic_detect(codec, &broadwell_headset);
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
params_set_format(params, SNDRV_PCM_FORMAT_S16_LE);
return 0;
}
static int broadwell_rt286_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT286_SCLK_S_PLL, 24000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
return ret;
}
static int broadwell_rtd_init(struct snd_soc_pcm_runtime *rtd)
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
static int broadwell_suspend(struct snd_soc_card *card){
struct snd_soc_component *component;
list_for_each_entry(component, &card->component_dev_list, card_list) {
if (!strcmp(component->name, "i2c-INT343A:00")) {
struct snd_soc_codec *codec = snd_soc_component_to_codec(component);
dev_dbg(codec->dev, "disabling jack detect before going to suspend.\n");
rt286_mic_detect(codec, NULL);
break;
}
}
return 0;
}
static int broadwell_resume(struct snd_soc_card *card){
struct snd_soc_component *component;
list_for_each_entry(component, &card->component_dev_list, card_list) {
if (!strcmp(component->name, "i2c-INT343A:00")) {
struct snd_soc_codec *codec = snd_soc_component_to_codec(component);
dev_dbg(codec->dev, "enabling jack detect for resume.\n");
rt286_mic_detect(codec, &broadwell_headset);
break;
}
}
return 0;
}
static int broadwell_audio_probe(struct platform_device *pdev)
{
broadwell_rt286.dev = &pdev->dev;
snd_soc_set_dmi_name(&broadwell_rt286, NULL);
return devm_snd_soc_register_card(&pdev->dev, &broadwell_rt286);
}
