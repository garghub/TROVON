static int armada375_usb_phy_init(struct phy *phy)
{
struct armada375_cluster_phy *cluster_phy;
u32 reg;
cluster_phy = dev_get_drvdata(phy->dev.parent);
if (!cluster_phy)
return -ENODEV;
reg = readl(cluster_phy->reg);
if (cluster_phy->use_usb3)
reg |= USB2_PHY_CONFIG_DISABLE;
else
reg &= ~USB2_PHY_CONFIG_DISABLE;
writel(reg, cluster_phy->reg);
return 0;
}
static struct phy *armada375_usb_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct armada375_cluster_phy *cluster_phy = dev_get_drvdata(dev);
if (!cluster_phy)
return ERR_PTR(-ENODEV);
if (WARN_ON((cluster_phy->phy_provided != PHY_NONE) &&
(cluster_phy->phy_provided != args->args[0]))) {
dev_err(dev, "This PHY has already been provided!\n");
dev_err(dev, "Check your device tree, only one controller can use it\n.");
if (args->args[0] == PHY_TYPE_USB2)
return ERR_PTR(-EBUSY);
else
return ERR_PTR(-ENODEV);
}
if (args->args[0] == PHY_TYPE_USB2)
cluster_phy->use_usb3 = false;
else if (args->args[0] == PHY_TYPE_USB3)
cluster_phy->use_usb3 = true;
else {
dev_err(dev, "Invalid PHY mode\n");
return ERR_PTR(-ENODEV);
}
cluster_phy->phy_provided = args->args[0];
return cluster_phy->phy;
}
static int armada375_usb_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct phy *phy;
struct phy_provider *phy_provider;
void __iomem *usb_cluster_base;
struct resource *res;
struct armada375_cluster_phy *cluster_phy;
cluster_phy = devm_kzalloc(dev, sizeof(*cluster_phy), GFP_KERNEL);
if (!cluster_phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
usb_cluster_base = devm_ioremap_resource(&pdev->dev, res);
if (!usb_cluster_base)
return -ENOMEM;
phy = devm_phy_create(dev, NULL, &armada375_usb_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(phy);
}
cluster_phy->phy = phy;
cluster_phy->reg = usb_cluster_base;
dev_set_drvdata(dev, cluster_phy);
phy_provider = devm_of_phy_provider_register(&pdev->dev,
armada375_usb_phy_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
