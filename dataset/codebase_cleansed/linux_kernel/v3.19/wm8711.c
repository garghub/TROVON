static bool wm8711_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8711_RESET:
return true;
default:
return false;
}
}
static inline int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
return 0;
}
static int wm8711_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8711_priv *wm8711 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8711_IFACE) & 0xfff3;
int i = get_coeff(wm8711->sysclk, params_rate(params));
u16 srate = (coeff_div[i].sr << 2) |
(coeff_div[i].bosr << 1) | coeff_div[i].usb;
snd_soc_write(codec, WM8711_SRATE, srate);
switch (params_width(params)) {
case 16:
break;
case 20:
iface |= 0x0004;
break;
case 24:
iface |= 0x0008;
break;
}
snd_soc_write(codec, WM8711_IFACE, iface);
return 0;
}
static int wm8711_pcm_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
snd_soc_write(codec, WM8711_ACTIVE, 0x0001);
return 0;
}
static void wm8711_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
if (!snd_soc_codec_is_active(codec)) {
udelay(50);
snd_soc_write(codec, WM8711_ACTIVE, 0x0);
}
}
static int wm8711_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8711_APDIGI) & 0xfff7;
if (mute)
snd_soc_write(codec, WM8711_APDIGI, mute_reg | 0x8);
else
snd_soc_write(codec, WM8711_APDIGI, mute_reg);
return 0;
}
static int wm8711_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8711_priv *wm8711 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 16934400:
case 18432000:
wm8711->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8711_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8711_IFACE) & 0x000c;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface |= 0x0040;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x0003;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x0013;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0090;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0080;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0010;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8711_IFACE, iface);
return 0;
}
static int wm8711_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8711_priv *wm8711 = snd_soc_codec_get_drvdata(codec);
u16 reg = snd_soc_read(codec, WM8711_PWR) & 0xff7f;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_write(codec, WM8711_PWR, reg);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
regcache_sync(wm8711->regmap);
snd_soc_write(codec, WM8711_PWR, reg | 0x0040);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8711_ACTIVE, 0x0);
snd_soc_write(codec, WM8711_PWR, 0xffff);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8711_probe(struct snd_soc_codec *codec)
{
int ret;
ret = wm8711_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
snd_soc_update_bits(codec, WM8711_LOUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8711_ROUT1V, 0x0100, 0x0100);
return ret;
}
static int wm8711_spi_probe(struct spi_device *spi)
{
struct wm8711_priv *wm8711;
int ret;
wm8711 = devm_kzalloc(&spi->dev, sizeof(struct wm8711_priv),
GFP_KERNEL);
if (wm8711 == NULL)
return -ENOMEM;
wm8711->regmap = devm_regmap_init_spi(spi, &wm8711_regmap);
if (IS_ERR(wm8711->regmap))
return PTR_ERR(wm8711->regmap);
spi_set_drvdata(spi, wm8711);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8711, &wm8711_dai, 1);
return ret;
}
static int wm8711_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8711_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wm8711_priv *wm8711;
int ret;
wm8711 = devm_kzalloc(&client->dev, sizeof(struct wm8711_priv),
GFP_KERNEL);
if (wm8711 == NULL)
return -ENOMEM;
wm8711->regmap = devm_regmap_init_i2c(client, &wm8711_regmap);
if (IS_ERR(wm8711->regmap))
return PTR_ERR(wm8711->regmap);
i2c_set_clientdata(client, wm8711);
ret = snd_soc_register_codec(&client->dev,
&soc_codec_dev_wm8711, &wm8711_dai, 1);
return ret;
}
static int wm8711_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8711_modinit(void)
{
int ret;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8711_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8711 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8711_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8711 SPI driver: %d\n",
ret);
}
#endif
return 0;
}
static void __exit wm8711_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8711_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8711_spi_driver);
#endif
}
