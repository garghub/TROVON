static void __init at91eb01_init_irq(void)\r\n{\r\nat91x40_init_interrupts(NULL);\r\n}\r\nstatic void __init at91eb01_init_early(void)\r\n{\r\nat91x40_initialize(40000000);\r\n}
