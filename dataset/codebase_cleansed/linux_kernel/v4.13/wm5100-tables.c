bool wm5100_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM5100_SOFTWARE_RESET:
case WM5100_DEVICE_REVISION:
case WM5100_FX_CTRL:
case WM5100_INTERRUPT_STATUS_1:
case WM5100_INTERRUPT_STATUS_2:
case WM5100_INTERRUPT_STATUS_3:
case WM5100_INTERRUPT_STATUS_4:
case WM5100_INTERRUPT_RAW_STATUS_2:
case WM5100_INTERRUPT_RAW_STATUS_3:
case WM5100_INTERRUPT_RAW_STATUS_4:
case WM5100_OUTPUT_STATUS_1:
case WM5100_OUTPUT_STATUS_2:
case WM5100_INPUT_ENABLES_STATUS:
case WM5100_MIC_DETECT_3:
return 1;
default:
if ((reg >= WM5100_DSP1_PM_0 && reg <= WM5100_DSP1_PM_1535) ||
(reg >= WM5100_DSP1_ZM_0 && reg <= WM5100_DSP1_ZM_2047) ||
(reg >= WM5100_DSP1_DM_0 && reg <= WM5100_DSP1_DM_511) ||
(reg >= WM5100_DSP2_PM_0 && reg <= WM5100_DSP2_PM_1535) ||
(reg >= WM5100_DSP2_ZM_0 && reg <= WM5100_DSP2_ZM_2047) ||
(reg >= WM5100_DSP2_DM_0 && reg <= WM5100_DSP2_DM_511) ||
(reg >= WM5100_DSP3_PM_0 && reg <= WM5100_DSP3_PM_1535) ||
(reg >= WM5100_DSP3_ZM_0 && reg <= WM5100_DSP3_ZM_2047) ||
(reg >= WM5100_DSP3_DM_0 && reg <= WM5100_DSP3_DM_511))
return 1;
else
return 0;
}
}
bool wm5100_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM5100_SOFTWARE_RESET:
case WM5100_DEVICE_REVISION:
case WM5100_CTRL_IF_1:
case WM5100_TONE_GENERATOR_1:
case WM5100_PWM_DRIVE_1:
case WM5100_PWM_DRIVE_2:
case WM5100_PWM_DRIVE_3:
case WM5100_CLOCKING_1:
case WM5100_CLOCKING_3:
case WM5100_CLOCKING_4:
case WM5100_CLOCKING_5:
case WM5100_CLOCKING_6:
case WM5100_CLOCKING_7:
case WM5100_CLOCKING_8:
case WM5100_ASRC_ENABLE:
case WM5100_ASRC_STATUS:
case WM5100_ASRC_RATE1:
case WM5100_ISRC_1_CTRL_1:
case WM5100_ISRC_1_CTRL_2:
case WM5100_ISRC_2_CTRL1:
case WM5100_ISRC_2_CTRL_2:
case WM5100_FLL1_CONTROL_1:
case WM5100_FLL1_CONTROL_2:
case WM5100_FLL1_CONTROL_3:
case WM5100_FLL1_CONTROL_5:
case WM5100_FLL1_CONTROL_6:
case WM5100_FLL1_EFS_1:
case WM5100_FLL2_CONTROL_1:
case WM5100_FLL2_CONTROL_2:
case WM5100_FLL2_CONTROL_3:
case WM5100_FLL2_CONTROL_5:
case WM5100_FLL2_CONTROL_6:
case WM5100_FLL2_EFS_1:
case WM5100_MIC_CHARGE_PUMP_1:
case WM5100_MIC_CHARGE_PUMP_2:
case WM5100_HP_CHARGE_PUMP_1:
case WM5100_LDO1_CONTROL:
case WM5100_MIC_BIAS_CTRL_1:
case WM5100_MIC_BIAS_CTRL_2:
case WM5100_MIC_BIAS_CTRL_3:
case WM5100_ACCESSORY_DETECT_MODE_1:
case WM5100_HEADPHONE_DETECT_1:
case WM5100_HEADPHONE_DETECT_2:
case WM5100_MIC_DETECT_1:
case WM5100_MIC_DETECT_2:
case WM5100_MIC_DETECT_3:
case WM5100_MISC_CONTROL:
case WM5100_INPUT_ENABLES:
case WM5100_INPUT_ENABLES_STATUS:
case WM5100_IN1L_CONTROL:
case WM5100_IN1R_CONTROL:
case WM5100_IN2L_CONTROL:
case WM5100_IN2R_CONTROL:
case WM5100_IN3L_CONTROL:
case WM5100_IN3R_CONTROL:
case WM5100_IN4L_CONTROL:
case WM5100_IN4R_CONTROL:
case WM5100_RXANC_SRC:
case WM5100_INPUT_VOLUME_RAMP:
case WM5100_ADC_DIGITAL_VOLUME_1L:
case WM5100_ADC_DIGITAL_VOLUME_1R:
case WM5100_ADC_DIGITAL_VOLUME_2L:
case WM5100_ADC_DIGITAL_VOLUME_2R:
case WM5100_ADC_DIGITAL_VOLUME_3L:
case WM5100_ADC_DIGITAL_VOLUME_3R:
case WM5100_ADC_DIGITAL_VOLUME_4L:
case WM5100_ADC_DIGITAL_VOLUME_4R:
case WM5100_OUTPUT_ENABLES_2:
case WM5100_OUTPUT_STATUS_1:
case WM5100_OUTPUT_STATUS_2:
case WM5100_CHANNEL_ENABLES_1:
case WM5100_OUT_VOLUME_1L:
case WM5100_OUT_VOLUME_1R:
case WM5100_DAC_VOLUME_LIMIT_1L:
case WM5100_DAC_VOLUME_LIMIT_1R:
case WM5100_OUT_VOLUME_2L:
case WM5100_OUT_VOLUME_2R:
case WM5100_DAC_VOLUME_LIMIT_2L:
case WM5100_DAC_VOLUME_LIMIT_2R:
case WM5100_OUT_VOLUME_3L:
case WM5100_OUT_VOLUME_3R:
case WM5100_DAC_VOLUME_LIMIT_3L:
case WM5100_DAC_VOLUME_LIMIT_3R:
case WM5100_OUT_VOLUME_4L:
case WM5100_OUT_VOLUME_4R:
case WM5100_DAC_VOLUME_LIMIT_5L:
case WM5100_DAC_VOLUME_LIMIT_5R:
case WM5100_DAC_VOLUME_LIMIT_6L:
case WM5100_DAC_VOLUME_LIMIT_6R:
case WM5100_DAC_AEC_CONTROL_1:
case WM5100_OUTPUT_VOLUME_RAMP:
case WM5100_DAC_DIGITAL_VOLUME_1L:
case WM5100_DAC_DIGITAL_VOLUME_1R:
case WM5100_DAC_DIGITAL_VOLUME_2L:
case WM5100_DAC_DIGITAL_VOLUME_2R:
case WM5100_DAC_DIGITAL_VOLUME_3L:
case WM5100_DAC_DIGITAL_VOLUME_3R:
case WM5100_DAC_DIGITAL_VOLUME_4L:
case WM5100_DAC_DIGITAL_VOLUME_4R:
case WM5100_DAC_DIGITAL_VOLUME_5L:
case WM5100_DAC_DIGITAL_VOLUME_5R:
case WM5100_DAC_DIGITAL_VOLUME_6L:
case WM5100_DAC_DIGITAL_VOLUME_6R:
case WM5100_PDM_SPK1_CTRL_1:
case WM5100_PDM_SPK1_CTRL_2:
case WM5100_PDM_SPK2_CTRL_1:
case WM5100_PDM_SPK2_CTRL_2:
case WM5100_AUDIO_IF_1_1:
case WM5100_AUDIO_IF_1_2:
case WM5100_AUDIO_IF_1_3:
case WM5100_AUDIO_IF_1_4:
case WM5100_AUDIO_IF_1_5:
case WM5100_AUDIO_IF_1_6:
case WM5100_AUDIO_IF_1_7:
case WM5100_AUDIO_IF_1_8:
case WM5100_AUDIO_IF_1_9:
case WM5100_AUDIO_IF_1_10:
case WM5100_AUDIO_IF_1_11:
case WM5100_AUDIO_IF_1_12:
case WM5100_AUDIO_IF_1_13:
case WM5100_AUDIO_IF_1_14:
case WM5100_AUDIO_IF_1_15:
case WM5100_AUDIO_IF_1_16:
case WM5100_AUDIO_IF_1_17:
case WM5100_AUDIO_IF_1_18:
case WM5100_AUDIO_IF_1_19:
case WM5100_AUDIO_IF_1_20:
case WM5100_AUDIO_IF_1_21:
case WM5100_AUDIO_IF_1_22:
case WM5100_AUDIO_IF_1_23:
case WM5100_AUDIO_IF_1_24:
case WM5100_AUDIO_IF_1_25:
case WM5100_AUDIO_IF_1_26:
case WM5100_AUDIO_IF_1_27:
case WM5100_AUDIO_IF_2_1:
case WM5100_AUDIO_IF_2_2:
case WM5100_AUDIO_IF_2_3:
case WM5100_AUDIO_IF_2_4:
case WM5100_AUDIO_IF_2_5:
case WM5100_AUDIO_IF_2_6:
case WM5100_AUDIO_IF_2_7:
case WM5100_AUDIO_IF_2_8:
case WM5100_AUDIO_IF_2_9:
case WM5100_AUDIO_IF_2_10:
case WM5100_AUDIO_IF_2_11:
case WM5100_AUDIO_IF_2_18:
case WM5100_AUDIO_IF_2_19:
case WM5100_AUDIO_IF_2_26:
case WM5100_AUDIO_IF_2_27:
case WM5100_AUDIO_IF_3_1:
case WM5100_AUDIO_IF_3_2:
case WM5100_AUDIO_IF_3_3:
case WM5100_AUDIO_IF_3_4:
case WM5100_AUDIO_IF_3_5:
case WM5100_AUDIO_IF_3_6:
case WM5100_AUDIO_IF_3_7:
case WM5100_AUDIO_IF_3_8:
case WM5100_AUDIO_IF_3_9:
case WM5100_AUDIO_IF_3_10:
case WM5100_AUDIO_IF_3_11:
case WM5100_AUDIO_IF_3_18:
case WM5100_AUDIO_IF_3_19:
case WM5100_AUDIO_IF_3_26:
case WM5100_AUDIO_IF_3_27:
case WM5100_PWM1MIX_INPUT_1_SOURCE:
case WM5100_PWM1MIX_INPUT_1_VOLUME:
case WM5100_PWM1MIX_INPUT_2_SOURCE:
case WM5100_PWM1MIX_INPUT_2_VOLUME:
case WM5100_PWM1MIX_INPUT_3_SOURCE:
case WM5100_PWM1MIX_INPUT_3_VOLUME:
case WM5100_PWM1MIX_INPUT_4_SOURCE:
case WM5100_PWM1MIX_INPUT_4_VOLUME:
case WM5100_PWM2MIX_INPUT_1_SOURCE:
case WM5100_PWM2MIX_INPUT_1_VOLUME:
case WM5100_PWM2MIX_INPUT_2_SOURCE:
case WM5100_PWM2MIX_INPUT_2_VOLUME:
case WM5100_PWM2MIX_INPUT_3_SOURCE:
case WM5100_PWM2MIX_INPUT_3_VOLUME:
case WM5100_PWM2MIX_INPUT_4_SOURCE:
case WM5100_PWM2MIX_INPUT_4_VOLUME:
case WM5100_OUT1LMIX_INPUT_1_SOURCE:
case WM5100_OUT1LMIX_INPUT_1_VOLUME:
case WM5100_OUT1LMIX_INPUT_2_SOURCE:
case WM5100_OUT1LMIX_INPUT_2_VOLUME:
case WM5100_OUT1LMIX_INPUT_3_SOURCE:
case WM5100_OUT1LMIX_INPUT_3_VOLUME:
case WM5100_OUT1LMIX_INPUT_4_SOURCE:
case WM5100_OUT1LMIX_INPUT_4_VOLUME:
case WM5100_OUT1RMIX_INPUT_1_SOURCE:
case WM5100_OUT1RMIX_INPUT_1_VOLUME:
case WM5100_OUT1RMIX_INPUT_2_SOURCE:
case WM5100_OUT1RMIX_INPUT_2_VOLUME:
case WM5100_OUT1RMIX_INPUT_3_SOURCE:
case WM5100_OUT1RMIX_INPUT_3_VOLUME:
case WM5100_OUT1RMIX_INPUT_4_SOURCE:
case WM5100_OUT1RMIX_INPUT_4_VOLUME:
case WM5100_OUT2LMIX_INPUT_1_SOURCE:
case WM5100_OUT2LMIX_INPUT_1_VOLUME:
case WM5100_OUT2LMIX_INPUT_2_SOURCE:
case WM5100_OUT2LMIX_INPUT_2_VOLUME:
case WM5100_OUT2LMIX_INPUT_3_SOURCE:
case WM5100_OUT2LMIX_INPUT_3_VOLUME:
case WM5100_OUT2LMIX_INPUT_4_SOURCE:
case WM5100_OUT2LMIX_INPUT_4_VOLUME:
case WM5100_OUT2RMIX_INPUT_1_SOURCE:
case WM5100_OUT2RMIX_INPUT_1_VOLUME:
case WM5100_OUT2RMIX_INPUT_2_SOURCE:
case WM5100_OUT2RMIX_INPUT_2_VOLUME:
case WM5100_OUT2RMIX_INPUT_3_SOURCE:
case WM5100_OUT2RMIX_INPUT_3_VOLUME:
case WM5100_OUT2RMIX_INPUT_4_SOURCE:
case WM5100_OUT2RMIX_INPUT_4_VOLUME:
case WM5100_OUT3LMIX_INPUT_1_SOURCE:
case WM5100_OUT3LMIX_INPUT_1_VOLUME:
case WM5100_OUT3LMIX_INPUT_2_SOURCE:
case WM5100_OUT3LMIX_INPUT_2_VOLUME:
case WM5100_OUT3LMIX_INPUT_3_SOURCE:
case WM5100_OUT3LMIX_INPUT_3_VOLUME:
case WM5100_OUT3LMIX_INPUT_4_SOURCE:
case WM5100_OUT3LMIX_INPUT_4_VOLUME:
case WM5100_OUT3RMIX_INPUT_1_SOURCE:
case WM5100_OUT3RMIX_INPUT_1_VOLUME:
case WM5100_OUT3RMIX_INPUT_2_SOURCE:
case WM5100_OUT3RMIX_INPUT_2_VOLUME:
case WM5100_OUT3RMIX_INPUT_3_SOURCE:
case WM5100_OUT3RMIX_INPUT_3_VOLUME:
case WM5100_OUT3RMIX_INPUT_4_SOURCE:
case WM5100_OUT3RMIX_INPUT_4_VOLUME:
case WM5100_OUT4LMIX_INPUT_1_SOURCE:
case WM5100_OUT4LMIX_INPUT_1_VOLUME:
case WM5100_OUT4LMIX_INPUT_2_SOURCE:
case WM5100_OUT4LMIX_INPUT_2_VOLUME:
case WM5100_OUT4LMIX_INPUT_3_SOURCE:
case WM5100_OUT4LMIX_INPUT_3_VOLUME:
case WM5100_OUT4LMIX_INPUT_4_SOURCE:
case WM5100_OUT4LMIX_INPUT_4_VOLUME:
case WM5100_OUT4RMIX_INPUT_1_SOURCE:
case WM5100_OUT4RMIX_INPUT_1_VOLUME:
case WM5100_OUT4RMIX_INPUT_2_SOURCE:
case WM5100_OUT4RMIX_INPUT_2_VOLUME:
case WM5100_OUT4RMIX_INPUT_3_SOURCE:
case WM5100_OUT4RMIX_INPUT_3_VOLUME:
case WM5100_OUT4RMIX_INPUT_4_SOURCE:
case WM5100_OUT4RMIX_INPUT_4_VOLUME:
case WM5100_OUT5LMIX_INPUT_1_SOURCE:
case WM5100_OUT5LMIX_INPUT_1_VOLUME:
case WM5100_OUT5LMIX_INPUT_2_SOURCE:
case WM5100_OUT5LMIX_INPUT_2_VOLUME:
case WM5100_OUT5LMIX_INPUT_3_SOURCE:
case WM5100_OUT5LMIX_INPUT_3_VOLUME:
case WM5100_OUT5LMIX_INPUT_4_SOURCE:
case WM5100_OUT5LMIX_INPUT_4_VOLUME:
case WM5100_OUT5RMIX_INPUT_1_SOURCE:
case WM5100_OUT5RMIX_INPUT_1_VOLUME:
case WM5100_OUT5RMIX_INPUT_2_SOURCE:
case WM5100_OUT5RMIX_INPUT_2_VOLUME:
case WM5100_OUT5RMIX_INPUT_3_SOURCE:
case WM5100_OUT5RMIX_INPUT_3_VOLUME:
case WM5100_OUT5RMIX_INPUT_4_SOURCE:
case WM5100_OUT5RMIX_INPUT_4_VOLUME:
case WM5100_OUT6LMIX_INPUT_1_SOURCE:
case WM5100_OUT6LMIX_INPUT_1_VOLUME:
case WM5100_OUT6LMIX_INPUT_2_SOURCE:
case WM5100_OUT6LMIX_INPUT_2_VOLUME:
case WM5100_OUT6LMIX_INPUT_3_SOURCE:
case WM5100_OUT6LMIX_INPUT_3_VOLUME:
case WM5100_OUT6LMIX_INPUT_4_SOURCE:
case WM5100_OUT6LMIX_INPUT_4_VOLUME:
case WM5100_OUT6RMIX_INPUT_1_SOURCE:
case WM5100_OUT6RMIX_INPUT_1_VOLUME:
case WM5100_OUT6RMIX_INPUT_2_SOURCE:
case WM5100_OUT6RMIX_INPUT_2_VOLUME:
case WM5100_OUT6RMIX_INPUT_3_SOURCE:
case WM5100_OUT6RMIX_INPUT_3_VOLUME:
case WM5100_OUT6RMIX_INPUT_4_SOURCE:
case WM5100_OUT6RMIX_INPUT_4_VOLUME:
case WM5100_AIF1TX1MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX1MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX1MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX1MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX1MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX1MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX1MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX1MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX2MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX2MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX2MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX2MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX2MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX2MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX2MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX2MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX3MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX3MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX3MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX3MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX3MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX3MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX3MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX3MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX4MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX4MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX4MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX4MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX4MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX4MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX4MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX4MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX5MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX5MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX5MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX5MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX5MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX5MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX5MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX5MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX6MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX6MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX6MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX6MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX6MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX6MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX6MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX6MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX7MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX7MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX7MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX7MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX7MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX7MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX7MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX7MIX_INPUT_4_VOLUME:
case WM5100_AIF1TX8MIX_INPUT_1_SOURCE:
case WM5100_AIF1TX8MIX_INPUT_1_VOLUME:
case WM5100_AIF1TX8MIX_INPUT_2_SOURCE:
case WM5100_AIF1TX8MIX_INPUT_2_VOLUME:
case WM5100_AIF1TX8MIX_INPUT_3_SOURCE:
case WM5100_AIF1TX8MIX_INPUT_3_VOLUME:
case WM5100_AIF1TX8MIX_INPUT_4_SOURCE:
case WM5100_AIF1TX8MIX_INPUT_4_VOLUME:
case WM5100_AIF2TX1MIX_INPUT_1_SOURCE:
case WM5100_AIF2TX1MIX_INPUT_1_VOLUME:
case WM5100_AIF2TX1MIX_INPUT_2_SOURCE:
case WM5100_AIF2TX1MIX_INPUT_2_VOLUME:
case WM5100_AIF2TX1MIX_INPUT_3_SOURCE:
case WM5100_AIF2TX1MIX_INPUT_3_VOLUME:
case WM5100_AIF2TX1MIX_INPUT_4_SOURCE:
case WM5100_AIF2TX1MIX_INPUT_4_VOLUME:
case WM5100_AIF2TX2MIX_INPUT_1_SOURCE:
case WM5100_AIF2TX2MIX_INPUT_1_VOLUME:
case WM5100_AIF2TX2MIX_INPUT_2_SOURCE:
case WM5100_AIF2TX2MIX_INPUT_2_VOLUME:
case WM5100_AIF2TX2MIX_INPUT_3_SOURCE:
case WM5100_AIF2TX2MIX_INPUT_3_VOLUME:
case WM5100_AIF2TX2MIX_INPUT_4_SOURCE:
case WM5100_AIF2TX2MIX_INPUT_4_VOLUME:
case WM5100_AIF3TX1MIX_INPUT_1_SOURCE:
case WM5100_AIF3TX1MIX_INPUT_1_VOLUME:
case WM5100_AIF3TX1MIX_INPUT_2_SOURCE:
case WM5100_AIF3TX1MIX_INPUT_2_VOLUME:
case WM5100_AIF3TX1MIX_INPUT_3_SOURCE:
case WM5100_AIF3TX1MIX_INPUT_3_VOLUME:
case WM5100_AIF3TX1MIX_INPUT_4_SOURCE:
case WM5100_AIF3TX1MIX_INPUT_4_VOLUME:
case WM5100_AIF3TX2MIX_INPUT_1_SOURCE:
case WM5100_AIF3TX2MIX_INPUT_1_VOLUME:
case WM5100_AIF3TX2MIX_INPUT_2_SOURCE:
case WM5100_AIF3TX2MIX_INPUT_2_VOLUME:
case WM5100_AIF3TX2MIX_INPUT_3_SOURCE:
case WM5100_AIF3TX2MIX_INPUT_3_VOLUME:
case WM5100_AIF3TX2MIX_INPUT_4_SOURCE:
case WM5100_AIF3TX2MIX_INPUT_4_VOLUME:
case WM5100_EQ1MIX_INPUT_1_SOURCE:
case WM5100_EQ1MIX_INPUT_1_VOLUME:
case WM5100_EQ1MIX_INPUT_2_SOURCE:
case WM5100_EQ1MIX_INPUT_2_VOLUME:
case WM5100_EQ1MIX_INPUT_3_SOURCE:
case WM5100_EQ1MIX_INPUT_3_VOLUME:
case WM5100_EQ1MIX_INPUT_4_SOURCE:
case WM5100_EQ1MIX_INPUT_4_VOLUME:
case WM5100_EQ2MIX_INPUT_1_SOURCE:
case WM5100_EQ2MIX_INPUT_1_VOLUME:
case WM5100_EQ2MIX_INPUT_2_SOURCE:
case WM5100_EQ2MIX_INPUT_2_VOLUME:
case WM5100_EQ2MIX_INPUT_3_SOURCE:
case WM5100_EQ2MIX_INPUT_3_VOLUME:
case WM5100_EQ2MIX_INPUT_4_SOURCE:
case WM5100_EQ2MIX_INPUT_4_VOLUME:
case WM5100_EQ3MIX_INPUT_1_SOURCE:
case WM5100_EQ3MIX_INPUT_1_VOLUME:
case WM5100_EQ3MIX_INPUT_2_SOURCE:
case WM5100_EQ3MIX_INPUT_2_VOLUME:
case WM5100_EQ3MIX_INPUT_3_SOURCE:
case WM5100_EQ3MIX_INPUT_3_VOLUME:
case WM5100_EQ3MIX_INPUT_4_SOURCE:
case WM5100_EQ3MIX_INPUT_4_VOLUME:
case WM5100_EQ4MIX_INPUT_1_SOURCE:
case WM5100_EQ4MIX_INPUT_1_VOLUME:
case WM5100_EQ4MIX_INPUT_2_SOURCE:
case WM5100_EQ4MIX_INPUT_2_VOLUME:
case WM5100_EQ4MIX_INPUT_3_SOURCE:
case WM5100_EQ4MIX_INPUT_3_VOLUME:
case WM5100_EQ4MIX_INPUT_4_SOURCE:
case WM5100_EQ4MIX_INPUT_4_VOLUME:
case WM5100_DRC1LMIX_INPUT_1_SOURCE:
case WM5100_DRC1LMIX_INPUT_1_VOLUME:
case WM5100_DRC1LMIX_INPUT_2_SOURCE:
case WM5100_DRC1LMIX_INPUT_2_VOLUME:
case WM5100_DRC1LMIX_INPUT_3_SOURCE:
case WM5100_DRC1LMIX_INPUT_3_VOLUME:
case WM5100_DRC1LMIX_INPUT_4_SOURCE:
case WM5100_DRC1LMIX_INPUT_4_VOLUME:
case WM5100_DRC1RMIX_INPUT_1_SOURCE:
case WM5100_DRC1RMIX_INPUT_1_VOLUME:
case WM5100_DRC1RMIX_INPUT_2_SOURCE:
case WM5100_DRC1RMIX_INPUT_2_VOLUME:
case WM5100_DRC1RMIX_INPUT_3_SOURCE:
case WM5100_DRC1RMIX_INPUT_3_VOLUME:
case WM5100_DRC1RMIX_INPUT_4_SOURCE:
case WM5100_DRC1RMIX_INPUT_4_VOLUME:
case WM5100_HPLP1MIX_INPUT_1_SOURCE:
case WM5100_HPLP1MIX_INPUT_1_VOLUME:
case WM5100_HPLP1MIX_INPUT_2_SOURCE:
case WM5100_HPLP1MIX_INPUT_2_VOLUME:
case WM5100_HPLP1MIX_INPUT_3_SOURCE:
case WM5100_HPLP1MIX_INPUT_3_VOLUME:
case WM5100_HPLP1MIX_INPUT_4_SOURCE:
case WM5100_HPLP1MIX_INPUT_4_VOLUME:
case WM5100_HPLP2MIX_INPUT_1_SOURCE:
case WM5100_HPLP2MIX_INPUT_1_VOLUME:
case WM5100_HPLP2MIX_INPUT_2_SOURCE:
case WM5100_HPLP2MIX_INPUT_2_VOLUME:
case WM5100_HPLP2MIX_INPUT_3_SOURCE:
case WM5100_HPLP2MIX_INPUT_3_VOLUME:
case WM5100_HPLP2MIX_INPUT_4_SOURCE:
case WM5100_HPLP2MIX_INPUT_4_VOLUME:
case WM5100_HPLP3MIX_INPUT_1_SOURCE:
case WM5100_HPLP3MIX_INPUT_1_VOLUME:
case WM5100_HPLP3MIX_INPUT_2_SOURCE:
case WM5100_HPLP3MIX_INPUT_2_VOLUME:
case WM5100_HPLP3MIX_INPUT_3_SOURCE:
case WM5100_HPLP3MIX_INPUT_3_VOLUME:
case WM5100_HPLP3MIX_INPUT_4_SOURCE:
case WM5100_HPLP3MIX_INPUT_4_VOLUME:
case WM5100_HPLP4MIX_INPUT_1_SOURCE:
case WM5100_HPLP4MIX_INPUT_1_VOLUME:
case WM5100_HPLP4MIX_INPUT_2_SOURCE:
case WM5100_HPLP4MIX_INPUT_2_VOLUME:
case WM5100_HPLP4MIX_INPUT_3_SOURCE:
case WM5100_HPLP4MIX_INPUT_3_VOLUME:
case WM5100_HPLP4MIX_INPUT_4_SOURCE:
case WM5100_HPLP4MIX_INPUT_4_VOLUME:
case WM5100_DSP1LMIX_INPUT_1_SOURCE:
case WM5100_DSP1LMIX_INPUT_1_VOLUME:
case WM5100_DSP1LMIX_INPUT_2_SOURCE:
case WM5100_DSP1LMIX_INPUT_2_VOLUME:
case WM5100_DSP1LMIX_INPUT_3_SOURCE:
case WM5100_DSP1LMIX_INPUT_3_VOLUME:
case WM5100_DSP1LMIX_INPUT_4_SOURCE:
case WM5100_DSP1LMIX_INPUT_4_VOLUME:
case WM5100_DSP1RMIX_INPUT_1_SOURCE:
case WM5100_DSP1RMIX_INPUT_1_VOLUME:
case WM5100_DSP1RMIX_INPUT_2_SOURCE:
case WM5100_DSP1RMIX_INPUT_2_VOLUME:
case WM5100_DSP1RMIX_INPUT_3_SOURCE:
case WM5100_DSP1RMIX_INPUT_3_VOLUME:
case WM5100_DSP1RMIX_INPUT_4_SOURCE:
case WM5100_DSP1RMIX_INPUT_4_VOLUME:
case WM5100_DSP1AUX1MIX_INPUT_1_SOURCE:
case WM5100_DSP1AUX2MIX_INPUT_1_SOURCE:
case WM5100_DSP1AUX3MIX_INPUT_1_SOURCE:
case WM5100_DSP1AUX4MIX_INPUT_1_SOURCE:
case WM5100_DSP1AUX5MIX_INPUT_1_SOURCE:
case WM5100_DSP1AUX6MIX_INPUT_1_SOURCE:
case WM5100_DSP2LMIX_INPUT_1_SOURCE:
case WM5100_DSP2LMIX_INPUT_1_VOLUME:
case WM5100_DSP2LMIX_INPUT_2_SOURCE:
case WM5100_DSP2LMIX_INPUT_2_VOLUME:
case WM5100_DSP2LMIX_INPUT_3_SOURCE:
case WM5100_DSP2LMIX_INPUT_3_VOLUME:
case WM5100_DSP2LMIX_INPUT_4_SOURCE:
case WM5100_DSP2LMIX_INPUT_4_VOLUME:
case WM5100_DSP2RMIX_INPUT_1_SOURCE:
case WM5100_DSP2RMIX_INPUT_1_VOLUME:
case WM5100_DSP2RMIX_INPUT_2_SOURCE:
case WM5100_DSP2RMIX_INPUT_2_VOLUME:
case WM5100_DSP2RMIX_INPUT_3_SOURCE:
case WM5100_DSP2RMIX_INPUT_3_VOLUME:
case WM5100_DSP2RMIX_INPUT_4_SOURCE:
case WM5100_DSP2RMIX_INPUT_4_VOLUME:
case WM5100_DSP2AUX1MIX_INPUT_1_SOURCE:
case WM5100_DSP2AUX2MIX_INPUT_1_SOURCE:
case WM5100_DSP2AUX3MIX_INPUT_1_SOURCE:
case WM5100_DSP2AUX4MIX_INPUT_1_SOURCE:
case WM5100_DSP2AUX5MIX_INPUT_1_SOURCE:
case WM5100_DSP2AUX6MIX_INPUT_1_SOURCE:
case WM5100_DSP3LMIX_INPUT_1_SOURCE:
case WM5100_DSP3LMIX_INPUT_1_VOLUME:
case WM5100_DSP3LMIX_INPUT_2_SOURCE:
case WM5100_DSP3LMIX_INPUT_2_VOLUME:
case WM5100_DSP3LMIX_INPUT_3_SOURCE:
case WM5100_DSP3LMIX_INPUT_3_VOLUME:
case WM5100_DSP3LMIX_INPUT_4_SOURCE:
case WM5100_DSP3LMIX_INPUT_4_VOLUME:
case WM5100_DSP3RMIX_INPUT_1_SOURCE:
case WM5100_DSP3RMIX_INPUT_1_VOLUME:
case WM5100_DSP3RMIX_INPUT_2_SOURCE:
case WM5100_DSP3RMIX_INPUT_2_VOLUME:
case WM5100_DSP3RMIX_INPUT_3_SOURCE:
case WM5100_DSP3RMIX_INPUT_3_VOLUME:
case WM5100_DSP3RMIX_INPUT_4_SOURCE:
case WM5100_DSP3RMIX_INPUT_4_VOLUME:
case WM5100_DSP3AUX1MIX_INPUT_1_SOURCE:
case WM5100_DSP3AUX2MIX_INPUT_1_SOURCE:
case WM5100_DSP3AUX3MIX_INPUT_1_SOURCE:
case WM5100_DSP3AUX4MIX_INPUT_1_SOURCE:
case WM5100_DSP3AUX5MIX_INPUT_1_SOURCE:
case WM5100_DSP3AUX6MIX_INPUT_1_SOURCE:
case WM5100_ASRC1LMIX_INPUT_1_SOURCE:
case WM5100_ASRC1RMIX_INPUT_1_SOURCE:
case WM5100_ASRC2LMIX_INPUT_1_SOURCE:
case WM5100_ASRC2RMIX_INPUT_1_SOURCE:
case WM5100_ISRC1DEC1MIX_INPUT_1_SOURCE:
case WM5100_ISRC1DEC2MIX_INPUT_1_SOURCE:
case WM5100_ISRC1DEC3MIX_INPUT_1_SOURCE:
case WM5100_ISRC1DEC4MIX_INPUT_1_SOURCE:
case WM5100_ISRC1INT1MIX_INPUT_1_SOURCE:
case WM5100_ISRC1INT2MIX_INPUT_1_SOURCE:
case WM5100_ISRC1INT3MIX_INPUT_1_SOURCE:
case WM5100_ISRC1INT4MIX_INPUT_1_SOURCE:
case WM5100_ISRC2DEC1MIX_INPUT_1_SOURCE:
case WM5100_ISRC2DEC2MIX_INPUT_1_SOURCE:
case WM5100_ISRC2DEC3MIX_INPUT_1_SOURCE:
case WM5100_ISRC2DEC4MIX_INPUT_1_SOURCE:
case WM5100_ISRC2INT1MIX_INPUT_1_SOURCE:
case WM5100_ISRC2INT2MIX_INPUT_1_SOURCE:
case WM5100_ISRC2INT3MIX_INPUT_1_SOURCE:
case WM5100_ISRC2INT4MIX_INPUT_1_SOURCE:
case WM5100_GPIO_CTRL_1:
case WM5100_GPIO_CTRL_2:
case WM5100_GPIO_CTRL_3:
case WM5100_GPIO_CTRL_4:
case WM5100_GPIO_CTRL_5:
case WM5100_GPIO_CTRL_6:
case WM5100_MISC_PAD_CTRL_1:
case WM5100_MISC_PAD_CTRL_2:
case WM5100_MISC_PAD_CTRL_3:
case WM5100_MISC_PAD_CTRL_4:
case WM5100_MISC_PAD_CTRL_5:
case WM5100_MISC_GPIO_1:
case WM5100_INTERRUPT_STATUS_1:
case WM5100_INTERRUPT_STATUS_2:
case WM5100_INTERRUPT_STATUS_3:
case WM5100_INTERRUPT_STATUS_4:
case WM5100_INTERRUPT_RAW_STATUS_2:
case WM5100_INTERRUPT_RAW_STATUS_3:
case WM5100_INTERRUPT_RAW_STATUS_4:
case WM5100_INTERRUPT_STATUS_1_MASK:
case WM5100_INTERRUPT_STATUS_2_MASK:
case WM5100_INTERRUPT_STATUS_3_MASK:
case WM5100_INTERRUPT_STATUS_4_MASK:
case WM5100_INTERRUPT_CONTROL:
case WM5100_IRQ_DEBOUNCE_1:
case WM5100_IRQ_DEBOUNCE_2:
case WM5100_FX_CTRL:
case WM5100_EQ1_1:
case WM5100_EQ1_2:
case WM5100_EQ1_3:
case WM5100_EQ1_4:
case WM5100_EQ1_5:
case WM5100_EQ1_6:
case WM5100_EQ1_7:
case WM5100_EQ1_8:
case WM5100_EQ1_9:
case WM5100_EQ1_10:
case WM5100_EQ1_11:
case WM5100_EQ1_12:
case WM5100_EQ1_13:
case WM5100_EQ1_14:
case WM5100_EQ1_15:
case WM5100_EQ1_16:
case WM5100_EQ1_17:
case WM5100_EQ1_18:
case WM5100_EQ1_19:
case WM5100_EQ1_20:
case WM5100_EQ2_1:
case WM5100_EQ2_2:
case WM5100_EQ2_3:
case WM5100_EQ2_4:
case WM5100_EQ2_5:
case WM5100_EQ2_6:
case WM5100_EQ2_7:
case WM5100_EQ2_8:
case WM5100_EQ2_9:
case WM5100_EQ2_10:
case WM5100_EQ2_11:
case WM5100_EQ2_12:
case WM5100_EQ2_13:
case WM5100_EQ2_14:
case WM5100_EQ2_15:
case WM5100_EQ2_16:
case WM5100_EQ2_17:
case WM5100_EQ2_18:
case WM5100_EQ2_19:
case WM5100_EQ2_20:
case WM5100_EQ3_1:
case WM5100_EQ3_2:
case WM5100_EQ3_3:
case WM5100_EQ3_4:
case WM5100_EQ3_5:
case WM5100_EQ3_6:
case WM5100_EQ3_7:
case WM5100_EQ3_8:
case WM5100_EQ3_9:
case WM5100_EQ3_10:
case WM5100_EQ3_11:
case WM5100_EQ3_12:
case WM5100_EQ3_13:
case WM5100_EQ3_14:
case WM5100_EQ3_15:
case WM5100_EQ3_16:
case WM5100_EQ3_17:
case WM5100_EQ3_18:
case WM5100_EQ3_19:
case WM5100_EQ3_20:
case WM5100_EQ4_1:
case WM5100_EQ4_2:
case WM5100_EQ4_3:
case WM5100_EQ4_4:
case WM5100_EQ4_5:
case WM5100_EQ4_6:
case WM5100_EQ4_7:
case WM5100_EQ4_8:
case WM5100_EQ4_9:
case WM5100_EQ4_10:
case WM5100_EQ4_11:
case WM5100_EQ4_12:
case WM5100_EQ4_13:
case WM5100_EQ4_14:
case WM5100_EQ4_15:
case WM5100_EQ4_16:
case WM5100_EQ4_17:
case WM5100_EQ4_18:
case WM5100_EQ4_19:
case WM5100_EQ4_20:
case WM5100_DRC1_CTRL1:
case WM5100_DRC1_CTRL2:
case WM5100_DRC1_CTRL3:
case WM5100_DRC1_CTRL4:
case WM5100_DRC1_CTRL5:
case WM5100_HPLPF1_1:
case WM5100_HPLPF1_2:
case WM5100_HPLPF2_1:
case WM5100_HPLPF2_2:
case WM5100_HPLPF3_1:
case WM5100_HPLPF3_2:
case WM5100_HPLPF4_1:
case WM5100_HPLPF4_2:
case WM5100_DSP1_CONTROL_1:
case WM5100_DSP1_CONTROL_2:
case WM5100_DSP1_CONTROL_3:
case WM5100_DSP1_CONTROL_4:
case WM5100_DSP1_CONTROL_5:
case WM5100_DSP1_CONTROL_6:
case WM5100_DSP1_CONTROL_7:
case WM5100_DSP1_CONTROL_8:
case WM5100_DSP1_CONTROL_9:
case WM5100_DSP1_CONTROL_10:
case WM5100_DSP1_CONTROL_11:
case WM5100_DSP1_CONTROL_12:
case WM5100_DSP1_CONTROL_13:
case WM5100_DSP1_CONTROL_14:
case WM5100_DSP1_CONTROL_15:
case WM5100_DSP1_CONTROL_16:
case WM5100_DSP1_CONTROL_17:
case WM5100_DSP1_CONTROL_18:
case WM5100_DSP1_CONTROL_19:
case WM5100_DSP1_CONTROL_20:
case WM5100_DSP1_CONTROL_21:
case WM5100_DSP1_CONTROL_22:
case WM5100_DSP1_CONTROL_23:
case WM5100_DSP1_CONTROL_24:
case WM5100_DSP1_CONTROL_25:
case WM5100_DSP1_CONTROL_26:
case WM5100_DSP1_CONTROL_27:
case WM5100_DSP1_CONTROL_28:
case WM5100_DSP1_CONTROL_29:
case WM5100_DSP1_CONTROL_30:
case WM5100_DSP2_CONTROL_1:
case WM5100_DSP2_CONTROL_2:
case WM5100_DSP2_CONTROL_3:
case WM5100_DSP2_CONTROL_4:
case WM5100_DSP2_CONTROL_5:
case WM5100_DSP2_CONTROL_6:
case WM5100_DSP2_CONTROL_7:
case WM5100_DSP2_CONTROL_8:
case WM5100_DSP2_CONTROL_9:
case WM5100_DSP2_CONTROL_10:
case WM5100_DSP2_CONTROL_11:
case WM5100_DSP2_CONTROL_12:
case WM5100_DSP2_CONTROL_13:
case WM5100_DSP2_CONTROL_14:
case WM5100_DSP2_CONTROL_15:
case WM5100_DSP2_CONTROL_16:
case WM5100_DSP2_CONTROL_17:
case WM5100_DSP2_CONTROL_18:
case WM5100_DSP2_CONTROL_19:
case WM5100_DSP2_CONTROL_20:
case WM5100_DSP2_CONTROL_21:
case WM5100_DSP2_CONTROL_22:
case WM5100_DSP2_CONTROL_23:
case WM5100_DSP2_CONTROL_24:
case WM5100_DSP2_CONTROL_25:
case WM5100_DSP2_CONTROL_26:
case WM5100_DSP2_CONTROL_27:
case WM5100_DSP2_CONTROL_28:
case WM5100_DSP2_CONTROL_29:
case WM5100_DSP2_CONTROL_30:
case WM5100_DSP3_CONTROL_1:
case WM5100_DSP3_CONTROL_2:
case WM5100_DSP3_CONTROL_3:
case WM5100_DSP3_CONTROL_4:
case WM5100_DSP3_CONTROL_5:
case WM5100_DSP3_CONTROL_6:
case WM5100_DSP3_CONTROL_7:
case WM5100_DSP3_CONTROL_8:
case WM5100_DSP3_CONTROL_9:
case WM5100_DSP3_CONTROL_10:
case WM5100_DSP3_CONTROL_11:
case WM5100_DSP3_CONTROL_12:
case WM5100_DSP3_CONTROL_13:
case WM5100_DSP3_CONTROL_14:
case WM5100_DSP3_CONTROL_15:
case WM5100_DSP3_CONTROL_16:
case WM5100_DSP3_CONTROL_17:
case WM5100_DSP3_CONTROL_18:
case WM5100_DSP3_CONTROL_19:
case WM5100_DSP3_CONTROL_20:
case WM5100_DSP3_CONTROL_21:
case WM5100_DSP3_CONTROL_22:
case WM5100_DSP3_CONTROL_23:
case WM5100_DSP3_CONTROL_24:
case WM5100_DSP3_CONTROL_25:
case WM5100_DSP3_CONTROL_26:
case WM5100_DSP3_CONTROL_27:
case WM5100_DSP3_CONTROL_28:
case WM5100_DSP3_CONTROL_29:
case WM5100_DSP3_CONTROL_30:
return 1;
default:
if ((reg >= WM5100_DSP1_PM_0 && reg <= WM5100_DSP1_PM_1535) ||
(reg >= WM5100_DSP1_ZM_0 && reg <= WM5100_DSP1_ZM_2047) ||
(reg >= WM5100_DSP1_DM_0 && reg <= WM5100_DSP1_DM_511) ||
(reg >= WM5100_DSP2_PM_0 && reg <= WM5100_DSP2_PM_1535) ||
(reg >= WM5100_DSP2_ZM_0 && reg <= WM5100_DSP2_ZM_2047) ||
(reg >= WM5100_DSP2_DM_0 && reg <= WM5100_DSP2_DM_511) ||
(reg >= WM5100_DSP3_PM_0 && reg <= WM5100_DSP3_PM_1535) ||
(reg >= WM5100_DSP3_ZM_0 && reg <= WM5100_DSP3_ZM_2047) ||
(reg >= WM5100_DSP3_DM_0 && reg <= WM5100_DSP3_DM_511))
return 1;
else
return 0;
}
}
