static void __init easy50712_init(void)\r\n{\r\nltq_register_gpio_stp();\r\nltq_register_nor(&easy50712_flash_data);\r\nltq_register_pci(&ltq_pci_data);\r\nltq_register_etop(&ltq_eth_data);\r\n}
