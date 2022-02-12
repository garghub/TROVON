static void __init wnr854t_init(void)
{
orion5x_init();
orion5x_mpp_conf(wnr854t_mpp_modes);
orion5x_eth_init(&wnr854t_eth_data);
orion5x_eth_switch_init(&wnr854t_switch_plat_data, NO_IRQ);
orion5x_uart0_init();
mvebu_mbus_add_window("devbus-boot", WNR854T_NOR_BOOT_BASE,
WNR854T_NOR_BOOT_SIZE);
platform_device_register(&wnr854t_nor_flash);
}
static int __init wnr854t_pci_map_irq(const struct pci_dev *dev, u8 slot,
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
static int __init wnr854t_pci_init(void)
{
if (machine_is_wnr854t())
pci_common_init(&wnr854t_pci);
return 0;
}
