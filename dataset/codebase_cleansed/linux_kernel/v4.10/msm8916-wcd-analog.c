static void pm8916_wcd_analog_micbias_enable(struct snd_soc_codec *codec)
{
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_EXT_PRECHARG_EN_MASK |
MICB_1_CTL_INT_PRECHARG_BYP_MASK,
MICB_1_CTL_INT_PRECHARG_BYP_EXT_PRECHRG_SEL
| MICB_1_CTL_EXT_PRECHARG_EN_ENABLE);
snd_soc_write(codec, CDC_A_MICB_1_VAL, MICB_1_VAL_MICB_OUT_VAL_V2P70V);
msleep(50);
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_EXT_PRECHARG_EN_MASK |
MICB_1_CTL_INT_PRECHARG_BYP_MASK, 0);
}
static int pm8916_wcd_analog_enable_micbias_ext(struct snd_soc_codec
*codec, int event,
int reg, u32 cap_mode)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
pm8916_wcd_analog_micbias_enable(codec);
snd_soc_update_bits(codec, CDC_A_MICB_1_EN,
MICB_1_EN_BYP_CAP_MASK, cap_mode);
break;
}
return 0;
}
static int pm8916_wcd_analog_enable_micbias_int(struct snd_soc_codec
*codec, int event,
int reg, u32 cap_mode)
{
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, CDC_A_MICB_1_INT_RBIAS,
MICB_1_INT_TX2_INT_RBIAS_EN_MASK,
MICB_1_INT_TX2_INT_RBIAS_EN_ENABLE);
snd_soc_update_bits(codec, reg, MICB_1_EN_PULL_DOWN_EN_MASK, 0);
snd_soc_update_bits(codec, CDC_A_MICB_1_EN,
MICB_1_EN_OPA_STG2_TAIL_CURR_MASK,
MICB_1_EN_OPA_STG2_TAIL_CURR_1_60UA);
break;
case SND_SOC_DAPM_POST_PMU:
pm8916_wcd_analog_micbias_enable(codec);
snd_soc_update_bits(codec, CDC_A_MICB_1_EN,
MICB_1_EN_BYP_CAP_MASK, cap_mode);
break;
}
return 0;
}
static int pm8916_wcd_analog_enable_micbias_ext1(struct
snd_soc_dapm_widget
*w, struct snd_kcontrol
*kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
return pm8916_wcd_analog_enable_micbias_ext(codec, event, w->reg,
wcd->micbias1_cap_mode);
}
static int pm8916_wcd_analog_enable_micbias_ext2(struct
snd_soc_dapm_widget
*w, struct snd_kcontrol
*kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
return pm8916_wcd_analog_enable_micbias_ext(codec, event, w->reg,
wcd->micbias2_cap_mode);
}
static int pm8916_wcd_analog_enable_micbias_int1(struct
snd_soc_dapm_widget
*w, struct snd_kcontrol
*kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
return pm8916_wcd_analog_enable_micbias_int(codec, event, w->reg,
wcd->micbias1_cap_mode);
}
static int pm8916_wcd_analog_enable_micbias_int2(struct
snd_soc_dapm_widget
*w, struct snd_kcontrol
*kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
return pm8916_wcd_analog_enable_micbias_int(codec, event, w->reg,
wcd->micbias2_cap_mode);
}
static int pm8916_wcd_analog_enable_adc(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
u16 adc_reg = CDC_A_TX_1_2_TEST_CTL_2;
u8 init_bit_shift;
if (w->reg == CDC_A_TX_1_EN)
init_bit_shift = 5;
else
init_bit_shift = 4;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (w->reg == CDC_A_TX_2_EN)
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_CFILT_REF_SEL_MASK,
MICB_1_CTL_CFILT_REF_SEL_HPF_REF);
usleep_range(10000, 10010);
snd_soc_update_bits(codec, adc_reg, 1 << init_bit_shift,
1 << init_bit_shift);
switch (w->reg) {
case CDC_A_TX_1_EN:
snd_soc_update_bits(codec, CDC_D_CDC_CONN_TX1_CTL,
CONN_TX1_SERIAL_TX1_MUX,
CONN_TX1_SERIAL_TX1_ADC_1);
break;
case CDC_A_TX_2_EN:
case CDC_A_TX_3_EN:
snd_soc_update_bits(codec, CDC_D_CDC_CONN_TX2_CTL,
CONN_TX2_SERIAL_TX2_MUX,
CONN_TX2_SERIAL_TX2_ADC_2);
break;
}
break;
case SND_SOC_DAPM_POST_PMU:
usleep_range(12000, 12010);
snd_soc_update_bits(codec, adc_reg, 1 << init_bit_shift, 0x00);
break;
case SND_SOC_DAPM_POST_PMD:
switch (w->reg) {
case CDC_A_TX_1_EN:
snd_soc_update_bits(codec, CDC_D_CDC_CONN_TX1_CTL,
CONN_TX1_SERIAL_TX1_MUX,
CONN_TX1_SERIAL_TX1_ZERO);
break;
case CDC_A_TX_2_EN:
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_CFILT_REF_SEL_MASK, 0);
case CDC_A_TX_3_EN:
snd_soc_update_bits(codec, CDC_D_CDC_CONN_TX2_CTL,
CONN_TX2_SERIAL_TX2_MUX,
CONN_TX2_SERIAL_TX2_ZERO);
break;
}
break;
}
return 0;
}
static int pm8916_wcd_analog_enable_spk_pa(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, CDC_A_SPKR_PWRSTG_CTL,
SPKR_PWRSTG_CTL_DAC_EN_MASK |
SPKR_PWRSTG_CTL_BBM_MASK |
SPKR_PWRSTG_CTL_HBRDGE_EN_MASK |
SPKR_PWRSTG_CTL_CLAMP_EN_MASK,
SPKR_PWRSTG_CTL_DAC_EN|
SPKR_PWRSTG_CTL_BBM_EN |
SPKR_PWRSTG_CTL_HBRDGE_EN |
SPKR_PWRSTG_CTL_CLAMP_EN);
snd_soc_update_bits(codec, CDC_A_RX_EAR_CTL,
RX_EAR_CTL_SPK_VBAT_LDO_EN_MASK,
RX_EAR_CTL_SPK_VBAT_LDO_EN_ENABLE);
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, CDC_A_SPKR_DRV_CTL,
SPKR_DRV_CTL_DEF_MASK,
SPKR_DRV_CTL_DEF_VAL);
snd_soc_update_bits(codec, w->reg,
SPKR_DRV_CLASSD_PA_EN_MASK,
SPKR_DRV_CLASSD_PA_EN_ENABLE);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, CDC_A_SPKR_PWRSTG_CTL,
SPKR_PWRSTG_CTL_DAC_EN_MASK|
SPKR_PWRSTG_CTL_BBM_MASK |
SPKR_PWRSTG_CTL_HBRDGE_EN_MASK |
SPKR_PWRSTG_CTL_CLAMP_EN_MASK, 0);
snd_soc_update_bits(codec, CDC_A_SPKR_DAC_CTL,
SPKR_DAC_CTL_DAC_RESET_MASK,
SPKR_DAC_CTL_DAC_RESET_NORMAL);
snd_soc_update_bits(codec, CDC_A_RX_EAR_CTL,
RX_EAR_CTL_SPK_VBAT_LDO_EN_MASK, 0);
break;
}
return 0;
}
static int pm8916_wcd_analog_probe(struct snd_soc_codec *codec)
{
struct pm8916_wcd_analog_priv *priv = dev_get_drvdata(codec->dev);
int err, reg;
err = regulator_bulk_enable(ARRAY_SIZE(priv->supplies), priv->supplies);
if (err != 0) {
dev_err(codec->dev, "failed to enable regulators (%d)\n", err);
return err;
}
snd_soc_codec_set_drvdata(codec, priv);
priv->pmic_rev = snd_soc_read(codec, CDC_D_REVISION1);
priv->codec_version = snd_soc_read(codec, CDC_D_PERPH_SUBTYPE);
dev_info(codec->dev, "PMIC REV: %d\t CODEC Version: %d\n",
priv->pmic_rev, priv->codec_version);
snd_soc_write(codec, CDC_D_PERPH_RESET_CTL4, 0x01);
snd_soc_write(codec, CDC_A_PERPH_RESET_CTL4, 0x01);
for (reg = 0; reg < ARRAY_SIZE(wcd_reg_defaults_2_0); reg++)
snd_soc_write(codec, wcd_reg_defaults_2_0[reg].reg,
wcd_reg_defaults_2_0[reg].def);
return 0;
}
static int pm8916_wcd_analog_remove(struct snd_soc_codec *codec)
{
struct pm8916_wcd_analog_priv *priv = dev_get_drvdata(codec->dev);
return regulator_bulk_disable(ARRAY_SIZE(priv->supplies),
priv->supplies);
}
static struct regmap *pm8916_get_regmap(struct device *dev)
{
return dev_get_regmap(dev->parent, NULL);
}
static int pm8916_wcd_analog_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_soc_update_bits(dai->codec, CDC_D_CDC_RST_CTL,
RST_CTL_DIG_SW_RST_N_MASK,
RST_CTL_DIG_SW_RST_N_REMOVE_RESET);
return 0;
}
static void pm8916_wcd_analog_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_soc_update_bits(dai->codec, CDC_D_CDC_RST_CTL,
RST_CTL_DIG_SW_RST_N_MASK, 0);
}
static int pm8916_wcd_analog_parse_dt(struct device *dev,
struct pm8916_wcd_analog_priv *priv)
{
if (of_property_read_bool(dev->of_node, "qcom,micbias1-ext-cap"))
priv->micbias1_cap_mode = MICB_1_EN_EXT_BYP_CAP;
else
priv->micbias1_cap_mode = MICB_1_EN_NO_EXT_BYP_CAP;
if (of_property_read_bool(dev->of_node, "qcom,micbias2-ext-cap"))
priv->micbias2_cap_mode = MICB_1_EN_EXT_BYP_CAP;
else
priv->micbias2_cap_mode = MICB_1_EN_NO_EXT_BYP_CAP;
return 0;
}
static int pm8916_wcd_analog_spmi_probe(struct platform_device *pdev)
{
struct pm8916_wcd_analog_priv *priv;
struct device *dev = &pdev->dev;
int ret, i;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
ret = pm8916_wcd_analog_parse_dt(dev, priv);
if (ret < 0)
return ret;
priv->mclk = devm_clk_get(dev, "mclk");
if (IS_ERR(priv->mclk)) {
dev_err(dev, "failed to get mclk\n");
return PTR_ERR(priv->mclk);
}
for (i = 0; i < ARRAY_SIZE(supply_names); i++)
priv->supplies[i].supply = supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(priv->supplies),
priv->supplies);
if (ret) {
dev_err(dev, "Failed to get regulator supplies %d\n", ret);
return ret;
}
ret = clk_prepare_enable(priv->mclk);
if (ret < 0) {
dev_err(dev, "failed to enable mclk %d\n", ret);
return ret;
}
dev_set_drvdata(dev, priv);
return snd_soc_register_codec(dev, &pm8916_wcd_analog,
pm8916_wcd_analog_dai,
ARRAY_SIZE(pm8916_wcd_analog_dai));
}
static int pm8916_wcd_analog_spmi_remove(struct platform_device *pdev)
{
struct pm8916_wcd_analog_priv *priv = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
clk_disable_unprepare(priv->mclk);
return 0;
}
