static bool wm8580_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8580_RESET:
return true;
default:
return false;
}
}
static int wm8580_out_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
int ret;
regcache_cache_only(wm8580->regmap, true);
regmap_update_bits(wm8580->regmap, reg, 0x100, 0x000);
regmap_update_bits(wm8580->regmap, reg2, 0x100, 0x000);
regcache_cache_only(wm8580->regmap, false);
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret < 0)
return ret;
snd_soc_update_bits(codec, reg, 0x100, 0x100);
snd_soc_update_bits(codec, reg2, 0x100, 0x100);
return 0;
}
static int pll_factors(struct _pll_div *pll_div, unsigned int target,
unsigned int source)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod;
int i;
pr_debug("wm8580: PLL %uHz->%uHz\n", source, target);
for (i = 0; i < ARRAY_SIZE(post_table); i++) {
if (target * post_table[i].div >= 90000000 &&
target * post_table[i].div <= 100000000) {
pll_div->freqmode = post_table[i].freqmode;
pll_div->postscale = post_table[i].postscale;
target *= post_table[i].div;
break;
}
}
if (i == ARRAY_SIZE(post_table)) {
printk(KERN_ERR "wm8580: Unable to scale output frequency "
"%u\n", target);
return -EINVAL;
}
Ndiv = target / source;
if (Ndiv < 5) {
source /= 2;
pll_div->prescale = 1;
Ndiv = target / source;
} else
pll_div->prescale = 0;
if ((Ndiv < 5) || (Ndiv > 13)) {
printk(KERN_ERR
"WM8580 N=%u outside supported range\n", Ndiv);
return -EINVAL;
}
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
pll_div->k = K;
pr_debug("PLL %x.%x prescale %d freqmode %d postscale %d\n",
pll_div->n, pll_div->k, pll_div->prescale, pll_div->freqmode,
pll_div->postscale);
return 0;
}
static int wm8580_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
int offset;
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
struct pll_state *state;
struct _pll_div pll_div;
unsigned int reg;
unsigned int pwr_mask;
int ret;
memset(&pll_div, 0, sizeof(pll_div));
switch (pll_id) {
case WM8580_PLLA:
state = &wm8580->a;
offset = 0;
pwr_mask = WM8580_PWRDN2_PLLAPD;
break;
case WM8580_PLLB:
state = &wm8580->b;
offset = 4;
pwr_mask = WM8580_PWRDN2_PLLBPD;
break;
default:
return -ENODEV;
}
if (freq_in && freq_out) {
ret = pll_factors(&pll_div, freq_out, freq_in);
if (ret != 0)
return ret;
}
state->in = freq_in;
state->out = freq_out;
snd_soc_update_bits(codec, WM8580_PWRDN2, pwr_mask, pwr_mask);
if (!freq_in || !freq_out)
return 0;
snd_soc_write(codec, WM8580_PLLA1 + offset, pll_div.k & 0x1ff);
snd_soc_write(codec, WM8580_PLLA2 + offset, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8580_PLLA3 + offset,
(pll_div.k >> 18 & 0xf) | (pll_div.n << 4));
reg = snd_soc_read(codec, WM8580_PLLA4 + offset);
reg &= ~0x1b;
reg |= pll_div.prescale | pll_div.postscale << 1 |
pll_div.freqmode << 3;
snd_soc_write(codec, WM8580_PLLA4 + offset, reg);
snd_soc_update_bits(codec, WM8580_PWRDN2, pwr_mask, 0);
return 0;
}
static int wm8580_paif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
u16 paifa = 0;
u16 paifb = 0;
int i, ratio, osr;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
paifa |= 0x8;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
paifa |= 0x0;
paifb |= WM8580_AIF_LENGTH_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
paifa |= 0x0;
paifb |= WM8580_AIF_LENGTH_24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
paifa |= 0x0;
paifb |= WM8580_AIF_LENGTH_32;
break;
default:
return -EINVAL;
}
ratio = wm8580->sysclk[dai->driver->id] / params_rate(params);
for (i = 0; i < ARRAY_SIZE(wm8580_sysclk_ratios); i++)
if (ratio == wm8580_sysclk_ratios[i])
break;
if (i == ARRAY_SIZE(wm8580_sysclk_ratios)) {
dev_err(codec->dev, "Invalid clock ratio %d/%d\n",
wm8580->sysclk[dai->driver->id], params_rate(params));
return -EINVAL;
}
paifa |= i;
dev_dbg(codec->dev, "Running at %dfs with %dHz clock\n",
wm8580_sysclk_ratios[i], wm8580->sysclk[dai->driver->id]);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
switch (ratio) {
case 128:
case 192:
osr = WM8580_DACOSR;
dev_dbg(codec->dev, "Selecting 64x OSR\n");
break;
default:
osr = 0;
dev_dbg(codec->dev, "Selecting 128x OSR\n");
break;
}
snd_soc_update_bits(codec, WM8580_PAIF3, WM8580_DACOSR, osr);
}
snd_soc_update_bits(codec, WM8580_PAIF1 + dai->driver->id,
WM8580_AIF_RATE_MASK | WM8580_AIF_BCLKSEL_MASK,
paifa);
snd_soc_update_bits(codec, WM8580_PAIF3 + dai->driver->id,
WM8580_AIF_LENGTH_MASK, paifb);
return 0;
}
static int wm8580_set_paif_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int aifa;
unsigned int aifb;
int can_invert_lrclk;
aifa = snd_soc_read(codec, WM8580_PAIF1 + codec_dai->driver->id);
aifb = snd_soc_read(codec, WM8580_PAIF3 + codec_dai->driver->id);
aifb &= ~(WM8580_AIF_FMT_MASK | WM8580_AIF_LRP | WM8580_AIF_BCP);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
aifa &= ~WM8580_AIF_MS;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aifa |= WM8580_AIF_MS;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
can_invert_lrclk = 1;
aifb |= WM8580_AIF_FMT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
can_invert_lrclk = 1;
aifb |= WM8580_AIF_FMT_RIGHTJ;
break;
case SND_SOC_DAIFMT_LEFT_J:
can_invert_lrclk = 1;
aifb |= WM8580_AIF_FMT_LEFTJ;
break;
case SND_SOC_DAIFMT_DSP_A:
can_invert_lrclk = 0;
aifb |= WM8580_AIF_FMT_DSP;
break;
case SND_SOC_DAIFMT_DSP_B:
can_invert_lrclk = 0;
aifb |= WM8580_AIF_FMT_DSP;
aifb |= WM8580_AIF_LRP;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
if (!can_invert_lrclk)
return -EINVAL;
aifb |= WM8580_AIF_BCP;
aifb |= WM8580_AIF_LRP;
break;
case SND_SOC_DAIFMT_IB_NF:
aifb |= WM8580_AIF_BCP;
break;
case SND_SOC_DAIFMT_NB_IF:
if (!can_invert_lrclk)
return -EINVAL;
aifb |= WM8580_AIF_LRP;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8580_PAIF1 + codec_dai->driver->id, aifa);
snd_soc_write(codec, WM8580_PAIF3 + codec_dai->driver->id, aifb);
return 0;
}
static int wm8580_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int reg;
switch (div_id) {
case WM8580_MCLK:
reg = snd_soc_read(codec, WM8580_PLLB4);
reg &= ~WM8580_PLLB4_MCLKOUTSRC_MASK;
switch (div) {
case WM8580_CLKSRC_MCLK:
break;
case WM8580_CLKSRC_PLLA:
reg |= WM8580_PLLB4_MCLKOUTSRC_PLLA;
break;
case WM8580_CLKSRC_PLLB:
reg |= WM8580_PLLB4_MCLKOUTSRC_PLLB;
break;
case WM8580_CLKSRC_OSC:
reg |= WM8580_PLLB4_MCLKOUTSRC_OSC;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8580_PLLB4, reg);
break;
case WM8580_CLKOUTSRC:
reg = snd_soc_read(codec, WM8580_PLLB4);
reg &= ~WM8580_PLLB4_CLKOUTSRC_MASK;
switch (div) {
case WM8580_CLKSRC_NONE:
break;
case WM8580_CLKSRC_PLLA:
reg |= WM8580_PLLB4_CLKOUTSRC_PLLACLK;
break;
case WM8580_CLKSRC_PLLB:
reg |= WM8580_PLLB4_CLKOUTSRC_PLLBCLK;
break;
case WM8580_CLKSRC_OSC:
reg |= WM8580_PLLB4_CLKOUTSRC_OSCCLK;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8580_PLLB4, reg);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8580_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
int ret, sel, sel_mask, sel_shift;
switch (dai->driver->id) {
case WM8580_DAI_PAIFRX:
sel_mask = 0x3;
sel_shift = 0;
break;
case WM8580_DAI_PAIFTX:
sel_mask = 0xc;
sel_shift = 2;
break;
default:
WARN(1, "Unknown DAI driver ID\n");
return -EINVAL;
}
switch (clk_id) {
case WM8580_CLKSRC_ADCMCLK:
if (dai->driver->id != WM8580_DAI_PAIFTX)
return -EINVAL;
sel = 0 << sel_shift;
break;
case WM8580_CLKSRC_PLLA:
sel = 1 << sel_shift;
break;
case WM8580_CLKSRC_PLLB:
sel = 2 << sel_shift;
break;
case WM8580_CLKSRC_MCLK:
sel = 3 << sel_shift;
break;
default:
dev_err(codec->dev, "Unknown clock %d\n", clk_id);
return -EINVAL;
}
wm8580->sysclk[dai->driver->id] = freq;
ret = snd_soc_update_bits(codec, WM8580_CLKSEL, sel_mask, sel);
if (ret < 0)
return ret;
return 0;
}
static int wm8580_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int reg;
reg = snd_soc_read(codec, WM8580_DAC_CONTROL5);
if (mute)
reg |= WM8580_DAC_CONTROL5_MUTEALL;
else
reg &= ~WM8580_DAC_CONTROL5_MUTEALL;
snd_soc_write(codec, WM8580_DAC_CONTROL5, reg);
return 0;
}
static int wm8580_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, WM8580_PWRDN1,
WM8580_PWRDN1_PWDN |
WM8580_PWRDN1_ALLDACPD, 0);
snd_soc_update_bits(codec, WM8580_ADC_CONTROL1,
0x100, 0);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8580_PWRDN1,
WM8580_PWRDN1_PWDN, WM8580_PWRDN1_PWDN);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8580_probe(struct snd_soc_codec *codec)
{
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8580->supplies),
wm8580->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_regulator_get;
}
ret = snd_soc_write(codec, WM8580_RESET, 0);
if (ret != 0) {
dev_err(codec->dev, "Failed to reset codec: %d\n", ret);
goto err_regulator_enable;
}
wm8580_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
err_regulator_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8580->supplies), wm8580->supplies);
err_regulator_get:
return ret;
}
static int wm8580_remove(struct snd_soc_codec *codec)
{
struct wm8580_priv *wm8580 = snd_soc_codec_get_drvdata(codec);
wm8580_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_disable(ARRAY_SIZE(wm8580->supplies), wm8580->supplies);
return 0;
}
static int wm8580_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8580_priv *wm8580;
int ret, i;
wm8580 = devm_kzalloc(&i2c->dev, sizeof(struct wm8580_priv),
GFP_KERNEL);
if (wm8580 == NULL)
return -ENOMEM;
wm8580->regmap = devm_regmap_init_i2c(i2c, &wm8580_regmap);
if (IS_ERR(wm8580->regmap))
return PTR_ERR(wm8580->regmap);
for (i = 0; i < ARRAY_SIZE(wm8580->supplies); i++)
wm8580->supplies[i].supply = wm8580_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8580->supplies),
wm8580->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, wm8580);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8580, wm8580_dai, ARRAY_SIZE(wm8580_dai));
return ret;
}
static int wm8580_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8580_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8580_i2c_driver);
if (ret != 0) {
pr_err("Failed to register WM8580 I2C driver: %d\n", ret);
}
#endif
return ret;
}
static void __exit wm8580_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8580_i2c_driver);
#endif
}
