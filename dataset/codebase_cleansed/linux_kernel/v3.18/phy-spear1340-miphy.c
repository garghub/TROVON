static int spear1340_miphy_sata_init(struct spear1340_miphy_priv *priv)
{
regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
SPEAR1340_PCIE_SATA_CFG_MASK,
SPEAR1340_SATA_CFG_VAL);
regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
SPEAR1340_PCIE_MIPHY_CFG_MASK,
SPEAR1340_PCIE_SATA_MIPHY_CFG_SATA_25M_CRYSTAL_CLK);
regmap_update_bits(priv->misc, SPEAR1340_PCM_CFG,
SPEAR1340_PCM_CFG_SATA_POWER_EN,
SPEAR1340_PCM_CFG_SATA_POWER_EN);
msleep(20);
regmap_update_bits(priv->misc, SPEAR1340_PERIP1_SW_RST,
SPEAR1340_PERIP1_SW_RSATA, 0);
msleep(20);
return 0;
}
static int spear1340_miphy_sata_exit(struct spear1340_miphy_priv *priv)
{
regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
SPEAR1340_PCIE_SATA_CFG_MASK, 0);
regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
SPEAR1340_PCIE_MIPHY_CFG_MASK, 0);
regmap_update_bits(priv->misc, SPEAR1340_PERIP1_SW_RST,
SPEAR1340_PERIP1_SW_RSATA,
SPEAR1340_PERIP1_SW_RSATA);
msleep(20);
regmap_update_bits(priv->misc, SPEAR1340_PCM_CFG,
SPEAR1340_PCM_CFG_SATA_POWER_EN, 0);
msleep(20);
return 0;
}
static int spear1340_miphy_pcie_init(struct spear1340_miphy_priv *priv)
{
regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
SPEAR1340_PCIE_MIPHY_CFG_MASK,
SPEAR1340_PCIE_SATA_MIPHY_CFG_PCIE);
regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
SPEAR1340_PCIE_SATA_CFG_MASK,
SPEAR1340_PCIE_CFG_VAL);
return 0;
}
static int spear1340_miphy_pcie_exit(struct spear1340_miphy_priv *priv)
{
regmap_update_bits(priv->misc, SPEAR1340_PCIE_MIPHY_CFG,
SPEAR1340_PCIE_MIPHY_CFG_MASK, 0);
regmap_update_bits(priv->misc, SPEAR1340_PCIE_SATA_CFG,
SPEAR1340_PCIE_SATA_CFG_MASK, 0);
return 0;
}
static int spear1340_miphy_init(struct phy *phy)
{
struct spear1340_miphy_priv *priv = phy_get_drvdata(phy);
int ret = 0;
if (priv->mode == SATA)
ret = spear1340_miphy_sata_init(priv);
else if (priv->mode == PCIE)
ret = spear1340_miphy_pcie_init(priv);
return ret;
}
static int spear1340_miphy_exit(struct phy *phy)
{
struct spear1340_miphy_priv *priv = phy_get_drvdata(phy);
int ret = 0;
if (priv->mode == SATA)
ret = spear1340_miphy_sata_exit(priv);
else if (priv->mode == PCIE)
ret = spear1340_miphy_pcie_exit(priv);
return ret;
}
static int spear1340_miphy_suspend(struct device *dev)
{
struct spear1340_miphy_priv *priv = dev_get_drvdata(dev);
int ret = 0;
if (priv->mode == SATA)
ret = spear1340_miphy_sata_exit(priv);
return ret;
}
static int spear1340_miphy_resume(struct device *dev)
{
struct spear1340_miphy_priv *priv = dev_get_drvdata(dev);
int ret = 0;
if (priv->mode == SATA)
ret = spear1340_miphy_sata_init(priv);
return ret;
}
static struct phy *spear1340_miphy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct spear1340_miphy_priv *priv = dev_get_drvdata(dev);
if (args->args_count < 1) {
dev_err(dev, "DT did not pass correct no of args\n");
return NULL;
}
priv->mode = args->args[0];
if (priv->mode != SATA && priv->mode != PCIE) {
dev_err(dev, "DT did not pass correct phy mode\n");
return NULL;
}
return priv->phy;
}
static int spear1340_miphy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct spear1340_miphy_priv *priv;
struct phy_provider *phy_provider;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->misc =
syscon_regmap_lookup_by_phandle(dev->of_node, "misc");
if (IS_ERR(priv->misc)) {
dev_err(dev, "failed to find misc regmap\n");
return PTR_ERR(priv->misc);
}
priv->phy = devm_phy_create(dev, NULL, &spear1340_miphy_ops, NULL);
if (IS_ERR(priv->phy)) {
dev_err(dev, "failed to create SATA PCIe PHY\n");
return PTR_ERR(priv->phy);
}
dev_set_drvdata(dev, priv);
phy_set_drvdata(priv->phy, priv);
phy_provider =
devm_of_phy_provider_register(dev, spear1340_miphy_xlate);
if (IS_ERR(phy_provider)) {
dev_err(dev, "failed to register phy provider\n");
return PTR_ERR(phy_provider);
}
return 0;
}
