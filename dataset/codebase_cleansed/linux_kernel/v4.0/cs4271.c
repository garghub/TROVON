static bool cs4271_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == CS4271_CHIPID;
}
static int cs4271_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
cs4271->mclk = freq;
return 0;
}
static int cs4271_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
int ret;
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
cs4271->master = 0;
break;
case SND_SOC_DAIFMT_CBM_CFM:
cs4271->master = 1;
val |= CS4271_MODE1_MASTER;
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
val |= CS4271_MODE1_DAC_DIF_LJ;
ret = regmap_update_bits(cs4271->regmap, CS4271_ADCCTL,
CS4271_ADCCTL_ADC_DIF_MASK, CS4271_ADCCTL_ADC_DIF_LJ);
if (ret < 0)
return ret;
break;
case SND_SOC_DAIFMT_I2S:
val |= CS4271_MODE1_DAC_DIF_I2S;
ret = regmap_update_bits(cs4271->regmap, CS4271_ADCCTL,
CS4271_ADCCTL_ADC_DIF_MASK, CS4271_ADCCTL_ADC_DIF_I2S);
if (ret < 0)
return ret;
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE1,
CS4271_MODE1_DAC_DIF_MASK | CS4271_MODE1_MASTER, val);
if (ret < 0)
return ret;
return 0;
}
static int cs4271_set_deemph(struct snd_soc_codec *codec)
{
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
int i, ret;
int val = CS4271_DACCTL_DEM_DIS;
if (cs4271->deemph) {
val = 1;
for (i = 2; i < ARRAY_SIZE(cs4271_deemph); i++)
if (abs(cs4271_deemph[i] - cs4271->rate) <
abs(cs4271_deemph[val] - cs4271->rate))
val = i;
val <<= 4;
}
ret = regmap_update_bits(cs4271->regmap, CS4271_DACCTL,
CS4271_DACCTL_DEM_MASK, val);
if (ret < 0)
return ret;
return 0;
}
static int cs4271_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = cs4271->deemph;
return 0;
}
static int cs4271_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
cs4271->deemph = ucontrol->value.integer.value[0];
return cs4271_set_deemph(codec);
}
static int cs4271_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
int i, ret;
unsigned int ratio, val;
if (cs4271->enable_soft_reset) {
if ((substream->stream == SNDRV_PCM_STREAM_PLAYBACK &&
!dai->capture_active) ||
(substream->stream == SNDRV_PCM_STREAM_CAPTURE &&
!dai->playback_active)) {
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN,
CS4271_MODE2_PDN);
if (ret < 0)
return ret;
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN, 0);
if (ret < 0)
return ret;
}
}
cs4271->rate = params_rate(params);
if (cs4271->rate < 50000)
val = CS4271_MODE1_MODE_1X;
else if (cs4271->rate < 100000)
val = CS4271_MODE1_MODE_2X;
else
val = CS4271_MODE1_MODE_4X;
ratio = cs4271->mclk / cs4271->rate;
for (i = 0; i < CS4171_NR_RATIOS; i++)
if ((cs4271_clk_tab[i].master == cs4271->master) &&
(cs4271_clk_tab[i].speed_mode == val) &&
(cs4271_clk_tab[i].ratio == ratio))
break;
if (i == CS4171_NR_RATIOS) {
dev_err(codec->dev, "Invalid sample rate\n");
return -EINVAL;
}
val |= cs4271_clk_tab[i].ratio_mask;
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE1,
CS4271_MODE1_MODE_MASK | CS4271_MODE1_DIV_MASK, val);
if (ret < 0)
return ret;
return cs4271_set_deemph(codec);
}
static int cs4271_mute_stream(struct snd_soc_dai *dai, int mute, int stream)
{
struct snd_soc_codec *codec = dai->codec;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
int ret;
int val_a = 0;
int val_b = 0;
if (stream != SNDRV_PCM_STREAM_PLAYBACK)
return 0;
if (mute) {
val_a = CS4271_VOLA_MUTE;
val_b = CS4271_VOLB_MUTE;
}
ret = regmap_update_bits(cs4271->regmap, CS4271_VOLA,
CS4271_VOLA_MUTE, val_a);
if (ret < 0)
return ret;
ret = regmap_update_bits(cs4271->regmap, CS4271_VOLB,
CS4271_VOLB_MUTE, val_b);
if (ret < 0)
return ret;
return 0;
}
static int cs4271_soc_suspend(struct snd_soc_codec *codec)
{
int ret;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN, CS4271_MODE2_PDN);
if (ret < 0)
return ret;
return 0;
}
static int cs4271_soc_resume(struct snd_soc_codec *codec)
{
int ret;
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
ret = regcache_sync(cs4271->regmap);
if (ret < 0)
return ret;
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN, 0);
if (ret < 0)
return ret;
return 0;
}
static int cs4271_codec_probe(struct snd_soc_codec *codec)
{
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
struct cs4271_platform_data *cs4271plat = codec->dev->platform_data;
int ret;
bool amutec_eq_bmutec = false;
#ifdef CONFIG_OF
if (of_match_device(cs4271_dt_ids, codec->dev)) {
if (of_get_property(codec->dev->of_node,
"cirrus,amutec-eq-bmutec", NULL))
amutec_eq_bmutec = true;
if (of_get_property(codec->dev->of_node,
"cirrus,enable-soft-reset", NULL))
cs4271->enable_soft_reset = true;
}
#endif
if (cs4271plat) {
amutec_eq_bmutec = cs4271plat->amutec_eq_bmutec;
cs4271->enable_soft_reset = cs4271plat->enable_soft_reset;
}
if (gpio_is_valid(cs4271->gpio_nreset)) {
gpio_direction_output(cs4271->gpio_nreset, 0);
udelay(1);
gpio_set_value(cs4271->gpio_nreset, 1);
udelay(1);
}
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN | CS4271_MODE2_CPEN,
CS4271_MODE2_PDN | CS4271_MODE2_CPEN);
if (ret < 0)
return ret;
ret = regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_PDN, 0);
if (ret < 0)
return ret;
udelay(85);
if (amutec_eq_bmutec)
regmap_update_bits(cs4271->regmap, CS4271_MODE2,
CS4271_MODE2_MUTECAEQUB,
CS4271_MODE2_MUTECAEQUB);
return 0;
}
static int cs4271_codec_remove(struct snd_soc_codec *codec)
{
struct cs4271_private *cs4271 = snd_soc_codec_get_drvdata(codec);
if (gpio_is_valid(cs4271->gpio_nreset))
gpio_set_value(cs4271->gpio_nreset, 0);
return 0;
}
static int cs4271_common_probe(struct device *dev,
struct cs4271_private **c)
{
struct cs4271_platform_data *cs4271plat = dev->platform_data;
struct cs4271_private *cs4271;
cs4271 = devm_kzalloc(dev, sizeof(*cs4271), GFP_KERNEL);
if (!cs4271)
return -ENOMEM;
if (of_match_device(cs4271_dt_ids, dev))
cs4271->gpio_nreset =
of_get_named_gpio(dev->of_node, "reset-gpio", 0);
if (cs4271plat)
cs4271->gpio_nreset = cs4271plat->gpio_nreset;
if (gpio_is_valid(cs4271->gpio_nreset)) {
int ret;
ret = devm_gpio_request(dev, cs4271->gpio_nreset,
"CS4271 Reset");
if (ret < 0)
return ret;
}
*c = cs4271;
return 0;
}
int cs4271_probe(struct device *dev, struct regmap *regmap)
{
struct cs4271_private *cs4271;
int ret;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ret = cs4271_common_probe(dev, &cs4271);
if (ret < 0)
return ret;
dev_set_drvdata(dev, cs4271);
cs4271->regmap = regmap;
return snd_soc_register_codec(dev, &soc_codec_dev_cs4271, &cs4271_dai,
1);
}
