static int wm8993_volatile(struct snd_soc_codec *codec, unsigned int reg)
{
switch (reg) {
case WM8993_SOFTWARE_RESET:
case WM8993_DC_SERVO_0:
case WM8993_DC_SERVO_READBACK_0:
case WM8993_DC_SERVO_READBACK_1:
case WM8993_DC_SERVO_READBACK_2:
return 1;
default:
return 0;
}
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, target;
unsigned int div;
int i;
div = 1;
fll_div->fll_clk_ref_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_clk_ref_div++;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
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
static int _wm8993_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
u16 reg1, reg4, reg5;
struct _fll_div fll_div;
int ret;
if (Fref == wm8993->fll_fref && Fout == wm8993->fll_fout)
return 0;
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm8993->fll_fref = 0;
wm8993->fll_fout = 0;
reg1 = snd_soc_read(codec, WM8993_FLL_CONTROL_1);
reg1 &= ~WM8993_FLL_ENA;
snd_soc_write(codec, WM8993_FLL_CONTROL_1, reg1);
return 0;
}
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
reg5 = snd_soc_read(codec, WM8993_FLL_CONTROL_5);
reg5 &= ~WM8993_FLL_CLK_SRC_MASK;
switch (fll_id) {
case WM8993_FLL_MCLK:
break;
case WM8993_FLL_LRCLK:
reg5 |= 1;
break;
case WM8993_FLL_BCLK:
reg5 |= 2;
break;
default:
dev_err(codec->dev, "Unknown FLL ID %d\n", fll_id);
return -EINVAL;
}
reg1 = snd_soc_read(codec, WM8993_FLL_CONTROL_1);
reg1 &= ~WM8993_FLL_ENA;
snd_soc_write(codec, WM8993_FLL_CONTROL_1, reg1);
if (fll_div.k)
reg1 |= WM8993_FLL_FRAC_MASK;
else
reg1 &= ~WM8993_FLL_FRAC_MASK;
snd_soc_write(codec, WM8993_FLL_CONTROL_1, reg1);
snd_soc_write(codec, WM8993_FLL_CONTROL_2,
(fll_div.fll_outdiv << WM8993_FLL_OUTDIV_SHIFT) |
(fll_div.fll_fratio << WM8993_FLL_FRATIO_SHIFT));
snd_soc_write(codec, WM8993_FLL_CONTROL_3, fll_div.k);
reg4 = snd_soc_read(codec, WM8993_FLL_CONTROL_4);
reg4 &= ~WM8993_FLL_N_MASK;
reg4 |= fll_div.n << WM8993_FLL_N_SHIFT;
snd_soc_write(codec, WM8993_FLL_CONTROL_4, reg4);
reg5 &= ~WM8993_FLL_CLK_REF_DIV_MASK;
reg5 |= fll_div.fll_clk_ref_div << WM8993_FLL_CLK_REF_DIV_SHIFT;
snd_soc_write(codec, WM8993_FLL_CONTROL_5, reg5);
snd_soc_write(codec, WM8993_FLL_CONTROL_1, reg1 | WM8993_FLL_ENA);
dev_dbg(codec->dev, "FLL enabled at %dHz->%dHz\n", Fref, Fout);
wm8993->fll_fref = Fref;
wm8993->fll_fout = Fout;
wm8993->fll_src = source;
return 0;
}
static int wm8993_set_fll(struct snd_soc_dai *dai, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
return _wm8993_set_fll(dai->codec, fll_id, source, Fref, Fout);
}
static int configure_clock(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
unsigned int reg;
switch (wm8993->sysclk_source) {
case WM8993_SYSCLK_MCLK:
dev_dbg(codec->dev, "Using %dHz MCLK\n", wm8993->mclk_rate);
reg = snd_soc_read(codec, WM8993_CLOCKING_2);
reg &= ~(WM8993_MCLK_DIV | WM8993_SYSCLK_SRC);
if (wm8993->mclk_rate > 13500000) {
reg |= WM8993_MCLK_DIV;
wm8993->sysclk_rate = wm8993->mclk_rate / 2;
} else {
reg &= ~WM8993_MCLK_DIV;
wm8993->sysclk_rate = wm8993->mclk_rate;
}
snd_soc_write(codec, WM8993_CLOCKING_2, reg);
break;
case WM8993_SYSCLK_FLL:
dev_dbg(codec->dev, "Using %dHz FLL clock\n",
wm8993->fll_fout);
reg = snd_soc_read(codec, WM8993_CLOCKING_2);
reg |= WM8993_SYSCLK_SRC;
if (wm8993->fll_fout > 13500000) {
reg |= WM8993_MCLK_DIV;
wm8993->sysclk_rate = wm8993->fll_fout / 2;
} else {
reg &= ~WM8993_MCLK_DIV;
wm8993->sysclk_rate = wm8993->fll_fout;
}
snd_soc_write(codec, WM8993_CLOCKING_2, reg);
break;
default:
dev_err(codec->dev, "System clock not configured\n");
return -EINVAL;
}
dev_dbg(codec->dev, "CLK_SYS is %dHz\n", wm8993->sysclk_rate);
return 0;
}
static int clk_sys_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return configure_clock(codec);
case SND_SOC_DAPM_POST_PMD:
break;
}
return 0;
}
static int class_w_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret;
if (ucontrol->value.integer.value[0] == 0) {
if (wm8993->class_w_users == 0) {
dev_dbg(codec->dev, "Disabling Class W\n");
snd_soc_update_bits(codec, WM8993_CLASS_W_0,
WM8993_CP_DYN_FREQ |
WM8993_CP_DYN_V,
0);
}
wm8993->class_w_users++;
wm8993->hubs_data.class_w = true;
}
ret = snd_soc_dapm_put_enum_double(kcontrol, ucontrol);
if (ucontrol->value.integer.value[0] == 1) {
if (wm8993->class_w_users == 1) {
dev_dbg(codec->dev, "Enabling Class W\n");
snd_soc_update_bits(codec, WM8993_CLASS_W_0,
WM8993_CP_DYN_FREQ |
WM8993_CP_DYN_V,
WM8993_CP_DYN_FREQ |
WM8993_CP_DYN_V);
}
wm8993->class_w_users--;
wm8993->hubs_data.class_w = false;
}
dev_dbg(codec->dev, "Indirect DAC use count now %d\n",
wm8993->class_w_users);
return ret;
}
static void wm8993_cache_restore(struct snd_soc_codec *codec)
{
u16 *cache = codec->reg_cache;
int i;
if (!codec->cache_sync)
return;
codec->cache_only = 0;
for (i = 1; i < WM8993_MAX_REGISTER; i++) {
if (cache[i] == wm8993_reg_defaults[i])
continue;
snd_soc_write(codec, i, cache[i]);
}
codec->cache_sync = 0;
}
static int wm8993_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_VMID_SEL_MASK, 0x2);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_2,
WM8993_TSHUT_ENA, WM8993_TSHUT_ENA);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0)
return ret;
wm8993_cache_restore(codec);
snd_soc_write(codec, 0x44, 3);
snd_soc_write(codec, 0x56, 3);
snd_soc_write(codec, 0x44, 0);
snd_soc_update_bits(codec, WM8993_ANTIPOP2,
WM8993_STARTUP_BIAS_ENA |
WM8993_VMID_BUF_ENA |
WM8993_VMID_RAMP_MASK |
WM8993_BIAS_SRC,
WM8993_STARTUP_BIAS_ENA |
WM8993_VMID_BUF_ENA |
WM8993_VMID_RAMP_MASK |
WM8993_BIAS_SRC);
if (!wm8993->pdata.lineout1_diff ||
!wm8993->pdata.lineout2_diff)
snd_soc_update_bits(codec, WM8993_ANTIPOP1,
WM8993_LINEOUT_VMID_BUF_ENA,
WM8993_LINEOUT_VMID_BUF_ENA);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_VMID_SEL_MASK |
WM8993_BIAS_ENA,
WM8993_BIAS_ENA | 0x2);
msleep(32);
snd_soc_update_bits(codec, WM8993_ANTIPOP2,
WM8993_BIAS_SRC |
WM8993_STARTUP_BIAS_ENA, 0);
}
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_VMID_SEL_MASK, 0x4);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_2,
WM8993_TSHUT_ENA, 0);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8993_ANTIPOP1,
WM8993_LINEOUT_VMID_BUF_ENA, 0);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_VMID_SEL_MASK | WM8993_BIAS_ENA,
0);
snd_soc_update_bits(codec, WM8993_ANTIPOP2,
WM8993_STARTUP_BIAS_ENA |
WM8993_VMID_BUF_ENA |
WM8993_VMID_RAMP_MASK |
WM8993_BIAS_SRC, 0);
#ifdef CONFIG_REGULATOR
codec->cache_sync = 1;
#endif
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8993_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8993_SYSCLK_MCLK:
wm8993->mclk_rate = freq;
case WM8993_SYSCLK_FLL:
wm8993->sysclk_source = clk_id;
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8993_set_dai_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
unsigned int aif1 = snd_soc_read(codec, WM8993_AUDIO_INTERFACE_1);
unsigned int aif4 = snd_soc_read(codec, WM8993_AUDIO_INTERFACE_4);
aif1 &= ~(WM8993_BCLK_DIR | WM8993_AIF_BCLK_INV |
WM8993_AIF_LRCLK_INV | WM8993_AIF_FMT_MASK);
aif4 &= ~WM8993_LRCLK_DIR;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
wm8993->master = 0;
break;
case SND_SOC_DAIFMT_CBS_CFM:
aif4 |= WM8993_LRCLK_DIR;
wm8993->master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFS:
aif1 |= WM8993_BCLK_DIR;
wm8993->master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif1 |= WM8993_BCLK_DIR;
aif4 |= WM8993_LRCLK_DIR;
wm8993->master = 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif1 |= WM8993_AIF_LRCLK_INV;
case SND_SOC_DAIFMT_DSP_A:
aif1 |= 0x18;
break;
case SND_SOC_DAIFMT_I2S:
aif1 |= 0x10;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif1 |= 0x8;
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
aif1 |= WM8993_AIF_BCLK_INV;
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
aif1 |= WM8993_AIF_BCLK_INV | WM8993_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8993_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif1 |= WM8993_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8993_AUDIO_INTERFACE_1, aif1);
snd_soc_write(codec, WM8993_AUDIO_INTERFACE_4, aif4);
return 0;
}
static int wm8993_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret, i, best, best_val, cur_val;
unsigned int clocking1, clocking3, aif1, aif4;
clocking1 = snd_soc_read(codec, WM8993_CLOCKING_1);
clocking1 &= ~WM8993_BCLK_DIV_MASK;
clocking3 = snd_soc_read(codec, WM8993_CLOCKING_3);
clocking3 &= ~(WM8993_CLK_SYS_RATE_MASK | WM8993_SAMPLE_RATE_MASK);
aif1 = snd_soc_read(codec, WM8993_AUDIO_INTERFACE_1);
aif1 &= ~WM8993_AIF_WL_MASK;
aif4 = snd_soc_read(codec, WM8993_AUDIO_INTERFACE_4);
aif4 &= ~WM8993_LRCLK_RATE_MASK;
wm8993->fs = params_rate(params);
wm8993->bclk = 2 * wm8993->fs;
if (wm8993->tdm_slots) {
dev_dbg(codec->dev, "Configuring for %d %d bit TDM slots\n",
wm8993->tdm_slots, wm8993->tdm_width);
wm8993->bclk *= wm8993->tdm_width * wm8993->tdm_slots;
} else {
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
wm8993->bclk *= 16;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
wm8993->bclk *= 20;
aif1 |= 0x8;
break;
case SNDRV_PCM_FORMAT_S24_LE:
wm8993->bclk *= 24;
aif1 |= 0x10;
break;
case SNDRV_PCM_FORMAT_S32_LE:
wm8993->bclk *= 32;
aif1 |= 0x18;
break;
default:
return -EINVAL;
}
}
dev_dbg(codec->dev, "Target BCLK is %dHz\n", wm8993->bclk);
ret = configure_clock(codec);
if (ret != 0)
return ret;
best = 0;
best_val = abs((wm8993->sysclk_rate / clk_sys_rates[0].ratio)
- wm8993->fs);
for (i = 1; i < ARRAY_SIZE(clk_sys_rates); i++) {
cur_val = abs((wm8993->sysclk_rate /
clk_sys_rates[i].ratio) - wm8993->fs);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected CLK_SYS_RATIO of %d\n",
clk_sys_rates[best].ratio);
clocking3 |= (clk_sys_rates[best].clk_sys_rate
<< WM8993_CLK_SYS_RATE_SHIFT);
best = 0;
best_val = abs(wm8993->fs - sample_rates[0].rate);
for (i = 1; i < ARRAY_SIZE(sample_rates); i++) {
cur_val = abs(wm8993->fs - sample_rates[i].rate);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected SAMPLE_RATE of %dHz\n",
sample_rates[best].rate);
clocking3 |= (sample_rates[best].sample_rate
<< WM8993_SAMPLE_RATE_SHIFT);
best = 0;
best_val = INT_MAX;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = ((wm8993->sysclk_rate * 10) / bclk_divs[i].div)
- wm8993->bclk;
if (cur_val < 0)
break;
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
wm8993->bclk = (wm8993->sysclk_rate * 10) / bclk_divs[best].div;
dev_dbg(codec->dev, "Selected BCLK_DIV of %d for %dHz BCLK\n",
bclk_divs[best].div, wm8993->bclk);
clocking1 |= bclk_divs[best].bclk_div << WM8993_BCLK_DIV_SHIFT;
dev_dbg(codec->dev, "LRCLK_RATE is %d\n", wm8993->bclk / wm8993->fs);
aif4 |= wm8993->bclk / wm8993->fs;
snd_soc_write(codec, WM8993_CLOCKING_1, clocking1);
snd_soc_write(codec, WM8993_CLOCKING_3, clocking3);
snd_soc_write(codec, WM8993_AUDIO_INTERFACE_1, aif1);
snd_soc_write(codec, WM8993_AUDIO_INTERFACE_4, aif4);
if (wm8993->pdata.num_retune_configs) {
u16 eq1 = snd_soc_read(codec, WM8993_EQ1);
struct wm8993_retune_mobile_setting *s;
best = 0;
best_val = abs(wm8993->pdata.retune_configs[0].rate
- wm8993->fs);
for (i = 0; i < wm8993->pdata.num_retune_configs; i++) {
cur_val = abs(wm8993->pdata.retune_configs[i].rate
- wm8993->fs);
if (cur_val < best_val) {
best_val = cur_val;
best = i;
}
}
s = &wm8993->pdata.retune_configs[best];
dev_dbg(codec->dev, "ReTune Mobile %s tuned for %dHz\n",
s->name, s->rate);
snd_soc_update_bits(codec, WM8993_EQ1, WM8993_EQ_ENA, 0);
for (i = 1; i < ARRAY_SIZE(s->config); i++)
snd_soc_write(codec, WM8993_EQ1 + i, s->config[i]);
snd_soc_update_bits(codec, WM8993_EQ1, WM8993_EQ_ENA, eq1);
}
return 0;
}
static int wm8993_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int reg;
reg = snd_soc_read(codec, WM8993_DAC_CTRL);
if (mute)
reg |= WM8993_DAC_MUTE;
else
reg &= ~WM8993_DAC_MUTE;
snd_soc_write(codec, WM8993_DAC_CTRL, reg);
return 0;
}
static int wm8993_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int aif1 = 0;
int aif2 = 0;
if (slots == 0) {
wm8993->tdm_slots = 0;
goto out;
}
aif1 |= WM8993_AIFADC_TDM;
aif2 |= WM8993_AIFDAC_TDM;
switch (rx_mask) {
case 3:
break;
case 0xc:
aif1 |= WM8993_AIFADC_TDM_CHAN;
break;
default:
return -EINVAL;
}
switch (tx_mask) {
case 3:
break;
case 0xc:
aif2 |= WM8993_AIFDAC_TDM_CHAN;
break;
default:
return -EINVAL;
}
out:
wm8993->tdm_width = slot_width;
wm8993->tdm_slots = slots / 2;
snd_soc_update_bits(codec, WM8993_AUDIO_INTERFACE_1,
WM8993_AIFADC_TDM | WM8993_AIFADC_TDM_CHAN, aif1);
snd_soc_update_bits(codec, WM8993_AUDIO_INTERFACE_2,
WM8993_AIFDAC_TDM | WM8993_AIFDAC_TDM_CHAN, aif2);
return 0;
}
static int wm8993_probe(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret, i, val;
wm8993->hubs_data.hp_startup_mode = 1;
wm8993->hubs_data.dcs_codes = -2;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8993->supplies); i++)
wm8993->supplies[i].supply = wm8993_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
val = snd_soc_read(codec, WM8993_SOFTWARE_RESET);
if (val != wm8993_reg_defaults[WM8993_SOFTWARE_RESET]) {
dev_err(codec->dev, "Invalid ID register value %x\n", val);
ret = -EINVAL;
goto err_enable;
}
ret = snd_soc_write(codec, WM8993_SOFTWARE_RESET, 0xffff);
if (ret != 0)
goto err_enable;
codec->cache_only = 1;
wm8993->class_w_users = 2;
snd_soc_update_bits(codec, WM8993_RIGHT_DAC_DIGITAL_VOLUME,
WM8993_DAC_VU, WM8993_DAC_VU);
snd_soc_update_bits(codec, WM8993_RIGHT_ADC_DIGITAL_VOLUME,
WM8993_ADC_VU, WM8993_ADC_VU);
snd_soc_update_bits(codec, WM8993_ANALOGUE_HP_0,
WM8993_HPOUT1_AUTO_PU, 0);
snd_soc_update_bits(codec, WM8993_CLOCKING_4, WM8993_SR_MODE, 0);
wm_hubs_handle_analogue_pdata(codec, wm8993->pdata.lineout1_diff,
wm8993->pdata.lineout2_diff,
wm8993->pdata.lineout1fb,
wm8993->pdata.lineout2fb,
wm8993->pdata.jd_scthr,
wm8993->pdata.jd_thr,
wm8993->pdata.micbias1_lvl,
wm8993->pdata.micbias2_lvl);
ret = wm8993_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (ret != 0)
goto err_enable;
snd_soc_add_controls(codec, wm8993_snd_controls,
ARRAY_SIZE(wm8993_snd_controls));
if (wm8993->pdata.num_retune_configs != 0) {
dev_dbg(codec->dev, "Using ReTune Mobile\n");
} else {
dev_dbg(codec->dev, "No ReTune Mobile, using normal EQ\n");
snd_soc_add_controls(codec, wm8993_eq_controls,
ARRAY_SIZE(wm8993_eq_controls));
}
snd_soc_dapm_new_controls(dapm, wm8993_dapm_widgets,
ARRAY_SIZE(wm8993_dapm_widgets));
wm_hubs_add_analogue_controls(codec);
snd_soc_dapm_add_routes(dapm, routes, ARRAY_SIZE(routes));
wm_hubs_add_analogue_routes(codec, wm8993->pdata.lineout1_diff,
wm8993->pdata.lineout2_diff);
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
err_get:
regulator_bulk_free(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
return ret;
}
static int wm8993_remove(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
wm8993_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_free(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
return 0;
}
static int wm8993_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int fll_fout = wm8993->fll_fout;
int fll_fref = wm8993->fll_fref;
int ret;
ret = _wm8993_set_fll(codec, 0, 0, 0, 0);
if (ret != 0) {
dev_err(codec->dev, "Failed to stop FLL\n");
return ret;
}
wm8993->fll_fout = fll_fout;
wm8993->fll_fref = fll_fref;
wm8993_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8993_resume(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret;
wm8993_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (wm8993->fll_fout) {
int fll_fout = wm8993->fll_fout;
int fll_fref = wm8993->fll_fref;
wm8993->fll_fref = 0;
wm8993->fll_fout = 0;
ret = _wm8993_set_fll(codec, 0, wm8993->fll_src,
fll_fref, fll_fout);
if (ret != 0)
dev_err(codec->dev, "Failed to restart FLL\n");
}
return 0;
}
static __devinit int wm8993_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8993_priv *wm8993;
int ret;
wm8993 = kzalloc(sizeof(struct wm8993_priv), GFP_KERNEL);
if (wm8993 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8993);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8993, &wm8993_dai, 1);
if (ret < 0)
kfree(wm8993);
return ret;
}
static __devexit int wm8993_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8993_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8993_i2c_driver);
if (ret != 0) {
pr_err("WM8993: Unable to register I2C driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8993_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8993_i2c_driver);
#endif
}
