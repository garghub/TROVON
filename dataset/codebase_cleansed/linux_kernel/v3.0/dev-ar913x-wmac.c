void __init ath79_register_ar913x_wmac(u8 *cal_data)
{
if (cal_data)
memcpy(ar913x_wmac_data.eeprom_data, cal_data,
sizeof(ar913x_wmac_data.eeprom_data));
ath79_device_reset_set(AR913X_RESET_AMBA2WMAC);
mdelay(10);
ath79_device_reset_clear(AR913X_RESET_AMBA2WMAC);
mdelay(10);
platform_device_register(&ar913x_wmac_device);
}
