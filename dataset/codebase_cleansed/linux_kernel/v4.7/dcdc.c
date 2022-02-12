static int dcdc_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dcdc_membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dcdc_membase))
return PTR_ERR(dcdc_membase);
dev_info(&pdev->dev, "Core Voltage : %d mV\n",
dcdc_r8(DCDC_BIAS_VREG1) * 8);
return 0;
}
int __init dcdc_init(void)
{
int ret = platform_driver_register(&dcdc_driver);
if (ret)
pr_info("dcdc: Error registering platform driver\n");
return ret;
}
