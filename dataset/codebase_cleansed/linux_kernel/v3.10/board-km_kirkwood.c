void __init km_kirkwood_init(void)
{
struct clk *sata_clk;
sata_clk = clk_get_sys("sata_mv.0", "0");
if (!IS_ERR(sata_clk))
sata_clk->flags |= CLK_IGNORE_UNUSED;
sata_clk = clk_get_sys("sata_mv.0", "1");
if (!IS_ERR(sata_clk))
sata_clk->flags |= CLK_IGNORE_UNUSED;
kirkwood_ge00_init(&km_kirkwood_ge00_data);
}
