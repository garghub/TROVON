static int imx6sl_get_arm_divider_for_wait(void)
{
if (readl_relaxed(ccm_base + CCSR) & BM_CCSR_PLL1_SW_CLK_SEL) {
return ARM_WAIT_DIV_396M;
} else {
if ((readl_relaxed(anatop_base + PLL_ARM) &
BM_PLL_ARM_DIV_SELECT) == PLL_ARM_DIV_792M)
return ARM_WAIT_DIV_792M;
else
return ARM_WAIT_DIV_996M;
}
}
static void imx6sl_enable_pll_arm(bool enable)
{
static u32 saved_pll_arm;
u32 val;
if (enable) {
saved_pll_arm = val = readl_relaxed(anatop_base + PLL_ARM);
val |= BM_PLL_ARM_ENABLE;
val &= ~BM_PLL_ARM_POWERDOWN;
writel_relaxed(val, anatop_base + PLL_ARM);
while (!(__raw_readl(anatop_base + PLL_ARM) & BM_PLL_ARM_LOCK))
;
} else {
writel_relaxed(saved_pll_arm, anatop_base + PLL_ARM);
}
}
void imx6sl_set_wait_clk(bool enter)
{
static unsigned long saved_arm_div;
int arm_div_for_wait = imx6sl_get_arm_divider_for_wait();
if (arm_div_for_wait == ARM_WAIT_DIV_396M)
imx6sl_enable_pll_arm(true);
if (enter) {
saved_arm_div = readl_relaxed(ccm_base + CACRR);
writel_relaxed(arm_div_for_wait, ccm_base + CACRR);
} else {
writel_relaxed(saved_arm_div, ccm_base + CACRR);
}
while (__raw_readl(ccm_base + CDHIPR) & BM_CDHIPR_ARM_PODF_BUSY)
;
if (arm_div_for_wait == ARM_WAIT_DIV_396M)
imx6sl_enable_pll_arm(false);
}
static void __init imx6sl_clocks_init(struct device_node *ccm_node)
{
struct device_node *np;
void __iomem *base;
int i;
int ret;
clks[IMX6SL_CLK_DUMMY] = imx_clk_fixed("dummy", 0);
clks[IMX6SL_CLK_CKIL] = imx_obtain_fixed_clock("ckil", 0);
clks[IMX6SL_CLK_OSC] = imx_obtain_fixed_clock("osc", 0);
np = of_find_compatible_node(NULL, NULL, "fsl,imx6sl-anatop");
base = of_iomap(np, 0);
WARN_ON(!base);
anatop_base = base;
clks[IMX6SL_CLK_PLL1_SYS] = imx_clk_pllv3(IMX_PLLV3_SYS, "pll1_sys", "osc", base, 0x7f);
clks[IMX6SL_CLK_PLL2_BUS] = imx_clk_pllv3(IMX_PLLV3_GENERIC, "pll2_bus", "osc", base + 0x30, 0x1);
clks[IMX6SL_CLK_PLL3_USB_OTG] = imx_clk_pllv3(IMX_PLLV3_USB, "pll3_usb_otg", "osc", base + 0x10, 0x3);
clks[IMX6SL_CLK_PLL4_AUDIO] = imx_clk_pllv3(IMX_PLLV3_AV, "pll4_audio", "osc", base + 0x70, 0x7f);
clks[IMX6SL_CLK_PLL5_VIDEO] = imx_clk_pllv3(IMX_PLLV3_AV, "pll5_video", "osc", base + 0xa0, 0x7f);
clks[IMX6SL_CLK_PLL6_ENET] = imx_clk_pllv3(IMX_PLLV3_ENET, "pll6_enet", "osc", base + 0xe0, 0x3);
clks[IMX6SL_CLK_PLL7_USB_HOST] = imx_clk_pllv3(IMX_PLLV3_USB, "pll7_usb_host", "osc", base + 0x20, 0x3);
clks[IMX6SL_CLK_USBPHY1] = imx_clk_gate("usbphy1", "pll3_usb_otg", base + 0x10, 20);
clks[IMX6SL_CLK_USBPHY2] = imx_clk_gate("usbphy2", "pll7_usb_host", base + 0x20, 20);
clks[IMX6SL_CLK_USBPHY1_GATE] = imx_clk_gate("usbphy1_gate", "dummy", base + 0x10, 6);
clks[IMX6SL_CLK_USBPHY2_GATE] = imx_clk_gate("usbphy2_gate", "dummy", base + 0x20, 6);
clks[IMX6SL_CLK_PLL4_POST_DIV] = clk_register_divider_table(NULL, "pll4_post_div", "pll4_audio", CLK_SET_RATE_PARENT, base + 0x70, 19, 2, 0, post_div_table, &imx_ccm_lock);
clks[IMX6SL_CLK_PLL4_AUDIO_DIV] = clk_register_divider(NULL, "pll4_audio_div", "pll4_post_div", CLK_SET_RATE_PARENT, base + 0x170, 15, 1, 0, &imx_ccm_lock);
clks[IMX6SL_CLK_PLL5_POST_DIV] = clk_register_divider_table(NULL, "pll5_post_div", "pll5_video", CLK_SET_RATE_PARENT, base + 0xa0, 19, 2, 0, post_div_table, &imx_ccm_lock);
clks[IMX6SL_CLK_PLL5_VIDEO_DIV] = clk_register_divider_table(NULL, "pll5_video_div", "pll5_post_div", CLK_SET_RATE_PARENT, base + 0x170, 30, 2, 0, video_div_table, &imx_ccm_lock);
clks[IMX6SL_CLK_ENET_REF] = clk_register_divider_table(NULL, "enet_ref", "pll6_enet", 0, base + 0xe0, 0, 2, 0, clk_enet_ref_table, &imx_ccm_lock);
clks[IMX6SL_CLK_PLL2_PFD0] = imx_clk_pfd("pll2_pfd0", "pll2_bus", base + 0x100, 0);
clks[IMX6SL_CLK_PLL2_PFD1] = imx_clk_pfd("pll2_pfd1", "pll2_bus", base + 0x100, 1);
clks[IMX6SL_CLK_PLL2_PFD2] = imx_clk_pfd("pll2_pfd2", "pll2_bus", base + 0x100, 2);
clks[IMX6SL_CLK_PLL3_PFD0] = imx_clk_pfd("pll3_pfd0", "pll3_usb_otg", base + 0xf0, 0);
clks[IMX6SL_CLK_PLL3_PFD1] = imx_clk_pfd("pll3_pfd1", "pll3_usb_otg", base + 0xf0, 1);
clks[IMX6SL_CLK_PLL3_PFD2] = imx_clk_pfd("pll3_pfd2", "pll3_usb_otg", base + 0xf0, 2);
clks[IMX6SL_CLK_PLL3_PFD3] = imx_clk_pfd("pll3_pfd3", "pll3_usb_otg", base + 0xf0, 3);
clks[IMX6SL_CLK_PLL2_198M] = imx_clk_fixed_factor("pll2_198m", "pll2_pfd2", 1, 2);
clks[IMX6SL_CLK_PLL3_120M] = imx_clk_fixed_factor("pll3_120m", "pll3_usb_otg", 1, 4);
clks[IMX6SL_CLK_PLL3_80M] = imx_clk_fixed_factor("pll3_80m", "pll3_usb_otg", 1, 6);
clks[IMX6SL_CLK_PLL3_60M] = imx_clk_fixed_factor("pll3_60m", "pll3_usb_otg", 1, 8);
np = ccm_node;
base = of_iomap(np, 0);
WARN_ON(!base);
ccm_base = base;
imx6q_pm_set_ccm_base(base);
clks[IMX6SL_CLK_STEP] = imx_clk_mux("step", base + 0xc, 8, 1, step_sels, ARRAY_SIZE(step_sels));
clks[IMX6SL_CLK_PLL1_SW] = imx_clk_mux("pll1_sw", base + 0xc, 2, 1, pll1_sw_sels, ARRAY_SIZE(pll1_sw_sels));
clks[IMX6SL_CLK_OCRAM_ALT_SEL] = imx_clk_mux("ocram_alt_sel", base + 0x14, 7, 1, ocram_alt_sels, ARRAY_SIZE(ocram_alt_sels));
clks[IMX6SL_CLK_OCRAM_SEL] = imx_clk_mux("ocram_sel", base + 0x14, 6, 1, ocram_sels, ARRAY_SIZE(ocram_sels));
clks[IMX6SL_CLK_PRE_PERIPH2_SEL] = imx_clk_mux("pre_periph2_sel", base + 0x18, 21, 2, pre_periph_sels, ARRAY_SIZE(pre_periph_sels));
clks[IMX6SL_CLK_PRE_PERIPH_SEL] = imx_clk_mux("pre_periph_sel", base + 0x18, 18, 2, pre_periph_sels, ARRAY_SIZE(pre_periph_sels));
clks[IMX6SL_CLK_PERIPH2_CLK2_SEL] = imx_clk_mux("periph2_clk2_sel", base + 0x18, 20, 1, periph2_clk2_sels, ARRAY_SIZE(periph2_clk2_sels));
clks[IMX6SL_CLK_PERIPH_CLK2_SEL] = imx_clk_mux("periph_clk2_sel", base + 0x18, 12, 2, periph_clk2_sels, ARRAY_SIZE(periph_clk2_sels));
clks[IMX6SL_CLK_CSI_SEL] = imx_clk_mux("csi_sel", base + 0x3c, 9, 2, csi_lcdif_sels, ARRAY_SIZE(csi_lcdif_sels));
clks[IMX6SL_CLK_LCDIF_AXI_SEL] = imx_clk_mux("lcdif_axi_sel", base + 0x3c, 14, 2, csi_lcdif_sels, ARRAY_SIZE(csi_lcdif_sels));
clks[IMX6SL_CLK_USDHC1_SEL] = imx_clk_fixup_mux("usdhc1_sel", base + 0x1c, 16, 1, usdhc_sels, ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_USDHC2_SEL] = imx_clk_fixup_mux("usdhc2_sel", base + 0x1c, 17, 1, usdhc_sels, ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_USDHC3_SEL] = imx_clk_fixup_mux("usdhc3_sel", base + 0x1c, 18, 1, usdhc_sels, ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_USDHC4_SEL] = imx_clk_fixup_mux("usdhc4_sel", base + 0x1c, 19, 1, usdhc_sels, ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_SSI1_SEL] = imx_clk_fixup_mux("ssi1_sel", base + 0x1c, 10, 2, ssi_sels, ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_SSI2_SEL] = imx_clk_fixup_mux("ssi2_sel", base + 0x1c, 12, 2, ssi_sels, ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_SSI3_SEL] = imx_clk_fixup_mux("ssi3_sel", base + 0x1c, 14, 2, ssi_sels, ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_PERCLK_SEL] = imx_clk_fixup_mux("perclk_sel", base + 0x1c, 6, 1, perclk_sels, ARRAY_SIZE(perclk_sels), imx_cscmr1_fixup);
clks[IMX6SL_CLK_PXP_AXI_SEL] = imx_clk_mux("pxp_axi_sel", base + 0x34, 6, 3, epdc_pxp_sels, ARRAY_SIZE(epdc_pxp_sels));
clks[IMX6SL_CLK_EPDC_AXI_SEL] = imx_clk_mux("epdc_axi_sel", base + 0x34, 15, 3, epdc_pxp_sels, ARRAY_SIZE(epdc_pxp_sels));
clks[IMX6SL_CLK_GPU2D_OVG_SEL] = imx_clk_mux("gpu2d_ovg_sel", base + 0x18, 4, 2, gpu2d_ovg_sels, ARRAY_SIZE(gpu2d_ovg_sels));
clks[IMX6SL_CLK_GPU2D_SEL] = imx_clk_mux("gpu2d_sel", base + 0x18, 8, 2, gpu2d_sels, ARRAY_SIZE(gpu2d_sels));
clks[IMX6SL_CLK_LCDIF_PIX_SEL] = imx_clk_mux("lcdif_pix_sel", base + 0x38, 6, 3, lcdif_pix_sels, ARRAY_SIZE(lcdif_pix_sels));
clks[IMX6SL_CLK_EPDC_PIX_SEL] = imx_clk_mux("epdc_pix_sel", base + 0x38, 15, 3, epdc_pix_sels, ARRAY_SIZE(epdc_pix_sels));
clks[IMX6SL_CLK_SPDIF0_SEL] = imx_clk_mux("spdif0_sel", base + 0x30, 20, 2, audio_sels, ARRAY_SIZE(audio_sels));
clks[IMX6SL_CLK_SPDIF1_SEL] = imx_clk_mux("spdif1_sel", base + 0x30, 7, 2, audio_sels, ARRAY_SIZE(audio_sels));
clks[IMX6SL_CLK_EXTERN_AUDIO_SEL] = imx_clk_mux("extern_audio_sel", base + 0x20, 19, 2, audio_sels, ARRAY_SIZE(audio_sels));
clks[IMX6SL_CLK_ECSPI_SEL] = imx_clk_mux("ecspi_sel", base + 0x38, 18, 1, ecspi_sels, ARRAY_SIZE(ecspi_sels));
clks[IMX6SL_CLK_UART_SEL] = imx_clk_mux("uart_sel", base + 0x24, 6, 1, uart_sels, ARRAY_SIZE(uart_sels));
clks[IMX6SL_CLK_PERIPH] = imx_clk_busy_mux("periph", base + 0x14, 25, 1, base + 0x48, 5, periph_sels, ARRAY_SIZE(periph_sels));
clks[IMX6SL_CLK_PERIPH2] = imx_clk_busy_mux("periph2", base + 0x14, 26, 1, base + 0x48, 3, periph2_sels, ARRAY_SIZE(periph2_sels));
clks[IMX6SL_CLK_OCRAM_PODF] = imx_clk_divider("ocram_podf", "ocram_sel", base + 0x14, 16, 3);
clks[IMX6SL_CLK_PERIPH_CLK2_PODF] = imx_clk_divider("periph_clk2_podf", "periph_clk2_sel", base + 0x14, 27, 3);
clks[IMX6SL_CLK_PERIPH2_CLK2_PODF] = imx_clk_divider("periph2_clk2_podf", "periph2_clk2_sel", base + 0x14, 0, 3);
clks[IMX6SL_CLK_IPG] = imx_clk_divider("ipg", "ahb", base + 0x14, 8, 2);
clks[IMX6SL_CLK_CSI_PODF] = imx_clk_divider("csi_podf", "csi_sel", base + 0x3c, 11, 3);
clks[IMX6SL_CLK_LCDIF_AXI_PODF] = imx_clk_divider("lcdif_axi_podf", "lcdif_axi_sel", base + 0x3c, 16, 3);
clks[IMX6SL_CLK_USDHC1_PODF] = imx_clk_divider("usdhc1_podf", "usdhc1_sel", base + 0x24, 11, 3);
clks[IMX6SL_CLK_USDHC2_PODF] = imx_clk_divider("usdhc2_podf", "usdhc2_sel", base + 0x24, 16, 3);
clks[IMX6SL_CLK_USDHC3_PODF] = imx_clk_divider("usdhc3_podf", "usdhc3_sel", base + 0x24, 19, 3);
clks[IMX6SL_CLK_USDHC4_PODF] = imx_clk_divider("usdhc4_podf", "usdhc4_sel", base + 0x24, 22, 3);
clks[IMX6SL_CLK_SSI1_PRED] = imx_clk_divider("ssi1_pred", "ssi1_sel", base + 0x28, 6, 3);
clks[IMX6SL_CLK_SSI1_PODF] = imx_clk_divider("ssi1_podf", "ssi1_pred", base + 0x28, 0, 6);
clks[IMX6SL_CLK_SSI2_PRED] = imx_clk_divider("ssi2_pred", "ssi2_sel", base + 0x2c, 6, 3);
clks[IMX6SL_CLK_SSI2_PODF] = imx_clk_divider("ssi2_podf", "ssi2_pred", base + 0x2c, 0, 6);
clks[IMX6SL_CLK_SSI3_PRED] = imx_clk_divider("ssi3_pred", "ssi3_sel", base + 0x28, 22, 3);
clks[IMX6SL_CLK_SSI3_PODF] = imx_clk_divider("ssi3_podf", "ssi3_pred", base + 0x28, 16, 6);
clks[IMX6SL_CLK_PERCLK] = imx_clk_fixup_divider("perclk", "perclk_sel", base + 0x1c, 0, 6, imx_cscmr1_fixup);
clks[IMX6SL_CLK_PXP_AXI_PODF] = imx_clk_divider("pxp_axi_podf", "pxp_axi_sel", base + 0x34, 3, 3);
clks[IMX6SL_CLK_EPDC_AXI_PODF] = imx_clk_divider("epdc_axi_podf", "epdc_axi_sel", base + 0x34, 12, 3);
clks[IMX6SL_CLK_GPU2D_OVG_PODF] = imx_clk_divider("gpu2d_ovg_podf", "gpu2d_ovg_sel", base + 0x18, 26, 3);
clks[IMX6SL_CLK_GPU2D_PODF] = imx_clk_divider("gpu2d_podf", "gpu2d_sel", base + 0x18, 29, 3);
clks[IMX6SL_CLK_LCDIF_PIX_PRED] = imx_clk_divider("lcdif_pix_pred", "lcdif_pix_sel", base + 0x38, 3, 3);
clks[IMX6SL_CLK_EPDC_PIX_PRED] = imx_clk_divider("epdc_pix_pred", "epdc_pix_sel", base + 0x38, 12, 3);
clks[IMX6SL_CLK_LCDIF_PIX_PODF] = imx_clk_fixup_divider("lcdif_pix_podf", "lcdif_pix_pred", base + 0x1c, 20, 3, imx_cscmr1_fixup);
clks[IMX6SL_CLK_EPDC_PIX_PODF] = imx_clk_divider("epdc_pix_podf", "epdc_pix_pred", base + 0x18, 23, 3);
clks[IMX6SL_CLK_SPDIF0_PRED] = imx_clk_divider("spdif0_pred", "spdif0_sel", base + 0x30, 25, 3);
clks[IMX6SL_CLK_SPDIF0_PODF] = imx_clk_divider("spdif0_podf", "spdif0_pred", base + 0x30, 22, 3);
clks[IMX6SL_CLK_SPDIF1_PRED] = imx_clk_divider("spdif1_pred", "spdif1_sel", base + 0x30, 12, 3);
clks[IMX6SL_CLK_SPDIF1_PODF] = imx_clk_divider("spdif1_podf", "spdif1_pred", base + 0x30, 9, 3);
clks[IMX6SL_CLK_EXTERN_AUDIO_PRED] = imx_clk_divider("extern_audio_pred", "extern_audio_sel", base + 0x28, 9, 3);
clks[IMX6SL_CLK_EXTERN_AUDIO_PODF] = imx_clk_divider("extern_audio_podf", "extern_audio_pred", base + 0x28, 25, 3);
clks[IMX6SL_CLK_ECSPI_ROOT] = imx_clk_divider("ecspi_root", "ecspi_sel", base + 0x38, 19, 6);
clks[IMX6SL_CLK_UART_ROOT] = imx_clk_divider("uart_root", "uart_sel", base + 0x24, 0, 6);
clks[IMX6SL_CLK_AHB] = imx_clk_busy_divider("ahb", "periph", base + 0x14, 10, 3, base + 0x48, 1);
clks[IMX6SL_CLK_MMDC_ROOT] = imx_clk_busy_divider("mmdc", "periph2", base + 0x14, 3, 3, base + 0x48, 2);
clks[IMX6SL_CLK_ARM] = imx_clk_busy_divider("arm", "pll1_sw", base + 0x10, 0, 3, base + 0x48, 16);
clks[IMX6SL_CLK_ECSPI1] = imx_clk_gate2("ecspi1", "ecspi_root", base + 0x6c, 0);
clks[IMX6SL_CLK_ECSPI2] = imx_clk_gate2("ecspi2", "ecspi_root", base + 0x6c, 2);
clks[IMX6SL_CLK_ECSPI3] = imx_clk_gate2("ecspi3", "ecspi_root", base + 0x6c, 4);
clks[IMX6SL_CLK_ECSPI4] = imx_clk_gate2("ecspi4", "ecspi_root", base + 0x6c, 6);
clks[IMX6SL_CLK_ENET] = imx_clk_gate2("enet", "ipg", base + 0x6c, 10);
clks[IMX6SL_CLK_EPIT1] = imx_clk_gate2("epit1", "perclk", base + 0x6c, 12);
clks[IMX6SL_CLK_EPIT2] = imx_clk_gate2("epit2", "perclk", base + 0x6c, 14);
clks[IMX6SL_CLK_EXTERN_AUDIO] = imx_clk_gate2("extern_audio", "extern_audio_podf", base + 0x6c, 16);
clks[IMX6SL_CLK_GPT] = imx_clk_gate2("gpt", "perclk", base + 0x6c, 20);
clks[IMX6SL_CLK_GPT_SERIAL] = imx_clk_gate2("gpt_serial", "perclk", base + 0x6c, 22);
clks[IMX6SL_CLK_GPU2D_OVG] = imx_clk_gate2("gpu2d_ovg", "gpu2d_ovg_podf", base + 0x6c, 26);
clks[IMX6SL_CLK_I2C1] = imx_clk_gate2("i2c1", "perclk", base + 0x70, 6);
clks[IMX6SL_CLK_I2C2] = imx_clk_gate2("i2c2", "perclk", base + 0x70, 8);
clks[IMX6SL_CLK_I2C3] = imx_clk_gate2("i2c3", "perclk", base + 0x70, 10);
clks[IMX6SL_CLK_OCOTP] = imx_clk_gate2("ocotp", "ipg", base + 0x70, 12);
clks[IMX6SL_CLK_CSI] = imx_clk_gate2("csi", "csi_podf", base + 0x74, 0);
clks[IMX6SL_CLK_PXP_AXI] = imx_clk_gate2("pxp_axi", "pxp_axi_podf", base + 0x74, 2);
clks[IMX6SL_CLK_EPDC_AXI] = imx_clk_gate2("epdc_axi", "epdc_axi_podf", base + 0x74, 4);
clks[IMX6SL_CLK_LCDIF_AXI] = imx_clk_gate2("lcdif_axi", "lcdif_axi_podf", base + 0x74, 6);
clks[IMX6SL_CLK_LCDIF_PIX] = imx_clk_gate2("lcdif_pix", "lcdif_pix_podf", base + 0x74, 8);
clks[IMX6SL_CLK_EPDC_PIX] = imx_clk_gate2("epdc_pix", "epdc_pix_podf", base + 0x74, 10);
clks[IMX6SL_CLK_OCRAM] = imx_clk_gate2("ocram", "ocram_podf", base + 0x74, 28);
clks[IMX6SL_CLK_PWM1] = imx_clk_gate2("pwm1", "perclk", base + 0x78, 16);
clks[IMX6SL_CLK_PWM2] = imx_clk_gate2("pwm2", "perclk", base + 0x78, 18);
clks[IMX6SL_CLK_PWM3] = imx_clk_gate2("pwm3", "perclk", base + 0x78, 20);
clks[IMX6SL_CLK_PWM4] = imx_clk_gate2("pwm4", "perclk", base + 0x78, 22);
clks[IMX6SL_CLK_SDMA] = imx_clk_gate2("sdma", "ipg", base + 0x7c, 6);
clks[IMX6SL_CLK_SPBA] = imx_clk_gate2("spba", "ipg", base + 0x7c, 12);
clks[IMX6SL_CLK_SPDIF] = imx_clk_gate2("spdif", "spdif0_podf", base + 0x7c, 14);
clks[IMX6SL_CLK_SSI1] = imx_clk_gate2("ssi1", "ssi1_podf", base + 0x7c, 18);
clks[IMX6SL_CLK_SSI2] = imx_clk_gate2("ssi2", "ssi2_podf", base + 0x7c, 20);
clks[IMX6SL_CLK_SSI3] = imx_clk_gate2("ssi3", "ssi3_podf", base + 0x7c, 22);
clks[IMX6SL_CLK_UART] = imx_clk_gate2("uart", "ipg", base + 0x7c, 24);
clks[IMX6SL_CLK_UART_SERIAL] = imx_clk_gate2("uart_serial", "uart_root", base + 0x7c, 26);
clks[IMX6SL_CLK_USBOH3] = imx_clk_gate2("usboh3", "ipg", base + 0x80, 0);
clks[IMX6SL_CLK_USDHC1] = imx_clk_gate2("usdhc1", "usdhc1_podf", base + 0x80, 2);
clks[IMX6SL_CLK_USDHC2] = imx_clk_gate2("usdhc2", "usdhc2_podf", base + 0x80, 4);
clks[IMX6SL_CLK_USDHC3] = imx_clk_gate2("usdhc3", "usdhc3_podf", base + 0x80, 6);
clks[IMX6SL_CLK_USDHC4] = imx_clk_gate2("usdhc4", "usdhc4_podf", base + 0x80, 8);
imx_check_clocks(clks, ARRAY_SIZE(clks));
clk_data.clks = clks;
clk_data.clk_num = ARRAY_SIZE(clks);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
ret = clk_set_rate(clks[IMX6SL_CLK_AHB], 132000000);
if (ret)
pr_warn("%s: failed to set AHB clock rate %d!\n",
__func__, ret);
for (i = 0; i < ARRAY_SIZE(clks_init_on); i++)
clk_prepare_enable(clks[clks_init_on[i]]);
if (IS_ENABLED(CONFIG_USB_MXS_PHY)) {
clk_prepare_enable(clks[IMX6SL_CLK_USBPHY1_GATE]);
clk_prepare_enable(clks[IMX6SL_CLK_USBPHY2_GATE]);
}
clk_set_parent(clks[IMX6SL_CLK_SPDIF0_SEL], clks[IMX6SL_CLK_PLL3_PFD3]);
imx6q_set_lpm(WAIT_CLOCKED);
}
