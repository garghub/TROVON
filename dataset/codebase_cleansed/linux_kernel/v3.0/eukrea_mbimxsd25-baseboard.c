static void eukrea_mbimxsd_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power)
gpio_direction_output(GPIO_LCDPWR, 1);
else
gpio_direction_output(GPIO_LCDPWR, 0);
}
void __init eukrea_mbimxsd25_baseboard_init(void)
{
if (mxc_iomux_v3_setup_multiple_pads(eukrea_mbimxsd_pads,
ARRAY_SIZE(eukrea_mbimxsd_pads)))
printk(KERN_ERR "error setting mbimxsd pads !\n");
#if defined(CONFIG_SND_SOC_EUKREA_TLV320)
mxc_audmux_v2_configure_port(0,
MXC_AUDMUX_V2_PTCR_SYN |
MXC_AUDMUX_V2_PTCR_TFSDIR |
MXC_AUDMUX_V2_PTCR_TFSEL(4) |
MXC_AUDMUX_V2_PTCR_TCLKDIR |
MXC_AUDMUX_V2_PTCR_TCSEL(4),
MXC_AUDMUX_V2_PDCR_RXDSEL(4)
);
mxc_audmux_v2_configure_port(4,
MXC_AUDMUX_V2_PTCR_SYN,
MXC_AUDMUX_V2_PDCR_RXDSEL(0)
);
#endif
imx25_add_imx_uart1(&uart_pdata);
imx25_add_imx_fb(&eukrea_mximxsd_fb_pdata);
imx25_add_imx_ssi(0, &eukrea_mbimxsd_ssi_pdata);
imx25_add_flexcan1(NULL);
imx25_add_sdhci_esdhc_imx(0, &sd1_pdata);
gpio_request(GPIO_LED1, "LED1");
gpio_direction_output(GPIO_LED1, 1);
gpio_free(GPIO_LED1);
gpio_request(GPIO_SWITCH1, "SWITCH1");
gpio_direction_input(GPIO_SWITCH1);
gpio_free(GPIO_SWITCH1);
gpio_request(GPIO_LCDPWR, "LCDPWR");
gpio_direction_output(GPIO_LCDPWR, 1);
gpio_free(GPIO_SWITCH1);
i2c_register_board_info(0, eukrea_mbimxsd_i2c_devices,
ARRAY_SIZE(eukrea_mbimxsd_i2c_devices));
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
imx_add_gpio_keys(&eukrea_mbimxsd_button_data);
}
