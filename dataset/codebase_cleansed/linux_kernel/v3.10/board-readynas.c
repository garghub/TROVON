void __init netgear_readynas_init(void)
{
kirkwood_ge00_init(&netgear_readynas_ge00_data);
kirkwood_pcie_init(KW_PCIE0);
}
