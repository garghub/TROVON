static void dw_mci_rockchip_prepare_command(struct dw_mci *host, u32 *cmdr)
{
*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}
static int dw_mci_rk3288_setup_clock(struct dw_mci *host)
{
host->bus_hz /= RK3288_CLKGEN_DIV;
return 0;
}
static void dw_mci_rk3288_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
unsigned int cclkin;
u32 bus_hz;
if (ios->clock == 0)
return;
if (ios->bus_width == MMC_BUS_WIDTH_8 &&
ios->timing == MMC_TIMING_MMC_DDR52)
cclkin = 2 * ios->clock * RK3288_CLKGEN_DIV;
else
cclkin = ios->clock * RK3288_CLKGEN_DIV;
ret = clk_set_rate(host->ciu_clk, cclkin);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", ios->clock);
bus_hz = clk_get_rate(host->ciu_clk) / RK3288_CLKGEN_DIV;
if (bus_hz != host->bus_hz) {
host->bus_hz = bus_hz;
host->current_speed = 0;
}
}
static int dw_mci_rockchip_init(struct dw_mci *host)
{
host->sdio_id0 = 8;
host->pdata->quirks |= DW_MCI_QUIRK_BROKEN_DTO;
return 0;
}
static int dw_mci_rockchip_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
if (!pdev->dev.of_node)
return -ENODEV;
match = of_match_node(dw_mci_rockchip_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
static int dw_mci_rockchip_suspend(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
return dw_mci_suspend(host);
}
static int dw_mci_rockchip_resume(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
return dw_mci_resume(host);
}
