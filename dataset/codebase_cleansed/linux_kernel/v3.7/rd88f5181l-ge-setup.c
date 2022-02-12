static void __init rd88f5181l_ge_init(void)
{
orion5x_init();
orion5x_mpp_conf(rd88f5181l_ge_mpp_modes);
orion5x_ehci0_init();
orion5x_eth_init(&rd88f5181l_ge_eth_data);
orion5x_eth_switch_init(&rd88f5181l_ge_switch_plat_data,
gpio_to_irq(8));
orion5x_i2c_init();
orion5x_uart0_init();
orion5x_setup_dev_boot_win(RD88F5181L_GE_NOR_BOOT_BASE,
RD88F5181L_GE_NOR_BOOT_SIZE);
platform_device_register(&rd88f5181l_ge_nor_boot_flash);
i2c_register_board_info(0, &rd88f5181l_ge_i2c_rtc, 1);
}
static int __init
rd88f5181l_ge_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
if (pin == 1)
return gpio_to_irq(4);
else
return gpio_to_irq(10);
}
static int __init rd88f5181l_ge_pci_init(void)
{
if (machine_is_rd88f5181l_ge()) {
orion5x_pci_set_cardbus_mode();
pci_common_init(&rd88f5181l_ge_pci);
}
return 0;
}
