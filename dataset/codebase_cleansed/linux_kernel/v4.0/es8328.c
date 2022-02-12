static int es8328_set_deemph(struct snd_soc_codec *codec)
{
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (es8328->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(deemph_settings); i++) {
if (abs(deemph_settings[i] - es8328->playback_fs) <
abs(deemph_settings[best] - es8328->playback_fs))
best = i;
}
val = best << 1;
} else {
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", val);
return snd_soc_update_bits(codec, ES8328_DACCONTROL6, 0x6, val);
}
static int es8328_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = es8328->deemph;
return 0;
}
static int es8328_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int deemph = ucontrol->value.integer.value[0];
int ret;
if (deemph > 1)
return -EINVAL;
ret = es8328_set_deemph(codec);
if (ret < 0)
return ret;
es8328->deemph = deemph;
return 0;
}
static int es8328_mute(struct snd_soc_dai *dai, int mute)
{
return snd_soc_update_bits(dai->codec, ES8328_DACCONTROL3,
ES8328_DACCONTROL3_DACMUTE,
mute ? ES8328_DACCONTROL3_DACMUTE : 0);
}
static int es8328_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int clk_rate;
int i;
int reg;
u8 ratio;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = ES8328_DACCONTROL2;
else
reg = ES8328_ADCCONTROL5;
clk_rate = clk_get_rate(es8328->clk);
if ((clk_rate != ES8328_SYSCLK_RATE_1X) &&
(clk_rate != ES8328_SYSCLK_RATE_2X)) {
dev_err(codec->dev,
"%s: clock is running at %d Hz, not %d or %d Hz\n",
__func__, clk_rate,
ES8328_SYSCLK_RATE_1X, ES8328_SYSCLK_RATE_2X);
return -EINVAL;
}
ratio = mclk_ratios[0].rate;
for (i = 1; i < ARRAY_SIZE(mclk_ratios); i++)
if (params_rate(params) <= mclk_ratios[i].rate)
ratio = mclk_ratios[i].ratio;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
es8328->playback_fs = params_rate(params);
es8328_set_deemph(codec);
}
return snd_soc_update_bits(codec, reg, ES8328_RATEMASK, ratio);
}
static int es8328_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int clk_rate;
u8 mode = ES8328_DACCONTROL1_DACWL_16;
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBM_CFM)
return -EINVAL;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
mode |= ES8328_DACCONTROL1_DACFORMAT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
mode |= ES8328_DACCONTROL1_DACFORMAT_RJUST;
break;
case SND_SOC_DAIFMT_LEFT_J:
mode |= ES8328_DACCONTROL1_DACFORMAT_LJUST;
break;
default:
return -EINVAL;
}
if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF)
return -EINVAL;
snd_soc_write(codec, ES8328_DACCONTROL1, mode);
snd_soc_write(codec, ES8328_ADCCONTROL4, mode);
clk_rate = clk_get_rate(es8328->clk);
if (clk_rate == ES8328_SYSCLK_RATE_1X)
snd_soc_write(codec, ES8328_MASTERMODE,
ES8328_MASTERMODE_MSC);
else
snd_soc_write(codec, ES8328_MASTERMODE,
ES8328_MASTERMODE_MCLKDIV2 |
ES8328_MASTERMODE_MSC);
return 0;
}
static int es8328_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_write(codec, ES8328_CHIPPOWER, 0);
snd_soc_update_bits(codec, ES8328_CONTROL1,
ES8328_CONTROL1_VMIDSEL_MASK |
ES8328_CONTROL1_ENREF,
ES8328_CONTROL1_VMIDSEL_50k |
ES8328_CONTROL1_ENREF);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, ES8328_CONTROL1,
ES8328_CONTROL1_VMIDSEL_MASK |
ES8328_CONTROL1_ENREF,
ES8328_CONTROL1_VMIDSEL_5k |
ES8328_CONTROL1_ENREF);
msleep(100);
}
snd_soc_write(codec, ES8328_CONTROL2,
ES8328_CONTROL2_OVERCURRENT_ON |
ES8328_CONTROL2_THERMAL_SHUTDOWN_ON);
snd_soc_update_bits(codec, ES8328_CONTROL1,
ES8328_CONTROL1_VMIDSEL_MASK |
ES8328_CONTROL1_ENREF,
ES8328_CONTROL1_VMIDSEL_500k |
ES8328_CONTROL1_ENREF);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, ES8328_CONTROL1,
ES8328_CONTROL1_VMIDSEL_MASK |
ES8328_CONTROL1_ENREF,
0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int es8328_suspend(struct snd_soc_codec *codec)
{
struct es8328_priv *es8328;
int ret;
es8328 = snd_soc_codec_get_drvdata(codec);
clk_disable_unprepare(es8328->clk);
ret = regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
es8328->supplies);
if (ret) {
dev_err(codec->dev, "unable to disable regulators\n");
return ret;
}
return 0;
}
static int es8328_resume(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
struct es8328_priv *es8328;
int ret;
es8328 = snd_soc_codec_get_drvdata(codec);
ret = clk_prepare_enable(es8328->clk);
if (ret) {
dev_err(codec->dev, "unable to enable clock\n");
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(es8328->supplies),
es8328->supplies);
if (ret) {
dev_err(codec->dev, "unable to enable regulators\n");
return ret;
}
regcache_mark_dirty(regmap);
ret = regcache_sync(regmap);
if (ret) {
dev_err(codec->dev, "unable to sync regcache\n");
return ret;
}
return 0;
}
static int es8328_codec_probe(struct snd_soc_codec *codec)
{
struct es8328_priv *es8328;
int ret;
es8328 = snd_soc_codec_get_drvdata(codec);
ret = regulator_bulk_enable(ARRAY_SIZE(es8328->supplies),
es8328->supplies);
if (ret) {
dev_err(codec->dev, "unable to enable regulators\n");
return ret;
}
es8328->clk = devm_clk_get(codec->dev, NULL);
if (IS_ERR(es8328->clk)) {
dev_err(codec->dev, "codec clock missing or invalid\n");
ret = PTR_ERR(es8328->clk);
goto clk_fail;
}
ret = clk_prepare_enable(es8328->clk);
if (ret) {
dev_err(codec->dev, "unable to prepare codec clk\n");
goto clk_fail;
}
return 0;
clk_fail:
regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
es8328->supplies);
return ret;
}
static int es8328_remove(struct snd_soc_codec *codec)
{
struct es8328_priv *es8328;
es8328 = snd_soc_codec_get_drvdata(codec);
if (es8328->clk)
clk_disable_unprepare(es8328->clk);
regulator_bulk_disable(ARRAY_SIZE(es8328->supplies),
es8328->supplies);
return 0;
}
int es8328_probe(struct device *dev, struct regmap *regmap)
{
struct es8328_priv *es8328;
int ret;
int i;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
es8328 = devm_kzalloc(dev, sizeof(*es8328), GFP_KERNEL);
if (es8328 == NULL)
return -ENOMEM;
es8328->regmap = regmap;
for (i = 0; i < ARRAY_SIZE(es8328->supplies); i++)
es8328->supplies[i].supply = supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(es8328->supplies),
es8328->supplies);
if (ret) {
dev_err(dev, "unable to get regulators\n");
return ret;
}
dev_set_drvdata(dev, es8328);
return snd_soc_register_codec(dev,
&es8328_codec_driver, &es8328_dai, 1);
}
