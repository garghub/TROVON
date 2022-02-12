void __init spear1340_clk_init(void __iomem *misc_base)
{
struct clk *clk, *clk1;
clk = clk_register_fixed_rate(NULL, "osc_32k_clk", NULL, 0, 32000);
clk_register_clkdev(clk, "osc_32k_clk", NULL);
clk = clk_register_fixed_rate(NULL, "osc_24m_clk", NULL, 0, 24000000);
clk_register_clkdev(clk, "osc_24m_clk", NULL);
clk = clk_register_fixed_rate(NULL, "osc_25m_clk", NULL, 0, 25000000);
clk_register_clkdev(clk, "osc_25m_clk", NULL);
clk = clk_register_fixed_rate(NULL, "gmii_pad_clk", NULL, 0, 125000000);
clk_register_clkdev(clk, "gmii_pad_clk", NULL);
clk = clk_register_fixed_rate(NULL, "i2s_src_pad_clk", NULL, 0,
12288000);
clk_register_clkdev(clk, "i2s_src_pad_clk", NULL);
clk = clk_register_gate(NULL, "rtc-spear", "osc_32k_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_RTC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0580000.rtc");
clk = clk_register_mux(NULL, "vco1_mclk", vco_parents,
ARRAY_SIZE(vco_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PLL_CFG, SPEAR1340_PLL1_CLK_SHIFT,
SPEAR1340_PLL_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "vco1_mclk", NULL);
clk = clk_register_vco_pll("vco1_clk", "pll1_clk", NULL, "vco1_mclk", 0,
SPEAR1340_PLL1_CTR, SPEAR1340_PLL1_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco1_clk", NULL);
clk_register_clkdev(clk1, "pll1_clk", NULL);
clk = clk_register_mux(NULL, "vco2_mclk", vco_parents,
ARRAY_SIZE(vco_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PLL_CFG, SPEAR1340_PLL2_CLK_SHIFT,
SPEAR1340_PLL_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "vco2_mclk", NULL);
clk = clk_register_vco_pll("vco2_clk", "pll2_clk", NULL, "vco2_mclk", 0,
SPEAR1340_PLL2_CTR, SPEAR1340_PLL2_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco2_clk", NULL);
clk_register_clkdev(clk1, "pll2_clk", NULL);
clk = clk_register_mux(NULL, "vco3_mclk", vco_parents,
ARRAY_SIZE(vco_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PLL_CFG, SPEAR1340_PLL3_CLK_SHIFT,
SPEAR1340_PLL_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "vco3_mclk", NULL);
clk = clk_register_vco_pll("vco3_clk", "pll3_clk", NULL, "vco3_mclk", 0,
SPEAR1340_PLL3_CTR, SPEAR1340_PLL3_FRQ, pll_rtbl,
ARRAY_SIZE(pll_rtbl), &_lock, &clk1, NULL);
clk_register_clkdev(clk, "vco3_clk", NULL);
clk_register_clkdev(clk1, "pll3_clk", NULL);
clk = clk_register_vco_pll("vco4_clk", "pll4_clk", NULL, "osc_24m_clk",
0, SPEAR1340_PLL4_CTR, SPEAR1340_PLL4_FRQ, pll4_rtbl,
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
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_THSENS_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e07008c4.thermal");
clk = clk_register_fixed_factor(NULL, "ddr_clk", "pll4_clk", 0, 1,
1);
clk_register_clkdev(clk, "ddr_clk", NULL);
clk = clk_register_frac("sys_syn_clk", "vco1div2_clk", 0,
SPEAR1340_SYS_CLK_SYNT, sys_synth_rtbl,
ARRAY_SIZE(sys_synth_rtbl), &_lock);
clk_register_clkdev(clk, "sys_syn_clk", NULL);
clk = clk_register_frac("amba_syn_clk", "vco1div2_clk", 0,
SPEAR1340_AMBA_CLK_SYNT, amba_synth_rtbl,
ARRAY_SIZE(amba_synth_rtbl), &_lock);
clk_register_clkdev(clk, "amba_syn_clk", NULL);
clk = clk_register_mux(NULL, "sys_mclk", sys_parents,
ARRAY_SIZE(sys_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_SYS_CLK_CTRL, SPEAR1340_SCLK_SRC_SEL_SHIFT,
SPEAR1340_SCLK_SRC_SEL_MASK, 0, &_lock);
clk_register_clkdev(clk, "sys_mclk", NULL);
clk = clk_register_fixed_factor(NULL, "cpu_clk", "sys_mclk", 0, 1,
2);
clk_register_clkdev(clk, "cpu_clk", NULL);
clk = clk_register_fixed_factor(NULL, "cpu_div3_clk", "cpu_clk", 0, 1,
3);
clk_register_clkdev(clk, "cpu_div3_clk", NULL);
clk = clk_register_fixed_factor(NULL, "wdt_clk", "cpu_clk", 0, 1,
2);
clk_register_clkdev(clk, NULL, "ec800620.wdt");
clk = clk_register_fixed_factor(NULL, "smp_twd_clk", "cpu_clk", 0, 1,
2);
clk_register_clkdev(clk, NULL, "smp_twd");
clk = clk_register_mux(NULL, "ahb_clk", ahb_parents,
ARRAY_SIZE(ahb_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_SYS_CLK_CTRL, SPEAR1340_HCLK_SRC_SEL_SHIFT,
SPEAR1340_HCLK_SRC_SEL_MASK, 0, &_lock);
clk_register_clkdev(clk, "ahb_clk", NULL);
clk = clk_register_fixed_factor(NULL, "apb_clk", "ahb_clk", 0, 1,
2);
clk_register_clkdev(clk, "apb_clk", NULL);
clk = clk_register_mux(NULL, "gpt0_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_GPT0_CLK_SHIFT,
SPEAR1340_GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt0_mclk", NULL);
clk = clk_register_gate(NULL, "gpt0_clk", "gpt0_mclk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_GPT0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt0");
clk = clk_register_mux(NULL, "gpt1_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_GPT1_CLK_SHIFT,
SPEAR1340_GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt1_mclk", NULL);
clk = clk_register_gate(NULL, "gpt1_clk", "gpt1_mclk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_GPT1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt1");
clk = clk_register_mux(NULL, "gpt2_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_GPT2_CLK_SHIFT,
SPEAR1340_GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt2_mclk", NULL);
clk = clk_register_gate(NULL, "gpt2_clk", "gpt2_mclk", 0,
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_GPT2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt2");
clk = clk_register_mux(NULL, "gpt3_mclk", gpt_parents,
ARRAY_SIZE(gpt_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_GPT3_CLK_SHIFT,
SPEAR1340_GPT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gpt3_mclk", NULL);
clk = clk_register_gate(NULL, "gpt3_clk", "gpt3_mclk", 0,
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_GPT3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "gpt3");
clk = clk_register_aux("uart0_syn_clk", "uart0_syn_gclk",
"vco1div2_clk", 0, SPEAR1340_UART0_CLK_SYNT, NULL,
aux_rtbl, ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "uart0_syn_clk", NULL);
clk_register_clkdev(clk1, "uart0_syn_gclk", NULL);
clk = clk_register_mux(NULL, "uart0_mclk", uart0_parents,
ARRAY_SIZE(uart0_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_UART0_CLK_SHIFT,
SPEAR1340_UART_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "uart0_mclk", NULL);
clk = clk_register_gate(NULL, "uart0_clk", "uart0_mclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP1_CLK_ENB,
SPEAR1340_UART0_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e0000000.serial");
clk = clk_register_aux("uart1_syn_clk", "uart1_syn_gclk",
"vco1div2_clk", 0, SPEAR1340_UART1_CLK_SYNT, NULL,
aux_rtbl, ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "uart1_syn_clk", NULL);
clk_register_clkdev(clk1, "uart1_syn_gclk", NULL);
clk = clk_register_mux(NULL, "uart1_mclk", uart1_parents,
ARRAY_SIZE(uart1_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_UART1_CLK_SHIFT,
SPEAR1340_UART_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "uart1_mclk", NULL);
clk = clk_register_gate(NULL, "uart1_clk", "uart1_mclk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_UART1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b4100000.serial");
clk = clk_register_aux("sdhci_syn_clk", "sdhci_syn_gclk",
"vco1div2_clk", 0, SPEAR1340_SDHCI_CLK_SYNT, NULL,
aux_rtbl, ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "sdhci_syn_clk", NULL);
clk_register_clkdev(clk1, "sdhci_syn_gclk", NULL);
clk = clk_register_gate(NULL, "sdhci_clk", "sdhci_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP1_CLK_ENB,
SPEAR1340_SDHCI_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "b3000000.sdhci");
clk = clk_register_aux("cfxd_syn_clk", "cfxd_syn_gclk", "vco1div2_clk",
0, SPEAR1340_CFXD_CLK_SYNT, NULL, aux_rtbl,
ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "cfxd_syn_clk", NULL);
clk_register_clkdev(clk1, "cfxd_syn_gclk", NULL);
clk = clk_register_gate(NULL, "cfxd_clk", "cfxd_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP1_CLK_ENB,
SPEAR1340_CFXD_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "b2800000.cf");
clk_register_clkdev(clk, NULL, "arasan_xd");
clk = clk_register_aux("c3_syn_clk", "c3_syn_gclk", "vco1div2_clk", 0,
SPEAR1340_C3_CLK_SYNT, NULL, aux_rtbl,
ARRAY_SIZE(aux_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "c3_syn_clk", NULL);
clk_register_clkdev(clk1, "c3_syn_gclk", NULL);
clk = clk_register_mux(NULL, "c3_mclk", c3_parents,
ARRAY_SIZE(c3_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_C3_CLK_SHIFT,
SPEAR1340_C3_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "c3_mclk", NULL);
clk = clk_register_gate(NULL, "c3_clk", "c3_mclk", CLK_SET_RATE_PARENT,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_C3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e1800000.c3");
clk = clk_register_mux(NULL, "phy_input_mclk", gmac_phy_input_parents,
ARRAY_SIZE(gmac_phy_input_parents),
CLK_SET_RATE_NO_REPARENT, SPEAR1340_GMAC_CLK_CFG,
SPEAR1340_GMAC_PHY_INPUT_CLK_SHIFT,
SPEAR1340_GMAC_PHY_INPUT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "phy_input_mclk", NULL);
clk = clk_register_aux("phy_syn_clk", "phy_syn_gclk", "phy_input_mclk",
0, SPEAR1340_GMAC_CLK_SYNT, NULL, gmac_rtbl,
ARRAY_SIZE(gmac_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "phy_syn_clk", NULL);
clk_register_clkdev(clk1, "phy_syn_gclk", NULL);
clk = clk_register_mux(NULL, "phy_mclk", gmac_phy_parents,
ARRAY_SIZE(gmac_phy_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_GMAC_PHY_CLK_SHIFT,
SPEAR1340_GMAC_PHY_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "stmmacphy.0", NULL);
clk = clk_register_mux(NULL, "clcd_syn_mclk", clcd_synth_parents,
ARRAY_SIZE(clcd_synth_parents),
CLK_SET_RATE_NO_REPARENT, SPEAR1340_CLCD_CLK_SYNT,
SPEAR1340_CLCD_SYNT_CLK_SHIFT,
SPEAR1340_CLCD_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "clcd_syn_mclk", NULL);
clk = clk_register_frac("clcd_syn_clk", "clcd_syn_mclk", 0,
SPEAR1340_CLCD_CLK_SYNT, clcd_rtbl,
ARRAY_SIZE(clcd_rtbl), &_lock);
clk_register_clkdev(clk, "clcd_syn_clk", NULL);
clk = clk_register_mux(NULL, "clcd_pixel_mclk", clcd_pixel_parents,
ARRAY_SIZE(clcd_pixel_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_CLCD_CLK_SHIFT,
SPEAR1340_CLCD_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "clcd_pixel_mclk", NULL);
clk = clk_register_gate(NULL, "clcd_clk", "clcd_pixel_mclk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_CLCD_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e1000000.clcd");
clk = clk_register_mux(NULL, "i2s_src_mclk", i2s_src_parents,
ARRAY_SIZE(i2s_src_parents), CLK_SET_RATE_NO_REPARENT,
SPEAR1340_I2S_CLK_CFG, SPEAR1340_I2S_SRC_CLK_SHIFT,
SPEAR1340_I2S_SRC_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "i2s_src_mclk", NULL);
clk = clk_register_aux("i2s_prs1_clk", NULL, "i2s_src_mclk",
CLK_SET_RATE_PARENT, SPEAR1340_I2S_CLK_CFG,
&i2s_prs1_masks, i2s_prs1_rtbl,
ARRAY_SIZE(i2s_prs1_rtbl), &_lock, NULL);
clk_register_clkdev(clk, "i2s_prs1_clk", NULL);
clk = clk_register_mux(NULL, "i2s_ref_mclk", i2s_ref_parents,
ARRAY_SIZE(i2s_ref_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_I2S_CLK_CFG, SPEAR1340_I2S_REF_SHIFT,
SPEAR1340_I2S_REF_SEL_MASK, 0, &_lock);
clk_register_clkdev(clk, "i2s_ref_mclk", NULL);
clk = clk_register_gate(NULL, "i2s_ref_pad_clk", "i2s_ref_mclk", 0,
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_I2S_REF_PAD_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, "i2s_ref_pad_clk", NULL);
clk = clk_register_aux("i2s_sclk_clk", "i2s_sclk_gclk", "i2s_ref_mclk",
0, SPEAR1340_I2S_CLK_CFG, &i2s_sclk_masks,
i2s_sclk_rtbl, ARRAY_SIZE(i2s_sclk_rtbl), &_lock,
&clk1);
clk_register_clkdev(clk, "i2s_sclk_clk", NULL);
clk_register_clkdev(clk1, "i2s_sclk_gclk", NULL);
clk = clk_register_gate(NULL, "i2c0_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_I2C0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0280000.i2c");
clk = clk_register_gate(NULL, "i2c1_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_I2C1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b4000000.i2c");
clk = clk_register_gate(NULL, "dma_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_DMA_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "ea800000.dma");
clk_register_clkdev(clk, NULL, "eb000000.dma");
clk = clk_register_gate(NULL, "gmac_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_GMAC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e2000000.eth");
clk = clk_register_gate(NULL, "fsmc_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_FSMC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b0000000.flash");
clk = clk_register_gate(NULL, "smi_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_SMI_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "ea000000.flash");
clk = clk_register_gate(NULL, "usbh0_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_UHC0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e4000000.ohci");
clk_register_clkdev(clk, NULL, "e4800000.ehci");
clk = clk_register_gate(NULL, "usbh1_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_UHC1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e5000000.ohci");
clk_register_clkdev(clk, NULL, "e5800000.ehci");
clk = clk_register_gate(NULL, "uoc_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_UOC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e3800000.otg");
clk = clk_register_gate(NULL, "pcie_sata_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_PCIE_SATA_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "b1000000.pcie");
clk_register_clkdev(clk, NULL, "b1000000.ahci");
clk = clk_register_gate(NULL, "sysram0_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_SYSRAM0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "sysram0_clk", NULL);
clk = clk_register_gate(NULL, "sysram1_clk", "ahb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_SYSRAM1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, "sysram1_clk", NULL);
clk = clk_register_aux("adc_syn_clk", "adc_syn_gclk", "ahb_clk",
0, SPEAR1340_ADC_CLK_SYNT, NULL, adc_rtbl,
ARRAY_SIZE(adc_rtbl), &_lock, &clk1);
clk_register_clkdev(clk, "adc_syn_clk", NULL);
clk_register_clkdev(clk1, "adc_syn_gclk", NULL);
clk = clk_register_gate(NULL, "adc_clk", "adc_syn_gclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP1_CLK_ENB,
SPEAR1340_ADC_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "e0080000.adc");
clk = clk_register_gate(NULL, "ssp_clk", "apb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_SSP_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0100000.spi");
clk = clk_register_gate(NULL, "gpio0_clk", "apb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_GPIO0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0600000.gpio");
clk = clk_register_gate(NULL, "gpio1_clk", "apb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_GPIO1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0680000.gpio");
clk = clk_register_gate(NULL, "i2s_play_clk", "apb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_I2S_PLAY_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b2400000.i2s-play");
clk = clk_register_gate(NULL, "i2s_rec_clk", "apb_clk", 0,
SPEAR1340_PERIP1_CLK_ENB, SPEAR1340_I2S_REC_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "b2000000.i2s-rec");
clk = clk_register_gate(NULL, "kbd_clk", "apb_clk", 0,
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_KBD_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0300000.kbd");
clk = clk_register_mux(NULL, "gen_syn0_1_mclk", gen_synth0_1_parents,
ARRAY_SIZE(gen_synth0_1_parents),
CLK_SET_RATE_NO_REPARENT, SPEAR1340_PLL_CFG,
SPEAR1340_GEN_SYNT0_1_CLK_SHIFT,
SPEAR1340_GEN_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gen_syn0_1_mclk", NULL);
clk = clk_register_mux(NULL, "gen_syn2_3_mclk", gen_synth2_3_parents,
ARRAY_SIZE(gen_synth2_3_parents),
CLK_SET_RATE_NO_REPARENT, SPEAR1340_PLL_CFG,
SPEAR1340_GEN_SYNT2_3_CLK_SHIFT,
SPEAR1340_GEN_SYNT_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "gen_syn2_3_mclk", NULL);
clk = clk_register_frac("gen_syn0_clk", "gen_syn0_1_mclk", 0,
SPEAR1340_GEN_CLK_SYNT0, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn0_clk", NULL);
clk = clk_register_frac("gen_syn1_clk", "gen_syn0_1_mclk", 0,
SPEAR1340_GEN_CLK_SYNT1, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn1_clk", NULL);
clk = clk_register_frac("gen_syn2_clk", "gen_syn2_3_mclk", 0,
SPEAR1340_GEN_CLK_SYNT2, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn2_clk", NULL);
clk = clk_register_frac("gen_syn3_clk", "gen_syn2_3_mclk", 0,
SPEAR1340_GEN_CLK_SYNT3, gen_rtbl, ARRAY_SIZE(gen_rtbl),
&_lock);
clk_register_clkdev(clk, "gen_syn3_clk", NULL);
clk = clk_register_gate(NULL, "mali_clk", "gen_syn3_clk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP3_CLK_ENB,
SPEAR1340_MALI_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "mali");
clk = clk_register_gate(NULL, "cec0_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CEC0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "spear_cec.0");
clk = clk_register_gate(NULL, "cec1_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CEC1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "spear_cec.1");
clk = clk_register_mux(NULL, "spdif_out_mclk", spdif_out_parents,
ARRAY_SIZE(spdif_out_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_SPDIF_OUT_CLK_SHIFT,
SPEAR1340_SPDIF_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "spdif_out_mclk", NULL);
clk = clk_register_gate(NULL, "spdif_out_clk", "spdif_out_mclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP3_CLK_ENB,
SPEAR1340_SPDIF_OUT_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d0000000.spdif-out");
clk = clk_register_mux(NULL, "spdif_in_mclk", spdif_in_parents,
ARRAY_SIZE(spdif_in_parents),
CLK_SET_RATE_PARENT | CLK_SET_RATE_NO_REPARENT,
SPEAR1340_PERIP_CLK_CFG, SPEAR1340_SPDIF_IN_CLK_SHIFT,
SPEAR1340_SPDIF_CLK_MASK, 0, &_lock);
clk_register_clkdev(clk, "spdif_in_mclk", NULL);
clk = clk_register_gate(NULL, "spdif_in_clk", "spdif_in_mclk",
CLK_SET_RATE_PARENT, SPEAR1340_PERIP3_CLK_ENB,
SPEAR1340_SPDIF_IN_CLK_ENB, 0, &_lock);
clk_register_clkdev(clk, NULL, "d0100000.spdif-in");
clk = clk_register_gate(NULL, "acp_clk", "ahb_clk", 0,
SPEAR1340_PERIP2_CLK_ENB, SPEAR1340_ACP_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "acp_clk");
clk = clk_register_gate(NULL, "plgpio_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_PLGPIO_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e2800000.gpio");
clk = clk_register_gate(NULL, "video_dec_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_VIDEO_DEC_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "video_dec");
clk = clk_register_gate(NULL, "video_enc_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_VIDEO_ENC_CLK_ENB,
0, &_lock);
clk_register_clkdev(clk, NULL, "video_enc");
clk = clk_register_gate(NULL, "video_in_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_VIDEO_IN_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "spear_vip");
clk = clk_register_gate(NULL, "cam0_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CAM0_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "d0200000.cam0");
clk = clk_register_gate(NULL, "cam1_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CAM1_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "d0300000.cam1");
clk = clk_register_gate(NULL, "cam2_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CAM2_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "d0400000.cam2");
clk = clk_register_gate(NULL, "cam3_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_CAM3_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "d0500000.cam3");
clk = clk_register_gate(NULL, "pwm_clk", "ahb_clk", 0,
SPEAR1340_PERIP3_CLK_ENB, SPEAR1340_PWM_CLK_ENB, 0,
&_lock);
clk_register_clkdev(clk, NULL, "e0180000.pwm");
}
