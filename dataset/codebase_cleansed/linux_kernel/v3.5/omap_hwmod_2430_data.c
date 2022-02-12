int __init omap2430_hwmod_init(void)
{
return omap_hwmod_register_links(omap2430_hwmod_ocp_ifs);
}
