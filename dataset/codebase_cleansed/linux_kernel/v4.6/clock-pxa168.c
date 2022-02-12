void __init pxa168_clk_init(phys_addr_t mpmu_phys, phys_addr_t apmu_phys,\r\nphys_addr_t apbc_phys)\r\n{\r\nclkdev_add_table(ARRAY_AND_SIZE(pxa168_clkregs));\r\n}
