void __init nuc910_map_io(void)
{
nuc900_map_io(nuc910evb_iodesc, ARRAY_SIZE(nuc910evb_iodesc));
}
void __init nuc910_init_clocks(void)
{
nuc900_init_clocks();
}
void __init nuc910_board_init(void)
{
nuc900_board_init(nuc910_dev, ARRAY_SIZE(nuc910_dev));
}
