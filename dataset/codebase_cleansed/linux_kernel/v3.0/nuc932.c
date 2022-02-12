void __init nuc932_map_io(void)
{
nuc93x_map_io(nuc932evb_iodesc, ARRAY_SIZE(nuc932evb_iodesc));
}
void __init nuc932_init_clocks(void)
{
nuc93x_init_clocks();
}
void __init nuc932_init_uartclk(void)
{
struct clk *ck_uart = clk_get(NULL, "uart");
BUG_ON(IS_ERR(ck_uart));
clk_enable(ck_uart);
}
void __init nuc932_board_init(void)
{
nuc93x_board_init(nuc932_dev, ARRAY_SIZE(nuc932_dev));
}
