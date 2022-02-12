static void xo1_power_off(void)
{
printk(KERN_INFO "OLPC XO-1 power off sequence...\n");
outl(0x40000000, pms_base + PM_SCLK);
outl(0x40000000, pms_base + PM_IN_SLPCTL);
outl(0x40000000, pms_base + PM_WKXD);
outl(0x40000000, pms_base + PM_WKD);
outl(0x0002ffff, pms_base + PM_SSC);
outl(0xffffffff, acpi_base + PM_GPE0_STS);
outl(0x00002000, acpi_base + PM1_CNT);
}
static int __devinit olpc_xo1_probe(struct platform_device *pdev)
{
struct resource *res;
int err;
if (!machine_is_olpc())
return -ENODEV;
err = mfd_cell_enable(pdev);
if (err)
return err;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(&pdev->dev, "can't fetch device resource info\n");
return -EIO;
}
if (strcmp(pdev->name, "cs5535-pms") == 0)
pms_base = res->start;
else if (strcmp(pdev->name, "olpc-xo1-pm-acpi") == 0)
acpi_base = res->start;
if (pms_base && acpi_base) {
pm_power_off = xo1_power_off;
printk(KERN_INFO "OLPC XO-1 support registered\n");
}
return 0;
}
static int __devexit olpc_xo1_remove(struct platform_device *pdev)
{
mfd_cell_disable(pdev);
if (strcmp(pdev->name, "cs5535-pms") == 0)
pms_base = 0;
else if (strcmp(pdev->name, "olpc-xo1-pm-acpi") == 0)
acpi_base = 0;
pm_power_off = NULL;
return 0;
}
static int __init olpc_xo1_init(void)
{
int r;
r = platform_driver_register(&cs5535_pms_drv);
if (r)
return r;
r = platform_driver_register(&cs5535_acpi_drv);
if (r)
platform_driver_unregister(&cs5535_pms_drv);
return r;
}
static void __exit olpc_xo1_exit(void)
{
platform_driver_unregister(&cs5535_acpi_drv);
platform_driver_unregister(&cs5535_pms_drv);
}
