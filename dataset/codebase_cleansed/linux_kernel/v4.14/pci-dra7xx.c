static inline u32 dra7xx_pcie_readl(struct dra7xx_pcie *pcie, u32 offset)
{
return readl(pcie->base + offset);
}
static inline void dra7xx_pcie_writel(struct dra7xx_pcie *pcie, u32 offset,
u32 value)
{
writel(value, pcie->base + offset);
}
static u64 dra7xx_pcie_cpu_addr_fixup(u64 pci_addr)
{
return pci_addr & DRA7XX_CPU_TO_BUS_ADDR;
}
static int dra7xx_pcie_link_up(struct dw_pcie *pci)
{
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
u32 reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_PHY_CS);
return !!(reg & LINK_UP);
}
static void dra7xx_pcie_stop_link(struct dw_pcie *pci)
{
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
u32 reg;
reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD);
reg &= ~LTSSM_EN;
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD, reg);
}
static int dra7xx_pcie_establish_link(struct dw_pcie *pci)
{
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
struct device *dev = pci->dev;
u32 reg;
u32 exp_cap_off = EXP_CAP_ID_OFFSET;
if (dw_pcie_link_up(pci)) {
dev_err(dev, "link is already up\n");
return 0;
}
if (dra7xx->link_gen == 1) {
dw_pcie_read(pci->dbi_base + exp_cap_off + PCI_EXP_LNKCAP,
4, &reg);
if ((reg & PCI_EXP_LNKCAP_SLS) != PCI_EXP_LNKCAP_SLS_2_5GB) {
reg &= ~((u32)PCI_EXP_LNKCAP_SLS);
reg |= PCI_EXP_LNKCAP_SLS_2_5GB;
dw_pcie_write(pci->dbi_base + exp_cap_off +
PCI_EXP_LNKCAP, 4, reg);
}
dw_pcie_read(pci->dbi_base + exp_cap_off + PCI_EXP_LNKCTL2,
2, &reg);
if ((reg & PCI_EXP_LNKCAP_SLS) != PCI_EXP_LNKCAP_SLS_2_5GB) {
reg &= ~((u32)PCI_EXP_LNKCAP_SLS);
reg |= PCI_EXP_LNKCAP_SLS_2_5GB;
dw_pcie_write(pci->dbi_base + exp_cap_off +
PCI_EXP_LNKCTL2, 2, reg);
}
}
reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD);
reg |= LTSSM_EN;
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD, reg);
return 0;
}
static void dra7xx_pcie_enable_msi_interrupts(struct dra7xx_pcie *dra7xx)
{
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MSI,
LEG_EP_INTERRUPTS | MSI);
dra7xx_pcie_writel(dra7xx,
PCIECTRL_DRA7XX_CONF_IRQENABLE_SET_MSI,
MSI | LEG_EP_INTERRUPTS);
}
static void dra7xx_pcie_enable_wrapper_interrupts(struct dra7xx_pcie *dra7xx)
{
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MAIN,
INTERRUPTS);
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_IRQENABLE_SET_MAIN,
INTERRUPTS);
}
static void dra7xx_pcie_enable_interrupts(struct dra7xx_pcie *dra7xx)
{
dra7xx_pcie_enable_wrapper_interrupts(dra7xx);
dra7xx_pcie_enable_msi_interrupts(dra7xx);
}
static int dra7xx_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
dw_pcie_setup_rc(pp);
dra7xx_pcie_establish_link(pci);
dw_pcie_wait_for_link(pci);
dw_pcie_msi_init(pp);
dra7xx_pcie_enable_interrupts(dra7xx);
return 0;
}
static int dra7xx_pcie_intx_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int dra7xx_pcie_init_irq_domain(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct device *dev = pci->dev;
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
struct device_node *node = dev->of_node;
struct device_node *pcie_intc_node = of_get_next_child(node, NULL);
if (!pcie_intc_node) {
dev_err(dev, "No PCIe Intc node found\n");
return -ENODEV;
}
dra7xx->irq_domain = irq_domain_add_linear(pcie_intc_node, PCI_NUM_INTX,
&intx_domain_ops, pp);
if (!dra7xx->irq_domain) {
dev_err(dev, "Failed to get a INTx IRQ domain\n");
return -ENODEV;
}
return 0;
}
static irqreturn_t dra7xx_pcie_msi_irq_handler(int irq, void *arg)
{
struct dra7xx_pcie *dra7xx = arg;
struct dw_pcie *pci = dra7xx->pci;
struct pcie_port *pp = &pci->pp;
u32 reg;
reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MSI);
switch (reg) {
case MSI:
dw_handle_msi_irq(pp);
break;
case INTA:
case INTB:
case INTC:
case INTD:
generic_handle_irq(irq_find_mapping(dra7xx->irq_domain,
ffs(reg)));
break;
}
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MSI, reg);
return IRQ_HANDLED;
}
static irqreturn_t dra7xx_pcie_irq_handler(int irq, void *arg)
{
struct dra7xx_pcie *dra7xx = arg;
struct dw_pcie *pci = dra7xx->pci;
struct device *dev = pci->dev;
struct dw_pcie_ep *ep = &pci->ep;
u32 reg;
reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MAIN);
if (reg & ERR_SYS)
dev_dbg(dev, "System Error\n");
if (reg & ERR_FATAL)
dev_dbg(dev, "Fatal Error\n");
if (reg & ERR_NONFATAL)
dev_dbg(dev, "Non Fatal Error\n");
if (reg & ERR_COR)
dev_dbg(dev, "Correctable Error\n");
if (reg & ERR_AXI)
dev_dbg(dev, "AXI tag lookup fatal Error\n");
if (reg & ERR_ECRC)
dev_dbg(dev, "ECRC Error\n");
if (reg & PME_TURN_OFF)
dev_dbg(dev,
"Power Management Event Turn-Off message received\n");
if (reg & PME_TO_ACK)
dev_dbg(dev,
"Power Management Turn-Off Ack message received\n");
if (reg & PM_PME)
dev_dbg(dev, "PM Power Management Event message received\n");
if (reg & LINK_REQ_RST)
dev_dbg(dev, "Link Request Reset\n");
if (reg & LINK_UP_EVT) {
if (dra7xx->mode == DW_PCIE_EP_TYPE)
dw_pcie_ep_linkup(ep);
dev_dbg(dev, "Link-up state change\n");
}
if (reg & CFG_BME_EVT)
dev_dbg(dev, "CFG 'Bus Master Enable' change\n");
if (reg & CFG_MSE_EVT)
dev_dbg(dev, "CFG 'Memory Space Enable' change\n");
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_IRQSTATUS_MAIN, reg);
return IRQ_HANDLED;
}
static void dw_pcie_ep_reset_bar(struct dw_pcie *pci, enum pci_barno bar)
{
u32 reg;
reg = PCI_BASE_ADDRESS_0 + (4 * bar);
dw_pcie_writel_dbi2(pci, reg, 0x0);
dw_pcie_writel_dbi(pci, reg, 0x0);
}
static void dra7xx_pcie_ep_init(struct dw_pcie_ep *ep)
{
struct dw_pcie *pci = to_dw_pcie_from_ep(ep);
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
enum pci_barno bar;
for (bar = BAR_0; bar <= BAR_5; bar++)
dw_pcie_ep_reset_bar(pci, bar);
dra7xx_pcie_enable_wrapper_interrupts(dra7xx);
}
static void dra7xx_pcie_raise_legacy_irq(struct dra7xx_pcie *dra7xx)
{
dra7xx_pcie_writel(dra7xx, PCIECTRL_TI_CONF_INTX_ASSERT, 0x1);
mdelay(1);
dra7xx_pcie_writel(dra7xx, PCIECTRL_TI_CONF_INTX_DEASSERT, 0x1);
}
static void dra7xx_pcie_raise_msi_irq(struct dra7xx_pcie *dra7xx,
u8 interrupt_num)
{
u32 reg;
reg = (interrupt_num - 1) << MSI_VECTOR_SHIFT;
reg |= MSI_REQ_GRANT;
dra7xx_pcie_writel(dra7xx, PCIECTRL_TI_CONF_MSI_XMT, reg);
}
static int dra7xx_pcie_raise_irq(struct dw_pcie_ep *ep,
enum pci_epc_irq_type type, u8 interrupt_num)
{
struct dw_pcie *pci = to_dw_pcie_from_ep(ep);
struct dra7xx_pcie *dra7xx = to_dra7xx_pcie(pci);
switch (type) {
case PCI_EPC_IRQ_LEGACY:
dra7xx_pcie_raise_legacy_irq(dra7xx);
break;
case PCI_EPC_IRQ_MSI:
dra7xx_pcie_raise_msi_irq(dra7xx, interrupt_num);
break;
default:
dev_err(pci->dev, "UNKNOWN IRQ type\n");
}
return 0;
}
static int __init dra7xx_add_pcie_ep(struct dra7xx_pcie *dra7xx,
struct platform_device *pdev)
{
int ret;
struct dw_pcie_ep *ep;
struct resource *res;
struct device *dev = &pdev->dev;
struct dw_pcie *pci = dra7xx->pci;
ep = &pci->ep;
ep->ops = &pcie_ep_ops;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ep_dbics");
pci->dbi_base = devm_ioremap(dev, res->start, resource_size(res));
if (!pci->dbi_base)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ep_dbics2");
pci->dbi_base2 = devm_ioremap(dev, res->start, resource_size(res));
if (!pci->dbi_base2)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "addr_space");
if (!res)
return -EINVAL;
ep->phys_base = res->start;
ep->addr_size = resource_size(res);
ret = dw_pcie_ep_init(ep);
if (ret) {
dev_err(dev, "failed to initialize endpoint\n");
return ret;
}
return 0;
}
static int __init dra7xx_add_pcie_port(struct dra7xx_pcie *dra7xx,
struct platform_device *pdev)
{
int ret;
struct dw_pcie *pci = dra7xx->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = pci->dev;
struct resource *res;
pp->irq = platform_get_irq(pdev, 1);
if (pp->irq < 0) {
dev_err(dev, "missing IRQ resource\n");
return pp->irq;
}
ret = devm_request_irq(dev, pp->irq, dra7xx_pcie_msi_irq_handler,
IRQF_SHARED | IRQF_NO_THREAD,
"dra7-pcie-msi", dra7xx);
if (ret) {
dev_err(dev, "failed to request irq\n");
return ret;
}
ret = dra7xx_pcie_init_irq_domain(pp);
if (ret < 0)
return ret;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rc_dbics");
pci->dbi_base = devm_ioremap(dev, res->start, resource_size(res));
if (!pci->dbi_base)
return -ENOMEM;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static void dra7xx_pcie_disable_phy(struct dra7xx_pcie *dra7xx)
{
int phy_count = dra7xx->phy_count;
while (phy_count--) {
phy_power_off(dra7xx->phy[phy_count]);
phy_exit(dra7xx->phy[phy_count]);
}
}
static int dra7xx_pcie_enable_phy(struct dra7xx_pcie *dra7xx)
{
int phy_count = dra7xx->phy_count;
int ret;
int i;
for (i = 0; i < phy_count; i++) {
ret = phy_init(dra7xx->phy[i]);
if (ret < 0)
goto err_phy;
ret = phy_power_on(dra7xx->phy[i]);
if (ret < 0) {
phy_exit(dra7xx->phy[i]);
goto err_phy;
}
}
return 0;
err_phy:
while (--i >= 0) {
phy_power_off(dra7xx->phy[i]);
phy_exit(dra7xx->phy[i]);
}
return ret;
}
static int dra7xx_pcie_ep_unaligned_memaccess(struct device *dev)
{
int ret;
struct device_node *np = dev->of_node;
struct of_phandle_args args;
struct regmap *regmap;
regmap = syscon_regmap_lookup_by_phandle(np,
"ti,syscon-unaligned-access");
if (IS_ERR(regmap)) {
dev_dbg(dev, "can't get ti,syscon-unaligned-access\n");
return -EINVAL;
}
ret = of_parse_phandle_with_fixed_args(np, "ti,syscon-unaligned-access",
2, 0, &args);
if (ret) {
dev_err(dev, "failed to parse ti,syscon-unaligned-access\n");
return ret;
}
ret = regmap_update_bits(regmap, args.args[0], args.args[1],
args.args[1]);
if (ret)
dev_err(dev, "failed to enable unaligned access\n");
of_node_put(args.np);
return ret;
}
static int __init dra7xx_pcie_probe(struct platform_device *pdev)
{
u32 reg;
int ret;
int irq;
int i;
int phy_count;
struct phy **phy;
void __iomem *base;
struct resource *res;
struct dw_pcie *pci;
struct pcie_port *pp;
struct dra7xx_pcie *dra7xx;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
char name[10];
struct gpio_desc *reset;
const struct of_device_id *match;
const struct dra7xx_pcie_of_data *data;
enum dw_pcie_device_mode mode;
match = of_match_device(of_match_ptr(of_dra7xx_pcie_match), dev);
if (!match)
return -EINVAL;
data = (struct dra7xx_pcie_of_data *)match->data;
mode = (enum dw_pcie_device_mode)data->mode;
dra7xx = devm_kzalloc(dev, sizeof(*dra7xx), GFP_KERNEL);
if (!dra7xx)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
pp = &pci->pp;
pp->ops = &dra7xx_pcie_host_ops;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "missing IRQ resource: %d\n", irq);
return irq;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ti_conf");
base = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!base)
return -ENOMEM;
phy_count = of_property_count_strings(np, "phy-names");
if (phy_count < 0) {
dev_err(dev, "unable to find the strings\n");
return phy_count;
}
phy = devm_kzalloc(dev, sizeof(*phy) * phy_count, GFP_KERNEL);
if (!phy)
return -ENOMEM;
for (i = 0; i < phy_count; i++) {
snprintf(name, sizeof(name), "pcie-phy%d", i);
phy[i] = devm_phy_get(dev, name);
if (IS_ERR(phy[i]))
return PTR_ERR(phy[i]);
}
dra7xx->base = base;
dra7xx->phy = phy;
dra7xx->pci = pci;
dra7xx->phy_count = phy_count;
ret = dra7xx_pcie_enable_phy(dra7xx);
if (ret) {
dev_err(dev, "failed to enable phy\n");
return ret;
}
platform_set_drvdata(pdev, dra7xx);
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "pm_runtime_get_sync failed\n");
goto err_get_sync;
}
reset = devm_gpiod_get_optional(dev, NULL, GPIOD_OUT_HIGH);
if (IS_ERR(reset)) {
ret = PTR_ERR(reset);
dev_err(&pdev->dev, "gpio request failed, ret %d\n", ret);
goto err_gpio;
}
reg = dra7xx_pcie_readl(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD);
reg &= ~LTSSM_EN;
dra7xx_pcie_writel(dra7xx, PCIECTRL_DRA7XX_CONF_DEVICE_CMD, reg);
dra7xx->link_gen = of_pci_get_max_link_speed(np);
if (dra7xx->link_gen < 0 || dra7xx->link_gen > 2)
dra7xx->link_gen = 2;
switch (mode) {
case DW_PCIE_RC_TYPE:
dra7xx_pcie_writel(dra7xx, PCIECTRL_TI_CONF_DEVICE_TYPE,
DEVICE_TYPE_RC);
ret = dra7xx_add_pcie_port(dra7xx, pdev);
if (ret < 0)
goto err_gpio;
break;
case DW_PCIE_EP_TYPE:
dra7xx_pcie_writel(dra7xx, PCIECTRL_TI_CONF_DEVICE_TYPE,
DEVICE_TYPE_EP);
ret = dra7xx_pcie_ep_unaligned_memaccess(dev);
if (ret)
goto err_gpio;
ret = dra7xx_add_pcie_ep(dra7xx, pdev);
if (ret < 0)
goto err_gpio;
break;
default:
dev_err(dev, "INVALID device type %d\n", mode);
}
dra7xx->mode = mode;
ret = devm_request_irq(dev, irq, dra7xx_pcie_irq_handler,
IRQF_SHARED, "dra7xx-pcie-main", dra7xx);
if (ret) {
dev_err(dev, "failed to request irq\n");
goto err_gpio;
}
return 0;
err_gpio:
pm_runtime_put(dev);
err_get_sync:
pm_runtime_disable(dev);
dra7xx_pcie_disable_phy(dra7xx);
return ret;
}
static int dra7xx_pcie_suspend(struct device *dev)
{
struct dra7xx_pcie *dra7xx = dev_get_drvdata(dev);
struct dw_pcie *pci = dra7xx->pci;
u32 val;
if (dra7xx->mode != DW_PCIE_RC_TYPE)
return 0;
val = dw_pcie_readl_dbi(pci, PCI_COMMAND);
val &= ~PCI_COMMAND_MEMORY;
dw_pcie_writel_dbi(pci, PCI_COMMAND, val);
return 0;
}
static int dra7xx_pcie_resume(struct device *dev)
{
struct dra7xx_pcie *dra7xx = dev_get_drvdata(dev);
struct dw_pcie *pci = dra7xx->pci;
u32 val;
if (dra7xx->mode != DW_PCIE_RC_TYPE)
return 0;
val = dw_pcie_readl_dbi(pci, PCI_COMMAND);
val |= PCI_COMMAND_MEMORY;
dw_pcie_writel_dbi(pci, PCI_COMMAND, val);
return 0;
}
static int dra7xx_pcie_suspend_noirq(struct device *dev)
{
struct dra7xx_pcie *dra7xx = dev_get_drvdata(dev);
dra7xx_pcie_disable_phy(dra7xx);
return 0;
}
static int dra7xx_pcie_resume_noirq(struct device *dev)
{
struct dra7xx_pcie *dra7xx = dev_get_drvdata(dev);
int ret;
ret = dra7xx_pcie_enable_phy(dra7xx);
if (ret) {
dev_err(dev, "failed to enable phy\n");
return ret;
}
return 0;
}
