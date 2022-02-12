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
void da8xx_restart(enum reboot_mode mode, const char *cmd)
{
struct device *dev;
dev = bus_find_device_by_name(&platform_bus_type, NULL, "watchdog");
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
ret = platform_device_register(&da8xx_emac_device);
if (ret < 0)
return ret;
ret = clk_add_alias(NULL, dev_name(&da8xx_mdio_device.dev),
NULL, &da8xx_emac_device.dev);
return ret;
}
void __init da8xx_register_mcasp(int id, struct snd_platform_data *pdata)
{
if (cpu_is_davinci_da830() && id == 1) {
da830_mcasp1_device.dev.platform_data = pdata;
platform_device_register(&da830_mcasp1_device);
} else if (cpu_is_davinci_da850()) {
da850_mcasp_device.dev.platform_data = pdata;
platform_device_register(&da850_mcasp_device);
}
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
int ret;
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
static int da850_sata_init(struct device *dev, void __iomem *addr)
{
int i, ret;
unsigned int val;
da850_sata_clk = clk_get(dev, NULL);
if (IS_ERR(da850_sata_clk))
return PTR_ERR(da850_sata_clk);
ret = clk_prepare_enable(da850_sata_clk);
if (ret)
goto err0;
val = __raw_readl(DA8XX_SYSCFG1_VIRT(DA8XX_PWRDN_REG));
val &= ~BIT(0);
__raw_writel(val, DA8XX_SYSCFG1_VIRT(DA8XX_PWRDN_REG));
for (i = 0; i < ARRAY_SIZE(da850_sata_xtal); i++)
if (da850_sata_xtal[i] == da850_sata_refclkpn)
break;
if (i == ARRAY_SIZE(da850_sata_xtal)) {
ret = -EINVAL;
goto err1;
}
val = SATA_PHY_MPY(i + 1) |
SATA_PHY_LOS(1) |
SATA_PHY_RXCDR(4) |
SATA_PHY_RXEQ(1) |
SATA_PHY_TXSWING(3) |
SATA_PHY_ENPLL(1);
__raw_writel(val, addr + SATA_P0PHYCR_REG);
return 0;
err1:
clk_disable_unprepare(da850_sata_clk);
err0:
clk_put(da850_sata_clk);
return ret;
}
static void da850_sata_exit(struct device *dev)
{
clk_disable_unprepare(da850_sata_clk);
clk_put(da850_sata_clk);
}
int __init da850_register_sata(unsigned long refclkpn)
{
da850_sata_refclkpn = refclkpn;
if (!da850_sata_refclkpn)
return -EINVAL;
return platform_device_register(&da850_sata_device);
}
