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
priv->iface = NULL;
mutex_unlock(&priv->lock);
}
static void ak4613_hw_constraints(struct ak4613_priv *priv,
struct snd_pcm_runtime *runtime)
{
static const unsigned int ak4613_rates[] = {
32000,
44100,
48000,
64000,
88200,
96000,
176400,
192000,
};
struct snd_pcm_hw_constraint_list *constraint = &priv->constraint;
unsigned int fs;
int i;
constraint->list = ak4613_rates;
constraint->mask = 0;
constraint->count = 0;
for (i = 0; i < ARRAY_SIZE(ak4613_rates); i++) {
fs = (ak4613_rates[i] <= 96000) ? 256 : 128;
if (priv->sysclk >= ak4613_rates[i] * fs)
constraint->count = i + 1;
}
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, constraint);
}
static int ak4613_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->cnt++;
ak4613_hw_constraints(priv, substream->runtime);
return 0;
}
static int ak4613_dai_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->sysclk = freq;
return 0;
}
static int ak4613_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
fmt &= SND_SOC_DAIFMT_FORMAT_MASK;
switch (fmt) {
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_I2S:
priv->fmt = fmt;
break;
default:
return -EINVAL;
}
return 0;
}
static bool ak4613_dai_fmt_matching(const struct ak4613_interface *iface,
int is_play,
unsigned int fmt, unsigned int width)
{
const struct ak4613_formats *fmts;
fmts = (is_play) ? &iface->playback : &iface->capture;
if (fmts->fmt != fmt)
return false;
if (fmts->width != width)
return false;
return true;
}
static int ak4613_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4613_priv *priv = snd_soc_codec_get_drvdata(codec);
const struct ak4613_interface *iface;
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
case 64000:
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
ret = -EINVAL;
iface = NULL;
mutex_lock(&priv->lock);
if (priv->iface) {
if (ak4613_dai_fmt_matching(priv->iface, is_play, fmt, width))
iface = priv->iface;
} else {
for (i = ARRAY_SIZE(ak4613_iface) - 1; i >= 0; i--) {
if (!ak4613_dai_fmt_matching(ak4613_iface + i,
is_play,
fmt, width))
continue;
iface = ak4613_iface + i;
break;
}
}
if ((priv->iface == NULL) ||
(priv->iface == iface)) {
priv->iface = iface;
ret = 0;
}
mutex_unlock(&priv->lock);
if (ret < 0)
goto hw_params_end;
fmt_ctrl = AUDIO_IFACE_TO_VAL(iface);
snd_soc_update_bits(codec, CTRL1, FMT_MASK, fmt_ctrl);
snd_soc_update_bits(codec, CTRL2, DFS_MASK, ctrl2);
snd_soc_update_bits(codec, ICTRL, ICTRL_MASK, priv->ic);
snd_soc_update_bits(codec, OCTRL, OCTRL_MASK, priv->oc);
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
static int ak4613_suspend(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
regcache_cache_only(regmap, true);
regcache_mark_dirty(regmap);
return 0;
}
static int ak4613_resume(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
regcache_cache_only(regmap, false);
return regcache_sync(regmap);
}
static void ak4613_parse_of(struct ak4613_priv *priv,
struct device *dev)
{
struct device_node *np = dev->of_node;
char prop[32];
int i;
for (i = 0; i < 2; i++) {
snprintf(prop, sizeof(prop), "asahi-kasei,in%d-single-end", i + 1);
if (!of_get_property(np, prop, NULL))
priv->ic |= 1 << i;
}
for (i = 0; i < 6; i++) {
snprintf(prop, sizeof(prop), "asahi-kasei,out%d-single-end", i + 1);
if (!of_get_property(np, prop, NULL))
priv->oc |= 1 << i;
}
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
ak4613_parse_of(priv, dev);
priv->iface = NULL;
priv->cnt = 0;
priv->sysclk = 0;
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
