void __init s5p_init_irq(u32 *vic, u32 num_vic)\r\n{\r\n#ifdef CONFIG_ARM_VIC\r\nint irq;\r\nfor (irq = 0; irq < num_vic; irq++)\r\nvic_init(VA_VIC(irq), VIC_BASE(irq), vic[irq], 0);\r\n#endif\r\n}
