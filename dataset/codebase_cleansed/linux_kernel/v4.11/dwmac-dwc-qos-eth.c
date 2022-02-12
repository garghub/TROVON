static int dwc_eth_dwmac_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat_dat)
{
struct device_node *np = pdev->dev.of_node;
u32 burst_map = 0;
u32 bit_index = 0;
u32 a_index = 0;
if (!plat_dat->axi) {
plat_dat->axi = kzalloc(sizeof(struct stmmac_axi), GFP_KERNEL);
if (!plat_dat->axi)
return -ENOMEM;
}
plat_dat->axi->axi_lpi_en = of_property_read_bool(np, "snps,en-lpi");
if (of_property_read_u32(np, "snps,write-requests",
&plat_dat->axi->axi_wr_osr_lmt)) {
plat_dat->axi->axi_wr_osr_lmt = 1;
} else {
plat_dat->axi->axi_wr_osr_lmt--;
}
if (of_property_read_u32(np, "read,read-requests",
&plat_dat->axi->axi_rd_osr_lmt)) {
plat_dat->axi->axi_rd_osr_lmt = 1;
} else {
plat_dat->axi->axi_rd_osr_lmt--;
}
of_property_read_u32(np, "snps,burst-map", &burst_map);
for (bit_index = 0; bit_index < 7; bit_index++) {
if (burst_map & (1 << bit_index)) {
switch (bit_index) {
case 0:
plat_dat->axi->axi_blen[a_index] = 4; break;
case 1:
plat_dat->axi->axi_blen[a_index] = 8; break;
case 2:
plat_dat->axi->axi_blen[a_index] = 16; break;
case 3:
plat_dat->axi->axi_blen[a_index] = 32; break;
case 4:
plat_dat->axi->axi_blen[a_index] = 64; break;
case 5:
plat_dat->axi->axi_blen[a_index] = 128; break;
case 6:
plat_dat->axi->axi_blen[a_index] = 256; break;
default:
break;
}
a_index++;
}
}
plat_dat->has_gmac4 = 1;
plat_dat->dma_cfg->aal = 1;
plat_dat->tso_en = 1;
plat_dat->pmt = 1;
return 0;
}
static int dwc_eth_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct resource *res;
int ret;
memset(&stmmac_res, 0, sizeof(struct stmmac_resources));
stmmac_res.irq = platform_get_irq(pdev, 0);
if (stmmac_res.irq < 0) {
if (stmmac_res.irq != -EPROBE_DEFER)
dev_err(&pdev->dev,
"IRQ configuration information not found\n");
return stmmac_res.irq;
}
stmmac_res.wol_irq = stmmac_res.irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
stmmac_res.addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(stmmac_res.addr))
return PTR_ERR(stmmac_res.addr);
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
plat_dat->stmmac_clk = devm_clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(plat_dat->stmmac_clk)) {
dev_err(&pdev->dev, "apb_pclk clock not found.\n");
ret = PTR_ERR(plat_dat->stmmac_clk);
plat_dat->stmmac_clk = NULL;
goto err_remove_config_dt;
}
clk_prepare_enable(plat_dat->stmmac_clk);
plat_dat->pclk = devm_clk_get(&pdev->dev, "phy_ref_clk");
if (IS_ERR(plat_dat->pclk)) {
dev_err(&pdev->dev, "phy_ref_clk clock not found.\n");
ret = PTR_ERR(plat_dat->pclk);
plat_dat->pclk = NULL;
goto err_out_clk_dis_phy;
}
clk_prepare_enable(plat_dat->pclk);
ret = dwc_eth_dwmac_config_dt(pdev, plat_dat);
if (ret)
goto err_out_clk_dis_aper;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
goto err_out_clk_dis_aper;
return 0;
err_out_clk_dis_aper:
clk_disable_unprepare(plat_dat->pclk);
err_out_clk_dis_phy:
clk_disable_unprepare(plat_dat->stmmac_clk);
err_remove_config_dt:
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
static int dwc_eth_dwmac_remove(struct platform_device *pdev)
{
return stmmac_pltfr_remove(pdev);
}
