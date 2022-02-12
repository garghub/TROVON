static int iproc_pcie_pltfm_probe(struct platform_device *pdev)
{
struct iproc_pcie *pcie;
struct device_node *np = pdev->dev.of_node;
struct resource reg;
resource_size_t iobase = 0;
LIST_HEAD(res);
int ret;
pcie = devm_kzalloc(&pdev->dev, sizeof(struct iproc_pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = &pdev->dev;
platform_set_drvdata(pdev, pcie);
ret = of_address_to_resource(np, 0, &reg);
if (ret < 0) {
dev_err(pcie->dev, "unable to obtain controller resources\n");
return ret;
}
pcie->base = devm_ioremap(pcie->dev, reg.start, resource_size(&reg));
if (!pcie->base) {
dev_err(pcie->dev, "unable to map controller registers\n");
return -ENOMEM;
}
pcie->phy = devm_phy_get(&pdev->dev, "pcie-phy");
if (IS_ERR(pcie->phy)) {
if (PTR_ERR(pcie->phy) == -EPROBE_DEFER)
return -EPROBE_DEFER;
pcie->phy = NULL;
}
ret = of_pci_get_host_bridge_resources(np, 0, 0xff, &res, &iobase);
if (ret) {
dev_err(pcie->dev,
"unable to get PCI host bridge resources\n");
return ret;
}
pcie->resources = &res;
ret = iproc_pcie_setup(pcie);
if (ret) {
dev_err(pcie->dev, "PCIe controller setup failed\n");
return ret;
}
return 0;
}
static int iproc_pcie_pltfm_remove(struct platform_device *pdev)
{
struct iproc_pcie *pcie = platform_get_drvdata(pdev);
return iproc_pcie_remove(pcie);
}
