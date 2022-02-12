static void __init nuc910evb_map_io(void)\r\n{\r\nnuc910_map_io();\r\nnuc910_init_clocks();\r\n}\r\nstatic void __init nuc910evb_init(void)\r\n{\r\nnuc910_board_init();\r\n}
