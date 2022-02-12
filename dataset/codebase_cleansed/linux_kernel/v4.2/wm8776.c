static bool wm8776_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8776_RESET:
return true;
default:
return false;
}
}
static int wm8776_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8776_RESET, 0);
}
static int wm8776_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int reg, iface, master;
switch (dai->driver->id) {
case WM8776_DAI_DAC:
reg = WM8776_DACIFCTRL;
master = 0x80;
break;
case WM8776_DAI_ADC:
reg = WM8776_ADCIFCTRL;
master = 0x100;
break;
default:
return -EINVAL;
}
iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFS:
master = 0;
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
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x00c;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x008;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x004;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, reg, 0xf, iface);
snd_soc_update_bits(codec, WM8776_MSTRCTRL, 0x180, master);
return 0;
}
static int wm8776_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8776_priv *wm8776 = snd_soc_codec_get_drvdata(codec);
int iface_reg, iface;
int ratio_shift, master;
int i;
switch (dai->driver->id) {
case WM8776_DAI_DAC:
iface_reg = WM8776_DACIFCTRL;
master = 0x80;
ratio_shift = 4;
break;
case WM8776_DAI_ADC:
iface_reg = WM8776_ADCIFCTRL;
master = 0x100;
ratio_shift = 0;
break;
default:
return -EINVAL;
}
switch (snd_pcm_format_width(params_format(params))) {
case 16:
iface = 0;
break;
case 20:
iface = 0x10;
break;
case 24:
iface = 0x20;
break;
case 32:
iface = 0x30;
break;
default:
dev_err(codec->dev, "Unsupported sample size: %i\n",
snd_pcm_format_width(params_format(params)));
return -EINVAL;
}
if (snd_soc_read(codec, WM8776_MSTRCTRL) & master) {
for (i = 0; i < ARRAY_SIZE(mclk_ratios); i++) {
if (wm8776->sysclk[dai->driver->id] / params_rate(params)
== mclk_ratios[i])
break;
}
if (i == ARRAY_SIZE(mclk_ratios)) {
dev_err(codec->dev,
"Unable to configure MCLK ratio %d/%d\n",
wm8776->sysclk[dai->driver->id], params_rate(params));
return -EINVAL;
}
dev_dbg(codec->dev, "MCLK is %dfs\n", mclk_ratios[i]);
snd_soc_update_bits(codec, WM8776_MSTRCTRL,
0x7 << ratio_shift, i << ratio_shift);
} else {
dev_dbg(codec->dev, "DAI in slave mode\n");
}
snd_soc_update_bits(codec, iface_reg, 0x30, iface);
return 0;
}
static int wm8776_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
return snd_soc_write(codec, WM8776_DACMUTE, !!mute);
}
static int wm8776_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8776_priv *wm8776 = snd_soc_codec_get_drvdata(codec);
if (WARN_ON(dai->driver->id >= ARRAY_SIZE(wm8776->sysclk)))
return -EINVAL;
wm8776->sysclk[dai->driver->id] = freq;
return 0;
}
static int wm8776_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8776_priv *wm8776 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
regcache_sync(wm8776->regmap);
snd_soc_update_bits(codec, WM8776_PWRDOWN, 1, 0);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8776_PWRDOWN, 1, 1);
break;
}
return 0;
}
static int wm8776_probe(struct snd_soc_codec *codec)
{
int ret = 0;
ret = wm8776_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, WM8776_HPRVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8776_DACRVOL, 0x100, 0x100);
return ret;
}
static int wm8776_spi_probe(struct spi_device *spi)
{
struct wm8776_priv *wm8776;
int ret;
wm8776 = devm_kzalloc(&spi->dev, sizeof(struct wm8776_priv),
GFP_KERNEL);
if (wm8776 == NULL)
return -ENOMEM;
wm8776->regmap = devm_regmap_init_spi(spi, &wm8776_regmap);
if (IS_ERR(wm8776->regmap))
return PTR_ERR(wm8776->regmap);
spi_set_drvdata(spi, wm8776);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8776, wm8776_dai, ARRAY_SIZE(wm8776_dai));
return ret;
}
static int wm8776_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8776_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8776_priv *wm8776;
int ret;
wm8776 = devm_kzalloc(&i2c->dev, sizeof(struct wm8776_priv),
GFP_KERNEL);
if (wm8776 == NULL)
return -ENOMEM;
wm8776->regmap = devm_regmap_init_i2c(i2c, &wm8776_regmap);
if (IS_ERR(wm8776->regmap))
return PTR_ERR(wm8776->regmap);
i2c_set_clientdata(i2c, wm8776);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8776, wm8776_dai, ARRAY_SIZE(wm8776_dai));
return ret;
}
static int wm8776_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8776_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8776_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8776 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8776_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8776 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8776_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8776_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8776_spi_driver);
#endif
}
