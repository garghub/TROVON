static bool rt5660_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5660_ranges); i++)
if ((reg >= rt5660_ranges[i].window_start &&
reg <= rt5660_ranges[i].window_start +
rt5660_ranges[i].window_len) ||
(reg >= rt5660_ranges[i].range_min &&
reg <= rt5660_ranges[i].range_max))
return true;
switch (reg) {
case RT5660_RESET:
case RT5660_PRIV_DATA:
case RT5660_EQ_CTRL1:
case RT5660_IRQ_CTRL2:
case RT5660_INT_IRQ_ST:
case RT5660_VENDOR_ID:
case RT5660_VENDOR_ID1:
case RT5660_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5660_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5660_ranges); i++)
if ((reg >= rt5660_ranges[i].window_start &&
reg <= rt5660_ranges[i].window_start +
rt5660_ranges[i].window_len) ||
(reg >= rt5660_ranges[i].range_min &&
reg <= rt5660_ranges[i].range_max))
return true;
switch (reg) {
case RT5660_RESET:
case RT5660_SPK_VOL:
case RT5660_LOUT_VOL:
case RT5660_IN1_IN2:
case RT5660_IN3_IN4:
case RT5660_DAC1_DIG_VOL:
case RT5660_STO1_ADC_DIG_VOL:
case RT5660_ADC_BST_VOL1:
case RT5660_STO1_ADC_MIXER:
case RT5660_AD_DA_MIXER:
case RT5660_STO_DAC_MIXER:
case RT5660_DIG_INF1_DATA:
case RT5660_REC_L1_MIXER:
case RT5660_REC_L2_MIXER:
case RT5660_REC_R1_MIXER:
case RT5660_REC_R2_MIXER:
case RT5660_LOUT_MIXER:
case RT5660_SPK_MIXER:
case RT5660_SPO_MIXER:
case RT5660_SPO_CLSD_RATIO:
case RT5660_OUT_L_GAIN1:
case RT5660_OUT_L_GAIN2:
case RT5660_OUT_L1_MIXER:
case RT5660_OUT_R_GAIN1:
case RT5660_OUT_R_GAIN2:
case RT5660_OUT_R1_MIXER:
case RT5660_PWR_DIG1:
case RT5660_PWR_DIG2:
case RT5660_PWR_ANLG1:
case RT5660_PWR_ANLG2:
case RT5660_PWR_MIXER:
case RT5660_PWR_VOL:
case RT5660_PRIV_INDEX:
case RT5660_PRIV_DATA:
case RT5660_I2S1_SDP:
case RT5660_ADDA_CLK1:
case RT5660_ADDA_CLK2:
case RT5660_DMIC_CTRL1:
case RT5660_GLB_CLK:
case RT5660_PLL_CTRL1:
case RT5660_PLL_CTRL2:
case RT5660_CLSD_AMP_OC_CTRL:
case RT5660_CLSD_AMP_CTRL:
case RT5660_LOUT_AMP_CTRL:
case RT5660_SPK_AMP_SPKVDD:
case RT5660_MICBIAS:
case RT5660_CLSD_OUT_CTRL1:
case RT5660_CLSD_OUT_CTRL2:
case RT5660_DIPOLE_MIC_CTRL1:
case RT5660_DIPOLE_MIC_CTRL2:
case RT5660_DIPOLE_MIC_CTRL3:
case RT5660_DIPOLE_MIC_CTRL4:
case RT5660_DIPOLE_MIC_CTRL5:
case RT5660_DIPOLE_MIC_CTRL6:
case RT5660_DIPOLE_MIC_CTRL7:
case RT5660_DIPOLE_MIC_CTRL8:
case RT5660_DIPOLE_MIC_CTRL9:
case RT5660_DIPOLE_MIC_CTRL10:
case RT5660_DIPOLE_MIC_CTRL11:
case RT5660_DIPOLE_MIC_CTRL12:
case RT5660_EQ_CTRL1:
case RT5660_EQ_CTRL2:
case RT5660_DRC_AGC_CTRL1:
case RT5660_DRC_AGC_CTRL2:
case RT5660_DRC_AGC_CTRL3:
case RT5660_DRC_AGC_CTRL4:
case RT5660_DRC_AGC_CTRL5:
case RT5660_JD_CTRL:
case RT5660_IRQ_CTRL1:
case RT5660_IRQ_CTRL2:
case RT5660_INT_IRQ_ST:
case RT5660_GPIO_CTRL1:
case RT5660_GPIO_CTRL2:
case RT5660_WIND_FILTER_CTRL1:
case RT5660_SV_ZCD1:
case RT5660_SV_ZCD2:
case RT5660_DRC1_LM_CTRL1:
case RT5660_DRC1_LM_CTRL2:
case RT5660_DRC2_LM_CTRL1:
case RT5660_DRC2_LM_CTRL2:
case RT5660_MULTI_DRC_CTRL:
case RT5660_DRC2_CTRL1:
case RT5660_DRC2_CTRL2:
case RT5660_DRC2_CTRL3:
case RT5660_DRC2_CTRL4:
case RT5660_DRC2_CTRL5:
case RT5660_ALC_PGA_CTRL1:
case RT5660_ALC_PGA_CTRL2:
case RT5660_ALC_PGA_CTRL3:
case RT5660_ALC_PGA_CTRL4:
case RT5660_ALC_PGA_CTRL5:
case RT5660_ALC_PGA_CTRL6:
case RT5660_ALC_PGA_CTRL7:
case RT5660_GEN_CTRL1:
case RT5660_GEN_CTRL2:
case RT5660_GEN_CTRL3:
case RT5660_VENDOR_ID:
case RT5660_VENDOR_ID1:
case RT5660_VENDOR_ID2:
return true;
default:
return false;
}
}
static int rt5660_set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
int idx, rate;
rate = rt5660->sysclk / rl6231_get_pre_div(rt5660->regmap,
RT5660_ADDA_CLK1, RT5660_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rate);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
snd_soc_update_bits(codec, RT5660_DMIC_CTRL1,
RT5660_DMIC_CLK_MASK, idx << RT5660_DMIC_CLK_SFT);
return idx;
}
static int rt5660_is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
unsigned int val;
val = snd_soc_read(codec, RT5660_GLB_CLK);
val &= RT5660_SCLK_SRC_MASK;
if (val == RT5660_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int rt5660_lout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5660_LOUT_AMP_CTRL,
RT5660_LOUT_CO_MASK | RT5660_LOUT_CB_MASK,
RT5660_LOUT_CO_EN | RT5660_LOUT_CB_PU);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5660_LOUT_AMP_CTRL,
RT5660_LOUT_CO_MASK | RT5660_LOUT_CB_MASK,
RT5660_LOUT_CO_DIS | RT5660_LOUT_CB_PD);
break;
default:
return 0;
}
return 0;
}
static int rt5660_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, bclk_ms, frame_size;
rt5660->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5660->sysclk, rt5660->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5660->lrck[dai->id], dai->id);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return frame_size;
}
if (frame_size > 32)
bclk_ms = 1;
else
bclk_ms = 0;
rt5660->bclk[dai->id] = rt5660->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5660->bclk[dai->id], rt5660->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5660_I2S_DL_20;
break;
case 24:
val_len |= RT5660_I2S_DL_24;
break;
case 8:
val_len |= RT5660_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5660_AIF1:
mask_clk = RT5660_I2S_BCLK_MS1_MASK | RT5660_I2S_PD1_MASK;
val_clk = bclk_ms << RT5660_I2S_BCLK_MS1_SFT |
pre_div << RT5660_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5660_I2S1_SDP, RT5660_I2S_DL_MASK,
val_len);
snd_soc_update_bits(codec, RT5660_ADDA_CLK1, mask_clk, val_clk);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5660_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5660->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5660_I2S_MS_S;
rt5660->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5660_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5660_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5660_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5660_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5660_AIF1:
snd_soc_update_bits(codec, RT5660_I2S1_SDP,
RT5660_I2S_MS_MASK | RT5660_I2S_BP_MASK |
RT5660_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5660_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5660->sysclk && clk_id == rt5660->sysclk_src)
return 0;
switch (clk_id) {
case RT5660_SCLK_S_MCLK:
reg_val |= RT5660_SCLK_SRC_MCLK;
break;
case RT5660_SCLK_S_PLL1:
reg_val |= RT5660_SCLK_SRC_PLL1;
break;
case RT5660_SCLK_S_RCCLK:
reg_val |= RT5660_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5660_GLB_CLK, RT5660_SCLK_SRC_MASK,
reg_val);
rt5660->sysclk = freq;
rt5660->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5660_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (source == rt5660->pll_src && freq_in == rt5660->pll_in &&
freq_out == rt5660->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5660->pll_in = 0;
rt5660->pll_out = 0;
snd_soc_update_bits(codec, RT5660_GLB_CLK,
RT5660_SCLK_SRC_MASK, RT5660_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5660_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5660_GLB_CLK,
RT5660_PLL1_SRC_MASK, RT5660_PLL1_SRC_MCLK);
break;
case RT5660_PLL1_S_BCLK:
snd_soc_update_bits(codec, RT5660_GLB_CLK,
RT5660_PLL1_SRC_MASK, RT5660_PLL1_SRC_BCLK1);
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
snd_soc_write(codec, RT5660_PLL_CTRL1,
pll_code.n_code << RT5660_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5660_PLL_CTRL2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5660_PLL_M_SFT |
pll_code.m_bp << RT5660_PLL_M_BP_SFT);
rt5660->pll_in = freq_in;
rt5660->pll_out = freq_out;
rt5660->pll_src = source;
return 0;
}
static int rt5660_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, RT5660_GEN_CTRL1,
RT5660_DIG_GATE_CTRL, RT5660_DIG_GATE_CTRL);
if (IS_ERR(rt5660->mclk))
break;
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_ON) {
clk_disable_unprepare(rt5660->mclk);
} else {
ret = clk_prepare_enable(rt5660->mclk);
if (ret)
return ret;
}
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, RT5660_PWR_ANLG1,
RT5660_PWR_VREF1 | RT5660_PWR_MB |
RT5660_PWR_BG | RT5660_PWR_VREF2,
RT5660_PWR_VREF1 | RT5660_PWR_MB |
RT5660_PWR_BG | RT5660_PWR_VREF2);
usleep_range(10000, 15000);
snd_soc_update_bits(codec, RT5660_PWR_ANLG1,
RT5660_PWR_FV1 | RT5660_PWR_FV2,
RT5660_PWR_FV1 | RT5660_PWR_FV2);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, RT5660_GEN_CTRL1,
RT5660_DIG_GATE_CTRL, 0);
break;
default:
break;
}
return 0;
}
static int rt5660_probe(struct snd_soc_codec *codec)
{
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
rt5660->codec = codec;
return 0;
}
static int rt5660_remove(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, RT5660_RESET, 0);
}
static int rt5660_suspend(struct snd_soc_codec *codec)
{
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5660->regmap, true);
regcache_mark_dirty(rt5660->regmap);
return 0;
}
static int rt5660_resume(struct snd_soc_codec *codec)
{
struct rt5660_priv *rt5660 = snd_soc_codec_get_drvdata(codec);
if (rt5660->pdata.poweroff_codec_in_suspend)
usleep_range(350000, 400000);
regcache_cache_only(rt5660->regmap, false);
regcache_sync(rt5660->regmap);
return 0;
}
static int rt5660_parse_dt(struct rt5660_priv *rt5660, struct device *dev)
{
rt5660->pdata.in1_diff = device_property_read_bool(dev,
"realtek,in1-differential");
rt5660->pdata.in3_diff = device_property_read_bool(dev,
"realtek,in3-differential");
rt5660->pdata.poweroff_codec_in_suspend = device_property_read_bool(dev,
"realtek,poweroff-in-suspend");
device_property_read_u32(dev, "realtek,dmic1-data-pin",
&rt5660->pdata.dmic1_data_pin);
return 0;
}
static int rt5660_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5660_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5660_priv *rt5660;
int ret;
unsigned int val;
rt5660 = devm_kzalloc(&i2c->dev, sizeof(struct rt5660_priv),
GFP_KERNEL);
if (rt5660 == NULL)
return -ENOMEM;
rt5660->mclk = devm_clk_get(&i2c->dev, "mclk");
if (PTR_ERR(rt5660->mclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
i2c_set_clientdata(i2c, rt5660);
if (pdata)
rt5660->pdata = *pdata;
else if (i2c->dev.of_node)
rt5660_parse_dt(rt5660, &i2c->dev);
rt5660->regmap = devm_regmap_init_i2c(i2c, &rt5660_regmap);
if (IS_ERR(rt5660->regmap)) {
ret = PTR_ERR(rt5660->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5660->regmap, RT5660_VENDOR_ID2, &val);
if (val != RT5660_DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt5660\n", val);
return -ENODEV;
}
regmap_write(rt5660->regmap, RT5660_RESET, 0);
ret = regmap_register_patch(rt5660->regmap, rt5660_patch,
ARRAY_SIZE(rt5660_patch));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
regmap_update_bits(rt5660->regmap, RT5660_GEN_CTRL1,
RT5660_AUTO_DIS_AMP | RT5660_MCLK_DET | RT5660_POW_CLKDET,
RT5660_AUTO_DIS_AMP | RT5660_MCLK_DET | RT5660_POW_CLKDET);
if (rt5660->pdata.dmic1_data_pin) {
regmap_update_bits(rt5660->regmap, RT5660_GPIO_CTRL1,
RT5660_GP1_PIN_MASK, RT5660_GP1_PIN_DMIC1_SCL);
if (rt5660->pdata.dmic1_data_pin == RT5660_DMIC1_DATA_GPIO2)
regmap_update_bits(rt5660->regmap, RT5660_DMIC_CTRL1,
RT5660_SEL_DMIC_DATA_MASK,
RT5660_SEL_DMIC_DATA_GPIO2);
else if (rt5660->pdata.dmic1_data_pin == RT5660_DMIC1_DATA_IN1P)
regmap_update_bits(rt5660->regmap, RT5660_DMIC_CTRL1,
RT5660_SEL_DMIC_DATA_MASK,
RT5660_SEL_DMIC_DATA_IN1P);
}
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5660,
rt5660_dai, ARRAY_SIZE(rt5660_dai));
}
static int rt5660_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
