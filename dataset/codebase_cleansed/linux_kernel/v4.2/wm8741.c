static bool wm8741_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8741_DACLLSB_ATTENUATION:
case WM8741_DACLMSB_ATTENUATION:
case WM8741_DACRLSB_ATTENUATION:
case WM8741_DACRMSB_ATTENUATION:
case WM8741_VOLUME_CONTROL:
case WM8741_FORMAT_CONTROL:
case WM8741_FILTER_CONTROL:
case WM8741_MODE_CONTROL_1:
case WM8741_MODE_CONTROL_2:
case WM8741_ADDITIONAL_CONTROL_1:
return true;
default:
return false;
}
}
static int wm8741_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8741_RESET, 0);
}
static int wm8741_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
if (wm8741->sysclk)
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
wm8741->sysclk_constraints);
return 0;
}
static int wm8741_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8741_FORMAT_CONTROL) & 0x1FC;
int i;
if (!wm8741->sysclk) {
dev_err(codec->dev,
"No MCLK configured, call set_sysclk() on init or in hw_params\n");
return -EINVAL;
}
for (i = 0; i < wm8741->sysclk_constraints->count; i++) {
if (wm8741->sysclk_constraints->list[i] == params_rate(params))
break;
}
if (i == wm8741->sysclk_constraints->count) {
dev_err(codec->dev, "LRCLK %d unsupported with MCLK %d\n",
params_rate(params), wm8741->sysclk);
return -EINVAL;
}
switch (params_width(params)) {
case 16:
break;
case 20:
iface |= 0x0001;
break;
case 24:
iface |= 0x0002;
break;
case 32:
iface |= 0x0003;
break;
default:
dev_dbg(codec->dev, "wm8741_hw_params: Unsupported bit size param = %d",
params_width(params));
return -EINVAL;
}
dev_dbg(codec->dev, "wm8741_hw_params: bit size param = %d, rate param = %d",
params_width(params), params_rate(params));
snd_soc_write(codec, WM8741_FORMAT_CONTROL, iface);
return 0;
}
static int wm8741_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "wm8741_set_dai_sysclk info: freq=%dHz\n", freq);
switch (freq) {
case 0:
wm8741->sysclk_constraints = NULL;
wm8741->sysclk = freq;
return 0;
case 11289600:
wm8741->sysclk_constraints = &constraints_11289;
wm8741->sysclk = freq;
return 0;
case 12288000:
wm8741->sysclk_constraints = &constraints_12288;
wm8741->sysclk = freq;
return 0;
case 16384000:
wm8741->sysclk_constraints = &constraints_16384;
wm8741->sysclk = freq;
return 0;
case 16934400:
wm8741->sysclk_constraints = &constraints_16934;
wm8741->sysclk = freq;
return 0;
case 18432000:
wm8741->sysclk_constraints = &constraints_18432;
wm8741->sysclk = freq;
return 0;
case 22579200:
case 33868800:
wm8741->sysclk_constraints = &constraints_22579;
wm8741->sysclk = freq;
return 0;
case 24576000:
wm8741->sysclk_constraints = &constraints_24576;
wm8741->sysclk = freq;
return 0;
case 36864000:
wm8741->sysclk_constraints = &constraints_36864;
wm8741->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8741_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8741_FORMAT_CONTROL) & 0x1C3;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0008;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0004;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x000C;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x001C;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0010;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0020;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0030;
break;
default:
return -EINVAL;
}
dev_dbg(codec->dev, "wm8741_set_dai_fmt: Format=%x, Clock Inv=%x\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK,
((fmt & SND_SOC_DAIFMT_INV_MASK)));
snd_soc_write(codec, WM8741_FORMAT_CONTROL, iface);
return 0;
}
static int wm8741_resume(struct snd_soc_codec *codec)
{
snd_soc_cache_sync(codec);
return 0;
}
static int wm8741_configure(struct snd_soc_codec *codec)
{
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
switch (wm8741->pdata.diff_mode) {
case WM8741_DIFF_MODE_STEREO:
case WM8741_DIFF_MODE_STEREO_REVERSED:
case WM8741_DIFF_MODE_MONO_LEFT:
case WM8741_DIFF_MODE_MONO_RIGHT:
snd_soc_update_bits(codec, WM8741_MODE_CONTROL_2,
WM8741_DIFF_MASK,
wm8741->pdata.diff_mode << WM8741_DIFF_SHIFT);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8741_DACLLSB_ATTENUATION,
WM8741_UPDATELL, WM8741_UPDATELL);
snd_soc_update_bits(codec, WM8741_DACLMSB_ATTENUATION,
WM8741_UPDATELM, WM8741_UPDATELM);
snd_soc_update_bits(codec, WM8741_DACRLSB_ATTENUATION,
WM8741_UPDATERL, WM8741_UPDATERL);
snd_soc_update_bits(codec, WM8741_DACRMSB_ATTENUATION,
WM8741_UPDATERM, WM8741_UPDATERM);
return 0;
}
static int wm8741_add_controls(struct snd_soc_codec *codec)
{
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
switch (wm8741->pdata.diff_mode) {
case WM8741_DIFF_MODE_STEREO:
case WM8741_DIFF_MODE_STEREO_REVERSED:
snd_soc_add_codec_controls(codec,
wm8741_snd_controls_stereo,
ARRAY_SIZE(wm8741_snd_controls_stereo));
break;
case WM8741_DIFF_MODE_MONO_LEFT:
snd_soc_add_codec_controls(codec,
wm8741_snd_controls_mono_left,
ARRAY_SIZE(wm8741_snd_controls_mono_left));
break;
case WM8741_DIFF_MODE_MONO_RIGHT:
snd_soc_add_codec_controls(codec,
wm8741_snd_controls_mono_right,
ARRAY_SIZE(wm8741_snd_controls_mono_right));
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8741_probe(struct snd_soc_codec *codec)
{
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
ret = regulator_bulk_enable(ARRAY_SIZE(wm8741->supplies),
wm8741->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = wm8741_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
goto err_enable;
}
ret = wm8741_configure(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to change default settings\n");
goto err_enable;
}
ret = wm8741_add_controls(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to add controls\n");
goto err_enable;
}
dev_dbg(codec->dev, "Successful registration\n");
return ret;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8741->supplies), wm8741->supplies);
err_get:
return ret;
}
static int wm8741_remove(struct snd_soc_codec *codec)
{
struct wm8741_priv *wm8741 = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(wm8741->supplies), wm8741->supplies);
return 0;
}
static int wm8741_set_pdata(struct device *dev, struct wm8741_priv *wm8741)
{
const struct wm8741_platform_data *pdata = dev_get_platdata(dev);
u32 diff_mode;
if (dev->of_node) {
if (of_property_read_u32(dev->of_node, "diff-mode", &diff_mode)
>= 0)
wm8741->pdata.diff_mode = diff_mode;
} else {
if (pdata != NULL)
memcpy(&wm8741->pdata, pdata, sizeof(wm8741->pdata));
}
return 0;
}
static int wm8741_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8741_priv *wm8741;
int ret, i;
wm8741 = devm_kzalloc(&i2c->dev, sizeof(struct wm8741_priv),
GFP_KERNEL);
if (wm8741 == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(wm8741->supplies); i++)
wm8741->supplies[i].supply = wm8741_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8741->supplies),
wm8741->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8741->regmap = devm_regmap_init_i2c(i2c, &wm8741_regmap);
if (IS_ERR(wm8741->regmap)) {
ret = PTR_ERR(wm8741->regmap);
dev_err(&i2c->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
ret = wm8741_set_pdata(&i2c->dev, wm8741);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to set pdata: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, wm8741);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8741, &wm8741_dai, 1);
return ret;
}
static int wm8741_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int wm8741_spi_probe(struct spi_device *spi)
{
struct wm8741_priv *wm8741;
int ret, i;
wm8741 = devm_kzalloc(&spi->dev, sizeof(struct wm8741_priv),
GFP_KERNEL);
if (wm8741 == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(wm8741->supplies); i++)
wm8741->supplies[i].supply = wm8741_supply_names[i];
ret = devm_regulator_bulk_get(&spi->dev, ARRAY_SIZE(wm8741->supplies),
wm8741->supplies);
if (ret != 0) {
dev_err(&spi->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8741->regmap = devm_regmap_init_spi(spi, &wm8741_regmap);
if (IS_ERR(wm8741->regmap)) {
ret = PTR_ERR(wm8741->regmap);
dev_err(&spi->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
ret = wm8741_set_pdata(&spi->dev, wm8741);
if (ret != 0) {
dev_err(&spi->dev, "Failed to set pdata: %d\n", ret);
return ret;
}
spi_set_drvdata(spi, wm8741);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8741, &wm8741_dai, 1);
return ret;
}
static int wm8741_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int __init wm8741_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8741_i2c_driver);
if (ret != 0)
pr_err("Failed to register WM8741 I2C driver: %d\n", ret);
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8741_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8741 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8741_exit(void)
{
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8741_spi_driver);
#endif
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8741_i2c_driver);
#endif
}
