int __init ti81xx_hwmod_init(void)
{
omap_hwmod_init();
return omap_hwmod_register_links(dm816x_hwmod_ocp_ifs);
}
