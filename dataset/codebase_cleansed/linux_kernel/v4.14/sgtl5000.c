static int mic_bias_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, SGTL5000_CHIP_MIC_CTRL,
SGTL5000_BIAS_R_MASK,
sgtl5000->micbias_resistor << SGTL5000_BIAS_R_SHIFT);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, SGTL5000_CHIP_MIC_CTRL,
SGTL5000_BIAS_R_MASK, 0);
break;
}
return 0;
}
static int power_vag_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
const u32 mask = SGTL5000_DAC_POWERUP | SGTL5000_ADC_POWERUP;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_VAG_POWERUP, SGTL5000_VAG_POWERUP);
msleep(400);
break;
case SND_SOC_DAPM_PRE_PMD:
if ((snd_soc_read(codec, SGTL5000_CHIP_ANA_POWER) &
mask) != mask) {
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_VAG_POWERUP, 0);
msleep(400);
}
break;
default:
break;
}
return 0;
}
static int dac_info_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xfc - 0x3c;
return 0;
}
static int dac_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int reg;
int l;
int r;
reg = snd_soc_read(codec, SGTL5000_CHIP_DAC_VOL);
l = (reg & SGTL5000_DAC_VOL_LEFT_MASK) >> SGTL5000_DAC_VOL_LEFT_SHIFT;
r = (reg & SGTL5000_DAC_VOL_RIGHT_MASK) >> SGTL5000_DAC_VOL_RIGHT_SHIFT;
l = clamp(l, 0x3c, 0xfc);
r = clamp(r, 0x3c, 0xfc);
l = 0xfc - l;
r = 0xfc - r;
ucontrol->value.integer.value[0] = l;
ucontrol->value.integer.value[1] = r;
return 0;
}
static int dac_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int reg;
int l;
int r;
l = ucontrol->value.integer.value[0];
r = ucontrol->value.integer.value[1];
l = clamp(l, 0, 0xfc - 0x3c);
r = clamp(r, 0, 0xfc - 0x3c);
l = 0xfc - l;
r = 0xfc - r;
reg = l << SGTL5000_DAC_VOL_LEFT_SHIFT |
r << SGTL5000_DAC_VOL_RIGHT_SHIFT;
snd_soc_write(codec, SGTL5000_CHIP_DAC_VOL, reg);
return 0;
}
static int avc_get_threshold(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int db, i;
u16 reg = snd_soc_read(codec, SGTL5000_DAP_AVC_THRESHOLD);
if (!reg) {
ucontrol->value.integer.value[0] = 96;
ucontrol->value.integer.value[1] = 96;
return 0;
}
for (i = 0; avc_thr_db2reg[i] > reg; i++)
;
db = i;
ucontrol->value.integer.value[0] = db;
ucontrol->value.integer.value[1] = db;
return 0;
}
static int avc_put_threshold(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int db;
u16 reg;
db = (int)ucontrol->value.integer.value[0];
if (db < 0 || db > 96)
return -EINVAL;
reg = avc_thr_db2reg[db];
snd_soc_write(codec, SGTL5000_DAP_AVC_THRESHOLD, reg);
return 0;
}
static int sgtl5000_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 adcdac_ctrl = SGTL5000_DAC_MUTE_LEFT | SGTL5000_DAC_MUTE_RIGHT;
snd_soc_update_bits(codec, SGTL5000_CHIP_ADCDAC_CTRL,
adcdac_ctrl, mute ? adcdac_ctrl : 0);
return 0;
}
static int sgtl5000_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
u16 i2sctl = 0;
sgtl5000->master = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
i2sctl |= SGTL5000_I2S_MASTER;
sgtl5000->master = 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
i2sctl |= SGTL5000_I2S_MODE_PCM << SGTL5000_I2S_MODE_SHIFT;
break;
case SND_SOC_DAIFMT_DSP_B:
i2sctl |= SGTL5000_I2S_MODE_PCM << SGTL5000_I2S_MODE_SHIFT;
i2sctl |= SGTL5000_I2S_LRALIGN;
break;
case SND_SOC_DAIFMT_I2S:
i2sctl |= SGTL5000_I2S_MODE_I2S_LJ << SGTL5000_I2S_MODE_SHIFT;
break;
case SND_SOC_DAIFMT_RIGHT_J:
i2sctl |= SGTL5000_I2S_MODE_RJ << SGTL5000_I2S_MODE_SHIFT;
i2sctl |= SGTL5000_I2S_LRPOL;
break;
case SND_SOC_DAIFMT_LEFT_J:
i2sctl |= SGTL5000_I2S_MODE_I2S_LJ << SGTL5000_I2S_MODE_SHIFT;
i2sctl |= SGTL5000_I2S_LRALIGN;
break;
default:
return -EINVAL;
}
sgtl5000->fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
i2sctl |= SGTL5000_I2S_SCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, SGTL5000_CHIP_I2S_CTRL, i2sctl);
return 0;
}
static int sgtl5000_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case SGTL5000_SYSCLK:
sgtl5000->sysclk = freq;
break;
default:
return -EINVAL;
}
return 0;
}
static int sgtl5000_set_clock(struct snd_soc_codec *codec, int frame_rate)
{
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
int clk_ctl = 0;
int sys_fs;
switch (frame_rate) {
case 8000:
case 16000:
sys_fs = 32000;
break;
case 11025:
case 22050:
sys_fs = 44100;
break;
default:
sys_fs = frame_rate;
break;
}
switch (sys_fs / frame_rate) {
case 4:
clk_ctl |= SGTL5000_RATE_MODE_DIV_4 << SGTL5000_RATE_MODE_SHIFT;
break;
case 2:
clk_ctl |= SGTL5000_RATE_MODE_DIV_2 << SGTL5000_RATE_MODE_SHIFT;
break;
case 1:
clk_ctl |= SGTL5000_RATE_MODE_DIV_1 << SGTL5000_RATE_MODE_SHIFT;
break;
default:
return -EINVAL;
}
switch (sys_fs) {
case 32000:
clk_ctl |= SGTL5000_SYS_FS_32k << SGTL5000_SYS_FS_SHIFT;
break;
case 44100:
clk_ctl |= SGTL5000_SYS_FS_44_1k << SGTL5000_SYS_FS_SHIFT;
break;
case 48000:
clk_ctl |= SGTL5000_SYS_FS_48k << SGTL5000_SYS_FS_SHIFT;
break;
case 96000:
clk_ctl |= SGTL5000_SYS_FS_96k << SGTL5000_SYS_FS_SHIFT;
break;
default:
dev_err(codec->dev, "frame rate %d not supported\n",
frame_rate);
return -EINVAL;
}
switch (sgtl5000->sysclk / frame_rate) {
case 256:
clk_ctl |= SGTL5000_MCLK_FREQ_256FS <<
SGTL5000_MCLK_FREQ_SHIFT;
break;
case 384:
clk_ctl |= SGTL5000_MCLK_FREQ_384FS <<
SGTL5000_MCLK_FREQ_SHIFT;
break;
case 512:
clk_ctl |= SGTL5000_MCLK_FREQ_512FS <<
SGTL5000_MCLK_FREQ_SHIFT;
break;
default:
if (sgtl5000->master) {
clk_ctl |= SGTL5000_MCLK_FREQ_PLL <<
SGTL5000_MCLK_FREQ_SHIFT;
} else {
dev_err(codec->dev,
"PLL not supported in slave mode\n");
dev_err(codec->dev, "%d ratio is not supported. "
"SYS_MCLK needs to be 256, 384 or 512 * fs\n",
sgtl5000->sysclk / frame_rate);
return -EINVAL;
}
}
if ((clk_ctl & SGTL5000_MCLK_FREQ_MASK) == SGTL5000_MCLK_FREQ_PLL) {
u64 out, t;
int div2;
int pll_ctl;
unsigned int in, int_div, frac_div;
if (sgtl5000->sysclk > 17000000) {
div2 = 1;
in = sgtl5000->sysclk / 2;
} else {
div2 = 0;
in = sgtl5000->sysclk;
}
if (sys_fs == 44100)
out = 180633600;
else
out = 196608000;
t = do_div(out, in);
int_div = out;
t *= 2048;
do_div(t, in);
frac_div = t;
pll_ctl = int_div << SGTL5000_PLL_INT_DIV_SHIFT |
frac_div << SGTL5000_PLL_FRAC_DIV_SHIFT;
snd_soc_write(codec, SGTL5000_CHIP_PLL_CTRL, pll_ctl);
if (div2)
snd_soc_update_bits(codec,
SGTL5000_CHIP_CLK_TOP_CTRL,
SGTL5000_INPUT_FREQ_DIV2,
SGTL5000_INPUT_FREQ_DIV2);
else
snd_soc_update_bits(codec,
SGTL5000_CHIP_CLK_TOP_CTRL,
SGTL5000_INPUT_FREQ_DIV2,
0);
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_PLL_POWERUP | SGTL5000_VCOAMP_POWERUP,
SGTL5000_PLL_POWERUP | SGTL5000_VCOAMP_POWERUP);
snd_soc_write(codec, SGTL5000_CHIP_CLK_CTRL, clk_ctl);
} else {
snd_soc_write(codec, SGTL5000_CHIP_CLK_CTRL, clk_ctl);
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_PLL_POWERUP | SGTL5000_VCOAMP_POWERUP,
0);
}
return 0;
}
static int sgtl5000_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
int channels = params_channels(params);
int i2s_ctl = 0;
int stereo;
int ret;
if (!sgtl5000->sysclk) {
dev_err(codec->dev, "%s: set sysclk first!\n", __func__);
return -EFAULT;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
stereo = SGTL5000_DAC_STEREO;
else
stereo = SGTL5000_ADC_STEREO;
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER, stereo,
channels == 1 ? 0 : stereo);
ret = sgtl5000_set_clock(codec, params_rate(params));
if (ret)
return ret;
switch (params_width(params)) {
case 16:
if (sgtl5000->fmt == SND_SOC_DAIFMT_RIGHT_J)
return -EINVAL;
i2s_ctl |= SGTL5000_I2S_DLEN_16 << SGTL5000_I2S_DLEN_SHIFT;
i2s_ctl |= SGTL5000_I2S_SCLKFREQ_32FS <<
SGTL5000_I2S_SCLKFREQ_SHIFT;
break;
case 20:
i2s_ctl |= SGTL5000_I2S_DLEN_20 << SGTL5000_I2S_DLEN_SHIFT;
i2s_ctl |= SGTL5000_I2S_SCLKFREQ_64FS <<
SGTL5000_I2S_SCLKFREQ_SHIFT;
break;
case 24:
i2s_ctl |= SGTL5000_I2S_DLEN_24 << SGTL5000_I2S_DLEN_SHIFT;
i2s_ctl |= SGTL5000_I2S_SCLKFREQ_64FS <<
SGTL5000_I2S_SCLKFREQ_SHIFT;
break;
case 32:
if (sgtl5000->fmt == SND_SOC_DAIFMT_RIGHT_J)
return -EINVAL;
i2s_ctl |= SGTL5000_I2S_DLEN_32 << SGTL5000_I2S_DLEN_SHIFT;
i2s_ctl |= SGTL5000_I2S_SCLKFREQ_64FS <<
SGTL5000_I2S_SCLKFREQ_SHIFT;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, SGTL5000_CHIP_I2S_CTRL,
SGTL5000_I2S_DLEN_MASK | SGTL5000_I2S_SCLKFREQ_MASK,
i2s_ctl);
return 0;
}
static int sgtl5000_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_REFTOP_POWERUP,
SGTL5000_REFTOP_POWERUP);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, SGTL5000_CHIP_ANA_POWER,
SGTL5000_REFTOP_POWERUP, 0);
break;
}
return 0;
}
static bool sgtl5000_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case SGTL5000_CHIP_ID:
case SGTL5000_CHIP_ADCDAC_CTRL:
case SGTL5000_CHIP_ANA_STATUS:
return true;
}
return false;
}
static bool sgtl5000_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case SGTL5000_CHIP_ID:
case SGTL5000_CHIP_DIG_POWER:
case SGTL5000_CHIP_CLK_CTRL:
case SGTL5000_CHIP_I2S_CTRL:
case SGTL5000_CHIP_SSS_CTRL:
case SGTL5000_CHIP_ADCDAC_CTRL:
case SGTL5000_CHIP_DAC_VOL:
case SGTL5000_CHIP_PAD_STRENGTH:
case SGTL5000_CHIP_ANA_ADC_CTRL:
case SGTL5000_CHIP_ANA_HP_CTRL:
case SGTL5000_CHIP_ANA_CTRL:
case SGTL5000_CHIP_LINREG_CTRL:
case SGTL5000_CHIP_REF_CTRL:
case SGTL5000_CHIP_MIC_CTRL:
case SGTL5000_CHIP_LINE_OUT_CTRL:
case SGTL5000_CHIP_LINE_OUT_VOL:
case SGTL5000_CHIP_ANA_POWER:
case SGTL5000_CHIP_PLL_CTRL:
case SGTL5000_CHIP_CLK_TOP_CTRL:
case SGTL5000_CHIP_ANA_STATUS:
case SGTL5000_CHIP_SHORT_CTRL:
case SGTL5000_CHIP_ANA_TEST2:
case SGTL5000_DAP_CTRL:
case SGTL5000_DAP_PEQ:
case SGTL5000_DAP_BASS_ENHANCE:
case SGTL5000_DAP_BASS_ENHANCE_CTRL:
case SGTL5000_DAP_AUDIO_EQ:
case SGTL5000_DAP_SURROUND:
case SGTL5000_DAP_FLT_COEF_ACCESS:
case SGTL5000_DAP_COEF_WR_B0_MSB:
case SGTL5000_DAP_COEF_WR_B0_LSB:
case SGTL5000_DAP_EQ_BASS_BAND0:
case SGTL5000_DAP_EQ_BASS_BAND1:
case SGTL5000_DAP_EQ_BASS_BAND2:
case SGTL5000_DAP_EQ_BASS_BAND3:
case SGTL5000_DAP_EQ_BASS_BAND4:
case SGTL5000_DAP_MAIN_CHAN:
case SGTL5000_DAP_MIX_CHAN:
case SGTL5000_DAP_AVC_CTRL:
case SGTL5000_DAP_AVC_THRESHOLD:
case SGTL5000_DAP_AVC_ATTACK:
case SGTL5000_DAP_AVC_DECAY:
case SGTL5000_DAP_COEF_WR_B1_MSB:
case SGTL5000_DAP_COEF_WR_B1_LSB:
case SGTL5000_DAP_COEF_WR_B2_MSB:
case SGTL5000_DAP_COEF_WR_B2_LSB:
case SGTL5000_DAP_COEF_WR_A1_MSB:
case SGTL5000_DAP_COEF_WR_A1_LSB:
case SGTL5000_DAP_COEF_WR_A2_MSB:
case SGTL5000_DAP_COEF_WR_A2_LSB:
return true;
default:
return false;
}
}
static int sgtl5000_set_power_regs(struct snd_soc_codec *codec)
{
int vddd;
int vdda;
int vddio;
u16 ana_pwr;
u16 lreg_ctrl;
int vag;
int lo_vag;
int vol_quot;
int lo_vol;
size_t i;
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
vdda = regulator_get_voltage(sgtl5000->supplies[VDDA].consumer);
vddio = regulator_get_voltage(sgtl5000->supplies[VDDIO].consumer);
vddd = (sgtl5000->num_supplies > VDDD)
? regulator_get_voltage(sgtl5000->supplies[VDDD].consumer)
: LDO_VOLTAGE;
vdda = vdda / 1000;
vddio = vddio / 1000;
vddd = vddd / 1000;
if (vdda <= 0 || vddio <= 0 || vddd < 0) {
dev_err(codec->dev, "regulator voltage not set correctly\n");
return -EINVAL;
}
if (vdda > 3600 || vddio > 3600 || vddd > 1980) {
dev_err(codec->dev,
"exceed max voltage vdda %dmV vddio %dmV vddd %dmV\n",
vdda, vddio, vddd);
return -EINVAL;
}
ana_pwr = snd_soc_read(codec, SGTL5000_CHIP_ANA_POWER);
ana_pwr |= SGTL5000_DAC_STEREO |
SGTL5000_ADC_STEREO |
SGTL5000_REFTOP_POWERUP;
lreg_ctrl = snd_soc_read(codec, SGTL5000_CHIP_LINREG_CTRL);
if (vddio < 3100 && vdda < 3100) {
snd_soc_update_bits(codec, SGTL5000_CHIP_CLK_TOP_CTRL,
SGTL5000_INT_OSC_EN,
SGTL5000_INT_OSC_EN);
ana_pwr |= SGTL5000_VDDC_CHRGPMP_POWERUP;
} else if (vddio >= 3100 && vdda >= 3100) {
ana_pwr &= ~SGTL5000_VDDC_CHRGPMP_POWERUP;
lreg_ctrl |= SGTL5000_VDDC_ASSN_OVRD;
lreg_ctrl |= SGTL5000_VDDC_MAN_ASSN_VDDIO <<
SGTL5000_VDDC_MAN_ASSN_SHIFT;
}
snd_soc_write(codec, SGTL5000_CHIP_LINREG_CTRL, lreg_ctrl);
snd_soc_write(codec, SGTL5000_CHIP_ANA_POWER, ana_pwr);
vag = vdda / 2;
if (vag <= SGTL5000_ANA_GND_BASE)
vag = 0;
else if (vag >= SGTL5000_ANA_GND_BASE + SGTL5000_ANA_GND_STP *
(SGTL5000_ANA_GND_MASK >> SGTL5000_ANA_GND_SHIFT))
vag = SGTL5000_ANA_GND_MASK >> SGTL5000_ANA_GND_SHIFT;
else
vag = (vag - SGTL5000_ANA_GND_BASE) / SGTL5000_ANA_GND_STP;
snd_soc_update_bits(codec, SGTL5000_CHIP_REF_CTRL,
SGTL5000_ANA_GND_MASK, vag << SGTL5000_ANA_GND_SHIFT);
lo_vag = vddio / 2;
if (lo_vag <= SGTL5000_LINE_OUT_GND_BASE)
lo_vag = 0;
else if (lo_vag >= SGTL5000_LINE_OUT_GND_BASE +
SGTL5000_LINE_OUT_GND_STP * SGTL5000_LINE_OUT_GND_MAX)
lo_vag = SGTL5000_LINE_OUT_GND_MAX;
else
lo_vag = (lo_vag - SGTL5000_LINE_OUT_GND_BASE) /
SGTL5000_LINE_OUT_GND_STP;
snd_soc_update_bits(codec, SGTL5000_CHIP_LINE_OUT_CTRL,
SGTL5000_LINE_OUT_CURRENT_MASK |
SGTL5000_LINE_OUT_GND_MASK,
lo_vag << SGTL5000_LINE_OUT_GND_SHIFT |
SGTL5000_LINE_OUT_CURRENT_360u <<
SGTL5000_LINE_OUT_CURRENT_SHIFT);
vol_quot = (vag * 100) / lo_vag;
lo_vol = 0;
for (i = 0; i < ARRAY_SIZE(vol_quot_table); i++) {
if (vol_quot >= vol_quot_table[i])
lo_vol = i;
else
break;
}
snd_soc_update_bits(codec, SGTL5000_CHIP_LINE_OUT_VOL,
SGTL5000_LINE_OUT_VOL_RIGHT_MASK |
SGTL5000_LINE_OUT_VOL_LEFT_MASK,
lo_vol << SGTL5000_LINE_OUT_VOL_RIGHT_SHIFT |
lo_vol << SGTL5000_LINE_OUT_VOL_LEFT_SHIFT);
return 0;
}
static int sgtl5000_enable_regulators(struct i2c_client *client)
{
int ret;
int i;
int external_vddd = 0;
struct regulator *vddd;
struct sgtl5000_priv *sgtl5000 = i2c_get_clientdata(client);
for (i = 0; i < ARRAY_SIZE(sgtl5000->supplies); i++)
sgtl5000->supplies[i].supply = supply_names[i];
vddd = regulator_get_optional(&client->dev, "VDDD");
if (IS_ERR(vddd)) {
if (PTR_ERR(vddd) == -EPROBE_DEFER)
return -EPROBE_DEFER;
} else {
external_vddd = 1;
regulator_put(vddd);
}
sgtl5000->num_supplies = ARRAY_SIZE(sgtl5000->supplies)
- 1 + external_vddd;
ret = regulator_bulk_get(&client->dev, sgtl5000->num_supplies,
sgtl5000->supplies);
if (ret)
return ret;
ret = regulator_bulk_enable(sgtl5000->num_supplies,
sgtl5000->supplies);
if (!ret)
usleep_range(10, 20);
else
regulator_bulk_free(sgtl5000->num_supplies,
sgtl5000->supplies);
return ret;
}
static int sgtl5000_probe(struct snd_soc_codec *codec)
{
int ret;
u16 reg;
struct sgtl5000_priv *sgtl5000 = snd_soc_codec_get_drvdata(codec);
ret = sgtl5000_set_power_regs(codec);
if (ret)
goto err;
snd_soc_update_bits(codec, SGTL5000_CHIP_REF_CTRL,
SGTL5000_SMALL_POP, 1);
snd_soc_write(codec, SGTL5000_CHIP_SHORT_CTRL, 0);
snd_soc_write(codec, SGTL5000_CHIP_SSS_CTRL,
SGTL5000_DAC_SEL_I2S_IN << SGTL5000_DAC_SEL_SHIFT);
snd_soc_write(codec, SGTL5000_CHIP_DIG_POWER,
SGTL5000_ADC_EN | SGTL5000_DAC_EN);
snd_soc_write(codec, SGTL5000_CHIP_ADCDAC_CTRL,
SGTL5000_DAC_VOL_RAMP_EN |
SGTL5000_DAC_MUTE_RIGHT |
SGTL5000_DAC_MUTE_LEFT);
reg = ((sgtl5000->lrclk_strength) << SGTL5000_PAD_I2S_LRCLK_SHIFT | 0x5f);
snd_soc_write(codec, SGTL5000_CHIP_PAD_STRENGTH, reg);
snd_soc_write(codec, SGTL5000_CHIP_ANA_CTRL,
SGTL5000_HP_ZCD_EN |
SGTL5000_ADC_ZCD_EN);
snd_soc_update_bits(codec, SGTL5000_CHIP_MIC_CTRL,
SGTL5000_BIAS_R_MASK,
sgtl5000->micbias_resistor << SGTL5000_BIAS_R_SHIFT);
snd_soc_update_bits(codec, SGTL5000_CHIP_MIC_CTRL,
SGTL5000_BIAS_VOLT_MASK,
sgtl5000->micbias_voltage << SGTL5000_BIAS_VOLT_SHIFT);
snd_soc_write(codec, SGTL5000_DAP_CTRL, 0);
return 0;
err:
return ret;
}
static int sgtl5000_remove(struct snd_soc_codec *codec)
{
return 0;
}
static void sgtl5000_fill_defaults(struct i2c_client *client)
{
struct sgtl5000_priv *sgtl5000 = i2c_get_clientdata(client);
int i, ret, val, index;
for (i = 0; i < ARRAY_SIZE(sgtl5000_reg_defaults); i++) {
val = sgtl5000_reg_defaults[i].def;
index = sgtl5000_reg_defaults[i].reg;
ret = regmap_write(sgtl5000->regmap, index, val);
if (ret)
dev_err(&client->dev,
"%s: error %d setting reg 0x%02x to 0x%04x\n",
__func__, ret, index, val);
}
}
static int sgtl5000_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sgtl5000_priv *sgtl5000;
int ret, reg, rev;
struct device_node *np = client->dev.of_node;
u32 value;
u16 ana_pwr;
sgtl5000 = devm_kzalloc(&client->dev, sizeof(*sgtl5000), GFP_KERNEL);
if (!sgtl5000)
return -ENOMEM;
i2c_set_clientdata(client, sgtl5000);
ret = sgtl5000_enable_regulators(client);
if (ret)
return ret;
sgtl5000->regmap = devm_regmap_init_i2c(client, &sgtl5000_regmap);
if (IS_ERR(sgtl5000->regmap)) {
ret = PTR_ERR(sgtl5000->regmap);
dev_err(&client->dev, "Failed to allocate regmap: %d\n", ret);
goto disable_regs;
}
sgtl5000->mclk = devm_clk_get(&client->dev, NULL);
if (IS_ERR(sgtl5000->mclk)) {
ret = PTR_ERR(sgtl5000->mclk);
dev_err(&client->dev, "Failed to get mclock: %d\n", ret);
if (ret == -ENOENT)
ret = -EPROBE_DEFER;
goto disable_regs;
}
ret = clk_prepare_enable(sgtl5000->mclk);
if (ret) {
dev_err(&client->dev, "Error enabling clock %d\n", ret);
goto disable_regs;
}
udelay(1);
ret = regmap_read(sgtl5000->regmap, SGTL5000_CHIP_ID, &reg);
if (ret) {
dev_err(&client->dev, "Error reading chip id %d\n", ret);
goto disable_clk;
}
if (((reg & SGTL5000_PARTID_MASK) >> SGTL5000_PARTID_SHIFT) !=
SGTL5000_PARTID_PART_ID) {
dev_err(&client->dev,
"Device with ID register %x is not a sgtl5000\n", reg);
ret = -ENODEV;
goto disable_clk;
}
rev = (reg & SGTL5000_REVID_MASK) >> SGTL5000_REVID_SHIFT;
dev_info(&client->dev, "sgtl5000 revision 0x%x\n", rev);
sgtl5000->revision = rev;
ret = regmap_write(sgtl5000->regmap,
SGTL5000_CHIP_CLK_CTRL,
SGTL5000_CHIP_CLK_CTRL_DEFAULT);
if (ret)
dev_err(&client->dev,
"Error %d initializing CHIP_CLK_CTRL\n", ret);
ana_pwr = SGTL5000_ANA_POWER_DEFAULT;
if (sgtl5000->num_supplies <= VDDD) {
ret = regmap_update_bits(sgtl5000->regmap,
SGTL5000_CHIP_LINREG_CTRL,
SGTL5000_LINREG_VDDD_MASK,
LINREG_VDDD);
if (ret)
dev_err(&client->dev,
"Error %d setting LINREG_VDDD\n", ret);
ana_pwr |= SGTL5000_LINEREG_D_POWERUP;
dev_info(&client->dev,
"Using internal LDO instead of VDDD: check ER1\n");
} else {
ana_pwr &= ~(SGTL5000_STARTUP_POWERUP
| SGTL5000_LINREG_SIMPLE_POWERUP);
dev_dbg(&client->dev, "Using external VDDD\n");
}
ret = regmap_write(sgtl5000->regmap, SGTL5000_CHIP_ANA_POWER, ana_pwr);
if (ret)
dev_err(&client->dev,
"Error %d setting CHIP_ANA_POWER to %04x\n",
ret, ana_pwr);
if (np) {
if (!of_property_read_u32(np,
"micbias-resistor-k-ohms", &value)) {
switch (value) {
case SGTL5000_MICBIAS_OFF:
sgtl5000->micbias_resistor = 0;
break;
case SGTL5000_MICBIAS_2K:
sgtl5000->micbias_resistor = 1;
break;
case SGTL5000_MICBIAS_4K:
sgtl5000->micbias_resistor = 2;
break;
case SGTL5000_MICBIAS_8K:
sgtl5000->micbias_resistor = 3;
break;
default:
sgtl5000->micbias_resistor = 2;
dev_err(&client->dev,
"Unsuitable MicBias resistor\n");
}
} else {
sgtl5000->micbias_resistor = 2;
}
if (!of_property_read_u32(np,
"micbias-voltage-m-volts", &value)) {
if ((value >= 1250) && (value <= 3000))
sgtl5000->micbias_voltage = (value / 250) - 5;
else {
sgtl5000->micbias_voltage = 0;
dev_err(&client->dev,
"Unsuitable MicBias voltage\n");
}
} else {
sgtl5000->micbias_voltage = 0;
}
}
sgtl5000->lrclk_strength = I2S_LRCLK_STRENGTH_LOW;
if (!of_property_read_u32(np, "lrclk-strength", &value)) {
if (value > I2S_LRCLK_STRENGTH_HIGH)
value = I2S_LRCLK_STRENGTH_LOW;
sgtl5000->lrclk_strength = value;
}
sgtl5000_fill_defaults(client);
ret = snd_soc_register_codec(&client->dev,
&sgtl5000_driver, &sgtl5000_dai, 1);
if (ret)
goto disable_clk;
return 0;
disable_clk:
clk_disable_unprepare(sgtl5000->mclk);
disable_regs:
regulator_bulk_disable(sgtl5000->num_supplies, sgtl5000->supplies);
regulator_bulk_free(sgtl5000->num_supplies, sgtl5000->supplies);
return ret;
}
static int sgtl5000_i2c_remove(struct i2c_client *client)
{
struct sgtl5000_priv *sgtl5000 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
clk_disable_unprepare(sgtl5000->mclk);
regulator_bulk_disable(sgtl5000->num_supplies, sgtl5000->supplies);
regulator_bulk_free(sgtl5000->num_supplies, sgtl5000->supplies);
return 0;
}
