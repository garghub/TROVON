static int iproc_pcie_pltfm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct iproc_pcie *pcie;
struct device_node *np = dev->of_node;
struct resource reg;
resource_size_t iobase = 0;
LIST_HEAD(res);
int ret;
of_id = of_match_device(iproc_pcie_of_match_table, dev);
if (!of_id)
return -EINVAL;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = dev;
pcie->type = (enum iproc_pcie_type)of_id->data;
ret = of_address_to_resource(np, 0, &reg);
if (ret < 0) {
dev_err(dev, "unable to obtain controller resources\n");
return ret;
}
pcie->base = devm_ioremap(dev, reg.start, resource_size(&reg));
if (!pcie->base) {
dev_err(dev, "unable to map controller registers\n");
return -ENOMEM;
}
pcie->base_addr = reg.start;
if (of_property_read_bool(np, "brcm,pcie-ob")) {
u32 val;
ret = of_property_read_u32(np, "brcm,pcie-ob-axi-offset",
&val);
if (ret) {
dev_err(dev,
"missing brcm,pcie-ob-axi-offset property\n");
return ret;
}
pcie->ob.axi_offset = val;
ret = of_property_read_u32(np, "brcm,pcie-ob-window-size",
&val);
if (ret) {
dev_err(dev,
"missing brcm,pcie-ob-window-size property\n");
return ret;
}
pcie->ob.window_size = (resource_size_t)val * SZ_1M;
if (of_property_read_bool(np, "brcm,pcie-ob-oarr-size"))
pcie->ob.set_oarr_size = true;
pcie->need_ob_cfg = true;
}
pcie->phy = devm_phy_get(dev, "pcie-phy");
if (IS_ERR(pcie->phy)) {
if (PTR_ERR(pcie->phy) == -EPROBE_DEFER)
return -EPROBE_DEFER;
pcie->phy = NULL;
}
ret = of_pci_get_host_bridge_resources(np, 0, 0xff, &res, &iobase);
if (ret) {
dev_err(dev,
"unable to get PCI host bridge resources\n");
return ret;
}
pcie->map_irq = of_irq_parse_and_map_pci;
ret = iproc_pcie_setup(pcie, &res);
if (ret)
dev_err(dev, "PCIe controller setup failed\n");
pci_free_resource_list(&res);
platform_set_drvdata(pdev, pcie);
return ret;
}
static int iproc_pcie_pltfm_remove(struct platform_device *pdev)
{
struct iproc_pcie *pcie = platform_get_drvdata(pdev);
return iproc_pcie_remove(pcie);
}
