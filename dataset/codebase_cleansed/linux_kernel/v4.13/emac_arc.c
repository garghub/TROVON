static int emac_arc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct net_device *ndev;
struct arc_emac_priv *priv;
int interface, err;
if (!dev->of_node)
return -ENODEV;
ndev = alloc_etherdev(sizeof(struct arc_emac_priv));
if (!ndev)
return -ENOMEM;
platform_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, dev);
priv = netdev_priv(ndev);
priv->drv_name = DRV_NAME;
priv->drv_version = DRV_VERSION;
interface = of_get_phy_mode(dev->of_node);
if (interface < 0)
interface = PHY_INTERFACE_MODE_MII;
priv->clk = devm_clk_get(dev, "hclk");
if (IS_ERR(priv->clk)) {
dev_err(dev, "failed to retrieve host clock from device tree\n");
err = -EINVAL;
goto out_netdev;
}
err = arc_emac_probe(ndev, interface);
out_netdev:
if (err)
free_netdev(ndev);
return err;
}
static int emac_arc_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
int err;
err = arc_emac_remove(ndev);
free_netdev(ndev);
return err;
}
