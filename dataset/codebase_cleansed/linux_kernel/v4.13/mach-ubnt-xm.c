static int ubnt_xm_pci_plat_dev_init(struct pci_dev *dev)
{
switch (PCI_SLOT(dev->devfn)) {
case 0:
dev->dev.platform_data = &ubnt_xm_eeprom_data;
break;
}
return 0;
}
static void __init ubnt_xm_pci_init(void)
{
memcpy(ubnt_xm_eeprom_data.eeprom_data, UBNT_XM_EEPROM_ADDR,
sizeof(ubnt_xm_eeprom_data.eeprom_data));
ath79_pci_set_plat_dev_init(ubnt_xm_pci_plat_dev_init);
ath79_register_pci();
}
static inline void ubnt_xm_pci_init(void) {}
static void __init ubnt_xm_init(void)
{
ath79_register_leds_gpio(-1, ARRAY_SIZE(ubnt_xm_leds_gpio),
ubnt_xm_leds_gpio);
ath79_register_gpio_keys_polled(-1, UBNT_XM_KEYS_POLL_INTERVAL,
ARRAY_SIZE(ubnt_xm_gpio_keys),
ubnt_xm_gpio_keys);
ath79_register_spi(&ubnt_xm_spi_data, ubnt_xm_spi_info,
ARRAY_SIZE(ubnt_xm_spi_info));
ubnt_xm_pci_init();
}
