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
rc = ahci_platform_init_host(pdev, hpriv, &ahci_port_info, 0, 0);
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
