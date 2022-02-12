void __init pxa910_clk_init(phys_addr_t mpmu_phys, phys_addr_t apmu_phys,
phys_addr_t apbc_phys, phys_addr_t apbcp_phys)
{
clkdev_add_table(ARRAY_AND_SIZE(pxa910_clkregs));
}
