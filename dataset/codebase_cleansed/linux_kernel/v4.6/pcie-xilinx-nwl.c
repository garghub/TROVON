static inline u32 nwl_bridge_readl(struct nwl_pcie *pcie, u32 off)
{
return readl(pcie->breg_base + off);
}
static inline void nwl_bridge_writel(struct nwl_pcie *pcie, u32 val, u32 off)
{
writel(val, pcie->breg_base + off);
}
static bool nwl_pcie_link_up(struct nwl_pcie *pcie)
{
if (readl(pcie->pcireg_base + PS_LINKUP_OFFSET) & PCIE_PHY_LINKUP_BIT)
return true;
return false;
}
static bool nwl_phy_link_up(struct nwl_pcie *pcie)
{
if (readl(pcie->pcireg_base + PS_LINKUP_OFFSET) & PHY_RDY_LINKUP_BIT)
return true;
return false;
}
static int nwl_wait_for_link(struct nwl_pcie *pcie)
{
int retries;
for (retries = 0; retries < LINK_WAIT_MAX_RETRIES; retries++) {
if (nwl_phy_link_up(pcie))
return 0;
usleep_range(LINK_WAIT_USLEEP_MIN, LINK_WAIT_USLEEP_MAX);
}
dev_err(pcie->dev, "PHY link never came up\n");
return -ETIMEDOUT;
}
static bool nwl_pcie_valid_device(struct pci_bus *bus, unsigned int devfn)
{
struct nwl_pcie *pcie = bus->sysdata;
if (bus->number != pcie->root_busno) {
if (!nwl_pcie_link_up(pcie))
return false;
}
if (bus->number == pcie->root_busno && devfn > 0)
return false;
return true;
}
static void __iomem *nwl_pcie_map_bus(struct pci_bus *bus, unsigned int devfn,
int where)
{
struct nwl_pcie *pcie = bus->sysdata;
int relbus;
if (!nwl_pcie_valid_device(bus, devfn))
return NULL;
relbus = (bus->number << ECAM_BUS_LOC_SHIFT) |
(devfn << ECAM_DEV_LOC_SHIFT);
return pcie->ecam_base + relbus + where;
}
static irqreturn_t nwl_pcie_misc_handler(int irq, void *data)
{
struct nwl_pcie *pcie = data;
u32 misc_stat;
misc_stat = nwl_bridge_readl(pcie, MSGF_MISC_STATUS) &
MSGF_MISC_SR_MASKALL;
if (!misc_stat)
return IRQ_NONE;
if (misc_stat & MSGF_MISC_SR_RXMSG_OVER)
dev_err(pcie->dev, "Received Message FIFO Overflow\n");
if (misc_stat & MSGF_MISC_SR_SLAVE_ERR)
dev_err(pcie->dev, "Slave error\n");
if (misc_stat & MSGF_MISC_SR_MASTER_ERR)
dev_err(pcie->dev, "Master error\n");
if (misc_stat & MSGF_MISC_SR_I_ADDR_ERR)
dev_err(pcie->dev,
"In Misc Ingress address translation error\n");
if (misc_stat & MSGF_MISC_SR_E_ADDR_ERR)
dev_err(pcie->dev,
"In Misc Egress address translation error\n");
if (misc_stat & MSGF_MISC_SR_PCIE_CORE_ERR)
dev_err(pcie->dev, "PCIe Core error\n");
nwl_bridge_writel(pcie, misc_stat, MSGF_MISC_STATUS);
return IRQ_HANDLED;
}
static void nwl_pcie_leg_handler(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct nwl_pcie *pcie;
unsigned long status;
u32 bit;
u32 virq;
chained_irq_enter(chip, desc);
pcie = irq_desc_get_handler_data(desc);
while ((status = nwl_bridge_readl(pcie, MSGF_LEG_STATUS) &
MSGF_LEG_SR_MASKALL) != 0) {
for_each_set_bit(bit, &status, INTX_NUM) {
virq = irq_find_mapping(pcie->legacy_irq_domain,
bit + 1);
if (virq)
generic_handle_irq(virq);
}
}
chained_irq_exit(chip, desc);
}
static void nwl_pcie_handle_msi_irq(struct nwl_pcie *pcie, u32 status_reg)
{
struct nwl_msi *msi;
unsigned long status;
u32 bit;
u32 virq;
msi = &pcie->msi;
while ((status = nwl_bridge_readl(pcie, status_reg)) != 0) {
for_each_set_bit(bit, &status, 32) {
nwl_bridge_writel(pcie, 1 << bit, status_reg);
virq = irq_find_mapping(msi->dev_domain, bit);
if (virq)
generic_handle_irq(virq);
}
}
}
static void nwl_pcie_msi_handler_high(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct nwl_pcie *pcie = irq_desc_get_handler_data(desc);
chained_irq_enter(chip, desc);
nwl_pcie_handle_msi_irq(pcie, MSGF_MSI_STATUS_HI);
chained_irq_exit(chip, desc);
}
static void nwl_pcie_msi_handler_low(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct nwl_pcie *pcie = irq_desc_get_handler_data(desc);
chained_irq_enter(chip, desc);
nwl_pcie_handle_msi_irq(pcie, MSGF_MSI_STATUS_LO);
chained_irq_exit(chip, desc);
}
static int nwl_legacy_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static void nwl_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct nwl_pcie *pcie = irq_data_get_irq_chip_data(data);
phys_addr_t msi_addr = pcie->phys_pcie_reg_base;
msg->address_lo = lower_32_bits(msi_addr);
msg->address_hi = upper_32_bits(msi_addr);
msg->data = data->hwirq;
}
static int nwl_msi_set_affinity(struct irq_data *irq_data,
const struct cpumask *mask, bool force)
{
return -EINVAL;
}
static int nwl_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct nwl_pcie *pcie = domain->host_data;
struct nwl_msi *msi = &pcie->msi;
int bit;
int i;
mutex_lock(&msi->lock);
bit = bitmap_find_next_zero_area(msi->bitmap, INT_PCI_MSI_NR, 0,
nr_irqs, 0);
if (bit >= INT_PCI_MSI_NR) {
mutex_unlock(&msi->lock);
return -ENOSPC;
}
bitmap_set(msi->bitmap, bit, nr_irqs);
for (i = 0; i < nr_irqs; i++) {
irq_domain_set_info(domain, virq + i, bit + i, &nwl_irq_chip,
domain->host_data, handle_simple_irq,
NULL, NULL);
}
mutex_unlock(&msi->lock);
return 0;
}
static void nwl_irq_domain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *data = irq_domain_get_irq_data(domain, virq);
struct nwl_pcie *pcie = irq_data_get_irq_chip_data(data);
struct nwl_msi *msi = &pcie->msi;
mutex_lock(&msi->lock);
bitmap_clear(msi->bitmap, data->hwirq, nr_irqs);
mutex_unlock(&msi->lock);
}
static void nwl_msi_free_irq_domain(struct nwl_pcie *pcie)
{
struct nwl_msi *msi = &pcie->msi;
if (msi->irq_msi0)
irq_set_chained_handler_and_data(msi->irq_msi0, NULL, NULL);
if (msi->irq_msi1)
irq_set_chained_handler_and_data(msi->irq_msi1, NULL, NULL);
if (msi->msi_domain)
irq_domain_remove(msi->msi_domain);
if (msi->dev_domain)
irq_domain_remove(msi->dev_domain);
kfree(msi->bitmap);
msi->bitmap = NULL;
}
static void nwl_pcie_free_irq_domain(struct nwl_pcie *pcie)
{
int i;
u32 irq;
for (i = 0; i < INTX_NUM; i++) {
irq = irq_find_mapping(pcie->legacy_irq_domain, i + 1);
if (irq > 0)
irq_dispose_mapping(irq);
}
if (pcie->legacy_irq_domain)
irq_domain_remove(pcie->legacy_irq_domain);
nwl_msi_free_irq_domain(pcie);
}
static int nwl_pcie_init_msi_irq_domain(struct nwl_pcie *pcie)
{
#ifdef CONFIG_PCI_MSI
struct fwnode_handle *fwnode = of_node_to_fwnode(pcie->dev->of_node);
struct nwl_msi *msi = &pcie->msi;
msi->dev_domain = irq_domain_add_linear(NULL, INT_PCI_MSI_NR,
&dev_msi_domain_ops, pcie);
if (!msi->dev_domain) {
dev_err(pcie->dev, "failed to create dev IRQ domain\n");
return -ENOMEM;
}
msi->msi_domain = pci_msi_create_irq_domain(fwnode,
&nwl_msi_domain_info,
msi->dev_domain);
if (!msi->msi_domain) {
dev_err(pcie->dev, "failed to create msi IRQ domain\n");
irq_domain_remove(msi->dev_domain);
return -ENOMEM;
}
#endif
return 0;
}
static int nwl_pcie_init_irq_domain(struct nwl_pcie *pcie)
{
struct device_node *node = pcie->dev->of_node;
struct device_node *legacy_intc_node;
legacy_intc_node = of_get_next_child(node, NULL);
if (!legacy_intc_node) {
dev_err(pcie->dev, "No legacy intc node found\n");
return -EINVAL;
}
pcie->legacy_irq_domain = irq_domain_add_linear(legacy_intc_node,
INTX_NUM,
&legacy_domain_ops,
pcie);
if (!pcie->legacy_irq_domain) {
dev_err(pcie->dev, "failed to create IRQ domain\n");
return -ENOMEM;
}
nwl_pcie_init_msi_irq_domain(pcie);
return 0;
}
static int nwl_pcie_enable_msi(struct nwl_pcie *pcie, struct pci_bus *bus)
{
struct platform_device *pdev = to_platform_device(pcie->dev);
struct nwl_msi *msi = &pcie->msi;
unsigned long base;
int ret;
int size = BITS_TO_LONGS(INT_PCI_MSI_NR) * sizeof(long);
mutex_init(&msi->lock);
msi->bitmap = kzalloc(size, GFP_KERNEL);
if (!msi->bitmap)
return -ENOMEM;
msi->irq_msi1 = platform_get_irq_byname(pdev, "msi1");
if (msi->irq_msi1 < 0) {
dev_err(&pdev->dev, "failed to get IRQ#%d\n", msi->irq_msi1);
ret = -EINVAL;
goto err;
}
irq_set_chained_handler_and_data(msi->irq_msi1,
nwl_pcie_msi_handler_high, pcie);
msi->irq_msi0 = platform_get_irq_byname(pdev, "msi0");
if (msi->irq_msi0 < 0) {
dev_err(&pdev->dev, "failed to get IRQ#%d\n", msi->irq_msi0);
ret = -EINVAL;
goto err;
}
irq_set_chained_handler_and_data(msi->irq_msi0,
nwl_pcie_msi_handler_low, pcie);
ret = nwl_bridge_readl(pcie, I_MSII_CAPABILITIES) & MSII_PRESENT;
if (!ret) {
dev_err(pcie->dev, "MSI not present\n");
ret = -EIO;
goto err;
}
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, I_MSII_CONTROL) |
MSII_ENABLE, I_MSII_CONTROL);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, I_MSII_CONTROL) |
MSII_STATUS_ENABLE, I_MSII_CONTROL);
base = pcie->phys_pcie_reg_base;
nwl_bridge_writel(pcie, lower_32_bits(base), I_MSII_BASE_LO);
nwl_bridge_writel(pcie, upper_32_bits(base), I_MSII_BASE_HI);
nwl_bridge_writel(pcie, (u32)~MSGF_MSI_SR_HI_MASK, MSGF_MSI_MASK_HI);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, MSGF_MSI_STATUS_HI) &
MSGF_MSI_SR_HI_MASK, MSGF_MSI_STATUS_HI);
nwl_bridge_writel(pcie, MSGF_MSI_SR_HI_MASK, MSGF_MSI_MASK_HI);
nwl_bridge_writel(pcie, (u32)~MSGF_MSI_SR_LO_MASK, MSGF_MSI_MASK_LO);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, MSGF_MSI_STATUS_LO) &
MSGF_MSI_SR_LO_MASK, MSGF_MSI_STATUS_LO);
nwl_bridge_writel(pcie, MSGF_MSI_SR_LO_MASK, MSGF_MSI_MASK_LO);
return 0;
err:
kfree(msi->bitmap);
msi->bitmap = NULL;
return ret;
}
static int nwl_pcie_bridge_init(struct nwl_pcie *pcie)
{
struct platform_device *pdev = to_platform_device(pcie->dev);
u32 breg_val, ecam_val, first_busno = 0;
int err;
breg_val = nwl_bridge_readl(pcie, E_BREG_CAPABILITIES) & BREG_PRESENT;
if (!breg_val) {
dev_err(pcie->dev, "BREG is not present\n");
return breg_val;
}
nwl_bridge_writel(pcie, lower_32_bits(pcie->phys_breg_base),
E_BREG_BASE_LO);
nwl_bridge_writel(pcie, upper_32_bits(pcie->phys_breg_base),
E_BREG_BASE_HI);
nwl_bridge_writel(pcie, ~BREG_ENABLE_FORCE & BREG_ENABLE,
E_BREG_CONTROL);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, BRCFG_PCIE_RX0) |
CFG_DMA_REG_BAR, BRCFG_PCIE_RX0);
nwl_bridge_writel(pcie, SET_ISUB_CONTROL, I_ISUB_CONTROL);
nwl_bridge_writel(pcie, CFG_ENABLE_MSG_FILTER_MASK,
BRCFG_PCIE_RX_MSG_FILTER);
err = nwl_wait_for_link(pcie);
if (err)
return err;
ecam_val = nwl_bridge_readl(pcie, E_ECAM_CAPABILITIES) & E_ECAM_PRESENT;
if (!ecam_val) {
dev_err(pcie->dev, "ECAM is not present\n");
return ecam_val;
}
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, E_ECAM_CONTROL) |
E_ECAM_CR_ENABLE, E_ECAM_CONTROL);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, E_ECAM_CONTROL) |
(pcie->ecam_value << E_ECAM_SIZE_SHIFT),
E_ECAM_CONTROL);
nwl_bridge_writel(pcie, lower_32_bits(pcie->phys_ecam_base),
E_ECAM_BASE_LO);
nwl_bridge_writel(pcie, upper_32_bits(pcie->phys_ecam_base),
E_ECAM_BASE_HI);
ecam_val = nwl_bridge_readl(pcie, E_ECAM_CONTROL);
pcie->last_busno = (ecam_val & E_ECAM_SIZE_LOC) >> E_ECAM_SIZE_SHIFT;
ecam_val = first_busno;
ecam_val |= (first_busno + 1) << 8;
ecam_val |= (pcie->last_busno << E_ECAM_SIZE_SHIFT);
writel(ecam_val, (pcie->ecam_base + PCI_PRIMARY_BUS));
if (nwl_pcie_link_up(pcie))
dev_info(pcie->dev, "Link is UP\n");
else
dev_info(pcie->dev, "Link is DOWN\n");
pcie->irq_misc = platform_get_irq_byname(pdev, "misc");
if (pcie->irq_misc < 0) {
dev_err(&pdev->dev, "failed to get misc IRQ %d\n",
pcie->irq_misc);
return -EINVAL;
}
err = devm_request_irq(pcie->dev, pcie->irq_misc,
nwl_pcie_misc_handler, IRQF_SHARED,
"nwl_pcie:misc", pcie);
if (err) {
dev_err(pcie->dev, "fail to register misc IRQ#%d\n",
pcie->irq_misc);
return err;
}
nwl_bridge_writel(pcie, (u32)~MSGF_MISC_SR_MASKALL, MSGF_MISC_MASK);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, MSGF_MISC_STATUS) &
MSGF_MISC_SR_MASKALL, MSGF_MISC_STATUS);
nwl_bridge_writel(pcie, MSGF_MISC_SR_MASKALL, MSGF_MISC_MASK);
nwl_bridge_writel(pcie, (u32)~MSGF_LEG_SR_MASKALL, MSGF_LEG_MASK);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, MSGF_LEG_STATUS) &
MSGF_LEG_SR_MASKALL, MSGF_LEG_STATUS);
nwl_bridge_writel(pcie, MSGF_LEG_SR_MASKALL, MSGF_LEG_MASK);
nwl_bridge_writel(pcie, nwl_bridge_readl(pcie, BRCFG_INTERRUPT) |
BRCFG_INTERRUPT_MASK, BRCFG_INTERRUPT);
return 0;
}
static int nwl_pcie_parse_dt(struct nwl_pcie *pcie,
struct platform_device *pdev)
{
struct device_node *node = pcie->dev->of_node;
struct resource *res;
const char *type;
type = of_get_property(node, "device_type", NULL);
if (!type || strcmp(type, "pci")) {
dev_err(pcie->dev, "invalid \"device_type\" %s\n", type);
return -EINVAL;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "breg");
pcie->breg_base = devm_ioremap_resource(pcie->dev, res);
if (IS_ERR(pcie->breg_base))
return PTR_ERR(pcie->breg_base);
pcie->phys_breg_base = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pcireg");
pcie->pcireg_base = devm_ioremap_resource(pcie->dev, res);
if (IS_ERR(pcie->pcireg_base))
return PTR_ERR(pcie->pcireg_base);
pcie->phys_pcie_reg_base = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cfg");
pcie->ecam_base = devm_ioremap_resource(pcie->dev, res);
if (IS_ERR(pcie->ecam_base))
return PTR_ERR(pcie->ecam_base);
pcie->phys_ecam_base = res->start;
pcie->irq_intx = platform_get_irq_byname(pdev, "intx");
if (pcie->irq_intx < 0) {
dev_err(&pdev->dev, "failed to get intx IRQ %d\n",
pcie->irq_intx);
return -EINVAL;
}
irq_set_chained_handler_and_data(pcie->irq_intx,
nwl_pcie_leg_handler, pcie);
return 0;
}
static int nwl_pcie_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct nwl_pcie *pcie;
struct pci_bus *bus;
struct pci_bus *child;
int err;
resource_size_t iobase = 0;
LIST_HEAD(res);
pcie = devm_kzalloc(&pdev->dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = &pdev->dev;
pcie->ecam_value = NWL_ECAM_VALUE_DEFAULT;
err = nwl_pcie_parse_dt(pcie, pdev);
if (err) {
dev_err(pcie->dev, "Parsing DT failed\n");
return err;
}
err = nwl_pcie_bridge_init(pcie);
if (err) {
dev_err(pcie->dev, "HW Initalization failed\n");
return err;
}
err = of_pci_get_host_bridge_resources(node, 0, 0xff, &res, &iobase);
if (err) {
pr_err("Getting bridge resources failed\n");
return err;
}
err = nwl_pcie_init_irq_domain(pcie);
if (err) {
dev_err(pcie->dev, "Failed creating IRQ Domain\n");
return err;
}
bus = pci_create_root_bus(&pdev->dev, pcie->root_busno,
&nwl_pcie_ops, pcie, &res);
if (!bus)
return -ENOMEM;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
err = nwl_pcie_enable_msi(pcie, bus);
if (err < 0) {
dev_err(&pdev->dev,
"failed to enable MSI support: %d\n", err);
return err;
}
}
pci_scan_child_bus(bus);
pci_assign_unassigned_bus_resources(bus);
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(bus);
platform_set_drvdata(pdev, pcie);
return 0;
}
static int nwl_pcie_remove(struct platform_device *pdev)
{
struct nwl_pcie *pcie = platform_get_drvdata(pdev);
nwl_pcie_free_irq_domain(pcie);
platform_set_drvdata(pdev, NULL);
return 0;
}
