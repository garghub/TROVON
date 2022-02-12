static bool nau8540_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8540_REG_POWER_MANAGEMENT ... NAU8540_REG_FLL_VCO_RSV:
case NAU8540_REG_PCM_CTRL0 ... NAU8540_REG_PCM_CTRL4:
case NAU8540_REG_ALC_CONTROL_1 ... NAU8540_REG_ALC_CONTROL_5:
case NAU8540_REG_ALC_GAIN_CH12 ... NAU8540_REG_ADC_SAMPLE_RATE:
case NAU8540_REG_DIGITAL_GAIN_CH1 ... NAU8540_REG_DIGITAL_MUX:
case NAU8540_REG_P2P_CH1 ... NAU8540_REG_I2C_CTRL:
case NAU8540_REG_I2C_DEVICE_ID:
case NAU8540_REG_VMID_CTRL ... NAU8540_REG_MUTE:
case NAU8540_REG_ANALOG_ADC1 ... NAU8540_REG_PWR:
return true;
default:
return false;
}
}
static bool nau8540_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8540_REG_SW_RESET ... NAU8540_REG_FLL_VCO_RSV:
case NAU8540_REG_PCM_CTRL0 ... NAU8540_REG_PCM_CTRL4:
case NAU8540_REG_ALC_CONTROL_1 ... NAU8540_REG_ALC_CONTROL_5:
case NAU8540_REG_NOTCH_FIL1_CH1 ... NAU8540_REG_ADC_SAMPLE_RATE:
case NAU8540_REG_DIGITAL_GAIN_CH1 ... NAU8540_REG_DIGITAL_MUX:
case NAU8540_REG_GPIO_CTRL ... NAU8540_REG_I2C_CTRL:
case NAU8540_REG_RST:
case NAU8540_REG_VMID_CTRL ... NAU8540_REG_MUTE:
case NAU8540_REG_ANALOG_ADC1 ... NAU8540_REG_PWR:
return true;
default:
return false;
}
}
static bool nau8540_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8540_REG_SW_RESET:
case NAU8540_REG_ALC_GAIN_CH12 ... NAU8540_REG_ALC_STATUS:
case NAU8540_REG_P2P_CH1 ... NAU8540_REG_PEAK_CH4:
case NAU8540_REG_I2C_DEVICE_ID:
case NAU8540_REG_RST:
return true;
default:
return false;
}
}
static int nau8540_clock_check(struct nau8540 *nau8540, int rate, int osr)
{
int osrate;
if (osr >= ARRAY_SIZE(osr_adc_sel))
return -EINVAL;
osrate = osr_adc_sel[osr].osr;
if (rate * osr > CLK_ADC_MAX) {
dev_err(nau8540->dev, "exceed the maximum frequency of CLK_ADC\n");
return -EINVAL;
}
return 0;
}
static int nau8540_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, osr;
regmap_read(nau8540->regmap, NAU8540_REG_ADC_SAMPLE_RATE, &osr);
osr &= NAU8540_ADC_OSR_MASK;
if (nau8540_clock_check(nau8540, params_rate(params), osr))
return -EINVAL;
regmap_update_bits(nau8540->regmap, NAU8540_REG_CLOCK_SRC,
NAU8540_CLK_ADC_SRC_MASK,
osr_adc_sel[osr].clk_src << NAU8540_CLK_ADC_SRC_SFT);
switch (params_width(params)) {
case 16:
val_len |= NAU8540_I2S_DL_16;
break;
case 20:
val_len |= NAU8540_I2S_DL_20;
break;
case 24:
val_len |= NAU8540_I2S_DL_24;
break;
case 32:
val_len |= NAU8540_I2S_DL_32;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL0,
NAU8540_I2S_DL_MASK, val_len);
return 0;
}
static int nau8540_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
unsigned int ctrl1_val = 0, ctrl2_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl2_val |= NAU8540_I2S_MS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl1_val |= NAU8540_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl1_val |= NAU8540_I2S_DF_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1_val |= NAU8540_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl1_val |= NAU8540_I2S_DF_RIGTH;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1_val |= NAU8540_I2S_DF_PCM_AB;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl1_val |= NAU8540_I2S_DF_PCM_AB;
ctrl1_val |= NAU8540_I2S_PCMB_EN;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL0,
NAU8540_I2S_DL_MASK | NAU8540_I2S_DF_MASK |
NAU8540_I2S_BP_INV | NAU8540_I2S_PCMB_EN, ctrl1_val);
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL1,
NAU8540_I2S_MS_MASK | NAU8540_I2S_DO12_OE, ctrl2_val);
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL2,
NAU8540_I2S_DO34_OE, 0);
return 0;
}
static int nau8540_set_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
unsigned int ctrl2_val = 0, ctrl4_val = 0;
if (slots > 4 || ((tx_mask & 0xf0) && (tx_mask & 0xf)))
return -EINVAL;
ctrl4_val |= (NAU8540_TDM_MODE | NAU8540_TDM_OFFSET_EN);
if (tx_mask & 0xf0) {
ctrl2_val = 4 * slot_width;
ctrl4_val |= (tx_mask >> 4);
} else {
ctrl4_val |= tx_mask;
}
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL4,
NAU8540_TDM_MODE | NAU8540_TDM_OFFSET_EN |
NAU8540_TDM_TX_MASK, ctrl4_val);
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL1,
NAU8540_I2S_DO12_OE, NAU8540_I2S_DO12_OE);
regmap_update_bits(nau8540->regmap, NAU8540_REG_PCM_CTRL2,
NAU8540_I2S_DO34_OE | NAU8540_I2S_TSLOT_L_MASK,
NAU8540_I2S_DO34_OE | ctrl2_val);
return 0;
}
static int nau8540_calc_fll_param(unsigned int fll_in,
unsigned int fs, struct nau8540_fll *fll_param)
{
u64 fvco, fvco_max;
unsigned int fref, i, fvco_sel;
for (i = 0; i < ARRAY_SIZE(fll_pre_scalar); i++) {
fref = fll_in / fll_pre_scalar[i].param;
if (fref <= NAU_FREF_MAX)
break;
}
if (i == ARRAY_SIZE(fll_pre_scalar))
return -EINVAL;
fll_param->clk_ref_div = fll_pre_scalar[i].val;
for (i = 0; i < ARRAY_SIZE(fll_ratio); i++) {
if (fref >= fll_ratio[i].param)
break;
}
if (i == ARRAY_SIZE(fll_ratio))
return -EINVAL;
fll_param->ratio = fll_ratio[i].val;
fvco_max = 0;
fvco_sel = ARRAY_SIZE(mclk_src_scaling);
for (i = 0; i < ARRAY_SIZE(mclk_src_scaling); i++) {
fvco = 256 * fs * 2 * mclk_src_scaling[i].param;
if (fvco > NAU_FVCO_MIN && fvco < NAU_FVCO_MAX &&
fvco_max < fvco) {
fvco_max = fvco;
fvco_sel = i;
}
}
if (ARRAY_SIZE(mclk_src_scaling) == fvco_sel)
return -EINVAL;
fll_param->mclk_src = mclk_src_scaling[fvco_sel].val;
fvco = div_u64(fvco_max << 16, fref * fll_param->ratio);
fll_param->fll_int = (fvco >> 16) & 0x3FF;
fll_param->fll_frac = fvco & 0xFFFF;
return 0;
}
static void nau8540_fll_apply(struct regmap *regmap,
struct nau8540_fll *fll_param)
{
regmap_update_bits(regmap, NAU8540_REG_CLOCK_SRC,
NAU8540_CLK_SRC_MASK | NAU8540_CLK_MCLK_SRC_MASK,
NAU8540_CLK_SRC_MCLK | fll_param->mclk_src);
regmap_update_bits(regmap, NAU8540_REG_FLL1,
NAU8540_FLL_RATIO_MASK, fll_param->ratio);
regmap_write(regmap, NAU8540_REG_FLL2, fll_param->fll_frac);
regmap_update_bits(regmap, NAU8540_REG_FLL3,
NAU8540_FLL_INTEGER_MASK, fll_param->fll_int);
regmap_update_bits(regmap, NAU8540_REG_FLL4,
NAU8540_FLL_REF_DIV_MASK,
fll_param->clk_ref_div << NAU8540_FLL_REF_DIV_SFT);
regmap_update_bits(regmap, NAU8540_REG_FLL5,
NAU8540_FLL_CLK_SW_MASK, NAU8540_FLL_CLK_SW_REF);
regmap_update_bits(regmap,
NAU8540_REG_FLL6, NAU8540_DCO_EN, 0);
if (fll_param->fll_frac) {
regmap_update_bits(regmap, NAU8540_REG_FLL5,
NAU8540_FLL_PDB_DAC_EN | NAU8540_FLL_LOOP_FTR_EN |
NAU8540_FLL_FTR_SW_MASK,
NAU8540_FLL_PDB_DAC_EN | NAU8540_FLL_LOOP_FTR_EN |
NAU8540_FLL_FTR_SW_FILTER);
regmap_update_bits(regmap, NAU8540_REG_FLL6,
NAU8540_SDM_EN, NAU8540_SDM_EN);
} else {
regmap_update_bits(regmap, NAU8540_REG_FLL5,
NAU8540_FLL_PDB_DAC_EN | NAU8540_FLL_LOOP_FTR_EN |
NAU8540_FLL_FTR_SW_MASK, NAU8540_FLL_FTR_SW_ACCU);
regmap_update_bits(regmap,
NAU8540_REG_FLL6, NAU8540_SDM_EN, 0);
}
}
static int nau8540_set_pll(struct snd_soc_codec *codec, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
struct nau8540_fll fll_param;
int ret, fs;
switch (pll_id) {
case NAU8540_CLK_FLL_MCLK:
regmap_update_bits(nau8540->regmap, NAU8540_REG_FLL3,
NAU8540_FLL_CLK_SRC_MASK, NAU8540_FLL_CLK_SRC_MCLK);
break;
case NAU8540_CLK_FLL_BLK:
regmap_update_bits(nau8540->regmap, NAU8540_REG_FLL3,
NAU8540_FLL_CLK_SRC_MASK, NAU8540_FLL_CLK_SRC_BLK);
break;
case NAU8540_CLK_FLL_FS:
regmap_update_bits(nau8540->regmap, NAU8540_REG_FLL3,
NAU8540_FLL_CLK_SRC_MASK, NAU8540_FLL_CLK_SRC_FS);
break;
default:
dev_err(nau8540->dev, "Invalid clock id (%d)\n", pll_id);
return -EINVAL;
}
dev_dbg(nau8540->dev, "Sysclk is %dHz and clock id is %d\n",
freq_out, pll_id);
fs = freq_out / 256;
ret = nau8540_calc_fll_param(freq_in, fs, &fll_param);
if (ret < 0) {
dev_err(nau8540->dev, "Unsupported input clock %d\n", freq_in);
return ret;
}
dev_dbg(nau8540->dev, "mclk_src=%x ratio=%x fll_frac=%x fll_int=%x clk_ref_div=%x\n",
fll_param.mclk_src, fll_param.ratio, fll_param.fll_frac,
fll_param.fll_int, fll_param.clk_ref_div);
nau8540_fll_apply(nau8540->regmap, &fll_param);
mdelay(2);
regmap_update_bits(nau8540->regmap, NAU8540_REG_CLOCK_SRC,
NAU8540_CLK_SRC_MASK, NAU8540_CLK_SRC_VCO);
return 0;
}
static int nau8540_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq, int dir)
{
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case NAU8540_CLK_DIS:
case NAU8540_CLK_MCLK:
regmap_update_bits(nau8540->regmap, NAU8540_REG_CLOCK_SRC,
NAU8540_CLK_SRC_MASK, NAU8540_CLK_SRC_MCLK);
regmap_update_bits(nau8540->regmap, NAU8540_REG_FLL6,
NAU8540_DCO_EN, 0);
break;
case NAU8540_CLK_INTERNAL:
regmap_update_bits(nau8540->regmap, NAU8540_REG_FLL6,
NAU8540_DCO_EN, NAU8540_DCO_EN);
regmap_update_bits(nau8540->regmap, NAU8540_REG_CLOCK_SRC,
NAU8540_CLK_SRC_MASK, NAU8540_CLK_SRC_VCO);
break;
default:
dev_err(nau8540->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
dev_dbg(nau8540->dev, "Sysclk is %dHz and clock id is %d\n",
freq, clk_id);
return 0;
}
static void nau8540_reset_chip(struct regmap *regmap)
{
regmap_write(regmap, NAU8540_REG_SW_RESET, 0x00);
regmap_write(regmap, NAU8540_REG_SW_RESET, 0x00);
}
static void nau8540_init_regs(struct nau8540 *nau8540)
{
struct regmap *regmap = nau8540->regmap;
regmap_update_bits(regmap, NAU8540_REG_VMID_CTRL,
NAU8540_VMID_EN | NAU8540_VMID_SEL_MASK,
NAU8540_VMID_EN | (0x2 << NAU8540_VMID_SEL_SFT));
regmap_update_bits(regmap, NAU8540_REG_REFERENCE,
NAU8540_PRECHARGE_DIS | NAU8540_GLOBAL_BIAS_EN,
NAU8540_PRECHARGE_DIS | NAU8540_GLOBAL_BIAS_EN);
mdelay(2);
regmap_update_bits(regmap, NAU8540_REG_MIC_BIAS,
NAU8540_PU_PRE, NAU8540_PU_PRE);
regmap_update_bits(regmap, NAU8540_REG_CLOCK_CTRL,
NAU8540_CLK_ADC_EN | NAU8540_CLK_I2S_EN,
NAU8540_CLK_ADC_EN | NAU8540_CLK_I2S_EN);
regmap_update_bits(regmap, NAU8540_REG_ADC_SAMPLE_RATE,
NAU8540_ADC_OSR_MASK, NAU8540_ADC_OSR_64);
}
static int __maybe_unused nau8540_suspend(struct snd_soc_codec *codec)
{
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(nau8540->regmap, true);
regcache_mark_dirty(nau8540->regmap);
return 0;
}
static int __maybe_unused nau8540_resume(struct snd_soc_codec *codec)
{
struct nau8540 *nau8540 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(nau8540->regmap, false);
regcache_sync(nau8540->regmap);
return 0;
}
static int nau8540_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct nau8540 *nau8540 = dev_get_platdata(dev);
int ret, value;
if (!nau8540) {
nau8540 = devm_kzalloc(dev, sizeof(*nau8540), GFP_KERNEL);
if (!nau8540)
return -ENOMEM;
}
i2c_set_clientdata(i2c, nau8540);
nau8540->regmap = devm_regmap_init_i2c(i2c, &nau8540_regmap_config);
if (IS_ERR(nau8540->regmap))
return PTR_ERR(nau8540->regmap);
ret = regmap_read(nau8540->regmap, NAU8540_REG_I2C_DEVICE_ID, &value);
if (ret < 0) {
dev_err(dev, "Failed to read device id from the NAU85L40: %d\n",
ret);
return ret;
}
nau8540->dev = dev;
nau8540_reset_chip(nau8540->regmap);
nau8540_init_regs(nau8540);
return snd_soc_register_codec(dev,
&nau8540_codec_driver, &nau8540_dai, 1);
}
static int nau8540_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
