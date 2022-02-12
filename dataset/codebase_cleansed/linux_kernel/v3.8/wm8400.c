static inline unsigned int wm8400_read(struct snd_soc_codec *codec,
unsigned int reg)
{
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
if (reg == WM8400_INTDRIVBITS)
return wm8400->fake_register;
else
return wm8400_reg_read(wm8400->wm8400, reg);
}
static int wm8400_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
if (reg == WM8400_INTDRIVBITS) {
wm8400->fake_register = value;
return 0;
} else
return wm8400_set_bits(wm8400->wm8400, reg, 0xffff, value);
}
static void wm8400_codec_reset(struct snd_soc_codec *codec)
{
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
wm8400_reset_codec_reg_cache(wm8400->wm8400);
}
static int wm8400_outpga_put_volsw_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int reg = mc->reg;
int ret;
u16 val;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret < 0)
return ret;
val = snd_soc_read(codec, reg);
return snd_soc_write(codec, reg, val | 0x0100);
}
static int inmixer_event (struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
u16 reg, fakepower;
reg = snd_soc_read(w->codec, WM8400_POWER_MANAGEMENT_2);
fakepower = snd_soc_read(w->codec, WM8400_INTDRIVBITS);
if (fakepower & ((1 << WM8400_INMIXL_PWR) |
(1 << WM8400_AINLMUX_PWR))) {
reg |= WM8400_AINL_ENA;
} else {
reg &= ~WM8400_AINL_ENA;
}
if (fakepower & ((1 << WM8400_INMIXR_PWR) |
(1 << WM8400_AINRMUX_PWR))) {
reg |= WM8400_AINR_ENA;
} else {
reg &= ~WM8400_AINR_ENA;
}
snd_soc_write(w->codec, WM8400_POWER_MANAGEMENT_2, reg);
return 0;
}
static int outmixer_event (struct snd_soc_dapm_widget *w,
struct snd_kcontrol * kcontrol, int event)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
u32 reg_shift = mc->shift;
int ret = 0;
u16 reg;
switch (reg_shift) {
case WM8400_SPEAKER_MIXER | (WM8400_LDSPK << 8) :
reg = snd_soc_read(w->codec, WM8400_OUTPUT_MIXER1);
if (reg & WM8400_LDLO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 1 LDLO Set\n");
ret = -1;
}
break;
case WM8400_SPEAKER_MIXER | (WM8400_RDSPK << 8):
reg = snd_soc_read(w->codec, WM8400_OUTPUT_MIXER2);
if (reg & WM8400_RDRO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 2 RDRO Set\n");
ret = -1;
}
break;
case WM8400_OUTPUT_MIXER1 | (WM8400_LDLO << 8):
reg = snd_soc_read(w->codec, WM8400_SPEAKER_MIXER);
if (reg & WM8400_LDSPK) {
printk(KERN_WARNING
"Cannot set as Speaker Mixer LDSPK Set\n");
ret = -1;
}
break;
case WM8400_OUTPUT_MIXER2 | (WM8400_RDRO << 8):
reg = snd_soc_read(w->codec, WM8400_SPEAKER_MIXER);
if (reg & WM8400_RDSPK) {
printk(KERN_WARNING
"Cannot set as Speaker Mixer RDSPK Set\n");
ret = -1;
}
break;
}
return ret;
}
static int wm8400_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
wm8400->sysclk = freq;
return 0;
}
static int fll_factors(struct wm8400_priv *wm8400, struct fll_factors *factors,
unsigned int Fref, unsigned int Fout)
{
u64 Kpart;
unsigned int K, Nmod, target;
factors->outdiv = 2;
while (Fout * factors->outdiv < 90000000 ||
Fout * factors->outdiv > 100000000) {
factors->outdiv *= 2;
if (factors->outdiv > 32) {
dev_err(wm8400->wm8400->dev,
"Unsupported FLL output frequency %uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * factors->outdiv;
factors->outdiv = factors->outdiv >> 2;
if (Fref < 48000)
factors->freq_ref = 1;
else
factors->freq_ref = 0;
if (Fref < 1000000)
factors->fratio = 9;
else
factors->fratio = 0;
do {
if (Fref < 1000000)
factors->fratio--;
else
factors->fratio++;
if (factors->fratio < 1 || factors->fratio > 8) {
dev_err(wm8400->wm8400->dev,
"Unable to calculate FRATIO\n");
return -EINVAL;
}
factors->n = target / (Fref * factors->fratio);
Nmod = target % (Fref * factors->fratio);
} while (Nmod == 0);
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, (Fref * factors->fratio));
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
factors->k = K / 10;
dev_dbg(wm8400->wm8400->dev,
"FLL: Fref=%u Fout=%u N=%x K=%x, FRATIO=%x OUTDIV=%x\n",
Fref, Fout,
factors->n, factors->k, factors->fratio, factors->outdiv);
return 0;
}
static int wm8400_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
struct fll_factors factors;
int ret;
u16 reg;
if (freq_in == wm8400->fll_in && freq_out == wm8400->fll_out)
return 0;
if (freq_out) {
ret = fll_factors(wm8400, &factors, freq_in, freq_out);
if (ret != 0)
return ret;
} else {
memset(&factors, 0, sizeof(factors));
}
wm8400->fll_out = freq_out;
wm8400->fll_in = freq_in;
reg = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_2);
reg &= ~WM8400_FLL_ENA;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_2, reg);
reg = snd_soc_read(codec, WM8400_FLL_CONTROL_1);
reg &= ~WM8400_FLL_OSC_ENA;
snd_soc_write(codec, WM8400_FLL_CONTROL_1, reg);
if (!freq_out)
return 0;
reg &= ~(WM8400_FLL_REF_FREQ | WM8400_FLL_FRATIO_MASK);
reg |= WM8400_FLL_FRAC | factors.fratio;
reg |= factors.freq_ref << WM8400_FLL_REF_FREQ_SHIFT;
snd_soc_write(codec, WM8400_FLL_CONTROL_1, reg);
snd_soc_write(codec, WM8400_FLL_CONTROL_2, factors.k);
snd_soc_write(codec, WM8400_FLL_CONTROL_3, factors.n);
reg = snd_soc_read(codec, WM8400_FLL_CONTROL_4);
reg &= ~WM8400_FLL_OUTDIV_MASK;
reg |= factors.outdiv;
snd_soc_write(codec, WM8400_FLL_CONTROL_4, reg);
return 0;
}
static int wm8400_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 audio1, audio3;
audio1 = snd_soc_read(codec, WM8400_AUDIO_INTERFACE_1);
audio3 = snd_soc_read(codec, WM8400_AUDIO_INTERFACE_3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
audio3 &= ~WM8400_AIF_MSTR1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
audio3 |= WM8400_AIF_MSTR1;
break;
default:
return -EINVAL;
}
audio1 &= ~WM8400_AIF_FMT_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
audio1 |= WM8400_AIF_FMT_I2S;
audio1 &= ~WM8400_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_RIGHT_J:
audio1 |= WM8400_AIF_FMT_RIGHTJ;
audio1 &= ~WM8400_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_LEFT_J:
audio1 |= WM8400_AIF_FMT_LEFTJ;
audio1 &= ~WM8400_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_A:
audio1 |= WM8400_AIF_FMT_DSP;
audio1 &= ~WM8400_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_B:
audio1 |= WM8400_AIF_FMT_DSP | WM8400_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8400_AUDIO_INTERFACE_1, audio1);
snd_soc_write(codec, WM8400_AUDIO_INTERFACE_3, audio3);
return 0;
}
static int wm8400_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8400_MCLK_DIV:
reg = snd_soc_read(codec, WM8400_CLOCKING_2) &
~WM8400_MCLK_DIV_MASK;
snd_soc_write(codec, WM8400_CLOCKING_2, reg | div);
break;
case WM8400_DACCLK_DIV:
reg = snd_soc_read(codec, WM8400_CLOCKING_2) &
~WM8400_DAC_CLKDIV_MASK;
snd_soc_write(codec, WM8400_CLOCKING_2, reg | div);
break;
case WM8400_ADCCLK_DIV:
reg = snd_soc_read(codec, WM8400_CLOCKING_2) &
~WM8400_ADC_CLKDIV_MASK;
snd_soc_write(codec, WM8400_CLOCKING_2, reg | div);
break;
case WM8400_BCLK_DIV:
reg = snd_soc_read(codec, WM8400_CLOCKING_1) &
~WM8400_BCLK_DIV_MASK;
snd_soc_write(codec, WM8400_CLOCKING_1, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8400_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 audio1 = snd_soc_read(codec, WM8400_AUDIO_INTERFACE_1);
audio1 &= ~WM8400_AIF_WL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
audio1 |= WM8400_AIF_WL_20BITS;
break;
case SNDRV_PCM_FORMAT_S24_LE:
audio1 |= WM8400_AIF_WL_24BITS;
break;
case SNDRV_PCM_FORMAT_S32_LE:
audio1 |= WM8400_AIF_WL_32BITS;
break;
}
snd_soc_write(codec, WM8400_AUDIO_INTERFACE_1, audio1);
return 0;
}
static int wm8400_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 val = snd_soc_read(codec, WM8400_DAC_CTRL) & ~WM8400_DAC_MUTE;
if (mute)
snd_soc_write(codec, WM8400_DAC_CTRL, val | WM8400_DAC_MUTE);
else
snd_soc_write(codec, WM8400_DAC_CTRL, val);
return 0;
}
static int wm8400_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8400_priv *wm8400 = snd_soc_codec_get_drvdata(codec);
u16 val;
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
val = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1) &
~WM8400_VMID_MODE_MASK;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val | 0x2);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(power),
&power[0]);
if (ret != 0) {
dev_err(wm8400->wm8400->dev,
"Failed to enable regulators: %d\n",
ret);
return ret;
}
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1,
WM8400_CODEC_ENA | WM8400_SYSCLK_ENA);
snd_soc_write(codec, WM8400_ANTIPOP2, WM8400_SOFTST |
WM8400_BUFDCOPEN | WM8400_POBCTRL);
msleep(50);
val = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1);
val |= 0x2 | WM8400_VREF_ENA;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val);
snd_soc_write(codec, WM8400_ANTIPOP2, WM8400_SOFTST |
WM8400_BUFDCOPEN | WM8400_POBCTRL |
WM8400_BUFIOEN);
snd_soc_write(codec, WM8400_ANTIPOP2, WM8400_BUFIOEN);
}
val = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1) &
~WM8400_VMID_MODE_MASK;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val | 0x4);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8400_ANTIPOP2, WM8400_SOFTST |
WM8400_POBCTRL | WM8400_BUFIOEN);
snd_soc_write(codec, WM8400_ANTIPOP2, WM8400_SOFTST |
WM8400_BUFDCOPEN | WM8400_POBCTRL |
WM8400_BUFIOEN);
val = snd_soc_read(codec, WM8400_DAC_CTRL);
snd_soc_write(codec, WM8400_DAC_CTRL, val | WM8400_DAC_MUTE);
val = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1);
val |= WM8400_SPK_ENA | WM8400_OUT3_ENA |
WM8400_OUT4_ENA | WM8400_LOUT_ENA |
WM8400_ROUT_ENA;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val);
val &= ~WM8400_VMID_MODE_MASK;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val);
msleep(300);
snd_soc_write(codec, WM8400_ANTIPOP1, WM8400_DIS_LLINE |
WM8400_DIS_RLINE | WM8400_DIS_OUT3 |
WM8400_DIS_OUT4 | WM8400_DIS_LOUT |
WM8400_DIS_ROUT);
val &= ~WM8400_VREF_ENA;
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, val);
snd_soc_write(codec, WM8400_ANTIPOP2, 0x0);
ret = regulator_bulk_disable(ARRAY_SIZE(power),
&power[0]);
if (ret != 0)
return ret;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8400_suspend(struct snd_soc_codec *codec)
{
wm8400_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8400_resume(struct snd_soc_codec *codec)
{
wm8400_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static void wm8400_probe_deferred(struct work_struct *work)
{
struct wm8400_priv *priv = container_of(work, struct wm8400_priv,
work);
struct snd_soc_codec *codec = priv->codec;
wm8400_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
}
static int wm8400_codec_probe(struct snd_soc_codec *codec)
{
struct wm8400 *wm8400 = dev_get_platdata(codec->dev);
struct wm8400_priv *priv;
int ret;
u16 reg;
priv = devm_kzalloc(codec->dev, sizeof(struct wm8400_priv),
GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, priv);
codec->control_data = priv->wm8400 = wm8400;
priv->codec = codec;
ret = devm_regulator_bulk_get(wm8400->dev,
ARRAY_SIZE(power), &power[0]);
if (ret != 0) {
dev_err(codec->dev, "Failed to get regulators: %d\n", ret);
return ret;
}
INIT_WORK(&priv->work, wm8400_probe_deferred);
wm8400_codec_reset(codec);
reg = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1);
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1, reg | WM8400_CODEC_ENA);
reg = snd_soc_read(codec, WM8400_LEFT_LINE_INPUT_1_2_VOLUME);
snd_soc_write(codec, WM8400_LEFT_LINE_INPUT_1_2_VOLUME,
reg & WM8400_IPVU);
reg = snd_soc_read(codec, WM8400_RIGHT_LINE_INPUT_1_2_VOLUME);
snd_soc_write(codec, WM8400_RIGHT_LINE_INPUT_1_2_VOLUME,
reg & WM8400_IPVU);
snd_soc_write(codec, WM8400_LEFT_OUTPUT_VOLUME, 0x50 | (1<<8));
snd_soc_write(codec, WM8400_RIGHT_OUTPUT_VOLUME, 0x50 | (1<<8));
if (!schedule_work(&priv->work))
return -EINVAL;
return 0;
}
static int wm8400_codec_remove(struct snd_soc_codec *codec)
{
u16 reg;
reg = snd_soc_read(codec, WM8400_POWER_MANAGEMENT_1);
snd_soc_write(codec, WM8400_POWER_MANAGEMENT_1,
reg & (~WM8400_CODEC_ENA));
return 0;
}
static int wm8400_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm8400,
&wm8400_dai, 1);
}
static int wm8400_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
