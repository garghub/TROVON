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
case RT5677_PLL1_CTRL2:
case RT5677_PLL2_CTRL2:
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
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
int idx = rl6231_calc_dmic_clk(rt5677->sysclk);
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
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(source->codec);
unsigned int val;
regmap_read(rt5677->regmap, RT5677_GLB_CLK1, &val);
val &= RT5677_SCLK_SRC_MASK;
if (val == RT5677_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int rt5677_bst1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
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
struct snd_soc_codec *codec = w->codec;
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
struct snd_soc_codec *codec = w->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL1_CTRL2, 0x2, 0x2);
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
struct snd_soc_codec *codec = w->codec;
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5677->regmap, RT5677_PLL2_CTRL2, 0x2, 0x2);
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
struct snd_soc_codec *codec = w->codec;
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
dev_err(codec->dev, "Unsupported clock setting\n");
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
static int rt5677_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY) {
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_LDO1_SEL_MASK | RT5677_LDO2_SEL_MASK,
0x0055);
regmap_update_bits(rt5677->regmap,
RT5677_PR_BASE + RT5677_BIAS_CUR4,
0x0f00, 0x0f00);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_PWR_VREF1 | RT5677_PWR_MB |
RT5677_PWR_BG | RT5677_PWR_VREF2,
RT5677_PWR_VREF1 | RT5677_PWR_MB |
RT5677_PWR_BG | RT5677_PWR_VREF2);
mdelay(20);
regmap_update_bits(rt5677->regmap, RT5677_PWR_ANLG1,
RT5677_PWR_FV1 | RT5677_PWR_FV2,
RT5677_PWR_FV1 | RT5677_PWR_FV2);
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
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int rt5677_probe(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
rt5677->codec = codec;
rt5677_set_bias_level(codec, SND_SOC_BIAS_OFF);
regmap_write(rt5677->regmap, RT5677_DIG_MISC, 0x0020);
regmap_write(rt5677->regmap, RT5677_PWR_DSP2, 0x0c00);
return 0;
}
static int rt5677_remove(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5677->regmap, RT5677_RESET, 0x10ec);
return 0;
}
static int rt5677_suspend(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5677->regmap, true);
regcache_mark_dirty(rt5677->regmap);
return 0;
}
static int rt5677_resume(struct snd_soc_codec *codec)
{
struct rt5677_priv *rt5677 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5677->regmap, false);
regcache_sync(rt5677->regmap);
return 0;
}
static int rt5677_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5677_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5677_priv *rt5677;
int ret;
unsigned int val;
rt5677 = devm_kzalloc(&i2c->dev, sizeof(struct rt5677_priv),
GFP_KERNEL);
if (rt5677 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5677);
if (pdata)
rt5677->pdata = *pdata;
rt5677->regmap = devm_regmap_init_i2c(i2c, &rt5677_regmap);
if (IS_ERR(rt5677->regmap)) {
ret = PTR_ERR(rt5677->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5677->regmap, RT5677_VENDOR_ID2, &val);
if (val != RT5677_DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt5677\n", val);
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
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5677,
rt5677_dai, ARRAY_SIZE(rt5677_dai));
}
static int rt5677_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
