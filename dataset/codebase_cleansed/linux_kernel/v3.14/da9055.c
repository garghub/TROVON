static int da9055_get_alc_data(struct snd_soc_codec *codec, u8 reg_val)
{
int mid_data, top_data;
int sum = 0;
u8 iteration;
for (iteration = 0; iteration < DA9055_ALC_AVG_ITERATIONS;
iteration++) {
snd_soc_write(codec, DA9055_ALC_CIC_OP_LVL_CTRL, reg_val);
snd_soc_write(codec, DA9055_ALC_CIC_OP_LVL_CTRL,
reg_val | DA9055_ALC_DATA_MIDDLE);
mid_data = snd_soc_read(codec, DA9055_ALC_CIC_OP_LVL_DATA);
snd_soc_write(codec, DA9055_ALC_CIC_OP_LVL_CTRL,
reg_val | DA9055_ALC_DATA_TOP);
top_data = snd_soc_read(codec, DA9055_ALC_CIC_OP_LVL_DATA);
sum += ((mid_data << 8) | (top_data << 16));
}
return sum / DA9055_ALC_AVG_ITERATIONS;
}
static int da9055_put_alc_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
u8 reg_val, adc_left, adc_right, mic_left, mic_right;
int avg_left_data, avg_right_data, offset_l, offset_r;
if (ucontrol->value.integer.value[0]) {
mic_left = snd_soc_read(codec, DA9055_MIC_L_CTRL);
mic_right = snd_soc_read(codec, DA9055_MIC_R_CTRL);
snd_soc_update_bits(codec, DA9055_MIC_L_CTRL,
DA9055_MIC_L_MUTE_EN, DA9055_MIC_L_MUTE_EN);
snd_soc_update_bits(codec, DA9055_MIC_R_CTRL,
DA9055_MIC_R_MUTE_EN, DA9055_MIC_R_MUTE_EN);
adc_left = snd_soc_read(codec, DA9055_ADC_L_CTRL);
adc_right = snd_soc_read(codec, DA9055_ADC_R_CTRL);
snd_soc_update_bits(codec, DA9055_ADC_L_CTRL,
DA9055_ADC_L_EN, DA9055_ADC_L_EN);
snd_soc_update_bits(codec, DA9055_ADC_R_CTRL,
DA9055_ADC_R_EN, DA9055_ADC_R_EN);
avg_left_data = da9055_get_alc_data(codec,
DA9055_ALC_CIC_OP_CHANNEL_LEFT);
avg_right_data = da9055_get_alc_data(codec,
DA9055_ALC_CIC_OP_CHANNEL_RIGHT);
offset_l = -avg_left_data;
offset_r = -avg_right_data;
reg_val = (offset_l & DA9055_ALC_OFFSET_15_8) >> 8;
snd_soc_write(codec, DA9055_ALC_OFFSET_OP2M_L, reg_val);
reg_val = (offset_l & DA9055_ALC_OFFSET_17_16) >> 16;
snd_soc_write(codec, DA9055_ALC_OFFSET_OP2U_L, reg_val);
reg_val = (offset_r & DA9055_ALC_OFFSET_15_8) >> 8;
snd_soc_write(codec, DA9055_ALC_OFFSET_OP2M_R, reg_val);
reg_val = (offset_r & DA9055_ALC_OFFSET_17_16) >> 16;
snd_soc_write(codec, DA9055_ALC_OFFSET_OP2U_R, reg_val);
snd_soc_write(codec, DA9055_ADC_L_CTRL, adc_left);
snd_soc_write(codec, DA9055_ADC_R_CTRL, adc_right);
snd_soc_write(codec, DA9055_MIC_L_CTRL, mic_left);
snd_soc_write(codec, DA9055_MIC_R_CTRL, mic_right);
}
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static bool da9055_volatile_register(struct device *dev,
unsigned int reg)
{
switch (reg) {
case DA9055_STATUS1:
case DA9055_PLL_STATUS:
case DA9055_AUX_L_GAIN_STATUS:
case DA9055_AUX_R_GAIN_STATUS:
case DA9055_MIC_L_GAIN_STATUS:
case DA9055_MIC_R_GAIN_STATUS:
case DA9055_MIXIN_L_GAIN_STATUS:
case DA9055_MIXIN_R_GAIN_STATUS:
case DA9055_ADC_L_GAIN_STATUS:
case DA9055_ADC_R_GAIN_STATUS:
case DA9055_DAC_L_GAIN_STATUS:
case DA9055_DAC_R_GAIN_STATUS:
case DA9055_HP_L_GAIN_STATUS:
case DA9055_HP_R_GAIN_STATUS:
case DA9055_LINE_GAIN_STATUS:
case DA9055_ALC_CIC_OP_LVL_DATA:
return 1;
default:
return 0;
}
}
static int da9055_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct da9055_priv *da9055 = snd_soc_codec_get_drvdata(codec);
u8 aif_ctrl, fs;
u32 sysclk;
switch (params_width(params)) {
case 16:
aif_ctrl = DA9055_AIF_WORD_S16_LE;
break;
case 20:
aif_ctrl = DA9055_AIF_WORD_S20_3LE;
break;
case 24:
aif_ctrl = DA9055_AIF_WORD_S24_LE;
break;
case 32:
aif_ctrl = DA9055_AIF_WORD_S32_LE;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA9055_AIF_CTRL, DA9055_AIF_WORD_LENGTH_MASK,
aif_ctrl);
switch (params_rate(params)) {
case 8000:
fs = DA9055_SR_8000;
sysclk = 3072000;
break;
case 11025:
fs = DA9055_SR_11025;
sysclk = 2822400;
break;
case 12000:
fs = DA9055_SR_12000;
sysclk = 3072000;
break;
case 16000:
fs = DA9055_SR_16000;
sysclk = 3072000;
break;
case 22050:
fs = DA9055_SR_22050;
sysclk = 2822400;
break;
case 32000:
fs = DA9055_SR_32000;
sysclk = 3072000;
break;
case 44100:
fs = DA9055_SR_44100;
sysclk = 2822400;
break;
case 48000:
fs = DA9055_SR_48000;
sysclk = 3072000;
break;
case 88200:
fs = DA9055_SR_88200;
sysclk = 2822400;
break;
case 96000:
fs = DA9055_SR_96000;
sysclk = 3072000;
break;
default:
return -EINVAL;
}
if (da9055->mclk_rate) {
snd_soc_write(codec, DA9055_SR, fs);
} else {
snd_soc_write(codec, DA9055_SR, DA9055_SR_48000);
}
if (da9055->mclk_rate && (da9055->mclk_rate != sysclk)) {
if (!da9055->master) {
snd_soc_update_bits(codec, DA9055_PLL_CTRL,
DA9055_PLL_EN | DA9055_PLL_SRM_EN,
DA9055_PLL_EN | DA9055_PLL_SRM_EN);
} else {
snd_soc_update_bits(codec, DA9055_PLL_CTRL,
DA9055_PLL_EN, DA9055_PLL_EN);
}
} else {
snd_soc_update_bits(codec, DA9055_PLL_CTRL, DA9055_PLL_EN, 0);
}
return 0;
}
static int da9055_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da9055_priv *da9055 = snd_soc_codec_get_drvdata(codec);
u8 aif_clk_mode, aif_ctrl, mode;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
mode = 1;
aif_clk_mode = DA9055_AIF_CLK_EN_MASTER_MODE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
mode = 0;
aif_clk_mode = DA9055_AIF_CLK_EN_SLAVE_MODE;
break;
default:
return -EINVAL;
}
if ((snd_soc_read(codec, DA9055_PLL_CTRL) & DA9055_PLL_EN) &&
(da9055->master != mode))
return -EINVAL;
da9055->master = mode;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
aif_ctrl = DA9055_AIF_FORMAT_I2S_MODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
aif_ctrl = DA9055_AIF_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
aif_ctrl = DA9055_AIF_FORMAT_RIGHT_J;
break;
case SND_SOC_DAIFMT_DSP_A:
aif_ctrl = DA9055_AIF_FORMAT_DSP;
break;
default:
return -EINVAL;
}
aif_clk_mode |= DA9055_AIF_BCLKS_PER_WCLK_32;
snd_soc_update_bits(codec, DA9055_AIF_CLK_MODE,
(DA9055_AIF_CLK_MODE_MASK | DA9055_AIF_BCLK_MASK),
aif_clk_mode);
snd_soc_update_bits(codec, DA9055_AIF_CTRL, DA9055_AIF_FORMAT_MASK,
aif_ctrl);
return 0;
}
static int da9055_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute) {
snd_soc_update_bits(codec, DA9055_DAC_L_CTRL,
DA9055_DAC_L_MUTE_EN, DA9055_DAC_L_MUTE_EN);
snd_soc_update_bits(codec, DA9055_DAC_R_CTRL,
DA9055_DAC_R_MUTE_EN, DA9055_DAC_R_MUTE_EN);
} else {
snd_soc_update_bits(codec, DA9055_DAC_L_CTRL,
DA9055_DAC_L_MUTE_EN, 0);
snd_soc_update_bits(codec, DA9055_DAC_R_CTRL,
DA9055_DAC_R_MUTE_EN, 0);
}
return 0;
}
static int da9055_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da9055_priv *da9055 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case DA9055_CLKSRC_MCLK:
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 13000000:
case 13500000:
case 14400000:
case 19200000:
case 19680000:
case 19800000:
da9055->mclk_rate = freq;
return 0;
default:
dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
freq);
return -EINVAL;
}
break;
default:
dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
}
static int da9055_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int fref, unsigned int fout)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da9055_priv *da9055 = snd_soc_codec_get_drvdata(codec);
u8 pll_frac_top, pll_frac_bot, pll_integer, cnt;
snd_soc_update_bits(codec, DA9055_PLL_CTRL, DA9055_PLL_EN, 0);
if (!da9055->master && (fout != 2822400))
goto pll_err;
for (cnt = 0; cnt < ARRAY_SIZE(da9055_pll_div); cnt++) {
if ((fref == da9055_pll_div[cnt].fref) &&
(da9055->master == da9055_pll_div[cnt].mode) &&
(fout == da9055_pll_div[cnt].fout)) {
pll_frac_top = da9055_pll_div[cnt].frac_top;
pll_frac_bot = da9055_pll_div[cnt].frac_bot;
pll_integer = da9055_pll_div[cnt].integer;
break;
}
}
if (cnt >= ARRAY_SIZE(da9055_pll_div))
goto pll_err;
snd_soc_write(codec, DA9055_PLL_FRAC_TOP, pll_frac_top);
snd_soc_write(codec, DA9055_PLL_FRAC_BOT, pll_frac_bot);
snd_soc_write(codec, DA9055_PLL_INTEGER, pll_integer);
return 0;
pll_err:
dev_err(codec_dai->dev, "Error in setting up PLL\n");
return -EINVAL;
}
static int da9055_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, DA9055_REFERENCES,
DA9055_VMID_EN | DA9055_BIAS_EN,
DA9055_VMID_EN | DA9055_BIAS_EN);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, DA9055_REFERENCES,
DA9055_VMID_EN | DA9055_BIAS_EN, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int da9055_probe(struct snd_soc_codec *codec)
{
int ret;
struct da9055_priv *da9055 = snd_soc_codec_get_drvdata(codec);
codec->control_data = da9055->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, DA9055_AUX_L_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_AUX_R_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_MIXIN_L_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_MIXIN_R_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_ADC_L_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_ADC_R_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_DAC_L_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_DAC_R_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_HP_L_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_HP_R_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_LINE_CTRL,
DA9055_GAIN_RAMPING_EN, DA9055_GAIN_RAMPING_EN);
snd_soc_update_bits(codec, DA9055_MIXIN_L_CTRL,
DA9055_MIXIN_L_MIX_EN, DA9055_MIXIN_L_MIX_EN);
snd_soc_update_bits(codec, DA9055_MIXIN_R_CTRL,
DA9055_MIXIN_R_MIX_EN, DA9055_MIXIN_R_MIX_EN);
snd_soc_update_bits(codec, DA9055_MIXOUT_L_CTRL,
DA9055_MIXOUT_L_MIX_EN, DA9055_MIXOUT_L_MIX_EN);
snd_soc_update_bits(codec, DA9055_MIXOUT_R_CTRL,
DA9055_MIXOUT_R_MIX_EN, DA9055_MIXOUT_R_MIX_EN);
snd_soc_write(codec, DA9055_PLL_CTRL, DA9055_PLL_INDIV_10_20_MHZ);
if (da9055->pdata) {
if (da9055->pdata->micbias_source) {
snd_soc_update_bits(codec, DA9055_MIXIN_R_SELECT,
DA9055_MICBIAS2_EN,
DA9055_MICBIAS2_EN);
} else {
snd_soc_update_bits(codec, DA9055_MIXIN_R_SELECT,
DA9055_MICBIAS2_EN, 0);
}
switch (da9055->pdata->micbias) {
case DA9055_MICBIAS_2_2V:
case DA9055_MICBIAS_2_1V:
case DA9055_MICBIAS_1_8V:
case DA9055_MICBIAS_1_6V:
snd_soc_update_bits(codec, DA9055_MIC_CONFIG,
DA9055_MICBIAS_LEVEL_MASK,
(da9055->pdata->micbias) << 4);
break;
}
}
return 0;
}
static int da9055_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9055_priv *da9055;
struct da9055_platform_data *pdata = dev_get_platdata(&i2c->dev);
int ret;
da9055 = devm_kzalloc(&i2c->dev, sizeof(struct da9055_priv),
GFP_KERNEL);
if (!da9055)
return -ENOMEM;
if (pdata)
da9055->pdata = pdata;
i2c_set_clientdata(i2c, da9055);
da9055->regmap = devm_regmap_init_i2c(i2c, &da9055_regmap_config);
if (IS_ERR(da9055->regmap)) {
ret = PTR_ERR(da9055->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_da9055, &da9055_dai, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register da9055 codec: %d\n",
ret);
}
return ret;
}
static int da9055_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
