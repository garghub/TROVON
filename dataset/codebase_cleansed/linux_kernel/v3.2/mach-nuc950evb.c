static void __init nuc950evb_map_io(void)
{
nuc950_map_io();
nuc950_init_clocks();
}
static void __init nuc950evb_init(void)
{
nuc950_board_init();
}
