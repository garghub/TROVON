static inline void hisi_pcie_apb_writel(struct hisi_pcie *pcie,
u32 val, u32 reg)
{
writel(val, pcie->reg_base + reg);
}
static inline u32 hisi_pcie_apb_readl(struct hisi_pcie *pcie, u32 reg)
{
return readl(pcie->reg_base + reg);
}
static int hisi_pcie_cfg_read(struct pcie_port *pp, int where, int size,
u32 *val)
{
u32 reg;
u32 reg_val;
struct hisi_pcie *pcie = to_hisi_pcie(pp);
void *walker = &reg_val;
walker += (where & 0x3);
reg = where & ~0x3;
reg_val = hisi_pcie_apb_readl(pcie, reg);
if (size == 1)
*val = *(u8 __force *) walker;
else if (size == 2)
*val = *(u16 __force *) walker;
else if (size == 4)
*val = reg_val;
else
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
static int hisi_pcie_cfg_write(struct pcie_port *pp, int where, int size,
u32 val)
{
u32 reg_val;
u32 reg;
struct hisi_pcie *pcie = to_hisi_pcie(pp);
void *walker = &reg_val;
walker += (where & 0x3);
reg = where & ~0x3;
if (size == 4)
hisi_pcie_apb_writel(pcie, val, reg);
else if (size == 2) {
reg_val = hisi_pcie_apb_readl(pcie, reg);
*(u16 __force *) walker = val;
hisi_pcie_apb_writel(pcie, reg_val, reg);
} else if (size == 1) {
reg_val = hisi_pcie_apb_readl(pcie, reg);
*(u8 __force *) walker = val;
hisi_pcie_apb_writel(pcie, reg_val, reg);
} else
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
static int hisi_pcie_link_up(struct pcie_port *pp)
{
u32 val;
struct hisi_pcie *hisi_pcie = to_hisi_pcie(pp);
regmap_read(hisi_pcie->subctrl, PCIE_SUBCTRL_SYS_STATE4_REG +
0x100 * hisi_pcie->port_id, &val);
return ((val & PCIE_LTSSM_STATE_MASK) == PCIE_LTSSM_LINKUP_STATE);
}
static int hisi_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
u32 port_id;
struct hisi_pcie *hisi_pcie = to_hisi_pcie(pp);
if (of_property_read_u32(pdev->dev.of_node, "port-id", &port_id)) {
dev_err(&pdev->dev, "failed to read port-id\n");
return -EINVAL;
}
if (port_id > 3) {
dev_err(&pdev->dev, "Invalid port-id: %d\n", port_id);
return -EINVAL;
}
hisi_pcie->port_id = port_id;
pp->ops = &hisi_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int hisi_pcie_probe(struct platform_device *pdev)
{
struct hisi_pcie *hisi_pcie;
struct pcie_port *pp;
struct resource *reg;
int ret;
hisi_pcie = devm_kzalloc(&pdev->dev, sizeof(*hisi_pcie), GFP_KERNEL);
if (!hisi_pcie)
return -ENOMEM;
pp = &hisi_pcie->pp;
pp->dev = &pdev->dev;
hisi_pcie->subctrl =
syscon_regmap_lookup_by_compatible("hisilicon,pcie-sas-subctrl");
if (IS_ERR(hisi_pcie->subctrl)) {
dev_err(pp->dev, "cannot get subctrl base\n");
return PTR_ERR(hisi_pcie->subctrl);
}
reg = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rc_dbi");
hisi_pcie->reg_base = devm_ioremap_resource(&pdev->dev, reg);
if (IS_ERR(hisi_pcie->reg_base)) {
dev_err(pp->dev, "cannot get rc_dbi base\n");
return PTR_ERR(hisi_pcie->reg_base);
}
hisi_pcie->pp.dbi_base = hisi_pcie->reg_base;
ret = hisi_add_pcie_port(pp, pdev);
if (ret)
return ret;
platform_set_drvdata(pdev, hisi_pcie);
dev_warn(pp->dev, "only 32-bit config accesses supported; smaller writes may corrupt adjacent RW1C fields\n");
return 0;
}
