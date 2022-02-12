static bool rt5665_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5665_RESET:
case RT5665_EJD_CTRL_2:
case RT5665_GPIO_STA:
case RT5665_INT_ST_1:
case RT5665_IL_CMD_1:
case RT5665_4BTN_IL_CMD_1:
case RT5665_PSV_IL_CMD_1:
case RT5665_AJD1_CTRL:
case RT5665_JD_CTRL_3:
case RT5665_STO_NG2_CTRL_1:
case RT5665_SAR_IL_CMD_4:
case RT5665_DEVICE_ID:
case RT5665_STO1_DAC_SIL_DET ... RT5665_STO2_DAC_SIL_DET:
case RT5665_MONO_AMP_CALIB_STA1 ... RT5665_MONO_AMP_CALIB_STA6:
case RT5665_HP_IMP_SENS_CTRL_12 ... RT5665_HP_IMP_SENS_CTRL_15:
case RT5665_HP_CALIB_STA_1 ... RT5665_HP_CALIB_STA_11:
return true;
default:
return false;
}
}
static bool rt5665_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5665_RESET:
case RT5665_VENDOR_ID:
case RT5665_VENDOR_ID_1:
case RT5665_DEVICE_ID:
case RT5665_LOUT:
case RT5665_HP_CTRL_1:
case RT5665_HP_CTRL_2:
case RT5665_MONO_OUT:
case RT5665_HPL_GAIN:
case RT5665_HPR_GAIN:
case RT5665_MONO_GAIN:
case RT5665_CAL_BST_CTRL:
case RT5665_CBJ_BST_CTRL:
case RT5665_IN1_IN2:
case RT5665_IN3_IN4:
case RT5665_INL1_INR1_VOL:
case RT5665_EJD_CTRL_1:
case RT5665_EJD_CTRL_2:
case RT5665_EJD_CTRL_3:
case RT5665_EJD_CTRL_4:
case RT5665_EJD_CTRL_5:
case RT5665_EJD_CTRL_6:
case RT5665_EJD_CTRL_7:
case RT5665_DAC2_CTRL:
case RT5665_DAC2_DIG_VOL:
case RT5665_DAC1_DIG_VOL:
case RT5665_DAC3_DIG_VOL:
case RT5665_DAC3_CTRL:
case RT5665_STO1_ADC_DIG_VOL:
case RT5665_MONO_ADC_DIG_VOL:
case RT5665_STO2_ADC_DIG_VOL:
case RT5665_STO1_ADC_BOOST:
case RT5665_MONO_ADC_BOOST:
case RT5665_STO2_ADC_BOOST:
case RT5665_HP_IMP_GAIN_1:
case RT5665_HP_IMP_GAIN_2:
case RT5665_STO1_ADC_MIXER:
case RT5665_MONO_ADC_MIXER:
case RT5665_STO2_ADC_MIXER:
case RT5665_AD_DA_MIXER:
case RT5665_STO1_DAC_MIXER:
case RT5665_MONO_DAC_MIXER:
case RT5665_STO2_DAC_MIXER:
case RT5665_A_DAC1_MUX:
case RT5665_A_DAC2_MUX:
case RT5665_DIG_INF2_DATA:
case RT5665_DIG_INF3_DATA:
case RT5665_PDM_OUT_CTRL:
case RT5665_PDM_DATA_CTRL_1:
case RT5665_PDM_DATA_CTRL_2:
case RT5665_PDM_DATA_CTRL_3:
case RT5665_PDM_DATA_CTRL_4:
case RT5665_REC1_GAIN:
case RT5665_REC1_L1_MIXER:
case RT5665_REC1_L2_MIXER:
case RT5665_REC1_R1_MIXER:
case RT5665_REC1_R2_MIXER:
case RT5665_REC2_GAIN:
case RT5665_REC2_L1_MIXER:
case RT5665_REC2_L2_MIXER:
case RT5665_REC2_R1_MIXER:
case RT5665_REC2_R2_MIXER:
case RT5665_CAL_REC:
case RT5665_ALC_BACK_GAIN:
case RT5665_MONOMIX_GAIN:
case RT5665_MONOMIX_IN_GAIN:
case RT5665_OUT_L_GAIN:
case RT5665_OUT_L_MIXER:
case RT5665_OUT_R_GAIN:
case RT5665_OUT_R_MIXER:
case RT5665_LOUT_MIXER:
case RT5665_PWR_DIG_1:
case RT5665_PWR_DIG_2:
case RT5665_PWR_ANLG_1:
case RT5665_PWR_ANLG_2:
case RT5665_PWR_ANLG_3:
case RT5665_PWR_MIXER:
case RT5665_PWR_VOL:
case RT5665_CLK_DET:
case RT5665_HPF_CTRL1:
case RT5665_DMIC_CTRL_1:
case RT5665_DMIC_CTRL_2:
case RT5665_I2S1_SDP:
case RT5665_I2S2_SDP:
case RT5665_I2S3_SDP:
case RT5665_ADDA_CLK_1:
case RT5665_ADDA_CLK_2:
case RT5665_I2S1_F_DIV_CTRL_1:
case RT5665_I2S1_F_DIV_CTRL_2:
case RT5665_TDM_CTRL_1:
case RT5665_TDM_CTRL_2:
case RT5665_TDM_CTRL_3:
case RT5665_TDM_CTRL_4:
case RT5665_TDM_CTRL_5:
case RT5665_TDM_CTRL_6:
case RT5665_TDM_CTRL_7:
case RT5665_TDM_CTRL_8:
case RT5665_GLB_CLK:
case RT5665_PLL_CTRL_1:
case RT5665_PLL_CTRL_2:
case RT5665_ASRC_1:
case RT5665_ASRC_2:
case RT5665_ASRC_3:
case RT5665_ASRC_4:
case RT5665_ASRC_5:
case RT5665_ASRC_6:
case RT5665_ASRC_7:
case RT5665_ASRC_8:
case RT5665_ASRC_9:
case RT5665_ASRC_10:
case RT5665_DEPOP_1:
case RT5665_DEPOP_2:
case RT5665_HP_CHARGE_PUMP_1:
case RT5665_HP_CHARGE_PUMP_2:
case RT5665_MICBIAS_1:
case RT5665_MICBIAS_2:
case RT5665_ASRC_12:
case RT5665_ASRC_13:
case RT5665_ASRC_14:
case RT5665_RC_CLK_CTRL:
case RT5665_I2S_M_CLK_CTRL_1:
case RT5665_I2S2_F_DIV_CTRL_1:
case RT5665_I2S2_F_DIV_CTRL_2:
case RT5665_I2S3_F_DIV_CTRL_1:
case RT5665_I2S3_F_DIV_CTRL_2:
case RT5665_EQ_CTRL_1:
case RT5665_EQ_CTRL_2:
case RT5665_IRQ_CTRL_1:
case RT5665_IRQ_CTRL_2:
case RT5665_IRQ_CTRL_3:
case RT5665_IRQ_CTRL_4:
case RT5665_IRQ_CTRL_5:
case RT5665_IRQ_CTRL_6:
case RT5665_INT_ST_1:
case RT5665_GPIO_CTRL_1:
case RT5665_GPIO_CTRL_2:
case RT5665_GPIO_CTRL_3:
case RT5665_GPIO_CTRL_4:
case RT5665_GPIO_STA:
case RT5665_HP_AMP_DET_CTRL_1:
case RT5665_HP_AMP_DET_CTRL_2:
case RT5665_MID_HP_AMP_DET:
case RT5665_LOW_HP_AMP_DET:
case RT5665_SV_ZCD_1:
case RT5665_SV_ZCD_2:
case RT5665_IL_CMD_1:
case RT5665_IL_CMD_2:
case RT5665_IL_CMD_3:
case RT5665_IL_CMD_4:
case RT5665_4BTN_IL_CMD_1:
case RT5665_4BTN_IL_CMD_2:
case RT5665_4BTN_IL_CMD_3:
case RT5665_PSV_IL_CMD_1:
case RT5665_ADC_STO1_HP_CTRL_1:
case RT5665_ADC_STO1_HP_CTRL_2:
case RT5665_ADC_MONO_HP_CTRL_1:
case RT5665_ADC_MONO_HP_CTRL_2:
case RT5665_ADC_STO2_HP_CTRL_1:
case RT5665_ADC_STO2_HP_CTRL_2:
case RT5665_AJD1_CTRL:
case RT5665_JD1_THD:
case RT5665_JD2_THD:
case RT5665_JD_CTRL_1:
case RT5665_JD_CTRL_2:
case RT5665_JD_CTRL_3:
case RT5665_DIG_MISC:
case RT5665_DUMMY_2:
case RT5665_DUMMY_3:
case RT5665_DAC_ADC_DIG_VOL1:
case RT5665_DAC_ADC_DIG_VOL2:
case RT5665_BIAS_CUR_CTRL_1:
case RT5665_BIAS_CUR_CTRL_2:
case RT5665_BIAS_CUR_CTRL_3:
case RT5665_BIAS_CUR_CTRL_4:
case RT5665_BIAS_CUR_CTRL_5:
case RT5665_BIAS_CUR_CTRL_6:
case RT5665_BIAS_CUR_CTRL_7:
case RT5665_BIAS_CUR_CTRL_8:
case RT5665_BIAS_CUR_CTRL_9:
case RT5665_BIAS_CUR_CTRL_10:
case RT5665_VREF_REC_OP_FB_CAP_CTRL:
case RT5665_CHARGE_PUMP_1:
case RT5665_DIG_IN_CTRL_1:
case RT5665_DIG_IN_CTRL_2:
case RT5665_PAD_DRIVING_CTRL:
case RT5665_SOFT_RAMP_DEPOP:
case RT5665_PLL:
case RT5665_CHOP_DAC:
case RT5665_CHOP_ADC:
case RT5665_CALIB_ADC_CTRL:
case RT5665_VOL_TEST:
case RT5665_TEST_MODE_CTRL_1:
case RT5665_TEST_MODE_CTRL_2:
case RT5665_TEST_MODE_CTRL_3:
case RT5665_TEST_MODE_CTRL_4:
case RT5665_BASSBACK_CTRL:
case RT5665_STO_NG2_CTRL_1:
case RT5665_STO_NG2_CTRL_2:
case RT5665_STO_NG2_CTRL_3:
case RT5665_STO_NG2_CTRL_4:
case RT5665_STO_NG2_CTRL_5:
case RT5665_STO_NG2_CTRL_6:
case RT5665_STO_NG2_CTRL_7:
case RT5665_STO_NG2_CTRL_8:
case RT5665_MONO_NG2_CTRL_1:
case RT5665_MONO_NG2_CTRL_2:
case RT5665_MONO_NG2_CTRL_3:
case RT5665_MONO_NG2_CTRL_4:
case RT5665_MONO_NG2_CTRL_5:
case RT5665_MONO_NG2_CTRL_6:
case RT5665_STO1_DAC_SIL_DET:
case RT5665_MONOL_DAC_SIL_DET:
case RT5665_MONOR_DAC_SIL_DET:
case RT5665_STO2_DAC_SIL_DET:
case RT5665_SIL_PSV_CTRL1:
case RT5665_SIL_PSV_CTRL2:
case RT5665_SIL_PSV_CTRL3:
case RT5665_SIL_PSV_CTRL4:
case RT5665_SIL_PSV_CTRL5:
case RT5665_SIL_PSV_CTRL6:
case RT5665_MONO_AMP_CALIB_CTRL_1:
case RT5665_MONO_AMP_CALIB_CTRL_2:
case RT5665_MONO_AMP_CALIB_CTRL_3:
case RT5665_MONO_AMP_CALIB_CTRL_4:
case RT5665_MONO_AMP_CALIB_CTRL_5:
case RT5665_MONO_AMP_CALIB_CTRL_6:
case RT5665_MONO_AMP_CALIB_CTRL_7:
case RT5665_MONO_AMP_CALIB_STA1:
case RT5665_MONO_AMP_CALIB_STA2:
case RT5665_MONO_AMP_CALIB_STA3:
case RT5665_MONO_AMP_CALIB_STA4:
case RT5665_MONO_AMP_CALIB_STA6:
case RT5665_HP_IMP_SENS_CTRL_01:
case RT5665_HP_IMP_SENS_CTRL_02:
case RT5665_HP_IMP_SENS_CTRL_03:
case RT5665_HP_IMP_SENS_CTRL_04:
case RT5665_HP_IMP_SENS_CTRL_05:
case RT5665_HP_IMP_SENS_CTRL_06:
case RT5665_HP_IMP_SENS_CTRL_07:
case RT5665_HP_IMP_SENS_CTRL_08:
case RT5665_HP_IMP_SENS_CTRL_09:
case RT5665_HP_IMP_SENS_CTRL_10:
case RT5665_HP_IMP_SENS_CTRL_11:
case RT5665_HP_IMP_SENS_CTRL_12:
case RT5665_HP_IMP_SENS_CTRL_13:
case RT5665_HP_IMP_SENS_CTRL_14:
case RT5665_HP_IMP_SENS_CTRL_15:
case RT5665_HP_IMP_SENS_CTRL_16:
case RT5665_HP_IMP_SENS_CTRL_17:
case RT5665_HP_IMP_SENS_CTRL_18:
case RT5665_HP_IMP_SENS_CTRL_19:
case RT5665_HP_IMP_SENS_CTRL_20:
case RT5665_HP_IMP_SENS_CTRL_21:
case RT5665_HP_IMP_SENS_CTRL_22:
case RT5665_HP_IMP_SENS_CTRL_23:
case RT5665_HP_IMP_SENS_CTRL_24:
case RT5665_HP_IMP_SENS_CTRL_25:
case RT5665_HP_IMP_SENS_CTRL_26:
case RT5665_HP_IMP_SENS_CTRL_27:
case RT5665_HP_IMP_SENS_CTRL_28:
case RT5665_HP_IMP_SENS_CTRL_29:
case RT5665_HP_IMP_SENS_CTRL_30:
case RT5665_HP_IMP_SENS_CTRL_31:
case RT5665_HP_IMP_SENS_CTRL_32:
case RT5665_HP_IMP_SENS_CTRL_33:
case RT5665_HP_IMP_SENS_CTRL_34:
case RT5665_HP_LOGIC_CTRL_1:
case RT5665_HP_LOGIC_CTRL_2:
case RT5665_HP_LOGIC_CTRL_3:
case RT5665_HP_CALIB_CTRL_1:
case RT5665_HP_CALIB_CTRL_2:
case RT5665_HP_CALIB_CTRL_3:
case RT5665_HP_CALIB_CTRL_4:
case RT5665_HP_CALIB_CTRL_5:
case RT5665_HP_CALIB_CTRL_6:
case RT5665_HP_CALIB_CTRL_7:
case RT5665_HP_CALIB_CTRL_9:
case RT5665_HP_CALIB_CTRL_10:
case RT5665_HP_CALIB_CTRL_11:
case RT5665_HP_CALIB_STA_1:
case RT5665_HP_CALIB_STA_2:
case RT5665_HP_CALIB_STA_3:
case RT5665_HP_CALIB_STA_4:
case RT5665_HP_CALIB_STA_5:
case RT5665_HP_CALIB_STA_6:
case RT5665_HP_CALIB_STA_7:
case RT5665_HP_CALIB_STA_8:
case RT5665_HP_CALIB_STA_9:
case RT5665_HP_CALIB_STA_10:
case RT5665_HP_CALIB_STA_11:
case RT5665_PGM_TAB_CTRL1:
case RT5665_PGM_TAB_CTRL2:
case RT5665_PGM_TAB_CTRL3:
case RT5665_PGM_TAB_CTRL4:
case RT5665_PGM_TAB_CTRL5:
case RT5665_PGM_TAB_CTRL6:
case RT5665_PGM_TAB_CTRL7:
case RT5665_PGM_TAB_CTRL8:
case RT5665_PGM_TAB_CTRL9:
case RT5665_SAR_IL_CMD_1:
case RT5665_SAR_IL_CMD_2:
case RT5665_SAR_IL_CMD_3:
case RT5665_SAR_IL_CMD_4:
case RT5665_SAR_IL_CMD_5:
case RT5665_SAR_IL_CMD_6:
case RT5665_SAR_IL_CMD_7:
case RT5665_SAR_IL_CMD_8:
case RT5665_SAR_IL_CMD_9:
case RT5665_SAR_IL_CMD_10:
case RT5665_SAR_IL_CMD_11:
case RT5665_SAR_IL_CMD_12:
case RT5665_DRC1_CTRL_0:
case RT5665_DRC1_CTRL_1:
case RT5665_DRC1_CTRL_2:
case RT5665_DRC1_CTRL_3:
case RT5665_DRC1_CTRL_4:
case RT5665_DRC1_CTRL_5:
case RT5665_DRC1_CTRL_6:
case RT5665_DRC1_HARD_LMT_CTRL_1:
case RT5665_DRC1_HARD_LMT_CTRL_2:
case RT5665_DRC1_PRIV_1:
case RT5665_DRC1_PRIV_2:
case RT5665_DRC1_PRIV_3:
case RT5665_DRC1_PRIV_4:
case RT5665_DRC1_PRIV_5:
case RT5665_DRC1_PRIV_6:
case RT5665_DRC1_PRIV_7:
case RT5665_DRC1_PRIV_8:
case RT5665_ALC_PGA_CTRL_1:
case RT5665_ALC_PGA_CTRL_2:
case RT5665_ALC_PGA_CTRL_3:
case RT5665_ALC_PGA_CTRL_4:
case RT5665_ALC_PGA_CTRL_5:
case RT5665_ALC_PGA_CTRL_6:
case RT5665_ALC_PGA_CTRL_7:
case RT5665_ALC_PGA_CTRL_8:
case RT5665_ALC_PGA_STA_1:
case RT5665_ALC_PGA_STA_2:
case RT5665_ALC_PGA_STA_3:
case RT5665_EQ_AUTO_RCV_CTRL1:
case RT5665_EQ_AUTO_RCV_CTRL2:
case RT5665_EQ_AUTO_RCV_CTRL3:
case RT5665_EQ_AUTO_RCV_CTRL4:
case RT5665_EQ_AUTO_RCV_CTRL5:
case RT5665_EQ_AUTO_RCV_CTRL6:
case RT5665_EQ_AUTO_RCV_CTRL7:
case RT5665_EQ_AUTO_RCV_CTRL8:
case RT5665_EQ_AUTO_RCV_CTRL9:
case RT5665_EQ_AUTO_RCV_CTRL10:
case RT5665_EQ_AUTO_RCV_CTRL11:
case RT5665_EQ_AUTO_RCV_CTRL12:
case RT5665_EQ_AUTO_RCV_CTRL13:
case RT5665_ADC_L_EQ_LPF1_A1:
case RT5665_R_EQ_LPF1_A1:
case RT5665_L_EQ_LPF1_H0:
case RT5665_R_EQ_LPF1_H0:
case RT5665_L_EQ_BPF1_A1:
case RT5665_R_EQ_BPF1_A1:
case RT5665_L_EQ_BPF1_A2:
case RT5665_R_EQ_BPF1_A2:
case RT5665_L_EQ_BPF1_H0:
case RT5665_R_EQ_BPF1_H0:
case RT5665_L_EQ_BPF2_A1:
case RT5665_R_EQ_BPF2_A1:
case RT5665_L_EQ_BPF2_A2:
case RT5665_R_EQ_BPF2_A2:
case RT5665_L_EQ_BPF2_H0:
case RT5665_R_EQ_BPF2_H0:
case RT5665_L_EQ_BPF3_A1:
case RT5665_R_EQ_BPF3_A1:
case RT5665_L_EQ_BPF3_A2:
case RT5665_R_EQ_BPF3_A2:
case RT5665_L_EQ_BPF3_H0:
case RT5665_R_EQ_BPF3_H0:
case RT5665_L_EQ_BPF4_A1:
case RT5665_R_EQ_BPF4_A1:
case RT5665_L_EQ_BPF4_A2:
case RT5665_R_EQ_BPF4_A2:
case RT5665_L_EQ_BPF4_H0:
case RT5665_R_EQ_BPF4_H0:
case RT5665_L_EQ_HPF1_A1:
case RT5665_R_EQ_HPF1_A1:
case RT5665_L_EQ_HPF1_H0:
case RT5665_R_EQ_HPF1_H0:
case RT5665_L_EQ_PRE_VOL:
case RT5665_R_EQ_PRE_VOL:
case RT5665_L_EQ_POST_VOL:
case RT5665_R_EQ_POST_VOL:
case RT5665_SCAN_MODE_CTRL:
case RT5665_I2C_MODE:
return true;
default:
return false;
}
}
static int rt5665_hp_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (snd_soc_read(codec, RT5665_STO_NG2_CTRL_1) & RT5665_NG2_EN) {
snd_soc_update_bits(codec, RT5665_STO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_DIS);
snd_soc_update_bits(codec, RT5665_STO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_EN);
}
return ret;
}
static int rt5665_mono_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (snd_soc_read(codec, RT5665_MONO_NG2_CTRL_1) & RT5665_NG2_EN) {
snd_soc_update_bits(codec, RT5665_MONO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_DIS);
snd_soc_update_bits(codec, RT5665_MONO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_EN);
}
return ret;
}
int rt5665_sel_asrc_clk_src(struct snd_soc_codec *codec,
unsigned int filter_mask, unsigned int clk_src)
{
unsigned int asrc2_mask = 0;
unsigned int asrc2_value = 0;
unsigned int asrc3_mask = 0;
unsigned int asrc3_value = 0;
switch (clk_src) {
case RT5665_CLK_SEL_SYS:
case RT5665_CLK_SEL_I2S1_ASRC:
case RT5665_CLK_SEL_I2S2_ASRC:
case RT5665_CLK_SEL_I2S3_ASRC:
case RT5665_CLK_SEL_SYS2:
case RT5665_CLK_SEL_SYS3:
case RT5665_CLK_SEL_SYS4:
break;
default:
return -EINVAL;
}
if (filter_mask & RT5665_DA_STEREO1_FILTER) {
asrc2_mask |= RT5665_DA_STO1_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5665_DA_STO1_CLK_SEL_MASK)
| (clk_src << RT5665_DA_STO1_CLK_SEL_SFT);
}
if (filter_mask & RT5665_DA_STEREO2_FILTER) {
asrc2_mask |= RT5665_DA_STO2_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5665_DA_STO2_CLK_SEL_MASK)
| (clk_src << RT5665_DA_STO2_CLK_SEL_SFT);
}
if (filter_mask & RT5665_DA_MONO_L_FILTER) {
asrc2_mask |= RT5665_DA_MONOL_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5665_DA_MONOL_CLK_SEL_MASK)
| (clk_src << RT5665_DA_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5665_DA_MONO_R_FILTER) {
asrc2_mask |= RT5665_DA_MONOR_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5665_DA_MONOR_CLK_SEL_MASK)
| (clk_src << RT5665_DA_MONOR_CLK_SEL_SFT);
}
if (filter_mask & RT5665_AD_STEREO1_FILTER) {
asrc3_mask |= RT5665_AD_STO1_CLK_SEL_MASK;
asrc3_value = (asrc2_value & ~RT5665_AD_STO1_CLK_SEL_MASK)
| (clk_src << RT5665_AD_STO1_CLK_SEL_SFT);
}
if (filter_mask & RT5665_AD_STEREO2_FILTER) {
asrc3_mask |= RT5665_AD_STO2_CLK_SEL_MASK;
asrc3_value = (asrc2_value & ~RT5665_AD_STO2_CLK_SEL_MASK)
| (clk_src << RT5665_AD_STO2_CLK_SEL_SFT);
}
if (filter_mask & RT5665_AD_MONO_L_FILTER) {
asrc3_mask |= RT5665_AD_MONOL_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5665_AD_MONOL_CLK_SEL_MASK)
| (clk_src << RT5665_AD_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5665_AD_MONO_R_FILTER) {
asrc3_mask |= RT5665_AD_MONOR_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5665_AD_MONOR_CLK_SEL_MASK)
| (clk_src << RT5665_AD_MONOR_CLK_SEL_SFT);
}
if (asrc2_mask)
snd_soc_update_bits(codec, RT5665_ASRC_2,
asrc2_mask, asrc2_value);
if (asrc3_mask)
snd_soc_update_bits(codec, RT5665_ASRC_3,
asrc3_mask, asrc3_value);
return 0;
}
static int rt5665_button_detect(struct snd_soc_codec *codec)
{
int btn_type, val;
val = snd_soc_read(codec, RT5665_4BTN_IL_CMD_1);
btn_type = val & 0xfff0;
snd_soc_write(codec, RT5665_4BTN_IL_CMD_1, val);
return btn_type;
}
static void rt5665_enable_push_button_irq(struct snd_soc_codec *codec,
bool enable)
{
if (enable) {
snd_soc_write(codec, RT5665_4BTN_IL_CMD_1, 0x000b);
snd_soc_write(codec, RT5665_IL_CMD_1, 0x0048);
snd_soc_update_bits(codec, RT5665_4BTN_IL_CMD_2,
RT5665_4BTN_IL_MASK | RT5665_4BTN_IL_RST_MASK,
RT5665_4BTN_IL_EN | RT5665_4BTN_IL_NOR);
snd_soc_update_bits(codec, RT5665_IRQ_CTRL_3,
RT5665_IL_IRQ_MASK, RT5665_IL_IRQ_EN);
} else {
snd_soc_update_bits(codec, RT5665_IRQ_CTRL_3,
RT5665_IL_IRQ_MASK, RT5665_IL_IRQ_DIS);
snd_soc_update_bits(codec, RT5665_4BTN_IL_CMD_2,
RT5665_4BTN_IL_MASK, RT5665_4BTN_IL_DIS);
snd_soc_update_bits(codec, RT5665_4BTN_IL_CMD_2,
RT5665_4BTN_IL_RST_MASK, RT5665_4BTN_IL_RST);
}
}
static int rt5665_headset_detect(struct snd_soc_codec *codec, int jack_insert)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
unsigned int sar_hs_type, val;
if (jack_insert) {
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
snd_soc_dapm_sync(dapm);
regmap_update_bits(rt5665->regmap, RT5665_MICBIAS_2, 0x100,
0x100);
regmap_read(rt5665->regmap, RT5665_GPIO_STA, &val);
if (val & 0x4) {
regmap_update_bits(rt5665->regmap, RT5665_EJD_CTRL_1,
0x100, 0);
regmap_read(rt5665->regmap, RT5665_GPIO_STA, &val);
while (val & 0x4) {
usleep_range(10000, 15000);
regmap_read(rt5665->regmap, RT5665_GPIO_STA,
&val);
}
}
regmap_update_bits(rt5665->regmap, RT5665_EJD_CTRL_1,
0x180, 0x180);
regmap_write(rt5665->regmap, RT5665_EJD_CTRL_3, 0x3424);
regmap_write(rt5665->regmap, RT5665_SAR_IL_CMD_1, 0xa291);
rt5665->sar_adc_value = snd_soc_read(rt5665->codec,
RT5665_SAR_IL_CMD_4) & 0x7ff;
sar_hs_type = rt5665->pdata.sar_hs_type ?
rt5665->pdata.sar_hs_type : 729;
if (rt5665->sar_adc_value > sar_hs_type) {
rt5665->jack_type = SND_JACK_HEADSET;
rt5665_enable_push_button_irq(codec, true);
} else {
rt5665->jack_type = SND_JACK_HEADPHONE;
regmap_write(rt5665->regmap, RT5665_SAR_IL_CMD_1,
0x2291);
regmap_update_bits(rt5665->regmap, RT5665_MICBIAS_2,
0x100, 0);
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
snd_soc_dapm_sync(dapm);
}
} else {
regmap_write(rt5665->regmap, RT5665_SAR_IL_CMD_1, 0x2291);
regmap_update_bits(rt5665->regmap, RT5665_MICBIAS_2, 0x100, 0);
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
snd_soc_dapm_sync(dapm);
if (rt5665->jack_type == SND_JACK_HEADSET)
rt5665_enable_push_button_irq(codec, false);
rt5665->jack_type = 0;
}
dev_dbg(codec->dev, "jack_type = %d\n", rt5665->jack_type);
return rt5665->jack_type;
}
static irqreturn_t rt5665_irq(int irq, void *data)
{
struct rt5665_priv *rt5665 = data;
mod_delayed_work(system_power_efficient_wq,
&rt5665->jack_detect_work, msecs_to_jiffies(250));
return IRQ_HANDLED;
}
static void rt5665_jd_check_handler(struct work_struct *work)
{
struct rt5665_priv *rt5665 = container_of(work, struct rt5665_priv,
jd_check_work.work);
if (snd_soc_read(rt5665->codec, RT5665_AJD1_CTRL) & 0x0010) {
rt5665->jack_type = rt5665_headset_detect(rt5665->codec, 0);
snd_soc_jack_report(rt5665->hs_jack, rt5665->jack_type,
SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3);
} else {
schedule_delayed_work(&rt5665->jd_check_work, 500);
}
}
int rt5665_set_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *hs_jack)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
switch (rt5665->pdata.jd_src) {
case RT5665_JD1:
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_1,
RT5665_GP1_PIN_MASK, RT5665_GP1_PIN_IRQ);
regmap_update_bits(rt5665->regmap, RT5665_RC_CLK_CTRL,
0xc000, 0xc000);
regmap_update_bits(rt5665->regmap, RT5665_PWR_ANLG_2,
RT5665_PWR_JD1, RT5665_PWR_JD1);
regmap_update_bits(rt5665->regmap, RT5665_IRQ_CTRL_1, 0x8, 0x8);
break;
case RT5665_JD_NULL:
break;
default:
dev_warn(codec->dev, "Wrong JD source\n");
break;
}
rt5665->hs_jack = hs_jack;
return 0;
}
static void rt5665_jack_detect_handler(struct work_struct *work)
{
struct rt5665_priv *rt5665 =
container_of(work, struct rt5665_priv, jack_detect_work.work);
int val, btn_type;
while (!rt5665->codec) {
pr_debug("%s codec = null\n", __func__);
usleep_range(10000, 15000);
}
while (!rt5665->codec->component.card->instantiated) {
pr_debug("%s\n", __func__);
usleep_range(10000, 15000);
}
mutex_lock(&rt5665->calibrate_mutex);
val = snd_soc_read(rt5665->codec, RT5665_AJD1_CTRL) & 0x0010;
if (!val) {
if (rt5665->jack_type == 0) {
rt5665->jack_type =
rt5665_headset_detect(rt5665->codec, 1);
} else {
rt5665->jack_type = SND_JACK_HEADSET;
btn_type = rt5665_button_detect(rt5665->codec);
switch (btn_type) {
case 0x8000:
case 0x4000:
case 0x2000:
rt5665->jack_type |= SND_JACK_BTN_0;
break;
case 0x1000:
case 0x0800:
case 0x0400:
rt5665->jack_type |= SND_JACK_BTN_1;
break;
case 0x0200:
case 0x0100:
case 0x0080:
rt5665->jack_type |= SND_JACK_BTN_2;
break;
case 0x0040:
case 0x0020:
case 0x0010:
rt5665->jack_type |= SND_JACK_BTN_3;
break;
case 0x0000:
break;
default:
btn_type = 0;
dev_err(rt5665->codec->dev,
"Unexpected button code 0x%04x\n",
btn_type);
break;
}
}
} else {
rt5665->jack_type = rt5665_headset_detect(rt5665->codec, 0);
}
snd_soc_jack_report(rt5665->hs_jack, rt5665->jack_type,
SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3);
if (rt5665->jack_type & (SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3))
schedule_delayed_work(&rt5665->jd_check_work, 0);
else
cancel_delayed_work_sync(&rt5665->jd_check_work);
mutex_unlock(&rt5665->calibrate_mutex);
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
int pd, idx = -EINVAL;
pd = rl6231_get_pre_div(rt5665->regmap,
RT5665_ADDA_CLK_1, RT5665_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rt5665->sysclk / pd);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else {
snd_soc_update_bits(codec, RT5665_DMIC_CTRL_1,
RT5665_DMIC_CLK_MASK, idx << RT5665_DMIC_CLK_SFT);
}
return idx;
}
static int rt5665_charge_pump_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5665_HP_CHARGE_PUMP_1,
RT5665_PM_HP_MASK | RT5665_OSW_L_MASK,
RT5665_PM_HP_HV | RT5665_OSW_L_EN);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, RT5665_HP_CHARGE_PUMP_1,
RT5665_PM_HP_MASK | RT5665_OSW_L_MASK,
RT5665_PM_HP_LV | RT5665_OSW_L_DIS);
break;
default:
return 0;
}
return 0;
}
static int is_sys_clk_from_pll(struct snd_soc_dapm_widget *w,
struct snd_soc_dapm_widget *sink)
{
unsigned int val;
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
val = snd_soc_read(codec, RT5665_GLB_CLK);
val &= RT5665_SCLK_SRC_MASK;
if (val == RT5665_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int is_using_asrc(struct snd_soc_dapm_widget *w,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg, shift, val;
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (w->shift) {
case RT5665_ADC_MONO_R_ASRC_SFT:
reg = RT5665_ASRC_3;
shift = RT5665_AD_MONOR_CLK_SEL_SFT;
break;
case RT5665_ADC_MONO_L_ASRC_SFT:
reg = RT5665_ASRC_3;
shift = RT5665_AD_MONOL_CLK_SEL_SFT;
break;
case RT5665_ADC_STO1_ASRC_SFT:
reg = RT5665_ASRC_3;
shift = RT5665_AD_STO1_CLK_SEL_SFT;
break;
case RT5665_ADC_STO2_ASRC_SFT:
reg = RT5665_ASRC_3;
shift = RT5665_AD_STO2_CLK_SEL_SFT;
break;
case RT5665_DAC_MONO_R_ASRC_SFT:
reg = RT5665_ASRC_2;
shift = RT5665_DA_MONOR_CLK_SEL_SFT;
break;
case RT5665_DAC_MONO_L_ASRC_SFT:
reg = RT5665_ASRC_2;
shift = RT5665_DA_MONOL_CLK_SEL_SFT;
break;
case RT5665_DAC_STO1_ASRC_SFT:
reg = RT5665_ASRC_2;
shift = RT5665_DA_STO1_CLK_SEL_SFT;
break;
case RT5665_DAC_STO2_ASRC_SFT:
reg = RT5665_ASRC_2;
shift = RT5665_DA_STO2_CLK_SEL_SFT;
break;
default:
return 0;
}
val = (snd_soc_read(codec, reg) >> shift) & 0xf;
switch (val) {
case RT5665_CLK_SEL_I2S1_ASRC:
case RT5665_CLK_SEL_I2S2_ASRC:
case RT5665_CLK_SEL_I2S3_ASRC:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_I2S_PD1_MASK, RT5665_I2S_PD1_2);
return 1;
default:
return 0;
}
}
static int rt5665_mono_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5665_MONO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_EN);
snd_soc_update_bits(codec, RT5665_MONO_AMP_CALIB_CTRL_1, 0x40,
0x0);
snd_soc_update_bits(codec, RT5665_MONO_OUT, 0x10, 0x10);
snd_soc_update_bits(codec, RT5665_MONO_OUT, 0x20, 0x20);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, RT5665_MONO_OUT, 0x20, 0);
snd_soc_update_bits(codec, RT5665_MONO_OUT, 0x10, 0);
snd_soc_update_bits(codec, RT5665_MONO_AMP_CALIB_CTRL_1, 0x40,
0x40);
snd_soc_update_bits(codec, RT5665_MONO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_DIS);
break;
default:
return 0;
}
return 0;
}
static int rt5665_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5665_STO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_EN);
snd_soc_write(codec, RT5665_HP_LOGIC_CTRL_2, 0x0003);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, RT5665_HP_LOGIC_CTRL_2, 0x0002);
snd_soc_update_bits(codec, RT5665_STO_NG2_CTRL_1,
RT5665_NG2_EN_MASK, RT5665_NG2_DIS);
break;
default:
return 0;
}
return 0;
}
static int rt5665_lout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5665_DEPOP_1,
RT5665_PUMP_EN, RT5665_PUMP_EN);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5665_DEPOP_1,
RT5665_PUMP_EN, 0);
break;
default:
return 0;
}
return 0;
}
static int set_dmic_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(150);
break;
default:
return 0;
}
return 0;
}
static int rt5655_set_verf(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
switch (w->shift) {
case RT5665_PWR_VREF1_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV1, 0);
break;
case RT5665_PWR_VREF2_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV2, 0);
break;
case RT5665_PWR_VREF3_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV3, 0);
break;
default:
break;
}
break;
case SND_SOC_DAPM_POST_PMU:
usleep_range(15000, 20000);
switch (w->shift) {
case RT5665_PWR_VREF1_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV1, RT5665_PWR_FV1);
break;
case RT5665_PWR_VREF2_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV2, RT5665_PWR_FV2);
break;
case RT5665_PWR_VREF3_BIT:
snd_soc_update_bits(codec, RT5665_PWR_ANLG_1,
RT5665_PWR_FV3, RT5665_PWR_FV3);
break;
default:
break;
}
break;
default:
return 0;
}
return 0;
}
static int rt5665_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk, val_bits = 0x0100;
int pre_div, frame_size;
rt5665->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5665->sysclk, rt5665->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5665->lrck[dai->id], dai->id);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
dev_dbg(dai->dev, "lrck is %dHz and pre_div is %d for iis %d\n",
rt5665->lrck[dai->id], pre_div, dai->id);
switch (params_width(params)) {
case 16:
val_bits = 0x0100;
break;
case 20:
val_len |= RT5665_I2S_DL_20;
val_bits = 0x1300;
break;
case 24:
val_len |= RT5665_I2S_DL_24;
val_bits = 0x2500;
break;
case 8:
val_len |= RT5665_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5665_AIF1_1:
case RT5665_AIF1_2:
mask_clk = RT5665_I2S_PD1_MASK;
val_clk = pre_div << RT5665_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5665_I2S1_SDP,
RT5665_I2S_DL_MASK, val_len);
break;
case RT5665_AIF2_1:
case RT5665_AIF2_2:
mask_clk = RT5665_I2S_PD2_MASK;
val_clk = pre_div << RT5665_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5665_I2S2_SDP,
RT5665_I2S_DL_MASK, val_len);
break;
case RT5665_AIF3:
mask_clk = RT5665_I2S_PD3_MASK;
val_clk = pre_div << RT5665_I2S_PD3_SFT;
snd_soc_update_bits(codec, RT5665_I2S3_SDP,
RT5665_I2S_DL_MASK, val_len);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1, mask_clk, val_clk);
snd_soc_update_bits(codec, RT5665_STO1_DAC_SIL_DET, 0x3700, val_bits);
switch (rt5665->lrck[dai->id]) {
case 192000:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_DAC_OSR_MASK | RT5665_ADC_OSR_MASK,
RT5665_DAC_OSR_32 | RT5665_ADC_OSR_32);
break;
case 96000:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_DAC_OSR_MASK | RT5665_ADC_OSR_MASK,
RT5665_DAC_OSR_64 | RT5665_ADC_OSR_64);
break;
default:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_DAC_OSR_MASK | RT5665_ADC_OSR_MASK,
RT5665_DAC_OSR_128 | RT5665_ADC_OSR_128);
break;
}
return 0;
}
static int rt5665_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5665->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5665_I2S_MS_S;
rt5665->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5665_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5665_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5665_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5665_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5665_AIF1_1:
case RT5665_AIF1_2:
snd_soc_update_bits(codec, RT5665_I2S1_SDP,
RT5665_I2S_MS_MASK | RT5665_I2S_BP_MASK |
RT5665_I2S_DF_MASK, reg_val);
break;
case RT5665_AIF2_1:
case RT5665_AIF2_2:
snd_soc_update_bits(codec, RT5665_I2S2_SDP,
RT5665_I2S_MS_MASK | RT5665_I2S_BP_MASK |
RT5665_I2S_DF_MASK, reg_val);
break;
case RT5665_AIF3:
snd_soc_update_bits(codec, RT5665_I2S3_SDP,
RT5665_I2S_MS_MASK | RT5665_I2S_BP_MASK |
RT5665_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5665_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5665->sysclk && clk_id == rt5665->sysclk_src)
return 0;
switch (clk_id) {
case RT5665_SCLK_S_MCLK:
reg_val |= RT5665_SCLK_SRC_MCLK;
break;
case RT5665_SCLK_S_PLL1:
reg_val |= RT5665_SCLK_SRC_PLL1;
break;
case RT5665_SCLK_S_RCCLK:
reg_val |= RT5665_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_SCLK_SRC_MASK, reg_val);
rt5665->sysclk = freq;
rt5665->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5665_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int Source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (Source == rt5665->pll_src && freq_in == rt5665->pll_in &&
freq_out == rt5665->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5665->pll_in = 0;
rt5665->pll_out = 0;
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_SCLK_SRC_MASK, RT5665_SCLK_SRC_MCLK);
return 0;
}
switch (Source) {
case RT5665_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_PLL1_SRC_MASK, RT5665_PLL1_SRC_MCLK);
break;
case RT5665_PLL1_S_BCLK1:
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_PLL1_SRC_MASK, RT5665_PLL1_SRC_BCLK1);
break;
case RT5665_PLL1_S_BCLK2:
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_PLL1_SRC_MASK, RT5665_PLL1_SRC_BCLK2);
break;
case RT5665_PLL1_S_BCLK3:
snd_soc_update_bits(codec, RT5665_GLB_CLK,
RT5665_PLL1_SRC_MASK, RT5665_PLL1_SRC_BCLK3);
break;
default:
dev_err(codec->dev, "Unknown PLL Source %d\n", Source);
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
snd_soc_write(codec, RT5665_PLL_CTRL_1,
pll_code.n_code << RT5665_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5665_PLL_CTRL_2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5665_PLL_M_SFT |
pll_code.m_bp << RT5665_PLL_M_BP_SFT);
rt5665->pll_in = freq_in;
rt5665->pll_out = freq_out;
rt5665->pll_src = Source;
return 0;
}
static int rt5665_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
if (rx_mask || tx_mask)
val |= RT5665_I2S1_MODE_TDM;
switch (slots) {
case 4:
val |= RT5665_TDM_IN_CH_4;
val |= RT5665_TDM_OUT_CH_4;
break;
case 6:
val |= RT5665_TDM_IN_CH_6;
val |= RT5665_TDM_OUT_CH_6;
break;
case 8:
val |= RT5665_TDM_IN_CH_8;
val |= RT5665_TDM_OUT_CH_8;
break;
case 2:
break;
default:
return -EINVAL;
}
switch (slot_width) {
case 20:
val |= RT5665_TDM_IN_LEN_20;
val |= RT5665_TDM_OUT_LEN_20;
break;
case 24:
val |= RT5665_TDM_IN_LEN_24;
val |= RT5665_TDM_OUT_LEN_24;
break;
case 32:
val |= RT5665_TDM_IN_LEN_32;
val |= RT5665_TDM_OUT_LEN_32;
break;
case 16:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5665_TDM_CTRL_1,
RT5665_I2S1_MODE_MASK | RT5665_TDM_IN_CH_MASK |
RT5665_TDM_OUT_CH_MASK | RT5665_TDM_IN_LEN_MASK |
RT5665_TDM_OUT_LEN_MASK, val);
return 0;
}
static int rt5665_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "%s ratio=%d\n", __func__, ratio);
rt5665->bclk[dai->id] = ratio;
if (ratio == 64) {
switch (dai->id) {
case RT5665_AIF2_1:
case RT5665_AIF2_2:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_I2S_BCLK_MS2_MASK,
RT5665_I2S_BCLK_MS2_64);
break;
case RT5665_AIF3:
snd_soc_update_bits(codec, RT5665_ADDA_CLK_1,
RT5665_I2S_BCLK_MS3_MASK,
RT5665_I2S_BCLK_MS3_64);
break;
}
}
return 0;
}
static int rt5665_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(rt5665->regmap, RT5665_DIG_MISC,
RT5665_DIG_GATE_CTRL, RT5665_DIG_GATE_CTRL);
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(rt5665->regmap, RT5665_PWR_DIG_1,
RT5665_PWR_LDO, RT5665_PWR_LDO);
regmap_update_bits(rt5665->regmap, RT5665_PWR_ANLG_1,
RT5665_PWR_MB, RT5665_PWR_MB);
regmap_update_bits(rt5665->regmap, RT5665_DIG_MISC,
RT5665_DIG_GATE_CTRL, 0);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(rt5665->regmap, RT5665_PWR_DIG_1,
RT5665_PWR_LDO, 0);
regmap_update_bits(rt5665->regmap, RT5665_PWR_ANLG_1,
RT5665_PWR_MB, 0);
break;
default:
break;
}
return 0;
}
static int rt5665_probe(struct snd_soc_codec *codec)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
rt5665->codec = codec;
schedule_delayed_work(&rt5665->calibrate_work, msecs_to_jiffies(100));
return 0;
}
static int rt5665_remove(struct snd_soc_codec *codec)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5665->regmap, RT5665_RESET, 0);
return 0;
}
static int rt5665_suspend(struct snd_soc_codec *codec)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5665->regmap, true);
regcache_mark_dirty(rt5665->regmap);
return 0;
}
static int rt5665_resume(struct snd_soc_codec *codec)
{
struct rt5665_priv *rt5665 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5665->regmap, false);
regcache_sync(rt5665->regmap);
return 0;
}
static int rt5665_parse_dt(struct rt5665_priv *rt5665, struct device *dev)
{
rt5665->pdata.in1_diff = of_property_read_bool(dev->of_node,
"realtek,in1-differential");
rt5665->pdata.in2_diff = of_property_read_bool(dev->of_node,
"realtek,in2-differential");
rt5665->pdata.in3_diff = of_property_read_bool(dev->of_node,
"realtek,in3-differential");
rt5665->pdata.in4_diff = of_property_read_bool(dev->of_node,
"realtek,in4-differential");
of_property_read_u32(dev->of_node, "realtek,dmic1-data-pin",
&rt5665->pdata.dmic1_data_pin);
of_property_read_u32(dev->of_node, "realtek,dmic2-data-pin",
&rt5665->pdata.dmic2_data_pin);
of_property_read_u32(dev->of_node, "realtek,jd-src",
&rt5665->pdata.jd_src);
rt5665->pdata.ldo1_en = of_get_named_gpio(dev->of_node,
"realtek,ldo1-en-gpios", 0);
return 0;
}
static void rt5665_calibrate(struct rt5665_priv *rt5665)
{
int value, count;
mutex_lock(&rt5665->calibrate_mutex);
regcache_cache_bypass(rt5665->regmap, true);
regmap_write(rt5665->regmap, RT5665_RESET, 0);
regmap_write(rt5665->regmap, RT5665_BIAS_CUR_CTRL_8, 0xa602);
regmap_write(rt5665->regmap, RT5665_HP_CHARGE_PUMP_1, 0x0c26);
regmap_write(rt5665->regmap, RT5665_MONOMIX_IN_GAIN, 0x021f);
regmap_write(rt5665->regmap, RT5665_MONO_OUT, 0x480a);
regmap_write(rt5665->regmap, RT5665_PWR_MIXER, 0x083f);
regmap_write(rt5665->regmap, RT5665_PWR_DIG_1, 0x0180);
regmap_write(rt5665->regmap, RT5665_EJD_CTRL_1, 0x4040);
regmap_write(rt5665->regmap, RT5665_HP_LOGIC_CTRL_2, 0x0000);
regmap_write(rt5665->regmap, RT5665_DIG_MISC, 0x0001);
regmap_write(rt5665->regmap, RT5665_MICBIAS_2, 0x0380);
regmap_write(rt5665->regmap, RT5665_GLB_CLK, 0x8000);
regmap_write(rt5665->regmap, RT5665_ADDA_CLK_1, 0x1000);
regmap_write(rt5665->regmap, RT5665_CHOP_DAC, 0x3030);
regmap_write(rt5665->regmap, RT5665_CALIB_ADC_CTRL, 0x3c05);
regmap_write(rt5665->regmap, RT5665_PWR_ANLG_1, 0xaa3e);
usleep_range(15000, 20000);
regmap_write(rt5665->regmap, RT5665_PWR_ANLG_1, 0xfe7e);
regmap_write(rt5665->regmap, RT5665_HP_CALIB_CTRL_2, 0x0321);
regmap_write(rt5665->regmap, RT5665_HP_CALIB_CTRL_1, 0xfc00);
count = 0;
while (true) {
regmap_read(rt5665->regmap, RT5665_HP_CALIB_STA_1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 60) {
pr_err("HP Calibration Failure\n");
regmap_write(rt5665->regmap, RT5665_RESET, 0);
regcache_cache_bypass(rt5665->regmap, false);
goto out_unlock;
}
count++;
}
regmap_write(rt5665->regmap, RT5665_MONO_AMP_CALIB_CTRL_1, 0x9e24);
count = 0;
while (true) {
regmap_read(rt5665->regmap, RT5665_MONO_AMP_CALIB_STA1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 60) {
pr_err("MONO Calibration Failure\n");
regmap_write(rt5665->regmap, RT5665_RESET, 0);
regcache_cache_bypass(rt5665->regmap, false);
goto out_unlock;
}
count++;
}
regmap_write(rt5665->regmap, RT5665_RESET, 0);
regcache_cache_bypass(rt5665->regmap, false);
regcache_mark_dirty(rt5665->regmap);
regcache_sync(rt5665->regmap);
regmap_write(rt5665->regmap, RT5665_BIAS_CUR_CTRL_8, 0xa602);
regmap_write(rt5665->regmap, RT5665_ASRC_8, 0x0120);
out_unlock:
mutex_unlock(&rt5665->calibrate_mutex);
}
static void rt5665_calibrate_handler(struct work_struct *work)
{
struct rt5665_priv *rt5665 = container_of(work, struct rt5665_priv,
calibrate_work.work);
while (!rt5665->codec->component.card->instantiated) {
pr_debug("%s\n", __func__);
usleep_range(10000, 15000);
}
rt5665_calibrate(rt5665);
}
static int rt5665_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5665_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5665_priv *rt5665;
int i, ret;
unsigned int val;
rt5665 = devm_kzalloc(&i2c->dev, sizeof(struct rt5665_priv),
GFP_KERNEL);
if (rt5665 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5665);
if (pdata)
rt5665->pdata = *pdata;
else
rt5665_parse_dt(rt5665, &i2c->dev);
for (i = 0; i < ARRAY_SIZE(rt5665->supplies); i++)
rt5665->supplies[i].supply = rt5665_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(rt5665->supplies),
rt5665->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(rt5665->supplies),
rt5665->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
if (gpio_is_valid(rt5665->pdata.ldo1_en)) {
if (devm_gpio_request_one(&i2c->dev, rt5665->pdata.ldo1_en,
GPIOF_OUT_INIT_HIGH, "rt5665"))
dev_err(&i2c->dev, "Fail gpio_request gpio_ldo\n");
}
usleep_range(300000, 350000);
rt5665->regmap = devm_regmap_init_i2c(i2c, &rt5665_regmap);
if (IS_ERR(rt5665->regmap)) {
ret = PTR_ERR(rt5665->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5665->regmap, RT5665_DEVICE_ID, &val);
if (val != DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt5665\n", val);
return -ENODEV;
}
regmap_read(rt5665->regmap, RT5665_RESET, &val);
switch (val) {
case 0x0:
rt5665->id = CODEC_5666;
break;
case 0x6:
rt5665->id = CODEC_5668;
break;
case 0x3:
default:
rt5665->id = CODEC_5665;
break;
}
regmap_write(rt5665->regmap, RT5665_RESET, 0);
if (rt5665->pdata.in1_diff)
regmap_update_bits(rt5665->regmap, RT5665_IN1_IN2,
RT5665_IN1_DF_MASK, RT5665_IN1_DF_MASK);
if (rt5665->pdata.in2_diff)
regmap_update_bits(rt5665->regmap, RT5665_IN1_IN2,
RT5665_IN2_DF_MASK, RT5665_IN2_DF_MASK);
if (rt5665->pdata.in3_diff)
regmap_update_bits(rt5665->regmap, RT5665_IN3_IN4,
RT5665_IN3_DF_MASK, RT5665_IN3_DF_MASK);
if (rt5665->pdata.in4_diff)
regmap_update_bits(rt5665->regmap, RT5665_IN3_IN4,
RT5665_IN4_DF_MASK, RT5665_IN4_DF_MASK);
if (rt5665->pdata.dmic1_data_pin != RT5665_DMIC1_NULL ||
rt5665->pdata.dmic2_data_pin != RT5665_DMIC2_NULL) {
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_2,
RT5665_GP9_PIN_MASK, RT5665_GP9_PIN_DMIC1_SCL);
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_1,
RT5665_GP8_PIN_MASK, RT5665_GP8_PIN_DMIC2_SCL);
switch (rt5665->pdata.dmic1_data_pin) {
case RT5665_DMIC1_DATA_IN2N:
regmap_update_bits(rt5665->regmap, RT5665_DMIC_CTRL_1,
RT5665_DMIC_1_DP_MASK, RT5665_DMIC_1_DP_IN2N);
break;
case RT5665_DMIC1_DATA_GPIO4:
regmap_update_bits(rt5665->regmap, RT5665_DMIC_CTRL_1,
RT5665_DMIC_1_DP_MASK, RT5665_DMIC_1_DP_GPIO4);
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_1,
RT5665_GP4_PIN_MASK, RT5665_GP4_PIN_DMIC1_SDA);
break;
default:
dev_dbg(&i2c->dev, "no DMIC1\n");
break;
}
switch (rt5665->pdata.dmic2_data_pin) {
case RT5665_DMIC2_DATA_IN2P:
regmap_update_bits(rt5665->regmap, RT5665_DMIC_CTRL_1,
RT5665_DMIC_2_DP_MASK, RT5665_DMIC_2_DP_IN2P);
break;
case RT5665_DMIC2_DATA_GPIO5:
regmap_update_bits(rt5665->regmap,
RT5665_DMIC_CTRL_1,
RT5665_DMIC_2_DP_MASK,
RT5665_DMIC_2_DP_GPIO5);
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_1,
RT5665_GP5_PIN_MASK, RT5665_GP5_PIN_DMIC2_SDA);
break;
default:
dev_dbg(&i2c->dev, "no DMIC2\n");
break;
}
}
regmap_write(rt5665->regmap, RT5665_HP_LOGIC_CTRL_2, 0x0002);
regmap_update_bits(rt5665->regmap, RT5665_EJD_CTRL_1,
0xf000 | RT5665_VREF_POW_MASK, 0xd000 | RT5665_VREF_POW_REG);
regmap_update_bits(rt5665->regmap, RT5665_STO1_DAC_SIL_DET,
RT5665_DEB_STO_DAC_MASK, RT5665_DEB_80_MS);
regmap_update_bits(rt5665->regmap, RT5665_HP_CHARGE_PUMP_1,
RT5665_PM_HP_MASK, RT5665_PM_HP_HV);
if (rt5665->id == CODEC_5666) {
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_2,
RT5665_GP4_PF_MASK, RT5665_GP4_PF_IN);
regmap_update_bits(rt5665->regmap, RT5665_GPIO_CTRL_3,
RT5665_GP8_PF_MASK, RT5665_GP8_PF_IN);
}
regmap_update_bits(rt5665->regmap, RT5665_PWR_ANLG_1,
RT5665_HP_DRIVER_MASK | RT5665_LDO1_DVO_MASK,
RT5665_HP_DRIVER_5X | RT5665_LDO1_DVO_12);
INIT_DELAYED_WORK(&rt5665->jack_detect_work,
rt5665_jack_detect_handler);
INIT_DELAYED_WORK(&rt5665->calibrate_work,
rt5665_calibrate_handler);
INIT_DELAYED_WORK(&rt5665->jd_check_work,
rt5665_jd_check_handler);
mutex_init(&rt5665->calibrate_mutex);
if (i2c->irq) {
ret = devm_request_threaded_irq(&i2c->dev, i2c->irq, NULL,
rt5665_irq, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING
| IRQF_ONESHOT, "rt5665", rt5665);
if (ret)
dev_err(&i2c->dev, "Failed to reguest IRQ: %d\n", ret);
}
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5665,
rt5665_dai, ARRAY_SIZE(rt5665_dai));
}
static int rt5665_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static void rt5665_i2c_shutdown(struct i2c_client *client)
{
struct rt5665_priv *rt5665 = i2c_get_clientdata(client);
regmap_write(rt5665->regmap, RT5665_RESET, 0);
}
