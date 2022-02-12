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
void __iomem *base = IO_ADDRESS(DAVINCI_SYSTEM_MODULE_BASE);
value = __raw_readl(base + VSCLKDIS_OFFSET);
value &= ~VSCLKDIS_MASK;
__raw_writel(value, base + VSCLKDIS_OFFSET);
value = __raw_readl(base + VDD3P3V_PWDN_OFFSET);
value &= ~VDD3P3V_VID_MASK;
__raw_writel(value, base + VDD3P3V_PWDN_OFFSET);
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
edma_cc0_info.rsv = rsv;
return platform_device_register(&dm646x_edma_device);
}
void __init dm646x_init(void)
{
davinci_common_init(&davinci_soc_info_dm646x);
}
static int __init dm646x_init_devices(void)
{
if (!cpu_is_davinci_dm646x())
return 0;
platform_device_register(&dm646x_mdio_device);
platform_device_register(&dm646x_emac_device);
clk_add_alias(NULL, dev_name(&dm646x_mdio_device.dev),
NULL, &dm646x_emac_device.dev);
return 0;
}
