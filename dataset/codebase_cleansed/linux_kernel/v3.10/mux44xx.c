int __init omap4_mux_init(struct omap_board_mux *board_subset,
struct omap_board_mux *board_wkup_subset, int flags)
{
struct omap_ball *package_balls_core;
struct omap_ball *package_balls_wkup = omap4_wkup_cbl_cbs_ball;
struct omap_mux *core_muxmodes;
struct omap_mux *core_subset = NULL;
int ret;
switch (flags & OMAP_PACKAGE_MASK) {
case OMAP_PACKAGE_CBL:
pr_debug("%s: OMAP4430 ES1.0 -> OMAP_PACKAGE_CBL\n", __func__);
package_balls_core = omap4_core_cbl_ball;
core_muxmodes = omap4_core_muxmodes;
break;
case OMAP_PACKAGE_CBS:
pr_debug("%s: OMAP4430 ES2.X -> OMAP_PACKAGE_CBS\n", __func__);
package_balls_core = omap4_core_cbs_ball;
core_muxmodes = omap4_core_muxmodes;
core_subset = omap4_es2_core_subset;
break;
default:
pr_err("%s: Unknown omap package, mux disabled\n", __func__);
return -EINVAL;
}
ret = omap_mux_init("core",
OMAP_MUX_GPIO_IN_MODE3,
OMAP4_CTRL_MODULE_PAD_CORE_MUX_PBASE,
OMAP4_CTRL_MODULE_PAD_CORE_MUX_SIZE,
core_muxmodes, core_subset, board_subset,
package_balls_core);
if (ret)
return ret;
ret = omap_mux_init("wkup",
OMAP_MUX_GPIO_IN_MODE3,
OMAP4_CTRL_MODULE_PAD_WKUP_MUX_PBASE,
OMAP4_CTRL_MODULE_PAD_WKUP_MUX_SIZE,
omap4_wkup_muxmodes, NULL, board_wkup_subset,
package_balls_wkup);
return ret;
}
