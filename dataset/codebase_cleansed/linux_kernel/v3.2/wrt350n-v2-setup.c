static void __init wrt350n_v2_init(void)
{
orion5x_init();
orion5x_mpp_conf(wrt350n_v2_mpp_modes);
orion5x_ehci0_init();
orion5x_eth_init(&wrt350n_v2_eth_data);
orion5x_eth_switch_init(&wrt350n_v2_switch_plat_data, NO_IRQ);
orion5x_uart0_init();
orion5x_setup_dev_boot_win(WRT350N_V2_NOR_BOOT_BASE,
WRT350N_V2_NOR_BOOT_SIZE);
platform_device_register(&wrt350n_v2_nor_flash);
platform_device_register(&wrt350n_v2_leds);
platform_device_register(&wrt350n_v2_button_device);
}
static int __init wrt350n_v2_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
if (slot == 7)
return gpio_to_irq(4);
return -1;
}
static int __init wrt350n_v2_pci_init(void)
{
if (machine_is_wrt350n_v2())
pci_common_init(&wrt350n_v2_pci);
return 0;
}
