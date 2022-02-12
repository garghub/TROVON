static bool wm8960_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8960_RESET:
return true;
default:
return false;
}
}
static int wm8960_set_deemph(struct snd_soc_codec *codec)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (wm8960->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(deemph_settings); i++) {
if (abs(deemph_settings[i] - wm8960->lrclk) <
abs(deemph_settings[best] - wm8960->lrclk))
best = i;
}
val = best << 1;
} else {
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", val);
return snd_soc_update_bits(codec, WM8960_DACCTL1,
0x6, val);
}
static int wm8960_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = wm8960->deemph;
return 0;
}
static int wm8960_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
unsigned int deemph = ucontrol->value.integer.value[0];
if (deemph > 1)
return -EINVAL;
wm8960->deemph = deemph;
return wm8960_set_deemph(codec);
}
static int wm8960_add_widgets(struct snd_soc_codec *codec)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
struct wm8960_data *pdata = &wm8960->pdata;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct snd_soc_dapm_widget *w;
snd_soc_dapm_new_controls(dapm, wm8960_dapm_widgets,
ARRAY_SIZE(wm8960_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_paths, ARRAY_SIZE(audio_paths));
if (pdata && pdata->capless) {
snd_soc_dapm_new_controls(dapm, wm8960_dapm_widgets_capless,
ARRAY_SIZE(wm8960_dapm_widgets_capless));
snd_soc_dapm_add_routes(dapm, audio_paths_capless,
ARRAY_SIZE(audio_paths_capless));
} else {
snd_soc_dapm_new_controls(dapm, wm8960_dapm_widgets_out3,
ARRAY_SIZE(wm8960_dapm_widgets_out3));
snd_soc_dapm_add_routes(dapm, audio_paths_out3,
ARRAY_SIZE(audio_paths_out3));
}
list_for_each_entry(w, &codec->component.card->widgets, list) {
if (w->dapm != dapm)
continue;
if (strcmp(w->name, "LOUT1 PGA") == 0)
wm8960->lout1 = w;
if (strcmp(w->name, "ROUT1 PGA") == 0)
wm8960->rout1 = w;
if (strcmp(w->name, "OUT3 VMID") == 0)
wm8960->out3 = w;
}
return 0;
}
static int wm8960_set_dai_fmt(struct snd_soc_dai *codec_dai,
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
snd_soc_write(codec, WM8960_IFACE1, iface);
return 0;
}
static int wm8960_configure_clocking(struct snd_soc_codec *codec)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
int sysclk, bclk, lrclk, freq_out, freq_in;
u16 iface1 = snd_soc_read(codec, WM8960_IFACE1);
int i, j, k;
if (!(iface1 & (1<<6))) {
dev_dbg(codec->dev,
"Codec is slave mode, no need to configure clock\n");
return 0;
}
if (wm8960->clk_id != WM8960_SYSCLK_MCLK && !wm8960->freq_in) {
dev_err(codec->dev, "No MCLK configured\n");
return -EINVAL;
}
freq_in = wm8960->freq_in;
bclk = wm8960->bclk;
lrclk = wm8960->lrclk;
if (wm8960->clk_id == WM8960_SYSCLK_AUTO) {
wm8960_set_pll(codec, 0, 0);
freq_out = freq_in;
} else if (wm8960->sysclk) {
freq_out = wm8960->sysclk;
} else {
dev_err(codec->dev, "No SYSCLK configured\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(sysclk_divs); ++i) {
if (sysclk_divs[i] == -1)
continue;
sysclk = freq_out / sysclk_divs[i];
for (j = 0; j < ARRAY_SIZE(dac_divs); ++j) {
if (sysclk == dac_divs[j] * lrclk) {
for (k = 0; k < ARRAY_SIZE(bclk_divs); ++k)
if (sysclk == bclk * bclk_divs[k] / 10)
break;
if (k != ARRAY_SIZE(bclk_divs))
break;
}
}
if (j != ARRAY_SIZE(dac_divs))
break;
}
if (i != ARRAY_SIZE(sysclk_divs)) {
goto configure_clock;
} else if (wm8960->clk_id != WM8960_SYSCLK_AUTO) {
dev_err(codec->dev, "failed to configure clock\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(sysclk_divs); ++i) {
if (sysclk_divs[i] == -1)
continue;
for (j = 0; j < ARRAY_SIZE(dac_divs); ++j) {
sysclk = lrclk * dac_divs[j];
freq_out = sysclk * sysclk_divs[i];
for (k = 0; k < ARRAY_SIZE(bclk_divs); ++k) {
if (sysclk == bclk * bclk_divs[k] / 10 &&
is_pll_freq_available(freq_in, freq_out)) {
wm8960_set_pll(codec,
freq_in, freq_out);
break;
} else {
continue;
}
}
if (k != ARRAY_SIZE(bclk_divs))
break;
}
if (j != ARRAY_SIZE(dac_divs))
break;
}
if (i == ARRAY_SIZE(sysclk_divs)) {
dev_err(codec->dev, "failed to configure clock\n");
return -EINVAL;
}
configure_clock:
snd_soc_update_bits(codec, WM8960_CLOCK1, 3 << 1, i << 1);
snd_soc_update_bits(codec, WM8960_CLOCK1, 0x7 << 3, j << 3);
snd_soc_update_bits(codec, WM8960_CLOCK1, 0x7 << 6, j << 6);
snd_soc_update_bits(codec, WM8960_CLOCK2, 0xf, k);
return 0;
}
static int wm8960_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8960_IFACE1) & 0xfff3;
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
int i;
wm8960->bclk = snd_soc_params_to_bclk(params);
if (params_channels(params) == 1)
wm8960->bclk *= 2;
switch (params_width(params)) {
case 16:
break;
case 20:
iface |= 0x0004;
break;
case 24:
iface |= 0x0008;
break;
case 32:
if ((iface & 0x3) != 0) {
iface |= 0x000c;
break;
}
default:
dev_err(codec->dev, "unsupported width %d\n",
params_width(params));
return -EINVAL;
}
wm8960->lrclk = params_rate(params);
if (tx) {
wm8960_set_deemph(codec);
} else {
for (i = 0; i < ARRAY_SIZE(alc_rates); i++)
if (alc_rates[i].rate == params_rate(params))
snd_soc_update_bits(codec,
WM8960_ADDCTL3, 0x7,
alc_rates[i].val);
}
snd_soc_write(codec, WM8960_IFACE1, iface);
wm8960->is_stream_in_use[tx] = true;
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_ON &&
!wm8960->is_stream_in_use[!tx])
return wm8960_configure_clocking(codec);
return 0;
}
static int wm8960_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
wm8960->is_stream_in_use[tx] = false;
return 0;
}
static int wm8960_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute)
snd_soc_update_bits(codec, WM8960_DACCTL1, 0x8, 0x8);
else
snd_soc_update_bits(codec, WM8960_DACCTL1, 0x8, 0);
return 0;
}
static int wm8960_set_bias_level_out3(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
u16 pm2 = snd_soc_read(codec, WM8960_POWER2);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
switch (snd_soc_codec_get_bias_level(codec)) {
case SND_SOC_BIAS_STANDBY:
if (!IS_ERR(wm8960->mclk)) {
ret = clk_prepare_enable(wm8960->mclk);
if (ret) {
dev_err(codec->dev,
"Failed to enable MCLK: %d\n",
ret);
return ret;
}
}
ret = wm8960_configure_clocking(codec);
if (ret)
return ret;
snd_soc_update_bits(codec, WM8960_POWER1, 0x180, 0x80);
break;
case SND_SOC_BIAS_ON:
if (wm8960->clk_id == WM8960_SYSCLK_AUTO && (pm2 & 0x1))
wm8960_set_pll(codec, 0, 0);
if (!IS_ERR(wm8960->mclk))
clk_disable_unprepare(wm8960->mclk);
break;
default:
break;
}
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
regcache_sync(wm8960->regmap);
snd_soc_write(codec, WM8960_APOP1,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN | WM8960_BUFIOEN);
snd_soc_update_bits(codec, WM8960_POWER1, 0x80, 0x80);
msleep(100);
snd_soc_update_bits(codec, WM8960_POWER1, WM8960_VREF,
WM8960_VREF);
snd_soc_write(codec, WM8960_APOP1, WM8960_BUFIOEN);
}
snd_soc_update_bits(codec, WM8960_POWER1, 0x180, 0x100);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8960_APOP1,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN | WM8960_BUFIOEN);
snd_soc_write(codec, WM8960_POWER1, 0);
msleep(600);
break;
}
return 0;
}
static int wm8960_set_bias_level_capless(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
u16 pm2 = snd_soc_read(codec, WM8960_POWER2);
int reg, ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
switch (snd_soc_codec_get_bias_level(codec)) {
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, WM8960_APOP1,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN);
reg = 0;
if (wm8960->lout1 && wm8960->lout1->power)
reg |= WM8960_PWR2_LOUT1;
if (wm8960->rout1 && wm8960->rout1->power)
reg |= WM8960_PWR2_ROUT1;
if (wm8960->out3 && wm8960->out3->power)
reg |= WM8960_PWR2_OUT3;
snd_soc_update_bits(codec, WM8960_POWER2,
WM8960_PWR2_LOUT1 |
WM8960_PWR2_ROUT1 |
WM8960_PWR2_OUT3, reg);
snd_soc_update_bits(codec, WM8960_POWER1,
WM8960_VMID_MASK, 0x80);
msleep(100);
snd_soc_update_bits(codec, WM8960_POWER1,
WM8960_VREF, WM8960_VREF);
msleep(100);
if (!IS_ERR(wm8960->mclk)) {
ret = clk_prepare_enable(wm8960->mclk);
if (ret) {
dev_err(codec->dev,
"Failed to enable MCLK: %d\n",
ret);
return ret;
}
}
ret = wm8960_configure_clocking(codec);
if (ret)
return ret;
break;
case SND_SOC_BIAS_ON:
if (wm8960->clk_id == WM8960_SYSCLK_AUTO && (pm2 & 0x1))
wm8960_set_pll(codec, 0, 0);
if (!IS_ERR(wm8960->mclk))
clk_disable_unprepare(wm8960->mclk);
snd_soc_update_bits(codec, WM8960_APOP1,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN);
snd_soc_update_bits(codec, WM8960_POWER1,
WM8960_VREF | WM8960_VMID_MASK, 0);
break;
case SND_SOC_BIAS_OFF:
regcache_sync(wm8960->regmap);
break;
default:
break;
}
break;
case SND_SOC_BIAS_STANDBY:
switch (snd_soc_codec_get_bias_level(codec)) {
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8960_APOP2,
WM8960_DISOP | WM8960_DRES_MASK,
0);
snd_soc_update_bits(codec, WM8960_APOP1,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN,
WM8960_POBCTRL | WM8960_SOFT_ST |
WM8960_BUFDCOPEN);
break;
default:
break;
}
break;
case SND_SOC_BIAS_OFF:
break;
}
return 0;
}
static bool is_pll_freq_available(unsigned int source, unsigned int target)
{
unsigned int Ndiv;
if (source == 0 || target == 0)
return false;
target *= 4;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
Ndiv = target / source;
}
if ((Ndiv < 6) || (Ndiv > 12))
return false;
return true;
}
static int pll_factors(unsigned int source, unsigned int target,
struct _pll_div *pll_div)
{
unsigned long long Kpart;
unsigned int K, Ndiv, Nmod;
pr_debug("WM8960 PLL: setting %dHz->%dHz\n", source, target);
target *= 4;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
pll_div->pre_div = 1;
Ndiv = target / source;
} else
pll_div->pre_div = 0;
if ((Ndiv < 6) || (Ndiv > 12)) {
pr_err("WM8960 PLL: Unsupported N=%d\n", Ndiv);
return -EINVAL;
}
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div->k = K;
pr_debug("WM8960 PLL: N=%x K=%x pre_div=%d\n",
pll_div->n, pll_div->k, pll_div->pre_div);
return 0;
}
static int wm8960_set_pll(struct snd_soc_codec *codec,
unsigned int freq_in, unsigned int freq_out)
{
u16 reg;
static struct _pll_div pll_div;
int ret;
if (freq_in && freq_out) {
ret = pll_factors(freq_in, freq_out, &pll_div);
if (ret != 0)
return ret;
}
snd_soc_update_bits(codec, WM8960_CLOCK1, 0x1, 0);
snd_soc_update_bits(codec, WM8960_POWER2, 0x1, 0);
if (!freq_in || !freq_out)
return 0;
reg = snd_soc_read(codec, WM8960_PLL1) & ~0x3f;
reg |= pll_div.pre_div << 4;
reg |= pll_div.n;
if (pll_div.k) {
reg |= 0x20;
snd_soc_write(codec, WM8960_PLL2, (pll_div.k >> 16) & 0xff);
snd_soc_write(codec, WM8960_PLL3, (pll_div.k >> 8) & 0xff);
snd_soc_write(codec, WM8960_PLL4, pll_div.k & 0xff);
}
snd_soc_write(codec, WM8960_PLL1, reg);
snd_soc_update_bits(codec, WM8960_POWER2, 0x1, 0x1);
msleep(250);
snd_soc_update_bits(codec, WM8960_CLOCK1, 0x1, 0x1);
return 0;
}
static int wm8960_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
wm8960->freq_in = freq_in;
if (pll_id == WM8960_SYSCLK_AUTO)
return 0;
return wm8960_set_pll(codec, freq_in, freq_out);
}
static int wm8960_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8960_SYSCLKDIV:
reg = snd_soc_read(codec, WM8960_CLOCK1) & 0x1f9;
snd_soc_write(codec, WM8960_CLOCK1, reg | div);
break;
case WM8960_DACDIV:
reg = snd_soc_read(codec, WM8960_CLOCK1) & 0x1c7;
snd_soc_write(codec, WM8960_CLOCK1, reg | div);
break;
case WM8960_OPCLKDIV:
reg = snd_soc_read(codec, WM8960_PLL1) & 0x03f;
snd_soc_write(codec, WM8960_PLL1, reg | div);
break;
case WM8960_DCLKDIV:
reg = snd_soc_read(codec, WM8960_CLOCK2) & 0x03f;
snd_soc_write(codec, WM8960_CLOCK2, reg | div);
break;
case WM8960_TOCLKSEL:
reg = snd_soc_read(codec, WM8960_ADDCTL1) & 0x1fd;
snd_soc_write(codec, WM8960_ADDCTL1, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8960_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
return wm8960->set_bias_level(codec, level);
}
static int wm8960_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8960_SYSCLK_MCLK:
snd_soc_update_bits(codec, WM8960_CLOCK1,
0x1, WM8960_SYSCLK_MCLK);
break;
case WM8960_SYSCLK_PLL:
snd_soc_update_bits(codec, WM8960_CLOCK1,
0x1, WM8960_SYSCLK_PLL);
break;
case WM8960_SYSCLK_AUTO:
break;
default:
return -EINVAL;
}
wm8960->sysclk = freq;
wm8960->clk_id = clk_id;
return 0;
}
static int wm8960_probe(struct snd_soc_codec *codec)
{
struct wm8960_priv *wm8960 = snd_soc_codec_get_drvdata(codec);
struct wm8960_data *pdata = &wm8960->pdata;
if (pdata->capless)
wm8960->set_bias_level = wm8960_set_bias_level_capless;
else
wm8960->set_bias_level = wm8960_set_bias_level_out3;
snd_soc_add_codec_controls(codec, wm8960_snd_controls,
ARRAY_SIZE(wm8960_snd_controls));
wm8960_add_widgets(codec);
return 0;
}
static void wm8960_set_pdata_from_of(struct i2c_client *i2c,
struct wm8960_data *pdata)
{
const struct device_node *np = i2c->dev.of_node;
if (of_property_read_bool(np, "wlf,capless"))
pdata->capless = true;
if (of_property_read_bool(np, "wlf,shared-lrclk"))
pdata->shared_lrclk = true;
}
static int wm8960_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8960_data *pdata = dev_get_platdata(&i2c->dev);
struct wm8960_priv *wm8960;
int ret;
wm8960 = devm_kzalloc(&i2c->dev, sizeof(struct wm8960_priv),
GFP_KERNEL);
if (wm8960 == NULL)
return -ENOMEM;
wm8960->mclk = devm_clk_get(&i2c->dev, "mclk");
if (IS_ERR(wm8960->mclk)) {
if (PTR_ERR(wm8960->mclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
}
wm8960->regmap = devm_regmap_init_i2c(i2c, &wm8960_regmap);
if (IS_ERR(wm8960->regmap))
return PTR_ERR(wm8960->regmap);
if (pdata)
memcpy(&wm8960->pdata, pdata, sizeof(struct wm8960_data));
else if (i2c->dev.of_node)
wm8960_set_pdata_from_of(i2c, &wm8960->pdata);
ret = wm8960_reset(wm8960->regmap);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to issue reset\n");
return ret;
}
if (wm8960->pdata.shared_lrclk) {
ret = regmap_update_bits(wm8960->regmap, WM8960_ADDCTL2,
0x4, 0x4);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable LRCM: %d\n",
ret);
return ret;
}
}
regmap_update_bits(wm8960->regmap, WM8960_LINVOL, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_RINVOL, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_LADC, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_RADC, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_LDAC, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_RDAC, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_LOUT1, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_ROUT1, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_LOUT2, 0x100, 0x100);
regmap_update_bits(wm8960->regmap, WM8960_ROUT2, 0x100, 0x100);
i2c_set_clientdata(i2c, wm8960);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8960, &wm8960_dai, 1);
return ret;
}
static int wm8960_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
