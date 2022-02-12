static void do_imx_poweroff(void)
{
u32 value = readl(snvs_base);
writel(value | 0x60, snvs_base);
}
static int imx_poweroff_probe(struct platform_device *pdev)
{
snvs_base = of_iomap(pdev->dev.of_node, 0);
if (!snvs_base) {
dev_err(&pdev->dev, "failed to get memory\n");
return -ENODEV;
}
pm_power_off = do_imx_poweroff;
return 0;
}
static int __init imx_poweroff_init(void)
{
return platform_driver_register(&imx_poweroff_driver);
}
