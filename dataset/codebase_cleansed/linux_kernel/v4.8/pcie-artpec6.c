static int artpec6_pcie_establish_link(struct pcie_port *pp)
{
struct artpec6_pcie *artpec6_pcie = to_artpec6_pcie(pp);
u32 val;
unsigned int retries;
regmap_read(artpec6_pcie->regmap, PCIECFG, &val);
val |= PCIECFG_CORE_RESET_REQ;
regmap_write(artpec6_pcie->regmap, PCIECFG, val);
regmap_read(artpec6_pcie->regmap, PCIECFG, &val);
val |= PCIECFG_RISRCREN |
PCIECFG_MODE_TX_DRV_EN |
PCIECFG_CISRREN |
PCIECFG_MACRO_ENABLE;
val |= PCIECFG_REFCLK_ENABLE;
val &= ~PCIECFG_DBG_OEN;
val &= ~PCIECFG_CLKREQ_B;
regmap_write(artpec6_pcie->regmap, PCIECFG, val);
usleep_range(5000, 6000);
regmap_read(artpec6_pcie->regmap, NOCCFG, &val);
val |= NOCCFG_ENABLE_CLK_PCIE;
regmap_write(artpec6_pcie->regmap, NOCCFG, val);
usleep_range(20, 30);
regmap_read(artpec6_pcie->regmap, PCIECFG, &val);
val |= PCIECFG_PCLK_ENABLE | PCIECFG_PLL_ENABLE;
regmap_write(artpec6_pcie->regmap, PCIECFG, val);
usleep_range(6000, 7000);
regmap_read(artpec6_pcie->regmap, NOCCFG, &val);
val &= ~NOCCFG_POWER_PCIE_IDLEREQ;
regmap_write(artpec6_pcie->regmap, NOCCFG, val);
retries = 50;
do {
usleep_range(1000, 2000);
regmap_read(artpec6_pcie->regmap, NOCCFG, &val);
retries--;
} while (retries &&
(val & (NOCCFG_POWER_PCIE_IDLEACK | NOCCFG_POWER_PCIE_IDLE)));
retries = 50;
do {
usleep_range(1000, 2000);
val = readl(artpec6_pcie->phy_base + PHY_STATUS);
retries--;
} while (retries && !(val & PHY_COSPLLLOCK));
regmap_read(artpec6_pcie->regmap, PCIECFG, &val);
val &= ~PCIECFG_CORE_RESET_REQ;
regmap_write(artpec6_pcie->regmap, PCIECFG, val);
usleep_range(100, 200);
writel(DBI_RO_WR_EN, pp->dbi_base + MISC_CONTROL_1_OFF);
pp->io_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->mem_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->cfg0_base &= ARTPEC6_CPU_TO_BUS_ADDR;
pp->cfg1_base &= ARTPEC6_CPU_TO_BUS_ADDR;
dw_pcie_setup_rc(pp);
regmap_read(artpec6_pcie->regmap, PCIECFG, &val);
val |= PCIECFG_LTSSM_ENABLE;
regmap_write(artpec6_pcie->regmap, PCIECFG, val);
if (!dw_pcie_wait_for_link(pp))
return 0;
dev_dbg(pp->dev, "DEBUG_R0: 0x%08x, DEBUG_R1: 0x%08x\n",
readl(pp->dbi_base + PCIE_PHY_DEBUG_R0),
readl(pp->dbi_base + PCIE_PHY_DEBUG_R1));
return -ETIMEDOUT;
}
static void artpec6_pcie_enable_interrupts(struct pcie_port *pp)
{
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
}
static void artpec6_pcie_host_init(struct pcie_port *pp)
{
artpec6_pcie_establish_link(pp);
artpec6_pcie_enable_interrupts(pp);
}
static int artpec6_pcie_link_up(struct pcie_port *pp)
{
u32 rc;
rc = readl(pp->dbi_base + PCIE_PHY_DEBUG_R1) & (0x1 << (36 - 32));
if (rc)
return 1;
return 0;
}
static irqreturn_t artpec6_pcie_msi_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static int __init artpec6_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq_byname(pdev, "msi");
if (pp->msi_irq <= 0) {
dev_err(&pdev->dev, "failed to get MSI irq\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, pp->msi_irq,
artpec6_pcie_msi_handler,
IRQF_SHARED | IRQF_NO_THREAD,
"artpec6-pcie-msi", pp);
if (ret) {
dev_err(&pdev->dev, "failed to request MSI irq\n");
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &artpec6_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int artpec6_pcie_probe(struct platform_device *pdev)
{
struct artpec6_pcie *artpec6_pcie;
struct pcie_port *pp;
struct resource *dbi_base;
struct resource *phy_base;
int ret;
artpec6_pcie = devm_kzalloc(&pdev->dev, sizeof(*artpec6_pcie),
GFP_KERNEL);
if (!artpec6_pcie)
return -ENOMEM;
pp = &artpec6_pcie->pp;
pp->dev = &pdev->dev;
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dbi");
pp->dbi_base = devm_ioremap_resource(&pdev->dev, dbi_base);
if (IS_ERR(pp->dbi_base))
return PTR_ERR(pp->dbi_base);
phy_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy");
artpec6_pcie->phy_base = devm_ioremap_resource(&pdev->dev, phy_base);
if (IS_ERR(artpec6_pcie->phy_base))
return PTR_ERR(artpec6_pcie->phy_base);
artpec6_pcie->regmap =
syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"axis,syscon-pcie");
if (IS_ERR(artpec6_pcie->regmap))
return PTR_ERR(artpec6_pcie->regmap);
ret = artpec6_add_pcie_port(pp, pdev);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, artpec6_pcie);
return 0;
}
