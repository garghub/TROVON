static int dra7xx_pciess_reset(struct omap_hwmod *oh)
{
int i;
for (i = 0; i < oh->rst_lines_cnt; i++) {
omap_hwmod_assert_hardreset(oh, oh->rst_lines[i].name);
omap_hwmod_deassert_hardreset(oh, oh->rst_lines[i].name);
}
return 0;
}
int __init dra7xx_hwmod_init(void)
{
int ret;
omap_hwmod_init();
ret = omap_hwmod_register_links(dra7xx_hwmod_ocp_ifs);
if (!ret && soc_is_dra74x())
ret = omap_hwmod_register_links(dra74x_hwmod_ocp_ifs);
else if (!ret && soc_is_dra72x())
ret = omap_hwmod_register_links(dra72x_hwmod_ocp_ifs);
if (!ret && omap_type() == OMAP2_DEVICE_TYPE_GP)
ret = omap_hwmod_register_links(dra7xx_gp_hwmod_ocp_ifs);
if (!ret && !of_machine_is_compatible("ti,dra718"))
ret = omap_hwmod_register_links(dra74x_dra72x_hwmod_ocp_ifs);
return ret;
}
