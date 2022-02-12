static void quirk_limit_mrrs(struct pci_dev *dev)
{
struct pci_bus *bus = dev->bus;
struct pci_dev *bridge = bus->self;
static const struct pci_device_id rc_pci_devids[] = {
{ PCI_DEVICE(PCI_VENDOR_ID_TI, PCIE_RC_K2HK),
.class = PCI_CLASS_BRIDGE_PCI << 8, .class_mask = ~0, },
{ PCI_DEVICE(PCI_VENDOR_ID_TI, PCIE_RC_K2E),
.class = PCI_CLASS_BRIDGE_PCI << 8, .class_mask = ~0, },
{ PCI_DEVICE(PCI_VENDOR_ID_TI, PCIE_RC_K2L),
.class = PCI_CLASS_BRIDGE_PCI << 8, .class_mask = ~0, },
{ 0, },
};
if (pci_is_root_bus(bus))
return;
while (!pci_is_root_bus(bus)) {
bridge = bus->self;
bus = bus->parent;
}
if (bridge) {
if (pci_match_id(rc_pci_devids, bridge)) {
if (pcie_get_readrq(dev) > 256) {
dev_info(&dev->dev, "limiting MRRS to 256\n");
pcie_set_readrq(dev, 256);
}
}
}
}
static int ks_pcie_establish_link(struct keystone_pcie *ks_pcie)
{
struct pcie_port *pp = &ks_pcie->pp;
unsigned int retries;
dw_pcie_setup_rc(pp);
if (dw_pcie_link_up(pp)) {
dev_err(pp->dev, "Link already up\n");
return 0;
}
for (retries = 0; retries < 5; retries++) {
ks_dw_pcie_initiate_link_train(ks_pcie);
if (!dw_pcie_wait_for_link(pp))
return 0;
}
dev_err(pp->dev, "phy link never came up\n");
return -ETIMEDOUT;
}
static void ks_pcie_msi_irq_handler(struct irq_desc *desc)
{
unsigned int irq = irq_desc_get_irq(desc);
struct keystone_pcie *ks_pcie = irq_desc_get_handler_data(desc);
u32 offset = irq - ks_pcie->msi_host_irqs[0];
struct pcie_port *pp = &ks_pcie->pp;
struct irq_chip *chip = irq_desc_get_chip(desc);
dev_dbg(pp->dev, "%s, irq %d\n", __func__, irq);
chained_irq_enter(chip, desc);
ks_dw_pcie_handle_msi_irq(ks_pcie, offset);
chained_irq_exit(chip, desc);
}
static void ks_pcie_legacy_irq_handler(struct irq_desc *desc)
{
unsigned int irq = irq_desc_get_irq(desc);
struct keystone_pcie *ks_pcie = irq_desc_get_handler_data(desc);
struct pcie_port *pp = &ks_pcie->pp;
u32 irq_offset = irq - ks_pcie->legacy_host_irqs[0];
struct irq_chip *chip = irq_desc_get_chip(desc);
dev_dbg(pp->dev, ": Handling legacy irq %d\n", irq);
chained_irq_enter(chip, desc);
ks_dw_pcie_handle_legacy_irq(ks_pcie, irq_offset);
chained_irq_exit(chip, desc);
}
static int ks_pcie_get_irq_controller_info(struct keystone_pcie *ks_pcie,
char *controller, int *num_irqs)
{
int temp, max_host_irqs, legacy = 1, *host_irqs;
struct device *dev = ks_pcie->pp.dev;
struct device_node *np_pcie = dev->of_node, **np_temp;
if (!strcmp(controller, "msi-interrupt-controller"))
legacy = 0;
if (legacy) {
np_temp = &ks_pcie->legacy_intc_np;
max_host_irqs = MAX_LEGACY_HOST_IRQS;
host_irqs = &ks_pcie->legacy_host_irqs[0];
} else {
np_temp = &ks_pcie->msi_intc_np;
max_host_irqs = MAX_MSI_HOST_IRQS;
host_irqs = &ks_pcie->msi_host_irqs[0];
}
*np_temp = of_find_node_by_name(np_pcie, controller);
if (!(*np_temp)) {
dev_err(dev, "Node for %s is absent\n", controller);
return -EINVAL;
}
temp = of_irq_count(*np_temp);
if (!temp) {
dev_err(dev, "No IRQ entries in %s\n", controller);
return -EINVAL;
}
if (temp > max_host_irqs)
dev_warn(dev, "Too many %s interrupts defined %u\n",
(legacy ? "legacy" : "MSI"), temp);
for (temp = 0; temp < max_host_irqs; temp++) {
host_irqs[temp] = irq_of_parse_and_map(*np_temp, temp);
if (!host_irqs[temp])
break;
}
if (temp) {
*num_irqs = temp;
return 0;
}
return -EINVAL;
}
static void ks_pcie_setup_interrupts(struct keystone_pcie *ks_pcie)
{
int i;
for (i = 0; i < ks_pcie->num_legacy_host_irqs; i++) {
irq_set_chained_handler_and_data(ks_pcie->legacy_host_irqs[i],
ks_pcie_legacy_irq_handler,
ks_pcie);
}
ks_dw_pcie_enable_legacy_irqs(ks_pcie);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
for (i = 0; i < ks_pcie->num_msi_host_irqs; i++) {
irq_set_chained_handler_and_data(ks_pcie->msi_host_irqs[i],
ks_pcie_msi_irq_handler,
ks_pcie);
}
}
if (ks_pcie->error_irq > 0)
ks_dw_pcie_enable_error_irq(ks_pcie->va_app_base);
}
static int keystone_pcie_fault(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
unsigned long instr = *(unsigned long *) instruction_pointer(regs);
if ((instr & 0x0e100090) == 0x00100090) {
int reg = (instr >> 12) & 15;
regs->uregs[reg] = -1;
regs->ARM_pc += 4;
}
return 0;
}
static void __init ks_pcie_host_init(struct pcie_port *pp)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
u32 val;
ks_pcie_establish_link(ks_pcie);
ks_dw_pcie_setup_rc_app_regs(ks_pcie);
ks_pcie_setup_interrupts(ks_pcie);
writew(PCI_IO_RANGE_TYPE_32 | (PCI_IO_RANGE_TYPE_32 << 8),
pp->dbi_base + PCI_IO_BASE);
writew(ks_pcie->device_id, pp->dbi_base + PCI_DEVICE_ID);
val = readl(pp->dbi_base + PCIE_CAP_BASE + PCI_EXP_DEVCTL);
val &= ~PCI_EXP_DEVCTL_READRQ;
val |= BIT(12);
writel(val, pp->dbi_base + PCIE_CAP_BASE + PCI_EXP_DEVCTL);
hook_fault_code(17, keystone_pcie_fault, SIGBUS, 0,
"Asynchronous external abort");
}
static irqreturn_t pcie_err_irq_handler(int irq, void *priv)
{
struct keystone_pcie *ks_pcie = priv;
return ks_dw_pcie_handle_error_irq(ks_pcie->pp.dev,
ks_pcie->va_app_base);
}
static int __init ks_add_pcie_port(struct keystone_pcie *ks_pcie,
struct platform_device *pdev)
{
struct pcie_port *pp = &ks_pcie->pp;
int ret;
ret = ks_pcie_get_irq_controller_info(ks_pcie,
"legacy-interrupt-controller",
&ks_pcie->num_legacy_host_irqs);
if (ret)
return ret;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
ret = ks_pcie_get_irq_controller_info(ks_pcie,
"msi-interrupt-controller",
&ks_pcie->num_msi_host_irqs);
if (ret)
return ret;
}
ks_pcie->error_irq = irq_of_parse_and_map(ks_pcie->np, 0);
if (ks_pcie->error_irq <= 0)
dev_info(&pdev->dev, "no error IRQ defined\n");
else {
if (request_irq(ks_pcie->error_irq, pcie_err_irq_handler,
IRQF_SHARED, "pcie-error-irq", ks_pcie) < 0) {
dev_err(&pdev->dev, "failed to request error IRQ %d\n",
ks_pcie->error_irq);
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &keystone_pcie_host_ops;
ret = ks_dw_pcie_host_init(ks_pcie, ks_pcie->msi_intc_np);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __exit ks_pcie_remove(struct platform_device *pdev)
{
struct keystone_pcie *ks_pcie = platform_get_drvdata(pdev);
clk_disable_unprepare(ks_pcie->clk);
return 0;
}
static int __init ks_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct keystone_pcie *ks_pcie;
struct pcie_port *pp;
struct resource *res;
void __iomem *reg_p;
struct phy *phy;
int ret;
ks_pcie = devm_kzalloc(&pdev->dev, sizeof(*ks_pcie),
GFP_KERNEL);
if (!ks_pcie)
return -ENOMEM;
pp = &ks_pcie->pp;
phy = devm_phy_get(dev, "pcie-phy");
if (PTR_ERR_OR_ZERO(phy) == -EPROBE_DEFER)
return PTR_ERR(phy);
if (!IS_ERR_OR_NULL(phy)) {
ret = phy_init(phy);
if (ret < 0)
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
reg_p = devm_ioremap_resource(dev, res);
if (IS_ERR(reg_p))
return PTR_ERR(reg_p);
ks_pcie->device_id = readl(reg_p) >> 16;
devm_iounmap(dev, reg_p);
devm_release_mem_region(dev, res->start, resource_size(res));
pp->dev = dev;
ks_pcie->np = dev->of_node;
platform_set_drvdata(pdev, ks_pcie);
ks_pcie->clk = devm_clk_get(dev, "pcie");
if (IS_ERR(ks_pcie->clk)) {
dev_err(dev, "Failed to get pcie rc clock\n");
return PTR_ERR(ks_pcie->clk);
}
ret = clk_prepare_enable(ks_pcie->clk);
if (ret)
return ret;
ret = ks_add_pcie_port(ks_pcie, pdev);
if (ret < 0)
goto fail_clk;
return 0;
fail_clk:
clk_disable_unprepare(ks_pcie->clk);
return ret;
}
