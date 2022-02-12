static int __init init_edosk7760_devices(void)\r\n{\r\nplat_irq_setup_pins(IRQ_MODE_IRQ);\r\nreturn platform_add_devices(edosk7760_devices,\r\nARRAY_SIZE(edosk7760_devices));\r\n}
