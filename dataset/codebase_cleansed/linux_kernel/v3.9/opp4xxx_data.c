int __init omap4_opp_init(void)
{
int r = -ENODEV;
if (cpu_is_omap443x())
r = omap_init_opp_table(omap443x_opp_def_list,
ARRAY_SIZE(omap443x_opp_def_list));
else if (cpu_is_omap446x())
r = omap_init_opp_table(omap446x_opp_def_list,
ARRAY_SIZE(omap446x_opp_def_list));
return r;
}
