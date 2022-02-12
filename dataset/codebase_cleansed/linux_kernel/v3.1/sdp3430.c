static int sdp3430_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set cpu DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 26000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return 0;
}
static int sdp3430_hw_voice_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_DSP_A |
SND_SOC_DAIFMT_IB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
printk(KERN_ERR "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_DSP_A |
SND_SOC_DAIFMT_IB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0) {
printk(KERN_ERR "can't set cpu DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 26000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return ret;
}
return 0;
}
static int sdp3430_twl4030_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_dapm_new_controls(dapm, sdp3430_twl4030_dapm_widgets,
ARRAY_SIZE(sdp3430_twl4030_dapm_widgets));
if (ret)
return ret;
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_enable_pin(dapm, "Ext Mic");
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
snd_soc_dapm_disable_pin(dapm, "Headset Mic");
snd_soc_dapm_disable_pin(dapm, "Headset Stereophone");
snd_soc_dapm_nc_pin(dapm, "AUXL");
snd_soc_dapm_nc_pin(dapm, "AUXR");
snd_soc_dapm_nc_pin(dapm, "CARKITMIC");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC0");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC1");
snd_soc_dapm_nc_pin(dapm, "OUTL");
snd_soc_dapm_nc_pin(dapm, "OUTR");
snd_soc_dapm_nc_pin(dapm, "EARPIECE");
snd_soc_dapm_nc_pin(dapm, "PREDRIVEL");
snd_soc_dapm_nc_pin(dapm, "PREDRIVER");
snd_soc_dapm_nc_pin(dapm, "CARKITL");
snd_soc_dapm_nc_pin(dapm, "CARKITR");
ret = snd_soc_dapm_sync(dapm);
if (ret)
return ret;
ret = snd_soc_jack_new(codec, "Headset Jack",
SND_JACK_HEADSET, &hs_jack);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&hs_jack, ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
if (ret)
return ret;
ret = snd_soc_jack_add_gpios(&hs_jack, ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
return ret;
}
static int sdp3430_twl4030_voice_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
unsigned short reg;
reg = codec->driver->read(codec, TWL4030_REG_VOICE_IF);
reg |= TWL4030_VIF_DIN_EN | TWL4030_VIF_DOUT_EN | TWL4030_VIF_EN;
codec->driver->write(codec, TWL4030_REG_VOICE_IF, reg);
return 0;
}
static int __init sdp3430_soc_init(void)
{
int ret;
u8 pin_mux;
if (!machine_is_omap_3430sdp())
return -ENODEV;
printk(KERN_INFO "SDP3430 SoC init\n");
sdp3430_snd_device = platform_device_alloc("soc-audio", -1);
if (!sdp3430_snd_device) {
printk(KERN_ERR "Platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(sdp3430_snd_device, &snd_soc_sdp3430);
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &pin_mux,
TWL4030_INTBR_PMBR1);
pin_mux &= ~TWL4030_GPIO6_PWM0_MUTE(0x03);
pin_mux |= TWL4030_GPIO6_PWM0_MUTE(0x02);
twl_i2c_write_u8(TWL4030_MODULE_INTBR, pin_mux,
TWL4030_INTBR_PMBR1);
ret = platform_device_add(sdp3430_snd_device);
if (ret)
goto err1;
return 0;
err1:
printk(KERN_ERR "Unable to add platform device\n");
platform_device_put(sdp3430_snd_device);
return ret;
}
static void __exit sdp3430_soc_exit(void)
{
snd_soc_jack_free_gpios(&hs_jack, ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
platform_device_unregister(sdp3430_snd_device);
}
