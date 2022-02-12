int __init dm646x_gpio_register(void)
{
return davinci_gpio_register(dm646x_gpio_resources,
ARRAY_SIZE(dm646x_gpio_resources),
&dm646x_gpio_platform_data);
}
void __init dm646x_init_mcasp0(struct snd_platform_data *pdata)
{
dm646x_mcasp0_device.dev.platform_data = pdata;
platform_device_register(&dm646x_mcasp0_device);
}
void __init dm646x_init_mcasp1(struct snd_platform_data *pdata)
{
dm646x_mcasp1_device.dev.platform_data = pdata;
platform_device_register(&dm646x_mcasp1_device);
platform_device_register(&dm646x_dit_device);
}
void dm646x_setup_vpif(struct vpif_display_config *display_config,
struct vpif_capture_config *capture_config)
{
unsigned int value;
value = __raw_readl(DAVINCI_SYSMOD_VIRT(SYSMOD_VSCLKDIS));
value &= ~VSCLKDIS_MASK;
__raw_writel(value, DAVINCI_SYSMOD_VIRT(SYSMOD_VSCLKDIS));
value = __raw_readl(DAVINCI_SYSMOD_VIRT(SYSMOD_VDD3P3VPWDN));
value &= ~VDD3P3V_VID_MASK;
__raw_writel(value, DAVINCI_SYSMOD_VIRT(SYSMOD_VDD3P3VPWDN));
davinci_cfg_reg(DM646X_STSOMUX_DISABLE);
davinci_cfg_reg(DM646X_STSIMUX_DISABLE);
davinci_cfg_reg(DM646X_PTSOMUX_DISABLE);
davinci_cfg_reg(DM646X_PTSIMUX_DISABLE);
vpif_display_dev.dev.platform_data = display_config;
vpif_capture_dev.dev.platform_data = capture_config;
platform_device_register(&vpif_dev);
platform_device_register(&vpif_display_dev);
platform_device_register(&vpif_capture_dev);
}
int __init dm646x_init_edma(struct edma_rsv_info *rsv)
{
struct platform_device *edma_pdev;
dm646x_edma_pdata.rsv = rsv;
edma_pdev = platform_device_register_full(&dm646x_edma_device);
return IS_ERR(edma_pdev) ? PTR_ERR(edma_pdev) : 0;
}
void __init dm646x_init(void)
{
davinci_common_init(&davinci_soc_info_dm646x);
davinci_map_sysmod();
davinci_clk_init(davinci_soc_info_dm646x.cpu_clks);
}
static int __init dm646x_init_devices(void)
{
int ret = 0;
if (!cpu_is_davinci_dm646x())
return 0;
platform_device_register(&dm646x_mdio_device);
platform_device_register(&dm646x_emac_device);
ret = davinci_init_wdt();
if (ret)
pr_warn("%s: watchdog init failed: %d\n", __func__, ret);
return ret;
}
