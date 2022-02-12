static int stmmac_pltfr_probe(struct platform_device *pdev)
{
int ret = 0;
struct resource *res;
void __iomem *addr = NULL;
struct stmmac_priv *priv = NULL;
struct plat_stmmacenet_data *plat_dat;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
pr_err("%s: ERROR: memory allocation failed"
"cannot get the I/O addr 0x%x\n",
__func__, (unsigned int)res->start);
return -EBUSY;
}
addr = ioremap(res->start, resource_size(res));
if (!addr) {
pr_err("%s: ERROR: memory mapping failed", __func__);
ret = -ENOMEM;
goto out_release_region;
}
plat_dat = pdev->dev.platform_data;
if (plat_dat->init) {
ret = plat_dat->init(pdev);
if (unlikely(ret))
goto out_unmap;
}
priv = stmmac_dvr_probe(&(pdev->dev), plat_dat, addr);
if (!priv) {
pr_err("%s: main driver probe failed", __func__);
goto out_unmap;
}
priv->dev->irq = platform_get_irq_byname(pdev, "macirq");
if (priv->dev->irq == -ENXIO) {
pr_err("%s: ERROR: MAC IRQ configuration "
"information not found\n", __func__);
ret = -ENXIO;
goto out_unmap;
}
priv->wol_irq = platform_get_irq_byname(pdev, "eth_wake_irq");
if (priv->wol_irq == -ENXIO)
priv->wol_irq = priv->dev->irq;
platform_set_drvdata(pdev, priv->dev);
pr_debug("STMMAC platform driver registration completed");
return 0;
out_unmap:
iounmap(addr);
platform_set_drvdata(pdev, NULL);
out_release_region:
release_mem_region(res->start, resource_size(res));
return ret;
}
static int stmmac_pltfr_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct resource *res;
int ret = stmmac_dvr_remove(ndev);
if (priv->plat->exit)
priv->plat->exit(pdev);
if (priv->plat->exit)
priv->plat->exit(pdev);
platform_set_drvdata(pdev, NULL);
iounmap((void *)priv->ioaddr);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
return ret;
}
static int stmmac_pltfr_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_suspend(ndev);
}
static int stmmac_pltfr_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_resume(ndev);
}
int stmmac_pltfr_freeze(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_freeze(ndev);
}
int stmmac_pltfr_restore(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_restore(ndev);
}
