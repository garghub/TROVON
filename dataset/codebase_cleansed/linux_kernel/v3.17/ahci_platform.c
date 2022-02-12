static int ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_platform_data *pdata = dev_get_platdata(dev);
struct ahci_host_priv *hpriv;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
if (pdata && pdata->init) {
rc = pdata->init(dev, hpriv->mmio);
if (rc)
goto disable_resources;
}
if (of_device_is_compatible(dev->of_node, "hisilicon,hisi-ahci"))
hpriv->flags |= AHCI_HFLAG_NO_FBS | AHCI_HFLAG_NO_NCQ;
rc = ahci_platform_init_host(pdev, hpriv, &ahci_port_info);
if (rc)
goto pdata_exit;
return 0;
pdata_exit:
if (pdata && pdata->exit)
pdata->exit(dev);
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
