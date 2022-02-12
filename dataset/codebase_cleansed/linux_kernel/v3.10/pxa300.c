static int __init pxa300_init(void)
{
if (cpu_is_pxa300() || cpu_is_pxa310()) {
mfp_init_base(io_p2v(MFPR_BASE));
mfp_init_addr(pxa300_mfp_addr_map);
clkdev_add_table(ARRAY_AND_SIZE(common_clkregs));
}
if (cpu_is_pxa310()) {
mfp_init_addr(pxa310_mfp_addr_map);
clkdev_add_table(ARRAY_AND_SIZE(pxa310_clkregs));
}
return 0;
}
