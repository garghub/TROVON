static int ls_pcie_link_up(struct pcie_port *pp)
{
u32 state;
struct ls_pcie *pcie = to_ls_pcie(pp);
regmap_read(pcie->scfg, SCFG_PEXMSCPORTSR(pcie->index), &state);
state = (state >> LTSSM_STATE_SHIFT) & LTSSM_STATE_MASK;
if (state < LTSSM_PCIE_L0)
return 0;
return 1;
}
static void ls_pcie_host_init(struct pcie_port *pp)
{
struct ls_pcie *pcie = to_ls_pcie(pp);
int count = 0;
u32 val;
dw_pcie_setup_rc(pp);
while (!ls_pcie_link_up(pp)) {
usleep_range(100, 1000);
count++;
if (count >= 200) {
dev_err(pp->dev, "phy link never came up\n");
return;
}
}
val = ioread32(pcie->dbi + PCIE_STRFMR1);
val &= 0xffff;
iowrite32(val, pcie->dbi + PCIE_STRFMR1);
}
static int ls_add_pcie_port(struct ls_pcie *pcie)
{
struct pcie_port *pp;
int ret;
pp = &pcie->pp;
pp->dev = pcie->dev;
pp->dbi_base = pcie->dbi;
pp->root_bus_nr = -1;
pp->ops = &ls_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(pp->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __init ls_pcie_probe(struct platform_device *pdev)
{
struct ls_pcie *pcie;
struct resource *dbi_base;
u32 index[2];
int ret;
pcie = devm_kzalloc(&pdev->dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = &pdev->dev;
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "regs");
if (!dbi_base) {
dev_err(&pdev->dev, "missing *regs* space\n");
return -ENODEV;
}
pcie->dbi = devm_ioremap_resource(&pdev->dev, dbi_base);
if (IS_ERR(pcie->dbi))
return PTR_ERR(pcie->dbi);
pcie->scfg = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"fsl,pcie-scfg");
if (IS_ERR(pcie->scfg)) {
dev_err(&pdev->dev, "No syscfg phandle specified\n");
return PTR_ERR(pcie->scfg);
}
ret = of_property_read_u32_array(pdev->dev.of_node,
"fsl,pcie-scfg", index, 2);
if (ret)
return ret;
pcie->index = index[1];
ret = ls_add_pcie_port(pcie);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, pcie);
return 0;
}
