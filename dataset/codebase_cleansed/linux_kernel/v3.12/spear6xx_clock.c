void __init spear6xx_clk_init(void __iomem *misc_base)
{
struct clk *clk, *clk1;
clk = clk_register_fixed_rate(NULL, "osc_32k_clk", NULL, CLK_IS_ROOT,
32000);
clk_register_clkdev(clk, "osc_32k_clk", NULL);
clk = clk_register_fixed_rate(NULL, "osc_30m_clk", NULL, CLK_IS_ROOT,
30000000);
clk_register_clkdev(clk, "osc_30m_clk", NULL);
clk = clk_register_gate(NULL, "rtc_spear", "osc_32k_clk", 0,
PERIP1_CLK_ENB, RTC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "rtc-spear");
clk = clk_register_fixed_rate(NULL, "pll3_clk", "osc_24m_clk", 0,
48000000);
clk_register_clkdev(clk, "pll3_clk", NULL);
clk = clk_register_vco_pll("vco1_clk", "pll1_clk", NULL, "osc_30m_clk",
0, PLL1_CTR, PLL1_FRQ, pll_rtbl, ARRAY_SIZE(pll_rtbl),
&_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco1_clk", NULL);
clk_register_clkdev(clk1, "pll1_clk", NULL);
clk = clk_register_vco_pll("vco2_clk", "pll2_clk", NULL, "osc_30m_clk",
0, PLL2_CTR, PLL2_FRQ, pll_rtbl, ARRAY_SIZE(pll_rtbl),
&_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco2_clk", NULL);
clk_register_clkdev(clk1, "pll2_clk", NULL);
clk = clk_register_fixed_factor(NULL, "wdt_clk", "osc_30m_clk", 0, 1,
1);
clk_register_clkdev(clk, NULL, "wdt");
clk = clk_register_fixed_factor(NULL, "cpu_clk", "pll1_clk",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "cpu_clk", NULL);
clk = clk_register_divider(NULL, "ahb_clk", "pll1_clk",
CLK_SET_RATE_PARENT, CORE_CLK_CFG, HCLK_RATIO_SHIFT,
HCLK_RATIO_MASK, 0, &_lock);
clk_register_clkdev(clk, "ahb_clk", NULL);
clk = clk_register_aux("uart_syn_clk", "uart_syn_gclk", "pll1_clk", 0,
UART_CLK_SYNT, NULL, aux_rtbl, ARRAY_SIZE(aux_rtbl),
&_lock, &clk1);
clk_register_clkdev(clk, "uart_syn_clk", NULL);
clk_register_clkdev(clk1, "uart_syn_gclk", NULL);
clk = clk_register_mux(NULL, "uart_mclk", uart_parents,
ARRAY_SIZE(uart_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, UART_CLK_SHIFT, UART_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "uart_mclk", NULL);
clk = clk_register_gate(NULL, "uart0", "uart_mclk", 0, PERIP1_CLK_ENB,
UART0_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d0000000.serial");
clk = clk_register_gate(NULL, "uart1", "uart_mclk", 0, PERIP1_CLK_ENB,
UART1_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d0080000.serial");
clk = clk_register_aux("firda_syn_clk", "firda_syn_gclk", "pll1_clk",
0, FIRDA_CLK_SYNT, NULL, aux_rtbl, ARRAY_SIZE(aux_rtbl),
&_lock, &clk1);
clk_register_clkdev(clk, "firda_syn_clk", NULL);
clk_register_clkdev(clk1, "firda_syn_gclk", NULL);
clk = clk_register_mux(NULL, "firda_mclk", firda_parents,
ARRAY_SIZE(firda_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, FIRDA_CLK_SHIFT, FIRDA_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "firda_mclk", NULL);
clk = clk_register_gate(NULL, "firda_clk", "firda_mclk", 0,
PERIP1_CLK_ENB, FIRDA_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "firda");
clk = clk_register_aux("clcd_syn_clk", "clcd_syn_gclk", "pll1_clk",
0, CLCD_CLK_SYNT, NULL, aux_rtbl, ARRAY_SIZE(aux_rtbl),
&_lock, &clk1);
clk_register_clkdev(clk, "clcd_syn_clk", NULL);
clk_register_clkdev(clk1, "clcd_syn_gclk", NULL);
clk = clk_register_mux(NULL, "clcd_mclk", clcd_parents,
ARRAY_SIZE(clcd_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, CLCD_CLK_SHIFT, CLCD_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "clcd_mclk", NULL);
clk = clk_register_gate(NULL, "clcd_clk", "clcd_mclk", 0,
PERIP1_CLK_ENB, CLCD_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "clcd");
clk = clk_register_gpt("gpt0_1_syn_clk", "pll1_clk", 0, PRSC0_CLK_CFG,
gpt_rtbl, ARRAY_SIZE(gpt_rtbl), &_lock);
clk_register_clkdev(clk, "gpt0_1_syn_clk", NULL);
clk = clk_register_mux(NULL, "gpt0_mclk", gpt0_1_parents,
ARRAY_SIZE(gpt0_1_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, GPT0_CLK_SHIFT, GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, NULL, "gpt0");
clk = clk_register_mux(NULL, "gpt1_mclk", gpt0_1_parents,
ARRAY_SIZE(gpt0_1_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, GPT1_CLK_SHIFT, GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt1_mclk", NULL);
clk = clk_register_gate(NULL, "gpt1_clk", "gpt1_mclk", 0,
PERIP1_CLK_ENB, GPT1_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "gpt1");
clk = clk_register_gpt("gpt2_syn_clk", "pll1_clk", 0, PRSC1_CLK_CFG,
gpt_rtbl, ARRAY_SIZE(gpt_rtbl), &_lock);
clk_register_clkdev(clk, "gpt2_syn_clk", NULL);
clk = clk_register_mux(NULL, "gpt2_mclk", gpt2_parents,
ARRAY_SIZE(gpt2_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, GPT2_CLK_SHIFT, GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt2_mclk", NULL);
clk = clk_register_gate(NULL, "gpt2_clk", "gpt2_mclk", 0,
PERIP1_CLK_ENB, GPT2_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "gpt2");
clk = clk_register_gpt("gpt3_syn_clk", "pll1_clk", 0, PRSC2_CLK_CFG,
gpt_rtbl, ARRAY_SIZE(gpt_rtbl), &_lock);
clk_register_clkdev(clk, "gpt3_syn_clk", NULL);
clk = clk_register_mux(NULL, "gpt3_mclk", gpt3_parents,
ARRAY_SIZE(gpt3_parents), CLK_SET_RATE_NO_REPARENT,
PERIP_CLK_CFG, GPT3_CLK_SHIFT, GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt3_mclk", NULL);
clk = clk_register_gate(NULL, "gpt3_clk", "gpt3_mclk", 0,
PERIP1_CLK_ENB, GPT3_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "gpt3");
clk = clk_register_gate(NULL, "usbh0_clk", "pll3_clk", 0,
PERIP1_CLK_ENB, USBH0_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e1800000.ehci");
clk_register_clkdev(clk, NULL, "e1900000.ohci");
clk = clk_register_gate(NULL, "usbh1_clk", "pll3_clk", 0,
PERIP1_CLK_ENB, USBH1_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e2000000.ehci");
clk_register_clkdev(clk, NULL, "e2100000.ohci");
clk = clk_register_gate(NULL, "usbd_clk", "pll3_clk", 0, PERIP1_CLK_ENB,
USBD_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "designware_udc");
clk = clk_register_fixed_factor(NULL, "ahbmult2_clk", "ahb_clk", 0, 2,
1);
clk_register_clkdev(clk, "ahbmult2_clk", NULL);
clk = clk_register_mux(NULL, "ddr_clk", ddr_parents,
ARRAY_SIZE(ddr_parents), CLK_SET_RATE_NO_REPARENT,
PLL_CLK_CFG, MCTR_CLK_SHIFT, MCTR_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "ddr_clk", NULL);
clk = clk_register_divider(NULL, "apb_clk", "ahb_clk",
CLK_SET_RATE_PARENT, CORE_CLK_CFG, PCLK_RATIO_SHIFT,
PCLK_RATIO_MASK, 0, &_lock);
clk_register_clkdev(clk, "apb_clk", NULL);
clk = clk_register_gate(NULL, "dma_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
DMA_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "fc400000.dma");
clk = clk_register_gate(NULL, "fsmc_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
FSMC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d1800000.flash");
clk = clk_register_gate(NULL, "gmac_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
GMAC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e0800000.ethernet");
clk = clk_register_gate(NULL, "i2c_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
I2C_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d0200000.i2c");
clk = clk_register_gate(NULL, "jpeg_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
JPEG_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "jpeg");
clk = clk_register_gate(NULL, "smi_clk", "ahb_clk", 0, PERIP1_CLK_ENB,
SMI_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "fc000000.flash");
clk = clk_register_gate(NULL, "adc_clk", "apb_clk", 0, PERIP1_CLK_ENB,
ADC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "adc");
clk = clk_register_fixed_factor(NULL, "gpio0_clk", "apb_clk", 0, 1, 1);
clk_register_clkdev(clk, NULL, "f0100000.gpio");
clk = clk_register_gate(NULL, "gpio1_clk", "apb_clk", 0, PERIP1_CLK_ENB,
GPIO1_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "fc980000.gpio");
clk = clk_register_gate(NULL, "gpio2_clk", "apb_clk", 0, PERIP1_CLK_ENB,
GPIO2_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d8100000.gpio");
clk = clk_register_gate(NULL, "ssp0_clk", "apb_clk", 0, PERIP1_CLK_ENB,
SSP0_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "ssp-pl022.0");
clk = clk_register_gate(NULL, "ssp1_clk", "apb_clk", 0, PERIP1_CLK_ENB,
SSP1_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "ssp-pl022.1");
clk = clk_register_gate(NULL, "ssp2_clk", "apb_clk", 0, PERIP1_CLK_ENB,
SSP2_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "ssp-pl022.2");
}
