static inline int get_srate(int rate)
{
int srate;
switch (rate) {
case 16000:
srate = 3;
break;
case 32000:
srate = 6;
break;
case 48000:
srate = 8;
break;
default:
return -EINVAL;
}
return srate;
}
static inline int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
return -EINVAL;
}
static int ml26124_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ml26124_priv *priv = snd_soc_codec_get_drvdata(codec);
int i = get_coeff(priv->mclk, params_rate(hw_params));
priv->substream = substream;
priv->rate = params_rate(hw_params);
if (priv->clk_in) {
switch (priv->mclk / params_rate(hw_params)) {
case 256:
snd_soc_update_bits(codec, ML26124_CLK_CTL,
BIT(0) | BIT(1), 1);
break;
case 512:
snd_soc_update_bits(codec, ML26124_CLK_CTL,
BIT(0) | BIT(1), 2);
break;
case 1024:
snd_soc_update_bits(codec, ML26124_CLK_CTL,
BIT(0) | BIT(1), 3);
break;
default:
dev_err(codec->dev, "Unsupported MCLKI\n");
break;
}
} else {
snd_soc_update_bits(codec, ML26124_CLK_CTL,
BIT(0) | BIT(1), 0);
}
switch (params_rate(hw_params)) {
case 16000:
snd_soc_update_bits(codec, ML26124_SMPLING_RATE, 0xf,
get_srate(params_rate(hw_params)));
snd_soc_update_bits(codec, ML26124_PLLNL, 0xff,
coeff_div[i].pllnl);
snd_soc_update_bits(codec, ML26124_PLLNH, 0x1,
coeff_div[i].pllnh);
snd_soc_update_bits(codec, ML26124_PLLML, 0xff,
coeff_div[i].pllml);
snd_soc_update_bits(codec, ML26124_PLLMH, 0x3f,
coeff_div[i].pllmh);
snd_soc_update_bits(codec, ML26124_PLLDIV, 0x1f,
coeff_div[i].plldiv);
break;
case 32000:
snd_soc_update_bits(codec, ML26124_SMPLING_RATE, 0xf,
get_srate(params_rate(hw_params)));
snd_soc_update_bits(codec, ML26124_PLLNL, 0xff,
coeff_div[i].pllnl);
snd_soc_update_bits(codec, ML26124_PLLNH, 0x1,
coeff_div[i].pllnh);
snd_soc_update_bits(codec, ML26124_PLLML, 0xff,
coeff_div[i].pllml);
snd_soc_update_bits(codec, ML26124_PLLMH, 0x3f,
coeff_div[i].pllmh);
snd_soc_update_bits(codec, ML26124_PLLDIV, 0x1f,
coeff_div[i].plldiv);
break;
case 48000:
snd_soc_update_bits(codec, ML26124_SMPLING_RATE, 0xf,
get_srate(params_rate(hw_params)));
snd_soc_update_bits(codec, ML26124_PLLNL, 0xff,
coeff_div[i].pllnl);
snd_soc_update_bits(codec, ML26124_PLLNH, 0x1,
coeff_div[i].pllnh);
snd_soc_update_bits(codec, ML26124_PLLML, 0xff,
coeff_div[i].pllml);
snd_soc_update_bits(codec, ML26124_PLLMH, 0x3f,
coeff_div[i].pllmh);
snd_soc_update_bits(codec, ML26124_PLLDIV, 0x1f,
coeff_div[i].plldiv);
break;
default:
pr_err("%s:this rate is no support for ml26124\n", __func__);
return -EINVAL;
}
return 0;
}
static int ml26124_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct ml26124_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (priv->substream->stream) {
case SNDRV_PCM_STREAM_CAPTURE:
snd_soc_update_bits(codec, ML26124_REC_PLYBAK_RUN, BIT(0), 1);
break;
case SNDRV_PCM_STREAM_PLAYBACK:
snd_soc_update_bits(codec, ML26124_REC_PLYBAK_RUN, BIT(1), 2);
break;
}
if (mute)
snd_soc_update_bits(codec, ML26124_DVOL_CTL, BIT(4),
DVOL_CTL_DVMUTE_ON);
else
snd_soc_update_bits(codec, ML26124_DVOL_CTL, BIT(4),
DVOL_CTL_DVMUTE_OFF);
return 0;
}
static int ml26124_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
unsigned char mode;
struct snd_soc_codec *codec = codec_dai->codec;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
mode = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
mode = 0;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, ML26124_SAI_MODE_SEL, BIT(0), mode);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
return 0;
}
static int ml26124_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ml26124_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case ML26124_USE_PLLOUT:
priv->clk_in = ML26124_USE_PLLOUT;
break;
case ML26124_USE_MCLKI:
priv->clk_in = ML26124_USE_MCLKI;
break;
default:
return -EINVAL;
}
priv->mclk = freq;
return 0;
}
static int ml26124_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct ml26124_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, ML26124_PW_SPAMP_PW_MNG,
ML26124_R26_MASK, ML26124_BLT_PREAMP_ON);
msleep(100);
snd_soc_update_bits(codec, ML26124_PW_SPAMP_PW_MNG,
ML26124_R26_MASK,
ML26124_MICBEN_ON | ML26124_BLT_ALL_ON);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, ML26124_PW_REF_PW_MNG,
ML26124_VMID, ML26124_VMID);
msleep(500);
regcache_sync(priv->regmap);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, ML26124_PW_REF_PW_MNG,
ML26124_VMID, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ml26124_suspend(struct snd_soc_codec *codec)
{
ml26124_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ml26124_resume(struct snd_soc_codec *codec)
{
ml26124_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ml26124_probe(struct snd_soc_codec *codec)
{
int ret;
struct ml26124_priv *priv = snd_soc_codec_get_drvdata(codec);
codec->control_data = priv->regmap;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, ML26124_SW_RST, 0x01, 1);
snd_soc_update_bits(codec, ML26124_SW_RST, 0x01, 0);
ml26124_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static __devinit int ml26124_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ml26124_priv *priv;
int ret;
priv = devm_kzalloc(&i2c->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
i2c_set_clientdata(i2c, priv);
priv->regmap = devm_regmap_init_i2c(i2c, &ml26124_i2c_regmap);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(&i2c->dev, "regmap_init_i2c() failed: %d\n", ret);
return ret;
}
return snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_ml26124, &ml26124_dai, 1);
}
static __devexit int ml26124_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
