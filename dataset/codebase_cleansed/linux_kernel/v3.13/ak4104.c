static int ak4104_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4104_private *ak4104 = snd_soc_codec_get_drvdata(codec);
int val = 0;
int ret;
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
val |= AK4104_CONTROL1_DIF0;
break;
case SND_SOC_DAIFMT_I2S:
val |= AK4104_CONTROL1_DIF0 | AK4104_CONTROL1_DIF1;
break;
default:
dev_err(codec->dev, "invalid dai format\n");
return -EINVAL;
}
if ((format & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
return -EINVAL;
ret = regmap_update_bits(ak4104->regmap, AK4104_REG_CONTROL1,
AK4104_CONTROL1_DIF0 | AK4104_CONTROL1_DIF1,
val);
if (ret < 0)
return ret;
return 0;
}
static int ak4104_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4104_private *ak4104 = snd_soc_codec_get_drvdata(codec);
int ret, val = 0;
val |= IEC958_AES0_CON_NOT_COPYRIGHT;
regmap_write(ak4104->regmap, AK4104_REG_CHN_STATUS(0), val);
val = 0;
switch (params_rate(params)) {
case 22050:
val |= IEC958_AES3_CON_FS_22050;
break;
case 24000:
val |= IEC958_AES3_CON_FS_24000;
break;
case 32000:
val |= IEC958_AES3_CON_FS_32000;
break;
case 44100:
val |= IEC958_AES3_CON_FS_44100;
break;
case 48000:
val |= IEC958_AES3_CON_FS_48000;
break;
case 88200:
val |= IEC958_AES3_CON_FS_88200;
break;
case 96000:
val |= IEC958_AES3_CON_FS_96000;
break;
case 176400:
val |= IEC958_AES3_CON_FS_176400;
break;
case 192000:
val |= IEC958_AES3_CON_FS_192000;
break;
default:
dev_err(codec->dev, "unsupported sampling rate\n");
return -EINVAL;
}
ret = regmap_write(ak4104->regmap, AK4104_REG_CHN_STATUS(3), val);
if (ret < 0)
return ret;
return 0;
}
static int ak4104_probe(struct snd_soc_codec *codec)
{
struct ak4104_private *ak4104 = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = ak4104->regmap;
ret = regmap_update_bits(ak4104->regmap, AK4104_REG_CONTROL1,
AK4104_CONTROL1_PW | AK4104_CONTROL1_RSTN,
AK4104_CONTROL1_PW | AK4104_CONTROL1_RSTN);
if (ret < 0)
return ret;
ret = regmap_update_bits(ak4104->regmap, AK4104_REG_TX,
AK4104_TX_TXE, AK4104_TX_TXE);
if (ret < 0)
return ret;
return 0;
}
static int ak4104_remove(struct snd_soc_codec *codec)
{
struct ak4104_private *ak4104 = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(ak4104->regmap, AK4104_REG_CONTROL1,
AK4104_CONTROL1_PW | AK4104_CONTROL1_RSTN, 0);
return 0;
}
static int ak4104_spi_probe(struct spi_device *spi)
{
struct device_node *np = spi->dev.of_node;
struct ak4104_private *ak4104;
unsigned int val;
int ret;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_0;
ret = spi_setup(spi);
if (ret < 0)
return ret;
ak4104 = devm_kzalloc(&spi->dev, sizeof(struct ak4104_private),
GFP_KERNEL);
if (ak4104 == NULL)
return -ENOMEM;
ak4104->regmap = devm_regmap_init_spi(spi, &ak4104_regmap);
if (IS_ERR(ak4104->regmap)) {
ret = PTR_ERR(ak4104->regmap);
return ret;
}
if (np) {
enum of_gpio_flags flags;
int gpio = of_get_named_gpio_flags(np, "reset-gpio", 0, &flags);
if (gpio_is_valid(gpio)) {
ret = devm_gpio_request_one(&spi->dev, gpio,
flags & OF_GPIO_ACTIVE_LOW ?
GPIOF_OUT_INIT_LOW : GPIOF_OUT_INIT_HIGH,
"ak4104 reset");
if (ret < 0)
return ret;
}
}
ret = regmap_read(ak4104->regmap, AK4104_REG_RESERVED, &val);
if (ret != 0)
return ret;
if (val != AK4104_RESERVED_VAL)
return -ENODEV;
spi_set_drvdata(spi, ak4104);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_device_ak4104, &ak4104_dai, 1);
return ret;
}
static int ak4104_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
