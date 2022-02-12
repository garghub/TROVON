static int es8328_set_deemph(struct snd_soc_codec *codec)
{
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (es8328->deemph) {
best = 0;
for (i = 1; i < ARRAY_SIZE(deemph_settings); i++) {
if (abs(deemph_settings[i].rate - es8328->playback_fs) <
abs(deemph_settings[best].rate - es8328->playback_fs))
best = i;
}
val = deemph_settings[best].val;
} else {
val = ES8328_DACCONTROL6_DEEMPH_OFF;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", val);
return snd_soc_update_bits(codec, ES8328_DACCONTROL6,
ES8328_DACCONTROL6_DEEMPH_MASK, val);
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
unsigned int deemph = ucontrol->value.integer.value[0];
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
static int es8328_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
if (es8328->master && es8328->sysclk_constraints)
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
es8328->sysclk_constraints);
return 0;
}
static int es8328_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int i;
int reg;
int wl;
int ratio;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = ES8328_DACCONTROL2;
else
reg = ES8328_ADCCONTROL5;
if (es8328->master) {
if (!es8328->sysclk_constraints) {
dev_err(codec->dev, "No MCLK configured\n");
return -EINVAL;
}
for (i = 0; i < es8328->sysclk_constraints->count; i++)
if (es8328->sysclk_constraints->list[i] ==
params_rate(params))
break;
if (i == es8328->sysclk_constraints->count) {
dev_err(codec->dev,
"LRCLK %d unsupported with current clock\n",
params_rate(params));
return -EINVAL;
}
ratio = es8328->mclk_ratios[i];
} else {
ratio = 0;
es8328->mclkdiv2 = 0;
}
snd_soc_update_bits(codec, ES8328_MASTERMODE,
ES8328_MASTERMODE_MCLKDIV2,
es8328->mclkdiv2 ? ES8328_MASTERMODE_MCLKDIV2 : 0);
switch (params_width(params)) {
case 16:
wl = 3;
break;
case 18:
wl = 2;
break;
case 20:
wl = 1;
break;
case 24:
wl = 0;
break;
case 32:
wl = 4;
break;
default:
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
snd_soc_update_bits(codec, ES8328_DACCONTROL1,
ES8328_DACCONTROL1_DACWL_MASK,
wl << ES8328_DACCONTROL1_DACWL_SHIFT);
es8328->playback_fs = params_rate(params);
es8328_set_deemph(codec);
} else
snd_soc_update_bits(codec, ES8328_ADCCONTROL4,
ES8328_ADCCONTROL4_ADCWL_MASK,
wl << ES8328_ADCCONTROL4_ADCWL_SHIFT);
return snd_soc_update_bits(codec, reg, ES8328_RATEMASK, ratio);
}
static int es8328_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
int mclkdiv2 = 0;
switch (freq) {
case 0:
es8328->sysclk_constraints = NULL;
es8328->mclk_ratios = NULL;
break;
case 22579200:
mclkdiv2 = 1;
case 11289600:
es8328->sysclk_constraints = &constraints_11289;
es8328->mclk_ratios = ratios_11289;
break;
case 24576000:
mclkdiv2 = 1;
case 12288000:
es8328->sysclk_constraints = &constraints_12288;
es8328->mclk_ratios = ratios_12288;
break;
default:
return -EINVAL;
}
es8328->mclkdiv2 = mclkdiv2;
return 0;
}
static int es8328_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct es8328_priv *es8328 = snd_soc_codec_get_drvdata(codec);
u8 dac_mode = 0;
u8 adc_mode = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec, ES8328_MASTERMODE,
ES8328_MASTERMODE_MSC,
ES8328_MASTERMODE_MSC);
es8328->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec, ES8328_MASTERMODE,
ES8328_MASTERMODE_MSC, 0);
es8328->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dac_mode |= ES8328_DACCONTROL1_DACFORMAT_I2S;
adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
dac_mode |= ES8328_DACCONTROL1_DACFORMAT_RJUST;
adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_RJUST;
break;
case SND_SOC_DAIFMT_LEFT_J:
dac_mode |= ES8328_DACCONTROL1_DACFORMAT_LJUST;
adc_mode |= ES8328_ADCCONTROL4_ADCFORMAT_LJUST;
break;
default:
return -EINVAL;
}
if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF)
return -EINVAL;
snd_soc_update_bits(codec, ES8328_DACCONTROL1,
ES8328_DACCONTROL1_DACFORMAT_MASK, dac_mode);
snd_soc_update_bits(codec, ES8328_ADCCONTROL4,
ES8328_ADCCONTROL4_ADCFORMAT_MASK, adc_mode);
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
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
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
