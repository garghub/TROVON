static int vout12supply_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec;
codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, WM8770_OUTMUX1, 0x180, 0);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, WM8770_OUTMUX1, 0x180, 0x180);
break;
}
return 0;
}
static int vout34supply_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec;
codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, WM8770_OUTMUX2, 0x180, 0);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, WM8770_OUTMUX2, 0x180, 0x180);
break;
}
return 0;
}
static int wm8770_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8770_RESET, 0);
}
static int wm8770_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec;
int iface, master;
codec = dai->codec;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
master = 0x100;
break;
case SND_SOC_DAIFMT_CBS_CFS:
master = 0;
break;
default:
return -EINVAL;
}
iface = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0xc;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x8;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x4;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8770_IFACECTRL, 0xf, iface);
snd_soc_update_bits(codec, WM8770_MSTRCTRL, 0x100, master);
return 0;
}
static int wm8770_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec;
struct wm8770_priv *wm8770;
int i;
int iface;
int shift;
int ratio;
codec = dai->codec;
wm8770 = snd_soc_codec_get_drvdata(codec);
iface = 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= 0x10;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= 0x20;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= 0x30;
break;
}
switch (substream->stream) {
case SNDRV_PCM_STREAM_PLAYBACK:
i = 0;
shift = 4;
break;
case SNDRV_PCM_STREAM_CAPTURE:
i = 2;
shift = 0;
break;
default:
return -EINVAL;
}
if (snd_soc_read(codec, WM8770_MSTRCTRL) & 0x100) {
for (; i < ARRAY_SIZE(mclk_ratios); ++i) {
ratio = wm8770->sysclk / params_rate(params);
if (ratio == mclk_ratios[i])
break;
}
if (i == ARRAY_SIZE(mclk_ratios)) {
dev_err(codec->dev,
"Unable to configure MCLK ratio %d/%d\n",
wm8770->sysclk, params_rate(params));
return -EINVAL;
}
dev_dbg(codec->dev, "MCLK is %dfs\n", mclk_ratios[i]);
snd_soc_update_bits(codec, WM8770_MSTRCTRL, 0x7 << shift,
i << shift);
}
snd_soc_update_bits(codec, WM8770_IFACECTRL, 0x30, iface);
return 0;
}
static int wm8770_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec;
codec = dai->codec;
return snd_soc_update_bits(codec, WM8770_DACMUTE, 0x10,
!!mute << 4);
}
static int wm8770_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec;
struct wm8770_priv *wm8770;
codec = dai->codec;
wm8770 = snd_soc_codec_get_drvdata(codec);
wm8770->sysclk = freq;
return 0;
}
static void wm8770_sync_cache(struct snd_soc_codec *codec)
{
int i;
u16 *cache;
if (!codec->cache_sync)
return;
codec->cache_only = 0;
cache = codec->reg_cache;
for (i = 0; i < codec->driver->reg_cache_size; i++) {
if (i == WM8770_RESET || cache[i] == wm8770_reg_defs[i])
continue;
snd_soc_write(codec, i, cache[i]);
}
codec->cache_sync = 0;
}
static int wm8770_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
struct wm8770_priv *wm8770;
wm8770 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
if (ret) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
wm8770_sync_cache(codec);
snd_soc_write(codec, WM8770_PWDNCTRL, 0);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8770_PWDNCTRL, 1);
regulator_bulk_disable(ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8770_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8770_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8770_resume(struct snd_soc_codec *codec)
{
wm8770_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8770_probe(struct snd_soc_codec *codec)
{
struct wm8770_priv *wm8770;
int ret;
int i;
wm8770 = snd_soc_codec_get_drvdata(codec);
wm8770->codec = codec;
codec->dapm.idle_bias_off = 1;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, wm8770->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); i++)
wm8770->supplies[i].supply = wm8770_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
if (ret) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8770->disable_nb[0].notifier_call = wm8770_regulator_event_0;
wm8770->disable_nb[1].notifier_call = wm8770_regulator_event_1;
wm8770->disable_nb[2].notifier_call = wm8770_regulator_event_2;
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); i++) {
ret = regulator_register_notifier(wm8770->supplies[i].consumer,
&wm8770->disable_nb[i]);
if (ret) {
dev_err(codec->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_reg_get;
}
ret = wm8770_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
wm8770_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8770_MSDIGVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_MSALGVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_VOUT1RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_VOUT2RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_VOUT3RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_VOUT4RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_DAC1RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_DAC2RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_DAC3RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_DAC4RVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8770_DACMUTE, 0x10, 0x10);
snd_soc_add_controls(codec, wm8770_snd_controls,
ARRAY_SIZE(wm8770_snd_controls));
snd_soc_dapm_new_controls(&codec->dapm, wm8770_dapm_widgets,
ARRAY_SIZE(wm8770_dapm_widgets));
snd_soc_dapm_add_routes(&codec->dapm, wm8770_intercon,
ARRAY_SIZE(wm8770_intercon));
return 0;
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8770->supplies), wm8770->supplies);
err_reg_get:
regulator_bulk_free(ARRAY_SIZE(wm8770->supplies), wm8770->supplies);
return ret;
}
static int wm8770_remove(struct snd_soc_codec *codec)
{
struct wm8770_priv *wm8770;
int i;
wm8770 = snd_soc_codec_get_drvdata(codec);
wm8770_set_bias_level(codec, SND_SOC_BIAS_OFF);
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); ++i)
regulator_unregister_notifier(wm8770->supplies[i].consumer,
&wm8770->disable_nb[i]);
regulator_bulk_free(ARRAY_SIZE(wm8770->supplies), wm8770->supplies);
return 0;
}
static int __devinit wm8770_spi_probe(struct spi_device *spi)
{
struct wm8770_priv *wm8770;
int ret;
wm8770 = kzalloc(sizeof(struct wm8770_priv), GFP_KERNEL);
if (!wm8770)
return -ENOMEM;
wm8770->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, wm8770);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8770, &wm8770_dai, 1);
if (ret < 0)
kfree(wm8770);
return ret;
}
static int __devexit wm8770_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static int __init wm8770_modinit(void)
{
int ret = 0;
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8770_spi_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8770 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8770_exit(void)
{
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8770_spi_driver);
#endif
}
