static bool rt5659_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5659_RESET:
case RT5659_EJD_CTRL_2:
case RT5659_SILENCE_CTRL:
case RT5659_DAC2_DIG_VOL:
case RT5659_HP_IMP_GAIN_2:
case RT5659_PDM_OUT_CTRL:
case RT5659_PDM_DATA_CTRL_1:
case RT5659_PDM_DATA_CTRL_4:
case RT5659_HAPTIC_GEN_CTRL_1:
case RT5659_HAPTIC_GEN_CTRL_3:
case RT5659_HAPTIC_LPF_CTRL_3:
case RT5659_CLK_DET:
case RT5659_MICBIAS_1:
case RT5659_ASRC_11:
case RT5659_ADC_EQ_CTRL_1:
case RT5659_DAC_EQ_CTRL_1:
case RT5659_INT_ST_1:
case RT5659_INT_ST_2:
case RT5659_GPIO_STA:
case RT5659_SINE_GEN_CTRL_1:
case RT5659_IL_CMD_1:
case RT5659_4BTN_IL_CMD_1:
case RT5659_PSV_IL_CMD_1:
case RT5659_AJD1_CTRL:
case RT5659_AJD2_AJD3_CTRL:
case RT5659_JD_CTRL_3:
case RT5659_VENDOR_ID:
case RT5659_VENDOR_ID_1:
case RT5659_DEVICE_ID:
case RT5659_MEMORY_TEST:
case RT5659_SOFT_RAMP_DEPOP_DAC_CLK_CTRL:
case RT5659_VOL_TEST:
case RT5659_STO_NG2_CTRL_1:
case RT5659_STO_NG2_CTRL_5:
case RT5659_STO_NG2_CTRL_6:
case RT5659_STO_NG2_CTRL_7:
case RT5659_MONO_NG2_CTRL_1:
case RT5659_MONO_NG2_CTRL_5:
case RT5659_MONO_NG2_CTRL_6:
case RT5659_HP_IMP_SENS_CTRL_1:
case RT5659_HP_IMP_SENS_CTRL_3:
case RT5659_HP_IMP_SENS_CTRL_4:
case RT5659_HP_CALIB_CTRL_1:
case RT5659_HP_CALIB_CTRL_9:
case RT5659_HP_CALIB_STA_1:
case RT5659_HP_CALIB_STA_2:
case RT5659_HP_CALIB_STA_3:
case RT5659_HP_CALIB_STA_4:
case RT5659_HP_CALIB_STA_5:
case RT5659_HP_CALIB_STA_6:
case RT5659_HP_CALIB_STA_7:
case RT5659_HP_CALIB_STA_8:
case RT5659_HP_CALIB_STA_9:
case RT5659_MONO_AMP_CALIB_CTRL_1:
case RT5659_MONO_AMP_CALIB_CTRL_3:
case RT5659_MONO_AMP_CALIB_STA_1:
case RT5659_MONO_AMP_CALIB_STA_2:
case RT5659_MONO_AMP_CALIB_STA_3:
case RT5659_MONO_AMP_CALIB_STA_4:
case RT5659_SPK_PWR_LMT_STA_1:
case RT5659_SPK_PWR_LMT_STA_2:
case RT5659_SPK_PWR_LMT_STA_3:
case RT5659_SPK_PWR_LMT_STA_4:
case RT5659_SPK_PWR_LMT_STA_5:
case RT5659_SPK_PWR_LMT_STA_6:
case RT5659_SPK_DC_CAILB_CTRL_1:
case RT5659_SPK_DC_CAILB_STA_1:
case RT5659_SPK_DC_CAILB_STA_2:
case RT5659_SPK_DC_CAILB_STA_3:
case RT5659_SPK_DC_CAILB_STA_4:
case RT5659_SPK_DC_CAILB_STA_5:
case RT5659_SPK_DC_CAILB_STA_6:
case RT5659_SPK_DC_CAILB_STA_7:
case RT5659_SPK_DC_CAILB_STA_8:
case RT5659_SPK_DC_CAILB_STA_9:
case RT5659_SPK_DC_CAILB_STA_10:
case RT5659_SPK_VDD_STA_1:
case RT5659_SPK_VDD_STA_2:
case RT5659_SPK_DC_DET_CTRL_1:
case RT5659_PURE_DC_DET_CTRL_1:
case RT5659_PURE_DC_DET_CTRL_2:
case RT5659_DRC1_PRIV_1:
case RT5659_DRC1_PRIV_4:
case RT5659_DRC1_PRIV_5:
case RT5659_DRC1_PRIV_6:
case RT5659_DRC1_PRIV_7:
case RT5659_DRC2_PRIV_1:
case RT5659_DRC2_PRIV_4:
case RT5659_DRC2_PRIV_5:
case RT5659_DRC2_PRIV_6:
case RT5659_DRC2_PRIV_7:
case RT5659_ALC_PGA_STA_1:
case RT5659_ALC_PGA_STA_2:
case RT5659_ALC_PGA_STA_3:
return true;
default:
return false;
}
}
static bool rt5659_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5659_RESET:
case RT5659_SPO_VOL:
case RT5659_HP_VOL:
case RT5659_LOUT:
case RT5659_MONO_OUT:
case RT5659_HPL_GAIN:
case RT5659_HPR_GAIN:
case RT5659_MONO_GAIN:
case RT5659_SPDIF_CTRL_1:
case RT5659_SPDIF_CTRL_2:
case RT5659_CAL_BST_CTRL:
case RT5659_IN1_IN2:
case RT5659_IN3_IN4:
case RT5659_INL1_INR1_VOL:
case RT5659_EJD_CTRL_1:
case RT5659_EJD_CTRL_2:
case RT5659_EJD_CTRL_3:
case RT5659_SILENCE_CTRL:
case RT5659_PSV_CTRL:
case RT5659_SIDETONE_CTRL:
case RT5659_DAC1_DIG_VOL:
case RT5659_DAC2_DIG_VOL:
case RT5659_DAC_CTRL:
case RT5659_STO1_ADC_DIG_VOL:
case RT5659_MONO_ADC_DIG_VOL:
case RT5659_STO2_ADC_DIG_VOL:
case RT5659_STO1_BOOST:
case RT5659_MONO_BOOST:
case RT5659_STO2_BOOST:
case RT5659_HP_IMP_GAIN_1:
case RT5659_HP_IMP_GAIN_2:
case RT5659_STO1_ADC_MIXER:
case RT5659_MONO_ADC_MIXER:
case RT5659_AD_DA_MIXER:
case RT5659_STO_DAC_MIXER:
case RT5659_MONO_DAC_MIXER:
case RT5659_DIG_MIXER:
case RT5659_A_DAC_MUX:
case RT5659_DIG_INF23_DATA:
case RT5659_PDM_OUT_CTRL:
case RT5659_PDM_DATA_CTRL_1:
case RT5659_PDM_DATA_CTRL_2:
case RT5659_PDM_DATA_CTRL_3:
case RT5659_PDM_DATA_CTRL_4:
case RT5659_SPDIF_CTRL:
case RT5659_REC1_GAIN:
case RT5659_REC1_L1_MIXER:
case RT5659_REC1_L2_MIXER:
case RT5659_REC1_R1_MIXER:
case RT5659_REC1_R2_MIXER:
case RT5659_CAL_REC:
case RT5659_REC2_L1_MIXER:
case RT5659_REC2_L2_MIXER:
case RT5659_REC2_R1_MIXER:
case RT5659_REC2_R2_MIXER:
case RT5659_SPK_L_MIXER:
case RT5659_SPK_R_MIXER:
case RT5659_SPO_AMP_GAIN:
case RT5659_ALC_BACK_GAIN:
case RT5659_MONOMIX_GAIN:
case RT5659_MONOMIX_IN_GAIN:
case RT5659_OUT_L_GAIN:
case RT5659_OUT_L_MIXER:
case RT5659_OUT_R_GAIN:
case RT5659_OUT_R_MIXER:
case RT5659_LOUT_MIXER:
case RT5659_HAPTIC_GEN_CTRL_1:
case RT5659_HAPTIC_GEN_CTRL_2:
case RT5659_HAPTIC_GEN_CTRL_3:
case RT5659_HAPTIC_GEN_CTRL_4:
case RT5659_HAPTIC_GEN_CTRL_5:
case RT5659_HAPTIC_GEN_CTRL_6:
case RT5659_HAPTIC_GEN_CTRL_7:
case RT5659_HAPTIC_GEN_CTRL_8:
case RT5659_HAPTIC_GEN_CTRL_9:
case RT5659_HAPTIC_GEN_CTRL_10:
case RT5659_HAPTIC_GEN_CTRL_11:
case RT5659_HAPTIC_LPF_CTRL_1:
case RT5659_HAPTIC_LPF_CTRL_2:
case RT5659_HAPTIC_LPF_CTRL_3:
case RT5659_PWR_DIG_1:
case RT5659_PWR_DIG_2:
case RT5659_PWR_ANLG_1:
case RT5659_PWR_ANLG_2:
case RT5659_PWR_ANLG_3:
case RT5659_PWR_MIXER:
case RT5659_PWR_VOL:
case RT5659_PRIV_INDEX:
case RT5659_CLK_DET:
case RT5659_PRIV_DATA:
case RT5659_PRE_DIV_1:
case RT5659_PRE_DIV_2:
case RT5659_I2S1_SDP:
case RT5659_I2S2_SDP:
case RT5659_I2S3_SDP:
case RT5659_ADDA_CLK_1:
case RT5659_ADDA_CLK_2:
case RT5659_DMIC_CTRL_1:
case RT5659_DMIC_CTRL_2:
case RT5659_TDM_CTRL_1:
case RT5659_TDM_CTRL_2:
case RT5659_TDM_CTRL_3:
case RT5659_TDM_CTRL_4:
case RT5659_TDM_CTRL_5:
case RT5659_GLB_CLK:
case RT5659_PLL_CTRL_1:
case RT5659_PLL_CTRL_2:
case RT5659_ASRC_1:
case RT5659_ASRC_2:
case RT5659_ASRC_3:
case RT5659_ASRC_4:
case RT5659_ASRC_5:
case RT5659_ASRC_6:
case RT5659_ASRC_7:
case RT5659_ASRC_8:
case RT5659_ASRC_9:
case RT5659_ASRC_10:
case RT5659_DEPOP_1:
case RT5659_DEPOP_2:
case RT5659_DEPOP_3:
case RT5659_HP_CHARGE_PUMP_1:
case RT5659_HP_CHARGE_PUMP_2:
case RT5659_MICBIAS_1:
case RT5659_MICBIAS_2:
case RT5659_ASRC_11:
case RT5659_ASRC_12:
case RT5659_ASRC_13:
case RT5659_REC_M1_M2_GAIN_CTRL:
case RT5659_RC_CLK_CTRL:
case RT5659_CLASSD_CTRL_1:
case RT5659_CLASSD_CTRL_2:
case RT5659_ADC_EQ_CTRL_1:
case RT5659_ADC_EQ_CTRL_2:
case RT5659_DAC_EQ_CTRL_1:
case RT5659_DAC_EQ_CTRL_2:
case RT5659_DAC_EQ_CTRL_3:
case RT5659_IRQ_CTRL_1:
case RT5659_IRQ_CTRL_2:
case RT5659_IRQ_CTRL_3:
case RT5659_IRQ_CTRL_4:
case RT5659_IRQ_CTRL_5:
case RT5659_IRQ_CTRL_6:
case RT5659_INT_ST_1:
case RT5659_INT_ST_2:
case RT5659_GPIO_CTRL_1:
case RT5659_GPIO_CTRL_2:
case RT5659_GPIO_CTRL_3:
case RT5659_GPIO_CTRL_4:
case RT5659_GPIO_CTRL_5:
case RT5659_GPIO_STA:
case RT5659_SINE_GEN_CTRL_1:
case RT5659_SINE_GEN_CTRL_2:
case RT5659_SINE_GEN_CTRL_3:
case RT5659_HP_AMP_DET_CTRL_1:
case RT5659_HP_AMP_DET_CTRL_2:
case RT5659_SV_ZCD_1:
case RT5659_SV_ZCD_2:
case RT5659_IL_CMD_1:
case RT5659_IL_CMD_2:
case RT5659_IL_CMD_3:
case RT5659_IL_CMD_4:
case RT5659_4BTN_IL_CMD_1:
case RT5659_4BTN_IL_CMD_2:
case RT5659_4BTN_IL_CMD_3:
case RT5659_PSV_IL_CMD_1:
case RT5659_PSV_IL_CMD_2:
case RT5659_ADC_STO1_HP_CTRL_1:
case RT5659_ADC_STO1_HP_CTRL_2:
case RT5659_ADC_MONO_HP_CTRL_1:
case RT5659_ADC_MONO_HP_CTRL_2:
case RT5659_AJD1_CTRL:
case RT5659_AJD2_AJD3_CTRL:
case RT5659_JD1_THD:
case RT5659_JD2_THD:
case RT5659_JD3_THD:
case RT5659_JD_CTRL_1:
case RT5659_JD_CTRL_2:
case RT5659_JD_CTRL_3:
case RT5659_JD_CTRL_4:
case RT5659_DIG_MISC:
case RT5659_DUMMY_2:
case RT5659_DUMMY_3:
case RT5659_VENDOR_ID:
case RT5659_VENDOR_ID_1:
case RT5659_DEVICE_ID:
case RT5659_DAC_ADC_DIG_VOL:
case RT5659_BIAS_CUR_CTRL_1:
case RT5659_BIAS_CUR_CTRL_2:
case RT5659_BIAS_CUR_CTRL_3:
case RT5659_BIAS_CUR_CTRL_4:
case RT5659_BIAS_CUR_CTRL_5:
case RT5659_BIAS_CUR_CTRL_6:
case RT5659_BIAS_CUR_CTRL_7:
case RT5659_BIAS_CUR_CTRL_8:
case RT5659_BIAS_CUR_CTRL_9:
case RT5659_BIAS_CUR_CTRL_10:
case RT5659_MEMORY_TEST:
case RT5659_VREF_REC_OP_FB_CAP_CTRL:
case RT5659_CLASSD_0:
case RT5659_CLASSD_1:
case RT5659_CLASSD_2:
case RT5659_CLASSD_3:
case RT5659_CLASSD_4:
case RT5659_CLASSD_5:
case RT5659_CLASSD_6:
case RT5659_CLASSD_7:
case RT5659_CLASSD_8:
case RT5659_CLASSD_9:
case RT5659_CLASSD_10:
case RT5659_CHARGE_PUMP_1:
case RT5659_CHARGE_PUMP_2:
case RT5659_DIG_IN_CTRL_1:
case RT5659_DIG_IN_CTRL_2:
case RT5659_PAD_DRIVING_CTRL:
case RT5659_SOFT_RAMP_DEPOP:
case RT5659_PLL:
case RT5659_CHOP_DAC:
case RT5659_CHOP_ADC:
case RT5659_CALIB_ADC_CTRL:
case RT5659_SOFT_RAMP_DEPOP_DAC_CLK_CTRL:
case RT5659_VOL_TEST:
case RT5659_TEST_MODE_CTRL_1:
case RT5659_TEST_MODE_CTRL_2:
case RT5659_TEST_MODE_CTRL_3:
case RT5659_TEST_MODE_CTRL_4:
case RT5659_BASSBACK_CTRL:
case RT5659_MP3_PLUS_CTRL_1:
case RT5659_MP3_PLUS_CTRL_2:
case RT5659_MP3_HPF_A1:
case RT5659_MP3_HPF_A2:
case RT5659_MP3_HPF_H0:
case RT5659_MP3_LPF_H0:
case RT5659_3D_SPK_CTRL:
case RT5659_3D_SPK_COEF_1:
case RT5659_3D_SPK_COEF_2:
case RT5659_3D_SPK_COEF_3:
case RT5659_3D_SPK_COEF_4:
case RT5659_3D_SPK_COEF_5:
case RT5659_3D_SPK_COEF_6:
case RT5659_3D_SPK_COEF_7:
case RT5659_STO_NG2_CTRL_1:
case RT5659_STO_NG2_CTRL_2:
case RT5659_STO_NG2_CTRL_3:
case RT5659_STO_NG2_CTRL_4:
case RT5659_STO_NG2_CTRL_5:
case RT5659_STO_NG2_CTRL_6:
case RT5659_STO_NG2_CTRL_7:
case RT5659_STO_NG2_CTRL_8:
case RT5659_MONO_NG2_CTRL_1:
case RT5659_MONO_NG2_CTRL_2:
case RT5659_MONO_NG2_CTRL_3:
case RT5659_MONO_NG2_CTRL_4:
case RT5659_MONO_NG2_CTRL_5:
case RT5659_MONO_NG2_CTRL_6:
case RT5659_MID_HP_AMP_DET:
case RT5659_LOW_HP_AMP_DET:
case RT5659_LDO_CTRL:
case RT5659_HP_DECROSS_CTRL_1:
case RT5659_HP_DECROSS_CTRL_2:
case RT5659_HP_DECROSS_CTRL_3:
case RT5659_HP_DECROSS_CTRL_4:
case RT5659_HP_IMP_SENS_CTRL_1:
case RT5659_HP_IMP_SENS_CTRL_2:
case RT5659_HP_IMP_SENS_CTRL_3:
case RT5659_HP_IMP_SENS_CTRL_4:
case RT5659_HP_IMP_SENS_MAP_1:
case RT5659_HP_IMP_SENS_MAP_2:
case RT5659_HP_IMP_SENS_MAP_3:
case RT5659_HP_IMP_SENS_MAP_4:
case RT5659_HP_IMP_SENS_MAP_5:
case RT5659_HP_IMP_SENS_MAP_6:
case RT5659_HP_IMP_SENS_MAP_7:
case RT5659_HP_IMP_SENS_MAP_8:
case RT5659_HP_LOGIC_CTRL_1:
case RT5659_HP_LOGIC_CTRL_2:
case RT5659_HP_CALIB_CTRL_1:
case RT5659_HP_CALIB_CTRL_2:
case RT5659_HP_CALIB_CTRL_3:
case RT5659_HP_CALIB_CTRL_4:
case RT5659_HP_CALIB_CTRL_5:
case RT5659_HP_CALIB_CTRL_6:
case RT5659_HP_CALIB_CTRL_7:
case RT5659_HP_CALIB_CTRL_9:
case RT5659_HP_CALIB_CTRL_10:
case RT5659_HP_CALIB_CTRL_11:
case RT5659_HP_CALIB_STA_1:
case RT5659_HP_CALIB_STA_2:
case RT5659_HP_CALIB_STA_3:
case RT5659_HP_CALIB_STA_4:
case RT5659_HP_CALIB_STA_5:
case RT5659_HP_CALIB_STA_6:
case RT5659_HP_CALIB_STA_7:
case RT5659_HP_CALIB_STA_8:
case RT5659_HP_CALIB_STA_9:
case RT5659_MONO_AMP_CALIB_CTRL_1:
case RT5659_MONO_AMP_CALIB_CTRL_2:
case RT5659_MONO_AMP_CALIB_CTRL_3:
case RT5659_MONO_AMP_CALIB_CTRL_4:
case RT5659_MONO_AMP_CALIB_CTRL_5:
case RT5659_MONO_AMP_CALIB_STA_1:
case RT5659_MONO_AMP_CALIB_STA_2:
case RT5659_MONO_AMP_CALIB_STA_3:
case RT5659_MONO_AMP_CALIB_STA_4:
case RT5659_SPK_PWR_LMT_CTRL_1:
case RT5659_SPK_PWR_LMT_CTRL_2:
case RT5659_SPK_PWR_LMT_CTRL_3:
case RT5659_SPK_PWR_LMT_STA_1:
case RT5659_SPK_PWR_LMT_STA_2:
case RT5659_SPK_PWR_LMT_STA_3:
case RT5659_SPK_PWR_LMT_STA_4:
case RT5659_SPK_PWR_LMT_STA_5:
case RT5659_SPK_PWR_LMT_STA_6:
case RT5659_FLEX_SPK_BST_CTRL_1:
case RT5659_FLEX_SPK_BST_CTRL_2:
case RT5659_FLEX_SPK_BST_CTRL_3:
case RT5659_FLEX_SPK_BST_CTRL_4:
case RT5659_SPK_EX_LMT_CTRL_1:
case RT5659_SPK_EX_LMT_CTRL_2:
case RT5659_SPK_EX_LMT_CTRL_3:
case RT5659_SPK_EX_LMT_CTRL_4:
case RT5659_SPK_EX_LMT_CTRL_5:
case RT5659_SPK_EX_LMT_CTRL_6:
case RT5659_SPK_EX_LMT_CTRL_7:
case RT5659_ADJ_HPF_CTRL_1:
case RT5659_ADJ_HPF_CTRL_2:
case RT5659_SPK_DC_CAILB_CTRL_1:
case RT5659_SPK_DC_CAILB_CTRL_2:
case RT5659_SPK_DC_CAILB_CTRL_3:
case RT5659_SPK_DC_CAILB_CTRL_4:
case RT5659_SPK_DC_CAILB_CTRL_5:
case RT5659_SPK_DC_CAILB_STA_1:
case RT5659_SPK_DC_CAILB_STA_2:
case RT5659_SPK_DC_CAILB_STA_3:
case RT5659_SPK_DC_CAILB_STA_4:
case RT5659_SPK_DC_CAILB_STA_5:
case RT5659_SPK_DC_CAILB_STA_6:
case RT5659_SPK_DC_CAILB_STA_7:
case RT5659_SPK_DC_CAILB_STA_8:
case RT5659_SPK_DC_CAILB_STA_9:
case RT5659_SPK_DC_CAILB_STA_10:
case RT5659_SPK_VDD_STA_1:
case RT5659_SPK_VDD_STA_2:
case RT5659_SPK_DC_DET_CTRL_1:
case RT5659_SPK_DC_DET_CTRL_2:
case RT5659_SPK_DC_DET_CTRL_3:
case RT5659_PURE_DC_DET_CTRL_1:
case RT5659_PURE_DC_DET_CTRL_2:
case RT5659_DUMMY_4:
case RT5659_DUMMY_5:
case RT5659_DUMMY_6:
case RT5659_DRC1_CTRL_1:
case RT5659_DRC1_CTRL_2:
case RT5659_DRC1_CTRL_3:
case RT5659_DRC1_CTRL_4:
case RT5659_DRC1_CTRL_5:
case RT5659_DRC1_CTRL_6:
case RT5659_DRC1_HARD_LMT_CTRL_1:
case RT5659_DRC1_HARD_LMT_CTRL_2:
case RT5659_DRC2_CTRL_1:
case RT5659_DRC2_CTRL_2:
case RT5659_DRC2_CTRL_3:
case RT5659_DRC2_CTRL_4:
case RT5659_DRC2_CTRL_5:
case RT5659_DRC2_CTRL_6:
case RT5659_DRC2_HARD_LMT_CTRL_1:
case RT5659_DRC2_HARD_LMT_CTRL_2:
case RT5659_DRC1_PRIV_1:
case RT5659_DRC1_PRIV_2:
case RT5659_DRC1_PRIV_3:
case RT5659_DRC1_PRIV_4:
case RT5659_DRC1_PRIV_5:
case RT5659_DRC1_PRIV_6:
case RT5659_DRC1_PRIV_7:
case RT5659_DRC2_PRIV_1:
case RT5659_DRC2_PRIV_2:
case RT5659_DRC2_PRIV_3:
case RT5659_DRC2_PRIV_4:
case RT5659_DRC2_PRIV_5:
case RT5659_DRC2_PRIV_6:
case RT5659_DRC2_PRIV_7:
case RT5659_MULTI_DRC_CTRL:
case RT5659_CROSS_OVER_1:
case RT5659_CROSS_OVER_2:
case RT5659_CROSS_OVER_3:
case RT5659_CROSS_OVER_4:
case RT5659_CROSS_OVER_5:
case RT5659_CROSS_OVER_6:
case RT5659_CROSS_OVER_7:
case RT5659_CROSS_OVER_8:
case RT5659_CROSS_OVER_9:
case RT5659_CROSS_OVER_10:
case RT5659_ALC_PGA_CTRL_1:
case RT5659_ALC_PGA_CTRL_2:
case RT5659_ALC_PGA_CTRL_3:
case RT5659_ALC_PGA_CTRL_4:
case RT5659_ALC_PGA_CTRL_5:
case RT5659_ALC_PGA_CTRL_6:
case RT5659_ALC_PGA_CTRL_7:
case RT5659_ALC_PGA_CTRL_8:
case RT5659_ALC_PGA_STA_1:
case RT5659_ALC_PGA_STA_2:
case RT5659_ALC_PGA_STA_3:
case RT5659_DAC_L_EQ_PRE_VOL:
case RT5659_DAC_R_EQ_PRE_VOL:
case RT5659_DAC_L_EQ_POST_VOL:
case RT5659_DAC_R_EQ_POST_VOL:
case RT5659_DAC_L_EQ_LPF1_A1:
case RT5659_DAC_L_EQ_LPF1_H0:
case RT5659_DAC_R_EQ_LPF1_A1:
case RT5659_DAC_R_EQ_LPF1_H0:
case RT5659_DAC_L_EQ_BPF2_A1:
case RT5659_DAC_L_EQ_BPF2_A2:
case RT5659_DAC_L_EQ_BPF2_H0:
case RT5659_DAC_R_EQ_BPF2_A1:
case RT5659_DAC_R_EQ_BPF2_A2:
case RT5659_DAC_R_EQ_BPF2_H0:
case RT5659_DAC_L_EQ_BPF3_A1:
case RT5659_DAC_L_EQ_BPF3_A2:
case RT5659_DAC_L_EQ_BPF3_H0:
case RT5659_DAC_R_EQ_BPF3_A1:
case RT5659_DAC_R_EQ_BPF3_A2:
case RT5659_DAC_R_EQ_BPF3_H0:
case RT5659_DAC_L_EQ_BPF4_A1:
case RT5659_DAC_L_EQ_BPF4_A2:
case RT5659_DAC_L_EQ_BPF4_H0:
case RT5659_DAC_R_EQ_BPF4_A1:
case RT5659_DAC_R_EQ_BPF4_A2:
case RT5659_DAC_R_EQ_BPF4_H0:
case RT5659_DAC_L_EQ_HPF1_A1:
case RT5659_DAC_L_EQ_HPF1_H0:
case RT5659_DAC_R_EQ_HPF1_A1:
case RT5659_DAC_R_EQ_HPF1_H0:
case RT5659_DAC_L_EQ_HPF2_A1:
case RT5659_DAC_L_EQ_HPF2_A2:
case RT5659_DAC_L_EQ_HPF2_H0:
case RT5659_DAC_R_EQ_HPF2_A1:
case RT5659_DAC_R_EQ_HPF2_A2:
case RT5659_DAC_R_EQ_HPF2_H0:
case RT5659_DAC_L_BI_EQ_BPF1_H0_1:
case RT5659_DAC_L_BI_EQ_BPF1_H0_2:
case RT5659_DAC_L_BI_EQ_BPF1_B1_1:
case RT5659_DAC_L_BI_EQ_BPF1_B1_2:
case RT5659_DAC_L_BI_EQ_BPF1_B2_1:
case RT5659_DAC_L_BI_EQ_BPF1_B2_2:
case RT5659_DAC_L_BI_EQ_BPF1_A1_1:
case RT5659_DAC_L_BI_EQ_BPF1_A1_2:
case RT5659_DAC_L_BI_EQ_BPF1_A2_1:
case RT5659_DAC_L_BI_EQ_BPF1_A2_2:
case RT5659_DAC_R_BI_EQ_BPF1_H0_1:
case RT5659_DAC_R_BI_EQ_BPF1_H0_2:
case RT5659_DAC_R_BI_EQ_BPF1_B1_1:
case RT5659_DAC_R_BI_EQ_BPF1_B1_2:
case RT5659_DAC_R_BI_EQ_BPF1_B2_1:
case RT5659_DAC_R_BI_EQ_BPF1_B2_2:
case RT5659_DAC_R_BI_EQ_BPF1_A1_1:
case RT5659_DAC_R_BI_EQ_BPF1_A1_2:
case RT5659_DAC_R_BI_EQ_BPF1_A2_1:
case RT5659_DAC_R_BI_EQ_BPF1_A2_2:
case RT5659_ADC_L_EQ_LPF1_A1:
case RT5659_ADC_R_EQ_LPF1_A1:
case RT5659_ADC_L_EQ_LPF1_H0:
case RT5659_ADC_R_EQ_LPF1_H0:
case RT5659_ADC_L_EQ_BPF1_A1:
case RT5659_ADC_R_EQ_BPF1_A1:
case RT5659_ADC_L_EQ_BPF1_A2:
case RT5659_ADC_R_EQ_BPF1_A2:
case RT5659_ADC_L_EQ_BPF1_H0:
case RT5659_ADC_R_EQ_BPF1_H0:
case RT5659_ADC_L_EQ_BPF2_A1:
case RT5659_ADC_R_EQ_BPF2_A1:
case RT5659_ADC_L_EQ_BPF2_A2:
case RT5659_ADC_R_EQ_BPF2_A2:
case RT5659_ADC_L_EQ_BPF2_H0:
case RT5659_ADC_R_EQ_BPF2_H0:
case RT5659_ADC_L_EQ_BPF3_A1:
case RT5659_ADC_R_EQ_BPF3_A1:
case RT5659_ADC_L_EQ_BPF3_A2:
case RT5659_ADC_R_EQ_BPF3_A2:
case RT5659_ADC_L_EQ_BPF3_H0:
case RT5659_ADC_R_EQ_BPF3_H0:
case RT5659_ADC_L_EQ_BPF4_A1:
case RT5659_ADC_R_EQ_BPF4_A1:
case RT5659_ADC_L_EQ_BPF4_A2:
case RT5659_ADC_R_EQ_BPF4_A2:
case RT5659_ADC_L_EQ_BPF4_H0:
case RT5659_ADC_R_EQ_BPF4_H0:
case RT5659_ADC_L_EQ_HPF1_A1:
case RT5659_ADC_R_EQ_HPF1_A1:
case RT5659_ADC_L_EQ_HPF1_H0:
case RT5659_ADC_R_EQ_HPF1_H0:
case RT5659_ADC_L_EQ_PRE_VOL:
case RT5659_ADC_R_EQ_PRE_VOL:
case RT5659_ADC_L_EQ_POST_VOL:
case RT5659_ADC_R_EQ_POST_VOL:
return true;
default:
return false;
}
}
static int rt5659_hp_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (snd_soc_read(codec, RT5659_STO_NG2_CTRL_1) & RT5659_NG2_EN) {
snd_soc_update_bits(codec, RT5659_STO_NG2_CTRL_1,
RT5659_NG2_EN_MASK, RT5659_NG2_DIS);
snd_soc_update_bits(codec, RT5659_STO_NG2_CTRL_1,
RT5659_NG2_EN_MASK, RT5659_NG2_EN);
}
return ret;
}
static void rt5659_enable_push_button_irq(struct snd_soc_codec *codec,
bool enable)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
if (enable) {
snd_soc_write(codec, RT5659_4BTN_IL_CMD_1, 0x000b);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
snd_soc_dapm_force_enable_pin(dapm,
"Mic Det Power");
snd_soc_dapm_sync(dapm);
snd_soc_update_bits(codec, RT5659_PWR_ANLG_2,
RT5659_PWR_MB1, RT5659_PWR_MB1);
snd_soc_update_bits(codec, RT5659_PWR_VOL,
RT5659_PWR_MIC_DET, RT5659_PWR_MIC_DET);
snd_soc_update_bits(codec, RT5659_IRQ_CTRL_2,
RT5659_IL_IRQ_MASK, RT5659_IL_IRQ_EN);
snd_soc_update_bits(codec, RT5659_4BTN_IL_CMD_2,
RT5659_4BTN_IL_MASK, RT5659_4BTN_IL_EN);
} else {
snd_soc_update_bits(codec, RT5659_4BTN_IL_CMD_2,
RT5659_4BTN_IL_MASK, RT5659_4BTN_IL_DIS);
snd_soc_update_bits(codec, RT5659_IRQ_CTRL_2,
RT5659_IL_IRQ_MASK, RT5659_IL_IRQ_DIS);
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
}
}
static int rt5659_headset_detect(struct snd_soc_codec *codec, int jack_insert)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
int val, i = 0, sleep_time[5] = {300, 150, 100, 50, 30};
int reg_63;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
if (jack_insert) {
snd_soc_dapm_force_enable_pin(dapm,
"Mic Det Power");
snd_soc_dapm_sync(dapm);
reg_63 = snd_soc_read(codec, RT5659_PWR_ANLG_1);
snd_soc_update_bits(codec, RT5659_PWR_ANLG_1,
RT5659_PWR_VREF2 | RT5659_PWR_MB,
RT5659_PWR_VREF2 | RT5659_PWR_MB);
msleep(20);
snd_soc_update_bits(codec, RT5659_PWR_ANLG_1,
RT5659_PWR_FV2, RT5659_PWR_FV2);
snd_soc_write(codec, RT5659_EJD_CTRL_2, 0x4160);
snd_soc_update_bits(codec, RT5659_EJD_CTRL_1,
0x20, 0x0);
msleep(20);
snd_soc_update_bits(codec, RT5659_EJD_CTRL_1,
0x20, 0x20);
while (i < 5) {
msleep(sleep_time[i]);
val = snd_soc_read(codec, RT5659_EJD_CTRL_2) & 0x0003;
i++;
if (val == 0x1 || val == 0x2 || val == 0x3)
break;
}
switch (val) {
case 1:
rt5659->jack_type = SND_JACK_HEADSET;
rt5659_enable_push_button_irq(codec, true);
break;
default:
snd_soc_write(codec, RT5659_PWR_ANLG_1, reg_63);
rt5659->jack_type = SND_JACK_HEADPHONE;
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
break;
}
} else {
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_sync(dapm);
if (rt5659->jack_type == SND_JACK_HEADSET)
rt5659_enable_push_button_irq(codec, false);
rt5659->jack_type = 0;
}
dev_dbg(codec->dev, "jack_type = %d\n", rt5659->jack_type);
return rt5659->jack_type;
}
static int rt5659_button_detect(struct snd_soc_codec *codec)
{
int btn_type, val;
val = snd_soc_read(codec, RT5659_4BTN_IL_CMD_1);
btn_type = val & 0xfff0;
snd_soc_write(codec, RT5659_4BTN_IL_CMD_1, val);
return btn_type;
}
static irqreturn_t rt5659_irq(int irq, void *data)
{
struct rt5659_priv *rt5659 = data;
queue_delayed_work(system_power_efficient_wq,
&rt5659->jack_detect_work, msecs_to_jiffies(250));
return IRQ_HANDLED;
}
int rt5659_set_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *hs_jack)
{
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
rt5659->hs_jack = hs_jack;
rt5659_irq(0, rt5659);
return 0;
}
static void rt5659_jack_detect_work(struct work_struct *work)
{
struct rt5659_priv *rt5659 =
container_of(work, struct rt5659_priv, jack_detect_work.work);
int val, btn_type, report = 0;
if (!rt5659->codec)
return;
val = snd_soc_read(rt5659->codec, RT5659_INT_ST_1) & 0x0080;
if (!val) {
if (rt5659->jack_type == 0) {
report = rt5659_headset_detect(rt5659->codec, 1);
} else {
report = SND_JACK_HEADSET;
btn_type = rt5659_button_detect(rt5659->codec);
switch (btn_type) {
case 0x8000:
case 0x4000:
case 0x2000:
report |= SND_JACK_BTN_0;
break;
case 0x1000:
case 0x0800:
case 0x0400:
report |= SND_JACK_BTN_1;
break;
case 0x0200:
case 0x0100:
case 0x0080:
report |= SND_JACK_BTN_2;
break;
case 0x0040:
case 0x0020:
case 0x0010:
report |= SND_JACK_BTN_3;
break;
case 0x0000:
break;
default:
btn_type = 0;
dev_err(rt5659->codec->dev,
"Unexpected button code 0x%04x\n",
btn_type);
break;
}
if (btn_type == 0)
report = rt5659->jack_type;
}
} else {
report = rt5659_headset_detect(rt5659->codec, 0);
}
snd_soc_jack_report(rt5659->hs_jack, report, SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3);
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
int pd, idx = -EINVAL;
pd = rl6231_get_pre_div(rt5659->regmap,
RT5659_ADDA_CLK_1, RT5659_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rt5659->sysclk / pd);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else {
snd_soc_update_bits(codec, RT5659_DMIC_CTRL_1,
RT5659_DMIC_CLK_MASK, idx << RT5659_DMIC_CLK_SFT);
}
return idx;
}
static int set_adc_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5659_CHOP_ADC,
RT5659_CKXEN_ADCC_MASK | RT5659_CKGEN_ADCC_MASK,
RT5659_CKXEN_ADCC_MASK | RT5659_CKGEN_ADCC_MASK);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5659_CHOP_ADC,
RT5659_CKXEN_ADCC_MASK | RT5659_CKGEN_ADCC_MASK, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5659_charge_pump_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_write(codec, RT5659_DEPOP_1, 0x0009);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, RT5659_HP_CHARGE_PUMP_1, 0x0c16);
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
val = snd_soc_read(codec, RT5659_GLB_CLK);
val &= RT5659_SCLK_SRC_MASK;
if (val == RT5659_SCLK_SRC_PLL1)
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
case RT5659_ADC_MONO_R_ASRC_SFT:
reg = RT5659_ASRC_3;
shift = RT5659_AD_MONO_R_T_SFT;
break;
case RT5659_ADC_MONO_L_ASRC_SFT:
reg = RT5659_ASRC_3;
shift = RT5659_AD_MONO_L_T_SFT;
break;
case RT5659_ADC_STO1_ASRC_SFT:
reg = RT5659_ASRC_2;
shift = RT5659_AD_STO1_T_SFT;
break;
case RT5659_DAC_MONO_R_ASRC_SFT:
reg = RT5659_ASRC_2;
shift = RT5659_DA_MONO_R_T_SFT;
break;
case RT5659_DAC_MONO_L_ASRC_SFT:
reg = RT5659_ASRC_2;
shift = RT5659_DA_MONO_L_T_SFT;
break;
case RT5659_DAC_STO_ASRC_SFT:
reg = RT5659_ASRC_2;
shift = RT5659_DA_STO_T_SFT;
break;
default:
return 0;
}
val = (snd_soc_read(codec, reg) >> shift) & 0xf;
switch (val) {
case 1:
case 2:
case 3:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_I2S_PD1_MASK, RT5659_I2S_PD1_2);
return 1;
default:
return 0;
}
}
static int rt5659_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5659_CLASSD_CTRL_1,
RT5659_POW_CLSD_DB_MASK, RT5659_POW_CLSD_DB_EN);
snd_soc_update_bits(codec, RT5659_CLASSD_2,
RT5659_M_RI_DIG, RT5659_M_RI_DIG);
snd_soc_write(codec, RT5659_CLASSD_1, 0x0803);
snd_soc_write(codec, RT5659_SPK_DC_CAILB_CTRL_3, 0x0000);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, RT5659_CLASSD_1, 0x0011);
snd_soc_update_bits(codec, RT5659_CLASSD_2,
RT5659_M_RI_DIG, 0x0);
snd_soc_write(codec, RT5659_SPK_DC_CAILB_CTRL_3, 0x0003);
snd_soc_update_bits(codec, RT5659_CLASSD_CTRL_1,
RT5659_POW_CLSD_DB_MASK, RT5659_POW_CLSD_DB_DIS);
break;
default:
return 0;
}
return 0;
}
static int rt5659_mono_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_write(codec, RT5659_MONO_AMP_CALIB_CTRL_1, 0x1e00);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, RT5659_MONO_AMP_CALIB_CTRL_1, 0x1e04);
break;
default:
return 0;
}
return 0;
}
static int rt5659_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec, RT5659_HP_CHARGE_PUMP_1, 0x0e1e);
snd_soc_update_bits(codec, RT5659_DEPOP_1, 0x0010, 0x0010);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec, RT5659_DEPOP_1, 0x0000);
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
msleep(450);
break;
default:
return 0;
}
return 0;
}
static int rt5659_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, frame_size;
rt5659->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5659->sysclk, rt5659->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5659->lrck[dai->id], dai->id);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
dev_dbg(dai->dev, "lrck is %dHz and pre_div is %d for iis %d\n",
rt5659->lrck[dai->id], pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5659_I2S_DL_20;
break;
case 24:
val_len |= RT5659_I2S_DL_24;
break;
case 8:
val_len |= RT5659_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5659_AIF1:
mask_clk = RT5659_I2S_PD1_MASK;
val_clk = pre_div << RT5659_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5659_I2S1_SDP,
RT5659_I2S_DL_MASK, val_len);
break;
case RT5659_AIF2:
mask_clk = RT5659_I2S_PD2_MASK;
val_clk = pre_div << RT5659_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5659_I2S2_SDP,
RT5659_I2S_DL_MASK, val_len);
break;
case RT5659_AIF3:
mask_clk = RT5659_I2S_PD3_MASK;
val_clk = pre_div << RT5659_I2S_PD3_SFT;
snd_soc_update_bits(codec, RT5659_I2S3_SDP,
RT5659_I2S_DL_MASK, val_len);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1, mask_clk, val_clk);
switch (rt5659->lrck[dai->id]) {
case 192000:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_DAC_OSR_MASK, RT5659_DAC_OSR_32);
break;
case 96000:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_DAC_OSR_MASK, RT5659_DAC_OSR_64);
break;
default:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_DAC_OSR_MASK, RT5659_DAC_OSR_128);
break;
}
return 0;
}
static int rt5659_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5659->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5659_I2S_MS_S;
rt5659->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5659_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5659_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5659_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5659_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5659_AIF1:
snd_soc_update_bits(codec, RT5659_I2S1_SDP,
RT5659_I2S_MS_MASK | RT5659_I2S_BP_MASK |
RT5659_I2S_DF_MASK, reg_val);
break;
case RT5659_AIF2:
snd_soc_update_bits(codec, RT5659_I2S2_SDP,
RT5659_I2S_MS_MASK | RT5659_I2S_BP_MASK |
RT5659_I2S_DF_MASK, reg_val);
break;
case RT5659_AIF3:
snd_soc_update_bits(codec, RT5659_I2S3_SDP,
RT5659_I2S_MS_MASK | RT5659_I2S_BP_MASK |
RT5659_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5659_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5659->sysclk && clk_id == rt5659->sysclk_src)
return 0;
switch (clk_id) {
case RT5659_SCLK_S_MCLK:
reg_val |= RT5659_SCLK_SRC_MCLK;
break;
case RT5659_SCLK_S_PLL1:
reg_val |= RT5659_SCLK_SRC_PLL1;
break;
case RT5659_SCLK_S_RCCLK:
reg_val |= RT5659_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_SCLK_SRC_MASK, reg_val);
rt5659->sysclk = freq;
rt5659->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5659_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int Source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (Source == rt5659->pll_src && freq_in == rt5659->pll_in &&
freq_out == rt5659->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5659->pll_in = 0;
rt5659->pll_out = 0;
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_SCLK_SRC_MASK, RT5659_SCLK_SRC_MCLK);
return 0;
}
switch (Source) {
case RT5659_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_PLL1_SRC_MASK, RT5659_PLL1_SRC_MCLK);
break;
case RT5659_PLL1_S_BCLK1:
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_PLL1_SRC_MASK, RT5659_PLL1_SRC_BCLK1);
break;
case RT5659_PLL1_S_BCLK2:
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_PLL1_SRC_MASK, RT5659_PLL1_SRC_BCLK2);
break;
case RT5659_PLL1_S_BCLK3:
snd_soc_update_bits(codec, RT5659_GLB_CLK,
RT5659_PLL1_SRC_MASK, RT5659_PLL1_SRC_BCLK3);
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
snd_soc_write(codec, RT5659_PLL_CTRL_1,
pll_code.n_code << RT5659_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5659_PLL_CTRL_2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5659_PLL_M_SFT |
pll_code.m_bp << RT5659_PLL_M_BP_SFT);
rt5659->pll_in = freq_in;
rt5659->pll_out = freq_out;
rt5659->pll_src = Source;
return 0;
}
static int rt5659_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
if (rx_mask || tx_mask)
val |= (1 << 15);
switch (slots) {
case 4:
val |= (1 << 10);
val |= (1 << 8);
break;
case 6:
val |= (2 << 10);
val |= (2 << 8);
break;
case 8:
val |= (3 << 10);
val |= (3 << 8);
break;
case 2:
break;
default:
return -EINVAL;
}
switch (slot_width) {
case 20:
val |= (1 << 6);
val |= (1 << 4);
break;
case 24:
val |= (2 << 6);
val |= (2 << 4);
break;
case 32:
val |= (3 << 6);
val |= (3 << 4);
break;
case 16:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5659_TDM_CTRL_1, 0x8ff0, val);
return 0;
}
static int rt5659_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "%s ratio=%d\n", __func__, ratio);
rt5659->bclk[dai->id] = ratio;
if (ratio == 64) {
switch (dai->id) {
case RT5659_AIF2:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_I2S_BCLK_MS2_MASK,
RT5659_I2S_BCLK_MS2_64);
break;
case RT5659_AIF3:
snd_soc_update_bits(codec, RT5659_ADDA_CLK_1,
RT5659_I2S_BCLK_MS3_MASK,
RT5659_I2S_BCLK_MS3_64);
break;
}
}
return 0;
}
static int rt5659_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(rt5659->regmap, RT5659_DIG_MISC,
RT5659_DIG_GATE_CTRL, RT5659_DIG_GATE_CTRL);
regmap_update_bits(rt5659->regmap, RT5659_PWR_DIG_1,
RT5659_PWR_LDO, RT5659_PWR_LDO);
regmap_update_bits(rt5659->regmap, RT5659_PWR_ANLG_1,
RT5659_PWR_MB | RT5659_PWR_VREF1 | RT5659_PWR_VREF2,
RT5659_PWR_MB | RT5659_PWR_VREF1 | RT5659_PWR_VREF2);
msleep(20);
regmap_update_bits(rt5659->regmap, RT5659_PWR_ANLG_1,
RT5659_PWR_FV1 | RT5659_PWR_FV2,
RT5659_PWR_FV1 | RT5659_PWR_FV2);
break;
case SND_SOC_BIAS_STANDBY:
if (dapm->bias_level == SND_SOC_BIAS_OFF) {
ret = clk_prepare_enable(rt5659->mclk);
if (ret) {
dev_err(codec->dev,
"failed to enable MCLK: %d\n", ret);
return ret;
}
}
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(rt5659->regmap, RT5659_PWR_DIG_1,
RT5659_PWR_LDO, 0);
regmap_update_bits(rt5659->regmap, RT5659_PWR_ANLG_1,
RT5659_PWR_MB | RT5659_PWR_VREF1 | RT5659_PWR_VREF2
| RT5659_PWR_FV1 | RT5659_PWR_FV2,
RT5659_PWR_MB | RT5659_PWR_VREF2);
regmap_update_bits(rt5659->regmap, RT5659_DIG_MISC,
RT5659_DIG_GATE_CTRL, 0);
clk_disable_unprepare(rt5659->mclk);
break;
default:
break;
}
return 0;
}
static int rt5659_probe(struct snd_soc_codec *codec)
{
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
rt5659->codec = codec;
return 0;
}
static int rt5659_remove(struct snd_soc_codec *codec)
{
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5659->regmap, RT5659_RESET, 0);
return 0;
}
static int rt5659_suspend(struct snd_soc_codec *codec)
{
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5659->regmap, true);
regcache_mark_dirty(rt5659->regmap);
return 0;
}
static int rt5659_resume(struct snd_soc_codec *codec)
{
struct rt5659_priv *rt5659 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5659->regmap, false);
regcache_sync(rt5659->regmap);
return 0;
}
static int rt5659_parse_dt(struct rt5659_priv *rt5659, struct device *dev)
{
rt5659->pdata.in1_diff = device_property_read_bool(dev,
"realtek,in1-differential");
rt5659->pdata.in3_diff = device_property_read_bool(dev,
"realtek,in3-differential");
rt5659->pdata.in4_diff = device_property_read_bool(dev,
"realtek,in4-differential");
device_property_read_u32(dev, "realtek,dmic1-data-pin",
&rt5659->pdata.dmic1_data_pin);
device_property_read_u32(dev, "realtek,dmic2-data-pin",
&rt5659->pdata.dmic2_data_pin);
device_property_read_u32(dev, "realtek,jd-src",
&rt5659->pdata.jd_src);
return 0;
}
static void rt5659_calibrate(struct rt5659_priv *rt5659)
{
int value, count;
regmap_write(rt5659->regmap, RT5659_BIAS_CUR_CTRL_8, 0xa502);
regmap_write(rt5659->regmap, RT5659_CHOP_DAC, 0x3030);
regmap_write(rt5659->regmap, RT5659_PRE_DIV_1, 0xef00);
regmap_write(rt5659->regmap, RT5659_PRE_DIV_2, 0xeffc);
regmap_write(rt5659->regmap, RT5659_MICBIAS_2, 0x0280);
regmap_write(rt5659->regmap, RT5659_DIG_MISC, 0x0001);
regmap_write(rt5659->regmap, RT5659_GLB_CLK, 0x8000);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_1, 0xaa7e);
msleep(60);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_1, 0xfe7e);
msleep(50);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_3, 0x0004);
regmap_write(rt5659->regmap, RT5659_PWR_DIG_2, 0x0400);
msleep(50);
regmap_write(rt5659->regmap, RT5659_PWR_DIG_1, 0x0080);
usleep_range(10000, 10005);
regmap_write(rt5659->regmap, RT5659_DEPOP_1, 0x0009);
msleep(50);
regmap_write(rt5659->regmap, RT5659_PWR_DIG_1, 0x0f80);
msleep(50);
regmap_write(rt5659->regmap, RT5659_HP_CHARGE_PUMP_1, 0x0e16);
msleep(50);
regmap_write(rt5659->regmap, RT5659_CAL_REC, 0x0505);
msleep(50);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_3, 0x0184);
regmap_write(rt5659->regmap, RT5659_CALIB_ADC_CTRL, 0x3c05);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x20c1);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x2cc1);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, 0x5100);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_7, 0x0014);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, 0xd100);
msleep(60);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x2cc1);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, 0x4900);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_7, 0x0016);
regmap_update_bits(rt5659->regmap, RT5659_HP_CALIB_CTRL_1,
0x8000, 0x8000);
count = 0;
while (true) {
regmap_read(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 30) {
dev_err(rt5659->codec->dev,
"HP Calibration 1 Failure\n");
return;
}
count++;
}
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x2cc1);
regmap_write(rt5659->regmap, RT5659_HP_VOL, 0x0000);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, 0x4500);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_7, 0x001f);
regmap_update_bits(rt5659->regmap, RT5659_HP_CALIB_CTRL_1,
0x8000, 0x8000);
count = 0;
while (true) {
regmap_read(rt5659->regmap, RT5659_HP_CALIB_CTRL_1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 85) {
dev_err(rt5659->codec->dev,
"HP Calibration 2 Failure\n");
return;
}
count++;
}
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_7, 0x0000);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x20c0);
regmap_write(rt5659->regmap, RT5659_CLASSD_0, 0x2021);
regmap_write(rt5659->regmap, RT5659_CLASSD_CTRL_1, 0x0260);
regmap_write(rt5659->regmap, RT5659_PWR_MIXER, 0x3000);
regmap_write(rt5659->regmap, RT5659_PWR_VOL, 0xc000);
regmap_write(rt5659->regmap, RT5659_A_DAC_MUX, 0x000c);
regmap_write(rt5659->regmap, RT5659_DIG_MISC, 0x8000);
regmap_write(rt5659->regmap, RT5659_SPO_VOL, 0x0808);
regmap_write(rt5659->regmap, RT5659_SPK_L_MIXER, 0x001e);
regmap_write(rt5659->regmap, RT5659_SPK_R_MIXER, 0x001e);
regmap_write(rt5659->regmap, RT5659_CLASSD_1, 0x0803);
regmap_write(rt5659->regmap, RT5659_CLASSD_2, 0x0554);
regmap_write(rt5659->regmap, RT5659_SPO_AMP_GAIN, 0x1103);
regmap_write(rt5659->regmap, RT5659_CAL_REC, 0x0909);
regmap_update_bits(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x0001,
0x0001);
regmap_write(rt5659->regmap, RT5659_SPK_DC_CAILB_CTRL_3, 0x0000);
regmap_write(rt5659->regmap, RT5659_CLASSD_0, 0x0021);
regmap_write(rt5659->regmap, RT5659_SPK_DC_CAILB_CTRL_1, 0x3e80);
regmap_update_bits(rt5659->regmap, RT5659_SPK_DC_CAILB_CTRL_1,
0x8000, 0x8000);
count = 0;
while (true) {
regmap_read(rt5659->regmap,
RT5659_SPK_DC_CAILB_CTRL_1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 10) {
dev_err(rt5659->codec->dev,
"SPK Calibration Failure\n");
return;
}
count++;
}
regmap_write(rt5659->regmap, RT5659_DIG_MISC, 0x0000);
regmap_write(rt5659->regmap, RT5659_MONOMIX_IN_GAIN, 0x021f);
regmap_write(rt5659->regmap, RT5659_MONO_OUT, 0x480a);
regmap_write(rt5659->regmap, RT5659_MONO_GAIN, 0x0003);
regmap_write(rt5659->regmap, RT5659_MONO_NG2_CTRL_5, 0x0009);
regmap_write(rt5659->regmap, RT5659_SPK_DC_CAILB_CTRL_3, 0x000f);
regmap_write(rt5659->regmap, RT5659_MONO_AMP_CALIB_CTRL_1, 0x1e00);
regmap_update_bits(rt5659->regmap, RT5659_MONO_AMP_CALIB_CTRL_1,
0x8000, 0x8000);
count = 0;
while (true) {
regmap_read(rt5659->regmap, RT5659_MONO_AMP_CALIB_CTRL_1,
&value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 35) {
dev_err(rt5659->codec->dev,
"Mono Calibration Failure\n");
return;
}
count++;
}
regmap_write(rt5659->regmap, RT5659_SPK_DC_CAILB_CTRL_3, 0x0003);
regmap_write(rt5659->regmap, RT5659_CAL_REC, 0x0808);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_3, 0x0000);
regmap_write(rt5659->regmap, RT5659_CALIB_ADC_CTRL, 0x2005);
regmap_write(rt5659->regmap, RT5659_HP_CALIB_CTRL_2, 0x20c0);
regmap_write(rt5659->regmap, RT5659_DEPOP_1, 0x0000);
regmap_write(rt5659->regmap, RT5659_CLASSD_1, 0x0011);
regmap_write(rt5659->regmap, RT5659_CLASSD_2, 0x0150);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_1, 0xfe3e);
regmap_write(rt5659->regmap, RT5659_MONO_OUT, 0xc80a);
regmap_write(rt5659->regmap, RT5659_MONO_AMP_CALIB_CTRL_1, 0x1e04);
regmap_write(rt5659->regmap, RT5659_PWR_MIXER, 0x0000);
regmap_write(rt5659->regmap, RT5659_PWR_VOL, 0x0000);
regmap_write(rt5659->regmap, RT5659_PWR_DIG_1, 0x0000);
regmap_write(rt5659->regmap, RT5659_PWR_DIG_2, 0x0000);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_1, 0x003e);
regmap_write(rt5659->regmap, RT5659_CLASSD_CTRL_1, 0x0060);
regmap_write(rt5659->regmap, RT5659_CLASSD_0, 0x2021);
regmap_write(rt5659->regmap, RT5659_GLB_CLK, 0x0000);
regmap_write(rt5659->regmap, RT5659_MICBIAS_2, 0x0080);
regmap_write(rt5659->regmap, RT5659_HP_VOL, 0x8080);
regmap_write(rt5659->regmap, RT5659_HP_CHARGE_PUMP_1, 0x0c16);
}
static int rt5659_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5659_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5659_priv *rt5659;
int ret;
unsigned int val;
rt5659 = devm_kzalloc(&i2c->dev, sizeof(struct rt5659_priv),
GFP_KERNEL);
if (rt5659 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5659);
if (pdata)
rt5659->pdata = *pdata;
else
rt5659_parse_dt(rt5659, &i2c->dev);
rt5659->gpiod_ldo1_en = devm_gpiod_get_optional(&i2c->dev, "ldo1-en",
GPIOD_OUT_HIGH);
if (IS_ERR(rt5659->gpiod_ldo1_en))
dev_warn(&i2c->dev, "Request ldo1-en GPIO failed\n");
rt5659->gpiod_reset = devm_gpiod_get_optional(&i2c->dev, "reset",
GPIOD_OUT_HIGH);
msleep(300);
rt5659->regmap = devm_regmap_init_i2c(i2c, &rt5659_regmap);
if (IS_ERR(rt5659->regmap)) {
ret = PTR_ERR(rt5659->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5659->regmap, RT5659_DEVICE_ID, &val);
if (val != DEVICE_ID) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt5659\n", val);
return -ENODEV;
}
regmap_write(rt5659->regmap, RT5659_RESET, 0);
rt5659->mclk = devm_clk_get(&i2c->dev, "mclk");
if (IS_ERR(rt5659->mclk)) {
if (PTR_ERR(rt5659->mclk) != -ENOENT)
return PTR_ERR(rt5659->mclk);
rt5659->mclk = NULL;
}
rt5659_calibrate(rt5659);
if (rt5659->pdata.in1_diff)
regmap_update_bits(rt5659->regmap, RT5659_IN1_IN2,
RT5659_IN1_DF_MASK, RT5659_IN1_DF_MASK);
if (rt5659->pdata.in3_diff)
regmap_update_bits(rt5659->regmap, RT5659_IN3_IN4,
RT5659_IN3_DF_MASK, RT5659_IN3_DF_MASK);
if (rt5659->pdata.in4_diff)
regmap_update_bits(rt5659->regmap, RT5659_IN3_IN4,
RT5659_IN4_DF_MASK, RT5659_IN4_DF_MASK);
if (rt5659->pdata.dmic1_data_pin != RT5659_DMIC1_NULL ||
rt5659->pdata.dmic2_data_pin != RT5659_DMIC2_NULL) {
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP2_PIN_MASK, RT5659_GP2_PIN_DMIC1_SCL);
switch (rt5659->pdata.dmic1_data_pin) {
case RT5659_DMIC1_DATA_IN2N:
regmap_update_bits(rt5659->regmap, RT5659_DMIC_CTRL_1,
RT5659_DMIC_1_DP_MASK, RT5659_DMIC_1_DP_IN2N);
break;
case RT5659_DMIC1_DATA_GPIO5:
regmap_update_bits(rt5659->regmap,
RT5659_GPIO_CTRL_3,
RT5659_I2S2_PIN_MASK,
RT5659_I2S2_PIN_GPIO);
regmap_update_bits(rt5659->regmap, RT5659_DMIC_CTRL_1,
RT5659_DMIC_1_DP_MASK, RT5659_DMIC_1_DP_GPIO5);
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP5_PIN_MASK, RT5659_GP5_PIN_DMIC1_SDA);
break;
case RT5659_DMIC1_DATA_GPIO9:
regmap_update_bits(rt5659->regmap, RT5659_DMIC_CTRL_1,
RT5659_DMIC_1_DP_MASK, RT5659_DMIC_1_DP_GPIO9);
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP9_PIN_MASK, RT5659_GP9_PIN_DMIC1_SDA);
break;
case RT5659_DMIC1_DATA_GPIO11:
regmap_update_bits(rt5659->regmap, RT5659_DMIC_CTRL_1,
RT5659_DMIC_1_DP_MASK, RT5659_DMIC_1_DP_GPIO11);
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP11_PIN_MASK,
RT5659_GP11_PIN_DMIC1_SDA);
break;
default:
dev_dbg(&i2c->dev, "no DMIC1\n");
break;
}
switch (rt5659->pdata.dmic2_data_pin) {
case RT5659_DMIC2_DATA_IN2P:
regmap_update_bits(rt5659->regmap,
RT5659_DMIC_CTRL_1,
RT5659_DMIC_2_DP_MASK,
RT5659_DMIC_2_DP_IN2P);
break;
case RT5659_DMIC2_DATA_GPIO6:
regmap_update_bits(rt5659->regmap,
RT5659_DMIC_CTRL_1,
RT5659_DMIC_2_DP_MASK,
RT5659_DMIC_2_DP_GPIO6);
regmap_update_bits(rt5659->regmap,
RT5659_GPIO_CTRL_1,
RT5659_GP6_PIN_MASK,
RT5659_GP6_PIN_DMIC2_SDA);
break;
case RT5659_DMIC2_DATA_GPIO10:
regmap_update_bits(rt5659->regmap,
RT5659_DMIC_CTRL_1,
RT5659_DMIC_2_DP_MASK,
RT5659_DMIC_2_DP_GPIO10);
regmap_update_bits(rt5659->regmap,
RT5659_GPIO_CTRL_1,
RT5659_GP10_PIN_MASK,
RT5659_GP10_PIN_DMIC2_SDA);
break;
case RT5659_DMIC2_DATA_GPIO12:
regmap_update_bits(rt5659->regmap,
RT5659_DMIC_CTRL_1,
RT5659_DMIC_2_DP_MASK,
RT5659_DMIC_2_DP_GPIO12);
regmap_update_bits(rt5659->regmap,
RT5659_GPIO_CTRL_1,
RT5659_GP12_PIN_MASK,
RT5659_GP12_PIN_DMIC2_SDA);
break;
default:
dev_dbg(&i2c->dev, "no DMIC2\n");
break;
}
} else {
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP2_PIN_MASK | RT5659_GP5_PIN_MASK |
RT5659_GP9_PIN_MASK | RT5659_GP11_PIN_MASK |
RT5659_GP6_PIN_MASK | RT5659_GP10_PIN_MASK |
RT5659_GP12_PIN_MASK,
RT5659_GP2_PIN_GPIO2 | RT5659_GP5_PIN_GPIO5 |
RT5659_GP9_PIN_GPIO9 | RT5659_GP11_PIN_GPIO11 |
RT5659_GP6_PIN_GPIO6 | RT5659_GP10_PIN_GPIO10 |
RT5659_GP12_PIN_GPIO12);
regmap_update_bits(rt5659->regmap, RT5659_DMIC_CTRL_1,
RT5659_DMIC_1_DP_MASK | RT5659_DMIC_2_DP_MASK,
RT5659_DMIC_1_DP_IN2N | RT5659_DMIC_2_DP_IN2P);
}
switch (rt5659->pdata.jd_src) {
case RT5659_JD3:
regmap_write(rt5659->regmap, RT5659_EJD_CTRL_1, 0xa880);
regmap_write(rt5659->regmap, RT5659_RC_CLK_CTRL, 0x9000);
regmap_write(rt5659->regmap, RT5659_GPIO_CTRL_1, 0xc800);
regmap_update_bits(rt5659->regmap, RT5659_PWR_ANLG_1,
RT5659_PWR_MB, RT5659_PWR_MB);
regmap_write(rt5659->regmap, RT5659_PWR_ANLG_2, 0x0001);
regmap_write(rt5659->regmap, RT5659_IRQ_CTRL_2, 0x0040);
break;
case RT5659_JD_NULL:
break;
default:
dev_warn(&i2c->dev, "Currently, support JD3 only\n");
break;
}
INIT_DELAYED_WORK(&rt5659->jack_detect_work, rt5659_jack_detect_work);
if (i2c->irq) {
ret = devm_request_threaded_irq(&i2c->dev, i2c->irq, NULL,
rt5659_irq, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING
| IRQF_ONESHOT, "rt5659", rt5659);
if (ret)
dev_err(&i2c->dev, "Failed to reguest IRQ: %d\n", ret);
regmap_update_bits(rt5659->regmap, RT5659_GPIO_CTRL_1,
RT5659_GP1_PIN_MASK, RT5659_GP1_PIN_IRQ);
}
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5659,
rt5659_dai, ARRAY_SIZE(rt5659_dai));
}
static int rt5659_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static void rt5659_i2c_shutdown(struct i2c_client *client)
{
struct rt5659_priv *rt5659 = i2c_get_clientdata(client);
regmap_write(rt5659->regmap, RT5659_RESET, 0);
}
