static bool rt5670_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5670_ranges); i++) {
if ((reg >= rt5670_ranges[i].window_start &&
reg <= rt5670_ranges[i].window_start +
rt5670_ranges[i].window_len) ||
(reg >= rt5670_ranges[i].range_min &&
reg <= rt5670_ranges[i].range_max)) {
return true;
}
}
switch (reg) {
case RT5670_RESET:
case RT5670_PDM_DATA_CTRL1:
case RT5670_PDM1_DATA_CTRL4:
case RT5670_PDM2_DATA_CTRL4:
case RT5670_PRIV_DATA:
case RT5670_ASRC_5:
case RT5670_CJ_CTRL1:
case RT5670_CJ_CTRL2:
case RT5670_CJ_CTRL3:
case RT5670_A_JD_CTRL1:
case RT5670_A_JD_CTRL2:
case RT5670_VAD_CTRL5:
case RT5670_ADC_EQ_CTRL1:
case RT5670_EQ_CTRL1:
case RT5670_ALC_CTRL_1:
case RT5670_IRQ_CTRL2:
case RT5670_INT_IRQ_ST:
case RT5670_IL_CMD:
case RT5670_DSP_CTRL1:
case RT5670_DSP_CTRL2:
case RT5670_DSP_CTRL3:
case RT5670_DSP_CTRL4:
case RT5670_DSP_CTRL5:
case RT5670_VENDOR_ID:
case RT5670_VENDOR_ID1:
case RT5670_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5670_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5670_ranges); i++) {
if ((reg >= rt5670_ranges[i].window_start &&
reg <= rt5670_ranges[i].window_start +
rt5670_ranges[i].window_len) ||
(reg >= rt5670_ranges[i].range_min &&
reg <= rt5670_ranges[i].range_max)) {
return true;
}
}
switch (reg) {
case RT5670_RESET:
case RT5670_HP_VOL:
case RT5670_LOUT1:
case RT5670_CJ_CTRL1:
case RT5670_CJ_CTRL2:
case RT5670_CJ_CTRL3:
case RT5670_IN2:
case RT5670_INL1_INR1_VOL:
case RT5670_DAC1_DIG_VOL:
case RT5670_DAC2_DIG_VOL:
case RT5670_DAC_CTRL:
case RT5670_STO1_ADC_DIG_VOL:
case RT5670_MONO_ADC_DIG_VOL:
case RT5670_STO2_ADC_DIG_VOL:
case RT5670_ADC_BST_VOL1:
case RT5670_ADC_BST_VOL2:
case RT5670_STO2_ADC_MIXER:
case RT5670_STO1_ADC_MIXER:
case RT5670_MONO_ADC_MIXER:
case RT5670_AD_DA_MIXER:
case RT5670_STO_DAC_MIXER:
case RT5670_DD_MIXER:
case RT5670_DIG_MIXER:
case RT5670_DSP_PATH1:
case RT5670_DSP_PATH2:
case RT5670_DIG_INF1_DATA:
case RT5670_DIG_INF2_DATA:
case RT5670_PDM_OUT_CTRL:
case RT5670_PDM_DATA_CTRL1:
case RT5670_PDM1_DATA_CTRL2:
case RT5670_PDM1_DATA_CTRL3:
case RT5670_PDM1_DATA_CTRL4:
case RT5670_PDM2_DATA_CTRL2:
case RT5670_PDM2_DATA_CTRL3:
case RT5670_PDM2_DATA_CTRL4:
case RT5670_REC_L1_MIXER:
case RT5670_REC_L2_MIXER:
case RT5670_REC_R1_MIXER:
case RT5670_REC_R2_MIXER:
case RT5670_HPO_MIXER:
case RT5670_MONO_MIXER:
case RT5670_OUT_L1_MIXER:
case RT5670_OUT_R1_MIXER:
case RT5670_LOUT_MIXER:
case RT5670_PWR_DIG1:
case RT5670_PWR_DIG2:
case RT5670_PWR_ANLG1:
case RT5670_PWR_ANLG2:
case RT5670_PWR_MIXER:
case RT5670_PWR_VOL:
case RT5670_PRIV_INDEX:
case RT5670_PRIV_DATA:
case RT5670_I2S4_SDP:
case RT5670_I2S1_SDP:
case RT5670_I2S2_SDP:
case RT5670_I2S3_SDP:
case RT5670_ADDA_CLK1:
case RT5670_ADDA_CLK2:
case RT5670_DMIC_CTRL1:
case RT5670_DMIC_CTRL2:
case RT5670_TDM_CTRL_1:
case RT5670_TDM_CTRL_2:
case RT5670_TDM_CTRL_3:
case RT5670_DSP_CLK:
case RT5670_GLB_CLK:
case RT5670_PLL_CTRL1:
case RT5670_PLL_CTRL2:
case RT5670_ASRC_1:
case RT5670_ASRC_2:
case RT5670_ASRC_3:
case RT5670_ASRC_4:
case RT5670_ASRC_5:
case RT5670_ASRC_7:
case RT5670_ASRC_8:
case RT5670_ASRC_9:
case RT5670_ASRC_10:
case RT5670_ASRC_11:
case RT5670_ASRC_12:
case RT5670_ASRC_13:
case RT5670_ASRC_14:
case RT5670_DEPOP_M1:
case RT5670_DEPOP_M2:
case RT5670_DEPOP_M3:
case RT5670_CHARGE_PUMP:
case RT5670_MICBIAS:
case RT5670_A_JD_CTRL1:
case RT5670_A_JD_CTRL2:
case RT5670_VAD_CTRL1:
case RT5670_VAD_CTRL2:
case RT5670_VAD_CTRL3:
case RT5670_VAD_CTRL4:
case RT5670_VAD_CTRL5:
case RT5670_ADC_EQ_CTRL1:
case RT5670_ADC_EQ_CTRL2:
case RT5670_EQ_CTRL1:
case RT5670_EQ_CTRL2:
case RT5670_ALC_DRC_CTRL1:
case RT5670_ALC_DRC_CTRL2:
case RT5670_ALC_CTRL_1:
case RT5670_ALC_CTRL_2:
case RT5670_ALC_CTRL_3:
case RT5670_JD_CTRL:
case RT5670_IRQ_CTRL1:
case RT5670_IRQ_CTRL2:
case RT5670_INT_IRQ_ST:
case RT5670_GPIO_CTRL1:
case RT5670_GPIO_CTRL2:
case RT5670_GPIO_CTRL3:
case RT5670_SCRABBLE_FUN:
case RT5670_SCRABBLE_CTRL:
case RT5670_BASE_BACK:
case RT5670_MP3_PLUS1:
case RT5670_MP3_PLUS2:
case RT5670_ADJ_HPF1:
case RT5670_ADJ_HPF2:
case RT5670_HP_CALIB_AMP_DET:
case RT5670_SV_ZCD1:
case RT5670_SV_ZCD2:
case RT5670_IL_CMD:
case RT5670_IL_CMD2:
case RT5670_IL_CMD3:
case RT5670_DRC_HL_CTRL1:
case RT5670_DRC_HL_CTRL2:
case RT5670_ADC_MONO_HP_CTRL1:
case RT5670_ADC_MONO_HP_CTRL2:
case RT5670_ADC_STO2_HP_CTRL1:
case RT5670_ADC_STO2_HP_CTRL2:
case RT5670_JD_CTRL3:
case RT5670_JD_CTRL4:
case RT5670_DIG_MISC:
case RT5670_DSP_CTRL1:
case RT5670_DSP_CTRL2:
case RT5670_DSP_CTRL3:
case RT5670_DSP_CTRL4:
case RT5670_DSP_CTRL5:
case RT5670_GEN_CTRL2:
case RT5670_GEN_CTRL3:
case RT5670_VENDOR_ID:
case RT5670_VENDOR_ID1:
case RT5670_VENDOR_ID2:
return true;
default:
return false;
}
}
static int rt5670_headset_detect(struct snd_soc_codec *codec, int jack_insert)
{
int val;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
if (jack_insert) {
snd_soc_dapm_force_enable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
snd_soc_update_bits(codec, RT5670_GEN_CTRL3, 0x4, 0x0);
snd_soc_update_bits(codec, RT5670_CJ_CTRL2,
RT5670_CBJ_DET_MODE | RT5670_CBJ_MN_JD,
RT5670_CBJ_MN_JD);
snd_soc_write(codec, RT5670_GPIO_CTRL2, 0x0004);
snd_soc_update_bits(codec, RT5670_GPIO_CTRL1,
RT5670_GP1_PIN_MASK, RT5670_GP1_PIN_IRQ);
snd_soc_update_bits(codec, RT5670_CJ_CTRL1,
RT5670_CBJ_BST1_EN, RT5670_CBJ_BST1_EN);
snd_soc_write(codec, RT5670_JD_CTRL3, 0x00f0);
snd_soc_update_bits(codec, RT5670_CJ_CTRL2,
RT5670_CBJ_MN_JD, RT5670_CBJ_MN_JD);
snd_soc_update_bits(codec, RT5670_CJ_CTRL2,
RT5670_CBJ_MN_JD, 0);
msleep(300);
val = snd_soc_read(codec, RT5670_CJ_CTRL3) & 0x7;
if (val == 0x1 || val == 0x2) {
rt5670->jack_type = SND_JACK_HEADSET;
snd_soc_update_bits(codec, RT5670_INT_IRQ_ST, 0x8, 0x8);
snd_soc_update_bits(codec, RT5670_IL_CMD, 0x40, 0x40);
snd_soc_read(codec, RT5670_IL_CMD);
} else {
snd_soc_update_bits(codec, RT5670_GEN_CTRL3, 0x4, 0x4);
rt5670->jack_type = SND_JACK_HEADPHONE;
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
}
} else {
snd_soc_update_bits(codec, RT5670_INT_IRQ_ST, 0x8, 0x0);
snd_soc_update_bits(codec, RT5670_GEN_CTRL3, 0x4, 0x4);
rt5670->jack_type = 0;
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
}
return rt5670->jack_type;
}
void rt5670_jack_suspend(struct snd_soc_codec *codec)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
rt5670->jack_type_saved = rt5670->jack_type;
rt5670_headset_detect(codec, 0);
}
void rt5670_jack_resume(struct snd_soc_codec *codec)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
if (rt5670->jack_type_saved)
rt5670_headset_detect(codec, 1);
}
static int rt5670_button_detect(struct snd_soc_codec *codec)
{
int btn_type, val;
val = snd_soc_read(codec, RT5670_IL_CMD);
btn_type = val & 0xff80;
snd_soc_write(codec, RT5670_IL_CMD, val);
if (btn_type != 0) {
msleep(20);
val = snd_soc_read(codec, RT5670_IL_CMD);
snd_soc_write(codec, RT5670_IL_CMD, val);
}
return btn_type;
}
static int rt5670_irq_detection(void *data)
{
struct rt5670_priv *rt5670 = (struct rt5670_priv *)data;
struct snd_soc_jack_gpio *gpio = &rt5670->hp_gpio;
struct snd_soc_jack *jack = rt5670->jack;
int val, btn_type, report = jack->status;
if (rt5670->pdata.jd_mode == 1)
val = snd_soc_read(rt5670->codec, RT5670_A_JD_CTRL1) & 0x0070;
else
val = snd_soc_read(rt5670->codec, RT5670_A_JD_CTRL1) & 0x0020;
switch (val) {
case 0x30:
case 0x0:
if (rt5670->jack_type == 0) {
report = rt5670_headset_detect(rt5670->codec, 1);
gpio->debounce_time = 25;
break;
}
btn_type = 0;
if (snd_soc_read(rt5670->codec, RT5670_INT_IRQ_ST) & 0x4) {
report = SND_JACK_HEADSET;
btn_type = rt5670_button_detect(rt5670->codec);
switch (btn_type) {
case 0x2000:
report |= SND_JACK_BTN_1;
break;
case 0x0400:
report |= SND_JACK_BTN_0;
break;
case 0x0080:
report |= SND_JACK_BTN_2;
break;
default:
dev_err(rt5670->codec->dev,
"Unexpected button code 0x%04x\n",
btn_type);
break;
}
}
if (btn_type == 0)
report = rt5670->jack_type;
break;
case 0x70:
case 0x10:
case 0x20:
report = 0;
snd_soc_update_bits(rt5670->codec, RT5670_INT_IRQ_ST, 0x1, 0x0);
rt5670_headset_detect(rt5670->codec, 0);
gpio->debounce_time = 150;
break;
default:
break;
}
return report;
}
int rt5670_set_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
int ret;
rt5670->jack = jack;
rt5670->hp_gpio.gpiod_dev = codec->dev;
rt5670->hp_gpio.name = "headset";
rt5670->hp_gpio.report = SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_BTN_2;
rt5670->hp_gpio.debounce_time = 150;
rt5670->hp_gpio.wake = true;
rt5670->hp_gpio.data = (struct rt5670_priv *)rt5670;
rt5670->hp_gpio.jack_status_check = rt5670_irq_detection;
ret = snd_soc_jack_add_gpios(rt5670->jack, 1,
&rt5670->hp_gpio);
if (ret) {
dev_err(codec->dev, "Adding jack GPIO failed\n");
return ret;
}
return 0;
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
int idx, rate;
rate = rt5670->sysclk / rl6231_get_pre_div(rt5670->regmap,
RT5670_ADDA_CLK1, RT5670_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rate);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
snd_soc_update_bits(codec, RT5670_DMIC_CTRL1,
RT5670_DMIC_CLK_MASK, idx << RT5670_DMIC_CLK_SFT);
return idx;
}
static int is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
if (rt5670->sysclk_src == RT5670_SCLK_S_PLL1)
return 1;
else
return 0;
}
static int is_using_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
unsigned int reg, shift, val;
switch (source->shift) {
case 0:
reg = RT5670_ASRC_3;
shift = 0;
break;
case 1:
reg = RT5670_ASRC_3;
shift = 4;
break;
case 2:
reg = RT5670_ASRC_5;
shift = 12;
break;
case 3:
reg = RT5670_ASRC_2;
shift = 0;
break;
case 8:
reg = RT5670_ASRC_2;
shift = 4;
break;
case 9:
reg = RT5670_ASRC_2;
shift = 8;
break;
case 10:
reg = RT5670_ASRC_2;
shift = 12;
break;
default:
return 0;
}
val = (snd_soc_read(codec, reg) >> shift) & 0xf;
switch (val) {
case 1:
case 2:
case 3:
case 4:
return 1;
default:
return 0;
}
}
static int can_use_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
if (rt5670->sysclk > rt5670->lrck[RT5670_AIF1] * 384)
return 1;
return 0;
}
int rt5670_sel_asrc_clk_src(struct snd_soc_codec *codec,
unsigned int filter_mask, unsigned int clk_src)
{
unsigned int asrc2_mask = 0, asrc2_value = 0;
unsigned int asrc3_mask = 0, asrc3_value = 0;
if (clk_src > RT5670_CLK_SEL_SYS3)
return -EINVAL;
if (filter_mask & RT5670_DA_STEREO_FILTER) {
asrc2_mask |= RT5670_DA_STO_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5670_DA_STO_CLK_SEL_MASK)
| (clk_src << RT5670_DA_STO_CLK_SEL_SFT);
}
if (filter_mask & RT5670_DA_MONO_L_FILTER) {
asrc2_mask |= RT5670_DA_MONOL_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5670_DA_MONOL_CLK_SEL_MASK)
| (clk_src << RT5670_DA_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5670_DA_MONO_R_FILTER) {
asrc2_mask |= RT5670_DA_MONOR_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5670_DA_MONOR_CLK_SEL_MASK)
| (clk_src << RT5670_DA_MONOR_CLK_SEL_SFT);
}
if (filter_mask & RT5670_AD_STEREO_FILTER) {
asrc2_mask |= RT5670_AD_STO1_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5670_AD_STO1_CLK_SEL_MASK)
| (clk_src << RT5670_AD_STO1_CLK_SEL_SFT);
}
if (filter_mask & RT5670_AD_MONO_L_FILTER) {
asrc3_mask |= RT5670_AD_MONOL_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5670_AD_MONOL_CLK_SEL_MASK)
| (clk_src << RT5670_AD_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5670_AD_MONO_R_FILTER) {
asrc3_mask |= RT5670_AD_MONOR_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5670_AD_MONOR_CLK_SEL_MASK)
| (clk_src << RT5670_AD_MONOR_CLK_SEL_SFT);
}
if (filter_mask & RT5670_UP_RATE_FILTER) {
asrc3_mask |= RT5670_UP_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5670_UP_CLK_SEL_MASK)
| (clk_src << RT5670_UP_CLK_SEL_SFT);
}
if (filter_mask & RT5670_DOWN_RATE_FILTER) {
asrc3_mask |= RT5670_DOWN_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5670_DOWN_CLK_SEL_MASK)
| (clk_src << RT5670_DOWN_CLK_SEL_SFT);
}
if (asrc2_mask)
snd_soc_update_bits(codec, RT5670_ASRC_2,
asrc2_mask, asrc2_value);
if (asrc3_mask)
snd_soc_update_bits(codec, RT5670_ASRC_3,
asrc3_mask, asrc3_value);
return 0;
}
static int rt5670_hp_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5670->regmap, RT5670_CHARGE_PUMP,
RT5670_PM_HP_MASK, RT5670_PM_HP_HV);
regmap_update_bits(rt5670->regmap, RT5670_GEN_CTRL2,
0x0400, 0x0400);
regmap_update_bits(rt5670->regmap, RT5670_PWR_ANLG1,
RT5670_PWR_HA | RT5670_PWR_FV1 |
RT5670_PWR_FV2, RT5670_PWR_HA |
RT5670_PWR_FV1 | RT5670_PWR_FV2);
regmap_write(rt5670->regmap, RT5670_DEPOP_M2, 0x3100);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x8009);
regmap_write(rt5670->regmap, RT5670_PR_BASE +
RT5670_HP_DCC_INT1, 0x9f00);
mdelay(20);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x8019);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x0004);
msleep(30);
break;
default:
return 0;
}
return 0;
}
static int rt5670_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_write(rt5670->regmap, RT5670_PR_BASE +
RT5670_MAMP_INT_REG2, 0xb400);
regmap_write(rt5670->regmap, RT5670_DEPOP_M3, 0x0772);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x805d);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x831d);
regmap_update_bits(rt5670->regmap, RT5670_GEN_CTRL2,
0x0300, 0x0300);
regmap_update_bits(rt5670->regmap, RT5670_HP_VOL,
RT5670_L_MUTE | RT5670_R_MUTE, 0);
msleep(80);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x8019);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_write(rt5670->regmap, RT5670_PR_BASE +
RT5670_MAMP_INT_REG2, 0xb400);
regmap_write(rt5670->regmap, RT5670_DEPOP_M3, 0x0772);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x803d);
mdelay(10);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x831d);
mdelay(10);
regmap_update_bits(rt5670->regmap, RT5670_HP_VOL,
RT5670_L_MUTE | RT5670_R_MUTE,
RT5670_L_MUTE | RT5670_R_MUTE);
msleep(20);
regmap_update_bits(rt5670->regmap,
RT5670_GEN_CTRL2, 0x0300, 0x0);
regmap_write(rt5670->regmap, RT5670_DEPOP_M1, 0x8019);
regmap_write(rt5670->regmap, RT5670_DEPOP_M3, 0x0707);
regmap_write(rt5670->regmap, RT5670_PR_BASE +
RT5670_MAMP_INT_REG2, 0xfc00);
break;
default:
return 0;
}
return 0;
}
static int rt5670_bst1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5670_PWR_ANLG2,
RT5670_PWR_BST1_P, RT5670_PWR_BST1_P);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5670_PWR_ANLG2,
RT5670_PWR_BST1_P, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5670_bst2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5670_PWR_ANLG2,
RT5670_PWR_BST2_P, RT5670_PWR_BST2_P);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5670_PWR_ANLG2,
RT5670_PWR_BST2_P, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5670_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, bclk_ms, frame_size;
rt5670->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5670->sysclk, rt5670->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5670->lrck[dai->id], dai->id);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
bclk_ms = frame_size > 32;
rt5670->bclk[dai->id] = rt5670->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5670->bclk[dai->id], rt5670->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5670_I2S_DL_20;
break;
case 24:
val_len |= RT5670_I2S_DL_24;
break;
case 8:
val_len |= RT5670_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5670_AIF1:
mask_clk = RT5670_I2S_BCLK_MS1_MASK | RT5670_I2S_PD1_MASK;
val_clk = bclk_ms << RT5670_I2S_BCLK_MS1_SFT |
pre_div << RT5670_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5670_I2S1_SDP,
RT5670_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5670_ADDA_CLK1, mask_clk, val_clk);
break;
case RT5670_AIF2:
mask_clk = RT5670_I2S_BCLK_MS2_MASK | RT5670_I2S_PD2_MASK;
val_clk = bclk_ms << RT5670_I2S_BCLK_MS2_SFT |
pre_div << RT5670_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5670_I2S2_SDP,
RT5670_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5670_ADDA_CLK1, mask_clk, val_clk);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5670_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5670->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5670_I2S_MS_S;
rt5670->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5670_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5670_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5670_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5670_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5670_AIF1:
snd_soc_update_bits(codec, RT5670_I2S1_SDP,
RT5670_I2S_MS_MASK | RT5670_I2S_BP_MASK |
RT5670_I2S_DF_MASK, reg_val);
break;
case RT5670_AIF2:
snd_soc_update_bits(codec, RT5670_I2S2_SDP,
RT5670_I2S_MS_MASK | RT5670_I2S_BP_MASK |
RT5670_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5670_set_codec_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (clk_id) {
case RT5670_SCLK_S_MCLK:
reg_val |= RT5670_SCLK_SRC_MCLK;
break;
case RT5670_SCLK_S_PLL1:
reg_val |= RT5670_SCLK_SRC_PLL1;
break;
case RT5670_SCLK_S_RCCLK:
reg_val |= RT5670_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5670_GLB_CLK,
RT5670_SCLK_SRC_MASK, reg_val);
rt5670->sysclk = freq;
if (clk_id != RT5670_SCLK_S_RCCLK)
rt5670->sysclk_src = clk_id;
dev_dbg(codec->dev, "Sysclk : %dHz clock id : %d\n", freq, clk_id);
return 0;
}
static int rt5670_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (source == rt5670->pll_src && freq_in == rt5670->pll_in &&
freq_out == rt5670->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5670->pll_in = 0;
rt5670->pll_out = 0;
snd_soc_update_bits(codec, RT5670_GLB_CLK,
RT5670_SCLK_SRC_MASK, RT5670_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5670_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5670_GLB_CLK,
RT5670_PLL1_SRC_MASK, RT5670_PLL1_SRC_MCLK);
break;
case RT5670_PLL1_S_BCLK1:
case RT5670_PLL1_S_BCLK2:
case RT5670_PLL1_S_BCLK3:
case RT5670_PLL1_S_BCLK4:
switch (dai->id) {
case RT5670_AIF1:
snd_soc_update_bits(codec, RT5670_GLB_CLK,
RT5670_PLL1_SRC_MASK, RT5670_PLL1_SRC_BCLK1);
break;
case RT5670_AIF2:
snd_soc_update_bits(codec, RT5670_GLB_CLK,
RT5670_PLL1_SRC_MASK, RT5670_PLL1_SRC_BCLK2);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
break;
default:
dev_err(codec->dev, "Unknown PLL source %d\n", source);
return -EINVAL;
}
ret = rl6231_pll_calc(freq_in, freq_out, &pll_code);
if (ret < 0) {
dev_err(codec->dev, "Unsupport input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "bypass=%d m=%d n=%d k=%d\n",
pll_code.m_bp, (pll_code.m_bp ? 0 : pll_code.m_code),
pll_code.n_code, pll_code.k_code);
snd_soc_write(codec, RT5670_PLL_CTRL1,
pll_code.n_code << RT5670_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5670_PLL_CTRL2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5670_PLL_M_SFT |
pll_code.m_bp << RT5670_PLL_M_BP_SFT);
rt5670->pll_in = freq_in;
rt5670->pll_out = freq_out;
rt5670->pll_src = source;
return 0;
}
static int rt5670_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
if (rx_mask || tx_mask)
val |= (1 << 14);
switch (slots) {
case 4:
val |= (1 << 12);
break;
case 6:
val |= (2 << 12);
break;
case 8:
val |= (3 << 12);
break;
case 2:
break;
default:
return -EINVAL;
}
switch (slot_width) {
case 20:
val |= (1 << 10);
break;
case 24:
val |= (2 << 10);
break;
case 32:
val |= (3 << 10);
break;
case 16:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5670_TDM_CTRL_1, 0x7c00, val);
return 0;
}
static int rt5670_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY == snd_soc_codec_get_bias_level(codec)) {
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_PWR_VREF1 | RT5670_PWR_MB |
RT5670_PWR_BG | RT5670_PWR_VREF2,
RT5670_PWR_VREF1 | RT5670_PWR_MB |
RT5670_PWR_BG | RT5670_PWR_VREF2);
mdelay(10);
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_PWR_FV1 | RT5670_PWR_FV2,
RT5670_PWR_FV1 | RT5670_PWR_FV2);
snd_soc_update_bits(codec, RT5670_CHARGE_PUMP,
RT5670_OSW_L_MASK | RT5670_OSW_R_MASK,
RT5670_OSW_L_DIS | RT5670_OSW_R_DIS);
snd_soc_update_bits(codec, RT5670_DIG_MISC, 0x1, 0x1);
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_LDO_SEL_MASK, 0x5);
}
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_PWR_VREF1 | RT5670_PWR_VREF2 |
RT5670_PWR_FV1 | RT5670_PWR_FV2, 0);
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_LDO_SEL_MASK, 0x3);
break;
case SND_SOC_BIAS_OFF:
if (rt5670->pdata.jd_mode)
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_PWR_VREF1 | RT5670_PWR_MB |
RT5670_PWR_BG | RT5670_PWR_VREF2 |
RT5670_PWR_FV1 | RT5670_PWR_FV2,
RT5670_PWR_MB | RT5670_PWR_BG);
else
snd_soc_update_bits(codec, RT5670_PWR_ANLG1,
RT5670_PWR_VREF1 | RT5670_PWR_MB |
RT5670_PWR_BG | RT5670_PWR_VREF2 |
RT5670_PWR_FV1 | RT5670_PWR_FV2, 0);
snd_soc_update_bits(codec, RT5670_DIG_MISC, 0x1, 0x0);
break;
default:
break;
}
return 0;
}
static int rt5670_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
switch (snd_soc_read(codec, RT5670_RESET) & RT5670_ID_MASK) {
case RT5670_ID_5670:
case RT5670_ID_5671:
snd_soc_dapm_new_controls(dapm,
rt5670_specific_dapm_widgets,
ARRAY_SIZE(rt5670_specific_dapm_widgets));
snd_soc_dapm_add_routes(dapm,
rt5670_specific_dapm_routes,
ARRAY_SIZE(rt5670_specific_dapm_routes));
break;
case RT5670_ID_5672:
snd_soc_dapm_new_controls(dapm,
rt5672_specific_dapm_widgets,
ARRAY_SIZE(rt5672_specific_dapm_widgets));
snd_soc_dapm_add_routes(dapm,
rt5672_specific_dapm_routes,
ARRAY_SIZE(rt5672_specific_dapm_routes));
break;
default:
dev_err(codec->dev,
"The driver is for RT5670 RT5671 or RT5672 only\n");
return -ENODEV;
}
rt5670->codec = codec;
return 0;
}
static int rt5670_remove(struct snd_soc_codec *codec)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5670->regmap, RT5670_RESET, 0);
snd_soc_jack_free_gpios(rt5670->jack, 1, &rt5670->hp_gpio);
return 0;
}
static int rt5670_suspend(struct snd_soc_codec *codec)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5670->regmap, true);
regcache_mark_dirty(rt5670->regmap);
return 0;
}
static int rt5670_resume(struct snd_soc_codec *codec)
{
struct rt5670_priv *rt5670 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5670->regmap, false);
regcache_sync(rt5670->regmap);
return 0;
}
static int rt5670_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5670_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5670_priv *rt5670;
int ret;
unsigned int val;
rt5670 = devm_kzalloc(&i2c->dev,
sizeof(struct rt5670_priv),
GFP_KERNEL);
if (NULL == rt5670)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5670);
if (pdata)
rt5670->pdata = *pdata;
if (dmi_check_system(dmi_platform_intel_braswell)) {
rt5670->pdata.dmic_en = true;
rt5670->pdata.dmic1_data_pin = RT5670_DMIC_DATA_IN2P;
rt5670->pdata.dev_gpio = true;
rt5670->pdata.jd_mode = 1;
} else if (dmi_check_system(dmi_platform_intel_bytcht_jdmode2)) {
rt5670->pdata.dmic_en = true;
rt5670->pdata.dmic1_data_pin = RT5670_DMIC_DATA_IN2P;
rt5670->pdata.dev_gpio = true;
rt5670->pdata.jd_mode = 2;
}
rt5670->regmap = devm_regmap_init_i2c(i2c, &rt5670_regmap);
if (IS_ERR(rt5670->regmap)) {
ret = PTR_ERR(rt5670->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5670->regmap, RT5670_VENDOR_ID2, &val);
if (val != RT5670_DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt5670/72\n", val);
return -ENODEV;
}
regmap_write(rt5670->regmap, RT5670_RESET, 0);
regmap_update_bits(rt5670->regmap, RT5670_PWR_ANLG1,
RT5670_PWR_HP_L | RT5670_PWR_HP_R |
RT5670_PWR_VREF2, RT5670_PWR_VREF2);
msleep(100);
regmap_write(rt5670->regmap, RT5670_RESET, 0);
regmap_read(rt5670->regmap, RT5670_VENDOR_ID, &val);
if (val >= 4)
regmap_write(rt5670->regmap, RT5670_GPIO_CTRL3, 0x0980);
else
regmap_write(rt5670->regmap, RT5670_GPIO_CTRL3, 0x0d00);
ret = regmap_register_patch(rt5670->regmap, init_list,
ARRAY_SIZE(init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
regmap_update_bits(rt5670->regmap, RT5670_DIG_MISC,
RT5670_MCLK_DET, RT5670_MCLK_DET);
if (rt5670->pdata.in2_diff)
regmap_update_bits(rt5670->regmap, RT5670_IN2,
RT5670_IN_DF2, RT5670_IN_DF2);
if (rt5670->pdata.dev_gpio) {
regmap_write(rt5670->regmap, RT5670_IL_CMD, 0x0000);
regmap_write(rt5670->regmap, RT5670_IL_CMD2, 0x0010);
regmap_write(rt5670->regmap, RT5670_IL_CMD3, 0x0014);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP1_PIN_MASK, RT5670_GP1_PIN_IRQ);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL2,
RT5670_GP1_PF_MASK, RT5670_GP1_PF_OUT);
}
if (rt5670->pdata.jd_mode) {
regmap_update_bits(rt5670->regmap, RT5670_GLB_CLK,
RT5670_SCLK_SRC_MASK, RT5670_SCLK_SRC_RCCLK);
rt5670->sysclk = 0;
rt5670->sysclk_src = RT5670_SCLK_S_RCCLK;
regmap_update_bits(rt5670->regmap, RT5670_PWR_ANLG1,
RT5670_PWR_MB, RT5670_PWR_MB);
regmap_update_bits(rt5670->regmap, RT5670_PWR_ANLG2,
RT5670_PWR_JD1, RT5670_PWR_JD1);
regmap_update_bits(rt5670->regmap, RT5670_IRQ_CTRL1,
RT5670_JD1_1_EN_MASK, RT5670_JD1_1_EN);
regmap_update_bits(rt5670->regmap, RT5670_JD_CTRL3,
RT5670_JD_TRI_CBJ_SEL_MASK |
RT5670_JD_TRI_HPO_SEL_MASK,
RT5670_JD_CBJ_JD1_1 | RT5670_JD_HPO_JD1_1);
switch (rt5670->pdata.jd_mode) {
case 1:
regmap_update_bits(rt5670->regmap, RT5670_A_JD_CTRL1,
RT5670_JD1_MODE_MASK,
RT5670_JD1_MODE_0);
break;
case 2:
regmap_update_bits(rt5670->regmap, RT5670_A_JD_CTRL1,
RT5670_JD1_MODE_MASK,
RT5670_JD1_MODE_1);
break;
case 3:
regmap_update_bits(rt5670->regmap, RT5670_A_JD_CTRL1,
RT5670_JD1_MODE_MASK,
RT5670_JD1_MODE_2);
break;
default:
break;
}
}
if (rt5670->pdata.dmic_en) {
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP2_PIN_MASK,
RT5670_GP2_PIN_DMIC1_SCL);
switch (rt5670->pdata.dmic1_data_pin) {
case RT5670_DMIC_DATA_IN2P:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL1,
RT5670_DMIC_1_DP_MASK,
RT5670_DMIC_1_DP_IN2P);
break;
case RT5670_DMIC_DATA_GPIO6:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL1,
RT5670_DMIC_1_DP_MASK,
RT5670_DMIC_1_DP_GPIO6);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP6_PIN_MASK,
RT5670_GP6_PIN_DMIC1_SDA);
break;
case RT5670_DMIC_DATA_GPIO7:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL1,
RT5670_DMIC_1_DP_MASK,
RT5670_DMIC_1_DP_GPIO7);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP7_PIN_MASK,
RT5670_GP7_PIN_DMIC1_SDA);
break;
default:
break;
}
switch (rt5670->pdata.dmic2_data_pin) {
case RT5670_DMIC_DATA_IN3N:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL1,
RT5670_DMIC_2_DP_MASK,
RT5670_DMIC_2_DP_IN3N);
break;
case RT5670_DMIC_DATA_GPIO8:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL1,
RT5670_DMIC_2_DP_MASK,
RT5670_DMIC_2_DP_GPIO8);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP8_PIN_MASK,
RT5670_GP8_PIN_DMIC2_SDA);
break;
default:
break;
}
switch (rt5670->pdata.dmic3_data_pin) {
case RT5670_DMIC_DATA_GPIO5:
regmap_update_bits(rt5670->regmap, RT5670_DMIC_CTRL2,
RT5670_DMIC_3_DP_MASK,
RT5670_DMIC_3_DP_GPIO5);
regmap_update_bits(rt5670->regmap, RT5670_GPIO_CTRL1,
RT5670_GP5_PIN_MASK,
RT5670_GP5_PIN_DMIC3_SDA);
break;
case RT5670_DMIC_DATA_GPIO9:
case RT5670_DMIC_DATA_GPIO10:
dev_err(&i2c->dev,
"Always use GPIO5 as DMIC3 data pin\n");
break;
default:
break;
}
}
pm_runtime_enable(&i2c->dev);
pm_request_idle(&i2c->dev);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5670,
rt5670_dai, ARRAY_SIZE(rt5670_dai));
if (ret < 0)
goto err;
pm_runtime_put(&i2c->dev);
return 0;
err:
pm_runtime_disable(&i2c->dev);
return ret;
}
static int rt5670_i2c_remove(struct i2c_client *i2c)
{
pm_runtime_disable(&i2c->dev);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
