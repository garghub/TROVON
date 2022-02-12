static void poodle_ext_control(struct snd_soc_dapm_context *dapm)
{
if (poodle_jack_func == POODLE_HP) {
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_L, 1);
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_R, 1);
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
} else {
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_L, 0);
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_R, 0);
snd_soc_dapm_disable_pin(dapm, "Headphone Jack");
}
if (poodle_spk_func == POODLE_SPK_ON)
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
else
snd_soc_dapm_disable_pin(dapm, "Ext Spk");
snd_soc_dapm_sync(dapm);
}
static int poodle_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
poodle_ext_control(&rtd->card->dapm);
return 0;
}
static void poodle_shutdown(struct snd_pcm_substream *substream)
{
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_L, 1);
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_R, 1);
}
static int poodle_hw_params(struct snd_pcm_substream *substream,
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
static int poodle_get_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = poodle_jack_func;
return 0;
}
static int poodle_set_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (poodle_jack_func == ucontrol->value.integer.value[0])
return 0;
poodle_jack_func = ucontrol->value.integer.value[0];
poodle_ext_control(&card->dapm);
return 1;
}
static int poodle_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = poodle_spk_func;
return 0;
}
static int poodle_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (poodle_spk_func == ucontrol->value.integer.value[0])
return 0;
poodle_spk_func = ucontrol->value.integer.value[0];
poodle_ext_control(&card->dapm);
return 1;
}
static int poodle_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_AMP_ON, 0);
else
locomo_gpio_write(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_AMP_ON, 1);
return 0;
}
static int poodle_wm8731_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "LLINEIN");
snd_soc_dapm_nc_pin(dapm, "RLINEIN");
return 0;
}
static int poodle_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &poodle;
int ret;
locomo_gpio_set_dir(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_AMP_ON, 0);
locomo_gpio_set_dir(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_L, 0);
locomo_gpio_set_dir(&poodle_locomo_device.dev,
POODLE_LOCOMO_GPIO_MUTE_R, 0);
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
static int poodle_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
