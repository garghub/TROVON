static void __init nuc932evb_map_io(void)
{
nuc932_map_io();
nuc932_init_clocks();
nuc932_init_uartclk();
}
static void __init nuc932evb_init(void)
{
nuc932_board_init();
}
