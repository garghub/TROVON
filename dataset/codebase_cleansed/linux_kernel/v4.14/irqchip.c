void __init irqchip_init(void)\r\n{\r\nof_irq_init(__irqchip_of_table);\r\nacpi_probe_device_table(irqchip);\r\n}
