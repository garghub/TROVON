int __init omap2420_hwmod_init(void)
{
omap_hwmod_init();
return omap_hwmod_register_links(omap2420_hwmod_ocp_ifs);
}
