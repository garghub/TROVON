static bool da9052_reg_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9052_PAGE0_CON_REG:
case DA9052_STATUS_A_REG:
case DA9052_STATUS_B_REG:
case DA9052_STATUS_C_REG:
case DA9052_STATUS_D_REG:
case DA9052_EVENT_A_REG:
case DA9052_EVENT_B_REG:
case DA9052_EVENT_C_REG:
case DA9052_EVENT_D_REG:
case DA9052_FAULTLOG_REG:
case DA9052_IRQ_MASK_A_REG:
case DA9052_IRQ_MASK_B_REG:
case DA9052_IRQ_MASK_C_REG:
case DA9052_IRQ_MASK_D_REG:
case DA9052_CONTROL_A_REG:
case DA9052_CONTROL_B_REG:
case DA9052_CONTROL_C_REG:
case DA9052_CONTROL_D_REG:
case DA9052_PDDIS_REG:
case DA9052_INTERFACE_REG:
case DA9052_RESET_REG:
case DA9052_GPIO_0_1_REG:
case DA9052_GPIO_2_3_REG:
case DA9052_GPIO_4_5_REG:
case DA9052_GPIO_6_7_REG:
case DA9052_GPIO_14_15_REG:
case DA9052_ID_0_1_REG:
case DA9052_ID_2_3_REG:
case DA9052_ID_4_5_REG:
case DA9052_ID_6_7_REG:
case DA9052_ID_8_9_REG:
case DA9052_ID_10_11_REG:
case DA9052_ID_12_13_REG:
case DA9052_ID_14_15_REG:
case DA9052_ID_16_17_REG:
case DA9052_ID_18_19_REG:
case DA9052_ID_20_21_REG:
case DA9052_SEQ_STATUS_REG:
case DA9052_SEQ_A_REG:
case DA9052_SEQ_B_REG:
case DA9052_SEQ_TIMER_REG:
case DA9052_BUCKA_REG:
case DA9052_BUCKB_REG:
case DA9052_BUCKCORE_REG:
case DA9052_BUCKPRO_REG:
case DA9052_BUCKMEM_REG:
case DA9052_BUCKPERI_REG:
case DA9052_LDO1_REG:
case DA9052_LDO2_REG:
case DA9052_LDO3_REG:
case DA9052_LDO4_REG:
case DA9052_LDO5_REG:
case DA9052_LDO6_REG:
case DA9052_LDO7_REG:
case DA9052_LDO8_REG:
case DA9052_LDO9_REG:
case DA9052_LDO10_REG:
case DA9052_SUPPLY_REG:
case DA9052_PULLDOWN_REG:
case DA9052_CHGBUCK_REG:
case DA9052_WAITCONT_REG:
case DA9052_ISET_REG:
case DA9052_BATCHG_REG:
case DA9052_CHG_CONT_REG:
case DA9052_INPUT_CONT_REG:
case DA9052_CHG_TIME_REG:
case DA9052_BBAT_CONT_REG:
case DA9052_BOOST_REG:
case DA9052_LED_CONT_REG:
case DA9052_LEDMIN123_REG:
case DA9052_LED1_CONF_REG:
case DA9052_LED2_CONF_REG:
case DA9052_LED3_CONF_REG:
case DA9052_LED1CONT_REG:
case DA9052_LED2CONT_REG:
case DA9052_LED3CONT_REG:
case DA9052_LED_CONT_4_REG:
case DA9052_LED_CONT_5_REG:
case DA9052_ADC_MAN_REG:
case DA9052_ADC_CONT_REG:
case DA9052_ADC_RES_L_REG:
case DA9052_ADC_RES_H_REG:
case DA9052_VDD_RES_REG:
case DA9052_VDD_MON_REG:
case DA9052_ICHG_AV_REG:
case DA9052_ICHG_THD_REG:
case DA9052_ICHG_END_REG:
case DA9052_TBAT_RES_REG:
case DA9052_TBAT_HIGHP_REG:
case DA9052_TBAT_HIGHN_REG:
case DA9052_TBAT_LOW_REG:
case DA9052_T_OFFSET_REG:
case DA9052_ADCIN4_RES_REG:
case DA9052_AUTO4_HIGH_REG:
case DA9052_AUTO4_LOW_REG:
case DA9052_ADCIN5_RES_REG:
case DA9052_AUTO5_HIGH_REG:
case DA9052_AUTO5_LOW_REG:
case DA9052_ADCIN6_RES_REG:
case DA9052_AUTO6_HIGH_REG:
case DA9052_AUTO6_LOW_REG:
case DA9052_TJUNC_RES_REG:
case DA9052_TSI_CONT_A_REG:
case DA9052_TSI_CONT_B_REG:
case DA9052_TSI_X_MSB_REG:
case DA9052_TSI_Y_MSB_REG:
case DA9052_TSI_LSB_REG:
case DA9052_TSI_Z_MSB_REG:
case DA9052_COUNT_S_REG:
case DA9052_COUNT_MI_REG:
case DA9052_COUNT_H_REG:
case DA9052_COUNT_D_REG:
case DA9052_COUNT_MO_REG:
case DA9052_COUNT_Y_REG:
case DA9052_ALARM_MI_REG:
case DA9052_ALARM_H_REG:
case DA9052_ALARM_D_REG:
case DA9052_ALARM_MO_REG:
case DA9052_ALARM_Y_REG:
case DA9052_SECOND_A_REG:
case DA9052_SECOND_B_REG:
case DA9052_SECOND_C_REG:
case DA9052_SECOND_D_REG:
case DA9052_PAGE1_CON_REG:
return true;
default:
return false;
}
}
static bool da9052_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9052_PAGE0_CON_REG:
case DA9052_EVENT_A_REG:
case DA9052_EVENT_B_REG:
case DA9052_EVENT_C_REG:
case DA9052_EVENT_D_REG:
case DA9052_IRQ_MASK_A_REG:
case DA9052_IRQ_MASK_B_REG:
case DA9052_IRQ_MASK_C_REG:
case DA9052_IRQ_MASK_D_REG:
case DA9052_CONTROL_A_REG:
case DA9052_CONTROL_B_REG:
case DA9052_CONTROL_C_REG:
case DA9052_CONTROL_D_REG:
case DA9052_PDDIS_REG:
case DA9052_RESET_REG:
case DA9052_GPIO_0_1_REG:
case DA9052_GPIO_2_3_REG:
case DA9052_GPIO_4_5_REG:
case DA9052_GPIO_6_7_REG:
case DA9052_GPIO_14_15_REG:
case DA9052_ID_0_1_REG:
case DA9052_ID_2_3_REG:
case DA9052_ID_4_5_REG:
case DA9052_ID_6_7_REG:
case DA9052_ID_8_9_REG:
case DA9052_ID_10_11_REG:
case DA9052_ID_12_13_REG:
case DA9052_ID_14_15_REG:
case DA9052_ID_16_17_REG:
case DA9052_ID_18_19_REG:
case DA9052_ID_20_21_REG:
case DA9052_SEQ_STATUS_REG:
case DA9052_SEQ_A_REG:
case DA9052_SEQ_B_REG:
case DA9052_SEQ_TIMER_REG:
case DA9052_BUCKA_REG:
case DA9052_BUCKB_REG:
case DA9052_BUCKCORE_REG:
case DA9052_BUCKPRO_REG:
case DA9052_BUCKMEM_REG:
case DA9052_BUCKPERI_REG:
case DA9052_LDO1_REG:
case DA9052_LDO2_REG:
case DA9052_LDO3_REG:
case DA9052_LDO4_REG:
case DA9052_LDO5_REG:
case DA9052_LDO6_REG:
case DA9052_LDO7_REG:
case DA9052_LDO8_REG:
case DA9052_LDO9_REG:
case DA9052_LDO10_REG:
case DA9052_SUPPLY_REG:
case DA9052_PULLDOWN_REG:
case DA9052_CHGBUCK_REG:
case DA9052_WAITCONT_REG:
case DA9052_ISET_REG:
case DA9052_BATCHG_REG:
case DA9052_CHG_CONT_REG:
case DA9052_INPUT_CONT_REG:
case DA9052_BBAT_CONT_REG:
case DA9052_BOOST_REG:
case DA9052_LED_CONT_REG:
case DA9052_LEDMIN123_REG:
case DA9052_LED1_CONF_REG:
case DA9052_LED2_CONF_REG:
case DA9052_LED3_CONF_REG:
case DA9052_LED1CONT_REG:
case DA9052_LED2CONT_REG:
case DA9052_LED3CONT_REG:
case DA9052_LED_CONT_4_REG:
case DA9052_LED_CONT_5_REG:
case DA9052_ADC_MAN_REG:
case DA9052_ADC_CONT_REG:
case DA9052_ADC_RES_L_REG:
case DA9052_ADC_RES_H_REG:
case DA9052_VDD_RES_REG:
case DA9052_VDD_MON_REG:
case DA9052_ICHG_THD_REG:
case DA9052_ICHG_END_REG:
case DA9052_TBAT_HIGHP_REG:
case DA9052_TBAT_HIGHN_REG:
case DA9052_TBAT_LOW_REG:
case DA9052_T_OFFSET_REG:
case DA9052_AUTO4_HIGH_REG:
case DA9052_AUTO4_LOW_REG:
case DA9052_AUTO5_HIGH_REG:
case DA9052_AUTO5_LOW_REG:
case DA9052_AUTO6_HIGH_REG:
case DA9052_AUTO6_LOW_REG:
case DA9052_TSI_CONT_A_REG:
case DA9052_TSI_CONT_B_REG:
case DA9052_COUNT_S_REG:
case DA9052_COUNT_MI_REG:
case DA9052_COUNT_H_REG:
case DA9052_COUNT_D_REG:
case DA9052_COUNT_MO_REG:
case DA9052_COUNT_Y_REG:
case DA9052_ALARM_MI_REG:
case DA9052_ALARM_H_REG:
case DA9052_ALARM_D_REG:
case DA9052_ALARM_MO_REG:
case DA9052_ALARM_Y_REG:
case DA9052_PAGE1_CON_REG:
return true;
default:
return false;
}
}
static bool da9052_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9052_STATUS_A_REG:
case DA9052_STATUS_B_REG:
case DA9052_STATUS_C_REG:
case DA9052_STATUS_D_REG:
case DA9052_EVENT_A_REG:
case DA9052_EVENT_B_REG:
case DA9052_EVENT_C_REG:
case DA9052_EVENT_D_REG:
case DA9052_CONTROL_B_REG:
case DA9052_CONTROL_D_REG:
case DA9052_SUPPLY_REG:
case DA9052_FAULTLOG_REG:
case DA9052_CHG_TIME_REG:
case DA9052_ADC_RES_L_REG:
case DA9052_ADC_RES_H_REG:
case DA9052_VDD_RES_REG:
case DA9052_ICHG_AV_REG:
case DA9052_TBAT_RES_REG:
case DA9052_ADCIN4_RES_REG:
case DA9052_ADCIN5_RES_REG:
case DA9052_ADCIN6_RES_REG:
case DA9052_TJUNC_RES_REG:
case DA9052_TSI_X_MSB_REG:
case DA9052_TSI_Y_MSB_REG:
case DA9052_TSI_LSB_REG:
case DA9052_TSI_Z_MSB_REG:
case DA9052_COUNT_S_REG:
case DA9052_COUNT_MI_REG:
case DA9052_COUNT_H_REG:
case DA9052_COUNT_D_REG:
case DA9052_COUNT_MO_REG:
case DA9052_COUNT_Y_REG:
case DA9052_ALARM_MI_REG:
return true;
default:
return false;
}
}
int da9052_adc_manual_read(struct da9052 *da9052, unsigned char channel)
{
int ret;
unsigned short calc_data;
unsigned short data;
unsigned char mux_sel;
if (channel > DA9052_ADC_VBBAT)
return -EINVAL;
mutex_lock(&da9052->auxadc_lock);
mux_sel = chan_mux[channel] | DA9052_ADC_MAN_MAN_CONV;
ret = da9052_reg_write(da9052, DA9052_ADC_MAN_REG, mux_sel);
if (ret < 0)
goto err;
if (!wait_for_completion_timeout(&da9052->done,
msecs_to_jiffies(500))) {
dev_err(da9052->dev,
"timeout waiting for ADC conversion interrupt\n");
ret = -ETIMEDOUT;
goto err;
}
ret = da9052_reg_read(da9052, DA9052_ADC_RES_H_REG);
if (ret < 0)
goto err;
calc_data = (unsigned short)ret;
data = calc_data << 2;
ret = da9052_reg_read(da9052, DA9052_ADC_RES_L_REG);
if (ret < 0)
goto err;
calc_data = (unsigned short)(ret & DA9052_ADC_RES_LSB);
data |= calc_data;
ret = data;
err:
mutex_unlock(&da9052->auxadc_lock);
return ret;
}
int da9052_adc_read_temp(struct da9052 *da9052)
{
int tbat;
tbat = da9052_reg_read(da9052, DA9052_TBAT_RES_REG);
if (tbat <= 0)
return tbat;
return tbat_lookup[tbat - 1];
}
int da9052_device_init(struct da9052 *da9052, u8 chip_id)
{
struct da9052_pdata *pdata = dev_get_platdata(da9052->dev);
int ret;
mutex_init(&da9052->auxadc_lock);
init_completion(&da9052->done);
if (pdata && pdata->init != NULL)
pdata->init(da9052);
da9052->chip_id = chip_id;
ret = da9052_irq_init(da9052);
if (ret != 0) {
dev_err(da9052->dev, "da9052_irq_init failed: %d\n", ret);
return ret;
}
ret = mfd_add_devices(da9052->dev, PLATFORM_DEVID_AUTO,
da9052_subdev_info,
ARRAY_SIZE(da9052_subdev_info), NULL, 0, NULL);
if (ret) {
dev_err(da9052->dev, "mfd_add_devices failed: %d\n", ret);
goto err;
}
return 0;
err:
da9052_irq_exit(da9052);
return ret;
}
void da9052_device_exit(struct da9052 *da9052)
{
mfd_remove_devices(da9052->dev);
da9052_irq_exit(da9052);
}
