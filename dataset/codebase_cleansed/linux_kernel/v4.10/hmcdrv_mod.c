static int __init hmcdrv_mod_init(void)
{
int rc = hmcdrv_ftp_probe();
if (rc)
return rc;
rc = hmcdrv_cache_startup(hmcdrv_mod_cachesize);
if (rc)
return rc;
rc = hmcdrv_dev_init();
if (rc)
hmcdrv_cache_shutdown();
return rc;
}
static void __exit hmcdrv_mod_exit(void)
{
hmcdrv_dev_exit();
hmcdrv_cache_shutdown();
}
