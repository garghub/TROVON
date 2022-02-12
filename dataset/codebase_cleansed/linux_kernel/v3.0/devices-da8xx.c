int __init da830_register_edma(struct edma_rsv_info *rsv)
{
da830_edma_cc0_info.rsv = rsv;
return platform_device_register(&da830_edma_device);
}
int __init da850_register_edma(struct edma_rsv_info *rsv[2])
{
if (rsv) {
da850_edma_cc_info[0].rsv = rsv[0];
da850_edma_cc_info[1].rsv = rsv[1];
}
return platform_device_register(&da850_edma_device);
}
int __init da8xx_register_i2c(int instance,
struct davinci_i2c_platform_data *pdata)
{
struct platform_device *pdev;
if (instance == 0)
pdev = &da8xx_i2c_device0;
else if (instance == 1)
pdev = &da8xx_i2c_device1;
else
return -EINVAL;
pdev->dev.platform_data = pdata;
return platform_device_register(pdev);
}
int __init da8xx_register_watchdog(void)
{
return platform_device_register(&da8xx_wdt_device);
}
int __init da8xx_register_emac(void)
{
int ret;
ret = platform_device_register(&da8xx_mdio_device);
if (ret < 0)
return ret;
ret = platform_device_register(&da8xx_emac_device);
if (ret < 0)
return ret;
ret = clk_add_alias(NULL, dev_name(&da8xx_mdio_device.dev),
NULL, &da8xx_emac_device.dev);
return ret;
}
void __init da8xx_register_mcasp(int id, struct snd_platform_data *pdata)
{
platform_device_register(&davinci_pcm_device);
if (cpu_is_davinci_da830() && id == 1) {
da830_mcasp1_device.dev.platform_data = pdata;
platform_device_register(&da830_mcasp1_device);
} else if (cpu_is_davinci_da850()) {
da850_mcasp_device.dev.platform_data = pdata;
platform_device_register(&da850_mcasp_device);
}
}
int __init da8xx_register_lcdc(struct da8xx_lcdc_platform_data *pdata)
{
da8xx_lcdc_device.dev.platform_data = pdata;
return platform_device_register(&da8xx_lcdc_device);
}
int __init da8xx_register_mmcsd0(struct davinci_mmc_config *config)
{
da8xx_mmcsd0_device.dev.platform_data = config;
return platform_device_register(&da8xx_mmcsd0_device);
}
int __init da850_register_mmcsd1(struct davinci_mmc_config *config)
{
da850_mmcsd1_device.dev.platform_data = config;
return platform_device_register(&da850_mmcsd1_device);
}
int da8xx_register_rtc(void)
{
int ret;
void __iomem *base;
base = ioremap(DA8XX_RTC_BASE, SZ_4K);
if (WARN_ON(!base))
return -ENOMEM;
__raw_writel(0x83e70b13, base + 0x6c);
__raw_writel(0x95a4f1e0, base + 0x70);
iounmap(base);
ret = platform_device_register(&da8xx_rtc_device);
if (!ret)
device_init_wakeup(&da8xx_rtc_device.dev, true);
return ret;
}
void __iomem * __init da8xx_get_mem_ctlr(void)
{
if (da8xx_ddr2_ctlr_base)
return da8xx_ddr2_ctlr_base;
da8xx_ddr2_ctlr_base = ioremap(DA8XX_DDR2_CTL_BASE, SZ_32K);
if (!da8xx_ddr2_ctlr_base)
pr_warning("%s: Unable to map DDR2 controller", __func__);
return da8xx_ddr2_ctlr_base;
}
int __init da8xx_register_cpuidle(void)
{
da8xx_cpuidle_pdata.ddr2_ctlr_base = da8xx_get_mem_ctlr();
return platform_device_register(&da8xx_cpuidle_device);
}
int __init da8xx_register_spi(int instance, struct spi_board_info *info,
unsigned len)
{
int ret;
if (instance < 0 || instance > 1)
return -EINVAL;
ret = spi_register_board_info(info, len);
if (ret)
pr_warning("%s: failed to register board info for spi %d :"
" %d\n", __func__, instance, ret);
da8xx_spi_pdata[instance].num_chipselect = len;
if (instance == 1 && cpu_is_davinci_da850()) {
da8xx_spi1_resources[0].start = DA850_SPI1_BASE;
da8xx_spi1_resources[0].end = DA850_SPI1_BASE + SZ_4K - 1;
}
return platform_device_register(&da8xx_spi_device[instance]);
}
