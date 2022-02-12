int __init omap5xxx_dt_clk_init(void)
{
int rc;
struct clk *abe_dpll_ref, *abe_dpll, *sys_32k_ck, *usb_dpll;
ti_dt_clocks_register(omap54xx_clks);
omap2_clk_disable_autoidle_all();
abe_dpll_ref = clk_get_sys(NULL, "abe_dpll_clk_mux");
sys_32k_ck = clk_get_sys(NULL, "sys_32k_ck");
rc = clk_set_parent(abe_dpll_ref, sys_32k_ck);
abe_dpll = clk_get_sys(NULL, "dpll_abe_ck");
if (!rc)
rc = clk_set_rate(abe_dpll, OMAP5_DPLL_ABE_DEFFREQ);
if (rc)
pr_err("%s: failed to configure ABE DPLL!\n", __func__);
abe_dpll = clk_get_sys(NULL, "dpll_abe_m2x2_ck");
if (!rc)
rc = clk_set_rate(abe_dpll, OMAP5_DPLL_ABE_DEFFREQ * 2);
if (rc)
pr_err("%s: failed to configure ABE m2x2 DPLL!\n", __func__);
usb_dpll = clk_get_sys(NULL, "dpll_usb_ck");
rc = clk_set_rate(usb_dpll, OMAP5_DPLL_USB_DEFFREQ);
if (rc)
pr_err("%s: failed to configure USB DPLL!\n", __func__);
usb_dpll = clk_get_sys(NULL, "dpll_usb_m2_ck");
rc = clk_set_rate(usb_dpll, OMAP5_DPLL_USB_DEFFREQ/2);
if (rc)
pr_err("%s: failed to set USB_DPLL M2 OUT\n", __func__);
return 0;
}
