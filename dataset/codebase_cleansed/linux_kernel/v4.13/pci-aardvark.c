static inline void advk_writel(struct advk_pcie *pcie, u32 val, u64 reg)
{
writel(val, pcie->base + reg);
}
static inline u32 advk_readl(struct advk_pcie *pcie, u64 reg)
{
return readl(pcie->base + reg);
}
static int advk_pcie_link_up(struct advk_pcie *pcie)
{
u32 val, ltssm_state;
val = advk_readl(pcie, CFG_REG);
ltssm_state = (val >> LTSSM_SHIFT) & LTSSM_MASK;
return ltssm_state >= LTSSM_L0;
}
static int advk_pcie_wait_for_link(struct advk_pcie *pcie)
{
struct device *dev = &pcie->pdev->dev;
int retries;
for (retries = 0; retries < LINK_WAIT_MAX_RETRIES; retries++) {
if (advk_pcie_link_up(pcie)) {
dev_info(dev, "link up\n");
return 0;
}
usleep_range(LINK_WAIT_USLEEP_MIN, LINK_WAIT_USLEEP_MAX);
}
dev_err(dev, "link never came up\n");
return -ETIMEDOUT;
}
static void advk_pcie_set_ob_win(struct advk_pcie *pcie,
u32 win_num, u32 match_ms,
u32 match_ls, u32 mask_ms,
u32 mask_ls, u32 remap_ms,
u32 remap_ls, u32 action)
{
advk_writel(pcie, match_ls, OB_WIN_MATCH_LS(win_num));
advk_writel(pcie, match_ms, OB_WIN_MATCH_MS(win_num));
advk_writel(pcie, mask_ms, OB_WIN_MASK_MS(win_num));
advk_writel(pcie, mask_ls, OB_WIN_MASK_LS(win_num));
advk_writel(pcie, remap_ms, OB_WIN_REMAP_MS(win_num));
advk_writel(pcie, remap_ls, OB_WIN_REMAP_LS(win_num));
advk_writel(pcie, action, OB_WIN_ACTIONS(win_num));
advk_writel(pcie, match_ls | BIT(0), OB_WIN_MATCH_LS(win_num));
}
static void advk_pcie_setup_hw(struct advk_pcie *pcie)
{
u32 reg;
int i;
for (i = 0; i < 8; i++)
advk_pcie_set_ob_win(pcie, i, 0, 0, 0, 0, 0, 0, 0);
reg = advk_readl(pcie, CTRL_CONFIG_REG);
reg &= ~(CTRL_MODE_MASK << CTRL_MODE_SHIFT);
reg |= ((PCIE_CORE_MODE_DIRECT & CTRL_MODE_MASK) << CTRL_MODE_SHIFT);
advk_writel(pcie, reg, CTRL_CONFIG_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL0_REG);
reg |= (IS_RC_MSK << IS_RC_SHIFT);
advk_writel(pcie, reg, PCIE_CORE_CTRL0_REG);
reg = PCIE_CORE_ERR_CAPCTL_ECRC_CHK_TX |
PCIE_CORE_ERR_CAPCTL_ECRC_CHK_TX_EN |
PCIE_CORE_ERR_CAPCTL_ECRC_CHCK |
PCIE_CORE_ERR_CAPCTL_ECRC_CHCK_RCV;
advk_writel(pcie, reg, PCIE_CORE_ERR_CAPCTL_REG);
reg = PCIE_CORE_DEV_CTRL_STATS_RELAX_ORDER_DISABLE |
(7 << PCIE_CORE_DEV_CTRL_STATS_MAX_PAYLOAD_SZ_SHIFT) |
PCIE_CORE_DEV_CTRL_STATS_SNOOP_DISABLE |
PCIE_CORE_DEV_CTRL_STATS_MAX_RD_REQ_SIZE_SHIFT;
advk_writel(pcie, reg, PCIE_CORE_DEV_CTRL_STATS_REG);
reg = PCIE_CORE_CTRL2_RESERVED |
PCIE_CORE_CTRL2_TD_ENABLE;
advk_writel(pcie, reg, PCIE_CORE_CTRL2_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL0_REG);
reg &= ~PCIE_GEN_SEL_MSK;
reg |= SPEED_GEN_2;
advk_writel(pcie, reg, PCIE_CORE_CTRL0_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL0_REG);
reg &= ~LANE_CNT_MSK;
reg |= LANE_COUNT_1;
advk_writel(pcie, reg, PCIE_CORE_CTRL0_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL0_REG);
reg |= LINK_TRAINING_EN;
advk_writel(pcie, reg, PCIE_CORE_CTRL0_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL2_REG);
reg |= PCIE_CORE_CTRL2_MSI_ENABLE;
advk_writel(pcie, reg, PCIE_CORE_CTRL2_REG);
advk_writel(pcie, PCIE_ISR0_ALL_MASK, PCIE_ISR0_REG);
advk_writel(pcie, PCIE_ISR1_ALL_MASK, PCIE_ISR1_REG);
advk_writel(pcie, PCIE_IRQ_ALL_MASK, HOST_CTRL_INT_STATUS_REG);
reg = PCIE_ISR0_ALL_MASK;
reg &= ~PCIE_ISR0_MSI_INT_PENDING;
advk_writel(pcie, reg, PCIE_ISR0_MASK_REG);
advk_writel(pcie, PCIE_ISR1_ALL_MASK, PCIE_ISR1_MASK_REG);
advk_writel(pcie, 0, PCIE_MSI_MASK_REG);
reg = PCIE_IRQ_ALL_MASK & (~PCIE_IRQ_ENABLE_INTS_MASK);
advk_writel(pcie, reg, HOST_CTRL_INT_MASK_REG);
reg = advk_readl(pcie, PCIE_CORE_CTRL2_REG);
reg |= PCIE_CORE_CTRL2_OB_WIN_ENABLE;
advk_writel(pcie, reg, PCIE_CORE_CTRL2_REG);
reg = advk_readl(pcie, PIO_CTRL);
reg |= PIO_CTRL_ADDR_WIN_DISABLE;
advk_writel(pcie, reg, PIO_CTRL);
reg = advk_readl(pcie, PCIE_CORE_LINK_CTRL_STAT_REG);
reg |= PCIE_CORE_LINK_TRAINING;
advk_writel(pcie, reg, PCIE_CORE_LINK_CTRL_STAT_REG);
advk_pcie_wait_for_link(pcie);
reg = PCIE_CORE_LINK_L0S_ENTRY |
(1 << PCIE_CORE_LINK_WIDTH_SHIFT);
advk_writel(pcie, reg, PCIE_CORE_LINK_CTRL_STAT_REG);
reg = advk_readl(pcie, PCIE_CORE_CMD_STATUS_REG);
reg |= PCIE_CORE_CMD_MEM_ACCESS_EN |
PCIE_CORE_CMD_IO_ACCESS_EN |
PCIE_CORE_CMD_MEM_IO_REQ_EN;
advk_writel(pcie, reg, PCIE_CORE_CMD_STATUS_REG);
}
static void advk_pcie_check_pio_status(struct advk_pcie *pcie)
{
struct device *dev = &pcie->pdev->dev;
u32 reg;
unsigned int status;
char *strcomp_status, *str_posted;
reg = advk_readl(pcie, PIO_STAT);
status = (reg & PIO_COMPLETION_STATUS_MASK) >>
PIO_COMPLETION_STATUS_SHIFT;
if (!status)
return;
switch (status) {
case PIO_COMPLETION_STATUS_UR:
strcomp_status = "UR";
break;
case PIO_COMPLETION_STATUS_CRS:
strcomp_status = "CRS";
break;
case PIO_COMPLETION_STATUS_CA:
strcomp_status = "CA";
break;
default:
strcomp_status = "Unknown";
break;
}
if (reg & PIO_NON_POSTED_REQ)
str_posted = "Non-posted";
else
str_posted = "Posted";
dev_err(dev, "%s PIO Response Status: %s, %#x @ %#x\n",
str_posted, strcomp_status, reg, advk_readl(pcie, PIO_ADDR_LS));
}
static int advk_pcie_wait_pio(struct advk_pcie *pcie)
{
struct device *dev = &pcie->pdev->dev;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(PIO_TIMEOUT_MS);
while (time_before(jiffies, timeout)) {
u32 start, isr;
start = advk_readl(pcie, PIO_START);
isr = advk_readl(pcie, PIO_ISR);
if (!start && isr)
return 0;
}
dev_err(dev, "config read/write timed out\n");
return -ETIMEDOUT;
}
static int advk_pcie_rd_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 *val)
{
struct advk_pcie *pcie = bus->sysdata;
u32 reg;
int ret;
if (PCI_SLOT(devfn) != 0) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
advk_writel(pcie, 0, PIO_START);
advk_writel(pcie, 1, PIO_ISR);
reg = advk_readl(pcie, PIO_CTRL);
reg &= ~PIO_CTRL_TYPE_MASK;
if (bus->number == pcie->root_bus_nr)
reg |= PCIE_CONFIG_RD_TYPE0;
else
reg |= PCIE_CONFIG_RD_TYPE1;
advk_writel(pcie, reg, PIO_CTRL);
reg = PCIE_BDF(devfn) | PCIE_CONF_REG(where);
advk_writel(pcie, reg, PIO_ADDR_LS);
advk_writel(pcie, 0, PIO_ADDR_MS);
advk_writel(pcie, 0xf, PIO_WR_DATA_STRB);
advk_writel(pcie, 1, PIO_START);
ret = advk_pcie_wait_pio(pcie);
if (ret < 0)
return PCIBIOS_SET_FAILED;
advk_pcie_check_pio_status(pcie);
*val = advk_readl(pcie, PIO_RD_DATA);
if (size == 1)
*val = (*val >> (8 * (where & 3))) & 0xff;
else if (size == 2)
*val = (*val >> (8 * (where & 3))) & 0xffff;
return PCIBIOS_SUCCESSFUL;
}
static int advk_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct advk_pcie *pcie = bus->sysdata;
u32 reg;
u32 data_strobe = 0x0;
int offset;
int ret;
if (PCI_SLOT(devfn) != 0)
return PCIBIOS_DEVICE_NOT_FOUND;
if (where % size)
return PCIBIOS_SET_FAILED;
advk_writel(pcie, 0, PIO_START);
advk_writel(pcie, 1, PIO_ISR);
reg = advk_readl(pcie, PIO_CTRL);
reg &= ~PIO_CTRL_TYPE_MASK;
if (bus->number == pcie->root_bus_nr)
reg |= PCIE_CONFIG_WR_TYPE0;
else
reg |= PCIE_CONFIG_WR_TYPE1;
advk_writel(pcie, reg, PIO_CTRL);
reg = PCIE_CONF_ADDR(bus->number, devfn, where);
advk_writel(pcie, reg, PIO_ADDR_LS);
advk_writel(pcie, 0, PIO_ADDR_MS);
offset = where & 0x3;
reg = val << (8 * offset);
data_strobe = GENMASK(size - 1, 0) << offset;
advk_writel(pcie, reg, PIO_WR_DATA);
advk_writel(pcie, data_strobe, PIO_WR_DATA_STRB);
advk_writel(pcie, 1, PIO_START);
ret = advk_pcie_wait_pio(pcie);
if (ret < 0)
return PCIBIOS_SET_FAILED;
advk_pcie_check_pio_status(pcie);
return PCIBIOS_SUCCESSFUL;
}
static void advk_msi_irq_compose_msi_msg(struct irq_data *data,
struct msi_msg *msg)
{
struct advk_pcie *pcie = irq_data_get_irq_chip_data(data);
phys_addr_t msi_msg = virt_to_phys(&pcie->msi_msg);
msg->address_lo = lower_32_bits(msi_msg);
msg->address_hi = upper_32_bits(msi_msg);
msg->data = data->irq;
}
static int advk_msi_set_affinity(struct irq_data *irq_data,
const struct cpumask *mask, bool force)
{
return -EINVAL;
}
static int advk_msi_irq_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct advk_pcie *pcie = domain->host_data;
int hwirq, i;
mutex_lock(&pcie->msi_used_lock);
hwirq = bitmap_find_next_zero_area(pcie->msi_used, MSI_IRQ_NUM,
0, nr_irqs, 0);
if (hwirq >= MSI_IRQ_NUM) {
mutex_unlock(&pcie->msi_used_lock);
return -ENOSPC;
}
bitmap_set(pcie->msi_used, hwirq, nr_irqs);
mutex_unlock(&pcie->msi_used_lock);
for (i = 0; i < nr_irqs; i++)
irq_domain_set_info(domain, virq + i, hwirq + i,
&pcie->msi_bottom_irq_chip,
domain->host_data, handle_simple_irq,
NULL, NULL);
return hwirq;
}
static void advk_msi_irq_domain_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
struct advk_pcie *pcie = domain->host_data;
mutex_lock(&pcie->msi_used_lock);
bitmap_clear(pcie->msi_used, d->hwirq, nr_irqs);
mutex_unlock(&pcie->msi_used_lock);
}
static void advk_pcie_irq_mask(struct irq_data *d)
{
struct advk_pcie *pcie = d->domain->host_data;
irq_hw_number_t hwirq = irqd_to_hwirq(d);
u32 mask;
mask = advk_readl(pcie, PCIE_ISR0_MASK_REG);
mask |= PCIE_ISR0_INTX_ASSERT(hwirq);
advk_writel(pcie, mask, PCIE_ISR0_MASK_REG);
}
static void advk_pcie_irq_unmask(struct irq_data *d)
{
struct advk_pcie *pcie = d->domain->host_data;
irq_hw_number_t hwirq = irqd_to_hwirq(d);
u32 mask;
mask = advk_readl(pcie, PCIE_ISR0_MASK_REG);
mask &= ~PCIE_ISR0_INTX_ASSERT(hwirq);
advk_writel(pcie, mask, PCIE_ISR0_MASK_REG);
}
static int advk_pcie_irq_map(struct irq_domain *h,
unsigned int virq, irq_hw_number_t hwirq)
{
struct advk_pcie *pcie = h->host_data;
advk_pcie_irq_mask(irq_get_irq_data(virq));
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &pcie->irq_chip,
handle_level_irq);
irq_set_chip_data(virq, pcie);
return 0;
}
static int advk_pcie_init_msi_irq_domain(struct advk_pcie *pcie)
{
struct device *dev = &pcie->pdev->dev;
struct device_node *node = dev->of_node;
struct irq_chip *bottom_ic, *msi_ic;
struct msi_domain_info *msi_di;
phys_addr_t msi_msg_phys;
mutex_init(&pcie->msi_used_lock);
bottom_ic = &pcie->msi_bottom_irq_chip;
bottom_ic->name = "MSI";
bottom_ic->irq_compose_msi_msg = advk_msi_irq_compose_msi_msg;
bottom_ic->irq_set_affinity = advk_msi_set_affinity;
msi_ic = &pcie->msi_irq_chip;
msi_ic->name = "advk-MSI";
msi_di = &pcie->msi_domain_info;
msi_di->flags = MSI_FLAG_USE_DEF_DOM_OPS | MSI_FLAG_USE_DEF_CHIP_OPS |
MSI_FLAG_MULTI_PCI_MSI;
msi_di->chip = msi_ic;
msi_msg_phys = virt_to_phys(&pcie->msi_msg);
advk_writel(pcie, lower_32_bits(msi_msg_phys),
PCIE_MSI_ADDR_LOW_REG);
advk_writel(pcie, upper_32_bits(msi_msg_phys),
PCIE_MSI_ADDR_HIGH_REG);
pcie->msi_inner_domain =
irq_domain_add_linear(NULL, MSI_IRQ_NUM,
&advk_msi_domain_ops, pcie);
if (!pcie->msi_inner_domain)
return -ENOMEM;
pcie->msi_domain =
pci_msi_create_irq_domain(of_node_to_fwnode(node),
msi_di, pcie->msi_inner_domain);
if (!pcie->msi_domain) {
irq_domain_remove(pcie->msi_inner_domain);
return -ENOMEM;
}
return 0;
}
static void advk_pcie_remove_msi_irq_domain(struct advk_pcie *pcie)
{
irq_domain_remove(pcie->msi_domain);
irq_domain_remove(pcie->msi_inner_domain);
}
static int advk_pcie_init_irq_domain(struct advk_pcie *pcie)
{
struct device *dev = &pcie->pdev->dev;
struct device_node *node = dev->of_node;
struct device_node *pcie_intc_node;
struct irq_chip *irq_chip;
pcie_intc_node = of_get_next_child(node, NULL);
if (!pcie_intc_node) {
dev_err(dev, "No PCIe Intc node found\n");
return -ENODEV;
}
irq_chip = &pcie->irq_chip;
irq_chip->name = devm_kasprintf(dev, GFP_KERNEL, "%s-irq",
dev_name(dev));
if (!irq_chip->name) {
of_node_put(pcie_intc_node);
return -ENOMEM;
}
irq_chip->irq_mask = advk_pcie_irq_mask;
irq_chip->irq_mask_ack = advk_pcie_irq_mask;
irq_chip->irq_unmask = advk_pcie_irq_unmask;
pcie->irq_domain =
irq_domain_add_linear(pcie_intc_node, LEGACY_IRQ_NUM,
&advk_pcie_irq_domain_ops, pcie);
if (!pcie->irq_domain) {
dev_err(dev, "Failed to get a INTx IRQ domain\n");
of_node_put(pcie_intc_node);
return -ENOMEM;
}
return 0;
}
static void advk_pcie_remove_irq_domain(struct advk_pcie *pcie)
{
irq_domain_remove(pcie->irq_domain);
}
static void advk_pcie_handle_msi(struct advk_pcie *pcie)
{
u32 msi_val, msi_mask, msi_status, msi_idx;
u16 msi_data;
msi_mask = advk_readl(pcie, PCIE_MSI_MASK_REG);
msi_val = advk_readl(pcie, PCIE_MSI_STATUS_REG);
msi_status = msi_val & ~msi_mask;
for (msi_idx = 0; msi_idx < MSI_IRQ_NUM; msi_idx++) {
if (!(BIT(msi_idx) & msi_status))
continue;
advk_writel(pcie, BIT(msi_idx), PCIE_MSI_STATUS_REG);
msi_data = advk_readl(pcie, PCIE_MSI_PAYLOAD_REG) & 0xFF;
generic_handle_irq(msi_data);
}
advk_writel(pcie, PCIE_ISR0_MSI_INT_PENDING,
PCIE_ISR0_REG);
}
static void advk_pcie_handle_int(struct advk_pcie *pcie)
{
u32 val, mask, status;
int i, virq;
val = advk_readl(pcie, PCIE_ISR0_REG);
mask = advk_readl(pcie, PCIE_ISR0_MASK_REG);
status = val & ((~mask) & PCIE_ISR0_ALL_MASK);
if (!status) {
advk_writel(pcie, val, PCIE_ISR0_REG);
return;
}
if (status & PCIE_ISR0_MSI_INT_PENDING)
advk_pcie_handle_msi(pcie);
for (i = 0; i < LEGACY_IRQ_NUM; i++) {
if (!(status & PCIE_ISR0_INTX_ASSERT(i)))
continue;
advk_writel(pcie, PCIE_ISR0_INTX_ASSERT(i),
PCIE_ISR0_REG);
virq = irq_find_mapping(pcie->irq_domain, i);
generic_handle_irq(virq);
}
}
static irqreturn_t advk_pcie_irq_handler(int irq, void *arg)
{
struct advk_pcie *pcie = arg;
u32 status;
status = advk_readl(pcie, HOST_CTRL_INT_STATUS_REG);
if (!(status & PCIE_IRQ_CORE_INT))
return IRQ_NONE;
advk_pcie_handle_int(pcie);
advk_writel(pcie, PCIE_IRQ_CORE_INT, HOST_CTRL_INT_STATUS_REG);
return IRQ_HANDLED;
}
static int advk_pcie_parse_request_of_pci_ranges(struct advk_pcie *pcie)
{
int err, res_valid = 0;
struct device *dev = &pcie->pdev->dev;
struct device_node *np = dev->of_node;
struct resource_entry *win, *tmp;
resource_size_t iobase;
INIT_LIST_HEAD(&pcie->resources);
err = of_pci_get_host_bridge_resources(np, 0, 0xff, &pcie->resources,
&iobase);
if (err)
return err;
err = devm_request_pci_bus_resources(dev, &pcie->resources);
if (err)
goto out_release_res;
resource_list_for_each_entry_safe(win, tmp, &pcie->resources) {
struct resource *res = win->res;
switch (resource_type(res)) {
case IORESOURCE_IO:
advk_pcie_set_ob_win(pcie, 1,
upper_32_bits(res->start),
lower_32_bits(res->start),
0, 0xF8000000, 0,
lower_32_bits(res->start),
OB_PCIE_IO);
err = pci_remap_iospace(res, iobase);
if (err) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
err, res);
resource_list_destroy_entry(win);
}
break;
case IORESOURCE_MEM:
advk_pcie_set_ob_win(pcie, 0,
upper_32_bits(res->start),
lower_32_bits(res->start),
0x0, 0xF8000000, 0,
lower_32_bits(res->start),
(2 << 20) | OB_PCIE_MEM);
res_valid |= !(res->flags & IORESOURCE_PREFETCH);
break;
case IORESOURCE_BUS:
pcie->root_bus_nr = res->start;
break;
}
}
if (!res_valid) {
dev_err(dev, "non-prefetchable memory resource required\n");
err = -EINVAL;
goto out_release_res;
}
return 0;
out_release_res:
pci_free_resource_list(&pcie->resources);
return err;
}
static int advk_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct advk_pcie *pcie;
struct resource *res;
struct pci_bus *bus, *child;
struct pci_host_bridge *bridge;
int ret, irq;
bridge = devm_pci_alloc_host_bridge(dev, sizeof(struct advk_pcie));
if (!bridge)
return -ENOMEM;
pcie = pci_host_bridge_priv(bridge);
pcie->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pcie->base = devm_ioremap_resource(dev, res);
if (IS_ERR(pcie->base))
return PTR_ERR(pcie->base);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(dev, irq, advk_pcie_irq_handler,
IRQF_SHARED | IRQF_NO_THREAD, "advk-pcie",
pcie);
if (ret) {
dev_err(dev, "Failed to register interrupt\n");
return ret;
}
ret = advk_pcie_parse_request_of_pci_ranges(pcie);
if (ret) {
dev_err(dev, "Failed to parse resources\n");
return ret;
}
advk_pcie_setup_hw(pcie);
ret = advk_pcie_init_irq_domain(pcie);
if (ret) {
dev_err(dev, "Failed to initialize irq\n");
return ret;
}
ret = advk_pcie_init_msi_irq_domain(pcie);
if (ret) {
dev_err(dev, "Failed to initialize irq\n");
advk_pcie_remove_irq_domain(pcie);
return ret;
}
list_splice_init(&pcie->resources, &bridge->windows);
bridge->dev.parent = dev;
bridge->sysdata = pcie;
bridge->busnr = 0;
bridge->ops = &advk_pcie_ops;
ret = pci_scan_root_bus_bridge(bridge);
if (ret < 0) {
advk_pcie_remove_msi_irq_domain(pcie);
advk_pcie_remove_irq_domain(pcie);
return ret;
}
bus = bridge->bus;
pci_bus_assign_resources(bus);
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(bus);
return 0;
}
