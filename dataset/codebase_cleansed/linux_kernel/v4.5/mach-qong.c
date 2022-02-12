static inline void __init mxc_init_imx_uart(void)
{
mxc_iomux_setup_multiple_pins(uart_pins, ARRAY_SIZE(uart_pins),
"uart-0");
imx31_add_imx_uart0(&uart_pdata);
}
static int __init qong_init_dnet(void)
{
int ret;
dnet_resources[1].start =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_DTR_DCE1));
dnet_resources[1].end =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_DTR_DCE1));
ret = platform_device_register(&dnet_device);
return ret;
}
static void qong_init_nor_mtd(void)
{
(void)platform_device_register(&qong_nor_mtd_device);
}
static void qong_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *nand_chip = mtd_to_nand(mtd);
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, nand_chip->IO_ADDR_W + (1 << 24));
else
writeb(cmd, nand_chip->IO_ADDR_W + (1 << 23));
}
static int qong_nand_device_ready(struct mtd_info *mtd)
{
return gpio_get_value(IOMUX_TO_GPIO(MX31_PIN_NFRB));
}
static void qong_nand_select_chip(struct mtd_info *mtd, int chip)
{
if (chip >= 0)
gpio_set_value(IOMUX_TO_GPIO(MX31_PIN_NFCE_B), 0);
else
gpio_set_value(IOMUX_TO_GPIO(MX31_PIN_NFCE_B), 1);
}
static void __init qong_init_nand_mtd(void)
{
__raw_writel(0x00004f00, MX31_IO_ADDRESS(MX31_WEIM_CSCRxU(3)));
__raw_writel(0x20013b31, MX31_IO_ADDRESS(MX31_WEIM_CSCRxL(3)));
__raw_writel(0x00020800, MX31_IO_ADDRESS(MX31_WEIM_CSCRxA(3)));
mxc_iomux_set_gpr(MUX_SDCTL_CSD1_SEL, true);
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_NFCE_B, IOMUX_CONFIG_GPIO));
if (!gpio_request(IOMUX_TO_GPIO(MX31_PIN_NFCE_B), "nand_enable"))
gpio_direction_output(IOMUX_TO_GPIO(MX31_PIN_NFCE_B), 0);
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_NFRB, IOMUX_CONFIG_GPIO));
if (!gpio_request(IOMUX_TO_GPIO(MX31_PIN_NFRB), "nand_rdy"))
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_NFRB));
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_NFWP_B, IOMUX_CONFIG_GPIO));
if (!gpio_request(IOMUX_TO_GPIO(MX31_PIN_NFWP_B), "nand_wp"))
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_NFWP_B));
platform_device_register(&qong_nand_device);
}
static void __init qong_init_fpga(void)
{
void __iomem *regs;
u32 fpga_ver;
regs = ioremap(QONG_FPGA_CTRL_BASEADDR, QONG_FPGA_CTRL_SIZE);
if (!regs) {
printk(KERN_ERR "%s: failed to map registers, aborting.\n",
__func__);
return;
}
fpga_ver = readl(regs + QONG_FPGA_CTRL_VERSION);
iounmap(regs);
printk(KERN_INFO "Qong FPGA version %d.%d.%d\n",
(fpga_ver & 0xF000) >> 12,
(fpga_ver & 0x0F00) >> 8, fpga_ver & 0x00FF);
if (fpga_ver < QONG_FPGA_VERSION(0, 8, 7)) {
printk(KERN_ERR "qong: Unexpected FPGA version, FPGA-based "
"devices won't be registered!\n");
return;
}
qong_init_nand_mtd();
qong_init_dnet();
}
static void __init qong_init(void)
{
imx31_soc_init();
mxc_init_imx_uart();
qong_init_nor_mtd();
qong_init_fpga();
imx31_add_imx2_wdt();
}
static void __init qong_timer_init(void)
{
mx31_clocks_init(26000000);
}
