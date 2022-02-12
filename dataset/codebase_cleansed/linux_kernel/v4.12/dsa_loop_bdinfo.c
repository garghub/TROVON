static int __init dsa_loop_bdinfo_init(void)
{
return mdiobus_register_board_info(&bdinfo, 1);
}
