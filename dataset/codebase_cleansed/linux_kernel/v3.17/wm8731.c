static bool wm8731_volatile(struct device *dev, unsigned int reg)
{
return reg == WM8731_RESET;
}
static bool wm8731_writeable(struct device *dev, unsigned int reg)
{
return reg <= WM8731_RESET;
}
static int wm8731_set_deemph(struct snd_soc_codec *codec)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (wm8731->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(wm8731_deemph); i++) {
if (abs(wm8731_deemph[i] - wm8731->playback_fs) <
abs(wm8731_deemph[best] - wm8731->playback_fs))
best = i;
}
val = best << 1;
} else {
best = 0;
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d (%dHz)\n",
best, wm8731_deemph[best]);
return snd_soc_update_bits(codec, WM8731_APDIGI, 0x6, val);
}
static int wm8731_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = wm8731->deemph;
return 0;
}
static int wm8731_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
int deemph = ucontrol->value.enumerated.item[0];
int ret = 0;
if (deemph > 1)
return -EINVAL;
mutex_lock(&codec->mutex);
if (wm8731->deemph != deemph) {
wm8731->deemph = deemph;
wm8731_set_deemph(codec);
ret = 1;
}
mutex_unlock(&codec->mutex);
return ret;
}
static int wm8731_check_osc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(source->codec);
return wm8731->sysclk_type == WM8731_SYSCLK_XTAL;
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
static int wm8731_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8731_IFACE) & 0xfff3;
int i = get_coeff(wm8731->sysclk, params_rate(params));
u16 srate = (coeff_div[i].sr << 2) |
(coeff_div[i].bosr << 1) | coeff_div[i].usb;
wm8731->playback_fs = params_rate(params);
snd_soc_write(codec, WM8731_SRATE, srate);
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
wm8731_set_deemph(codec);
snd_soc_write(codec, WM8731_IFACE, iface);
return 0;
}
static int wm8731_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8731_APDIGI) & 0xfff7;
if (mute)
snd_soc_write(codec, WM8731_APDIGI, mute_reg | 0x8);
else
snd_soc_write(codec, WM8731_APDIGI, mute_reg);
return 0;
}
static int wm8731_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8731_SYSCLK_XTAL:
case WM8731_SYSCLK_MCLK:
wm8731->sysclk_type = clk_id;
break;
default:
return -EINVAL;
}
switch (freq) {
case 0:
wm8731->constraints = NULL;
break;
case 12000000:
wm8731->constraints = &wm8731_constraints_12000000;
break;
case 12288000:
case 18432000:
wm8731->constraints = &wm8731_constraints_12288000_18432000;
break;
case 16934400:
case 11289600:
wm8731->constraints = &wm8731_constraints_11289600_16934400;
break;
default:
return -EINVAL;
}
wm8731->sysclk = freq;
snd_soc_dapm_sync(&codec->dapm);
return 0;
}
static int wm8731_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
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
iface |= 0x0013;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x0003;
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
snd_soc_write(codec, WM8731_IFACE, iface);
return 0;
}
static int wm8731_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
int ret;
u16 reg;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8731->supplies),
wm8731->supplies);
if (ret != 0)
return ret;
regcache_sync(wm8731->regmap);
}
reg = snd_soc_read(codec, WM8731_PWR) & 0xff7f;
snd_soc_write(codec, WM8731_PWR, reg | 0x0040);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8731_PWR, 0xffff);
regulator_bulk_disable(ARRAY_SIZE(wm8731->supplies),
wm8731->supplies);
regcache_mark_dirty(wm8731->regmap);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8731_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(dai->codec);
if (wm8731->constraints)
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
wm8731->constraints);
return 0;
}
static int wm8731_suspend(struct snd_soc_codec *codec)
{
wm8731_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8731_resume(struct snd_soc_codec *codec)
{
wm8731_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8731_probe(struct snd_soc_codec *codec)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
int ret = 0, i;
for (i = 0; i < ARRAY_SIZE(wm8731->supplies); i++)
wm8731->supplies[i].supply = wm8731_supply_names[i];
ret = devm_regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8731->supplies),
wm8731->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8731->supplies),
wm8731->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = wm8731_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_regulator_enable;
}
wm8731_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8731_LOUT1V, 0x100, 0);
snd_soc_update_bits(codec, WM8731_ROUT1V, 0x100, 0);
snd_soc_update_bits(codec, WM8731_LINVOL, 0x100, 0);
snd_soc_update_bits(codec, WM8731_RINVOL, 0x100, 0);
snd_soc_update_bits(codec, WM8731_APANA, 0x8, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8731->supplies), wm8731->supplies);
return 0;
err_regulator_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8731->supplies), wm8731->supplies);
return ret;
}
static int wm8731_remove(struct snd_soc_codec *codec)
{
struct wm8731_priv *wm8731 = snd_soc_codec_get_drvdata(codec);
wm8731_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_disable(ARRAY_SIZE(wm8731->supplies), wm8731->supplies);
return 0;
}
static int wm8731_spi_probe(struct spi_device *spi)
{
struct wm8731_priv *wm8731;
int ret;
wm8731 = devm_kzalloc(&spi->dev, sizeof(struct wm8731_priv),
GFP_KERNEL);
if (wm8731 == NULL)
return -ENOMEM;
wm8731->regmap = devm_regmap_init_spi(spi, &wm8731_regmap);
if (IS_ERR(wm8731->regmap)) {
ret = PTR_ERR(wm8731->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
spi_set_drvdata(spi, wm8731);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8731, &wm8731_dai, 1);
if (ret != 0) {
dev_err(&spi->dev, "Failed to register CODEC: %d\n", ret);
return ret;
}
return 0;
}
static int wm8731_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8731_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8731_priv *wm8731;
int ret;
wm8731 = devm_kzalloc(&i2c->dev, sizeof(struct wm8731_priv),
GFP_KERNEL);
if (wm8731 == NULL)
return -ENOMEM;
wm8731->regmap = devm_regmap_init_i2c(i2c, &wm8731_regmap);
if (IS_ERR(wm8731->regmap)) {
ret = PTR_ERR(wm8731->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(i2c, wm8731);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8731, &wm8731_dai, 1);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
return ret;
}
return 0;
}
static int wm8731_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8731_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8731_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8731 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8731_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8731 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8731_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8731_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8731_spi_driver);
#endif
}
