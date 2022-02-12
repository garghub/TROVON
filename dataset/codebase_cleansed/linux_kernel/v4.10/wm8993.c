static bool wm8993_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8993_SOFTWARE_RESET:
case WM8993_GPIO_CTRL_1:
case WM8993_DC_SERVO_0:
case WM8993_DC_SERVO_READBACK_0:
case WM8993_DC_SERVO_READBACK_1:
case WM8993_DC_SERVO_READBACK_2:
return true;
default:
return false;
}
}
static bool wm8993_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8993_SOFTWARE_RESET:
case WM8993_POWER_MANAGEMENT_1:
case WM8993_POWER_MANAGEMENT_2:
case WM8993_POWER_MANAGEMENT_3:
case WM8993_AUDIO_INTERFACE_1:
case WM8993_AUDIO_INTERFACE_2:
case WM8993_CLOCKING_1:
case WM8993_CLOCKING_2:
case WM8993_AUDIO_INTERFACE_3:
case WM8993_AUDIO_INTERFACE_4:
case WM8993_DAC_CTRL:
case WM8993_LEFT_DAC_DIGITAL_VOLUME:
case WM8993_RIGHT_DAC_DIGITAL_VOLUME:
case WM8993_DIGITAL_SIDE_TONE:
case WM8993_ADC_CTRL:
case WM8993_LEFT_ADC_DIGITAL_VOLUME:
case WM8993_RIGHT_ADC_DIGITAL_VOLUME:
case WM8993_GPIO_CTRL_1:
case WM8993_GPIO1:
case WM8993_IRQ_DEBOUNCE:
case WM8993_GPIOCTRL_2:
case WM8993_GPIO_POL:
case WM8993_LEFT_LINE_INPUT_1_2_VOLUME:
case WM8993_LEFT_LINE_INPUT_3_4_VOLUME:
case WM8993_RIGHT_LINE_INPUT_1_2_VOLUME:
case WM8993_RIGHT_LINE_INPUT_3_4_VOLUME:
case WM8993_LEFT_OUTPUT_VOLUME:
case WM8993_RIGHT_OUTPUT_VOLUME:
case WM8993_LINE_OUTPUTS_VOLUME:
case WM8993_HPOUT2_VOLUME:
case WM8993_LEFT_OPGA_VOLUME:
case WM8993_RIGHT_OPGA_VOLUME:
case WM8993_SPKMIXL_ATTENUATION:
case WM8993_SPKMIXR_ATTENUATION:
case WM8993_SPKOUT_MIXERS:
case WM8993_SPKOUT_BOOST:
case WM8993_SPEAKER_VOLUME_LEFT:
case WM8993_SPEAKER_VOLUME_RIGHT:
case WM8993_INPUT_MIXER2:
case WM8993_INPUT_MIXER3:
case WM8993_INPUT_MIXER4:
case WM8993_INPUT_MIXER5:
case WM8993_INPUT_MIXER6:
case WM8993_OUTPUT_MIXER1:
case WM8993_OUTPUT_MIXER2:
case WM8993_OUTPUT_MIXER3:
case WM8993_OUTPUT_MIXER4:
case WM8993_OUTPUT_MIXER5:
case WM8993_OUTPUT_MIXER6:
case WM8993_HPOUT2_MIXER:
case WM8993_LINE_MIXER1:
case WM8993_LINE_MIXER2:
case WM8993_SPEAKER_MIXER:
case WM8993_ADDITIONAL_CONTROL:
case WM8993_ANTIPOP1:
case WM8993_ANTIPOP2:
case WM8993_MICBIAS:
case WM8993_FLL_CONTROL_1:
case WM8993_FLL_CONTROL_2:
case WM8993_FLL_CONTROL_3:
case WM8993_FLL_CONTROL_4:
case WM8993_FLL_CONTROL_5:
case WM8993_CLOCKING_3:
case WM8993_CLOCKING_4:
case WM8993_MW_SLAVE_CONTROL:
case WM8993_BUS_CONTROL_1:
case WM8993_WRITE_SEQUENCER_0:
case WM8993_WRITE_SEQUENCER_1:
case WM8993_WRITE_SEQUENCER_2:
case WM8993_WRITE_SEQUENCER_3:
case WM8993_WRITE_SEQUENCER_4:
case WM8993_WRITE_SEQUENCER_5:
case WM8993_CHARGE_PUMP_1:
case WM8993_CLASS_W_0:
case WM8993_DC_SERVO_0:
case WM8993_DC_SERVO_1:
case WM8993_DC_SERVO_3:
case WM8993_DC_SERVO_READBACK_0:
case WM8993_DC_SERVO_READBACK_1:
case WM8993_DC_SERVO_READBACK_2:
case WM8993_ANALOGUE_HP_0:
case WM8993_EQ1:
case WM8993_EQ2:
case WM8993_EQ3:
case WM8993_EQ4:
case WM8993_EQ5:
case WM8993_EQ6:
case WM8993_EQ7:
case WM8993_EQ8:
case WM8993_EQ9:
case WM8993_EQ10:
case WM8993_EQ11:
case WM8993_EQ12:
case WM8993_EQ13:
case WM8993_EQ14:
case WM8993_EQ15:
case WM8993_EQ16:
case WM8993_EQ17:
case WM8993_EQ18:
case WM8993_EQ19:
case WM8993_EQ20:
case WM8993_EQ21:
case WM8993_EQ22:
case WM8993_EQ23:
case WM8993_EQ24:
case WM8993_DIGITAL_PULLS:
case WM8993_DRC_CONTROL_1:
case WM8993_DRC_CONTROL_2:
case WM8993_DRC_CONTROL_3:
case WM8993_DRC_CONTROL_4:
return true;
default:
return false;
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
struct i2c_client *i2c = to_i2c_client(codec->dev);
u16 reg1, reg4, reg5;
struct _fll_div fll_div;
unsigned int timeout;
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
if (i2c->irq)
timeout = msecs_to_jiffies(20);
else if (Fref < 1000000)
timeout = msecs_to_jiffies(3);
else
timeout = msecs_to_jiffies(1);
try_wait_for_completion(&wm8993->fll_lock);
snd_soc_write(codec, WM8993_FLL_CONTROL_1, reg1 | WM8993_FLL_ENA);
timeout = wait_for_completion_timeout(&wm8993->fll_lock, timeout);
if (i2c->irq && !timeout)
dev_warn(codec->dev, "Timed out waiting for FLL\n");
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
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return configure_clock(codec);
case SND_SOC_DAPM_POST_PMD:
break;
}
return 0;
}
static int wm8993_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret;
wm_hubs_set_bias_level(codec, level);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_VMID_SEL_MASK, 0x2);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_2,
WM8993_TSHUT_ENA, WM8993_TSHUT_ENA);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0)
return ret;
regcache_cache_only(wm8993->regmap, false);
regcache_sync(wm8993->regmap);
wm_hubs_vmid_ena(codec);
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
regcache_cache_only(wm8993->regmap, true);
regcache_mark_dirty(wm8993->regmap);
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
break;
}
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
switch (params_width(params)) {
case 16:
wm8993->bclk *= 16;
break;
case 20:
wm8993->bclk *= 20;
aif1 |= 0x8;
break;
case 24:
wm8993->bclk *= 24;
aif1 |= 0x10;
break;
case 32:
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
static irqreturn_t wm8993_irq(int irq, void *data)
{
struct wm8993_priv *wm8993 = data;
int mask, val, ret;
ret = regmap_read(wm8993->regmap, WM8993_GPIO_CTRL_1, &val);
if (ret != 0) {
dev_err(wm8993->dev, "Failed to read interrupt status: %d\n",
ret);
return IRQ_NONE;
}
ret = regmap_read(wm8993->regmap, WM8993_GPIOCTRL_2, &mask);
if (ret != 0) {
dev_err(wm8993->dev, "Failed to read interrupt mask: %d\n",
ret);
return IRQ_NONE;
}
val &= ~(mask | WM8993_IRQ);
if (!val)
return IRQ_NONE;
if (val & WM8993_TEMPOK_EINT)
dev_crit(wm8993->dev, "Thermal warning\n");
if (val & WM8993_FLL_LOCK_EINT) {
dev_dbg(wm8993->dev, "FLL locked\n");
complete(&wm8993->fll_lock);
}
ret = regmap_write(wm8993->regmap, WM8993_GPIO_CTRL_1, val);
if (ret != 0)
dev_err(wm8993->dev, "Failed to ack interrupt: %d\n", ret);
return IRQ_HANDLED;
}
static int wm8993_probe(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
wm8993->hubs_data.hp_startup_mode = 1;
wm8993->hubs_data.dcs_codes_l = -2;
wm8993->hubs_data.dcs_codes_r = -2;
wm8993->hubs_data.series_startup = 1;
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
wm8993->pdata.micbias1_delay,
wm8993->pdata.micbias2_delay,
wm8993->pdata.micbias1_lvl,
wm8993->pdata.micbias2_lvl);
snd_soc_add_codec_controls(codec, wm8993_snd_controls,
ARRAY_SIZE(wm8993_snd_controls));
if (wm8993->pdata.num_retune_configs != 0) {
dev_dbg(codec->dev, "Using ReTune Mobile\n");
} else {
dev_dbg(codec->dev, "No ReTune Mobile, using normal EQ\n");
snd_soc_add_codec_controls(codec, wm8993_eq_controls,
ARRAY_SIZE(wm8993_eq_controls));
}
snd_soc_dapm_new_controls(dapm, wm8993_dapm_widgets,
ARRAY_SIZE(wm8993_dapm_widgets));
wm_hubs_add_analogue_controls(codec);
snd_soc_dapm_add_routes(dapm, routes, ARRAY_SIZE(routes));
wm_hubs_add_analogue_routes(codec, wm8993->pdata.lineout1_diff,
wm8993->pdata.lineout2_diff);
if (wm8993->pdata.lineout1_diff && wm8993->pdata.lineout2_diff)
dapm->idle_bias_off = 1;
return 0;
}
static int wm8993_suspend(struct snd_soc_codec *codec)
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
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8993_resume(struct snd_soc_codec *codec)
{
struct wm8993_priv *wm8993 = snd_soc_codec_get_drvdata(codec);
int ret;
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
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
static int wm8993_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8993_priv *wm8993;
unsigned int reg;
int ret, i;
wm8993 = devm_kzalloc(&i2c->dev, sizeof(struct wm8993_priv),
GFP_KERNEL);
if (wm8993 == NULL)
return -ENOMEM;
wm8993->dev = &i2c->dev;
init_completion(&wm8993->fll_lock);
wm8993->regmap = devm_regmap_init_i2c(i2c, &wm8993_regmap);
if (IS_ERR(wm8993->regmap)) {
ret = PTR_ERR(wm8993->regmap);
dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, wm8993);
for (i = 0; i < ARRAY_SIZE(wm8993->supplies); i++)
wm8993->supplies[i].supply = wm8993_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8993->supplies),
wm8993->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = regmap_read(wm8993->regmap, WM8993_SOFTWARE_RESET, &reg);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read chip ID: %d\n", ret);
goto err_enable;
}
if (reg != 0x8993) {
dev_err(&i2c->dev, "Invalid ID register value %x\n", reg);
ret = -EINVAL;
goto err_enable;
}
ret = regmap_write(wm8993->regmap, WM8993_SOFTWARE_RESET, 0xffff);
if (ret != 0)
goto err_enable;
ret = regmap_register_patch(wm8993->regmap, wm8993_regmap_patch,
ARRAY_SIZE(wm8993_regmap_patch));
if (ret != 0)
dev_warn(wm8993->dev, "Failed to apply regmap patch: %d\n",
ret);
if (i2c->irq) {
ret = regmap_update_bits(wm8993->regmap, WM8993_GPIO1,
WM8993_GPIO1_PD |
WM8993_GPIO1_SEL_MASK, 7);
if (ret != 0)
goto err_enable;
ret = request_threaded_irq(i2c->irq, NULL, wm8993_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"wm8993", wm8993);
if (ret != 0)
goto err_enable;
}
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
regcache_cache_only(wm8993->regmap, true);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8993, &wm8993_dai, 1);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
goto err_irq;
}
return 0;
err_irq:
if (i2c->irq)
free_irq(i2c->irq, wm8993);
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
return ret;
}
static int wm8993_i2c_remove(struct i2c_client *i2c)
{
struct wm8993_priv *wm8993 = i2c_get_clientdata(i2c);
snd_soc_unregister_codec(&i2c->dev);
if (i2c->irq)
free_irq(i2c->irq, wm8993);
regulator_bulk_disable(ARRAY_SIZE(wm8993->supplies), wm8993->supplies);
return 0;
}
