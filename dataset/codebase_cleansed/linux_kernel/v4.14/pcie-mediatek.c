static void mtk_pcie_subsys_powerdown(struct mtk_pcie *pcie)
{
struct device *dev = pcie->dev;
clk_disable_unprepare(pcie->free_ck);
if (dev->pm_domain) {
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
}
}
static void mtk_pcie_port_free(struct mtk_pcie_port *port)
{
struct mtk_pcie *pcie = port->pcie;
struct device *dev = pcie->dev;
devm_iounmap(dev, port->base);
list_del(&port->list);
devm_kfree(dev, port);
}
static void mtk_pcie_put_resources(struct mtk_pcie *pcie)
{
struct mtk_pcie_port *port, *tmp;
list_for_each_entry_safe(port, tmp, &pcie->ports, list) {
phy_power_off(port->phy);
phy_exit(port->phy);
clk_disable_unprepare(port->pipe_ck);
clk_disable_unprepare(port->obff_ck);
clk_disable_unprepare(port->axi_ck);
clk_disable_unprepare(port->aux_ck);
clk_disable_unprepare(port->ahb_ck);
clk_disable_unprepare(port->sys_ck);
mtk_pcie_port_free(port);
}
mtk_pcie_subsys_powerdown(pcie);
}
static int mtk_pcie_check_cfg_cpld(struct mtk_pcie_port *port)
{
u32 val;
int err;
err = readl_poll_timeout_atomic(port->base + PCIE_APP_TLP_REQ, val,
!(val & APP_CFG_REQ), 10,
100 * USEC_PER_MSEC);
if (err)
return PCIBIOS_SET_FAILED;
if (readl(port->base + PCIE_APP_TLP_REQ) & APP_CPL_STATUS)
return PCIBIOS_SET_FAILED;
return PCIBIOS_SUCCESSFUL;
}
static int mtk_pcie_hw_rd_cfg(struct mtk_pcie_port *port, u32 bus, u32 devfn,
int where, int size, u32 *val)
{
u32 tmp;
writel(CFG_HEADER_DW0(CFG_WRRD_TYPE_0, CFG_RD_FMT),
port->base + PCIE_CFG_HEADER0);
writel(CFG_HEADER_DW1(where, size), port->base + PCIE_CFG_HEADER1);
writel(CFG_HEADER_DW2(where, PCI_FUNC(devfn), PCI_SLOT(devfn), bus),
port->base + PCIE_CFG_HEADER2);
tmp = readl(port->base + PCIE_APP_TLP_REQ);
tmp |= APP_CFG_REQ;
writel(tmp, port->base + PCIE_APP_TLP_REQ);
if (mtk_pcie_check_cfg_cpld(port))
return PCIBIOS_SET_FAILED;
*val = readl(port->base + PCIE_CFG_RDATA);
if (size == 1)
*val = (*val >> (8 * (where & 3))) & 0xff;
else if (size == 2)
*val = (*val >> (8 * (where & 3))) & 0xffff;
return PCIBIOS_SUCCESSFUL;
}
static int mtk_pcie_hw_wr_cfg(struct mtk_pcie_port *port, u32 bus, u32 devfn,
int where, int size, u32 val)
{
writel(CFG_HEADER_DW0(CFG_WRRD_TYPE_0, CFG_WR_FMT),
port->base + PCIE_CFG_HEADER0);
writel(CFG_HEADER_DW1(where, size), port->base + PCIE_CFG_HEADER1);
writel(CFG_HEADER_DW2(where, PCI_FUNC(devfn), PCI_SLOT(devfn), bus),
port->base + PCIE_CFG_HEADER2);
val = val << 8 * (where & 3);
writel(val, port->base + PCIE_CFG_WDATA);
val = readl(port->base + PCIE_APP_TLP_REQ);
val |= APP_CFG_REQ;
writel(val, port->base + PCIE_APP_TLP_REQ);
return mtk_pcie_check_cfg_cpld(port);
}
static struct mtk_pcie_port *mtk_pcie_find_port(struct pci_bus *bus,
unsigned int devfn)
{
struct mtk_pcie *pcie = bus->sysdata;
struct mtk_pcie_port *port;
list_for_each_entry(port, &pcie->ports, list)
if (port->slot == PCI_SLOT(devfn))
return port;
return NULL;
}
static int mtk_pcie_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct mtk_pcie_port *port;
u32 bn = bus->number;
int ret;
port = mtk_pcie_find_port(bus, devfn);
if (!port) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
ret = mtk_pcie_hw_rd_cfg(port, bn, devfn, where, size, val);
if (ret)
*val = ~0;
return ret;
}
static int mtk_pcie_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct mtk_pcie_port *port;
u32 bn = bus->number;
port = mtk_pcie_find_port(bus, devfn);
if (!port)
return PCIBIOS_DEVICE_NOT_FOUND;
return mtk_pcie_hw_wr_cfg(port, bn, devfn, where, size, val);
}
static int mtk_pcie_startup_port_v2(struct mtk_pcie_port *port)
{
struct mtk_pcie *pcie = port->pcie;
struct resource *mem = &pcie->mem;
u32 val;
size_t size;
int err;
if (pcie->base) {
val = readl(pcie->base + PCIE_SYS_CFG_V2);
val |= PCIE_CSR_LTSSM_EN(port->slot) |
PCIE_CSR_ASPM_L1_EN(port->slot);
writel(val, pcie->base + PCIE_SYS_CFG_V2);
}
writel(0, port->base + PCIE_RST_CTRL);
writel(PCIE_LINKDOWN_RST_EN, port->base + PCIE_RST_CTRL);
val = readl(port->base + PCIE_RST_CTRL);
val |= PCIE_PHY_RSTB | PCIE_PERSTB | PCIE_PIPE_SRSTB |
PCIE_MAC_SRSTB | PCIE_CRSTB;
writel(val, port->base + PCIE_RST_CTRL);
err = readl_poll_timeout(port->base + PCIE_LINK_STATUS_V2, val,
!!(val & PCIE_PORT_LINKUP_V2), 20,
100 * USEC_PER_MSEC);
if (err)
return -ETIMEDOUT;
val = readl(port->base + PCIE_INT_MASK);
val &= ~INTX_MASK;
writel(val, port->base + PCIE_INT_MASK);
size = mem->end - mem->start;
val = lower_32_bits(mem->start) | AHB2PCIE_SIZE(fls(size));
writel(val, port->base + PCIE_AHB_TRANS_BASE0_L);
val = upper_32_bits(mem->start);
writel(val, port->base + PCIE_AHB_TRANS_BASE0_H);
val = fls(0xffffffff) | WIN_ENABLE;
writel(val, port->base + PCIE_AXI_WINDOW0);
return 0;
}
static int mtk_pcie_msi_alloc(struct mtk_pcie_port *port)
{
int msi;
msi = find_first_zero_bit(port->msi_irq_in_use, MTK_MSI_IRQS_NUM);
if (msi < MTK_MSI_IRQS_NUM)
set_bit(msi, port->msi_irq_in_use);
else
return -ENOSPC;
return msi;
}
static void mtk_pcie_msi_free(struct mtk_pcie_port *port, unsigned long hwirq)
{
clear_bit(hwirq, port->msi_irq_in_use);
}
static int mtk_pcie_msi_setup_irq(struct msi_controller *chip,
struct pci_dev *pdev, struct msi_desc *desc)
{
struct mtk_pcie_port *port;
struct msi_msg msg;
unsigned int irq;
int hwirq;
phys_addr_t msg_addr;
port = mtk_pcie_find_port(pdev->bus, pdev->devfn);
if (!port)
return -EINVAL;
hwirq = mtk_pcie_msi_alloc(port);
if (hwirq < 0)
return hwirq;
irq = irq_create_mapping(port->msi_domain, hwirq);
if (!irq) {
mtk_pcie_msi_free(port, hwirq);
return -EINVAL;
}
chip->dev = &pdev->dev;
irq_set_msi_desc(irq, desc);
msg_addr = virt_to_phys(port->base + PCIE_MSI_VECTOR);
msg.address_hi = 0;
msg.address_lo = lower_32_bits(msg_addr);
msg.data = hwirq;
pci_write_msi_msg(irq, &msg);
return 0;
}
static void mtk_msi_teardown_irq(struct msi_controller *chip, unsigned int irq)
{
struct pci_dev *pdev = to_pci_dev(chip->dev);
struct irq_data *d = irq_get_irq_data(irq);
irq_hw_number_t hwirq = irqd_to_hwirq(d);
struct mtk_pcie_port *port;
port = mtk_pcie_find_port(pdev->bus, pdev->devfn);
if (!port)
return;
irq_dispose_mapping(irq);
mtk_pcie_msi_free(port, hwirq);
}
static int mtk_pcie_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &mtk_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static void mtk_pcie_enable_msi(struct mtk_pcie_port *port)
{
u32 val;
phys_addr_t msg_addr;
msg_addr = virt_to_phys(port->base + PCIE_MSI_VECTOR);
val = lower_32_bits(msg_addr);
writel(val, port->base + PCIE_IMSI_ADDR);
val = readl(port->base + PCIE_INT_MASK);
val &= ~MSI_MASK;
writel(val, port->base + PCIE_INT_MASK);
}
static int mtk_pcie_intx_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int mtk_pcie_init_irq_domain(struct mtk_pcie_port *port,
struct device_node *node)
{
struct device *dev = port->pcie->dev;
struct device_node *pcie_intc_node;
pcie_intc_node = of_get_next_child(node, NULL);
if (!pcie_intc_node) {
dev_err(dev, "no PCIe Intc node found\n");
return -ENODEV;
}
port->irq_domain = irq_domain_add_linear(pcie_intc_node, PCI_NUM_INTX,
&intx_domain_ops, port);
if (!port->irq_domain) {
dev_err(dev, "failed to get INTx IRQ domain\n");
return -ENODEV;
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
port->msi_domain = irq_domain_add_linear(node, MTK_MSI_IRQS_NUM,
&msi_domain_ops,
&mtk_pcie_msi_chip);
if (!port->msi_domain) {
dev_err(dev, "failed to create MSI IRQ domain\n");
return -ENODEV;
}
mtk_pcie_enable_msi(port);
}
return 0;
}
static irqreturn_t mtk_pcie_intr_handler(int irq, void *data)
{
struct mtk_pcie_port *port = (struct mtk_pcie_port *)data;
unsigned long status;
u32 virq;
u32 bit = INTX_SHIFT;
while ((status = readl(port->base + PCIE_INT_STATUS)) & INTX_MASK) {
for_each_set_bit_from(bit, &status, PCI_NUM_INTX + INTX_SHIFT) {
writel(1 << bit, port->base + PCIE_INT_STATUS);
virq = irq_find_mapping(port->irq_domain,
bit - INTX_SHIFT);
generic_handle_irq(virq);
}
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
while ((status = readl(port->base + PCIE_INT_STATUS)) & MSI_STATUS) {
unsigned long imsi_status;
while ((imsi_status = readl(port->base + PCIE_IMSI_STATUS))) {
for_each_set_bit(bit, &imsi_status, MTK_MSI_IRQS_NUM) {
writel(1 << bit, port->base + PCIE_IMSI_STATUS);
virq = irq_find_mapping(port->msi_domain, bit);
generic_handle_irq(virq);
}
}
writel(MSI_STATUS, port->base + PCIE_INT_STATUS);
}
}
return IRQ_HANDLED;
}
static int mtk_pcie_setup_irq(struct mtk_pcie_port *port,
struct device_node *node)
{
struct mtk_pcie *pcie = port->pcie;
struct device *dev = pcie->dev;
struct platform_device *pdev = to_platform_device(dev);
int err, irq;
irq = platform_get_irq(pdev, port->slot);
err = devm_request_irq(dev, irq, mtk_pcie_intr_handler,
IRQF_SHARED, "mtk-pcie", port);
if (err) {
dev_err(dev, "unable to request IRQ %d\n", irq);
return err;
}
err = mtk_pcie_init_irq_domain(port, node);
if (err) {
dev_err(dev, "failed to init PCIe IRQ domain\n");
return err;
}
return 0;
}
static void __iomem *mtk_pcie_map_bus(struct pci_bus *bus,
unsigned int devfn, int where)
{
struct mtk_pcie *pcie = bus->sysdata;
writel(PCIE_CONF_ADDR(where, PCI_FUNC(devfn), PCI_SLOT(devfn),
bus->number), pcie->base + PCIE_CFG_ADDR);
return pcie->base + PCIE_CFG_DATA + (where & 3);
}
static int mtk_pcie_startup_port(struct mtk_pcie_port *port)
{
struct mtk_pcie *pcie = port->pcie;
u32 func = PCI_FUNC(port->slot << 3);
u32 slot = PCI_SLOT(port->slot << 3);
u32 val;
int err;
val = readl(pcie->base + PCIE_SYS_CFG);
val |= PCIE_PORT_PERST(port->slot);
writel(val, pcie->base + PCIE_SYS_CFG);
val = readl(pcie->base + PCIE_SYS_CFG);
val &= ~PCIE_PORT_PERST(port->slot);
writel(val, pcie->base + PCIE_SYS_CFG);
err = readl_poll_timeout(port->base + PCIE_LINK_STATUS, val,
!!(val & PCIE_PORT_LINKUP), 20,
100 * USEC_PER_MSEC);
if (err)
return -ETIMEDOUT;
val = readl(pcie->base + PCIE_INT_ENABLE);
val |= PCIE_PORT_INT_EN(port->slot);
writel(val, pcie->base + PCIE_INT_ENABLE);
writel(PCIE_BAR_MAP_MAX | PCIE_BAR_ENABLE,
port->base + PCIE_BAR0_SETUP);
writel(PCIE_CLASS_CODE | PCIE_REVISION_ID, port->base + PCIE_CLASS);
writel(PCIE_CONF_ADDR(PCIE_FC_CREDIT, func, slot, 0),
pcie->base + PCIE_CFG_ADDR);
val = readl(pcie->base + PCIE_CFG_DATA);
val &= ~PCIE_FC_CREDIT_MASK;
val |= PCIE_FC_CREDIT_VAL(0x806c);
writel(PCIE_CONF_ADDR(PCIE_FC_CREDIT, func, slot, 0),
pcie->base + PCIE_CFG_ADDR);
writel(val, pcie->base + PCIE_CFG_DATA);
writel(PCIE_CONF_ADDR(PCIE_FTS_NUM, func, slot, 0),
pcie->base + PCIE_CFG_ADDR);
val = readl(pcie->base + PCIE_CFG_DATA);
val &= ~PCIE_FTS_NUM_MASK;
val |= PCIE_FTS_NUM_L0(0x50);
writel(PCIE_CONF_ADDR(PCIE_FTS_NUM, func, slot, 0),
pcie->base + PCIE_CFG_ADDR);
writel(val, pcie->base + PCIE_CFG_DATA);
return 0;
}
static void mtk_pcie_enable_port(struct mtk_pcie_port *port)
{
struct mtk_pcie *pcie = port->pcie;
struct device *dev = pcie->dev;
int err;
err = clk_prepare_enable(port->sys_ck);
if (err) {
dev_err(dev, "failed to enable sys_ck%d clock\n", port->slot);
goto err_sys_clk;
}
err = clk_prepare_enable(port->ahb_ck);
if (err) {
dev_err(dev, "failed to enable ahb_ck%d\n", port->slot);
goto err_ahb_clk;
}
err = clk_prepare_enable(port->aux_ck);
if (err) {
dev_err(dev, "failed to enable aux_ck%d\n", port->slot);
goto err_aux_clk;
}
err = clk_prepare_enable(port->axi_ck);
if (err) {
dev_err(dev, "failed to enable axi_ck%d\n", port->slot);
goto err_axi_clk;
}
err = clk_prepare_enable(port->obff_ck);
if (err) {
dev_err(dev, "failed to enable obff_ck%d\n", port->slot);
goto err_obff_clk;
}
err = clk_prepare_enable(port->pipe_ck);
if (err) {
dev_err(dev, "failed to enable pipe_ck%d\n", port->slot);
goto err_pipe_clk;
}
reset_control_assert(port->reset);
reset_control_deassert(port->reset);
err = phy_init(port->phy);
if (err) {
dev_err(dev, "failed to initialize port%d phy\n", port->slot);
goto err_phy_init;
}
err = phy_power_on(port->phy);
if (err) {
dev_err(dev, "failed to power on port%d phy\n", port->slot);
goto err_phy_on;
}
if (!pcie->soc->startup(port))
return;
dev_info(dev, "Port%d link down\n", port->slot);
phy_power_off(port->phy);
err_phy_on:
phy_exit(port->phy);
err_phy_init:
clk_disable_unprepare(port->pipe_ck);
err_pipe_clk:
clk_disable_unprepare(port->obff_ck);
err_obff_clk:
clk_disable_unprepare(port->axi_ck);
err_axi_clk:
clk_disable_unprepare(port->aux_ck);
err_aux_clk:
clk_disable_unprepare(port->ahb_ck);
err_ahb_clk:
clk_disable_unprepare(port->sys_ck);
err_sys_clk:
mtk_pcie_port_free(port);
}
static int mtk_pcie_parse_port(struct mtk_pcie *pcie,
struct device_node *node,
int slot)
{
struct mtk_pcie_port *port;
struct resource *regs;
struct device *dev = pcie->dev;
struct platform_device *pdev = to_platform_device(dev);
char name[10];
int err;
port = devm_kzalloc(dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
err = of_property_read_u32(node, "num-lanes", &port->lane);
if (err) {
dev_err(dev, "missing num-lanes property\n");
return err;
}
snprintf(name, sizeof(name), "port%d", slot);
regs = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
port->base = devm_ioremap_resource(dev, regs);
if (IS_ERR(port->base)) {
dev_err(dev, "failed to map port%d base\n", slot);
return PTR_ERR(port->base);
}
snprintf(name, sizeof(name), "sys_ck%d", slot);
port->sys_ck = devm_clk_get(dev, name);
if (IS_ERR(port->sys_ck)) {
dev_err(dev, "failed to get sys_ck%d clock\n", slot);
return PTR_ERR(port->sys_ck);
}
snprintf(name, sizeof(name), "ahb_ck%d", slot);
port->ahb_ck = devm_clk_get(dev, name);
if (IS_ERR(port->ahb_ck)) {
if (PTR_ERR(port->ahb_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
port->ahb_ck = NULL;
}
snprintf(name, sizeof(name), "axi_ck%d", slot);
port->axi_ck = devm_clk_get(dev, name);
if (IS_ERR(port->axi_ck)) {
if (PTR_ERR(port->axi_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
port->axi_ck = NULL;
}
snprintf(name, sizeof(name), "aux_ck%d", slot);
port->aux_ck = devm_clk_get(dev, name);
if (IS_ERR(port->aux_ck)) {
if (PTR_ERR(port->aux_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
port->aux_ck = NULL;
}
snprintf(name, sizeof(name), "obff_ck%d", slot);
port->obff_ck = devm_clk_get(dev, name);
if (IS_ERR(port->obff_ck)) {
if (PTR_ERR(port->obff_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
port->obff_ck = NULL;
}
snprintf(name, sizeof(name), "pipe_ck%d", slot);
port->pipe_ck = devm_clk_get(dev, name);
if (IS_ERR(port->pipe_ck)) {
if (PTR_ERR(port->pipe_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
port->pipe_ck = NULL;
}
snprintf(name, sizeof(name), "pcie-rst%d", slot);
port->reset = devm_reset_control_get_optional_exclusive(dev, name);
if (PTR_ERR(port->reset) == -EPROBE_DEFER)
return PTR_ERR(port->reset);
snprintf(name, sizeof(name), "pcie-phy%d", slot);
port->phy = devm_phy_optional_get(dev, name);
if (IS_ERR(port->phy))
return PTR_ERR(port->phy);
port->slot = slot;
port->pcie = pcie;
if (pcie->soc->setup_irq) {
err = pcie->soc->setup_irq(port, node);
if (err)
return err;
}
INIT_LIST_HEAD(&port->list);
list_add_tail(&port->list, &pcie->ports);
return 0;
}
static int mtk_pcie_subsys_powerup(struct mtk_pcie *pcie)
{
struct device *dev = pcie->dev;
struct platform_device *pdev = to_platform_device(dev);
struct resource *regs;
int err;
regs = platform_get_resource_byname(pdev, IORESOURCE_MEM, "subsys");
if (regs) {
pcie->base = devm_ioremap_resource(dev, regs);
if (IS_ERR(pcie->base)) {
dev_err(dev, "failed to map shared register\n");
return PTR_ERR(pcie->base);
}
}
pcie->free_ck = devm_clk_get(dev, "free_ck");
if (IS_ERR(pcie->free_ck)) {
if (PTR_ERR(pcie->free_ck) == -EPROBE_DEFER)
return -EPROBE_DEFER;
pcie->free_ck = NULL;
}
if (dev->pm_domain) {
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
}
err = clk_prepare_enable(pcie->free_ck);
if (err) {
dev_err(dev, "failed to enable free_ck\n");
goto err_free_ck;
}
return 0;
err_free_ck:
if (dev->pm_domain) {
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
}
return err;
}
static int mtk_pcie_setup(struct mtk_pcie *pcie)
{
struct device *dev = pcie->dev;
struct device_node *node = dev->of_node, *child;
struct of_pci_range_parser parser;
struct of_pci_range range;
struct resource res;
struct mtk_pcie_port *port, *tmp;
int err;
if (of_pci_range_parser_init(&parser, node)) {
dev_err(dev, "missing \"ranges\" property\n");
return -EINVAL;
}
for_each_of_pci_range(&parser, &range) {
err = of_pci_range_to_resource(&range, node, &res);
if (err < 0)
return err;
switch (res.flags & IORESOURCE_TYPE_BITS) {
case IORESOURCE_IO:
pcie->offset.io = res.start - range.pci_addr;
memcpy(&pcie->pio, &res, sizeof(res));
pcie->pio.name = node->full_name;
pcie->io.start = range.cpu_addr;
pcie->io.end = range.cpu_addr + range.size - 1;
pcie->io.flags = IORESOURCE_MEM;
pcie->io.name = "I/O";
memcpy(&res, &pcie->io, sizeof(res));
break;
case IORESOURCE_MEM:
pcie->offset.mem = res.start - range.pci_addr;
memcpy(&pcie->mem, &res, sizeof(res));
pcie->mem.name = "non-prefetchable";
break;
}
}
err = of_pci_parse_bus_range(node, &pcie->busn);
if (err < 0) {
dev_err(dev, "failed to parse bus ranges property: %d\n", err);
pcie->busn.name = node->name;
pcie->busn.start = 0;
pcie->busn.end = 0xff;
pcie->busn.flags = IORESOURCE_BUS;
}
for_each_available_child_of_node(node, child) {
int slot;
err = of_pci_get_devfn(child);
if (err < 0) {
dev_err(dev, "failed to parse devfn: %d\n", err);
return err;
}
slot = PCI_SLOT(err);
err = mtk_pcie_parse_port(pcie, child, slot);
if (err)
return err;
}
err = mtk_pcie_subsys_powerup(pcie);
if (err)
return err;
list_for_each_entry_safe(port, tmp, &pcie->ports, list)
mtk_pcie_enable_port(port);
if (list_empty(&pcie->ports))
mtk_pcie_subsys_powerdown(pcie);
return 0;
}
static int mtk_pcie_request_resources(struct mtk_pcie *pcie)
{
struct pci_host_bridge *host = pci_host_bridge_from_priv(pcie);
struct list_head *windows = &host->windows;
struct device *dev = pcie->dev;
int err;
pci_add_resource_offset(windows, &pcie->pio, pcie->offset.io);
pci_add_resource_offset(windows, &pcie->mem, pcie->offset.mem);
pci_add_resource(windows, &pcie->busn);
err = devm_request_pci_bus_resources(dev, windows);
if (err < 0)
return err;
pci_remap_iospace(&pcie->pio, pcie->io.start);
return 0;
}
static int mtk_pcie_register_host(struct pci_host_bridge *host)
{
struct mtk_pcie *pcie = pci_host_bridge_priv(host);
struct pci_bus *child;
int err;
host->busnr = pcie->busn.start;
host->dev.parent = pcie->dev;
host->ops = pcie->soc->ops;
host->map_irq = of_irq_parse_and_map_pci;
host->swizzle_irq = pci_common_swizzle;
host->sysdata = pcie;
if (IS_ENABLED(CONFIG_PCI_MSI) && pcie->soc->has_msi)
host->msi = &mtk_pcie_msi_chip;
err = pci_scan_root_bus_bridge(host);
if (err < 0)
return err;
pci_bus_size_bridges(host->bus);
pci_bus_assign_resources(host->bus);
list_for_each_entry(child, &host->bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(host->bus);
return 0;
}
static int mtk_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_pcie *pcie;
struct pci_host_bridge *host;
int err;
host = devm_pci_alloc_host_bridge(dev, sizeof(*pcie));
if (!host)
return -ENOMEM;
pcie = pci_host_bridge_priv(host);
pcie->dev = dev;
pcie->soc = of_device_get_match_data(dev);
platform_set_drvdata(pdev, pcie);
INIT_LIST_HEAD(&pcie->ports);
err = mtk_pcie_setup(pcie);
if (err)
return err;
err = mtk_pcie_request_resources(pcie);
if (err)
goto put_resources;
err = mtk_pcie_register_host(host);
if (err)
goto put_resources;
return 0;
put_resources:
if (!list_empty(&pcie->ports))
mtk_pcie_put_resources(pcie);
return err;
}
