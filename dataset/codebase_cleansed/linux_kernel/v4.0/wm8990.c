static bool wm8990_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8990_RESET:
return 1;
default:
return 0;
}
}
static int wm899x_outpga_put_volsw_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
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
static int outmixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
u32 reg_shift = kcontrol->private_value & 0xfff;
int ret = 0;
u16 reg;
switch (reg_shift) {
case WM8990_SPEAKER_MIXER | (WM8990_LDSPK_BIT << 8) :
reg = snd_soc_read(codec, WM8990_OUTPUT_MIXER1);
if (reg & WM8990_LDLO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 1 LDLO Set\n");
ret = -1;
}
break;
case WM8990_SPEAKER_MIXER | (WM8990_RDSPK_BIT << 8):
reg = snd_soc_read(codec, WM8990_OUTPUT_MIXER2);
if (reg & WM8990_RDRO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 2 RDRO Set\n");
ret = -1;
}
break;
case WM8990_OUTPUT_MIXER1 | (WM8990_LDLO_BIT << 8):
reg = snd_soc_read(codec, WM8990_SPEAKER_MIXER);
if (reg & WM8990_LDSPK) {
printk(KERN_WARNING
"Cannot set as Speaker Mixer LDSPK Set\n");
ret = -1;
}
break;
case WM8990_OUTPUT_MIXER2 | (WM8990_RDRO_BIT << 8):
reg = snd_soc_read(codec, WM8990_SPEAKER_MIXER);
if (reg & WM8990_RDSPK) {
printk(KERN_WARNING
"Cannot set as Speaker Mixer RDSPK Set\n");
ret = -1;
}
break;
}
return ret;
}
static void pll_factors(struct _pll_div *pll_div, unsigned int target,
unsigned int source)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
pll_div->div2 = 1;
Ndiv = target / source;
} else
pll_div->div2 = 0;
if ((Ndiv < 6) || (Ndiv > 12))
printk(KERN_WARNING
"WM8990 N value outwith recommended range! N = %u\n", Ndiv);
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div->k = K;
}
static int wm8990_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct _pll_div pll_div;
if (freq_in && freq_out) {
pll_factors(&pll_div, freq_out * 4, freq_in);
snd_soc_update_bits(codec, WM8990_POWER_MANAGEMENT_2,
WM8990_PLL_ENA, WM8990_PLL_ENA);
snd_soc_update_bits(codec, WM8990_CLOCKING_2,
WM8990_SYSCLK_SRC, WM8990_SYSCLK_SRC);
snd_soc_write(codec, WM8990_PLL1, pll_div.n | WM8990_SDM |
(pll_div.div2?WM8990_PRESCALE:0));
snd_soc_write(codec, WM8990_PLL2, (u8)(pll_div.k>>8));
snd_soc_write(codec, WM8990_PLL3, (u8)(pll_div.k & 0xFF));
} else {
snd_soc_update_bits(codec, WM8990_POWER_MANAGEMENT_2,
WM8990_PLL_ENA, 0);
}
return 0;
}
static int wm8990_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8990_priv *wm8990 = snd_soc_codec_get_drvdata(codec);
wm8990->sysclk = freq;
return 0;
}
static int wm8990_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 audio1, audio3;
audio1 = snd_soc_read(codec, WM8990_AUDIO_INTERFACE_1);
audio3 = snd_soc_read(codec, WM8990_AUDIO_INTERFACE_3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
audio3 &= ~WM8990_AIF_MSTR1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
audio3 |= WM8990_AIF_MSTR1;
break;
default:
return -EINVAL;
}
audio1 &= ~WM8990_AIF_FMT_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
audio1 |= WM8990_AIF_TMF_I2S;
audio1 &= ~WM8990_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_RIGHT_J:
audio1 |= WM8990_AIF_TMF_RIGHTJ;
audio1 &= ~WM8990_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_LEFT_J:
audio1 |= WM8990_AIF_TMF_LEFTJ;
audio1 &= ~WM8990_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_A:
audio1 |= WM8990_AIF_TMF_DSP;
audio1 &= ~WM8990_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_B:
audio1 |= WM8990_AIF_TMF_DSP | WM8990_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8990_AUDIO_INTERFACE_1, audio1);
snd_soc_write(codec, WM8990_AUDIO_INTERFACE_3, audio3);
return 0;
}
static int wm8990_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
switch (div_id) {
case WM8990_MCLK_DIV:
snd_soc_update_bits(codec, WM8990_CLOCKING_2,
WM8990_MCLK_DIV_MASK, div);
break;
case WM8990_DACCLK_DIV:
snd_soc_update_bits(codec, WM8990_CLOCKING_2,
WM8990_DAC_CLKDIV_MASK, div);
break;
case WM8990_ADCCLK_DIV:
snd_soc_update_bits(codec, WM8990_CLOCKING_2,
WM8990_ADC_CLKDIV_MASK, div);
break;
case WM8990_BCLK_DIV:
snd_soc_update_bits(codec, WM8990_CLOCKING_1,
WM8990_BCLK_DIV_MASK, div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8990_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 audio1 = snd_soc_read(codec, WM8990_AUDIO_INTERFACE_1);
audio1 &= ~WM8990_AIF_WL_MASK;
switch (params_width(params)) {
case 16:
break;
case 20:
audio1 |= WM8990_AIF_WL_20BITS;
break;
case 24:
audio1 |= WM8990_AIF_WL_24BITS;
break;
case 32:
audio1 |= WM8990_AIF_WL_32BITS;
break;
}
snd_soc_write(codec, WM8990_AUDIO_INTERFACE_1, audio1);
return 0;
}
static int wm8990_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 val;
val = snd_soc_read(codec, WM8990_DAC_CTRL) & ~WM8990_DAC_MUTE;
if (mute)
snd_soc_write(codec, WM8990_DAC_CTRL, val | WM8990_DAC_MUTE);
else
snd_soc_write(codec, WM8990_DAC_CTRL, val);
return 0;
}
static int wm8990_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8990_priv *wm8990 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8990_POWER_MANAGEMENT_1,
WM8990_VMID_MODE_MASK, 0x2);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regcache_sync(wm8990->regmap);
if (ret < 0) {
dev_err(codec->dev, "Failed to sync cache: %d\n", ret);
return ret;
}
snd_soc_write(codec, WM8990_ANTIPOP1, WM8990_DIS_LLINE |
WM8990_DIS_RLINE | WM8990_DIS_OUT3 |
WM8990_DIS_OUT4 | WM8990_DIS_LOUT |
WM8990_DIS_ROUT);
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_SOFTST |
WM8990_BUFDCOPEN | WM8990_POBCTRL |
WM8990_VMIDTOG);
msleep(300);
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_SOFTST |
WM8990_BUFDCOPEN | WM8990_POBCTRL);
snd_soc_write(codec, WM8990_ANTIPOP1, 0);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x1b00);
msleep(50);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x1f02);
msleep(100);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x1f03);
msleep(600);
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_SOFTST |
WM8990_BUFDCOPEN | WM8990_POBCTRL |
WM8990_BUFIOEN);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x3);
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_BUFIOEN);
snd_soc_write(codec, WM8990_EXT_ACCESS_ENA, 0x2);
snd_soc_write(codec, WM8990_EXT_CTL1, 0xa003);
snd_soc_write(codec, WM8990_EXT_ACCESS_ENA, 0);
}
snd_soc_update_bits(codec, WM8990_POWER_MANAGEMENT_1,
WM8990_VMID_MODE_MASK, 0x4);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_SOFTST |
WM8990_POBCTRL | WM8990_BUFIOEN);
snd_soc_write(codec, WM8990_ANTIPOP2, WM8990_SOFTST |
WM8990_BUFDCOPEN | WM8990_POBCTRL |
WM8990_BUFIOEN);
snd_soc_update_bits(codec, WM8990_DAC_CTRL,
WM8990_DAC_MUTE, WM8990_DAC_MUTE);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x1f03);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x1f01);
msleep(300);
snd_soc_write(codec, WM8990_ANTIPOP1, WM8990_DIS_LLINE |
WM8990_DIS_RLINE | WM8990_DIS_OUT3 |
WM8990_DIS_OUT4 | WM8990_DIS_LOUT |
WM8990_DIS_ROUT);
snd_soc_write(codec, WM8990_POWER_MANAGEMENT_1, 0x0);
snd_soc_write(codec, WM8990_ANTIPOP2, 0x0);
regcache_mark_dirty(wm8990->regmap);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8990_probe(struct snd_soc_codec *codec)
{
wm8990_reset(codec);
wm8990_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8990_AUDIO_INTERFACE_4,
WM8990_ALRCGPIO1, WM8990_ALRCGPIO1);
snd_soc_update_bits(codec, WM8990_GPIO1_GPIO2,
WM8990_GPIO1_SEL_MASK, 1);
snd_soc_update_bits(codec, WM8990_POWER_MANAGEMENT_2,
WM8990_OPCLK_ENA, WM8990_OPCLK_ENA);
snd_soc_write(codec, WM8990_LEFT_OUTPUT_VOLUME, 0x50 | (1<<8));
snd_soc_write(codec, WM8990_RIGHT_OUTPUT_VOLUME, 0x50 | (1<<8));
return 0;
}
static int wm8990_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8990_priv *wm8990;
int ret;
wm8990 = devm_kzalloc(&i2c->dev, sizeof(struct wm8990_priv),
GFP_KERNEL);
if (wm8990 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8990);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8990, &wm8990_dai, 1);
return ret;
}
static int wm8990_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
