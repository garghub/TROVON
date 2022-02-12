int __init am33xx_hwmod_init(void)
{
omap_hwmod_init();
return omap_hwmod_register_links(am33xx_hwmod_ocp_ifs);
}
