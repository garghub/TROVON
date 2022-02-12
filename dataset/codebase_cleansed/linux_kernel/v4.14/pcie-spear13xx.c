static int spear13xx_pcie_establish_link(struct spear13xx_pcie *spear13xx_pcie)
{
struct dw_pcie *pci = spear13xx_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct pcie_app_reg *app_reg = spear13xx_pcie->app_base;
u32 val;
u32 exp_cap_off = EXP_CAP_ID_OFFSET;
if (dw_pcie_link_up(pci)) {
dev_err(pci->dev, "link already up\n");
return 0;
}
dw_pcie_setup_rc(pp);
dw_pcie_read(pci->dbi_base + exp_cap_off + PCI_EXP_DEVCTL, 2, &val);
val &= ~PCI_EXP_DEVCTL_READRQ;
dw_pcie_write(pci->dbi_base + exp_cap_off + PCI_EXP_DEVCTL, 2, val);
dw_pcie_write(pci->dbi_base + PCI_VENDOR_ID, 2, 0x104A);
dw_pcie_write(pci->dbi_base + PCI_DEVICE_ID, 2, 0xCD80);
if (spear13xx_pcie->is_gen1) {
dw_pcie_read(pci->dbi_base + exp_cap_off + PCI_EXP_LNKCAP,
4, &val);
if ((val & PCI_EXP_LNKCAP_SLS) != PCI_EXP_LNKCAP_SLS_2_5GB) {
val &= ~((u32)PCI_EXP_LNKCAP_SLS);
val |= PCI_EXP_LNKCAP_SLS_2_5GB;
dw_pcie_write(pci->dbi_base + exp_cap_off +
PCI_EXP_LNKCAP, 4, val);
}
dw_pcie_read(pci->dbi_base + exp_cap_off + PCI_EXP_LNKCTL2,
2, &val);
if ((val & PCI_EXP_LNKCAP_SLS) != PCI_EXP_LNKCAP_SLS_2_5GB) {
val &= ~((u32)PCI_EXP_LNKCAP_SLS);
val |= PCI_EXP_LNKCAP_SLS_2_5GB;
dw_pcie_write(pci->dbi_base + exp_cap_off +
PCI_EXP_LNKCTL2, 2, val);
}
}
writel(DEVICE_TYPE_RC | (1 << MISCTRL_EN_ID)
| (1 << APP_LTSSM_ENABLE_ID)
| ((u32)1 << REG_TRANSLATION_ENABLE),
&app_reg->app_ctrl_0);
return dw_pcie_wait_for_link(pci);
}
static irqreturn_t spear13xx_pcie_irq_handler(int irq, void *arg)
{
struct spear13xx_pcie *spear13xx_pcie = arg;
struct pcie_app_reg *app_reg = spear13xx_pcie->app_base;
struct dw_pcie *pci = spear13xx_pcie->pci;
struct pcie_port *pp = &pci->pp;
unsigned int status;
status = readl(&app_reg->int_sts);
if (status & MSI_CTRL_INT) {
BUG_ON(!IS_ENABLED(CONFIG_PCI_MSI));
dw_handle_msi_irq(pp);
}
writel(status, &app_reg->int_clr);
return IRQ_HANDLED;
}
static void spear13xx_pcie_enable_interrupts(struct spear13xx_pcie *spear13xx_pcie)
{
struct dw_pcie *pci = spear13xx_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct pcie_app_reg *app_reg = spear13xx_pcie->app_base;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
dw_pcie_msi_init(pp);
writel(readl(&app_reg->int_mask) |
MSI_CTRL_INT, &app_reg->int_mask);
}
}
static int spear13xx_pcie_link_up(struct dw_pcie *pci)
{
struct spear13xx_pcie *spear13xx_pcie = to_spear13xx_pcie(pci);
struct pcie_app_reg *app_reg = spear13xx_pcie->app_base;
if (readl(&app_reg->app_status_1) & XMLH_LINK_UP)
return 1;
return 0;
}
static int spear13xx_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct spear13xx_pcie *spear13xx_pcie = to_spear13xx_pcie(pci);
spear13xx_pcie_establish_link(spear13xx_pcie);
spear13xx_pcie_enable_interrupts(spear13xx_pcie);
return 0;
}
static int spear13xx_add_pcie_port(struct spear13xx_pcie *spear13xx_pcie,
struct platform_device *pdev)
{
struct dw_pcie *pci = spear13xx_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = &pdev->dev;
int ret;
pp->irq = platform_get_irq(pdev, 0);
if (pp->irq < 0) {
dev_err(dev, "failed to get irq\n");
return pp->irq;
}
ret = devm_request_irq(dev, pp->irq, spear13xx_pcie_irq_handler,
IRQF_SHARED | IRQF_NO_THREAD,
"spear1340-pcie", spear13xx_pcie);
if (ret) {
dev_err(dev, "failed to request irq %d\n", pp->irq);
return ret;
}
pp->root_bus_nr = -1;
pp->ops = &spear13xx_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int spear13xx_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_pcie *pci;
struct spear13xx_pcie *spear13xx_pcie;
struct device_node *np = dev->of_node;
struct resource *dbi_base;
int ret;
spear13xx_pcie = devm_kzalloc(dev, sizeof(*spear13xx_pcie), GFP_KERNEL);
if (!spear13xx_pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
spear13xx_pcie->pci = pci;
spear13xx_pcie->phy = devm_phy_get(dev, "pcie-phy");
if (IS_ERR(spear13xx_pcie->phy)) {
ret = PTR_ERR(spear13xx_pcie->phy);
if (ret == -EPROBE_DEFER)
dev_info(dev, "probe deferred\n");
else
dev_err(dev, "couldn't get pcie-phy\n");
return ret;
}
phy_init(spear13xx_pcie->phy);
spear13xx_pcie->clk = devm_clk_get(dev, NULL);
if (IS_ERR(spear13xx_pcie->clk)) {
dev_err(dev, "couldn't get clk for pcie\n");
return PTR_ERR(spear13xx_pcie->clk);
}
ret = clk_prepare_enable(spear13xx_pcie->clk);
if (ret) {
dev_err(dev, "couldn't enable clk for pcie\n");
return ret;
}
dbi_base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dbi");
pci->dbi_base = devm_pci_remap_cfg_resource(dev, dbi_base);
if (IS_ERR(pci->dbi_base)) {
dev_err(dev, "couldn't remap dbi base %p\n", dbi_base);
ret = PTR_ERR(pci->dbi_base);
goto fail_clk;
}
spear13xx_pcie->app_base = pci->dbi_base + 0x2000;
if (of_property_read_bool(np, "st,pcie-is-gen1"))
spear13xx_pcie->is_gen1 = true;
platform_set_drvdata(pdev, spear13xx_pcie);
ret = spear13xx_add_pcie_port(spear13xx_pcie, pdev);
if (ret < 0)
goto fail_clk;
return 0;
fail_clk:
clk_disable_unprepare(spear13xx_pcie->clk);
return ret;
}
