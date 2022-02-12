static int ap136_pci_plat_dev_init(struct pci_dev *dev)
{
if (dev->bus->number == 1 && (PCI_SLOT(dev->devfn)) == 0)
dev->dev.platform_data = &ap136_ath9k_data;
return 0;
}
static void __init ap136_pci_init(u8 *eeprom)
{
memcpy(ap136_ath9k_data.eeprom_data, eeprom,
sizeof(ap136_ath9k_data.eeprom_data));
ath79_pci_set_plat_dev_init(ap136_pci_plat_dev_init);
ath79_register_pci();
}
static inline void ap136_pci_init(u8 *eeprom) {}
static void __init ap136_setup(void)
{
u8 *art = (u8 *) KSEG1ADDR(0x1fff0000);
ath79_register_leds_gpio(-1, ARRAY_SIZE(ap136_leds_gpio),
ap136_leds_gpio);
ath79_register_gpio_keys_polled(-1, AP136_KEYS_POLL_INTERVAL,
ARRAY_SIZE(ap136_gpio_keys),
ap136_gpio_keys);
ath79_register_spi(&ap136_spi_data, ap136_spi_info,
ARRAY_SIZE(ap136_spi_info));
ath79_register_usb();
ath79_register_wmac(art + AP136_WMAC_CALDATA_OFFSET);
ap136_pci_init(art + AP136_PCIE_CALDATA_OFFSET);
}
