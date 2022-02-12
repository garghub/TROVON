static bool nau8810_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8810_REG_RESET ... NAU8810_REG_SMPLR:
case NAU8810_REG_DAC ... NAU8810_REG_DACGAIN:
case NAU8810_REG_ADC ... NAU8810_REG_ADCGAIN:
case NAU8810_REG_EQ1 ... NAU8810_REG_EQ5:
case NAU8810_REG_DACLIM1 ... NAU8810_REG_DACLIM2:
case NAU8810_REG_NOTCH1 ... NAU8810_REG_NOTCH4:
case NAU8810_REG_ALC1 ... NAU8810_REG_ATTEN:
case NAU8810_REG_INPUT_SIGNAL ... NAU8810_REG_PGAGAIN:
case NAU8810_REG_ADCBOOST:
case NAU8810_REG_OUTPUT ... NAU8810_REG_SPKMIX:
case NAU8810_REG_SPKGAIN:
case NAU8810_REG_MONOMIX:
case NAU8810_REG_POWER4 ... NAU8810_REG_TSLOTCTL2:
case NAU8810_REG_DEVICE_REVID ... NAU8810_REG_RESERVE:
case NAU8810_REG_OUTCTL ... NAU8810_REG_ALC1ENHAN2:
case NAU8810_REG_MISCCTL:
case NAU8810_REG_OUTTIEOFF ... NAU8810_REG_OUTTIEOFFMAN:
return true;
default:
return false;
}
}
static bool nau8810_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8810_REG_RESET ... NAU8810_REG_SMPLR:
case NAU8810_REG_DAC ... NAU8810_REG_DACGAIN:
case NAU8810_REG_ADC ... NAU8810_REG_ADCGAIN:
case NAU8810_REG_EQ1 ... NAU8810_REG_EQ5:
case NAU8810_REG_DACLIM1 ... NAU8810_REG_DACLIM2:
case NAU8810_REG_NOTCH1 ... NAU8810_REG_NOTCH4:
case NAU8810_REG_ALC1 ... NAU8810_REG_ATTEN:
case NAU8810_REG_INPUT_SIGNAL ... NAU8810_REG_PGAGAIN:
case NAU8810_REG_ADCBOOST:
case NAU8810_REG_OUTPUT ... NAU8810_REG_SPKMIX:
case NAU8810_REG_SPKGAIN:
case NAU8810_REG_MONOMIX:
case NAU8810_REG_POWER4 ... NAU8810_REG_TSLOTCTL2:
case NAU8810_REG_OUTCTL ... NAU8810_REG_ALC1ENHAN2:
case NAU8810_REG_MISCCTL:
case NAU8810_REG_OUTTIEOFF ... NAU8810_REG_OUTTIEOFFMAN:
return true;
default:
return false;
}
}
static bool nau8810_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8810_REG_RESET:
case NAU8810_REG_DEVICE_REVID ... NAU8810_REG_RESERVE:
return true;
default:
return false;
}
}
static int nau8810_eq_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
struct soc_bytes_ext *params = (void *)kcontrol->private_value;
int i, reg, reg_val;
u16 *val;
val = (u16 *)ucontrol->value.bytes.data;
reg = NAU8810_REG_EQ1;
for (i = 0; i < params->max / sizeof(u16); i++) {
regmap_read(nau8810->regmap, reg + i, &reg_val);
reg_val = cpu_to_be16(reg_val);
memcpy(val + i, &reg_val, sizeof(reg_val));
}
return 0;
}
static int nau8810_eq_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
struct soc_bytes_ext *params = (void *)kcontrol->private_value;
void *data;
u16 *val, value;
int i, reg, ret;
data = kmemdup(ucontrol->value.bytes.data,
params->max, GFP_KERNEL | GFP_DMA);
if (!data)
return -ENOMEM;
val = (u16 *)data;
reg = NAU8810_REG_EQ1;
for (i = 0; i < params->max / sizeof(u16); i++) {
value = be16_to_cpu(*(val + i));
ret = regmap_write(nau8810->regmap, reg + i, value);
if (ret) {
dev_err(codec->dev, "EQ configuration fail, register: %x ret: %d\n",
reg + i, ret);
kfree(data);
return ret;
}
}
kfree(data);
return 0;
}
static int check_mclk_select_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
unsigned int value;
regmap_read(nau8810->regmap, NAU8810_REG_CLOCK, &value);
return (value & NAU8810_CLKM_MASK);
}
static int nau8810_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
nau8810->clk_id = clk_id;
nau8810->sysclk = freq;
dev_dbg(nau8810->dev, "master sysclk %dHz, source %s\n",
freq, clk_id == NAU8810_SCLK_PLL ? "PLL" : "MCLK");
return 0;
}
static int nau88l0_calc_pll(unsigned int pll_in,
unsigned int fs, struct nau8810_pll *pll_param)
{
u64 f2, f2_max, pll_ratio;
int i, scal_sel;
if (pll_in > NAU_PLL_REF_MAX || pll_in < NAU_PLL_REF_MIN)
return -EINVAL;
f2_max = 0;
scal_sel = ARRAY_SIZE(nau8810_mclk_scaler);
for (i = 0; i < ARRAY_SIZE(nau8810_mclk_scaler); i++) {
f2 = 256 * fs * 4 * nau8810_mclk_scaler[i] / 10;
if (f2 > NAU_PLL_FREQ_MIN && f2 < NAU_PLL_FREQ_MAX &&
f2_max < f2) {
f2_max = f2;
scal_sel = i;
}
}
if (ARRAY_SIZE(nau8810_mclk_scaler) == scal_sel)
return -EINVAL;
pll_param->mclk_scaler = scal_sel;
f2 = f2_max;
pll_ratio = div_u64(f2 << 28, pll_in);
pll_param->pre_factor = 0;
if (((pll_ratio >> 28) & 0xF) < NAU_PLL_OPTOP_MIN) {
pll_ratio <<= 1;
pll_param->pre_factor = 1;
}
pll_param->pll_int = (pll_ratio >> 28) & 0xF;
pll_param->pll_frac = ((pll_ratio & 0xFFFFFFF) >> 4);
return 0;
}
static int nau8810_set_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
struct regmap *map = nau8810->regmap;
struct nau8810_pll *pll_param = &nau8810->pll;
int ret, fs;
fs = freq_out / 256;
ret = nau88l0_calc_pll(freq_in, fs, pll_param);
if (ret < 0) {
dev_err(nau8810->dev, "Unsupported input clock %d\n", freq_in);
return ret;
}
dev_info(nau8810->dev, "pll_int=%x pll_frac=%x mclk_scaler=%x pre_factor=%x\n",
pll_param->pll_int, pll_param->pll_frac, pll_param->mclk_scaler,
pll_param->pre_factor);
regmap_update_bits(map, NAU8810_REG_PLLN,
NAU8810_PLLMCLK_DIV2 | NAU8810_PLLN_MASK,
(pll_param->pre_factor ? NAU8810_PLLMCLK_DIV2 : 0) |
pll_param->pll_int);
regmap_write(map, NAU8810_REG_PLLK1,
(pll_param->pll_frac >> NAU8810_PLLK1_SFT) &
NAU8810_PLLK1_MASK);
regmap_write(map, NAU8810_REG_PLLK2,
(pll_param->pll_frac >> NAU8810_PLLK2_SFT) &
NAU8810_PLLK2_MASK);
regmap_write(map, NAU8810_REG_PLLK3,
pll_param->pll_frac & NAU8810_PLLK3_MASK);
regmap_update_bits(map, NAU8810_REG_CLOCK, NAU8810_MCLKSEL_MASK,
pll_param->mclk_scaler << NAU8810_MCLKSEL_SFT);
regmap_update_bits(map, NAU8810_REG_CLOCK,
NAU8810_CLKM_MASK, NAU8810_CLKM_PLL);
return 0;
}
static int nau8810_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
u16 ctrl1_val = 0, ctrl2_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl2_val |= NAU8810_CLKIO_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl1_val |= NAU8810_AIFMT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1_val |= NAU8810_AIFMT_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1_val |= NAU8810_AIFMT_PCM_A;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
ctrl1_val |= NAU8810_BCLKP_IB | NAU8810_FSP_IF;
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl1_val |= NAU8810_BCLKP_IB;
break;
case SND_SOC_DAIFMT_NB_IF:
ctrl1_val |= NAU8810_FSP_IF;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8810->regmap, NAU8810_REG_IFACE,
NAU8810_AIFMT_MASK | NAU8810_FSP_IF |
NAU8810_BCLKP_IB, ctrl1_val);
regmap_update_bits(nau8810->regmap, NAU8810_REG_CLOCK,
NAU8810_CLKIO_MASK, ctrl2_val);
return 0;
}
static int nau8810_mclk_clkdiv(struct nau8810 *nau8810, int rate)
{
int i, sclk, imclk = rate * 256, div = 0;
if (!nau8810->sysclk) {
dev_err(nau8810->dev, "Make mclk div configuration fail because of invalid system clock\n");
return -EINVAL;
}
for (i = 1; i < ARRAY_SIZE(nau8810_mclk_scaler); i++) {
sclk = (nau8810->sysclk * 10) /
nau8810_mclk_scaler[i];
if (sclk < imclk)
break;
div = i;
}
dev_dbg(nau8810->dev,
"master clock prescaler %x for fs %d\n", div, rate);
regmap_update_bits(nau8810->regmap, NAU8810_REG_CLOCK,
NAU8810_MCLKSEL_MASK, (div << NAU8810_MCLKSEL_SFT));
regmap_update_bits(nau8810->regmap, NAU8810_REG_CLOCK,
NAU8810_CLKM_MASK, NAU8810_CLKM_MCLK);
return 0;
}
static int nau8810_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
int val_len = 0, val_rate = 0, ret = 0;
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= NAU8810_WLEN_20;
break;
case 24:
val_len |= NAU8810_WLEN_24;
break;
case 32:
val_len |= NAU8810_WLEN_32;
break;
}
switch (params_rate(params)) {
case 8000:
val_rate |= NAU8810_SMPLR_8K;
break;
case 11025:
val_rate |= NAU8810_SMPLR_12K;
break;
case 16000:
val_rate |= NAU8810_SMPLR_16K;
break;
case 22050:
val_rate |= NAU8810_SMPLR_24K;
break;
case 32000:
val_rate |= NAU8810_SMPLR_32K;
break;
case 44100:
case 48000:
break;
}
regmap_update_bits(nau8810->regmap, NAU8810_REG_IFACE,
NAU8810_WLEN_MASK, val_len);
regmap_update_bits(nau8810->regmap, NAU8810_REG_SMPLR,
NAU8810_SMPLR_MASK, val_rate);
if (nau8810->clk_id == NAU8810_SCLK_MCLK) {
ret = nau8810_mclk_clkdiv(nau8810, params_rate(params));
if (ret < 0)
dev_err(nau8810->dev, "MCLK div configuration fail\n");
}
return ret;
}
static int nau8810_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct nau8810 *nau8810 = snd_soc_codec_get_drvdata(codec);
struct regmap *map = nau8810->regmap;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(map, NAU8810_REG_POWER1,
NAU8810_REFIMP_MASK, NAU8810_REFIMP_80K);
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(map, NAU8810_REG_POWER1,
NAU8810_IOBUF_EN | NAU8810_ABIAS_EN,
NAU8810_IOBUF_EN | NAU8810_ABIAS_EN);
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
regcache_sync(map);
regmap_update_bits(map, NAU8810_REG_POWER1,
NAU8810_REFIMP_MASK, NAU8810_REFIMP_3K);
mdelay(100);
}
regmap_update_bits(map, NAU8810_REG_POWER1,
NAU8810_REFIMP_MASK, NAU8810_REFIMP_300K);
break;
case SND_SOC_BIAS_OFF:
regmap_write(map, NAU8810_REG_POWER1, 0);
regmap_write(map, NAU8810_REG_POWER2, 0);
regmap_write(map, NAU8810_REG_POWER3, 0);
break;
}
return 0;
}
static int nau8810_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct nau8810 *nau8810 = dev_get_platdata(dev);
if (!nau8810) {
nau8810 = devm_kzalloc(dev, sizeof(*nau8810), GFP_KERNEL);
if (!nau8810)
return -ENOMEM;
}
i2c_set_clientdata(i2c, nau8810);
nau8810->regmap = devm_regmap_init_i2c(i2c, &nau8810_regmap_config);
if (IS_ERR(nau8810->regmap))
return PTR_ERR(nau8810->regmap);
nau8810->dev = dev;
regmap_write(nau8810->regmap, NAU8810_REG_RESET, 0x00);
return snd_soc_register_codec(dev,
&nau8810_codec_driver, &nau8810_dai, 1);
}
static int nau8810_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
