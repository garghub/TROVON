static int ak4642_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
snd_soc_write(codec, L_IVC, 0x91);
snd_soc_write(codec, R_IVC, 0x91);
} else {
snd_soc_update_bits(codec, SG_SL1, PMMP | MGAIN0, PMMP | MGAIN0);
snd_soc_write(codec, TIMER, ZTM(0x3) | WTM(0x3));
snd_soc_write(codec, ALC_CTL1, ALC | LMTH0);
snd_soc_update_bits(codec, PW_MGMT1, PMADL, PMADL);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, PMADR);
}
return 0;
}
static void ak4642_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
} else {
snd_soc_update_bits(codec, PW_MGMT1, PMADL, 0);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, 0);
snd_soc_update_bits(codec, ALC_CTL1, ALC, 0);
}
}
static int ak4642_dai_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4642_priv *priv = snd_soc_codec_get_drvdata(codec);
u8 pll;
int extended_freq = 0;
switch (freq) {
case 11289600:
pll = PLL2;
break;
case 12288000:
pll = PLL2 | PLL0;
break;
case 12000000:
pll = PLL2 | PLL1;
break;
case 24000000:
pll = PLL2 | PLL1 | PLL0;
break;
case 13500000:
pll = PLL3 | PLL2;
break;
case 27000000:
pll = PLL3 | PLL2 | PLL0;
break;
case 19200000:
pll = PLL3;
extended_freq = 1;
break;
case 13000000:
pll = PLL3 | PLL2 | PLL1;
extended_freq = 1;
break;
case 26000000:
pll = PLL3 | PLL2 | PLL1 | PLL0;
extended_freq = 1;
break;
default:
return -EINVAL;
}
if (extended_freq && !priv->drvdata->extended_frequencies)
return -EINVAL;
snd_soc_update_bits(codec, MD_CTL1, PLL_MASK, pll);
return 0;
}
static int ak4642_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u8 data;
u8 bcko;
data = MCKO | PMPLL;
bcko = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
data |= MS;
bcko = BCKO_64;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PW_MGMT2, MS | MCKO | PMPLL, data);
snd_soc_update_bits(codec, MD_CTL1, BCKO_MASK, bcko);
data = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
data = LEFT_J;
break;
case SND_SOC_DAIFMT_I2S:
data = I2S;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MD_CTL1, DIF_MASK, data);
return 0;
}
static int ak4642_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 rate;
switch (params_rate(params)) {
case 7350:
rate = FS2;
break;
case 8000:
rate = 0;
break;
case 11025:
rate = FS2 | FS0;
break;
case 12000:
rate = FS0;
break;
case 14700:
rate = FS2 | FS1;
break;
case 16000:
rate = FS1;
break;
case 22050:
rate = FS2 | FS1 | FS0;
break;
case 24000:
rate = FS1 | FS0;
break;
case 29400:
rate = FS3 | FS2 | FS1;
break;
case 32000:
rate = FS3 | FS1;
break;
case 44100:
rate = FS3 | FS2 | FS1 | FS0;
break;
case 48000:
rate = FS3 | FS1 | FS0;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MD_CTL2, FS_MASK, rate);
return 0;
}
static int ak4642_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, PW_MGMT1, 0x00);
break;
default:
snd_soc_update_bits(codec, PW_MGMT1, PMVCM, PMVCM);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ak4642_resume(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
regcache_mark_dirty(regmap);
regcache_sync(regmap);
return 0;
}
static int ak4642_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device_node *np = i2c->dev.of_node;
const struct ak4642_drvdata *drvdata = NULL;
struct regmap *regmap;
struct ak4642_priv *priv;
if (np) {
const struct of_device_id *of_id;
of_id = of_match_device(ak4642_of_match, &i2c->dev);
if (of_id)
drvdata = of_id->data;
} else {
drvdata = (const struct ak4642_drvdata *)id->driver_data;
}
if (!drvdata) {
dev_err(&i2c->dev, "Unknown device type\n");
return -EINVAL;
}
priv = devm_kzalloc(&i2c->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->drvdata = drvdata;
i2c_set_clientdata(i2c, priv);
regmap = devm_regmap_init_i2c(i2c, drvdata->regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_ak4642, &ak4642_dai, 1);
}
static int ak4642_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
