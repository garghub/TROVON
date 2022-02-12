void __init nuc960_map_io(void)
{
nuc900_map_io(nuc960evb_iodesc, ARRAY_SIZE(nuc960evb_iodesc));
}
void __init nuc960_init_clocks(void)
{
nuc900_init_clocks();
}
void __init nuc960_board_init(void)
{
nuc900_board_init(nuc960_dev, ARRAY_SIZE(nuc960_dev));
}
