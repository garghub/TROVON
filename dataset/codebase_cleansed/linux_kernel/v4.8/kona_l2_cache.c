void __init kona_l2_cache_init(void)
{
unsigned int result;
int ret;
ret = bcm_kona_smc_init();
if (ret) {
pr_info("Secure API not available (%d). Skipping L2 init.\n",
ret);
return;
}
result = bcm_kona_smc(SSAPI_ENABLE_L2_CACHE, 0, 0, 0, 0);
if (result != SEC_ROM_RET_OK) {
pr_err("Secure Monitor call failed (%u)! Skipping L2 init.\n",
result);
return;
}
ret = l2x0_of_init(0, ~0);
if (ret)
pr_err("Couldn't enable L2 cache: %d\n", ret);
}
