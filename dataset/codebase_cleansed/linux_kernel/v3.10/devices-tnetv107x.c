static int __init nand_init(int chipsel, struct davinci_nand_pdata *data)
{
struct resource res[2];
struct platform_device *pdev;
u32 range;
int ret;
range = max(data->mask_cle, data->mask_ale);
range = PAGE_ALIGN(range + 4) - 1;
if (range >= emif_window_sizes[chipsel])
return -EINVAL;
pdev = kzalloc(sizeof(*pdev), GFP_KERNEL);
if (!pdev)
return -ENOMEM;
pdev->name = "davinci_nand";
pdev->id = chipsel;
pdev->dev.platform_data = data;
memset(res, 0, sizeof(res));
res[0].start = emif_windows[chipsel];
res[0].end = res[0].start + range;
res[0].flags = IORESOURCE_MEM;
res[1].start = TNETV107X_ASYNC_EMIF_CNTRL_BASE;
res[1].end = res[1].start + SZ_4K - 1;
res[1].flags = IORESOURCE_MEM;
ret = platform_device_add_resources(pdev, res, ARRAY_SIZE(res));
if (ret < 0) {
kfree(pdev);
return ret;
}
return platform_device_register(pdev);
}
void __init tnetv107x_devices_init(struct tnetv107x_device_info *info)
{
int i, error;
struct clk *tsc_clk;
tsc_clk = clk_get(NULL, "sys_tsc_clk");
if (!IS_ERR(tsc_clk)) {
error = clk_set_rate(tsc_clk, 5000000);
WARN_ON(error < 0);
clk_put(tsc_clk);
}
platform_device_register(&edma_device);
platform_device_register(&tnetv107x_wdt_device);
platform_device_register(&tsc_device);
if (info->serial_config)
davinci_serial_init(info->serial_config);
for (i = 0; i < 2; i++)
if (info->mmc_config[i]) {
mmc_devices[i].dev.platform_data = info->mmc_config[i];
platform_device_register(&mmc_devices[i]);
}
for (i = 0; i < 4; i++)
if (info->nand_config[i])
nand_init(i, info->nand_config[i]);
if (info->keypad_config) {
keypad_device.dev.platform_data = info->keypad_config;
platform_device_register(&keypad_device);
}
if (info->ssp_config) {
ssp_device.dev.platform_data = info->ssp_config;
platform_device_register(&ssp_device);
}
}
