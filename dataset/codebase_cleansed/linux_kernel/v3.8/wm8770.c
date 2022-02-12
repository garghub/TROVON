static bool wm8770_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8770_RESET:
return true;
default:
return false;
}
}
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
regcache_sync(wm8770->regmap);
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
static int wm8770_probe(struct snd_soc_codec *codec)
{
struct wm8770_priv *wm8770;
int ret;
wm8770 = snd_soc_codec_get_drvdata(codec);
wm8770->codec = codec;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = wm8770_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
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
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8770->supplies), wm8770->supplies);
return ret;
}
static int wm8770_spi_probe(struct spi_device *spi)
{
struct wm8770_priv *wm8770;
int ret, i;
wm8770 = devm_kzalloc(&spi->dev, sizeof(struct wm8770_priv),
GFP_KERNEL);
if (!wm8770)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); i++)
wm8770->supplies[i].supply = wm8770_supply_names[i];
ret = devm_regulator_bulk_get(&spi->dev, ARRAY_SIZE(wm8770->supplies),
wm8770->supplies);
if (ret) {
dev_err(&spi->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8770->disable_nb[0].notifier_call = wm8770_regulator_event_0;
wm8770->disable_nb[1].notifier_call = wm8770_regulator_event_1;
wm8770->disable_nb[2].notifier_call = wm8770_regulator_event_2;
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); i++) {
ret = regulator_register_notifier(wm8770->supplies[i].consumer,
&wm8770->disable_nb[i]);
if (ret) {
dev_err(&spi->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
wm8770->regmap = devm_regmap_init_spi(spi, &wm8770_regmap);
if (IS_ERR(wm8770->regmap))
return PTR_ERR(wm8770->regmap);
spi_set_drvdata(spi, wm8770);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8770, &wm8770_dai, 1);
return ret;
}
static int wm8770_spi_remove(struct spi_device *spi)
{
struct wm8770_priv *wm8770 = spi_get_drvdata(spi);
int i;
for (i = 0; i < ARRAY_SIZE(wm8770->supplies); ++i)
regulator_unregister_notifier(wm8770->supplies[i].consumer,
&wm8770->disable_nb[i]);
snd_soc_unregister_codec(&spi->dev);
return 0;
}
