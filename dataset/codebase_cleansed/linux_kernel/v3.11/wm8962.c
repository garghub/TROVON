static bool wm8962_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8962_CLOCKING1:
case WM8962_CLOCKING2:
case WM8962_SOFTWARE_RESET:
case WM8962_ALC2:
case WM8962_THERMAL_SHUTDOWN_STATUS:
case WM8962_ADDITIONAL_CONTROL_4:
case WM8962_CLASS_D_CONTROL_1:
case WM8962_DC_SERVO_6:
case WM8962_INTERRUPT_STATUS_1:
case WM8962_INTERRUPT_STATUS_2:
case WM8962_DSP2_EXECCONTROL:
return true;
default:
return false;
}
}
static bool wm8962_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8962_LEFT_INPUT_VOLUME:
case WM8962_RIGHT_INPUT_VOLUME:
case WM8962_HPOUTL_VOLUME:
case WM8962_HPOUTR_VOLUME:
case WM8962_CLOCKING1:
case WM8962_ADC_DAC_CONTROL_1:
case WM8962_ADC_DAC_CONTROL_2:
case WM8962_AUDIO_INTERFACE_0:
case WM8962_CLOCKING2:
case WM8962_AUDIO_INTERFACE_1:
case WM8962_LEFT_DAC_VOLUME:
case WM8962_RIGHT_DAC_VOLUME:
case WM8962_AUDIO_INTERFACE_2:
case WM8962_SOFTWARE_RESET:
case WM8962_ALC1:
case WM8962_ALC2:
case WM8962_ALC3:
case WM8962_NOISE_GATE:
case WM8962_LEFT_ADC_VOLUME:
case WM8962_RIGHT_ADC_VOLUME:
case WM8962_ADDITIONAL_CONTROL_1:
case WM8962_ADDITIONAL_CONTROL_2:
case WM8962_PWR_MGMT_1:
case WM8962_PWR_MGMT_2:
case WM8962_ADDITIONAL_CONTROL_3:
case WM8962_ANTI_POP:
case WM8962_CLOCKING_3:
case WM8962_INPUT_MIXER_CONTROL_1:
case WM8962_LEFT_INPUT_MIXER_VOLUME:
case WM8962_RIGHT_INPUT_MIXER_VOLUME:
case WM8962_INPUT_MIXER_CONTROL_2:
case WM8962_INPUT_BIAS_CONTROL:
case WM8962_LEFT_INPUT_PGA_CONTROL:
case WM8962_RIGHT_INPUT_PGA_CONTROL:
case WM8962_SPKOUTL_VOLUME:
case WM8962_SPKOUTR_VOLUME:
case WM8962_THERMAL_SHUTDOWN_STATUS:
case WM8962_ADDITIONAL_CONTROL_4:
case WM8962_CLASS_D_CONTROL_1:
case WM8962_CLASS_D_CONTROL_2:
case WM8962_CLOCKING_4:
case WM8962_DAC_DSP_MIXING_1:
case WM8962_DAC_DSP_MIXING_2:
case WM8962_DC_SERVO_0:
case WM8962_DC_SERVO_1:
case WM8962_DC_SERVO_4:
case WM8962_DC_SERVO_6:
case WM8962_ANALOGUE_PGA_BIAS:
case WM8962_ANALOGUE_HP_0:
case WM8962_ANALOGUE_HP_2:
case WM8962_CHARGE_PUMP_1:
case WM8962_CHARGE_PUMP_B:
case WM8962_WRITE_SEQUENCER_CONTROL_1:
case WM8962_WRITE_SEQUENCER_CONTROL_2:
case WM8962_WRITE_SEQUENCER_CONTROL_3:
case WM8962_CONTROL_INTERFACE:
case WM8962_MIXER_ENABLES:
case WM8962_HEADPHONE_MIXER_1:
case WM8962_HEADPHONE_MIXER_2:
case WM8962_HEADPHONE_MIXER_3:
case WM8962_HEADPHONE_MIXER_4:
case WM8962_SPEAKER_MIXER_1:
case WM8962_SPEAKER_MIXER_2:
case WM8962_SPEAKER_MIXER_3:
case WM8962_SPEAKER_MIXER_4:
case WM8962_SPEAKER_MIXER_5:
case WM8962_BEEP_GENERATOR_1:
case WM8962_OSCILLATOR_TRIM_3:
case WM8962_OSCILLATOR_TRIM_4:
case WM8962_OSCILLATOR_TRIM_7:
case WM8962_ANALOGUE_CLOCKING1:
case WM8962_ANALOGUE_CLOCKING2:
case WM8962_ANALOGUE_CLOCKING3:
case WM8962_PLL_SOFTWARE_RESET:
case WM8962_PLL2:
case WM8962_PLL_4:
case WM8962_PLL_9:
case WM8962_PLL_10:
case WM8962_PLL_11:
case WM8962_PLL_12:
case WM8962_PLL_13:
case WM8962_PLL_14:
case WM8962_PLL_15:
case WM8962_PLL_16:
case WM8962_FLL_CONTROL_1:
case WM8962_FLL_CONTROL_2:
case WM8962_FLL_CONTROL_3:
case WM8962_FLL_CONTROL_5:
case WM8962_FLL_CONTROL_6:
case WM8962_FLL_CONTROL_7:
case WM8962_FLL_CONTROL_8:
case WM8962_GENERAL_TEST_1:
case WM8962_DF1:
case WM8962_DF2:
case WM8962_DF3:
case WM8962_DF4:
case WM8962_DF5:
case WM8962_DF6:
case WM8962_DF7:
case WM8962_LHPF1:
case WM8962_LHPF2:
case WM8962_THREED1:
case WM8962_THREED2:
case WM8962_THREED3:
case WM8962_THREED4:
case WM8962_DRC_1:
case WM8962_DRC_2:
case WM8962_DRC_3:
case WM8962_DRC_4:
case WM8962_DRC_5:
case WM8962_TLOOPBACK:
case WM8962_EQ1:
case WM8962_EQ2:
case WM8962_EQ3:
case WM8962_EQ4:
case WM8962_EQ5:
case WM8962_EQ6:
case WM8962_EQ7:
case WM8962_EQ8:
case WM8962_EQ9:
case WM8962_EQ10:
case WM8962_EQ11:
case WM8962_EQ12:
case WM8962_EQ13:
case WM8962_EQ14:
case WM8962_EQ15:
case WM8962_EQ16:
case WM8962_EQ17:
case WM8962_EQ18:
case WM8962_EQ19:
case WM8962_EQ20:
case WM8962_EQ21:
case WM8962_EQ22:
case WM8962_EQ23:
case WM8962_EQ24:
case WM8962_EQ25:
case WM8962_EQ26:
case WM8962_EQ27:
case WM8962_EQ28:
case WM8962_EQ29:
case WM8962_EQ30:
case WM8962_EQ31:
case WM8962_EQ32:
case WM8962_EQ33:
case WM8962_EQ34:
case WM8962_EQ35:
case WM8962_EQ36:
case WM8962_EQ37:
case WM8962_EQ38:
case WM8962_EQ39:
case WM8962_EQ40:
case WM8962_EQ41:
case WM8962_GPIO_BASE:
case WM8962_GPIO_2:
case WM8962_GPIO_3:
case WM8962_GPIO_5:
case WM8962_GPIO_6:
case WM8962_INTERRUPT_STATUS_1:
case WM8962_INTERRUPT_STATUS_2:
case WM8962_INTERRUPT_STATUS_1_MASK:
case WM8962_INTERRUPT_STATUS_2_MASK:
case WM8962_INTERRUPT_CONTROL:
case WM8962_IRQ_DEBOUNCE:
case WM8962_MICINT_SOURCE_POL:
case WM8962_DSP2_POWER_MANAGEMENT:
case WM8962_DSP2_EXECCONTROL:
case WM8962_DSP2_INSTRUCTION_RAM_0:
case WM8962_DSP2_ADDRESS_RAM_2:
case WM8962_DSP2_ADDRESS_RAM_1:
case WM8962_DSP2_ADDRESS_RAM_0:
case WM8962_DSP2_DATA1_RAM_1:
case WM8962_DSP2_DATA1_RAM_0:
case WM8962_DSP2_DATA2_RAM_1:
case WM8962_DSP2_DATA2_RAM_0:
case WM8962_DSP2_DATA3_RAM_1:
case WM8962_DSP2_DATA3_RAM_0:
case WM8962_DSP2_COEFF_RAM_0:
case WM8962_RETUNEADC_SHARED_COEFF_1:
case WM8962_RETUNEADC_SHARED_COEFF_0:
case WM8962_RETUNEDAC_SHARED_COEFF_1:
case WM8962_RETUNEDAC_SHARED_COEFF_0:
case WM8962_SOUNDSTAGE_ENABLES_1:
case WM8962_SOUNDSTAGE_ENABLES_0:
case WM8962_HDBASS_AI_1:
case WM8962_HDBASS_AI_0:
case WM8962_HDBASS_AR_1:
case WM8962_HDBASS_AR_0:
case WM8962_HDBASS_B_1:
case WM8962_HDBASS_B_0:
case WM8962_HDBASS_K_1:
case WM8962_HDBASS_K_0:
case WM8962_HDBASS_N1_1:
case WM8962_HDBASS_N1_0:
case WM8962_HDBASS_N2_1:
case WM8962_HDBASS_N2_0:
case WM8962_HDBASS_N3_1:
case WM8962_HDBASS_N3_0:
case WM8962_HDBASS_N4_1:
case WM8962_HDBASS_N4_0:
case WM8962_HDBASS_N5_1:
case WM8962_HDBASS_N5_0:
case WM8962_HDBASS_X1_1:
case WM8962_HDBASS_X1_0:
case WM8962_HDBASS_X2_1:
case WM8962_HDBASS_X2_0:
case WM8962_HDBASS_X3_1:
case WM8962_HDBASS_X3_0:
case WM8962_HDBASS_ATK_1:
case WM8962_HDBASS_ATK_0:
case WM8962_HDBASS_DCY_1:
case WM8962_HDBASS_DCY_0:
case WM8962_HDBASS_PG_1:
case WM8962_HDBASS_PG_0:
case WM8962_HPF_C_1:
case WM8962_HPF_C_0:
case WM8962_ADCL_RETUNE_C1_1:
case WM8962_ADCL_RETUNE_C1_0:
case WM8962_ADCL_RETUNE_C2_1:
case WM8962_ADCL_RETUNE_C2_0:
case WM8962_ADCL_RETUNE_C3_1:
case WM8962_ADCL_RETUNE_C3_0:
case WM8962_ADCL_RETUNE_C4_1:
case WM8962_ADCL_RETUNE_C4_0:
case WM8962_ADCL_RETUNE_C5_1:
case WM8962_ADCL_RETUNE_C5_0:
case WM8962_ADCL_RETUNE_C6_1:
case WM8962_ADCL_RETUNE_C6_0:
case WM8962_ADCL_RETUNE_C7_1:
case WM8962_ADCL_RETUNE_C7_0:
case WM8962_ADCL_RETUNE_C8_1:
case WM8962_ADCL_RETUNE_C8_0:
case WM8962_ADCL_RETUNE_C9_1:
case WM8962_ADCL_RETUNE_C9_0:
case WM8962_ADCL_RETUNE_C10_1:
case WM8962_ADCL_RETUNE_C10_0:
case WM8962_ADCL_RETUNE_C11_1:
case WM8962_ADCL_RETUNE_C11_0:
case WM8962_ADCL_RETUNE_C12_1:
case WM8962_ADCL_RETUNE_C12_0:
case WM8962_ADCL_RETUNE_C13_1:
case WM8962_ADCL_RETUNE_C13_0:
case WM8962_ADCL_RETUNE_C14_1:
case WM8962_ADCL_RETUNE_C14_0:
case WM8962_ADCL_RETUNE_C15_1:
case WM8962_ADCL_RETUNE_C15_0:
case WM8962_ADCL_RETUNE_C16_1:
case WM8962_ADCL_RETUNE_C16_0:
case WM8962_ADCL_RETUNE_C17_1:
case WM8962_ADCL_RETUNE_C17_0:
case WM8962_ADCL_RETUNE_C18_1:
case WM8962_ADCL_RETUNE_C18_0:
case WM8962_ADCL_RETUNE_C19_1:
case WM8962_ADCL_RETUNE_C19_0:
case WM8962_ADCL_RETUNE_C20_1:
case WM8962_ADCL_RETUNE_C20_0:
case WM8962_ADCL_RETUNE_C21_1:
case WM8962_ADCL_RETUNE_C21_0:
case WM8962_ADCL_RETUNE_C22_1:
case WM8962_ADCL_RETUNE_C22_0:
case WM8962_ADCL_RETUNE_C23_1:
case WM8962_ADCL_RETUNE_C23_0:
case WM8962_ADCL_RETUNE_C24_1:
case WM8962_ADCL_RETUNE_C24_0:
case WM8962_ADCL_RETUNE_C25_1:
case WM8962_ADCL_RETUNE_C25_0:
case WM8962_ADCL_RETUNE_C26_1:
case WM8962_ADCL_RETUNE_C26_0:
case WM8962_ADCL_RETUNE_C27_1:
case WM8962_ADCL_RETUNE_C27_0:
case WM8962_ADCL_RETUNE_C28_1:
case WM8962_ADCL_RETUNE_C28_0:
case WM8962_ADCL_RETUNE_C29_1:
case WM8962_ADCL_RETUNE_C29_0:
case WM8962_ADCL_RETUNE_C30_1:
case WM8962_ADCL_RETUNE_C30_0:
case WM8962_ADCL_RETUNE_C31_1:
case WM8962_ADCL_RETUNE_C31_0:
case WM8962_ADCL_RETUNE_C32_1:
case WM8962_ADCL_RETUNE_C32_0:
case WM8962_RETUNEADC_PG2_1:
case WM8962_RETUNEADC_PG2_0:
case WM8962_RETUNEADC_PG_1:
case WM8962_RETUNEADC_PG_0:
case WM8962_ADCR_RETUNE_C1_1:
case WM8962_ADCR_RETUNE_C1_0:
case WM8962_ADCR_RETUNE_C2_1:
case WM8962_ADCR_RETUNE_C2_0:
case WM8962_ADCR_RETUNE_C3_1:
case WM8962_ADCR_RETUNE_C3_0:
case WM8962_ADCR_RETUNE_C4_1:
case WM8962_ADCR_RETUNE_C4_0:
case WM8962_ADCR_RETUNE_C5_1:
case WM8962_ADCR_RETUNE_C5_0:
case WM8962_ADCR_RETUNE_C6_1:
case WM8962_ADCR_RETUNE_C6_0:
case WM8962_ADCR_RETUNE_C7_1:
case WM8962_ADCR_RETUNE_C7_0:
case WM8962_ADCR_RETUNE_C8_1:
case WM8962_ADCR_RETUNE_C8_0:
case WM8962_ADCR_RETUNE_C9_1:
case WM8962_ADCR_RETUNE_C9_0:
case WM8962_ADCR_RETUNE_C10_1:
case WM8962_ADCR_RETUNE_C10_0:
case WM8962_ADCR_RETUNE_C11_1:
case WM8962_ADCR_RETUNE_C11_0:
case WM8962_ADCR_RETUNE_C12_1:
case WM8962_ADCR_RETUNE_C12_0:
case WM8962_ADCR_RETUNE_C13_1:
case WM8962_ADCR_RETUNE_C13_0:
case WM8962_ADCR_RETUNE_C14_1:
case WM8962_ADCR_RETUNE_C14_0:
case WM8962_ADCR_RETUNE_C15_1:
case WM8962_ADCR_RETUNE_C15_0:
case WM8962_ADCR_RETUNE_C16_1:
case WM8962_ADCR_RETUNE_C16_0:
case WM8962_ADCR_RETUNE_C17_1:
case WM8962_ADCR_RETUNE_C17_0:
case WM8962_ADCR_RETUNE_C18_1:
case WM8962_ADCR_RETUNE_C18_0:
case WM8962_ADCR_RETUNE_C19_1:
case WM8962_ADCR_RETUNE_C19_0:
case WM8962_ADCR_RETUNE_C20_1:
case WM8962_ADCR_RETUNE_C20_0:
case WM8962_ADCR_RETUNE_C21_1:
case WM8962_ADCR_RETUNE_C21_0:
case WM8962_ADCR_RETUNE_C22_1:
case WM8962_ADCR_RETUNE_C22_0:
case WM8962_ADCR_RETUNE_C23_1:
case WM8962_ADCR_RETUNE_C23_0:
case WM8962_ADCR_RETUNE_C24_1:
case WM8962_ADCR_RETUNE_C24_0:
case WM8962_ADCR_RETUNE_C25_1:
case WM8962_ADCR_RETUNE_C25_0:
case WM8962_ADCR_RETUNE_C26_1:
case WM8962_ADCR_RETUNE_C26_0:
case WM8962_ADCR_RETUNE_C27_1:
case WM8962_ADCR_RETUNE_C27_0:
case WM8962_ADCR_RETUNE_C28_1:
case WM8962_ADCR_RETUNE_C28_0:
case WM8962_ADCR_RETUNE_C29_1:
case WM8962_ADCR_RETUNE_C29_0:
case WM8962_ADCR_RETUNE_C30_1:
case WM8962_ADCR_RETUNE_C30_0:
case WM8962_ADCR_RETUNE_C31_1:
case WM8962_ADCR_RETUNE_C31_0:
case WM8962_ADCR_RETUNE_C32_1:
case WM8962_ADCR_RETUNE_C32_0:
case WM8962_DACL_RETUNE_C1_1:
case WM8962_DACL_RETUNE_C1_0:
case WM8962_DACL_RETUNE_C2_1:
case WM8962_DACL_RETUNE_C2_0:
case WM8962_DACL_RETUNE_C3_1:
case WM8962_DACL_RETUNE_C3_0:
case WM8962_DACL_RETUNE_C4_1:
case WM8962_DACL_RETUNE_C4_0:
case WM8962_DACL_RETUNE_C5_1:
case WM8962_DACL_RETUNE_C5_0:
case WM8962_DACL_RETUNE_C6_1:
case WM8962_DACL_RETUNE_C6_0:
case WM8962_DACL_RETUNE_C7_1:
case WM8962_DACL_RETUNE_C7_0:
case WM8962_DACL_RETUNE_C8_1:
case WM8962_DACL_RETUNE_C8_0:
case WM8962_DACL_RETUNE_C9_1:
case WM8962_DACL_RETUNE_C9_0:
case WM8962_DACL_RETUNE_C10_1:
case WM8962_DACL_RETUNE_C10_0:
case WM8962_DACL_RETUNE_C11_1:
case WM8962_DACL_RETUNE_C11_0:
case WM8962_DACL_RETUNE_C12_1:
case WM8962_DACL_RETUNE_C12_0:
case WM8962_DACL_RETUNE_C13_1:
case WM8962_DACL_RETUNE_C13_0:
case WM8962_DACL_RETUNE_C14_1:
case WM8962_DACL_RETUNE_C14_0:
case WM8962_DACL_RETUNE_C15_1:
case WM8962_DACL_RETUNE_C15_0:
case WM8962_DACL_RETUNE_C16_1:
case WM8962_DACL_RETUNE_C16_0:
case WM8962_DACL_RETUNE_C17_1:
case WM8962_DACL_RETUNE_C17_0:
case WM8962_DACL_RETUNE_C18_1:
case WM8962_DACL_RETUNE_C18_0:
case WM8962_DACL_RETUNE_C19_1:
case WM8962_DACL_RETUNE_C19_0:
case WM8962_DACL_RETUNE_C20_1:
case WM8962_DACL_RETUNE_C20_0:
case WM8962_DACL_RETUNE_C21_1:
case WM8962_DACL_RETUNE_C21_0:
case WM8962_DACL_RETUNE_C22_1:
case WM8962_DACL_RETUNE_C22_0:
case WM8962_DACL_RETUNE_C23_1:
case WM8962_DACL_RETUNE_C23_0:
case WM8962_DACL_RETUNE_C24_1:
case WM8962_DACL_RETUNE_C24_0:
case WM8962_DACL_RETUNE_C25_1:
case WM8962_DACL_RETUNE_C25_0:
case WM8962_DACL_RETUNE_C26_1:
case WM8962_DACL_RETUNE_C26_0:
case WM8962_DACL_RETUNE_C27_1:
case WM8962_DACL_RETUNE_C27_0:
case WM8962_DACL_RETUNE_C28_1:
case WM8962_DACL_RETUNE_C28_0:
case WM8962_DACL_RETUNE_C29_1:
case WM8962_DACL_RETUNE_C29_0:
case WM8962_DACL_RETUNE_C30_1:
case WM8962_DACL_RETUNE_C30_0:
case WM8962_DACL_RETUNE_C31_1:
case WM8962_DACL_RETUNE_C31_0:
case WM8962_DACL_RETUNE_C32_1:
case WM8962_DACL_RETUNE_C32_0:
case WM8962_RETUNEDAC_PG2_1:
case WM8962_RETUNEDAC_PG2_0:
case WM8962_RETUNEDAC_PG_1:
case WM8962_RETUNEDAC_PG_0:
case WM8962_DACR_RETUNE_C1_1:
case WM8962_DACR_RETUNE_C1_0:
case WM8962_DACR_RETUNE_C2_1:
case WM8962_DACR_RETUNE_C2_0:
case WM8962_DACR_RETUNE_C3_1:
case WM8962_DACR_RETUNE_C3_0:
case WM8962_DACR_RETUNE_C4_1:
case WM8962_DACR_RETUNE_C4_0:
case WM8962_DACR_RETUNE_C5_1:
case WM8962_DACR_RETUNE_C5_0:
case WM8962_DACR_RETUNE_C6_1:
case WM8962_DACR_RETUNE_C6_0:
case WM8962_DACR_RETUNE_C7_1:
case WM8962_DACR_RETUNE_C7_0:
case WM8962_DACR_RETUNE_C8_1:
case WM8962_DACR_RETUNE_C8_0:
case WM8962_DACR_RETUNE_C9_1:
case WM8962_DACR_RETUNE_C9_0:
case WM8962_DACR_RETUNE_C10_1:
case WM8962_DACR_RETUNE_C10_0:
case WM8962_DACR_RETUNE_C11_1:
case WM8962_DACR_RETUNE_C11_0:
case WM8962_DACR_RETUNE_C12_1:
case WM8962_DACR_RETUNE_C12_0:
case WM8962_DACR_RETUNE_C13_1:
case WM8962_DACR_RETUNE_C13_0:
case WM8962_DACR_RETUNE_C14_1:
case WM8962_DACR_RETUNE_C14_0:
case WM8962_DACR_RETUNE_C15_1:
case WM8962_DACR_RETUNE_C15_0:
case WM8962_DACR_RETUNE_C16_1:
case WM8962_DACR_RETUNE_C16_0:
case WM8962_DACR_RETUNE_C17_1:
case WM8962_DACR_RETUNE_C17_0:
case WM8962_DACR_RETUNE_C18_1:
case WM8962_DACR_RETUNE_C18_0:
case WM8962_DACR_RETUNE_C19_1:
case WM8962_DACR_RETUNE_C19_0:
case WM8962_DACR_RETUNE_C20_1:
case WM8962_DACR_RETUNE_C20_0:
case WM8962_DACR_RETUNE_C21_1:
case WM8962_DACR_RETUNE_C21_0:
case WM8962_DACR_RETUNE_C22_1:
case WM8962_DACR_RETUNE_C22_0:
case WM8962_DACR_RETUNE_C23_1:
case WM8962_DACR_RETUNE_C23_0:
case WM8962_DACR_RETUNE_C24_1:
case WM8962_DACR_RETUNE_C24_0:
case WM8962_DACR_RETUNE_C25_1:
case WM8962_DACR_RETUNE_C25_0:
case WM8962_DACR_RETUNE_C26_1:
case WM8962_DACR_RETUNE_C26_0:
case WM8962_DACR_RETUNE_C27_1:
case WM8962_DACR_RETUNE_C27_0:
case WM8962_DACR_RETUNE_C28_1:
case WM8962_DACR_RETUNE_C28_0:
case WM8962_DACR_RETUNE_C29_1:
case WM8962_DACR_RETUNE_C29_0:
case WM8962_DACR_RETUNE_C30_1:
case WM8962_DACR_RETUNE_C30_0:
case WM8962_DACR_RETUNE_C31_1:
case WM8962_DACR_RETUNE_C31_0:
case WM8962_DACR_RETUNE_C32_1:
case WM8962_DACR_RETUNE_C32_0:
case WM8962_VSS_XHD2_1:
case WM8962_VSS_XHD2_0:
case WM8962_VSS_XHD3_1:
case WM8962_VSS_XHD3_0:
case WM8962_VSS_XHN1_1:
case WM8962_VSS_XHN1_0:
case WM8962_VSS_XHN2_1:
case WM8962_VSS_XHN2_0:
case WM8962_VSS_XHN3_1:
case WM8962_VSS_XHN3_0:
case WM8962_VSS_XLA_1:
case WM8962_VSS_XLA_0:
case WM8962_VSS_XLB_1:
case WM8962_VSS_XLB_0:
case WM8962_VSS_XLG_1:
case WM8962_VSS_XLG_0:
case WM8962_VSS_PG2_1:
case WM8962_VSS_PG2_0:
case WM8962_VSS_PG_1:
case WM8962_VSS_PG_0:
case WM8962_VSS_XTD1_1:
case WM8962_VSS_XTD1_0:
case WM8962_VSS_XTD2_1:
case WM8962_VSS_XTD2_0:
case WM8962_VSS_XTD3_1:
case WM8962_VSS_XTD3_0:
case WM8962_VSS_XTD4_1:
case WM8962_VSS_XTD4_0:
case WM8962_VSS_XTD5_1:
case WM8962_VSS_XTD5_0:
case WM8962_VSS_XTD6_1:
case WM8962_VSS_XTD6_0:
case WM8962_VSS_XTD7_1:
case WM8962_VSS_XTD7_0:
case WM8962_VSS_XTD8_1:
case WM8962_VSS_XTD8_0:
case WM8962_VSS_XTD9_1:
case WM8962_VSS_XTD9_0:
case WM8962_VSS_XTD10_1:
case WM8962_VSS_XTD10_0:
case WM8962_VSS_XTD11_1:
case WM8962_VSS_XTD11_0:
case WM8962_VSS_XTD12_1:
case WM8962_VSS_XTD12_0:
case WM8962_VSS_XTD13_1:
case WM8962_VSS_XTD13_0:
case WM8962_VSS_XTD14_1:
case WM8962_VSS_XTD14_0:
case WM8962_VSS_XTD15_1:
case WM8962_VSS_XTD15_0:
case WM8962_VSS_XTD16_1:
case WM8962_VSS_XTD16_0:
case WM8962_VSS_XTD17_1:
case WM8962_VSS_XTD17_0:
case WM8962_VSS_XTD18_1:
case WM8962_VSS_XTD18_0:
case WM8962_VSS_XTD19_1:
case WM8962_VSS_XTD19_0:
case WM8962_VSS_XTD20_1:
case WM8962_VSS_XTD20_0:
case WM8962_VSS_XTD21_1:
case WM8962_VSS_XTD21_0:
case WM8962_VSS_XTD22_1:
case WM8962_VSS_XTD22_0:
case WM8962_VSS_XTD23_1:
case WM8962_VSS_XTD23_0:
case WM8962_VSS_XTD24_1:
case WM8962_VSS_XTD24_0:
case WM8962_VSS_XTD25_1:
case WM8962_VSS_XTD25_0:
case WM8962_VSS_XTD26_1:
case WM8962_VSS_XTD26_0:
case WM8962_VSS_XTD27_1:
case WM8962_VSS_XTD27_0:
case WM8962_VSS_XTD28_1:
case WM8962_VSS_XTD28_0:
case WM8962_VSS_XTD29_1:
case WM8962_VSS_XTD29_0:
case WM8962_VSS_XTD30_1:
case WM8962_VSS_XTD30_0:
case WM8962_VSS_XTD31_1:
case WM8962_VSS_XTD31_0:
case WM8962_VSS_XTD32_1:
case WM8962_VSS_XTD32_0:
case WM8962_VSS_XTS1_1:
case WM8962_VSS_XTS1_0:
case WM8962_VSS_XTS2_1:
case WM8962_VSS_XTS2_0:
case WM8962_VSS_XTS3_1:
case WM8962_VSS_XTS3_0:
case WM8962_VSS_XTS4_1:
case WM8962_VSS_XTS4_0:
case WM8962_VSS_XTS5_1:
case WM8962_VSS_XTS5_0:
case WM8962_VSS_XTS6_1:
case WM8962_VSS_XTS6_0:
case WM8962_VSS_XTS7_1:
case WM8962_VSS_XTS7_0:
case WM8962_VSS_XTS8_1:
case WM8962_VSS_XTS8_0:
case WM8962_VSS_XTS9_1:
case WM8962_VSS_XTS9_0:
case WM8962_VSS_XTS10_1:
case WM8962_VSS_XTS10_0:
case WM8962_VSS_XTS11_1:
case WM8962_VSS_XTS11_0:
case WM8962_VSS_XTS12_1:
case WM8962_VSS_XTS12_0:
case WM8962_VSS_XTS13_1:
case WM8962_VSS_XTS13_0:
case WM8962_VSS_XTS14_1:
case WM8962_VSS_XTS14_0:
case WM8962_VSS_XTS15_1:
case WM8962_VSS_XTS15_0:
case WM8962_VSS_XTS16_1:
case WM8962_VSS_XTS16_0:
case WM8962_VSS_XTS17_1:
case WM8962_VSS_XTS17_0:
case WM8962_VSS_XTS18_1:
case WM8962_VSS_XTS18_0:
case WM8962_VSS_XTS19_1:
case WM8962_VSS_XTS19_0:
case WM8962_VSS_XTS20_1:
case WM8962_VSS_XTS20_0:
case WM8962_VSS_XTS21_1:
case WM8962_VSS_XTS21_0:
case WM8962_VSS_XTS22_1:
case WM8962_VSS_XTS22_0:
case WM8962_VSS_XTS23_1:
case WM8962_VSS_XTS23_0:
case WM8962_VSS_XTS24_1:
case WM8962_VSS_XTS24_0:
case WM8962_VSS_XTS25_1:
case WM8962_VSS_XTS25_0:
case WM8962_VSS_XTS26_1:
case WM8962_VSS_XTS26_0:
case WM8962_VSS_XTS27_1:
case WM8962_VSS_XTS27_0:
case WM8962_VSS_XTS28_1:
case WM8962_VSS_XTS28_0:
case WM8962_VSS_XTS29_1:
case WM8962_VSS_XTS29_0:
case WM8962_VSS_XTS30_1:
case WM8962_VSS_XTS30_0:
case WM8962_VSS_XTS31_1:
case WM8962_VSS_XTS31_0:
case WM8962_VSS_XTS32_1:
case WM8962_VSS_XTS32_0:
return true;
default:
return false;
}
}
static int wm8962_reset(struct wm8962_priv *wm8962)
{
int ret;
ret = regmap_write(wm8962->regmap, WM8962_SOFTWARE_RESET, 0x6243);
if (ret != 0)
return ret;
return regmap_write(wm8962->regmap, WM8962_PLL_SOFTWARE_RESET, 0);
}
static int wm8962_dsp2_write_config(struct snd_soc_codec *codec)
{
return regcache_sync_region(codec->control_data,
WM8962_HDBASS_AI_1, WM8962_MAX_REGISTER);
}
static int wm8962_dsp2_set_enable(struct snd_soc_codec *codec, u16 val)
{
u16 adcl = snd_soc_read(codec, WM8962_LEFT_ADC_VOLUME);
u16 adcr = snd_soc_read(codec, WM8962_RIGHT_ADC_VOLUME);
u16 dac = snd_soc_read(codec, WM8962_ADC_DAC_CONTROL_1);
snd_soc_write(codec, WM8962_LEFT_ADC_VOLUME, 0);
snd_soc_write(codec, WM8962_RIGHT_ADC_VOLUME, WM8962_ADC_VU);
snd_soc_update_bits(codec, WM8962_ADC_DAC_CONTROL_1,
WM8962_DAC_MUTE, WM8962_DAC_MUTE);
snd_soc_write(codec, WM8962_SOUNDSTAGE_ENABLES_0, val);
snd_soc_write(codec, WM8962_LEFT_ADC_VOLUME, adcl);
snd_soc_write(codec, WM8962_RIGHT_ADC_VOLUME, adcr);
snd_soc_update_bits(codec, WM8962_ADC_DAC_CONTROL_1,
WM8962_DAC_MUTE, dac);
return 0;
}
static int wm8962_dsp2_start(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
wm8962_dsp2_write_config(codec);
snd_soc_write(codec, WM8962_DSP2_EXECCONTROL, WM8962_DSP2_RUNR);
wm8962_dsp2_set_enable(codec, wm8962->dsp2_ena);
return 0;
}
static int wm8962_dsp2_stop(struct snd_soc_codec *codec)
{
wm8962_dsp2_set_enable(codec, 0);
snd_soc_write(codec, WM8962_DSP2_EXECCONTROL, WM8962_DSP2_STOP);
return 0;
}
static int wm8962_dsp2_ena_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int wm8962_dsp2_ena_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int shift = kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = !!(wm8962->dsp2_ena & 1 << shift);
return 0;
}
static int wm8962_dsp2_ena_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int shift = kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int old = wm8962->dsp2_ena;
int ret = 0;
int dsp2_running = snd_soc_read(codec, WM8962_DSP2_POWER_MANAGEMENT) &
WM8962_DSP2_ENA;
mutex_lock(&codec->mutex);
if (ucontrol->value.integer.value[0])
wm8962->dsp2_ena |= 1 << shift;
else
wm8962->dsp2_ena &= ~(1 << shift);
if (wm8962->dsp2_ena == old)
goto out;
ret = 1;
if (dsp2_running) {
if (wm8962->dsp2_ena)
wm8962_dsp2_set_enable(codec, wm8962->dsp2_ena);
else
wm8962_dsp2_stop(codec);
}
out:
mutex_unlock(&codec->mutex);
return ret;
}
static int wm8962_put_hp_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
int ret;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret == 0)
return 0;
ret = snd_soc_read(codec, WM8962_PWR_MGMT_2);
if (ret & WM8962_HPOUTL_PGA_ENA) {
snd_soc_write(codec, WM8962_HPOUTL_VOLUME,
snd_soc_read(codec, WM8962_HPOUTL_VOLUME));
return 1;
}
if (ret & WM8962_HPOUTR_PGA_ENA)
snd_soc_write(codec, WM8962_HPOUTR_VOLUME,
snd_soc_read(codec, WM8962_HPOUTR_VOLUME));
return 1;
}
static int wm8962_put_spk_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
int ret;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret == 0)
return 0;
ret = snd_soc_read(codec, WM8962_PWR_MGMT_2);
if (ret & WM8962_SPKOUTL_PGA_ENA) {
snd_soc_write(codec, WM8962_SPKOUTL_VOLUME,
snd_soc_read(codec, WM8962_SPKOUTL_VOLUME));
return 1;
}
if (ret & WM8962_SPKOUTR_PGA_ENA)
snd_soc_write(codec, WM8962_SPKOUTR_VOLUME,
snd_soc_read(codec, WM8962_SPKOUTR_VOLUME));
return 1;
}
static int cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(5);
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static int hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
int timeout;
int reg;
int expected = (WM8962_DCS_STARTUP_DONE_HP1L |
WM8962_DCS_STARTUP_DONE_HP1R);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_ENA | WM8962_HP1R_ENA,
WM8962_HP1L_ENA | WM8962_HP1R_ENA);
udelay(20);
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_ENA_DLY | WM8962_HP1R_ENA_DLY,
WM8962_HP1L_ENA_DLY | WM8962_HP1R_ENA_DLY);
snd_soc_update_bits(codec, WM8962_DC_SERVO_1,
WM8962_HP1L_DCS_ENA | WM8962_HP1R_DCS_ENA |
WM8962_HP1L_DCS_STARTUP |
WM8962_HP1R_DCS_STARTUP,
WM8962_HP1L_DCS_ENA | WM8962_HP1R_DCS_ENA |
WM8962_HP1L_DCS_STARTUP |
WM8962_HP1R_DCS_STARTUP);
timeout = 0;
do {
msleep(1);
reg = snd_soc_read(codec, WM8962_DC_SERVO_6);
if (reg < 0) {
dev_err(codec->dev,
"Failed to read DCS status: %d\n",
reg);
continue;
}
dev_dbg(codec->dev, "DCS status: %x\n", reg);
} while (++timeout < 200 && (reg & expected) != expected);
if ((reg & expected) != expected)
dev_err(codec->dev, "DC servo timed out\n");
else
dev_dbg(codec->dev, "DC servo complete after %dms\n",
timeout);
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_ENA_OUTP |
WM8962_HP1R_ENA_OUTP,
WM8962_HP1L_ENA_OUTP |
WM8962_HP1R_ENA_OUTP);
udelay(20);
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_RMV_SHORT |
WM8962_HP1R_RMV_SHORT,
WM8962_HP1L_RMV_SHORT |
WM8962_HP1R_RMV_SHORT);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_RMV_SHORT |
WM8962_HP1R_RMV_SHORT, 0);
udelay(20);
snd_soc_update_bits(codec, WM8962_DC_SERVO_1,
WM8962_HP1L_DCS_ENA | WM8962_HP1R_DCS_ENA |
WM8962_HP1L_DCS_STARTUP |
WM8962_HP1R_DCS_STARTUP,
0);
snd_soc_update_bits(codec, WM8962_ANALOGUE_HP_0,
WM8962_HP1L_ENA | WM8962_HP1R_ENA |
WM8962_HP1L_ENA_DLY | WM8962_HP1R_ENA_DLY |
WM8962_HP1L_ENA_OUTP |
WM8962_HP1R_ENA_OUTP, 0);
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static int out_pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
int reg;
switch (w->shift) {
case WM8962_HPOUTR_PGA_ENA_SHIFT:
reg = WM8962_HPOUTR_VOLUME;
break;
case WM8962_HPOUTL_PGA_ENA_SHIFT:
reg = WM8962_HPOUTL_VOLUME;
break;
case WM8962_SPKOUTR_PGA_ENA_SHIFT:
reg = WM8962_SPKOUTR_VOLUME;
break;
case WM8962_SPKOUTL_PGA_ENA_SHIFT:
reg = WM8962_SPKOUTL_VOLUME;
break;
default:
BUG();
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
return snd_soc_write(codec, reg, snd_soc_read(codec, reg));
default:
BUG();
return -EINVAL;
}
}
static int dsp2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (wm8962->dsp2_ena)
wm8962_dsp2_start(codec);
break;
case SND_SOC_DAPM_PRE_PMD:
if (wm8962->dsp2_ena)
wm8962_dsp2_stop(codec);
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static int wm8962_add_widgets(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
struct wm8962_pdata *pdata = &wm8962->pdata;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_add_codec_controls(codec, wm8962_snd_controls,
ARRAY_SIZE(wm8962_snd_controls));
if (pdata->spk_mono)
snd_soc_add_codec_controls(codec, wm8962_spk_mono_controls,
ARRAY_SIZE(wm8962_spk_mono_controls));
else
snd_soc_add_codec_controls(codec, wm8962_spk_stereo_controls,
ARRAY_SIZE(wm8962_spk_stereo_controls));
snd_soc_dapm_new_controls(dapm, wm8962_dapm_widgets,
ARRAY_SIZE(wm8962_dapm_widgets));
if (pdata->spk_mono)
snd_soc_dapm_new_controls(dapm, wm8962_dapm_spk_mono_widgets,
ARRAY_SIZE(wm8962_dapm_spk_mono_widgets));
else
snd_soc_dapm_new_controls(dapm, wm8962_dapm_spk_stereo_widgets,
ARRAY_SIZE(wm8962_dapm_spk_stereo_widgets));
snd_soc_dapm_add_routes(dapm, wm8962_intercon,
ARRAY_SIZE(wm8962_intercon));
if (pdata->spk_mono)
snd_soc_dapm_add_routes(dapm, wm8962_spk_mono_intercon,
ARRAY_SIZE(wm8962_spk_mono_intercon));
else
snd_soc_dapm_add_routes(dapm, wm8962_spk_stereo_intercon,
ARRAY_SIZE(wm8962_spk_stereo_intercon));
snd_soc_dapm_disable_pin(dapm, "Beep");
return 0;
}
static void wm8962_configure_bclk(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int dspclk, i;
int clocking2 = 0;
int clocking4 = 0;
int aif2 = 0;
if (!wm8962->sysclk_rate) {
dev_dbg(codec->dev, "No SYSCLK configured\n");
return;
}
if (!wm8962->bclk || !wm8962->lrclk) {
dev_dbg(codec->dev, "No audio clocks configured\n");
return;
}
for (i = 0; i < ARRAY_SIZE(sysclk_rates); i++) {
if (sysclk_rates[i] == wm8962->sysclk_rate / wm8962->lrclk) {
clocking4 |= i << WM8962_SYSCLK_RATE_SHIFT;
break;
}
}
if (i == ARRAY_SIZE(sysclk_rates)) {
dev_err(codec->dev, "Unsupported sysclk ratio %d\n",
wm8962->sysclk_rate / wm8962->lrclk);
return;
}
dev_dbg(codec->dev, "Selected sysclk ratio %d\n", sysclk_rates[i]);
snd_soc_update_bits(codec, WM8962_CLOCKING_4,
WM8962_SYSCLK_RATE_MASK, clocking4);
dspclk = snd_soc_read(codec, WM8962_CLOCKING1);
if (dspclk < 0) {
dev_err(codec->dev, "Failed to read DSPCLK: %d\n", dspclk);
return;
}
dspclk = (dspclk & WM8962_DSPCLK_DIV_MASK) >> WM8962_DSPCLK_DIV_SHIFT;
switch (dspclk) {
case 0:
dspclk = wm8962->sysclk_rate;
break;
case 1:
dspclk = wm8962->sysclk_rate / 2;
break;
case 2:
dspclk = wm8962->sysclk_rate / 4;
break;
default:
dev_warn(codec->dev, "Unknown DSPCLK divisor read back\n");
dspclk = wm8962->sysclk;
}
dev_dbg(codec->dev, "DSPCLK is %dHz, BCLK %d\n", dspclk, wm8962->bclk);
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
if (bclk_divs[i] < 0)
continue;
if (dspclk / bclk_divs[i] == wm8962->bclk) {
dev_dbg(codec->dev, "Selected BCLK_DIV %d for %dHz\n",
bclk_divs[i], wm8962->bclk);
clocking2 |= i;
break;
}
}
if (i == ARRAY_SIZE(bclk_divs)) {
dev_err(codec->dev, "Unsupported BCLK ratio %d\n",
dspclk / wm8962->bclk);
return;
}
aif2 |= wm8962->bclk / wm8962->lrclk;
dev_dbg(codec->dev, "Selected LRCLK divisor %d for %dHz\n",
wm8962->bclk / wm8962->lrclk, wm8962->lrclk);
snd_soc_update_bits(codec, WM8962_CLOCKING2,
WM8962_BCLK_DIV_MASK, clocking2);
snd_soc_update_bits(codec, WM8962_AUDIO_INTERFACE_2,
WM8962_AIF_RATE_MASK, aif2);
}
static int wm8962_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
if (level == codec->dapm.bias_level)
return 0;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8962_PWR_MGMT_1,
WM8962_VMID_SEL_MASK, 0x80);
wm8962_configure_bclk(codec);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, WM8962_PWR_MGMT_1,
WM8962_VMID_SEL_MASK, 0x100);
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
msleep(100);
break;
case SND_SOC_BIAS_OFF:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8962_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int i;
int aif0 = 0;
int adctl3 = 0;
wm8962->bclk = snd_soc_params_to_bclk(params);
if (params_channels(params) == 1)
wm8962->bclk *= 2;
wm8962->lrclk = params_rate(params);
for (i = 0; i < ARRAY_SIZE(sr_vals); i++) {
if (sr_vals[i].rate == wm8962->lrclk) {
adctl3 |= sr_vals[i].reg;
break;
}
}
if (i == ARRAY_SIZE(sr_vals)) {
dev_err(codec->dev, "Unsupported rate %dHz\n", wm8962->lrclk);
return -EINVAL;
}
if (wm8962->lrclk % 8000 == 0)
adctl3 |= WM8962_SAMPLE_RATE_INT_MODE;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
aif0 |= 0x4;
break;
case SNDRV_PCM_FORMAT_S24_LE:
aif0 |= 0x8;
break;
case SNDRV_PCM_FORMAT_S32_LE:
aif0 |= 0xc;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8962_AUDIO_INTERFACE_0,
WM8962_WL_MASK, aif0);
snd_soc_update_bits(codec, WM8962_ADDITIONAL_CONTROL_3,
WM8962_SAMPLE_RATE_INT_MODE |
WM8962_SAMPLE_RATE_MASK, adctl3);
dev_dbg(codec->dev, "hw_params set BCLK %dHz LRCLK %dHz\n",
wm8962->bclk, wm8962->lrclk);
if (codec->dapm.bias_level == SND_SOC_BIAS_ON)
wm8962_configure_bclk(codec);
return 0;
}
static int wm8962_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int src;
switch (clk_id) {
case WM8962_SYSCLK_MCLK:
wm8962->sysclk = WM8962_SYSCLK_MCLK;
src = 0;
break;
case WM8962_SYSCLK_FLL:
wm8962->sysclk = WM8962_SYSCLK_FLL;
src = 1 << WM8962_SYSCLK_SRC_SHIFT;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8962_CLOCKING2, WM8962_SYSCLK_SRC_MASK,
src);
wm8962->sysclk_rate = freq;
wm8962_configure_bclk(codec);
return 0;
}
static int wm8962_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int aif0 = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif0 |= WM8962_LRCLK_INV | 3;
case SND_SOC_DAIFMT_DSP_A:
aif0 |= 3;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
case SND_SOC_DAIFMT_IB_NF:
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif0 |= 1;
break;
case SND_SOC_DAIFMT_I2S:
aif0 |= 2;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif0 |= WM8962_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif0 |= WM8962_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
aif0 |= WM8962_BCLK_INV | WM8962_LRCLK_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
aif0 |= WM8962_MSTR;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8962_AUDIO_INTERFACE_0,
WM8962_FMT_MASK | WM8962_BCLK_INV | WM8962_MSTR |
WM8962_LRCLK_INV, aif0);
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
unsigned int target;
unsigned int div;
unsigned int fratio, gcd_fll;
int i;
div = 1;
fll_div->fll_refclk_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_refclk_div++;
if (div > 4) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
pr_debug("FLL Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
div = 2;
while (Fout * div < 90000000) {
div++;
if (div > 64) {
pr_err("Unable to find FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * div;
fll_div->fll_outdiv = div - 1;
pr_debug("FLL Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
fratio = fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
fll_div->n = target / (fratio * Fref);
if (target % Fref == 0) {
fll_div->theta = 0;
fll_div->lambda = 0;
} else {
gcd_fll = gcd(target, fratio * Fref);
fll_div->theta = (target - (fll_div->n * fratio * Fref))
/ gcd_fll;
fll_div->lambda = (fratio * Fref) / gcd_fll;
}
pr_debug("FLL N=%x THETA=%x LAMBDA=%x\n",
fll_div->n, fll_div->theta, fll_div->lambda);
pr_debug("FLL_FRATIO=%x FLL_OUTDIV=%x FLL_REFCLK_DIV=%x\n",
fll_div->fll_fratio, fll_div->fll_outdiv,
fll_div->fll_refclk_div);
return 0;
}
static int wm8962_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
struct _fll_div fll_div;
unsigned long timeout;
int ret;
int fll1 = 0;
if (source == wm8962->fll_src && Fref == wm8962->fll_fref &&
Fout == wm8962->fll_fout)
return 0;
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm8962->fll_fref = 0;
wm8962->fll_fout = 0;
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_1,
WM8962_FLL_ENA, 0);
pm_runtime_put(codec->dev);
return 0;
}
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_1, WM8962_FLL_ENA, 0);
switch (fll_id) {
case WM8962_FLL_MCLK:
case WM8962_FLL_BCLK:
case WM8962_FLL_OSC:
fll1 |= (fll_id - 1) << WM8962_FLL_REFCLK_SRC_SHIFT;
break;
case WM8962_FLL_INT:
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_1,
WM8962_FLL_OSC_ENA, WM8962_FLL_OSC_ENA);
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_5,
WM8962_FLL_FRC_NCO, WM8962_FLL_FRC_NCO);
break;
default:
dev_err(codec->dev, "Unknown FLL source %d\n", ret);
return -EINVAL;
}
if (fll_div.theta || fll_div.lambda)
fll1 |= WM8962_FLL_FRAC;
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_1, WM8962_FLL_ENA, 0);
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_2,
WM8962_FLL_OUTDIV_MASK |
WM8962_FLL_REFCLK_DIV_MASK,
(fll_div.fll_outdiv << WM8962_FLL_OUTDIV_SHIFT) |
(fll_div.fll_refclk_div));
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_3,
WM8962_FLL_FRATIO_MASK, fll_div.fll_fratio);
snd_soc_write(codec, WM8962_FLL_CONTROL_6, fll_div.theta);
snd_soc_write(codec, WM8962_FLL_CONTROL_7, fll_div.lambda);
snd_soc_write(codec, WM8962_FLL_CONTROL_8, fll_div.n);
try_wait_for_completion(&wm8962->fll_lock);
pm_runtime_get_sync(codec->dev);
snd_soc_update_bits(codec, WM8962_FLL_CONTROL_1,
WM8962_FLL_FRAC | WM8962_FLL_REFCLK_SRC_MASK |
WM8962_FLL_ENA, fll1 | WM8962_FLL_ENA);
dev_dbg(codec->dev, "FLL configured for %dHz->%dHz\n", Fref, Fout);
ret = 0;
if (wm8962->irq)
timeout = msecs_to_jiffies(5);
else
timeout = msecs_to_jiffies(1);
timeout = wait_for_completion_timeout(&wm8962->fll_lock,
timeout);
if (timeout == 0 && wm8962->irq) {
dev_err(codec->dev, "FLL lock timed out");
ret = -ETIMEDOUT;
}
wm8962->fll_fref = Fref;
wm8962->fll_fout = Fout;
wm8962->fll_src = source;
return ret;
}
static int wm8962_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int val;
if (mute)
val = WM8962_DAC_MUTE;
else
val = 0;
return snd_soc_update_bits(codec, WM8962_ADC_DAC_CONTROL_1,
WM8962_DAC_MUTE, val);
}
static void wm8962_mic_work(struct work_struct *work)
{
struct wm8962_priv *wm8962 = container_of(work,
struct wm8962_priv,
mic_work.work);
struct snd_soc_codec *codec = wm8962->codec;
int status = 0;
int irq_pol = 0;
int reg;
reg = snd_soc_read(codec, WM8962_ADDITIONAL_CONTROL_4);
if (reg & WM8962_MICDET_STS) {
status |= SND_JACK_MICROPHONE;
irq_pol |= WM8962_MICD_IRQ_POL;
}
if (reg & WM8962_MICSHORT_STS) {
status |= SND_JACK_BTN_0;
irq_pol |= WM8962_MICSCD_IRQ_POL;
}
snd_soc_jack_report(wm8962->jack, status,
SND_JACK_MICROPHONE | SND_JACK_BTN_0);
snd_soc_update_bits(codec, WM8962_MICINT_SOURCE_POL,
WM8962_MICSCD_IRQ_POL |
WM8962_MICD_IRQ_POL, irq_pol);
}
static irqreturn_t wm8962_irq(int irq, void *data)
{
struct device *dev = data;
struct wm8962_priv *wm8962 = dev_get_drvdata(dev);
unsigned int mask;
unsigned int active;
int reg, ret;
ret = regmap_read(wm8962->regmap, WM8962_INTERRUPT_STATUS_2_MASK,
&mask);
if (ret != 0) {
dev_err(dev, "Failed to read interrupt mask: %d\n",
ret);
return IRQ_NONE;
}
ret = regmap_read(wm8962->regmap, WM8962_INTERRUPT_STATUS_2, &active);
if (ret != 0) {
dev_err(dev, "Failed to read interrupt: %d\n", ret);
return IRQ_NONE;
}
active &= ~mask;
if (!active)
return IRQ_NONE;
ret = regmap_write(wm8962->regmap, WM8962_INTERRUPT_STATUS_2, active);
if (ret != 0)
dev_warn(dev, "Failed to ack interrupt: %d\n", ret);
if (active & WM8962_FLL_LOCK_EINT) {
dev_dbg(dev, "FLL locked\n");
complete(&wm8962->fll_lock);
}
if (active & WM8962_FIFOS_ERR_EINT)
dev_err(dev, "FIFO error\n");
if (active & WM8962_TEMP_SHUT_EINT) {
dev_crit(dev, "Thermal shutdown\n");
ret = regmap_read(wm8962->regmap,
WM8962_THERMAL_SHUTDOWN_STATUS, &reg);
if (ret != 0) {
dev_warn(dev, "Failed to read thermal status: %d\n",
ret);
reg = 0;
}
if (reg & WM8962_TEMP_ERR_HP)
dev_crit(dev, "Headphone thermal error\n");
if (reg & WM8962_TEMP_WARN_HP)
dev_crit(dev, "Headphone thermal warning\n");
if (reg & WM8962_TEMP_ERR_SPK)
dev_crit(dev, "Speaker thermal error\n");
if (reg & WM8962_TEMP_WARN_SPK)
dev_crit(dev, "Speaker thermal warning\n");
}
if (active & (WM8962_MICSCD_EINT | WM8962_MICD_EINT)) {
dev_dbg(dev, "Microphone event detected\n");
#ifndef CONFIG_SND_SOC_WM8962_MODULE
trace_snd_soc_jack_irq(dev_name(dev));
#endif
pm_wakeup_event(dev, 300);
schedule_delayed_work(&wm8962->mic_work,
msecs_to_jiffies(250));
}
return IRQ_HANDLED;
}
int wm8962_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int irq_mask, enable;
wm8962->jack = jack;
if (jack) {
irq_mask = 0;
enable = WM8962_MICDET_ENA;
} else {
irq_mask = WM8962_MICD_EINT | WM8962_MICSCD_EINT;
enable = 0;
}
snd_soc_update_bits(codec, WM8962_INTERRUPT_STATUS_2_MASK,
WM8962_MICD_EINT | WM8962_MICSCD_EINT, irq_mask);
snd_soc_update_bits(codec, WM8962_ADDITIONAL_CONTROL_4,
WM8962_MICDET_ENA, enable);
snd_soc_jack_report(wm8962->jack, 0,
SND_JACK_MICROPHONE | SND_JACK_BTN_0);
if (jack) {
snd_soc_dapm_force_enable_pin(&codec->dapm, "SYSCLK");
snd_soc_dapm_force_enable_pin(&codec->dapm, "MICBIAS");
} else {
snd_soc_dapm_disable_pin(&codec->dapm, "SYSCLK");
snd_soc_dapm_disable_pin(&codec->dapm, "MICBIAS");
}
return 0;
}
static void wm8962_beep_work(struct work_struct *work)
{
struct wm8962_priv *wm8962 =
container_of(work, struct wm8962_priv, beep_work);
struct snd_soc_codec *codec = wm8962->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int i;
int reg = 0;
int best = 0;
if (wm8962->beep_rate) {
for (i = 0; i < ARRAY_SIZE(beep_rates); i++) {
if (abs(wm8962->beep_rate - beep_rates[i]) <
abs(wm8962->beep_rate - beep_rates[best]))
best = i;
}
dev_dbg(codec->dev, "Set beep rate %dHz for requested %dHz\n",
beep_rates[best], wm8962->beep_rate);
reg = WM8962_BEEP_ENA | (best << WM8962_BEEP_RATE_SHIFT);
snd_soc_dapm_enable_pin(dapm, "Beep");
} else {
dev_dbg(codec->dev, "Disabling beep\n");
snd_soc_dapm_disable_pin(dapm, "Beep");
}
snd_soc_update_bits(codec, WM8962_BEEP_GENERATOR_1,
WM8962_BEEP_ENA | WM8962_BEEP_RATE_MASK, reg);
snd_soc_dapm_sync(dapm);
}
static int wm8962_beep_event(struct input_dev *dev, unsigned int type,
unsigned int code, int hz)
{
struct snd_soc_codec *codec = input_get_drvdata(dev);
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "Beep event %x %x\n", code, hz);
switch (code) {
case SND_BELL:
if (hz)
hz = 1000;
case SND_TONE:
break;
default:
return -1;
}
wm8962->beep_rate = hz;
schedule_work(&wm8962->beep_work);
return 0;
}
static ssize_t wm8962_beep_set(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct wm8962_priv *wm8962 = dev_get_drvdata(dev);
long int time;
int ret;
ret = strict_strtol(buf, 10, &time);
if (ret != 0)
return ret;
input_event(wm8962->beep, EV_SND, SND_TONE, time);
return count;
}
static void wm8962_init_beep(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int ret;
wm8962->beep = devm_input_allocate_device(codec->dev);
if (!wm8962->beep) {
dev_err(codec->dev, "Failed to allocate beep device\n");
return;
}
INIT_WORK(&wm8962->beep_work, wm8962_beep_work);
wm8962->beep_rate = 0;
wm8962->beep->name = "WM8962 Beep Generator";
wm8962->beep->phys = dev_name(codec->dev);
wm8962->beep->id.bustype = BUS_I2C;
wm8962->beep->evbit[0] = BIT_MASK(EV_SND);
wm8962->beep->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
wm8962->beep->event = wm8962_beep_event;
wm8962->beep->dev.parent = codec->dev;
input_set_drvdata(wm8962->beep, codec);
ret = input_register_device(wm8962->beep);
if (ret != 0) {
wm8962->beep = NULL;
dev_err(codec->dev, "Failed to register beep device\n");
}
ret = device_create_file(codec->dev, &dev_attr_beep);
if (ret != 0) {
dev_err(codec->dev, "Failed to create keyclick file: %d\n",
ret);
}
}
static void wm8962_free_beep(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
device_remove_file(codec->dev, &dev_attr_beep);
cancel_work_sync(&wm8962->beep_work);
wm8962->beep = NULL;
snd_soc_update_bits(codec, WM8962_BEEP_GENERATOR_1, WM8962_BEEP_ENA,0);
}
static void wm8962_init_beep(struct snd_soc_codec *codec)
{
}
static void wm8962_free_beep(struct snd_soc_codec *codec)
{
}
static void wm8962_set_gpio_mode(struct snd_soc_codec *codec, int gpio)
{
int mask = 0;
int val = 0;
switch (gpio) {
case 2:
mask = WM8962_CLKOUT2_SEL_MASK;
val = 1 << WM8962_CLKOUT2_SEL_SHIFT;
break;
case 3:
mask = WM8962_CLKOUT3_SEL_MASK;
val = 1 << WM8962_CLKOUT3_SEL_SHIFT;
break;
default:
break;
}
if (mask)
snd_soc_update_bits(codec, WM8962_ANALOGUE_CLOCKING1,
mask, val);
}
static inline struct wm8962_priv *gpio_to_wm8962(struct gpio_chip *chip)
{
return container_of(chip, struct wm8962_priv, gpio_chip);
}
static int wm8962_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct wm8962_priv *wm8962 = gpio_to_wm8962(chip);
struct snd_soc_codec *codec = wm8962->codec;
switch (offset + 1) {
case 2:
case 3:
case 5:
case 6:
break;
default:
return -EINVAL;
}
wm8962_set_gpio_mode(codec, offset + 1);
return 0;
}
static void wm8962_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct wm8962_priv *wm8962 = gpio_to_wm8962(chip);
struct snd_soc_codec *codec = wm8962->codec;
snd_soc_update_bits(codec, WM8962_GPIO_BASE + offset,
WM8962_GP2_LVL, !!value << WM8962_GP2_LVL_SHIFT);
}
static int wm8962_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct wm8962_priv *wm8962 = gpio_to_wm8962(chip);
struct snd_soc_codec *codec = wm8962->codec;
int ret, val;
val = (1 << WM8962_GP2_FN_SHIFT) | (value << WM8962_GP2_LVL_SHIFT);
ret = snd_soc_update_bits(codec, WM8962_GPIO_BASE + offset,
WM8962_GP2_FN_MASK | WM8962_GP2_LVL, val);
if (ret < 0)
return ret;
return 0;
}
static void wm8962_init_gpio(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
struct wm8962_pdata *pdata = &wm8962->pdata;
int ret;
wm8962->gpio_chip = wm8962_template_chip;
wm8962->gpio_chip.ngpio = WM8962_MAX_GPIO;
wm8962->gpio_chip.dev = codec->dev;
if (pdata->gpio_base)
wm8962->gpio_chip.base = pdata->gpio_base;
else
wm8962->gpio_chip.base = -1;
ret = gpiochip_add(&wm8962->gpio_chip);
if (ret != 0)
dev_err(codec->dev, "Failed to add GPIOs: %d\n", ret);
}
static void wm8962_free_gpio(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = gpiochip_remove(&wm8962->gpio_chip);
if (ret != 0)
dev_err(codec->dev, "Failed to remove GPIOs: %d\n", ret);
}
static void wm8962_init_gpio(struct snd_soc_codec *codec)
{
}
static void wm8962_free_gpio(struct snd_soc_codec *codec)
{
}
static int wm8962_probe(struct snd_soc_codec *codec)
{
int ret;
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
struct wm8962_pdata *pdata = &wm8962->pdata;
int i, trigger, irq_pol;
bool dmicclk, dmicdat;
wm8962->codec = codec;
codec->control_data = wm8962->regmap;
ret = snd_soc_codec_set_cache_io(codec, 16, 16, SND_SOC_REGMAP);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
wm8962->disable_nb[0].notifier_call = wm8962_regulator_event_0;
wm8962->disable_nb[1].notifier_call = wm8962_regulator_event_1;
wm8962->disable_nb[2].notifier_call = wm8962_regulator_event_2;
wm8962->disable_nb[3].notifier_call = wm8962_regulator_event_3;
wm8962->disable_nb[4].notifier_call = wm8962_regulator_event_4;
wm8962->disable_nb[5].notifier_call = wm8962_regulator_event_5;
wm8962->disable_nb[6].notifier_call = wm8962_regulator_event_6;
wm8962->disable_nb[7].notifier_call = wm8962_regulator_event_7;
for (i = 0; i < ARRAY_SIZE(wm8962->supplies); i++) {
ret = regulator_register_notifier(wm8962->supplies[i].consumer,
&wm8962->disable_nb[i]);
if (ret != 0) {
dev_err(codec->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
snd_soc_update_bits(codec, WM8962_CLOCKING2, WM8962_SYSCLK_ENA, 0);
snd_soc_update_bits(codec, WM8962_CLOCKING2,
WM8962_CLKREG_OVD, WM8962_CLKREG_OVD);
snd_soc_update_bits(codec, WM8962_PLL2,
WM8962_OSC_ENA | WM8962_PLL2_ENA | WM8962_PLL3_ENA,
0);
for (i = 0; i < ARRAY_SIZE(pdata->gpio_init); i++)
if (pdata->gpio_init[i]) {
wm8962_set_gpio_mode(codec, i + 1);
snd_soc_write(codec, 0x200 + i,
pdata->gpio_init[i] & 0xffff);
}
if (pdata->spk_mono)
snd_soc_update_bits(codec, WM8962_CLASS_D_CONTROL_2,
WM8962_SPK_MONO_MASK, WM8962_SPK_MONO);
if (pdata->mic_cfg)
snd_soc_update_bits(codec, WM8962_ADDITIONAL_CONTROL_4,
WM8962_MICDET_ENA |
WM8962_MICDET_THR_MASK |
WM8962_MICSHORT_THR_MASK |
WM8962_MICBIAS_LVL,
pdata->mic_cfg);
snd_soc_update_bits(codec, WM8962_LEFT_INPUT_VOLUME,
WM8962_IN_VU, WM8962_IN_VU);
snd_soc_update_bits(codec, WM8962_RIGHT_INPUT_VOLUME,
WM8962_IN_VU, WM8962_IN_VU);
snd_soc_update_bits(codec, WM8962_LEFT_ADC_VOLUME,
WM8962_ADC_VU, WM8962_ADC_VU);
snd_soc_update_bits(codec, WM8962_RIGHT_ADC_VOLUME,
WM8962_ADC_VU, WM8962_ADC_VU);
snd_soc_update_bits(codec, WM8962_LEFT_DAC_VOLUME,
WM8962_DAC_VU, WM8962_DAC_VU);
snd_soc_update_bits(codec, WM8962_RIGHT_DAC_VOLUME,
WM8962_DAC_VU, WM8962_DAC_VU);
snd_soc_update_bits(codec, WM8962_SPKOUTL_VOLUME,
WM8962_SPKOUT_VU, WM8962_SPKOUT_VU);
snd_soc_update_bits(codec, WM8962_SPKOUTR_VOLUME,
WM8962_SPKOUT_VU, WM8962_SPKOUT_VU);
snd_soc_update_bits(codec, WM8962_HPOUTL_VOLUME,
WM8962_HPOUT_VU, WM8962_HPOUT_VU);
snd_soc_update_bits(codec, WM8962_HPOUTR_VOLUME,
WM8962_HPOUT_VU, WM8962_HPOUT_VU);
snd_soc_update_bits(codec, WM8962_EQ1, WM8962_EQ_SHARED_COEFF, 0);
snd_soc_update_bits(codec, WM8962_IRQ_DEBOUNCE,
WM8962_FLL_LOCK_DB | WM8962_PLL3_LOCK_DB |
WM8962_PLL2_LOCK_DB | WM8962_TEMP_SHUT_DB,
0);
wm8962_add_widgets(codec);
dmicclk = false;
dmicdat = false;
for (i = 0; i < WM8962_MAX_GPIO; i++) {
switch (snd_soc_read(codec, WM8962_GPIO_BASE + i)
& WM8962_GP2_FN_MASK) {
case WM8962_GPIO_FN_DMICCLK:
dmicclk = true;
break;
case WM8962_GPIO_FN_DMICDAT:
dmicdat = true;
break;
default:
break;
}
}
if (!dmicclk || !dmicdat) {
dev_dbg(codec->dev, "DMIC not in use, disabling\n");
snd_soc_dapm_nc_pin(&codec->dapm, "DMICDAT");
}
if (dmicclk != dmicdat)
dev_warn(codec->dev, "DMIC GPIOs partially configured\n");
wm8962_init_beep(codec);
wm8962_init_gpio(codec);
if (wm8962->irq) {
if (pdata->irq_active_low) {
trigger = IRQF_TRIGGER_LOW;
irq_pol = WM8962_IRQ_POL;
} else {
trigger = IRQF_TRIGGER_HIGH;
irq_pol = 0;
}
snd_soc_update_bits(codec, WM8962_INTERRUPT_CONTROL,
WM8962_IRQ_POL, irq_pol);
ret = request_threaded_irq(wm8962->irq, NULL, wm8962_irq,
trigger | IRQF_ONESHOT,
"wm8962", codec->dev);
if (ret != 0) {
dev_err(codec->dev, "Failed to request IRQ %d: %d\n",
wm8962->irq, ret);
wm8962->irq = 0;
} else {
snd_soc_update_bits(codec,
WM8962_INTERRUPT_STATUS_2_MASK,
WM8962_FLL_LOCK_EINT |
WM8962_TEMP_SHUT_EINT |
WM8962_FIFOS_ERR_EINT, 0);
}
}
return 0;
}
static int wm8962_remove(struct snd_soc_codec *codec)
{
struct wm8962_priv *wm8962 = snd_soc_codec_get_drvdata(codec);
int i;
if (wm8962->irq)
free_irq(wm8962->irq, codec);
cancel_delayed_work_sync(&wm8962->mic_work);
wm8962_free_gpio(codec);
wm8962_free_beep(codec);
for (i = 0; i < ARRAY_SIZE(wm8962->supplies); i++)
regulator_unregister_notifier(wm8962->supplies[i].consumer,
&wm8962->disable_nb[i]);
return 0;
}
static int wm8962_set_pdata_from_of(struct i2c_client *i2c,
struct wm8962_pdata *pdata)
{
const struct device_node *np = i2c->dev.of_node;
u32 val32;
int i;
if (of_property_read_bool(np, "spk-mono"))
pdata->spk_mono = true;
if (of_property_read_u32(np, "mic-cfg", &val32) >= 0)
pdata->mic_cfg = val32;
if (of_property_read_u32_array(np, "gpio-cfg", pdata->gpio_init,
ARRAY_SIZE(pdata->gpio_init)) >= 0)
for (i = 0; i < ARRAY_SIZE(pdata->gpio_init); i++) {
if (pdata->gpio_init[i] > 0xffff)
pdata->gpio_init[i] = 0x0;
}
return 0;
}
static int wm8962_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8962_pdata *pdata = dev_get_platdata(&i2c->dev);
struct wm8962_priv *wm8962;
unsigned int reg;
int ret, i;
wm8962 = devm_kzalloc(&i2c->dev, sizeof(struct wm8962_priv),
GFP_KERNEL);
if (wm8962 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8962);
INIT_DELAYED_WORK(&wm8962->mic_work, wm8962_mic_work);
init_completion(&wm8962->fll_lock);
wm8962->irq = i2c->irq;
if (pdata) {
memcpy(&wm8962->pdata, pdata, sizeof(struct wm8962_pdata));
} else if (i2c->dev.of_node) {
ret = wm8962_set_pdata_from_of(i2c, &wm8962->pdata);
if (ret != 0)
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8962->supplies); i++)
wm8962->supplies[i].supply = wm8962_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8962->supplies),
wm8962->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
goto err;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8962->supplies),
wm8962->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
wm8962->regmap = devm_regmap_init_i2c(i2c, &wm8962_regmap);
if (IS_ERR(wm8962->regmap)) {
ret = PTR_ERR(wm8962->regmap);
dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
goto err_enable;
}
regcache_cache_bypass(wm8962->regmap, true);
ret = regmap_read(wm8962->regmap, WM8962_SOFTWARE_RESET, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register\n");
goto err_enable;
}
if (reg != 0x6243) {
dev_err(&i2c->dev,
"Device is not a WM8962, ID %x != 0x6243\n", reg);
ret = -EINVAL;
goto err_enable;
}
ret = regmap_read(wm8962->regmap, WM8962_RIGHT_INPUT_VOLUME, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read device revision: %d\n",
ret);
goto err_enable;
}
dev_info(&i2c->dev, "customer id %x revision %c\n",
(reg & WM8962_CUST_ID_MASK) >> WM8962_CUST_ID_SHIFT,
((reg & WM8962_CHIP_REV_MASK) >> WM8962_CHIP_REV_SHIFT)
+ 'A');
regcache_cache_bypass(wm8962->regmap, false);
ret = wm8962_reset(wm8962);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to issue reset\n");
goto err_enable;
}
if (wm8962->pdata.in4_dc_measure) {
ret = regmap_register_patch(wm8962->regmap,
wm8962_dc_measure,
ARRAY_SIZE(wm8962_dc_measure));
if (ret != 0)
dev_err(&i2c->dev,
"Failed to configure for DC mesurement: %d\n",
ret);
}
pm_runtime_enable(&i2c->dev);
pm_request_idle(&i2c->dev);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8962, &wm8962_dai, 1);
if (ret < 0)
goto err_enable;
regulator_bulk_disable(ARRAY_SIZE(wm8962->supplies), wm8962->supplies);
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8962->supplies), wm8962->supplies);
err:
return ret;
}
static int wm8962_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int wm8962_runtime_resume(struct device *dev)
{
struct wm8962_priv *wm8962 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(wm8962->supplies),
wm8962->supplies);
if (ret != 0) {
dev_err(dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
regcache_cache_only(wm8962->regmap, false);
wm8962_reset(wm8962);
regmap_update_bits(wm8962->regmap, WM8962_CLOCKING2,
WM8962_SYSCLK_ENA, 0);
regmap_update_bits(wm8962->regmap, WM8962_CLOCKING2,
WM8962_CLKREG_OVD, WM8962_CLKREG_OVD);
regmap_update_bits(wm8962->regmap, WM8962_PLL2,
WM8962_OSC_ENA | WM8962_PLL2_ENA | WM8962_PLL3_ENA,
0);
regcache_sync(wm8962->regmap);
regmap_update_bits(wm8962->regmap, WM8962_ANTI_POP,
WM8962_STARTUP_BIAS_ENA | WM8962_VMID_BUF_ENA,
WM8962_STARTUP_BIAS_ENA | WM8962_VMID_BUF_ENA);
regmap_update_bits(wm8962->regmap, WM8962_PWR_MGMT_1,
WM8962_BIAS_ENA | WM8962_VMID_SEL_MASK,
WM8962_BIAS_ENA | 0x180);
msleep(5);
return 0;
}
static int wm8962_runtime_suspend(struct device *dev)
{
struct wm8962_priv *wm8962 = dev_get_drvdata(dev);
regmap_update_bits(wm8962->regmap, WM8962_PWR_MGMT_1,
WM8962_VMID_SEL_MASK | WM8962_BIAS_ENA, 0);
regmap_update_bits(wm8962->regmap, WM8962_ANTI_POP,
WM8962_STARTUP_BIAS_ENA |
WM8962_VMID_BUF_ENA, 0);
regcache_cache_only(wm8962->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(wm8962->supplies),
wm8962->supplies);
return 0;
}
