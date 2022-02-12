static void rt5631_write_index(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
snd_soc_write(codec, RT5631_INDEX_ADD, reg);
snd_soc_write(codec, RT5631_INDEX_DATA, value);
}
static unsigned int rt5631_read_index(struct snd_soc_codec *codec,
unsigned int reg)
{
unsigned int value;
snd_soc_write(codec, RT5631_INDEX_ADD, reg);
value = snd_soc_read(codec, RT5631_INDEX_DATA);
return value;
}
static int rt5631_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, RT5631_RESET, 0);
}
static bool rt5631_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5631_RESET:
case RT5631_INT_ST_IRQ_CTRL_2:
case RT5631_INDEX_ADD:
case RT5631_INDEX_DATA:
case RT5631_EQ_CTRL:
return 1;
default:
return 0;
}
}
static bool rt5631_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5631_RESET:
case RT5631_SPK_OUT_VOL:
case RT5631_HP_OUT_VOL:
case RT5631_MONO_AXO_1_2_VOL:
case RT5631_AUX_IN_VOL:
case RT5631_STEREO_DAC_VOL_1:
case RT5631_MIC_CTRL_1:
case RT5631_STEREO_DAC_VOL_2:
case RT5631_ADC_CTRL_1:
case RT5631_ADC_REC_MIXER:
case RT5631_ADC_CTRL_2:
case RT5631_VDAC_DIG_VOL:
case RT5631_OUTMIXER_L_CTRL:
case RT5631_OUTMIXER_R_CTRL:
case RT5631_AXO1MIXER_CTRL:
case RT5631_AXO2MIXER_CTRL:
case RT5631_MIC_CTRL_2:
case RT5631_DIG_MIC_CTRL:
case RT5631_MONO_INPUT_VOL:
case RT5631_SPK_MIXER_CTRL:
case RT5631_SPK_MONO_OUT_CTRL:
case RT5631_SPK_MONO_HP_OUT_CTRL:
case RT5631_SDP_CTRL:
case RT5631_MONO_SDP_CTRL:
case RT5631_STEREO_AD_DA_CLK_CTRL:
case RT5631_PWR_MANAG_ADD1:
case RT5631_PWR_MANAG_ADD2:
case RT5631_PWR_MANAG_ADD3:
case RT5631_PWR_MANAG_ADD4:
case RT5631_GEN_PUR_CTRL_REG:
case RT5631_GLOBAL_CLK_CTRL:
case RT5631_PLL_CTRL:
case RT5631_INT_ST_IRQ_CTRL_1:
case RT5631_INT_ST_IRQ_CTRL_2:
case RT5631_GPIO_CTRL:
case RT5631_MISC_CTRL:
case RT5631_DEPOP_FUN_CTRL_1:
case RT5631_DEPOP_FUN_CTRL_2:
case RT5631_JACK_DET_CTRL:
case RT5631_SOFT_VOL_CTRL:
case RT5631_ALC_CTRL_1:
case RT5631_ALC_CTRL_2:
case RT5631_ALC_CTRL_3:
case RT5631_PSEUDO_SPATL_CTRL:
case RT5631_INDEX_ADD:
case RT5631_INDEX_DATA:
case RT5631_EQ_CTRL:
case RT5631_VENDOR_ID:
case RT5631_VENDOR_ID1:
case RT5631_VENDOR_ID2:
return 1;
default:
return 0;
}
}
static int rt5631_dmic_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = rt5631->dmic_used_flag;
return 0;
}
static int rt5631_dmic_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
rt5631->dmic_used_flag = ucontrol->value.integer.value[0];
return 0;
}
static int check_sysclk1_source(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_GLOBAL_CLK_CTRL);
return reg & RT5631_SYSCLK_SOUR_SEL_PLL;
}
static int check_dmic_used(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(source->codec);
return rt5631->dmic_used_flag;
}
static int check_dacl_to_outmixl(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_OUTMIXER_L_CTRL);
return !(reg & RT5631_M_DAC_L_TO_OUTMIXER_L);
}
static int check_dacr_to_outmixr(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_OUTMIXER_R_CTRL);
return !(reg & RT5631_M_DAC_R_TO_OUTMIXER_R);
}
static int check_dacl_to_spkmixl(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_SPK_MIXER_CTRL);
return !(reg & RT5631_M_DAC_L_TO_SPKMIXER_L);
}
static int check_dacr_to_spkmixr(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_SPK_MIXER_CTRL);
return !(reg & RT5631_M_DAC_R_TO_SPKMIXER_R);
}
static int check_adcl_select(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_ADC_REC_MIXER);
return !(reg & RT5631_M_MIC1_TO_RECMIXER_L);
}
static int check_adcr_select(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg;
reg = snd_soc_read(source->codec, RT5631_ADC_REC_MIXER);
return !(reg & RT5631_M_MIC2_TO_RECMIXER_R);
}
static void onebit_depop_power_stage(struct snd_soc_codec *codec, int enable)
{
unsigned int soft_vol, hp_zc;
snd_soc_update_bits(codec, RT5631_DEPOP_FUN_CTRL_2,
RT5631_EN_ONE_BIT_DEPOP, 0);
soft_vol = snd_soc_read(codec, RT5631_SOFT_VOL_CTRL);
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, 0);
hp_zc = snd_soc_read(codec, RT5631_INT_ST_IRQ_CTRL_2);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc & 0xf7ff);
if (enable) {
rt5631_write_index(codec, RT5631_TEST_MODE_CTRL, 0x84c0);
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x309f);
rt5631_write_index(codec, RT5631_CP_INTL_REG2, 0x6530);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_2,
RT5631_EN_CAP_FREE_DEPOP);
} else {
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_2, 0);
msleep(100);
}
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, soft_vol);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc);
}
static void onebit_depop_mute_stage(struct snd_soc_codec *codec, int enable)
{
unsigned int soft_vol, hp_zc;
snd_soc_update_bits(codec, RT5631_DEPOP_FUN_CTRL_2,
RT5631_EN_ONE_BIT_DEPOP, 0);
soft_vol = snd_soc_read(codec, RT5631_SOFT_VOL_CTRL);
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, 0);
hp_zc = snd_soc_read(codec, RT5631_INT_ST_IRQ_CTRL_2);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc & 0xf7ff);
if (enable) {
schedule_timeout_uninterruptible(msecs_to_jiffies(10));
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x307f);
snd_soc_update_bits(codec, RT5631_HP_OUT_VOL,
RT5631_L_MUTE | RT5631_R_MUTE, 0);
msleep(300);
} else {
snd_soc_update_bits(codec, RT5631_HP_OUT_VOL,
RT5631_L_MUTE | RT5631_R_MUTE,
RT5631_L_MUTE | RT5631_R_MUTE);
msleep(100);
}
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, soft_vol);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc);
}
static void depop_seq_power_stage(struct snd_soc_codec *codec, int enable)
{
unsigned int soft_vol, hp_zc;
snd_soc_update_bits(codec, RT5631_DEPOP_FUN_CTRL_2,
RT5631_EN_ONE_BIT_DEPOP, RT5631_EN_ONE_BIT_DEPOP);
soft_vol = snd_soc_read(codec, RT5631_SOFT_VOL_CTRL);
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, 0);
hp_zc = snd_soc_read(codec, RT5631_INT_ST_IRQ_CTRL_2);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc & 0xf7ff);
if (enable) {
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x303e);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_CHARGE_PUMP | RT5631_PWR_HP_L_AMP |
RT5631_PWR_HP_R_AMP,
RT5631_PWR_CHARGE_PUMP | RT5631_PWR_HP_L_AMP |
RT5631_PWR_HP_R_AMP);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_EN_DEPOP2_FOR_HP);
msleep(100);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_HP_DEPOP_DIS, RT5631_PWR_HP_DEPOP_DIS);
} else {
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x303F);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_EN_MUTE_UNMUTE_DEPOP |
RT5631_PD_HPAMP_L_ST_UP | RT5631_PD_HPAMP_R_ST_UP);
msleep(75);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_PD_HPAMP_L_ST_UP |
RT5631_PD_HPAMP_R_ST_UP);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_HP_DEPOP_DIS, 0);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_EN_DEPOP2_FOR_HP |
RT5631_PD_HPAMP_L_ST_UP | RT5631_PD_HPAMP_R_ST_UP);
msleep(80);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_CHARGE_PUMP | RT5631_PWR_HP_L_AMP |
RT5631_PWR_HP_R_AMP, 0);
}
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, soft_vol);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc);
}
static void depop_seq_mute_stage(struct snd_soc_codec *codec, int enable)
{
unsigned int soft_vol, hp_zc;
snd_soc_update_bits(codec, RT5631_DEPOP_FUN_CTRL_2,
RT5631_EN_ONE_BIT_DEPOP, RT5631_EN_ONE_BIT_DEPOP);
soft_vol = snd_soc_read(codec, RT5631_SOFT_VOL_CTRL);
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, 0);
hp_zc = snd_soc_read(codec, RT5631_INT_ST_IRQ_CTRL_2);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc & 0xf7ff);
if (enable) {
schedule_timeout_uninterruptible(msecs_to_jiffies(10));
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x302f);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_EN_MUTE_UNMUTE_DEPOP |
RT5631_EN_HP_R_M_UN_MUTE_DEPOP |
RT5631_EN_HP_L_M_UN_MUTE_DEPOP);
snd_soc_update_bits(codec, RT5631_HP_OUT_VOL,
RT5631_L_MUTE | RT5631_R_MUTE, 0);
msleep(160);
} else {
rt5631_write_index(codec, RT5631_SPK_INTL_CTRL, 0x302f);
snd_soc_write(codec, RT5631_DEPOP_FUN_CTRL_1,
RT5631_POW_ON_SOFT_GEN | RT5631_EN_MUTE_UNMUTE_DEPOP |
RT5631_EN_HP_R_M_UN_MUTE_DEPOP |
RT5631_EN_HP_L_M_UN_MUTE_DEPOP);
snd_soc_update_bits(codec, RT5631_HP_OUT_VOL,
RT5631_L_MUTE | RT5631_R_MUTE,
RT5631_L_MUTE | RT5631_R_MUTE);
msleep(150);
}
snd_soc_write(codec, RT5631_SOFT_VOL_CTRL, soft_vol);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, hp_zc);
}
static int hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
if (rt5631->codec_version) {
onebit_depop_mute_stage(codec, 0);
onebit_depop_power_stage(codec, 0);
} else {
depop_seq_mute_stage(codec, 0);
depop_seq_power_stage(codec, 0);
}
break;
case SND_SOC_DAPM_POST_PMU:
if (rt5631->codec_version) {
onebit_depop_power_stage(codec, 1);
onebit_depop_mute_stage(codec, 1);
} else {
depop_seq_power_stage(codec, 1);
depop_seq_mute_stage(codec, 1);
}
break;
default:
break;
}
return 0;
}
static int set_dmic_params(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
switch (rt5631->rx_rate) {
case 44100:
case 48000:
snd_soc_update_bits(codec, RT5631_DIG_MIC_CTRL,
RT5631_DMIC_CLK_CTRL_MASK,
RT5631_DMIC_CLK_CTRL_TO_32FS);
break;
case 32000:
case 22050:
snd_soc_update_bits(codec, RT5631_DIG_MIC_CTRL,
RT5631_DMIC_CLK_CTRL_MASK,
RT5631_DMIC_CLK_CTRL_TO_64FS);
break;
case 16000:
case 11025:
case 8000:
snd_soc_update_bits(codec, RT5631_DIG_MIC_CTRL,
RT5631_DMIC_CLK_CTRL_MASK,
RT5631_DMIC_CLK_CTRL_TO_128FS);
break;
default:
return -EINVAL;
}
return 0;
}
static int get_coeff(int mclk, int rate, int timesofbclk)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].mclk == mclk && coeff_div[i].rate == rate &&
(coeff_div[i].bclk / coeff_div[i].rate) == timesofbclk)
return i;
}
return -EINVAL;
}
static int rt5631_hifi_pcm_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
int timesofbclk = 32, coeff;
unsigned int iface = 0;
dev_dbg(codec->dev, "enter %s\n", __func__);
rt5631->bclk_rate = snd_soc_params_to_bclk(params);
if (rt5631->bclk_rate < 0) {
dev_err(codec->dev, "Fail to get BCLK rate\n");
return rt5631->bclk_rate;
}
rt5631->rx_rate = params_rate(params);
if (rt5631->master)
coeff = get_coeff(rt5631->sysclk, rt5631->rx_rate,
rt5631->bclk_rate / rt5631->rx_rate);
else
coeff = get_coeff(rt5631->sysclk, rt5631->rx_rate,
timesofbclk);
if (coeff < 0) {
dev_err(codec->dev, "Fail to get coeff\n");
return coeff;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= RT5631_SDP_I2S_DL_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= RT5631_SDP_I2S_DL_24;
break;
case SNDRV_PCM_FORMAT_S8:
iface |= RT5631_SDP_I2S_DL_8;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5631_SDP_CTRL,
RT5631_SDP_I2S_DL_MASK, iface);
snd_soc_write(codec, RT5631_STEREO_AD_DA_CLK_CTRL,
coeff_div[coeff].reg_val);
return 0;
}
static int rt5631_hifi_codec_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
unsigned int iface = 0;
dev_dbg(codec->dev, "enter %s\n", __func__);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5631->master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iface |= RT5631_SDP_MODE_SEL_SLAVE;
rt5631->master = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= RT5631_SDP_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= RT5631_SDP_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= RT5631_SDP_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= RT5631_SDP_I2S_BCLK_POL_CTRL;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, RT5631_SDP_CTRL, iface);
return 0;
}
static int rt5631_hifi_codec_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "enter %s, syclk=%d\n", __func__, freq);
if ((freq >= (256 * 8000)) && (freq <= (512 * 96000))) {
rt5631->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int rt5631_codec_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
int i, ret = -EINVAL;
dev_dbg(codec->dev, "enter %s\n", __func__);
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
snd_soc_update_bits(codec, RT5631_GLOBAL_CLK_CTRL,
RT5631_SYSCLK_SOUR_SEL_MASK,
RT5631_SYSCLK_SOUR_SEL_MCLK);
return 0;
}
if (rt5631->master) {
for (i = 0; i < ARRAY_SIZE(codec_master_pll_div); i++)
if (freq_in == codec_master_pll_div[i].pll_in &&
freq_out == codec_master_pll_div[i].pll_out) {
dev_info(codec->dev,
"change PLL in master mode\n");
snd_soc_write(codec, RT5631_PLL_CTRL,
codec_master_pll_div[i].reg_val);
schedule_timeout_uninterruptible(
msecs_to_jiffies(20));
snd_soc_update_bits(codec,
RT5631_GLOBAL_CLK_CTRL,
RT5631_SYSCLK_SOUR_SEL_MASK |
RT5631_PLLCLK_SOUR_SEL_MASK,
RT5631_SYSCLK_SOUR_SEL_PLL |
RT5631_PLLCLK_SOUR_SEL_MCLK);
ret = 0;
break;
}
} else {
for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++)
if (freq_in == codec_slave_pll_div[i].pll_in &&
freq_out == codec_slave_pll_div[i].pll_out) {
dev_info(codec->dev,
"change PLL in slave mode\n");
snd_soc_write(codec, RT5631_PLL_CTRL,
codec_slave_pll_div[i].reg_val);
schedule_timeout_uninterruptible(
msecs_to_jiffies(20));
snd_soc_update_bits(codec,
RT5631_GLOBAL_CLK_CTRL,
RT5631_SYSCLK_SOUR_SEL_MASK |
RT5631_PLLCLK_SOUR_SEL_MASK,
RT5631_SYSCLK_SOUR_SEL_PLL |
RT5631_PLLCLK_SOUR_SEL_BCLK);
ret = 0;
break;
}
}
return ret;
}
static int rt5631_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD2,
RT5631_PWR_MICBIAS1_VOL | RT5631_PWR_MICBIAS2_VOL,
RT5631_PWR_MICBIAS1_VOL | RT5631_PWR_MICBIAS2_VOL);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_VREF | RT5631_PWR_MAIN_BIAS,
RT5631_PWR_VREF | RT5631_PWR_MAIN_BIAS);
msleep(80);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_FAST_VREF_CTRL,
RT5631_PWR_FAST_VREF_CTRL);
regcache_cache_only(rt5631->regmap, false);
regcache_sync(rt5631->regmap);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, RT5631_PWR_MANAG_ADD1, 0x0000);
snd_soc_write(codec, RT5631_PWR_MANAG_ADD2, 0x0000);
snd_soc_write(codec, RT5631_PWR_MANAG_ADD3, 0x0000);
snd_soc_write(codec, RT5631_PWR_MANAG_ADD4, 0x0000);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int rt5631_probe(struct snd_soc_codec *codec)
{
struct rt5631_priv *rt5631 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
val = rt5631_read_index(codec, RT5631_ADDA_MIXER_INTL_REG3);
if (val & 0x0002)
rt5631->codec_version = 1;
else
rt5631->codec_version = 0;
rt5631_reset(codec);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_VREF | RT5631_PWR_MAIN_BIAS,
RT5631_PWR_VREF | RT5631_PWR_MAIN_BIAS);
msleep(80);
snd_soc_update_bits(codec, RT5631_PWR_MANAG_ADD3,
RT5631_PWR_FAST_VREF_CTRL, RT5631_PWR_FAST_VREF_CTRL);
snd_soc_write(codec, RT5631_INT_ST_IRQ_CTRL_2, 0x0f18);
if (rt5631->codec_version)
snd_soc_update_bits(codec, RT5631_INT_ST_IRQ_CTRL_2,
0x2000, 0x2000);
else
snd_soc_update_bits(codec, RT5631_INT_ST_IRQ_CTRL_2,
0x2000, 0);
if (rt5631->dmic_used_flag) {
snd_soc_update_bits(codec, RT5631_GPIO_CTRL,
RT5631_GPIO_PIN_FUN_SEL_MASK |
RT5631_GPIO_DMIC_FUN_SEL_MASK,
RT5631_GPIO_PIN_FUN_SEL_GPIO_DIMC |
RT5631_GPIO_DMIC_FUN_SEL_DIMC);
snd_soc_update_bits(codec, RT5631_DIG_MIC_CTRL,
RT5631_DMIC_L_CH_LATCH_MASK |
RT5631_DMIC_R_CH_LATCH_MASK,
RT5631_DMIC_L_CH_LATCH_FALLING |
RT5631_DMIC_R_CH_LATCH_RISING);
}
codec->dapm.bias_level = SND_SOC_BIAS_STANDBY;
return 0;
}
static int rt5631_remove(struct snd_soc_codec *codec)
{
rt5631_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int rt5631_suspend(struct snd_soc_codec *codec)
{
rt5631_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int rt5631_resume(struct snd_soc_codec *codec)
{
rt5631_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int rt5631_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5631_priv *rt5631;
int ret;
rt5631 = devm_kzalloc(&i2c->dev, sizeof(struct rt5631_priv),
GFP_KERNEL);
if (NULL == rt5631)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5631);
rt5631->regmap = devm_regmap_init_i2c(i2c, &rt5631_regmap_config);
if (IS_ERR(rt5631->regmap))
return PTR_ERR(rt5631->regmap);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5631,
rt5631_dai, ARRAY_SIZE(rt5631_dai));
return ret;
}
static int rt5631_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
