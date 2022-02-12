static bool wm9081_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM9081_SOFTWARE_RESET:
case WM9081_INTERRUPT_STATUS:
return true;
default:
return false;
}
}
static bool wm9081_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM9081_SOFTWARE_RESET:
case WM9081_ANALOGUE_LINEOUT:
case WM9081_ANALOGUE_SPEAKER_PGA:
case WM9081_VMID_CONTROL:
case WM9081_BIAS_CONTROL_1:
case WM9081_ANALOGUE_MIXER:
case WM9081_ANTI_POP_CONTROL:
case WM9081_ANALOGUE_SPEAKER_1:
case WM9081_ANALOGUE_SPEAKER_2:
case WM9081_POWER_MANAGEMENT:
case WM9081_CLOCK_CONTROL_1:
case WM9081_CLOCK_CONTROL_2:
case WM9081_CLOCK_CONTROL_3:
case WM9081_FLL_CONTROL_1:
case WM9081_FLL_CONTROL_2:
case WM9081_FLL_CONTROL_3:
case WM9081_FLL_CONTROL_4:
case WM9081_FLL_CONTROL_5:
case WM9081_AUDIO_INTERFACE_1:
case WM9081_AUDIO_INTERFACE_2:
case WM9081_AUDIO_INTERFACE_3:
case WM9081_AUDIO_INTERFACE_4:
case WM9081_INTERRUPT_STATUS:
case WM9081_INTERRUPT_STATUS_MASK:
case WM9081_INTERRUPT_POLARITY:
case WM9081_INTERRUPT_CONTROL:
case WM9081_DAC_DIGITAL_1:
case WM9081_DAC_DIGITAL_2:
case WM9081_DRC_1:
case WM9081_DRC_2:
case WM9081_DRC_3:
case WM9081_DRC_4:
case WM9081_WRITE_SEQUENCER_1:
case WM9081_WRITE_SEQUENCER_2:
case WM9081_MW_SLAVE_1:
case WM9081_EQ_1:
case WM9081_EQ_2:
case WM9081_EQ_3:
case WM9081_EQ_4:
case WM9081_EQ_5:
case WM9081_EQ_6:
case WM9081_EQ_7:
case WM9081_EQ_8:
case WM9081_EQ_9:
case WM9081_EQ_10:
case WM9081_EQ_11:
case WM9081_EQ_12:
case WM9081_EQ_13:
case WM9081_EQ_14:
case WM9081_EQ_15:
case WM9081_EQ_16:
case WM9081_EQ_17:
case WM9081_EQ_18:
case WM9081_EQ_19:
case WM9081_EQ_20:
return true;
default:
return false;
}
}
static int wm9081_reset(struct regmap *map)
{
return regmap_write(map, WM9081_SOFTWARE_RESET, 0x9081);
}
static int speaker_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg;
reg = snd_soc_read(codec, WM9081_ANALOGUE_SPEAKER_2);
if (reg & WM9081_SPK_MODE)
ucontrol->value.integer.value[0] = 1;
else
ucontrol->value.integer.value[0] = 0;
return 0;
}
static int speaker_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg_pwr = snd_soc_read(codec, WM9081_POWER_MANAGEMENT);
unsigned int reg2 = snd_soc_read(codec, WM9081_ANALOGUE_SPEAKER_2);
if (ucontrol->value.integer.value[0] ==
((reg2 & WM9081_SPK_MODE) != 0))
return 0;
if (reg_pwr & WM9081_SPK_ENA)
return -EINVAL;
if (ucontrol->value.integer.value[0]) {
reg2 &= ~(WM9081_SPK_INV_MUTE | WM9081_OUT_SPK_CTRL);
reg2 |= WM9081_SPK_MODE;
} else {
reg2 |= WM9081_SPK_INV_MUTE | WM9081_OUT_SPK_CTRL;
reg2 &= ~WM9081_SPK_MODE;
}
snd_soc_write(codec, WM9081_ANALOGUE_SPEAKER_2, reg2);
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, target;
unsigned int div;
int i;
div = 1;
while ((Fref / div) > 13500000) {
div *= 2;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
fll_div->fll_clk_ref_div = div / 2;
pr_debug("Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
div = 0;
target = Fout * 2;
while (target < 90000000) {
div++;
target *= 2;
if (div > 7) {
pr_err("Unable to find FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
fll_div->fll_outdiv = div;
pr_debug("Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
target /= fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
Ndiv = target / Fref;
fll_div->n = Ndiv;
Nmod = target % Fref;
pr_debug("Nmod=%d\n", Nmod);
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, Fref);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
fll_div->k = K / 10;
pr_debug("N=%x K=%x FLL_FRATIO=%x FLL_OUTDIV=%x FLL_CLK_REF_DIV=%x\n",
fll_div->n, fll_div->k,
fll_div->fll_fratio, fll_div->fll_outdiv,
fll_div->fll_clk_ref_div);
return 0;
}
static int wm9081_set_fll(struct snd_soc_codec *codec, int fll_id,
unsigned int Fref, unsigned int Fout)
{
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
u16 reg1, reg4, reg5;
struct _fll_div fll_div;
int ret;
int clk_sys_reg;
if (Fref == wm9081->fll_fref && Fout == wm9081->fll_fout)
return 0;
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm9081->fll_fref = 0;
wm9081->fll_fout = 0;
return 0;
}
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
reg5 = snd_soc_read(codec, WM9081_FLL_CONTROL_5);
reg5 &= ~WM9081_FLL_CLK_SRC_MASK;
switch (fll_id) {
case WM9081_SYSCLK_FLL_MCLK:
reg5 |= 0x1;
break;
default:
dev_err(codec->dev, "Unknown FLL ID %d\n", fll_id);
return -EINVAL;
}
clk_sys_reg = snd_soc_read(codec, WM9081_CLOCK_CONTROL_3);
if (clk_sys_reg & WM9081_CLK_SYS_ENA)
snd_soc_write(codec, WM9081_CLOCK_CONTROL_3,
clk_sys_reg & ~WM9081_CLK_SYS_ENA);
reg1 = snd_soc_read(codec, WM9081_FLL_CONTROL_1);
reg1 &= ~WM9081_FLL_ENA;
snd_soc_write(codec, WM9081_FLL_CONTROL_1, reg1);
if (fll_div.k)
reg1 |= WM9081_FLL_FRAC_MASK;
else
reg1 &= ~WM9081_FLL_FRAC_MASK;
snd_soc_write(codec, WM9081_FLL_CONTROL_1, reg1);
snd_soc_write(codec, WM9081_FLL_CONTROL_2,
(fll_div.fll_outdiv << WM9081_FLL_OUTDIV_SHIFT) |
(fll_div.fll_fratio << WM9081_FLL_FRATIO_SHIFT));
snd_soc_write(codec, WM9081_FLL_CONTROL_3, fll_div.k);
reg4 = snd_soc_read(codec, WM9081_FLL_CONTROL_4);
reg4 &= ~WM9081_FLL_N_MASK;
reg4 |= fll_div.n << WM9081_FLL_N_SHIFT;
snd_soc_write(codec, WM9081_FLL_CONTROL_4, reg4);
reg5 &= ~WM9081_FLL_CLK_REF_DIV_MASK;
reg5 |= fll_div.fll_clk_ref_div << WM9081_FLL_CLK_REF_DIV_SHIFT;
snd_soc_write(codec, WM9081_FLL_CONTROL_5, reg5);
snd_soc_update_bits(codec, WM9081_FLL_CONTROL_4,
WM9081_FLL_GAIN_MASK, 0);
snd_soc_write(codec, WM9081_FLL_CONTROL_1, reg1 | WM9081_FLL_ENA);
if (clk_sys_reg & WM9081_CLK_SYS_ENA)
snd_soc_write(codec, WM9081_CLOCK_CONTROL_3, clk_sys_reg);
dev_dbg(codec->dev, "FLL enabled at %dHz->%dHz\n", Fref, Fout);
wm9081->fll_fref = Fref;
wm9081->fll_fout = Fout;
return 0;
}
static int configure_clock(struct snd_soc_codec *codec)
{
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
int new_sysclk, i, target;
unsigned int reg;
int ret = 0;
int mclkdiv = 0;
int fll = 0;
switch (wm9081->sysclk_source) {
case WM9081_SYSCLK_MCLK:
if (wm9081->mclk_rate > 12225000) {
mclkdiv = 1;
wm9081->sysclk_rate = wm9081->mclk_rate / 2;
} else {
wm9081->sysclk_rate = wm9081->mclk_rate;
}
wm9081_set_fll(codec, WM9081_SYSCLK_FLL_MCLK, 0, 0);
break;
case WM9081_SYSCLK_FLL_MCLK:
if (wm9081->master && wm9081->bclk) {
for (i = 0; i < ARRAY_SIZE(clk_sys_rates); i++) {
target = wm9081->fs * clk_sys_rates[i].ratio;
new_sysclk = target;
if (target >= wm9081->bclk &&
target > 3000000)
break;
}
if (i == ARRAY_SIZE(clk_sys_rates))
return -EINVAL;
} else if (wm9081->fs) {
for (i = 0; i < ARRAY_SIZE(clk_sys_rates); i++) {
new_sysclk = clk_sys_rates[i].ratio
* wm9081->fs;
if (new_sysclk > 3000000)
break;
}
if (i == ARRAY_SIZE(clk_sys_rates))
return -EINVAL;
} else {
new_sysclk = 12288000;
}
ret = wm9081_set_fll(codec, WM9081_SYSCLK_FLL_MCLK,
wm9081->mclk_rate, new_sysclk);
if (ret == 0) {
wm9081->sysclk_rate = new_sysclk;
fll = 1;
} else {
wm9081->sysclk_rate = wm9081->mclk_rate;
}
break;
default:
return -EINVAL;
}
reg = snd_soc_read(codec, WM9081_CLOCK_CONTROL_1);
if (mclkdiv)
reg |= WM9081_MCLKDIV2;
else
reg &= ~WM9081_MCLKDIV2;
snd_soc_write(codec, WM9081_CLOCK_CONTROL_1, reg);
reg = snd_soc_read(codec, WM9081_CLOCK_CONTROL_3);
if (fll)
reg |= WM9081_CLK_SRC_SEL;
else
reg &= ~WM9081_CLK_SRC_SEL;
snd_soc_write(codec, WM9081_CLOCK_CONTROL_3, reg);
dev_dbg(codec->dev, "CLK_SYS is %dHz\n", wm9081->sysclk_rate);
return ret;
}
static int clk_sys_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
switch (wm9081->sysclk_source) {
case WM9081_SYSCLK_MCLK:
dev_dbg(codec->dev, "Using %dHz MCLK\n", wm9081->mclk_rate);
break;
case WM9081_SYSCLK_FLL_MCLK:
dev_dbg(codec->dev, "Using %dHz MCLK with FLL\n",
wm9081->mclk_rate);
break;
default:
dev_err(codec->dev, "System clock not configured\n");
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
configure_clock(codec);
break;
case SND_SOC_DAPM_POST_PMD:
wm9081_set_fll(codec, 0, 0, 0);
break;
}
return 0;
}
static int wm9081_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM9081_VMID_CONTROL,
WM9081_VMID_SEL_MASK, 0x2);
snd_soc_update_bits(codec, WM9081_BIAS_CONTROL_1,
WM9081_STBY_BIAS_ENA, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_cache_only(wm9081->regmap, false);
regcache_sync(wm9081->regmap);
snd_soc_update_bits(codec, WM9081_ANTI_POP_CONTROL,
WM9081_LINEOUT_DISCH, 0);
snd_soc_update_bits(codec, WM9081_BIAS_CONTROL_1,
WM9081_BIAS_SRC | WM9081_BIAS_ENA,
WM9081_BIAS_SRC | WM9081_BIAS_ENA);
snd_soc_update_bits(codec, WM9081_VMID_CONTROL,
WM9081_VMID_RAMP |
WM9081_VMID_SEL_MASK,
WM9081_VMID_RAMP | 0x6);
mdelay(100);
snd_soc_update_bits(codec, WM9081_VMID_CONTROL,
WM9081_VMID_RAMP, 0);
snd_soc_update_bits(codec, WM9081_BIAS_CONTROL_1,
WM9081_BIAS_SRC, 0);
}
snd_soc_update_bits(codec, WM9081_VMID_CONTROL,
WM9081_VMID_SEL_MASK, 0x04);
snd_soc_update_bits(codec, WM9081_BIAS_CONTROL_1,
WM9081_STBY_BIAS_ENA,
WM9081_STBY_BIAS_ENA);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM9081_BIAS_CONTROL_1,
WM9081_BIAS_SRC | WM9081_BIAS_ENA,
WM9081_BIAS_SRC);
snd_soc_update_bits(codec, WM9081_VMID_CONTROL,
WM9081_VMID_RAMP | WM9081_VMID_SEL_MASK,
WM9081_VMID_RAMP);
snd_soc_update_bits(codec, WM9081_ANTI_POP_CONTROL,
WM9081_LINEOUT_DISCH,
WM9081_LINEOUT_DISCH);
regcache_cache_only(wm9081->regmap, true);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm9081_set_dai_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
unsigned int aif2 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_2);
aif2 &= ~(WM9081_AIF_BCLK_INV | WM9081_AIF_LRCLK_INV |
WM9081_BCLK_DIR | WM9081_LRCLK_DIR | WM9081_AIF_FMT_MASK);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
wm9081->master = 0;
break;
case SND_SOC_DAIFMT_CBS_CFM:
aif2 |= WM9081_LRCLK_DIR;
wm9081->master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFS:
aif2 |= WM9081_BCLK_DIR;
wm9081->master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif2 |= WM9081_LRCLK_DIR | WM9081_BCLK_DIR;
wm9081->master = 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif2 |= WM9081_AIF_LRCLK_INV;
case SND_SOC_DAIFMT_DSP_A:
aif2 |= 0x3;
break;
case SND_SOC_DAIFMT_I2S:
aif2 |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif2 |= 0x1;
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
aif2 |= WM9081_AIF_BCLK_INV;
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
aif2 |= WM9081_AIF_BCLK_INV | WM9081_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif2 |= WM9081_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif2 |= WM9081_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM9081_AUDIO_INTERFACE_2, aif2);
return 0;
}
static int wm9081_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
int ret, i, best, best_val, cur_val;
unsigned int clk_ctrl2, aif1, aif2, aif3, aif4;
clk_ctrl2 = snd_soc_read(codec, WM9081_CLOCK_CONTROL_2);
clk_ctrl2 &= ~(WM9081_CLK_SYS_RATE_MASK | WM9081_SAMPLE_RATE_MASK);
aif1 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_1);
aif2 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_2);
aif2 &= ~WM9081_AIF_WL_MASK;
aif3 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_3);
aif3 &= ~WM9081_BCLK_DIV_MASK;
aif4 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_4);
aif4 &= ~WM9081_LRCLK_RATE_MASK;
wm9081->fs = params_rate(params);
if (wm9081->tdm_width) {
int slots = ((aif1 & WM9081_AIFDAC_TDM_MODE_MASK) >>
WM9081_AIFDAC_TDM_MODE_SHIFT) + 1;
wm9081->bclk = wm9081->fs * wm9081->tdm_width * slots;
} else {
wm9081->bclk = 2 * wm9081->fs;
switch (params_width(params)) {
case 16:
wm9081->bclk *= 16;
break;
case 20:
wm9081->bclk *= 20;
aif2 |= 0x4;
break;
case 24:
wm9081->bclk *= 24;
aif2 |= 0x8;
break;
case 32:
wm9081->bclk *= 32;
aif2 |= 0xc;
break;
default:
return -EINVAL;
}
}
dev_dbg(codec->dev, "Target BCLK is %dHz\n", wm9081->bclk);
ret = configure_clock(codec);
if (ret != 0)
return ret;
best = 0;
best_val = abs((wm9081->sysclk_rate / clk_sys_rates[0].ratio)
- wm9081->fs);
for (i = 1; i < ARRAY_SIZE(clk_sys_rates); i++) {
cur_val = abs((wm9081->sysclk_rate /
clk_sys_rates[i].ratio) - wm9081->fs);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected CLK_SYS_RATIO of %d\n",
clk_sys_rates[best].ratio);
clk_ctrl2 |= (clk_sys_rates[best].clk_sys_rate
<< WM9081_CLK_SYS_RATE_SHIFT);
best = 0;
best_val = abs(wm9081->fs - sample_rates[0].rate);
for (i = 1; i < ARRAY_SIZE(sample_rates); i++) {
cur_val = abs(wm9081->fs - sample_rates[i].rate);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected SAMPLE_RATE of %dHz\n",
sample_rates[best].rate);
clk_ctrl2 |= (sample_rates[best].sample_rate
<< WM9081_SAMPLE_RATE_SHIFT);
best = 0;
best_val = INT_MAX;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = ((wm9081->sysclk_rate * 10) / bclk_divs[i].div)
- wm9081->bclk;
if (cur_val < 0)
break;
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
wm9081->bclk = (wm9081->sysclk_rate * 10) / bclk_divs[best].div;
dev_dbg(codec->dev, "Selected BCLK_DIV of %d for %dHz BCLK\n",
bclk_divs[best].div, wm9081->bclk);
aif3 |= bclk_divs[best].bclk_div;
dev_dbg(codec->dev, "LRCLK_RATE is %d\n", wm9081->bclk / wm9081->fs);
aif4 |= wm9081->bclk / wm9081->fs;
if (wm9081->pdata.num_retune_configs) {
struct wm9081_pdata *pdata = &wm9081->pdata;
struct wm9081_retune_mobile_setting *s;
int eq1;
best = 0;
best_val = abs(pdata->retune_configs[0].rate - wm9081->fs);
for (i = 0; i < pdata->num_retune_configs; i++) {
cur_val = abs(pdata->retune_configs[i].rate -
wm9081->fs);
if (cur_val < best_val) {
best_val = cur_val;
best = i;
}
}
s = &pdata->retune_configs[best];
dev_dbg(codec->dev, "ReTune Mobile %s tuned for %dHz\n",
s->name, s->rate);
eq1 = snd_soc_read(codec, WM9081_EQ_1) & WM9081_EQ_ENA;
if (eq1 & WM9081_EQ_ENA)
snd_soc_write(codec, WM9081_EQ_1, 0);
for (i = 1; i < ARRAY_SIZE(s->config); i++)
snd_soc_write(codec, WM9081_EQ_1 + i, s->config[i]);
eq1 |= (s->config[0] & ~WM9081_EQ_ENA);
snd_soc_write(codec, WM9081_EQ_1, eq1);
}
snd_soc_write(codec, WM9081_CLOCK_CONTROL_2, clk_ctrl2);
snd_soc_write(codec, WM9081_AUDIO_INTERFACE_2, aif2);
snd_soc_write(codec, WM9081_AUDIO_INTERFACE_3, aif3);
snd_soc_write(codec, WM9081_AUDIO_INTERFACE_4, aif4);
return 0;
}
static int wm9081_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int reg;
reg = snd_soc_read(codec, WM9081_DAC_DIGITAL_2);
if (mute)
reg |= WM9081_DAC_MUTE;
else
reg &= ~WM9081_DAC_MUTE;
snd_soc_write(codec, WM9081_DAC_DIGITAL_2, reg);
return 0;
}
static int wm9081_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM9081_SYSCLK_MCLK:
case WM9081_SYSCLK_FLL_MCLK:
wm9081->sysclk_source = clk_id;
wm9081->mclk_rate = freq;
break;
default:
return -EINVAL;
}
return 0;
}
static int wm9081_set_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
unsigned int aif1 = snd_soc_read(codec, WM9081_AUDIO_INTERFACE_1);
aif1 &= ~(WM9081_AIFDAC_TDM_SLOT_MASK | WM9081_AIFDAC_TDM_MODE_MASK);
if (slots < 0 || slots > 4)
return -EINVAL;
wm9081->tdm_width = slot_width;
if (slots == 0)
slots = 1;
aif1 |= (slots - 1) << WM9081_AIFDAC_TDM_MODE_SHIFT;
switch (rx_mask) {
case 1:
break;
case 2:
aif1 |= 0x10;
break;
case 4:
aif1 |= 0x20;
break;
case 8:
aif1 |= 0x30;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM9081_AUDIO_INTERFACE_1, aif1);
return 0;
}
static int wm9081_probe(struct snd_soc_codec *codec)
{
struct wm9081_priv *wm9081 = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, WM9081_ANALOGUE_LINEOUT,
WM9081_LINEOUTZC, WM9081_LINEOUTZC);
snd_soc_update_bits(codec, WM9081_ANALOGUE_SPEAKER_PGA,
WM9081_SPKPGAZC, WM9081_SPKPGAZC);
if (!wm9081->pdata.num_retune_configs) {
dev_dbg(codec->dev,
"No ReTune Mobile data, using normal EQ\n");
snd_soc_add_codec_controls(codec, wm9081_eq_controls,
ARRAY_SIZE(wm9081_eq_controls));
}
return 0;
}
static int wm9081_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm9081_priv *wm9081;
unsigned int reg;
int ret;
wm9081 = devm_kzalloc(&i2c->dev, sizeof(struct wm9081_priv),
GFP_KERNEL);
if (wm9081 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm9081);
wm9081->regmap = devm_regmap_init_i2c(i2c, &wm9081_regmap);
if (IS_ERR(wm9081->regmap)) {
ret = PTR_ERR(wm9081->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret = regmap_read(wm9081->regmap, WM9081_SOFTWARE_RESET, &reg);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read chip ID: %d\n", ret);
return ret;
}
if (reg != 0x9081) {
dev_err(&i2c->dev, "Device is not a WM9081: ID=0x%x\n", reg);
return -EINVAL;
}
ret = wm9081_reset(wm9081->regmap);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to issue reset\n");
return ret;
}
if (dev_get_platdata(&i2c->dev))
memcpy(&wm9081->pdata, dev_get_platdata(&i2c->dev),
sizeof(wm9081->pdata));
reg = 0;
if (wm9081->pdata.irq_high)
reg |= WM9081_IRQ_POL;
if (!wm9081->pdata.irq_cmos)
reg |= WM9081_IRQ_OP_CTRL;
regmap_update_bits(wm9081->regmap, WM9081_INTERRUPT_CONTROL,
WM9081_IRQ_POL | WM9081_IRQ_OP_CTRL, reg);
regcache_cache_only(wm9081->regmap, true);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm9081, &wm9081_dai, 1);
if (ret < 0)
return ret;
return 0;
}
static int wm9081_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
