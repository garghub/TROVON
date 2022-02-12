int get_c0_perfcount_int(void)\r\n{\r\nreturn gic_get_c0_perfcount_int();\r\n}\r\nvoid __init arch_init_irq(void)\r\n{\r\nirqchip_init();\r\n}
