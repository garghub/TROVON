static void usb_host_port_power(int port, int power)
{
if (!power)
return;
__raw_writew(__raw_readw(IOMEM(0xe6890008)) | 0x600, IOMEM(0xe6890008));
}
static void __init g3evm_init(void)
{
sh7367_pinmux_init();
gpio_request(GPIO_PORT22, NULL);
gpio_direction_output(GPIO_PORT22, 1);
gpio_export(GPIO_PORT22, 0);
gpio_request(GPIO_PORT23, NULL);
gpio_direction_output(GPIO_PORT23, 1);
gpio_export(GPIO_PORT23, 0);
gpio_request(GPIO_PORT24, NULL);
gpio_direction_output(GPIO_PORT24, 1);
gpio_export(GPIO_PORT24, 0);
gpio_request(GPIO_FN_SCIFA1_TXD, NULL);
gpio_request(GPIO_FN_SCIFA1_RXD, NULL);
gpio_request(GPIO_FN_SCIFA1_CTS, NULL);
gpio_request(GPIO_FN_SCIFA1_RTS, NULL);
gpio_request(GPIO_FN_VBUS0, NULL);
gpio_request(GPIO_FN_PWEN, NULL);
gpio_request(GPIO_FN_OVCN, NULL);
gpio_request(GPIO_FN_OVCN2, NULL);
gpio_request(GPIO_FN_EXTLP, NULL);
gpio_request(GPIO_FN_IDIN, NULL);
__raw_writew(0x0300, IOMEM(0xe605810a));
__raw_writew(0x00e0, IOMEM(0xe60581c0));
__raw_writew(0x6010, IOMEM(0xe60581c6));
__raw_writew(0x8a0a, IOMEM(0xe605810c));
gpio_request(GPIO_FN_PORT42_KEYOUT0, NULL);
gpio_request(GPIO_FN_PORT43_KEYOUT1, NULL);
gpio_request(GPIO_FN_PORT44_KEYOUT2, NULL);
gpio_request(GPIO_FN_PORT45_KEYOUT3, NULL);
gpio_request(GPIO_FN_PORT46_KEYOUT4, NULL);
gpio_request(GPIO_FN_PORT47_KEYOUT5, NULL);
gpio_request(GPIO_FN_PORT48_KEYIN0_PU, NULL);
gpio_request(GPIO_FN_PORT49_KEYIN1_PU, NULL);
gpio_request(GPIO_FN_PORT50_KEYIN2_PU, NULL);
gpio_request(GPIO_FN_PORT55_KEYIN3_PU, NULL);
gpio_request(GPIO_FN_PORT56_KEYIN4_PU, NULL);
gpio_request(GPIO_FN_PORT57_KEYIN5_PU, NULL);
gpio_request(GPIO_FN_PORT58_KEYIN6_PU, NULL);
gpio_request(GPIO_FN_FCE0, NULL);
gpio_request(GPIO_FN_D0_ED0_NAF0, NULL);
gpio_request(GPIO_FN_D1_ED1_NAF1, NULL);
gpio_request(GPIO_FN_D2_ED2_NAF2, NULL);
gpio_request(GPIO_FN_D3_ED3_NAF3, NULL);
gpio_request(GPIO_FN_D4_ED4_NAF4, NULL);
gpio_request(GPIO_FN_D5_ED5_NAF5, NULL);
gpio_request(GPIO_FN_D6_ED6_NAF6, NULL);
gpio_request(GPIO_FN_D7_ED7_NAF7, NULL);
gpio_request(GPIO_FN_D8_ED8_NAF8, NULL);
gpio_request(GPIO_FN_D9_ED9_NAF9, NULL);
gpio_request(GPIO_FN_D10_ED10_NAF10, NULL);
gpio_request(GPIO_FN_D11_ED11_NAF11, NULL);
gpio_request(GPIO_FN_D12_ED12_NAF12, NULL);
gpio_request(GPIO_FN_D13_ED13_NAF13, NULL);
gpio_request(GPIO_FN_D14_ED14_NAF14, NULL);
gpio_request(GPIO_FN_D15_ED15_NAF15, NULL);
gpio_request(GPIO_FN_WE0_XWR0_FWE, NULL);
gpio_request(GPIO_FN_FRB, NULL);
__raw_writel(__raw_readl(IOMEM(0xe6158048)) & ~(1 << 15), IOMEM(0xe6158048));
gpio_request(GPIO_FN_IRDA_OUT, NULL);
gpio_request(GPIO_FN_IRDA_IN, NULL);
gpio_request(GPIO_FN_IRDA_FIRSEL, NULL);
sh7367_add_standard_devices();
platform_add_devices(g3evm_devices, ARRAY_SIZE(g3evm_devices));
}
