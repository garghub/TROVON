static void __init nuc950evb_map_io(void)\r\n{\r\nnuc950_map_io();\r\nnuc950_init_clocks();\r\n}\r\nstatic void __init nuc950evb_init(void)\r\n{\r\nnuc950_board_init();\r\n}
