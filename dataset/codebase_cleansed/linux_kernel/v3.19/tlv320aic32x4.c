static inline int aic32x4_get_divs(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(aic32x4_divs); i++) {
if ((aic32x4_divs[i].rate == rate)
&& (aic32x4_divs[i].mclk == mclk)) {
return i;
}
}
printk(KERN_ERR "aic32x4: master clock and sample rate is not supported\n");
return -EINVAL;
}
static int aic32x4_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic32x4_priv *aic32x4 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case AIC32X4_FREQ_12000000:
case AIC32X4_FREQ_24000000:
case AIC32X4_FREQ_25000000:
aic32x4->sysclk = freq;
return 0;
}
printk(KERN_ERR "aic32x4: invalid frequency to set DAI system clock\n");
return -EINVAL;
}
static int aic32x4_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 iface_reg_1;
u8 iface_reg_2;
u8 iface_reg_3;
iface_reg_1 = snd_soc_read(codec, AIC32X4_IFACE1);
iface_reg_1 = iface_reg_1 & ~(3 << 6 | 3 << 2);
iface_reg_2 = snd_soc_read(codec, AIC32X4_IFACE2);
iface_reg_2 = 0;
iface_reg_3 = snd_soc_read(codec, AIC32X4_IFACE3);
iface_reg_3 = iface_reg_3 & ~(1 << 3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface_reg_1 |= AIC32X4_BCLKMASTER | AIC32X4_WCLKMASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
printk(KERN_ERR "aic32x4: invalid DAI master/slave interface\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_DSP_A:
iface_reg_1 |= (AIC32X4_DSP_MODE << AIC32X4_PLLJ_SHIFT);
iface_reg_3 |= (1 << 3);
iface_reg_2 = 0x01;
break;
case SND_SOC_DAIFMT_DSP_B:
iface_reg_1 |= (AIC32X4_DSP_MODE << AIC32X4_PLLJ_SHIFT);
iface_reg_3 |= (1 << 3);
break;
case SND_SOC_DAIFMT_RIGHT_J:
iface_reg_1 |=
(AIC32X4_RIGHT_JUSTIFIED_MODE << AIC32X4_PLLJ_SHIFT);
break;
case SND_SOC_DAIFMT_LEFT_J:
iface_reg_1 |=
(AIC32X4_LEFT_JUSTIFIED_MODE << AIC32X4_PLLJ_SHIFT);
break;
default:
printk(KERN_ERR "aic32x4: invalid DAI interface format\n");
return -EINVAL;
}
snd_soc_write(codec, AIC32X4_IFACE1, iface_reg_1);
snd_soc_write(codec, AIC32X4_IFACE2, iface_reg_2);
snd_soc_write(codec, AIC32X4_IFACE3, iface_reg_3);
return 0;
}
static int aic32x4_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct aic32x4_priv *aic32x4 = snd_soc_codec_get_drvdata(codec);
u8 data;
int i;
i = aic32x4_get_divs(aic32x4->sysclk, params_rate(params));
if (i < 0) {
printk(KERN_ERR "aic32x4: sampling rate not supported\n");
return i;
}
snd_soc_write(codec, AIC32X4_CLKMUX, AIC32X4_PLLCLKIN);
snd_soc_write(codec, AIC32X4_IFACE3, AIC32X4_DACMOD2BCLK);
data = snd_soc_read(codec, AIC32X4_PLLPR);
data &= ~(7 << 4);
snd_soc_write(codec, AIC32X4_PLLPR,
(data | (aic32x4_divs[i].p_val << 4) | 0x01));
snd_soc_write(codec, AIC32X4_PLLJ, aic32x4_divs[i].pll_j);
snd_soc_write(codec, AIC32X4_PLLDMSB, (aic32x4_divs[i].pll_d >> 8));
snd_soc_write(codec, AIC32X4_PLLDLSB,
(aic32x4_divs[i].pll_d & 0xff));
data = snd_soc_read(codec, AIC32X4_NDAC);
data &= ~(0x7f);
snd_soc_write(codec, AIC32X4_NDAC, data | aic32x4_divs[i].ndac);
data = snd_soc_read(codec, AIC32X4_MDAC);
data &= ~(0x7f);
snd_soc_write(codec, AIC32X4_MDAC, data | aic32x4_divs[i].mdac);
snd_soc_write(codec, AIC32X4_DOSRMSB, aic32x4_divs[i].dosr >> 8);
snd_soc_write(codec, AIC32X4_DOSRLSB,
(aic32x4_divs[i].dosr & 0xff));
data = snd_soc_read(codec, AIC32X4_NADC);
data &= ~(0x7f);
snd_soc_write(codec, AIC32X4_NADC, data | aic32x4_divs[i].nadc);
data = snd_soc_read(codec, AIC32X4_MADC);
data &= ~(0x7f);
snd_soc_write(codec, AIC32X4_MADC, data | aic32x4_divs[i].madc);
snd_soc_write(codec, AIC32X4_AOSR, aic32x4_divs[i].aosr);
data = snd_soc_read(codec, AIC32X4_BCLKN);
data &= ~(0x7f);
snd_soc_write(codec, AIC32X4_BCLKN, data | aic32x4_divs[i].blck_N);
data = snd_soc_read(codec, AIC32X4_IFACE1);
data = data & ~(3 << 4);
switch (params_width(params)) {
case 16:
break;
case 20:
data |= (AIC32X4_WORD_LEN_20BITS << AIC32X4_DOSRMSB_SHIFT);
break;
case 24:
data |= (AIC32X4_WORD_LEN_24BITS << AIC32X4_DOSRMSB_SHIFT);
break;
case 32:
data |= (AIC32X4_WORD_LEN_32BITS << AIC32X4_DOSRMSB_SHIFT);
break;
}
snd_soc_write(codec, AIC32X4_IFACE1, data);
if (params_channels(params) == 1) {
data = AIC32X4_RDAC2LCHN | AIC32X4_LDAC2LCHN;
} else {
if (aic32x4->swapdacs)
data = AIC32X4_RDAC2LCHN | AIC32X4_LDAC2RCHN;
else
data = AIC32X4_LDAC2LCHN | AIC32X4_RDAC2RCHN;
}
snd_soc_update_bits(codec, AIC32X4_DACSETUP, AIC32X4_DAC_CHAN_MASK,
data);
return 0;
}
static int aic32x4_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 dac_reg;
dac_reg = snd_soc_read(codec, AIC32X4_DACMUTE) & ~AIC32X4_MUTEON;
if (mute)
snd_soc_write(codec, AIC32X4_DACMUTE, dac_reg | AIC32X4_MUTEON);
else
snd_soc_write(codec, AIC32X4_DACMUTE, dac_reg);
return 0;
}
static int aic32x4_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct aic32x4_priv *aic32x4 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
ret = clk_prepare_enable(aic32x4->mclk);
if (ret) {
dev_err(codec->dev, "Failed to enable master clock\n");
return ret;
}
snd_soc_update_bits(codec, AIC32X4_PLLPR,
AIC32X4_PLLEN, AIC32X4_PLLEN);
snd_soc_update_bits(codec, AIC32X4_NDAC,
AIC32X4_NDACEN, AIC32X4_NDACEN);
snd_soc_update_bits(codec, AIC32X4_MDAC,
AIC32X4_MDACEN, AIC32X4_MDACEN);
snd_soc_update_bits(codec, AIC32X4_NADC,
AIC32X4_NADCEN, AIC32X4_NADCEN);
snd_soc_update_bits(codec, AIC32X4_MADC,
AIC32X4_MADCEN, AIC32X4_MADCEN);
snd_soc_update_bits(codec, AIC32X4_BCLKN,
AIC32X4_BCLKEN, AIC32X4_BCLKEN);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, AIC32X4_BCLKN,
AIC32X4_BCLKEN, 0);
snd_soc_update_bits(codec, AIC32X4_MADC,
AIC32X4_MADCEN, 0);
snd_soc_update_bits(codec, AIC32X4_NADC,
AIC32X4_NADCEN, 0);
snd_soc_update_bits(codec, AIC32X4_MDAC,
AIC32X4_MDACEN, 0);
snd_soc_update_bits(codec, AIC32X4_NDAC,
AIC32X4_NDACEN, 0);
snd_soc_update_bits(codec, AIC32X4_PLLPR,
AIC32X4_PLLEN, 0);
clk_disable_unprepare(aic32x4->mclk);
break;
case SND_SOC_BIAS_OFF:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int aic32x4_probe(struct snd_soc_codec *codec)
{
struct aic32x4_priv *aic32x4 = snd_soc_codec_get_drvdata(codec);
u32 tmp_reg;
if (gpio_is_valid(aic32x4->rstn_gpio)) {
ndelay(10);
gpio_set_value(aic32x4->rstn_gpio, 1);
}
snd_soc_write(codec, AIC32X4_RESET, 0x01);
if (aic32x4->power_cfg & AIC32X4_PWR_MICBIAS_2075_LDOIN) {
snd_soc_write(codec, AIC32X4_MICBIAS, AIC32X4_MICBIAS_LDOIN |
AIC32X4_MICBIAS_2075V);
}
if (aic32x4->power_cfg & AIC32X4_PWR_AVDD_DVDD_WEAK_DISABLE)
snd_soc_write(codec, AIC32X4_PWRCFG, AIC32X4_AVDDWEAKDISABLE);
tmp_reg = (aic32x4->power_cfg & AIC32X4_PWR_AIC32X4_LDO_ENABLE) ?
AIC32X4_LDOCTLEN : 0;
snd_soc_write(codec, AIC32X4_LDOCTL, tmp_reg);
tmp_reg = snd_soc_read(codec, AIC32X4_CMMODE);
if (aic32x4->power_cfg & AIC32X4_PWR_CMMODE_LDOIN_RANGE_18_36)
tmp_reg |= AIC32X4_LDOIN_18_36;
if (aic32x4->power_cfg & AIC32X4_PWR_CMMODE_HP_LDOIN_POWERED)
tmp_reg |= AIC32X4_LDOIN2HP;
snd_soc_write(codec, AIC32X4_CMMODE, tmp_reg);
if (aic32x4->micpga_routing & AIC32X4_MICPGA_ROUTE_LMIC_IN2R_10K)
snd_soc_write(codec, AIC32X4_LMICPGANIN,
AIC32X4_LMICPGANIN_IN2R_10K);
else
snd_soc_write(codec, AIC32X4_LMICPGANIN,
AIC32X4_LMICPGANIN_CM1L_10K);
if (aic32x4->micpga_routing & AIC32X4_MICPGA_ROUTE_RMIC_IN1L_10K)
snd_soc_write(codec, AIC32X4_RMICPGANIN,
AIC32X4_RMICPGANIN_IN1L_10K);
else
snd_soc_write(codec, AIC32X4_RMICPGANIN,
AIC32X4_RMICPGANIN_CM1R_10K);
tmp_reg = snd_soc_read(codec, AIC32X4_ADCSETUP);
snd_soc_write(codec, AIC32X4_ADCSETUP, tmp_reg |
AIC32X4_LADC_EN | AIC32X4_RADC_EN);
snd_soc_write(codec, AIC32X4_ADCSETUP, tmp_reg);
return 0;
}
static int aic32x4_parse_dt(struct aic32x4_priv *aic32x4,
struct device_node *np)
{
aic32x4->swapdacs = false;
aic32x4->micpga_routing = 0;
aic32x4->rstn_gpio = of_get_named_gpio(np, "reset-gpios", 0);
return 0;
}
static void aic32x4_disable_regulators(struct aic32x4_priv *aic32x4)
{
regulator_disable(aic32x4->supply_iov);
if (!IS_ERR(aic32x4->supply_ldo))
regulator_disable(aic32x4->supply_ldo);
if (!IS_ERR(aic32x4->supply_dv))
regulator_disable(aic32x4->supply_dv);
if (!IS_ERR(aic32x4->supply_av))
regulator_disable(aic32x4->supply_av);
}
static int aic32x4_setup_regulators(struct device *dev,
struct aic32x4_priv *aic32x4)
{
int ret = 0;
aic32x4->supply_ldo = devm_regulator_get_optional(dev, "ldoin");
aic32x4->supply_iov = devm_regulator_get(dev, "iov");
aic32x4->supply_dv = devm_regulator_get_optional(dev, "dv");
aic32x4->supply_av = devm_regulator_get_optional(dev, "av");
if (IS_ERR(aic32x4->supply_iov)) {
dev_err(dev, "Missing supply 'iov'\n");
return PTR_ERR(aic32x4->supply_iov);
}
if (IS_ERR(aic32x4->supply_ldo)) {
if (PTR_ERR(aic32x4->supply_ldo) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (IS_ERR(aic32x4->supply_dv)) {
dev_err(dev, "Missing supply 'dv' or 'ldoin'\n");
return PTR_ERR(aic32x4->supply_dv);
}
if (IS_ERR(aic32x4->supply_av)) {
dev_err(dev, "Missing supply 'av' or 'ldoin'\n");
return PTR_ERR(aic32x4->supply_av);
}
} else {
if (IS_ERR(aic32x4->supply_dv) &&
PTR_ERR(aic32x4->supply_dv) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (IS_ERR(aic32x4->supply_av) &&
PTR_ERR(aic32x4->supply_av) == -EPROBE_DEFER)
return -EPROBE_DEFER;
}
ret = regulator_enable(aic32x4->supply_iov);
if (ret) {
dev_err(dev, "Failed to enable regulator iov\n");
return ret;
}
if (!IS_ERR(aic32x4->supply_ldo)) {
ret = regulator_enable(aic32x4->supply_ldo);
if (ret) {
dev_err(dev, "Failed to enable regulator ldo\n");
goto error_ldo;
}
}
if (!IS_ERR(aic32x4->supply_dv)) {
ret = regulator_enable(aic32x4->supply_dv);
if (ret) {
dev_err(dev, "Failed to enable regulator dv\n");
goto error_dv;
}
}
if (!IS_ERR(aic32x4->supply_av)) {
ret = regulator_enable(aic32x4->supply_av);
if (ret) {
dev_err(dev, "Failed to enable regulator av\n");
goto error_av;
}
}
if (!IS_ERR(aic32x4->supply_ldo) && IS_ERR(aic32x4->supply_av))
aic32x4->power_cfg |= AIC32X4_PWR_AIC32X4_LDO_ENABLE;
return 0;
error_av:
if (!IS_ERR(aic32x4->supply_dv))
regulator_disable(aic32x4->supply_dv);
error_dv:
if (!IS_ERR(aic32x4->supply_ldo))
regulator_disable(aic32x4->supply_ldo);
error_ldo:
regulator_disable(aic32x4->supply_iov);
return ret;
}
static int aic32x4_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct aic32x4_pdata *pdata = i2c->dev.platform_data;
struct aic32x4_priv *aic32x4;
struct device_node *np = i2c->dev.of_node;
int ret;
aic32x4 = devm_kzalloc(&i2c->dev, sizeof(struct aic32x4_priv),
GFP_KERNEL);
if (aic32x4 == NULL)
return -ENOMEM;
aic32x4->regmap = devm_regmap_init_i2c(i2c, &aic32x4_regmap);
if (IS_ERR(aic32x4->regmap))
return PTR_ERR(aic32x4->regmap);
i2c_set_clientdata(i2c, aic32x4);
if (pdata) {
aic32x4->power_cfg = pdata->power_cfg;
aic32x4->swapdacs = pdata->swapdacs;
aic32x4->micpga_routing = pdata->micpga_routing;
aic32x4->rstn_gpio = pdata->rstn_gpio;
} else if (np) {
ret = aic32x4_parse_dt(aic32x4, np);
if (ret) {
dev_err(&i2c->dev, "Failed to parse DT node\n");
return ret;
}
} else {
aic32x4->power_cfg = 0;
aic32x4->swapdacs = false;
aic32x4->micpga_routing = 0;
aic32x4->rstn_gpio = -1;
}
aic32x4->mclk = devm_clk_get(&i2c->dev, "mclk");
if (IS_ERR(aic32x4->mclk)) {
dev_err(&i2c->dev, "Failed getting the mclk. The current implementation does not support the usage of this codec without mclk\n");
return PTR_ERR(aic32x4->mclk);
}
if (gpio_is_valid(aic32x4->rstn_gpio)) {
ret = devm_gpio_request_one(&i2c->dev, aic32x4->rstn_gpio,
GPIOF_OUT_INIT_LOW, "tlv320aic32x4 rstn");
if (ret != 0)
return ret;
}
ret = aic32x4_setup_regulators(&i2c->dev, aic32x4);
if (ret) {
dev_err(&i2c->dev, "Failed to setup regulators\n");
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_aic32x4, &aic32x4_dai, 1);
if (ret) {
dev_err(&i2c->dev, "Failed to register codec\n");
aic32x4_disable_regulators(aic32x4);
return ret;
}
i2c_set_clientdata(i2c, aic32x4);
return 0;
}
static int aic32x4_i2c_remove(struct i2c_client *client)
{
struct aic32x4_priv *aic32x4 = i2c_get_clientdata(client);
aic32x4_disable_regulators(aic32x4);
snd_soc_unregister_codec(&client->dev);
return 0;
}
