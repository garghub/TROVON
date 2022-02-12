int __init omap3_opp_init(void)
{
int r = -ENODEV;
if (!cpu_is_omap34xx())
return r;
if (cpu_is_omap3630())
r = omap_init_opp_table(omap36xx_opp_def_list,
ARRAY_SIZE(omap36xx_opp_def_list));
else
r = omap_init_opp_table(omap34xx_opp_def_list,
ARRAY_SIZE(omap34xx_opp_def_list));
return r;
}
