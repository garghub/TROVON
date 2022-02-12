int __init am43xx_hwmod_init(void)
{
omap_hwmod_am43xx_reg();
omap_hwmod_init();
return omap_hwmod_register_links(am43xx_hwmod_ocp_ifs);
}
