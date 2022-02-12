int __init omap4_opp_init(void)
{
int r = -ENODEV;
if (!cpu_is_omap44xx())
return r;
r = omap_init_opp_table(omap44xx_opp_def_list,
ARRAY_SIZE(omap44xx_opp_def_list));
return r;
}
