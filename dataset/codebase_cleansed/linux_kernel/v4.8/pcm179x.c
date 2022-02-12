static bool pcm179x_accessible_reg(struct device *dev, unsigned int reg)
{
return reg >= 0x10 && reg <= 0x17;
}
static bool pcm179x_writeable_reg(struct device *dev, unsigned int reg)
{
bool accessible;
accessible = pcm179x_accessible_reg(dev, reg);
return accessible && reg != 0x16 && reg != 0x17;
}
static int pcm179x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pcm179x_private *priv = snd_soc_codec_get_drvdata(codec);
priv->format = format;
return 0;
}
static int pcm179x_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm179x_private *priv = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regmap_update_bits(priv->regmap, PCM179X_SOFT_MUTE,
PCM179X_MUTE_MASK, !!mute);
if (ret < 0)
return ret;
return 0;
}
static int pcm179x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm179x_private *priv = snd_soc_codec_get_drvdata(codec);
int val = 0, ret;
priv->rate = params_rate(params);
switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
switch (params_width(params)) {
case 24:
case 32:
val = 2;
break;
case 16:
val = 0;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
switch (params_width(params)) {
case 24:
case 32:
val = 5;
break;
case 16:
val = 4;
break;
default:
return -EINVAL;
}
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
val = val << PCM179X_FMT_SHIFT | PCM179X_ATLD_ENABLE;
ret = regmap_update_bits(priv->regmap, PCM179X_FMT_CONTROL,
PCM179X_FMT_MASK | PCM179X_ATLD_ENABLE, val);
if (ret < 0)
return ret;
return 0;
}
int pcm179x_common_init(struct device *dev, struct regmap *regmap)
{
struct pcm179x_private *pcm179x;
pcm179x = devm_kzalloc(dev, sizeof(struct pcm179x_private),
GFP_KERNEL);
if (!pcm179x)
return -ENOMEM;
pcm179x->regmap = regmap;
dev_set_drvdata(dev, pcm179x);
return snd_soc_register_codec(dev,
&soc_codec_dev_pcm179x, &pcm179x_dai, 1);
}
int pcm179x_common_exit(struct device *dev)
{
snd_soc_unregister_codec(dev);
return 0;
}
