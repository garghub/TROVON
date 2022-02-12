void __init spear1310_clk_init(void)
{
struct clk *clk, *clk1;
clk = clk_register_fixed_rate(NULL, "osc_32k_clk", NULL, CLK_IS_ROOT,
32000);
clk_register_clkdev(clk, "osc_32k_clk", NULL);
clk = clk_register_fixed_rate(NULL, "osc_24m_clk", NULL, CLK_IS_ROOT,
24000000);
clk_register_clkdev(clk, "osc_24m_clk", NULL);
clk = clk_register_fixed_rate(NULL, "osc_25m_clk", NULL, CLK_IS_ROOT,
25000000);
clk_register_clkdev(clk, "osc_25m_clk", NULL);
clk = clk_register_fixed_rate(NULL, "gmii_pad_clk", NULL, CLK_IS_ROOT,
125000000);
clk_register_clkdev(clk, "gmii_pad_clk", NULL);
clk = clk_register_fixed_rate(NULL, "i2s_src_pad_clk", NULL,
CLK_IS_ROOT, 12288000);
clk_register_clkdev(clk, "i2s_src_pad_clk", NULL);
clk = clk_register_gate(NULL, "rtc-spear", "osc_32k_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_RTC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0580000.rtc");
clk = clk_register_mux(NULL, "vco1_mclk", vco_parents,
ARRAY_SIZE(vco_parents), 0, SPEAR1310_PLL_CFG,
SPEAR1310_PLL1_CLK_SHIFT, SPEAR1310_PLL_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "vco1_mclk", NULL);
clk = clk_register_vco_pll("vco1_clk", "pll1_clk", NULL, "vco1_mclk",
0, SPEAR1310_PLL1_CTR, SPEAR1310_PLL1_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco1_clk", NULL);
clk_register_clkdev(clk1, "pll1_clk", NULL);
clk = clk_register_mux(NULL, "vco2_mclk", vco_parents,
ARRAY_SIZE(vco_parents), 0, SPEAR1310_PLL_CFG,
SPEAR1310_PLL2_CLK_SHIFT, SPEAR1310_PLL_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "vco2_mclk", NULL);
clk = clk_register_vco_pll("vco2_clk", "pll2_clk", NULL, "vco2_mclk",
0, SPEAR1310_PLL2_CTR, SPEAR1310_PLL2_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco2_clk", NULL);
clk_register_clkdev(clk1, "pll2_clk", NULL);
clk = clk_register_mux(NULL, "vco3_mclk", vco_parents,
ARRAY_SIZE(vco_parents), 0, SPEAR1310_PLL_CFG,
SPEAR1310_PLL3_CLK_SHIFT, SPEAR1310_PLL_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "vco3_mclk", NULL);
clk = clk_register_vco_pll("vco3_clk", "pll3_clk", NULL, "vco3_mclk",
0, SPEAR1310_PLL3_CTR, SPEAR1310_PLL3_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco3_clk", NULL);
clk_register_clkdev(clk1, "pll3_clk", NULL);
clk = clk_register_vco_pll("vco4_clk", "pll4_clk", NULL, "osc_24m_clk",
0, SPEAR1310_PLL4_CTR, SPEAR1310_PLL4_FRQ, pll4_rtbl,
ARRAY_SIZE(pll4_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco4_clk", NULL);
clk_register_clkdev(clk1, "pll4_clk", NULL);
clk = clk_register_fixed_rate(NULL, "pll5_clk", "osc_24m_clk", 0,
48000000);
clk_register_clkdev(clk, "pll5_clk", NULL);
clk = clk_register_fixed_rate(NULL, "pll6_clk", "osc_25m_clk", 0,
25000000);
clk_register_clkdev(clk, "pll6_clk", NULL);
clk = clk_register_fixed_factor(NULL, "vco1div2_clk", "vco1_clk", 0, 1,
2);
clk_register_clkdev(clk, "vco1div2_clk", NULL);
clk = clk_register_fixed_factor(NULL, "vco1div4_clk", "vco1_clk", 0, 1,
4);
clk_register_clkdev(clk, "vco1div4_clk", NULL);
clk = clk_register_fixed_factor(NULL, "vco2div2_clk", "vco2_clk", 0, 1,
2);
clk_register_clkdev(clk, "vco2div2_clk", NULL);
clk = clk_register_fixed_factor(NULL, "vco3div2_clk", "vco3_clk", 0, 1,
2);
clk_register_clkdev(clk, "vco3div2_clk", NULL);
clk_register_fixed_factor(NULL, "thermal_clk", "osc_24m_clk", 0, 1,
128);
clk = clk_register_gate(NULL, "thermal_gclk", "thermal_clk", 0,
SPEAR1310_PERIP2_CLK_ENB, SPEAR1310_THSENS_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "spear_thermal");
clk = clk_register_fixed_factor(NULL, "ddr_clk", "pll4_clk", 0, 1,
1);
clk_register_clkdev(clk, "ddr_clk", NULL);
clk = clk_register_fixed_factor(NULL, "cpu_clk", "pll1_clk",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "cpu_clk", NULL);
clk = clk_register_fixed_factor(NULL, "wdt_clk", "cpu_clk", 0, 1,
2);
clk_register_clkdev(clk, NULL, "ec800620.wdt");
clk = clk_register_fixed_factor(NULL, "smp_twd_clk", "cpu_clk", 0, 1,
2);
clk_register_clkdev(clk, NULL, "smp_twd");
clk = clk_register_fixed_factor(NULL, "ahb_clk", "pll1_clk", 0, 1,
6);
clk_register_clkdev(clk, "ahb_clk", NULL);
clk = clk_register_fixed_factor(NULL, "apb_clk", "pll1_clk", 0, 1,
12);
clk_register_clkdev(clk, "apb_clk", NULL);
clk = clk_register_mux(NULL, "gpt0_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), 0, SPEAR1310_PERIP_CLK_CFG,
SPEAR1310_GPT0_CLK_SHIFT, SPEAR1310_GPT_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "gpt0_mclk", NULL);
clk = clk_register_gate(NULL, "gpt0_clk", "gpt0_mclk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_GPT0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt0");
clk = clk_register_mux(NULL, "gpt1_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), 0, SPEAR1310_PERIP_CLK_CFG,
SPEAR1310_GPT1_CLK_SHIFT, SPEAR1310_GPT_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "gpt1_mclk", NULL);
clk = clk_register_gate(NULL, "gpt1_clk", "gpt1_mclk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_GPT1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt1");
clk = clk_register_mux(NULL, "gpt2_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), 0, SPEAR1310_PERIP_CLK_CFG,
SPEAR1310_GPT2_CLK_SHIFT, SPEAR1310_GPT_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "gpt2_mclk", NULL);
clk = clk_register_gate(NULL, "gpt2_clk", "gpt2_mclk", 0,
SPEAR1310_PERIP2_CLK_ENB, SPEAR1310_GPT2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt2");
clk = clk_register_mux(NULL, "gpt3_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), 0, SPEAR1310_PERIP_CLK_CFG,
SPEAR1310_GPT3_CLK_SHIFT, SPEAR1310_GPT_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "gpt3_mclk", NULL);
clk = clk_register_gate(NULL, "gpt3_clk", "gpt3_mclk", 0,
SPEAR1310_PERIP2_CLK_ENB, SPEAR1310_GPT3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt3");
clk = clk_register_aux("uart_syn_clk", "uart_syn_gclk", "vco1div2_clk",
0, SPEAR1310_UART_CLK_SYNT, NULL, aux_rtbl,
ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "uart_syn_clk", NULL);
clk_register_clkdev(clk1, "uart_syn_gclk", NULL);
clk = clk_register_mux(NULL, "uart0_mclk", uart0_parents,
ARRAY_SIZE(uart0_parents), CLK_SET_RATE_PARENT,
SPEAR1310_PERIP_CLK_CFG, SPEAR1310_UART_CLK_SHIFT,
SPEAR1310_UART_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "uart0_mclk", NULL);
clk = clk_register_gate(NULL, "uart0_clk", "uart0_mclk",
CLK_SET_RATE_PARENT, SPEAR1310_PERIP1_CLK_ENB,
SPEAR1310_UART_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e0000000.serial");
clk = clk_register_aux("sdhci_syn_clk", "sdhci_syn_gclk",
"vco1div2_clk", 0, SPEAR1310_SDHCI_CLK_SYNT, NULL,
aux_rtbl, ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "sdhci_syn_clk", NULL);
clk_register_clkdev(clk1, "sdhci_syn_gclk", NULL);
clk = clk_register_gate(NULL, "sdhci_clk", "sdhci_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1310_PERIP1_CLK_ENB,
SPEAR1310_SDHCI_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "b3000000.sdhci");
clk = clk_register_aux("cfxd_syn_clk", "cfxd_syn_gclk", "vco1div2_clk",
0, SPEAR1310_CFXD_CLK_SYNT, NULL, aux_rtbl,
ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "cfxd_syn_clk", NULL);
clk_register_clkdev(clk1, "cfxd_syn_gclk", NULL);
clk = clk_register_gate(NULL, "cfxd_clk", "cfxd_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1310_PERIP1_CLK_ENB,
SPEAR1310_CFXD_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "b2800000.cf");
clk_register_clkdev(clk, NULL, "arasan_xd");
clk = clk_register_aux("c3_syn_clk", "c3_syn_gclk", "vco1div2_clk",
0, SPEAR1310_C3_CLK_SYNT, NULL, aux_rtbl,
ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "c3_syn_clk", NULL);
clk_register_clkdev(clk1, "c3_syn_gclk", NULL);
clk = clk_register_mux(NULL, "c3_mclk", c3_parents,
ARRAY_SIZE(c3_parents), CLK_SET_RATE_PARENT,
SPEAR1310_PERIP_CLK_CFG, SPEAR1310_C3_CLK_SHIFT,
SPEAR1310_C3_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "c3_mclk", NULL);
clk = clk_register_gate(NULL, "c3_clk", "c3_mclk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_C3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "c3");
clk = clk_register_mux(NULL, "phy_input_mclk", gmac_phy_input_parents,
ARRAY_SIZE(gmac_phy_input_parents), 0,
SPEAR1310_GMAC_CLK_CFG,
SPEAR1310_GMAC_PHY_INPUT_CLK_SHIFT,
SPEAR1310_GMAC_PHY_INPUT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "phy_input_mclk", NULL);
clk = clk_register_aux("phy_syn_clk", "phy_syn_gclk", "phy_input_mclk",
0, SPEAR1310_GMAC_CLK_SYNT, NULL, gmac_rtbl,
ARRAY_SIZE(gmac_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "phy_syn_clk", NULL);
clk_register_clkdev(clk1, "phy_syn_gclk", NULL);
clk = clk_register_mux(NULL, "phy_mclk", gmac_phy_parents,
ARRAY_SIZE(gmac_phy_parents), 0,
SPEAR1310_PERIP_CLK_CFG, SPEAR1310_GMAC_PHY_CLK_SHIFT,
SPEAR1310_GMAC_PHY_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "stmmacphy.0", NULL);
clk = clk_register_mux(NULL, "clcd_syn_mclk", clcd_synth_parents,
ARRAY_SIZE(clcd_synth_parents), 0,
SPEAR1310_CLCD_CLK_SYNT, SPEAR1310_CLCD_SYNT_CLK_SHIFT,
SPEAR1310_CLCD_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "clcd_syn_mclk", NULL);
clk = clk_register_frac("clcd_syn_clk", "clcd_syn_mclk", 0,
SPEAR1310_CLCD_CLK_SYNT, clcd_rtbl,
ARRAY_SIZE(clcd_rtbl), &_lock);
clk_register_clkdev(clk, "clcd_syn_clk", NULL);
clk = clk_register_mux(NULL, "clcd_pixel_mclk", clcd_pixel_parents,
ARRAY_SIZE(clcd_pixel_parents), CLK_SET_RATE_PARENT,
SPEAR1310_PERIP_CLK_CFG, SPEAR1310_CLCD_CLK_SHIFT,
SPEAR1310_CLCD_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "clcd_pixel_mclk", NULL);
clk = clk_register_gate(NULL, "clcd_clk", "clcd_pixel_mclk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_CLCD_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e1000000.clcd");
clk = clk_register_mux(NULL, "i2s_src_mclk", i2s_src_parents,
ARRAY_SIZE(i2s_src_parents), 0, SPEAR1310_I2S_CLK_CFG,
SPEAR1310_I2S_SRC_CLK_SHIFT, SPEAR1310_I2S_SRC_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "i2s_src_mclk", NULL);
clk = clk_register_aux("i2s_prs1_clk", NULL, "i2s_src_mclk", 0,
SPEAR1310_I2S_CLK_CFG, &i2s_prs1_masks, i2s_prs1_rtbl,
ARRAY_SIZE(i2s_prs1_rtbl), &_lock, NULL);
clk_register_clkdev(clk, "i2s_prs1_clk", NULL);
clk = clk_register_mux(NULL, "i2s_ref_mclk", i2s_ref_parents,
ARRAY_SIZE(i2s_ref_parents), CLK_SET_RATE_PARENT,
SPEAR1310_I2S_CLK_CFG, SPEAR1310_I2S_REF_SHIFT,
SPEAR1310_I2S_REF_SEL_MASK, 0, &_lock);
clk_register_clkdev(clk, "i2s_ref_mclk", NULL);
clk = clk_register_gate(NULL, "i2s_ref_pad_clk", "i2s_ref_mclk", 0,
SPEAR1310_PERIP2_CLK_ENB, SPEAR1310_I2S_REF_PAD_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, "i2s_ref_pad_clk", NULL);
clk = clk_register_aux("i2s_sclk_clk", "i2s_sclk_gclk",
"i2s_ref_mclk", 0, SPEAR1310_I2S_CLK_CFG,
&i2s_sclk_masks, i2s_sclk_rtbl,
ARRAY_SIZE(i2s_sclk_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "i2s_sclk_clk", NULL);
clk_register_clkdev(clk1, "i2s_sclk_gclk", NULL);
clk = clk_register_gate(NULL, "i2c0_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_I2C0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0280000.i2c");
clk = clk_register_gate(NULL, "dma_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_DMA_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "ea800000.dma");
clk_register_clkdev(clk, NULL, "eb000000.dma");
clk = clk_register_gate(NULL, "jpeg_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_JPEG_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b2000000.jpeg");
clk = clk_register_gate(NULL, "gmac_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_GMAC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e2000000.eth");
clk = clk_register_gate(NULL, "fsmc_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_FSMC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b0000000.flash");
clk = clk_register_gate(NULL, "smi_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_SMI_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "ea000000.flash");
clk = clk_register_gate(NULL, "usbh0_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_UHC0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e4000000.ohci");
clk_register_clkdev(clk, NULL, "e4800000.ehci");
clk = clk_register_gate(NULL, "usbh1_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_UHC1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e5000000.ohci");
clk_register_clkdev(clk, NULL, "e5800000.ehci");
clk = clk_register_gate(NULL, "uoc_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_UOC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e3800000.otg");
clk = clk_register_gate(NULL, "pcie_sata_0_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_PCIE_SATA_0_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "dw_pcie.0");
clk_register_clkdev(clk, NULL, "b1000000.ahci");
clk = clk_register_gate(NULL, "pcie_sata_1_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_PCIE_SATA_1_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "dw_pcie.1");
clk_register_clkdev(clk, NULL, "b1800000.ahci");
clk = clk_register_gate(NULL, "pcie_sata_2_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_PCIE_SATA_2_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "dw_pcie.2");
clk_register_clkdev(clk, NULL, "b4000000.ahci");
clk = clk_register_gate(NULL, "sysram0_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_SYSRAM0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "sysram0_clk", NULL);
clk = clk_register_gate(NULL, "sysram1_clk", "ahb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_SYSRAM1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "sysram1_clk", NULL);
clk = clk_register_aux("adc_syn_clk", "adc_syn_gclk", "ahb_clk",
0, SPEAR1310_ADC_CLK_SYNT, NULL, adc_rtbl,
ARRAY_SIZE(adc_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "adc_syn_clk", NULL);
clk_register_clkdev(clk1, "adc_syn_gclk", NULL);
clk = clk_register_gate(NULL, "adc_clk", "adc_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1310_PERIP1_CLK_ENB,
SPEAR1310_ADC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e0080000.adc");
clk = clk_register_gate(NULL, "ssp0_clk", "apb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_SSP_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0100000.spi");
clk = clk_register_gate(NULL, "gpio0_clk", "apb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_GPIO0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0600000.gpio");
clk = clk_register_gate(NULL, "gpio1_clk", "apb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_GPIO1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0680000.gpio");
clk = clk_register_gate(NULL, "i2s0_clk", "apb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_I2S0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0180000.i2s");
clk = clk_register_gate(NULL, "i2s1_clk", "apb_clk", 0,
SPEAR1310_PERIP1_CLK_ENB, SPEAR1310_I2S1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0200000.i2s");
clk = clk_register_gate(NULL, "kbd_clk", "apb_clk", 0,
SPEAR1310_PERIP2_CLK_ENB, SPEAR1310_KBD_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0300000.kbd");
clk = clk_register_mux(NULL, "gen_syn0_1_mclk", gen_synth0_1_parents,
ARRAY_SIZE(gen_synth0_1_parents), 0, SPEAR1310_PLL_CFG,
SPEAR1310_RAS_SYNT0_1_CLK_SHIFT,
SPEAR1310_RAS_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gen_syn0_1_clk", NULL);
clk = clk_register_mux(NULL, "gen_syn2_3_mclk", gen_synth2_3_parents,
ARRAY_SIZE(gen_synth2_3_parents), 0, SPEAR1310_PLL_CFG,
SPEAR1310_RAS_SYNT2_3_CLK_SHIFT,
SPEAR1310_RAS_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gen_syn2_3_clk", NULL);
clk = clk_register_frac("gen_syn0_clk", "gen_syn0_1_clk", 0,
SPEAR1310_RAS_CLK_SYNT0, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn0_clk", NULL);
clk = clk_register_frac("gen_syn1_clk", "gen_syn0_1_clk", 0,
SPEAR1310_RAS_CLK_SYNT1, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn1_clk", NULL);
clk = clk_register_frac("gen_syn2_clk", "gen_syn2_3_clk", 0,
SPEAR1310_RAS_CLK_SYNT2, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn2_clk", NULL);
clk = clk_register_frac("gen_syn3_clk", "gen_syn2_3_clk", 0,
SPEAR1310_RAS_CLK_SYNT3, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn3_clk", NULL);
clk = clk_register_gate(NULL, "ras_osc_24m_clk", "osc_24m_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_OSC_24M_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_osc_24m_clk", NULL);
clk = clk_register_gate(NULL, "ras_osc_25m_clk", "osc_25m_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_OSC_25M_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_osc_25m_clk", NULL);
clk = clk_register_gate(NULL, "ras_osc_32k_clk", "osc_32k_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_OSC_32K_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_osc_32k_clk", NULL);
clk = clk_register_gate(NULL, "ras_pll2_clk", "pll2_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_PLL2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_pll2_clk", NULL);
clk = clk_register_gate(NULL, "ras_pll3_clk", "pll3_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_PLL3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_pll3_clk", NULL);
clk = clk_register_gate(NULL, "ras_tx125_clk", "gmii_pad_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_C125M_PAD_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_tx125_clk", NULL);
clk = clk_register_fixed_rate(NULL, "ras_30m_fixed_clk", "pll5_clk", 0,
30000000);
clk = clk_register_gate(NULL, "ras_30m_clk", "ras_30m_fixed_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_C30M_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_30m_clk", NULL);
clk = clk_register_fixed_rate(NULL, "ras_48m_fixed_clk", "pll5_clk", 0,
48000000);
clk = clk_register_gate(NULL, "ras_48m_clk", "ras_48m_fixed_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_C48M_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_48m_clk", NULL);
clk = clk_register_gate(NULL, "ras_ahb_clk", "ahb_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_ACLK_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_ahb_clk", NULL);
clk = clk_register_gate(NULL, "ras_apb_clk", "apb_clk", 0,
SPEAR1310_RAS_CLK_ENB, SPEAR1310_PCLK_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "ras_apb_clk", NULL);
clk = clk_register_fixed_rate(NULL, "ras_plclk0_clk", NULL, CLK_IS_ROOT,
50000000);
clk = clk_register_fixed_rate(NULL, "ras_tx50_clk", NULL, CLK_IS_ROOT,
50000000);
clk = clk_register_gate(NULL, "can0_clk", "apb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_CAN0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "c_can_platform.0");
clk = clk_register_gate(NULL, "can1_clk", "apb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_CAN1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "c_can_platform.1");
clk = clk_register_gate(NULL, "ras_smii0_clk", "ras_ahb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_MII0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c400000.eth");
clk = clk_register_gate(NULL, "ras_smii1_clk", "ras_ahb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_MII1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c500000.eth");
clk = clk_register_gate(NULL, "ras_smii2_clk", "ras_ahb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_MII2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c600000.eth");
clk = clk_register_gate(NULL, "ras_rgmii_clk", "ras_ahb_clk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_GMII_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c700000.eth");
clk = clk_register_mux(NULL, "smii_rgmii_phy_mclk",
smii_rgmii_phy_parents,
ARRAY_SIZE(smii_rgmii_phy_parents), 0,
SPEAR1310_RAS_CTRL_REG1,
SPEAR1310_SMII_RGMII_PHY_CLK_SHIFT,
SPEAR1310_PHY_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "stmmacphy.1", NULL);
clk_register_clkdev(clk, "stmmacphy.2", NULL);
clk_register_clkdev(clk, "stmmacphy.4", NULL);
clk = clk_register_mux(NULL, "rmii_phy_mclk", rmii_phy_parents,
ARRAY_SIZE(rmii_phy_parents), 0,
SPEAR1310_RAS_CTRL_REG1, SPEAR1310_RMII_PHY_CLK_SHIFT,
SPEAR1310_PHY_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "stmmacphy.3", NULL);
clk = clk_register_mux(NULL, "uart1_mclk", uart_parents,
ARRAY_SIZE(uart_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_UART1_CLK_SHIFT, SPEAR1310_RAS_UART_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "uart1_mclk", NULL);
clk = clk_register_gate(NULL, "uart1_clk", "uart1_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_UART1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c800000.serial");
clk = clk_register_mux(NULL, "uart2_mclk", uart_parents,
ARRAY_SIZE(uart_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_UART2_CLK_SHIFT, SPEAR1310_RAS_UART_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "uart2_mclk", NULL);
clk = clk_register_gate(NULL, "uart2_clk", "uart2_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_UART2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5c900000.serial");
clk = clk_register_mux(NULL, "uart3_mclk", uart_parents,
ARRAY_SIZE(uart_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_UART3_CLK_SHIFT, SPEAR1310_RAS_UART_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "uart3_mclk", NULL);
clk = clk_register_gate(NULL, "uart3_clk", "uart3_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_UART3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5ca00000.serial");
clk = clk_register_mux(NULL, "uart4_mclk", uart_parents,
ARRAY_SIZE(uart_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_UART4_CLK_SHIFT, SPEAR1310_RAS_UART_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "uart4_mclk", NULL);
clk = clk_register_gate(NULL, "uart4_clk", "uart4_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_UART4_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5cb00000.serial");
clk = clk_register_mux(NULL, "uart5_mclk", uart_parents,
ARRAY_SIZE(uart_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_UART5_CLK_SHIFT, SPEAR1310_RAS_UART_CLK_MASK,
0, &_lock);
clk_register_clkdev(clk, "uart5_mclk", NULL);
clk = clk_register_gate(NULL, "uart5_clk", "uart5_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_UART5_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5cc00000.serial");
clk = clk_register_mux(NULL, "i2c1_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C1_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c1_mclk", NULL);
clk = clk_register_gate(NULL, "i2c1_clk", "i2c1_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5cd00000.i2c");
clk = clk_register_mux(NULL, "i2c2_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C2_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c2_mclk", NULL);
clk = clk_register_gate(NULL, "i2c2_clk", "i2c2_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5ce00000.i2c");
clk = clk_register_mux(NULL, "i2c3_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C3_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c3_mclk", NULL);
clk = clk_register_gate(NULL, "i2c3_clk", "i2c3_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5cf00000.i2c");
clk = clk_register_mux(NULL, "i2c4_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C4_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c4_mclk", NULL);
clk = clk_register_gate(NULL, "i2c4_clk", "i2c4_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C4_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5d000000.i2c");
clk = clk_register_mux(NULL, "i2c5_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C5_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c5_mclk", NULL);
clk = clk_register_gate(NULL, "i2c5_clk", "i2c5_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C5_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5d100000.i2c");
clk = clk_register_mux(NULL, "i2c6_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C6_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c6_mclk", NULL);
clk = clk_register_gate(NULL, "i2c6_clk", "i2c6_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C6_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5d200000.i2c");
clk = clk_register_mux(NULL, "i2c7_mclk", i2c_parents,
ARRAY_SIZE(i2c_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_I2C7_CLK_SHIFT, SPEAR1310_I2C_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "i2c7_mclk", NULL);
clk = clk_register_gate(NULL, "i2c7_clk", "i2c7_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_I2C7_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5d300000.i2c");
clk = clk_register_mux(NULL, "ssp1_mclk", ssp1_parents,
ARRAY_SIZE(ssp1_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_SSP1_CLK_SHIFT, SPEAR1310_SSP1_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "ssp1_mclk", NULL);
clk = clk_register_gate(NULL, "ssp1_clk", "ssp1_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_SSP1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "5d400000.spi");
clk = clk_register_mux(NULL, "pci_mclk", pci_parents,
ARRAY_SIZE(pci_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_PCI_CLK_SHIFT, SPEAR1310_PCI_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "pci_mclk", NULL);
clk = clk_register_gate(NULL, "pci_clk", "pci_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_PCI_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "pci");
clk = clk_register_mux(NULL, "tdm1_mclk", tdm_parents,
ARRAY_SIZE(tdm_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_TDM1_CLK_SHIFT, SPEAR1310_TDM_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "tdm1_mclk", NULL);
clk = clk_register_gate(NULL, "tdm1_clk", "tdm1_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_TDM1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "tdm_hdlc.0");
clk = clk_register_mux(NULL, "tdm2_mclk", tdm_parents,
ARRAY_SIZE(tdm_parents), 0, SPEAR1310_RAS_CTRL_REG0,
SPEAR1310_TDM2_CLK_SHIFT, SPEAR1310_TDM_CLK_MASK, 0,
&_lock);
clk_register_clkdev(clk, "tdm2_mclk", NULL);
clk = clk_register_gate(NULL, "tdm2_clk", "tdm2_mclk", 0,
SPEAR1310_RAS_SW_CLK_CTRL, SPEAR1310_TDM2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "tdm_hdlc.1");
}
