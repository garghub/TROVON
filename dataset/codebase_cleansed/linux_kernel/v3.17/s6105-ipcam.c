static int s6105_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret = 0;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_CBM_CFM |
SND_SOC_DAIFMT_NB_NF);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, S6105_CAM_CODEC_CLOCK,
SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
return 0;
}
static int output_type_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item) {
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, "HPLOUT/HPROUT");
} else {
strcpy(uinfo->value.enumerated.name, "HPLOUT/HPLCOM");
}
return 0;
}
static int output_type_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] = kcontrol->private_value;
return 0;
}
static int output_type_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = kcontrol->private_data;
struct snd_soc_dapm_context *dapm = &card->dapm;
unsigned int val = (ucontrol->value.enumerated.item[0] != 0);
char *differential = "Audio Out Differential";
char *stereo = "Audio Out Stereo";
if (kcontrol->private_value == val)
return 0;
kcontrol->private_value = val;
snd_soc_dapm_disable_pin(dapm, val ? differential : stereo);
snd_soc_dapm_sync(dapm);
snd_soc_dapm_enable_pin(dapm, val ? stereo : differential);
snd_soc_dapm_sync(dapm);
return 1;
}
static int s6105_aic3x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_card *card = rtd->card;
snd_soc_dapm_disable_pin(&card->dapm, "Audio Out Differential");
snd_ctl_add(card->snd_card, snd_ctl_new1(&audio_out_mux, card));
return 0;
}
static int __init s6105_init(void)
{
int ret;
i2c_register_board_info(0, i2c_device, ARRAY_SIZE(i2c_device));
s6105_snd_device = platform_device_alloc("soc-audio", -1);
if (!s6105_snd_device)
return -ENOMEM;
platform_set_drvdata(s6105_snd_device, &snd_soc_card_s6105);
platform_device_add_data(s6105_snd_device, &s6105_snd_data,
sizeof(s6105_snd_data));
ret = platform_device_add(s6105_snd_device);
if (ret)
platform_device_put(s6105_snd_device);
return ret;
}
static void __exit s6105_exit(void)
{
platform_device_unregister(s6105_snd_device);
}
