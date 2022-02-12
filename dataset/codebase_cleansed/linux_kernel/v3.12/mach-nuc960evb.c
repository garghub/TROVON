static void __init nuc960evb_map_io(void)\r\n{\r\nnuc960_map_io();\r\nnuc960_init_clocks();\r\n}\r\nstatic void __init nuc960evb_init(void)\r\n{\r\nnuc960_board_init();\r\n}
