static bool ls_pcie_is_bridge(struct ls_pcie *pcie)
{
struct dw_pcie *pci = pcie->pci;
u32 header_type;
header_type = ioread8(pci->dbi_base + PCI_HEADER_TYPE);
header_type &= 0x7f;
return header_type == PCI_HEADER_TYPE_BRIDGE;
}
static void ls_pcie_clear_multifunction(struct ls_pcie *pcie)
{
struct dw_pcie *pci = pcie->pci;
iowrite8(PCI_HEADER_TYPE_BRIDGE, pci->dbi_base + PCI_HEADER_TYPE);
}
static void ls_pcie_fix_class(struct ls_pcie *pcie)
{
struct dw_pcie *pci = pcie->pci;
iowrite16(PCI_CLASS_BRIDGE_PCI, pci->dbi_base + PCI_CLASS_DEVICE);
}
static void ls_pcie_drop_msg_tlp(struct ls_pcie *pcie)
{
u32 val;
struct dw_pcie *pci = pcie->pci;
val = ioread32(pci->dbi_base + PCIE_STRFMR1);
val &= 0xDFFFFFFF;
iowrite32(val, pci->dbi_base + PCIE_STRFMR1);
}
static int ls1021_pcie_link_up(struct dw_pcie *pci)
{
u32 state;
struct ls_pcie *pcie = to_ls_pcie(pci);
if (!pcie->scfg)
return 0;
regmap_read(pcie->scfg, SCFG_PEXMSCPORTSR(pcie->index), &state);
state = (state >> LTSSM_STATE_SHIFT) & LTSSM_STATE_MASK;
if (state < LTSSM_PCIE_L0)
return 0;
return 1;
}
static void ls1021_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct ls_pcie *pcie = to_ls_pcie(pci);
struct device *dev = pci->dev;
u32 index[2];
pcie->scfg = syscon_regmap_lookup_by_phandle(dev->of_node,
"fsl,pcie-scfg");
if (IS_ERR(pcie->scfg)) {
dev_err(dev, "No syscfg phandle specified\n");
pcie->scfg = NULL;
return;
}
if (of_property_read_u32_array(dev->of_node,
"fsl,pcie-scfg", index, 2)) {
pcie->scfg = NULL;
return;
}
pcie->index = index[1];
dw_pcie_setup_rc(pp);
ls_pcie_drop_msg_tlp(pcie);
}
static int ls_pcie_link_up(struct dw_pcie *pci)
{
struct ls_pcie *pcie = to_ls_pcie(pci);
u32 state;
state = (ioread32(pcie->lut + pcie->drvdata->lut_dbg) >>
pcie->drvdata->ltssm_shift) &
LTSSM_STATE_MASK;
if (state < LTSSM_PCIE_L0)
return 0;
return 1;
}
static void ls_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct ls_pcie *pcie = to_ls_pcie(pci);
iowrite32(1, pci->dbi_base + PCIE_DBI_RO_WR_EN);
ls_pcie_fix_class(pcie);
ls_pcie_clear_multifunction(pcie);
ls_pcie_drop_msg_tlp(pcie);
iowrite32(0, pci->dbi_base + PCIE_DBI_RO_WR_EN);
}
static int ls_pcie_msi_host_init(struct pcie_port *pp,
struct msi_controller *chip)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct device *dev = pci->dev;
struct device_node *np = dev->of_node;
struct device_node *msi_node;
msi_node = of_parse_phandle(np, "msi-parent", 0);
if (!msi_node) {
dev_err(dev, "failed to find msi-parent\n");
return -EINVAL;
}
return 0;
}
static int __init ls_add_pcie_port(struct ls_pcie *pcie)
{
struct dw_pcie *pci = pcie->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = pci->dev;
int ret;
pp->ops = pcie->drvdata->ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __init ls_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_pcie *pci;
struct ls_pcie *pcie;
struct resource *dbi_base;
int ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pcie->drvdata = of_device_get_match_data(dev);
pci->dev = dev;
pci->ops = pcie->drvdata->dw_pcie_ops;
pcie->pci = pci;
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "regs");
pci->dbi_base = devm_pci_remap_cfg_resource(dev, dbi_base);
if (IS_ERR(pci->dbi_base))
return PTR_ERR(pci->dbi_base);
pcie->lut = pci->dbi_base + pcie->drvdata->lut_offset;
if (!ls_pcie_is_bridge(pcie))
return -ENODEV;
platform_set_drvdata(pdev, pcie);
ret = ls_add_pcie_port(pcie);
if (ret < 0)
return ret;
return 0;
}
