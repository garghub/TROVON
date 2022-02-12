int __init dra7xx_hwmod_init(void)
{
omap_hwmod_init();
return omap_hwmod_register_links(dra7xx_hwmod_ocp_ifs);
}
