static void __init ubnt_xm_init(void)
{
ath79_register_leds_gpio(-1, ARRAY_SIZE(ubnt_xm_leds_gpio),
ubnt_xm_leds_gpio);
ath79_register_gpio_keys_polled(-1, UBNT_XM_KEYS_POLL_INTERVAL,
ARRAY_SIZE(ubnt_xm_gpio_keys),
ubnt_xm_gpio_keys);
ath79_register_spi(&ubnt_xm_spi_data, ubnt_xm_spi_info,
ARRAY_SIZE(ubnt_xm_spi_info));
#ifdef CONFIG_PCI
memcpy(ubnt_xm_eeprom_data.eeprom_data, UBNT_XM_EEPROM_ADDR,
sizeof(ubnt_xm_eeprom_data.eeprom_data));
ath724x_pci_add_data(ubnt_xm_pci_data, ARRAY_SIZE(ubnt_xm_pci_data));
#endif
}
