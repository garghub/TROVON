static int ak4104_fill_cache(struct snd_soc_codec *codec)
{
int i;
u8 *reg_cache = codec->reg_cache;
struct spi_device *spi = codec->control_data;
for (i = 0; i < codec->driver->reg_cache_size; i++) {
int ret = spi_w8r8(spi, i | AK4104_READ);
if (ret < 0) {
dev_err(&spi->dev, "SPI write failure\n");
return ret;
}
reg_cache[i] = ret;
}
return 0;
}
static unsigned int ak4104_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u8 *reg_cache = codec->reg_cache;
if (reg >= codec->driver->reg_cache_size)
return -EINVAL;
return reg_cache[reg];
}
static int ak4104_spi_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 *cache = codec->reg_cache;
struct spi_device *spi = codec->control_data;
if (reg >= codec->driver->reg_cache_size)
return -EINVAL;
if (cache[reg] != value) {
u8 tmp[2] = { (reg & AK4104_REG_MASK) | AK4104_WRITE, value };
if (spi_write(spi, tmp, sizeof(tmp))) {
dev_err(&spi->dev, "SPI write failed\n");
return -EIO;
}
cache[reg] = value;
}
return 0;
}
static int ak4104_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
int val = 0;
val = ak4104_read_reg_cache(codec, AK4104_REG_CONTROL1);
if (val < 0)
return val;
val &= ~(AK4104_CONTROL1_DIF0 | AK4104_CONTROL1_DIF1);
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
return ak4104_spi_write(codec, AK4104_REG_CONTROL1, val);
}
static int ak4104_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
int val = 0;
val |= IEC958_AES0_CON_NOT_COPYRIGHT;
ak4104_spi_write(codec, AK4104_REG_CHN_STATUS(0), val);
val = 0;
switch (params_rate(params)) {
case 44100:
val |= IEC958_AES3_CON_FS_44100;
break;
case 48000:
val |= IEC958_AES3_CON_FS_48000;
break;
case 32000:
val |= IEC958_AES3_CON_FS_32000;
break;
default:
dev_err(codec->dev, "unsupported sampling rate\n");
return -EINVAL;
}
return ak4104_spi_write(codec, AK4104_REG_CHN_STATUS(3), val);
}
static int ak4104_probe(struct snd_soc_codec *codec)
{
struct ak4104_private *ak4104 = snd_soc_codec_get_drvdata(codec);
int ret, val;
codec->control_data = ak4104->control_data;
ret = ak4104_fill_cache(codec);
if (ret < 0) {
dev_err(codec->dev, "failed to fill register cache\n");
return ret;
}
if (ak4104_read_reg_cache(codec, AK4104_REG_RESERVED) !=
AK4104_RESERVED_VAL)
return -ENODEV;
val = ak4104_read_reg_cache(codec, AK4104_REG_CONTROL1);
val |= AK4104_CONTROL1_PW | AK4104_CONTROL1_RSTN;
ret = ak4104_spi_write(codec, AK4104_REG_CONTROL1, val);
if (ret < 0)
return ret;
val = ak4104_read_reg_cache(codec, AK4104_REG_TX);
val |= AK4104_TX_TXE;
ret = ak4104_spi_write(codec, AK4104_REG_TX, val);
if (ret < 0)
return ret;
dev_info(codec->dev, "SPI device initialized\n");
return 0;
}
static int ak4104_remove(struct snd_soc_codec *codec)
{
int val, ret;
val = ak4104_read_reg_cache(codec, AK4104_REG_CONTROL1);
if (val < 0)
return val;
val &= ~(AK4104_CONTROL1_PW | AK4104_CONTROL1_RSTN);
ret = ak4104_spi_write(codec, AK4104_REG_CONTROL1, val);
return ret;
}
static int ak4104_spi_probe(struct spi_device *spi)
{
struct ak4104_private *ak4104;
int ret;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_0;
ret = spi_setup(spi);
if (ret < 0)
return ret;
ak4104 = kzalloc(sizeof(struct ak4104_private), GFP_KERNEL);
if (ak4104 == NULL)
return -ENOMEM;
ak4104->control_data = spi;
ak4104->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, ak4104);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_device_ak4104, &ak4104_dai, 1);
if (ret < 0)
kfree(ak4104);
return ret;
}
static int __devexit ak4104_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static int __init ak4104_init(void)
{
return spi_register_driver(&ak4104_spi_driver);
}
static void __exit ak4104_exit(void)
{
spi_unregister_driver(&ak4104_spi_driver);
}
