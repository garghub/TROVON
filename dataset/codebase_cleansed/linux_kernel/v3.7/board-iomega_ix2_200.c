void __init iomega_ix2_200_init(void)
{
kirkwood_mpp_conf(iomega_ix2_200_mpp_config);
kirkwood_ehci_init();
kirkwood_ge01_init(&iomega_ix2_200_ge00_data);
}
