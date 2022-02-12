void __init iconnect_init(void)
{
kirkwood_ge00_init(&iconnect_ge00_data);
}
static int __init iconnect_pci_init(void)
{
if (of_machine_is_compatible("iom,iconnect"))
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
