void __init ns2_init(void)
{
if (of_machine_is_compatible("lacie,netspace_lite_v2") ||
of_machine_is_compatible("lacie,netspace_mini_v2"))
ns2_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
kirkwood_ge00_init(&ns2_ge00_data);
}
