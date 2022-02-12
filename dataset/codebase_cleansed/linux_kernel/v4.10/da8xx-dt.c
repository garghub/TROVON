static void __init da850_init_machine(void)
{
int ret;
ret = da8xx_register_usb20_phy_clk(false);
if (ret)
pr_warn("%s: registering USB 2.0 PHY clock failed: %d",
__func__, ret);
ret = da8xx_register_usb11_phy_clk(false);
if (ret)
pr_warn("%s: registering USB 1.1 PHY clock failed: %d",
__func__, ret);
of_platform_default_populate(NULL, da850_auxdata_lookup, NULL);
davinci_pm_init();
}
