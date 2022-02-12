static void __init nuc960evb_map_io(void)
{
nuc960_map_io();
nuc960_init_clocks();
}
static void __init nuc960evb_init(void)
{
nuc960_board_init();
}
