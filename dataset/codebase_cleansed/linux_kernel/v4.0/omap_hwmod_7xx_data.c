int __init dra7xx_hwmod_init(void)
{
int ret;
omap_hwmod_init();
ret = omap_hwmod_register_links(dra7xx_hwmod_ocp_ifs);
if (!ret && soc_is_dra74x())
return omap_hwmod_register_links(dra74x_hwmod_ocp_ifs);
else if (!ret && soc_is_dra72x())
return omap_hwmod_register_links(dra72x_hwmod_ocp_ifs);
return ret;
}
