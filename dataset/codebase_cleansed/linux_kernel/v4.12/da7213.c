static int da7213_get_alc_data(struct snd_soc_codec *codec, u8 reg_val)
{
int mid_data, top_data;
int sum = 0;
u8 iteration;
for (iteration = 0; iteration < DA7213_ALC_AVG_ITERATIONS;
iteration++) {
snd_soc_write(codec, DA7213_ALC_CIC_OP_LVL_CTRL, reg_val);
snd_soc_write(codec, DA7213_ALC_CIC_OP_LVL_CTRL,
reg_val | DA7213_ALC_DATA_MIDDLE);
mid_data = snd_soc_read(codec, DA7213_ALC_CIC_OP_LVL_DATA);
snd_soc_write(codec, DA7213_ALC_CIC_OP_LVL_CTRL,
reg_val | DA7213_ALC_DATA_TOP);
top_data = snd_soc_read(codec, DA7213_ALC_CIC_OP_LVL_DATA);
sum += ((mid_data << 8) | (top_data << 16));
}
return sum / DA7213_ALC_AVG_ITERATIONS;
}
static void da7213_alc_calib_man(struct snd_soc_codec *codec)
{
u8 reg_val;
int avg_left_data, avg_right_data, offset_l, offset_r;
avg_left_data = da7213_get_alc_data(codec,
DA7213_ALC_CIC_OP_CHANNEL_LEFT);
avg_right_data = da7213_get_alc_data(codec,
DA7213_ALC_CIC_OP_CHANNEL_RIGHT);
offset_l = -avg_left_data;
offset_r = -avg_right_data;
reg_val = (offset_l & DA7213_ALC_OFFSET_15_8) >> 8;
snd_soc_write(codec, DA7213_ALC_OFFSET_MAN_M_L, reg_val);
reg_val = (offset_l & DA7213_ALC_OFFSET_19_16) >> 16;
snd_soc_write(codec, DA7213_ALC_OFFSET_MAN_U_L, reg_val);
reg_val = (offset_r & DA7213_ALC_OFFSET_15_8) >> 8;
snd_soc_write(codec, DA7213_ALC_OFFSET_MAN_M_R, reg_val);
reg_val = (offset_r & DA7213_ALC_OFFSET_19_16) >> 16;
snd_soc_write(codec, DA7213_ALC_OFFSET_MAN_U_R, reg_val);
snd_soc_update_bits(codec, DA7213_ALC_CTRL1,
DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE);
}
static void da7213_alc_calib_auto(struct snd_soc_codec *codec)
{
u8 alc_ctrl1;
snd_soc_update_bits(codec, DA7213_ALC_CTRL1, DA7213_ALC_AUTO_CALIB_EN,
DA7213_ALC_AUTO_CALIB_EN);
do {
alc_ctrl1 = snd_soc_read(codec, DA7213_ALC_CTRL1);
} while (alc_ctrl1 & DA7213_ALC_AUTO_CALIB_EN);
if (alc_ctrl1 & DA7213_ALC_CALIB_OVERFLOW) {
dev_warn(codec->dev,
"ALC auto calibration failed with overflow\n");
snd_soc_update_bits(codec, DA7213_ALC_CTRL1,
DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
0);
} else {
snd_soc_update_bits(codec, DA7213_ALC_CTRL1,
DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE,
DA7213_ALC_OFFSET_EN | DA7213_ALC_SYNC_MODE);
}
}
static void da7213_alc_calib(struct snd_soc_codec *codec)
{
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
u8 adc_l_ctrl, adc_r_ctrl;
u8 mixin_l_sel, mixin_r_sel;
u8 mic_1_ctrl, mic_2_ctrl;
adc_l_ctrl = snd_soc_read(codec, DA7213_ADC_L_CTRL);
adc_r_ctrl = snd_soc_read(codec, DA7213_ADC_R_CTRL);
mixin_l_sel = snd_soc_read(codec, DA7213_MIXIN_L_SELECT);
mixin_r_sel = snd_soc_read(codec, DA7213_MIXIN_R_SELECT);
mic_1_ctrl = snd_soc_read(codec, DA7213_MIC_1_CTRL);
mic_2_ctrl = snd_soc_read(codec, DA7213_MIC_2_CTRL);
snd_soc_update_bits(codec, DA7213_ADC_L_CTRL, DA7213_ADC_EN,
DA7213_ADC_EN);
snd_soc_update_bits(codec, DA7213_ADC_R_CTRL, DA7213_ADC_EN,
DA7213_ADC_EN);
snd_soc_update_bits(codec, DA7213_MIXIN_L_SELECT,
DA7213_MIXIN_L_MIX_SELECT_MIC_1 |
DA7213_MIXIN_L_MIX_SELECT_MIC_2,
DA7213_MIXIN_L_MIX_SELECT_MIC_1 |
DA7213_MIXIN_L_MIX_SELECT_MIC_2);
snd_soc_update_bits(codec, DA7213_MIXIN_R_SELECT,
DA7213_MIXIN_R_MIX_SELECT_MIC_2 |
DA7213_MIXIN_R_MIX_SELECT_MIC_1,
DA7213_MIXIN_R_MIX_SELECT_MIC_2 |
DA7213_MIXIN_R_MIX_SELECT_MIC_1);
snd_soc_update_bits(codec, DA7213_MIC_1_CTRL, DA7213_MUTE_EN,
DA7213_MUTE_EN);
snd_soc_update_bits(codec, DA7213_MIC_2_CTRL, DA7213_MUTE_EN,
DA7213_MUTE_EN);
if (da7213->alc_calib_auto)
da7213_alc_calib_auto(codec);
else
da7213_alc_calib_man(codec);
snd_soc_write(codec, DA7213_MIXIN_L_SELECT, mixin_l_sel);
snd_soc_write(codec, DA7213_MIXIN_R_SELECT, mixin_r_sel);
snd_soc_write(codec, DA7213_ADC_L_CTRL, adc_l_ctrl);
snd_soc_write(codec, DA7213_ADC_R_CTRL, adc_r_ctrl);
snd_soc_write(codec, DA7213_MIC_1_CTRL, mic_1_ctrl);
snd_soc_write(codec, DA7213_MIC_2_CTRL, mic_2_ctrl);
}
static int da7213_put_mixin_gain(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_put_volsw_2r(kcontrol, ucontrol);
if ((!ret) && (da7213->alc_en))
da7213_alc_calib(codec);
return ret;
}
static int da7213_put_alc_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
if (ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1]) {
if (!da7213->alc_en) {
da7213_alc_calib(codec);
da7213->alc_en = true;
}
} else {
da7213->alc_en = false;
}
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static int da7213_dai_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, pll_status;
int i = 0;
bool srm_lock = false;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (da7213->master)
snd_soc_update_bits(codec, DA7213_DAI_CLK_MODE,
DA7213_DAI_CLK_EN_MASK,
DA7213_DAI_CLK_EN_MASK);
snd_soc_update_bits(codec, DA7213_PC_COUNT,
DA7213_PC_FREERUN_MASK, 0);
pll_ctrl = snd_soc_read(codec, DA7213_PLL_CTRL);
if (!(pll_ctrl & DA7213_PLL_SRM_EN))
return 0;
if (pll_ctrl & DA7213_PLL_32K_MODE) {
snd_soc_write(codec, 0xF0, 0x8B);
snd_soc_write(codec, 0xF2, 0x03);
snd_soc_write(codec, 0xF0, 0x00);
}
do {
pll_status = snd_soc_read(codec, DA7213_PLL_STATUS);
if (pll_status & DA7219_PLL_SRM_LOCK) {
srm_lock = true;
} else {
++i;
msleep(50);
}
} while ((i < DA7213_SRM_CHECK_RETRIES) && (!srm_lock));
if (!srm_lock)
dev_warn(codec->dev, "SRM failed to lock\n");
return 0;
case SND_SOC_DAPM_POST_PMD:
pll_ctrl = snd_soc_read(codec, DA7213_PLL_CTRL);
if (pll_ctrl & DA7213_PLL_32K_MODE) {
snd_soc_write(codec, 0xF0, 0x8B);
snd_soc_write(codec, 0xF2, 0x01);
snd_soc_write(codec, 0xF0, 0x00);
}
snd_soc_update_bits(codec, DA7213_PC_COUNT,
DA7213_PC_FREERUN_MASK,
DA7213_PC_FREERUN_MASK);
if (da7213->master)
snd_soc_update_bits(codec, DA7213_DAI_CLK_MODE,
DA7213_DAI_CLK_EN_MASK, 0);
return 0;
default:
return -EINVAL;
}
}
static bool da7213_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA7213_STATUS1:
case DA7213_PLL_STATUS:
case DA7213_AUX_L_GAIN_STATUS:
case DA7213_AUX_R_GAIN_STATUS:
case DA7213_MIC_1_GAIN_STATUS:
case DA7213_MIC_2_GAIN_STATUS:
case DA7213_MIXIN_L_GAIN_STATUS:
case DA7213_MIXIN_R_GAIN_STATUS:
case DA7213_ADC_L_GAIN_STATUS:
case DA7213_ADC_R_GAIN_STATUS:
case DA7213_DAC_L_GAIN_STATUS:
case DA7213_DAC_R_GAIN_STATUS:
case DA7213_HP_L_GAIN_STATUS:
case DA7213_HP_R_GAIN_STATUS:
case DA7213_LINE_GAIN_STATUS:
case DA7213_ALC_CTRL1:
case DA7213_ALC_OFFSET_AUTO_M_L:
case DA7213_ALC_OFFSET_AUTO_U_L:
case DA7213_ALC_OFFSET_AUTO_M_R:
case DA7213_ALC_OFFSET_AUTO_U_R:
case DA7213_ALC_CIC_OP_LVL_DATA:
return 1;
default:
return 0;
}
}
static int da7213_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 dai_ctrl = 0;
u8 fs;
switch (params_width(params)) {
case 16:
dai_ctrl |= DA7213_DAI_WORD_LENGTH_S16_LE;
break;
case 20:
dai_ctrl |= DA7213_DAI_WORD_LENGTH_S20_LE;
break;
case 24:
dai_ctrl |= DA7213_DAI_WORD_LENGTH_S24_LE;
break;
case 32:
dai_ctrl |= DA7213_DAI_WORD_LENGTH_S32_LE;
break;
default:
return -EINVAL;
}
switch (params_rate(params)) {
case 8000:
fs = DA7213_SR_8000;
break;
case 11025:
fs = DA7213_SR_11025;
break;
case 12000:
fs = DA7213_SR_12000;
break;
case 16000:
fs = DA7213_SR_16000;
break;
case 22050:
fs = DA7213_SR_22050;
break;
case 32000:
fs = DA7213_SR_32000;
break;
case 44100:
fs = DA7213_SR_44100;
break;
case 48000:
fs = DA7213_SR_48000;
break;
case 88200:
fs = DA7213_SR_88200;
break;
case 96000:
fs = DA7213_SR_96000;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA7213_DAI_CTRL, DA7213_DAI_WORD_LENGTH_MASK,
dai_ctrl);
snd_soc_write(codec, DA7213_SR, fs);
return 0;
}
static int da7213_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
u8 dai_clk_mode = 0, dai_ctrl = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
da7213->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
da7213->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
dai_clk_mode |= DA7213_DAI_WCLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
dai_clk_mode |= DA7213_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
dai_clk_mode |= DA7213_DAI_WCLK_POL_INV | DA7213_DAI_CLK_POL_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dai_ctrl |= DA7213_DAI_FORMAT_I2S_MODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
dai_ctrl |= DA7213_DAI_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
dai_ctrl |= DA7213_DAI_FORMAT_RIGHT_J;
break;
default:
return -EINVAL;
}
dai_clk_mode |= DA7213_DAI_BCLKS_PER_WCLK_64;
snd_soc_write(codec, DA7213_DAI_CLK_MODE, dai_clk_mode);
snd_soc_update_bits(codec, DA7213_DAI_CTRL, DA7213_DAI_FORMAT_MASK,
dai_ctrl);
return 0;
}
static int da7213_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute) {
snd_soc_update_bits(codec, DA7213_DAC_L_CTRL,
DA7213_MUTE_EN, DA7213_MUTE_EN);
snd_soc_update_bits(codec, DA7213_DAC_R_CTRL,
DA7213_MUTE_EN, DA7213_MUTE_EN);
} else {
snd_soc_update_bits(codec, DA7213_DAC_L_CTRL,
DA7213_MUTE_EN, 0);
snd_soc_update_bits(codec, DA7213_DAC_R_CTRL,
DA7213_MUTE_EN, 0);
}
return 0;
}
static int da7213_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
if ((da7213->clk_src == clk_id) && (da7213->mclk_rate == freq))
return 0;
if (((freq < 5000000) && (freq != 32768)) || (freq > 54000000)) {
dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
freq);
return -EINVAL;
}
switch (clk_id) {
case DA7213_CLKSRC_MCLK:
snd_soc_update_bits(codec, DA7213_PLL_CTRL,
DA7213_PLL_MCLK_SQR_EN, 0);
break;
case DA7213_CLKSRC_MCLK_SQR:
snd_soc_update_bits(codec, DA7213_PLL_CTRL,
DA7213_PLL_MCLK_SQR_EN,
DA7213_PLL_MCLK_SQR_EN);
break;
default:
dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
da7213->clk_src = clk_id;
if (da7213->mclk) {
freq = clk_round_rate(da7213->mclk, freq);
ret = clk_set_rate(da7213->mclk, freq);
if (ret) {
dev_err(codec_dai->dev, "Failed to set clock rate %d\n",
freq);
return ret;
}
}
da7213->mclk_rate = freq;
return 0;
}
static int da7213_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int fref, unsigned int fout)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, indiv_bits, indiv;
u8 pll_frac_top, pll_frac_bot, pll_integer;
u32 freq_ref;
u64 frac_div;
if (da7213->mclk_rate == 32768) {
if (!da7213->master) {
dev_err(codec->dev,
"32KHz only valid if codec is clock master\n");
return -EINVAL;
}
indiv_bits = DA7213_PLL_INDIV_9_TO_18_MHZ;
indiv = DA7213_PLL_INDIV_9_TO_18_MHZ_VAL;
source = DA7213_SYSCLK_PLL_32KHZ;
freq_ref = 3750000;
} else {
if (da7213->mclk_rate < 5000000) {
dev_err(codec->dev,
"PLL input clock %d below valid range\n",
da7213->mclk_rate);
return -EINVAL;
} else if (da7213->mclk_rate <= 9000000) {
indiv_bits = DA7213_PLL_INDIV_5_TO_9_MHZ;
indiv = DA7213_PLL_INDIV_5_TO_9_MHZ_VAL;
} else if (da7213->mclk_rate <= 18000000) {
indiv_bits = DA7213_PLL_INDIV_9_TO_18_MHZ;
indiv = DA7213_PLL_INDIV_9_TO_18_MHZ_VAL;
} else if (da7213->mclk_rate <= 36000000) {
indiv_bits = DA7213_PLL_INDIV_18_TO_36_MHZ;
indiv = DA7213_PLL_INDIV_18_TO_36_MHZ_VAL;
} else if (da7213->mclk_rate <= 54000000) {
indiv_bits = DA7213_PLL_INDIV_36_TO_54_MHZ;
indiv = DA7213_PLL_INDIV_36_TO_54_MHZ_VAL;
} else {
dev_err(codec->dev,
"PLL input clock %d above valid range\n",
da7213->mclk_rate);
return -EINVAL;
}
freq_ref = (da7213->mclk_rate / indiv);
}
pll_ctrl = indiv_bits;
switch (source) {
case DA7213_SYSCLK_MCLK:
snd_soc_update_bits(codec, DA7213_PLL_CTRL,
DA7213_PLL_INDIV_MASK |
DA7213_PLL_MODE_MASK, pll_ctrl);
return 0;
case DA7213_SYSCLK_PLL:
break;
case DA7213_SYSCLK_PLL_SRM:
pll_ctrl |= DA7213_PLL_SRM_EN;
fout = DA7213_PLL_FREQ_OUT_94310400;
break;
case DA7213_SYSCLK_PLL_32KHZ:
if (da7213->mclk_rate != 32768) {
dev_err(codec->dev,
"32KHz mode only valid with 32KHz MCLK\n");
return -EINVAL;
}
pll_ctrl |= DA7213_PLL_32K_MODE | DA7213_PLL_SRM_EN;
fout = DA7213_PLL_FREQ_OUT_94310400;
break;
default:
dev_err(codec->dev, "Invalid PLL config\n");
return -EINVAL;
}
pll_integer = fout / freq_ref;
frac_div = (u64)(fout % freq_ref) * 8192ULL;
do_div(frac_div, freq_ref);
pll_frac_top = (frac_div >> DA7213_BYTE_SHIFT) & DA7213_BYTE_MASK;
pll_frac_bot = (frac_div) & DA7213_BYTE_MASK;
snd_soc_write(codec, DA7213_PLL_FRAC_TOP, pll_frac_top);
snd_soc_write(codec, DA7213_PLL_FRAC_BOT, pll_frac_bot);
snd_soc_write(codec, DA7213_PLL_INTEGER, pll_integer);
pll_ctrl |= DA7213_PLL_EN;
snd_soc_update_bits(codec, DA7213_PLL_CTRL,
DA7213_PLL_INDIV_MASK | DA7213_PLL_MODE_MASK,
pll_ctrl);
if (source == DA7213_SYSCLK_PLL_32KHZ) {
snd_soc_write(codec, 0xF0, 0x8B);
snd_soc_write(codec, 0xF1, 0x03);
snd_soc_write(codec, 0xF1, 0x01);
snd_soc_write(codec, 0xF0, 0x00);
}
return 0;
}
static int da7213_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_STANDBY) {
if (da7213->mclk) {
ret = clk_prepare_enable(da7213->mclk);
if (ret) {
dev_err(codec->dev,
"Failed to enable mclk\n");
return ret;
}
}
}
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, DA7213_REFERENCES,
DA7213_VMID_EN | DA7213_BIAS_EN,
DA7213_VMID_EN | DA7213_BIAS_EN);
} else {
if (da7213->mclk)
clk_disable_unprepare(da7213->mclk);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, DA7213_REFERENCES,
DA7213_VMID_EN | DA7213_BIAS_EN, 0);
break;
}
return 0;
}
static enum da7213_micbias_voltage
da7213_of_micbias_lvl(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 1600:
return DA7213_MICBIAS_1_6V;
case 2200:
return DA7213_MICBIAS_2_2V;
case 2500:
return DA7213_MICBIAS_2_5V;
case 3000:
return DA7213_MICBIAS_3_0V;
default:
dev_warn(codec->dev, "Invalid micbias level\n");
return DA7213_MICBIAS_2_2V;
}
}
static enum da7213_dmic_data_sel
da7213_of_dmic_data_sel(struct snd_soc_codec *codec, const char *str)
{
if (!strcmp(str, "lrise_rfall")) {
return DA7213_DMIC_DATA_LRISE_RFALL;
} else if (!strcmp(str, "lfall_rrise")) {
return DA7213_DMIC_DATA_LFALL_RRISE;
} else {
dev_warn(codec->dev, "Invalid DMIC data select type\n");
return DA7213_DMIC_DATA_LRISE_RFALL;
}
}
static enum da7213_dmic_samplephase
da7213_of_dmic_samplephase(struct snd_soc_codec *codec, const char *str)
{
if (!strcmp(str, "on_clkedge")) {
return DA7213_DMIC_SAMPLE_ON_CLKEDGE;
} else if (!strcmp(str, "between_clkedge")) {
return DA7213_DMIC_SAMPLE_BETWEEN_CLKEDGE;
} else {
dev_warn(codec->dev, "Invalid DMIC sample phase\n");
return DA7213_DMIC_SAMPLE_ON_CLKEDGE;
}
}
static enum da7213_dmic_clk_rate
da7213_of_dmic_clkrate(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 1500000:
return DA7213_DMIC_CLK_1_5MHZ;
case 3000000:
return DA7213_DMIC_CLK_3_0MHZ;
default:
dev_warn(codec->dev, "Invalid DMIC clock rate\n");
return DA7213_DMIC_CLK_1_5MHZ;
}
}
static struct da7213_platform_data
*da7213_of_to_pdata(struct snd_soc_codec *codec)
{
struct device_node *np = codec->dev->of_node;
struct da7213_platform_data *pdata;
const char *of_str;
u32 of_val32;
pdata = devm_kzalloc(codec->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_warn(codec->dev, "Failed to allocate memory for pdata\n");
return NULL;
}
if (of_property_read_u32(np, "dlg,micbias1-lvl", &of_val32) >= 0)
pdata->micbias1_lvl = da7213_of_micbias_lvl(codec, of_val32);
else
pdata->micbias1_lvl = DA7213_MICBIAS_2_2V;
if (of_property_read_u32(np, "dlg,micbias2-lvl", &of_val32) >= 0)
pdata->micbias2_lvl = da7213_of_micbias_lvl(codec, of_val32);
else
pdata->micbias2_lvl = DA7213_MICBIAS_2_2V;
if (!of_property_read_string(np, "dlg,dmic-data-sel", &of_str))
pdata->dmic_data_sel = da7213_of_dmic_data_sel(codec, of_str);
else
pdata->dmic_data_sel = DA7213_DMIC_DATA_LRISE_RFALL;
if (!of_property_read_string(np, "dlg,dmic-samplephase", &of_str))
pdata->dmic_samplephase =
da7213_of_dmic_samplephase(codec, of_str);
else
pdata->dmic_samplephase = DA7213_DMIC_SAMPLE_ON_CLKEDGE;
if (of_property_read_u32(np, "dlg,dmic-clkrate", &of_val32) >= 0)
pdata->dmic_clk_rate = da7213_of_dmic_clkrate(codec, of_val32);
else
pdata->dmic_clk_rate = DA7213_DMIC_CLK_3_0MHZ;
return pdata;
}
static int da7213_probe(struct snd_soc_codec *codec)
{
struct da7213_priv *da7213 = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, DA7213_ALC_CTRL1,
DA7213_ALC_CALIB_MODE_MAN, 0);
da7213->alc_calib_auto = true;
snd_soc_update_bits(codec, DA7213_PC_COUNT, DA7213_PC_FREERUN_MASK,
DA7213_PC_FREERUN_MASK);
snd_soc_update_bits(codec, DA7213_AUX_L_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_AUX_R_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_MIXIN_L_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_MIXIN_R_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_ADC_L_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_ADC_R_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_DAC_L_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_DAC_R_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_HP_L_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_HP_R_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_LINE_CTRL,
DA7213_GAIN_RAMP_EN, DA7213_GAIN_RAMP_EN);
snd_soc_update_bits(codec, DA7213_MIXIN_L_CTRL,
DA7213_MIXIN_MIX_EN, DA7213_MIXIN_MIX_EN);
snd_soc_update_bits(codec, DA7213_MIXIN_R_CTRL,
DA7213_MIXIN_MIX_EN, DA7213_MIXIN_MIX_EN);
snd_soc_update_bits(codec, DA7213_MIXOUT_L_CTRL,
DA7213_MIXOUT_MIX_EN, DA7213_MIXOUT_MIX_EN);
snd_soc_update_bits(codec, DA7213_MIXOUT_R_CTRL,
DA7213_MIXOUT_MIX_EN, DA7213_MIXOUT_MIX_EN);
snd_soc_update_bits(codec, DA7213_HP_L_CTRL,
DA7213_HP_AMP_OE, DA7213_HP_AMP_OE);
snd_soc_update_bits(codec, DA7213_HP_R_CTRL,
DA7213_HP_AMP_OE, DA7213_HP_AMP_OE);
snd_soc_update_bits(codec, DA7213_LINE_CTRL,
DA7213_LINE_AMP_OE, DA7213_LINE_AMP_OE);
if (codec->dev->of_node)
da7213->pdata = da7213_of_to_pdata(codec);
else
da7213->pdata = dev_get_platdata(codec->dev);
if (da7213->pdata) {
struct da7213_platform_data *pdata = da7213->pdata;
u8 micbias_lvl = 0, dmic_cfg = 0;
switch (pdata->micbias1_lvl) {
case DA7213_MICBIAS_1_6V:
case DA7213_MICBIAS_2_2V:
case DA7213_MICBIAS_2_5V:
case DA7213_MICBIAS_3_0V:
micbias_lvl |= (pdata->micbias1_lvl <<
DA7213_MICBIAS1_LEVEL_SHIFT);
break;
}
switch (pdata->micbias2_lvl) {
case DA7213_MICBIAS_1_6V:
case DA7213_MICBIAS_2_2V:
case DA7213_MICBIAS_2_5V:
case DA7213_MICBIAS_3_0V:
micbias_lvl |= (pdata->micbias2_lvl <<
DA7213_MICBIAS2_LEVEL_SHIFT);
break;
}
snd_soc_update_bits(codec, DA7213_MICBIAS_CTRL,
DA7213_MICBIAS1_LEVEL_MASK |
DA7213_MICBIAS2_LEVEL_MASK, micbias_lvl);
switch (pdata->dmic_data_sel) {
case DA7213_DMIC_DATA_LFALL_RRISE:
case DA7213_DMIC_DATA_LRISE_RFALL:
dmic_cfg |= (pdata->dmic_data_sel <<
DA7213_DMIC_DATA_SEL_SHIFT);
break;
}
switch (pdata->dmic_samplephase) {
case DA7213_DMIC_SAMPLE_ON_CLKEDGE:
case DA7213_DMIC_SAMPLE_BETWEEN_CLKEDGE:
dmic_cfg |= (pdata->dmic_samplephase <<
DA7213_DMIC_SAMPLEPHASE_SHIFT);
break;
}
switch (pdata->dmic_clk_rate) {
case DA7213_DMIC_CLK_3_0MHZ:
case DA7213_DMIC_CLK_1_5MHZ:
dmic_cfg |= (pdata->dmic_clk_rate <<
DA7213_DMIC_CLK_RATE_SHIFT);
break;
}
snd_soc_update_bits(codec, DA7213_MIC_CONFIG,
DA7213_DMIC_DATA_SEL_MASK |
DA7213_DMIC_SAMPLEPHASE_MASK |
DA7213_DMIC_CLK_RATE_MASK, dmic_cfg);
}
da7213->mclk = devm_clk_get(codec->dev, "mclk");
if (IS_ERR(da7213->mclk)) {
if (PTR_ERR(da7213->mclk) != -ENOENT)
return PTR_ERR(da7213->mclk);
else
da7213->mclk = NULL;
}
return 0;
}
static int da7213_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da7213_priv *da7213;
int ret;
da7213 = devm_kzalloc(&i2c->dev, sizeof(struct da7213_priv),
GFP_KERNEL);
if (!da7213)
return -ENOMEM;
i2c_set_clientdata(i2c, da7213);
da7213->regmap = devm_regmap_init_i2c(i2c, &da7213_regmap_config);
if (IS_ERR(da7213->regmap)) {
ret = PTR_ERR(da7213->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_da7213, &da7213_dai, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register da7213 codec: %d\n",
ret);
}
return ret;
}
static int da7213_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
