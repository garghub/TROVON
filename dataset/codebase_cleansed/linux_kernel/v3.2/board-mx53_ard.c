static void __init mx53_ard_io_init(void)
{
gpio_request(ARD_ETHERNET_INT_B, "eth-int-b");
gpio_direction_input(ARD_ETHERNET_INT_B);
gpio_request(ARD_I2CPORTEXP_B, "i2cptexp-rst");
gpio_direction_output(ARD_I2CPORTEXP_B, 1);
}
static int weim_cs_config(void)
{
u32 reg;
void __iomem *weim_base, *iomuxc_base;
weim_base = ioremap(MX53_WEIM_BASE_ADDR, SZ_4K);
if (!weim_base)
return -ENOMEM;
iomuxc_base = ioremap(MX53_IOMUXC_BASE_ADDR, SZ_4K);
if (!iomuxc_base)
return -ENOMEM;
writel(0x20001, (weim_base + 0x18));
writel(0x0, (weim_base + 0x1C));
writel(0x16000202, (weim_base + 0x20));
writel(0x00000002, (weim_base + 0x24));
writel(0x16002082, (weim_base + 0x28));
writel(0x00000000, (weim_base + 0x2C));
writel(0x00000000, (weim_base + 0x90));
reg = readl(iomuxc_base + 0x4);
reg &= ~0x3F;
reg |= 0x1B;
writel(reg, (iomuxc_base + 0x4));
iounmap(iomuxc_base);
iounmap(weim_base);
return 0;
}
void __init imx53_ard_common_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx53_ard_pads,
ARRAY_SIZE(mx53_ard_pads));
weim_cs_config();
}
static void __init mx53_ard_board_init(void)
{
imx53_soc_init();
imx53_add_imx_uart(0, NULL);
imx53_ard_common_init();
mx53_ard_io_init();
platform_add_devices(devices, ARRAY_SIZE(devices));
imx53_add_sdhci_esdhc_imx(0, &mx53_ard_sd1_data);
imx53_add_imx2_wdt(0, NULL);
imx53_add_imx_i2c(1, &mx53_ard_i2c2_data);
imx53_add_imx_i2c(2, &mx53_ard_i2c3_data);
imx_add_gpio_keys(&ard_button_data);
imx53_add_ahci_imx();
}
static void __init mx53_ard_timer_init(void)
{
mx53_clocks_init(32768, 24000000, 22579200, 0);
}
