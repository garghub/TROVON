static void pll_factors(unsigned int target, unsigned int source)
{
unsigned long long Kpart;
unsigned int K, Ndiv, Nmod;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
pll_div.pre_div = 1;
Ndiv = target / source;
} else
pll_div.pre_div = 0;
if ((Ndiv < 6) || (Ndiv > 12))
printk(KERN_WARNING
"WM8510 N value %u outwith recommended range!d\n",
Ndiv);
pll_div.n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div.k = K;
}
static int wm8510_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
if (freq_in == 0 || freq_out == 0) {
reg = snd_soc_read(codec, WM8510_CLOCK);
snd_soc_write(codec, WM8510_CLOCK, reg & 0x0ff);
reg = snd_soc_read(codec, WM8510_POWER1);
snd_soc_write(codec, WM8510_POWER1, reg & 0x1df);
return 0;
}
pll_factors(freq_out*4, freq_in);
snd_soc_write(codec, WM8510_PLLN, (pll_div.pre_div << 4) | pll_div.n);
snd_soc_write(codec, WM8510_PLLK1, pll_div.k >> 18);
snd_soc_write(codec, WM8510_PLLK2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8510_PLLK3, pll_div.k & 0x1ff);
reg = snd_soc_read(codec, WM8510_POWER1);
snd_soc_write(codec, WM8510_POWER1, reg | 0x020);
reg = snd_soc_read(codec, WM8510_CLOCK);
snd_soc_write(codec, WM8510_CLOCK, reg | 0x100);
return 0;
}
static int wm8510_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8510_OPCLKDIV:
reg = snd_soc_read(codec, WM8510_GPIO) & 0x1cf;
snd_soc_write(codec, WM8510_GPIO, reg | div);
break;
case WM8510_MCLKDIV:
reg = snd_soc_read(codec, WM8510_CLOCK) & 0x11f;
snd_soc_write(codec, WM8510_CLOCK, reg | div);
break;
case WM8510_ADCCLK:
reg = snd_soc_read(codec, WM8510_ADC) & 0x1f7;
snd_soc_write(codec, WM8510_ADC, reg | div);
break;
case WM8510_DACCLK:
reg = snd_soc_read(codec, WM8510_DAC) & 0x1f7;
snd_soc_write(codec, WM8510_DAC, reg | div);
break;
case WM8510_BCLKDIV:
reg = snd_soc_read(codec, WM8510_CLOCK) & 0x1e3;
snd_soc_write(codec, WM8510_CLOCK, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8510_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
u16 clk = snd_soc_read(codec, WM8510_CLOCK) & 0x1fe;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
clk |= 0x0001;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0010;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0008;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x00018;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0180;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0100;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0080;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8510_IFACE, iface);
snd_soc_write(codec, WM8510_CLOCK, clk);
return 0;
}
static int wm8510_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
u16 iface = snd_soc_read(codec, WM8510_IFACE) & 0x19f;
u16 adn = snd_soc_read(codec, WM8510_ADD) & 0x1f1;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= 0x0020;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= 0x0040;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= 0x0060;
break;
}
switch (params_rate(params)) {
case 8000:
adn |= 0x5 << 1;
break;
case 11025:
adn |= 0x4 << 1;
break;
case 16000:
adn |= 0x3 << 1;
break;
case 22050:
adn |= 0x2 << 1;
break;
case 32000:
adn |= 0x1 << 1;
break;
case 44100:
case 48000:
break;
}
snd_soc_write(codec, WM8510_IFACE, iface);
snd_soc_write(codec, WM8510_ADD, adn);
return 0;
}
static int wm8510_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8510_DAC) & 0xffbf;
if (mute)
snd_soc_write(codec, WM8510_DAC, mute_reg | 0x40);
else
snd_soc_write(codec, WM8510_DAC, mute_reg);
return 0;
}
static int wm8510_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 power1 = snd_soc_read(codec, WM8510_POWER1) & ~0x3;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
power1 |= 0x1;
snd_soc_write(codec, WM8510_POWER1, power1);
break;
case SND_SOC_BIAS_STANDBY:
power1 |= WM8510_POWER1_BIASEN | WM8510_POWER1_BUFIOEN;
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_cache_sync(codec);
snd_soc_write(codec, WM8510_POWER1, power1 | 0x3);
mdelay(100);
}
power1 |= 0x2;
snd_soc_write(codec, WM8510_POWER1, power1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8510_POWER1, 0);
snd_soc_write(codec, WM8510_POWER2, 0);
snd_soc_write(codec, WM8510_POWER3, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8510_suspend(struct snd_soc_codec *codec)
{
wm8510_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8510_resume(struct snd_soc_codec *codec)
{
wm8510_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8510_probe(struct snd_soc_codec *codec)
{
struct wm8510_priv *wm8510 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, wm8510->control_type);
if (ret < 0) {
printk(KERN_ERR "wm8510: failed to set cache I/O: %d\n", ret);
return ret;
}
wm8510_reset(codec);
wm8510_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return ret;
}
static int wm8510_remove(struct snd_soc_codec *codec)
{
struct wm8510_priv *wm8510 = snd_soc_codec_get_drvdata(codec);
wm8510_set_bias_level(codec, SND_SOC_BIAS_OFF);
kfree(wm8510);
return 0;
}
static int __devinit wm8510_spi_probe(struct spi_device *spi)
{
struct wm8510_priv *wm8510;
int ret;
wm8510 = kzalloc(sizeof(struct wm8510_priv), GFP_KERNEL);
if (wm8510 == NULL)
return -ENOMEM;
wm8510->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, wm8510);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8510, &wm8510_dai, 1);
if (ret < 0)
kfree(wm8510);
return ret;
}
static int __devexit wm8510_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static __devinit int wm8510_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8510_priv *wm8510;
int ret;
wm8510 = kzalloc(sizeof(struct wm8510_priv), GFP_KERNEL);
if (wm8510 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8510);
wm8510->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8510, &wm8510_dai, 1);
if (ret < 0)
kfree(wm8510);
return ret;
}
static __devexit int wm8510_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8510_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8510_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8510 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8510_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8510 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8510_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8510_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8510_spi_driver);
#endif
}
