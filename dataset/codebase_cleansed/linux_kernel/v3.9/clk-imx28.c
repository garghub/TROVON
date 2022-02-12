int mxs_saif_clkmux_select(unsigned int clkmux)
{
if (clkmux > 0x3)
return -EINVAL;
__mxs_clrl(0x3 << BP_SAIF_CLKMUX, DIGCTRL);
__mxs_setl(clkmux << BP_SAIF_CLKMUX, DIGCTRL);
return 0;
}
static void __init clk_misc_init(void)
{
u32 val;
__mxs_setl(1 << BP_CPU_INTERRUPT_WAIT, CPU);
__mxs_setl(1 << BP_ENET_DIV_TIME, ENET);
__mxs_clrl(0x3 << BP_CLKSEQ_BYPASS_SAIF0, CLKSEQ);
val = readl_relaxed(SAIF0);
val |= 1 << BP_SAIF_DIV_FRAC_EN;
writel_relaxed(val, SAIF0);
val = readl_relaxed(SAIF1);
val |= 1 << BP_SAIF_DIV_FRAC_EN;
writel_relaxed(val, SAIF1);
val = readl_relaxed(ENET);
val &= ~(1 << BP_ENET_SLEEP);
writel_relaxed(val, ENET);
__mxs_clrl(0xf << BP_CLKSEQ_BYPASS_SSP0, CLKSEQ);
val = readl_relaxed(FRAC0);
val &= ~((0x3f << BP_FRAC0_IO0FRAC) | (0x3f << BP_FRAC0_IO1FRAC));
val |= (30 << BP_FRAC0_IO0FRAC) | (30 << BP_FRAC0_IO1FRAC);
writel_relaxed(val, FRAC0);
}
int __init mx28_clocks_init(void)
{
struct device_node *np;
u32 i;
clk_misc_init();
clks[ref_xtal] = mxs_clk_fixed("ref_xtal", 24000000);
clks[pll0] = mxs_clk_pll("pll0", "ref_xtal", PLL0CTRL0, 17, 480000000);
clks[pll1] = mxs_clk_pll("pll1", "ref_xtal", PLL1CTRL0, 17, 480000000);
clks[pll2] = mxs_clk_pll("pll2", "ref_xtal", PLL2CTRL0, 23, 50000000);
clks[ref_cpu] = mxs_clk_ref("ref_cpu", "pll0", FRAC0, 0);
clks[ref_emi] = mxs_clk_ref("ref_emi", "pll0", FRAC0, 1);
clks[ref_io1] = mxs_clk_ref("ref_io1", "pll0", FRAC0, 2);
clks[ref_io0] = mxs_clk_ref("ref_io0", "pll0", FRAC0, 3);
clks[ref_pix] = mxs_clk_ref("ref_pix", "pll0", FRAC1, 0);
clks[ref_hsadc] = mxs_clk_ref("ref_hsadc", "pll0", FRAC1, 1);
clks[ref_gpmi] = mxs_clk_ref("ref_gpmi", "pll0", FRAC1, 2);
clks[saif0_sel] = mxs_clk_mux("saif0_sel", CLKSEQ, 0, 1, sel_pll0, ARRAY_SIZE(sel_pll0));
clks[saif1_sel] = mxs_clk_mux("saif1_sel", CLKSEQ, 1, 1, sel_pll0, ARRAY_SIZE(sel_pll0));
clks[gpmi_sel] = mxs_clk_mux("gpmi_sel", CLKSEQ, 2, 1, sel_gpmi, ARRAY_SIZE(sel_gpmi));
clks[ssp0_sel] = mxs_clk_mux("ssp0_sel", CLKSEQ, 3, 1, sel_io0, ARRAY_SIZE(sel_io0));
clks[ssp1_sel] = mxs_clk_mux("ssp1_sel", CLKSEQ, 4, 1, sel_io0, ARRAY_SIZE(sel_io0));
clks[ssp2_sel] = mxs_clk_mux("ssp2_sel", CLKSEQ, 5, 1, sel_io1, ARRAY_SIZE(sel_io1));
clks[ssp3_sel] = mxs_clk_mux("ssp3_sel", CLKSEQ, 6, 1, sel_io1, ARRAY_SIZE(sel_io1));
clks[emi_sel] = mxs_clk_mux("emi_sel", CLKSEQ, 7, 1, emi_sels, ARRAY_SIZE(emi_sels));
clks[etm_sel] = mxs_clk_mux("etm_sel", CLKSEQ, 8, 1, sel_cpu, ARRAY_SIZE(sel_cpu));
clks[lcdif_sel] = mxs_clk_mux("lcdif_sel", CLKSEQ, 14, 1, sel_pix, ARRAY_SIZE(sel_pix));
clks[cpu] = mxs_clk_mux("cpu", CLKSEQ, 18, 1, cpu_sels, ARRAY_SIZE(cpu_sels));
clks[ptp_sel] = mxs_clk_mux("ptp_sel", ENET, 19, 1, ptp_sels, ARRAY_SIZE(ptp_sels));
clks[cpu_pll] = mxs_clk_div("cpu_pll", "ref_cpu", CPU, 0, 6, 28);
clks[cpu_xtal] = mxs_clk_div("cpu_xtal", "ref_xtal", CPU, 16, 10, 29);
clks[hbus] = mxs_clk_div("hbus", "cpu", HBUS, 0, 5, 31);
clks[xbus] = mxs_clk_div("xbus", "ref_xtal", XBUS, 0, 10, 31);
clks[ssp0_div] = mxs_clk_div("ssp0_div", "ssp0_sel", SSP0, 0, 9, 29);
clks[ssp1_div] = mxs_clk_div("ssp1_div", "ssp1_sel", SSP1, 0, 9, 29);
clks[ssp2_div] = mxs_clk_div("ssp2_div", "ssp2_sel", SSP2, 0, 9, 29);
clks[ssp3_div] = mxs_clk_div("ssp3_div", "ssp3_sel", SSP3, 0, 9, 29);
clks[gpmi_div] = mxs_clk_div("gpmi_div", "gpmi_sel", GPMI, 0, 10, 29);
clks[emi_pll] = mxs_clk_div("emi_pll", "ref_emi", EMI, 0, 6, 28);
clks[emi_xtal] = mxs_clk_div("emi_xtal", "ref_xtal", EMI, 8, 4, 29);
clks[lcdif_div] = mxs_clk_div("lcdif_div", "lcdif_sel", LCDIF, 0, 13, 29);
clks[etm_div] = mxs_clk_div("etm_div", "etm_sel", ETM, 0, 7, 29);
clks[ptp] = mxs_clk_div("ptp", "ptp_sel", ENET, 21, 6, 27);
clks[saif0_div] = mxs_clk_frac("saif0_div", "saif0_sel", SAIF0, 0, 16, 29);
clks[saif1_div] = mxs_clk_frac("saif1_div", "saif1_sel", SAIF1, 0, 16, 29);
clks[clk32k_div] = mxs_clk_fixed_factor("clk32k_div", "ref_xtal", 1, 750);
clks[rtc] = mxs_clk_fixed_factor("rtc", "ref_xtal", 1, 768);
clks[lradc] = mxs_clk_fixed_factor("lradc", "clk32k", 1, 16);
clks[spdif_div] = mxs_clk_fixed_factor("spdif_div", "pll0", 1, 4);
clks[clk32k] = mxs_clk_gate("clk32k", "clk32k_div", XTAL, 26);
clks[pwm] = mxs_clk_gate("pwm", "ref_xtal", XTAL, 29);
clks[uart] = mxs_clk_gate("uart", "ref_xtal", XTAL, 31);
clks[ssp0] = mxs_clk_gate("ssp0", "ssp0_div", SSP0, 31);
clks[ssp1] = mxs_clk_gate("ssp1", "ssp1_div", SSP1, 31);
clks[ssp2] = mxs_clk_gate("ssp2", "ssp2_div", SSP2, 31);
clks[ssp3] = mxs_clk_gate("ssp3", "ssp3_div", SSP3, 31);
clks[gpmi] = mxs_clk_gate("gpmi", "gpmi_div", GPMI, 31);
clks[spdif] = mxs_clk_gate("spdif", "spdif_div", SPDIF, 31);
clks[emi] = mxs_clk_gate("emi", "emi_sel", EMI, 31);
clks[saif0] = mxs_clk_gate("saif0", "saif0_div", SAIF0, 31);
clks[saif1] = mxs_clk_gate("saif1", "saif1_div", SAIF1, 31);
clks[lcdif] = mxs_clk_gate("lcdif", "lcdif_div", LCDIF, 31);
clks[etm] = mxs_clk_gate("etm", "etm_div", ETM, 31);
clks[fec] = mxs_clk_gate("fec", "hbus", ENET, 30);
clks[can0] = mxs_clk_gate("can0", "ref_xtal", FLEXCAN, 30);
clks[can1] = mxs_clk_gate("can1", "ref_xtal", FLEXCAN, 28);
clks[usb0] = mxs_clk_gate("usb0", "usb0_phy", DIGCTRL, 2);
clks[usb1] = mxs_clk_gate("usb1", "usb1_phy", DIGCTRL, 16);
clks[usb0_phy] = clk_register_gate(NULL, "usb0_phy", "pll0", 0, PLL0CTRL0, 18, 0, &mxs_lock);
clks[usb1_phy] = clk_register_gate(NULL, "usb1_phy", "pll1", 0, PLL1CTRL0, 18, 0, &mxs_lock);
clks[enet_out] = clk_register_gate(NULL, "enet_out", "pll2", 0, ENET, 18, 0, &mxs_lock);
for (i = 0; i < ARRAY_SIZE(clks); i++)
if (IS_ERR(clks[i])) {
pr_err("i.MX28 clk %d: register failed with %ld\n",
i, PTR_ERR(clks[i]));
return PTR_ERR(clks[i]);
}
np = of_find_compatible_node(NULL, NULL, "fsl,imx28-clkctrl");
if (np) {
clk_data.clks = clks;
clk_data.clk_num = ARRAY_SIZE(clks);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
clk_register_clkdev(clks[xbus], NULL, "timrot");
clk_register_clkdev(clks[enet_out], NULL, "enet_out");
for (i = 0; i < ARRAY_SIZE(clks_init_on); i++)
clk_prepare_enable(clks[clks_init_on[i]]);
mxs_timer_init();
return 0;
}
