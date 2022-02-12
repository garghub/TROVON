static int armada8k_pcie_link_up(struct pcie_port *pp)
{
u32 reg;
u32 mask = PCIE_GLB_STS_RDLH_LINK_UP | PCIE_GLB_STS_PHY_LINK_UP;
reg = dw_pcie_readl_rc(pp, PCIE_GLOBAL_STATUS_REG);
if ((reg & mask) == mask)
return 1;
dev_dbg(pp->dev, "No link detected (Global-Status: 0x%08x).\n", reg);
return 0;
}
static void armada8k_pcie_establish_link(struct armada8k_pcie *pcie)
{
struct pcie_port *pp = &pcie->pp;
u32 reg;
if (!dw_pcie_link_up(pp)) {
reg = dw_pcie_readl_rc(pp, PCIE_GLOBAL_CONTROL_REG);
reg &= ~(PCIE_APP_LTSSM_EN);
dw_pcie_writel_rc(pp, PCIE_GLOBAL_CONTROL_REG, reg);
}
reg = dw_pcie_readl_rc(pp, PCIE_GLOBAL_CONTROL_REG);
reg &= ~(PCIE_DEVICE_TYPE_MASK << PCIE_DEVICE_TYPE_SHIFT);
reg |= PCIE_DEVICE_TYPE_RC << PCIE_DEVICE_TYPE_SHIFT;
dw_pcie_writel_rc(pp, PCIE_GLOBAL_CONTROL_REG, reg);
dw_pcie_writel_rc(pp, PCIE_ARCACHE_TRC_REG, ARCACHE_DEFAULT_VALUE);
dw_pcie_writel_rc(pp, PCIE_AWCACHE_TRC_REG, AWCACHE_DEFAULT_VALUE);
reg = dw_pcie_readl_rc(pp, PCIE_ARUSER_REG);
reg &= ~(AX_USER_DOMAIN_MASK << AX_USER_DOMAIN_SHIFT);
reg |= DOMAIN_OUTER_SHAREABLE << AX_USER_DOMAIN_SHIFT;
dw_pcie_writel_rc(pp, PCIE_ARUSER_REG, reg);
reg = dw_pcie_readl_rc(pp, PCIE_AWUSER_REG);
reg &= ~(AX_USER_DOMAIN_MASK << AX_USER_DOMAIN_SHIFT);
reg |= DOMAIN_OUTER_SHAREABLE << AX_USER_DOMAIN_SHIFT;
dw_pcie_writel_rc(pp, PCIE_AWUSER_REG, reg);
reg = dw_pcie_readl_rc(pp, PCIE_GLOBAL_INT_MASK1_REG);
reg |= PCIE_INT_A_ASSERT_MASK | PCIE_INT_B_ASSERT_MASK |
PCIE_INT_C_ASSERT_MASK | PCIE_INT_D_ASSERT_MASK;
dw_pcie_writel_rc(pp, PCIE_GLOBAL_INT_MASK1_REG, reg);
if (!dw_pcie_link_up(pp)) {
reg = dw_pcie_readl_rc(pp, PCIE_GLOBAL_CONTROL_REG);
reg |= PCIE_APP_LTSSM_EN;
dw_pcie_writel_rc(pp, PCIE_GLOBAL_CONTROL_REG, reg);
}
if (dw_pcie_wait_for_link(pp))
dev_err(pp->dev, "Link not up after reconfiguration\n");
}
static void armada8k_pcie_host_init(struct pcie_port *pp)
{
struct armada8k_pcie *pcie = to_armada8k_pcie(pp);
dw_pcie_setup_rc(pp);
armada8k_pcie_establish_link(pcie);
}
static irqreturn_t armada8k_pcie_irq_handler(int irq, void *arg)
{
struct armada8k_pcie *pcie = arg;
struct pcie_port *pp = &pcie->pp;
u32 val;
val = dw_pcie_readl_rc(pp, PCIE_GLOBAL_INT_CAUSE1_REG);
dw_pcie_writel_rc(pp, PCIE_GLOBAL_INT_CAUSE1_REG, val);
return IRQ_HANDLED;
}
static int armada8k_add_pcie_port(struct armada8k_pcie *pcie,
struct platform_device *pdev)
{
struct pcie_port *pp = &pcie->pp;
struct device *dev = &pdev->dev;
int ret;
pp->root_bus_nr = -1;
pp->ops = &armada8k_pcie_host_ops;
pp->irq = platform_get_irq(pdev, 0);
if (!pp->irq) {
dev_err(dev, "failed to get irq for port\n");
return -ENODEV;
}
ret = devm_request_irq(dev, pp->irq, armada8k_pcie_irq_handler,
IRQF_SHARED, "armada8k-pcie", pcie);
if (ret) {
dev_err(dev, "failed to request irq %d\n", pp->irq);
return ret;
}
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host: %d\n", ret);
return ret;
}
return 0;
}
static int armada8k_pcie_probe(struct platform_device *pdev)
{
struct armada8k_pcie *pcie;
struct pcie_port *pp;
struct device *dev = &pdev->dev;
struct resource *base;
int ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->clk = devm_clk_get(dev, NULL);
if (IS_ERR(pcie->clk))
return PTR_ERR(pcie->clk);
clk_prepare_enable(pcie->clk);
pp = &pcie->pp;
pp->dev = dev;
base = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ctrl");
pp->dbi_base = devm_ioremap_resource(dev, base);
if (IS_ERR(pp->dbi_base)) {
dev_err(dev, "couldn't remap regs base %p\n", base);
ret = PTR_ERR(pp->dbi_base);
goto fail;
}
ret = armada8k_add_pcie_port(pcie, pdev);
if (ret)
goto fail;
return 0;
fail:
if (!IS_ERR(pcie->clk))
clk_disable_unprepare(pcie->clk);
return ret;
}
