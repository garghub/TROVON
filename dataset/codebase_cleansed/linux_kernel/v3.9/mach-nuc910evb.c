static void __init nuc910evb_map_io(void)
{
nuc910_map_io();
nuc910_init_clocks();
}
static void __init nuc910evb_init(void)
{
nuc910_board_init();
}
