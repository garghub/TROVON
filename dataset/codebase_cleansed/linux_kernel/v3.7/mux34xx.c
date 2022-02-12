int __init omap3_mux_init(struct omap_board_mux *board_subset, int flags)
{
struct omap_mux *package_subset;
struct omap_ball *package_balls;
switch (flags & OMAP_PACKAGE_MASK) {
case OMAP_PACKAGE_CBC:
package_subset = omap3_cbc_subset;
package_balls = omap3_cbc_ball;
break;
case OMAP_PACKAGE_CBB:
package_subset = omap3_cbb_subset;
package_balls = omap3_cbb_ball;
break;
case OMAP_PACKAGE_CUS:
package_subset = omap3_cus_subset;
package_balls = omap3_cus_ball;
break;
case OMAP_PACKAGE_CBP:
package_subset = omap36xx_cbp_subset;
package_balls = omap36xx_cbp_ball;
break;
default:
pr_err("%s Unknown omap package, mux disabled\n", __func__);
return -EINVAL;
}
return omap_mux_init("core", 0,
OMAP3_CONTROL_PADCONF_MUX_PBASE,
OMAP3_CONTROL_PADCONF_MUX_SIZE,
omap3_muxmodes, package_subset, board_subset,
package_balls);
}
