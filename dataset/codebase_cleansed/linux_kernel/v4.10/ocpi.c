int ocpi_enable(void)
{
unsigned int val;
if (!cpu_is_omap16xx())
return -ENODEV;
val = omap_readl(OCPI_PROT);
val &= ~0xff;
omap_writel(val, OCPI_PROT);
val = omap_readl(OCPI_SEC);
val &= ~0xff;
omap_writel(val, OCPI_SEC);
return 0;
}
static int __init omap_ocpi_init(void)
{
if (!cpu_is_omap16xx())
return -ENODEV;
ocpi_ck = clk_get(NULL, "l3_ocpi_ck");
if (IS_ERR(ocpi_ck))
return PTR_ERR(ocpi_ck);
clk_enable(ocpi_ck);
ocpi_enable();
pr_info("OMAP OCPI interconnect driver loaded\n");
return 0;
}
static void __exit omap_ocpi_exit(void)
{
if (!cpu_is_omap16xx())
return;
clk_disable(ocpi_ck);
clk_put(ocpi_ck);
}
