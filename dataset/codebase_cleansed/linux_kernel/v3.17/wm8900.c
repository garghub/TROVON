static bool wm8900_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8900_REG_ID:
return true;
default:
return false;
}
}
static void wm8900_reset(struct snd_soc_codec *codec)
{
snd_soc_write(codec, WM8900_REG_RESET, 0);
}
static int wm8900_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
u16 hpctl1 = snd_soc_read(codec, WM8900_REG_HPCTL1);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
hpctl1 = WM8900_REG_HPCTL1_HP_CLAMP_IP |
WM8900_REG_HPCTL1_HP_CLAMP_OP;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
break;
case SND_SOC_DAPM_POST_PMU:
hpctl1 &= ~WM8900_REG_HPCTL1_HP_CLAMP_IP;
hpctl1 |= WM8900_REG_HPCTL1_HP_SHORT |
WM8900_REG_HPCTL1_HP_SHORT2 |
WM8900_REG_HPCTL1_HP_IPSTAGE_ENA;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
msleep(400);
hpctl1 &= ~WM8900_REG_HPCTL1_HP_CLAMP_OP;
hpctl1 |= WM8900_REG_HPCTL1_HP_OPSTAGE_ENA;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
hpctl1 &= ~WM8900_REG_HPCTL1_HP_SHORT2;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
hpctl1 &= ~WM8900_REG_HPCTL1_HP_SHORT;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
break;
case SND_SOC_DAPM_PRE_PMD:
hpctl1 |= WM8900_REG_HPCTL1_HP_SHORT;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
hpctl1 &= ~WM8900_REG_HPCTL1_HP_OPSTAGE_ENA;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
hpctl1 |= WM8900_REG_HPCTL1_HP_CLAMP_IP |
WM8900_REG_HPCTL1_HP_CLAMP_OP;
hpctl1 &= ~WM8900_REG_HPCTL1_HP_IPSTAGE_ENA;
snd_soc_write(codec, WM8900_REG_HPCTL1, hpctl1);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, WM8900_REG_HPCTL1, 0);
break;
default:
WARN(1, "Invalid event %d\n", event);
break;
}
return 0;
}
static int wm8900_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 reg;
reg = snd_soc_read(codec, WM8900_REG_AUDIO1) & ~0x60;
switch (params_width(params)) {
case 16:
break;
case 20:
reg |= 0x20;
break;
case 24:
reg |= 0x40;
break;
case 32:
reg |= 0x60;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8900_REG_AUDIO1, reg);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
reg = snd_soc_read(codec, WM8900_REG_DACCTRL);
if (params_rate(params) <= 24000)
reg |= WM8900_REG_DACCTRL_DAC_SB_FILT;
else
reg &= ~WM8900_REG_DACCTRL_DAC_SB_FILT;
snd_soc_write(codec, WM8900_REG_DACCTRL, reg);
}
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, target;
unsigned int div;
if (WARN_ON(!Fout))
return -EINVAL;
target = Fout;
div = 1;
while (target < 90000000) {
div *= 2;
target *= 2;
}
if (target > 100000000)
printk(KERN_WARNING "wm8900: FLL rate %u out of range, Fref=%u"
" Fout=%u\n", target, Fref, Fout);
if (div > 32) {
printk(KERN_ERR "wm8900: Invalid FLL division rate %u, "
"Fref=%u, Fout=%u, target=%u\n",
div, Fref, Fout, target);
return -EINVAL;
}
fll_div->fllclk_div = div >> 2;
if (Fref < 48000)
fll_div->fll_slow_lock_ref = 1;
else
fll_div->fll_slow_lock_ref = 0;
Ndiv = target / Fref;
if (Fref < 1000000)
fll_div->fll_ratio = 8;
else
fll_div->fll_ratio = 1;
fll_div->n = Ndiv / fll_div->fll_ratio;
Nmod = (target / fll_div->fll_ratio) % Fref;
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, Fref);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
fll_div->k = K / 10;
if (WARN_ON(target != Fout * (fll_div->fllclk_div << 2)) ||
WARN_ON(!K && target != Fref * fll_div->fll_ratio * fll_div->n))
return -EINVAL;
return 0;
}
static int wm8900_set_fll(struct snd_soc_codec *codec,
int fll_id, unsigned int freq_in, unsigned int freq_out)
{
struct wm8900_priv *wm8900 = snd_soc_codec_get_drvdata(codec);
struct _fll_div fll_div;
if (wm8900->fll_in == freq_in && wm8900->fll_out == freq_out)
return 0;
snd_soc_update_bits(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_FLL_ENA, 0);
if (!freq_in || !freq_out) {
snd_soc_update_bits(codec, WM8900_REG_CLOCKING1,
WM8900_REG_CLOCKING1_MCLK_SRC, 0);
snd_soc_update_bits(codec, WM8900_REG_FLLCTL1,
WM8900_REG_FLLCTL1_OSC_ENA, 0);
wm8900->fll_in = freq_in;
wm8900->fll_out = freq_out;
return 0;
}
if (fll_factors(&fll_div, freq_in, freq_out) != 0)
goto reenable;
wm8900->fll_in = freq_in;
wm8900->fll_out = freq_out;
snd_soc_write(codec, WM8900_REG_FLLCTL1,
fll_div.fll_ratio | WM8900_REG_FLLCTL1_OSC_ENA);
snd_soc_write(codec, WM8900_REG_FLLCTL4, fll_div.n >> 5);
snd_soc_write(codec, WM8900_REG_FLLCTL5,
(fll_div.fllclk_div << 6) | (fll_div.n & 0x1f));
if (fll_div.k) {
snd_soc_write(codec, WM8900_REG_FLLCTL2,
(fll_div.k >> 8) | 0x100);
snd_soc_write(codec, WM8900_REG_FLLCTL3, fll_div.k & 0xff);
} else
snd_soc_write(codec, WM8900_REG_FLLCTL2, 0);
if (fll_div.fll_slow_lock_ref)
snd_soc_write(codec, WM8900_REG_FLLCTL6,
WM8900_REG_FLLCTL6_FLL_SLOW_LOCK_REF);
else
snd_soc_write(codec, WM8900_REG_FLLCTL6, 0);
snd_soc_update_bits(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_FLL_ENA,
WM8900_REG_POWER1_FLL_ENA);
reenable:
snd_soc_update_bits(codec, WM8900_REG_CLOCKING1,
WM8900_REG_CLOCKING1_MCLK_SRC,
WM8900_REG_CLOCKING1_MCLK_SRC);
return 0;
}
static int wm8900_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
return wm8900_set_fll(codec_dai->codec, pll_id, freq_in, freq_out);
}
static int wm8900_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
switch (div_id) {
case WM8900_BCLK_DIV:
snd_soc_update_bits(codec, WM8900_REG_CLOCKING1,
WM8900_REG_CLOCKING1_BCLK_MASK, div);
break;
case WM8900_OPCLK_DIV:
snd_soc_update_bits(codec, WM8900_REG_CLOCKING1,
WM8900_REG_CLOCKING1_OPCLK_MASK, div);
break;
case WM8900_DAC_LRCLK:
snd_soc_update_bits(codec, WM8900_REG_AUDIO4,
WM8900_LRC_MASK, div);
break;
case WM8900_ADC_LRCLK:
snd_soc_update_bits(codec, WM8900_REG_AUDIO3,
WM8900_LRC_MASK, div);
break;
case WM8900_DAC_CLKDIV:
snd_soc_update_bits(codec, WM8900_REG_CLOCKING2,
WM8900_REG_CLOCKING2_DAC_CLKDIV, div);
break;
case WM8900_ADC_CLKDIV:
snd_soc_update_bits(codec, WM8900_REG_CLOCKING2,
WM8900_REG_CLOCKING2_ADC_CLKDIV, div);
break;
case WM8900_LRCLK_MODE:
snd_soc_update_bits(codec, WM8900_REG_DACCTRL,
WM8900_REG_DACCTRL_AIF_LRCLKRATE, div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8900_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int clocking1, aif1, aif3, aif4;
clocking1 = snd_soc_read(codec, WM8900_REG_CLOCKING1);
aif1 = snd_soc_read(codec, WM8900_REG_AUDIO1);
aif3 = snd_soc_read(codec, WM8900_REG_AUDIO3);
aif4 = snd_soc_read(codec, WM8900_REG_AUDIO4);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
clocking1 &= ~WM8900_REG_CLOCKING1_BCLK_DIR;
aif3 &= ~WM8900_REG_AUDIO3_ADCLRC_DIR;
aif4 &= ~WM8900_REG_AUDIO4_DACLRC_DIR;
break;
case SND_SOC_DAIFMT_CBS_CFM:
clocking1 &= ~WM8900_REG_CLOCKING1_BCLK_DIR;
aif3 |= WM8900_REG_AUDIO3_ADCLRC_DIR;
aif4 |= WM8900_REG_AUDIO4_DACLRC_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
clocking1 |= WM8900_REG_CLOCKING1_BCLK_DIR;
aif3 |= WM8900_REG_AUDIO3_ADCLRC_DIR;
aif4 |= WM8900_REG_AUDIO4_DACLRC_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
clocking1 |= WM8900_REG_CLOCKING1_BCLK_DIR;
aif3 &= ~WM8900_REG_AUDIO3_ADCLRC_DIR;
aif4 &= ~WM8900_REG_AUDIO4_DACLRC_DIR;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
aif1 |= WM8900_REG_AUDIO1_AIF_FMT_MASK;
aif1 &= ~WM8900_REG_AUDIO1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_DSP_B:
aif1 |= WM8900_REG_AUDIO1_AIF_FMT_MASK;
aif1 |= WM8900_REG_AUDIO1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_I2S:
aif1 &= ~WM8900_REG_AUDIO1_AIF_FMT_MASK;
aif1 |= 0x10;
break;
case SND_SOC_DAIFMT_RIGHT_J:
aif1 &= ~WM8900_REG_AUDIO1_AIF_FMT_MASK;
break;
case SND_SOC_DAIFMT_LEFT_J:
aif1 &= ~WM8900_REG_AUDIO1_AIF_FMT_MASK;
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
aif1 &= ~WM8900_REG_AUDIO1_BCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8900_REG_AUDIO1_BCLK_INV;
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
aif1 &= ~WM8900_REG_AUDIO1_BCLK_INV;
aif1 &= ~WM8900_REG_AUDIO1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
aif1 |= WM8900_REG_AUDIO1_BCLK_INV;
aif1 |= WM8900_REG_AUDIO1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8900_REG_AUDIO1_BCLK_INV;
aif1 &= ~WM8900_REG_AUDIO1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif1 &= ~WM8900_REG_AUDIO1_BCLK_INV;
aif1 |= WM8900_REG_AUDIO1_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8900_REG_CLOCKING1, clocking1);
snd_soc_write(codec, WM8900_REG_AUDIO1, aif1);
snd_soc_write(codec, WM8900_REG_AUDIO3, aif3);
snd_soc_write(codec, WM8900_REG_AUDIO4, aif4);
return 0;
}
static int wm8900_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
reg = snd_soc_read(codec, WM8900_REG_DACCTRL);
if (mute)
reg |= WM8900_REG_DACCTRL_MUTE;
else
reg &= ~WM8900_REG_DACCTRL_MUTE;
snd_soc_write(codec, WM8900_REG_DACCTRL, reg);
return 0;
}
static int wm8900_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 reg;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, WM8900_REG_GPIO,
WM8900_REG_GPIO_TEMP_ENA,
WM8900_REG_GPIO_TEMP_ENA);
snd_soc_update_bits(codec, WM8900_REG_ADDCTL,
WM8900_REG_ADDCTL_TEMP_SD,
WM8900_REG_ADDCTL_TEMP_SD);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_write(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_STARTUP_BIAS_ENA);
snd_soc_write(codec, WM8900_REG_ADDCTL,
WM8900_REG_ADDCTL_BIAS_SRC |
WM8900_REG_ADDCTL_VMID_SOFTST);
snd_soc_write(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_STARTUP_BIAS_ENA | 0x1);
schedule_timeout_interruptible(msecs_to_jiffies(400));
snd_soc_write(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_STARTUP_BIAS_ENA |
WM8900_REG_POWER1_BIAS_ENA | 0x1);
snd_soc_write(codec, WM8900_REG_ADDCTL, 0);
snd_soc_write(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_BIAS_ENA | 0x1);
}
reg = snd_soc_read(codec, WM8900_REG_POWER1);
snd_soc_write(codec, WM8900_REG_POWER1,
(reg & WM8900_REG_POWER1_FLL_ENA) |
WM8900_REG_POWER1_BIAS_ENA | 0x1);
snd_soc_write(codec, WM8900_REG_POWER2,
WM8900_REG_POWER2_SYSCLK_ENA);
snd_soc_write(codec, WM8900_REG_POWER3, 0);
break;
case SND_SOC_BIAS_OFF:
reg = snd_soc_read(codec, WM8900_REG_POWER1);
snd_soc_write(codec, WM8900_REG_POWER1,
reg & WM8900_REG_POWER1_STARTUP_BIAS_ENA);
snd_soc_write(codec, WM8900_REG_ADDCTL,
WM8900_REG_ADDCTL_BIAS_SRC |
WM8900_REG_ADDCTL_VMID_SOFTST);
snd_soc_write(codec, WM8900_REG_POWER1,
WM8900_REG_POWER1_STARTUP_BIAS_ENA);
schedule_timeout_interruptible(msecs_to_jiffies(500));
snd_soc_write(codec, WM8900_REG_HPCTL1, 0);
snd_soc_write(codec, WM8900_REG_ADDCTL, 0);
snd_soc_write(codec, WM8900_REG_POWER1, 0);
snd_soc_write(codec, WM8900_REG_POWER2, 0);
snd_soc_write(codec, WM8900_REG_POWER3, 0);
schedule_timeout_interruptible(msecs_to_jiffies(1));
snd_soc_write(codec, WM8900_REG_POWER2,
WM8900_REG_POWER2_SYSCLK_ENA);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8900_suspend(struct snd_soc_codec *codec)
{
struct wm8900_priv *wm8900 = snd_soc_codec_get_drvdata(codec);
int fll_out = wm8900->fll_out;
int fll_in = wm8900->fll_in;
int ret;
ret = wm8900_set_fll(codec, 0, 0, 0);
if (ret != 0) {
dev_err(codec->dev, "Failed to stop FLL\n");
return ret;
}
wm8900->fll_out = fll_out;
wm8900->fll_in = fll_in;
wm8900_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8900_resume(struct snd_soc_codec *codec)
{
struct wm8900_priv *wm8900 = snd_soc_codec_get_drvdata(codec);
int ret;
wm8900_reset(codec);
ret = regcache_sync(wm8900->regmap);
if (ret != 0) {
dev_err(codec->dev, "Failed to restore cache: %d\n", ret);
return ret;
}
wm8900_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (wm8900->fll_out) {
int fll_out = wm8900->fll_out;
int fll_in = wm8900->fll_in;
wm8900->fll_in = 0;
wm8900->fll_out = 0;
ret = wm8900_set_fll(codec, 0, fll_in, fll_out);
if (ret != 0) {
dev_err(codec->dev, "Failed to restart FLL\n");
return ret;
}
}
return 0;
}
static int wm8900_probe(struct snd_soc_codec *codec)
{
int reg;
reg = snd_soc_read(codec, WM8900_REG_ID);
if (reg != 0x8900) {
dev_err(codec->dev, "Device is not a WM8900 - ID %x\n", reg);
return -ENODEV;
}
wm8900_reset(codec);
wm8900_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_update_bits(codec, WM8900_REG_LINVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_RINVOL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_LOUT1CTL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_ROUT1CTL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_LOUT2CTL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_ROUT2CTL, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_LDAC_DV, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_RDAC_DV, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_LADC_DV, 0x100, 0x100);
snd_soc_update_bits(codec, WM8900_REG_RADC_DV, 0x100, 0x100);
snd_soc_write(codec, WM8900_REG_OUTBIASCTL, 0x81);
return 0;
}
static int wm8900_remove(struct snd_soc_codec *codec)
{
wm8900_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8900_spi_probe(struct spi_device *spi)
{
struct wm8900_priv *wm8900;
int ret;
wm8900 = devm_kzalloc(&spi->dev, sizeof(struct wm8900_priv),
GFP_KERNEL);
if (wm8900 == NULL)
return -ENOMEM;
wm8900->regmap = devm_regmap_init_spi(spi, &wm8900_regmap);
if (IS_ERR(wm8900->regmap))
return PTR_ERR(wm8900->regmap);
spi_set_drvdata(spi, wm8900);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8900, &wm8900_dai, 1);
return ret;
}
static int wm8900_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8900_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8900_priv *wm8900;
int ret;
wm8900 = devm_kzalloc(&i2c->dev, sizeof(struct wm8900_priv),
GFP_KERNEL);
if (wm8900 == NULL)
return -ENOMEM;
wm8900->regmap = devm_regmap_init_i2c(i2c, &wm8900_regmap);
if (IS_ERR(wm8900->regmap))
return PTR_ERR(wm8900->regmap);
i2c_set_clientdata(i2c, wm8900);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8900, &wm8900_dai, 1);
return ret;
}
static int wm8900_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8900_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8900_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8900 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8900_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8900 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8900_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8900_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8900_spi_driver);
#endif
}
