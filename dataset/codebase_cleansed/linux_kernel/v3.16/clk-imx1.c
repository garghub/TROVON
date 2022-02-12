int __init mx1_clocks_init(unsigned long fref)
{
int i;
clk[dummy] = imx_clk_fixed("dummy", 0);
clk[clk32] = imx_clk_fixed("clk32", fref);
clk[clk16m_ext] = imx_clk_fixed("clk16m_ext", 16000000);
clk[clk16m] = imx_clk_gate("clk16m", "clk16m_ext", CCM_CSCR, 17);
clk[clk32_premult] = imx_clk_fixed_factor("clk32_premult", "clk32", 512, 1);
clk[prem] = imx_clk_mux("prem", CCM_CSCR, 16, 1, prem_sel_clks,
ARRAY_SIZE(prem_sel_clks));
clk[mpll] = imx_clk_pllv1("mpll", "clk32_premult", CCM_MPCTL0);
clk[mpll_gate] = imx_clk_gate("mpll_gate", "mpll", CCM_CSCR, 0);
clk[spll] = imx_clk_pllv1("spll", "prem", CCM_SPCTL0);
clk[spll_gate] = imx_clk_gate("spll_gate", "spll", CCM_CSCR, 1);
clk[mcu] = imx_clk_divider("mcu", "clk32_premult", CCM_CSCR, 15, 1);
clk[fclk] = imx_clk_divider("fclk", "mpll_gate", CCM_CSCR, 15, 1);
clk[hclk] = imx_clk_divider("hclk", "spll_gate", CCM_CSCR, 10, 4);
clk[clk48m] = imx_clk_divider("clk48m", "spll_gate", CCM_CSCR, 26, 3);
clk[per1] = imx_clk_divider("per1", "spll_gate", CCM_PCDR, 0, 4);
clk[per2] = imx_clk_divider("per2", "spll_gate", CCM_PCDR, 4, 4);
clk[per3] = imx_clk_divider("per3", "spll_gate", CCM_PCDR, 16, 7);
clk[clko] = imx_clk_mux("clko", CCM_CSCR, 29, 3, clko_sel_clks,
ARRAY_SIZE(clko_sel_clks));
clk[uart3_gate] = imx_clk_gate("uart3_gate", "hclk", SCM_GCCR, 6);
clk[ssi2_gate] = imx_clk_gate("ssi2_gate", "hclk", SCM_GCCR, 5);
clk[brom_gate] = imx_clk_gate("brom_gate", "hclk", SCM_GCCR, 4);
clk[dma_gate] = imx_clk_gate("dma_gate", "hclk", SCM_GCCR, 3);
clk[csi_gate] = imx_clk_gate("csi_gate", "hclk", SCM_GCCR, 2);
clk[mma_gate] = imx_clk_gate("mma_gate", "hclk", SCM_GCCR, 1);
clk[usbd_gate] = imx_clk_gate("usbd_gate", "clk48m", SCM_GCCR, 0);
for (i = 0; i < ARRAY_SIZE(clk); i++)
if (IS_ERR(clk[i]))
pr_err("imx1 clk %d: register failed with %ld\n",
i, PTR_ERR(clk[i]));
clk_register_clkdev(clk[dma_gate], "ahb", "imx1-dma");
clk_register_clkdev(clk[hclk], "ipg", "imx1-dma");
clk_register_clkdev(clk[per1], "per", "imx-gpt.0");
clk_register_clkdev(clk[hclk], "ipg", "imx-gpt.0");
clk_register_clkdev(clk[per1], "per", "imx1-uart.0");
clk_register_clkdev(clk[hclk], "ipg", "imx1-uart.0");
clk_register_clkdev(clk[per1], "per", "imx1-uart.1");
clk_register_clkdev(clk[hclk], "ipg", "imx1-uart.1");
clk_register_clkdev(clk[per1], "per", "imx1-uart.2");
clk_register_clkdev(clk[uart3_gate], "ipg", "imx1-uart.2");
clk_register_clkdev(clk[hclk], NULL, "imx1-i2c.0");
clk_register_clkdev(clk[per2], "per", "imx1-cspi.0");
clk_register_clkdev(clk[dummy], "ipg", "imx1-cspi.0");
clk_register_clkdev(clk[per2], "per", "imx1-cspi.1");
clk_register_clkdev(clk[dummy], "ipg", "imx1-cspi.1");
clk_register_clkdev(clk[per2], "per", "imx1-fb.0");
clk_register_clkdev(clk[dummy], "ipg", "imx1-fb.0");
clk_register_clkdev(clk[dummy], "ahb", "imx1-fb.0");
mxc_timer_init(MX1_IO_ADDRESS(MX1_TIM1_BASE_ADDR), MX1_TIM1_INT);
return 0;
}
