static void __init dove_init(void)
{
pr_info("Dove 88AP510 SoC\n");
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init(0);
#endif
BUG_ON(mvebu_mbus_dt_init(false));
dove_init_pmu();
}
