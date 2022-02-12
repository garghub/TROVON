static int wm899x_outpga_put_volsw_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int ret;
u16 val;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret < 0)
return ret;
val = snd_soc_read(codec, reg);
return snd_soc_write(codec, reg, val | 0x0100);
}
static int inmixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
u16 reg, fakepower;
reg = snd_soc_read(w->codec, WM8991_POWER_MANAGEMENT_2);
fakepower = snd_soc_read(w->codec, WM8991_INTDRIVBITS);
if (fakepower & ((1 << WM8991_INMIXL_PWR_BIT) |
(1 << WM8991_AINLMUX_PWR_BIT)))
reg |= WM8991_AINL_ENA;
else
reg &= ~WM8991_AINL_ENA;
if (fakepower & ((1 << WM8991_INMIXR_PWR_BIT) |
(1 << WM8991_AINRMUX_PWR_BIT)))
reg |= WM8991_AINR_ENA;
else
reg &= ~WM8991_AINR_ENA;
snd_soc_write(w->codec, WM8991_POWER_MANAGEMENT_2, reg);
return 0;
}
static int outmixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
u32 reg_shift = kcontrol->private_value & 0xfff;
int ret = 0;
u16 reg;
switch (reg_shift) {
case WM8991_SPEAKER_MIXER | (WM8991_LDSPK_BIT << 8):
reg = snd_soc_read(w->codec, WM8991_OUTPUT_MIXER1);
if (reg & WM8991_LDLO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 1 LDLO Set\n");
ret = -1;
}
break;
case WM8991_SPEAKER_MIXER | (WM8991_RDSPK_BIT << 8):
reg = snd_soc_read(w->codec, WM8991_OUTPUT_MIXER2);
if (reg & WM8991_RDRO) {
printk(KERN_WARNING
"Cannot set as Output Mixer 2 RDRO Set\n");
ret = -1;
}
break;
case WM8991_OUTPUT_MIXER1 | (WM8991_LDLO_BIT << 8):
reg = snd_soc_read(w->codec, WM8991_SPEAKER_MIXER);
if (reg & WM8991_LDSPK) {
printk(KERN_WARNING
"Cannot set as Speaker Mixer LDSPK Set\n");
ret = -1;
}
break;
case WM8991_OUTPUT_MIXER2 | (WM8991_RDRO_BIT << 8):
reg = snd_soc_read(w->codec, WM8991_SPEAKER_MIXER);
if (reg & WM8991_RDSPK) {
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
"WM8991 N value outwith recommended range! N = %d\n", Ndiv);
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
static int wm8991_set_dai_pll(struct snd_soc_dai *codec_dai,
int pll_id, int src, unsigned int freq_in, unsigned int freq_out)
{
u16 reg;
struct snd_soc_codec *codec = codec_dai->codec;
struct _pll_div pll_div;
if (freq_in && freq_out) {
pll_factors(&pll_div, freq_out * 4, freq_in);
reg = snd_soc_read(codec, WM8991_POWER_MANAGEMENT_2);
reg |= WM8991_PLL_ENA;
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_2, reg);
reg = snd_soc_read(codec, WM8991_CLOCKING_2);
snd_soc_write(codec, WM8991_CLOCKING_2, reg | WM8991_SYSCLK_SRC);
snd_soc_write(codec, WM8991_PLL1, pll_div.n | WM8991_SDM |
(pll_div.div2 ? WM8991_PRESCALE : 0));
snd_soc_write(codec, WM8991_PLL2, (u8)(pll_div.k>>8));
snd_soc_write(codec, WM8991_PLL3, (u8)(pll_div.k & 0xFF));
} else {
reg = snd_soc_read(codec, WM8991_POWER_MANAGEMENT_2);
reg &= ~WM8991_PLL_ENA;
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_2, reg);
}
return 0;
}
static int wm8991_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 audio1, audio3;
audio1 = snd_soc_read(codec, WM8991_AUDIO_INTERFACE_1);
audio3 = snd_soc_read(codec, WM8991_AUDIO_INTERFACE_3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
audio3 &= ~WM8991_AIF_MSTR1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
audio3 |= WM8991_AIF_MSTR1;
break;
default:
return -EINVAL;
}
audio1 &= ~WM8991_AIF_FMT_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
audio1 |= WM8991_AIF_TMF_I2S;
audio1 &= ~WM8991_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_RIGHT_J:
audio1 |= WM8991_AIF_TMF_RIGHTJ;
audio1 &= ~WM8991_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_LEFT_J:
audio1 |= WM8991_AIF_TMF_LEFTJ;
audio1 &= ~WM8991_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_A:
audio1 |= WM8991_AIF_TMF_DSP;
audio1 &= ~WM8991_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_B:
audio1 |= WM8991_AIF_TMF_DSP | WM8991_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8991_AUDIO_INTERFACE_1, audio1);
snd_soc_write(codec, WM8991_AUDIO_INTERFACE_3, audio3);
return 0;
}
static int wm8991_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8991_MCLK_DIV:
reg = snd_soc_read(codec, WM8991_CLOCKING_2) &
~WM8991_MCLK_DIV_MASK;
snd_soc_write(codec, WM8991_CLOCKING_2, reg | div);
break;
case WM8991_DACCLK_DIV:
reg = snd_soc_read(codec, WM8991_CLOCKING_2) &
~WM8991_DAC_CLKDIV_MASK;
snd_soc_write(codec, WM8991_CLOCKING_2, reg | div);
break;
case WM8991_ADCCLK_DIV:
reg = snd_soc_read(codec, WM8991_CLOCKING_2) &
~WM8991_ADC_CLKDIV_MASK;
snd_soc_write(codec, WM8991_CLOCKING_2, reg | div);
break;
case WM8991_BCLK_DIV:
reg = snd_soc_read(codec, WM8991_CLOCKING_1) &
~WM8991_BCLK_DIV_MASK;
snd_soc_write(codec, WM8991_CLOCKING_1, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8991_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 audio1 = snd_soc_read(codec, WM8991_AUDIO_INTERFACE_1);
audio1 &= ~WM8991_AIF_WL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
audio1 |= WM8991_AIF_WL_20BITS;
break;
case SNDRV_PCM_FORMAT_S24_LE:
audio1 |= WM8991_AIF_WL_24BITS;
break;
case SNDRV_PCM_FORMAT_S32_LE:
audio1 |= WM8991_AIF_WL_32BITS;
break;
}
snd_soc_write(codec, WM8991_AUDIO_INTERFACE_1, audio1);
return 0;
}
static int wm8991_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 val;
val = snd_soc_read(codec, WM8991_DAC_CTRL) & ~WM8991_DAC_MUTE;
if (mute)
snd_soc_write(codec, WM8991_DAC_CTRL, val | WM8991_DAC_MUTE);
else
snd_soc_write(codec, WM8991_DAC_CTRL, val);
return 0;
}
static int wm8991_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 val;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
val = snd_soc_read(codec, WM8991_POWER_MANAGEMENT_1) &
~WM8991_VMID_MODE_MASK;
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, val | 0x2);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_cache_sync(codec);
snd_soc_write(codec, WM8991_ANTIPOP1, WM8991_DIS_LLINE |
WM8991_DIS_RLINE | WM8991_DIS_OUT3 |
WM8991_DIS_OUT4 | WM8991_DIS_LOUT |
WM8991_DIS_ROUT);
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_SOFTST |
WM8991_BUFDCOPEN | WM8991_POBCTRL |
WM8991_VMIDTOG);
msleep(300);
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_SOFTST |
WM8991_BUFDCOPEN | WM8991_POBCTRL);
snd_soc_write(codec, WM8991_ANTIPOP1, 0);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x1b00);
msleep(50);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x1f02);
msleep(100);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x1f03);
msleep(600);
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_SOFTST |
WM8991_BUFDCOPEN | WM8991_POBCTRL |
WM8991_BUFIOEN);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x3);
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_BUFIOEN);
}
val = snd_soc_read(codec, WM8991_POWER_MANAGEMENT_1) &
~WM8991_VMID_MODE_MASK;
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, val | 0x4);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_SOFTST |
WM8991_POBCTRL | WM8991_BUFIOEN);
snd_soc_write(codec, WM8991_ANTIPOP2, WM8991_SOFTST |
WM8991_BUFDCOPEN | WM8991_POBCTRL |
WM8991_BUFIOEN);
val = snd_soc_read(codec, WM8991_DAC_CTRL);
snd_soc_write(codec, WM8991_DAC_CTRL, val | WM8991_DAC_MUTE);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x1f03);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x1f01);
msleep(300);
snd_soc_write(codec, WM8991_ANTIPOP1, WM8991_DIS_LLINE |
WM8991_DIS_RLINE | WM8991_DIS_OUT3 |
WM8991_DIS_OUT4 | WM8991_DIS_LOUT |
WM8991_DIS_ROUT);
snd_soc_write(codec, WM8991_POWER_MANAGEMENT_1, 0x0);
snd_soc_write(codec, WM8991_ANTIPOP2, 0x0);
codec->cache_sync = 1;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8991_suspend(struct snd_soc_codec *codec)
{
wm8991_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8991_resume(struct snd_soc_codec *codec)
{
wm8991_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8991_remove(struct snd_soc_codec *codec)
{
wm8991_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8991_probe(struct snd_soc_codec *codec)
{
struct wm8991_priv *wm8991;
int ret;
wm8991 = snd_soc_codec_get_drvdata(codec);
ret = snd_soc_codec_set_cache_io(codec, 8, 16, wm8991->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache i/o: %d\n", ret);
return ret;
}
ret = wm8991_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
wm8991_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8991_AUDIO_INTERFACE_4,
WM8991_ALRCGPIO1, WM8991_ALRCGPIO1);
snd_soc_update_bits(codec, WM8991_GPIO1_GPIO2,
WM8991_GPIO1_SEL_MASK, 1);
snd_soc_update_bits(codec, WM8991_POWER_MANAGEMENT_1,
WM8991_VREF_ENA | WM8991_VMID_MODE_MASK,
WM8991_VREF_ENA | WM8991_VMID_MODE_MASK);
snd_soc_update_bits(codec, WM8991_POWER_MANAGEMENT_2,
WM8991_OPCLK_ENA, WM8991_OPCLK_ENA);
snd_soc_write(codec, WM8991_DAC_CTRL, 0);
snd_soc_write(codec, WM8991_LEFT_OUTPUT_VOLUME, 0x50 | (1<<8));
snd_soc_write(codec, WM8991_RIGHT_OUTPUT_VOLUME, 0x50 | (1<<8));
snd_soc_add_codec_controls(codec, wm8991_snd_controls,
ARRAY_SIZE(wm8991_snd_controls));
snd_soc_dapm_new_controls(&codec->dapm, wm8991_dapm_widgets,
ARRAY_SIZE(wm8991_dapm_widgets));
snd_soc_dapm_add_routes(&codec->dapm, audio_map,
ARRAY_SIZE(audio_map));
return 0;
}
static __devinit int wm8991_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8991_priv *wm8991;
int ret;
wm8991 = devm_kzalloc(&i2c->dev, sizeof(*wm8991), GFP_KERNEL);
if (!wm8991)
return -ENOMEM;
wm8991->control_type = SND_SOC_I2C;
i2c_set_clientdata(i2c, wm8991);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8991, &wm8991_dai, 1);
return ret;
}
static __devexit int wm8991_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
