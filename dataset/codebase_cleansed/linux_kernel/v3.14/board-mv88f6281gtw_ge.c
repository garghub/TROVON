void __init mv88f6281gtw_ge_init(void)\r\n{\r\nkirkwood_ge00_init(&mv88f6281gtw_ge_ge00_data);\r\nkirkwood_ge00_switch_init(&mv88f6281gtw_ge_switch_plat_data, NO_IRQ);\r\n}
