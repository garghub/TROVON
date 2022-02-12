static int imx6q_sata_init(struct device *dev, void __iomem *mmio)
{
int ret = 0;
unsigned int reg_val;
struct imx_ahci_priv *imxpriv = dev_get_drvdata(dev->parent);
imxpriv->gpr =
syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (IS_ERR(imxpriv->gpr)) {
dev_err(dev, "failed to find fsl,imx6q-iomux-gpr regmap\n");
return PTR_ERR(imxpriv->gpr);
}
ret = clk_prepare_enable(imxpriv->sata_ref_clk);
if (ret < 0) {
dev_err(dev, "prepare-enable sata_ref clock err:%d\n", ret);
return ret;
}
regmap_update_bits(imxpriv->gpr, 0x34, IMX6Q_GPR13_SATA_RX_EQ_VAL_MASK
| IMX6Q_GPR13_SATA_RX_LOS_LVL_MASK
| IMX6Q_GPR13_SATA_RX_DPLL_MODE_MASK
| IMX6Q_GPR13_SATA_SPD_MODE_MASK
| IMX6Q_GPR13_SATA_MPLL_SS_EN
| IMX6Q_GPR13_SATA_TX_ATTEN_MASK
| IMX6Q_GPR13_SATA_TX_BOOST_MASK
| IMX6Q_GPR13_SATA_TX_LVL_MASK
| IMX6Q_GPR13_SATA_TX_EDGE_RATE
, IMX6Q_GPR13_SATA_RX_EQ_VAL_3_0_DB
| IMX6Q_GPR13_SATA_RX_LOS_LVL_SATA2M
| IMX6Q_GPR13_SATA_RX_DPLL_MODE_2P_4F
| IMX6Q_GPR13_SATA_SPD_MODE_3P0G
| IMX6Q_GPR13_SATA_MPLL_SS_EN
| IMX6Q_GPR13_SATA_TX_ATTEN_9_16
| IMX6Q_GPR13_SATA_TX_BOOST_3_33_DB
| IMX6Q_GPR13_SATA_TX_LVL_1_025_V);
regmap_update_bits(imxpriv->gpr, 0x34, IMX6Q_GPR13_SATA_MPLL_CLK_EN,
IMX6Q_GPR13_SATA_MPLL_CLK_EN);
usleep_range(100, 200);
reg_val = readl(mmio + HOST_CAP);
if (!(reg_val & HOST_CAP_SSS)) {
reg_val |= HOST_CAP_SSS;
writel(reg_val, mmio + HOST_CAP);
}
reg_val = readl(mmio + HOST_PORTS_IMPL);
if (!(reg_val & 0x1)) {
reg_val |= 0x1;
writel(reg_val, mmio + HOST_PORTS_IMPL);
}
reg_val = clk_get_rate(imxpriv->ahb_clk) / 1000;
writel(reg_val, mmio + HOST_TIMER1MS);
return 0;
}
static void imx6q_sata_exit(struct device *dev)
{
struct imx_ahci_priv *imxpriv = dev_get_drvdata(dev->parent);
regmap_update_bits(imxpriv->gpr, 0x34, IMX6Q_GPR13_SATA_MPLL_CLK_EN,
!IMX6Q_GPR13_SATA_MPLL_CLK_EN);
clk_disable_unprepare(imxpriv->sata_ref_clk);
}
static int imx_ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *mem, *irq, res[2];
const struct of_device_id *of_id;
const struct ahci_platform_data *pdata = NULL;
struct imx_ahci_priv *imxpriv;
struct device *ahci_dev;
struct platform_device *ahci_pdev;
int ret;
imxpriv = devm_kzalloc(dev, sizeof(*imxpriv), GFP_KERNEL);
if (!imxpriv) {
dev_err(dev, "can't alloc ahci_host_priv\n");
return -ENOMEM;
}
ahci_pdev = platform_device_alloc("ahci", -1);
if (!ahci_pdev)
return -ENODEV;
ahci_dev = &ahci_pdev->dev;
ahci_dev->parent = dev;
imxpriv->ahb_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(imxpriv->ahb_clk)) {
dev_err(dev, "can't get ahb clock.\n");
ret = PTR_ERR(imxpriv->ahb_clk);
goto err_out;
}
imxpriv->sata_ref_clk = devm_clk_get(dev, "sata_ref");
if (IS_ERR(imxpriv->sata_ref_clk)) {
dev_err(dev, "can't get sata_ref clock.\n");
ret = PTR_ERR(imxpriv->sata_ref_clk);
goto err_out;
}
imxpriv->ahci_pdev = ahci_pdev;
platform_set_drvdata(pdev, imxpriv);
of_id = of_match_device(imx_ahci_of_match, dev);
if (of_id) {
pdata = of_id->data;
} else {
ret = -EINVAL;
goto err_out;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!mem || !irq) {
dev_err(dev, "no mmio/irq resource\n");
ret = -ENOMEM;
goto err_out;
}
res[0] = *mem;
res[1] = *irq;
ahci_dev->coherent_dma_mask = DMA_BIT_MASK(32);
ahci_dev->dma_mask = &ahci_dev->coherent_dma_mask;
ahci_dev->of_node = dev->of_node;
ret = platform_device_add_resources(ahci_pdev, res, 2);
if (ret)
goto err_out;
ret = platform_device_add_data(ahci_pdev, pdata, sizeof(*pdata));
if (ret)
goto err_out;
ret = platform_device_add(ahci_pdev);
if (ret) {
err_out:
platform_device_put(ahci_pdev);
return ret;
}
return 0;
}
static int imx_ahci_remove(struct platform_device *pdev)
{
struct imx_ahci_priv *imxpriv = platform_get_drvdata(pdev);
struct platform_device *ahci_pdev = imxpriv->ahci_pdev;
platform_device_unregister(ahci_pdev);
return 0;
}
