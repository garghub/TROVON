static void rt5514_enable_dsp_prepare(struct rt5514_priv *rt5514)
{
regmap_write(rt5514->i2c_regmap, 0x18002000, 0x000010ec);
regmap_write(rt5514->i2c_regmap, 0x18002200, 0x00028604);
regmap_write(rt5514->i2c_regmap, 0xfafafafa, 0x00000001);
regmap_write(rt5514->i2c_regmap, 0x18002f00, 0x0005514b);
regmap_write(rt5514->i2c_regmap, 0x18002f00, 0x00055149);
regmap_write(rt5514->i2c_regmap, 0xfafafafa, 0x00000000);
regmap_write(rt5514->i2c_regmap, 0x18002070, 0x00000040);
regmap_write(rt5514->i2c_regmap, 0x18002240, 0x0000000a);
regmap_write(rt5514->i2c_regmap, 0x18002100, 0x0000000b);
regmap_write(rt5514->i2c_regmap, 0x18002004, 0x00808b81);
regmap_write(rt5514->i2c_regmap, 0x18002f08, 0x00000005);
regmap_write(rt5514->i2c_regmap, 0x18001114, 0x00000001);
regmap_write(rt5514->i2c_regmap, 0x18001118, 0x00000001);
}
static bool rt5514_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5514_VENDOR_ID1:
case RT5514_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5514_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5514_RESET:
case RT5514_PWR_ANA1:
case RT5514_PWR_ANA2:
case RT5514_I2S_CTRL1:
case RT5514_I2S_CTRL2:
case RT5514_VAD_CTRL6:
case RT5514_EXT_VAD_CTRL:
case RT5514_DIG_IO_CTRL:
case RT5514_PAD_CTRL1:
case RT5514_DMIC_DATA_CTRL:
case RT5514_DIG_SOURCE_CTRL:
case RT5514_SRC_CTRL:
case RT5514_DOWNFILTER2_CTRL1:
case RT5514_PLL_SOURCE_CTRL:
case RT5514_CLK_CTRL1:
case RT5514_CLK_CTRL2:
case RT5514_PLL3_CALIB_CTRL1:
case RT5514_PLL3_CALIB_CTRL5:
case RT5514_DELAY_BUF_CTRL1:
case RT5514_DELAY_BUF_CTRL3:
case RT5514_DOWNFILTER0_CTRL1:
case RT5514_DOWNFILTER0_CTRL2:
case RT5514_DOWNFILTER0_CTRL3:
case RT5514_DOWNFILTER1_CTRL1:
case RT5514_DOWNFILTER1_CTRL2:
case RT5514_DOWNFILTER1_CTRL3:
case RT5514_ANA_CTRL_LDO10:
case RT5514_ANA_CTRL_LDO18_16:
case RT5514_ANA_CTRL_ADC12:
case RT5514_ANA_CTRL_ADC21:
case RT5514_ANA_CTRL_ADC22:
case RT5514_ANA_CTRL_ADC23:
case RT5514_ANA_CTRL_MICBST:
case RT5514_ANA_CTRL_ADCFED:
case RT5514_ANA_CTRL_INBUF:
case RT5514_ANA_CTRL_VREF:
case RT5514_ANA_CTRL_PLL3:
case RT5514_ANA_CTRL_PLL1_1:
case RT5514_ANA_CTRL_PLL1_2:
case RT5514_DMIC_LP_CTRL:
case RT5514_MISC_CTRL_DSP:
case RT5514_DSP_CTRL1:
case RT5514_DSP_CTRL3:
case RT5514_DSP_CTRL4:
case RT5514_VENDOR_ID1:
case RT5514_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5514_i2c_readable_register(struct device *dev,
unsigned int reg)
{
switch (reg) {
case RT5514_DSP_MAPPING | RT5514_RESET:
case RT5514_DSP_MAPPING | RT5514_PWR_ANA1:
case RT5514_DSP_MAPPING | RT5514_PWR_ANA2:
case RT5514_DSP_MAPPING | RT5514_I2S_CTRL1:
case RT5514_DSP_MAPPING | RT5514_I2S_CTRL2:
case RT5514_DSP_MAPPING | RT5514_VAD_CTRL6:
case RT5514_DSP_MAPPING | RT5514_EXT_VAD_CTRL:
case RT5514_DSP_MAPPING | RT5514_DIG_IO_CTRL:
case RT5514_DSP_MAPPING | RT5514_PAD_CTRL1:
case RT5514_DSP_MAPPING | RT5514_DMIC_DATA_CTRL:
case RT5514_DSP_MAPPING | RT5514_DIG_SOURCE_CTRL:
case RT5514_DSP_MAPPING | RT5514_SRC_CTRL:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER2_CTRL1:
case RT5514_DSP_MAPPING | RT5514_PLL_SOURCE_CTRL:
case RT5514_DSP_MAPPING | RT5514_CLK_CTRL1:
case RT5514_DSP_MAPPING | RT5514_CLK_CTRL2:
case RT5514_DSP_MAPPING | RT5514_PLL3_CALIB_CTRL1:
case RT5514_DSP_MAPPING | RT5514_PLL3_CALIB_CTRL5:
case RT5514_DSP_MAPPING | RT5514_DELAY_BUF_CTRL1:
case RT5514_DSP_MAPPING | RT5514_DELAY_BUF_CTRL3:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER0_CTRL1:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER0_CTRL2:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER0_CTRL3:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER1_CTRL1:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER1_CTRL2:
case RT5514_DSP_MAPPING | RT5514_DOWNFILTER1_CTRL3:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_LDO10:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_LDO18_16:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_ADC12:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_ADC21:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_ADC22:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_ADC23:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_MICBST:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_ADCFED:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_INBUF:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_VREF:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_PLL3:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_PLL1_1:
case RT5514_DSP_MAPPING | RT5514_ANA_CTRL_PLL1_2:
case RT5514_DSP_MAPPING | RT5514_DMIC_LP_CTRL:
case RT5514_DSP_MAPPING | RT5514_MISC_CTRL_DSP:
case RT5514_DSP_MAPPING | RT5514_DSP_CTRL1:
case RT5514_DSP_MAPPING | RT5514_DSP_CTRL3:
case RT5514_DSP_MAPPING | RT5514_DSP_CTRL4:
case RT5514_DSP_MAPPING | RT5514_VENDOR_ID1:
case RT5514_DSP_MAPPING | RT5514_VENDOR_ID2:
return true;
default:
return false;
}
}
static int rt5514_dsp_voice_wake_up_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct rt5514_priv *rt5514 = snd_soc_component_get_drvdata(component);
ucontrol->value.integer.value[0] = rt5514->dsp_enabled;
return 0;
}
static int rt5514_dsp_voice_wake_up_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct rt5514_priv *rt5514 = snd_soc_component_get_drvdata(component);
struct snd_soc_codec *codec = rt5514->codec;
const struct firmware *fw = NULL;
if (ucontrol->value.integer.value[0] == rt5514->dsp_enabled)
return 0;
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
rt5514->dsp_enabled = ucontrol->value.integer.value[0];
if (rt5514->dsp_enabled) {
rt5514_enable_dsp_prepare(rt5514);
request_firmware(&fw, RT5514_FIRMWARE1, codec->dev);
if (fw) {
#if defined(CONFIG_SND_SOC_RT5514_SPI)
rt5514_spi_burst_write(0x4ff60000, fw->data,
((fw->size/8)+1)*8);
#else
dev_err(codec->dev, "There is no SPI driver for"
" loading the firmware\n");
#endif
release_firmware(fw);
fw = NULL;
}
request_firmware(&fw, RT5514_FIRMWARE2, codec->dev);
if (fw) {
#if defined(CONFIG_SND_SOC_RT5514_SPI)
rt5514_spi_burst_write(0x4ffc0000, fw->data,
((fw->size/8)+1)*8);
#else
dev_err(codec->dev, "There is no SPI driver for"
" loading the firmware\n");
#endif
release_firmware(fw);
fw = NULL;
}
regmap_write(rt5514->i2c_regmap, 0x18002f00,
0x00055148);
} else {
regmap_multi_reg_write(rt5514->i2c_regmap,
rt5514_i2c_patch, ARRAY_SIZE(rt5514_i2c_patch));
regcache_mark_dirty(rt5514->regmap);
regcache_sync(rt5514->regmap);
}
}
return 0;
}
static int rt5514_calc_dmic_clk(struct snd_soc_codec *codec, int rate)
{
int div[] = {2, 3, 4, 8, 12, 16, 24, 32};
int i;
if (rate < 1000000 * div[0]) {
pr_warn("Base clock rate %d is too low\n", rate);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(div); i++) {
if (3072000 * div[i] >= rate)
return i;
}
dev_warn(codec->dev, "Base clock rate %d is too high\n", rate);
return -EINVAL;
}
static int rt5514_set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
int idx;
idx = rt5514_calc_dmic_clk(codec, rt5514->sysclk);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
regmap_update_bits(rt5514->regmap, RT5514_CLK_CTRL1,
RT5514_CLK_DMIC_OUT_SEL_MASK,
idx << RT5514_CLK_DMIC_OUT_SEL_SFT);
if (rt5514->pdata.dmic_init_delay)
msleep(rt5514->pdata.dmic_init_delay);
return idx;
}
static int rt5514_is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
if (rt5514->sysclk_src == RT5514_SCLK_S_PLL1)
return 1;
else
return 0;
}
static int rt5514_pre_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (rt5514->dsp_enabled) {
rt5514->dsp_enabled = 0;
regmap_multi_reg_write(rt5514->i2c_regmap,
rt5514_i2c_patch, ARRAY_SIZE(rt5514_i2c_patch));
regcache_mark_dirty(rt5514->regmap);
regcache_sync(rt5514->regmap);
}
break;
default:
return 0;
}
return 0;
}
static int rt5514_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
int pre_div, bclk_ms, frame_size;
unsigned int val_len = 0;
rt5514->lrck = params_rate(params);
pre_div = rl6231_get_clk_info(rt5514->sysclk, rt5514->lrck);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting\n");
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
bclk_ms = frame_size > 32;
rt5514->bclk = rt5514->lrck * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5514->bclk, rt5514->lrck);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val_len = RT5514_I2S_DL_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val_len = RT5514_I2S_DL_24;
break;
case SNDRV_PCM_FORMAT_S8:
val_len = RT5514_I2S_DL_8;
break;
default:
return -EINVAL;
}
regmap_update_bits(rt5514->regmap, RT5514_I2S_CTRL1, RT5514_I2S_DL_MASK,
val_len);
regmap_update_bits(rt5514->regmap, RT5514_CLK_CTRL2,
RT5514_CLK_SYS_DIV_OUT_MASK | RT5514_SEL_ADC_OSR_MASK,
pre_div << RT5514_CLK_SYS_DIV_OUT_SFT |
pre_div << RT5514_SEL_ADC_OSR_SFT);
return 0;
}
static int rt5514_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
reg_val |= RT5514_I2S_LR_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5514_I2S_BP_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
reg_val |= RT5514_I2S_BP_INV | RT5514_I2S_LR_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5514_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5514_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5514_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
regmap_update_bits(rt5514->regmap, RT5514_I2S_CTRL1,
RT5514_I2S_DF_MASK | RT5514_I2S_BP_MASK | RT5514_I2S_LR_MASK,
reg_val);
return 0;
}
static int rt5514_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5514->sysclk && clk_id == rt5514->sysclk_src)
return 0;
switch (clk_id) {
case RT5514_SCLK_S_MCLK:
reg_val |= RT5514_CLK_SYS_PRE_SEL_MCLK;
break;
case RT5514_SCLK_S_PLL1:
reg_val |= RT5514_CLK_SYS_PRE_SEL_PLL;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
regmap_update_bits(rt5514->regmap, RT5514_CLK_CTRL2,
RT5514_CLK_SYS_PRE_SEL_MASK, reg_val);
rt5514->sysclk = freq;
rt5514->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5514_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5514->pll_in = 0;
rt5514->pll_out = 0;
regmap_update_bits(rt5514->regmap, RT5514_CLK_CTRL2,
RT5514_CLK_SYS_PRE_SEL_MASK,
RT5514_CLK_SYS_PRE_SEL_MCLK);
return 0;
}
if (source == rt5514->pll_src && freq_in == rt5514->pll_in &&
freq_out == rt5514->pll_out)
return 0;
switch (source) {
case RT5514_PLL1_S_MCLK:
regmap_update_bits(rt5514->regmap, RT5514_PLL_SOURCE_CTRL,
RT5514_PLL_1_SEL_MASK, RT5514_PLL_1_SEL_MCLK);
break;
case RT5514_PLL1_S_BCLK:
regmap_update_bits(rt5514->regmap, RT5514_PLL_SOURCE_CTRL,
RT5514_PLL_1_SEL_MASK, RT5514_PLL_1_SEL_SCLK);
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
regmap_write(rt5514->regmap, RT5514_ANA_CTRL_PLL1_1,
pll_code.k_code << RT5514_PLL_K_SFT |
pll_code.n_code << RT5514_PLL_N_SFT |
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5514_PLL_M_SFT);
regmap_update_bits(rt5514->regmap, RT5514_ANA_CTRL_PLL1_2,
RT5514_PLL_M_BP, pll_code.m_bp << RT5514_PLL_M_BP_SFT);
rt5514->pll_in = freq_in;
rt5514->pll_out = freq_out;
rt5514->pll_src = source;
return 0;
}
static int rt5514_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
if (rx_mask || tx_mask)
val |= RT5514_TDM_MODE;
if (slots == 4)
val |= RT5514_TDMSLOT_SEL_RX_4CH | RT5514_TDMSLOT_SEL_TX_4CH;
switch (slot_width) {
case 20:
val |= RT5514_CH_LEN_RX_20 | RT5514_CH_LEN_TX_20;
break;
case 24:
val |= RT5514_CH_LEN_RX_24 | RT5514_CH_LEN_TX_24;
break;
case 32:
val |= RT5514_CH_LEN_RX_32 | RT5514_CH_LEN_TX_32;
break;
case 16:
default:
break;
}
regmap_update_bits(rt5514->regmap, RT5514_I2S_CTRL1, RT5514_TDM_MODE |
RT5514_TDMSLOT_SEL_RX_MASK | RT5514_TDMSLOT_SEL_TX_MASK |
RT5514_CH_LEN_RX_MASK | RT5514_CH_LEN_TX_MASK, val);
return 0;
}
static int rt5514_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (IS_ERR(rt5514->mclk))
break;
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_ON) {
clk_disable_unprepare(rt5514->mclk);
} else {
ret = clk_prepare_enable(rt5514->mclk);
if (ret)
return ret;
}
break;
default:
break;
}
return 0;
}
static int rt5514_probe(struct snd_soc_codec *codec)
{
struct rt5514_priv *rt5514 = snd_soc_codec_get_drvdata(codec);
rt5514->mclk = devm_clk_get(codec->dev, "mclk");
if (PTR_ERR(rt5514->mclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
rt5514->codec = codec;
return 0;
}
static int rt5514_i2c_read(void *context, unsigned int reg, unsigned int *val)
{
struct i2c_client *client = context;
struct rt5514_priv *rt5514 = i2c_get_clientdata(client);
regmap_read(rt5514->i2c_regmap, reg | RT5514_DSP_MAPPING, val);
return 0;
}
static int rt5514_i2c_write(void *context, unsigned int reg, unsigned int val)
{
struct i2c_client *client = context;
struct rt5514_priv *rt5514 = i2c_get_clientdata(client);
regmap_write(rt5514->i2c_regmap, reg | RT5514_DSP_MAPPING, val);
return 0;
}
static int rt5514_parse_dt(struct rt5514_priv *rt5514, struct device *dev)
{
device_property_read_u32(dev, "realtek,dmic-init-delay-ms",
&rt5514->pdata.dmic_init_delay);
return 0;
}
static int rt5514_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5514_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5514_priv *rt5514;
int ret;
unsigned int val;
rt5514 = devm_kzalloc(&i2c->dev, sizeof(struct rt5514_priv),
GFP_KERNEL);
if (rt5514 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5514);
if (pdata)
rt5514->pdata = *pdata;
else if (i2c->dev.of_node)
rt5514_parse_dt(rt5514, &i2c->dev);
rt5514->i2c_regmap = devm_regmap_init_i2c(i2c, &rt5514_i2c_regmap);
if (IS_ERR(rt5514->i2c_regmap)) {
ret = PTR_ERR(rt5514->i2c_regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
rt5514->regmap = devm_regmap_init(&i2c->dev, NULL, i2c, &rt5514_regmap);
if (IS_ERR(rt5514->regmap)) {
ret = PTR_ERR(rt5514->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5514->regmap, RT5514_VENDOR_ID2, &val);
if (val != RT5514_DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt5514\n", val);
return -ENODEV;
}
ret = regmap_multi_reg_write(rt5514->i2c_regmap, rt5514_i2c_patch,
ARRAY_SIZE(rt5514_i2c_patch));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply i2c_regmap patch: %d\n",
ret);
ret = regmap_register_patch(rt5514->regmap, rt5514_patch,
ARRAY_SIZE(rt5514_patch));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5514,
rt5514_dai, ARRAY_SIZE(rt5514_dai));
}
static int rt5514_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
