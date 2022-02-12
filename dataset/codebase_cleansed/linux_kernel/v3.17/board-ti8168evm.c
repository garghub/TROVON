static void __init ti81xx_evm_init(void)\r\n{\r\nomap_serial_init();\r\nomap_sdrc_init(NULL, NULL);\r\nusb_musb_init(&musb_board_data);\r\n}
