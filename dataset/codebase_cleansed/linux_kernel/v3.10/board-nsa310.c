static int __init nsa310_pci_init(void)
{
if (of_machine_is_compatible("zyxel,nsa310"))
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
