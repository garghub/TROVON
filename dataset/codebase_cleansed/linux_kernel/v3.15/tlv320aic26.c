static int aic26_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct aic26 *aic26 = snd_soc_codec_get_drvdata(codec);
int fsref, divisor, wlen, pval, jval, dval, qval;
u16 reg;
dev_dbg(&aic26->spi->dev, "aic26_hw_params(substream=%p, params=%p)\n",
substream, params);
dev_dbg(&aic26->spi->dev, "rate=%i format=%i\n", params_rate(params),
params_format(params));
switch (params_rate(params)) {
case 8000: fsref = 48000; divisor = AIC26_DIV_6; break;
case 11025: fsref = 44100; divisor = AIC26_DIV_4; break;
case 12000: fsref = 48000; divisor = AIC26_DIV_4; break;
case 16000: fsref = 48000; divisor = AIC26_DIV_3; break;
case 22050: fsref = 44100; divisor = AIC26_DIV_2; break;
case 24000: fsref = 48000; divisor = AIC26_DIV_2; break;
case 32000: fsref = 48000; divisor = AIC26_DIV_1_5; break;
case 44100: fsref = 44100; divisor = AIC26_DIV_1; break;
case 48000: fsref = 48000; divisor = AIC26_DIV_1; break;
default:
dev_dbg(&aic26->spi->dev, "bad rate\n"); return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8: wlen = AIC26_WLEN_16; break;
case SNDRV_PCM_FORMAT_S16_BE: wlen = AIC26_WLEN_16; break;
case SNDRV_PCM_FORMAT_S24_BE: wlen = AIC26_WLEN_24; break;
case SNDRV_PCM_FORMAT_S32_BE: wlen = AIC26_WLEN_32; break;
default:
dev_dbg(&aic26->spi->dev, "bad format\n"); return -EINVAL;
}
pval = 1;
jval = fsref / (aic26->mclk / 2048);
dval = fsref - (jval * (aic26->mclk / 2048));
dval = (10000 * dval) / (aic26->mclk / 2048);
dev_dbg(&aic26->spi->dev, "Setting PLLM to %d.%04d\n", jval, dval);
qval = 0;
reg = 0x8000 | qval << 11 | pval << 8 | jval << 2;
snd_soc_write(codec, AIC26_REG_PLL_PROG1, reg);
reg = dval << 2;
snd_soc_write(codec, AIC26_REG_PLL_PROG2, reg);
if (aic26->master)
reg = 0x0800;
if (fsref == 48000)
reg = 0x2000;
snd_soc_update_bits(codec, AIC26_REG_AUDIO_CTRL3, 0xf800, reg);
reg = wlen | aic26->datfm | (divisor << 3) | divisor;
snd_soc_update_bits(codec, AIC26_REG_AUDIO_CTRL1, 0xfff, reg);
return 0;
}
static int aic26_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct aic26 *aic26 = snd_soc_codec_get_drvdata(codec);
u16 reg;
dev_dbg(&aic26->spi->dev, "aic26_mute(dai=%p, mute=%i)\n",
dai, mute);
if (mute)
reg = 0x8080;
else
reg = 0;
snd_soc_update_bits(codec, AIC26_REG_DAC_GAIN, 0x8000, reg);
return 0;
}
static int aic26_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic26 *aic26 = snd_soc_codec_get_drvdata(codec);
dev_dbg(&aic26->spi->dev, "aic26_set_sysclk(dai=%p, clk_id==%i,"
" freq=%i, dir=%i)\n",
codec_dai, clk_id, freq, dir);
if ((freq < 2000000) || (freq > 50000000))
return -EINVAL;
aic26->mclk = freq;
return 0;
}
static int aic26_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic26 *aic26 = snd_soc_codec_get_drvdata(codec);
dev_dbg(&aic26->spi->dev, "aic26_set_fmt(dai=%p, fmt==%i)\n",
codec_dai, fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM: aic26->master = 1; break;
case SND_SOC_DAIFMT_CBS_CFS: aic26->master = 0; break;
default:
dev_dbg(&aic26->spi->dev, "bad master\n"); return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S: aic26->datfm = AIC26_DATFM_I2S; break;
case SND_SOC_DAIFMT_DSP_A: aic26->datfm = AIC26_DATFM_DSP; break;
case SND_SOC_DAIFMT_RIGHT_J: aic26->datfm = AIC26_DATFM_RIGHTJ; break;
case SND_SOC_DAIFMT_LEFT_J: aic26->datfm = AIC26_DATFM_LEFTJ; break;
default:
dev_dbg(&aic26->spi->dev, "bad format\n"); return -EINVAL;
}
return 0;
}
static ssize_t aic26_keyclick_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct aic26 *aic26 = dev_get_drvdata(dev);
int val, amp, freq, len;
val = snd_soc_read(aic26->codec, AIC26_REG_AUDIO_CTRL2);
amp = (val >> 12) & 0x7;
freq = (125 << ((val >> 8) & 0x7)) >> 1;
len = 2 * (1 + ((val >> 4) & 0xf));
return sprintf(buf, "amp=%x freq=%iHz len=%iclks\n", amp, freq, len);
}
static ssize_t aic26_keyclick_set(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct aic26 *aic26 = dev_get_drvdata(dev);
snd_soc_update_bits(aic26->codec, AIC26_REG_AUDIO_CTRL2,
0x8000, 0x800);
return count;
}
static int aic26_probe(struct snd_soc_codec *codec)
{
struct aic26 *aic26 = dev_get_drvdata(codec->dev);
int ret, reg;
aic26->codec = codec;
snd_soc_write(codec, AIC26_REG_RESET, 0xBB00);
snd_soc_write(codec, AIC26_REG_POWER_CTRL, 0);
reg = snd_soc_read(codec, AIC26_REG_AUDIO_CTRL3);
reg &= ~0xf800;
reg |= 0x0800;
snd_soc_write(codec, AIC26_REG_AUDIO_CTRL3, reg);
ret = device_create_file(codec->dev, &dev_attr_keyclick);
if (ret)
dev_info(codec->dev, "error creating sysfs files\n");
return 0;
}
static int aic26_spi_probe(struct spi_device *spi)
{
struct aic26 *aic26;
int ret;
dev_dbg(&spi->dev, "probing tlv320aic26 spi device\n");
aic26 = devm_kzalloc(&spi->dev, sizeof *aic26, GFP_KERNEL);
if (!aic26)
return -ENOMEM;
aic26->regmap = devm_regmap_init_spi(spi, &aic26_regmap);
if (IS_ERR(aic26->regmap))
return PTR_ERR(aic26->regmap);
aic26->spi = spi;
dev_set_drvdata(&spi->dev, aic26);
aic26->master = 1;
ret = snd_soc_register_codec(&spi->dev,
&aic26_soc_codec_dev, &aic26_dai, 1);
return ret;
}
static int aic26_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
