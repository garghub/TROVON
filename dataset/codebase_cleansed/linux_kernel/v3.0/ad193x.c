static int ad193x_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int reg;
reg = snd_soc_read(codec, AD193X_DAC_CTRL2);
reg = (mute > 0) ? reg | AD193X_DAC_MASTER_MUTE : reg &
(~AD193X_DAC_MASTER_MUTE);
snd_soc_write(codec, AD193X_DAC_CTRL2, reg);
return 0;
}
static int ad193x_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct snd_soc_codec *codec = dai->codec;
int dac_reg = snd_soc_read(codec, AD193X_DAC_CTRL1);
int adc_reg = snd_soc_read(codec, AD193X_ADC_CTRL2);
dac_reg &= ~AD193X_DAC_CHAN_MASK;
adc_reg &= ~AD193X_ADC_CHAN_MASK;
switch (slots) {
case 2:
dac_reg |= AD193X_DAC_2_CHANNELS << AD193X_DAC_CHAN_SHFT;
adc_reg |= AD193X_ADC_2_CHANNELS << AD193X_ADC_CHAN_SHFT;
break;
case 4:
dac_reg |= AD193X_DAC_4_CHANNELS << AD193X_DAC_CHAN_SHFT;
adc_reg |= AD193X_ADC_4_CHANNELS << AD193X_ADC_CHAN_SHFT;
break;
case 8:
dac_reg |= AD193X_DAC_8_CHANNELS << AD193X_DAC_CHAN_SHFT;
adc_reg |= AD193X_ADC_8_CHANNELS << AD193X_ADC_CHAN_SHFT;
break;
case 16:
dac_reg |= AD193X_DAC_16_CHANNELS << AD193X_DAC_CHAN_SHFT;
adc_reg |= AD193X_ADC_16_CHANNELS << AD193X_ADC_CHAN_SHFT;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, AD193X_DAC_CTRL1, dac_reg);
snd_soc_write(codec, AD193X_ADC_CTRL2, adc_reg);
return 0;
}
static int ad193x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
int adc_reg1, adc_reg2, dac_reg;
adc_reg1 = snd_soc_read(codec, AD193X_ADC_CTRL1);
adc_reg2 = snd_soc_read(codec, AD193X_ADC_CTRL2);
dac_reg = snd_soc_read(codec, AD193X_DAC_CTRL1);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
adc_reg1 &= ~AD193X_ADC_SERFMT_MASK;
adc_reg1 |= AD193X_ADC_SERFMT_TDM;
break;
case SND_SOC_DAIFMT_DSP_A:
adc_reg1 &= ~AD193X_ADC_SERFMT_MASK;
adc_reg1 |= AD193X_ADC_SERFMT_AUX;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
adc_reg2 &= ~AD193X_ADC_LEFT_HIGH;
adc_reg2 &= ~AD193X_ADC_BCLK_INV;
dac_reg &= ~AD193X_DAC_LEFT_HIGH;
dac_reg &= ~AD193X_DAC_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
adc_reg2 |= AD193X_ADC_LEFT_HIGH;
adc_reg2 &= ~AD193X_ADC_BCLK_INV;
dac_reg |= AD193X_DAC_LEFT_HIGH;
dac_reg &= ~AD193X_DAC_BCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
adc_reg2 &= ~AD193X_ADC_LEFT_HIGH;
adc_reg2 |= AD193X_ADC_BCLK_INV;
dac_reg &= ~AD193X_DAC_LEFT_HIGH;
dac_reg |= AD193X_DAC_BCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
adc_reg2 |= AD193X_ADC_LEFT_HIGH;
adc_reg2 |= AD193X_ADC_BCLK_INV;
dac_reg |= AD193X_DAC_LEFT_HIGH;
dac_reg |= AD193X_DAC_BCLK_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
adc_reg2 |= AD193X_ADC_LCR_MASTER;
adc_reg2 |= AD193X_ADC_BCLK_MASTER;
dac_reg |= AD193X_DAC_LCR_MASTER;
dac_reg |= AD193X_DAC_BCLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFM:
adc_reg2 |= AD193X_ADC_LCR_MASTER;
adc_reg2 &= ~AD193X_ADC_BCLK_MASTER;
dac_reg |= AD193X_DAC_LCR_MASTER;
dac_reg &= ~AD193X_DAC_BCLK_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFS:
adc_reg2 &= ~AD193X_ADC_LCR_MASTER;
adc_reg2 |= AD193X_ADC_BCLK_MASTER;
dac_reg &= ~AD193X_DAC_LCR_MASTER;
dac_reg |= AD193X_DAC_BCLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
adc_reg2 &= ~AD193X_ADC_LCR_MASTER;
adc_reg2 &= ~AD193X_ADC_BCLK_MASTER;
dac_reg &= ~AD193X_DAC_LCR_MASTER;
dac_reg &= ~AD193X_DAC_BCLK_MASTER;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, AD193X_ADC_CTRL1, adc_reg1);
snd_soc_write(codec, AD193X_ADC_CTRL2, adc_reg2);
snd_soc_write(codec, AD193X_DAC_CTRL1, dac_reg);
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
int word_len = 0, reg = 0, master_rate = 0;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
word_len = 3;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
word_len = 1;
break;
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S32_LE:
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
reg = snd_soc_read(codec, AD193X_PLL_CLK_CTRL0);
reg = (reg & AD193X_PLL_INPUT_MASK) | master_rate;
snd_soc_write(codec, AD193X_PLL_CLK_CTRL0, reg);
reg = snd_soc_read(codec, AD193X_DAC_CTRL2);
reg = (reg & (~AD193X_DAC_WORD_LEN_MASK)) | word_len;
snd_soc_write(codec, AD193X_DAC_CTRL2, reg);
reg = snd_soc_read(codec, AD193X_ADC_CTRL1);
reg = (reg & (~AD193X_ADC_WORD_LEN_MASK)) | word_len;
snd_soc_write(codec, AD193X_ADC_CTRL1, reg);
return 0;
}
static int ad193x_probe(struct snd_soc_codec *codec)
{
struct ad193x_priv *ad193x = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
if (ad193x->control_type == SND_SOC_I2C)
ret = snd_soc_codec_set_cache_io(codec, 8, 8, ad193x->control_type);
else
ret = snd_soc_codec_set_cache_io(codec, 16, 8, ad193x->control_type);
if (ret < 0) {
dev_err(codec->dev, "failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_write(codec, AD193X_DAC_CHNL_MUTE, 0x0);
snd_soc_write(codec, AD193X_DAC_CTRL2, 0x1A);
snd_soc_write(codec, AD193X_DAC_CTRL0, 0x41);
snd_soc_write(codec, AD193X_ADC_CTRL0, 0x3);
snd_soc_write(codec, AD193X_ADC_CTRL1, 0x43);
snd_soc_write(codec, AD193X_PLL_CLK_CTRL0, 0x99);
snd_soc_write(codec, AD193X_PLL_CLK_CTRL1, 0x04);
snd_soc_add_controls(codec, ad193x_snd_controls,
ARRAY_SIZE(ad193x_snd_controls));
snd_soc_dapm_new_controls(dapm, ad193x_dapm_widgets,
ARRAY_SIZE(ad193x_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_paths, ARRAY_SIZE(audio_paths));
return ret;
}
static int __devinit ad193x_spi_probe(struct spi_device *spi)
{
struct ad193x_priv *ad193x;
int ret;
ad193x = kzalloc(sizeof(struct ad193x_priv), GFP_KERNEL);
if (ad193x == NULL)
return -ENOMEM;
spi_set_drvdata(spi, ad193x);
ad193x->control_type = SND_SOC_SPI;
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_ad193x, &ad193x_dai, 1);
if (ret < 0)
kfree(ad193x);
return ret;
}
static int __devexit ad193x_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static int __devinit ad193x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad193x_priv *ad193x;
int ret;
ad193x = kzalloc(sizeof(struct ad193x_priv), GFP_KERNEL);
if (ad193x == NULL)
return -ENOMEM;
i2c_set_clientdata(client, ad193x);
ad193x->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&client->dev,
&soc_codec_dev_ad193x, &ad193x_dai, 1);
if (ret < 0)
kfree(ad193x);
return ret;
}
static int __devexit ad193x_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init ad193x_modinit(void)
{
int ret;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&ad193x_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register AD193X I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&ad193x_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register AD193X SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit ad193x_modexit(void)
{
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&ad193x_spi_driver);
#endif
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&ad193x_i2c_driver);
#endif
}
