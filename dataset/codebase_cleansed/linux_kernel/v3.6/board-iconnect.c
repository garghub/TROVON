void __init iconnect_init(void)
{
kirkwood_mpp_conf(iconnect_mpp_config);
kirkwood_nand_init(ARRAY_AND_SIZE(iconnect_nand_parts), 25);
kirkwood_ehci_init();
kirkwood_ge00_init(&iconnect_ge00_data);
platform_device_register(&iconnect_button_device);
}
static int __init iconnect_pci_init(void)
{
if (of_machine_is_compatible("iom,iconnect"))
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
