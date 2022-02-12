static void __init rd88f5181l_fxo_init(void)
{
orion5x_init();
orion5x_mpp_conf(rd88f5181l_fxo_mpp_modes);
orion5x_ehci0_init();
orion5x_eth_init(&rd88f5181l_fxo_eth_data);
orion5x_eth_switch_init(&rd88f5181l_fxo_switch_plat_data);
orion5x_uart0_init();
mvebu_mbus_add_window_by_id(ORION_MBUS_DEVBUS_BOOT_TARGET,
ORION_MBUS_DEVBUS_BOOT_ATTR,
RD88F5181L_FXO_NOR_BOOT_BASE,
RD88F5181L_FXO_NOR_BOOT_SIZE);
platform_device_register(&rd88f5181l_fxo_nor_boot_flash);
}
static int __init
rd88f5181l_fxo_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return gpio_to_irq(1);
}
static int __init rd88f5181l_fxo_pci_init(void)
{
if (machine_is_rd88f5181l_fxo()) {
orion5x_pci_set_cardbus_mode();
pci_common_init(&rd88f5181l_fxo_pci);
}
return 0;
}
