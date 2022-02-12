void __init omap_dsp_reserve_sdram_memblock(void)
{
phys_addr_t size = CONFIG_TIDSPBRIDGE_MEMPOOL_SIZE;
phys_addr_t paddr;
if (!cpu_is_omap34xx())
return;
if (!size)
return;
paddr = arm_memblock_steal(size, SZ_1M);
if (!paddr) {
pr_err("%s: failed to reserve %llx bytes\n",
__func__, (unsigned long long)size);
return;
}
omap_dsp_phys_mempool_base = paddr;
}
static phys_addr_t omap_dsp_get_mempool_base(void)
{
return omap_dsp_phys_mempool_base;
}
static int __init omap_dsp_init(void)
{
struct platform_device *pdev;
int err = -ENOMEM;
struct omap_dsp_platform_data *pdata = &omap_dsp_pdata;
if (!cpu_is_omap34xx())
return 0;
pdata->phys_mempool_base = omap_dsp_get_mempool_base();
if (pdata->phys_mempool_base) {
pdata->phys_mempool_size = CONFIG_TIDSPBRIDGE_MEMPOOL_SIZE;
pr_info("%s: %llx bytes @ %llx\n", __func__,
(unsigned long long)pdata->phys_mempool_size,
(unsigned long long)pdata->phys_mempool_base);
}
pdev = platform_device_alloc("omap-dsp", -1);
if (!pdev)
goto err_out;
err = platform_device_add_data(pdev, pdata, sizeof(*pdata));
if (err)
goto err_out;
err = platform_device_add(pdev);
if (err)
goto err_out;
omap_dsp_pdev = pdev;
return 0;
err_out:
platform_device_put(pdev);
return err;
}
static void __exit omap_dsp_exit(void)
{
if (!cpu_is_omap34xx())
return;
platform_device_unregister(omap_dsp_pdev);
}
