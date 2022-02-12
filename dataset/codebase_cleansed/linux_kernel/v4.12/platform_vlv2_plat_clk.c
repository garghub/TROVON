static int __init vlv2_plat_clk_init(void)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("vlv2_plat_clk", -1, NULL, 0);
if (IS_ERR(pdev)) {
pr_err("platform_vlv2_plat_clk:register failed: %ld\n",
PTR_ERR(pdev));
return PTR_ERR(pdev);
}
return 0;
}
