static bool rt5663_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5663_RESET:
case RT5663_SIL_DET_CTL:
case RT5663_HP_IMP_GAIN_2:
case RT5663_AD_DA_MIXER:
case RT5663_FRAC_DIV_2:
case RT5663_MICBIAS_1:
case RT5663_ASRC_11_2:
case RT5663_ADC_EQ_1:
case RT5663_INT_ST_1:
case RT5663_INT_ST_2:
case RT5663_GPIO_STA:
case RT5663_SIN_GEN_1:
case RT5663_IL_CMD_1:
case RT5663_IL_CMD_5:
case RT5663_IL_CMD_PWRSAV1:
case RT5663_EM_JACK_TYPE_1:
case RT5663_EM_JACK_TYPE_2:
case RT5663_EM_JACK_TYPE_3:
case RT5663_JD_CTRL2:
case RT5663_VENDOR_ID:
case RT5663_VENDOR_ID_1:
case RT5663_VENDOR_ID_2:
case RT5663_PLL_INT_REG:
case RT5663_SOFT_RAMP:
case RT5663_STO_DRE_1:
case RT5663_STO_DRE_5:
case RT5663_STO_DRE_6:
case RT5663_STO_DRE_7:
case RT5663_MIC_DECRO_1:
case RT5663_MIC_DECRO_4:
case RT5663_HP_IMP_SEN_1:
case RT5663_HP_IMP_SEN_3:
case RT5663_HP_IMP_SEN_4:
case RT5663_HP_IMP_SEN_5:
case RT5663_HP_CALIB_1_1:
case RT5663_HP_CALIB_9:
case RT5663_HP_CALIB_ST1:
case RT5663_HP_CALIB_ST2:
case RT5663_HP_CALIB_ST3:
case RT5663_HP_CALIB_ST4:
case RT5663_HP_CALIB_ST5:
case RT5663_HP_CALIB_ST6:
case RT5663_HP_CALIB_ST7:
case RT5663_HP_CALIB_ST8:
case RT5663_HP_CALIB_ST9:
case RT5663_ANA_JD:
return true;
default:
return false;
}
}
static bool rt5663_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5663_RESET:
case RT5663_HP_OUT_EN:
case RT5663_HP_LCH_DRE:
case RT5663_HP_RCH_DRE:
case RT5663_CALIB_BST:
case RT5663_RECMIX:
case RT5663_SIL_DET_CTL:
case RT5663_PWR_SAV_SILDET:
case RT5663_SIDETONE_CTL:
case RT5663_STO1_DAC_DIG_VOL:
case RT5663_STO1_ADC_DIG_VOL:
case RT5663_STO1_BOOST:
case RT5663_HP_IMP_GAIN_1:
case RT5663_HP_IMP_GAIN_2:
case RT5663_STO1_ADC_MIXER:
case RT5663_AD_DA_MIXER:
case RT5663_STO_DAC_MIXER:
case RT5663_DIG_SIDE_MIXER:
case RT5663_BYPASS_STO_DAC:
case RT5663_CALIB_REC_MIX:
case RT5663_PWR_DIG_1:
case RT5663_PWR_DIG_2:
case RT5663_PWR_ANLG_1:
case RT5663_PWR_ANLG_2:
case RT5663_PWR_ANLG_3:
case RT5663_PWR_MIXER:
case RT5663_SIG_CLK_DET:
case RT5663_PRE_DIV_GATING_1:
case RT5663_PRE_DIV_GATING_2:
case RT5663_I2S1_SDP:
case RT5663_ADDA_CLK_1:
case RT5663_ADDA_RST:
case RT5663_FRAC_DIV_1:
case RT5663_FRAC_DIV_2:
case RT5663_TDM_1:
case RT5663_TDM_2:
case RT5663_TDM_3:
case RT5663_TDM_4:
case RT5663_TDM_5:
case RT5663_GLB_CLK:
case RT5663_PLL_1:
case RT5663_PLL_2:
case RT5663_ASRC_1:
case RT5663_ASRC_2:
case RT5663_ASRC_4:
case RT5663_DUMMY_REG:
case RT5663_ASRC_8:
case RT5663_ASRC_9:
case RT5663_ASRC_11:
case RT5663_DEPOP_1:
case RT5663_DEPOP_2:
case RT5663_DEPOP_3:
case RT5663_HP_CHARGE_PUMP_1:
case RT5663_HP_CHARGE_PUMP_2:
case RT5663_MICBIAS_1:
case RT5663_RC_CLK:
case RT5663_ASRC_11_2:
case RT5663_DUMMY_REG_2:
case RT5663_REC_PATH_GAIN:
case RT5663_AUTO_1MRC_CLK:
case RT5663_ADC_EQ_1:
case RT5663_ADC_EQ_2:
case RT5663_IRQ_1:
case RT5663_IRQ_2:
case RT5663_IRQ_3:
case RT5663_IRQ_4:
case RT5663_IRQ_5:
case RT5663_INT_ST_1:
case RT5663_INT_ST_2:
case RT5663_GPIO_1:
case RT5663_GPIO_2:
case RT5663_GPIO_STA:
case RT5663_SIN_GEN_1:
case RT5663_SIN_GEN_2:
case RT5663_SIN_GEN_3:
case RT5663_SOF_VOL_ZC1:
case RT5663_IL_CMD_1:
case RT5663_IL_CMD_2:
case RT5663_IL_CMD_3:
case RT5663_IL_CMD_4:
case RT5663_IL_CMD_5:
case RT5663_IL_CMD_6:
case RT5663_IL_CMD_7:
case RT5663_IL_CMD_8:
case RT5663_IL_CMD_PWRSAV1:
case RT5663_IL_CMD_PWRSAV2:
case RT5663_EM_JACK_TYPE_1:
case RT5663_EM_JACK_TYPE_2:
case RT5663_EM_JACK_TYPE_3:
case RT5663_EM_JACK_TYPE_4:
case RT5663_EM_JACK_TYPE_5:
case RT5663_EM_JACK_TYPE_6:
case RT5663_STO1_HPF_ADJ1:
case RT5663_STO1_HPF_ADJ2:
case RT5663_FAST_OFF_MICBIAS:
case RT5663_JD_CTRL1:
case RT5663_JD_CTRL2:
case RT5663_DIG_MISC:
case RT5663_VENDOR_ID:
case RT5663_VENDOR_ID_1:
case RT5663_VENDOR_ID_2:
case RT5663_DIG_VOL_ZCD:
case RT5663_ANA_BIAS_CUR_1:
case RT5663_ANA_BIAS_CUR_2:
case RT5663_ANA_BIAS_CUR_3:
case RT5663_ANA_BIAS_CUR_4:
case RT5663_ANA_BIAS_CUR_5:
case RT5663_ANA_BIAS_CUR_6:
case RT5663_BIAS_CUR_5:
case RT5663_BIAS_CUR_6:
case RT5663_BIAS_CUR_7:
case RT5663_BIAS_CUR_8:
case RT5663_DACREF_LDO:
case RT5663_DUMMY_REG_3:
case RT5663_BIAS_CUR_9:
case RT5663_DUMMY_REG_4:
case RT5663_VREFADJ_OP:
case RT5663_VREF_RECMIX:
case RT5663_CHARGE_PUMP_1:
case RT5663_CHARGE_PUMP_1_2:
case RT5663_CHARGE_PUMP_1_3:
case RT5663_CHARGE_PUMP_2:
case RT5663_DIG_IN_PIN1:
case RT5663_PAD_DRV_CTL:
case RT5663_PLL_INT_REG:
case RT5663_CHOP_DAC_L:
case RT5663_CHOP_ADC:
case RT5663_CALIB_ADC:
case RT5663_CHOP_DAC_R:
case RT5663_DUMMY_CTL_DACLR:
case RT5663_DUMMY_REG_5:
case RT5663_SOFT_RAMP:
case RT5663_TEST_MODE_1:
case RT5663_TEST_MODE_2:
case RT5663_TEST_MODE_3:
case RT5663_STO_DRE_1:
case RT5663_STO_DRE_2:
case RT5663_STO_DRE_3:
case RT5663_STO_DRE_4:
case RT5663_STO_DRE_5:
case RT5663_STO_DRE_6:
case RT5663_STO_DRE_7:
case RT5663_STO_DRE_8:
case RT5663_STO_DRE_9:
case RT5663_STO_DRE_10:
case RT5663_MIC_DECRO_1:
case RT5663_MIC_DECRO_2:
case RT5663_MIC_DECRO_3:
case RT5663_MIC_DECRO_4:
case RT5663_MIC_DECRO_5:
case RT5663_MIC_DECRO_6:
case RT5663_HP_DECRO_1:
case RT5663_HP_DECRO_2:
case RT5663_HP_DECRO_3:
case RT5663_HP_DECRO_4:
case RT5663_HP_DECOUP:
case RT5663_HP_IMP_SEN_MAP8:
case RT5663_HP_IMP_SEN_MAP9:
case RT5663_HP_IMP_SEN_MAP10:
case RT5663_HP_IMP_SEN_MAP11:
case RT5663_HP_IMP_SEN_1:
case RT5663_HP_IMP_SEN_2:
case RT5663_HP_IMP_SEN_3:
case RT5663_HP_IMP_SEN_4:
case RT5663_HP_IMP_SEN_5:
case RT5663_HP_IMP_SEN_6:
case RT5663_HP_IMP_SEN_7:
case RT5663_HP_IMP_SEN_8:
case RT5663_HP_IMP_SEN_9:
case RT5663_HP_IMP_SEN_10:
case RT5663_HP_IMP_SEN_11:
case RT5663_HP_IMP_SEN_12:
case RT5663_HP_IMP_SEN_13:
case RT5663_HP_IMP_SEN_14:
case RT5663_HP_IMP_SEN_15:
case RT5663_HP_IMP_SEN_16:
case RT5663_HP_IMP_SEN_17:
case RT5663_HP_IMP_SEN_18:
case RT5663_HP_IMP_SEN_19:
case RT5663_HP_IMPSEN_DIG5:
case RT5663_HP_IMPSEN_MAP1:
case RT5663_HP_IMPSEN_MAP2:
case RT5663_HP_IMPSEN_MAP3:
case RT5663_HP_IMPSEN_MAP4:
case RT5663_HP_IMPSEN_MAP5:
case RT5663_HP_IMPSEN_MAP7:
case RT5663_HP_LOGIC_1:
case RT5663_HP_LOGIC_2:
case RT5663_HP_CALIB_1:
case RT5663_HP_CALIB_1_1:
case RT5663_HP_CALIB_2:
case RT5663_HP_CALIB_3:
case RT5663_HP_CALIB_4:
case RT5663_HP_CALIB_5:
case RT5663_HP_CALIB_5_1:
case RT5663_HP_CALIB_6:
case RT5663_HP_CALIB_7:
case RT5663_HP_CALIB_9:
case RT5663_HP_CALIB_10:
case RT5663_HP_CALIB_11:
case RT5663_HP_CALIB_ST1:
case RT5663_HP_CALIB_ST2:
case RT5663_HP_CALIB_ST3:
case RT5663_HP_CALIB_ST4:
case RT5663_HP_CALIB_ST5:
case RT5663_HP_CALIB_ST6:
case RT5663_HP_CALIB_ST7:
case RT5663_HP_CALIB_ST8:
case RT5663_HP_CALIB_ST9:
case RT5663_HP_AMP_DET:
case RT5663_DUMMY_REG_6:
case RT5663_HP_BIAS:
case RT5663_CBJ_1:
case RT5663_CBJ_2:
case RT5663_CBJ_3:
case RT5663_DUMMY_1:
case RT5663_DUMMY_2:
case RT5663_DUMMY_3:
case RT5663_ANA_JD:
case RT5663_ADC_LCH_LPF1_A1:
case RT5663_ADC_RCH_LPF1_A1:
case RT5663_ADC_LCH_LPF1_H0:
case RT5663_ADC_RCH_LPF1_H0:
case RT5663_ADC_LCH_BPF1_A1:
case RT5663_ADC_RCH_BPF1_A1:
case RT5663_ADC_LCH_BPF1_A2:
case RT5663_ADC_RCH_BPF1_A2:
case RT5663_ADC_LCH_BPF1_H0:
case RT5663_ADC_RCH_BPF1_H0:
case RT5663_ADC_LCH_BPF2_A1:
case RT5663_ADC_RCH_BPF2_A1:
case RT5663_ADC_LCH_BPF2_A2:
case RT5663_ADC_RCH_BPF2_A2:
case RT5663_ADC_LCH_BPF2_H0:
case RT5663_ADC_RCH_BPF2_H0:
case RT5663_ADC_LCH_BPF3_A1:
case RT5663_ADC_RCH_BPF3_A1:
case RT5663_ADC_LCH_BPF3_A2:
case RT5663_ADC_RCH_BPF3_A2:
case RT5663_ADC_LCH_BPF3_H0:
case RT5663_ADC_RCH_BPF3_H0:
case RT5663_ADC_LCH_BPF4_A1:
case RT5663_ADC_RCH_BPF4_A1:
case RT5663_ADC_LCH_BPF4_A2:
case RT5663_ADC_RCH_BPF4_A2:
case RT5663_ADC_LCH_BPF4_H0:
case RT5663_ADC_RCH_BPF4_H0:
case RT5663_ADC_LCH_HPF1_A1:
case RT5663_ADC_RCH_HPF1_A1:
case RT5663_ADC_LCH_HPF1_H0:
case RT5663_ADC_RCH_HPF1_H0:
case RT5663_ADC_EQ_PRE_VOL_L:
case RT5663_ADC_EQ_PRE_VOL_R:
case RT5663_ADC_EQ_POST_VOL_L:
case RT5663_ADC_EQ_POST_VOL_R:
return true;
default:
return false;
}
}
static bool rt5668_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5663_RESET:
case RT5668_CBJ_TYPE_2:
case RT5668_PDM_OUT_CTL:
case RT5668_PDM_I2C_DATA_CTL1:
case RT5668_PDM_I2C_DATA_CTL4:
case RT5668_ALC_BK_GAIN:
case RT5663_PLL_2:
case RT5663_MICBIAS_1:
case RT5663_ADC_EQ_1:
case RT5663_INT_ST_1:
case RT5668_GPIO_STA:
case RT5663_IL_CMD_1:
case RT5663_IL_CMD_5:
case RT5668_A_JD_CTRL:
case RT5663_JD_CTRL2:
case RT5663_VENDOR_ID:
case RT5663_VENDOR_ID_1:
case RT5663_VENDOR_ID_2:
case RT5663_STO_DRE_1:
case RT5663_STO_DRE_5:
case RT5663_STO_DRE_6:
case RT5663_STO_DRE_7:
case RT5668_MONO_DYNA_6:
case RT5668_STO1_SIL_DET:
case RT5668_MONOL_SIL_DET:
case RT5668_MONOR_SIL_DET:
case RT5668_STO2_DAC_SIL:
case RT5668_MONO_AMP_CAL_ST1:
case RT5668_MONO_AMP_CAL_ST2:
case RT5668_MONO_AMP_CAL_ST3:
case RT5668_MONO_AMP_CAL_ST4:
case RT5663_HP_IMP_SEN_2:
case RT5663_HP_IMP_SEN_3:
case RT5663_HP_IMP_SEN_4:
case RT5663_HP_IMP_SEN_10:
case RT5663_HP_CALIB_1:
case RT5663_HP_CALIB_10:
case RT5663_HP_CALIB_ST1:
case RT5663_HP_CALIB_ST4:
case RT5663_HP_CALIB_ST5:
case RT5663_HP_CALIB_ST6:
case RT5663_HP_CALIB_ST7:
case RT5663_HP_CALIB_ST8:
case RT5663_HP_CALIB_ST9:
case RT5668_HP_CALIB_ST10:
case RT5668_HP_CALIB_ST11:
return true;
default:
return false;
}
}
static bool rt5668_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case RT5668_LOUT_CTRL:
case RT5668_HP_AMP_2:
case RT5668_MONO_OUT:
case RT5668_MONO_GAIN:
case RT5668_AEC_BST:
case RT5668_IN1_IN2:
case RT5668_IN3_IN4:
case RT5668_INL1_INR1:
case RT5668_CBJ_TYPE_2:
case RT5668_CBJ_TYPE_3:
case RT5668_CBJ_TYPE_4:
case RT5668_CBJ_TYPE_5:
case RT5668_CBJ_TYPE_8:
case RT5668_DAC3_DIG_VOL:
case RT5668_DAC3_CTRL:
case RT5668_MONO_ADC_DIG_VOL:
case RT5668_STO2_ADC_DIG_VOL:
case RT5668_MONO_ADC_BST_GAIN:
case RT5668_STO2_ADC_BST_GAIN:
case RT5668_SIDETONE_CTRL:
case RT5668_MONO1_ADC_MIXER:
case RT5668_STO2_ADC_MIXER:
case RT5668_MONO_DAC_MIXER:
case RT5668_DAC2_SRC_CTRL:
case RT5668_IF_3_4_DATA_CTL:
case RT5668_IF_5_DATA_CTL:
case RT5668_PDM_OUT_CTL:
case RT5668_PDM_I2C_DATA_CTL1:
case RT5668_PDM_I2C_DATA_CTL2:
case RT5668_PDM_I2C_DATA_CTL3:
case RT5668_PDM_I2C_DATA_CTL4:
case RT5668_RECMIX1_NEW:
case RT5668_RECMIX1L_0:
case RT5668_RECMIX1L:
case RT5668_RECMIX1R_0:
case RT5668_RECMIX1R:
case RT5668_RECMIX2_NEW:
case RT5668_RECMIX2_L_2:
case RT5668_RECMIX2_R:
case RT5668_RECMIX2_R_2:
case RT5668_CALIB_REC_LR:
case RT5668_ALC_BK_GAIN:
case RT5668_MONOMIX_GAIN:
case RT5668_MONOMIX_IN_GAIN:
case RT5668_OUT_MIXL_GAIN:
case RT5668_OUT_LMIX_IN_GAIN:
case RT5668_OUT_RMIX_IN_GAIN:
case RT5668_OUT_RMIX_IN_GAIN1:
case RT5668_LOUT_MIXER_CTRL:
case RT5668_PWR_VOL:
case RT5668_ADCDAC_RST:
case RT5668_I2S34_SDP:
case RT5668_I2S5_SDP:
case RT5668_TDM_5:
case RT5668_TDM_6:
case RT5668_TDM_7:
case RT5668_TDM_8:
case RT5668_ASRC_3:
case RT5668_ASRC_6:
case RT5668_ASRC_7:
case RT5668_PLL_TRK_13:
case RT5668_I2S_M_CLK_CTL:
case RT5668_FDIV_I2S34_M_CLK:
case RT5668_FDIV_I2S34_M_CLK2:
case RT5668_FDIV_I2S5_M_CLK:
case RT5668_FDIV_I2S5_M_CLK2:
case RT5668_IRQ_4:
case RT5668_GPIO_3:
case RT5668_GPIO_4:
case RT5668_GPIO_STA:
case RT5668_HP_AMP_DET1:
case RT5668_HP_AMP_DET2:
case RT5668_HP_AMP_DET3:
case RT5668_MID_BD_HP_AMP:
case RT5668_LOW_BD_HP_AMP:
case RT5668_SOF_VOL_ZC2:
case RT5668_ADC_STO2_ADJ1:
case RT5668_ADC_STO2_ADJ2:
case RT5668_A_JD_CTRL:
case RT5668_JD1_TRES_CTRL:
case RT5668_JD2_TRES_CTRL:
case RT5668_JD_CTRL2:
case RT5668_DUM_REG_2:
case RT5668_DUM_REG_3:
case RT5663_VENDOR_ID:
case RT5663_VENDOR_ID_1:
case RT5663_VENDOR_ID_2:
case RT5668_DACADC_DIG_VOL2:
case RT5668_DIG_IN_PIN2:
case RT5668_PAD_DRV_CTL1:
case RT5668_SOF_RAM_DEPOP:
case RT5668_VOL_TEST:
case RT5668_TEST_MODE_3:
case RT5668_TEST_MODE_4:
case RT5663_STO_DRE_9:
case RT5668_MONO_DYNA_1:
case RT5668_MONO_DYNA_2:
case RT5668_MONO_DYNA_3:
case RT5668_MONO_DYNA_4:
case RT5668_MONO_DYNA_5:
case RT5668_MONO_DYNA_6:
case RT5668_STO1_SIL_DET:
case RT5668_MONOL_SIL_DET:
case RT5668_MONOR_SIL_DET:
case RT5668_STO2_DAC_SIL:
case RT5668_PWR_SAV_CTL1:
case RT5668_PWR_SAV_CTL2:
case RT5668_PWR_SAV_CTL3:
case RT5668_PWR_SAV_CTL4:
case RT5668_PWR_SAV_CTL5:
case RT5668_PWR_SAV_CTL6:
case RT5668_MONO_AMP_CAL1:
case RT5668_MONO_AMP_CAL2:
case RT5668_MONO_AMP_CAL3:
case RT5668_MONO_AMP_CAL4:
case RT5668_MONO_AMP_CAL5:
case RT5668_MONO_AMP_CAL6:
case RT5668_MONO_AMP_CAL7:
case RT5668_MONO_AMP_CAL_ST1:
case RT5668_MONO_AMP_CAL_ST2:
case RT5668_MONO_AMP_CAL_ST3:
case RT5668_MONO_AMP_CAL_ST4:
case RT5668_MONO_AMP_CAL_ST5:
case RT5668_HP_IMP_SEN_13:
case RT5668_HP_IMP_SEN_14:
case RT5668_HP_IMP_SEN_6:
case RT5668_HP_IMP_SEN_7:
case RT5668_HP_IMP_SEN_8:
case RT5668_HP_IMP_SEN_9:
case RT5668_HP_IMP_SEN_10:
case RT5668_HP_LOGIC_3:
case RT5668_HP_CALIB_ST10:
case RT5668_HP_CALIB_ST11:
case RT5668_PRO_REG_TBL_4:
case RT5668_PRO_REG_TBL_5:
case RT5668_PRO_REG_TBL_6:
case RT5668_PRO_REG_TBL_7:
case RT5668_PRO_REG_TBL_8:
case RT5668_PRO_REG_TBL_9:
case RT5668_SAR_ADC_INL_1:
case RT5668_SAR_ADC_INL_2:
case RT5668_SAR_ADC_INL_3:
case RT5668_SAR_ADC_INL_4:
case RT5668_SAR_ADC_INL_5:
case RT5668_SAR_ADC_INL_6:
case RT5668_SAR_ADC_INL_7:
case RT5668_SAR_ADC_INL_8:
case RT5668_SAR_ADC_INL_9:
case RT5668_SAR_ADC_INL_10:
case RT5668_SAR_ADC_INL_11:
case RT5668_SAR_ADC_INL_12:
case RT5668_DRC_CTRL_1:
case RT5668_DRC1_CTRL_2:
case RT5668_DRC1_CTRL_3:
case RT5668_DRC1_CTRL_4:
case RT5668_DRC1_CTRL_5:
case RT5668_DRC1_CTRL_6:
case RT5668_DRC1_HD_CTRL_1:
case RT5668_DRC1_HD_CTRL_2:
case RT5668_DRC1_PRI_REG_1:
case RT5668_DRC1_PRI_REG_2:
case RT5668_DRC1_PRI_REG_3:
case RT5668_DRC1_PRI_REG_4:
case RT5668_DRC1_PRI_REG_5:
case RT5668_DRC1_PRI_REG_6:
case RT5668_DRC1_PRI_REG_7:
case RT5668_DRC1_PRI_REG_8:
case RT5668_ALC_PGA_CTL_1:
case RT5668_ALC_PGA_CTL_2:
case RT5668_ALC_PGA_CTL_3:
case RT5668_ALC_PGA_CTL_4:
case RT5668_ALC_PGA_CTL_5:
case RT5668_ALC_PGA_CTL_6:
case RT5668_ALC_PGA_CTL_7:
case RT5668_ALC_PGA_CTL_8:
case RT5668_ALC_PGA_REG_1:
case RT5668_ALC_PGA_REG_2:
case RT5668_ALC_PGA_REG_3:
case RT5668_ADC_EQ_RECOV_1:
case RT5668_ADC_EQ_RECOV_2:
case RT5668_ADC_EQ_RECOV_3:
case RT5668_ADC_EQ_RECOV_4:
case RT5668_ADC_EQ_RECOV_5:
case RT5668_ADC_EQ_RECOV_6:
case RT5668_ADC_EQ_RECOV_7:
case RT5668_ADC_EQ_RECOV_8:
case RT5668_ADC_EQ_RECOV_9:
case RT5668_ADC_EQ_RECOV_10:
case RT5668_ADC_EQ_RECOV_11:
case RT5668_ADC_EQ_RECOV_12:
case RT5668_ADC_EQ_RECOV_13:
case RT5668_VID_HIDDEN:
case RT5668_VID_CUSTOMER:
case RT5668_SCAN_MODE:
case RT5668_I2C_BYPA:
return true;
case RT5663_TDM_1:
case RT5663_DEPOP_3:
case RT5663_ASRC_11_2:
case RT5663_INT_ST_2:
case RT5663_GPIO_STA:
case RT5663_SIN_GEN_1:
case RT5663_SIN_GEN_2:
case RT5663_SIN_GEN_3:
case RT5663_IL_CMD_PWRSAV1:
case RT5663_IL_CMD_PWRSAV2:
case RT5663_EM_JACK_TYPE_1:
case RT5663_EM_JACK_TYPE_2:
case RT5663_EM_JACK_TYPE_3:
case RT5663_EM_JACK_TYPE_4:
case RT5663_FAST_OFF_MICBIAS:
case RT5663_ANA_BIAS_CUR_1:
case RT5663_ANA_BIAS_CUR_2:
case RT5663_BIAS_CUR_9:
case RT5663_DUMMY_REG_4:
case RT5663_VREF_RECMIX:
case RT5663_CHARGE_PUMP_1_2:
case RT5663_CHARGE_PUMP_1_3:
case RT5663_CHARGE_PUMP_2:
case RT5663_CHOP_DAC_R:
case RT5663_DUMMY_CTL_DACLR:
case RT5663_DUMMY_REG_5:
case RT5663_SOFT_RAMP:
case RT5663_TEST_MODE_1:
case RT5663_STO_DRE_10:
case RT5663_MIC_DECRO_1:
case RT5663_MIC_DECRO_2:
case RT5663_MIC_DECRO_3:
case RT5663_MIC_DECRO_4:
case RT5663_MIC_DECRO_5:
case RT5663_MIC_DECRO_6:
case RT5663_HP_DECRO_1:
case RT5663_HP_DECRO_2:
case RT5663_HP_DECRO_3:
case RT5663_HP_DECRO_4:
case RT5663_HP_DECOUP:
case RT5663_HP_IMPSEN_MAP4:
case RT5663_HP_IMPSEN_MAP5:
case RT5663_HP_IMPSEN_MAP7:
case RT5663_HP_CALIB_1:
case RT5663_CBJ_1:
case RT5663_CBJ_2:
case RT5663_CBJ_3:
return false;
default:
return rt5663_readable_register(dev, reg);
}
}
static void rt5663_enable_push_button_irq(struct snd_soc_codec *codec,
bool enable)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
if (enable) {
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_EN_4BTN_INL_MASK, RT5668_EN_4BTN_INL_EN);
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_RESET_4BTN_INL_MASK,
RT5668_RESET_4BTN_INL_RESET);
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_RESET_4BTN_INL_MASK,
RT5668_RESET_4BTN_INL_NOR);
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
snd_soc_update_bits(codec, RT5663_IRQ_3,
RT5668_EN_IRQ_INLINE_MASK,
RT5668_EN_IRQ_INLINE_NOR);
break;
case CODEC_TYPE_RT5663:
snd_soc_update_bits(codec, RT5663_IRQ_2,
RT5663_EN_IRQ_INLINE_MASK,
RT5663_EN_IRQ_INLINE_NOR);
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
} else {
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
snd_soc_update_bits(codec, RT5663_IRQ_3,
RT5668_EN_IRQ_INLINE_MASK,
RT5668_EN_IRQ_INLINE_BYP);
break;
case CODEC_TYPE_RT5663:
snd_soc_update_bits(codec, RT5663_IRQ_2,
RT5663_EN_IRQ_INLINE_MASK,
RT5663_EN_IRQ_INLINE_BYP);
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_EN_4BTN_INL_MASK, RT5668_EN_4BTN_INL_DIS);
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_RESET_4BTN_INL_MASK,
RT5668_RESET_4BTN_INL_RESET);
snd_soc_update_bits(codec, RT5663_IL_CMD_6,
RT5668_RESET_4BTN_INL_MASK,
RT5668_RESET_4BTN_INL_NOR);
}
}
static int rt5668_jack_detect(struct snd_soc_codec *codec, int jack_insert)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5663_priv *rt5668 = snd_soc_codec_get_drvdata(codec);
int val, i = 0, sleep_time[5] = {300, 150, 100, 50, 30};
dev_dbg(codec->dev, "%s jack_insert:%d\n", __func__, jack_insert);
if (jack_insert) {
snd_soc_write(codec, RT5668_CBJ_TYPE_2, 0x8040);
snd_soc_write(codec, RT5668_CBJ_TYPE_3, 0x1484);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS2");
snd_soc_dapm_force_enable_pin(dapm, "Mic Det Power");
snd_soc_dapm_force_enable_pin(dapm, "CBJ Power");
snd_soc_dapm_sync(dapm);
snd_soc_update_bits(codec, RT5663_RC_CLK,
RT5668_DIG_1M_CLK_MASK, RT5668_DIG_1M_CLK_EN);
snd_soc_update_bits(codec, RT5663_RECMIX, 0x8, 0x8);
while (i < 5) {
msleep(sleep_time[i]);
val = snd_soc_read(codec, RT5668_CBJ_TYPE_2) & 0x0003;
if (val == 0x1 || val == 0x2 || val == 0x3)
break;
dev_dbg(codec->dev, "%s: MX-0011 val=%x sleep %d\n",
__func__, val, sleep_time[i]);
i++;
}
dev_dbg(codec->dev, "%s val = %d\n", __func__, val);
switch (val) {
case 1:
case 2:
rt5668->jack_type = SND_JACK_HEADSET;
rt5663_enable_push_button_irq(codec, true);
break;
default:
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
snd_soc_dapm_disable_pin(dapm, "MICBIAS2");
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_disable_pin(dapm, "CBJ Power");
snd_soc_dapm_sync(dapm);
rt5668->jack_type = SND_JACK_HEADPHONE;
break;
}
} else {
snd_soc_update_bits(codec, RT5663_RECMIX, 0x8, 0x0);
if (rt5668->jack_type == SND_JACK_HEADSET) {
rt5663_enable_push_button_irq(codec, false);
snd_soc_dapm_disable_pin(dapm, "MICBIAS1");
snd_soc_dapm_disable_pin(dapm, "MICBIAS2");
snd_soc_dapm_disable_pin(dapm, "Mic Det Power");
snd_soc_dapm_disable_pin(dapm, "CBJ Power");
snd_soc_dapm_sync(dapm);
}
rt5668->jack_type = 0;
}
dev_dbg(codec->dev, "jack_type = %d\n", rt5668->jack_type);
return rt5668->jack_type;
}
static int rt5663_jack_detect(struct snd_soc_codec *codec, int jack_insert)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
int val, i = 0, sleep_time[5] = {300, 150, 100, 50, 30};
dev_dbg(codec->dev, "%s jack_insert:%d\n", __func__, jack_insert);
if (jack_insert) {
snd_soc_update_bits(codec, RT5663_DIG_MISC,
RT5668_DIG_GATE_CTRL_MASK, RT5668_DIG_GATE_CTRL_EN);
snd_soc_update_bits(codec, RT5663_HP_CHARGE_PUMP_1,
RT5663_SI_HP_MASK | RT5668_OSW_HP_L_MASK |
RT5668_OSW_HP_R_MASK, RT5663_SI_HP_EN |
RT5668_OSW_HP_L_DIS | RT5668_OSW_HP_R_DIS);
snd_soc_update_bits(codec, RT5663_DUMMY_1,
RT5663_EMB_CLK_MASK | RT5663_HPA_CPL_BIAS_MASK |
RT5663_HPA_CPR_BIAS_MASK, RT5663_EMB_CLK_EN |
RT5663_HPA_CPL_BIAS_1 | RT5663_HPA_CPR_BIAS_1);
snd_soc_update_bits(codec, RT5663_CBJ_1,
RT5663_INBUF_CBJ_BST1_MASK | RT5663_CBJ_SENSE_BST1_MASK,
RT5663_INBUF_CBJ_BST1_ON | RT5663_CBJ_SENSE_BST1_L);
snd_soc_update_bits(codec, RT5663_IL_CMD_2,
RT5663_PWR_MIC_DET_MASK, RT5663_PWR_MIC_DET_ON);
snd_soc_update_bits(codec, RT5663_PWR_ANLG_2,
RT5668_PWR_BST1_MASK, RT5668_PWR_BST1_ON);
snd_soc_update_bits(codec, RT5663_EM_JACK_TYPE_1,
RT5663_CBJ_DET_MASK | RT5663_EXT_JD_MASK |
RT5663_POL_EXT_JD_MASK, RT5663_CBJ_DET_EN |
RT5663_EXT_JD_EN | RT5663_POL_EXT_JD_EN);
snd_soc_update_bits(codec, RT5663_PWR_ANLG_1,
RT5668_PWR_MB_MASK | RT5668_LDO1_DVO_MASK |
RT5668_AMP_HP_MASK, RT5668_PWR_MB |
RT5668_LDO1_DVO_0_9V | RT5668_AMP_HP_3X);
snd_soc_update_bits(codec, RT5663_AUTO_1MRC_CLK,
RT5668_IRQ_POW_SAV_MASK, RT5668_IRQ_POW_SAV_EN);
snd_soc_update_bits(codec, RT5663_IRQ_1,
RT5663_EN_IRQ_JD1_MASK, RT5663_EN_IRQ_JD1_EN);
while (i < 5) {
msleep(sleep_time[i]);
val = snd_soc_read(codec, RT5663_EM_JACK_TYPE_2) &
0x0003;
dev_dbg(codec->dev, "%s: MX-00e7 val=%x sleep %d\n",
__func__, val, sleep_time[i]);
i++;
if (val == 0x1 || val == 0x2 || val == 0x3)
break;
}
dev_dbg(codec->dev, "%s val = %d\n", __func__, val);
switch (val) {
case 1:
case 2:
rt5663->jack_type = SND_JACK_HEADSET;
rt5663_enable_push_button_irq(codec, true);
break;
default:
rt5663->jack_type = SND_JACK_HEADPHONE;
break;
}
} else {
if (rt5663->jack_type == SND_JACK_HEADSET)
rt5663_enable_push_button_irq(codec, false);
rt5663->jack_type = 0;
}
dev_dbg(codec->dev, "jack_type = %d\n", rt5663->jack_type);
return rt5663->jack_type;
}
static int rt5663_button_detect(struct snd_soc_codec *codec)
{
int btn_type, val;
val = snd_soc_read(codec, RT5663_IL_CMD_5);
dev_dbg(codec->dev, "%s: val=0x%x\n", __func__, val);
btn_type = val & 0xfff0;
snd_soc_write(codec, RT5663_IL_CMD_5, val);
return btn_type;
}
static irqreturn_t rt5663_irq(int irq, void *data)
{
struct rt5663_priv *rt5663 = data;
dev_dbg(rt5663->codec->dev, "%s IRQ queue work\n", __func__);
queue_delayed_work(system_wq, &rt5663->jack_detect_work,
msecs_to_jiffies(250));
return IRQ_HANDLED;
}
int rt5663_set_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *hs_jack)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
rt5663->hs_jack = hs_jack;
rt5663_irq(0, rt5663);
return 0;
}
static bool rt5663_check_jd_status(struct snd_soc_codec *codec)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
int val = snd_soc_read(codec, RT5663_INT_ST_1);
dev_dbg(codec->dev, "%s val=%x\n", __func__, val);
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
return !(val & 0x2000);
case CODEC_TYPE_RT5663:
return !(val & 0x1000);
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
return false;
}
static void rt5663_jack_detect_work(struct work_struct *work)
{
struct rt5663_priv *rt5663 =
container_of(work, struct rt5663_priv, jack_detect_work.work);
struct snd_soc_codec *codec = rt5663->codec;
int btn_type, report = 0;
if (!codec)
return;
if (rt5663_check_jd_status(codec)) {
if (rt5663->jack_type == 0) {
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
report = rt5668_jack_detect(rt5663->codec, 1);
break;
case CODEC_TYPE_RT5663:
report = rt5663_jack_detect(rt5663->codec, 1);
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
} else {
report = SND_JACK_HEADSET;
btn_type = rt5663_button_detect(rt5663->codec);
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
dev_err(rt5663->codec->dev,
"Unexpected button code 0x%04x\n",
btn_type);
break;
}
if (btn_type == 0)
report = rt5663->jack_type;
}
} else {
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
report = rt5668_jack_detect(rt5663->codec, 0);
break;
case CODEC_TYPE_RT5663:
report = rt5663_jack_detect(rt5663->codec, 0);
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
}
dev_dbg(codec->dev, "%s jack report: 0x%04x\n", __func__, report);
snd_soc_jack_report(rt5663->hs_jack, report, SND_JACK_HEADSET |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3);
}
static int rt5663_is_sys_clk_from_pll(struct snd_soc_dapm_widget *w,
struct snd_soc_dapm_widget *sink)
{
unsigned int val;
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
val = snd_soc_read(codec, RT5663_GLB_CLK);
val &= RT5663_SCLK_SRC_MASK;
if (val == RT5663_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int rt5663_is_using_asrc(struct snd_soc_dapm_widget *w,
struct snd_soc_dapm_widget *sink)
{
unsigned int reg, shift, val;
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
if (rt5663->codec_type == CODEC_TYPE_RT5668) {
switch (w->shift) {
case RT5668_ADC_STO1_ASRC_SHIFT:
reg = RT5668_ASRC_3;
shift = RT5668_AD_STO1_TRACK_SHIFT;
break;
case RT5668_DAC_STO1_ASRC_SHIFT:
reg = RT5663_ASRC_2;
shift = RT5668_DA_STO1_TRACK_SHIFT;
break;
default:
return 0;
}
} else {
switch (w->shift) {
case RT5663_ADC_STO1_ASRC_SHIFT:
reg = RT5663_ASRC_2;
shift = RT5663_AD_STO1_TRACK_SHIFT;
break;
case RT5663_DAC_STO1_ASRC_SHIFT:
reg = RT5663_ASRC_2;
shift = RT5663_DA_STO1_TRACK_SHIFT;
break;
default:
return 0;
}
}
val = (snd_soc_read(codec, reg) >> shift) & 0x7;
if (val)
return 1;
return 0;
}
static int rt5663_i2s_use_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
int da_asrc_en, ad_asrc_en;
da_asrc_en = (snd_soc_read(codec, RT5663_ASRC_2) &
RT5663_DA_STO1_TRACK_MASK) ? 1 : 0;
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
ad_asrc_en = (snd_soc_read(codec, RT5668_ASRC_3) &
RT5668_AD_STO1_TRACK_MASK) ? 1 : 0;
break;
case CODEC_TYPE_RT5663:
ad_asrc_en = (snd_soc_read(codec, RT5663_ASRC_2) &
RT5663_AD_STO1_TRACK_MASK) ? 1 : 0;
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
return 1;
}
if (da_asrc_en || ad_asrc_en)
if (rt5663->sysclk > rt5663->lrck * 384)
return 1;
dev_err(codec->dev, "sysclk < 384 x fs, disable i2s asrc\n");
return 0;
}
int rt5663_sel_asrc_clk_src(struct snd_soc_codec *codec,
unsigned int filter_mask, unsigned int clk_src)
{
struct rt5663_priv *rt5668 = snd_soc_codec_get_drvdata(codec);
unsigned int asrc2_mask = 0;
unsigned int asrc2_value = 0;
unsigned int asrc3_mask = 0;
unsigned int asrc3_value = 0;
switch (clk_src) {
case RT5663_CLK_SEL_SYS:
case RT5663_CLK_SEL_I2S1_ASRC:
break;
default:
return -EINVAL;
}
if (filter_mask & RT5663_DA_STEREO_FILTER) {
asrc2_mask |= RT5668_DA_STO1_TRACK_MASK;
asrc2_value |= clk_src << RT5668_DA_STO1_TRACK_SHIFT;
}
if (filter_mask & RT5663_AD_STEREO_FILTER) {
switch (rt5668->codec_type) {
case CODEC_TYPE_RT5668:
asrc3_mask |= RT5668_AD_STO1_TRACK_MASK;
asrc3_value |= clk_src << RT5668_AD_STO1_TRACK_SHIFT;
break;
case CODEC_TYPE_RT5663:
asrc2_mask |= RT5663_AD_STO1_TRACK_MASK;
asrc2_value |= clk_src << RT5663_AD_STO1_TRACK_SHIFT;
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
}
}
if (asrc2_mask)
snd_soc_update_bits(codec, RT5663_ASRC_2, asrc2_mask,
asrc2_value);
if (asrc3_mask)
snd_soc_update_bits(codec, RT5668_ASRC_3, asrc3_mask,
asrc3_value);
return 0;
}
static int rt5663_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (rt5663->codec_type == CODEC_TYPE_RT5668) {
snd_soc_update_bits(codec, RT5663_HP_CHARGE_PUMP_1,
RT5668_SEL_PM_HP_SHIFT, RT5668_SEL_PM_HP_HIGH);
snd_soc_update_bits(codec, RT5663_HP_LOGIC_2,
RT5668_HP_SIG_SRC1_MASK,
RT5668_HP_SIG_SRC1_SILENCE);
} else {
snd_soc_write(codec, RT5663_DEPOP_2, 0x3003);
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x000b,
0x000b);
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x0030,
0x0030);
snd_soc_update_bits(codec, RT5663_HP_CHARGE_PUMP_1,
RT5668_OVCD_HP_MASK, RT5668_OVCD_HP_DIS);
snd_soc_write(codec, RT5663_HP_CHARGE_PUMP_2, 0x1371);
snd_soc_write(codec, RT5663_HP_BIAS, 0xabba);
snd_soc_write(codec, RT5663_CHARGE_PUMP_1, 0x2224);
snd_soc_write(codec, RT5663_ANA_BIAS_CUR_1, 0x7766);
snd_soc_write(codec, RT5663_HP_BIAS, 0xafaa);
snd_soc_write(codec, RT5663_CHARGE_PUMP_2, 0x7777);
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x3000,
0x3000);
}
break;
case SND_SOC_DAPM_PRE_PMD:
if (rt5663->codec_type == CODEC_TYPE_RT5668) {
snd_soc_update_bits(codec, RT5663_HP_LOGIC_2,
RT5668_HP_SIG_SRC1_MASK,
RT5668_HP_SIG_SRC1_REG);
} else {
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x3000, 0x0);
snd_soc_update_bits(codec, RT5663_HP_CHARGE_PUMP_1,
RT5668_OVCD_HP_MASK, RT5668_OVCD_HP_EN);
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x0030, 0x0);
snd_soc_update_bits(codec, RT5663_DEPOP_1, 0x000b,
0x000b);
}
break;
default:
return 0;
}
return 0;
}
static int rt5668_bst2_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5663_PWR_ANLG_2,
RT5668_PWR_BST2_MASK | RT5668_PWR_BST2_OP_MASK,
RT5668_PWR_BST2 | RT5668_PWR_BST2_OP);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5663_PWR_ANLG_2,
RT5668_PWR_BST2_MASK | RT5668_PWR_BST2_OP_MASK, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5663_pre_div_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec, RT5663_PRE_DIV_GATING_1, 0xff00);
snd_soc_write(codec, RT5663_PRE_DIV_GATING_2, 0xfffc);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec, RT5663_PRE_DIV_GATING_1, 0x0000);
snd_soc_write(codec, RT5663_PRE_DIV_GATING_2, 0x0000);
break;
default:
return 0;
}
return 0;
}
static int rt5663_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0;
int pre_div;
rt5663->lrck = params_rate(params);
dev_dbg(dai->dev, "bclk is %dHz and sysclk is %dHz\n",
rt5663->lrck, rt5663->sysclk);
pre_div = rl6231_get_clk_info(rt5663->sysclk, rt5663->lrck);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5663->lrck, dai->id);
return -EINVAL;
}
dev_dbg(dai->dev, "pre_div is %d for iis %d\n", pre_div, dai->id);
switch (params_width(params)) {
case 8:
val_len = RT5668_I2S_DL_8;
break;
case 16:
val_len = RT5668_I2S_DL_16;
break;
case 20:
val_len = RT5668_I2S_DL_20;
break;
case 24:
val_len = RT5668_I2S_DL_24;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5663_I2S1_SDP,
RT5668_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5663_ADDA_CLK_1,
RT5668_I2S_PD1_MASK, pre_div << RT5668_I2S_PD1_SHIFT);
return 0;
}
static int rt5663_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5668_I2S_MS_S;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5668_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5668_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5668_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5668_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT5663_I2S1_SDP, RT5668_I2S_MS_MASK |
RT5668_I2S_BP_MASK | RT5668_I2S_DF_MASK, reg_val);
return 0;
}
static int rt5663_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5663->sysclk && clk_id == rt5663->sysclk_src)
return 0;
switch (clk_id) {
case RT5663_SCLK_S_MCLK:
reg_val |= RT5663_SCLK_SRC_MCLK;
break;
case RT5663_SCLK_S_PLL1:
reg_val |= RT5663_SCLK_SRC_PLL1;
break;
case RT5663_SCLK_S_RCCLK:
reg_val |= RT5663_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5663_GLB_CLK, RT5668_SCLK_SRC_MASK,
reg_val);
rt5663->sysclk = freq;
rt5663->sysclk_src = clk_id;
dev_dbg(codec->dev, "Sysclk is %dHz and clock id is %d\n",
freq, clk_id);
return 0;
}
static int rt5663_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
int mask, shift, val;
if (source == rt5663->pll_src && freq_in == rt5663->pll_in &&
freq_out == rt5663->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5663->pll_in = 0;
rt5663->pll_out = 0;
snd_soc_update_bits(codec, RT5663_GLB_CLK,
RT5663_SCLK_SRC_MASK, RT5663_SCLK_SRC_MCLK);
return 0;
}
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
mask = RT5668_PLL1_SRC_MASK;
shift = RT5668_PLL1_SRC_SHIFT;
break;
case CODEC_TYPE_RT5663:
mask = RT5663_PLL1_SRC_MASK;
shift = RT5663_PLL1_SRC_SHIFT;
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
return -EINVAL;
}
switch (source) {
case RT5663_PLL1_S_MCLK:
val = 0x0;
break;
case RT5663_PLL1_S_BCLK1:
val = 0x1;
break;
default:
dev_err(codec->dev, "Unknown PLL source %d\n", source);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5663_GLB_CLK, mask, (val << shift));
ret = rl6231_pll_calc(freq_in, freq_out, &pll_code);
if (ret < 0) {
dev_err(codec->dev, "Unsupport input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "bypass=%d m=%d n=%d k=%d\n", pll_code.m_bp,
(pll_code.m_bp ? 0 : pll_code.m_code), pll_code.n_code,
pll_code.k_code);
snd_soc_write(codec, RT5663_PLL_1,
pll_code.n_code << RT5668_PLL_N_SHIFT | pll_code.k_code);
snd_soc_write(codec, RT5663_PLL_2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5668_PLL_M_SHIFT |
pll_code.m_bp << RT5668_PLL_M_BP_SHIFT);
rt5663->pll_in = freq_in;
rt5663->pll_out = freq_out;
rt5663->pll_src = source;
return 0;
}
static int rt5663_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0, reg;
if (rx_mask || tx_mask)
val |= RT5668_TDM_MODE_TDM;
switch (slots) {
case 4:
val |= RT5668_TDM_IN_CH_4;
val |= RT5668_TDM_OUT_CH_4;
break;
case 6:
val |= RT5668_TDM_IN_CH_6;
val |= RT5668_TDM_OUT_CH_6;
break;
case 8:
val |= RT5668_TDM_IN_CH_8;
val |= RT5668_TDM_OUT_CH_8;
break;
case 2:
break;
default:
return -EINVAL;
}
switch (slot_width) {
case 20:
val |= RT5668_TDM_IN_LEN_20;
val |= RT5668_TDM_OUT_LEN_20;
break;
case 24:
val |= RT5668_TDM_IN_LEN_24;
val |= RT5668_TDM_OUT_LEN_24;
break;
case 32:
val |= RT5668_TDM_IN_LEN_32;
val |= RT5668_TDM_OUT_LEN_32;
break;
case 16:
break;
default:
return -EINVAL;
}
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
reg = RT5663_TDM_2;
break;
case CODEC_TYPE_RT5663:
reg = RT5663_TDM_1;
break;
default:
dev_err(codec->dev, "Unknown CODEC_TYPE\n");
return -EINVAL;
}
snd_soc_update_bits(codec, reg, RT5668_TDM_MODE_MASK |
RT5668_TDM_IN_CH_MASK | RT5668_TDM_OUT_CH_MASK |
RT5668_TDM_IN_LEN_MASK | RT5668_TDM_OUT_LEN_MASK, val);
return 0;
}
static int rt5663_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
unsigned int reg;
dev_dbg(codec->dev, "%s ratio = %d\n", __func__, ratio);
if (rt5663->codec_type == CODEC_TYPE_RT5668)
reg = RT5668_TDM_8;
else
reg = RT5663_TDM_5;
switch (ratio) {
case 32:
snd_soc_update_bits(codec, reg,
RT5663_TDM_LENGTN_MASK,
RT5663_TDM_LENGTN_16);
break;
case 40:
snd_soc_update_bits(codec, reg,
RT5663_TDM_LENGTN_MASK,
RT5663_TDM_LENGTN_20);
break;
case 48:
snd_soc_update_bits(codec, reg,
RT5663_TDM_LENGTN_MASK,
RT5663_TDM_LENGTN_24);
break;
case 64:
snd_soc_update_bits(codec, reg,
RT5663_TDM_LENGTN_MASK,
RT5663_TDM_LENGTN_32);
break;
default:
dev_err(codec->dev, "Invalid ratio!\n");
return -EINVAL;
}
return 0;
}
static int rt5663_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, RT5663_PWR_ANLG_1,
RT5668_PWR_FV1_MASK | RT5668_PWR_FV2_MASK,
RT5668_PWR_FV1 | RT5668_PWR_FV2);
break;
case SND_SOC_BIAS_PREPARE:
if (rt5663->codec_type == CODEC_TYPE_RT5668) {
snd_soc_update_bits(codec, RT5663_DIG_MISC,
RT5668_DIG_GATE_CTRL_MASK,
RT5668_DIG_GATE_CTRL_EN);
snd_soc_update_bits(codec, RT5663_SIG_CLK_DET,
RT5668_EN_ANA_CLK_DET_MASK |
RT5668_PWR_CLK_DET_MASK,
RT5668_EN_ANA_CLK_DET_AUTO |
RT5668_PWR_CLK_DET_EN);
}
break;
case SND_SOC_BIAS_STANDBY:
if (rt5663->codec_type == CODEC_TYPE_RT5668)
snd_soc_update_bits(codec, RT5663_DIG_MISC,
RT5668_DIG_GATE_CTRL_MASK,
RT5668_DIG_GATE_CTRL_DIS);
snd_soc_update_bits(codec, RT5663_PWR_ANLG_1,
RT5668_PWR_VREF1_MASK | RT5668_PWR_VREF2_MASK |
RT5668_PWR_FV1_MASK | RT5668_PWR_FV2_MASK |
RT5668_PWR_MB_MASK, RT5668_PWR_VREF1 |
RT5668_PWR_VREF2 | RT5668_PWR_MB);
usleep_range(10000, 10005);
if (rt5663->codec_type == CODEC_TYPE_RT5668) {
snd_soc_update_bits(codec, RT5663_SIG_CLK_DET,
RT5668_EN_ANA_CLK_DET_MASK |
RT5668_PWR_CLK_DET_MASK,
RT5668_EN_ANA_CLK_DET_DIS |
RT5668_PWR_CLK_DET_DIS);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, RT5663_PWR_ANLG_1,
RT5668_PWR_VREF1_MASK | RT5668_PWR_VREF2_MASK |
RT5668_PWR_FV1 | RT5668_PWR_FV2, 0x0);
break;
default:
break;
}
return 0;
}
static int rt5663_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
rt5663->codec = codec;
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
snd_soc_dapm_new_controls(dapm,
rt5668_specific_dapm_widgets,
ARRAY_SIZE(rt5668_specific_dapm_widgets));
snd_soc_dapm_add_routes(dapm,
rt5668_specific_dapm_routes,
ARRAY_SIZE(rt5668_specific_dapm_routes));
snd_soc_add_codec_controls(codec, rt5668_specific_controls,
ARRAY_SIZE(rt5668_specific_controls));
break;
case CODEC_TYPE_RT5663:
snd_soc_dapm_new_controls(dapm,
rt5663_specific_dapm_widgets,
ARRAY_SIZE(rt5663_specific_dapm_widgets));
snd_soc_dapm_add_routes(dapm,
rt5663_specific_dapm_routes,
ARRAY_SIZE(rt5663_specific_dapm_routes));
snd_soc_add_codec_controls(codec, rt5663_specific_controls,
ARRAY_SIZE(rt5663_specific_controls));
break;
}
return 0;
}
static int rt5663_remove(struct snd_soc_codec *codec)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
regmap_write(rt5663->regmap, RT5663_RESET, 0);
return 0;
}
static int rt5663_suspend(struct snd_soc_codec *codec)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5663->regmap, true);
regcache_mark_dirty(rt5663->regmap);
return 0;
}
static int rt5663_resume(struct snd_soc_codec *codec)
{
struct rt5663_priv *rt5663 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5663->regmap, false);
regcache_sync(rt5663->regmap);
return 0;
}
static void rt5668_calibrate(struct rt5663_priv *rt5668)
{
regmap_write(rt5668->regmap, RT5663_BIAS_CUR_8, 0xa402);
regmap_write(rt5668->regmap, RT5663_PWR_DIG_1, 0x0100);
regmap_write(rt5668->regmap, RT5663_RECMIX, 0x4040);
regmap_write(rt5668->regmap, RT5663_DIG_MISC, 0x0001);
regmap_write(rt5668->regmap, RT5663_RC_CLK, 0x0380);
regmap_write(rt5668->regmap, RT5663_GLB_CLK, 0x8000);
regmap_write(rt5668->regmap, RT5663_ADDA_CLK_1, 0x1000);
regmap_write(rt5668->regmap, RT5663_CHOP_DAC_L, 0x3030);
regmap_write(rt5668->regmap, RT5663_CALIB_ADC, 0x3c05);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_1, 0xa23e);
msleep(40);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_1, 0xf23e);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_2, 0x0321);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_1, 0xfc00);
msleep(500);
}
static void rt5663_calibrate(struct rt5663_priv *rt5668)
{
int value, count;
regmap_write(rt5668->regmap, RT5663_RC_CLK, 0x0280);
regmap_write(rt5668->regmap, RT5663_GLB_CLK, 0x8000);
regmap_write(rt5668->regmap, RT5663_DIG_MISC, 0x8001);
regmap_write(rt5668->regmap, RT5663_VREF_RECMIX, 0x0032);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_1, 0xa2be);
msleep(20);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_1, 0xf2be);
regmap_write(rt5668->regmap, RT5663_PWR_DIG_2, 0x8400);
regmap_write(rt5668->regmap, RT5663_CHOP_ADC, 0x3000);
regmap_write(rt5668->regmap, RT5663_DEPOP_1, 0x003b);
regmap_write(rt5668->regmap, RT5663_PWR_DIG_1, 0x8df8);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_2, 0x0003);
regmap_write(rt5668->regmap, RT5663_PWR_ANLG_3, 0x018c);
regmap_write(rt5668->regmap, RT5663_ADDA_CLK_1, 0x1111);
regmap_write(rt5668->regmap, RT5663_PRE_DIV_GATING_1, 0xffff);
regmap_write(rt5668->regmap, RT5663_PRE_DIV_GATING_2, 0xffff);
regmap_write(rt5668->regmap, RT5663_DEPOP_2, 0x3003);
regmap_write(rt5668->regmap, RT5663_DEPOP_1, 0x003b);
regmap_write(rt5668->regmap, RT5663_HP_CHARGE_PUMP_1, 0x1e32);
regmap_write(rt5668->regmap, RT5663_HP_CHARGE_PUMP_2, 0x1371);
regmap_write(rt5668->regmap, RT5663_DACREF_LDO, 0x3b0b);
regmap_write(rt5668->regmap, RT5663_STO_DAC_MIXER, 0x2080);
regmap_write(rt5668->regmap, RT5663_BYPASS_STO_DAC, 0x000c);
regmap_write(rt5668->regmap, RT5663_HP_BIAS, 0xabba);
regmap_write(rt5668->regmap, RT5663_CHARGE_PUMP_1, 0x2224);
regmap_write(rt5668->regmap, RT5663_HP_OUT_EN, 0x8088);
regmap_write(rt5668->regmap, RT5663_STO_DRE_9, 0x0017);
regmap_write(rt5668->regmap, RT5663_STO_DRE_10, 0x0017);
regmap_write(rt5668->regmap, RT5663_STO1_ADC_MIXER, 0x4040);
regmap_write(rt5668->regmap, RT5663_RECMIX, 0x0005);
regmap_write(rt5668->regmap, RT5663_ADDA_RST, 0xc000);
regmap_write(rt5668->regmap, RT5663_STO1_HPF_ADJ1, 0x3320);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_2, 0x00c9);
regmap_write(rt5668->regmap, RT5663_DUMMY_1, 0x004c);
regmap_write(rt5668->regmap, RT5663_ANA_BIAS_CUR_1, 0x7766);
regmap_write(rt5668->regmap, RT5663_BIAS_CUR_8, 0x4702);
msleep(200);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_1, 0x0069);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_3, 0x06c2);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_1_1, 0x7b00);
regmap_write(rt5668->regmap, RT5663_HP_CALIB_1_1, 0xfb00);
count = 0;
while (true) {
regmap_read(rt5668->regmap, RT5663_HP_CALIB_1_1, &value);
if (value & 0x8000)
usleep_range(10000, 10005);
else
break;
if (count > 200)
return;
count++;
}
}
static int rt5663_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5663_priv *rt5663;
int ret;
unsigned int val;
struct regmap *regmap;
rt5663 = devm_kzalloc(&i2c->dev, sizeof(struct rt5663_priv),
GFP_KERNEL);
if (rt5663 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5663);
regmap = devm_regmap_init_i2c(i2c, &temp_regmap);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&i2c->dev, "Failed to allocate temp register map: %d\n",
ret);
return ret;
}
regmap_read(regmap, RT5663_VENDOR_ID_2, &val);
switch (val) {
case RT5668_DEVICE_ID:
rt5663->regmap = devm_regmap_init_i2c(i2c, &rt5668_regmap);
rt5663->codec_type = CODEC_TYPE_RT5668;
break;
case RT5663_DEVICE_ID:
rt5663->regmap = devm_regmap_init_i2c(i2c, &rt5663_regmap);
rt5663->codec_type = CODEC_TYPE_RT5663;
break;
default:
dev_err(&i2c->dev,
"Device with ID register %#x is not rt5663 or rt5668\n",
val);
return -ENODEV;
}
if (IS_ERR(rt5663->regmap)) {
ret = PTR_ERR(rt5663->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_write(rt5663->regmap, RT5663_RESET, 0);
regcache_cache_bypass(rt5663->regmap, true);
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
rt5668_calibrate(rt5663);
break;
case CODEC_TYPE_RT5663:
rt5663_calibrate(rt5663);
break;
default:
dev_err(&i2c->dev, "%s:Unknown codec type\n", __func__);
}
regcache_cache_bypass(rt5663->regmap, false);
regmap_write(rt5663->regmap, RT5663_RESET, 0);
dev_dbg(&i2c->dev, "calibrate done\n");
regmap_update_bits(rt5663->regmap, RT5663_GPIO_1, RT5668_GP1_PIN_MASK,
RT5668_GP1_PIN_IRQ);
regmap_update_bits(rt5663->regmap, RT5663_IL_CMD_5,
RT5668_4BTN_CLK_DEB_MASK, RT5668_4BTN_CLK_DEB_65MS);
switch (rt5663->codec_type) {
case CODEC_TYPE_RT5668:
regmap_write(rt5663->regmap, RT5663_BIAS_CUR_8, 0xa402);
regmap_update_bits(rt5663->regmap, RT5663_AUTO_1MRC_CLK,
RT5668_IRQ_POW_SAV_MASK | RT5668_IRQ_POW_SAV_JD1_MASK,
RT5668_IRQ_POW_SAV_EN | RT5668_IRQ_POW_SAV_JD1_EN);
regmap_update_bits(rt5663->regmap, RT5663_PWR_ANLG_2,
RT5668_PWR_JD1_MASK, RT5668_PWR_JD1);
regmap_update_bits(rt5663->regmap, RT5663_IRQ_1,
RT5668_EN_CB_JD_MASK, RT5668_EN_CB_JD_EN);
regmap_update_bits(rt5663->regmap, RT5663_HP_LOGIC_2,
RT5668_HP_SIG_SRC1_MASK, RT5668_HP_SIG_SRC1_REG);
regmap_update_bits(rt5663->regmap, RT5663_RECMIX,
RT5668_VREF_BIAS_MASK | RT5668_CBJ_DET_MASK |
RT5668_DET_TYPE_MASK, RT5668_VREF_BIAS_REG |
RT5668_CBJ_DET_EN | RT5668_DET_TYPE_QFN);
regmap_update_bits(rt5663->regmap, RT5663_GPIO_2,
RT5668_GP4_PIN_CONF_MASK, RT5668_GP4_PIN_CONF_INPUT);
regmap_update_bits(rt5663->regmap, RT5668_GPIO_3,
RT5668_GP8_PIN_CONF_MASK, RT5668_GP8_PIN_CONF_INPUT);
regmap_update_bits(rt5663->regmap, RT5663_PWR_ANLG_1,
RT5668_LDO1_DVO_MASK | RT5668_AMP_HP_MASK,
RT5668_LDO1_DVO_0_9V | RT5668_AMP_HP_3X);
break;
case CODEC_TYPE_RT5663:
regmap_write(rt5663->regmap, RT5663_VREF_RECMIX, 0x0032);
regmap_write(rt5663->regmap, RT5663_PWR_ANLG_1, 0xa2be);
msleep(20);
regmap_write(rt5663->regmap, RT5663_PWR_ANLG_1, 0xf2be);
regmap_update_bits(rt5663->regmap, RT5663_GPIO_2,
RT5663_GP1_PIN_CONF_MASK, RT5663_GP1_PIN_CONF_OUTPUT);
regmap_update_bits(rt5663->regmap, RT5663_DACREF_LDO, 0x3e0e,
0x3a0a);
regmap_update_bits(rt5663->regmap, RT5663_RECMIX,
RT5663_RECMIX1_BST1_MASK, RT5663_RECMIX1_BST1_ON);
regmap_update_bits(rt5663->regmap, RT5663_TDM_2,
RT5663_DATA_SWAP_ADCDAT1_MASK,
RT5663_DATA_SWAP_ADCDAT1_LL);
break;
default:
dev_err(&i2c->dev, "%s:Unknown codec type\n", __func__);
}
INIT_DELAYED_WORK(&rt5663->jack_detect_work, rt5663_jack_detect_work);
if (i2c->irq) {
ret = request_irq(i2c->irq, rt5663_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING
| IRQF_ONESHOT, "rt5663", rt5663);
if (ret)
dev_err(&i2c->dev, "%s Failed to reguest IRQ: %d\n",
__func__, ret);
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5663,
rt5663_dai, ARRAY_SIZE(rt5663_dai));
if (ret) {
if (i2c->irq)
free_irq(i2c->irq, rt5663);
}
return ret;
}
static int rt5663_i2c_remove(struct i2c_client *i2c)
{
struct rt5663_priv *rt5663 = i2c_get_clientdata(i2c);
if (i2c->irq)
free_irq(i2c->irq, rt5663);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static void rt5663_i2c_shutdown(struct i2c_client *client)
{
struct rt5663_priv *rt5663 = i2c_get_clientdata(client);
regmap_write(rt5663->regmap, RT5663_RESET, 0);
}
