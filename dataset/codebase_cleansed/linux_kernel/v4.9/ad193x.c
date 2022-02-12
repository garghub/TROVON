static inline bool ad193x_has_adc(const struct ad193x_priv *ad193x)
{
switch (ad193x->type) {
case AD1933:
case AD1934:
return false;
default:
break;
}
return true;
}
static int ad193x_mute(struct snd_soc_dai *dai, int mute)
{
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(dai->codec);
if (mute)
regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
AD193X_DAC_MASTER_MUTE,
AD193X_DAC_MASTER_MUTE);
else
regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
AD193X_DAC_MASTER_MUTE, 0);
return 0;
}
static int ad193x_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(dai->codec);
unsigned int channels;
switch (slots) {
case 2:
channels = AD193X_2_CHANNELS;
break;
case 4:
channels = AD193X_4_CHANNELS;
break;
case 8:
channels = AD193X_8_CHANNELS;
break;
case 16:
channels = AD193X_16_CHANNELS;
break;
default:
return -EINVAL;
}
regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL1,
AD193X_DAC_CHAN_MASK, channels << AD193X_DAC_CHAN_SHFT);
if (ad193x_has_adc(ad193x))
regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL2,
AD193X_ADC_CHAN_MASK,
channels << AD193X_ADC_CHAN_SHFT);
return 0;
}
static int ad193x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec_dai->codec);
unsigned int adc_serfmt = 0;
unsigned int adc_fmt = 0;
unsigned int dac_fmt = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
adc_serfmt |= AD193X_ADC_SERFMT_TDM;
break;
case SND_SOC_DAIFMT_DSP_A:
adc_serfmt |= AD193X_ADC_SERFMT_AUX;
break;
default:
if (ad193x_has_adc(ad193x))
return -EINVAL;
break;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
adc_fmt |= AD193X_ADC_LEFT_HIGH;
dac_fmt |= AD193X_DAC_LEFT_HIGH;
break;
case SND_SOC_DAIFMT_IB_NF:
adc_fmt |= AD193X_ADC_BCLK_INV;
dac_fmt |= AD193X_DAC_BCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
adc_fmt |= AD193X_ADC_LEFT_HIGH;
adc_fmt |= AD193X_ADC_BCLK_INV;
dac_fmt |= AD193X_DAC_LEFT_HIGH;
dac_fmt |= AD193X_DAC_BCLK_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
adc_fmt |= AD193X_ADC_LCR_MASTER;
adc_fmt |= AD193X_ADC_BCLK_MASTER;
dac_fmt |= AD193X_DAC_LCR_MASTER;
dac_fmt |= AD193X_DAC_BCLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFM:
adc_fmt |= AD193X_ADC_LCR_MASTER;
dac_fmt |= AD193X_DAC_LCR_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFS:
adc_fmt |= AD193X_ADC_BCLK_MASTER;
dac_fmt |= AD193X_DAC_BCLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
if (ad193x_has_adc(ad193x)) {
regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL1,
AD193X_ADC_SERFMT_MASK, adc_serfmt);
regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL2,
AD193X_ADC_FMT_MASK, adc_fmt);
}
regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL1,
AD193X_DAC_FMT_MASK, dac_fmt);
return 0;
}
static int ad193x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 12288000:
case 18432000:
case 24576000:
case 36864000:
ad193x->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int ad193x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int word_len = 0, master_rate = 0;
struct snd_soc_codec *codec = dai->codec;
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec);
switch (params_width(params)) {
case 16:
word_len = 3;
break;
case 20:
word_len = 1;
break;
case 24:
case 32:
word_len = 0;
break;
}
switch (ad193x->sysclk) {
case 12288000:
master_rate = AD193X_PLL_INPUT_256;
break;
case 18432000:
master_rate = AD193X_PLL_INPUT_384;
break;
case 24576000:
master_rate = AD193X_PLL_INPUT_512;
break;
case 36864000:
master_rate = AD193X_PLL_INPUT_768;
break;
}
regmap_update_bits(ad193x->regmap, AD193X_PLL_CLK_CTRL0,
AD193X_PLL_INPUT_MASK, master_rate);
regmap_update_bits(ad193x->regmap, AD193X_DAC_CTRL2,
AD193X_DAC_WORD_LEN_MASK,
word_len << AD193X_DAC_WORD_LEN_SHFT);
if (ad193x_has_adc(ad193x))
regmap_update_bits(ad193x->regmap, AD193X_ADC_CTRL1,
AD193X_ADC_WORD_LEN_MASK, word_len);
return 0;
}
static int ad193x_codec_probe(struct snd_soc_codec *codec)
{
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
int num, ret;
regmap_write(ad193x->regmap, AD193X_DAC_CHNL_MUTE, 0x0);
regmap_write(ad193x->regmap, AD193X_DAC_CTRL2, 0x1A);
regmap_write(ad193x->regmap, AD193X_DAC_CTRL0, 0x40);
if (ad193x_has_adc(ad193x)) {
regmap_write(ad193x->regmap, AD193X_ADC_CTRL0, 0x3);
regmap_write(ad193x->regmap, AD193X_ADC_CTRL1, 0x43);
}
regmap_write(ad193x->regmap, AD193X_PLL_CLK_CTRL0, 0x99);
regmap_write(ad193x->regmap, AD193X_PLL_CLK_CTRL1, 0x04);
if (ad193x_has_adc(ad193x)) {
num = ARRAY_SIZE(ad193x_adc_snd_controls);
ret = snd_soc_add_codec_controls(codec,
ad193x_adc_snd_controls,
num);
if (ret)
return ret;
num = ARRAY_SIZE(ad193x_adc_widgets);
ret = snd_soc_dapm_new_controls(dapm,
ad193x_adc_widgets,
num);
if (ret)
return ret;
num = ARRAY_SIZE(ad193x_adc_audio_paths);
ret = snd_soc_dapm_add_routes(dapm,
ad193x_adc_audio_paths,
num);
if (ret)
return ret;
}
return 0;
}
int ad193x_probe(struct device *dev, struct regmap *regmap,
enum ad193x_type type)
{
struct ad193x_priv *ad193x;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ad193x = devm_kzalloc(dev, sizeof(*ad193x), GFP_KERNEL);
if (ad193x == NULL)
return -ENOMEM;
ad193x->regmap = regmap;
ad193x->type = type;
dev_set_drvdata(dev, ad193x);
return snd_soc_register_codec(dev, &soc_codec_dev_ad193x,
&ad193x_dai, 1);
}
