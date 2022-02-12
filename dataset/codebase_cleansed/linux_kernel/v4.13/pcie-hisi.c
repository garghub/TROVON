static int hisi_pcie_rd_conf(struct pci_bus *bus, u32 devfn, int where,
int size, u32 *val)
{
struct pci_config_window *cfg = bus->sysdata;
int dev = PCI_SLOT(devfn);
if (bus->number == cfg->busr.start) {
if (dev > 0)
return PCIBIOS_DEVICE_NOT_FOUND;
else
return pci_generic_config_read32(bus, devfn, where,
size, val);
}
return pci_generic_config_read(bus, devfn, where, size, val);
}
static int hisi_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct pci_config_window *cfg = bus->sysdata;
int dev = PCI_SLOT(devfn);
if (bus->number == cfg->busr.start) {
if (dev > 0)
return PCIBIOS_DEVICE_NOT_FOUND;
else
return pci_generic_config_write32(bus, devfn, where,
size, val);
}
return pci_generic_config_write(bus, devfn, where, size, val);
}
static void __iomem *hisi_pcie_map_bus(struct pci_bus *bus, unsigned int devfn,
int where)
{
struct pci_config_window *cfg = bus->sysdata;
void __iomem *reg_base = cfg->priv;
if (bus->number == cfg->busr.start)
return reg_base + where;
else
return pci_ecam_map_bus(bus, devfn, where);
}
static int hisi_pcie_init(struct pci_config_window *cfg)
{
struct device *dev = cfg->parent;
struct acpi_device *adev = to_acpi_device(dev);
struct acpi_pci_root *root = acpi_driver_data(adev);
struct resource *res;
void __iomem *reg_base;
int ret;
res = devm_kzalloc(dev, sizeof(*res), GFP_KERNEL);
if (!res)
return -ENOMEM;
ret = acpi_get_rc_resources(dev, "HISI0081", root->segment, res);
if (ret) {
dev_err(dev, "can't get rc base address\n");
return -ENOMEM;
}
reg_base = devm_pci_remap_cfgspace(dev, res->start, resource_size(res));
if (!reg_base)
return -ENOMEM;
cfg->priv = reg_base;
return 0;
}
static int hisi_pcie_cfg_read(struct pcie_port *pp, int where, int size,
u32 *val)
{
u32 reg;
u32 reg_val;
void *walker = &reg_val;
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
walker += (where & 0x3);
reg = where & ~0x3;
reg_val = dw_pcie_readl_dbi(pci, reg);
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
void *walker = &reg_val;
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
walker += (where & 0x3);
reg = where & ~0x3;
if (size == 4)
dw_pcie_writel_dbi(pci, reg, val);
else if (size == 2) {
reg_val = dw_pcie_readl_dbi(pci, reg);
*(u16 __force *) walker = val;
dw_pcie_writel_dbi(pci, reg, reg_val);
} else if (size == 1) {
reg_val = dw_pcie_readl_dbi(pci, reg);
*(u8 __force *) walker = val;
dw_pcie_writel_dbi(pci, reg, reg_val);
} else
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
static int hisi_pcie_link_up_hip05(struct hisi_pcie *hisi_pcie)
{
u32 val;
regmap_read(hisi_pcie->subctrl, PCIE_SUBCTRL_SYS_STATE4_REG +
0x100 * hisi_pcie->port_id, &val);
return ((val & PCIE_LTSSM_STATE_MASK) == PCIE_LTSSM_LINKUP_STATE);
}
static int hisi_pcie_link_up_hip06(struct hisi_pcie *hisi_pcie)
{
struct dw_pcie *pci = hisi_pcie->pci;
u32 val;
val = dw_pcie_readl_dbi(pci, PCIE_SYS_STATE4);
return ((val & PCIE_LTSSM_STATE_MASK) == PCIE_LTSSM_LINKUP_STATE);
}
static int hisi_pcie_link_up(struct dw_pcie *pci)
{
struct hisi_pcie *hisi_pcie = to_hisi_pcie(pci);
return hisi_pcie->soc_ops->hisi_pcie_link_up(hisi_pcie);
}
static int hisi_add_pcie_port(struct hisi_pcie *hisi_pcie,
struct platform_device *pdev)
{
struct dw_pcie *pci = hisi_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = &pdev->dev;
int ret;
u32 port_id;
if (of_property_read_u32(dev->of_node, "port-id", &port_id)) {
dev_err(dev, "failed to read port-id\n");
return -EINVAL;
}
if (port_id > 3) {
dev_err(dev, "Invalid port-id: %d\n", port_id);
return -EINVAL;
}
hisi_pcie->port_id = port_id;
pp->ops = &hisi_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int hisi_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_pcie *pci;
struct hisi_pcie *hisi_pcie;
struct resource *reg;
struct device_driver *driver;
int ret;
hisi_pcie = devm_kzalloc(dev, sizeof(*hisi_pcie), GFP_KERNEL);
if (!hisi_pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
driver = dev->driver;
hisi_pcie->pci = pci;
hisi_pcie->soc_ops = of_device_get_match_data(dev);
hisi_pcie->subctrl =
syscon_regmap_lookup_by_compatible("hisilicon,pcie-sas-subctrl");
if (IS_ERR(hisi_pcie->subctrl)) {
dev_err(dev, "cannot get subctrl base\n");
return PTR_ERR(hisi_pcie->subctrl);
}
reg = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rc_dbi");
pci->dbi_base = devm_pci_remap_cfg_resource(dev, reg);
if (IS_ERR(pci->dbi_base))
return PTR_ERR(pci->dbi_base);
platform_set_drvdata(pdev, hisi_pcie);
ret = hisi_add_pcie_port(hisi_pcie, pdev);
if (ret)
return ret;
return 0;
}
static int hisi_pcie_almost_ecam_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct pci_ecam_ops *ops;
ops = (struct pci_ecam_ops *)of_device_get_match_data(dev);
return pci_host_common_probe(pdev, ops);
}
static int hisi_pcie_platform_init(struct pci_config_window *cfg)
{
struct device *dev = cfg->parent;
struct platform_device *pdev = to_platform_device(dev);
struct resource *res;
void __iomem *reg_base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(dev, "missing \"reg[1]\"property\n");
return -EINVAL;
}
reg_base = devm_pci_remap_cfgspace(dev, res->start, resource_size(res));
if (!reg_base)
return -ENOMEM;
cfg->priv = reg_base;
return 0;
}
