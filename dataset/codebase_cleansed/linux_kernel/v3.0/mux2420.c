int __init omap2420_mux_init(struct omap_board_mux *board_subset, int flags)
{
struct omap_ball *package_balls = NULL;
switch (flags & OMAP_PACKAGE_MASK) {
case OMAP_PACKAGE_ZAC:
package_balls = omap2420_pop_ball;
break;
case OMAP_PACKAGE_ZAF:
default:
pr_warning("%s: No ball data available for omap2420 package\n",
__func__);
}
return omap_mux_init("core", OMAP_MUX_REG_8BIT | OMAP_MUX_GPIO_IN_MODE3,
OMAP2420_CONTROL_PADCONF_MUX_PBASE,
OMAP2420_CONTROL_PADCONF_MUX_SIZE,
omap2420_muxmodes, NULL, board_subset,
package_balls);
}
