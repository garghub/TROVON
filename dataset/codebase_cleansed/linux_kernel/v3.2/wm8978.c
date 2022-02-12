static int wm8978_add_widgets(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, wm8978_dapm_widgets,
ARRAY_SIZE(wm8978_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
return 0;
}
static void pll_factors(struct snd_soc_codec *codec,
struct wm8978_pll_div *pll_div, unsigned int target, unsigned int source)
{
u64 k_part;
unsigned int k, n_div, n_mod;
n_div = target / source;
if (n_div < 6) {
source >>= 1;
pll_div->div2 = 1;
n_div = target / source;
} else {
pll_div->div2 = 0;
}
if (n_div < 6 || n_div > 12)
dev_warn(codec->dev,
"WM8978 N value exceeds recommended range! N = %u\n",
n_div);
pll_div->n = n_div;
n_mod = target - source * n_div;
k_part = FIXED_PLL_SIZE * (long long)n_mod + source / 2;
do_div(k_part, source);
k = k_part & 0xFFFFFFFF;
pll_div->k = k;
}
static int wm8978_enum_mclk(unsigned int f_out, unsigned int f_mclk,
unsigned int *f_pllout)
{
int i;
for (i = 0; i < ARRAY_SIZE(mclk_numerator); i++) {
unsigned int f_pllout_x4 = 4 * f_out * mclk_numerator[i] /
mclk_denominator[i];
if (3 * f_mclk <= f_pllout_x4 && f_pllout_x4 < 13 * f_mclk) {
*f_pllout = f_pllout_x4 / 4;
return i;
}
}
return -EINVAL;
}
static int wm8978_configure_pll(struct snd_soc_codec *codec)
{
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
struct wm8978_pll_div pll_div;
unsigned int f_opclk = wm8978->f_opclk, f_mclk = wm8978->f_mclk,
f_256fs = wm8978->f_256fs;
unsigned int f2;
if (!f_mclk)
return -EINVAL;
if (f_opclk) {
unsigned int opclk_div;
wm8978->mclk_idx = -1;
if (16 * f_opclk < 3 * f_mclk || 4 * f_opclk >= 13 * f_mclk)
return -EINVAL;
if (4 * f_opclk < 3 * f_mclk)
opclk_div = (3 * f_mclk / 4 + f_opclk - 1) / f_opclk;
else
opclk_div = 1;
dev_dbg(codec->dev, "%s: OPCLKDIV=%d\n", __func__, opclk_div);
snd_soc_update_bits(codec, WM8978_GPIO_CONTROL, 0x30,
(opclk_div - 1) << 4);
wm8978->f_pllout = f_opclk * opclk_div;
} else if (f_256fs) {
int idx = wm8978_enum_mclk(f_256fs, f_mclk, &wm8978->f_pllout);
if (idx < 0)
return idx;
wm8978->mclk_idx = idx;
snd_soc_update_bits(codec, WM8978_GPIO_CONTROL, 7, 0);
} else {
return -EINVAL;
}
f2 = wm8978->f_pllout * 4;
dev_dbg(codec->dev, "%s: f_MCLK=%uHz, f_PLLOUT=%uHz\n", __func__,
wm8978->f_mclk, wm8978->f_pllout);
pll_factors(codec, &pll_div, f2, wm8978->f_mclk);
dev_dbg(codec->dev, "%s: calculated PLL N=0x%x, K=0x%x, div2=%d\n",
__func__, pll_div.n, pll_div.k, pll_div.div2);
snd_soc_update_bits(codec, WM8978_POWER_MANAGEMENT_1, 0x20, 0);
snd_soc_write(codec, WM8978_PLL_N, (pll_div.div2 << 4) | pll_div.n);
snd_soc_write(codec, WM8978_PLL_K1, pll_div.k >> 18);
snd_soc_write(codec, WM8978_PLL_K2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8978_PLL_K3, pll_div.k & 0x1ff);
snd_soc_update_bits(codec, WM8978_POWER_MANAGEMENT_1, 0x20, 0x20);
if (f_opclk)
snd_soc_update_bits(codec, WM8978_GPIO_CONTROL, 7, 4);
return 0;
}
static int wm8978_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (div_id) {
case WM8978_OPCLKRATE:
wm8978->f_opclk = div;
if (wm8978->f_mclk)
ret = wm8978_configure_pll(codec);
break;
case WM8978_BCLKDIV:
if (div & ~0x1c)
return -EINVAL;
snd_soc_update_bits(codec, WM8978_CLOCKING, 0x1c, div);
break;
default:
return -EINVAL;
}
dev_dbg(codec->dev, "%s: ID %d, value %u\n", __func__, div_id, div);
return ret;
}
static int wm8978_set_dai_sysclk(struct snd_soc_dai *codec_dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
dev_dbg(codec->dev, "%s: ID %d, freq %u\n", __func__, clk_id, freq);
if (freq) {
wm8978->f_mclk = freq;
if (wm8978->f_opclk)
ret = wm8978_configure_pll(codec);
if (!ret)
wm8978->sysclk = clk_id;
}
if (wm8978->sysclk == WM8978_PLL && (!freq || clk_id == WM8978_MCLK)) {
snd_soc_update_bits(codec, WM8978_CLOCKING, 0x100, 0);
snd_soc_update_bits(codec, WM8978_GPIO_CONTROL, 7, 0);
snd_soc_update_bits(codec, WM8978_POWER_MANAGEMENT_1, 0x20, 0);
wm8978->sysclk = WM8978_MCLK;
wm8978->f_pllout = 0;
wm8978->f_opclk = 0;
}
return ret;
}
static int wm8978_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8978_AUDIO_INTERFACE) & ~0x198;
u16 clk = snd_soc_read(codec, WM8978_CLOCKING);
dev_dbg(codec->dev, "%s\n", __func__);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
clk |= 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
clk &= ~1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x10;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x8;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x18;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x180;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x100;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x80;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8978_AUDIO_INTERFACE, iface);
snd_soc_write(codec, WM8978_CLOCKING, clk);
return 0;
}
static int wm8978_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
u16 iface_ctl = snd_soc_read(codec, WM8978_AUDIO_INTERFACE) & ~0x60;
u16 add_ctl = snd_soc_read(codec, WM8978_ADDITIONAL_CONTROL) & ~0xe;
u16 clking = snd_soc_read(codec, WM8978_CLOCKING);
enum wm8978_sysclk_src current_clk_id = clking & 0x100 ?
WM8978_PLL : WM8978_MCLK;
unsigned int f_sel, diff, diff_best = INT_MAX;
int i, best = 0;
if (!wm8978->f_mclk)
return -EINVAL;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface_ctl |= 0x20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface_ctl |= 0x40;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface_ctl |= 0x60;
break;
}
switch (params_rate(params)) {
case 8000:
add_ctl |= 0x5 << 1;
break;
case 11025:
add_ctl |= 0x4 << 1;
break;
case 16000:
add_ctl |= 0x3 << 1;
break;
case 22050:
add_ctl |= 0x2 << 1;
break;
case 32000:
add_ctl |= 0x1 << 1;
break;
case 44100:
case 48000:
break;
}
wm8978->f_256fs = params_rate(params) * 256;
if (wm8978->sysclk == WM8978_MCLK) {
wm8978->mclk_idx = -1;
f_sel = wm8978->f_mclk;
} else {
if (!wm8978->f_pllout) {
int ret = wm8978_configure_pll(codec);
if (ret < 0)
return ret;
}
f_sel = wm8978->f_pllout;
}
if (wm8978->mclk_idx < 0) {
if (f_sel < wm8978->f_256fs || f_sel > 12 * wm8978->f_256fs)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(mclk_numerator); i++) {
diff = abs(wm8978->f_256fs * 3 -
f_sel * 3 * mclk_denominator[i] / mclk_numerator[i]);
if (diff < diff_best) {
diff_best = diff;
best = i;
}
if (!diff)
break;
}
} else {
best = wm8978->mclk_idx;
diff = 0;
}
if (diff)
dev_warn(codec->dev, "Imprecise sampling rate: %uHz%s\n",
f_sel * mclk_denominator[best] / mclk_numerator[best] / 256,
wm8978->sysclk == WM8978_MCLK ?
", consider using PLL" : "");
dev_dbg(codec->dev, "%s: fmt %d, rate %u, MCLK divisor #%d\n", __func__,
params_format(params), params_rate(params), best);
snd_soc_update_bits(codec, WM8978_CLOCKING, 0xe0, best << 5);
snd_soc_write(codec, WM8978_AUDIO_INTERFACE, iface_ctl);
snd_soc_write(codec, WM8978_ADDITIONAL_CONTROL, add_ctl);
if (wm8978->sysclk != current_clk_id) {
if (wm8978->sysclk == WM8978_PLL)
snd_soc_update_bits(codec, WM8978_CLOCKING,
0x100, 0x100);
else
snd_soc_update_bits(codec, WM8978_CLOCKING, 0x100, 0);
}
return 0;
}
static int wm8978_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
dev_dbg(codec->dev, "%s: %d\n", __func__, mute);
if (mute)
snd_soc_update_bits(codec, WM8978_DAC_CONTROL, 0x40, 0x40);
else
snd_soc_update_bits(codec, WM8978_DAC_CONTROL, 0x40, 0);
return 0;
}
static int wm8978_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 power1 = snd_soc_read(codec, WM8978_POWER_MANAGEMENT_1) & ~3;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
power1 |= 1;
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_1, power1);
break;
case SND_SOC_BIAS_STANDBY:
power1 |= 0xc;
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_1,
power1 | 0x3);
mdelay(100);
}
power1 |= 0x2;
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_1, power1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8978_POWER_MANAGEMENT_1, ~0x20, 0);
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_2, 0);
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_3, 0);
break;
}
dev_dbg(codec->dev, "%s: %d, %x\n", __func__, level, power1);
codec->dapm.bias_level = level;
return 0;
}
static int wm8978_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8978_set_bias_level(codec, SND_SOC_BIAS_OFF);
snd_soc_write(codec, WM8978_POWER_MANAGEMENT_1, 0);
return 0;
}
static int wm8978_resume(struct snd_soc_codec *codec)
{
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
int i;
u16 *cache = codec->reg_cache;
for (i = 0; i < ARRAY_SIZE(wm8978_reg); i++) {
if (i == WM8978_RESET)
continue;
if (cache[i] != wm8978_reg[i])
snd_soc_write(codec, i, cache[i]);
}
wm8978_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (wm8978->f_pllout)
snd_soc_update_bits(codec, WM8978_POWER_MANAGEMENT_1, 0x20, 0x20);
return 0;
}
static int wm8978_probe(struct snd_soc_codec *codec)
{
struct wm8978_priv *wm8978 = snd_soc_codec_get_drvdata(codec);
int ret = 0, i;
wm8978->sysclk = WM8978_PLL;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_I2C);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(update_reg); i++)
snd_soc_update_bits(codec, update_reg[i], 0x100, 0x100);
ret = snd_soc_write(codec, WM8978_RESET, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
wm8978_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_controls(codec, wm8978_snd_controls,
ARRAY_SIZE(wm8978_snd_controls));
wm8978_add_widgets(codec);
return 0;
}
static int wm8978_remove(struct snd_soc_codec *codec)
{
wm8978_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static __devinit int wm8978_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8978_priv *wm8978;
int ret;
wm8978 = kzalloc(sizeof(struct wm8978_priv), GFP_KERNEL);
if (wm8978 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8978);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8978, &wm8978_dai, 1);
if (ret < 0)
kfree(wm8978);
return ret;
}
static __devexit int wm8978_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8978_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8978_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8978 I2C driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8978_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8978_i2c_driver);
#endif
}
