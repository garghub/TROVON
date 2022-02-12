static bool wm8737_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8737_RESET:
return true;
default:
return false;
}
}
static int wm8737_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8737_RESET, 0);
}
static int wm8737_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8737_priv *wm8737 = snd_soc_codec_get_drvdata(codec);
int i;
u16 clocking = 0;
u16 af = 0;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate != params_rate(params))
continue;
if (coeff_div[i].mclk == wm8737->mclk)
break;
if (coeff_div[i].mclk == wm8737->mclk * 2) {
clocking |= WM8737_CLKDIV2;
break;
}
}
if (i == ARRAY_SIZE(coeff_div)) {
dev_err(codec->dev, "%dHz MCLK can't support %dHz\n",
wm8737->mclk, params_rate(params));
return -EINVAL;
}
clocking |= coeff_div[i].usb | (coeff_div[i].sr << WM8737_SR_SHIFT);
switch (params_width(params)) {
case 16:
break;
case 20:
af |= 0x8;
break;
case 24:
af |= 0x10;
break;
case 32:
af |= 0x18;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8737_AUDIO_FORMAT, WM8737_WL_MASK, af);
snd_soc_update_bits(codec, WM8737_CLOCKING,
WM8737_USB_MODE | WM8737_CLKDIV2 | WM8737_SR_MASK,
clocking);
return 0;
}
static int wm8737_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8737_priv *wm8737 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (freq == coeff_div[i].mclk ||
freq == coeff_div[i].mclk * 2) {
wm8737->mclk = freq;
return 0;
}
}
dev_err(codec->dev, "MCLK rate %dHz not supported\n", freq);
return -EINVAL;
}
static int wm8737_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 af = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
af |= WM8737_MS;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
af |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
af |= 0x1;
break;
case SND_SOC_DAIFMT_DSP_A:
af |= 0x3;
break;
case SND_SOC_DAIFMT_DSP_B:
af |= 0x13;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
af |= WM8737_LRP;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8737_AUDIO_FORMAT,
WM8737_FORMAT_MASK | WM8737_LRP | WM8737_MS, af);
return 0;
}
static int wm8737_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8737_priv *wm8737 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8737_MISC_BIAS_CONTROL,
WM8737_VMIDSEL_MASK, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8737->supplies),
wm8737->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
regcache_sync(wm8737->regmap);
snd_soc_update_bits(codec, WM8737_MISC_BIAS_CONTROL,
WM8737_VMIDSEL_MASK, 0x4);
snd_soc_update_bits(codec, WM8737_POWER_MANAGEMENT,
WM8737_VMID_MASK |
WM8737_VREF_MASK,
WM8737_VMID_MASK |
WM8737_VREF_MASK);
msleep(500);
}
snd_soc_update_bits(codec, WM8737_MISC_BIAS_CONTROL,
WM8737_VMIDSEL_MASK, 2);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8737_POWER_MANAGEMENT,
WM8737_VMID_MASK | WM8737_VREF_MASK, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies),
wm8737->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8737_probe(struct snd_soc_codec *codec)
{
struct wm8737_priv *wm8737 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(wm8737->supplies),
wm8737->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = wm8737_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
goto err_enable;
}
snd_soc_update_bits(codec, WM8737_LEFT_PGA_VOLUME, WM8737_LVU,
WM8737_LVU);
snd_soc_update_bits(codec, WM8737_RIGHT_PGA_VOLUME, WM8737_RVU,
WM8737_RVU);
wm8737_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies), wm8737->supplies);
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8737->supplies), wm8737->supplies);
err_get:
return ret;
}
static int wm8737_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8737_priv *wm8737;
int ret, i;
wm8737 = devm_kzalloc(&i2c->dev, sizeof(struct wm8737_priv),
GFP_KERNEL);
if (wm8737 == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(wm8737->supplies); i++)
wm8737->supplies[i].supply = wm8737_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8737->supplies),
wm8737->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8737->regmap = devm_regmap_init_i2c(i2c, &wm8737_regmap);
if (IS_ERR(wm8737->regmap))
return PTR_ERR(wm8737->regmap);
i2c_set_clientdata(i2c, wm8737);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8737, &wm8737_dai, 1);
return ret;
}
static int wm8737_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int wm8737_spi_probe(struct spi_device *spi)
{
struct wm8737_priv *wm8737;
int ret, i;
wm8737 = devm_kzalloc(&spi->dev, sizeof(struct wm8737_priv),
GFP_KERNEL);
if (wm8737 == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(wm8737->supplies); i++)
wm8737->supplies[i].supply = wm8737_supply_names[i];
ret = devm_regulator_bulk_get(&spi->dev, ARRAY_SIZE(wm8737->supplies),
wm8737->supplies);
if (ret != 0) {
dev_err(&spi->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8737->regmap = devm_regmap_init_spi(spi, &wm8737_regmap);
if (IS_ERR(wm8737->regmap))
return PTR_ERR(wm8737->regmap);
spi_set_drvdata(spi, wm8737);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8737, &wm8737_dai, 1);
return ret;
}
static int wm8737_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int __init wm8737_modinit(void)
{
int ret;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8737_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8737 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8737_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8737 SPI driver: %d\n",
ret);
}
#endif
return 0;
}
static void __exit wm8737_exit(void)
{
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8737_spi_driver);
#endif
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8737_i2c_driver);
#endif
}
