static int __init dsa_loop_bdinfo_init(void)\r\n{\r\nreturn mdiobus_register_board_info(&bdinfo, 1);\r\n}
