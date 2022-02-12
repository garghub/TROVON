static void spitz_ext_control(struct snd_soc_dapm_context *dapm)
{
snd_soc_dapm_mutex_lock(dapm);
if (spitz_spk_func == SPITZ_SPK_ON)
snd_soc_dapm_enable_pin_unlocked(dapm, "Ext Spk");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Ext Spk");
switch (spitz_jack_func) {
case SPITZ_HP:
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Headphone Jack");
gpio_set_value(SPITZ_GPIO_MUTE_L, 1);
gpio_set_value(SPITZ_GPIO_MUTE_R, 1);
break;
case SPITZ_MIC:
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Mic Jack");
gpio_set_value(SPITZ_GPIO_MUTE_L, 0);
gpio_set_value(SPITZ_GPIO_MUTE_R, 0);
break;
case SPITZ_LINE:
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Line Jack");
gpio_set_value(SPITZ_GPIO_MUTE_L, 0);
gpio_set_value(SPITZ_GPIO_MUTE_R, 0);
break;
case SPITZ_HEADSET:
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
snd_soc_dapm_enable_pin_unlocked(dapm, "Headset Jack");
gpio_set_value(SPITZ_GPIO_MUTE_L, 0);
gpio_set_value(SPITZ_GPIO_MUTE_R, 1);
break;
case SPITZ_HP_OFF:
snd_soc_dapm_disable_pin_unlocked(dapm, "Headphone Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Headset Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Mic Jack");
snd_soc_dapm_disable_pin_unlocked(dapm, "Line Jack");
gpio_set_value(SPITZ_GPIO_MUTE_L, 0);
gpio_set_value(SPITZ_GPIO_MUTE_R, 0);
break;
}
snd_soc_dapm_sync_unlocked(dapm);
snd_soc_dapm_mutex_unlock(dapm);
}
static int spitz_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
spitz_ext_control(&rtd->card->dapm);
return 0;
}
static int spitz_hw_params(struct snd_pcm_substream *substream,
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
ret = snd_soc_dai_set_sysclk(codec_dai, WM8750_SYSCLK, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA2XX_I2S_SYSCLK, 0,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int spitz_get_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] = spitz_jack_func;
return 0;
}
static int spitz_set_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (spitz_jack_func == ucontrol->value.enumerated.item[0])
return 0;
spitz_jack_func = ucontrol->value.enumerated.item[0];
spitz_ext_control(&card->dapm);
return 1;
}
static int spitz_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] = spitz_spk_func;
return 0;
}
static int spitz_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (spitz_spk_func == ucontrol->value.enumerated.item[0])
return 0;
spitz_spk_func = ucontrol->value.enumerated.item[0];
spitz_ext_control(&card->dapm);
return 1;
}
static int spitz_mic_bias(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
gpio_set_value_cansleep(spitz_mic_gpio, SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int spitz_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_spitz;
int ret;
if (machine_is_akita())
spitz_mic_gpio = AKITA_GPIO_MIC_BIAS;
else
spitz_mic_gpio = SPITZ_GPIO_MIC_BIAS;
ret = gpio_request(spitz_mic_gpio, "MIC GPIO");
if (ret)
goto err1;
ret = gpio_direction_output(spitz_mic_gpio, 0);
if (ret)
goto err2;
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
goto err2;
}
return 0;
err2:
gpio_free(spitz_mic_gpio);
err1:
return ret;
}
static int spitz_remove(struct platform_device *pdev)
{
gpio_free(spitz_mic_gpio);
return 0;
}
