static void wm8995_update_class_w(struct snd_soc_codec *codec)
{
int enable = 1;
int source = 0;
int reg, reg_r;
reg = snd_soc_read(codec, WM8995_DAC1_LEFT_MIXER_ROUTING);
switch (reg) {
case WM8995_AIF2DACL_TO_DAC1L:
dev_dbg(codec->dev, "Class W source AIF2DAC\n");
source = 2 << WM8995_CP_DYN_SRC_SEL_SHIFT;
break;
case WM8995_AIF1DAC2L_TO_DAC1L:
dev_dbg(codec->dev, "Class W source AIF1DAC2\n");
source = 1 << WM8995_CP_DYN_SRC_SEL_SHIFT;
break;
case WM8995_AIF1DAC1L_TO_DAC1L:
dev_dbg(codec->dev, "Class W source AIF1DAC1\n");
source = 0 << WM8995_CP_DYN_SRC_SEL_SHIFT;
break;
default:
dev_dbg(codec->dev, "DAC mixer setting: %x\n", reg);
enable = 0;
break;
}
reg_r = snd_soc_read(codec, WM8995_DAC1_RIGHT_MIXER_ROUTING);
if (reg_r != reg) {
dev_dbg(codec->dev, "Left and right DAC mixers different\n");
enable = 0;
}
if (enable) {
dev_dbg(codec->dev, "Class W enabled\n");
snd_soc_update_bits(codec, WM8995_CLASS_W_1,
WM8995_CP_DYN_PWR_MASK |
WM8995_CP_DYN_SRC_SEL_MASK,
source | WM8995_CP_DYN_PWR);
} else {
dev_dbg(codec->dev, "Class W disabled\n");
snd_soc_update_bits(codec, WM8995_CLASS_W_1,
WM8995_CP_DYN_PWR_MASK, 0);
}
}
static int check_clk_sys(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
const char *clk;
reg = snd_soc_read(source->codec, WM8995_CLOCKING_1);
if (reg & WM8995_SYSCLK_SRC)
clk = "AIF2CLK";
else
clk = "AIF1CLK";
return !strcmp(source->name, clk);
}
static int wm8995_put_class_w(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *w = wlist->widgets[0];
struct snd_soc_codec *codec;
int ret;
codec = w->codec;
ret = snd_soc_dapm_put_volsw(kcontrol, ucontrol);
wm8995_update_class_w(codec);
return ret;
}
static int hp_supply_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec;
struct wm8995_priv *wm8995;
codec = w->codec;
wm8995 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, WM8995_POWER_MANAGEMENT_1,
WM8995_HPOUT1L_ENA_MASK |
WM8995_HPOUT1R_ENA_MASK,
WM8995_HPOUT1L_ENA |
WM8995_HPOUT1R_ENA);
snd_soc_update_bits(codec, WM8995_ANALOGUE_HP_1,
WM8995_HPOUT1L_DLY_MASK |
WM8995_HPOUT1R_DLY_MASK,
WM8995_HPOUT1L_DLY |
WM8995_HPOUT1R_DLY);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8995_CHARGE_PUMP_1,
WM8995_CP_ENA_MASK, 0);
break;
}
return 0;
}
static void dc_servo_cmd(struct snd_soc_codec *codec,
unsigned int reg, unsigned int val, unsigned int mask)
{
int timeout = 10;
dev_dbg(codec->dev, "%s: reg = %#x, val = %#x, mask = %#x\n",
__func__, reg, val, mask);
snd_soc_write(codec, reg, val);
while (timeout--) {
msleep(10);
val = snd_soc_read(codec, WM8995_DC_SERVO_READBACK_0);
if ((val & mask) == mask)
return;
}
dev_err(codec->dev, "Timed out waiting for DC Servo\n");
}
static int hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec;
unsigned int reg;
codec = w->codec;
reg = snd_soc_read(codec, WM8995_ANALOGUE_HP_1);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, WM8995_CHARGE_PUMP_1,
WM8995_CP_ENA_MASK, WM8995_CP_ENA);
msleep(5);
snd_soc_update_bits(codec, WM8995_POWER_MANAGEMENT_1,
WM8995_HPOUT1L_ENA_MASK |
WM8995_HPOUT1R_ENA_MASK,
WM8995_HPOUT1L_ENA | WM8995_HPOUT1R_ENA);
udelay(20);
reg |= WM8995_HPOUT1L_DLY | WM8995_HPOUT1R_DLY;
snd_soc_write(codec, WM8995_ANALOGUE_HP_1, reg);
snd_soc_write(codec, WM8995_DC_SERVO_1, WM8995_DCS_ENA_CHAN_0 |
WM8995_DCS_ENA_CHAN_1);
dc_servo_cmd(codec, WM8995_DC_SERVO_2,
WM8995_DCS_TRIG_STARTUP_0 |
WM8995_DCS_TRIG_STARTUP_1,
WM8995_DCS_TRIG_DAC_WR_0 |
WM8995_DCS_TRIG_DAC_WR_1);
reg |= WM8995_HPOUT1R_OUTP | WM8995_HPOUT1R_RMV_SHORT |
WM8995_HPOUT1L_OUTP | WM8995_HPOUT1L_RMV_SHORT;
snd_soc_write(codec, WM8995_ANALOGUE_HP_1, reg);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8995_ANALOGUE_HP_1,
WM8995_HPOUT1L_OUTP_MASK |
WM8995_HPOUT1R_OUTP_MASK |
WM8995_HPOUT1L_RMV_SHORT_MASK |
WM8995_HPOUT1R_RMV_SHORT_MASK, 0);
snd_soc_update_bits(codec, WM8995_ANALOGUE_HP_1,
WM8995_HPOUT1L_DLY_MASK |
WM8995_HPOUT1R_DLY_MASK, 0);
snd_soc_write(codec, WM8995_DC_SERVO_1, 0);
snd_soc_update_bits(codec, WM8995_POWER_MANAGEMENT_1,
WM8995_HPOUT1L_ENA_MASK |
WM8995_HPOUT1R_ENA_MASK,
0);
break;
}
return 0;
}
static int configure_aif_clock(struct snd_soc_codec *codec, int aif)
{
struct wm8995_priv *wm8995;
int rate;
int reg1 = 0;
int offset;
wm8995 = snd_soc_codec_get_drvdata(codec);
if (aif)
offset = 4;
else
offset = 0;
switch (wm8995->sysclk[aif]) {
case WM8995_SYSCLK_MCLK1:
rate = wm8995->mclk[0];
break;
case WM8995_SYSCLK_MCLK2:
reg1 |= 0x8;
rate = wm8995->mclk[1];
break;
case WM8995_SYSCLK_FLL1:
reg1 |= 0x10;
rate = wm8995->fll[0].out;
break;
case WM8995_SYSCLK_FLL2:
reg1 |= 0x18;
rate = wm8995->fll[1].out;
break;
default:
return -EINVAL;
}
if (rate >= 13500000) {
rate /= 2;
reg1 |= WM8995_AIF1CLK_DIV;
dev_dbg(codec->dev, "Dividing AIF%d clock to %dHz\n",
aif + 1, rate);
}
wm8995->aifclk[aif] = rate;
snd_soc_update_bits(codec, WM8995_AIF1_CLOCKING_1 + offset,
WM8995_AIF1CLK_SRC_MASK | WM8995_AIF1CLK_DIV_MASK,
reg1);
return 0;
}
static int configure_clock(struct snd_soc_codec *codec)
{
struct wm8995_priv *wm8995;
int old, new;
wm8995 = snd_soc_codec_get_drvdata(codec);
configure_aif_clock(codec, 0);
configure_aif_clock(codec, 1);
if (wm8995->aifclk[0] == wm8995->aifclk[1])
return 0;
if (wm8995->aifclk[0] < wm8995->aifclk[1])
new = WM8995_SYSCLK_SRC;
else
new = 0;
old = snd_soc_read(codec, WM8995_CLOCKING_1) & WM8995_SYSCLK_SRC;
if (old == new)
return 0;
snd_soc_update_bits(codec, WM8995_CLOCKING_1,
WM8995_SYSCLK_SRC_MASK, new);
snd_soc_dapm_sync(&codec->dapm);
return 0;
}
static int clk_sys_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec;
codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return configure_clock(codec);
case SND_SOC_DAPM_POST_PMD:
configure_clock(codec);
break;
}
return 0;
}
static int wm8995_volatile(struct snd_soc_codec *codec, unsigned int reg)
{
if (reg > WM8995_MAX_CACHED_REGISTER)
return 1;
switch (reg) {
case WM8995_SOFTWARE_RESET:
case WM8995_DC_SERVO_READBACK_0:
case WM8995_INTERRUPT_STATUS_1:
case WM8995_INTERRUPT_STATUS_2:
case WM8995_INTERRUPT_STATUS_1_MASK:
case WM8995_INTERRUPT_STATUS_2_MASK:
case WM8995_INTERRUPT_CONTROL:
case WM8995_ACCESSORY_DETECT_MODE1:
case WM8995_ACCESSORY_DETECT_MODE2:
case WM8995_HEADPHONE_DETECT1:
case WM8995_HEADPHONE_DETECT2:
return 1;
}
return 0;
}
static int wm8995_aif_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int mute_reg;
switch (dai->id) {
case 0:
mute_reg = WM8995_AIF1_DAC1_FILTERS_1;
break;
case 1:
mute_reg = WM8995_AIF2_DAC_FILTERS_1;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, mute_reg, WM8995_AIF1DAC1_MUTE_MASK,
!!mute << WM8995_AIF1DAC1_MUTE_SHIFT);
return 0;
}
static int wm8995_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec;
int master;
int aif;
codec = dai->codec;
master = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
master = WM8995_AIF1_MSTR;
break;
default:
dev_err(dai->dev, "Unknown master/slave configuration\n");
return -EINVAL;
}
aif = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif |= WM8995_AIF1_LRCLK_INV;
case SND_SOC_DAIFMT_DSP_A:
aif |= (0x3 << WM8995_AIF1_FMT_SHIFT);
break;
case SND_SOC_DAIFMT_I2S:
aif |= (0x2 << WM8995_AIF1_FMT_SHIFT);
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif |= (0x1 << WM8995_AIF1_FMT_SHIFT);
break;
default:
dev_err(dai->dev, "Unknown dai format\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif |= WM8995_AIF1_BCLK_INV;
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
aif |= WM8995_AIF1_BCLK_INV | WM8995_AIF1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif |= WM8995_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif |= WM8995_AIF1_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8995_AIF1_CONTROL_1,
WM8995_AIF1_BCLK_INV_MASK |
WM8995_AIF1_LRCLK_INV_MASK |
WM8995_AIF1_FMT_MASK, aif);
snd_soc_update_bits(codec, WM8995_AIF1_MASTER_SLAVE,
WM8995_AIF1_MSTR_MASK, master);
return 0;
}
static int wm8995_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec;
struct wm8995_priv *wm8995;
int aif1_reg;
int bclk_reg;
int lrclk_reg;
int rate_reg;
int bclk_rate;
int aif1;
int lrclk, bclk;
int i, rate_val, best, best_val, cur_val;
codec = dai->codec;
wm8995 = snd_soc_codec_get_drvdata(codec);
switch (dai->id) {
case 0:
aif1_reg = WM8995_AIF1_CONTROL_1;
bclk_reg = WM8995_AIF1_BCLK;
rate_reg = WM8995_AIF1_RATE;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ) {
lrclk_reg = WM8995_AIF1DAC_LRCLK;
} else {
lrclk_reg = WM8995_AIF1ADC_LRCLK;
dev_dbg(codec->dev, "AIF1 using split LRCLK\n");
}
break;
case 1:
aif1_reg = WM8995_AIF2_CONTROL_1;
bclk_reg = WM8995_AIF2_BCLK;
rate_reg = WM8995_AIF2_RATE;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ) {
lrclk_reg = WM8995_AIF2DAC_LRCLK;
} else {
lrclk_reg = WM8995_AIF2ADC_LRCLK;
dev_dbg(codec->dev, "AIF2 using split LRCLK\n");
}
break;
default:
return -EINVAL;
}
bclk_rate = snd_soc_params_to_bclk(params);
if (bclk_rate < 0)
return bclk_rate;
aif1 = 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
aif1 |= (0x1 << WM8995_AIF1_WL_SHIFT);
break;
case SNDRV_PCM_FORMAT_S24_LE:
aif1 |= (0x2 << WM8995_AIF1_WL_SHIFT);
break;
case SNDRV_PCM_FORMAT_S32_LE:
aif1 |= (0x3 << WM8995_AIF1_WL_SHIFT);
break;
default:
dev_err(dai->dev, "Unsupported word length %u\n",
params_format(params));
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(srs); ++i)
if (srs[i] == params_rate(params))
break;
if (i == ARRAY_SIZE(srs)) {
dev_err(dai->dev, "Sample rate %d is not supported\n",
params_rate(params));
return -EINVAL;
}
rate_val = i << WM8995_AIF1_SR_SHIFT;
dev_dbg(dai->dev, "Sample rate is %dHz\n", srs[i]);
dev_dbg(dai->dev, "AIF%dCLK is %dHz, target BCLK %dHz\n",
dai->id + 1, wm8995->aifclk[dai->id], bclk_rate);
best = 1;
best_val = abs((fs_ratios[1] * params_rate(params))
- wm8995->aifclk[dai->id]);
for (i = 2; i < ARRAY_SIZE(fs_ratios); i++) {
cur_val = abs((fs_ratios[i] * params_rate(params))
- wm8995->aifclk[dai->id]);
if (cur_val >= best_val)
continue;
best = i;
best_val = cur_val;
}
rate_val |= best;
dev_dbg(dai->dev, "Selected AIF%dCLK/fs = %d\n",
dai->id + 1, fs_ratios[best]);
best = 0;
bclk = 0;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = (wm8995->aifclk[dai->id] * 10 / bclk_divs[i]) - bclk_rate;
if (cur_val < 0)
break;
best = i;
}
bclk |= best << WM8995_AIF1_BCLK_DIV_SHIFT;
bclk_rate = wm8995->aifclk[dai->id] * 10 / bclk_divs[best];
dev_dbg(dai->dev, "Using BCLK_DIV %d for actual BCLK %dHz\n",
bclk_divs[best], bclk_rate);
lrclk = bclk_rate / params_rate(params);
dev_dbg(dai->dev, "Using LRCLK rate %d for actual LRCLK %dHz\n",
lrclk, bclk_rate / lrclk);
snd_soc_update_bits(codec, aif1_reg,
WM8995_AIF1_WL_MASK, aif1);
snd_soc_update_bits(codec, bclk_reg,
WM8995_AIF1_BCLK_DIV_MASK, bclk);
snd_soc_update_bits(codec, lrclk_reg,
WM8995_AIF1DAC_RATE_MASK, lrclk);
snd_soc_update_bits(codec, rate_reg,
WM8995_AIF1_SR_MASK |
WM8995_AIF1CLK_RATE_MASK, rate_val);
return 0;
}
static int wm8995_set_tristate(struct snd_soc_dai *codec_dai, int tristate)
{
struct snd_soc_codec *codec = codec_dai->codec;
int reg, val, mask;
switch (codec_dai->id) {
case 0:
reg = WM8995_AIF1_MASTER_SLAVE;
mask = WM8995_AIF1_TRI;
break;
case 1:
reg = WM8995_AIF2_MASTER_SLAVE;
mask = WM8995_AIF2_TRI;
break;
case 2:
reg = WM8995_POWER_MANAGEMENT_5;
mask = WM8995_AIF3_TRI;
break;
default:
return -EINVAL;
}
if (tristate)
val = mask;
else
val = 0;
return snd_soc_update_bits(codec, reg, mask, val);
}
static int wm8995_get_fll_config(struct fll_div *fll,
int freq_in, int freq_out)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod;
pr_debug("FLL input=%dHz, output=%dHz\n", freq_in, freq_out);
fll->clk_ref_div = 0;
while (freq_in > 13500000) {
fll->clk_ref_div++;
freq_in /= 2;
if (fll->clk_ref_div > 3)
return -EINVAL;
}
pr_debug("CLK_REF_DIV=%d, Fref=%dHz\n", fll->clk_ref_div, freq_in);
fll->outdiv = 3;
while (freq_out * (fll->outdiv + 1) < 90000000) {
fll->outdiv++;
if (fll->outdiv > 63)
return -EINVAL;
}
freq_out *= fll->outdiv + 1;
pr_debug("OUTDIV=%d, Fvco=%dHz\n", fll->outdiv, freq_out);
if (freq_in > 1000000) {
fll->fll_fratio = 0;
} else if (freq_in > 256000) {
fll->fll_fratio = 1;
freq_in *= 2;
} else if (freq_in > 128000) {
fll->fll_fratio = 2;
freq_in *= 4;
} else if (freq_in > 64000) {
fll->fll_fratio = 3;
freq_in *= 8;
} else {
fll->fll_fratio = 4;
freq_in *= 16;
}
pr_debug("FLL_FRATIO=%d, Fref=%dHz\n", fll->fll_fratio, freq_in);
Ndiv = freq_out / freq_in;
fll->n = Ndiv;
Nmod = freq_out % freq_in;
pr_debug("Nmod=%d\n", Nmod);
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, freq_in);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
fll->k = K / 10;
pr_debug("N=%x K=%x\n", fll->n, fll->k);
return 0;
}
static int wm8995_set_fll(struct snd_soc_dai *dai, int id,
int src, unsigned int freq_in,
unsigned int freq_out)
{
struct snd_soc_codec *codec;
struct wm8995_priv *wm8995;
int reg_offset, ret;
struct fll_div fll;
u16 reg, aif1, aif2;
codec = dai->codec;
wm8995 = snd_soc_codec_get_drvdata(codec);
aif1 = snd_soc_read(codec, WM8995_AIF1_CLOCKING_1)
& WM8995_AIF1CLK_ENA;
aif2 = snd_soc_read(codec, WM8995_AIF2_CLOCKING_1)
& WM8995_AIF2CLK_ENA;
switch (id) {
case WM8995_FLL1:
reg_offset = 0;
id = 0;
break;
case WM8995_FLL2:
reg_offset = 0x20;
id = 1;
break;
default:
return -EINVAL;
}
switch (src) {
case 0:
if (freq_out)
return -EINVAL;
break;
case WM8995_FLL_SRC_MCLK1:
case WM8995_FLL_SRC_MCLK2:
case WM8995_FLL_SRC_LRCLK:
case WM8995_FLL_SRC_BCLK:
break;
default:
return -EINVAL;
}
if (wm8995->fll[id].src == src &&
wm8995->fll[id].in == freq_in && wm8995->fll[id].out == freq_out)
return 0;
if (freq_out)
ret = wm8995_get_fll_config(&fll, freq_in, freq_out);
else
ret = wm8995_get_fll_config(&fll, wm8995->fll[id].in,
wm8995->fll[id].out);
if (ret < 0)
return ret;
snd_soc_update_bits(codec, WM8995_AIF1_CLOCKING_1,
WM8995_AIF1CLK_ENA_MASK, 0);
snd_soc_update_bits(codec, WM8995_AIF2_CLOCKING_1,
WM8995_AIF2CLK_ENA_MASK, 0);
snd_soc_update_bits(codec, WM8995_FLL1_CONTROL_1 + reg_offset,
WM8995_FLL1_ENA_MASK, 0);
reg = (fll.outdiv << WM8995_FLL1_OUTDIV_SHIFT) |
(fll.fll_fratio << WM8995_FLL1_FRATIO_SHIFT);
snd_soc_update_bits(codec, WM8995_FLL1_CONTROL_2 + reg_offset,
WM8995_FLL1_OUTDIV_MASK |
WM8995_FLL1_FRATIO_MASK, reg);
snd_soc_write(codec, WM8995_FLL1_CONTROL_3 + reg_offset, fll.k);
snd_soc_update_bits(codec, WM8995_FLL1_CONTROL_4 + reg_offset,
WM8995_FLL1_N_MASK,
fll.n << WM8995_FLL1_N_SHIFT);
snd_soc_update_bits(codec, WM8995_FLL1_CONTROL_5 + reg_offset,
WM8995_FLL1_REFCLK_DIV_MASK |
WM8995_FLL1_REFCLK_SRC_MASK,
(fll.clk_ref_div << WM8995_FLL1_REFCLK_DIV_SHIFT) |
(src - 1));
if (freq_out)
snd_soc_update_bits(codec, WM8995_FLL1_CONTROL_1 + reg_offset,
WM8995_FLL1_ENA_MASK, WM8995_FLL1_ENA);
wm8995->fll[id].in = freq_in;
wm8995->fll[id].out = freq_out;
wm8995->fll[id].src = src;
snd_soc_update_bits(codec, WM8995_AIF1_CLOCKING_1,
WM8995_AIF1CLK_ENA_MASK, aif1);
snd_soc_update_bits(codec, WM8995_AIF2_CLOCKING_1,
WM8995_AIF2CLK_ENA_MASK, aif2);
configure_clock(codec);
return 0;
}
static int wm8995_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec;
struct wm8995_priv *wm8995;
codec = dai->codec;
wm8995 = snd_soc_codec_get_drvdata(codec);
switch (dai->id) {
case 0:
case 1:
break;
default:
return -EINVAL;
}
switch (clk_id) {
case WM8995_SYSCLK_MCLK1:
wm8995->sysclk[dai->id] = WM8995_SYSCLK_MCLK1;
wm8995->mclk[0] = freq;
dev_dbg(dai->dev, "AIF%d using MCLK1 at %uHz\n",
dai->id + 1, freq);
break;
case WM8995_SYSCLK_MCLK2:
wm8995->sysclk[dai->id] = WM8995_SYSCLK_MCLK1;
wm8995->mclk[1] = freq;
dev_dbg(dai->dev, "AIF%d using MCLK2 at %uHz\n",
dai->id + 1, freq);
break;
case WM8995_SYSCLK_FLL1:
wm8995->sysclk[dai->id] = WM8995_SYSCLK_FLL1;
dev_dbg(dai->dev, "AIF%d using FLL1\n", dai->id + 1);
break;
case WM8995_SYSCLK_FLL2:
wm8995->sysclk[dai->id] = WM8995_SYSCLK_FLL2;
dev_dbg(dai->dev, "AIF%d using FLL2\n", dai->id + 1);
break;
case WM8995_SYSCLK_OPCLK:
default:
dev_err(dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
configure_clock(codec);
return 0;
}
static int wm8995_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8995_priv *wm8995;
int ret;
wm8995 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8995->supplies),
wm8995->supplies);
if (ret)
return ret;
ret = snd_soc_cache_sync(codec);
if (ret) {
dev_err(codec->dev,
"Failed to sync cache: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, WM8995_POWER_MANAGEMENT_1,
WM8995_BG_ENA_MASK, WM8995_BG_ENA);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8995_POWER_MANAGEMENT_1,
WM8995_BG_ENA_MASK, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8995->supplies),
wm8995->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8995_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8995_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8995_resume(struct snd_soc_codec *codec)
{
wm8995_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8995_remove(struct snd_soc_codec *codec)
{
struct wm8995_priv *wm8995;
struct i2c_client *i2c;
i2c = container_of(codec->dev, struct i2c_client, dev);
wm8995 = snd_soc_codec_get_drvdata(codec);
wm8995_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8995_probe(struct snd_soc_codec *codec)
{
struct wm8995_priv *wm8995;
int i;
int ret;
codec->dapm.idle_bias_off = 1;
wm8995 = snd_soc_codec_get_drvdata(codec);
wm8995->codec = codec;
ret = snd_soc_codec_set_cache_io(codec, 16, 16, wm8995->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache i/o: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8995->supplies); i++)
wm8995->supplies[i].supply = wm8995_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8995->supplies),
wm8995->supplies);
if (ret) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8995->disable_nb[0].notifier_call = wm8995_regulator_event_0;
wm8995->disable_nb[1].notifier_call = wm8995_regulator_event_1;
wm8995->disable_nb[2].notifier_call = wm8995_regulator_event_2;
wm8995->disable_nb[3].notifier_call = wm8995_regulator_event_3;
wm8995->disable_nb[4].notifier_call = wm8995_regulator_event_4;
wm8995->disable_nb[5].notifier_call = wm8995_regulator_event_5;
wm8995->disable_nb[6].notifier_call = wm8995_regulator_event_6;
wm8995->disable_nb[7].notifier_call = wm8995_regulator_event_7;
for (i = 0; i < ARRAY_SIZE(wm8995->supplies); i++) {
ret = regulator_register_notifier(wm8995->supplies[i].consumer,
&wm8995->disable_nb[i]);
if (ret) {
dev_err(codec->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8995->supplies),
wm8995->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_reg_get;
}
ret = snd_soc_read(codec, WM8995_SOFTWARE_RESET);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device ID: %d\n", ret);
goto err_reg_enable;
}
if (ret != 0x8995) {
dev_err(codec->dev, "Invalid device ID: %#x\n", ret);
goto err_reg_enable;
}
ret = snd_soc_write(codec, WM8995_SOFTWARE_RESET, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
wm8995_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8995_AIF1_DAC1_RIGHT_VOLUME,
WM8995_AIF1DAC1_VU_MASK, WM8995_AIF1DAC1_VU);
snd_soc_update_bits(codec, WM8995_AIF1_DAC2_RIGHT_VOLUME,
WM8995_AIF1DAC2_VU_MASK, WM8995_AIF1DAC2_VU);
snd_soc_update_bits(codec, WM8995_AIF2_DAC_RIGHT_VOLUME,
WM8995_AIF2DAC_VU_MASK, WM8995_AIF2DAC_VU);
snd_soc_update_bits(codec, WM8995_AIF1_ADC1_RIGHT_VOLUME,
WM8995_AIF1ADC1_VU_MASK, WM8995_AIF1ADC1_VU);
snd_soc_update_bits(codec, WM8995_AIF1_ADC2_RIGHT_VOLUME,
WM8995_AIF1ADC2_VU_MASK, WM8995_AIF1ADC2_VU);
snd_soc_update_bits(codec, WM8995_AIF2_ADC_RIGHT_VOLUME,
WM8995_AIF2ADC_VU_MASK, WM8995_AIF1ADC2_VU);
snd_soc_update_bits(codec, WM8995_DAC1_RIGHT_VOLUME,
WM8995_DAC1_VU_MASK, WM8995_DAC1_VU);
snd_soc_update_bits(codec, WM8995_DAC2_RIGHT_VOLUME,
WM8995_DAC2_VU_MASK, WM8995_DAC2_VU);
snd_soc_update_bits(codec, WM8995_RIGHT_LINE_INPUT_1_VOLUME,
WM8995_IN1_VU_MASK, WM8995_IN1_VU);
wm8995_update_class_w(codec);
snd_soc_add_controls(codec, wm8995_snd_controls,
ARRAY_SIZE(wm8995_snd_controls));
snd_soc_dapm_new_controls(&codec->dapm, wm8995_dapm_widgets,
ARRAY_SIZE(wm8995_dapm_widgets));
snd_soc_dapm_add_routes(&codec->dapm, wm8995_intercon,
ARRAY_SIZE(wm8995_intercon));
return 0;
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8995->supplies), wm8995->supplies);
err_reg_get:
regulator_bulk_free(ARRAY_SIZE(wm8995->supplies), wm8995->supplies);
return ret;
}
static int __devinit wm8995_spi_probe(struct spi_device *spi)
{
struct wm8995_priv *wm8995;
int ret;
wm8995 = kzalloc(sizeof *wm8995, GFP_KERNEL);
if (!wm8995)
return -ENOMEM;
wm8995->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, wm8995);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8995, wm8995_dai,
ARRAY_SIZE(wm8995_dai));
if (ret < 0)
kfree(wm8995);
return ret;
}
static int __devexit wm8995_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static __devinit int wm8995_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8995_priv *wm8995;
int ret;
wm8995 = kzalloc(sizeof *wm8995, GFP_KERNEL);
if (!wm8995)
return -ENOMEM;
wm8995->control_type = SND_SOC_I2C;
i2c_set_clientdata(i2c, wm8995);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8995, wm8995_dai,
ARRAY_SIZE(wm8995_dai));
if (ret < 0)
kfree(wm8995);
return ret;
}
static __devexit int wm8995_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8995_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8995_i2c_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8995 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8995_spi_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8995 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8995_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8995_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8995_spi_driver);
#endif
}
