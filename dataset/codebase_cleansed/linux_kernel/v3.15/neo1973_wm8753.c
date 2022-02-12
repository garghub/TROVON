static int neo1973_hifi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int pll_out = 0, bclk = 0;
int ret = 0;
unsigned long iis_clkrate;
iis_clkrate = s3c24xx_i2s_get_clockrate();
switch (params_rate(params)) {
case 8000:
case 16000:
pll_out = 12288000;
break;
case 48000:
bclk = WM8753_BCLK_DIV_4;
pll_out = 12288000;
break;
case 96000:
bclk = WM8753_BCLK_DIV_2;
pll_out = 12288000;
break;
case 11025:
bclk = WM8753_BCLK_DIV_16;
pll_out = 11289600;
break;
case 22050:
bclk = WM8753_BCLK_DIV_8;
pll_out = 11289600;
break;
case 44100:
bclk = WM8753_BCLK_DIV_4;
pll_out = 11289600;
break;
case 88200:
bclk = WM8753_BCLK_DIV_2;
pll_out = 11289600;
break;
}
ret = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8753_MCLK, pll_out,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_MCLK,
S3C2410_IISMOD_32FS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8753_BCLKDIV, bclk);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_PRESCALER,
S3C24XX_PRESCALE(4, 4));
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8753_PLL1, 0,
iis_clkrate / 4, pll_out);
if (ret < 0)
return ret;
return 0;
}
static int neo1973_hifi_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
return snd_soc_dai_set_pll(codec_dai, WM8753_PLL1, 0, 0, 0);
}
static int neo1973_voice_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pcmdiv = 0;
int ret = 0;
unsigned long iis_clkrate;
iis_clkrate = s3c24xx_i2s_get_clockrate();
if (params_rate(params) != 8000)
return -EINVAL;
if (params_channels(params) != 1)
return -EINVAL;
pcmdiv = WM8753_PCM_DIV_6;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_DSP_B |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8753_PCMCLK, 12288000,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8753_PCMDIV, pcmdiv);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8753_PLL2, 0,
iis_clkrate / 4, 12288000);
if (ret < 0)
return ret;
return 0;
}
static int neo1973_voice_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
return snd_soc_dai_set_pll(codec_dai, WM8753_PLL2, 0, 0, 0);
}
static int lm4853_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
gta02_speaker_enabled = ucontrol->value.integer.value[0];
gpio_set_value(S3C2410_GPJ(2), !gta02_speaker_enabled);
return 0;
}
static int lm4853_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = gta02_speaker_enabled;
return 0;
}
static int lm4853_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
gpio_set_value(S3C2410_GPJ(1), SND_SOC_DAPM_EVENT_OFF(event));
return 0;
}
static int neo1973_wm8753_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = rtd->card;
snd_soc_dapm_nc_pin(&codec->dapm, "OUT3");
snd_soc_dapm_nc_pin(&codec->dapm, "OUT4");
snd_soc_dapm_nc_pin(&codec->dapm, "LINE1");
snd_soc_dapm_nc_pin(&codec->dapm, "LINE2");
snd_soc_dapm_disable_pin(&card->dapm, "GSM Line Out");
snd_soc_dapm_disable_pin(&card->dapm, "GSM Line In");
snd_soc_dapm_disable_pin(&card->dapm, "Headset Mic");
snd_soc_dapm_disable_pin(&card->dapm, "Handset Mic");
snd_soc_dapm_disable_pin(&card->dapm, "Stereo Out");
snd_soc_dapm_disable_pin(&card->dapm, "Handset Spk");
snd_soc_dapm_ignore_suspend(&card->dapm, "GSM Line Out");
snd_soc_dapm_ignore_suspend(&card->dapm, "GSM Line In");
snd_soc_dapm_ignore_suspend(&card->dapm, "Headset Mic");
snd_soc_dapm_ignore_suspend(&card->dapm, "Handset Mic");
snd_soc_dapm_ignore_suspend(&card->dapm, "Stereo Out");
snd_soc_dapm_ignore_suspend(&card->dapm, "Handset Spk");
return 0;
}
static int __init neo1973_init(void)
{
int ret;
if (!machine_is_neo1973_gta02())
return -ENODEV;
if (machine_is_neo1973_gta02()) {
neo1973.name = "neo1973gta02";
neo1973.num_aux_devs = 1;
ret = gpio_request_array(neo1973_gta02_gpios,
ARRAY_SIZE(neo1973_gta02_gpios));
if (ret)
return ret;
}
neo1973_snd_device = platform_device_alloc("soc-audio", -1);
if (!neo1973_snd_device) {
ret = -ENOMEM;
goto err_gpio_free;
}
platform_set_drvdata(neo1973_snd_device, &neo1973);
ret = platform_device_add(neo1973_snd_device);
if (ret)
goto err_put_device;
return 0;
err_put_device:
platform_device_put(neo1973_snd_device);
err_gpio_free:
if (machine_is_neo1973_gta02()) {
gpio_free_array(neo1973_gta02_gpios,
ARRAY_SIZE(neo1973_gta02_gpios));
}
return ret;
}
static void __exit neo1973_exit(void)
{
platform_device_unregister(neo1973_snd_device);
if (machine_is_neo1973_gta02()) {
gpio_free_array(neo1973_gta02_gpios,
ARRAY_SIZE(neo1973_gta02_gpios));
}
}
