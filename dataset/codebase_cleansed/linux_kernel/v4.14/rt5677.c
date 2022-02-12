static bool rt5677_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5677_ranges); i++) {
if (reg >= rt5677_ranges[i].range_min &&
reg <= rt5677_ranges[i].range_max) {
return true;
}
}
switch (reg) {
case RT5677_RESET:
case RT5677_SLIMBUS_PARAM:
case RT5677_PDM_DATA_CTRL1:
case RT5677_PDM_DATA_CTRL2:
case RT5677_PDM1_DATA_CTRL4:
case RT5677_PDM2_DATA_CTRL4:
case RT5677_I2C_MASTER_CTRL1:
case RT5677_I2C_MASTER_CTRL7:
case RT5677_I2C_MASTER_CTRL8:
case RT5677_HAP_GENE_CTRL2:
case RT5677_PWR_DSP_ST:
case RT5677_PRIV_DATA:
case RT5677_ASRC_22:
case RT5677_ASRC_23:
case RT5677_VAD_CTRL5:
case RT5677_ADC_EQ_CTRL1:
case RT5677_EQ_CTRL1:
case RT5677_IRQ_CTRL1:
case RT5677_IRQ_CTRL2:
case RT5677_GPIO_ST:
case RT5677_DSP_INB1_SRC_CTRL4:
case RT5677_DSP_INB2_SRC_CTRL4:
case RT5677_DSP_INB3_SRC_CTRL4:
case RT5677_DSP_OUTB1_SRC_CTRL4:
case RT5677_DSP_OUTB2_SRC_CTRL4:
case RT5677_VENDOR_ID:
case RT5677_VENDOR_ID1:
case RT5677_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5677_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5677_ranges); i++) {
if (reg >= rt5677_ranges[i].range_min &&
reg <= rt5677_ranges[i].range_max) {
return true;
}
}
switch (reg) {
case RT5677_RESET:
case RT5677_LOUT1:
case RT5677_IN1:
case RT5677_MICBIAS:
case RT5677_SLIMBUS_PARAM:
case RT5677_SLIMBUS_RX:
case RT5677_SLIMBUS_CTRL:
case RT5677_SIDETONE_CTRL:
case RT5677_ANA_DAC1_2_3_SRC:
case RT5677_IF_DSP_DAC3_4_MIXER:
case RT5677_DAC4_DIG_VOL:
case RT5677_DAC3_DIG_VOL:
case RT5677_DAC1_DIG_VOL:
case RT5677_DAC2_DIG_VOL:
case RT5677_IF_DSP_DAC2_MIXER:
case RT5677_STO1_ADC_DIG_VOL:
case RT5677_MONO_ADC_DIG_VOL:
case RT5677_STO1_2_ADC_BST:
case RT5677_STO2_ADC_DIG_VOL:
case RT5677_ADC_BST_CTRL2:
case RT5677_STO3_4_ADC_BST:
case RT5677_STO3_ADC_DIG_VOL:
case RT5677_STO4_ADC_DIG_VOL:
case RT5677_STO4_ADC_MIXER:
case RT5677_STO3_ADC_MIXER:
case RT5677_STO2_ADC_MIXER:
case RT5677_STO1_ADC_MIXER:
case RT5677_MONO_ADC_MIXER:
case RT5677_ADC_IF_DSP_DAC1_MIXER:
case RT5677_STO1_DAC_MIXER:
case RT5677_MONO_DAC_MIXER:
case RT5677_DD1_MIXER:
case RT5677_DD2_MIXER:
case RT5677_IF3_DATA:
case RT5677_IF4_DATA:
case RT5677_PDM_OUT_CTRL:
case RT5677_PDM_DATA_CTRL1:
case RT5677_PDM_DATA_CTRL2:
case RT5677_PDM1_DATA_CTRL2:
case RT5677_PDM1_DATA_CTRL3:
case RT5677_PDM1_DATA_CTRL4:
case RT5677_PDM2_DATA_CTRL2:
case RT5677_PDM2_DATA_CTRL3:
case RT5677_PDM2_DATA_CTRL4:
case RT5677_TDM1_CTRL1:
case RT5677_TDM1_CTRL2:
case RT5677_TDM1_CTRL3:
case RT5677_TDM1_CTRL4:
case RT5677_TDM1_CTRL5:
case RT5677_TDM2_CTRL1:
case RT5677_TDM2_CTRL2:
case RT5677_TDM2_CTRL3:
case RT5677_TDM2_CTRL4:
case RT5677_TDM2_CTRL5:
case RT5677_I2C_MASTER_CTRL1:
case RT5677_I2C_MASTER_CTRL2:
case RT5677_I2C_MASTER_CTRL3:
case RT5677_I2C_MASTER_CTRL4:
case RT5677_I2C_MASTER_CTRL5:
case RT5677_I2C_MASTER_CTRL6:
case RT5677_I2C_MASTER_CTRL7:
case RT5677_I2C_MASTER_CTRL8:
case RT5677_DMIC_CTRL1:
case RT5677_DMIC_CTRL2:
case RT5677_HAP_GENE_CTRL1:
case RT5677_HAP_GENE_CTRL2:
case RT5677_HAP_GENE_CTRL3:
case RT5677_HAP_GENE_CTRL4:
case RT5677_HAP_GENE_CTRL5:
case RT5677_HAP_GENE_CTRL6:
case RT5677_HAP_GENE_CTRL7:
case RT5677_HAP_GENE_CTRL8:
case RT5677_HAP_GENE_CTRL9:
case RT5677_HAP_GENE_CTRL10:
case RT5677_PWR_DIG1:
case RT5677_PWR_DIG2:
case RT5677_PWR_ANLG1:
case RT5677_PWR_ANLG2:
case RT5677_PWR_DSP1:
case RT5677_PWR_DSP_ST:
case RT5677_PWR_DSP2:
case RT5677_ADC_DAC_HPF_CTRL1:
case RT5677_PRIV_INDEX:
case RT5677_PRIV_DATA:
case RT5677_I2S4_SDP:
case RT5677_I2S1_SDP:
case RT5677_I2S2_SDP:
case RT5677_I2S3_SDP:
case RT5677_CLK_TREE_CTRL1:
case RT5677_CLK_TREE_CTRL2:
case RT5677_CLK_TREE_CTRL3:
case RT5677_PLL1_CTRL1:
case RT5677_PLL1_CTRL2:
case RT5677_PLL2_CTRL1:
case RT5677_PLL2_CTRL2:
case RT5677_GLB_CLK1:
case RT5677_GLB_CLK2:
case RT5677_ASRC_1:
case RT5677_ASRC_2:
case RT5677_ASRC_3:
case RT5677_ASRC_4:
case RT5677_ASRC_5:
case RT5677_ASRC_6:
case RT5677_ASRC_7:
case RT5677_ASRC_8:
case RT5677_ASRC_9:
case RT5677_ASRC_10:
case RT5677_ASRC_11:
case RT5677_ASRC_12:
case RT5677_ASRC_13:
case RT5677_ASRC_14:
case RT5677_ASRC_15:
case RT5677_ASRC_16:
case RT5677_ASRC_17:
case RT5677_ASRC_18:
case RT5677_ASRC_19:
case RT5677_ASRC_20:
case RT5677_ASRC_21:
case RT5677_ASRC_22:
case RT5677_ASRC_23:
case RT5677_VAD_CTRL1:
case RT5677_VAD_CTRL2:
case RT5677_VAD_CTRL3:
case RT5677_VAD_CTRL4:
case RT5677_VAD_CTRL5:
case RT5677_DSP_INB_CTRL1:
case RT5677_DSP_INB_CTRL2:
case RT5677_DSP_IN_OUTB_CTRL:
case RT5677_DSP_OUTB0_1_DIG_VOL:
case RT5677_DSP_OUTB2_3_DIG_VOL:
case RT5677_DSP_OUTB4_5_DIG_VOL:
case RT5677_DSP_OUTB6_7_DIG_VOL:
case RT5677_ADC_EQ_CTRL1:
case RT5677_ADC_EQ_CTRL2:
case RT5677_EQ_CTRL1:
case RT5677_EQ_CTRL2:
case RT5677_EQ_CTRL3:
case RT5677_SOFT_VOL_ZERO_CROSS1:
case RT5677_JD_CTRL1:
case RT5677_JD_CTRL2:
case RT5677_JD_CTRL3:
case RT5677_IRQ_CTRL1:
case RT5677_IRQ_CTRL2:
case RT5677_GPIO_ST:
case RT5677_GPIO_CTRL1:
case RT5677_GPIO_CTRL2:
case RT5677_GPIO_CTRL3:
case RT5677_STO1_ADC_HI_FILTER1:
case RT5677_STO1_ADC_HI_FILTER2:
case RT5677_MONO_ADC_HI_FILTER1:
case RT5677_MONO_ADC_HI_FILTER2:
case RT5677_STO2_ADC_HI_FILTER1:
case RT5677_STO2_ADC_HI_FILTER2:
case RT5677_STO3_ADC_HI_FILTER1:
case RT5677_STO3_ADC_HI_FILTER2:
case RT5677_STO4_ADC_HI_FILTER1:
case RT5677_STO4_ADC_HI_FILTER2:
case RT5677_MB_DRC_CTRL1:
case RT5677_DRC1_CTRL1:
case RT5677_DRC1_CTRL2:
case RT5677_DRC1_CTRL3:
case RT5677_DRC1_CTRL4:
case RT5677_DRC1_CTRL5:
case RT5677_DRC1_CTRL6:
case RT5677_DRC2_CTRL1:
case RT5677_DRC2_CTRL2:
case RT5677_DRC2_CTRL3:
case RT5677_DRC2_CTRL4:
case RT5677_DRC2_CTRL5:
case RT5677_DRC2_CTRL6:
case RT5677_DRC1_HL_CTRL1:
case RT5677_DRC1_HL_CTRL2:
case RT5677_DRC2_HL_CTRL1:
case RT5677_DRC2_HL_CTRL2:
case RT5677_DSP_INB1_SRC_CTRL1:
case RT5677_DSP_INB1_SRC_CTRL2:
case RT5677_DSP_INB1_SRC_CTRL3:
case RT5677_DSP_INB1_SRC_CTRL4:
case RT5677_DSP_INB2_SRC_CTRL1:
case RT5677_DSP_INB2_SRC_CTRL2:
case RT5677_DSP_INB2_SRC_CTRL3:
case RT5677_DSP_INB2_SRC_CTRL4:
case RT5677_DSP_INB3_SRC_CTRL1:
case RT5677_DSP_INB3_SRC_CTRL2:
case RT5677_DSP_INB3_SRC_CTRL3:
case RT5677_DSP_INB3_SRC_CTRL4:
case RT5677_DSP_OUTB1_SRC_CTRL1:
case RT5677_DSP_OUTB1_SRC_CTRL2:
case RT5677_DSP_OUTB1_SRC_CTRL3:
case RT5677_DSP_OUTB1_SRC_CTRL4:
case RT5677_DSP_OUTB2_SRC_CTRL1:
case RT5677_DSP_OUTB2_SRC_CTRL2:
case RT5677_DSP_OUTB2_SRC_CTRL3:
case RT5677_DSP_OUTB2_SRC_CTRL4:
case RT5677_DSP_OUTB_0123_MIXER_CTRL:
case RT5677_DSP_OUTB_45_MIXER_CTRL:
case RT5677_DSP_OUTB_67_MIXER_CTRL:
case RT5677_DIG_MISC:
case RT5677_GEN_CTRL1:
case RT5677_GEN_CTRL2:
case RT5677_VENDOR_ID:
case RT5677_VENDOR_ID1:
case RT5677_VENDOR_ID2:
return true;
default:
return false;
}
}
static int rt5677_dsp_mode_i2c_write_addr(struct rt5677_priv *rt5677,
unsigned int addr, unsigned int value, unsigned int opcode)
{
struct snd_soc_codec *codec = rt5677->codec;
int ret;
mutex_lock(&rt5677->dsp_cmd_lock);
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_ADDR_MSB,
addr >> 16);
if (ret < 0) {
dev_err(codec->dev, "Failed to set addr msb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_ADDR_LSB,
addr & 0xffff);
if (ret < 0) {
dev_err(codec->dev, "Failed to set addr lsb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_DATA_MSB,
value >> 16);
if (ret < 0) {
dev_err(codec->dev, "Failed to set data msb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_DATA_LSB,
value & 0xffff);
if (ret < 0) {
dev_err(codec->dev, "Failed to set data lsb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_OP_CODE,
opcode);
if (ret < 0) {
dev_err(codec->dev, "Failed to set op code value: %d\n", ret);
goto err;
}
err:
mutex_unlock(&rt5677->dsp_cmd_lock);
return ret;
}
static int rt5677_dsp_mode_i2c_read_addr(
struct rt5677_priv *rt5677, unsigned int addr, unsigned int *value)
{
struct snd_soc_codec *codec = rt5677->codec;
int ret;
unsigned int msb, lsb;
mutex_lock(&rt5677->dsp_cmd_lock);
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_ADDR_MSB,
addr >> 16);
if (ret < 0) {
dev_err(codec->dev, "Failed to set addr msb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_ADDR_LSB,
addr & 0xffff);
if (ret < 0) {
dev_err(codec->dev, "Failed to set addr lsb value: %d\n", ret);
goto err;
}
ret = regmap_write(rt5677->regmap_physical, RT5677_DSP_I2C_OP_CODE,
0x0002);
if (ret < 0) {
dev_err(codec->dev, "Failed to set op code value: %d\n", ret);
goto err;
}
regmap_read(rt5677->regmap_physical, RT5677_DSP_I2C_DATA_MSB, &msb);
regmap_read(rt5677->regmap_physical, RT5677_DSP_I2C_DATA_LSB, &lsb);
*value = (msb << 16) | lsb;
err:
mutex_unlock(&rt5677->dsp_cmd_lock);
return ret;
}
static int rt5677_dsp_mode_i2c_write(struct rt5677_priv *rt5677,
unsigned int reg, unsigned int value)
{
return rt5677_dsp_mode_i2c_write_addr(rt5677, 0x18020000 + reg * 2,
value, 0x0001);
}
static int rt5677_dsp_mode_i2c_read(
struct rt5677_priv *rt5677, unsigned int reg, unsigned int *value)
{
int ret = rt5677_dsp_mode_i2c_read_addr(rt5677, 0x18020000 + reg * 2,
value);
*value &= 0xffff;
return ret;
}
static void rt5677_set_dsp_mode(struct snd_soc_codec *codec, bool on)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
if (on) {
regmap_update_bits(rt5677->regmap, RT5677_PWR_DSP1, 0x2, 0x2);
rt5677->is_dsp_mode = true;
} else {
regmap_update_bits(rt5677->regmap, RT5677_PWR_DSP1, 0x2, 0x0);
rt5677->is_dsp_mode = false;
}
}
static int rt5677_set_dsp_vad(struct snd_soc_codec *codec, bool on)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
static bool activity;
int ret;
if (!IS_ENABLED(CONFIG_SND_SOC_RT5677_SPI))
return -ENXIO;
if (on && !activity) {
activity = true;
regcache_cache_only(rt5677->regmap, false);
regcache_cache_bypass(rt5677->regmap, true);
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC, 0x1, 0x1);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_BIAS_CUR4, 0x0f00, 0x0f00);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_LDO1_SEL_MASK, 0x0);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_LDO1, RT5677_PWR_LDO1);
switch (rt5677->type) {
case RT5677:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_MCLK_SRC_MASK, RT5677_MCLK2_SRC);
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK2,
RT5677_PLL2_PR_SRC_MASK |
RT5677_DSP_CLK_SRC_MASK,
RT5677_PLL2_PR_SRC_MCLK2 |
RT5677_DSP_CLK_SRC_BYPASS);
break;
case RT5676:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK2,
RT5677_DSP_CLK_SRC_MASK,
RT5677_DSP_CLK_SRC_BYPASS);
break;
default:
break;
}
regmap_write(rt5677->regmap, RT5677_PWR_DSP2, 0x07ff);
regmap_write(rt5677->regmap, RT5677_PWR_DSP1, 0x07fd);
rt5677_set_dsp_mode(codec, true);
ret = request_firmware(&rt5677->fw1, RT5677_FIRMWARE1,
codec->dev);
if (ret == 0) {
rt5677_spi_write_firmware(0x50000000, rt5677->fw1);
release_firmware(rt5677->fw1);
}
ret = request_firmware(&rt5677->fw2, RT5677_FIRMWARE2,
codec->dev);
if (ret == 0) {
rt5677_spi_write_firmware(0x60000000, rt5677->fw2);
release_firmware(rt5677->fw2);
}
regmap_update_bits(rt5677->regmap, RT5677_PWR_DSP1, 0x1, 0x0);
regcache_cache_bypass(rt5677->regmap, false);
regcache_cache_only(rt5677->regmap, true);
} else if (!on && activity) {
activity = false;
regcache_cache_only(rt5677->regmap, false);
regcache_cache_bypass(rt5677->regmap, true);
regmap_update_bits(rt5677->regmap, RT5677_PWR_DSP1, 0x1, 0x1);
rt5677_set_dsp_mode(codec, false);
regmap_write(rt5677->regmap, RT5677_PWR_DSP1, 0x0001);
regmap_write(rt5677->regmap, RT5677_RESET, 0x10ec);
regcache_cache_bypass(rt5677->regmap, false);
regcache_mark_dirty(rt5677->regmap);
regcache_sync(rt5677->regmap);
}
return 0;
}
static int rt5677_dsp_vad_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct rt5677_priv *rt5677 = snd_soc_component_get_drvdata(component);
ucontrol->value.integer.value[0] = rt5677->dsp_vad_en;
return 0;
}
static int rt5677_dsp_vad_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct rt5677_priv *rt5677 = snd_soc_component_get_drvdata(component);
struct snd_soc_codec *codec = snd_soc_component_to_codec(component);
rt5677->dsp_vad_en = !!ucontrol->value.integer.value[0];
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
rt5677_set_dsp_vad(codec, rt5677->dsp_vad_en);
return 0;
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
int idx, rate;
rate = rt5677->sysclk / rl6231_get_pre_div(rt5677->regmap,
RT5677_CLK_TREE_CTRL1, RT5677_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rate);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
regmap_update_bits(rt5677->regmap, RT5677_DMIC_CTRL1,
RT5677_DMIC_CLK_MASK, idx << RT5677_DMIC_CLK_SFT);
return idx;
}
static int is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
regmap_read(rt5677->regmap, RT5677_GLB_CLK1, &val);
val &= RT5677_SCLK_SRC_MASK;
if (val == RT5677_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int is_using_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int reg, shift, val;
if (source->reg == RT5677_ASRC_1) {
switch (source->shift) {
case 12:
reg = RT5677_ASRC_4;
shift = 0;
break;
case 13:
reg = RT5677_ASRC_4;
shift = 4;
break;
case 14:
reg = RT5677_ASRC_4;
shift = 8;
break;
case 15:
reg = RT5677_ASRC_4;
shift = 12;
break;
default:
return 0;
}
} else {
switch (source->shift) {
case 0:
reg = RT5677_ASRC_6;
shift = 8;
break;
case 1:
reg = RT5677_ASRC_6;
shift = 12;
break;
case 2:
reg = RT5677_ASRC_5;
shift = 0;
break;
case 3:
reg = RT5677_ASRC_5;
shift = 4;
break;
case 4:
reg = RT5677_ASRC_5;
shift = 8;
break;
case 5:
reg = RT5677_ASRC_5;
shift = 12;
break;
case 12:
reg = RT5677_ASRC_3;
shift = 0;
break;
case 13:
reg = RT5677_ASRC_3;
shift = 4;
break;
case 14:
reg = RT5677_ASRC_3;
shift = 12;
break;
default:
return 0;
}
}
regmap_read(rt5677->regmap, reg, &val);
val = (val >> shift) & 0xf;
switch (val) {
case 1 ... 6:
return 1;
default:
return 0;
}
}
static int can_use_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
if (rt5677->sysclk > rt5677->lrck[RT5677_AIF1] * 384)
return 1;
return 0;
}
int rt5677_sel_asrc_clk_src(struct snd_soc_codec *codec,
unsigned int filter_mask, unsigned int clk_src)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int asrc3_mask = 0, asrc3_value = 0;
unsigned int asrc4_mask = 0, asrc4_value = 0;
unsigned int asrc5_mask = 0, asrc5_value = 0;
unsigned int asrc6_mask = 0, asrc6_value = 0;
unsigned int asrc7_mask = 0, asrc7_value = 0;
unsigned int asrc8_mask = 0, asrc8_value = 0;
switch (clk_src) {
case RT5677_CLK_SEL_SYS:
case RT5677_CLK_SEL_I2S1_ASRC:
case RT5677_CLK_SEL_I2S2_ASRC:
case RT5677_CLK_SEL_I2S3_ASRC:
case RT5677_CLK_SEL_I2S4_ASRC:
case RT5677_CLK_SEL_I2S5_ASRC:
case RT5677_CLK_SEL_I2S6_ASRC:
case RT5677_CLK_SEL_SYS2:
case RT5677_CLK_SEL_SYS3:
case RT5677_CLK_SEL_SYS4:
case RT5677_CLK_SEL_SYS5:
case RT5677_CLK_SEL_SYS6:
case RT5677_CLK_SEL_SYS7:
break;
default:
return -EINVAL;
}
if (filter_mask & RT5677_DA_STEREO_FILTER) {
asrc3_mask |= RT5677_DA_STO_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5677_DA_STO_CLK_SEL_MASK)
| (clk_src << RT5677_DA_STO_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DA_MONO2_L_FILTER) {
asrc3_mask |= RT5677_DA_MONO2L_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5677_DA_MONO2L_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO2L_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DA_MONO2_R_FILTER) {
asrc3_mask |= RT5677_DA_MONO2R_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5677_DA_MONO2R_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO2R_CLK_SEL_SFT);
}
if (asrc3_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_3, asrc3_mask,
asrc3_value);
if (filter_mask & RT5677_DA_MONO3_L_FILTER) {
asrc4_mask |= RT5677_DA_MONO3L_CLK_SEL_MASK;
asrc4_value = (asrc4_value & ~RT5677_DA_MONO3L_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO3L_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DA_MONO3_R_FILTER) {
asrc4_mask |= RT5677_DA_MONO3R_CLK_SEL_MASK;
asrc4_value = (asrc4_value & ~RT5677_DA_MONO3R_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO3R_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DA_MONO4_L_FILTER) {
asrc4_mask |= RT5677_DA_MONO4L_CLK_SEL_MASK;
asrc4_value = (asrc4_value & ~RT5677_DA_MONO4L_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO4L_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DA_MONO4_R_FILTER) {
asrc4_mask |= RT5677_DA_MONO4R_CLK_SEL_MASK;
asrc4_value = (asrc4_value & ~RT5677_DA_MONO4R_CLK_SEL_MASK)
| (clk_src << RT5677_DA_MONO4R_CLK_SEL_SFT);
}
if (asrc4_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_4, asrc4_mask,
asrc4_value);
if (filter_mask & RT5677_AD_STEREO1_FILTER) {
asrc5_mask |= RT5677_AD_STO1_CLK_SEL_MASK;
asrc5_value = (asrc5_value & ~RT5677_AD_STO1_CLK_SEL_MASK)
| (clk_src << RT5677_AD_STO1_CLK_SEL_SFT);
}
if (filter_mask & RT5677_AD_STEREO2_FILTER) {
asrc5_mask |= RT5677_AD_STO2_CLK_SEL_MASK;
asrc5_value = (asrc5_value & ~RT5677_AD_STO2_CLK_SEL_MASK)
| (clk_src << RT5677_AD_STO2_CLK_SEL_SFT);
}
if (filter_mask & RT5677_AD_STEREO3_FILTER) {
asrc5_mask |= RT5677_AD_STO3_CLK_SEL_MASK;
asrc5_value = (asrc5_value & ~RT5677_AD_STO3_CLK_SEL_MASK)
| (clk_src << RT5677_AD_STO3_CLK_SEL_SFT);
}
if (filter_mask & RT5677_AD_STEREO4_FILTER) {
asrc5_mask |= RT5677_AD_STO4_CLK_SEL_MASK;
asrc5_value = (asrc5_value & ~RT5677_AD_STO4_CLK_SEL_MASK)
| (clk_src << RT5677_AD_STO4_CLK_SEL_SFT);
}
if (asrc5_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_5, asrc5_mask,
asrc5_value);
if (filter_mask & RT5677_AD_MONO_L_FILTER) {
asrc6_mask |= RT5677_AD_MONOL_CLK_SEL_MASK;
asrc6_value = (asrc6_value & ~RT5677_AD_MONOL_CLK_SEL_MASK)
| (clk_src << RT5677_AD_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5677_AD_MONO_R_FILTER) {
asrc6_mask |= RT5677_AD_MONOR_CLK_SEL_MASK;
asrc6_value = (asrc6_value & ~RT5677_AD_MONOR_CLK_SEL_MASK)
| (clk_src << RT5677_AD_MONOR_CLK_SEL_SFT);
}
if (asrc6_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_6, asrc6_mask,
asrc6_value);
if (filter_mask & RT5677_DSP_OB_0_3_FILTER) {
asrc7_mask |= RT5677_DSP_OB_0_3_CLK_SEL_MASK;
asrc7_value = (asrc7_value & ~RT5677_DSP_OB_0_3_CLK_SEL_MASK)
| (clk_src << RT5677_DSP_OB_0_3_CLK_SEL_SFT);
}
if (filter_mask & RT5677_DSP_OB_4_7_FILTER) {
asrc7_mask |= RT5677_DSP_OB_4_7_CLK_SEL_MASK;
asrc7_value = (asrc7_value & ~RT5677_DSP_OB_4_7_CLK_SEL_MASK)
| (clk_src << RT5677_DSP_OB_4_7_CLK_SEL_SFT);
}
if (asrc7_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_7, asrc7_mask,
asrc7_value);
if (filter_mask & RT5677_I2S1_SOURCE) {
asrc8_mask |= RT5677_I2S1_CLK_SEL_MASK;
asrc8_value = (asrc8_value & ~RT5677_I2S1_CLK_SEL_MASK)
| ((clk_src - 1) << RT5677_I2S1_CLK_SEL_SFT);
}
if (filter_mask & RT5677_I2S2_SOURCE) {
asrc8_mask |= RT5677_I2S2_CLK_SEL_MASK;
asrc8_value = (asrc8_value & ~RT5677_I2S2_CLK_SEL_MASK)
| ((clk_src - 1) << RT5677_I2S2_CLK_SEL_SFT);
}
if (filter_mask & RT5677_I2S3_SOURCE) {
asrc8_mask |= RT5677_I2S3_CLK_SEL_MASK;
asrc8_value = (asrc8_value & ~RT5677_I2S3_CLK_SEL_MASK)
| ((clk_src - 1) << RT5677_I2S3_CLK_SEL_SFT);
}
if (filter_mask & RT5677_I2S4_SOURCE) {
asrc8_mask |= RT5677_I2S4_CLK_SEL_MASK;
asrc8_value = (asrc8_value & ~RT5677_I2S4_CLK_SEL_MASK)
| ((clk_src - 1) << RT5677_I2S4_CLK_SEL_SFT);
}
if (asrc8_mask)
regmap_update_bits(rt5677->regmap, RT5677_ASRC_8, asrc8_mask,
asrc8_value);
return 0;
}
static int rt5677_dmic_use_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int asrc_setting;
switch (source->shift) {
case 11:
regmap_read(rt5677->regmap, RT5677_ASRC_5, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_STO1_CLK_SEL_MASK) >>
RT5677_AD_STO1_CLK_SEL_SFT;
break;
case 10:
regmap_read(rt5677->regmap, RT5677_ASRC_5, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_STO2_CLK_SEL_MASK) >>
RT5677_AD_STO2_CLK_SEL_SFT;
break;
case 9:
regmap_read(rt5677->regmap, RT5677_ASRC_5, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_STO3_CLK_SEL_MASK) >>
RT5677_AD_STO3_CLK_SEL_SFT;
break;
case 8:
regmap_read(rt5677->regmap, RT5677_ASRC_5, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_STO4_CLK_SEL_MASK) >>
RT5677_AD_STO4_CLK_SEL_SFT;
break;
case 7:
regmap_read(rt5677->regmap, RT5677_ASRC_6, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_MONOL_CLK_SEL_MASK) >>
RT5677_AD_MONOL_CLK_SEL_SFT;
break;
case 6:
regmap_read(rt5677->regmap, RT5677_ASRC_6, &asrc_setting);
asrc_setting = (asrc_setting & RT5677_AD_MONOR_CLK_SEL_MASK) >>
RT5677_AD_MONOR_CLK_SEL_SFT;
break;
default:
return 0;
}
if (asrc_setting >= RT5677_CLK_SEL_I2S1_ASRC &&
asrc_setting <= RT5677_CLK_SEL_I2S6_ASRC)
return 1;
return 0;
}
static int rt5677_bst1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_BST1_P, RT5677_PWR_BST1_P);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_BST1_P, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5677_bst2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_BST2_P, RT5677_PWR_BST2_P);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_BST2_P, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5677_set_pll1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL1_CTRL2, 0x2, 0x2);
break;
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL1_CTRL2, 0x2, 0x0);
break;
default:
return 0;
}
return 0;
}
static int rt5677_set_pll2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL2_CTRL2, 0x2, 0x2);
break;
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL2_CTRL2, 0x2, 0x0);
break;
default:
return 0;
}
return 0;
}
static int rt5677_set_micbias1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_CLK_MB1 | RT5677_PWR_PP_MB1 |
RT5677_PWR_CLK_MB, RT5677_PWR_CLK_MB1 |
RT5677_PWR_PP_MB1 | RT5677_PWR_CLK_MB);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_CLK_MB1 | RT5677_PWR_PP_MB1 |
RT5677_PWR_CLK_MB, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5677_if1_adc_tdm_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int value;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_read(rt5677->regmap, RT5677_TDM1_CTRL2, &value);
if (value & RT5677_IF1_ADC_CTRL_MASK)
regmap_update_bits(rt5677->regmap, RT5677_TDM1_CTRL1,
RT5677_IF1_ADC_MODE_MASK,
RT5677_IF1_ADC_MODE_TDM);
break;
default:
return 0;
}
return 0;
}
static int rt5677_if2_adc_tdm_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int value;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_read(rt5677->regmap, RT5677_TDM2_CTRL2, &value);
if (value & RT5677_IF2_ADC_CTRL_MASK)
regmap_update_bits(rt5677->regmap, RT5677_TDM2_CTRL1,
RT5677_IF2_ADC_MODE_MASK,
RT5677_IF2_ADC_MODE_TDM);
break;
default:
return 0;
}
return 0;
}
static int rt5677_vref_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (snd_soc_codec_get_bias_level(codec) != SND_SOC_BIAS_ON &&
!rt5677->is_vref_slow) {
mdelay(20);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_PWR_FV1 | RT5677_PWR_FV2,
RT5677_PWR_FV1 | RT5677_PWR_FV2);
rt5677->is_vref_slow = true;
}
break;
default:
return 0;
}
return 0;
}
static int rt5677_filter_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(50);
break;
default:
return 0;
}
return 0;
}
static int rt5677_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, bclk_ms, frame_size;
rt5677->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5677->sysclk, rt5677->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting: sysclk=%dHz lrck=%dHz\n",
rt5677->sysclk, rt5677->lrck[dai->id]);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
bclk_ms = frame_size > 32;
rt5677->bclk[dai->id] = rt5677->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5677->bclk[dai->id], rt5677->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5677_I2S_DL_20;
break;
case 24:
val_len |= RT5677_I2S_DL_24;
break;
case 8:
val_len |= RT5677_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5677_AIF1:
mask_clk = RT5677_I2S_PD1_MASK;
val_clk = pre_div << RT5677_I2S_PD1_SFT;
regmap_update_bits(rt5677->regmap, RT5677_I2S1_SDP,
RT5677_I2S_DL_MASK, val_len);
regmap_update_bits(rt5677->regmap, RT5677_CLK_TREE_CTRL1,
mask_clk, val_clk);
break;
case RT5677_AIF2:
mask_clk = RT5677_I2S_PD2_MASK;
val_clk = pre_div << RT5677_I2S_PD2_SFT;
regmap_update_bits(rt5677->regmap, RT5677_I2S2_SDP,
RT5677_I2S_DL_MASK, val_len);
regmap_update_bits(rt5677->regmap, RT5677_CLK_TREE_CTRL1,
mask_clk, val_clk);
break;
case RT5677_AIF3:
mask_clk = RT5677_I2S_BCLK_MS3_MASK | RT5677_I2S_PD3_MASK;
val_clk = bclk_ms << RT5677_I2S_BCLK_MS3_SFT |
pre_div << RT5677_I2S_PD3_SFT;
regmap_update_bits(rt5677->regmap, RT5677_I2S3_SDP,
RT5677_I2S_DL_MASK, val_len);
regmap_update_bits(rt5677->regmap, RT5677_CLK_TREE_CTRL1,
mask_clk, val_clk);
break;
case RT5677_AIF4:
mask_clk = RT5677_I2S_BCLK_MS4_MASK | RT5677_I2S_PD4_MASK;
val_clk = bclk_ms << RT5677_I2S_BCLK_MS4_SFT |
pre_div << RT5677_I2S_PD4_SFT;
regmap_update_bits(rt5677->regmap, RT5677_I2S4_SDP,
RT5677_I2S_DL_MASK, val_len);
regmap_update_bits(rt5677->regmap, RT5677_CLK_TREE_CTRL1,
mask_clk, val_clk);
break;
default:
break;
}
return 0;
}
static int rt5677_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5677->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5677_I2S_MS_S;
rt5677->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5677_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5677_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5677_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5677_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5677_AIF1:
regmap_update_bits(rt5677->regmap, RT5677_I2S1_SDP,
RT5677_I2S_MS_MASK | RT5677_I2S_BP_MASK |
RT5677_I2S_DF_MASK, reg_val);
break;
case RT5677_AIF2:
regmap_update_bits(rt5677->regmap, RT5677_I2S2_SDP,
RT5677_I2S_MS_MASK | RT5677_I2S_BP_MASK |
RT5677_I2S_DF_MASK, reg_val);
break;
case RT5677_AIF3:
regmap_update_bits(rt5677->regmap, RT5677_I2S3_SDP,
RT5677_I2S_MS_MASK | RT5677_I2S_BP_MASK |
RT5677_I2S_DF_MASK, reg_val);
break;
case RT5677_AIF4:
regmap_update_bits(rt5677->regmap, RT5677_I2S4_SDP,
RT5677_I2S_MS_MASK | RT5677_I2S_BP_MASK |
RT5677_I2S_DF_MASK, reg_val);
break;
default:
break;
}
return 0;
}
static int rt5677_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5677->sysclk && clk_id == rt5677->sysclk_src)
return 0;
switch (clk_id) {
case RT5677_SCLK_S_MCLK:
reg_val |= RT5677_SCLK_SRC_MCLK;
break;
case RT5677_SCLK_S_PLL1:
reg_val |= RT5677_SCLK_SRC_PLL1;
break;
case RT5677_SCLK_S_RCCLK:
reg_val |= RT5677_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_SCLK_SRC_MASK, reg_val);
rt5677->sysclk = freq;
rt5677->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5677_pll_calc(const unsigned int freq_in,
const unsigned int freq_out, struct rl6231_pll_code *pll_code)
{
if (RT5677_PLL_INP_MIN > freq_in)
return -EINVAL;
return rl6231_pll_calc(freq_in, freq_out, pll_code);
}
static int rt5677_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (source == rt5677->pll_src && freq_in == rt5677->pll_in &&
freq_out == rt5677->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5677->pll_in = 0;
rt5677->pll_out = 0;
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_SCLK_SRC_MASK, RT5677_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5677_PLL1_S_MCLK:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_PLL1_SRC_MASK, RT5677_PLL1_SRC_MCLK);
break;
case RT5677_PLL1_S_BCLK1:
case RT5677_PLL1_S_BCLK2:
case RT5677_PLL1_S_BCLK3:
case RT5677_PLL1_S_BCLK4:
switch (dai->id) {
case RT5677_AIF1:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_PLL1_SRC_MASK, RT5677_PLL1_SRC_BCLK1);
break;
case RT5677_AIF2:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_PLL1_SRC_MASK, RT5677_PLL1_SRC_BCLK2);
break;
case RT5677_AIF3:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_PLL1_SRC_MASK, RT5677_PLL1_SRC_BCLK3);
break;
case RT5677_AIF4:
regmap_update_bits(rt5677->regmap, RT5677_GLB_CLK1,
RT5677_PLL1_SRC_MASK, RT5677_PLL1_SRC_BCLK4);
break;
default:
break;
}
break;
default:
dev_err(codec->dev, "Unknown PLL source %d\n", source);
return -EINVAL;
}
ret = rt5677_pll_calc(freq_in, freq_out, &pll_code);
if (ret < 0) {
dev_err(codec->dev, "Unsupport input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "m_bypass=%d m=%d n=%d k=%d\n",
pll_code.m_bp, (pll_code.m_bp ? 0 : pll_code.m_code),
pll_code.n_code, pll_code.k_code);
regmap_write(rt5677->regmap, RT5677_PLL1_CTRL1,
pll_code.n_code << RT5677_PLL_N_SFT | pll_code.k_code);
regmap_write(rt5677->regmap, RT5677_PLL1_CTRL2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5677_PLL_M_SFT |
pll_code.m_bp << RT5677_PLL_M_BP_SFT);
rt5677->pll_in = freq_in;
rt5677->pll_out = freq_out;
rt5677->pll_src = source;
return 0;
}
static int rt5677_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0, slot_width_25 = 0;
if (rx_mask || tx_mask)
val |= (1 << 12);
switch (slots) {
case 4:
val |= (1 << 10);
break;
case 6:
val |= (2 << 10);
break;
case 8:
val |= (3 << 10);
break;
case 2:
default:
break;
}
switch (slot_width) {
case 20:
val |= (1 << 8);
break;
case 25:
slot_width_25 = 0x8080;
case 24:
val |= (2 << 8);
break;
case 32:
val |= (3 << 8);
break;
case 16:
default:
break;
}
switch (dai->id) {
case RT5677_AIF1:
regmap_update_bits(rt5677->regmap, RT5677_TDM1_CTRL1, 0x1f00,
val);
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC, 0x8000,
slot_width_25);
break;
case RT5677_AIF2:
regmap_update_bits(rt5677->regmap, RT5677_TDM2_CTRL1, 0x1f00,
val);
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC, 0x80,
slot_width_25);
break;
default:
break;
}
return 0;
}
static int rt5677_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_STANDBY) {
rt5677_set_dsp_vad(codec, false);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_LDO1_SEL_MASK | RT5677_LDO2_SEL_MASK,
0x0055);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_BIAS_CUR4,
0x0f00, 0x0f00);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_PWR_FV1 | RT5677_PWR_FV2 |
RT5677_PWR_VREF1 | RT5677_PWR_MB |
RT5677_PWR_BG | RT5677_PWR_VREF2,
RT5677_PWR_VREF1 | RT5677_PWR_MB |
RT5677_PWR_BG | RT5677_PWR_VREF2);
rt5677->is_vref_slow = false;
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG2,
RT5677_PWR_CORE, RT5677_PWR_CORE);
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC,
0x1, 0x1);
}
break;
case SND_SOC_BIAS_STANDBY:
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC, 0x1, 0x0);
regmap_write(rt5677->regmap, RT5677_PWR_DIG1, 0x0000);
regmap_write(rt5677->regmap, RT5677_PWR_DIG2, 0x0000);
regmap_write(rt5677->regmap, RT5677_PWR_ANLG1, 0x0022);
regmap_write(rt5677->regmap, RT5677_PWR_ANLG2, 0x0000);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_BIAS_CUR4, 0x0f00, 0x0000);
if (rt5677->dsp_vad_en)
rt5677_set_dsp_vad(codec, true);
break;
default:
break;
}
return 0;
}
static void rt5677_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct rt5677_priv *rt5677 = gpiochip_get_data(chip);
switch (offset) {
case RT5677_GPIO1 ... RT5677_GPIO5:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL2,
0x1 << (offset * 3 + 1), !!value << (offset * 3 + 1));
break;
case RT5677_GPIO6:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL3,
RT5677_GPIO6_OUT_MASK, !!value << RT5677_GPIO6_OUT_SFT);
break;
default:
break;
}
}
static int rt5677_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct rt5677_priv *rt5677 = gpiochip_get_data(chip);
switch (offset) {
case RT5677_GPIO1 ... RT5677_GPIO5:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL2,
0x3 << (offset * 3 + 1),
(0x2 | !!value) << (offset * 3 + 1));
break;
case RT5677_GPIO6:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL3,
RT5677_GPIO6_DIR_MASK | RT5677_GPIO6_OUT_MASK,
RT5677_GPIO6_DIR_OUT | !!value << RT5677_GPIO6_OUT_SFT);
break;
default:
break;
}
return 0;
}
static int rt5677_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct rt5677_priv *rt5677 = gpiochip_get_data(chip);
int value, ret;
ret = regmap_read(rt5677->regmap, RT5677_GPIO_ST, &value);
if (ret < 0)
return ret;
return (value & (0x1 << offset)) >> offset;
}
static int rt5677_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct rt5677_priv *rt5677 = gpiochip_get_data(chip);
switch (offset) {
case RT5677_GPIO1 ... RT5677_GPIO5:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL2,
0x1 << (offset * 3 + 2), 0x0);
break;
case RT5677_GPIO6:
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL3,
RT5677_GPIO6_DIR_MASK, RT5677_GPIO6_DIR_IN);
break;
default:
break;
}
return 0;
}
static void rt5677_gpio_config(struct rt5677_priv *rt5677, unsigned offset,
int value)
{
int shift;
switch (offset) {
case RT5677_GPIO1 ... RT5677_GPIO2:
shift = 2 * (1 - offset);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_DIG_IN_PIN_ST_CTRL2,
0x3 << shift,
(value & 0x3) << shift);
break;
case RT5677_GPIO3 ... RT5677_GPIO6:
shift = 2 * (9 - offset);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_DIG_IN_PIN_ST_CTRL3,
0x3 << shift,
(value & 0x3) << shift);
break;
default:
break;
}
}
static int rt5677_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct rt5677_priv *rt5677 = gpiochip_get_data(chip);
struct regmap_irq_chip_data *data = rt5677->irq_data;
int irq;
if ((rt5677->pdata.jd1_gpio == 1 && offset == RT5677_GPIO1) ||
(rt5677->pdata.jd1_gpio == 2 &&
offset == RT5677_GPIO2) ||
(rt5677->pdata.jd1_gpio == 3 &&
offset == RT5677_GPIO3)) {
irq = RT5677_IRQ_JD1;
} else if ((rt5677->pdata.jd2_gpio == 1 && offset == RT5677_GPIO4) ||
(rt5677->pdata.jd2_gpio == 2 &&
offset == RT5677_GPIO5) ||
(rt5677->pdata.jd2_gpio == 3 &&
offset == RT5677_GPIO6)) {
irq = RT5677_IRQ_JD2;
} else if ((rt5677->pdata.jd3_gpio == 1 &&
offset == RT5677_GPIO4) ||
(rt5677->pdata.jd3_gpio == 2 &&
offset == RT5677_GPIO5) ||
(rt5677->pdata.jd3_gpio == 3 &&
offset == RT5677_GPIO6)) {
irq = RT5677_IRQ_JD3;
} else {
return -ENXIO;
}
return regmap_irq_get_virq(data, irq);
}
static void rt5677_init_gpio(struct i2c_client *i2c)
{
struct rt5677_priv *rt5677 = i2c_get_clientdata(i2c);
int ret;
rt5677->gpio_chip = rt5677_template_chip;
rt5677->gpio_chip.ngpio = RT5677_GPIO_NUM;
rt5677->gpio_chip.parent = &i2c->dev;
rt5677->gpio_chip.base = -1;
ret = gpiochip_add_data(&rt5677->gpio_chip, rt5677);
if (ret != 0)
dev_err(&i2c->dev, "Failed to add GPIOs: %d\n", ret);
}
static void rt5677_free_gpio(struct i2c_client *i2c)
{
struct rt5677_priv *rt5677 = i2c_get_clientdata(i2c);
gpiochip_remove(&rt5677->gpio_chip);
}
static void rt5677_gpio_config(struct rt5677_priv *rt5677, unsigned offset,
int value)
{
}
static void rt5677_init_gpio(struct i2c_client *i2c)
{
}
static void rt5677_free_gpio(struct i2c_client *i2c)
{
}
static int rt5677_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
int i;
rt5677->codec = codec;
if (rt5677->pdata.dmic2_clk_pin == RT5677_DMIC_CLK2) {
snd_soc_dapm_add_routes(dapm,
rt5677_dmic2_clk_2,
ARRAY_SIZE(rt5677_dmic2_clk_2));
} else {
snd_soc_dapm_add_routes(dapm,
rt5677_dmic2_clk_1,
ARRAY_SIZE(rt5677_dmic2_clk_1));
}
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
regmap_write(rt5677->regmap, RT5677_DIG_MISC, 0x0020);
regmap_write(rt5677->regmap, RT5677_PWR_DSP2, 0x0c00);
for (i = 0; i < RT5677_GPIO_NUM; i++)
rt5677_gpio_config(rt5677, i, rt5677->pdata.gpio_config[i]);
if (rt5677->irq_data) {
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL1, 0x8000,
0x8000);
regmap_update_bits(rt5677->regmap, RT5677_DIG_MISC, 0x0018,
0x0008);
if (rt5677->pdata.jd1_gpio)
regmap_update_bits(rt5677->regmap, RT5677_JD_CTRL1,
RT5677_SEL_GPIO_JD1_MASK,
rt5677->pdata.jd1_gpio <<
RT5677_SEL_GPIO_JD1_SFT);
if (rt5677->pdata.jd2_gpio)
regmap_update_bits(rt5677->regmap, RT5677_JD_CTRL1,
RT5677_SEL_GPIO_JD2_MASK,
rt5677->pdata.jd2_gpio <<
RT5677_SEL_GPIO_JD2_SFT);
if (rt5677->pdata.jd3_gpio)
regmap_update_bits(rt5677->regmap, RT5677_JD_CTRL1,
RT5677_SEL_GPIO_JD3_MASK,
rt5677->pdata.jd3_gpio <<
RT5677_SEL_GPIO_JD3_SFT);
}
mutex_init(&rt5677->dsp_cmd_lock);
mutex_init(&rt5677->dsp_pri_lock);
return 0;
}
static int rt5677_remove(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5677->regmap, RT5677_RESET, 0x10ec);
gpiod_set_value_cansleep(rt5677->pow_ldo2, 0);
gpiod_set_value_cansleep(rt5677->reset_pin, 1);
return 0;
}
static int rt5677_suspend(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
if (!rt5677->dsp_vad_en) {
regcache_cache_only(rt5677->regmap, true);
regcache_mark_dirty(rt5677->regmap);
gpiod_set_value_cansleep(rt5677->pow_ldo2, 0);
gpiod_set_value_cansleep(rt5677->reset_pin, 1);
}
return 0;
}
static int rt5677_resume(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
if (!rt5677->dsp_vad_en) {
rt5677->pll_src = 0;
rt5677->pll_in = 0;
rt5677->pll_out = 0;
gpiod_set_value_cansleep(rt5677->pow_ldo2, 1);
gpiod_set_value_cansleep(rt5677->reset_pin, 0);
if (rt5677->pow_ldo2 || rt5677->reset_pin)
msleep(10);
regcache_cache_only(rt5677->regmap, false);
regcache_sync(rt5677->regmap);
}
return 0;
}
static int rt5677_read(void *context, unsigned int reg, unsigned int *val)
{
struct i2c_client *client = context;
struct rt5677_priv *rt5677 = i2c_get_clientdata(client);
if (rt5677->is_dsp_mode) {
if (reg > 0xff) {
mutex_lock(&rt5677->dsp_pri_lock);
rt5677_dsp_mode_i2c_write(rt5677, RT5677_PRIV_INDEX,
reg & 0xff);
rt5677_dsp_mode_i2c_read(rt5677, RT5677_PRIV_DATA, val);
mutex_unlock(&rt5677->dsp_pri_lock);
} else {
rt5677_dsp_mode_i2c_read(rt5677, reg, val);
}
} else {
regmap_read(rt5677->regmap_physical, reg, val);
}
return 0;
}
static int rt5677_write(void *context, unsigned int reg, unsigned int val)
{
struct i2c_client *client = context;
struct rt5677_priv *rt5677 = i2c_get_clientdata(client);
if (rt5677->is_dsp_mode) {
if (reg > 0xff) {
mutex_lock(&rt5677->dsp_pri_lock);
rt5677_dsp_mode_i2c_write(rt5677, RT5677_PRIV_INDEX,
reg & 0xff);
rt5677_dsp_mode_i2c_write(rt5677, RT5677_PRIV_DATA,
val);
mutex_unlock(&rt5677->dsp_pri_lock);
} else {
rt5677_dsp_mode_i2c_write(rt5677, reg, val);
}
} else {
regmap_write(rt5677->regmap_physical, reg, val);
}
return 0;
}
static void rt5677_read_acpi_properties(struct rt5677_priv *rt5677,
struct device *dev)
{
u32 val;
if (!device_property_read_u32(dev, "DCLK", &val))
rt5677->pdata.dmic2_clk_pin = val;
rt5677->pdata.in1_diff = device_property_read_bool(dev, "IN1");
rt5677->pdata.in2_diff = device_property_read_bool(dev, "IN2");
rt5677->pdata.lout1_diff = device_property_read_bool(dev, "OUT1");
rt5677->pdata.lout2_diff = device_property_read_bool(dev, "OUT2");
rt5677->pdata.lout3_diff = device_property_read_bool(dev, "OUT3");
device_property_read_u32(dev, "JD1", &rt5677->pdata.jd1_gpio);
device_property_read_u32(dev, "JD2", &rt5677->pdata.jd2_gpio);
device_property_read_u32(dev, "JD3", &rt5677->pdata.jd3_gpio);
}
static void rt5677_read_device_properties(struct rt5677_priv *rt5677,
struct device *dev)
{
rt5677->pdata.in1_diff = device_property_read_bool(dev,
"realtek,in1-differential");
rt5677->pdata.in2_diff = device_property_read_bool(dev,
"realtek,in2-differential");
rt5677->pdata.lout1_diff = device_property_read_bool(dev,
"realtek,lout1-differential");
rt5677->pdata.lout2_diff = device_property_read_bool(dev,
"realtek,lout2-differential");
rt5677->pdata.lout3_diff = device_property_read_bool(dev,
"realtek,lout3-differential");
device_property_read_u8_array(dev, "realtek,gpio-config",
rt5677->pdata.gpio_config, RT5677_GPIO_NUM);
device_property_read_u32(dev, "realtek,jd1-gpio",
&rt5677->pdata.jd1_gpio);
device_property_read_u32(dev, "realtek,jd2-gpio",
&rt5677->pdata.jd2_gpio);
device_property_read_u32(dev, "realtek,jd3-gpio",
&rt5677->pdata.jd3_gpio);
}
static int rt5677_init_irq(struct i2c_client *i2c)
{
int ret;
struct rt5677_priv *rt5677 = i2c_get_clientdata(i2c);
if (!rt5677->pdata.jd1_gpio &&
!rt5677->pdata.jd2_gpio &&
!rt5677->pdata.jd3_gpio)
return 0;
if (!i2c->irq) {
dev_err(&i2c->dev, "No interrupt specified\n");
return -EINVAL;
}
ret = regmap_add_irq_chip(rt5677->regmap, i2c->irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_ONESHOT, 0,
&rt5677_irq_chip, &rt5677->irq_data);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register IRQ chip: %d\n", ret);
return ret;
}
return 0;
}
static void rt5677_free_irq(struct i2c_client *i2c)
{
struct rt5677_priv *rt5677 = i2c_get_clientdata(i2c);
if (rt5677->irq_data)
regmap_del_irq_chip(i2c->irq, rt5677->irq_data);
}
static int rt5677_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5677_priv *rt5677;
int ret;
unsigned int val;
rt5677 = devm_kzalloc(&i2c->dev, sizeof(struct rt5677_priv),
GFP_KERNEL);
if (rt5677 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5677);
if (i2c->dev.of_node) {
const struct of_device_id *match_id;
match_id = of_match_device(rt5677_of_match, &i2c->dev);
if (match_id)
rt5677->type = (enum rt5677_type)match_id->data;
rt5677_read_device_properties(rt5677, &i2c->dev);
} else if (ACPI_HANDLE(&i2c->dev)) {
const struct acpi_device_id *acpi_id;
acpi_id = acpi_match_device(rt5677_acpi_match, &i2c->dev);
if (acpi_id)
rt5677->type = (enum rt5677_type)acpi_id->driver_data;
rt5677_read_acpi_properties(rt5677, &i2c->dev);
} else {
return -EINVAL;
}
rt5677->pow_ldo2 = devm_gpiod_get_optional(&i2c->dev,
"realtek,pow-ldo2", GPIOD_OUT_HIGH);
if (IS_ERR(rt5677->pow_ldo2)) {
ret = PTR_ERR(rt5677->pow_ldo2);
dev_err(&i2c->dev, "Failed to request POW_LDO2: %d\n", ret);
return ret;
}
rt5677->reset_pin = devm_gpiod_get_optional(&i2c->dev,
"realtek,reset", GPIOD_OUT_LOW);
if (IS_ERR(rt5677->reset_pin)) {
ret = PTR_ERR(rt5677->reset_pin);
dev_err(&i2c->dev, "Failed to request RESET: %d\n", ret);
return ret;
}
if (rt5677->pow_ldo2 || rt5677->reset_pin) {
msleep(10);
}
rt5677->regmap_physical = devm_regmap_init_i2c(i2c,
&rt5677_regmap_physical);
if (IS_ERR(rt5677->regmap_physical)) {
ret = PTR_ERR(rt5677->regmap_physical);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
rt5677->regmap = devm_regmap_init(&i2c->dev, NULL, i2c, &rt5677_regmap);
if (IS_ERR(rt5677->regmap)) {
ret = PTR_ERR(rt5677->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5677->regmap, RT5677_VENDOR_ID2, &val);
if (val != RT5677_DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt5677\n", val);
return -ENODEV;
}
regmap_write(rt5677->regmap, RT5677_RESET, 0x10ec);
ret = regmap_register_patch(rt5677->regmap, init_list,
ARRAY_SIZE(init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
if (rt5677->pdata.in1_diff)
regmap_update_bits(rt5677->regmap, RT5677_IN1,
RT5677_IN_DF1, RT5677_IN_DF1);
if (rt5677->pdata.in2_diff)
regmap_update_bits(rt5677->regmap, RT5677_IN1,
RT5677_IN_DF2, RT5677_IN_DF2);
if (rt5677->pdata.lout1_diff)
regmap_update_bits(rt5677->regmap, RT5677_LOUT1,
RT5677_LOUT1_L_DF, RT5677_LOUT1_L_DF);
if (rt5677->pdata.lout2_diff)
regmap_update_bits(rt5677->regmap, RT5677_LOUT1,
RT5677_LOUT2_L_DF, RT5677_LOUT2_L_DF);
if (rt5677->pdata.lout3_diff)
regmap_update_bits(rt5677->regmap, RT5677_LOUT1,
RT5677_LOUT3_L_DF, RT5677_LOUT3_L_DF);
if (rt5677->pdata.dmic2_clk_pin == RT5677_DMIC_CLK2) {
regmap_update_bits(rt5677->regmap, RT5677_GEN_CTRL2,
RT5677_GPIO5_FUNC_MASK,
RT5677_GPIO5_FUNC_DMIC);
regmap_update_bits(rt5677->regmap, RT5677_GPIO_CTRL2,
RT5677_GPIO5_DIR_MASK,
RT5677_GPIO5_DIR_OUT);
}
if (rt5677->pdata.micbias1_vdd_3v3)
regmap_update_bits(rt5677->regmap, RT5677_MICBIAS,
RT5677_MICBIAS1_CTRL_VDD_MASK,
RT5677_MICBIAS1_CTRL_VDD_3_3V);
rt5677_init_gpio(i2c);
rt5677_init_irq(i2c);
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5677,
rt5677_dai, ARRAY_SIZE(rt5677_dai));
}
static int rt5677_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
rt5677_free_irq(i2c);
rt5677_free_gpio(i2c);
return 0;
}
