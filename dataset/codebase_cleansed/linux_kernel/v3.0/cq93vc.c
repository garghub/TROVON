static inline unsigned int cq93vc_read(struct snd_soc_codec *codec,
unsigned int reg)
{
struct davinci_vc *davinci_vc = codec->control_data;
return readl(davinci_vc->base + reg);
}
static inline int cq93vc_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
struct davinci_vc *davinci_vc = codec->control_data;
writel(value, davinci_vc->base + reg);
return 0;
}
static int cq93vc_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 reg = cq93vc_read(codec, DAVINCI_VC_REG09) & ~DAVINCI_VC_REG09_MUTE;
if (mute)
cq93vc_write(codec, DAVINCI_VC_REG09,
reg | DAVINCI_VC_REG09_MUTE);
else
cq93vc_write(codec, DAVINCI_VC_REG09, reg);
return 0;
}
static int cq93vc_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct davinci_vc *davinci_vc = codec->control_data;
switch (freq) {
case 22579200:
case 27000000:
case 33868800:
davinci_vc->cq93vc.sysclk = freq;
return 0;
}
return -EINVAL;
}
static int cq93vc_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
cq93vc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_ON);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
cq93vc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_OFF);
break;
case SND_SOC_BIAS_OFF:
cq93vc_write(codec, DAVINCI_VC_REG12,
DAVINCI_VC_REG12_POWER_ALL_OFF);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int cq93vc_resume(struct snd_soc_codec *codec)
{
cq93vc_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int cq93vc_probe(struct snd_soc_codec *codec)
{
struct davinci_vc *davinci_vc = codec->dev->platform_data;
davinci_vc->cq93vc.codec = codec;
codec->control_data = davinci_vc;
snd_soc_add_controls(codec, cq93vc_snd_controls,
ARRAY_SIZE(cq93vc_snd_controls));
cq93vc_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int cq93vc_remove(struct snd_soc_codec *codec)
{
cq93vc_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
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
static int __init cq93vc_init(void)
{
return platform_driver_register(&cq93vc_codec_driver);
}
static void __exit cq93vc_exit(void)
{
platform_driver_unregister(&cq93vc_codec_driver);
}
