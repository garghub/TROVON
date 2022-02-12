int __init dra7xx_dt_clk_init(void)
{
int rc;
struct clk *dpll_ck, *hdcp_ck;
ti_dt_clocks_register(dra7xx_clks);
omap2_clk_disable_autoidle_all();
dpll_ck = clk_get_sys(NULL, "dpll_gmac_ck");
rc = clk_set_rate(dpll_ck, DRA7_DPLL_GMAC_DEFFREQ);
if (rc)
pr_err("%s: failed to configure GMAC DPLL!\n", __func__);
dpll_ck = clk_get_sys(NULL, "dpll_usb_ck");
rc = clk_set_rate(dpll_ck, DRA7_DPLL_USB_DEFFREQ);
if (rc)
pr_err("%s: failed to configure USB DPLL!\n", __func__);
dpll_ck = clk_get_sys(NULL, "dpll_usb_m2_ck");
rc = clk_set_rate(dpll_ck, DRA7_DPLL_USB_DEFFREQ/2);
if (rc)
pr_err("%s: failed to set USB_DPLL M2 OUT\n", __func__);
hdcp_ck = clk_get_sys(NULL, "dss_deshdcp_clk");
rc = clk_prepare_enable(hdcp_ck);
if (rc)
pr_err("%s: failed to set dss_deshdcp_clk\n", __func__);
return rc;
}
