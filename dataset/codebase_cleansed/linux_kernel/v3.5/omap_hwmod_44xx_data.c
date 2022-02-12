int __init omap44xx_hwmod_init(void)
{
return omap_hwmod_register_links(omap44xx_hwmod_ocp_ifs);
}
