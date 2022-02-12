int __init am43xx_hwmod_init(void)
{
int ret;
omap_hwmod_am43xx_reg();
omap_hwmod_init();
ret = omap_hwmod_register_links(am43xx_hwmod_ocp_ifs);
if (!ret && of_machine_is_compatible("ti,am4372"))
ret = omap_hwmod_register_links(am43xx_rtc_hwmod_ocp_ifs);
return ret;
}
