static int sdp4430_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int clk_id, freq;
int ret;
clk_id = twl6040_get_clk_id(rtd->codec);
if (clk_id == TWL6040_SYSCLK_SEL_HPPLL)
freq = 38400000;
else if (clk_id == TWL6040_SYSCLK_SEL_LPPLL)
freq = 32768;
else
return -EINVAL;
ret = snd_soc_dai_set_sysclk(codec_dai, clk_id, freq,
SND_SOC_CLOCK_IN);
if (ret) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return ret;
}
static int sdp4430_twl6040_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret, hs_trim;
hs_trim = twl6040_get_trim_value(codec, TWL6040_TRIM_HSOTRIM);
omap_mcpdm_configure_dn_offsets(rtd, TWL6040_HSF_TRIM_LEFT(hs_trim),
TWL6040_HSF_TRIM_RIGHT(hs_trim));
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
