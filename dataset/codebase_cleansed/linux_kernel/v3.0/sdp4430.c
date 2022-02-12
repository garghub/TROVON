static int sdp4430_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int clk_id, freq;
int ret;
if (twl6040_power_mode) {
clk_id = TWL6040_SYSCLK_SEL_HPPLL;
freq = 38400000;
} else {
clk_id = TWL6040_SYSCLK_SEL_LPPLL;
freq = 32768;
}
ret = snd_soc_dai_set_sysclk(codec_dai, clk_id, freq,
SND_SOC_CLOCK_IN);
if (ret) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return ret;
}
static int sdp4430_get_power_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = twl6040_power_mode;
return 0;
}
static int sdp4430_set_power_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
if (twl6040_power_mode == ucontrol->value.integer.value[0])
return 0;
twl6040_power_mode = ucontrol->value.integer.value[0];
return 1;
}
static int sdp4430_twl6040_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_add_controls(codec, sdp4430_controls,
ARRAY_SIZE(sdp4430_controls));
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(dapm, sdp4430_twl6040_dapm_widgets,
ARRAY_SIZE(sdp4430_twl6040_dapm_widgets));
if (ret)
return ret;
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_enable_pin(dapm, "Ext Mic");
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
snd_soc_dapm_enable_pin(dapm, "AFML");
snd_soc_dapm_enable_pin(dapm, "AFMR");
snd_soc_dapm_enable_pin(dapm, "Headset Mic");
snd_soc_dapm_enable_pin(dapm, "Headset Stereophone");
ret = snd_soc_dapm_sync(dapm);
if (ret)
return ret;
ret = snd_soc_jack_new(codec, "Headset Jack",
SND_JACK_HEADSET, &hs_jack);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&hs_jack, ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
if (machine_is_omap_4430sdp())
twl6040_hs_jack_detect(codec, &hs_jack, SND_JACK_HEADSET);
else
snd_soc_jack_report(&hs_jack, SND_JACK_HEADSET, SND_JACK_HEADSET);
return ret;
}
static int __init sdp4430_soc_init(void)
{
int ret;
if (!machine_is_omap_4430sdp())
return -ENODEV;
printk(KERN_INFO "SDP4430 SoC init\n");
sdp4430_snd_device = platform_device_alloc("soc-audio", -1);
if (!sdp4430_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(sdp4430_snd_device, &snd_soc_sdp4430);
ret = platform_device_add(sdp4430_snd_device);
if (ret)
goto err;
twl6040_power_mode = 1;
return 0;
err:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(sdp4430_snd_device);
return ret;
}
static void __exit sdp4430_soc_exit(void)
{
platform_device_unregister(sdp4430_snd_device);
}
