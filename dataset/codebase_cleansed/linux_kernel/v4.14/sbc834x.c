static void __init sbc834x_setup_arch(void)\r\n{\r\nmpc83xx_setup_arch();\r\n}\r\nstatic int __init sbc834x_probe(void)\r\n{\r\nreturn of_machine_is_compatible("SBC834xE");\r\n}
