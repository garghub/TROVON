static void __init cns3420_early_serial_setup(void)
{
#ifdef CONFIG_SERIAL_8250_CONSOLE
static struct uart_port cns3420_serial_port = {
.membase = (void __iomem *)CNS3XXX_UART0_BASE_VIRT,
.mapbase = CNS3XXX_UART0_BASE,
.irq = IRQ_CNS3XXX_UART0,
.iotype = UPIO_MEM,
.flags = UPF_BOOT_AUTOCONF | UPF_FIXED_TYPE,
.regshift = 2,
.uartclk = 24000000,
.line = 0,
.type = PORT_16550A,
.fifosize = 16,
};
early_serial_setup(&cns3420_serial_port);
#endif
}
static int csn3xxx_usb_power_on(struct platform_device *pdev)
{
if (atomic_inc_return(&usb_pwr_ref) == 1) {
cns3xxx_pwr_power_up(1 << PM_PLL_HM_PD_CTRL_REG_OFFSET_PLL_USB);
cns3xxx_pwr_clk_en(1 << PM_CLK_GATE_REG_OFFSET_USB_HOST);
cns3xxx_pwr_soft_rst(1 << PM_SOFT_RST_REG_OFFST_USB_HOST);
__raw_writel((__raw_readl(MISC_CHIP_CONFIG_REG) | (0X2 << 24)),
MISC_CHIP_CONFIG_REG);
}
return 0;
}
static void csn3xxx_usb_power_off(struct platform_device *pdev)
{
if (atomic_dec_return(&usb_pwr_ref) == 0)
cns3xxx_pwr_clk_dis(1 << PM_CLK_GATE_REG_OFFSET_USB_HOST);
}
static void __init cns3420_init(void)
{
cns3xxx_l2x0_init();
platform_add_devices(cns3420_pdevs, ARRAY_SIZE(cns3420_pdevs));
cns3xxx_ahci_init();
cns3xxx_sdhci_init();
pm_power_off = cns3xxx_power_off;
}
static void __init cns3420_map_io(void)
{
cns3xxx_map_io();
iotable_init(cns3420_io_desc, ARRAY_SIZE(cns3420_io_desc));
cns3420_early_serial_setup();
}
