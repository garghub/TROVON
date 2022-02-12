static int cq93vc_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 reg;
if (mute)
reg = DAVINCI_VC_REG09_MUTE;
else
reg = 0;
snd_soc_update_bits(codec, DAVINCI_VC_REG09, DAVINCI_VC_REG09_MUTE,
reg);
return 0;
}
static int cq93vc_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
switch (freq) {
case 22579200:
case 27000000:
case 33868800:
return 0;
}
return -EINVAL;
}
static int cq93vc_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_ON);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_OFF);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_OFF);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static struct regmap *cq93vc_get_regmap(struct device *dev)
{
struct davinci_vc *davinci_vc = dev->platform_data;
return davinci_vc->regmap;
}
static int cq93vc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_cq93vc, &cq93vc_dai, 1);
}
static int cq93vc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
