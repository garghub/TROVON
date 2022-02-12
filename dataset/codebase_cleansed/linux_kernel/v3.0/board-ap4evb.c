static int slot_cn7_get_cd(struct platform_device *pdev)
{
return !gpio_get_value(GPIO_PORT41);
}
static void usb1_host_port_power(int port, int power)
{
if (!power)
return;
__raw_writew(__raw_readw(0xE68B0008) | 0x600, 0xE68B0008);
}
static int __fsi_set_rate(struct clk *clk, long rate, int enable)
{
int ret = 0;
if (rate <= 0)
return ret;
if (enable) {
ret = clk_set_rate(clk, rate);
if (0 == ret)
ret = clk_enable(clk);
} else {
clk_disable(clk);
}
return ret;
}
static int __fsi_set_round_rate(struct clk *clk, long rate, int enable)
{
return __fsi_set_rate(clk, clk_round_rate(clk, rate), enable);
}
static int fsi_ak4642_set_rate(struct device *dev, int rate, int enable)
{
struct clk *fsia_ick;
struct clk *fsiack;
int ret = -EIO;
fsia_ick = clk_get(dev, "icka");
if (IS_ERR(fsia_ick))
return PTR_ERR(fsia_ick);
fsiack = clk_get_parent(fsia_ick);
if (!fsiack)
goto fsia_ick_out;
ret = __fsi_set_rate(fsiack, rate, enable);
if (ret < 0)
goto fsiack_out;
ret = __fsi_set_round_rate(fsia_ick, rate, enable);
if ((ret < 0) && enable)
__fsi_set_round_rate(fsiack, rate, 0);
fsiack_out:
clk_put(fsiack);
fsia_ick_out:
clk_put(fsia_ick);
return 0;
}
static int fsi_hdmi_set_rate(struct device *dev, int rate, int enable)
{
struct clk *fsib_clk;
struct clk *fdiv_clk = &sh7372_fsidivb_clk;
long fsib_rate = 0;
long fdiv_rate = 0;
int ackmd_bpfmd;
int ret;
switch (rate) {
case 44100:
fsib_rate = rate * 256;
ackmd_bpfmd = SH_FSI_ACKMD_256 | SH_FSI_BPFMD_64;
break;
case 48000:
fsib_rate = 85428000;
fdiv_rate = rate * 256;
ackmd_bpfmd = SH_FSI_ACKMD_256 | SH_FSI_BPFMD_64;
break;
default:
pr_err("unsupported rate in FSI2 port B\n");
return -EINVAL;
}
fsib_clk = clk_get(dev, "ickb");
if (IS_ERR(fsib_clk))
return -EIO;
ret = __fsi_set_round_rate(fsib_clk, fsib_rate, enable);
if (ret < 0)
goto fsi_set_rate_end;
ret = __fsi_set_round_rate(fdiv_clk, fdiv_rate, enable);
if (ret < 0) {
if (enable)
__fsi_set_round_rate(fsib_clk, fsib_rate, 0);
goto fsi_set_rate_end;
}
ret = ackmd_bpfmd;
fsi_set_rate_end:
clk_put(fsib_clk);
return ret;
}
static int fsi_set_rate(struct device *dev, int is_porta, int rate, int enable)
{
int ret;
if (is_porta)
ret = fsi_ak4642_set_rate(dev, rate, enable);
else
ret = fsi_hdmi_set_rate(dev, rate, enable);
return ret;
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
static void __init fsi_init_pm_clock(void)
{
struct clk *fsia_ick;
int ret;
fsia_ick = clk_get(&fsi_device.dev, "icka");
if (IS_ERR(fsia_ick)) {
ret = PTR_ERR(fsia_ick);
pr_err("Cannot get FSI ICK: %d\n", ret);
return;
}
ret = clk_set_parent(fsia_ick, &sh7372_fsiack_clk);
if (ret < 0)
pr_err("Cannot set FSI-A parent: %d\n", ret);
clk_put(fsia_ick);
}
static void __init gpio_no_direction(u32 addr)
{
__raw_writeb(0x00, addr);
}
static int ts_get_pendown_state(void)
{
int val;
gpio_free(GPIO_TSC_IRQ);
gpio_request(GPIO_TSC_PORT, NULL);
gpio_direction_input(GPIO_TSC_PORT);
val = gpio_get_value(GPIO_TSC_PORT);
gpio_request(GPIO_TSC_IRQ, NULL);
return !val;
}
static int ts_init(void)
{
gpio_request(GPIO_TSC_IRQ, NULL);
return 0;
}
static void __init ap4evb_map_io(void)
{
iotable_init(ap4evb_io_desc, ARRAY_SIZE(ap4evb_io_desc));
sh7372_add_early_devices();
shmobile_setup_console();
}
static void __init ap4evb_init(void)
{
u32 srcr4;
struct clk *clk;
sh7372_pinmux_init();
gpio_request(GPIO_FN_SCIFA0_TXD, NULL);
gpio_request(GPIO_FN_SCIFA0_RXD, NULL);
gpio_request(GPIO_FN_CS5A, NULL);
gpio_request(GPIO_FN_IRQ6_39, NULL);
gpio_request(GPIO_PORT32, NULL);
gpio_request(GPIO_PORT33, NULL);
gpio_request(GPIO_PORT34, NULL);
gpio_request(GPIO_PORT35, NULL);
gpio_direction_input(GPIO_PORT32);
gpio_direction_input(GPIO_PORT33);
gpio_direction_input(GPIO_PORT34);
gpio_direction_input(GPIO_PORT35);
gpio_export(GPIO_PORT32, 0);
gpio_export(GPIO_PORT33, 0);
gpio_export(GPIO_PORT34, 0);
gpio_export(GPIO_PORT35, 0);
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
__raw_writew(0x8a0a, 0xE6058130);
gpio_request(GPIO_FN_FSIAIBT, NULL);
gpio_request(GPIO_FN_FSIAILR, NULL);
gpio_request(GPIO_FN_FSIAISLD, NULL);
gpio_request(GPIO_FN_FSIAOSLD, NULL);
gpio_request(GPIO_PORT161, NULL);
gpio_direction_output(GPIO_PORT161, 0);
gpio_request(GPIO_PORT9, NULL);
gpio_request(GPIO_PORT10, NULL);
gpio_no_direction(GPIO_PORT9CR);
gpio_no_direction(GPIO_PORT10CR);
gpio_request(GPIO_PORT41, NULL);
gpio_direction_input(GPIO_PORT41);
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
lcdc_info.ch[0].lcd_size_cfg.width = 44;
lcdc_info.ch[0].lcd_size_cfg.height = 79;
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
gpio_request(GPIO_PORT189, NULL);
gpio_direction_output(GPIO_PORT189, 1);
gpio_request(GPIO_PORT151, NULL);
gpio_direction_output(GPIO_PORT151, 1);
lcdc_info.clock_source = LCDC_CLK_BUS;
lcdc_info.ch[0].interface_type = RGB18;
lcdc_info.ch[0].clock_divider = 3;
lcdc_info.ch[0].flags = 0;
lcdc_info.ch[0].lcd_size_cfg.width = 152;
lcdc_info.ch[0].lcd_size_cfg.height = 91;
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
#define SRCR4 0xe61580bc
srcr4 = __raw_readl(SRCR4);
__raw_writel(srcr4 | (1 << 13), SRCR4);
udelay(50);
__raw_writel(srcr4 & ~(1 << 13), SRCR4);
platform_add_devices(ap4evb_devices, ARRAY_SIZE(ap4evb_devices));
hdmi_init_pm_clock();
fsi_init_pm_clock();
sh7372_pm_init();
}
static void __init ap4evb_timer_init(void)
{
sh7372_clock_init();
shmobile_timer.init();
clk_set_rate(&sh7372_dv_clki_clk, 27000000);
}
