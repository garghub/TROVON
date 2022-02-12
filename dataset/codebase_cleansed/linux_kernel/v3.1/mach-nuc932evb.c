static void __init nuc932evb_map_io(void)\r\n{\r\nnuc932_map_io();\r\nnuc932_init_clocks();\r\nnuc932_init_uartclk();\r\n}\r\nstatic void __init nuc932evb_init(void)\r\n{\r\nnuc932_board_init();\r\n}
