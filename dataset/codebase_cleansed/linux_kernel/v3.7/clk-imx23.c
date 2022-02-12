static void __init clk_misc_init(void)
{
u32 val;
__mxs_setl(1 << BP_CPU_INTERRUPT_WAIT, CPU);
__mxs_clrl(1 << BP_CLKSEQ_BYPASS_SAIF, CLKSEQ);
val = readl_relaxed(SAIF);
val |= 1 << BP_SAIF_DIV_FRAC_EN;
writel_relaxed(val, SAIF);
__mxs_clrl(1 << BP_CLKSEQ_BYPASS_SSP, CLKSEQ);
__mxs_clrl(0x3f << BP_FRAC_IOFRAC, FRAC);
__mxs_setl(30 << BP_FRAC_IOFRAC, FRAC);
}
int __init mx23_clocks_init(void)
{
struct device_node *np;
int i;
clk_misc_init();
clks[ref_xtal] = mxs_clk_fixed("ref_xtal", 24000000);
clks[pll] = mxs_clk_pll("pll", "ref_xtal", PLLCTRL0, 16, 480000000);
clks[ref_cpu] = mxs_clk_ref("ref_cpu", "pll", FRAC, 0);
clks[ref_emi] = mxs_clk_ref("ref_emi", "pll", FRAC, 1);
clks[ref_pix] = mxs_clk_ref("ref_pix", "pll", FRAC, 2);
clks[ref_io] = mxs_clk_ref("ref_io", "pll", FRAC, 3);
clks[saif_sel] = mxs_clk_mux("saif_sel", CLKSEQ, 0, 1, sel_pll, ARRAY_SIZE(sel_pll));
clks[lcdif_sel] = mxs_clk_mux("lcdif_sel", CLKSEQ, 1, 1, sel_pix, ARRAY_SIZE(sel_pix));
clks[gpmi_sel] = mxs_clk_mux("gpmi_sel", CLKSEQ, 4, 1, sel_io, ARRAY_SIZE(sel_io));
clks[ssp_sel] = mxs_clk_mux("ssp_sel", CLKSEQ, 5, 1, sel_io, ARRAY_SIZE(sel_io));
clks[emi_sel] = mxs_clk_mux("emi_sel", CLKSEQ, 6, 1, emi_sels, ARRAY_SIZE(emi_sels));
clks[cpu] = mxs_clk_mux("cpu", CLKSEQ, 7, 1, cpu_sels, ARRAY_SIZE(cpu_sels));
clks[etm_sel] = mxs_clk_mux("etm_sel", CLKSEQ, 8, 1, sel_cpu, ARRAY_SIZE(sel_cpu));
clks[cpu_pll] = mxs_clk_div("cpu_pll", "ref_cpu", CPU, 0, 6, 28);
clks[cpu_xtal] = mxs_clk_div("cpu_xtal", "ref_xtal", CPU, 16, 10, 29);
clks[hbus] = mxs_clk_div("hbus", "cpu", HBUS, 0, 5, 29);
clks[xbus] = mxs_clk_div("xbus", "ref_xtal", XBUS, 0, 10, 31);
clks[lcdif_div] = mxs_clk_div("lcdif_div", "lcdif_sel", PIX, 0, 12, 29);
clks[ssp_div] = mxs_clk_div("ssp_div", "ssp_sel", SSP, 0, 9, 29);
clks[gpmi_div] = mxs_clk_div("gpmi_div", "gpmi_sel", GPMI, 0, 10, 29);
clks[emi_pll] = mxs_clk_div("emi_pll", "ref_emi", EMI, 0, 6, 28);
clks[emi_xtal] = mxs_clk_div("emi_xtal", "ref_xtal", EMI, 8, 4, 29);
clks[etm_div] = mxs_clk_div("etm_div", "etm_sel", ETM, 0, 6, 29);
clks[saif_div] = mxs_clk_frac("saif_div", "saif_sel", SAIF, 0, 16, 29);
clks[clk32k_div] = mxs_clk_fixed_factor("clk32k_div", "ref_xtal", 1, 750);
clks[rtc] = mxs_clk_fixed_factor("rtc", "ref_xtal", 1, 768);
clks[adc] = mxs_clk_fixed_factor("adc", "clk32k", 1, 16);
clks[spdif_div] = mxs_clk_fixed_factor("spdif_div", "pll", 1, 4);
clks[clk32k] = mxs_clk_gate("clk32k", "clk32k_div", XTAL, 26);
clks[dri] = mxs_clk_gate("dri", "ref_xtal", XTAL, 28);
clks[pwm] = mxs_clk_gate("pwm", "ref_xtal", XTAL, 29);
clks[filt] = mxs_clk_gate("filt", "ref_xtal", XTAL, 30);
clks[uart] = mxs_clk_gate("uart", "ref_xtal", XTAL, 31);
clks[ssp] = mxs_clk_gate("ssp", "ssp_div", SSP, 31);
clks[gpmi] = mxs_clk_gate("gpmi", "gpmi_div", GPMI, 31);
clks[spdif] = mxs_clk_gate("spdif", "spdif_div", SPDIF, 31);
clks[emi] = mxs_clk_gate("emi", "emi_sel", EMI, 31);
clks[saif] = mxs_clk_gate("saif", "saif_div", SAIF, 31);
clks[lcdif] = mxs_clk_gate("lcdif", "lcdif_div", PIX, 31);
clks[etm] = mxs_clk_gate("etm", "etm_div", ETM, 31);
clks[usb] = mxs_clk_gate("usb", "usb_pwr", DIGCTRL, 2);
clks[usb_pwr] = clk_register_gate(NULL, "usb_pwr", "pll", 0, PLLCTRL0, 18, 0, &mxs_lock);
for (i = 0; i < ARRAY_SIZE(clks); i++)
if (IS_ERR(clks[i])) {
pr_err("i.MX23 clk %d: register failed with %ld\n",
i, PTR_ERR(clks[i]));
return PTR_ERR(clks[i]);
}
np = of_find_compatible_node(NULL, NULL, "fsl,imx23-clkctrl");
if (np) {
clk_data.clks = clks;
clk_data.clk_num = ARRAY_SIZE(clks);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
clk_register_clkdev(clks[clk32k], NULL, "timrot");
for (i = 0; i < ARRAY_SIZE(clks_init_on); i++)
clk_prepare_enable(clks[clks_init_on[i]]);
mxs_timer_init();
return 0;
}
