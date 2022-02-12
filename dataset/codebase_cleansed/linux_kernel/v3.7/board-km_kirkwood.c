void __init km_kirkwood_init(void)
{
struct clk *sata_clk;
kirkwood_mpp_conf(km_kirkwood_mpp_config);
sata_clk = clk_get_sys("sata_mv.0", "0");
if (!IS_ERR(sata_clk))
sata_clk->flags |= CLK_IGNORE_UNUSED;
sata_clk = clk_get_sys("sata_mv.0", "1");
if (!IS_ERR(sata_clk))
sata_clk->flags |= CLK_IGNORE_UNUSED;
kirkwood_ehci_init();
kirkwood_ge00_init(&km_kirkwood_ge00_data);
}
