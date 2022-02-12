static bool pcm1792a_accessible_reg(struct device *dev, unsigned int reg)
{
return reg >= 0x10 && reg <= 0x17;
}
static bool pcm1792a_writeable_reg(struct device *dev, unsigned register reg)
{
bool accessible;
accessible = pcm1792a_accessible_reg(dev, reg);
return accessible && reg != 0x16 && reg != 0x17;
}
static int pcm1792a_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pcm1792a_private *priv = snd_soc_codec_get_drvdata(codec);
priv->format = format;
return 0;
}
static int pcm1792a_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm1792a_private *priv = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regmap_update_bits(priv->regmap, PCM1792A_SOFT_MUTE,
PCM1792A_MUTE_MASK, !!mute);
if (ret < 0)
return ret;
return 0;
}
static int pcm1792a_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm1792a_private *priv = snd_soc_codec_get_drvdata(codec);
int val = 0, ret;
int pcm_format = params_format(params);
priv->rate = params_rate(params);
switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
if (pcm_format == SNDRV_PCM_FORMAT_S24_LE ||
pcm_format == SNDRV_PCM_FORMAT_S32_LE)
val = 0x02;
else if (pcm_format == SNDRV_PCM_FORMAT_S16_LE)
val = 0x00;
break;
case SND_SOC_DAIFMT_I2S:
if (pcm_format == SNDRV_PCM_FORMAT_S24_LE ||
pcm_format == SNDRV_PCM_FORMAT_S32_LE)
val = 0x05;
else if (pcm_format == SNDRV_PCM_FORMAT_S16_LE)
val = 0x04;
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
val = val << PCM1792A_FMT_SHIFT | PCM1792A_ATLD_ENABLE;
ret = regmap_update_bits(priv->regmap, PCM1792A_FMT_CONTROL,
PCM1792A_FMT_MASK | PCM1792A_ATLD_ENABLE, val);
if (ret < 0)
return ret;
return 0;
}
static int pcm1792a_spi_probe(struct spi_device *spi)
{
struct pcm1792a_private *pcm1792a;
int ret;
pcm1792a = devm_kzalloc(&spi->dev, sizeof(struct pcm1792a_private),
GFP_KERNEL);
if (!pcm1792a)
return -ENOMEM;
spi_set_drvdata(spi, pcm1792a);
pcm1792a->regmap = devm_regmap_init_spi(spi, &pcm1792a_regmap);
if (IS_ERR(pcm1792a->regmap)) {
ret = PTR_ERR(pcm1792a->regmap);
dev_err(&spi->dev, "Failed to register regmap: %d\n", ret);
return ret;
}
return snd_soc_register_codec(&spi->dev,
&soc_codec_dev_pcm1792a, &pcm1792a_dai, 1);
}
static int pcm1792a_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
