static int __init omap_dsp_init(void)
{
struct platform_device *pdev;
int err = -ENOMEM;
struct omap_dsp_platform_data *pdata = &omap_dsp_pdata;
pdata->phys_mempool_base = omap_dsp_get_mempool_base();
if (pdata->phys_mempool_base) {
pdata->phys_mempool_size = CONFIG_TIDSPBRIDGE_MEMPOOL_SIZE;
pr_info("%s: %x bytes @ %x\n", __func__,
pdata->phys_mempool_size, pdata->phys_mempool_base);
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
platform_device_unregister(omap_dsp_pdev);
}
