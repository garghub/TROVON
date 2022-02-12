static bool wm8955_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8955_LOUT1_VOLUME:
case WM8955_ROUT1_VOLUME:
case WM8955_DAC_CONTROL:
case WM8955_AUDIO_INTERFACE:
case WM8955_SAMPLE_RATE:
case WM8955_LEFT_DAC_VOLUME:
case WM8955_RIGHT_DAC_VOLUME:
case WM8955_BASS_CONTROL:
case WM8955_TREBLE_CONTROL:
case WM8955_RESET:
case WM8955_ADDITIONAL_CONTROL_1:
case WM8955_ADDITIONAL_CONTROL_2:
case WM8955_POWER_MANAGEMENT_1:
case WM8955_POWER_MANAGEMENT_2:
case WM8955_ADDITIONAL_CONTROL_3:
case WM8955_LEFT_OUT_MIX_1:
case WM8955_LEFT_OUT_MIX_2:
case WM8955_RIGHT_OUT_MIX_1:
case WM8955_RIGHT_OUT_MIX_2:
case WM8955_MONO_OUT_MIX_1:
case WM8955_MONO_OUT_MIX_2:
case WM8955_LOUT2_VOLUME:
case WM8955_ROUT2_VOLUME:
case WM8955_MONOOUT_VOLUME:
case WM8955_CLOCKING_PLL:
case WM8955_PLL_CONTROL_1:
case WM8955_PLL_CONTROL_2:
case WM8955_PLL_CONTROL_3:
case WM8955_PLL_CONTROL_4:
return true;
default:
return false;
}
}
static bool wm8955_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8955_RESET:
return true;
default:
return false;
}
}
static int wm8955_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8955_RESET, 0);
}
static int wm8995_pll_factors(struct device *dev,
int Fref, int Fout, struct pll_factors *pll)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, target;
dev_dbg(dev, "Fref=%u Fout=%u\n", Fref, Fout);
target = Fout * 4;
if (target < 90000000) {
pll->outdiv = 1;
target *= 2;
} else {
pll->outdiv = 0;
}
WARN_ON(target < 90000000 || target > 100000000);
dev_dbg(dev, "Fvco=%dHz\n", target);
Ndiv = target / Fref;
pll->n = Ndiv;
Nmod = target % Fref;
dev_dbg(dev, "Nmod=%d\n", Nmod);
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, Fref);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
pll->k = K / 10;
dev_dbg(dev, "N=%x K=%x OUTDIV=%x\n", pll->n, pll->k, pll->outdiv);
return 0;
}
static int wm8955_configure_clocking(struct snd_soc_codec *codec)
{
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
int i, ret, val;
int clocking = 0;
int srate = 0;
int sr = -1;
struct pll_factors pll;
if (wm8955->fs == 0)
wm8955->fs = 8000;
for (i = 0; i < ARRAY_SIZE(clock_cfgs); i++) {
if (wm8955->fs != clock_cfgs[i].fs)
continue;
sr = i;
if (wm8955->mclk_rate == clock_cfgs[i].mclk)
break;
}
if (sr == -1) {
dev_err(codec->dev, "Sample rate %dHz unsupported\n",
wm8955->fs);
WARN_ON(sr == -1);
return -EINVAL;
}
if (i == ARRAY_SIZE(clock_cfgs)) {
clocking |= WM8955_MCLKSEL;
ret = wm8995_pll_factors(codec->dev, wm8955->mclk_rate,
clock_cfgs[sr].mclk, &pll);
if (ret != 0) {
dev_err(codec->dev,
"Unable to generate %dHz from %dHz MCLK\n",
wm8955->fs, wm8955->mclk_rate);
return -EINVAL;
}
snd_soc_update_bits(codec, WM8955_PLL_CONTROL_1,
WM8955_N_MASK | WM8955_K_21_18_MASK,
(pll.n << WM8955_N_SHIFT) |
pll.k >> 18);
snd_soc_update_bits(codec, WM8955_PLL_CONTROL_2,
WM8955_K_17_9_MASK,
(pll.k >> 9) & WM8955_K_17_9_MASK);
snd_soc_update_bits(codec, WM8955_PLL_CONTROL_3,
WM8955_K_8_0_MASK,
pll.k & WM8955_K_8_0_MASK);
if (pll.k)
snd_soc_update_bits(codec, WM8955_PLL_CONTROL_4,
WM8955_KEN, WM8955_KEN);
else
snd_soc_update_bits(codec, WM8955_PLL_CONTROL_4,
WM8955_KEN, 0);
if (pll.outdiv)
val = WM8955_PLL_RB | WM8955_PLLOUTDIV2;
else
val = WM8955_PLL_RB;
snd_soc_update_bits(codec, WM8955_CLOCKING_PLL,
WM8955_PLL_RB | WM8955_PLLOUTDIV2, val);
snd_soc_update_bits(codec, WM8955_CLOCKING_PLL,
WM8955_PLLEN, WM8955_PLLEN);
}
srate = clock_cfgs[sr].usb | (clock_cfgs[sr].sr << WM8955_SR_SHIFT);
snd_soc_update_bits(codec, WM8955_SAMPLE_RATE,
WM8955_USB | WM8955_SR_MASK, srate);
snd_soc_update_bits(codec, WM8955_CLOCKING_PLL,
WM8955_MCLKSEL, clocking);
return 0;
}
static int wm8955_sysclk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
int ret = 0;
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_DIGENB, 0);
snd_soc_update_bits(codec, WM8955_CLOCKING_PLL,
WM8955_PLL_RB | WM8955_PLLEN, 0);
switch (event) {
case SND_SOC_DAPM_POST_PMD:
break;
case SND_SOC_DAPM_PRE_PMU:
ret = wm8955_configure_clocking(codec);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int wm8955_set_deemph(struct snd_soc_codec *codec)
{
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (wm8955->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(deemph_settings); i++) {
if (abs(deemph_settings[i] - wm8955->fs) <
abs(deemph_settings[best] - wm8955->fs))
best = i;
}
val = best << WM8955_DEEMPH_SHIFT;
} else {
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", val);
return snd_soc_update_bits(codec, WM8955_DAC_CONTROL,
WM8955_DEEMPH_MASK, val);
}
static int wm8955_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = wm8955->deemph;
return 0;
}
static int wm8955_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
unsigned int deemph = ucontrol->value.integer.value[0];
if (deemph > 1)
return -EINVAL;
wm8955->deemph = deemph;
return wm8955_set_deemph(codec);
}
static int wm8955_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
int ret;
int wl;
switch (params_width(params)) {
case 16:
wl = 0;
break;
case 20:
wl = 0x4;
break;
case 24:
wl = 0x8;
break;
case 32:
wl = 0xc;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8955_AUDIO_INTERFACE,
WM8955_WL_MASK, wl);
wm8955->fs = params_rate(params);
wm8955_set_deemph(codec);
ret = snd_soc_read(codec, WM8955_POWER_MANAGEMENT_1);
if (ret < 0)
return ret;
if (ret & WM8955_DIGENB) {
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_DIGENB, 0);
snd_soc_update_bits(codec, WM8955_CLOCKING_PLL,
WM8955_PLL_RB | WM8955_PLLEN, 0);
wm8955_configure_clocking(codec);
}
return 0;
}
static int wm8955_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8955_priv *priv = snd_soc_codec_get_drvdata(codec);
int div;
switch (clk_id) {
case WM8955_CLK_MCLK:
if (freq > 15000000) {
priv->mclk_rate = freq /= 2;
div = WM8955_MCLKDIV2;
} else {
priv->mclk_rate = freq;
div = 0;
}
snd_soc_update_bits(codec, WM8955_SAMPLE_RATE,
WM8955_MCLKDIV2, div);
break;
default:
return -EINVAL;
}
dev_dbg(dai->dev, "Clock source is %d at %uHz\n", clk_id, freq);
return 0;
}
static int wm8955_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u16 aif = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif |= WM8955_MS;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif |= WM8955_LRP;
case SND_SOC_DAIFMT_DSP_A:
aif |= 0x3;
break;
case SND_SOC_DAIFMT_I2S:
aif |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif |= 0x1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif |= WM8955_BCLKINV;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
aif |= WM8955_BCLKINV | WM8955_LRP;
break;
case SND_SOC_DAIFMT_IB_NF:
aif |= WM8955_BCLKINV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif |= WM8955_LRP;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8955_AUDIO_INTERFACE,
WM8955_MS | WM8955_FORMAT_MASK | WM8955_BCLKINV |
WM8955_LRP, aif);
return 0;
}
static int wm8955_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int val;
if (mute)
val = WM8955_DACMU;
else
val = 0;
snd_soc_update_bits(codec, WM8955_DAC_CONTROL, WM8955_DACMU, val);
return 0;
}
static int wm8955_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_VMIDSEL_MASK,
0x1 << WM8955_VMIDSEL_SHIFT);
snd_soc_update_bits(codec, WM8955_ADDITIONAL_CONTROL_1,
WM8955_VSEL_MASK,
0x2 << WM8955_VSEL_SHIFT);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8955->supplies),
wm8955->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
regcache_sync(wm8955->regmap);
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_VREF |
WM8955_VMIDSEL_MASK,
WM8955_VREF |
0x3 << WM8955_VREF_SHIFT);
msleep(500);
snd_soc_update_bits(codec,
WM8955_ADDITIONAL_CONTROL_3,
WM8955_VROI, WM8955_VROI);
}
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_VMIDSEL_MASK,
0x2 << WM8955_VMIDSEL_SHIFT);
snd_soc_update_bits(codec, WM8955_ADDITIONAL_CONTROL_1,
WM8955_VSEL_MASK, 0);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec,
WM8955_ADDITIONAL_CONTROL_3,
WM8955_VROI, 0);
snd_soc_update_bits(codec, WM8955_POWER_MANAGEMENT_1,
WM8955_VREF |
WM8955_VMIDSEL_MASK, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8955->supplies),
wm8955->supplies);
break;
}
return 0;
}
static int wm8955_probe(struct snd_soc_codec *codec)
{
struct wm8955_priv *wm8955 = snd_soc_codec_get_drvdata(codec);
struct wm8955_pdata *pdata = dev_get_platdata(codec->dev);
int ret, i;
for (i = 0; i < ARRAY_SIZE(wm8955->supplies); i++)
wm8955->supplies[i].supply = wm8955_supply_names[i];
ret = devm_regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8955->supplies),
wm8955->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8955->supplies),
wm8955->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = wm8955_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_enable;
}
snd_soc_update_bits(codec, WM8955_LEFT_DAC_VOLUME,
WM8955_LDVU, WM8955_LDVU);
snd_soc_update_bits(codec, WM8955_RIGHT_DAC_VOLUME,
WM8955_RDVU, WM8955_RDVU);
snd_soc_update_bits(codec, WM8955_LOUT1_VOLUME,
WM8955_LO1VU | WM8955_LO1ZC,
WM8955_LO1VU | WM8955_LO1ZC);
snd_soc_update_bits(codec, WM8955_ROUT1_VOLUME,
WM8955_RO1VU | WM8955_RO1ZC,
WM8955_RO1VU | WM8955_RO1ZC);
snd_soc_update_bits(codec, WM8955_LOUT2_VOLUME,
WM8955_LO2VU | WM8955_LO2ZC,
WM8955_LO2VU | WM8955_LO2ZC);
snd_soc_update_bits(codec, WM8955_ROUT2_VOLUME,
WM8955_RO2VU | WM8955_RO2ZC,
WM8955_RO2VU | WM8955_RO2ZC);
snd_soc_update_bits(codec, WM8955_MONOOUT_VOLUME,
WM8955_MOZC, WM8955_MOZC);
snd_soc_update_bits(codec, WM8955_BASS_CONTROL, WM8955_BB, WM8955_BB);
if (pdata) {
if (pdata->out2_speaker)
snd_soc_update_bits(codec, WM8955_ADDITIONAL_CONTROL_2,
WM8955_ROUT2INV, WM8955_ROUT2INV);
if (pdata->monoin_diff)
snd_soc_update_bits(codec, WM8955_MONO_OUT_MIX_1,
WM8955_DMEN, WM8955_DMEN);
}
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(wm8955->supplies), wm8955->supplies);
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8955->supplies), wm8955->supplies);
return ret;
}
static int wm8955_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8955_priv *wm8955;
int ret;
wm8955 = devm_kzalloc(&i2c->dev, sizeof(struct wm8955_priv),
GFP_KERNEL);
if (wm8955 == NULL)
return -ENOMEM;
wm8955->regmap = devm_regmap_init_i2c(i2c, &wm8955_regmap);
if (IS_ERR(wm8955->regmap)) {
ret = PTR_ERR(wm8955->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(i2c, wm8955);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8955, &wm8955_dai, 1);
return ret;
}
static int wm8955_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
