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
int word_len = 0;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
word_len = AD1836_WORD_LEN_16;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
word_len = AD1836_WORD_LEN_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S32_LE:
word_len = AD1836_WORD_LEN_24;
break;
}
snd_soc_update_bits(codec, AD1836_DAC_CTRL1, AD1836_DAC_WORD_LEN_MASK,
word_len << AD1836_DAC_WORD_LEN_OFFSET);
snd_soc_update_bits(codec, AD1836_ADC_CTRL2, AD1836_ADC_WORD_LEN_MASK,
word_len << AD1836_ADC_WORD_OFFSET);
return 0;
}
static int ad1836_soc_suspend(struct snd_soc_codec *codec,
pm_message_t state)
{
u16 adc_ctrl2 = snd_soc_read(codec, AD1836_ADC_CTRL2);
adc_ctrl2 &= ~AD1836_ADC_SERFMT_MASK;
return snd_soc_write(codec, AD1836_ADC_CTRL2, adc_ctrl2);
}
static int ad1836_soc_resume(struct snd_soc_codec *codec)
{
u16 adc_ctrl2 = snd_soc_read(codec, AD1836_ADC_CTRL2);
adc_ctrl2 |= AD1836_ADC_AUX;
return snd_soc_write(codec, AD1836_ADC_CTRL2, adc_ctrl2);
}
static int ad1836_probe(struct snd_soc_codec *codec)
{
struct ad1836_priv *ad1836 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret = 0;
codec->control_data = ad1836->control_data;
ret = snd_soc_codec_set_cache_io(codec, 4, 12, SND_SOC_SPI);
if (ret < 0) {
dev_err(codec->dev, "failed to set cache I/O: %d\n",
ret);
return ret;
}
snd_soc_write(codec, AD1836_DAC_CTRL1, 0x300);
snd_soc_write(codec, AD1836_DAC_CTRL2, 0x0);
snd_soc_write(codec, AD1836_ADC_CTRL1, 0x100);
snd_soc_write(codec, AD1836_ADC_CTRL2, 0x180);
snd_soc_write(codec, AD1836_ADC_CTRL3, 0x3A);
snd_soc_write(codec, AD1836_DAC_L1_VOL, 0x3FF);
snd_soc_write(codec, AD1836_DAC_R1_VOL, 0x3FF);
snd_soc_write(codec, AD1836_DAC_L2_VOL, 0x3FF);
snd_soc_write(codec, AD1836_DAC_R2_VOL, 0x3FF);
snd_soc_write(codec, AD1836_DAC_L3_VOL, 0x3FF);
snd_soc_write(codec, AD1836_DAC_R3_VOL, 0x3FF);
snd_soc_add_controls(codec, ad1836_snd_controls,
ARRAY_SIZE(ad1836_snd_controls));
snd_soc_dapm_new_controls(dapm, ad1836_dapm_widgets,
ARRAY_SIZE(ad1836_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_paths, ARRAY_SIZE(audio_paths));
return ret;
}
static int ad1836_remove(struct snd_soc_codec *codec)
{
u16 adc_ctrl2 = snd_soc_read(codec, AD1836_ADC_CTRL2);
adc_ctrl2 &= ~AD1836_ADC_SERFMT_MASK;
return snd_soc_write(codec, AD1836_ADC_CTRL2, adc_ctrl2);
}
static int __devinit ad1836_spi_probe(struct spi_device *spi)
{
struct ad1836_priv *ad1836;
int ret;
ad1836 = kzalloc(sizeof(struct ad1836_priv), GFP_KERNEL);
if (ad1836 == NULL)
return -ENOMEM;
spi_set_drvdata(spi, ad1836);
ad1836->control_data = spi;
ad1836->control_type = SND_SOC_SPI;
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_ad1836, &ad1836_dai, 1);
if (ret < 0)
kfree(ad1836);
return ret;
}
static int __devexit ad1836_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static int __init ad1836_init(void)
{
int ret;
ret = spi_register_driver(&ad1836_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register ad1836 SPI driver: %d\n",
ret);
}
return ret;
}
static void __exit ad1836_exit(void)
{
spi_unregister_driver(&ad1836_spi_driver);
}
