static irqreturn_t dw_plat_pcie_msi_irq_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static void dw_plat_pcie_host_init(struct pcie_port *pp)
{
dw_pcie_setup_rc(pp);
dw_pcie_wait_for_link(pp);
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
}
static int dw_plat_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
pp->irq = platform_get_irq(pdev, 1);
if (pp->irq < 0)
return pp->irq;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq(pdev, 0);
if (pp->msi_irq < 0)
return pp->msi_irq;
ret = devm_request_irq(&pdev->dev, pp->msi_irq,
dw_plat_pcie_msi_irq_handler,
IRQF_SHARED, "dw-plat-pcie-msi", pp);
if (ret) {
dev_err(&pdev->dev, "failed to request MSI IRQ\n");
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &dw_plat_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int dw_plat_pcie_probe(struct platform_device *pdev)
{
struct dw_plat_pcie *dw_plat_pcie;
struct pcie_port *pp;
struct resource *res;
int ret;
dw_plat_pcie = devm_kzalloc(&pdev->dev, sizeof(*dw_plat_pcie),
GFP_KERNEL);
if (!dw_plat_pcie)
return -ENOMEM;
pp = &dw_plat_pcie->pp;
pp->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
dw_plat_pcie->mem_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dw_plat_pcie->mem_base))
return PTR_ERR(dw_plat_pcie->mem_base);
pp->dbi_base = dw_plat_pcie->mem_base;
ret = dw_plat_add_pcie_port(pp, pdev);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, dw_plat_pcie);
return 0;
}
