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
if (of_property_read_bool(np, "brcm,pcie-ob")) {
u32 val;
ret = of_property_read_u32(np, "brcm,pcie-ob-axi-offset",
&val);
if (ret) {
dev_err(pcie->dev,
"missing brcm,pcie-ob-axi-offset property\n");
return ret;
}
pcie->ob.axi_offset = val;
ret = of_property_read_u32(np, "brcm,pcie-ob-window-size",
&val);
if (ret) {
dev_err(pcie->dev,
"missing brcm,pcie-ob-window-size property\n");
return ret;
}
pcie->ob.window_size = (resource_size_t)val * SZ_1M;
if (of_property_read_bool(np, "brcm,pcie-ob-oarr-size"))
pcie->ob.set_oarr_size = true;
pcie->need_ob_cfg = true;
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
pcie->map_irq = of_irq_parse_and_map_pci;
ret = iproc_pcie_setup(pcie, &res);
if (ret)
dev_err(pcie->dev, "PCIe controller setup failed\n");
pci_free_resource_list(&res);
return ret;
}
static int iproc_pcie_pltfm_remove(struct platform_device *pdev)
{
struct iproc_pcie *pcie = platform_get_drvdata(pdev);
return iproc_pcie_remove(pcie);
}
