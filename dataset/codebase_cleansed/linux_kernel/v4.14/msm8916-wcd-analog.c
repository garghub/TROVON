static void pm8916_wcd_analog_micbias_enable(struct snd_soc_codec *codec)
{
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_EXT_PRECHARG_EN_MASK |
MICB_1_CTL_INT_PRECHARG_BYP_MASK,
MICB_1_CTL_INT_PRECHARG_BYP_EXT_PRECHRG_SEL
| MICB_1_CTL_EXT_PRECHARG_EN_ENABLE);
if (wcd->micbias_mv) {
snd_soc_write(codec, CDC_A_MICB_1_VAL,
MICB_VOLTAGE_REGVAL(wcd->micbias_mv));
if (wcd->micbias_mv >= 2700)
msleep(50);
}
snd_soc_update_bits(codec, CDC_A_MICB_1_CTL,
MICB_1_CTL_EXT_PRECHARG_EN_MASK |
MICB_1_CTL_INT_PRECHARG_BYP_MASK, 0);
}
static int pm8916_wcd_analog_enable_micbias_ext(struct snd_soc_codec
*codec, int event,
int reg, unsigned int cap_mode)
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
static void pm8916_wcd_setup_mbhc(struct pm8916_wcd_analog_priv *wcd)
{
struct snd_soc_codec *codec = wcd->codec;
u32 plug_type = 0;
u32 int_en_mask;
snd_soc_write(codec, CDC_A_MBHC_DET_CTL_1,
CDC_A_MBHC_DET_CTL_L_DET_EN |
CDC_A_MBHC_DET_CTL_MECH_DET_TYPE_INSERTION |
CDC_A_MBHC_DET_CTL_MIC_CLAMP_CTL_AUTO |
CDC_A_MBHC_DET_CTL_MBHC_BIAS_EN);
if (wcd->hphl_jack_type_normally_open)
plug_type |= CDC_A_HPHL_PLUG_TYPE_NO;
if (wcd->gnd_jack_type_normally_open)
plug_type |= CDC_A_GND_PLUG_TYPE_NO;
snd_soc_write(codec, CDC_A_MBHC_DET_CTL_2,
CDC_A_MBHC_DET_CTL_HS_L_DET_PULL_UP_CTRL_I_3P0 |
CDC_A_MBHC_DET_CTL_HS_L_DET_COMPA_CTRL_V0P9_VDD |
plug_type |
CDC_A_MBHC_DET_CTL_HPHL_100K_TO_GND_EN);
snd_soc_write(codec, CDC_A_MBHC_DBNC_TIMER,
CDC_A_MBHC_DBNC_TIMER_INSREM_DBNC_T_256_MS |
CDC_A_MBHC_DBNC_TIMER_BTN_DBNC_T_16MS);
snd_soc_update_bits(codec, CDC_D_CDC_DIG_CLK_CTL,
DIG_CLK_CTL_D_MBHC_CLK_EN_MASK,
DIG_CLK_CTL_D_MBHC_CLK_EN);
int_en_mask = MBHC_SWITCH_INT;
if (wcd->mbhc_btn_enabled)
int_en_mask |= MBHC_BUTTON_PRESS_DET | MBHC_BUTTON_RELEASE_DET;
snd_soc_update_bits(codec, CDC_D_INT_EN_CLR, int_en_mask, 0);
snd_soc_update_bits(codec, CDC_D_INT_EN_SET, int_en_mask, int_en_mask);
wcd->mbhc_btn0_pressed = false;
wcd->detect_accessory_type = true;
}
static int pm8916_mbhc_configure_bias(struct pm8916_wcd_analog_priv *priv,
bool micbias2_enabled)
{
struct snd_soc_codec *codec = priv->codec;
u32 coarse, fine, reg_val, reg_addr;
int *vrefs, i;
if (!micbias2_enabled) {
snd_soc_update_bits(codec, CDC_A_MICB_1_INT_RBIAS,
MICB_1_INT_TX2_INT_RBIAS_EN_MASK,
MICB_1_INT_TX2_INT_RBIAS_EN_ENABLE);
snd_soc_update_bits(codec, CDC_A_MICB_2_EN,
CDC_A_MICB_2_PULL_DOWN_EN_MASK,
0);
snd_soc_update_bits(codec, CDC_A_MBHC_FSM_CTL,
CDC_A_MBHC_FSM_CTL_BTN_ISRC_CTRL_MASK,
CDC_A_MBHC_FSM_CTL_BTN_ISRC_CTRL_I_100UA);
}
snd_soc_update_bits(codec, CDC_A_MBHC_FSM_CTL,
CDC_A_MBHC_FSM_CTL_MBHC_FSM_EN_MASK,
CDC_A_MBHC_FSM_CTL_MBHC_FSM_EN);
if (micbias2_enabled)
vrefs = &priv->vref_btn_micb[0];
else
vrefs = &priv->vref_btn_cs[0];
reg_addr = CDC_A_MBHC_BTN0_ZDET_CTL_0;
for (i = 0; i < MBHC_MAX_BUTTONS; i++) {
coarse = (vrefs[i] / 100);
fine = ((vrefs[i] % 100) / 12);
reg_val = (coarse << CDC_A_MBHC_BTN_VREF_COARSE_SHIFT) |
(fine << CDC_A_MBHC_BTN_VREF_FINE_SHIFT);
snd_soc_update_bits(codec, reg_addr,
CDC_A_MBHC_BTN_VREF_MASK,
reg_val);
reg_addr++;
}
return 0;
}
static int pm8916_wcd_analog_enable_micbias_int2(struct
snd_soc_dapm_widget
*w, struct snd_kcontrol
*kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
pm8916_mbhc_configure_bias(wcd, true);
break;
case SND_SOC_DAPM_POST_PMD:
pm8916_mbhc_configure_bias(wcd, false);
break;
}
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
priv->codec = codec;
snd_soc_update_bits(codec, CDC_D_CDC_RST_CTL,
RST_CTL_DIG_SW_RST_N_MASK,
RST_CTL_DIG_SW_RST_N_REMOVE_RESET);
pm8916_wcd_setup_mbhc(priv);
return 0;
}
static int pm8916_wcd_analog_remove(struct snd_soc_codec *codec)
{
struct pm8916_wcd_analog_priv *priv = dev_get_drvdata(codec->dev);
snd_soc_update_bits(codec, CDC_D_CDC_RST_CTL,
RST_CTL_DIG_SW_RST_N_MASK, 0);
return regulator_bulk_disable(ARRAY_SIZE(priv->supplies),
priv->supplies);
}
static int pm8916_wcd_analog_set_jack(struct snd_soc_codec *codec,
struct snd_soc_jack *jack,
void *data)
{
struct pm8916_wcd_analog_priv *wcd = snd_soc_codec_get_drvdata(codec);
wcd->jack = jack;
return 0;
}
static struct regmap *pm8916_get_regmap(struct device *dev)
{
return dev_get_regmap(dev->parent, NULL);
}
static irqreturn_t mbhc_btn_release_irq_handler(int irq, void *arg)
{
struct pm8916_wcd_analog_priv *priv = arg;
if (priv->detect_accessory_type) {
struct snd_soc_codec *codec = priv->codec;
u32 val = snd_soc_read(codec, CDC_A_MBHC_RESULT_1);
if ((val != -1) && !(val & CDC_A_MBHC_RESULT_1_BTN_RESULT_MASK))
priv->mbhc_btn0_pressed = false;
} else {
snd_soc_jack_report(priv->jack, 0, btn_mask);
}
return IRQ_HANDLED;
}
static irqreturn_t mbhc_btn_press_irq_handler(int irq, void *arg)
{
struct pm8916_wcd_analog_priv *priv = arg;
struct snd_soc_codec *codec = priv->codec;
u32 btn_result;
btn_result = snd_soc_read(codec, CDC_A_MBHC_RESULT_1) &
CDC_A_MBHC_RESULT_1_BTN_RESULT_MASK;
switch (btn_result) {
case 0xf:
snd_soc_jack_report(priv->jack, SND_JACK_BTN_4, btn_mask);
break;
case 0x7:
snd_soc_jack_report(priv->jack, SND_JACK_BTN_3, btn_mask);
break;
case 0x3:
snd_soc_jack_report(priv->jack, SND_JACK_BTN_2, btn_mask);
break;
case 0x1:
snd_soc_jack_report(priv->jack, SND_JACK_BTN_1, btn_mask);
break;
case 0x0:
if (priv->detect_accessory_type)
priv->mbhc_btn0_pressed = true;
else
snd_soc_jack_report(priv->jack,
SND_JACK_BTN_0, btn_mask);
break;
default:
dev_err(codec->dev,
"Unexpected button press result (%x)", btn_result);
break;
}
return IRQ_HANDLED;
}
static irqreturn_t pm8916_mbhc_switch_irq_handler(int irq, void *arg)
{
struct pm8916_wcd_analog_priv *priv = arg;
struct snd_soc_codec *codec = priv->codec;
bool ins = false;
if (snd_soc_read(codec, CDC_A_MBHC_DET_CTL_1) &
CDC_A_MBHC_DET_CTL_MECH_DET_TYPE_MASK)
ins = true;
snd_soc_update_bits(codec, CDC_A_MBHC_DET_CTL_1,
CDC_A_MBHC_DET_CTL_MECH_DET_TYPE_MASK,
(!ins << CDC_A_MBHC_DET_CTL_MECH_DET_TYPE_SHIFT));
if (ins) {
bool micbias_enabled = false;
if (snd_soc_read(codec, CDC_A_MICB_2_EN) &
CDC_A_MICB_2_EN_ENABLE)
micbias_enabled = true;
pm8916_mbhc_configure_bias(priv, micbias_enabled);
if (priv->mbhc_btn0_pressed)
snd_soc_jack_report(priv->jack,
SND_JACK_HEADPHONE, hs_jack_mask);
else
snd_soc_jack_report(priv->jack,
SND_JACK_HEADSET, hs_jack_mask);
priv->detect_accessory_type = false;
} else {
snd_soc_jack_report(priv->jack, 0, hs_jack_mask);
priv->detect_accessory_type = true;
priv->mbhc_btn0_pressed = false;
}
return IRQ_HANDLED;
}
static int pm8916_wcd_analog_parse_dt(struct device *dev,
struct pm8916_wcd_analog_priv *priv)
{
int rval;
if (of_property_read_bool(dev->of_node, "qcom,micbias1-ext-cap"))
priv->micbias1_cap_mode = MICB_1_EN_EXT_BYP_CAP;
else
priv->micbias1_cap_mode = MICB_1_EN_NO_EXT_BYP_CAP;
if (of_property_read_bool(dev->of_node, "qcom,micbias2-ext-cap"))
priv->micbias2_cap_mode = MICB_1_EN_EXT_BYP_CAP;
else
priv->micbias2_cap_mode = MICB_1_EN_NO_EXT_BYP_CAP;
of_property_read_u32(dev->of_node, "qcom,micbias-lvl",
&priv->micbias_mv);
if (of_property_read_bool(dev->of_node,
"qcom,hphl-jack-type-normally-open"))
priv->hphl_jack_type_normally_open = true;
else
priv->hphl_jack_type_normally_open = false;
if (of_property_read_bool(dev->of_node,
"qcom,gnd-jack-type-normally-open"))
priv->gnd_jack_type_normally_open = true;
else
priv->gnd_jack_type_normally_open = false;
priv->mbhc_btn_enabled = true;
rval = of_property_read_u32_array(dev->of_node,
"qcom,mbhc-vthreshold-low",
&priv->vref_btn_cs[0],
MBHC_MAX_BUTTONS);
if (rval < 0) {
priv->mbhc_btn_enabled = false;
} else {
rval = of_property_read_u32_array(dev->of_node,
"qcom,mbhc-vthreshold-high",
&priv->vref_btn_micb[0],
MBHC_MAX_BUTTONS);
if (rval < 0)
priv->mbhc_btn_enabled = false;
}
if (!priv->mbhc_btn_enabled)
dev_err(dev,
"DT property missing, MBHC btn detection disabled\n");
return 0;
}
static int pm8916_wcd_analog_spmi_probe(struct platform_device *pdev)
{
struct pm8916_wcd_analog_priv *priv;
struct device *dev = &pdev->dev;
int ret, i, irq;
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
irq = platform_get_irq_byname(pdev, "mbhc_switch_int");
if (irq < 0) {
dev_err(dev, "failed to get mbhc switch irq\n");
return irq;
}
ret = devm_request_irq(dev, irq, pm8916_mbhc_switch_irq_handler,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
"mbhc switch irq", priv);
if (ret)
dev_err(dev, "cannot request mbhc switch irq\n");
if (priv->mbhc_btn_enabled) {
irq = platform_get_irq_byname(pdev, "mbhc_but_press_det");
if (irq < 0) {
dev_err(dev, "failed to get button press irq\n");
return irq;
}
ret = devm_request_irq(dev, irq, mbhc_btn_press_irq_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"mbhc btn press irq", priv);
if (ret)
dev_err(dev, "cannot request mbhc button press irq\n");
irq = platform_get_irq_byname(pdev, "mbhc_but_rel_det");
if (irq < 0) {
dev_err(dev, "failed to get button release irq\n");
return irq;
}
ret = devm_request_irq(dev, irq, mbhc_btn_release_irq_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"mbhc btn release irq", priv);
if (ret)
dev_err(dev, "cannot request mbhc button release irq\n");
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
