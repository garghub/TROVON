static void ak4613_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
struct device *dev = codec->dev;
mutex_lock(&priv->lock);
priv->cnt--;
if (priv->cnt < 0) {
dev_err(dev, "unexpected counter error\n");
priv->cnt = 0;
}
if (!priv->cnt)
priv->fmt_ctrl = NO_FMT;
mutex_unlock(&priv->lock);
}
static int ak4613_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
fmt &= SND_SOC_DAIFMT_FORMAT_MASK;
switch (fmt) {
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_I2S:
priv->fmt = fmt;
break;
default:
return -EINVAL;
}
return 0;
}
static int ak4613_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
const struct ak4613_formats *fmts;
struct device *dev = codec->dev;
unsigned int width = params_width(params);
unsigned int fmt = priv->fmt;
unsigned int rate;
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
int i, ret;
u8 fmt_ctrl, ctrl2;
rate = params_rate(params);
switch (rate) {
case 32000:
case 44100:
case 48000:
ctrl2 = DFS_NORMAL_SPEED;
break;
case 88200:
case 96000:
ctrl2 = DFS_DOUBLE_SPEED;
break;
case 176400:
case 192000:
ctrl2 = DFS_QUAD_SPEED;
break;
default:
return -EINVAL;
}
fmt_ctrl = NO_FMT;
for (i = 0; i < ARRAY_SIZE(ak4613_iface); i++) {
fmts = (is_play) ? &ak4613_iface[i].playback :
&ak4613_iface[i].capture;
if (fmts->fmt != fmt)
continue;
if (fmt == SND_SOC_DAIFMT_RIGHT_J) {
if (fmts->width != width)
continue;
} else {
if (fmts->width < width)
continue;
}
fmt_ctrl = AUDIO_IFACE_IDX_TO_VAL(i);
break;
}
ret = -EINVAL;
if (fmt_ctrl == NO_FMT)
goto hw_params_end;
mutex_lock(&priv->lock);
if ((priv->fmt_ctrl == NO_FMT) ||
(priv->fmt_ctrl == fmt_ctrl)) {
priv->fmt_ctrl = fmt_ctrl;
priv->cnt++;
ret = 0;
}
mutex_unlock(&priv->lock);
if (ret < 0)
goto hw_params_end;
snd_soc_update_bits(codec, CTRL1, FMT_MASK, fmt_ctrl);
snd_soc_write(codec, CTRL2, ctrl2);
hw_params_end:
if (ret < 0)
dev_warn(dev, "unsupported data width/format combination\n");
return ret;
}
static int ak4613_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u8 mgmt1 = 0;
switch (level) {
case SND_SOC_BIAS_ON:
mgmt1 |= RSTN;
case SND_SOC_BIAS_PREPARE:
mgmt1 |= PMADC | PMDAC;
case SND_SOC_BIAS_STANDBY:
mgmt1 |= PMVR;
case SND_SOC_BIAS_OFF:
default:
break;
}
snd_soc_write(codec, PW_MGMT1, mgmt1);
return 0;
}
static int ak4613_resume(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
regcache_mark_dirty(regmap);
return regcache_sync(regmap);
}
static int ak4613_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct device_node *np = dev->of_node;
const struct regmap_config *regmap_cfg;
struct regmap *regmap;
struct ak4613_priv *priv;
regmap_cfg = NULL;
if (np) {
const struct of_device_id *of_id;
of_id = of_match_device(ak4613_of_match, dev);
if (of_id)
regmap_cfg = of_id->data;
} else {
regmap_cfg = (const struct regmap_config *)id->driver_data;
}
if (!regmap_cfg)
return -EINVAL;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->fmt_ctrl = NO_FMT;
priv->cnt = 0;
mutex_init(&priv->lock);
i2c_set_clientdata(i2c, priv);
regmap = devm_regmap_init_i2c(i2c, regmap_cfg);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return snd_soc_register_codec(dev, &soc_codec_dev_ak4613,
&ak4613_dai, 1);
}
static int ak4613_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
