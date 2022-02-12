static bool wm8988_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8988_LINVOL:
case WM8988_RINVOL:
case WM8988_LOUT1V:
case WM8988_ROUT1V:
case WM8988_ADCDAC:
case WM8988_IFACE:
case WM8988_SRATE:
case WM8988_LDAC:
case WM8988_RDAC:
case WM8988_BASS:
case WM8988_TREBLE:
case WM8988_RESET:
case WM8988_3D:
case WM8988_ALC1:
case WM8988_ALC2:
case WM8988_ALC3:
case WM8988_NGATE:
case WM8988_LADC:
case WM8988_RADC:
case WM8988_ADCTL1:
case WM8988_ADCTL2:
case WM8988_PWR1:
case WM8988_PWR2:
case WM8988_ADCTL3:
case WM8988_ADCIN:
case WM8988_LADCIN:
case WM8988_RADCIN:
case WM8988_LOUTM1:
case WM8988_LOUTM2:
case WM8988_ROUTM1:
case WM8988_ROUTM2:
case WM8988_LOUT2V:
case WM8988_ROUT2V:
case WM8988_LPPB:
return true;
default:
return false;
}
}
static int wm8988_lrc_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
u16 adctl2 = snd_soc_read(codec, WM8988_ADCTL2);
if (snd_soc_read(codec, WM8988_PWR2) & 0x180)
adctl2 &= ~0x4;
else
adctl2 |= 0x4;
return snd_soc_write(codec, WM8988_ADCTL2, adctl2);
}
static inline int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
return -EINVAL;
}
static int wm8988_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 18432000:
case 22579200:
case 36864000:
wm8988->sysclk_constraints = &constraints_112896;
wm8988->sysclk = freq;
return 0;
case 12288000:
case 16934400:
case 24576000:
case 33868800:
wm8988->sysclk_constraints = &constraints_12288;
wm8988->sysclk = freq;
return 0;
case 12000000:
case 24000000:
wm8988->sysclk_constraints = &constraints_12;
wm8988->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8988_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface = 0x0040;
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
snd_soc_write(codec, WM8988_IFACE, iface);
return 0;
}
static int wm8988_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
if (!wm8988->sysclk) {
dev_err(codec->dev,
"No MCLK configured, call set_sysclk() on init\n");
return -EINVAL;
}
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
wm8988->sysclk_constraints);
return 0;
}
static int wm8988_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8988_IFACE) & 0x1f3;
u16 srate = snd_soc_read(codec, WM8988_SRATE) & 0x180;
int coeff;
coeff = get_coeff(wm8988->sysclk, params_rate(params));
if (coeff < 0) {
coeff = get_coeff(wm8988->sysclk / 2, params_rate(params));
srate |= 0x40;
}
if (coeff < 0) {
dev_err(codec->dev,
"Unable to configure sample rate %dHz with %dHz MCLK\n",
params_rate(params), wm8988->sysclk);
return coeff;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= 0x0004;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= 0x0008;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= 0x000c;
break;
}
snd_soc_write(codec, WM8988_IFACE, iface);
if (coeff >= 0)
snd_soc_write(codec, WM8988_SRATE, srate |
(coeff_div[coeff].sr << 1) | coeff_div[coeff].usb);
return 0;
}
static int wm8988_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8988_ADCDAC) & 0xfff7;
if (mute)
snd_soc_write(codec, WM8988_ADCDAC, mute_reg | 0x8);
else
snd_soc_write(codec, WM8988_ADCDAC, mute_reg);
return 0;
}
static int wm8988_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
u16 pwr_reg = snd_soc_read(codec, WM8988_PWR1) & ~0x1c1;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_write(codec, WM8988_PWR1, pwr_reg | 0x00c0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_sync(wm8988->regmap);
snd_soc_write(codec, WM8988_PWR1, pwr_reg | 0x1c1);
msleep(100);
}
snd_soc_write(codec, WM8988_PWR1, pwr_reg | 0x0141);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8988_PWR1, 0x0000);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8988_suspend(struct snd_soc_codec *codec)
{
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
wm8988_set_bias_level(codec, SND_SOC_BIAS_OFF);
regcache_mark_dirty(wm8988->regmap);
return 0;
}
static int wm8988_resume(struct snd_soc_codec *codec)
{
wm8988_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8988_probe(struct snd_soc_codec *codec)
{
struct wm8988_priv *wm8988 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
codec->control_data = wm8988->regmap;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = wm8988_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
snd_soc_update_bits(codec, WM8988_RADC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8988_RDAC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8988_ROUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8988_ROUT2V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8988_RINVOL, 0x0100, 0x0100);
wm8988_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8988_remove(struct snd_soc_codec *codec)
{
wm8988_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int __devinit wm8988_spi_probe(struct spi_device *spi)
{
struct wm8988_priv *wm8988;
int ret;
wm8988 = devm_kzalloc(&spi->dev, sizeof(struct wm8988_priv),
GFP_KERNEL);
if (wm8988 == NULL)
return -ENOMEM;
wm8988->regmap = regmap_init_spi(spi, &wm8988_regmap);
if (IS_ERR(wm8988->regmap)) {
ret = PTR_ERR(wm8988->regmap);
dev_err(&spi->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
spi_set_drvdata(spi, wm8988);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8988, &wm8988_dai, 1);
if (ret != 0)
regmap_exit(wm8988->regmap);
return ret;
}
static int __devexit wm8988_spi_remove(struct spi_device *spi)
{
struct wm8988_priv *wm8988 = spi_get_drvdata(spi);
snd_soc_unregister_codec(&spi->dev);
regmap_exit(wm8988->regmap);
return 0;
}
static __devinit int wm8988_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8988_priv *wm8988;
int ret;
wm8988 = devm_kzalloc(&i2c->dev, sizeof(struct wm8988_priv),
GFP_KERNEL);
if (wm8988 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8988);
wm8988->regmap = regmap_init_i2c(i2c, &wm8988_regmap);
if (IS_ERR(wm8988->regmap)) {
ret = PTR_ERR(wm8988->regmap);
dev_err(&i2c->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8988, &wm8988_dai, 1);
if (ret != 0)
regmap_exit(wm8988->regmap);
return ret;
}
static __devexit int wm8988_i2c_remove(struct i2c_client *client)
{
struct wm8988_priv *wm8988 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regmap_exit(wm8988->regmap);
return 0;
}
static int __init wm8988_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8988_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8988 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8988_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8988 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8988_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8988_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8988_spi_driver);
#endif
}
