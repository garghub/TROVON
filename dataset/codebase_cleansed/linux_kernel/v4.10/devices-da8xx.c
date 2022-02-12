int __init da830_register_edma(struct edma_rsv_info *rsv)
{
struct platform_device *edma_pdev;
da8xx_edma0_pdata.rsv = rsv;
da8xx_edma0_pdata.slave_map = da830_edma_map;
da8xx_edma0_pdata.slavecnt = ARRAY_SIZE(da830_edma_map);
edma_pdev = platform_device_register_full(&da8xx_edma0_device);
return IS_ERR(edma_pdev) ? PTR_ERR(edma_pdev) : 0;
}
int __init da850_register_edma(struct edma_rsv_info *rsv[2])
{
struct platform_device *edma_pdev;
if (rsv) {
da8xx_edma0_pdata.rsv = rsv[0];
da850_edma1_pdata.rsv = rsv[1];
}
da8xx_edma0_pdata.slave_map = da850_edma0_map;
da8xx_edma0_pdata.slavecnt = ARRAY_SIZE(da850_edma0_map);
edma_pdev = platform_device_register_full(&da8xx_edma0_device);
if (IS_ERR(edma_pdev)) {
pr_warn("%s: Failed to register eDMA0\n", __func__);
return PTR_ERR(edma_pdev);
}
da850_edma1_pdata.slave_map = da850_edma1_map;
da850_edma1_pdata.slavecnt = ARRAY_SIZE(da850_edma1_map);
edma_pdev = platform_device_register_full(&da850_edma1_device);
return IS_ERR(edma_pdev) ? PTR_ERR(edma_pdev) : 0;
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
void da8xx_restart(enum reboot_mode mode, const char *cmd)
{
struct device *dev;
dev = bus_find_device_by_name(&platform_bus_type, NULL, "davinci-wdt");
if (!dev) {
pr_err("%s: failed to find watchdog device\n", __func__);
return;
}
davinci_watchdog_reset(to_platform_device(dev));
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
return platform_device_register(&da8xx_emac_device);
}
void __init da8xx_register_mcasp(int id, struct snd_platform_data *pdata)
{
struct platform_device *pdev;
switch (id) {
case 0:
pdev = &da850_mcasp_device;
break;
case 1:
if (!cpu_is_davinci_da830())
return;
pdev = &da830_mcasp1_device;
break;
case 2:
if (!cpu_is_davinci_da830())
return;
pdev = &da830_mcasp2_device;
break;
default:
return;
}
pdev->dev.platform_data = pdata;
platform_device_register(pdev);
}
int __init da8xx_register_uio_pruss(void)
{
da8xx_uio_pruss_pdata.sram_pool = sram_get_gen_pool();
return platform_device_register(&da8xx_uio_pruss_dev);
}
int __init da8xx_register_lcdc(struct da8xx_lcdc_platform_data *pdata)
{
da8xx_lcdc_device.dev.platform_data = pdata;
return platform_device_register(&da8xx_lcdc_device);
}
int __init da8xx_register_gpio(void *pdata)
{
da8xx_gpio_device.dev.platform_data = pdata;
return platform_device_register(&da8xx_gpio_device);
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
static int __init early_rproc_mem(char *p)
{
char *endp;
if (p == NULL)
return 0;
rproc_size = memparse(p, &endp);
if (*endp == '@')
rproc_base = memparse(endp + 1, NULL);
return 0;
}
void __init da8xx_rproc_reserve_cma(void)
{
int ret;
if (!rproc_base || !rproc_size) {
pr_err("%s: 'rproc_mem=nn@address' badly specified\n"
" 'nn' and 'address' must both be non-zero\n",
__func__);
return;
}
pr_info("%s: reserving 0x%lx @ 0x%lx...\n",
__func__, rproc_size, (unsigned long)rproc_base);
ret = dma_declare_contiguous(&da8xx_dsp.dev, rproc_size, rproc_base, 0);
if (ret)
pr_err("%s: dma_declare_contiguous failed %d\n", __func__, ret);
}
void __init da8xx_rproc_reserve_cma(void)
{
}
int __init da8xx_register_rproc(void)
{
int ret;
ret = platform_device_register(&da8xx_dsp);
if (ret)
pr_err("%s: can't register DSP device: %d\n", __func__, ret);
return ret;
}
int da8xx_register_rtc(void)
{
return platform_device_register(&da8xx_rtc_device);
}
void __iomem * __init da8xx_get_mem_ctlr(void)
{
if (da8xx_ddr2_ctlr_base)
return da8xx_ddr2_ctlr_base;
da8xx_ddr2_ctlr_base = ioremap(DA8XX_DDR2_CTL_BASE, SZ_32K);
if (!da8xx_ddr2_ctlr_base)
pr_warn("%s: Unable to map DDR2 controller", __func__);
return da8xx_ddr2_ctlr_base;
}
int __init da8xx_register_cpuidle(void)
{
da8xx_cpuidle_pdata.ddr2_ctlr_base = da8xx_get_mem_ctlr();
return platform_device_register(&da8xx_cpuidle_device);
}
int __init da8xx_register_spi_bus(int instance, unsigned num_chipselect)
{
if (instance < 0 || instance > 1)
return -EINVAL;
da8xx_spi_pdata[instance].num_chipselect = num_chipselect;
if (instance == 1 && cpu_is_davinci_da850()) {
da8xx_spi1_resources[0].start = DA850_SPI1_BASE;
da8xx_spi1_resources[0].end = DA850_SPI1_BASE + SZ_4K - 1;
}
return platform_device_register(&da8xx_spi_device[instance]);
}
int __init da850_register_sata(unsigned long refclkpn)
{
BUG_ON(refclkpn != 100 * 1000 * 1000);
return platform_device_register(&da850_sata_device);
}
int __init da8xx_register_cfgchip(void)
{
return platform_device_register(&da8xx_cfgchip_device);
}
