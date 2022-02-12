static inline int wm8350_out1_ramp_step(struct snd_soc_codec *codec)
{
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out1 = &wm8350_data->out1;
struct wm8350 *wm8350 = wm8350_data->wm8350;
int left_complete = 0, right_complete = 0;
u16 reg, val;
reg = wm8350_reg_read(wm8350, WM8350_LOUT1_VOLUME);
val = (reg & WM8350_OUT1L_VOL_MASK) >> WM8350_OUT1L_VOL_SHIFT;
if (out1->ramp == WM8350_RAMP_UP) {
if (val < out1->left_vol) {
val++;
reg &= ~WM8350_OUT1L_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_LOUT1_VOLUME,
reg | (val << WM8350_OUT1L_VOL_SHIFT));
} else
left_complete = 1;
} else if (out1->ramp == WM8350_RAMP_DOWN) {
if (val > 0) {
val--;
reg &= ~WM8350_OUT1L_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_LOUT1_VOLUME,
reg | (val << WM8350_OUT1L_VOL_SHIFT));
} else
left_complete = 1;
} else
return 1;
reg = wm8350_reg_read(wm8350, WM8350_ROUT1_VOLUME);
val = (reg & WM8350_OUT1R_VOL_MASK) >> WM8350_OUT1R_VOL_SHIFT;
if (out1->ramp == WM8350_RAMP_UP) {
if (val < out1->right_vol) {
val++;
reg &= ~WM8350_OUT1R_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_ROUT1_VOLUME,
reg | (val << WM8350_OUT1R_VOL_SHIFT));
} else
right_complete = 1;
} else if (out1->ramp == WM8350_RAMP_DOWN) {
if (val > 0) {
val--;
reg &= ~WM8350_OUT1R_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_ROUT1_VOLUME,
reg | (val << WM8350_OUT1R_VOL_SHIFT));
} else
right_complete = 1;
}
if (!left_complete || !right_complete)
wm8350_set_bits(wm8350, WM8350_LOUT1_VOLUME, WM8350_OUT1_VU);
return left_complete & right_complete;
}
static inline int wm8350_out2_ramp_step(struct snd_soc_codec *codec)
{
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out2 = &wm8350_data->out2;
struct wm8350 *wm8350 = wm8350_data->wm8350;
int left_complete = 0, right_complete = 0;
u16 reg, val;
reg = wm8350_reg_read(wm8350, WM8350_LOUT2_VOLUME);
val = (reg & WM8350_OUT2L_VOL_MASK) >> WM8350_OUT1L_VOL_SHIFT;
if (out2->ramp == WM8350_RAMP_UP) {
if (val < out2->left_vol) {
val++;
reg &= ~WM8350_OUT2L_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_LOUT2_VOLUME,
reg | (val << WM8350_OUT1L_VOL_SHIFT));
} else
left_complete = 1;
} else if (out2->ramp == WM8350_RAMP_DOWN) {
if (val > 0) {
val--;
reg &= ~WM8350_OUT2L_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_LOUT2_VOLUME,
reg | (val << WM8350_OUT1L_VOL_SHIFT));
} else
left_complete = 1;
} else
return 1;
reg = wm8350_reg_read(wm8350, WM8350_ROUT2_VOLUME);
val = (reg & WM8350_OUT2R_VOL_MASK) >> WM8350_OUT1R_VOL_SHIFT;
if (out2->ramp == WM8350_RAMP_UP) {
if (val < out2->right_vol) {
val++;
reg &= ~WM8350_OUT2R_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_ROUT2_VOLUME,
reg | (val << WM8350_OUT1R_VOL_SHIFT));
} else
right_complete = 1;
} else if (out2->ramp == WM8350_RAMP_DOWN) {
if (val > 0) {
val--;
reg &= ~WM8350_OUT2R_VOL_MASK;
wm8350_reg_write(wm8350, WM8350_ROUT2_VOLUME,
reg | (val << WM8350_OUT1R_VOL_SHIFT));
} else
right_complete = 1;
}
if (!left_complete || !right_complete)
wm8350_set_bits(wm8350, WM8350_LOUT2_VOLUME, WM8350_OUT2_VU);
return left_complete & right_complete;
}
static void wm8350_pga_work(struct work_struct *work)
{
struct snd_soc_dapm_context *dapm =
container_of(work, struct snd_soc_dapm_context, delayed_work.work);
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(dapm);
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out1 = &wm8350_data->out1,
*out2 = &wm8350_data->out2;
int i, out1_complete, out2_complete;
if (out1->ramp == WM8350_RAMP_NONE && out2->ramp == WM8350_RAMP_NONE)
return;
for (i = 0; i <= 63; i++) {
out1_complete = 1, out2_complete = 1;
if (out1->ramp != WM8350_RAMP_NONE)
out1_complete = wm8350_out1_ramp_step(codec);
if (out2->ramp != WM8350_RAMP_NONE)
out2_complete = wm8350_out2_ramp_step(codec);
if (out1_complete && out2_complete)
break;
if (out1->ramp == WM8350_RAMP_UP ||
out2->ramp == WM8350_RAMP_UP) {
if (i >= WM8350_OUTn_0dB)
schedule_timeout_interruptible(msecs_to_jiffies
(2));
else
schedule_timeout_interruptible(msecs_to_jiffies
(1));
} else
udelay(50);
}
out1->ramp = WM8350_RAMP_NONE;
out2->ramp = WM8350_RAMP_NONE;
}
static int pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out;
switch (w->shift) {
case 0:
case 1:
out = &wm8350_data->out1;
break;
case 2:
case 3:
out = &wm8350_data->out2;
break;
default:
WARN(1, "Invalid shift %d\n", w->shift);
return -1;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
out->ramp = WM8350_RAMP_UP;
out->active = 1;
schedule_delayed_work(&codec->dapm.delayed_work,
msecs_to_jiffies(1));
break;
case SND_SOC_DAPM_PRE_PMD:
out->ramp = WM8350_RAMP_DOWN;
out->active = 0;
schedule_delayed_work(&codec->dapm.delayed_work,
msecs_to_jiffies(1));
break;
}
return 0;
}
static int wm8350_put_volsw_2r_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8350_data *wm8350_priv = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out = NULL;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int ret;
unsigned int reg = mc->reg;
u16 val;
switch (reg) {
case WM8350_LOUT1_VOLUME:
out = &wm8350_priv->out1;
break;
case WM8350_LOUT2_VOLUME:
out = &wm8350_priv->out2;
break;
default:
break;
}
if (out) {
out->left_vol = ucontrol->value.integer.value[0];
out->right_vol = ucontrol->value.integer.value[1];
if (!out->active)
return 1;
}
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret < 0)
return ret;
val = snd_soc_read(codec, reg);
snd_soc_write(codec, reg, val | WM8350_OUT1_VU);
return 1;
}
static int wm8350_get_volsw_2r(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8350_data *wm8350_priv = snd_soc_codec_get_drvdata(codec);
struct wm8350_output *out1 = &wm8350_priv->out1;
struct wm8350_output *out2 = &wm8350_priv->out2;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
switch (reg) {
case WM8350_LOUT1_VOLUME:
ucontrol->value.integer.value[0] = out1->left_vol;
ucontrol->value.integer.value[1] = out1->right_vol;
return 0;
case WM8350_LOUT2_VOLUME:
ucontrol->value.integer.value[0] = out2->left_vol;
ucontrol->value.integer.value[1] = out2->right_vol;
return 0;
default:
break;
}
return snd_soc_get_volsw(kcontrol, ucontrol);
}
static int wm8350_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = wm8350_data->wm8350;
u16 fll_4;
switch (clk_id) {
case WM8350_MCLK_SEL_MCLK:
wm8350_clear_bits(wm8350, WM8350_CLOCK_CONTROL_1,
WM8350_MCLK_SEL);
break;
case WM8350_MCLK_SEL_PLL_MCLK:
case WM8350_MCLK_SEL_PLL_DAC:
case WM8350_MCLK_SEL_PLL_ADC:
case WM8350_MCLK_SEL_PLL_32K:
wm8350_set_bits(wm8350, WM8350_CLOCK_CONTROL_1,
WM8350_MCLK_SEL);
fll_4 = snd_soc_read(codec, WM8350_FLL_CONTROL_4) &
~WM8350_FLL_CLK_SRC_MASK;
snd_soc_write(codec, WM8350_FLL_CONTROL_4, fll_4 | clk_id);
break;
}
if (dir == SND_SOC_CLOCK_OUT)
wm8350_set_bits(wm8350, WM8350_CLOCK_CONTROL_2,
WM8350_MCLK_DIR);
else
wm8350_clear_bits(wm8350, WM8350_CLOCK_CONTROL_2,
WM8350_MCLK_DIR);
return 0;
}
static int wm8350_set_clkdiv(struct snd_soc_dai *codec_dai, int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 val;
switch (div_id) {
case WM8350_ADC_CLKDIV:
val = snd_soc_read(codec, WM8350_ADC_DIVIDER) &
~WM8350_ADC_CLKDIV_MASK;
snd_soc_write(codec, WM8350_ADC_DIVIDER, val | div);
break;
case WM8350_DAC_CLKDIV:
val = snd_soc_read(codec, WM8350_DAC_CLOCK_CONTROL) &
~WM8350_DAC_CLKDIV_MASK;
snd_soc_write(codec, WM8350_DAC_CLOCK_CONTROL, val | div);
break;
case WM8350_BCLK_CLKDIV:
val = snd_soc_read(codec, WM8350_CLOCK_CONTROL_1) &
~WM8350_BCLK_DIV_MASK;
snd_soc_write(codec, WM8350_CLOCK_CONTROL_1, val | div);
break;
case WM8350_OPCLK_CLKDIV:
val = snd_soc_read(codec, WM8350_CLOCK_CONTROL_1) &
~WM8350_OPCLK_DIV_MASK;
snd_soc_write(codec, WM8350_CLOCK_CONTROL_1, val | div);
break;
case WM8350_SYS_CLKDIV:
val = snd_soc_read(codec, WM8350_CLOCK_CONTROL_1) &
~WM8350_MCLK_DIV_MASK;
snd_soc_write(codec, WM8350_CLOCK_CONTROL_1, val | div);
break;
case WM8350_DACLR_CLKDIV:
val = snd_soc_read(codec, WM8350_DAC_LR_RATE) &
~WM8350_DACLRC_RATE_MASK;
snd_soc_write(codec, WM8350_DAC_LR_RATE, val | div);
break;
case WM8350_ADCLR_CLKDIV:
val = snd_soc_read(codec, WM8350_ADC_LR_RATE) &
~WM8350_ADCLRC_RATE_MASK;
snd_soc_write(codec, WM8350_ADC_LR_RATE, val | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8350_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8350_AI_FORMATING) &
~(WM8350_AIF_BCLK_INV | WM8350_AIF_LRCLK_INV | WM8350_AIF_FMT_MASK);
u16 master = snd_soc_read(codec, WM8350_AI_DAC_CONTROL) &
~WM8350_BCLK_MSTR;
u16 dac_lrc = snd_soc_read(codec, WM8350_DAC_LR_RATE) &
~WM8350_DACLRC_ENA;
u16 adc_lrc = snd_soc_read(codec, WM8350_ADC_LR_RATE) &
~WM8350_ADCLRC_ENA;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
master |= WM8350_BCLK_MSTR;
dac_lrc |= WM8350_DACLRC_ENA;
adc_lrc |= WM8350_ADCLRC_ENA;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x2 << 8;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x1 << 8;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x3 << 8;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x3 << 8 | WM8350_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= WM8350_AIF_LRCLK_INV | WM8350_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= WM8350_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= WM8350_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8350_AI_FORMATING, iface);
snd_soc_write(codec, WM8350_AI_DAC_CONTROL, master);
snd_soc_write(codec, WM8350_DAC_LR_RATE, dac_lrc);
snd_soc_write(codec, WM8350_ADC_LR_RATE, adc_lrc);
return 0;
}
static int wm8350_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8350_data *wm8350_data = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = wm8350_data->wm8350;
u16 iface = snd_soc_read(codec, WM8350_AI_FORMATING) &
~WM8350_AIF_WL_MASK;
switch (params_width(params)) {
case 16:
break;
case 20:
iface |= 0x1 << 10;
break;
case 24:
iface |= 0x2 << 10;
break;
case 32:
iface |= 0x3 << 10;
break;
}
snd_soc_write(codec, WM8350_AI_FORMATING, iface);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (params_rate(params) < 24000)
wm8350_set_bits(wm8350, WM8350_DAC_MUTE_VOLUME,
WM8350_DAC_SB_FILT);
else
wm8350_clear_bits(wm8350, WM8350_DAC_MUTE_VOLUME,
WM8350_DAC_SB_FILT);
}
return 0;
}
static int wm8350_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val;
if (mute)
val = WM8350_DAC_MUTE_ENA;
else
val = 0;
snd_soc_update_bits(codec, WM8350_DAC_MUTE, WM8350_DAC_MUTE_ENA, val);
return 0;
}
static inline int fll_factors(struct _fll_div *fll_div, unsigned int input,
unsigned int output)
{
u64 Kpart;
unsigned int t1, t2, K, Nmod;
if (output >= 2815250 && output <= 3125000)
fll_div->div = 0x4;
else if (output >= 5625000 && output <= 6250000)
fll_div->div = 0x3;
else if (output >= 11250000 && output <= 12500000)
fll_div->div = 0x2;
else if (output >= 22500000 && output <= 25000000)
fll_div->div = 0x1;
else {
printk(KERN_ERR "wm8350: fll freq %d out of range\n", output);
return -EINVAL;
}
if (input > 48000)
fll_div->ratio = 1;
else
fll_div->ratio = 8;
t1 = output * (1 << (fll_div->div + 1));
t2 = input * fll_div->ratio;
fll_div->n = t1 / t2;
Nmod = t1 % t2;
if (Nmod) {
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, t2);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
fll_div->k = K;
} else
fll_div->k = 0;
return 0;
}
static int wm8350_set_fll(struct snd_soc_dai *codec_dai,
int pll_id, int source, unsigned int freq_in,
unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8350_data *priv = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = priv->wm8350;
struct _fll_div fll_div;
int ret = 0;
u16 fll_1, fll_4;
if (freq_in == priv->fll_freq_in && freq_out == priv->fll_freq_out)
return 0;
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_4,
WM8350_FLL_ENA | WM8350_FLL_OSC_ENA);
if (freq_out == 0 || freq_in == 0)
return ret;
ret = fll_factors(&fll_div, freq_in, freq_out);
if (ret < 0)
return ret;
dev_dbg(wm8350->dev,
"FLL in %u FLL out %u N 0x%x K 0x%x div %d ratio %d",
freq_in, freq_out, fll_div.n, fll_div.k, fll_div.div,
fll_div.ratio);
fll_1 = snd_soc_read(codec, WM8350_FLL_CONTROL_1) &
~(WM8350_FLL_OUTDIV_MASK | WM8350_FLL_RSP_RATE_MASK | 0xc000);
snd_soc_write(codec, WM8350_FLL_CONTROL_1,
fll_1 | (fll_div.div << 8) | 0x50);
snd_soc_write(codec, WM8350_FLL_CONTROL_2,
(fll_div.ratio << 11) | (fll_div.
n & WM8350_FLL_N_MASK));
snd_soc_write(codec, WM8350_FLL_CONTROL_3, fll_div.k);
fll_4 = snd_soc_read(codec, WM8350_FLL_CONTROL_4) &
~(WM8350_FLL_FRAC | WM8350_FLL_SLOW_LOCK_REF);
snd_soc_write(codec, WM8350_FLL_CONTROL_4,
fll_4 | (fll_div.k ? WM8350_FLL_FRAC : 0) |
(fll_div.ratio == 8 ? WM8350_FLL_SLOW_LOCK_REF : 0));
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_4, WM8350_FLL_OSC_ENA);
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_4, WM8350_FLL_ENA);
priv->fll_freq_out = freq_out;
priv->fll_freq_in = freq_in;
return 0;
}
static int wm8350_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8350_data *priv = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = priv->wm8350;
struct wm8350_audio_platform_data *platform =
wm8350->codec.platform_data;
u16 pm1;
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1) &
~(WM8350_VMID_MASK | WM8350_CODEC_ISEL_MASK);
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
pm1 | WM8350_VMID_50K |
platform->codec_current_on << 14);
break;
case SND_SOC_BIAS_PREPARE:
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1);
pm1 &= ~WM8350_VMID_MASK;
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
pm1 | WM8350_VMID_50K);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(priv->supplies),
priv->supplies);
if (ret != 0)
return ret;
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_4,
WM8350_SYSCLK_ENA);
wm8350_set_bits(wm8350, WM8350_DAC_MUTE,
WM8350_DAC_MUTE_ENA);
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL,
platform->dis_out1 |
(platform->dis_out2 << 2) |
(platform->dis_out3 << 4) |
(platform->dis_out4 << 6));
schedule_timeout_interruptible(msecs_to_jiffies
(platform->
cap_discharge_msecs));
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL,
(platform->vmid_s_curve << 8));
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
(platform->
codec_current_charge << 14) |
WM8350_VMID_5K | WM8350_VMIDEN |
WM8350_VBUFEN);
schedule_timeout_interruptible(msecs_to_jiffies
(platform->
vmid_charge_msecs));
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1) &
~(WM8350_VMID_MASK | WM8350_CODEC_ISEL_MASK);
pm1 |= WM8350_VMID_300K |
(platform->codec_current_standby << 14);
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
pm1);
pm1 |= WM8350_BIASEN;
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1, pm1);
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL, 0);
} else {
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1) &
~(WM8350_VMID_MASK | WM8350_CODEC_ISEL_MASK);
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
pm1 | WM8350_VMID_300K |
(platform->
codec_current_standby << 14));
}
break;
case SND_SOC_BIAS_OFF:
wm8350_set_bits(wm8350, WM8350_DAC_MUTE, WM8350_DAC_MUTE_ENA);
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_3,
WM8350_OUT1L_ENA | WM8350_OUT1R_ENA |
WM8350_OUT2L_ENA | WM8350_OUT2R_ENA);
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL,
(platform->vmid_s_curve << 8));
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1) &
~WM8350_VMIDEN;
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1, pm1);
schedule_timeout_interruptible(msecs_to_jiffies
(platform->
vmid_discharge_msecs));
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL,
(platform->vmid_s_curve << 8) |
platform->dis_out1 |
(platform->dis_out2 << 2) |
(platform->dis_out3 << 4) |
(platform->dis_out4 << 6));
pm1 = wm8350_reg_read(wm8350, WM8350_POWER_MGMT_1) &
~(WM8350_VBUFEN | WM8350_VMID_MASK);
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1,
pm1 | WM8350_OUTPUT_DRAIN_EN);
schedule_timeout_interruptible(msecs_to_jiffies
(platform->drain_msecs));
pm1 &= ~WM8350_BIASEN;
wm8350_reg_write(wm8350, WM8350_POWER_MGMT_1, pm1);
wm8350_reg_write(wm8350, WM8350_ANTI_POP_CONTROL, 0);
wm8350_clear_bits(wm8350, WM8350_LOUT1_VOLUME,
WM8350_OUT1L_ENA);
wm8350_clear_bits(wm8350, WM8350_ROUT1_VOLUME,
WM8350_OUT1R_ENA);
wm8350_clear_bits(wm8350, WM8350_LOUT2_VOLUME,
WM8350_OUT2L_ENA);
wm8350_clear_bits(wm8350, WM8350_ROUT2_VOLUME,
WM8350_OUT2R_ENA);
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_4,
WM8350_SYSCLK_ENA);
regulator_bulk_disable(ARRAY_SIZE(priv->supplies),
priv->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8350_suspend(struct snd_soc_codec *codec)
{
wm8350_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8350_resume(struct snd_soc_codec *codec)
{
wm8350_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static void wm8350_hp_work(struct wm8350_data *priv,
struct wm8350_jack_data *jack,
u16 mask)
{
struct wm8350 *wm8350 = priv->wm8350;
u16 reg;
int report;
reg = wm8350_reg_read(wm8350, WM8350_JACK_PIN_STATUS);
if (reg & mask)
report = jack->report;
else
report = 0;
snd_soc_jack_report(jack->jack, report, jack->report);
}
static void wm8350_hpl_work(struct work_struct *work)
{
struct wm8350_data *priv =
container_of(work, struct wm8350_data, hpl.work.work);
wm8350_hp_work(priv, &priv->hpl, WM8350_JACK_L_LVL);
}
static void wm8350_hpr_work(struct work_struct *work)
{
struct wm8350_data *priv =
container_of(work, struct wm8350_data, hpr.work.work);
wm8350_hp_work(priv, &priv->hpr, WM8350_JACK_R_LVL);
}
static irqreturn_t wm8350_hpl_jack_handler(int irq, void *data)
{
struct wm8350_data *priv = data;
struct wm8350 *wm8350 = priv->wm8350;
#ifndef CONFIG_SND_SOC_WM8350_MODULE
trace_snd_soc_jack_irq("WM8350 HPL");
#endif
if (device_may_wakeup(wm8350->dev))
pm_wakeup_event(wm8350->dev, 250);
queue_delayed_work(system_power_efficient_wq,
&priv->hpl.work, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
static irqreturn_t wm8350_hpr_jack_handler(int irq, void *data)
{
struct wm8350_data *priv = data;
struct wm8350 *wm8350 = priv->wm8350;
#ifndef CONFIG_SND_SOC_WM8350_MODULE
trace_snd_soc_jack_irq("WM8350 HPR");
#endif
if (device_may_wakeup(wm8350->dev))
pm_wakeup_event(wm8350->dev, 250);
queue_delayed_work(system_power_efficient_wq,
&priv->hpr.work, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
int wm8350_hp_jack_detect(struct snd_soc_codec *codec, enum wm8350_jack which,
struct snd_soc_jack *jack, int report)
{
struct wm8350_data *priv = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = priv->wm8350;
int ena;
switch (which) {
case WM8350_JDL:
priv->hpl.jack = jack;
priv->hpl.report = report;
ena = WM8350_JDL_ENA;
break;
case WM8350_JDR:
priv->hpr.jack = jack;
priv->hpr.report = report;
ena = WM8350_JDR_ENA;
break;
default:
return -EINVAL;
}
if (report) {
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_4, WM8350_TOCLK_ENA);
wm8350_set_bits(wm8350, WM8350_JACK_DETECT, ena);
} else {
wm8350_clear_bits(wm8350, WM8350_JACK_DETECT, ena);
}
switch (which) {
case WM8350_JDL:
wm8350_hpl_jack_handler(0, priv);
break;
case WM8350_JDR:
wm8350_hpr_jack_handler(0, priv);
break;
}
return 0;
}
static irqreturn_t wm8350_mic_handler(int irq, void *data)
{
struct wm8350_data *priv = data;
struct wm8350 *wm8350 = priv->wm8350;
u16 reg;
int report = 0;
#ifndef CONFIG_SND_SOC_WM8350_MODULE
trace_snd_soc_jack_irq("WM8350 mic");
#endif
reg = wm8350_reg_read(wm8350, WM8350_JACK_PIN_STATUS);
if (reg & WM8350_JACK_MICSCD_LVL)
report |= priv->mic.short_report;
if (reg & WM8350_JACK_MICSD_LVL)
report |= priv->mic.report;
snd_soc_jack_report(priv->mic.jack, report,
priv->mic.report | priv->mic.short_report);
return IRQ_HANDLED;
}
int wm8350_mic_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack,
int detect_report, int short_report)
{
struct wm8350_data *priv = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = priv->wm8350;
priv->mic.jack = jack;
priv->mic.report = detect_report;
priv->mic.short_report = short_report;
if (detect_report || short_report) {
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_4, WM8350_TOCLK_ENA);
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_1,
WM8350_MIC_DET_ENA);
} else {
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_1,
WM8350_MIC_DET_ENA);
}
return 0;
}
static int wm8350_codec_probe(struct snd_soc_codec *codec)
{
struct wm8350 *wm8350 = dev_get_platdata(codec->dev);
struct wm8350_data *priv;
struct wm8350_output *out1;
struct wm8350_output *out2;
int ret, i;
if (wm8350->codec.platform_data == NULL) {
dev_err(codec->dev, "No audio platform data supplied\n");
return -EINVAL;
}
priv = devm_kzalloc(codec->dev, sizeof(struct wm8350_data),
GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, priv);
priv->wm8350 = wm8350;
for (i = 0; i < ARRAY_SIZE(supply_names); i++)
priv->supplies[i].supply = supply_names[i];
ret = devm_regulator_bulk_get(wm8350->dev, ARRAY_SIZE(priv->supplies),
priv->supplies);
if (ret != 0)
return ret;
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_5, WM8350_CODEC_ENA);
INIT_DELAYED_WORK(&codec->dapm.delayed_work, wm8350_pga_work);
INIT_DELAYED_WORK(&priv->hpl.work, wm8350_hpl_work);
INIT_DELAYED_WORK(&priv->hpr.work, wm8350_hpr_work);
wm8350_set_bits(wm8350, WM8350_POWER_MGMT_5, WM8350_CODEC_ENA);
snd_soc_write(codec, WM8350_SECURITY, 0xa7);
snd_soc_write(codec, 0xde, 0x13);
snd_soc_write(codec, WM8350_SECURITY, 0);
out1 = &priv->out1;
out2 = &priv->out2;
out1->left_vol = (wm8350_reg_read(wm8350, WM8350_LOUT1_VOLUME) &
WM8350_OUT1L_VOL_MASK) >> WM8350_OUT1L_VOL_SHIFT;
out1->right_vol = (wm8350_reg_read(wm8350, WM8350_ROUT1_VOLUME) &
WM8350_OUT1R_VOL_MASK) >> WM8350_OUT1R_VOL_SHIFT;
out2->left_vol = (wm8350_reg_read(wm8350, WM8350_LOUT2_VOLUME) &
WM8350_OUT2L_VOL_MASK) >> WM8350_OUT1L_VOL_SHIFT;
out2->right_vol = (wm8350_reg_read(wm8350, WM8350_ROUT2_VOLUME) &
WM8350_OUT2R_VOL_MASK) >> WM8350_OUT1R_VOL_SHIFT;
wm8350_reg_write(wm8350, WM8350_LOUT1_VOLUME, 0);
wm8350_reg_write(wm8350, WM8350_ROUT1_VOLUME, 0);
wm8350_reg_write(wm8350, WM8350_LOUT2_VOLUME, 0);
wm8350_reg_write(wm8350, WM8350_ROUT2_VOLUME, 0);
wm8350_set_bits(wm8350, WM8350_LOUT1_VOLUME,
WM8350_OUT1_VU | WM8350_OUT1L_MUTE);
wm8350_set_bits(wm8350, WM8350_LOUT2_VOLUME,
WM8350_OUT2_VU | WM8350_OUT2L_MUTE);
wm8350_set_bits(wm8350, WM8350_ROUT1_VOLUME,
WM8350_OUT1_VU | WM8350_OUT1R_MUTE);
wm8350_set_bits(wm8350, WM8350_ROUT2_VOLUME,
WM8350_OUT2_VU | WM8350_OUT2R_MUTE);
wm8350_clear_bits(wm8350, WM8350_AI_FORMATING, WM8350_AIF_TRI);
wm8350_clear_bits(wm8350, WM8350_ADC_DAC_COMP,
WM8350_DAC_COMP | WM8350_LOOPBACK);
wm8350_clear_bits(wm8350, WM8350_JACK_DETECT,
WM8350_JDL_ENA | WM8350_JDR_ENA);
wm8350_register_irq(wm8350, WM8350_IRQ_CODEC_JCK_DET_L,
wm8350_hpl_jack_handler, 0, "Left jack detect",
priv);
wm8350_register_irq(wm8350, WM8350_IRQ_CODEC_JCK_DET_R,
wm8350_hpr_jack_handler, 0, "Right jack detect",
priv);
wm8350_register_irq(wm8350, WM8350_IRQ_CODEC_MICSCD,
wm8350_mic_handler, 0, "Microphone short", priv);
wm8350_register_irq(wm8350, WM8350_IRQ_CODEC_MICD,
wm8350_mic_handler, 0, "Microphone detect", priv);
wm8350_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8350_codec_remove(struct snd_soc_codec *codec)
{
struct wm8350_data *priv = snd_soc_codec_get_drvdata(codec);
struct wm8350 *wm8350 = dev_get_platdata(codec->dev);
wm8350_clear_bits(wm8350, WM8350_JACK_DETECT,
WM8350_JDL_ENA | WM8350_JDR_ENA);
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_4, WM8350_TOCLK_ENA);
wm8350_free_irq(wm8350, WM8350_IRQ_CODEC_MICD, priv);
wm8350_free_irq(wm8350, WM8350_IRQ_CODEC_MICSCD, priv);
wm8350_free_irq(wm8350, WM8350_IRQ_CODEC_JCK_DET_L, priv);
wm8350_free_irq(wm8350, WM8350_IRQ_CODEC_JCK_DET_R, priv);
priv->hpl.jack = NULL;
priv->hpr.jack = NULL;
priv->mic.jack = NULL;
cancel_delayed_work_sync(&priv->hpl.work);
cancel_delayed_work_sync(&priv->hpr.work);
flush_delayed_work(&codec->dapm.delayed_work);
wm8350_set_bias_level(codec, SND_SOC_BIAS_OFF);
wm8350_clear_bits(wm8350, WM8350_POWER_MGMT_5, WM8350_CODEC_ENA);
return 0;
}
static struct regmap *wm8350_get_regmap(struct device *dev)
{
struct wm8350 *wm8350 = dev_get_platdata(dev);
return wm8350->regmap;
}
static int wm8350_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm8350,
&wm8350_dai, 1);
}
static int wm8350_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
