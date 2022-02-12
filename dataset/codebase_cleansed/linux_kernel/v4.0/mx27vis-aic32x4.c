static int mx27vis_aic32x4_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
25000000, SND_SOC_CLOCK_OUT);
if (ret) {
pr_err("%s: failed setting codec sysclk\n", __func__);
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
SND_SOC_CLOCK_IN);
if (ret) {
pr_err("can't set CPU system clock IMX_SSP_SYS_CLK\n");
return ret;
}
return 0;
}
static int mx27vis_amp_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int value = ucontrol->value.integer.value[0];
unsigned int reg = mc->reg;
int max = mc->max;
if (value > max)
return -EINVAL;
switch (reg) {
case MX27VIS_AMP_GAIN:
gpio_set_value(mx27vis_amp_gain0_gpio, value & 1);
gpio_set_value(mx27vis_amp_gain1_gpio, value >> 1);
mx27vis_amp_gain = value;
break;
case MX27VIS_AMP_MUTE:
gpio_set_value(mx27vis_amp_mutel_gpio, value & 1);
gpio_set_value(mx27vis_amp_muter_gpio, value >> 1);
mx27vis_amp_mute = value;
break;
}
return 0;
}
static int mx27vis_amp_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
switch (reg) {
case MX27VIS_AMP_GAIN:
ucontrol->value.integer.value[0] = mx27vis_amp_gain;
break;
case MX27VIS_AMP_MUTE:
ucontrol->value.integer.value[0] = mx27vis_amp_mute;
break;
}
return 0;
}
static int mx27vis_aic32x4_probe(struct platform_device *pdev)
{
struct snd_mx27vis_platform_data *pdata = pdev->dev.platform_data;
int ret;
if (!pdata) {
dev_err(&pdev->dev, "No platform data supplied\n");
return -EINVAL;
}
mx27vis_amp_gain0_gpio = pdata->amp_gain0_gpio;
mx27vis_amp_gain1_gpio = pdata->amp_gain1_gpio;
mx27vis_amp_mutel_gpio = pdata->amp_mutel_gpio;
mx27vis_amp_muter_gpio = pdata->amp_muter_gpio;
mx27vis_aic32x4.dev = &pdev->dev;
ret = snd_soc_register_card(&mx27vis_aic32x4);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
return ret;
}
imx_audmux_v1_configure_port(MX27_AUDMUX_HPCR1_SSI0,
IMX_AUDMUX_V1_PCR_SYN |
IMX_AUDMUX_V1_PCR_TFSDIR |
IMX_AUDMUX_V1_PCR_TCLKDIR |
IMX_AUDMUX_V1_PCR_TFCSEL(MX27_AUDMUX_PPCR1_SSI_PINS_1) |
IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_PPCR1_SSI_PINS_1)
);
imx_audmux_v1_configure_port(MX27_AUDMUX_PPCR1_SSI_PINS_1,
IMX_AUDMUX_V1_PCR_SYN |
IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR1_SSI0)
);
return ret;
}
static int mx27vis_aic32x4_remove(struct platform_device *pdev)
{
snd_soc_unregister_card(&mx27vis_aic32x4);
return 0;
}
