static bool wm8523_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8523_DEVICE_ID:
case WM8523_REVISION:
return true;
default:
return false;
}
}
static int wm8523_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8523_priv *wm8523 = snd_soc_codec_get_drvdata(codec);
if (!wm8523->sysclk) {
dev_err(codec->dev,
"No MCLK configured, call set_sysclk() on init\n");
return -EINVAL;
}
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&wm8523->rate_constraint);
return 0;
}
static int wm8523_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8523_priv *wm8523 = snd_soc_codec_get_drvdata(codec);
int i;
u16 aifctrl1 = snd_soc_read(codec, WM8523_AIF_CTRL1);
u16 aifctrl2 = snd_soc_read(codec, WM8523_AIF_CTRL2);
for (i = 0; i < ARRAY_SIZE(lrclk_ratios); i++) {
if (wm8523->sysclk / params_rate(params) ==
lrclk_ratios[i].ratio)
break;
}
if (i == ARRAY_SIZE(lrclk_ratios)) {
dev_err(codec->dev, "MCLK/fs ratio %d unsupported\n",
wm8523->sysclk / params_rate(params));
return -EINVAL;
}
aifctrl2 &= ~WM8523_SR_MASK;
aifctrl2 |= lrclk_ratios[i].value;
aifctrl1 &= ~WM8523_WL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
aifctrl1 |= 0x8;
break;
case SNDRV_PCM_FORMAT_S24_LE:
aifctrl1 |= 0x10;
break;
case SNDRV_PCM_FORMAT_S32_LE:
aifctrl1 |= 0x18;
break;
}
snd_soc_write(codec, WM8523_AIF_CTRL1, aifctrl1);
snd_soc_write(codec, WM8523_AIF_CTRL2, aifctrl2);
return 0;
}
static int wm8523_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8523_priv *wm8523 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
int i;
wm8523->sysclk = freq;
wm8523->rate_constraint.count = 0;
for (i = 0; i < ARRAY_SIZE(lrclk_ratios); i++) {
val = freq / lrclk_ratios[i].ratio;
switch (val) {
case 8000:
case 11025:
case 16000:
case 22050:
case 32000:
case 44100:
case 48000:
case 64000:
case 88200:
case 96000:
case 176400:
case 192000:
dev_dbg(codec->dev, "Supported sample rate: %dHz\n",
val);
wm8523->rate_constraint_list[i] = val;
wm8523->rate_constraint.count++;
break;
default:
dev_dbg(codec->dev, "Skipping sample rate: %dHz\n",
val);
}
}
if (wm8523->rate_constraint.count == 0)
return -EINVAL;
return 0;
}
static int wm8523_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 aifctrl1 = snd_soc_read(codec, WM8523_AIF_CTRL1);
aifctrl1 &= ~(WM8523_BCLK_INV_MASK | WM8523_LRCLK_INV_MASK |
WM8523_FMT_MASK | WM8523_AIF_MSTR_MASK);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
aifctrl1 |= WM8523_AIF_MSTR;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
aifctrl1 |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aifctrl1 |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
aifctrl1 |= 0x0003;
break;
case SND_SOC_DAIFMT_DSP_B:
aifctrl1 |= 0x0023;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
aifctrl1 |= WM8523_BCLK_INV | WM8523_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aifctrl1 |= WM8523_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aifctrl1 |= WM8523_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8523_AIF_CTRL1, aifctrl1);
return 0;
}
static int wm8523_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8523_priv *wm8523 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8523_PSCTRL1,
WM8523_SYS_ENA_MASK, 3);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8523->supplies),
wm8523->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
regcache_sync(wm8523->regmap);
snd_soc_update_bits(codec, WM8523_PSCTRL1,
WM8523_SYS_ENA_MASK, 1);
msleep(100);
}
snd_soc_update_bits(codec, WM8523_PSCTRL1,
WM8523_SYS_ENA_MASK, 2);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8523_PSCTRL1,
WM8523_SYS_ENA_MASK, 0);
msleep(100);
regulator_bulk_disable(ARRAY_SIZE(wm8523->supplies),
wm8523->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8523_suspend(struct snd_soc_codec *codec)
{
wm8523_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8523_resume(struct snd_soc_codec *codec)
{
wm8523_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8523_probe(struct snd_soc_codec *codec)
{
struct wm8523_priv *wm8523 = snd_soc_codec_get_drvdata(codec);
wm8523->rate_constraint.list = &wm8523->rate_constraint_list[0];
wm8523->rate_constraint.count =
ARRAY_SIZE(wm8523->rate_constraint_list);
snd_soc_update_bits(codec, WM8523_DAC_GAINR,
WM8523_DACR_VU, WM8523_DACR_VU);
snd_soc_update_bits(codec, WM8523_DAC_CTRL3, WM8523_ZC, WM8523_ZC);
wm8523_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8523_remove(struct snd_soc_codec *codec)
{
wm8523_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8523_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8523_priv *wm8523;
unsigned int val;
int ret, i;
wm8523 = devm_kzalloc(&i2c->dev, sizeof(struct wm8523_priv),
GFP_KERNEL);
if (wm8523 == NULL)
return -ENOMEM;
wm8523->regmap = devm_regmap_init_i2c(i2c, &wm8523_regmap);
if (IS_ERR(wm8523->regmap)) {
ret = PTR_ERR(wm8523->regmap);
dev_err(&i2c->dev, "Failed to create regmap: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8523->supplies); i++)
wm8523->supplies[i].supply = wm8523_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8523->supplies),
wm8523->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8523->supplies),
wm8523->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = regmap_read(wm8523->regmap, WM8523_DEVICE_ID, &val);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register\n");
goto err_enable;
}
if (val != 0x8523) {
dev_err(&i2c->dev, "Device is not a WM8523, ID is %x\n", ret);
ret = -EINVAL;
goto err_enable;
}
ret = regmap_read(wm8523->regmap, WM8523_REVISION, &val);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read revision register\n");
goto err_enable;
}
dev_info(&i2c->dev, "revision %c\n",
(val & WM8523_CHIP_REV_MASK) + 'A');
ret = regmap_write(wm8523->regmap, WM8523_DEVICE_ID, 0x8523);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to reset device: %d\n", ret);
goto err_enable;
}
regulator_bulk_disable(ARRAY_SIZE(wm8523->supplies), wm8523->supplies);
i2c_set_clientdata(i2c, wm8523);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8523, &wm8523_dai, 1);
return ret;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8523->supplies), wm8523->supplies);
return ret;
}
static int wm8523_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8523_modinit(void)
{
int ret;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8523_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8523 I2C driver: %d\n",
ret);
}
#endif
return 0;
}
static void __exit wm8523_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8523_i2c_driver);
#endif
}
