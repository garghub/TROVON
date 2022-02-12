static int spear310_pinctrl_probe(struct platform_device *pdev)
{
int ret;
spear3xx_machdata.groups = spear310_pingroups;
spear3xx_machdata.ngroups = ARRAY_SIZE(spear310_pingroups);
spear3xx_machdata.functions = spear310_functions;
spear3xx_machdata.nfunctions = ARRAY_SIZE(spear310_functions);
pmx_init_addr(&spear3xx_machdata, PMX_CONFIG_REG);
pmx_init_gpio_pingroup_addr(spear3xx_machdata.gpio_pingroups,
spear3xx_machdata.ngpio_pingroups, PMX_CONFIG_REG);
spear3xx_machdata.modes_supported = false;
ret = spear_pinctrl_probe(pdev, &spear3xx_machdata);
if (ret)
return ret;
return 0;
}
static int __init spear310_pinctrl_init(void)
{
return platform_driver_register(&spear310_pinctrl_driver);
}
static void __exit spear310_pinctrl_exit(void)
{
platform_driver_unregister(&spear310_pinctrl_driver);
}
