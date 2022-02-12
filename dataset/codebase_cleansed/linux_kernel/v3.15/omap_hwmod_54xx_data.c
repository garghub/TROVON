int __init omap54xx_hwmod_init(void)
{
omap_hwmod_init();
return omap_hwmod_register_links(omap54xx_hwmod_ocp_ifs);
}
