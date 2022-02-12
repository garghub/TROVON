static int ns2_pci_phy_init(struct phy *p)
{
struct ns2_pci_phy *phy = phy_get_drvdata(p);
int rc;
rc = mdiobus_write(phy->mdiodev->bus, phy->mdiodev->addr,
BLK_ADDR_REG_OFFSET, PLL_AFE1_100MHZ_BLK);
if (rc)
goto err;
rc = mdiobus_write(phy->mdiodev->bus, phy->mdiodev->addr,
PLL_CLK_AMP_OFFSET, PLL_CLK_AMP_2P05V);
if (rc)
goto err;
return 0;
err:
dev_err(&phy->mdiodev->dev, "Error %d writing to phy\n", rc);
return rc;
}
static int ns2_pci_phy_probe(struct mdio_device *mdiodev)
{
struct device *dev = &mdiodev->dev;
struct phy_provider *provider;
struct ns2_pci_phy *p;
struct phy *phy;
phy = devm_phy_create(dev, dev->of_node, &ns2_pci_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create Phy\n");
return PTR_ERR(phy);
}
p = devm_kmalloc(dev, sizeof(struct ns2_pci_phy),
GFP_KERNEL);
if (!p)
return -ENOMEM;
p->mdiodev = mdiodev;
dev_set_drvdata(dev, p);
p->phy = phy;
phy_set_drvdata(phy, p);
provider = devm_of_phy_provider_register(&phy->dev,
of_phy_simple_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "failed to register Phy provider\n");
return PTR_ERR(provider);
}
dev_info(dev, "%s PHY registered\n", dev_name(dev));
return 0;
}
