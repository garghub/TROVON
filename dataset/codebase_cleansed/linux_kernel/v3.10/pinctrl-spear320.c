static int spear320_pinctrl_probe(struct platform_device *pdev)
{
int ret;
spear3xx_machdata.groups = spear320_pingroups;
spear3xx_machdata.ngroups = ARRAY_SIZE(spear320_pingroups);
spear3xx_machdata.functions = spear320_functions;
spear3xx_machdata.nfunctions = ARRAY_SIZE(spear320_functions);
spear3xx_machdata.modes_supported = true;
spear3xx_machdata.pmx_modes = spear320_pmx_modes;
spear3xx_machdata.npmx_modes = ARRAY_SIZE(spear320_pmx_modes);
pmx_init_addr(&spear3xx_machdata, PMX_CONFIG_REG);
pmx_init_gpio_pingroup_addr(spear3xx_machdata.gpio_pingroups,
spear3xx_machdata.ngpio_pingroups, PMX_CONFIG_REG);
ret = spear_pinctrl_probe(pdev, &spear3xx_machdata);
if (ret)
return ret;
return 0;
}
static int spear320_pinctrl_remove(struct platform_device *pdev)
{
return spear_pinctrl_remove(pdev);
}
static int __init spear320_pinctrl_init(void)
{
return platform_driver_register(&spear320_pinctrl_driver);
}
static void __exit spear320_pinctrl_exit(void)
{
platform_driver_unregister(&spear320_pinctrl_driver);
}
