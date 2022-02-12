static u32 artpec6_pcie_readl(struct artpec6_pcie *artpec6_pcie, u32 offset)
{
u32 val;
regmap_read(artpec6_pcie->regmap, offset, &val);
return val;
}
static void artpec6_pcie_writel(struct artpec6_pcie *artpec6_pcie, u32 offset, u32 val)
{
regmap_write(artpec6_pcie->regmap, offset, val);
}
static int artpec6_pcie_establish_link(struct artpec6_pcie *artpec6_pcie)
{
struct dw_pcie *pci = artpec6_pcie->pci;
struct pcie_port *pp = &pci->pp;
u32 val;
unsigned int retries;
val = artpec6_pcie_readl(artpec6_pcie, PCIECFG);
val |= PCIECFG_CORE_RESET_REQ;
artpec6_pcie_writel(artpec6_pcie, PCIECFG, val);
val = artpec6_pcie_readl(artpec6_pcie, PCIECFG);
val |= PCIECFG_RISRCREN |
PCIECFG_MODE_TX_DRV_EN |
PCIECFG_CISRREN |
PCIECFG_MACRO_ENABLE;
val |= PCIECFG_REFCLK_ENABLE;
val &= ~PCIECFG_DBG_OEN;
val &= ~PCIECFG_CLKREQ_B;
artpec6_pcie_writel(artpec6_pcie, PCIECFG, val);
usleep_range(5000, 6000);
val = artpec6_pcie_readl(artpec6_pcie, NOCCFG);
val |= NOCCFG_ENABLE_CLK_PCIE;
artpec6_pcie_writel(artpec6_pcie, NOCCFG, val);
usleep_range(20, 30);
val = artpec6_pcie_readl(artpec6_pcie, PCIECFG);
val |= PCIECFG_PCLK_ENABLE | PCIECFG_PLL_ENABLE;
artpec6_pcie_writel(artpec6_pcie, PCIECFG, val);
usleep_range(6000, 7000);
val = artpec6_pcie_readl(artpec6_pcie, NOCCFG);
val &= ~NOCCFG_POWER_PCIE_IDLEREQ;
artpec6_pcie_writel(artpec6_pcie, NOCCFG, val);
retries = 50;
do {
usleep_range(1000, 2000);
val = artpec6_pcie_readl(artpec6_pcie, NOCCFG);
retries--;
} while (retries &&
(val & (NOCCFG_POWER_PCIE_IDLEACK | NOCCFG_POWER_PCIE_IDLE)));
retries = 50;
do {
usleep_range(1000, 2000);
val = readl(artpec6_pcie->phy_base + PHY_STATUS);
retries--;
} while (retries && !(val & PHY_COSPLLLOCK));
val = artpec6_pcie_readl(artpec6_pcie, PCIECFG);
val &= ~PCIECFG_CORE_RESET_REQ;
artpec6_pcie_writel(artpec6_pcie, PCIECFG, val);
usleep_range(100, 200);
dw_pcie_writel_dbi(pci, MISC_CONTROL_1_OFF, DBI_RO_WR_EN);
pp->io_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->mem_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->cfg0_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->cfg1_base &= ARTPEC6_CPU_TO_BUS_ADDR;
dw_pcie_setup_rc(pp);
val = artpec6_pcie_readl(artpec6_pcie, PCIECFG);
val |= PCIECFG_LTSSM_ENABLE;
artpec6_pcie_writel(artpec6_pcie, PCIECFG, val);
if (!dw_pcie_wait_for_link(pci))
return 0;
dev_dbg(pci->dev, "DEBUG_R0: 0x%08x, DEBUG_R1: 0x%08x\n",
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R0),
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R1));
return -ETIMEDOUT;
}
static void artpec6_pcie_enable_interrupts(struct artpec6_pcie *artpec6_pcie)
{
struct dw_pcie *pci = artpec6_pcie->pci;
struct pcie_port *pp = &pci->pp;
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
}
static void artpec6_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct artpec6_pcie *artpec6_pcie = to_artpec6_pcie(pci);
artpec6_pcie_establish_link(artpec6_pcie);
artpec6_pcie_enable_interrupts(artpec6_pcie);
}
static irqreturn_t artpec6_pcie_msi_handler(int irq, void *arg)
{
struct artpec6_pcie *artpec6_pcie = arg;
struct dw_pcie *pci = artpec6_pcie->pci;
struct pcie_port *pp = &pci->pp;
return dw_handle_msi_irq(pp);
}
static int artpec6_add_pcie_port(struct artpec6_pcie *artpec6_pcie,
struct platform_device *pdev)
{
struct dw_pcie *pci = artpec6_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = pci->dev;
int ret;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq_byname(pdev, "msi");
if (pp->msi_irq <= 0) {
dev_err(dev, "failed to get MSI irq\n");
return -ENODEV;
}
ret = devm_request_irq(dev, pp->msi_irq,
artpec6_pcie_msi_handler,
IRQF_SHARED | IRQF_NO_THREAD,
"artpec6-pcie-msi", artpec6_pcie);
if (ret) {
dev_err(dev, "failed to request MSI irq\n");
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &artpec6_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int artpec6_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_pcie *pci;
struct artpec6_pcie *artpec6_pcie;
struct resource *dbi_base;
struct resource *phy_base;
int ret;
artpec6_pcie = devm_kzalloc(dev, sizeof(*artpec6_pcie), GFP_KERNEL);
if (!artpec6_pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
artpec6_pcie->pci = pci;
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dbi");
pci->dbi_base = devm_ioremap_resource(dev, dbi_base);
if (IS_ERR(pci->dbi_base))
return PTR_ERR(pci->dbi_base);
phy_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy");
artpec6_pcie->phy_base = devm_ioremap_resource(dev, phy_base);
if (IS_ERR(artpec6_pcie->phy_base))
return PTR_ERR(artpec6_pcie->phy_base);
artpec6_pcie->regmap =
syscon_regmap_lookup_by_phandle(dev->of_node,
"axis,syscon-pcie");
if (IS_ERR(artpec6_pcie->regmap))
return PTR_ERR(artpec6_pcie->regmap);
platform_set_drvdata(pdev, artpec6_pcie);
ret = artpec6_add_pcie_port(artpec6_pcie, pdev);
if (ret < 0)
return ret;
return 0;
}
