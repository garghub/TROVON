static bool ls_pcie_is_bridge(struct ls_pcie *pcie)
{
u32 header_type;
header_type = ioread8(pcie->dbi + PCI_HEADER_TYPE);
header_type &= 0x7f;
return header_type == PCI_HEADER_TYPE_BRIDGE;
}
static void ls_pcie_clear_multifunction(struct ls_pcie *pcie)
{
iowrite8(PCI_HEADER_TYPE_BRIDGE, pcie->dbi + PCI_HEADER_TYPE);
}
static void ls_pcie_fix_class(struct ls_pcie *pcie)
{
iowrite16(PCI_CLASS_BRIDGE_PCI, pcie->dbi + PCI_CLASS_DEVICE);
}
static void ls_pcie_drop_msg_tlp(struct ls_pcie *pcie)
{
u32 val;
val = ioread32(pcie->dbi + PCIE_STRFMR1);
val &= 0xDFFFFFFF;
iowrite32(val, pcie->dbi + PCIE_STRFMR1);
}
static int ls1021_pcie_link_up(struct pcie_port *pp)
{
u32 state;
struct ls_pcie *pcie = to_ls_pcie(pp);
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
struct ls_pcie *pcie = to_ls_pcie(pp);
u32 index[2];
pcie->scfg = syscon_regmap_lookup_by_phandle(pp->dev->of_node,
"fsl,pcie-scfg");
if (IS_ERR(pcie->scfg)) {
dev_err(pp->dev, "No syscfg phandle specified\n");
pcie->scfg = NULL;
return;
}
if (of_property_read_u32_array(pp->dev->of_node,
"fsl,pcie-scfg", index, 2)) {
pcie->scfg = NULL;
return;
}
pcie->index = index[1];
dw_pcie_setup_rc(pp);
ls_pcie_drop_msg_tlp(pcie);
}
static int ls_pcie_link_up(struct pcie_port *pp)
{
struct ls_pcie *pcie = to_ls_pcie(pp);
u32 state;
state = (ioread32(pcie->lut + PCIE_LUT_DBG) >>
pcie->drvdata->ltssm_shift) &
LTSSM_STATE_MASK;
if (state < LTSSM_PCIE_L0)
return 0;
return 1;
}
static void ls_pcie_host_init(struct pcie_port *pp)
{
struct ls_pcie *pcie = to_ls_pcie(pp);
iowrite32(1, pcie->dbi + PCIE_DBI_RO_WR_EN);
ls_pcie_fix_class(pcie);
ls_pcie_clear_multifunction(pcie);
ls_pcie_drop_msg_tlp(pcie);
iowrite32(0, pcie->dbi + PCIE_DBI_RO_WR_EN);
}
static int ls_pcie_msi_host_init(struct pcie_port *pp,
struct msi_controller *chip)
{
struct device_node *msi_node;
struct device_node *np = pp->dev->of_node;
msi_node = of_parse_phandle(np, "msi-parent", 0);
if (!msi_node) {
dev_err(pp->dev, "failed to find msi-parent\n");
return -EINVAL;
}
return 0;
}
static int __init ls_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
struct ls_pcie *pcie = to_ls_pcie(pp);
pp->dev = &pdev->dev;
pp->dbi_base = pcie->dbi;
pp->ops = pcie->drvdata->ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(pp->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __init ls_pcie_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct ls_pcie *pcie;
struct resource *dbi_base;
int ret;
match = of_match_device(ls_pcie_of_match, &pdev->dev);
if (!match)
return -ENODEV;
pcie = devm_kzalloc(&pdev->dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "regs");
pcie->dbi = devm_ioremap_resource(&pdev->dev, dbi_base);
if (IS_ERR(pcie->dbi)) {
dev_err(&pdev->dev, "missing *regs* space\n");
return PTR_ERR(pcie->dbi);
}
pcie->drvdata = match->data;
pcie->lut = pcie->dbi + pcie->drvdata->lut_offset;
if (!ls_pcie_is_bridge(pcie))
return -ENODEV;
ret = ls_add_pcie_port(&pcie->pp, pdev);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, pcie);
return 0;
}
