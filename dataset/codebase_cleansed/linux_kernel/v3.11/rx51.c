static void rx51_ext_control(struct snd_soc_dapm_context *dapm)
{
int hp = 0, hs = 0, tvout = 0;
switch (rx51_jack_func) {
case RX51_JACK_TVOUT:
tvout = 1;
hp = 1;
break;
case RX51_JACK_HS:
hs = 1;
case RX51_JACK_HP:
hp = 1;
break;
}
if (rx51_spk_func)
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
else
snd_soc_dapm_disable_pin(dapm, "Ext Spk");
if (rx51_dmic_func)
snd_soc_dapm_enable_pin(dapm, "DMic");
else
snd_soc_dapm_disable_pin(dapm, "DMic");
if (hp)
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
else
snd_soc_dapm_disable_pin(dapm, "Headphone Jack");
if (hs)
snd_soc_dapm_enable_pin(dapm, "HS Mic");
else
snd_soc_dapm_disable_pin(dapm, "HS Mic");
gpio_set_value(RX51_TVOUT_SEL_GPIO, tvout);
snd_soc_dapm_sync(dapm);
}
static int rx51_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_card *card = rtd->card;
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_CHANNELS, 2, 2);
rx51_ext_control(&card->dapm);
return 0;
}
static int rx51_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
return snd_soc_dai_set_sysclk(codec_dai, 0, 19200000,
SND_SOC_CLOCK_IN);
}
static int rx51_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = rx51_spk_func;
return 0;
}
static int rx51_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (rx51_spk_func == ucontrol->value.integer.value[0])
return 0;
rx51_spk_func = ucontrol->value.integer.value[0];
rx51_ext_control(&card->dapm);
return 1;
}
static int rx51_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value_cansleep(RX51_SPEAKER_AMP_TWL_GPIO, 1);
else
gpio_set_value_cansleep(RX51_SPEAKER_AMP_TWL_GPIO, 0);
return 0;
}
static int rx51_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = w->dapm->codec;
if (SND_SOC_DAPM_EVENT_ON(event))
tpa6130a2_stereo_enable(codec, 1);
else
tpa6130a2_stereo_enable(codec, 0);
return 0;
}
static int rx51_get_input(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = rx51_dmic_func;
return 0;
}
static int rx51_set_input(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (rx51_dmic_func == ucontrol->value.integer.value[0])
return 0;
rx51_dmic_func = ucontrol->value.integer.value[0];
rx51_ext_control(&card->dapm);
return 1;
}
static int rx51_get_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = rx51_jack_func;
return 0;
}
static int rx51_set_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (rx51_jack_func == ucontrol->value.integer.value[0])
return 0;
rx51_jack_func = ucontrol->value.integer.value[0];
rx51_ext_control(&card->dapm);
return 1;
}
static int rx51_aic34_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int err;
snd_soc_dapm_nc_pin(dapm, "MIC3L");
snd_soc_dapm_nc_pin(dapm, "MIC3R");
snd_soc_dapm_nc_pin(dapm, "LINE1R");
err = snd_soc_add_card_controls(rtd->card, aic34_rx51_controls,
ARRAY_SIZE(aic34_rx51_controls));
if (err < 0)
return err;
snd_soc_dapm_new_controls(dapm, aic34_dapm_widgets,
ARRAY_SIZE(aic34_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
err = tpa6130a2_add_controls(codec);
if (err < 0)
return err;
snd_soc_limit_volume(codec, "TPA6130A2 Headphone Playback Volume", 42);
err = omap_mcbsp_st_add_controls(rtd);
if (err < 0)
return err;
err = snd_soc_jack_new(codec, "AV Jack",
SND_JACK_HEADSET | SND_JACK_VIDEOOUT,
&rx51_av_jack);
if (err)
return err;
err = snd_soc_jack_add_gpios(&rx51_av_jack,
ARRAY_SIZE(rx51_av_jack_gpios),
rx51_av_jack_gpios);
return err;
}
static int rx51_aic34b_init(struct snd_soc_dapm_context *dapm)
{
int err;
err = snd_soc_add_card_controls(dapm->card, aic34_rx51_controlsb,
ARRAY_SIZE(aic34_rx51_controlsb));
if (err < 0)
return err;
err = snd_soc_dapm_new_controls(dapm, aic34_dapm_widgetsb,
ARRAY_SIZE(aic34_dapm_widgetsb));
if (err < 0)
return 0;
return snd_soc_dapm_add_routes(dapm, audio_mapb,
ARRAY_SIZE(audio_mapb));
}
static int __init rx51_soc_init(void)
{
int err;
if (!machine_is_nokia_rx51() && !of_machine_is_compatible("nokia,omap3-n900"))
return -ENODEV;
err = gpio_request_one(RX51_TVOUT_SEL_GPIO,
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "tvout_sel");
if (err)
goto err_gpio_tvout_sel;
err = gpio_request_one(RX51_ECI_SW_GPIO,
GPIOF_DIR_OUT | GPIOF_INIT_HIGH, "eci_sw");
if (err)
goto err_gpio_eci_sw;
rx51_snd_device = platform_device_alloc("soc-audio", -1);
if (!rx51_snd_device) {
err = -ENOMEM;
goto err1;
}
platform_set_drvdata(rx51_snd_device, &rx51_sound_card);
err = platform_device_add(rx51_snd_device);
if (err)
goto err2;
return 0;
err2:
platform_device_put(rx51_snd_device);
err1:
gpio_free(RX51_ECI_SW_GPIO);
err_gpio_eci_sw:
gpio_free(RX51_TVOUT_SEL_GPIO);
err_gpio_tvout_sel:
return err;
}
static void __exit rx51_soc_exit(void)
{
snd_soc_jack_free_gpios(&rx51_av_jack, ARRAY_SIZE(rx51_av_jack_gpios),
rx51_av_jack_gpios);
platform_device_unregister(rx51_snd_device);
gpio_free(RX51_ECI_SW_GPIO);
gpio_free(RX51_TVOUT_SEL_GPIO);
}
