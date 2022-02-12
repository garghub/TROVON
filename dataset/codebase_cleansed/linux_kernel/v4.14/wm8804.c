static int wm8804_aif_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct wm8804_priv *wm8804 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!wm8804->aif_pwr)
snd_soc_update_bits(codec, WM8804_PWRDN, 0x10, 0x0);
wm8804->aif_pwr++;
break;
case SND_SOC_DAPM_POST_PMD:
wm8804->aif_pwr--;
if (!wm8804->aif_pwr)
snd_soc_update_bits(codec, WM8804_PWRDN, 0x10, 0x10);
break;
}
return 0;
}
static int txsrc_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val = ucontrol->value.enumerated.item[0] << e->shift_l;
unsigned int mask = 1 << e->shift_l;
unsigned int txpwr;
if (val != 0 && val != mask)
return -EINVAL;
snd_soc_dapm_mutex_lock(dapm);
if (snd_soc_test_bits(codec, e->reg, mask, val)) {
txpwr = snd_soc_read(codec, WM8804_PWRDN) & 0x4;
snd_soc_update_bits(codec, WM8804_PWRDN, 0x4, 0x4);
snd_soc_update_bits(codec, e->reg, mask, val);
snd_soc_update_bits(codec, WM8804_PWRDN, 0x4, txpwr);
}
snd_soc_dapm_mutex_unlock(dapm);
return 0;
}
static bool wm8804_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8804_RST_DEVID1:
case WM8804_DEVID2:
case WM8804_DEVREV:
case WM8804_INTSTAT:
case WM8804_SPDSTAT:
case WM8804_RXCHAN1:
case WM8804_RXCHAN2:
case WM8804_RXCHAN3:
case WM8804_RXCHAN4:
case WM8804_RXCHAN5:
return true;
default:
return false;
}
}
static int wm8804_soft_reset(struct wm8804_priv *wm8804)
{
return regmap_write(wm8804->regmap, WM8804_RST_DEVID1, 0x0);
}
static int wm8804_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec;
u16 format, master, bcp, lrp;
codec = dai->codec;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
format = 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
format = 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
format = 0x1;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
format = 0x3;
break;
default:
dev_err(dai->dev, "Unknown dai format\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8804_AIFTX, 0x3, format);
snd_soc_update_bits(codec, WM8804_AIFRX, 0x3, format);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
master = 0;
break;
default:
dev_err(dai->dev, "Unknown master/slave configuration\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8804_AIFRX, 0x40, master << 6);
bcp = lrp = 0;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
bcp = lrp = 1;
break;
case SND_SOC_DAIFMT_IB_NF:
bcp = 1;
break;
case SND_SOC_DAIFMT_NB_IF:
lrp = 1;
break;
default:
dev_err(dai->dev, "Unknown polarity configuration\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8804_AIFTX, 0x10 | 0x20,
(bcp << 4) | (lrp << 5));
snd_soc_update_bits(codec, WM8804_AIFRX, 0x10 | 0x20,
(bcp << 4) | (lrp << 5));
return 0;
}
static int wm8804_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec;
u16 blen;
codec = dai->codec;
switch (params_width(params)) {
case 16:
blen = 0x0;
break;
case 20:
blen = 0x1;
break;
case 24:
blen = 0x2;
break;
default:
dev_err(dai->dev, "Unsupported word length: %u\n",
params_width(params));
return -EINVAL;
}
snd_soc_update_bits(codec, WM8804_AIFTX, 0xc, blen << 2);
snd_soc_update_bits(codec, WM8804_AIFRX, 0xc, blen << 2);
return 0;
}
static int pll_factors(struct pll_div *pll_div, unsigned int target,
unsigned int source, unsigned int mclk_div)
{
u64 Kpart;
unsigned long int K, Ndiv, Nmod, tmp;
int i;
for (i = 0; i < ARRAY_SIZE(post_table); i++) {
tmp = target * post_table[i].div;
if ((tmp >= 90000000 && tmp <= 100000000) &&
(mclk_div == post_table[i].mclkdiv)) {
pll_div->freqmode = post_table[i].freqmode;
pll_div->mclkdiv = post_table[i].mclkdiv;
target *= post_table[i].div;
break;
}
}
if (i == ARRAY_SIZE(post_table)) {
pr_err("%s: Unable to scale output frequency: %uHz\n",
__func__, target);
return -EINVAL;
}
pll_div->prescale = 0;
Ndiv = target / source;
if (Ndiv < 5) {
source >>= 1;
pll_div->prescale = 1;
Ndiv = target / source;
}
if (Ndiv < 5 || Ndiv > 13) {
pr_err("%s: WM8804 N value is not within the recommended range: %lu\n",
__func__, Ndiv);
return -EINVAL;
}
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (u64)Nmod;
do_div(Kpart, source);
K = Kpart & 0xffffffff;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div->k = K;
return 0;
}
static int wm8804_set_pll(struct snd_soc_dai *dai, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8804_priv *wm8804 = snd_soc_codec_get_drvdata(codec);
bool change;
if (!freq_in || !freq_out) {
regmap_update_bits_check(wm8804->regmap, WM8804_PWRDN,
0x1, 0x1, &change);
if (change)
pm_runtime_put(wm8804->dev);
} else {
int ret;
struct pll_div pll_div;
ret = pll_factors(&pll_div, freq_out, freq_in,
wm8804->mclk_div);
if (ret)
return ret;
regmap_update_bits_check(wm8804->regmap, WM8804_PWRDN,
0x1, 0x1, &change);
if (!change)
pm_runtime_get_sync(wm8804->dev);
snd_soc_update_bits(codec, WM8804_PLL4, 0xf | 0x10,
pll_div.n | (pll_div.prescale << 4));
snd_soc_update_bits(codec, WM8804_PLL5, 0x3 | 0x8,
pll_div.freqmode | (pll_div.mclkdiv << 3));
snd_soc_write(codec, WM8804_PLL1, pll_div.k & 0xff);
snd_soc_write(codec, WM8804_PLL2, (pll_div.k >> 8) & 0xff);
snd_soc_write(codec, WM8804_PLL3, pll_div.k >> 16);
snd_soc_update_bits(codec, WM8804_PWRDN, 0x1, 0);
}
return 0;
}
static int wm8804_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec;
codec = dai->codec;
switch (clk_id) {
case WM8804_TX_CLKSRC_MCLK:
if ((freq >= 10000000 && freq <= 14400000)
|| (freq >= 16280000 && freq <= 27000000))
snd_soc_update_bits(codec, WM8804_PLL6, 0x80, 0x80);
else {
dev_err(dai->dev, "OSCCLOCK is not within the "
"recommended range: %uHz\n", freq);
return -EINVAL;
}
break;
case WM8804_TX_CLKSRC_PLL:
snd_soc_update_bits(codec, WM8804_PLL6, 0x80, 0);
break;
case WM8804_CLKOUT_SRC_CLK1:
snd_soc_update_bits(codec, WM8804_PLL6, 0x8, 0);
break;
case WM8804_CLKOUT_SRC_OSCCLK:
snd_soc_update_bits(codec, WM8804_PLL6, 0x8, 0x8);
break;
default:
dev_err(dai->dev, "Unknown clock source: %d\n", clk_id);
return -EINVAL;
}
return 0;
}
static int wm8804_set_clkdiv(struct snd_soc_dai *dai,
int div_id, int div)
{
struct snd_soc_codec *codec;
struct wm8804_priv *wm8804;
codec = dai->codec;
switch (div_id) {
case WM8804_CLKOUT_DIV:
snd_soc_update_bits(codec, WM8804_PLL5, 0x30,
(div & 0x3) << 4);
break;
case WM8804_MCLK_DIV:
wm8804 = snd_soc_codec_get_drvdata(codec);
wm8804->mclk_div = div;
break;
default:
dev_err(dai->dev, "Unknown clock divider: %d\n", div_id);
return -EINVAL;
}
return 0;
}
int wm8804_probe(struct device *dev, struct regmap *regmap)
{
struct wm8804_priv *wm8804;
unsigned int id1, id2;
int i, ret;
wm8804 = devm_kzalloc(dev, sizeof(*wm8804), GFP_KERNEL);
if (!wm8804)
return -ENOMEM;
dev_set_drvdata(dev, wm8804);
wm8804->dev = dev;
wm8804->regmap = regmap;
wm8804->reset = devm_gpiod_get_optional(dev, "wlf,reset",
GPIOD_OUT_LOW);
if (IS_ERR(wm8804->reset)) {
ret = PTR_ERR(wm8804->reset);
dev_err(dev, "Failed to get reset line: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8804->supplies); i++)
wm8804->supplies[i].supply = wm8804_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8804->disable_nb[0].notifier_call = wm8804_regulator_event_0;
wm8804->disable_nb[1].notifier_call = wm8804_regulator_event_1;
for (i = 0; i < ARRAY_SIZE(wm8804->supplies); i++) {
struct regulator *regulator = wm8804->supplies[i].consumer;
ret = devm_regulator_register_notifier(regulator,
&wm8804->disable_nb[i]);
if (ret != 0) {
dev_err(dev,
"Failed to register regulator notifier: %d\n",
ret);
return ret;
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
gpiod_set_value_cansleep(wm8804->reset, 1);
ret = regmap_read(regmap, WM8804_RST_DEVID1, &id1);
if (ret < 0) {
dev_err(dev, "Failed to read device ID: %d\n", ret);
goto err_reg_enable;
}
ret = regmap_read(regmap, WM8804_DEVID2, &id2);
if (ret < 0) {
dev_err(dev, "Failed to read device ID: %d\n", ret);
goto err_reg_enable;
}
id2 = (id2 << 8) | id1;
if (id2 != 0x8805) {
dev_err(dev, "Invalid device ID: %#x\n", id2);
ret = -EINVAL;
goto err_reg_enable;
}
ret = regmap_read(regmap, WM8804_DEVREV, &id1);
if (ret < 0) {
dev_err(dev, "Failed to read device revision: %d\n",
ret);
goto err_reg_enable;
}
dev_info(dev, "revision %c\n", id1 + 'A');
if (!wm8804->reset) {
ret = wm8804_soft_reset(wm8804);
if (ret < 0) {
dev_err(dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
}
ret = snd_soc_register_codec(dev, &soc_codec_dev_wm8804,
&wm8804_dai, 1);
if (ret < 0) {
dev_err(dev, "Failed to register CODEC: %d\n", ret);
goto err_reg_enable;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_idle(dev);
return 0;
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8804->supplies), wm8804->supplies);
return ret;
}
void wm8804_remove(struct device *dev)
{
pm_runtime_disable(dev);
snd_soc_unregister_codec(dev);
}
static int wm8804_runtime_resume(struct device *dev)
{
struct wm8804_priv *wm8804 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(wm8804->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
regcache_sync(wm8804->regmap);
regmap_update_bits(wm8804->regmap, WM8804_PWRDN, 0x8, 0x0);
return 0;
}
static int wm8804_runtime_suspend(struct device *dev)
{
struct wm8804_priv *wm8804 = dev_get_drvdata(dev);
regmap_update_bits(wm8804->regmap, WM8804_PWRDN, 0x8, 0x8);
regulator_bulk_disable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
return 0;
}
