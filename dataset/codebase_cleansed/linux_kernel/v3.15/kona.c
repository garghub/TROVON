void __init kona_l2_cache_init(void)
{
int ret;
if (!IS_ENABLED(CONFIG_CACHE_L2X0))
return;
ret = bcm_kona_smc_init();
if (ret) {
pr_info("Secure API not available (%d). Skipping L2 init.\n",
ret);
return;
}
bcm_kona_smc(SSAPI_ENABLE_L2_CACHE, 0, 0, 0, 0);
ret = l2x0_of_init(0, ~0);
if (ret)
pr_err("Couldn't enable L2 cache: %d\n", ret);
}
