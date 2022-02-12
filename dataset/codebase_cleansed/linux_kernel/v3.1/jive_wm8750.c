static int jive_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct s3c_i2sv2_rate_calc div;
unsigned int clk = 0;
int ret = 0;
switch (params_rate(params)) {
case 8000:
case 16000:
case 48000:
case 96000:
clk = 12288000;
break;
case 11025:
case 22050:
case 44100:
clk = 11289600;
break;
}
s3c_i2sv2_iis_calc_rate(&div, NULL, params_rate(params),
s3c_i2sv2_get_clock(cpu_dai));
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8750_SYSCLK, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C2412_DIV_RCLK, div.fs_div);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C2412_DIV_PRESCALER,
div.clk_div - 1);
if (ret < 0)
return ret;
return 0;
}
static int jive_wm8750_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int err;
snd_soc_dapm_nc_pin(dapm, "LINPUT2");
snd_soc_dapm_nc_pin(dapm, "RINPUT2");
snd_soc_dapm_nc_pin(dapm, "LINPUT3");
snd_soc_dapm_nc_pin(dapm, "RINPUT3");
snd_soc_dapm_nc_pin(dapm, "OUT3");
snd_soc_dapm_nc_pin(dapm, "MONO");
err = snd_soc_dapm_new_controls(dapm, wm8750_dapm_widgets,
ARRAY_SIZE(wm8750_dapm_widgets));
if (err) {
printk(KERN_ERR "%s: failed to add widgets (%d)\n",
__func__, err);
return err;
}
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init jive_init(void)
{
int ret;
if (!machine_is_jive())
return 0;
printk("JIVE WM8750 Audio support\n");
jive_snd_device = platform_device_alloc("soc-audio", -1);
if (!jive_snd_device)
return -ENOMEM;
platform_set_drvdata(jive_snd_device, &snd_soc_machine_jive);
ret = platform_device_add(jive_snd_device);
if (ret)
platform_device_put(jive_snd_device);
return ret;
}
static void __exit jive_exit(void)
{
platform_device_unregister(jive_snd_device);
}
