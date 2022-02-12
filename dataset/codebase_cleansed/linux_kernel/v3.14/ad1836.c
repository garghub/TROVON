static int ad1836_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
default:
return -EINVAL;
}
return 0;
}
static int ad1836_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(dai->codec);
int word_len = 0;
switch (params_width(params)) {
case 16:
word_len = AD1836_WORD_LEN_16;
break;
case 20:
word_len = AD1836_WORD_LEN_20;
break;
case 24:
case 32:
word_len = AD1836_WORD_LEN_24;
break;
default:
return -EINVAL;
}
regmap_update_bits(ad1836->regmap, AD1836_DAC_CTRL1,
AD1836_DAC_WORD_LEN_MASK,
word_len << AD1836_DAC_WORD_LEN_OFFSET);
regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
AD1836_ADC_WORD_LEN_MASK,
word_len << AD1836_ADC_WORD_OFFSET);
return 0;
}
static int ad1836_suspend(struct snd_soc_codec *codec)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(codec);
return regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
AD1836_ADC_SERFMT_MASK, 0);
}
static int ad1836_resume(struct snd_soc_codec *codec)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(codec);
return regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
AD1836_ADC_SERFMT_MASK, AD1836_ADC_AUX);
}
static int ad1836_probe(struct snd_soc_codec *codec)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int num_dacs, num_adcs;
int ret = 0;
int i;
num_dacs = ad183x_dais[ad1836->type].playback.channels_max / 2;
num_adcs = ad183x_dais[ad1836->type].capture.channels_max / 2;
regmap_write(ad1836->regmap, AD1836_DAC_CTRL1, 0x300);
regmap_write(ad1836->regmap, AD1836_DAC_CTRL2, 0x0);
regmap_write(ad1836->regmap, AD1836_ADC_CTRL1, 0x100);
regmap_write(ad1836->regmap, AD1836_ADC_CTRL2, 0x180);
for (i = 1; i <= num_dacs; ++i) {
regmap_write(ad1836->regmap, AD1836_DAC_L_VOL(i), 0x3FF);
regmap_write(ad1836->regmap, AD1836_DAC_R_VOL(i), 0x3FF);
}
if (ad1836->type == AD1836) {
regmap_write(ad1836->regmap, AD1836_ADC_CTRL3, 0x3A);
ret = snd_soc_add_codec_controls(codec, ad1836_controls,
ARRAY_SIZE(ad1836_controls));
if (ret)
return ret;
} else {
regmap_write(ad1836->regmap, AD1836_ADC_CTRL3, 0x00);
}
ret = snd_soc_add_codec_controls(codec, ad183x_dac_controls, num_dacs * 2);
if (ret)
return ret;
ret = snd_soc_add_codec_controls(codec, ad183x_adc_controls, num_adcs);
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(dapm, ad183x_dac_dapm_widgets, num_dacs);
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(dapm, ad183x_adc_dapm_widgets, num_adcs);
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, ad183x_dac_routes, num_dacs);
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, ad183x_adc_routes, num_adcs);
if (ret)
return ret;
return ret;
}
static int ad1836_remove(struct snd_soc_codec *codec)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(codec);
return regmap_update_bits(ad1836->regmap, AD1836_ADC_CTRL2,
AD1836_ADC_SERFMT_MASK, 0);
}
static int ad1836_spi_probe(struct spi_device *spi)
{
struct ad1836_priv *ad1836;
int ret;
ad1836 = devm_kzalloc(&spi->dev, sizeof(struct ad1836_priv),
GFP_KERNEL);
if (ad1836 == NULL)
return -ENOMEM;
ad1836->regmap = devm_regmap_init_spi(spi, &ad1836_regmap_config);
if (IS_ERR(ad1836->regmap))
return PTR_ERR(ad1836->regmap);
ad1836->type = spi_get_device_id(spi)->driver_data;
spi_set_drvdata(spi, ad1836);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_ad1836, &ad183x_dais[ad1836->type], 1);
return ret;
}
static int ad1836_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
