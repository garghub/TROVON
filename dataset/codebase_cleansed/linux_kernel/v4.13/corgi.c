static void corgi_ext_control(struct snd_soc_dapm_context *dapm)
{
snd_soc_dapm_mutex_lock(dapm);
switch (corgi_jack_func) {
case CORGI_HP:
gpio_set_value(CORGI_GPIO_MUTE_L, 1);
gpio_set_value(CORGI_GPIO_MUTE_R, 1);
snd_soc_dapm_disable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
break;
case CORGI_MIC:
gpio_set_value(CORGI_GPIO_MUTE_L, 0);
gpio_set_value(CORGI_GPIO_MUTE_R, 0);
snd_soc_dapm_enable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
break;
case CORGI_LINE:
gpio_set_value(CORGI_GPIO_MUTE_L, 0);
gpio_set_value(CORGI_GPIO_MUTE_R, 0);
snd_soc_dapm_disable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
break;
case CORGI_HEADSET:
gpio_set_value(CORGI_GPIO_MUTE_L, 0);
gpio_set_value(CORGI_GPIO_MUTE_R, 1);
snd_soc_dapm_enable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Headset Jack");
break;
}
if (corgi_spk_func == CORGI_SPK_ON)
snd_soc_dapm_enable_pin_unlocked(dapm, "Ext Spk");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Ext Spk");
snd_soc_dapm_sync_unlocked(dapm);
snd_soc_dapm_mutex_unlock(dapm);
}
static int corgi_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
corgi_ext_control(&rtd->card->dapm);
return 0;
}
static void corgi_shutdown(struct snd_pcm_substream *substream)
{
gpio_set_value(CORGI_GPIO_MUTE_L, 1);
gpio_set_value(CORGI_GPIO_MUTE_R, 1);
}
static int corgi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
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
ret = snd_soc_dai_set_sysclk(codec_dai, WM8731_SYSCLK_XTAL, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA2XX_I2S_SYSCLK, 0,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int corgi_get_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] = corgi_jack_func;
return 0;
}
static int corgi_set_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (corgi_jack_func == ucontrol->value.enumerated.item[0])
return 0;
corgi_jack_func = ucontrol->value.enumerated.item[0];
corgi_ext_control(&card->dapm);
return 1;
}
static int corgi_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] = corgi_spk_func;
return 0;
}
static int corgi_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (corgi_spk_func == ucontrol->value.enumerated.item[0])
return 0;
corgi_spk_func = ucontrol->value.enumerated.item[0];
corgi_ext_control(&card->dapm);
return 1;
}
static int corgi_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
gpio_set_value(CORGI_GPIO_APM_ON, SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int corgi_mic_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
gpio_set_value(CORGI_GPIO_MIC_BIAS, SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int corgi_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &corgi;
int ret;
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
