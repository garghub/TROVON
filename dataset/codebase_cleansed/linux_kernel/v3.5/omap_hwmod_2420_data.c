int __init omap2420_hwmod_init(void)
{
return omap_hwmod_register_links(omap2420_hwmod_ocp_ifs);
}
