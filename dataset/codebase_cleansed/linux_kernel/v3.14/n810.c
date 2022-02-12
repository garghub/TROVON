static void n810_ext_control(struct snd_soc_dapm_context *dapm)
{
int hp = 0, line1l = 0;
switch (n810_jack_func) {
case N810_JACK_HS:
line1l = 1;
case N810_JACK_HP:
hp = 1;
break;
case N810_JACK_MIC:
line1l = 1;
break;
}
if (n810_spk_func)
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
else
snd_soc_dapm_disable_pin(dapm, "Ext Spk");
if (hp)
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
else
snd_soc_dapm_disable_pin(dapm, "Headphone Jack");
if (line1l)
snd_soc_dapm_enable_pin(dapm, "LINE1L");
else
snd_soc_dapm_disable_pin(dapm, "LINE1L");
if (n810_dmic_func)
snd_soc_dapm_enable_pin(dapm, "DMic");
else
snd_soc_dapm_disable_pin(dapm, "DMic");
snd_soc_dapm_sync(dapm);
}
static int n810_startup(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_CHANNELS, 2, 2);
n810_ext_control(&codec->dapm);
return clk_prepare_enable(sys_clkout2);
}
static void n810_shutdown(struct snd_pcm_substream *substream)
{
clk_disable_unprepare(sys_clkout2);
}
static int n810_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int err;
err = snd_soc_dai_set_sysclk(codec_dai, 0, 12000000,
SND_SOC_CLOCK_IN);
return err;
}
static int n810_get_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = n810_spk_func;
return 0;
}
static int n810_set_spk(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (n810_spk_func == ucontrol->value.integer.value[0])
return 0;
n810_spk_func = ucontrol->value.integer.value[0];
n810_ext_control(&card->dapm);
return 1;
}
static int n810_get_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = n810_jack_func;
return 0;
}
static int n810_set_jack(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (n810_jack_func == ucontrol->value.integer.value[0])
return 0;
n810_jack_func = ucontrol->value.integer.value[0];
n810_ext_control(&card->dapm);
return 1;
}
static int n810_get_input(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = n810_dmic_func;
return 0;
}
static int n810_set_input(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
if (n810_dmic_func == ucontrol->value.integer.value[0])
return 0;
n810_dmic_func = ucontrol->value.integer.value[0];
n810_ext_control(&card->dapm);
return 1;
}
static int n810_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value(N810_SPEAKER_AMP_GPIO, 1);
else
gpio_set_value(N810_SPEAKER_AMP_GPIO, 0);
return 0;
}
static int n810_jack_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value(N810_HEADSET_AMP_GPIO, 1);
else
gpio_set_value(N810_HEADSET_AMP_GPIO, 0);
return 0;
}
static int n810_aic33_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "MONO_LOUT");
snd_soc_dapm_nc_pin(dapm, "HPLCOM");
snd_soc_dapm_nc_pin(dapm, "HPRCOM");
snd_soc_dapm_nc_pin(dapm, "MIC3L");
snd_soc_dapm_nc_pin(dapm, "MIC3R");
snd_soc_dapm_nc_pin(dapm, "LINE1R");
snd_soc_dapm_nc_pin(dapm, "LINE2L");
snd_soc_dapm_nc_pin(dapm, "LINE2R");
return 0;
}
static int __init n810_soc_init(void)
{
int err;
struct device *dev;
if (!of_have_populated_dt() ||
(!of_machine_is_compatible("nokia,n810") &&
!of_machine_is_compatible("nokia,n810-wimax")))
return -ENODEV;
n810_snd_device = platform_device_alloc("soc-audio", -1);
if (!n810_snd_device)
return -ENOMEM;
platform_set_drvdata(n810_snd_device, &snd_soc_n810);
err = platform_device_add(n810_snd_device);
if (err)
goto err1;
dev = &n810_snd_device->dev;
sys_clkout2_src = clk_get(dev, "sys_clkout2_src");
if (IS_ERR(sys_clkout2_src)) {
dev_err(dev, "Could not get sys_clkout2_src clock\n");
err = PTR_ERR(sys_clkout2_src);
goto err2;
}
sys_clkout2 = clk_get(dev, "sys_clkout2");
if (IS_ERR(sys_clkout2)) {
dev_err(dev, "Could not get sys_clkout2\n");
err = PTR_ERR(sys_clkout2);
goto err3;
}
func96m_clk = clk_get(dev, "func_96m_ck");
if (IS_ERR(func96m_clk)) {
dev_err(dev, "Could not get func 96M clock\n");
err = PTR_ERR(func96m_clk);
goto err4;
}
clk_set_parent(sys_clkout2_src, func96m_clk);
clk_set_rate(sys_clkout2, 12000000);
if (WARN_ON((gpio_request(N810_HEADSET_AMP_GPIO, "hs_amp") < 0) ||
(gpio_request(N810_SPEAKER_AMP_GPIO, "spk_amp") < 0))) {
err = -EINVAL;
goto err4;
}
gpio_direction_output(N810_HEADSET_AMP_GPIO, 0);
gpio_direction_output(N810_SPEAKER_AMP_GPIO, 0);
return 0;
err4:
clk_put(sys_clkout2);
err3:
clk_put(sys_clkout2_src);
err2:
platform_device_del(n810_snd_device);
err1:
platform_device_put(n810_snd_device);
return err;
}
static void __exit n810_soc_exit(void)
{
gpio_free(N810_SPEAKER_AMP_GPIO);
gpio_free(N810_HEADSET_AMP_GPIO);
clk_put(sys_clkout2_src);
clk_put(sys_clkout2);
clk_put(func96m_clk);
platform_device_unregister(n810_snd_device);
}
