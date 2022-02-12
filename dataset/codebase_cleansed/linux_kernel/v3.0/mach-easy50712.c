static void __init easy50712_init(void)
{
ltq_register_gpio_stp();
ltq_register_nor(&easy50712_flash_data);
ltq_register_pci(&ltq_pci_data);
ltq_register_etop(&ltq_eth_data);
}
