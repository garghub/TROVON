static bool max98371_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98371_IRQ_CLEAR1:
case MAX98371_IRQ_CLEAR2:
case MAX98371_IRQ_CLEAR3:
case MAX98371_VERSION:
return true;
default:
return false;
}
}
static bool max98371_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98371_SOFT_RESET:
return false;
default:
return true;
}
}
static int max98371_dai_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98371_priv *max98371 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
dev_err(codec->dev, "DAI clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val |= 0;
break;
case SND_SOC_DAIFMT_RIGHT_J:
val |= MAX98371_DAI_RIGHT;
break;
case SND_SOC_DAIFMT_LEFT_J:
val |= MAX98371_DAI_LEFT;
break;
default:
dev_err(codec->dev, "DAI wrong mode unsupported");
return -EINVAL;
}
regmap_update_bits(max98371->regmap, MAX98371_FMT,
MAX98371_FMT_MODE_MASK, val);
return 0;
}
static int max98371_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98371_priv *max98371 = snd_soc_codec_get_drvdata(codec);
int blr_clk_ratio, ch_size, channels = params_channels(params);
int rate = params_rate(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
regmap_update_bits(max98371->regmap, MAX98371_FMT,
MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_16);
ch_size = 8;
break;
case SNDRV_PCM_FORMAT_S16_LE:
regmap_update_bits(max98371->regmap, MAX98371_FMT,
MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_16);
ch_size = 16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
regmap_update_bits(max98371->regmap, MAX98371_FMT,
MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_32);
ch_size = 24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
regmap_update_bits(max98371->regmap, MAX98371_FMT,
MAX98371_FMT_MASK, MAX98371_DAI_CHANSZ_32);
ch_size = 32;
break;
default:
return -EINVAL;
}
blr_clk_ratio = channels * ch_size;
switch (blr_clk_ratio) {
case 32:
regmap_update_bits(max98371->regmap,
MAX98371_DAI_CLK,
MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_32);
break;
case 48:
regmap_update_bits(max98371->regmap,
MAX98371_DAI_CLK,
MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_48);
break;
case 64:
regmap_update_bits(max98371->regmap,
MAX98371_DAI_CLK,
MAX98371_DAI_BSEL_MASK, MAX98371_DAI_BSEL_64);
break;
default:
return -EINVAL;
}
switch (rate) {
case 32000:
regmap_update_bits(max98371->regmap,
MAX98371_SPK_SR,
MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_32);
break;
case 44100:
regmap_update_bits(max98371->regmap,
MAX98371_SPK_SR,
MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_44);
break;
case 48000:
regmap_update_bits(max98371->regmap,
MAX98371_SPK_SR,
MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_48);
break;
case 88200:
regmap_update_bits(max98371->regmap,
MAX98371_SPK_SR,
MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_88);
break;
case 96000:
regmap_update_bits(max98371->regmap,
MAX98371_SPK_SR,
MAX98371_SPK_SR_MASK, MAX98371_SPK_SR_96);
break;
default:
return -EINVAL;
}
regmap_update_bits(max98371->regmap, MAX98371_MONOMIX_SRC,
MAX98371_MONOMIX_SRC_MASK, MONOMIX_RX_0_1);
regmap_update_bits(max98371->regmap, MAX98371_DAI_CHANNEL,
MAX98371_CHANNEL_MASK, MAX98371_CHANNEL_MASK);
return 0;
}
static int max98371_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max98371_priv *max98371;
int ret, reg;
max98371 = devm_kzalloc(&i2c->dev,
sizeof(*max98371), GFP_KERNEL);
if (!max98371)
return -ENOMEM;
i2c_set_clientdata(i2c, max98371);
max98371->regmap = devm_regmap_init_i2c(i2c, &max98371_regmap);
if (IS_ERR(max98371->regmap)) {
ret = PTR_ERR(max98371->regmap);
dev_err(&i2c->dev,
"Failed to allocate regmap: %d\n", ret);
return ret;
}
ret = regmap_read(max98371->regmap, MAX98371_VERSION, &reg);
if (ret < 0) {
dev_info(&i2c->dev, "device error %d\n", ret);
return ret;
}
dev_info(&i2c->dev, "device version %x\n", reg);
ret = snd_soc_register_codec(&i2c->dev, &max98371_codec,
max98371_dai, ARRAY_SIZE(max98371_dai));
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
return ret;
}
return ret;
}
static int max98371_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
