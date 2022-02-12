static int slot_cn7_get_cd(struct platform_device *pdev)
{
return !gpio_get_value(GPIO_PORT41);
}
static void usb1_host_port_power(int port, int power)
{
if (!power)
return;
__raw_writew(__raw_readw(IOMEM(0xE68B0008)) | 0x600, IOMEM(0xE68B0008));
}
static int sh_mipi_set_dot_clock(struct platform_device *pdev,
void __iomem *base,
int enable)
{
struct clk *pck = clk_get(&pdev->dev, "dsip_clk");
if (IS_ERR(pck))
return PTR_ERR(pck);
if (enable) {
clk_set_rate(pck, clk_round_rate(pck, 24000000));
clk_enable(pck);
} else {
clk_disable(pck);
}
clk_put(pck);
return 0;
}
static long ap4evb_clk_optimize(unsigned long target, unsigned long *best_freq,
unsigned long *parent_freq)
{
struct clk *hdmi_ick = clk_get(&hdmi_device.dev, "ick");
long error;
if (IS_ERR(hdmi_ick)) {
int ret = PTR_ERR(hdmi_ick);
pr_err("Cannot get HDMI ICK: %d\n", ret);
return ret;
}
error = clk_round_parent(hdmi_ick, target, best_freq, parent_freq, 1, 64);
clk_put(hdmi_ick);
return error;
}
static void __init hdmi_init_pm_clock(void)
{
struct clk *hdmi_ick = clk_get(&hdmi_device.dev, "ick");
int ret;
long rate;
if (IS_ERR(hdmi_ick)) {
ret = PTR_ERR(hdmi_ick);
pr_err("Cannot get HDMI ICK: %d\n", ret);
goto out;
}
ret = clk_set_parent(&sh7372_pllc2_clk, &sh7372_dv_clki_div2_clk);
if (ret < 0) {
pr_err("Cannot set PLLC2 parent: %d, %d users\n", ret, sh7372_pllc2_clk.usecount);
goto out;
}
pr_debug("PLLC2 initial frequency %lu\n", clk_get_rate(&sh7372_pllc2_clk));
rate = clk_round_rate(&sh7372_pllc2_clk, 594000000);
if (rate < 0) {
pr_err("Cannot get suitable rate: %ld\n", rate);
ret = rate;
goto out;
}
ret = clk_set_rate(&sh7372_pllc2_clk, rate);
if (ret < 0) {
pr_err("Cannot set rate %ld: %d\n", rate, ret);
goto out;
}
pr_debug("PLLC2 set frequency %lu\n", rate);
ret = clk_set_parent(hdmi_ick, &sh7372_pllc2_clk);
if (ret < 0)
pr_err("Cannot set HDMI parent: %d\n", ret);
out:
if (!IS_ERR(hdmi_ick))
clk_put(hdmi_ick);
}
static int ts_get_pendown_state(void)
{
int val;
gpio_free(GPIO_TSC_IRQ);
gpio_request_one(GPIO_TSC_PORT, GPIOF_IN, NULL);
val = gpio_get_value(GPIO_TSC_PORT);
gpio_request(GPIO_TSC_IRQ, NULL);
return !val;
}
static int ts_init(void)
{
gpio_request(GPIO_TSC_IRQ, NULL);
return 0;
}
static void __init ap4evb_init(void)
{
struct pm_domain_device domain_devices[] = {
{ "A4LC", &lcdc1_device, },
{ "A4LC", &lcdc_device, },
{ "A4MP", &fsi_device, },
{ "A3SP", &sh_mmcif_device, },
{ "A3SP", &sdhi0_device, },
{ "A3SP", &sdhi1_device, },
{ "A4R", &ceu_device, },
};
u32 srcr4;
struct clk *clk;
regulator_register_always_on(0, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_always_on(1, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(2, dummy_supplies, ARRAY_SIZE(dummy_supplies));
clk_set_rate(&sh7372_dv_clki_clk, 27000000);
sh7372_pinmux_init();
gpio_request(GPIO_FN_SCIFA0_TXD, NULL);
gpio_request(GPIO_FN_SCIFA0_RXD, NULL);
gpio_request(GPIO_FN_CS5A, NULL);
gpio_request(GPIO_FN_IRQ6_39, NULL);
gpio_request_one(GPIO_PORT32, GPIOF_IN | GPIOF_EXPORT, NULL);
gpio_request_one(GPIO_PORT33, GPIOF_IN | GPIOF_EXPORT, NULL);
gpio_request_one(GPIO_PORT34, GPIOF_IN | GPIOF_EXPORT, NULL);
gpio_request_one(GPIO_PORT35, GPIOF_IN | GPIOF_EXPORT, NULL);
gpio_request(GPIO_FN_SDHICD0, NULL);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_SDHICMD1, NULL);
gpio_request(GPIO_FN_SDHICLK1, NULL);
gpio_request(GPIO_FN_SDHID1_3, NULL);
gpio_request(GPIO_FN_SDHID1_2, NULL);
gpio_request(GPIO_FN_SDHID1_1, NULL);
gpio_request(GPIO_FN_SDHID1_0, NULL);
gpio_request(GPIO_FN_MMCD0_0, NULL);
gpio_request(GPIO_FN_MMCD0_1, NULL);
gpio_request(GPIO_FN_MMCD0_2, NULL);
gpio_request(GPIO_FN_MMCD0_3, NULL);
gpio_request(GPIO_FN_MMCD0_4, NULL);
gpio_request(GPIO_FN_MMCD0_5, NULL);
gpio_request(GPIO_FN_MMCD0_6, NULL);
gpio_request(GPIO_FN_MMCD0_7, NULL);
gpio_request(GPIO_FN_MMCCMD0, NULL);
gpio_request(GPIO_FN_MMCCLK0, NULL);
gpio_request(GPIO_FN_VBUS0_1, NULL);
gpio_request(GPIO_FN_IDIN_1_18, NULL);
gpio_request(GPIO_FN_PWEN_1_115, NULL);
gpio_request(GPIO_FN_OVCN_1_114, NULL);
gpio_request(GPIO_FN_EXTLP_1, NULL);
gpio_request(GPIO_FN_OVCN2_1, NULL);
__raw_writew(0x8a0a, IOMEM(0xE6058130));
gpio_request(GPIO_FN_FSIAIBT, NULL);
gpio_request(GPIO_FN_FSIAILR, NULL);
gpio_request(GPIO_FN_FSIAISLD, NULL);
gpio_request(GPIO_FN_FSIAOSLD, NULL);
gpio_request_one(GPIO_PORT161, GPIOF_OUT_INIT_LOW, NULL);
gpio_request(GPIO_PORT9, NULL);
gpio_request(GPIO_PORT10, NULL);
gpio_direction_none(GPIO_PORT9CR);
gpio_direction_none(GPIO_PORT10CR);
gpio_request_one(GPIO_PORT41, GPIOF_IN, NULL);
gpio_request(GPIO_FN_FSIBCK, NULL);
__raw_writew(__raw_readw(USCCR1) & ~(1 << 6), USCCR1);
clk = clk_get(NULL, "spu_clk");
if (!IS_ERR(clk)) {
clk_set_rate(clk, clk_round_rate(clk, 119600000));
clk_put(clk);
}
intc_set_priority(IRQ_FSI, 3);
i2c_register_board_info(0, i2c0_devices,
ARRAY_SIZE(i2c0_devices));
i2c_register_board_info(1, i2c1_devices,
ARRAY_SIZE(i2c1_devices));
#ifdef CONFIG_AP4EVB_QHD
gpio_request(GPIO_FN_KEYOUT0, NULL);
gpio_request(GPIO_FN_KEYOUT1, NULL);
gpio_request(GPIO_FN_KEYOUT2, NULL);
gpio_request(GPIO_FN_KEYOUT3, NULL);
gpio_request(GPIO_FN_KEYOUT4, NULL);
gpio_request(GPIO_FN_KEYIN0_136, NULL);
gpio_request(GPIO_FN_KEYIN1_135, NULL);
gpio_request(GPIO_FN_KEYIN2_134, NULL);
gpio_request(GPIO_FN_KEYIN3_133, NULL);
gpio_request(GPIO_FN_KEYIN4, NULL);
irq_set_irq_type(IRQ28, IRQ_TYPE_LEVEL_LOW);
tsc_device.irq = IRQ28;
i2c_register_board_info(1, &tsc_device, 1);
lcdc_info.clock_source = LCDC_CLK_PERIPHERAL;
lcdc_info.ch[0].interface_type = RGB24;
lcdc_info.ch[0].clock_divider = 1;
lcdc_info.ch[0].flags = LCDC_FLAGS_DWPOL;
lcdc_info.ch[0].panel_cfg.width = 44;
lcdc_info.ch[0].panel_cfg.height = 79;
platform_add_devices(qhd_devices, ARRAY_SIZE(qhd_devices));
#else
gpio_request(GPIO_FN_LCDD17, NULL);
gpio_request(GPIO_FN_LCDD16, NULL);
gpio_request(GPIO_FN_LCDD15, NULL);
gpio_request(GPIO_FN_LCDD14, NULL);
gpio_request(GPIO_FN_LCDD13, NULL);
gpio_request(GPIO_FN_LCDD12, NULL);
gpio_request(GPIO_FN_LCDD11, NULL);
gpio_request(GPIO_FN_LCDD10, NULL);
gpio_request(GPIO_FN_LCDD9, NULL);
gpio_request(GPIO_FN_LCDD8, NULL);
gpio_request(GPIO_FN_LCDD7, NULL);
gpio_request(GPIO_FN_LCDD6, NULL);
gpio_request(GPIO_FN_LCDD5, NULL);
gpio_request(GPIO_FN_LCDD4, NULL);
gpio_request(GPIO_FN_LCDD3, NULL);
gpio_request(GPIO_FN_LCDD2, NULL);
gpio_request(GPIO_FN_LCDD1, NULL);
gpio_request(GPIO_FN_LCDD0, NULL);
gpio_request(GPIO_FN_LCDDISP, NULL);
gpio_request(GPIO_FN_LCDDCK, NULL);
gpio_request_one(GPIO_PORT189, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(GPIO_PORT151, GPIOF_OUT_INIT_HIGH, NULL);
lcdc_info.clock_source = LCDC_CLK_BUS;
lcdc_info.ch[0].interface_type = RGB18;
lcdc_info.ch[0].clock_divider = 3;
lcdc_info.ch[0].flags = 0;
lcdc_info.ch[0].panel_cfg.width = 152;
lcdc_info.ch[0].panel_cfg.height = 91;
irq_set_irq_type(IRQ7, IRQ_TYPE_LEVEL_LOW);
tsc_device.irq = IRQ7;
i2c_register_board_info(0, &tsc_device, 1);
#endif
gpio_request(GPIO_FN_VIO_CKO, NULL);
clk = clk_get(NULL, "vck1_clk");
if (!IS_ERR(clk)) {
clk_set_rate(clk, clk_round_rate(clk, 13000000));
clk_enable(clk);
clk_put(clk);
}
sh7372_add_standard_devices();
gpio_request(GPIO_FN_HDMI_HPD, NULL);
gpio_request(GPIO_FN_HDMI_CEC, NULL);
#define SRCR4 IOMEM(0xe61580bc)
srcr4 = __raw_readl(SRCR4);
__raw_writel(srcr4 | (1 << 13), SRCR4);
udelay(50);
__raw_writel(srcr4 & ~(1 << 13), SRCR4);
platform_add_devices(ap4evb_devices, ARRAY_SIZE(ap4evb_devices));
rmobile_add_devices_to_domains(domain_devices,
ARRAY_SIZE(domain_devices));
hdmi_init_pm_clock();
sh7372_pm_init();
pm_clk_add(&fsi_device.dev, "spu2");
pm_clk_add(&lcdc1_device.dev, "hdmi");
}
