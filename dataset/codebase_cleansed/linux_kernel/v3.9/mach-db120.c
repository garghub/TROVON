static int db120_pci_plat_dev_init(struct pci_dev *dev)
{
switch (PCI_SLOT(dev->devfn)) {
case 0:
dev->dev.platform_data = &db120_ath9k_data;
break;
}
return 0;
}
static void __init db120_pci_init(u8 *eeprom)
{
memcpy(db120_ath9k_data.eeprom_data, eeprom,
sizeof(db120_ath9k_data.eeprom_data));
ath79_pci_set_plat_dev_init(db120_pci_plat_dev_init);
ath79_register_pci();
}
static inline void db120_pci_init(void) {}
static void __init db120_setup(void)
{
u8 *art = (u8 *) KSEG1ADDR(0x1fff0000);
ath79_register_leds_gpio(-1, ARRAY_SIZE(db120_leds_gpio),
db120_leds_gpio);
ath79_register_gpio_keys_polled(-1, DB120_KEYS_POLL_INTERVAL,
ARRAY_SIZE(db120_gpio_keys),
db120_gpio_keys);
ath79_register_spi(&db120_spi_data, db120_spi_info,
ARRAY_SIZE(db120_spi_info));
ath79_register_usb();
ath79_register_wmac(art + DB120_WMAC_CALDATA_OFFSET);
db120_pci_init(art + DB120_PCIE_CALDATA_OFFSET);
}
